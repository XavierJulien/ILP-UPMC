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
    ILP_Object ilptmp15;
    ilptmp15 = ILP_Integer2ILP (50);

    {
      ILP_Object x1 = ilptmp15;
      {
	ILP_Object ilptmp16;
	while (1)
	  {
	    ILP_Object ilptmp17;
	    {
	      ILP_Object ilptmp18;
	      ILP_Object ilptmp19;
	      ilptmp18 = x1;
	      ilptmp19 = ILP_Integer2ILP (52);
	      ilptmp17 = ILP_LessThan (ilptmp18, ilptmp19);
	    }
	    if (ILP_isEquivalentToTrue (ilptmp17))
	      {
		{
		  ILP_Object ilptmp20;
		  {
		    ILP_Object ilptmp21;
		    ILP_Object ilptmp22;
		    ilptmp21 = x1;
		    ilptmp22 = ILP_Integer2ILP (1);
		    ilptmp20 = ILP_Plus (ilptmp21, ilptmp22);
		  }
		  (void) (x1 = ilptmp20);
		}

	      }
	    else
	      {
		break;

	      }
	  }
	ilptmp16 = ILP_FALSE;
	ilptmp16 = x1;
	return ilptmp16;
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
