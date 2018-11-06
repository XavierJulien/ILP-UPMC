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
    ILP_Object ilptmp433;
    ILP_Object ilptmp434;
    ilptmp433 = ILP_Integer2ILP (2);
    ilptmp434 = x1;
    return ILP_Times (ilptmp433, ilptmp434);
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
    ILP_Object ilptmp435;
    ilptmp435 = ILP_Integer2ILP (11);

    {
      ILP_Object y4 = ilptmp435;
      {
	ILP_Object ilptmp436;
	{
	  ILP_Object ilptmp437;
	  ILP_Object ilptmp438;
	  {
	    ILP_Object ilptmp439;
	    {
	      ILP_Object ilptmp440;
	      ILP_Object ilptmp441;
	      ilptmp440 = y4;
	      ilptmp441 = ILP_Integer2ILP (1);
	      ilptmp439 = ILP_Plus (ilptmp440, ilptmp441);
	    }
	    ilptmp437 = (y4 = ilptmp439);
	  }
	  ilptmp438 = y4;
	  ilptmp436 = ilp__pseudosequence (NULL, ilptmp437, ilptmp438);
	}
	return ilp__foo (NULL, ilptmp436);
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
