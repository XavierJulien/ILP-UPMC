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
    ILP_Object ilptmp312;
    ilptmp312 = ILP_Integer2ILP (3);

    {
      ILP_Object x1 = ilptmp312;
      {
	ILP_Object ilptmp313;
	{
	  ILP_Object ilptmp314;
	  ILP_Object ilptmp315;
	  ilptmp314 = x1;
	  ilptmp315 = x1;
	  ilptmp313 = ILP_Plus (ilptmp314, ilptmp315);
	}

	{
	  ILP_Object x2 = ilptmp313;
	  {
	    ILP_Object ilptmp316;
	    ILP_Object ilptmp317;
	    ilptmp316 = x2;
	    ilptmp317 = x2;
	    return ILP_Times (ilptmp316, ilptmp317);
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
