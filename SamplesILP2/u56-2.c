#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object even;
ILP_Object odd;

/* Global prototypes */
ILP_Object ilp__odd (ILP_Closure ilp_useless, ILP_Object n1);
ILP_Object ilp__even (ILP_Closure ilp_useless, ILP_Object n2);

/* Global functions */

ILP_Object
ilp__odd (ILP_Closure ilp_useless, ILP_Object n1)
{
  {
    ILP_Object ilptmp59;
    {
      ILP_Object ilptmp60;
      ILP_Object ilptmp61;
      ilptmp60 = n1;
      ilptmp61 = ILP_Integer2ILP (0);
      ilptmp59 = ILP_Equal (ilptmp60, ilptmp61);
    }
    if (ILP_isEquivalentToTrue (ilptmp59))
      {
	return ILP_FALSE;

      }
    else
      {
	{
	  ILP_Object ilptmp62;
	  {
	    ILP_Object ilptmp63;
	    ILP_Object ilptmp64;
	    ilptmp63 = n1;
	    ilptmp64 = ILP_Integer2ILP (1);
	    ilptmp62 = ILP_Equal (ilptmp63, ilptmp64);
	  }
	  if (ILP_isEquivalentToTrue (ilptmp62))
	    {
	      return ILP_TRUE;

	    }
	  else
	    {
	      {
		ILP_Object ilptmp65;
		{
		  ILP_Object ilptmp66;
		  ILP_Object ilptmp67;
		  ilptmp66 = n1;
		  ilptmp67 = ILP_Integer2ILP (1);
		  ilptmp65 = ILP_Minus (ilptmp66, ilptmp67);
		}
		return ilp__even (NULL, ilptmp65);
	      }

	    }
	}

      }
  }
}

struct ILP_Closure odd_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__odd,
    1,
    {NULL}}}
};

ILP_Object
ilp__even (ILP_Closure ilp_useless, ILP_Object n2)
{
  {
    ILP_Object ilptmp68;
    {
      ILP_Object ilptmp69;
      ILP_Object ilptmp70;
      ilptmp69 = n2;
      ilptmp70 = ILP_Integer2ILP (0);
      ilptmp68 = ILP_Equal (ilptmp69, ilptmp70);
    }
    if (ILP_isEquivalentToTrue (ilptmp68))
      {
	return ILP_TRUE;

      }
    else
      {
	{
	  ILP_Object ilptmp71;
	  {
	    ILP_Object ilptmp72;
	    ILP_Object ilptmp73;
	    ilptmp72 = n2;
	    ilptmp73 = ILP_Integer2ILP (1);
	    ilptmp71 = ILP_Equal (ilptmp72, ilptmp73);
	  }
	  if (ILP_isEquivalentToTrue (ilptmp71))
	    {
	      return ILP_FALSE;

	    }
	  else
	    {
	      {
		ILP_Object ilptmp74;
		{
		  ILP_Object ilptmp75;
		  ILP_Object ilptmp76;
		  ilptmp75 = n2;
		  ilptmp76 = ILP_Integer2ILP (1);
		  ilptmp74 = ILP_Minus (ilptmp75, ilptmp76);
		}
		return ilp__odd (NULL, ilptmp74);
	      }

	    }
	}

      }
  }
}

struct ILP_Closure even_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__even,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp77;
    {
      ILP_Object ilptmp78;
      ilptmp78 = ILP_Integer2ILP (56);
      ilptmp77 = ilp__odd (NULL, ilptmp78);
    }
    return ILP_Not (ilptmp77);
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
