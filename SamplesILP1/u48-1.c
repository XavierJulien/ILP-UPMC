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
    ILP_Object ilptmp251;
    {
      ILP_Object ilptmp252;
      ilptmp252 = ILP_TRUE;
      if (ILP_isEquivalentToTrue (ilptmp252))
	{
	  {
	    ILP_Object ilptmp253;
	    ilptmp253 = ILP_String2ILP ("invisible");
	    ilptmp251 = ILP_print (ilptmp253);
	  }

	}
      else
	{
	  ilptmp251 = ILP_FALSE;

	}
    }
    ilptmp251 = ILP_Integer2ILP (48);
    return ilptmp251;
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
