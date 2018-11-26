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
    ILP_Object ilptmp363;
    {
      ILP_Object ilptmp364;
      ilptmp364 = ILP_String2ILP ("Un, ");
      ilptmp363 = ILP_print (ilptmp364);
    }
    {
      ILP_Object ilptmp365;
      ilptmp365 = ILP_String2ILP ("deux et ");
      ilptmp363 = ILP_print (ilptmp365);
    }
    {
      ILP_Object ilptmp366;
      ilptmp366 = ILP_String2ILP ("trois.");
      ilptmp363 = ILP_print (ilptmp366);
    }
    return ilptmp363;
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
