/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.interpreter;

import com.paracamplus.ilp4.ilp4tme8.interfaces.IASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp4.interpreter.ILP9Instance;
import com.paracamplus.ilp4.interpreter.interfaces.IClassEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;

public class Interpreter extends com.paracamplus.ilp4.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> 
{

	public Interpreter (IGlobalVariableEnvironment globalVariableEnvironment,
			IOperatorEnvironment operatorEnvironment,
			IClassEnvironment classEnvironment ) {
		super(globalVariableEnvironment, operatorEnvironment,classEnvironment);
	}

	// Class-related methods 

	@Override
	public Object visit(IASTreadProperty iast, ILexicalEnvironment data) throws EvaluationException {
		Object obj = iast.getObj().accept(this, data);
		Object property = iast.getProperty().accept(this, data);
		if ( obj instanceof ILP9Instance ) {
			return ((ILP9Instance) obj).read((String)property);
		} else {
			String msg = "Not an ILP9 instance " + property;
			throw new EvaluationException(msg);
		}
	}

	@Override
	public Object visit(IASTwriteProperty iast, ILexicalEnvironment data) throws EvaluationException {
		Object obj = iast.getObj().accept(this, data);
		Object property = iast.getProperty().accept(this, data);
		Object value = iast.getValue().accept(this, data);
		if ( obj instanceof ILP9Instance ) {
			return ((ILP9Instance) obj).write((String)property,value);
		} else {
			String msg = "Not an ILP9 instance " + obj;
			throw new EvaluationException(msg);
		}
	}

	@Override
	public Object visit(IASThasProperty iast, ILexicalEnvironment data) throws EvaluationException {
		Object obj = iast.getObj().accept(this, data);
		String property = (String)iast.getProperty().accept(this, data);
		if ( obj instanceof ILP9Instance ) {
			try {
				((ILP9Instance) obj).read(property);
				return true;
			}catch(EvaluationException e) {
				return false;
			}
		}else {
			String msg = "Not an ILP9 instance " + property;
			throw new EvaluationException(msg);

		}
	}
}
