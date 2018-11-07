#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;
ILP_Object sinus;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp1;
    ilptmp1 = ILP_Float2ILP (1.0);

    {
      ILP_Object x1 = ilptmp1;
      {
	ILP_Object ilptmp2;
	{
	  ILP_Object ilptmp3;
	  ilptmp3 = x1;
	  ilptmp2 = ILP_sinus (ilptmp3);
	}

	{
	  ILP_Object sin2 = ilptmp2;
	  {
	    ILP_Object ilptmp4;
	    ilptmp4 = sin2;
	    return ILP_print (ilptmp4);
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
