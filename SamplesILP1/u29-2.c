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
    ILP_Object ilptmp318;
    ILP_Object ilptmp319;
    ilptmp318 = ILP_Integer2ILP (11);
    ilptmp319 = ILP_Integer2ILP (22);

    {
      ILP_Object x1 = ilptmp318;
      ILP_Object y2 = ilptmp319;
      {
	ILP_Object ilptmp320;
	ILP_Object ilptmp321;
	{
	  ILP_Object ilptmp322;
	  ILP_Object ilptmp323;
	  ilptmp322 = x1;
	  ilptmp323 = y2;
	  ilptmp320 = ILP_Plus (ilptmp322, ilptmp323);
	}
	{
	  ILP_Object ilptmp324;
	  ILP_Object ilptmp325;
	  ilptmp324 = x1;
	  ilptmp325 = y2;
	  ilptmp321 = ILP_Times (ilptmp324, ilptmp325);
	}

	{
	  ILP_Object x3 = ilptmp320;
	  ILP_Object y4 = ilptmp321;
	  {
	    ILP_Object ilptmp326;
	    ILP_Object ilptmp327;
	    ilptmp326 = x3;
	    ilptmp327 = y4;
	    return ILP_Times (ilptmp326, ilptmp327);
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
