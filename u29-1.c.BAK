#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp524; 
ilptmp524 = ILP_Integer2ILP(3); 

  {
    ILP_Object x1 = ilptmp524;
{ 
  ILP_Object ilptmp525; 
{ 
  ILP_Object ilptmp526; 
  ILP_Object ilptmp527; 
ilptmp526 = x1; 
ilptmp527 = x1; 
ilptmp525 = ILP_Plus(ilptmp526, ilptmp527);
} 

  {
    ILP_Object x2 = ilptmp525;
{ 
  ILP_Object ilptmp528; 
  ILP_Object ilptmp529; 
ilptmp528 = x2; 
ilptmp529 = x2; 
return ILP_Times(ilptmp528, ilptmp529);
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
