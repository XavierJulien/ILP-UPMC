#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object apply;
ILP_Object deuxfois;

/* Global prototypes */ 
ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1);
ILP_Object ilp__apply(ILP_Closure ilp_useless
,
    ILP_Object f2,
    ILP_Object x3);

/* Global functions */ 

ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1) {
{ 
  ILP_Object ilptmp241; 
  ILP_Object ilptmp242; 
ilptmp241 = ILP_Integer2ILP(2); 
ilptmp242 = x1; 
return ILP_Times(ilptmp241, ilptmp242);
} 
}
struct ILP_Closure deuxfois_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__deuxfois, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__apply(ILP_Closure ilp_useless
,
    ILP_Object f2,
    ILP_Object x3) {
{ 
  ILP_Object ilptmp243; 
  ILP_Object ilptmp244; 
ilptmp243 = f2; 
ilptmp244 = x3; 
return ILP_invoke(ilptmp243, 1, ilptmp244);
}
}
struct ILP_Closure apply_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__apply, 
       2, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp245; 
  ILP_Object ilptmp246; 
{ 
  ILP_Object ilptmp247; 
  ILP_Object ilptmp248; 
ilptmp247 = (ILP_Object)&deuxfois_closure_object; 
ilptmp248 = ILP_Integer2ILP(3000); 
ilptmp245 = ilp__apply(NULL , ilptmp247, ilptmp248);
}
ilptmp246 = ILP_Integer2ILP(7); 
return ILP_Minus(ilptmp245, ilptmp246);
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
