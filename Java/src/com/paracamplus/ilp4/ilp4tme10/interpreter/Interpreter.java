/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.interpreter;

import com.paracamplus.ilp4.ilp4tme10.ast.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;
import com.paracamplus.ilp4.interfaces.IASTprogram;

import java.util.ArrayList;
import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp4.interpreter.interfaces.IClassEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.ILexicalEnvironment;
import com.paracamplus.ilp1.interpreter.interfaces.IOperatorEnvironment;

public class Interpreter extends com.paracamplus.ilp4.interpreter.Interpreter
implements IASTvisitor<Object, ILexicalEnvironment, EvaluationException> 
{
    public ArrayList<String> vars;
    public GlobalVariableRecon data;
	public Interpreter (IGlobalVariableEnvironment globalVariableEnvironment,
            IOperatorEnvironment operatorEnvironment,
            IClassEnvironment classEnvironment ) {
		super(globalVariableEnvironment, operatorEnvironment, classEnvironment);
		data = new GlobalVariableRecon();
		vars = new ArrayList<>();
	}
	
	public Object visit(com.paracamplus.ilp1.interfaces.IASTprogram iast, ILexicalEnvironment lexenv) throws EvaluationException {
		data.visit((IASTprogram)iast, vars);
    	return visit((IASTprogram)iast, lexenv);
    }
	public Object visit(IASTexists iast, ILexicalEnvironment lexenv) throws EvaluationException {
		
		 return lexenv.isPresent(iast.getVariable()) || (getGlobalVariableEnvironment().getGlobalVariableValue(iast.getVariable().getMangledName()) != null) || iast.exists(vars);

	}
}
