#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object pseudosequence;
ILP_Object foo;

/* Global prototypes */ 
ILP_Object ilp__pseudosequence(ILP_Closure ilp_useless
,
    ILP_Object one1,
    ILP_Object two2);
ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x3);

/* Global functions */ 

ILP_Object ilp__pseudosequence(ILP_Closure ilp_useless
,
    ILP_Object one1,
    ILP_Object two2) {
return two2; 
}
struct ILP_Closure pseudosequence_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__pseudosequence, 
       2, 
       { NULL } } } 
}; 

ILP_Object ilp__foo(ILP_Closure ilp_useless
,
    ILP_Object x3) {
{ 
  ILP_Object ilptmp197; 
  ILP_Object ilptmp198; 
ilptmp197 = ILP_Integer2ILP(2); 
ilptmp198 = x3; 
return ILP_Times(ilptmp197, ilptmp198);
} 
}
struct ILP_Closure foo_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__foo, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp199; 
ilptmp199 = ILP_Integer2ILP(12); 

  {
    ILP_Object y4 = ilptmp199;
{ 
  ILP_Object ilptmp200; 
{ 
  ILP_Object ilptmp201; 
  ILP_Object ilptmp202; 
{ 
  ILP_Object ilptmp203; 
{ 
  ILP_Object ilptmp204; 
ilptmp204 = y4; 
ilptmp203 = ilp__foo(NULL , ilptmp204);
}
ilptmp201 = (y4 = ilptmp203); 
} 
ilptmp202 = y4; 
ilptmp200 = ilp__pseudosequence(NULL , ilptmp201, ilptmp202);
}
return ilp__foo(NULL , ilptmp200);
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
