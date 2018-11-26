#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object twice;
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__twice (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp125;
    ILP_Object ilptmp126;
    ilptmp125 = ILP_Integer2ILP (2);
    ilptmp126 = x1;
    return ILP_Times (ilptmp125, ilptmp126);
  }
}

struct ILP_Closure deuxfois_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__deuxfois,
    1,
    {NULL}}}
};

ILP_Object
ilp__twice (ILP_Closure ilp_useless, ILP_Object f2, ILP_Object x3)
{
  {
    ILP_Object ilptmp127;
    ILP_Object ilptmp128;
    ilptmp127 = f2;
    {
      ILP_Object ilptmp129;
      ILP_Object ilptmp130;
      ilptmp129 = f2;
      ilptmp130 = x3;
      ilptmp128 = ILP_invoke (ilptmp129, 1, ilptmp130);
    }
    return ILP_invoke (ilptmp127, 1, ilptmp128);
  }
}

struct ILP_Closure twice_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__twice,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp131;
    ILP_Object ilptmp132;
    {
      ILP_Object ilptmp133;
      ILP_Object ilptmp134;
      ilptmp133 = (ILP_Object) & deuxfois_closure_object;
      ilptmp134 = ILP_Integer2ILP (1500);
      ilptmp131 = ilp__twice (NULL, ilptmp133, ilptmp134);
    }
    ilptmp132 = ILP_Integer2ILP (6);
    return ILP_Minus (ilptmp131, ilptmp132);
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
