#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp271;
    ilptmp271 = ILP_Integer2ILP (49);

    {
      ILP_Object x1 = ilptmp271;
      {
	ILP_Object ilptmp272;
	{
	  ILP_Object ilptmp273;
	  ilptmp273 = x1;
	  ilptmp272 = ILP_print (ilptmp273);
	}
	{
	  ILP_Object ilptmp274;
	  {
	    ILP_Object ilptmp275;
	    ILP_Object ilptmp276;
	    ilptmp275 = x1;
	    ilptmp276 = ILP_Integer2ILP (1);
	    ilptmp274 = ILP_Plus (ilptmp275, ilptmp276);
	  }
	  ilptmp272 = (x1 = ilptmp274);
	}
	{
	  ILP_Object ilptmp277;
	  ilptmp277 = x1;
	  ilptmp272 = ILP_print (ilptmp277);
	}
	{
	  ILP_Object ilptmp278;
	  {
	    ILP_Object ilptmp279;
	    ILP_Object ilptmp280;
	    ilptmp279 = x1;
	    ilptmp280 = ILP_Integer2ILP (1);
	    ilptmp278 = ILP_Plus (ilptmp279, ilptmp280);
	  }
	  ilptmp272 = (x1 = ilptmp278);
	}
	{
	  ILP_Object ilptmp281;
	  ilptmp281 = x1;
	  ilptmp272 = ILP_print (ilptmp281);
	}
	ilptmp272 = x1;
	return ilptmp272;
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
