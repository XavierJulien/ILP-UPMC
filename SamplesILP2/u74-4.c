#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	fr3;
ILP_Object	fr2;
ILP_Object	f1;
ILP_Object	f2;
ILP_Object	f3;

/* Global prototypes */
ILP_Object 
ilp__f1(ILP_Closure ilp_useless
	,
	ILP_Object x1);
ILP_Object 
ilp__f2(ILP_Closure ilp_useless
	,
	ILP_Object x2,
	ILP_Object y3);
ILP_Object 
ilp__f3(ILP_Closure ilp_useless
	,
	ILP_Object x4);
ILP_Object 
ilp__fr1(ILP_Closure ilp_useless
	 ,
	 ILP_Object x5);
ILP_Object 
ilp__fr2(ILP_Closure ilp_useless
	 ,
	 ILP_Object x6);
ILP_Object 
ilp__fr3(ILP_Closure ilp_useless
	 ,
	 ILP_Object x7);

/* Global functions */

ILP_Object 
ilp__f1(ILP_Closure ilp_useless
	,
	ILP_Object x1)
{
	{
		ILP_Object	ilptmp345;
		{
			ILP_Object	ilptmp346;
			ILP_Object	ilptmp347;
			ilptmp346 = x1;
			ilptmp347 = ILP_Integer2ILP(74);
			ilptmp345 = ILP_LessThan(ilptmp346, ilptmp347);
		}
		if (ILP_isEquivalentToTrue(ilptmp345)) {
			{
				ILP_Object	ilptmp348;
				ILP_Object	ilptmp349;
				ilptmp348 = ILP_Integer2ILP(2);
				ilptmp349 = x1;
				return ILP_Times(ilptmp348, ilptmp349);
			}

		} else {
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
ilp__f2(ILP_Closure ilp_useless
	,
	ILP_Object x2,
	ILP_Object y3)
{
	{
		ILP_Object	ilptmp350;
		{
			ILP_Object	ilptmp351;
			ilptmp351 = x2;
			ilptmp350 = ilp__f1(NULL, ilptmp351);
		}
		return ilp__f1(NULL, ilptmp350);
	}
}
struct ILP_Closure f2_closure_object = {
	&ILP_object_Closure_class,
	{{ilp__f2,
			2,
	{NULL}}}
};

ILP_Object 
ilp__f3(ILP_Closure ilp_useless
	,
	ILP_Object x4)
{
	{
		ILP_Object	ilptmp352;
		ILP_Object	ilptmp353;
		{
			ILP_Object	ilptmp354;
			ilptmp354 = x4;
			ilptmp352 = ilp__f1(NULL, ilptmp354);
		}
		{
			ILP_Object	ilptmp355;
			ILP_Object	ilptmp356;
			ilptmp355 = x4;
			ilptmp356 = x4;
			ilptmp353 = ilp__f2(NULL, ilptmp355, ilptmp356);
		}
		return ilp__f2(NULL, ilptmp352, ilptmp353);
	}
}
struct ILP_Closure f3_closure_object = {
	&ILP_object_Closure_class,
	{{ilp__f3,
			1,
	{NULL}}}
};

ILP_Object 
ilp__fr1(ILP_Closure ilp_useless
	 ,
	 ILP_Object x5)
{
	{
		ILP_Object	ilptmp357;
		ilptmp357 = x5;
		return ilp__fr2(NULL, ilptmp357);
	}
}
struct ILP_Closure fr1_closure_object = {
	&ILP_object_Closure_class,
	{{ilp__fr1,
			1,
	{NULL}}}
};

ILP_Object 
ilp__fr2(ILP_Closure ilp_useless
	 ,
	 ILP_Object x6)
{
	{
		ILP_Object	ilptmp358;
		{
			ILP_Object	ilptmp359;
			ilptmp359 = x6;
			ilptmp358 = ilp__fr3(NULL, ilptmp359);
		}
		return ilp__fr3(NULL, ilptmp358);
	}
}
struct ILP_Closure fr2_closure_object = {
	&ILP_object_Closure_class,
	{{ilp__fr2,
			1,
	{NULL}}}
};

ILP_Object 
ilp__fr3(ILP_Closure ilp_useless
	 ,
	 ILP_Object x7)
{
	{
		ILP_Object	ilptmp360;
		{
			ILP_Object	ilptmp361;
			{
				ILP_Object	ilptmp362;
				ilptmp362 = x7;
				ilptmp361 = ilp__f3(NULL, ilptmp362);
			}
			ilptmp360 = ilp__f1(NULL, ilptmp361);
		}
		return ilp__f3(NULL, ilptmp360);
	}
}
struct ILP_Closure fr3_closure_object = {
	&ILP_object_Closure_class,
	{{ilp__fr3,
			1,
	{NULL}}}
};


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp363;
		ilptmp363 = ILP_Integer2ILP(74);
		return ilp__fr3(NULL, ilptmp363);
	}

}

static ILP_Object 
ilp_caught_program()
{
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;

	if (0 == setjmp(new_catcher._jmp_buf)) {
		ILP_establish_catcher(&new_catcher);
		return ilp_program();
	};
	return ILP_current_exception;
}

int 
main(int argc, char *argv[])
{
	ILP_START_GC;
	ILP_print(ilp_caught_program());
	ILP_newline();
	return EXIT_SUCCESS;
}
