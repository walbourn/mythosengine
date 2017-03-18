//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùù°°°°°°ùùùùù°°°°°°°ùùùù°°ùùùùù°°°ù°°°°°°°°°°ùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùù°±°ùùùù°ùù°±°ùùùù°±ùùù°±°ùùùù°±°ù°±°ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùù±°±ùùùù±ùù±°±ùùùùù±±ùù±°±°ùùù±°±ù±°±ùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùù±²±±°±±²ùù±²±±°±±²±±ùù±²±±°ùù²±±ù±²±±°±±²ùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùù±²±ùùùùùùù²±ùùùùù±²±ùù±²±ùù²ù±²±ù±²±ùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùù²±²ùùùùùùù²±²ùùùù²±²ùù²±²ùùù²²±²ù²±²ùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùù²²²ùùùùùùù²²²ùùùù²²²ùù²²²ùùùù²²²ù²²²²²²²²²²ùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùù Microsoft Windows 95/98/NT Version ùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùCopyright (c) 1996-1999 by Dan Higdon, Tim Little, and Chuck Walbournùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùù
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
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
// Created by Sean Gallagher
//
// pnlbox.cpp
//
//ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//
//                                Includes
//
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

#define WIN32_LEAN_AND_MEAN
#include <stdlib.h>
#include <assert.h>

#include <pane.hpp>

//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±
//
//                                 Code
//
//±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±±

