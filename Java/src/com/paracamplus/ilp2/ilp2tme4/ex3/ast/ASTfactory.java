package com.paracamplus.ilp2.ilp2tme4.ex3.ast;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTfactory;
import com.paracamplus.ilp2.ilp2tme4.ex3.interfaces.IASTunless;

public class ASTfactory extends com.paracamplus.ilp2.ast.ASTfactory implements IASTfactory {
	@Override
	public IASTunless newUnless(IASTexpression condition, IASTexpression body) {
      return new ASTunless(condition, body);
	}
}