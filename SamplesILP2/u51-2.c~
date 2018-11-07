#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object print;

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp18; 
ilptmp18 = ILP_Integer2ILP(49); 

  {
    ILP_Object x1 = ilptmp18;
{ 
  ILP_Object ilptmp19; 
{ 
  ILP_Object ilptmp20; 
ilptmp20 = x1; 
ilptmp19 = ILP_print(ilptmp20);
}
{ 
  ILP_Object ilptmp21; 
{ 
  ILP_Object ilptmp22; 
  ILP_Object ilptmp23; 
ilptmp22 = x1; 
ilptmp23 = ILP_Integer2ILP(1); 
ilptmp21 = ILP_Plus(ilptmp22, ilptmp23);
} 
ilptmp19 = (x1 = ilptmp21); 
} 
{ 
  ILP_Object ilptmp24; 
ilptmp24 = x1; 
ilptmp19 = ILP_print(ilptmp24);
}
{ 
  ILP_Object ilptmp25; 
{ 
  ILP_Object ilptmp26; 
  ILP_Object ilptmp27; 
ilptmp26 = x1; 
ilptmp27 = ILP_Integer2ILP(1); 
ilptmp25 = ILP_Plus(ilptmp26, ilptmp27);
} 
ilptmp19 = (x1 = ilptmp25); 
} 
{ 
  ILP_Object ilptmp28; 
ilptmp28 = x1; 
ilptmp19 = ILP_print(ilptmp28);
}
ilptmp19 = x1; 
return ilptmp19; 
} 

  }
}

} 

static ILP_Object ilp_caught_program () {
  struct ILP_catcher* current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if ( 0 == setjmp(new_catcher._jmp_buf) ) {
    ILP_establish_catcher(&new_catcher);
    return ilp_program();
  };
  return ILP_current_exception;
}

int main (int argc, char *argv[]) 
{ 
  ILP_START_GC; 
  ILP_print(ilp_caught_program()); 
  ILP_newline(); 
  return EXIT_SUCCESS; 
} 
