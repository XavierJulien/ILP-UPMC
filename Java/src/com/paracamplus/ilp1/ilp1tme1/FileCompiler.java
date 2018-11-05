package com.paracamplus.ilp1.ilp1tme1;

import java.io.File;
import java.io.IOException;

import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.parser.ParseException;

public class FileCompiler extends com.paracamplus.ilp1.compiler.test.CompilerTest {

	public FileCompiler(File file) {
		super(file);
	}
	
	public static void main(String[] args) throws CompilationException, ParseException, IOException {
		FileCompiler f = new FileCompiler(new File("SamplesTME1/u01-2.ilpml"));
		f.processFile();
	}

}
