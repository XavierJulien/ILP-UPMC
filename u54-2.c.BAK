#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object deuxfois;

/* Global prototypes */ 
ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1);

/* Global functions */ 

ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1) {
{ 
  ILP_Object ilptmp84; 
  ILP_Object ilptmp85; 
ilptmp84 = ILP_Integer2ILP(2); 
ilptmp85 = x1; 
return ILP_Times(ilptmp84, ilptmp85);
} 
}
struct ILP_Closure deuxfois_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__deuxfois, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp86; 
ilptmp86 = ILP_Integer2ILP(27); 
return ilp__deuxfois(NULL , ilptmp86);
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
