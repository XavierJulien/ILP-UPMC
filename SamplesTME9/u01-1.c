#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object done;

/* Global prototypes */

/* Global functions */


/* Classes */
ILP_GenerateClass (4);
extern struct ILP_Class4 ILP_object_Point_class;
extern struct ILP_Field ILP_object_x_field;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__m_2 (ILP_Closure ilp_useless, ILP_Object self1);
ILP_Object ilp__n_4 (ILP_Closure ilp_useless, ILP_Object self3);

struct ILP_Field ILP_object_x_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point_class,
    NULL,
    "x",
    0}}
};

struct ILP_Field ILP_object_y_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point_class,
    &ILP_object_x_field,
    "y",
    1}}
};

struct ILP_Class4 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    2,
    &ILP_object_y_field,
    4,
    {ILPm_print,
     ILPm_classOf,
     ilp__m_2,
     ilp__n_4,
     }}}
};

struct ILP_Method ILP_object_m_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "m",
    1,				/* arité */
    2				/* offset */
    }}
};

struct ILP_Method ILP_object_n_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "n",
    1,				/* arité */
    3				/* offset */
    }}
};

ILP_Object
ilp__m_2 (ILP_Closure ilp_useless, ILP_Object self1)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self1;

  {
    {
      ILP_Object ilptmp1;
      {
	ILP_Object ilptmp2;
	ilptmp2 = self1;
	if (ILP_IsA (ilptmp2, Point))
	  {
	    ilptmp1 = ilptmp2->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp1 = ILP_UnknownFieldError ("x", ilptmp2);
	  }
      }
      return ILP_print (ilptmp1);
    }
  }
}

ILP_Object
ilp__n_4 (ILP_Closure ilp_useless, ILP_Object self3)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_n_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self3;

  {
    {
      ILP_general_function ilptmp3;
      ILP_Object ilptmp4;
      ilptmp4 = self3;
      ILP_find_method_inline_cache (ilptmp3, ilptmp4, &ILP_object_m_method,
				    1);
      return ilptmp3 (NULL, ilptmp4);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp5;
    {
      ILP_Object ilptmp6;
      ILP_Object ilptmp7;
      ILP_Object ilptmp8;
      ilptmp7 = ILP_Integer2ILP (11);
      ilptmp8 = ILP_Integer2ILP (22);
      ilptmp6 = ILP_MakeInstance (Point);
      ilptmp6->_content.asInstance.field[0] = ilptmp7;
      ilptmp6->_content.asInstance.field[1] = ilptmp8;
      ilptmp5 = ilptmp6;
    }

    {
      ILP_Object p5 = ilptmp5;
      {
	ILP_Object ilptmp9;
	{
	  ILP_general_function ilptmp10;
	  ILP_Object ilptmp11;
	  ilptmp11 = p5;
	  ILP_find_method_inline_cache (ilptmp10, ilptmp11,
					&ILP_object_m_method, 1);
	  ilptmp9 = ilptmp10 (NULL, ilptmp11);
	}
	{
	  ILP_Object ilptmp12;
	  ilptmp12 = ILP_Integer2ILP (0);

	  {
	    ILP_Object x6 = ilptmp12;
	    while (1)
	      {
		ILP_Object ilptmp13;
		{
		  ILP_Object ilptmp14;
		  ILP_Object ilptmp15;
		  ilptmp14 = x6;
		  ilptmp15 = ILP_Integer2ILP (10);
		  ilptmp13 = ILP_LessThan (ilptmp14, ilptmp15);
		}
		if (ILP_isEquivalentToTrue (ilptmp13))
		  {
		    {
		      ILP_Object ilptmp16;
		      {
			ILP_general_function ilptmp17;
			ILP_Object ilptmp18;
			ilptmp18 = p5;
			ILP_find_method_inline_cache (ilptmp17, ilptmp18,
						      &ILP_object_n_method,
						      1);
			ilptmp16 = ilptmp17 (NULL, ilptmp18);
		      }
		      {
			ILP_Object ilptmp19;
			{
			  ILP_Object ilptmp20;
			  ILP_Object ilptmp21;
			  ilptmp20 = x6;
			  ilptmp21 = ILP_Integer2ILP (1);
			  ilptmp19 = ILP_Plus (ilptmp20, ilptmp21);
			}
			ilptmp16 = (x6 = ilptmp19);
		      }
		      (void) ilptmp16;
		    }

		  }
		else
		  {
		    break;

		  }
	      }
	    ilptmp9 = ILP_FALSE;

	  }
	}
	ilptmp9 = done;
	ilptmp9 = ILP_Integer2ILP (836);
	return ilptmp9;
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
