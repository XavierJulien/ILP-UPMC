#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object pseudosequence;
ILP_Object foo;

/* Global prototypes */
ILP_Object ilp__pseudosequence (ILP_Closure ilp_useless,
				ILP_Object one1, ILP_Object two2);
ILP_Object ilp__foo (ILP_Closure ilp_useless, ILP_Object x3);

/* Global functions */

ILP_Object
ilp__pseudosequence (ILP_Closure ilp_useless,
		     ILP_Object one1, ILP_Object two2)
{
  return two2;
}

struct ILP_Closure pseudosequence_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__pseudosequence,
    2,
    {NULL}}}
};

ILP_Object
ilp__foo (ILP_Closure ilp_useless, ILP_Object x3)
{
  {
    ILP_Object ilptmp95;
    ILP_Object ilptmp96;
    ilptmp95 = ILP_Integer2ILP (2);
    ilptmp96 = x3;
    return ILP_Times (ilptmp95, ilptmp96);
  }
}

struct ILP_Closure foo_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__foo,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp97;
    ilptmp97 = ILP_Integer2ILP (12);

    {
      ILP_Object y4 = ilptmp97;
      {
	ILP_Object ilptmp98;
	{
	  ILP_Object ilptmp99;
	  ILP_Object ilptmp100;
	  {
	    ILP_Object ilptmp101;
	    {
	      ILP_Object ilptmp102;
	      ilptmp102 = y4;
	      ilptmp101 = ilp__foo (NULL, ilptmp102);
	    }
	    ilptmp99 = (y4 = ilptmp101);
	  }
	  ilptmp100 = y4;
	  ilptmp98 = ilp__pseudosequence (NULL, ilptmp99, ilptmp100);
	}
	return ilp__foo (NULL, ilptmp98);
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
