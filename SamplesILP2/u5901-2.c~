#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object pseudosequence;
ILP_Object foo;

/* Global prototypes */ 
ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x1);
ILP_Object ilp__pseudosequence(ILP_Closure ilp_useless
,
    ILP_Object one2,
    ILP_Object two3);

/* Global functions */ 

ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x1) {
{ 
  ILP_Object ilptmp180; 
  ILP_Object ilptmp181; 
ilptmp180 = ILP_Integer2ILP(2); 
ilptmp181 = x1; 
return ILP_Times(ilptmp180, ilptmp181);
} 
}
struct ILP_Closure foo_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__foo, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__pseudosequence(ILP_Closure ilp_useless
,
    ILP_Object one2,
    ILP_Object two3) {
return two3; 
}
struct ILP_Closure pseudosequence_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__pseudosequence, 
       2, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp182; 
ilptmp182 = ILP_Integer2ILP(11); 

  {
    ILP_Object y4 = ilptmp182;
{ 
  ILP_Object ilptmp183; 
{ 
  ILP_Object ilptmp184; 
  ILP_Object ilptmp185; 
{ 
  ILP_Object ilptmp186; 
{ 
  ILP_Object ilptmp187; 
  ILP_Object ilptmp188; 
ilptmp187 = y4; 
ilptmp188 = ILP_Integer2ILP(1); 
ilptmp186 = ILP_Plus(ilptmp187, ilptmp188);
} 
ilptmp184 = (y4 = ilptmp186); 
} 
ilptmp185 = y4; 
ilptmp183 = ilp__pseudosequence(NULL , ilptmp184, ilptmp185);
}
return ilp__foo(NULL , ilptmp183);
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
