/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.compiler.normalizer;


import com.paracamplus.ilp4.ilp4tme8.ast.ASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.ast.ASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.ast.ASTwriteProperty;
import com.paracamplus.ilp1.interfaces.IASTexpression;

public class NormalizationFactory
extends com.paracamplus.ilp4.compiler.normalizer.NormalizationFactory
implements INormalizationFactory {
    
	@Override
	public IASTexpression newReadProperty(IASTexpression fieldName, IASTexpression target) {
		return new ASTreadProperty(target, fieldName);
	}


	@Override
	public IASTexpression newHasProperty(IASTexpression fieldName, IASTexpression target) {
		return new ASThasProperty(target, fieldName);
	}


	@Override
	public IASTexpression newWriteProperty(IASTexpression fieldName, IASTexpression target,
			IASTexpression value) {
		return new ASTwriteProperty(target, fieldName, value);
	}
}
