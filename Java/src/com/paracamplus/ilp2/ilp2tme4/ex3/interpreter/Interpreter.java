/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex3.interpreter;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTunless;
import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTvisitor;


public class Interpreter extends com.paracamplus.ilp2.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {
        
    public Interpreter(IGlobalVariableEnvironment globalVariableEnvironment,
			IOperatorEnvironment operatorEnvironment) {
		super(globalVariableEnvironment, operatorEnvironment);
	}

    
	public Object visit(IASTunless iast, ILexicalEnvironment data) throws EvaluationException {
        Object c = iast.getCondition().accept(this, data);
        if( c != null && c instanceof Boolean) {
        	Boolean b = (Boolean) c;
        	if(!b.booleanValue()) {
        		return iast.getBody().accept(this, data);
        	}else {
        		return new Object();
        	}
        }else {
        	throw new EvaluationException("la condition n'est pas un booléen");
        }
	}

}
