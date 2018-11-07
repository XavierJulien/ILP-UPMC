package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;

import java.math.BigInteger;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;

public class VectorGet extends Primitive{

	public VectorGet() {
		super("vectorGet");
	}

	@Override
	public int getArity() {
		// TODO Auto-generated method stub
		return 2;
	}

	@Override
	public Object apply(Object arg1, Object arg2)throws EvaluationException {
		if(arg1 instanceof Object[]) {
			if(arg2 instanceof BigInteger){
				Object[] tab = (Object[])arg1;
				BigInteger index = (BigInteger)arg2;
				return tab[index.intValue()];
			}else{
				throw new EvaluationException("ce n'est pas un entier");
			}
		}else{
			throw new EvaluationException("ce n'est pas un vecteur");
		}
	}

}