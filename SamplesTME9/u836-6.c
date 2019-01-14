#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


/* Classes */
ILP_GenerateClass (3);
extern struct ILP_Class3 ILP_object_Point_class;
extern struct ILP_Field ILP_object_x_field;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__x_2 (ILP_Closure ilp_useless, ILP_Object self1);

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

struct ILP_Class3 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    2,
    &ILP_object_y_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__x_2,
     }}}
};

struct ILP_Method ILP_object_x_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "x",
    1,				/* arité */
    2				/* offset */
    }}
};

ILP_Object
ilp__x_2 (ILP_Closure ilp_useless, ILP_Object self1)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_x_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self1;

  {
    {
      ILP_Object ilptmp22;
      ilptmp22 = self1;
      if (ILP_IsA (ilptmp22, Point))
	{
	  return ilptmp22->_content.asInstance.field[0];
	}
      else
	{
	  return ILP_UnknownFieldError ("x", ilptmp22);
	}
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp23;
    {
      ILP_Object ilptmp24;
      ILP_Object ilptmp25;
      ILP_Object ilptmp26;
      ilptmp25 = ILP_Integer2ILP (11);
      ilptmp26 = ILP_Integer2ILP (22);
      ilptmp24 = ILP_MakeInstance (Point);
      ilptmp24->_content.asInstance.field[0] = ilptmp25;
      ilptmp24->_content.asInstance.field[1] = ilptmp26;
      ilptmp23 = ilptmp24;
    }

    {
      ILP_Object p3 = ilptmp23;
      {
	ILP_Object ilptmp27;
	{
	  ILP_general_function ilptmp28;
	  ILP_Object ilptmp29;
	  ilptmp29 = p3;
	  ILP_find_method_inline_cache (ilptmp28, ilptmp29,
					&ILP_object_x_method, 1);
	  ilptmp27 = ilptmp28 (NULL, ilptmp29);
	}
	{
	  ILP_general_function ilptmp30;
	  ILP_Object ilptmp31;
	  ilptmp31 = p3;
	  ILP_find_method_inline_cache (ilptmp30, ilptmp31,
					&ILP_object_x_method, 1);
	  ilptmp27 = ilptmp30 (NULL, ilptmp31);
	}
	{
	  ILP_general_function ilptmp32;
	  ILP_Object ilptmp33;
	  ilptmp33 = p3;
	  ILP_find_method_inline_cache (ilptmp32, ilptmp33,
					&ILP_object_x_method, 1);
	  ilptmp27 = ilptmp32 (NULL, ilptmp33);
	}
	{
	  ILP_general_function ilptmp34;
	  ILP_Object ilptmp35;
	  ilptmp35 = p3;
	  ILP_find_method_inline_cache (ilptmp34, ilptmp35,
					&ILP_object_x_method, 1);
	  ilptmp27 = ilptmp34 (NULL, ilptmp35);
	}
	ilptmp27 = ILP_Integer2ILP (836);
	return ilptmp27;
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
