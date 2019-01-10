/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.ast;

import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;

public class ASTreadProperty extends ASTexpression
implements IASTreadProperty {

	public ASTreadProperty (IASTexpression obj,
			IASTexpression property) {
		this.obj = obj;
		this.property = property;
	}
	private final IASTexpression obj;
	private final IASTexpression property;


	@Override
	public <Result, Data, Anomaly extends Throwable> Result accept(
			com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor,
			Data data) throws Anomaly {
		return ((IASTvisitor<Result, Data, Anomaly>) visitor).visit(this, data);
	}

	@Override
	public IASTexpression getObj() {
		return this.obj;
	}

	@Override
	public IASTexpression getProperty() {
		return this.property;
	}
}
