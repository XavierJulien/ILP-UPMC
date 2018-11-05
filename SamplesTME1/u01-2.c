#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */


ILP_Object 
ilp_program()
{
	{
		ILP_Object	ilptmp1;
		ILP_Object	ilptmp2;
		ILP_Object	ilptmp3;
		ilptmp1 = ILP_Integer2ILP(3);
		ilptmp2 = ILP_Integer2ILP(3);
		ilptmp3 = ILP_Integer2ILP(2);

		{
			ILP_Object	a1 = ilptmp1;
			ILP_Object	b2 = ilptmp2;
			ILP_Object	c3 = ilptmp3;
			{
				ILP_Object	ilptmp4;
				{
					ILP_Object	ilptmp5;
					ILP_Object	ilptmp6;
					{
						ILP_Object	ilptmp7;
						ILP_Object	ilptmp8;
						ilptmp7 = b2;
						ilptmp8 = b2;
						ilptmp5 = ILP_Times(ilptmp7, ilptmp8);
					}
					{
						ILP_Object	ilptmp9;
						ILP_Object	ilptmp10;
						{
							ILP_Object	ilptmp11;
							ILP_Object	ilptmp12;
							ilptmp11 = ILP_Integer2ILP(4);
							ilptmp12 = a1;
							ilptmp9 = ILP_Times(ilptmp11, ilptmp12);
						}
						ilptmp10 = c3;
						ilptmp6 = ILP_Times(ilptmp9, ilptmp10);
					}
					ilptmp4 = ILP_Minus(ilptmp5, ilptmp6);
				}

				{
					ILP_Object	discriminant4 = ilptmp4;
					{
						ILP_Object	ilptmp13;
						{
							ILP_Object	ilptmp14;
							ILP_Object	ilptmp15;
							ilptmp14 = discriminant4;
							ilptmp15 = ILP_Integer2ILP(0);
							ilptmp13 = ILP_Equal(ilptmp14, ilptmp15);
						}
						if (ILP_isEquivalentToTrue(ilptmp13)) {
							return ILP_String2ILP("discriminant nul : une seule racine");

						} else {
							{
								ILP_Object	ilptmp16;
								{
									ILP_Object	ilptmp17;
									ILP_Object	ilptmp18;
									ilptmp17 = discriminant4;
									ilptmp18 = ILP_Integer2ILP(0);
									ilptmp16 = ILP_GreaterThan(ilptmp17, ilptmp18);
								}
								if (ILP_isEquivalentToTrue(ilptmp16)) {
									return ILP_String2ILP("discriminant positif : deux racines");

								} else {
									{
										ILP_Object	ilptmp19;
										{
											ILP_Object	ilptmp20;
											ILP_Object	ilptmp21;
											ilptmp20 = discriminant4;
											ilptmp21 = ILP_Integer2ILP(0);
											ilptmp19 = ILP_LessThan(ilptmp20, ilptmp21);
										}
										if (ILP_isEquivalentToTrue(ilptmp19)) {
											return ILP_String2ILP("discriminant négatif : aucune racine");

										} else {
											return ILP_FALSE;

										}
									}

								}
							}

						}
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
