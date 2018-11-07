package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;

import java.math.BigInteger;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;

public class MakeVector extends Primitive{

	public MakeVector() {
		super("makeVector");
	}

	@Override
	public int getArity() {
		// TODO Auto-generated method stub
		return 2;
	}

	@Override
	public Object apply(Object arg1, Object arg2)
			throws EvaluationException {
		if(arg1 instanceof BigInteger){
			BigInteger taille = (BigInteger)arg1;
			Object[] tab = new Object[taille.intValue()];
			for(int i = 0 ;i<taille.intValue();i++){
				tab[i] = arg2;
			}
			return tab;
		}else{
			throw new EvaluationException("ce n'est pas un int");
		}
	}

}
