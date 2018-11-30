/* *****************************************************************
 * ilp3 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp3
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.interpreter;

import java.util.List;
import java.util.Vector;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp3.ilp3tme7.interfaces.IASTcostart;
import com.paracamplus.ilp3.ilp3tme7.interfaces.IASTvisitor;
import com.paracamplus.ilp3.ilp3tme7.thread.CoroutineInstance;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.Invocable;

public class Interpreter extends com.paracamplus.ilp3.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {
    
	 public Interpreter(IGlobalVariableEnvironment globalVariableEnvironment,
				IOperatorEnvironment operatorEnvironment) {
			super(globalVariableEnvironment, operatorEnvironment);
		}

	@Override
	public Object visit(IASTcostart iast, ILexicalEnvironment data) throws EvaluationException {
		IASTexpression fun = iast.getFunction();
		IASTexpression[] args = iast.getArguments();
		Object function = fun.accept(this, data);
        if ( function instanceof Invocable ) {
            Invocable f = (Invocable)function;
            List<Object> newArgs = new Vector<Object>();
            for ( IASTexpression arg : args ) {
                Object value = arg.accept(this, data);
                newArgs.add(value);
            }
    		CoroutineInstance c = new CoroutineInstance(f,this,newArgs.toArray());
    		c.start();
    		return c;
        } else {
        	System.out.println("pas possible");
            String msg = "Cannot apply " + function;
            throw new EvaluationException(msg);
        }
	}

}
