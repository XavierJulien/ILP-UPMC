#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	print;
ILP_Object	x_3d;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp3;
		ilptmp3 = ILP_Integer2ILP(49);

		{
			ILP_Object	x1 = ilptmp3;
			{
				ILP_Object	ilptmp4;
				{
					ILP_Object	ilptmp5;
					ilptmp5 = x1;
					ilptmp4 = ILP_print(ilptmp5);
				}
				ilptmp4 = x_3d;
				{
					ILP_Object	ilptmp6;
					ILP_Object	ilptmp7;
					ilptmp6 = x1;
					ilptmp7 = ILP_Integer2ILP(1);
					ilptmp4 = ILP_Plus(ilptmp6, ilptmp7);
				}
				{
					ILP_Object	ilptmp8;
					ilptmp8 = x1;
					ilptmp4 = ILP_print(ilptmp8);
				}
				ilptmp4 = x_3d;
				{
					ILP_Object	ilptmp9;
					ILP_Object	ilptmp10;
					ilptmp9 = x1;
					ilptmp10 = ILP_Integer2ILP(1);
					ilptmp4 = ILP_Plus(ilptmp9, ilptmp10);
				}
				{
					ILP_Object	ilptmp11;
					ilptmp11 = x1;
					ilptmp4 = ILP_print(ilptmp11);
				}
				ilptmp4 = x1;
				return ilptmp4;
			}

		}
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
