package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.UnaryPrimitive;

public class VectorLength extends UnaryPrimitive{

	public VectorLength() {
		super("vectorLength");
		// TODO Auto-generated constructor stub
	}

	@Override
	public Object apply(Object arg1) throws EvaluationException {
		if(!(arg1 instanceof Object[])) throw new EvaluationException("ce n'est pas un vecteur");
		Object[] tab = (Object[])arg1;
		System.out.println(tab.length);
		return tab.length;
	}

}
