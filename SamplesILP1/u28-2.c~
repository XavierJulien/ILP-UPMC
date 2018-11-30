#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp513; 
  ILP_Object ilptmp514; 
ilptmp513 = ILP_Integer2ILP(1); 
ilptmp514 = ILP_Integer2ILP(2); 

  {
    ILP_Object x1 = ilptmp513;
    ILP_Object y2 = ilptmp514;
{ 
  ILP_Object ilptmp515; 
ilptmp515 = ILP_Integer2ILP(3); 

  {
    ILP_Object y3 = ilptmp515;
{ 
  ILP_Object ilptmp516; 
  ILP_Object ilptmp517; 
ilptmp516 = x1; 
ilptmp517 = y3; 
return ILP_Plus(ilptmp516, ilptmp517);
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