//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°±  Constructors/Destructors  ±°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - Constructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
PaneListBox::PaneListBox(VngoVport *gvp, const char *f_type) :
    strings(0),
    gvport(gvp),
    edata_ptr(0)
{
    memset(font_type, 0, sizeof(BYTE) * GBERG_MAX_NAME);
    strncpy(font_type, f_type, GBERG_MAX_NAME-1);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - Destructor
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
PaneListBox::~PaneListBox()
{
    release();
    gvport = 0;
}


//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°±  Operations  ±°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°
//°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - init
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
BOOL PaneListBox::init(short sx, short sy, ushort maxlen, ushort maxentries,
                       ulong sedata, ushort spc)
{
    if (strings || edata_ptr)
        release();

    if (!gvport)
        return FALSE;

    vrc.x = 0;
    vrc.y = 0;
    vrc.dx = gvport->vbuff.width;
    vrc.dy = gvport->vbuff.height;

    screen_x = sx;
    screen_y = sy;

    spacing = spc;
    count=0;
    cur_sel=0;
    first_visible=0;
    hilite_cur_sel = TRUE;

    max_string_len = maxlen;
    max_string_entries = maxentries;
    sizeof_edata = sedata;

    fg=bg=0;

//ÄÄÄ Get the font height and width
    GBergFontInfo fi;
    if (gberg_info_font(font_type, &fi))
        return FALSE;

    row_height = fi.height + (spacing*2);
    font_width = fi.width;

//ÄÄÄ Allocate string buffer
    strings = new char [max_string_len * max_string_entries];
    if (!strings)
        return FALSE;
    memset(strings, 0, sizeof(BYTE)* max_string_len * max_string_entries);

//ÄÄÄ get the number of rows visible based on the font size
    num_visible = ushort(vrc.dy / row_height);

//ÄÄÄ Handle external data
    if (sizeof_edata)
    {
        edata_ptr = new char [sizeof_edata * max_string_entries];
        if (!edata_ptr)
            return FALSE;

        memset(edata_ptr, 0, sizeof(BYTE) * sizeof_edata * max_string_entries);
    }

    return TRUE;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - release
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::release()
{
    if (strings)
    {
        delete [] strings;
        strings=0;
    }

    if (edata_ptr)
    {
        delete [] edata_ptr;
        edata_ptr=0;
    }
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - render
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::render()
{
    // if we don't have a vport,  there's no real reason to hang around
    if (!gvport)
        return;

    int waslocked = gvport->lock();

    if (bg != VNGO_TRANSPARENT)
        gvport->reset(bg);

    GBergText gt(gvport);

    gberg_select_font(font_type);

    char *sptr = strings;
    int x = 0;

    // add the code to show only the visible ones here.....
    sptr += first_visible * max_string_len;

    int y = 0;
    // show only the visible rows

    ulong num_to_draw;
    if (first_visible+num_visible < count)
        num_to_draw = num_visible;
    else
        num_to_draw = count;

    for (ulong k=first_visible; k < ulong(first_visible+num_to_draw); k++, y++)
//    for (ulong k=first_visible; k <= ulong(first_visible+num_to_draw); k++, y++)
//    for (ulong k=first_visible; k <= ulong(first_visible+num_visible); k++, y++)
    {
        // if the current row is currently selected,  then highlight it...
        if (k == cur_sel && hilite_cur_sel)
            gberg_color(bg,fg);
        else
            gberg_color(fg,bg);

        gt.out(x, (y*row_height) + spacing, sptr);
        sptr += max_string_len;
    }

    // return to normal foreground and background color
    gberg_color(fg,bg);

    if (!waslocked)
        gvport->unlock();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - get_pick_index
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
int PaneListBox::get_pick_index(int x, int y)
{
    // x and y are in screen coords,  so we need to
    // convert them into something we can use.

    int new_x, new_y;
    int sel = -1;

    new_x = x - screen_x;
    new_y = y - screen_y;

    // things are really hosed if this happens...
    if (new_y < 0)
        return -1;

    if ((new_x < vrc.x) || (new_x > (vrc.x + vrc.dx)) ||
        (new_y < vrc.y) || (new_y > (vrc.y + vrc.dy)) )
        return -1;

//    if (new_y > (int)(num_visible * row_height))
    if (new_y > (int)((num_visible+1) * row_height))
        return -1;

    sel = first_visible + ((ulong)new_y / row_height);

    // make sure our new selected index is visible
    if (sel > (int)(first_visible + num_visible))
        return -1;

    // if they pick something off the bottom of the list, then return
    // an error
    if (sel >= (int)count)
        return -1;

    return sel;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - get_item_data
//
// returns a pointer the the extra data allocated for that index
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void *PaneListBox::get_item_data(ulong index)
{
    if (index >= (ulong)count)
        return NULL;

    BYTE *sptr = (BYTE *)edata_ptr;

    sptr += index * sizeof_edata;

    return (void *)sptr;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - get_selected_item
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::get_selected_item(ulong index, char *dest)
{
    const char *sptr = strings + index * max_string_len;

    strcpy (dest, sptr);
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - set_selected_item
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::set_selected_item(ulong index, char *src)
{
    char *sptr = strings + index * max_string_len;

    memset(sptr, 0, sizeof(char)*max_string_len);

    strncpy (sptr, src, sizeof(char)*max_string_len-1);
}



//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - set_cur_sel
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ushort PaneListBox::set_cur_sel(ulong index)
{
    if ((index) >= 0 && (index < max_string_entries))
    {
        cur_sel = (ushort)index;

        ushort bottom = get_bottom_index();

        ushort lv = first_visible+num_visible;

        if (cur_sel < first_visible)
            first_visible =(ushort) index;
        else if (cur_sel > lv)
        {
            first_visible = (ushort)index;
            if (lv > bottom)
                first_visible = cur_sel - (lv - bottom);
        }

        return 1;
    }
    else
        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - set_font
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ushort PaneListBox::set_font(const char *font)
{
    GBergFontInfo fi;
    if (gberg_info_font(font, &fi))
    {
        return 0;
    }

    row_height = fi.height + (spacing*2);
    font_width = fi.width;

    num_visible = ushort(vrc.dy / row_height);

    strcpy(font_type, font);

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - set_top_index
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong PaneListBox::set_top_index(ulong index)
{
    if ((index >= 0) && (index < max_string_entries))
    {
        first_visible = (ushort)index;
        return 1;
    }
    else
        return 0;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                               °°° Private °°°
// PaneListBox - delete_data
//
// Deletes the user defined extra data at the given index position
// Note : Assumes that the count has already been decremented.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong PaneListBox::delete_data(ulong index)
{
    int bindex = index * sizeof_edata;

    BYTE *tptr = (BYTE *)edata_ptr;

    memmove (tptr + bindex,
             tptr + bindex + sizeof_edata,
             sizeof_edata * (max_string_entries - (index + 1)));

    memset (tptr + sizeof_edata * (max_string_entries - 1), 0, sizeof_edata);

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                               °°° Private °°°
// PaneListBox - insert_data
//
// Inserts a user defined extra data at the given index position.
// If the void pointer is NULL,  then we'll insert a blank structure...
// Note : Assumes that the count has already been incremented.
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong PaneListBox::insert_data(ulong index, void *extra)
{
    int bindex = index * sizeof_edata;

    BYTE *sptr = (BYTE *)edata_ptr + bindex;
    BYTE *dptr = (BYTE *)edata_ptr + bindex + sizeof_edata;

    memmove (dptr,
             sptr,
             sizeof(BYTE) * sizeof_edata * (max_string_entries - (index + 1)));

    if (extra)
        memcpy (sptr, extra, sizeof(BYTE) * sizeof_edata);
    else
        memset (sptr, 0, sizeof(BYTE) * sizeof_edata);

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - add_string
//
// Adds a string to the end of the list box
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ushort PaneListBox::add_string(const char *new_str, void *extra)
{
    return insert_string (count, new_str, extra);
}

#if 0
ushort PaneListBox::add_string(ulong id, void *extra)
{
    char buff[128];

    LoadString(hInst, id, buff, sizeof(buff));

    return insert_string (count, buff, extra);
}
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - delete_string
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ushort PaneListBox::delete_string(ulong index)
{
    if ((count == 0) || (index > get_bottom_index()))
        return 0;

    int bindex = index * max_string_len;

    memmove (strings + bindex,
             strings + bindex + max_string_len,
             max_string_len * (max_string_entries - (index + 1)));

    memset (strings + max_string_len * (max_string_entries - 1),
            0,
            max_string_len);

    // the all important count decrement!!!
    count--;

    // Here's where we'll delete the extra data that is associated with a
    // list box entry.

    if (edata_ptr)
        delete_data (index);

    // If we've just deleted the currently selected one,  then make the
    // previous row be the currently selected.
    if ((index == cur_sel) && count)
    {
        if (cur_sel != 0)
            cur_sel--;
    }

    return 1;
}

#if 0
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
//                               °°° Private °°°
// PaneListBox - find_insertion_index
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ulong PaneListBox::find_insertion_index(ulong ind)
{
    ulong res = 0;

    for (ulong i=0; i < get_count(); i++)
    {
        void *data;
        AbramsForceRec *ptr;
        data = get_item_data(i);
        ptr = (AbramsForceRec *)data;

        if (ptr->index >= ind)
        {
            res = (ulong)i;
            return res;
        }
    }

    if (res < ind)
        res = get_count();

    return res;
}
#endif

//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - insert_string
//
// Inserts a string at the given index position
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
ushort PaneListBox::insert_string(ulong index, const char *ins_str, void *extra)
{
    if ((ulong)count == max_string_entries)
        return 0;

    int bindex = index * max_string_len;

    char *sptr = strings + bindex;
    char *dptr = strings + bindex + max_string_len;

    memmove (dptr,
             sptr,
             sizeof(char) * max_string_len * (max_string_entries - (index + 1)));

    strncpy (sptr, ins_str, sizeof(char) * (max_string_len - 1));
    sptr[sizeof(char)*max_string_len-1] = '\0';

    // the all important count increment!!!
    count++;

    // Here's where we'll insert the extra data that is associated with a
    // list box entry.

    if (edata_ptr)
        insert_data(index, extra);

    return 1;
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - reset_content
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::reset_content()
{
    count = 0;
    cur_sel = 0;
    first_visible = 0;
    memset(strings, 0, sizeof(BYTE)*max_string_len*max_string_entries);

    if (edata_ptr)
    {
        memset(edata_ptr, 0, sizeof(BYTE) * sizeof_edata * max_string_entries);
    }

    render();
}


//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
// PaneListBox - scroll
//ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ
void PaneListBox::scroll(direction_t dir)
{
    if (!gvport)
        return;

    switch(dir)
    {
        case UP:
            {
                ulong top = get_top_index();
                top--;
                set_top_index(top);
            }

            break;

        case DOWN:
            {

                ulong top = get_top_index();

                ulong last_visible = get_count();

                if ((top + get_num_visible()) < last_visible)
                {
                    top++;
                    set_top_index(top);
                }
            }

            break;

        default:
            return;
    }

    render();
}

//°±² eof - pnlbox.cpp ²±°
