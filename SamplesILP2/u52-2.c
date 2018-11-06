#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	x_3d;
ILP_Object
do;
ILP_Object while;


ILP_Object	ilp_program() {
	{
		ILP_Object	ilptmp12;
				ilptmp12 =	ILP_Integer2ILP(50);

		{
			ILP_Object	x1 = ilptmp12;
			{
				ILP_Object	ilptmp13;
						ilptmp13 = while;
				{
					ILP_Object	ilptmp14;
					ILP_Object	ilptmp15;
							ilptmp14 =	x1;
							ilptmp15 =	ILP_Integer2ILP(52);
							ilptmp13 =	ILP_LessThan(ilptmp14, ilptmp15);
				}
				ilptmp13 =
				do;
			{
				ILP_Object	ilptmp16;
						ilptmp16 =	x_3d;
				{
					ILP_Object	ilptmp17;
					ILP_Object	ilptmp18;
							ilptmp17 =	x1;
							ilptmp18 =	ILP_Integer2ILP(1);
							ilptmp16 =	ILP_Plus(ilptmp17, ilptmp18);
				}
						ilptmp13 =	ilptmp16;
			}
			ilptmp13 = x1;
			return ilptmp13;
			}

			}
			}

			}

			static ILP_Object ilp_caught_program() {
				struct ILP_catcher *current_catcher = ILP_current_catcher;
				struct ILP_catcher new_catcher;

				if              (0 == setjmp(new_catcher._jmp_buf)) {
					ILP_establish_catcher(&new_catcher);
					return ilp_program();
				};
				return ILP_current_exception;
			}

			int		main       (int argc, char *argv[]){
				ILP_START_GC;
				ILP_print(ilp_caught_program());
				ILP_newline();
				return EXIT_SUCCESS;
			}
