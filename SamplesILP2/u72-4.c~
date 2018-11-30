#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object foo;

/* Global prototypes */ 
ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x1,
    ILP_Object y2);

/* Global functions */ 

ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x1,
    ILP_Object y2) {
{ 
  ILP_Object ilptmp305; 
  ILP_Object ilptmp306; 
ilptmp305 = x1; 
ilptmp306 = y2; 
return ILP_Plus(ilptmp305, ilptmp306);
} 
}
struct ILP_Closure foo_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__foo, 
       2, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp307; 
  ILP_Object ilptmp308; 
{ 
  ILP_Object ilptmp309; 
ilptmp309 = ILP_TRUE; 
  if ( ILP_isEquivalentToTrue(ilptmp309 ) ) {
ilptmp307 = ILP_Integer2ILP(8); 

  } else {
ilptmp307 = ILP_Integer2ILP(1); 

  }
}
{ 
  ILP_Object ilptmp310; 
ilptmp310 = ILP_Integer2ILP(8); 

  {
    ILP_Object x3 = ilptmp310;
{ 
  ILP_Object ilptmp311; 
  ILP_Object ilptmp312; 
ilptmp311 = x3; 
ilptmp312 = x3; 
ilptmp308 = ILP_Times(ilptmp311, ilptmp312);
} 

  }
}
return ilp__foo(NULL , ilptmp307, ilptmp308);
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
