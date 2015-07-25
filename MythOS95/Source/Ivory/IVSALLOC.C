//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//
//                   Ivory -- A Memory Management Library
//
//                     Microsoft Windows 95/98/NT Version
//
//  Copyright (c) 1994-1999 by Dan Higdon, Tim Little, and Chuck Walbourn
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// This file and all associated files are subject to the terms of the
// GNU Lesser General Public License version 2 as published by the
// Free Software Foundation (http://www.gnu.org).   They remain the
// property of the authors: Dan Higdon, Tim Little, and Chuck Walbourn.
// See LICENSE.TXT in the distribution for a copy of this license.
//
// THE AUTHORS MAKE NO WARRANTIES, EXPRESS OR IMPLIED, AS TO THE CORRECTNESS
// OF THIS CODE OR ANY DERIVATIVE WORKS WHICH INCORPORATE IT.  THE AUTHORS
// PROVIDE THE CODE ON AN "AS-IS" BASIS AND EXPLICITLY DISCLAIMS ANY
// LIABILITY, INCLUDING CONSEQUENTIAL AND INCIDENTAL DAMAGES FOR ERRORS,
// OMISSIONS, AND OTHER PROBLEMS IN THE CODE.
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
//                        http://www.mythos-engine.org/
//
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//
// Created by Dan Higdon
//
// ivsalloc.c
//
// Ivory Sub Allocation - Allocation in a fixed, specified region
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <assert.h>

#include "ivory.h"

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Equates
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

