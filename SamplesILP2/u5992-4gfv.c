#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object deuxfois;

/* Global prototypes */
ILP_Object ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1);

/* Global functions */

ILP_Object
ilp__deuxfois (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp110;
    ILP_Object ilptmp111;
    ilptmp110 = ILP_Integer2ILP (2);
    ilptmp111 = x1;
    return ILP_Times (ilptmp110, ilptmp111);
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
    ILP_Object ilptmp112;
    ilptmp112 = (ILP_Object) & deuxfois_closure_object;

    {
      ILP_Object f2 = ilptmp112;
      {
	ILP_Object ilptmp113;
	ILP_Object ilptmp114;
	{
	  ILP_Object ilptmp115;
	  ILP_Object ilptmp116;
	  ilptmp115 = f2;
	  ilptmp116 = ILP_Integer2ILP (3000);
	  ilptmp113 = ILP_invoke (ilptmp115, 1, ilptmp116);
	}
	ilptmp114 = ILP_Integer2ILP (8);
	return ILP_Minus (ilptmp113, ilptmp114);
      }

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
