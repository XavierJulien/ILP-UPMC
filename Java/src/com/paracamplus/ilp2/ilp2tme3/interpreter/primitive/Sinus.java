/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;


import java.math.BigDecimal;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.UnaryPrimitive;

public class Sinus extends UnaryPrimitive {
    
    public Sinus() {
        super("sinus");
    }
        
    @Override
	public Object apply (Object value) throws EvaluationException {
    	if(!(value instanceof BigDecimal)) throw new EvaluationException("Sinus expected a double value");
        	BigDecimal b =  (BigDecimal)value;
        	return Math.sin(b.doubleValue());
    }
}
