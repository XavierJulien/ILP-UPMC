/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex2;


import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp2.ilp2tme4.ex2.IASTvisitor;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;


public class RemoveUnless implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> {

	@Override
	public Object visit(IASTalternative iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTbinaryOperation iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTblock iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTboolean iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTfloat iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTinteger iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTinvocation iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTsequence iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTstring iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTunaryOperation iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTvariable iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTloop iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTunless iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Object visit(IASTassignment iast, ILexicalEnvironment data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}


}
