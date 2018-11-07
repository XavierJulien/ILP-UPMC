#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object f;

/* Global prototypes */ 
ILP_Object ilp__f(ILP_Closure ilp_useless
,
    ILP_Object ma_3angle1);

/* Global functions */ 

ILP_Object ilp__f(ILP_Closure ilp_useless
,
    ILP_Object ma_3angle1) {
{ 
  ILP_Object ilptmp102; 
  ILP_Object ilptmp103; 
ilptmp102 = ma_3angle1; 
ilptmp103 = ILP_Integer2ILP(3); 
return ILP_Divide(ilptmp102, ilptmp103);
} 
}
struct ILP_Closure f_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__f, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp104; 
{ 
  ILP_Object ilptmp105; 
  ILP_Object ilptmp106; 
ilptmp105 = ILP_Integer2ILP(3); 
ilptmp106 = ILP_Integer2ILP(5491); 
ilptmp104 = ILP_Times(ilptmp105, ilptmp106);
} 
return ilp__f(NULL , ilptmp104);
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
