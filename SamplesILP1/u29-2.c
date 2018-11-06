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
		ILP_Object	ilptmp158;
		ILP_Object	ilptmp159;
		ilptmp158 = ILP_Integer2ILP(11);
		ilptmp159 = ILP_Integer2ILP(22);

		{
			ILP_Object	x1 = ilptmp158;
			ILP_Object	y2 = ilptmp159;
			{
				ILP_Object	ilptmp160;
				ILP_Object	ilptmp161;
				{
					ILP_Object	ilptmp162;
					ILP_Object	ilptmp163;
					ilptmp162 = x1;
					ilptmp163 = y2;
					ilptmp160 = ILP_Plus(ilptmp162, ilptmp163);
				}
				{
					ILP_Object	ilptmp164;
					ILP_Object	ilptmp165;
					ilptmp164 = x1;
					ilptmp165 = y2;
					ilptmp161 = ILP_Times(ilptmp164, ilptmp165);
				}

				{
					ILP_Object	x3 = ilptmp160;
					ILP_Object	y4 = ilptmp161;
					{
						ILP_Object	ilptmp166;
						ILP_Object	ilptmp167;
						ilptmp166 = x3;
						ilptmp167 = y4;
						return ILP_Times(ilptmp166, ilptmp167);
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
