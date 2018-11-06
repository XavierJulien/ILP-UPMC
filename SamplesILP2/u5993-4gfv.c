#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object apply;
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__apply (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp494;
    ILP_Object ilptmp495;
    ilptmp494 = ILP_Integer2ILP (2);
    ilptmp495 = x1;
    return ILP_Times (ilptmp494, ilptmp495);
  }
}

struct ILP_Closure deuxfois_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__deuxfois,
    1,
    {NULL}}}
};

ILP_Object
ilp__apply (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3)
{
  {
    ILP_Object ilptmp496;
    ILP_Object ilptmp497;
    ilptmp496 = f2;
    ilptmp497 = x3;
    return ILP_invoke (ilptmp496, 1, ilptmp497);
  }
}

struct ILP_Closure apply_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__apply,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp498;
    ILP_Object ilptmp499;
    {
      ILP_Object ilptmp500;
      ILP_Object ilptmp501;
      ilptmp500 = (ILP_Object) & deuxfois_closure_object;
      ilptmp501 = ILP_Integer2ILP (3000);
      ilptmp498 = ilp__apply (NULL, ilptmp500, ilptmp501);
    }
    ilptmp499 = ILP_Integer2ILP (7);
    return ILP_Minus (ilptmp498, ilptmp499);
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
