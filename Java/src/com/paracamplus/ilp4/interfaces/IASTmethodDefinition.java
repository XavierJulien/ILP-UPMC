/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.interfaces;

import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;

public interface IASTmethodDefinition extends IASTfunctionDefinition {
    String getMethodName();
	String getDefiningClassName();
}
