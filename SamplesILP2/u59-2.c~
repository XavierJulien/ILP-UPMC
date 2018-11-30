#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object g;

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp168; 
ilptmp168 = ILP_Integer2ILP(1); 

  {
    ILP_Object x1 = ilptmp168;
{ 
  ILP_Object ilptmp169; 
{ 
  ILP_Object ilptmp170; 
ilptmp170 = ILP_Integer2ILP(59); 
ilptmp169 = (g = ilptmp170); 
} 
ilptmp169 = g; 
return ilptmp169; 
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
