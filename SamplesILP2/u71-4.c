#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp196;
		{
			ILP_Object	ilptmp197;
			ilptmp197 = ILP_TRUE;

			{
				ILP_Object	x1 = ilptmp197;
				ilptmp196 = x1;

			}
		}
		if (ILP_isEquivalentToTrue(ilptmp196)) {
			return ILP_Integer2ILP(1);

		} else {
			return ILP_Integer2ILP(2);

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
