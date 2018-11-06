#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object fr3;
ILP_Object fr2;
ILP_Object f1;
ILP_Object f2;
ILP_Object f3;

/* Global prototypes */ 
ILP_Object ilp__f1(ILP_Closure ilp_useless
,
    ILP_Object x1);
ILP_Object ilp__f2(ILP_Closure ilp_useless
,
    ILP_Object x2,
    ILP_Object y3);
ILP_Object ilp__f3(ILP_Closure ilp_useless
,
    ILP_Object x4);
ILP_Object ilp__fr1(ILP_Closure ilp_useless
,
    ILP_Object x5);
ILP_Object ilp__fr2(ILP_Closure ilp_useless
,
    ILP_Object x6);
ILP_Object ilp__fr3(ILP_Closure ilp_useless
,
    ILP_Object x7);

/* Global functions */ 

ILP_Object ilp__f1(ILP_Closure ilp_useless
,
    ILP_Object x1) {
{ 
  ILP_Object ilptmp364; 
{ 
  ILP_Object ilptmp365; 
  ILP_Object ilptmp366; 
ilptmp365 = x1; 
ilptmp366 = ILP_Integer2ILP(74); 
ilptmp364 = ILP_LessThan(ilptmp365, ilptmp366);
} 
  if ( ILP_isEquivalentToTrue(ilptmp364 ) ) {
{ 
  ILP_Object ilptmp367; 
  ILP_Object ilptmp368; 
ilptmp367 = ILP_Integer2ILP(2); 
ilptmp368 = x1; 
return ILP_Times(ilptmp367, ilptmp368);
} 

  } else {
return x1; 

  }
}
}
struct ILP_Closure f1_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__f1, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__f2(ILP_Closure ilp_useless
,
    ILP_Object x2,
    ILP_Object y3) {
{ 
  ILP_Object ilptmp369; 
{ 
  ILP_Object ilptmp370; 
ilptmp370 = x2; 
ilptmp369 = ilp__f1(NULL , ilptmp370);
}
return ilp__f1(NULL , ilptmp369);
}
}
struct ILP_Closure f2_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__f2, 
       2, 
       { NULL } } } 
}; 

ILP_Object ilp__f3(ILP_Closure ilp_useless
,
    ILP_Object x4) {
{ 
  ILP_Object ilptmp371; 
  ILP_Object ilptmp372; 
{ 
  ILP_Object ilptmp373; 
ilptmp373 = x4; 
ilptmp371 = ilp__f1(NULL , ilptmp373);
}
{ 
  ILP_Object ilptmp374; 
  ILP_Object ilptmp375; 
ilptmp374 = x4; 
ilptmp375 = x4; 
ilptmp372 = ilp__f2(NULL , ilptmp374, ilptmp375);
}
return ilp__f2(NULL , ilptmp371, ilptmp372);
}
}
struct ILP_Closure f3_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__f3, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__fr1(ILP_Closure ilp_useless
,
    ILP_Object x5) {
{ 
  ILP_Object ilptmp376; 
ilptmp376 = x5; 
return ilp__fr2(NULL , ilptmp376);
}
}
struct ILP_Closure fr1_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__fr1, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__fr2(ILP_Closure ilp_useless
,
    ILP_Object x6) {
{ 
  ILP_Object ilptmp377; 
{ 
  ILP_Object ilptmp378; 
ilptmp378 = x6; 
ilptmp377 = ilp__fr3(NULL , ilptmp378);
}
return ilp__fr3(NULL , ilptmp377);
}
}
struct ILP_Closure fr2_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__fr2, 
       1, 
       { NULL } } } 
}; 

ILP_Object ilp__fr3(ILP_Closure ilp_useless
,
    ILP_Object x7) {
{ 
  ILP_Object ilptmp379; 
{ 
  ILP_Object ilptmp380; 
{ 
  ILP_Object ilptmp381; 
ilptmp381 = x7; 
ilptmp380 = ilp__f3(NULL , ilptmp381);
}
ilptmp379 = ilp__f1(NULL , ilptmp380);
}
return ilp__f3(NULL , ilptmp379);
}
}
struct ILP_Closure fr3_closure_object = { 
   &ILP_object_Closure_class, 
   { { ilp__fr3, 
       1, 
       { NULL } } } 
}; 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp382; 
ilptmp382 = ILP_Integer2ILP(74); 
return ilp__fr3(NULL , ilptmp382);
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
