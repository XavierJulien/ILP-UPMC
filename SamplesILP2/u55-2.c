#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object dou_ble;

/* Global prototypes */
ILP_Object ilp__dou_ble (ILP_Closure ilp_useless, ILP_Object x1);

/* Global functions */

ILP_Object
ilp__dou_ble (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp54;
    ILP_Object ilptmp55;
    ilptmp54 = ILP_Integer2ILP (2);
    ilptmp55 = x1;
    return ILP_Times (ilptmp54, ilptmp55);
  }
}

struct ILP_Closure dou_ble_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__dou_ble,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp56;
    {
      ILP_Object ilptmp57;
      ILP_Object ilptmp58;
      ilptmp57 = ILP_Integer2ILP (52);
      ilptmp58 = ILP_Integer2ILP (3);
      ilptmp56 = ILP_Plus (ilptmp57, ilptmp58);
    }
    return ilp__dou_ble (NULL, ilptmp56);
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
