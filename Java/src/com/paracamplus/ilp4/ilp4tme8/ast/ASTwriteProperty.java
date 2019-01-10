/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.ast;

import com.paracamplus.ilp1.ast.ASTexpression;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;

public class ASTwriteProperty extends ASTexpression
implements IASTwriteProperty {

	public ASTwriteProperty (IASTexpression obj,
			IASTexpression property, IASTexpression value) {
		this.obj = obj;
		this.property = property;
		this.value = value;
	}
	private final IASTexpression obj;
	private final IASTexpression property;
	private final IASTexpression value;


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

	@Override
	public IASTexpression getValue() {
		return this.value;
	}
}
