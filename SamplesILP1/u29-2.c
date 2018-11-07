#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp540; 
  ILP_Object ilptmp541; 
ilptmp540 = ILP_Integer2ILP(11); 
ilptmp541 = ILP_Integer2ILP(22); 

  {
    ILP_Object x1 = ilptmp540;
    ILP_Object y2 = ilptmp541;
{ 
  ILP_Object ilptmp542; 
  ILP_Object ilptmp543; 
{ 
  ILP_Object ilptmp544; 
  ILP_Object ilptmp545; 
ilptmp544 = x1; 
ilptmp545 = y2; 
ilptmp542 = ILP_Plus(ilptmp544, ilptmp545);
} 
{ 
  ILP_Object ilptmp546; 
  ILP_Object ilptmp547; 
ilptmp546 = x1; 
ilptmp547 = y2; 
ilptmp543 = ILP_Times(ilptmp546, ilptmp547);
} 

  {
    ILP_Object x3 = ilptmp542;
    ILP_Object y4 = ilptmp543;
{ 
  ILP_Object ilptmp548; 
  ILP_Object ilptmp549; 
ilptmp548 = x3; 
ilptmp549 = y4; 
return ILP_Times(ilptmp548, ilptmp549);
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
