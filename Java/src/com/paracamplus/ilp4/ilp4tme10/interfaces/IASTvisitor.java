/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.interfaces;

import com.paracamplus.ilp4.ilp4tme10.ast.IASTexists;

public interface IASTvisitor<Result, Data, Anomaly extends Throwable>
extends com.paracamplus.ilp4.interfaces.IASTvisitor<Result, Data, Anomaly>{

    Result visit(IASTexists iast, Data data) throws Anomaly;
    
}
