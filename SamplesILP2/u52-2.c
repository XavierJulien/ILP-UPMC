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
    ILP_Object ilptmp290;
    ilptmp290 = ILP_Integer2ILP (50);

    {
      ILP_Object x1 = ilptmp290;
      {
	ILP_Object ilptmp291;
	while (1)
	  {
	    ILP_Object ilptmp292;
	    {
	      ILP_Object ilptmp293;
	      ILP_Object ilptmp294;
	      ilptmp293 = x1;
	      ilptmp294 = ILP_Integer2ILP (52);
	      ilptmp292 = ILP_LessThan (ilptmp293, ilptmp294);
	    }
	    if (ILP_isEquivalentToTrue (ilptmp292))
	      {
		{
		  ILP_Object ilptmp295;
		  {
		    ILP_Object ilptmp296;
		    ILP_Object ilptmp297;
		    ilptmp296 = x1;
		    ilptmp297 = ILP_Integer2ILP (1);
		    ilptmp295 = ILP_Plus (ilptmp296, ilptmp297);
		  }
		  (void) (x1 = ilptmp295);
		}

	      }
	    else
	      {
		break;

	      }
	  }
	ilptmp291 = ILP_FALSE;
	ilptmp291 = x1;
	return ilptmp291;
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
