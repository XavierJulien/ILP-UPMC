#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object	print;
ILP_Object	x_3d;
ILP_Object
do;
ILP_Object while;


ILP_Object	ilp_program() {
	{
		ILP_Object	ilptmp19;
				ilptmp19 =	ILP_Integer2ILP(5);

		{
			ILP_Object	x1 = ilptmp19;
			{
				ILP_Object	ilptmp20;
				{
					ILP_Object	ilptmp21;
					{
						ILP_Object	ilptmp22;
						ILP_Object	ilptmp23;
								ilptmp22 =	x1;
								ilptmp23 =	ILP_Integer2ILP(53);
								ilptmp21 =	ILP_LessThan(ilptmp22, ilptmp23);
					}
					ilptmp20 = ILP_invoke(while, 1, ilptmp21);
				}
						ilptmp20 =
				do;
			{
				ILP_Object	ilptmp24;
				{
					ILP_Object	ilptmp25;
					ilptmp25 = x1;
					ilptmp24 = ILP_print(ilptmp25);
				}
				ilptmp24 = x_3d;
				{
					ILP_Object	ilptmp26;
					ILP_Object	ilptmp27;
					ilptmp26 = ILP_Integer2ILP(2);
					ilptmp27 = x1;
					ilptmp24 = ILP_Times(ilptmp26, ilptmp27);
				}
				{
					ILP_Object	ilptmp28;
					{
						ILP_Object	ilptmp29;
						ILP_Object	ilptmp30;
						ilptmp29 = x1;
						ilptmp30 = ILP_Integer2ILP(53);
						ilptmp28 = ILP_GreaterThan(ilptmp29, ilptmp30);
					}
					ilptmp24 = ILP_invoke(while, 1, ilptmp28);
				}
				ilptmp24 =
				do;
			{
				ILP_Object	ilptmp31;
				{
					ILP_Object	ilptmp32;
					ilptmp32 = x1;
					ilptmp31 = ILP_print(ilptmp32);
				}
				ilptmp31 = x_3d;
				{
					ILP_Object	ilptmp33;
					ILP_Object	ilptmp34;
					ilptmp33 = x1;
					ilptmp34 = ILP_Integer2ILP(3);
					ilptmp31 = ILP_Minus(ilptmp33, ilptmp34);
				}
				ilptmp24 = ilptmp31;
			}
			ilptmp20 = ilptmp24;
			}
			ilptmp20 = x1;
			return ilptmp20;
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
