/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.ast;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTfactory;

public class ASTfactory 
extends  com.paracamplus.ilp4.ast.ASTfactory
implements IASTfactory {
	@Override
	public IASTexpression newExists(IASTvariable variable) {
		return new ASTexists(variable);
	}
}
