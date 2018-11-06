#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object f;

/* Global prototypes */
ILP_Object ilp__f (ILP_Closure ilp_useless, ILP_Object ma_3angle1);

/* Global functions */

ILP_Object
ilp__f (ILP_Closure ilp_useless, ILP_Object ma_3angle1)
{
  {
    ILP_Object ilptmp355;
    ILP_Object ilptmp356;
    ilptmp355 = ma_3angle1;
    ilptmp356 = ILP_Integer2ILP (3);
    return ILP_Divide (ilptmp355, ilptmp356);
  }
}

struct ILP_Closure f_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp357;
    {
      ILP_Object ilptmp358;
      ILP_Object ilptmp359;
      ilptmp358 = ILP_Integer2ILP (3);
      ilptmp359 = ILP_Integer2ILP (5491);
      ilptmp357 = ILP_Times (ilptmp358, ilptmp359);
    }
    return ilp__f (NULL, ilptmp357);
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
