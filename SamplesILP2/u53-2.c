#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp23;
    ilptmp23 = ILP_Integer2ILP (5);

    {
      ILP_Object x1 = ilptmp23;
      {
	ILP_Object ilptmp24;
	while (1)
	  {
	    ILP_Object ilptmp25;
	    {
	      ILP_Object ilptmp26;
	      ILP_Object ilptmp27;
	      ilptmp26 = x1;
	      ilptmp27 = ILP_Integer2ILP (53);
	      ilptmp25 = ILP_LessThan (ilptmp26, ilptmp27);
	    }
	    if (ILP_isEquivalentToTrue (ilptmp25))
	      {
		{
		  ILP_Object ilptmp28;
		  {
		    ILP_Object ilptmp29;
		    ilptmp29 = x1;
		    ilptmp28 = ILP_print (ilptmp29);
		  }
		  {
		    ILP_Object ilptmp30;
		    {
		      ILP_Object ilptmp31;
		      ILP_Object ilptmp32;
		      ilptmp31 = ILP_Integer2ILP (2);
		      ilptmp32 = x1;
		      ilptmp30 = ILP_Times (ilptmp31, ilptmp32);
		    }
		    ilptmp28 = (x1 = ilptmp30);
		  }
		  while (1)
		    {
		      ILP_Object ilptmp33;
		      {
			ILP_Object ilptmp34;
			ILP_Object ilptmp35;
			ilptmp34 = x1;
			ilptmp35 = ILP_Integer2ILP (53);
			ilptmp33 = ILP_GreaterThan (ilptmp34, ilptmp35);
		      }
		      if (ILP_isEquivalentToTrue (ilptmp33))
			{
			  {
			    ILP_Object ilptmp36;
			    {
			      ILP_Object ilptmp37;
			      ilptmp37 = x1;
			      ilptmp36 = ILP_print (ilptmp37);
			    }
			    {
			      ILP_Object ilptmp38;
			      {
				ILP_Object ilptmp39;
				ILP_Object ilptmp40;
				ilptmp39 = x1;
				ilptmp40 = ILP_Integer2ILP (3);
				ilptmp38 = ILP_Minus (ilptmp39, ilptmp40);
			      }
			      ilptmp36 = (x1 = ilptmp38);
			    }
			    (void) ilptmp36;
			  }

			}
		      else
			{
			  break;

			}
		    }
		  ilptmp28 = ILP_FALSE;
		  (void) ilptmp28;
		}

	      }
	    else
	      {
		break;

	      }
	  }
	ilptmp24 = ILP_FALSE;
	ilptmp24 = x1;
	return ilptmp24;
      }

    }
  }

}

static ILP_Object
ilp_caught_program ()
{
  struct ILP_catcher *current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if (0 == setjmp (new_catcher._jmp_buf))
    {
      ILP_establish_catcher (&new_catcher);
      return ilp_program ();
    };
  return ILP_current_exception;
}

int
main (int argc, char *argv[])
{
  ILP_START_GC;
  ILP_print (ilp_caught_program ());
  ILP_newline ();
  return EXIT_SUCCESS;
}
