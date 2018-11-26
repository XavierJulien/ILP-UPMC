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
    ILP_Object ilptmp336;
    ilptmp336 = ILP_Float2ILP (2.2);

    {
      ILP_Object f11 = ilptmp336;
      {
	ILP_Object ilptmp337;
	ilptmp337 = ILP_Float2ILP (6.3);

	{
	  ILP_Object f22 = ilptmp337;
	  {
	    ILP_Object ilptmp338;
	    ILP_Object ilptmp339;
	    ilptmp338 = f11;
	    ilptmp339 = f22;
	    return ILP_Plus (ilptmp338, ilptmp339);
	  }

	}
      }

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
