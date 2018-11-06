#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp122;
		ilptmp122 = ILP_Integer2ILP(2);

		{
			ILP_Object	x1 = ilptmp122;
			{
				ILP_Object	ilptmp123;
				ilptmp123 = ILP_Integer2ILP(3);

				{
					ILP_Object	y2 = ilptmp123;
					{
						ILP_Object	ilptmp124;
						ILP_Object	ilptmp125;
						ilptmp124 = x1;
						ilptmp125 = x1;
						return ILP_Times(ilptmp124, ilptmp125);
					}

				}
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
