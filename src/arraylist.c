/**
 *  @file arraylist.c
 *  @author championsurfer3044
 *  @date 03 Jun 2019 
 *  @brief 
 *
 *  LICENSE:-
 *  The MIT License (MIT)
 *  Copyright (c) 2019 Mrunmoy Samal
 *
 *  Permission is hereby granted, free of charge, to any person
 *  obtaining a copy of this software and associated documentation
 *  files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use,
 *  copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom
 *  the Software is furnished to do so, subject to the following
 *  conditions:
 *
 *  The above copyright notice and this permission notice shall
 *  be included in all copies or substantial portions of the
 *  Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 *  OR OTHER DEALINGS IN THE SOFTWARE.
 */


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "arraylist.h"

/*
*----------------------------------------------------------------------
*   Private Defines
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Macros
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Data Types
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Variables
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Variables (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Private Constants (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Function Prototypes (static)
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/
static void add_elem(struct array_list_t *self, int item) {
    if (!self) return;

    if (self->count == self->size) { // time to grow arraylist
        self->size *= 2;
        self->array = (int *)realloc(self->array, self->size * sizeof(int));
        assert(self->array);
    }
    self->array[self->count++] = item;
}

static bool contains(struct array_list_t *self, int elem) {
    if (!self) return false;

    for (int i = 0; i < self->count; i++) {
        if (self->array[i] == elem)
            return true;
    }
    return false;
}

static void clear(struct array_list_t *self) {
    if (!self) return;
    self->count = 0;
}

static int get(struct array_list_t *self, int index) {
    if (!self || index >= self->count) return -1;

    return self->array[index];
}

static void remove_elem_at(struct array_list_t *self, int index) {
    if (!self || index >= self->count) return;

    for (int i = index; i < self->count-1; i++) {
        self->array[i] = self->array[i+1];
    }
    self->count--;
}

static void remove_elem(struct array_list_t *self, int elem) {
    if (!self) return;
    for (int i = 0; i < self->count; i++) {
        if (self->array[i] == elem) {
            for (int j = i; j < self->count-1; j++) {
                self->array[j] = self->array[j+1];
            }
            self->count--;
            return;
        }
    }
}

/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/

array_list_t *new_arraylist(const int list_size) {
    if (!list_size) return NULL;

    array_list_t *obj = (array_list_t *)malloc (sizeof(array_list_t));
    assert(obj);
    obj->array = (int *)malloc(list_size * sizeof(int));
    assert(obj->array);

    obj->size     = list_size;
    obj->add      = add_elem;
    obj->contains = contains;
    obj->clear    = clear;
    obj->get      = get;
    obj->remove_at= remove_elem_at;
    obj->remove   = remove_elem;

    return obj;
}

void destroy_arraylist(array_list_t *obj) {
    if (!obj) return;
    free(obj->array);
    free(obj);
}
