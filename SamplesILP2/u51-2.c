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
    ILP_Object ilptmp4;
    ilptmp4 = ILP_Integer2ILP (49);

    {
      ILP_Object x1 = ilptmp4;
      {
	ILP_Object ilptmp5;
	{
	  ILP_Object ilptmp6;
	  ilptmp6 = x1;
	  ilptmp5 = ILP_print (ilptmp6);
	}
	{
	  ILP_Object ilptmp7;
	  {
	    ILP_Object ilptmp8;
	    ILP_Object ilptmp9;
	    ilptmp8 = x1;
	    ilptmp9 = ILP_Integer2ILP (1);
	    ilptmp7 = ILP_Plus (ilptmp8, ilptmp9);
	  }
	  ilptmp5 = (x1 = ilptmp7);
	}
	{
	  ILP_Object ilptmp10;
	  ilptmp10 = x1;
	  ilptmp5 = ILP_print (ilptmp10);
	}
	{
	  ILP_Object ilptmp11;
	  {
	    ILP_Object ilptmp12;
	    ILP_Object ilptmp13;
	    ilptmp12 = x1;
	    ilptmp13 = ILP_Integer2ILP (1);
	    ilptmp11 = ILP_Plus (ilptmp12, ilptmp13);
	  }
	  ilptmp5 = (x1 = ilptmp11);
	}
	{
	  ILP_Object ilptmp14;
	  ilptmp14 = x1;
	  ilptmp5 = ILP_print (ilptmp14);
	}
	ilptmp5 = x1;
	return ilptmp5;
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
