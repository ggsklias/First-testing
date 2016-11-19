int foo;

/* This is called from native code, after a fork.
 * We are testing that analysis kicks in when we enter this function. */
void run_child_code(void)
{
  foo = 42;
}


/* This is called from native code in fork-parent path. */
void run_parent_code(void)
{
  foo = 89;
}
