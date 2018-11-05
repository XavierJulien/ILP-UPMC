package com.paracamplus.ilp1.ilp1tme1;

import java.io.File;
import java.io.IOException;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.parser.ParseException;

public class FileInterpreter extends com.paracamplus.ilp1.interpreter.test.InterpreterTest{
	public FileInterpreter(File file) {
		super(file);
	}
	
	public static void main(String[] args) throws ParseException, IOException, EvaluationException {
		FileInterpreter f = new FileInterpreter(new File("SamplesTME1/u01-3.ilpml"));
		f.processFile();
		
	}
}
