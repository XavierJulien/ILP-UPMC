/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.interpreter;


import java.util.ArrayList;

import com.paracamplus.ilp1.interfaces.IASTalternative;
import com.paracamplus.ilp1.interfaces.IASTbinaryOperation;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTboolean;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.interfaces.IASTfloat;
import com.paracamplus.ilp1.interfaces.IASTinteger;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTsequence;
import com.paracamplus.ilp1.interfaces.IASTstring;
import com.paracamplus.ilp1.interfaces.IASTunaryOperation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp2.interfaces.IASTassignment;
import com.paracamplus.ilp2.interfaces.IASTfunctionDefinition;
import com.paracamplus.ilp2.interfaces.IASTloop;
import com.paracamplus.ilp3.interfaces.IASTcodefinitions;
import com.paracamplus.ilp3.interfaces.IASTlambda;
import com.paracamplus.ilp3.interfaces.IASTtry;
import com.paracamplus.ilp4.ilp4tme10.ast.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;
import com.paracamplus.ilp4.interfaces.IASTclassDefinition;
import com.paracamplus.ilp4.interfaces.IASTfieldRead;
import com.paracamplus.ilp4.interfaces.IASTfieldWrite;
import com.paracamplus.ilp4.interfaces.IASTinstantiation;
import com.paracamplus.ilp4.interfaces.IASTmethodDefinition;
import com.paracamplus.ilp4.interfaces.IASTprogram;
import com.paracamplus.ilp4.interfaces.IASTself;
import com.paracamplus.ilp4.interfaces.IASTsend;
import com.paracamplus.ilp4.interfaces.IASTsuper;

public class GlobalVariableRecon 
implements IASTvisitor<Void, ArrayList<String>, EvaluationException> {
	
	public ArrayList<String> visit(IASTprogram iast, ArrayList<String> data) throws EvaluationException {
        for(IASTfunctionDefinition def: iast.getFunctionDefinitions()) {
            def.getBody().accept(this, data);
        }
        for(IASTclassDefinition def: iast.getClassDefinitions()) {
            for(IASTmethodDefinition defM: def.getProperMethodDefinitions()) {
                defM.getBody().accept(this, data);
            }
        }
        iast.getBody().accept(this, data);
        return null;
    }
	
    @Override
    public Void visit(IASTinstantiation iast, ArrayList<String> data) throws EvaluationException {
        for(IASTexpression e: iast.getArguments()) e.accept(this, data);
        return null;
    }

    @Override
    public Void visit(IASTfieldRead iast, ArrayList<String> data) throws EvaluationException {
        iast.getTarget().accept(this, data);
        return null;
    }

    @Override
    public Void visit(IASTself iast, ArrayList<String> data) throws EvaluationException {
        return null;
    }

    @Override
    public Void visit(IASTsend iast, ArrayList<String> data) throws EvaluationException {
        for(IASTexpression e: iast.getArguments()) e.accept(this, data);
        iast.getReceiver().accept(this, data);
        return null;
    }

    @Override
    public Void visit(IASTsuper iast, ArrayList<String> data) throws EvaluationException {
        return null;
    }

    @Override
    public Void visit(IASTfieldWrite iast, ArrayList<String> data) throws EvaluationException {
        iast.getTarget().accept(this, data);
        iast.getValue().accept(this, data);
        return null;
    }

    @Override
    public Void visit(IASTcodefinitions iast, ArrayList<String> data) throws EvaluationException {
        for(IASTlambda l: iast.getFunctions()) l.accept(this, data);
        iast.getBody().accept(this, data);
        return null;
    }

    @Override
    public Void visit(IASTlambda iast, ArrayList<String> data) throws EvaluationException {
        iast.getBody().accept(this, data);
        return null;
}

	@Override
	public Void visit(IASTtry iast, ArrayList<String> data) throws EvaluationException {
		iast.getBody().accept(this, data);
		if(iast.getCatcher() != null) iast.getCatcher().accept(this, data);
		if(iast.getFinallyer() != null) iast.getFinallyer().accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTassignment iast, ArrayList<String> data) throws EvaluationException {
		System.out.println("variable " + iast.getVariable().getMangledName());
		iast.getExpression().accept(this, data);
		data.add(iast.getVariable().getMangledName());
		return null;
	}

	@Override
	public Void visit(IASTloop iast, ArrayList<String> data) throws EvaluationException {
		iast.getBody().accept(this, data);
		iast.getCondition().accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTalternative iast, ArrayList<String> data) throws EvaluationException {
		iast.getCondition().accept(this, data);
		iast.getConsequence().accept(this, data);
		if(iast.isTernary())iast.getAlternant().accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTbinaryOperation iast, ArrayList<String> data) throws EvaluationException {
		for(IASTexpression e :iast.getOperands()) e.accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTblock iast, ArrayList<String> data) throws EvaluationException {
		ArrayList<String> temp = new ArrayList<String>();
        for(IASTblock.IASTbinding bi: iast.getBindings()) {
            bi.getInitialisation().accept(this, temp);
            
        }
        iast.getBody().accept(this, data);
        data.removeAll(temp);
		return null;
	}

	@Override
	public Void visit(IASTboolean iast, ArrayList<String> data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Void visit(IASTfloat iast, ArrayList<String> data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Void visit(IASTinteger iast, ArrayList<String> data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Void visit(IASTinvocation iast, ArrayList<String> data) throws EvaluationException {
		for(IASTexpression e :iast.getArguments()) e.accept(this, data);
		iast.getFunction().accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTsequence iast, ArrayList<String> data) throws EvaluationException {
		for(IASTexpression e: iast.getExpressions()) e.accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTstring iast, ArrayList<String> data) throws EvaluationException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Void visit(IASTunaryOperation iast, ArrayList<String> data) throws EvaluationException {
		iast.getOperand().accept(this, data);
		return null;
	}

	@Override
	public Void visit(IASTvariable iast, ArrayList<String> data) throws EvaluationException {
		return null;
	}

	@Override
	public Void visit(IASTexists iast, ArrayList<String> data) throws EvaluationException {
		iast.getVariable().accept(this, data);
		return null;
	}
}