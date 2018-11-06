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
    ILP_Object ilptmp142;
    ilptmp142 = ILP_Integer2ILP (3);

    {
      ILP_Object x1 = ilptmp142;
      {
	ILP_Object ilptmp143;
	{
	  ILP_Object ilptmp144;
	  ILP_Object ilptmp145;
	  ilptmp144 = x1;
	  ilptmp145 = x1;
	  ilptmp143 = ILP_Plus (ilptmp144, ilptmp145);
	}

	{
	  ILP_Object x2 = ilptmp143;
	  {
	    ILP_Object ilptmp146;
	    ILP_Object ilptmp147;
	    ilptmp146 = x2;
	    ilptmp147 = x2;
	    return ILP_Times (ilptmp146, ilptmp147);
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
