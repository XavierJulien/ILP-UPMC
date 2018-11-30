package com.paracamplus.ilp2.ilp2tme6.parser;

import com.paracamplus.ilp2.ilp2tme6.CopyTransform;
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

public class ILPMLParser
extends com.paracamplus.ilp2.parser.ilpml.ILPMLParser {
	
	public ILPMLParser(IASTfactory factory) throws ParseException {
		super(factory);
	}
	
	@Override
    public IASTprogram getProgram() throws ParseException {
		IASTprogram p = super.getProgram();
		try {
			System.out.println("passe dans la copy");
			return new CopyTransform<Void>((IASTfactory) factory).visit(p, null);
			
		} catch (CompilationException e) {
			System.out.println("passe dans p");
			return p;
		}
    }

}
