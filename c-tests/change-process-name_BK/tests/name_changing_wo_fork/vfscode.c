#include <stdlib.h>
#include <stdio.h>
int foo;

/* This is called from native code, after a fork.
 * We are testing that analysis kicks in when we enter this function. */

struct {
    char arr1[5];
    char pad1[5];
    char arr2[5];
    char pad2[5];
}data;

void run_child_code(void)
{
  foo = 42;
}

//  char *st1 = &data.arr1[0];
//  char *st2 = &st1[5];
//  printf ("Test %c\n", *st2);
//void run_child_code1(void)
//{
//  foo = 42;
//  char *test = calloc(1,10);
//  free(test);
//  char *st1 = &data.arr1[0];
//  char *st2 = &st1[5];
//  printf ("Test %c\n", *st2, *test);
//}
//
//void run_child_code2(void)
//{
//  foo = 42;
//  char *test = calloc(1,10);
//  char *st1 = &data.arr1[0];
//  char *st2 = &st1[5];
//  printf ("Test %c %c\n", *st2, *test);
//}
//
///* This is called from native code in fork-parent path. */
//void run_parent_code(void)
//{
//  foo = 89;
//}
