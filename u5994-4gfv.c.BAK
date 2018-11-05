#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object twice;
ILP_Object deuxfois;

/* Global prototypes */ 
ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1);
ILP_Object ilp__twice(ILP_Closure ilp_useless
,
    ILP_Object f2,
    ILP_Object x3);

/* Global functions */ 

ILP_Object ilp__deuxfois(ILP_Closure ilp_useless
,
    ILP_Object x1) {
{ 
  ILP_Object ilptmp259; 
  ILP_Object ilptmp260; 
ilptmp259 = ILP_Integer2ILP(2); 
ilptmp260 = x1; 
return ILP_Times(ilptmp259, ilptmp260);
} 
}
struct ILP_Closure deuxfois_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__deuxfois, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__twice(ILP_Closure ilp_useless
,
    ILP_Object f2,
    ILP_Object x3) {
{ 
  ILP_Object ilptmp261; 
  ILP_Object ilptmp262; 
ilptmp261 = f2; 
{ 
  ILP_Object ilptmp263; 
  ILP_Object ilptmp264; 
ilptmp263 = f2; 
ilptmp264 = x3; 
ilptmp262 = ILP_invoke(ilptmp263, 1, ilptmp264);
}
return ILP_invoke(ilptmp261, 1, ilptmp262);
}
}
struct ILP_Closure twice_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__twice, 
       2, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp265; 
  ILP_Object ilptmp266; 
{ 
  ILP_Object ilptmp267; 
  ILP_Object ilptmp268; 
ilptmp267 = (ILP_Object)&deuxfois_closure_object; 
ilptmp268 = ILP_Integer2ILP(1500); 
ilptmp265 = ilp__twice(NULL , ilptmp267, ilptmp268);
}
ilptmp266 = ILP_Integer2ILP(6); 
return ILP_Minus(ilptmp265, ilptmp266);
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
