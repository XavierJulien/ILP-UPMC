/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme3.interpreter;


import java.io.Writer;

import com.paracamplus.ilp1.interpreter.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp2.ilp2tme3.interpreter.primitive.Sinus;

public class GlobalVariableStuff extends com.paracamplus.ilp1.interpreter.GlobalVariableStuff{
    public static void fillGlobalVariables (IGlobalVariableEnvironment env, Writer out) {
        env.addGlobalVariableValue(new Sinus());
    }
}
