package com.paracamplus.ilp1.ilp1tme2.ex2;

import com.paracamplus.ilp1.interfaces.*;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;

public class CountConstant implements com.paracamplus.ilp1.interfaces.IASTvisitor<Integer, Void, EvaluationException>{

	@Override
	public Integer visit(IASTalternative iast, Void data) throws EvaluationException {
		 int count = iast.getCondition().accept(this, data) + iast.getConsequence().accept(this, data);
	        if(iast.getAlternant() != null) count += iast.getAlternant().accept(this, data);
	        return count;
	}

	@Override
	public Integer visit(IASTbinaryOperation iast, Void data) throws EvaluationException {
		return iast.getLeftOperand().accept(this, data)+iast.getRightOperand().accept(this, data);
		}

	@Override
	public Integer visit(IASTblock iast, Void data) throws EvaluationException {
		int bindingsCount = 0;
        for(IASTblock.IASTbinding b: iast.getBindings()) {
            bindingsCount += b.getInitialisation().accept(this, data);
        }
		return bindingsCount + iast.getBody().accept(this, data);
	}

	@Override
	public Integer visit(IASTboolean iast, Void data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTfloat iast, Void data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTinteger iast, Void data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTinvocation iast, Void data) throws EvaluationException {
		int cpt = iast.getFunction().accept(this, data);
		IASTexpression[] t = iast.getArguments();
		for(int i = 0;i<t.length;i++) {
			cpt += t[i].accept(this, data);
		}
		return cpt;
	}

	@Override
	public Integer visit(IASTsequence iast, Void data) throws EvaluationException {
		int cpt = 0;
		IASTexpression[] t = iast.getExpressions();
		for(int i = 0;i<t.length;i++) {
			cpt += t[i].accept(this, data);
		}
		return cpt;
	}

	@Override
	public Integer visit(IASTstring iast, Void data) throws EvaluationException {
		return 1;
	}

	@Override
	public Integer visit(IASTunaryOperation iast, Void data) throws EvaluationException {
		return iast.getOperand().accept(this, data);
	}

	@Override
	public Integer visit(IASTvariable iast, Void data) throws EvaluationException {
		return 0;
	}

}
