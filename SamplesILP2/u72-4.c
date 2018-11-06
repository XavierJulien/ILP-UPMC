#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	function;
ILP_Object	foo;
ILP_Object	x;
ILP_Object	y;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp198;
		ilptmp198 = function;
		{
			ILP_Object	ilptmp199;
			ILP_Object	ilptmp200;
			{
				ILP_Object	ilptmp201;
				ILP_Object	ilptmp202;
				ilptmp201 = x;
				ilptmp202 = y;
				ilptmp199 = ILP_invoke(foo, 2, ilptmp201, ilptmp202);
			}
			{
				ILP_Object	ilptmp203;
				ILP_Object	ilptmp204;
				ilptmp203 = x;
				ilptmp204 = y;
				ilptmp200 = ILP_Plus(ilptmp203, ilptmp204);
			}
			ilptmp198 = ILP_invoke(ilptmp199, 1, ilptmp200);
		}
		{
			ILP_Object	ilptmp205;
			ILP_Object	ilptmp206;
			{
				ILP_Object	ilptmp207;
				ilptmp207 = ILP_TRUE;
				if (ILP_isEquivalentToTrue(ilptmp207)) {
					ilptmp205 = ILP_Integer2ILP(8);

				} else {
					ilptmp205 = ILP_Integer2ILP(1);

				}
			}
			{
				ILP_Object	ilptmp208;
				ilptmp208 = ILP_Integer2ILP(8);

				{
					ILP_Object	x1 = ilptmp208;
					{
						ILP_Object	ilptmp209;
						ILP_Object	ilptmp210;
						ilptmp209 = x1;
						ilptmp210 = x1;
						ilptmp206 = ILP_Times(ilptmp209, ilptmp210);
					}

				}
			}
			ilptmp198 = ILP_invoke(foo, 2, ilptmp205, ilptmp206);
		}
		return ilptmp198;
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
