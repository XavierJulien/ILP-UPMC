#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;
ILP_Object x;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp1;
    {
      ILP_Object ilptmp2;
      ilptmp2 = ILP_Integer2ILP (12);
      ilptmp1 = (x = ilptmp2);
    }
    {
      ILP_Object ilptmp3;
      {
	ILP_Object ilptmp4;
	ILP_Object ilptmp5;
	ilptmp4 = ILP_Integer2ILP (3);
	ilptmp5 = x;
	ilptmp3 = ILP_Times (ilptmp4, ilptmp5);
      }

      {
	ILP_Object x_11 = ilptmp3;
	{
	  ILP_Object ilptmp6;
	  ILP_Object ilptmp7;
	  ilptmp6 = ILP_Integer2ILP (3);
	  ilptmp7 = x_11;
	  ilptmp1 = ILP_Times (ilptmp6, ilptmp7);
	}

      }
    }
    {
      ILP_Object ilptmp8;
      ilptmp8 = x;
      ilptmp1 = ILP_print (ilptmp8);
    }
    return ilptmp1;
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
