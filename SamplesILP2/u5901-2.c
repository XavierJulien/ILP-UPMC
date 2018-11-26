#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object pseudosequence;
ILP_Object foo;

/* Global prototypes */
ILP_Object ilp__foo (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__pseudosequence (ILP_Closure ilp_useless,
				ILP_Object one2, ILP_Object two3);

/* Global functions */

ILP_Object
ilp__foo (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp86;
    ILP_Object ilptmp87;
    ilptmp86 = ILP_Integer2ILP (2);
    ilptmp87 = x1;
    return ILP_Times (ilptmp86, ilptmp87);
  }
}

struct ILP_Closure foo_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__foo,
    1,
    {NULL}}}
};

ILP_Object
ilp__pseudosequence (ILP_Closure ilp_useless,
		     ILP_Object one2, ILP_Object two3)
{
  return two3;
}

struct ILP_Closure pseudosequence_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__pseudosequence,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp88;
    ilptmp88 = ILP_Integer2ILP (11);

    {
      ILP_Object y4 = ilptmp88;
      {
	ILP_Object ilptmp89;
	{
	  ILP_Object ilptmp90;
	  ILP_Object ilptmp91;
	  {
	    ILP_Object ilptmp92;
	    {
	      ILP_Object ilptmp93;
	      ILP_Object ilptmp94;
	      ilptmp93 = y4;
	      ilptmp94 = ILP_Integer2ILP (1);
	      ilptmp92 = ILP_Plus (ilptmp93, ilptmp94);
	    }
	    ilptmp90 = (y4 = ilptmp92);
	  }
	  ilptmp91 = y4;
	  ilptmp89 = ilp__pseudosequence (NULL, ilptmp90, ilptmp91);
	}
	return ilp__foo (NULL, ilptmp89);
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
