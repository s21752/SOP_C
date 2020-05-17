#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void makeChildren (int current_depth, int tree_depth);

#define INITIAL_LEVEL -1

int main ()
{
  printf ("Hello world!\n");

  makeChildren (INITIAL_LEVEL, 2);

  return 0;
}

void makeChildren (int current_depth, int tree_depth)
{
  current_depth++;

  if (current_depth == tree_depth)
    {
      exit (0);
    }

  pid_t child_a, child_b, wait_pid;

  child_a = fork ();

  if (child_a == 0)
    {
      // child a code
      makeChildren(current_depth, tree_depth);
    }
  else
    {
      child_b = fork ();
      if (child_b == 0)
	{
	  // child b code
	  makeChildren(current_depth, tree_depth);
	}
      else
	{
	  // parent code
	  printf ("\n\ndepth level %d", current_depth);
	  printf (" parent pid: %d, child a pid: %d, child b pid: %d\n",
		  getpid (), child_a, child_b);

	// wait for all children to exit
	  while ((wait_pid = wait (0)) > 0);
	}
    }
}
