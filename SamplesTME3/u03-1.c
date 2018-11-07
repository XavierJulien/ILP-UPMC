#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;
ILP_Object makeVector;
ILP_Object vectorGet;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp11;
    ilptmp11 = ILP_Integer2ILP (2);

    {
      ILP_Object x1 = ilptmp11;
      {
	ILP_Object ilptmp12;
	{
	  ILP_Object ilptmp13;
	  ILP_Object ilptmp14;
	  ilptmp13 = ILP_Integer2ILP (5);
	  ilptmp14 = x1;
	  ilptmp12 = ILP_makeVector (ilptmp13, ilptmp14);
	}

	{
	  ILP_Object sin2 = ilptmp12;
	  {
	    ILP_Object ilptmp15;
	    {
	      ILP_Object ilptmp16;
	      ILP_Object ilptmp17;
	      ilptmp16 = sin2;
	      ilptmp17 = ILP_Integer2ILP (1);
	      ilptmp15 = ILP_vectorGet (ilptmp16, ilptmp17);
	    }
	    return ILP_print (ilptmp15);
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
