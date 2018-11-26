#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object fr1;
ILP_Object fr3;
ILP_Object fr2;
ILP_Object f1;
ILP_Object f2;
ILP_Object f3;

/* Global prototypes */
ILP_Object ilp__f1 (ILP_Closure ilp_useless, ILP_Object x1);
ILP_Object ilp__f2 (ILP_Closure ilp_useless, ILP_Object x2, ILP_Object y3);
ILP_Object ilp__f3 (ILP_Closure ilp_useless, ILP_Object x4);
ILP_Object ilp__fr1 (ILP_Closure ilp_useless, ILP_Object x5);
ILP_Object ilp__fr2 (ILP_Closure ilp_useless, ILP_Object x6);
ILP_Object ilp__fr3 (ILP_Closure ilp_useless, ILP_Object x7);

/* Global functions */

ILP_Object
ilp__f1 (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp161;
    ILP_Object ilptmp162;
    ilptmp161 = ILP_Integer2ILP (2);
    ilptmp162 = x1;
    return ILP_Times (ilptmp161, ilptmp162);
  }
}

struct ILP_Closure f1_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f1,
    1,
    {NULL}}}
};

ILP_Object
ilp__f2 (ILP_Closure ilp_useless, ILP_Object x2, ILP_Object y3)
{
  {
    ILP_Object ilptmp163;
    {
      ILP_Object ilptmp164;
      ilptmp164 = x2;
      ilptmp163 = ilp__f1 (NULL, ilptmp164);
    }
    return ilp__f1 (NULL, ilptmp163);
  }
}

struct ILP_Closure f2_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f2,
    2,
    {NULL}}}
};

ILP_Object
ilp__f3 (ILP_Closure ilp_useless, ILP_Object x4)
{
  {
    ILP_Object ilptmp165;
    ILP_Object ilptmp166;
    {
      ILP_Object ilptmp167;
      ilptmp167 = x4;
      ilptmp165 = ilp__f1 (NULL, ilptmp167);
    }
    {
      ILP_Object ilptmp168;
      ILP_Object ilptmp169;
      ilptmp168 = x4;
      ilptmp169 = x4;
      ilptmp166 = ilp__f2 (NULL, ilptmp168, ilptmp169);
    }
    return ilp__f2 (NULL, ilptmp165, ilptmp166);
  }
}

struct ILP_Closure f3_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__f3,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr1 (ILP_Closure ilp_useless, ILP_Object x5)
{
  {
    ILP_Object ilptmp170;
    ilptmp170 = x5;
    return ilp__fr2 (NULL, ilptmp170);
  }
}

struct ILP_Closure fr1_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr1,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr2 (ILP_Closure ilp_useless, ILP_Object x6)
{
  {
    ILP_Object ilptmp171;
    {
      ILP_Object ilptmp172;
      ilptmp172 = x6;
      ilptmp171 = ilp__fr3 (NULL, ilptmp172);
    }
    return ilp__fr3 (NULL, ilptmp171);
  }
}

struct ILP_Closure fr2_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr2,
    1,
    {NULL}}}
};

ILP_Object
ilp__fr3 (ILP_Closure ilp_useless, ILP_Object x7)
{
  {
    ILP_Object ilptmp173;
    {
      ILP_Object ilptmp174;
      {
	ILP_Object ilptmp175;
	ilptmp175 = x7;
	ilptmp174 = ilp__fr3 (NULL, ilptmp175);
      }
      ilptmp173 = ilp__fr1 (NULL, ilptmp174);
    }
    return ilp__f3 (NULL, ilptmp173);
  }
}

struct ILP_Closure fr3_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__fr3,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp176;
    ilptmp176 = ILP_Integer2ILP (73);
    return ilp__f3 (NULL, ilptmp176);
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
