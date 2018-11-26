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
    ILP_Object ilptmp135;
    ILP_Object ilptmp136;
    ilptmp135 = ILP_Integer2ILP (2);
    ilptmp136 = x1;
    return ILP_Times (ilptmp135, ilptmp136);
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
    ILP_Object ilptmp137;
    {
      ILP_Object ilptmp138;
      ilptmp138 = (ILP_Object) & deuxfois_closure_object;

      {
	ILP_Object f2 = ilptmp138;
	{
	  ILP_Object ilptmp139;
	  ilptmp139 = f2;
	  ilptmp137 = (g = ilptmp139);
	}

      }
    }
    {
      ILP_Object ilptmp140;
      ILP_Object ilptmp141;
      {
	ILP_Object ilptmp142;
	ilptmp142 = ILP_Integer2ILP (3000);
	ilptmp140 = ILP_invoke (g, 1, ilptmp142);
      }
      ilptmp141 = ILP_Integer2ILP (5);
      ilptmp137 = ILP_Minus (ilptmp140, ilptmp141);
    }
    return ilptmp137;
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
