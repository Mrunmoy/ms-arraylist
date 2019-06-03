# ArrayList implementation in C

### API Description:
#### Creation/Deletion:
`array_list_t *new_arraylist(const int list_size)` creates a new dynamically allocated pointer to an integer arraylist of size list_size.

`void destroy_arraylist(array_list_t *obj)` releases memory allocated for the previously created arraylist.

#### Member Functions:
- `void (*add)(struct array_list_t *self, int item)` Adds an integer element to the arraylist.
- `void (*add_at)(struct array_list_t *self, int index, int item)` Adds an integer element to the arraylist at an index.
- `bool (*contains)(struct array_list_t *self, int elem)` Checks if the arraylist contains the given element.
- `void (*clear)(struct array_list_t *self)` Clears the arraylist.
- `int (*get)(struct array_list_t *self, int index)` Returns the value at given index, -1 if value doesnt exist. (This needs to be fixed to be able to use negative numbers. Probably I will change the return code to bool and return the value (if found) in the parameter list.)
- `void (*remove_at)(struct array_list_t *self, int index)` Removes an element at an index. 
- `void (*remove)(struct array_list_t *self, int elem)` Removes an element if exists.

#### Member Variables:
- `count` Gives the number of elements in the arraylist (mutable, please do not modify directly).
- `size` Gives the total size of the arraylist (mutable, please do not modify directly).


### Usage Example:
```
  array_list_t *obj = new_arraylist(3);
  assert(obj);

  srand(time(0));

  print_list(obj);

  for (int i = 0;i < 3; i++) {
    obj->add_at(obj, i, rand() % 23);
  }

  print_list(obj);

  for (int i = 0;i < 20; i++) {
    obj->add(obj, rand() % 23);
  }

  print_list(obj);

  destroy_arraylist(obj);
  obj = NULL;

  ```


The test file `findpos.c` attempts to solve [this](https://www.hackerrank.com/challenges/java-arraylist/problem) hackerrank problem.
