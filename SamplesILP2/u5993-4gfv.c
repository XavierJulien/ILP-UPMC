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
    ILP_Object ilptmp117;
    ILP_Object ilptmp118;
    ilptmp117 = ILP_Integer2ILP (2);
    ilptmp118 = x1;
    return ILP_Times (ilptmp117, ilptmp118);
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
    ILP_Object ilptmp119;
    ILP_Object ilptmp120;
    ilptmp119 = f2;
    ilptmp120 = x3;
    return ILP_invoke (ilptmp119, 1, ilptmp120);
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
    ILP_Object ilptmp121;
    ILP_Object ilptmp122;
    {
      ILP_Object ilptmp123;
      ILP_Object ilptmp124;
      ilptmp123 = (ILP_Object) & deuxfois_closure_object;
      ilptmp124 = ILP_Integer2ILP (3000);
      ilptmp121 = ilp__apply (NULL, ilptmp123, ilptmp124);
    }
    ilptmp122 = ILP_Integer2ILP (7);
    return ILP_Minus (ilptmp121, ilptmp122);
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
