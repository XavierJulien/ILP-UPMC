package com.paracamplus.ilp1.ilp1tme1.sequence;

import com.paracamplus.ilp1.interfaces.IASTexpression;

public interface IASTfactory extends com.paracamplus.ilp1.interfaces.IASTfactory {

	IASTexpression newSequence(IASTexpression[] asts);
}
