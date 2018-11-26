#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object foo;

/* Global prototypes */
ILP_Object ilp__foo (ILP_Closure ilp_useless, ILP_Object x1, ILP_Object y2);

/* Global functions */

ILP_Object
ilp__foo (ILP_Closure ilp_useless, ILP_Object x1, ILP_Object y2)
{
  {
    ILP_Object ilptmp153;
    ILP_Object ilptmp154;
    ilptmp153 = x1;
    ilptmp154 = y2;
    return ILP_Plus (ilptmp153, ilptmp154);
  }
}

struct ILP_Closure foo_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__foo,
    2,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp155;
    ILP_Object ilptmp156;
    {
      ILP_Object ilptmp157;
      ilptmp157 = ILP_TRUE;
      if (ILP_isEquivalentToTrue (ilptmp157))
	{
	  ilptmp155 = ILP_Integer2ILP (8);

	}
      else
	{
	  ilptmp155 = ILP_Integer2ILP (1);

	}
    }
    {
      ILP_Object ilptmp158;
      ilptmp158 = ILP_Integer2ILP (8);

      {
	ILP_Object x3 = ilptmp158;
	{
	  ILP_Object ilptmp159;
	  ILP_Object ilptmp160;
	  ilptmp159 = x3;
	  ilptmp160 = x3;
	  ilptmp156 = ILP_Times (ilptmp159, ilptmp160);
	}

      }
    }
    return ilp__foo (NULL, ilptmp155, ilptmp156);
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