// This is the size of a single page of memory.  It MUST be a power of 2!
#define PAGE_SIZE  (4096*4)
#define PAGE_MASK  (~(PAGE_SIZE-1))

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                               Routines
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// A routine to construct a dword from two words
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
#define MAKEDWORD(a,b) ((((dword)a) << 16) | (b))

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_sub_initialize
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ivory_sub_initialize (IvorySubAlloc *memory, size_t mem_size)
{
    assertMyth("ivory_sub_initialize needs valid input",
               memory != 0 && (mem_size > sizeof (IvorySubAlloc) + 1024));

//ÄÄÄ Once we have the block, set up the allocation header
//ÄÄÄ Fill in the "public" fields
    memory->memory_size = mem_size - sizeof (*memory);

//ÄÄÄ Initialize the counters
#ifdef DEBUG
    memory->allocation_count = 0;
    memory->free_count = 0;
    memory->memory_alloced = 0;
#endif

//ÄÄÄ Now, the internal fields (memory is allocated from the top)
    memory->next_free = (byte *)memory + mem_size - sizeof (AllocationHeader);
    memory->freelist = 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_sub_terminate
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ivory_sub_terminate (IvorySubAlloc *memmory)
{
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_alloc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void *ivory_sub_alloc (IvorySubAlloc *memory, size_t size)
{
    AllocationHeader **pph, *ph;
        size_t  alloc_size;

    assertMyth("ivory_sub_alloc needs valid inputs", memory != 0 && size > 0);

//ÄÄÄ Now, make sure there is room for the AllocationHeader, and
//ÄÄÄ then round the size to the nearest (greater) 16 byte alignment
    alloc_size  = size + sizeof (AllocationHeader) + 0x0f;
    alloc_size &= ~0x0f;

//ÄÄÄ First, scan the free list to see if we can find a suitable block
//ÄÄÄ Will this be fast enough, with the double pointer scheme?
    pph = &memory->freelist;
    ph  = *pph;

    while (ph && ph->size < alloc_size)
    {
        pph = &ph->next;
        ph  = ph->next;
    }

//ÄÄÄ If we have found a suitable block....
    if (ph)
    {
        //ÄÄÄ If this block is large enough to split, do so
        if (ph->size - alloc_size > sizeof (AllocationHeader) + 16)
        {
            //ÄÄÄ Remove our block from the end, so as to preserve the chain.
            ph->size -= alloc_size;
            ph = (AllocationHeader *)((char *)ph + ph->size);
        }
        //ÄÄÄ Otherwise, claim it as our own by overwriting
        //ÄÄÄ whatever pointed to it.
        else
            *pph = ph->next;
    }
    else
    {
        //ÄÄÄ Allocate a new block from the unused memory

        //ÄÄÄ If there isn't enough memory....
        if (memory->next_free - alloc_size <= &memory->wildspace_start)
        {
            return 0;
        }
        else
        {
            //ÄÄÄ Otherwise, take as much as we need (but no more!)
            //ÄÄÄ Allocate the memory from wildspace
            memory->next_free -= alloc_size;
            ph = (AllocationHeader *)memory->next_free;
        }
    }

//ÄÄÄ Now, 'ph' points to a usable chunk of memory.
    assert (ph != 0);
    ph->size = alloc_size;
    ph->next = 0;

#ifdef DEBUG
    //ÄÄÄ Now, return the area past the buffer (our user's memory)
    memory->allocation_count++;
    memory->memory_alloced += alloc_size;

    //ÄÄÄ Make sure the block actually contains as many bytes as we want!
    //ÄÄÄ (Testing by protfault! :-)
    memset (ph + 1, 0, size);
#endif

    return ph + 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_sub_zalloc
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void *ivory_sub_zalloc (IvorySubAlloc *memory, size_t size)
{
    void *ptr;

    assertMyth("ivory_sub_zalloc needs valid inputs", memory != 0 && size > 0);

    ptr = ivory_sub_alloc (memory, size);
    if (!ptr)
        return 0;

    memset (ptr, 0, size);
    return ptr;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// ivory_sub_free
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void ivory_sub_free (IvorySubAlloc *memory, void **ptr)
{
    AllocationHeader    *freeblk, *prevprev, *prevblk, *nextblk;

    assertMyth("ivory_sub_free needs valid inputs", memory != 0 && ptr != 0 && *ptr != 0);

//ÄÄÄ Make sure this is our pointer!
    assertMyth ("ivory_sub_free given pointer out of range",
                *ptr > (void *)memory);
    assertMyth ("ivory_sub_free given pointer out of range",
                *ptr < (void *)(((char *)memory) + memory->memory_size));

//ÄÄÄ Get a pointer to the header info in front of this block
    freeblk = (AllocationHeader *)*ptr;
    freeblk--;

//ÄÄÄ Record the free for statistical purposes
#ifdef DEBUG
    memory->memory_alloced -= freeblk->size;
    memory->free_count++;
#endif

//ÄÄÄ Scan until we are past all free blocks lower in memory than
//ÄÄÄ ourselves.  This is the most expensive part of this deallocator.
//ÄÄÄ Note: the '== 0' case is ok, since 0 is not greater than anything!
    prevprev  = prevblk = 0;
    nextblk   = memory->freelist;
    while (nextblk > freeblk)
    {
        prevprev = prevblk;
        prevblk  = nextblk;
        nextblk  = nextblk->next;
    }

    assertMyth("ivory_sub_free told to free memory already in free list",
               nextblk != freeblk);

//ÄÄÄ Now, we have either a point in the list to add our link, or
//ÄÄÄ the end of the list.
//ÄÄÄ 'ph2' points to the link we want to point to our
//ÄÄÄ free region, and prevblk points to the block containing
//ÄÄÄ that pointer.
    assert ((prevblk == 0 && nextblk == memory->freelist) ||
            (prevblk != 0 && prevblk->next == nextblk));
    assert (prevprev == 0 || prevprev->next == prevblk);

//ÄÄÄ If the next block is adjacent, merge.  Otherwise chain it.
    if (nextblk)
    {
        if (freeblk == end_of (nextblk))
        {
            nextblk->size += freeblk->size;
            freeblk = nextblk;
        }
        else
            freeblk->next = nextblk;
    }
#ifdef DEBUG
    else
    {
        assert (freeblk->next == 0);
    }
#endif

//ÄÄÄ At this point, we know that....
    assert (freeblk == nextblk ||       // We have merged, or
            freeblk->next == nextblk);  // we are linked in.

//ÄÄÄ If there's a previous block, and it's adjacent, eat our block
    if (prevblk)
    {
        if (prevblk == end_of (freeblk))
        {
            freeblk->size += prevblk->size;

            //ÄÄÄ Patch our pointer, which is the freelist head if there is no previous block
            if (prevprev)
                prevprev->next = freeblk;
            else
                memory->freelist = freeblk;

            //ÄÄÄ Back up our previous block pointer for the next step
            prevblk = prevprev;
        }
        //ÄÄÄ Otherwise, put our block into place
        else
            prevblk->next = freeblk;
    }
    //ÄÄÄ Otherwise, set this as the first block
    else
        memory->freelist = freeblk;


//ÄÄÄ If our block is now the last thing in memory, return it to wildspace
    if (freeblk == (AllocationHeader *)memory->next_free)
    {
        memory->next_free += freeblk->size;

        //ÄÄÄ Make sure that we no longer point at this memory.
        if (prevblk)
            prevblk->next = 0;
        else
            memory->freelist = 0;
    }

//ÄÄÄ Lastly, zero out the pointer so we don't get into trouble later
    *ptr = 0;
}

//°±² End of module - ivsalloc.c ²±°
