/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.compiler.normalizer;

import com.paracamplus.ilp1.compiler.normalizer.INormalizationEnvironment;
import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp4.compiler.interfaces.IASTCclassDefinition;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;

public class Normalizer 
extends com.paracamplus.ilp4.compiler.normalizer.Normalizer 
implements 
IASTvisitor<IASTexpression, INormalizationEnvironment, CompilationException> {


	public Normalizer (INormalizationFactory factory,
			IASTCclassDefinition objectClass ) {
		super(factory,objectClass);
	}

	@Override
	public IASTexpression visit(IASTreadProperty iast, INormalizationEnvironment data) throws CompilationException {
		IASTexpression fieldName = iast.getProperty();
		IASTexpression target = iast.getObj().accept(this, data);
		return ((INormalizationFactory) factory).newReadProperty(target,fieldName);
	}


	@Override
	public IASTexpression visit(IASTwriteProperty iast, INormalizationEnvironment data) throws CompilationException {
		IASTexpression fieldName = iast.getProperty();
		IASTexpression target = iast.getObj().accept(this, data);
		IASTexpression value = iast.getValue().accept(this, data);
		return ((INormalizationFactory) factory).newWriteProperty(target,fieldName,value);
	}


	@Override
	public IASTexpression visit(IASThasProperty iast, INormalizationEnvironment data) throws CompilationException {
		IASTexpression fieldName = iast.getProperty();
		IASTexpression target = iast.getObj().accept(this, data);
		return ((INormalizationFactory) factory).newHasProperty(target,fieldName);
	}

}
