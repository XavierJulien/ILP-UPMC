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
  ILP_Object ilptmp212; 
  ILP_Object ilptmp213; 
ilptmp212 = ILP_Integer2ILP(2); 
ilptmp213 = x1; 
return ILP_Times(ilptmp212, ilptmp213);
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
  ILP_Object ilptmp214; 
  ILP_Object ilptmp215; 
{ 
  ILP_Object ilptmp216; 
  ILP_Object ilptmp217; 
{ 
  ILP_Object ilptmp218; 
ilptmp218 = (ILP_Object)&deuxfois_closure_object; 
  if ( ILP_isEquivalentToTrue(ilptmp218 ) ) {
ilptmp216 = (ILP_Object)&deuxfois_closure_object; 

  } else {
ilptmp216 = (ILP_Object)&deuxfois_closure_object; 

  }
}
ilptmp217 = ILP_Integer2ILP(3000); 
ilptmp214 = ILP_invoke(ilptmp216, 1, ilptmp217);
}
ilptmp215 = ILP_Integer2ILP(9); 
return ILP_Minus(ilptmp214, ilptmp215);
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
