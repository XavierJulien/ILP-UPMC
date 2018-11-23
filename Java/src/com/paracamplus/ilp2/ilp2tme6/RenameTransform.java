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

import com.paracamplus.ilp2.interfaces.IASTprogram;
import com.paracamplus.ilp2.interfaces.IASTvisitor;
import com.paracamplus.ilp1.interfaces.IASTinvocation;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.compiler.normalizer.INormalizationEnvironment;
import com.paracamplus.ilp1.interfaces.IASTblock;
import com.paracamplus.ilp1.interfaces.IASTblock.IASTbinding;
import com.paracamplus.ilp1.interfaces.IASTexpression;

public class RenameTransform extends CopyTransform<INormalizationEnvironment> implements IASTvisitor<IASTexpression, INormalizationEnvironment, CompilationException> {
    
	public static int cpt = 0;
    public RenameTransform(IASTfactory fact) {
    	super(fact);
	}
    
    public IASTprogram visit(IASTprogram iast, INormalizationEnvironment data) throws CompilationException {
    	IASTfunctionDefinition[] fcts = iast.getFunctionDefinitions();
    	IASTfunctionDefinition[] fcts2 = new IASTfunctionDefinition[fcts.length];
    	for(int j = 0; j < fcts.length; j++) {
    		IASTfunctionDefinition f = fcts[j];
    		IASTvariable[] vars = f.getVariables();
    		IASTvariable[] newVars = new IASTvariable[vars.length];
    		for (int i = 0; i < vars.length; i++) {
    			IASTvariable v = vars[i];
    			IASTvariable newV = factory.newVariable(v.getName() + "_" + cpt++);
    			data = data.extend(v, newV);
    		}
    		IASTexpression newBody = f.getBody().accept(this, data);
    		fcts2[j] = factory.newFunctionDefinition(f.getFunctionVariable(), newVars, newBody);
    	}
    	IASTexpression body = iast.getBody().accept(this, data);
		return factory.newProgram(fcts2, body);
		
    }

	@Override
	public IASTexpression visit(IASTinvocation iast, INormalizationEnvironment data) throws CompilationException {
		int n = iast.getArguments().length;
		IASTexpression[] exprs = iast.getArguments();
        IASTexpression[] newArg = new IASTexpression[n];
		for(int i = 0;i<n;i++) {
			newArg[i] = exprs[i].accept(this, data);
		}
		return factory.newInvocation(iast.getFunction().accept(this, data), newArg);
	
	}

	@Override
	public IASTvariable visit(IASTvariable iast, INormalizationEnvironment data) throws CompilationException {
		return data.renaming(iast); // Ajouter try/catch pour variables spéciales (par exemple, PI)
	}
	
	@Override
	public IASTexpression visit(IASTassignment iast, INormalizationEnvironment data) throws CompilationException {
		 IASTvariable variable = iast.getVariable();
	     IASTvariable newvariable = visit(variable, data);
	     IASTexpression expression = iast.getExpression();
	     IASTexpression newexpression = expression.accept(this, data);
	     return factory.newAssignment(newvariable, newexpression);
	    
	}
	
	@Override
	public IASTexpression visit(IASTblock iast, INormalizationEnvironment data) throws CompilationException {
		INormalizationEnvironment newData = data;
		IASTbinding[] b = iast.getBindings();
		for(int i = 0; i < b.length;i++) {
			IASTvariable v = b[i].getVariable();
			IASTvariable newV = factory.newVariable(v.getName() + "_" + cpt++);
			newData = newData.extend(v, newV);
			
		}
		return new ASTfactory().newBlock(iast.getBindings(), iast.getBody().accept(this, data));
	}

}
/*
Var globale : Set<String> recursive;
for(f : functiondef)
	set<string> seen = new ...
	stack s = new stack();
	s.push(f.name());
	while (!s.isEmpty())
		string g = s.pop();
		seen.add(g);
		for each function h called by g
			s.push(h)
			if (!seen.constains(h)
				if h=f then recursive.add(f);
					break;
		}

pour que : isrecursive(f){ return recursive.constains(f)}

*/	