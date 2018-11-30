#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object even;
ILP_Object odd;

/* Global prototypes */ 
ILP_Object ilp__odd(ILP_Closure ilp_useless
,
    ILP_Object n1);
ILP_Object ilp__even(ILP_Closure ilp_useless
,
    ILP_Object n2);

/* Global functions */ 

ILP_Object ilp__odd(ILP_Closure ilp_useless
,
    ILP_Object n1) {
{ 
  ILP_Object ilptmp137; 
{ 
  ILP_Object ilptmp138; 
  ILP_Object ilptmp139; 
ilptmp138 = n1; 
ilptmp139 = ILP_Integer2ILP(0); 
ilptmp137 = ILP_Equal(ilptmp138, ilptmp139);
} 
  if ( ILP_isEquivalentToTrue(ilptmp137 ) ) {
return ILP_FALSE; 

  } else {
{ 
  ILP_Object ilptmp140; 
{ 
  ILP_Object ilptmp141; 
  ILP_Object ilptmp142; 
ilptmp141 = n1; 
ilptmp142 = ILP_Integer2ILP(1); 
ilptmp140 = ILP_Equal(ilptmp141, ilptmp142);
} 
  if ( ILP_isEquivalentToTrue(ilptmp140 ) ) {
return ILP_TRUE; 

  } else {
{ 
  ILP_Object ilptmp143; 
{ 
  ILP_Object ilptmp144; 
  ILP_Object ilptmp145; 
ilptmp144 = n1; 
ilptmp145 = ILP_Integer2ILP(1); 
ilptmp143 = ILP_Minus(ilptmp144, ilptmp145);
} 
return ilp__even(NULL , ilptmp143);
}

  }
}

  }
}
}
struct ILP_Closure odd_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__odd, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__even(ILP_Closure ilp_useless
,
    ILP_Object n2) {
{ 
  ILP_Object ilptmp146; 
{ 
  ILP_Object ilptmp147; 
  ILP_Object ilptmp148; 
ilptmp147 = n2; 
ilptmp148 = ILP_Integer2ILP(0); 
ilptmp146 = ILP_Equal(ilptmp147, ilptmp148);
} 
  if ( ILP_isEquivalentToTrue(ilptmp146 ) ) {
return ILP_TRUE; 

  } else {
{ 
  ILP_Object ilptmp149; 
{ 
  ILP_Object ilptmp150; 
  ILP_Object ilptmp151; 
ilptmp150 = n2; 
ilptmp151 = ILP_Integer2ILP(1); 
ilptmp149 = ILP_Equal(ilptmp150, ilptmp151);
} 
  if ( ILP_isEquivalentToTrue(ilptmp149 ) ) {
return ILP_FALSE; 

  } else {
{ 
  ILP_Object ilptmp152; 
{ 
  ILP_Object ilptmp153; 
  ILP_Object ilptmp154; 
ilptmp153 = n2; 
ilptmp154 = ILP_Integer2ILP(1); 
ilptmp152 = ILP_Minus(ilptmp153, ilptmp154);
} 
return ilp__odd(NULL , ilptmp152);
}

  }
}

  }
}
}
struct ILP_Closure even_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__even, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp155; 
{ 
  ILP_Object ilptmp156; 
ilptmp156 = ILP_Integer2ILP(56); 
ilptmp155 = ilp__odd(NULL , ilptmp156);
}
return ILP_Not(ilptmp155);
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
