/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.ast;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTfactory;
public class ASTfactory 
extends  com.paracamplus.ilp4.ast.ASTfactory
implements IASTfactory {


    
	@Override
	public IASTexpression newHasProperty(IASTexpression obj, IASTexpression property) {
		return new ASThasProperty(obj, property);
	}



	@Override
	public IASTexpression newWriteProperty(IASTexpression obj, IASTexpression property, IASTexpression value) {
		return new ASTwriteProperty(obj, property, value);
	}



	@Override
	public IASTexpression newReadProperty(IASTexpression obj, IASTexpression property) {
		return new ASTreadProperty(obj, property);
	}
}
