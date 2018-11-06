#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	fr1;
ILP_Object	fr3;
ILP_Object	function;
ILP_Object	fr2;
ILP_Object	x;
ILP_Object	y;
ILP_Object	f1;
ILP_Object	f2;
ILP_Object	f3;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp211;
		ilptmp211 = function;
		{
			ILP_Object	ilptmp212;
			ILP_Object	ilptmp213;
			{
				ILP_Object	ilptmp214;
				ilptmp214 = x;
				ilptmp212 = ILP_invoke(f1, 1, ilptmp214);
			}
			{
				ILP_Object	ilptmp215;
				ILP_Object	ilptmp216;
				ilptmp215 = ILP_Integer2ILP(2);
				ilptmp216 = x;
				ilptmp213 = ILP_Times(ilptmp215, ilptmp216);
			}
			ilptmp211 = ILP_invoke(ilptmp212, 1, ilptmp213);
		}
		ilptmp211 = function;
		{
			ILP_Object	ilptmp217;
			ILP_Object	ilptmp218;
			ilptmp217 = x;
			ilptmp218 = y;
			ilptmp211 = ILP_invoke(f2, 2, ilptmp217, ilptmp218);
		}
		{
			ILP_Object	ilptmp219;
			{
				ILP_Object	ilptmp220;
				ilptmp220 = x;
				ilptmp219 = ILP_invoke(f1, 1, ilptmp220);
			}
			ilptmp211 = ILP_invoke(f1, 1, ilptmp219);
		}
		ilptmp211 = function;
		{
			ILP_Object	ilptmp221;
			ilptmp221 = x;
			ilptmp211 = ILP_invoke(f3, 1, ilptmp221);
		}
		{
			ILP_Object	ilptmp222;
			ILP_Object	ilptmp223;
			{
				ILP_Object	ilptmp224;
				ilptmp224 = x;
				ilptmp222 = ILP_invoke(f1, 1, ilptmp224);
			}
			{
				ILP_Object	ilptmp225;
				ILP_Object	ilptmp226;
				ilptmp225 = x;
				ilptmp226 = x;
				ilptmp223 = ILP_invoke(f2, 2, ilptmp225, ilptmp226);
			}
			ilptmp211 = ILP_invoke(f2, 2, ilptmp222, ilptmp223);
		}
		ilptmp211 = function;
		{
			ILP_Object	ilptmp227;
			ilptmp227 = x;
			ilptmp211 = ILP_invoke(fr1, 1, ilptmp227);
		}
		{
			ILP_Object	ilptmp228;
			ilptmp228 = x;
			ilptmp211 = ILP_invoke(fr2, 1, ilptmp228);
		}
		ilptmp211 = function;
		{
			ILP_Object	ilptmp229;
			ilptmp229 = x;
			ilptmp211 = ILP_invoke(fr2, 1, ilptmp229);
		}
		{
			ILP_Object	ilptmp230;
			{
				ILP_Object	ilptmp231;
				ilptmp231 = x;
				ilptmp230 = ILP_invoke(fr3, 1, ilptmp231);
			}
			ilptmp211 = ILP_invoke(fr3, 1, ilptmp230);
		}
		ilptmp211 = function;
		{
			ILP_Object	ilptmp232;
			ilptmp232 = x;
			ilptmp211 = ILP_invoke(fr3, 1, ilptmp232);
		}
		{
			ILP_Object	ilptmp233;
			{
				ILP_Object	ilptmp234;
				{
					ILP_Object	ilptmp235;
					ilptmp235 = x;
					ilptmp234 = ILP_invoke(fr3, 1, ilptmp235);
				}
				ilptmp233 = ILP_invoke(fr1, 1, ilptmp234);
			}
			ilptmp211 = ILP_invoke(f3, 1, ilptmp233);
		}
		{
			ILP_Object	ilptmp236;
			ilptmp236 = ILP_Integer2ILP(73);
			ilptmp211 = ILP_invoke(f3, 1, ilptmp236);
		}
		return ilptmp211;
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
