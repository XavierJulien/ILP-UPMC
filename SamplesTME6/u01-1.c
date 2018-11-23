#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp636;
    {
      ILP_Object ilptmp637;
      ILP_Object ilptmp638;
      ilptmp637 = ILP_Integer2ILP (2);
      ilptmp638 = ILP_Integer2ILP (2);
      ilptmp636 = ILP_Equal (ilptmp637, ilptmp638);
    }
    if (ILP_isEquivalentToTrue (ilptmp636))
      {
	return ILP_Integer2ILP (3);

      }
    else
      {
	return ILP_FALSE;

      }
  }

}

static ILP_Object
ilp_caught_program ()
{
  struct ILP_catcher *current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if (0 == setjmp (new_catcher._jmp_buf))
    {
      ILP_establish_catcher (&new_catcher);
      return ilp_program ();
    };
  return ILP_current_exception;
}

int
main (int argc, char *argv[])
{
  ILP_START_GC;
  ILP_print (ilp_caught_program ());
  ILP_newline ();
  return EXIT_SUCCESS;
}
