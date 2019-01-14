package com.paracamplus.ilp4.ilp4tme10.ast;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import com.paracamplus.ilp1.compiler.interfaces.IASTCglobalVariable;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;

public class ASTexists implements IASTexists {

	public ASTexists(IASTvariable variable) {
		this.variable = variable;
		globVars = new ArrayList<>();
	}
	
    private final IASTvariable variable;
    private List<IASTCglobalVariable> globVars;
	
    public IASTvariable getVariable() {
		return variable;
	}

	@Override
	public <Result, Data, Anomaly extends Throwable> Result accept(
			com.paracamplus.ilp1.interfaces.IASTvisitor<Result, Data, Anomaly> visitor, Data data) throws Anomaly {
		return ((IASTvisitor <Result, Data, Anomaly>) visitor).visit(this, data);
	}

	@Override
	public boolean exists(ArrayList<String> data) {
		System.out.println("entre dans exists");
		System.out.println(data.size());
		 for(String v: data) {
	            if(v.equals(variable.getName())) return true;
	        }
		 return false;
	}

}
