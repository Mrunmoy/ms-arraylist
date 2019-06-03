#ifndef MS_ARRAYLIST_H
#define MS_ARRAYLIST_H

/**
 *  @file arraylist.h
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

#ifdef __cplusplus
extern "C" {
#endif

/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <stdint.h>
#include <stdbool.h>

/*
*----------------------------------------------------------------------
*   Public Data Types
*----------------------------------------------------------------------
*/
typedef struct array_list_t {
    int *array;
    int size;
    int count;
    void (*add)(struct array_list_t *self, int item);
    bool (*contains)(struct array_list_t *self, int elem);
    void (*clear)(struct array_list_t *self);
    int (*get)(struct array_list_t *self, int index);
    void (*remove_at)(struct array_list_t *self, int index);
    void (*remove)(struct array_list_t *self, int elem);
}array_list_t;

/*
*----------------------------------------------------------------------
*   Public Constants (const)
*----------------------------------------------------------------------
*/


/*
*----------------------------------------------------------------------
*   Public Function Prototypes
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Externs
*----------------------------------------------------------------------
*/

array_list_t *new_arraylist(const int list_size);
void destroy_arraylist(array_list_t *obj);


#ifdef __cplusplus
}
#endif

#endif //MS_ARRAYLIST_H
