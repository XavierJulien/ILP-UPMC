/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp1.ilp1tme1.sequence;

import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp1.ilp1tme1.sequence.IASTsequence;

public class ASTfactory extends com.paracamplus.ilp1.ast.ASTfactory implements IASTfactory {

    @Override
	public IASTsequence newSequence(IASTexpression[] asts) {
        return new ASTsequence(asts);
    }
}
