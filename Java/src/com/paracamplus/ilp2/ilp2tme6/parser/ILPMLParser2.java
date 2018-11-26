package com.paracamplus.ilp2.ilp2tme6.parser;

import com.paracamplus.ilp2.ilp2tme6.RenameTransform;
import com.paracamplus.ilp2.interfaces.IASTfactory;
import com.paracamplus.ilp2.interfaces.IASTprogram;
import com.paracamplus.ilp1.compiler.CompilationException;
/*
import com.paracamplus.ilp2.parser.ilpml.ILPMLListener;

import antlr4.ILPMLgrammar2Lexer;
import antlr4.ILPMLgrammar2Parser;

import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import org.antlr.v4.runtime.tree.ParseTreeWalker;
*/
import com.paracamplus.ilp1.parser.ParseException;

public class ILPMLParser2
extends com.paracamplus.ilp2.parser.ilpml.ILPMLParser {
	
	public ILPMLParser2(IASTfactory factory) throws ParseException {
		super(factory);
	}
	
	@Override
    public IASTprogram getProgram() throws ParseException {
		IASTprogram p = super.getProgram();
		try {
			return new RenameTransform((IASTfactory) factory).visit(p, null);
		} catch (CompilationException e) {
			return p;
		}
    }

}
