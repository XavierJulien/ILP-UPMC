#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object g;
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp530;
    ILP_Object ilptmp531;
    ilptmp530 = ILP_Integer2ILP (2);
    ilptmp531 = x1;
    return ILP_Times (ilptmp530, ilptmp531);
  }
}

struct ILP_Closure deuxfois_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__deuxfois,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp532;
    {
      ILP_Object ilptmp533;
      ilptmp533 = (ILP_Object) & deuxfois_closure_object;

      {
	ILP_Object f2 = ilptmp533;
	{
	  ILP_Object ilptmp534;
	  ilptmp534 = f2;
	  ilptmp532 = (g = ilptmp534);
	}

      }
    }
    {
      ILP_Object ilptmp535;
      ILP_Object ilptmp536;
      {
	ILP_Object ilptmp537;
	ilptmp537 = ILP_Integer2ILP (3000);
	ilptmp535 = ILP_invoke (g, 1, ilptmp537);
      }
      ilptmp536 = ILP_Integer2ILP (5);
      ilptmp532 = ILP_Minus (ilptmp535, ilptmp536);
    }
    return ilptmp532;
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
