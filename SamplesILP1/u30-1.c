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
		ILP_Object	ilptmp172;
		ilptmp172 = ILP_Integer2ILP(22);

		{
			ILP_Object	i1 = ilptmp172;
			{
				ILP_Object	ilptmp173;
				ilptmp173 = ILP_Float2ILP(3.3);

				{
					ILP_Object	f2 = ilptmp173;
					{
						ILP_Object	ilptmp174;
						ILP_Object	ilptmp175;
						ilptmp174 = i1;
						ilptmp175 = f2;
						return ILP_Plus(ilptmp174, ilptmp175);
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
