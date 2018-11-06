#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	print;

/* Global prototypes */

/* Global functions */


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp211;
		{
			ILP_Object	ilptmp212;
			ILP_Object	ilptmp213;
			ilptmp212 = ILP_Integer2ILP(20);
			ilptmp213 = ILP_Integer2ILP(1);
			ilptmp211 = ILP_Plus(ilptmp212, ilptmp213);
		}
		return ILP_print(ilptmp211);
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
