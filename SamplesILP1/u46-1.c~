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
  ILP_Object ilptmp620; 
{ 
  ILP_Object ilptmp621; 
ilptmp621 =  ILP_String2ILP("Un, "); 
ilptmp620 = ILP_print(ilptmp621);
}
{ 
  ILP_Object ilptmp622; 
ilptmp622 =  ILP_String2ILP("deux et "); 
ilptmp620 = ILP_print(ilptmp622);
}
{ 
  ILP_Object ilptmp623; 
ilptmp623 =  ILP_String2ILP("trois."); 
ilptmp620 = ILP_print(ilptmp623);
}
return ilptmp620; 
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
