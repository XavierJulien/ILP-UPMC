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
    ILP_Object ilptmp103;
    ILP_Object ilptmp104;
    ilptmp103 = ILP_Integer2ILP (2);
    ilptmp104 = x1;
    return ILP_Times (ilptmp103, ilptmp104);
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
    ILP_Object ilptmp105;
    ILP_Object ilptmp106;
    {
      ILP_Object ilptmp107;
      ILP_Object ilptmp108;
      {
	ILP_Object ilptmp109;
	ilptmp109 = (ILP_Object) & deuxfois_closure_object;
	if (ILP_isEquivalentToTrue (ilptmp109))
	  {
	    ilptmp107 = (ILP_Object) & deuxfois_closure_object;

	  }
	else
	  {
	    ilptmp107 = (ILP_Object) & deuxfois_closure_object;

	  }
      }
      ilptmp108 = ILP_Integer2ILP (3000);
      ilptmp105 = ILP_invoke (ilptmp107, 1, ilptmp108);
    }
    ilptmp106 = ILP_Integer2ILP (9);
    return ILP_Minus (ilptmp105, ilptmp106);
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
