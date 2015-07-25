//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                     Ivory -- A Memory Management Library
//
//                          Microsoft Windows '95 Version
//
//            Copyright (c) 1994-1997 by Charybdis Enterprises, Inc.
//                           All Rights Reserved.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//           *** Charybdis Enterprises, Inc. Company Confidential ***
//
//  This file and all associated files are the company proprietary property
//        of Charybdis Enterprises, Inc.  Unauthorized use prohibited.
//
// CHARYBDIS ENTERPRISES, INC. MAKES NO WARRANTIES, EXPRESS OR IMPLIED, AS
// TO THE CORRECTNESS OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE
// IT.  CHARYBDIS ENTERPRISES, INC. PROVIDES THE CODE ON AN "AS-IS" BASIS
// AND EXPLICITLY DISCLAIMS ANY LIABILITY, INCLUDING CONSEQUENTIAL AND
// INCIDENTAL DAMAGES FOR ERRORS, OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Dan Higdon
//
// ivarena.c
//
// Ivory Allocation - Arena allocation routines.
//
//		Ivory provides a malloc-style memory allocation library.
//	Ivory allows the programmer to allocate memory either from a global
//	pool (like malloc), or to allocate chunks from a special arena.
//
//	Arena allocations may be rapidly freed by freeing the arena, or
//	by re-initializing the arena's internal pointers.  As you may have
//	guessed, the arena may be allocated with the global allocation routines.
//  The objects allocated by the arena routines may not be individually
//  freed, and do not incur any overhead in bytes over their basic sizes.
//  Thus, they lend themselves to small, quickly allocated items, such
//  as list CONS cells or POINT and VECTOR records, that can be later
//  disposed of as a group.
//
//  If the current arena is out of space, the library will allocate
//  an additional block the same size as the current arena, and chain
//  it onto the arena by way of the arena's "next" field.  This additional
//  block will be freed when the arena is emptied.  The additional block
//  will impact performance, so it is wise to create the initial arena
//  with enough space.  The function ivory_arena_chainlen() is provided
//  as an aid in determining when an arena is too small.
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//                                
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#include <memory.h>
#include <assert.h>
#include "ivory.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define max(a,b) ((a)>(b)?(a):(b))

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_arena_initialize                                                  
//
// Prepare the provided block to be used as an arena.                 
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
IvoryArena *ivory_arena_initialize (IvoryArena *arena, size_t arena_size)
{
    IvoryArena *p = arena;

    assertMyth("ivory_arena_initialize needs valid inputs",
               arena != 0 && arena_size > 0);

//ÄÄÄ Set up the arena fields
    p->size = arena_size;
    p->end	= p->data + arena_size - sizeof (IvoryArena);
    p->current = p->data;
    p->next = 0;

    return p;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_arena_clear
//
// Returns the arena to an empty state, freeing any additional "tags".
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ivory_arena_clear (IvoryArena *arena)
{
    IvoryArena *arena_chain;

    assertMyth("ivory_arena_clear needs arena", arena != 0);

//ÄÄÄ Wipe out any "hanger-on" tag blocks
    arena_chain = arena->next;
    while (arena_chain != 0)
    {
        void *tmp = arena_chain;
        arena_chain = ((IvoryArena *)tmp)->next;
        ivory_free (&tmp);
    }

//ÄÄÄ Now, reset the internal pointers.
    assert (arena->end == arena->data + arena->size - sizeof (IvoryArena));
    arena->current = arena->data;
    arena->next = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_arena_alloc_internal
//
// Allocate a block from the provided arena.  Does not assume that
// the requested block will fit in the current arena.  However, it
// does assume that the requested item is not larger than the TOTAL
// arena size.  If this is the case, an assertion error will result.
// Should I maybe be more forgiving of this error?
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void *ivory_arena_alloc_internal (IvoryArena *arena, size_t size)
{
    void *new_object;

    assertMyth("ivory_arena_alloc_internal needs valid inputs",
               arena != 0 && size > 0 && size < arena->size); 

    while (arena->current + size > arena->end)
    {
        if (arena->next == 0)
        {
            //ÄÄÄ If we are at the end of a chain, add a new link of the same
            //ÄÄÄ size, or 'size', whichever is larger.
            int new_size = max (arena->size, size + sizeof (IvoryArena));

            arena->next = (IvoryArena *)ivory_alloc (new_size);
            if (!arena->next)
                return 0;

            ivory_arena_initialize (arena->next, new_size);
            arena = arena->next;
            break;
        }
        else
            arena = arena->next;
    }

//ÄÄÄ Now, arena points to a block that can hold our new allocation.
    assert (arena && arena->current + size <= arena->end);

    new_object = arena->current;
    arena->current += size;
    return new_object;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_arena_zalloc
//
// Allocate and zero-out a block from the provided arena.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void *ivory_arena_zalloc (IvoryArena *arena, size_t size)
{
    void *new_arena;

    assertMyth("ivory_arena_zalloc needs valid inputs", arena != 0 && size > 0);

    new_arena = ivory_arena_alloc (arena, size);
    if (!new_arena)
        return 0;

    memset (new_arena, 0, size);
    return new_arena;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_arena_chainlength
//
// Return the length of the arena chain.  If no chaining is
// necessary, the length will be 0.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int ivory_arena_chainlength (const IvoryArena *arena)
{
    int chain_count = 0;

    assertMyth("ivory_arena_chainlength needs arena", arena != 0);

    //ÄÄÄ Iterate through the arena list, accumulating the count.
    while ((arena = arena->next) != 0)
        chain_count++;

    return chain_count;
}

//°±² End of module - ivarena.c ²±°
