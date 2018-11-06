#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	pseudosequence;
ILP_Object	y_3d;
ILP_Object	function;
ILP_Object	one;
ILP_Object	foo;
ILP_Object	x;
ILP_Object	y;
ILP_Object	two;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp120;
		ilptmp120 = function;
		{
			ILP_Object	ilptmp121;
			ILP_Object	ilptmp122;
			ilptmp121 = one;
			ilptmp122 = two;
			ilptmp120 = ILP_invoke(pseudosequence, 2, ilptmp121, ilptmp122);
		}
		ilptmp120 = two;
		ilptmp120 = function;
		{
			ILP_Object	ilptmp123;
			ILP_Object	ilptmp124;
			{
				ILP_Object	ilptmp125;
				ilptmp125 = x;
				ilptmp123 = ILP_invoke(foo, 1, ilptmp125);
			}
			{
				ILP_Object	ilptmp126;
				ILP_Object	ilptmp127;
				ilptmp126 = ILP_Integer2ILP(2);
				ilptmp127 = x;
				ilptmp124 = ILP_Times(ilptmp126, ilptmp127);
			}
			ilptmp120 = ILP_invoke(ilptmp123, 1, ilptmp124);
		}
		{
			ILP_Object	ilptmp128;
			ilptmp128 = ILP_Integer2ILP(12);

			{
				ILP_Object	y1 = ilptmp128;
				ilptmp120 = foo;

			}
		}
		{
			ILP_Object	ilptmp129;
			ilptmp129 = pseudosequence;
			{
				ILP_Object	ilptmp130;
				{
					ILP_Object	ilptmp131;
					ilptmp131 = y_3d;
					{
						ILP_Object	ilptmp132;
						ilptmp132 = y;
						ilptmp131 = ILP_invoke(foo, 1, ilptmp132);
					}
					ilptmp130 = ilptmp131;
				}
				ilptmp130 = y;
				ilptmp129 = ilptmp130;
			}
			ilptmp120 = ilptmp129;
		}
		return ilptmp120;
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
