#include <stdio.h> 
#include <stdlib.h> 
#include "ilp.h" 

/* Global variables */ 
ILP_Object print;

/* Global prototypes */ 

/* Global functions */ 


ILP_Object ilp_program () 
{ 
{ 
  ILP_Object ilptmp63; 
ilptmp63 = ILP_Integer2ILP(5); 

  {
    ILP_Object x1 = ilptmp63;
{ 
  ILP_Object ilptmp64; 
while ( 1 ) { 
  ILP_Object ilptmp65; 
{ 
  ILP_Object ilptmp66; 
  ILP_Object ilptmp67; 
ilptmp66 = x1; 
ilptmp67 = ILP_Integer2ILP(53); 
ilptmp65 = ILP_LessThan(ilptmp66, ilptmp67);
} 
  if ( ILP_isEquivalentToTrue(ilptmp65) ) {
{ 
  ILP_Object ilptmp68; 
{ 
  ILP_Object ilptmp69; 
ilptmp69 = x1; 
ilptmp68 = ILP_print(ilptmp69);
}
{ 
  ILP_Object ilptmp70; 
{ 
  ILP_Object ilptmp71; 
  ILP_Object ilptmp72; 
ilptmp71 = ILP_Integer2ILP(2); 
ilptmp72 = x1; 
ilptmp70 = ILP_Times(ilptmp71, ilptmp72);
} 
ilptmp68 = (x1 = ilptmp70); 
} 
while ( 1 ) { 
  ILP_Object ilptmp73; 
{ 
  ILP_Object ilptmp74; 
  ILP_Object ilptmp75; 
ilptmp74 = x1; 
ilptmp75 = ILP_Integer2ILP(53); 
ilptmp73 = ILP_GreaterThan(ilptmp74, ilptmp75);
} 
  if ( ILP_isEquivalentToTrue(ilptmp73) ) {
{ 
  ILP_Object ilptmp76; 
{ 
  ILP_Object ilptmp77; 
ilptmp77 = x1; 
ilptmp76 = ILP_print(ilptmp77);
}
{ 
  ILP_Object ilptmp78; 
{ 
  ILP_Object ilptmp79; 
  ILP_Object ilptmp80; 
ilptmp79 = x1; 
ilptmp80 = ILP_Integer2ILP(3); 
ilptmp78 = ILP_Minus(ilptmp79, ilptmp80);
} 
ilptmp76 = (x1 = ilptmp78); 
} 
(void)ilptmp76; 
} 

} else { 
    break; 

}
}
ilptmp68 = ILP_FALSE; 
(void)ilptmp68; 
} 

} else { 
    break; 

}
}
ilptmp64 = ILP_FALSE; 
ilptmp64 = x1; 
return ilptmp64; 
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
