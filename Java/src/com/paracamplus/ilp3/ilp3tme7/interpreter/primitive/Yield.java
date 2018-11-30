package com.paracamplus.ilp3.ilp3tme7.interpreter.primitive;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;
import com.paracamplus.ilp3.ilp3tme7.thread.CoroutineInstance;

public class Yield extends Primitive {

	public Yield() {
        super("yield");
    }
	@Override
	public int getArity() {
		return 0;
	}

	@Override
	public Object apply () throws EvaluationException {
        if(Thread.currentThread() instanceof CoroutineInstance) {
        	((CoroutineInstance)Thread.currentThread()).yieldCoroutine();
        return null;
        }else {
        	System.out.println("problème");
        	return null;
        }
    }
}
