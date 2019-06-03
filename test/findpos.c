/**
 *  @file findpos.c
 *  @author sam
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
 *
 *  This is an attempted implementation for problem at
 *  https://www.hackerrank.com/challenges/java-arraylist/problem
 */


/*
*----------------------------------------------------------------------
*   Include Files
*----------------------------------------------------------------------
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
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
extern void print_list(array_list_t *obj);
/*
*----------------------------------------------------------------------
*   Private Functions Definitions
*----------------------------------------------------------------------
*/

/*
*----------------------------------------------------------------------
*   Exported Functions Definitions
*----------------------------------------------------------------------
*/


int main()
{
    int num_lines = 0;
    while (scanf("%d\n", &num_lines) != EOF) {
        array_list_t **obj = (array_list_t **)malloc(num_lines*sizeof(array_list_t *));
        assert(obj);
        for (int i=0;i < num_lines; i++) {
            int d = 0;
            scanf("%d ", &d);
            if (d) {
                obj[i] = new_arraylist(d);
                assert(obj[i]);
                int item = 0;
                for (int num_items = 0; num_items < d - 1; num_items++) {
                    scanf("%d ", &item);
                    //printf("got %d, ", item);
                    obj[i]->add(obj[i], item);
                }
                scanf("%d\n", &item);
                //printf("got %d\n", item);
                obj[i]->add(obj[i], item);
            }
            else {
                obj[i] = NULL;
            }
            //print_list(obj[i]);
        }

        int num_queries = 0;
        scanf("%d\n", &num_queries);
        typedef struct query_t {
            int x, y;
        }query_t;

        query_t *queries = malloc(num_queries*sizeof(query_t));
        assert(queries);
        for (int i=0;i < num_queries; i++) {
            int x = 0, y = 0;
            scanf("%d %d\n", &queries[i].x, &queries[i].y);
            //printf("Q.%d {x: %d, y: %d}\n", i, queries[i].x, queries[i].y);
            queries[i].x--; queries[i].y--;
        }

        for (int i=0;i < num_queries; i++) {
            if (queries[i].x >= 0 && queries[i].x < num_lines && queries[i].y >= 0) {
                if (obj[queries[i].x]) {
                    int result = obj[queries[i].x]->get(obj[queries[i].x], queries[i].y);
                    if (result < 0) {
                        printf("[Q.%d] ERROR!\n", i);
                    }
                    else
                        printf("[Q.%d] %d\n", i, result);
                }
                else {
                    printf("[Q.%d] ERROR!\n", i);
                }
            }
            else {
                printf("[Q.%d] ERROR!\n", i);
            }
        }
        free(queries);

        for (int i=0;i < num_lines; i++) {
            destroy_arraylist(obj[i]);
        }
        free(obj);
        fflush(stdin);
    }
    return 0;
}