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
		ILP_Object	ilptmp237;
		ilptmp237 = function;
		{
			ILP_Object	ilptmp238;
			ILP_Object	ilptmp239;
			{
				ILP_Object	ilptmp240;
				ilptmp240 = x;
				ilptmp238 = ILP_invoke(f1, 1, ilptmp240);
			}
			{
				ILP_Object	ilptmp241;
				{
					ILP_Object	ilptmp242;
					ILP_Object	ilptmp243;
					ilptmp242 = x;
					ilptmp243 = ILP_Integer2ILP(74);
					ilptmp241 = ILP_LessThan(ilptmp242, ilptmp243);
				}
				if (ILP_isEquivalentToTrue(ilptmp241)) {
					{
						ILP_Object	ilptmp244;
						ILP_Object	ilptmp245;
						ilptmp244 = ILP_Integer2ILP(2);
						ilptmp245 = x;
						ilptmp239 = ILP_Times(ilptmp244, ilptmp245);
					}

				} else {
					ilptmp239 = x;

				}
			}
			ilptmp237 = ILP_invoke(ilptmp238, 1, ilptmp239);
		}
		ilptmp237 = function;
		{
			ILP_Object	ilptmp246;
			ILP_Object	ilptmp247;
			ilptmp246 = x;
			ilptmp247 = y;
			ilptmp237 = ILP_invoke(f2, 2, ilptmp246, ilptmp247);
		}
		{
			ILP_Object	ilptmp248;
			{
				ILP_Object	ilptmp249;
				ilptmp249 = x;
				ilptmp248 = ILP_invoke(f1, 1, ilptmp249);
			}
			ilptmp237 = ILP_invoke(f1, 1, ilptmp248);
		}
		ilptmp237 = function;
		{
			ILP_Object	ilptmp250;
			ilptmp250 = x;
			ilptmp237 = ILP_invoke(f3, 1, ilptmp250);
		}
		{
			ILP_Object	ilptmp251;
			ILP_Object	ilptmp252;
			{
				ILP_Object	ilptmp253;
				ilptmp253 = x;
				ilptmp251 = ILP_invoke(f1, 1, ilptmp253);
			}
			{
				ILP_Object	ilptmp254;
				ILP_Object	ilptmp255;
				ilptmp254 = x;
				ilptmp255 = x;
				ilptmp252 = ILP_invoke(f2, 2, ilptmp254, ilptmp255);
			}
			ilptmp237 = ILP_invoke(f2, 2, ilptmp251, ilptmp252);
		}
		ilptmp237 = function;
		{
			ILP_Object	ilptmp256;
			ilptmp256 = x;
			ilptmp237 = ILP_invoke(fr1, 1, ilptmp256);
		}
		{
			ILP_Object	ilptmp257;
			ilptmp257 = x;
			ilptmp237 = ILP_invoke(fr2, 1, ilptmp257);
		}
		ilptmp237 = function;
		{
			ILP_Object	ilptmp258;
			ilptmp258 = x;
			ilptmp237 = ILP_invoke(fr2, 1, ilptmp258);
		}
		{
			ILP_Object	ilptmp259;
			{
				ILP_Object	ilptmp260;
				ilptmp260 = x;
				ilptmp259 = ILP_invoke(fr3, 1, ilptmp260);
			}
			ilptmp237 = ILP_invoke(fr3, 1, ilptmp259);
		}
		ilptmp237 = function;
		{
			ILP_Object	ilptmp261;
			ilptmp261 = x;
			ilptmp237 = ILP_invoke(fr3, 1, ilptmp261);
		}
		{
			ILP_Object	ilptmp262;
			{
				ILP_Object	ilptmp263;
				{
					ILP_Object	ilptmp264;
					ilptmp264 = x;
					ilptmp263 = ILP_invoke(f3, 1, ilptmp264);
				}
				ilptmp262 = ILP_invoke(f1, 1, ilptmp263);
			}
			ilptmp237 = ILP_invoke(f3, 1, ilptmp262);
		}
		{
			ILP_Object	ilptmp265;
			ilptmp265 = ILP_Integer2ILP(74);
			ilptmp237 = ILP_invoke(fr3, 1, ilptmp265);
		}
		return ilptmp237;
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
