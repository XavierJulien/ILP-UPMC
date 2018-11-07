/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex2;


import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp2.ast.ASTfactory;
import com.paracamplus.ilp2.ilp2tme4.ex2.IASTvisitor;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.ast.ASToperator;
import com.paracamplus.ilp1.ast.ASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;


public class RemoveUnless implements IASTvisitor<IASTexpression, Void, EvaluationException> {

	@Override
	public IASTexpression visit(IASTassignment iast, Void data) throws EvaluationException {
		return new ASTfactory().newAssignment((IASTvariable)iast.getVariable().accept(this, data), 
											  iast.getExpression().accept(this, data));
	}
	
	@Override
	public IASTexpression visit(IASTalternative iast, Void data) throws EvaluationException {
		if(iast.isTernary())
            return new ASTfactory().newAlternative(iast.getCondition().accept(this, data),
                                                   iast.getConsequence().accept(this, data),
                                                   iast.getAlternant().accept(this, data));
        else
            return new ASTfactory().newAlternative(iast.getCondition().accept(this, data),
                                                   iast.getConsequence().accept(this, data),
                                                   null);
	}

	@Override
	public IASTexpression visit(IASTbinaryOperation iast, Void data) throws EvaluationException {
		return new ASTfactory().newBinaryOperation(iast.getOperator(), 
												   iast.getLeftOperand().accept(this, data), 
												   iast.getRightOperand().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTblock iast, Void data) throws EvaluationException {
		return new ASTfactory().newBlock(iast.getBindings(), iast.getBody().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTboolean iast, Void data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTfloat iast, Void data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinteger iast, Void data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinvocation iast, Void data) throws EvaluationException {
		int n = iast.getArguments().length;
        IASTexpression[] newArg = new IASTexpression[n];
		for(int i = 0;i<n;i++) {
			newArg[i] = iast.getArguments()[i].accept(this, data);
		}
		return new ASTfactory().newInvocation(iast.getFunction().accept(this, data), newArg);
	}

	@Override
	public IASTexpression visit(IASTsequence iast, Void data) throws EvaluationException {
		int n = iast.getExpressions().length;
        IASTexpression[] newEx = new IASTexpression[n];
		for(int i = 0;i<n;i++) {
			newEx[i] = iast.getExpressions()[i].accept(this, data);
		}
		return new ASTfactory().newSequence(newEx);
	}

	@Override
	public IASTexpression visit(IASTstring iast, Void data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTunaryOperation iast, Void data) throws EvaluationException {
		return new ASTfactory().newUnaryOperation(iast.getOperator(), 
												  iast.getOperand().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTvariable iast, Void data) throws EvaluationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTloop iast, Void data) throws EvaluationException {
		return new ASTfactory().newLoop(iast.getCondition().accept(this, data), 
										iast.getBody().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTunless iast, Void data) throws EvaluationException {
		 return new ASTfactory().newAlternative(new ASTunaryOperation(new ASToperator("!"), iast.getCondition().accept(this, data)),
                                                iast.getBody().accept(this, data),
                                                null);
	}

}
