#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object man_3agle;

/* Global prototypes */ 
ILP_Object ilp__man_3agle(ILP_Closure ilp_useless
,
    ILP_Object n1);

/* Global functions */ 

ILP_Object ilp__man_3agle(ILP_Closure ilp_useless
,
    ILP_Object n1) {
{ 
  ILP_Object ilptmp92; 
  ILP_Object ilptmp93; 
ilptmp92 = n1; 
ilptmp93 = ILP_Integer2ILP(2); 
return ILP_Divide(ilptmp92, ilptmp93);
} 
}
struct ILP_Closure man_3agle_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__man_3agle, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp94; 
{ 
  ILP_Object ilptmp95; 
  ILP_Object ilptmp96; 
ilptmp95 = ILP_Integer2ILP(2); 
ilptmp96 = ILP_Integer2ILP(5490); 
ilptmp94 = ILP_Times(ilptmp95, ilptmp96);
} 
return ilp__man_3agle(NULL , ilptmp94);
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
