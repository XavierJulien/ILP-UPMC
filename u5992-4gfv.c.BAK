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
  ILP_Object ilptmp226; 
  ILP_Object ilptmp227; 
ilptmp226 = ILP_Integer2ILP(2); 
ilptmp227 = x1; 
return ILP_Times(ilptmp226, ilptmp227);
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
  ILP_Object ilptmp228; 
ilptmp228 = (ILP_Object)&deuxfois_closure_object; 

  {
    ILP_Object f2 = ilptmp228;
{ 
  ILP_Object ilptmp229; 
  ILP_Object ilptmp230; 
{ 
  ILP_Object ilptmp231; 
  ILP_Object ilptmp232; 
ilptmp231 = f2; 
ilptmp232 = ILP_Integer2ILP(3000); 
ilptmp229 = ILP_invoke(ilptmp231, 1, ilptmp232);
}
ilptmp230 = ILP_Integer2ILP(8); 
return ILP_Minus(ilptmp229, ilptmp230);
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
