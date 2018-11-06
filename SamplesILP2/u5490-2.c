#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	man_3agle;
ILP_Object	function;
ILP_Object	n;


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp42;
		ilptmp42 = function;
		{
			ILP_Object	ilptmp43;
			ILP_Object	ilptmp44;
			{
				ILP_Object	ilptmp45;
				ilptmp45 = n;
				ilptmp43 = ILP_invoke(man_3agle, 1, ilptmp45);
			}
			{
				ILP_Object	ilptmp46;
				ILP_Object	ilptmp47;
				ilptmp46 = n;
				ilptmp47 = ILP_Integer2ILP(2);
				ilptmp44 = ILP_Divide(ilptmp46, ilptmp47);
			}
			ilptmp42 = ILP_invoke(ilptmp43, 1, ilptmp44);
		}
		{
			ILP_Object	ilptmp48;
			{
				ILP_Object	ilptmp49;
				ILP_Object	ilptmp50;
				ilptmp49 = ILP_Integer2ILP(2);
				ilptmp50 = ILP_Integer2ILP(5490);
				ilptmp48 = ILP_Times(ilptmp49, ilptmp50);
			}
			ilptmp42 = ILP_invoke(man_3agle, 1, ilptmp48);
		}
		return ilptmp42;
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
