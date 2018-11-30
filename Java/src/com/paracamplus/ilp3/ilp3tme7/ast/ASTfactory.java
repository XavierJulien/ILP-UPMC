/* *****************************************************************
 * ilp3 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp3
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.ast;


import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp3.ilp3tme7.interfaces.IASTfactory;

public class ASTfactory extends com.paracamplus.ilp3.ast.ASTfactory
implements IASTfactory{

	@Override
	public IASTexpression newCostart(IASTexpression function, IASTexpression[] args) {
		return new ASTcostart(function,args);
	}

    
   
}
