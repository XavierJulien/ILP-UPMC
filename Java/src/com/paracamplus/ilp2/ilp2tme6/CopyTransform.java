/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme6;


import com.paracamplus.ilp2.interfaces.IASTfactory;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.ast.ASTfactory;
import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp2.interfaces.IASTprogram;
import com.paracamplus.ilp2.interfaces.IASTvisitor;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASToperator;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;


public class CopyTransform<Data> implements IASTvisitor<IASTexpression, Data, CompilationException> {
    

    // 
    public IASTfactory factory;
    
    public CopyTransform(IASTfactory fact) {
    	this.factory = fact;	
	}
    
    public IASTprogram visit(IASTprogram iast, Data data) throws CompilationException {
    	IASTfunctionDefinition[] fcts = iast.getFunctionDefinitions();
    	IASTfunctionDefinition[] fcts2 = new IASTfunctionDefinition[fcts.length];
    	for(int j = 0; j < fcts.length; j++) {
    		IASTfunctionDefinition f = fcts[j];
    		IASTexpression newBody = f.getBody().accept(this, data);
    		//System.out.println(f.getFunctionVariable().getName());
    		fcts2[j] = factory.newFunctionDefinition(f.getFunctionVariable(), f.getVariables(), newBody);//Pas sur
    	}
    	IASTexpression body = iast.getBody().accept(this, data);
		return factory.newProgram(fcts2, body);
		
    }

	@Override
	public IASTexpression visit(IASTalternative iast, Data data) throws CompilationException {
		IASTexpression c = iast.getCondition().accept(this, data);
		IASTexpression t = iast.getConsequence().accept(this, data);
        if ( iast.isTernary() ) {
        	IASTexpression a = iast.getAlternant().accept(this, data);
            return factory.newAlternative(c, t, a);
        } else {
        	IASTexpression whatever = factory.newBooleanConstant("false");
            return factory.newAlternative(c, t, whatever);
        }
	}

	@Override
	public IASTexpression visit(IASTbinaryOperation iast, Data data) throws CompilationException {
		IASToperator operator = iast.getOperator();
        IASTexpression left = iast.getLeftOperand().accept(this, data);
        IASTexpression right = iast.getRightOperand().accept(this, data);
        return factory.newBinaryOperation(operator, left, right);
	}

	@Override
	public IASTexpression visit(IASTblock iast, Data data) throws CompilationException {
		return new ASTfactory().newBlock(iast.getBindings(), iast.getBody().accept(this, data));
	}

	@Override
	public IASTexpression visit(IASTboolean iast, Data data) throws CompilationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTfloat iast, Data data) throws CompilationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinteger iast, Data data) throws CompilationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTinvocation iast, Data data) throws CompilationException {
		int n = iast.getArguments().length;
        IASTexpression[] newArg = new IASTexpression[n];
		for(int i = 0;i<n;i++) {
			newArg[i] = iast.getArguments()[i].accept(this, data);
		}
		return new ASTfactory().newInvocation(iast.getFunction().accept(this, data), newArg);
	
	}

	@Override
	public IASTexpression visit(IASTsequence iast, Data data) throws CompilationException {
		IASTexpression[] expressions = iast.getExpressions();
        IASTexpression[] exprs = new IASTexpression[expressions.length];
        for ( int i=0 ; i< expressions.length ; i++ ) {
            exprs[i] = expressions[i].accept(this, data);
        }
        if ( iast.getExpressions().length == 1 ) {
            return exprs[0];
        } else {
            return factory.newSequence(exprs);
        }
	}

	@Override
	public IASTexpression visit(IASTstring iast, Data data) throws CompilationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTunaryOperation iast, Data data) throws CompilationException {
        IASToperator operator = iast.getOperator();
        IASTexpression operand = iast.getOperand().accept(this, data);
        return factory.newUnaryOperation(operator, operand);
	}

	@Override
	public IASTvariable visit(IASTvariable iast, Data data) throws CompilationException {
		return iast;
	}

	@Override
	public IASTexpression visit(IASTassignment iast, Data data) throws CompilationException {
		 IASTvariable variable = iast.getVariable();
	     IASTvariable newvariable = visit(variable, data);
	     IASTexpression expression = iast.getExpression();
	     IASTexpression newexpression = expression.accept(this, data);
	     return factory.newAssignment(newvariable, newexpression);
	    
	}

	@Override
	public IASTexpression visit(IASTloop iast, Data data) throws CompilationException {
        IASTexpression newcondition = iast.getCondition().accept(this, data);
        IASTexpression newbody = iast.getBody().accept(this, data);
        return factory.newLoop(newcondition, newbody);
	}



}
