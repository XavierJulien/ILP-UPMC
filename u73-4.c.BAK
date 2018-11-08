#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object fr1;
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
  ILP_Object ilptmp329; 
  ILP_Object ilptmp330; 
ilptmp329 = ILP_Integer2ILP(2); 
ilptmp330 = x1; 
return ILP_Times(ilptmp329, ilptmp330);
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
  ILP_Object ilptmp331; 
{ 
  ILP_Object ilptmp332; 
ilptmp332 = x2; 
ilptmp331 = ilp__f1(NULL , ilptmp332);
}
return ilp__f1(NULL , ilptmp331);
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
  ILP_Object ilptmp333; 
  ILP_Object ilptmp334; 
{ 
  ILP_Object ilptmp335; 
ilptmp335 = x4; 
ilptmp333 = ilp__f1(NULL , ilptmp335);
}
{ 
  ILP_Object ilptmp336; 
  ILP_Object ilptmp337; 
ilptmp336 = x4; 
ilptmp337 = x4; 
ilptmp334 = ilp__f2(NULL , ilptmp336, ilptmp337);
}
return ilp__f2(NULL , ilptmp333, ilptmp334);
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
  ILP_Object ilptmp338; 
ilptmp338 = x5; 
return ilp__fr2(NULL , ilptmp338);
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
  ILP_Object ilptmp339; 
{ 
  ILP_Object ilptmp340; 
ilptmp340 = x6; 
ilptmp339 = ilp__fr3(NULL , ilptmp340);
}
return ilp__fr3(NULL , ilptmp339);
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
  ILP_Object ilptmp341; 
{ 
  ILP_Object ilptmp342; 
{ 
  ILP_Object ilptmp343; 
ilptmp343 = x7; 
ilptmp342 = ilp__fr3(NULL , ilptmp343);
}
ilptmp341 = ilp__fr1(NULL , ilptmp342);
}
return ilp__f3(NULL , ilptmp341);
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
  ILP_Object ilptmp344; 
ilptmp344 = ILP_Integer2ILP(73); 
return ilp__f3(NULL , ilptmp344);
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
