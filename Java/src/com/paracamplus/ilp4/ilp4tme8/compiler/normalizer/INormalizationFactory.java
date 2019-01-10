/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.compiler.normalizer;

import com.paracamplus.ilp1.interfaces.IASTexpression;

public interface INormalizationFactory 
extends com.paracamplus.ilp4.compiler.normalizer.INormalizationFactory {

	IASTexpression newReadProperty(IASTexpression fieldName, 
			IASTexpression target);

	IASTexpression newHasProperty(IASTexpression fieldName, 
			IASTexpression target);

	IASTexpression newWriteProperty(IASTexpression fieldName,
			IASTexpression target, 
			IASTexpression value);


}
