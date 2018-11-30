package com.paracamplus.ilp3.ilp3tme7.interpreter.primitive;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;
import com.paracamplus.ilp3.ilp3tme7.thread.CoroutineInstance;

public class Resume extends Primitive {

	public Resume() {
		super("resume");
		
	}

	@Override
	public int getArity() {
		return 1;
	}

	@Override
	public Object apply (Object c) throws EvaluationException {
        if(c instanceof CoroutineInstance) {
		((CoroutineInstance) c).resumeCoroutine();
        return null;
        }else {
        	System.out.println("problème");
        	return null;
        }
    }
}
