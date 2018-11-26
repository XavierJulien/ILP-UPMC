#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
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
    ILP_Object ilptmp177;
    {
      ILP_Object ilptmp178;
      ILP_Object ilptmp179;
      ilptmp178 = x1;
      ilptmp179 = ILP_Integer2ILP (74);
      ilptmp177 = ILP_LessThan (ilptmp178, ilptmp179);
    }
    if (ILP_isEquivalentToTrue (ilptmp177))
      {
	{
	  ILP_Object ilptmp180;
	  ILP_Object ilptmp181;
	  ilptmp180 = ILP_Integer2ILP (2);
	  ilptmp181 = x1;
	  return ILP_Times (ilptmp180, ilptmp181);
	}

      }
    else
      {
	return x1;

      }
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
    ILP_Object ilptmp182;
    {
      ILP_Object ilptmp183;
      ilptmp183 = x2;
      ilptmp182 = ilp__f1 (NULL, ilptmp183);
    }
    return ilp__f1 (NULL, ilptmp182);
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
    ILP_Object ilptmp184;
    ILP_Object ilptmp185;
    {
      ILP_Object ilptmp186;
      ilptmp186 = x4;
      ilptmp184 = ilp__f1 (NULL, ilptmp186);
    }
    {
      ILP_Object ilptmp187;
      ILP_Object ilptmp188;
      ilptmp187 = x4;
      ilptmp188 = x4;
      ilptmp185 = ilp__f2 (NULL, ilptmp187, ilptmp188);
    }
    return ilp__f2 (NULL, ilptmp184, ilptmp185);
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
    ILP_Object ilptmp189;
    ilptmp189 = x5;
    return ilp__fr2 (NULL, ilptmp189);
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
    ILP_Object ilptmp190;
    {
      ILP_Object ilptmp191;
      ilptmp191 = x6;
      ilptmp190 = ilp__fr3 (NULL, ilptmp191);
    }
    return ilp__fr3 (NULL, ilptmp190);
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
    ILP_Object ilptmp192;
    {
      ILP_Object ilptmp193;
      {
	ILP_Object ilptmp194;
	ilptmp194 = x7;
	ilptmp193 = ilp__f3 (NULL, ilptmp194);
      }
      ilptmp192 = ilp__f1 (NULL, ilptmp193);
    }
    return ilp__f3 (NULL, ilptmp192);
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
    ILP_Object ilptmp195;
    ilptmp195 = ILP_Integer2ILP (74);
    return ilp__fr3 (NULL, ilptmp195);
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
