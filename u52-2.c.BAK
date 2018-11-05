#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp37; 
ilptmp37 = ILP_Integer2ILP(50); 

  {
    ILP_Object x1 = ilptmp37;
{ 
  ILP_Object ilptmp38; 
while ( 1 ) { 
  ILP_Object ilptmp39; 
{ 
  ILP_Object ilptmp40; 
  ILP_Object ilptmp41; 
ilptmp40 = x1; 
ilptmp41 = ILP_Integer2ILP(52); 
ilptmp39 = ILP_LessThan(ilptmp40, ilptmp41);
} 
  if ( ILP_isEquivalentToTrue(ilptmp39) ) {
{ 
  ILP_Object ilptmp42; 
{ 
  ILP_Object ilptmp43; 
  ILP_Object ilptmp44; 
ilptmp43 = x1; 
ilptmp44 = ILP_Integer2ILP(1); 
ilptmp42 = ILP_Plus(ilptmp43, ilptmp44);
} 
(void)(x1 = ilptmp42); 
} 

} else { 
    break; 

}
}
ilptmp38 = ILP_FALSE; 
ilptmp38 = x1; 
return ilptmp38; 
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
