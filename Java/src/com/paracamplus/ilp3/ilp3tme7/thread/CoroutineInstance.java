package com.paracamplus.ilp3.ilp3tme7.thread;

import java.util.concurrent.Semaphore;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.Invocable;
import com.paracamplus.ilp3.ilp3tme7.interpreter.Interpreter;

public class CoroutineInstance extends Thread {

	protected Invocable f;
	protected Interpreter interpreter;
	protected Object[] array;
	protected Semaphore yieldsem;
	protected Semaphore resumesem;
	private boolean isfinished = false;
	
	public CoroutineInstance(Invocable f, Interpreter interpreter, Object[] array) {
		yieldsem = new Semaphore(0);
		resumesem = new Semaphore(0);
		this.f = f;
		this.interpreter = interpreter;
		this.array = array;
	}
	@Override
	public void run() {
		try {
			resumesem.acquireUninterruptibly();
			f.apply(interpreter, array);
			isfinished  = true;
			yieldsem.release();
		} catch (EvaluationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void resumeCoroutine() {
		if(!isfinished) {
			resumesem.release();
			yieldsem.acquireUninterruptibly();
			
		}
	}
	
	public void yieldCoroutine() {
		yieldsem.release();
		resumesem.acquireUninterruptibly();
		
		
	}
}
