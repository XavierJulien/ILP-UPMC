#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp554; 
ilptmp554 = ILP_Integer2ILP(22); 

  {
    ILP_Object i1 = ilptmp554;
{ 
  ILP_Object ilptmp555; 
ilptmp555 = ILP_Float2ILP(3.3); 

  {
    ILP_Object f2 = ilptmp555;
{ 
  ILP_Object ilptmp556; 
  ILP_Object ilptmp557; 
ilptmp556 = i1; 
ilptmp557 = f2; 
return ILP_Plus(ilptmp556, ilptmp557);
} 

  }
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
