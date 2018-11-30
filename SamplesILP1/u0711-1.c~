#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp398; 
  ILP_Object ilptmp399; 
ilptmp398 = ILP_Integer2ILP(711); 
{ 
  ILP_Object ilptmp400; 
  ILP_Object ilptmp401; 
ilptmp400 = ILP_FALSE; 
ilptmp401 = ILP_Integer2ILP(2); 
ilptmp399 = ILP_Or(ilptmp400, ilptmp401);
} 
return ILP_Or(ilptmp398, ilptmp399);
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
