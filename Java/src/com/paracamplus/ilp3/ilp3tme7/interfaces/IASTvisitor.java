/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp3.ilp3tme7.interfaces;

public interface IASTvisitor<Result, Data, Anomaly extends Throwable> extends
com.paracamplus.ilp3.interfaces.IASTvisitor<Result, Data, Anomaly>{
    Result visit(IASTcostart iast, Data data) throws Anomaly;
}
