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
    ILP_Object ilptmp542;
    {
      ILP_Object ilptmp543;
      {
	ILP_Object ilptmp544;
	ILP_Object ilptmp545;
	ilptmp544 = ILP_Integer2ILP (1);
	ilptmp545 = ILP_Integer2ILP (1);
	ilptmp543 = ILP_Equal (ilptmp544, ilptmp545);
      }
      if (ILP_isEquivalentToTrue (ilptmp543))
	{
	  ilptmp542 = ILP_TRUE;

	}
      else
	{
	  ilptmp542 = ILP_FALSE;

	}
    }
    if (ILP_isEquivalentToTrue (ilptmp542))
      {
	return ILP_Integer2ILP (3);

      }
    else
      {
	return ILP_Integer2ILP (4);

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
