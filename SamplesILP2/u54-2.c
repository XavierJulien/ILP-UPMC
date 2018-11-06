#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	function;
ILP_Object	x;
ILP_Object	deuxfois;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp35;
		ilptmp35 = function;
		{
			ILP_Object	ilptmp36;
			ILP_Object	ilptmp37;
			{
				ILP_Object	ilptmp38;
				ilptmp38 = x;
				ilptmp36 = ILP_invoke(deuxfois, 1, ilptmp38);
			}
			{
				ILP_Object	ilptmp39;
				ILP_Object	ilptmp40;
				ilptmp39 = ILP_Integer2ILP(2);
				ilptmp40 = x;
				ilptmp37 = ILP_Times(ilptmp39, ilptmp40);
			}
			ilptmp35 = ILP_invoke(ilptmp36, 1, ilptmp37);
		}
		{
			ILP_Object	ilptmp41;
			ilptmp41 = ILP_Integer2ILP(27);
			ilptmp35 = ILP_invoke(deuxfois, 1, ilptmp41);
		}
		return ilptmp35;
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
