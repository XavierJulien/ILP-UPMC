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
		ILP_Object	ilptmp196;
		ilptmp196 = ILP_Integer2ILP(33);

		{
			ILP_Object	u1 = ilptmp196;
			{
				ILP_Object	ilptmp197;
				ilptmp197 = ILP_String2ILP("foobar");
				{
					ILP_Object	ilptmp198;
					ILP_Object	ilptmp199;
					ilptmp198 = u1;
					ilptmp199 = ILP_Integer2ILP(22);
					ilptmp197 = ILP_Plus(ilptmp198, ilptmp199);
				}
				return ilptmp197;
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
