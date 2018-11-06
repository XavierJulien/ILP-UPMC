#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp16; 
  ILP_Object ilptmp17; 
ilptmp16 = ILP_Integer2ILP(711); 
{ 
  ILP_Object ilptmp18; 
  ILP_Object ilptmp19; 
ilptmp18 = ILP_FALSE; 
ilptmp19 = ILP_Integer2ILP(2); 
ilptmp17 = ILP_Or(ilptmp18, ilptmp19);
} 
return ILP_Or(ilptmp16, ilptmp17);
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
