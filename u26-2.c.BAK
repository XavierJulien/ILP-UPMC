#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp486; 
  ILP_Object ilptmp487; 
ilptmp486 = ILP_Integer2ILP(1); 
ilptmp487 = ILP_Integer2ILP(2); 

  {
    ILP_Object x1 = ilptmp486;
    ILP_Object y2 = ilptmp487;
{ 
  ILP_Object ilptmp488; 
  ILP_Object ilptmp489; 
ilptmp488 = x1; 
ilptmp489 = y2; 
return ILP_Plus(ilptmp488, ilptmp489);
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
