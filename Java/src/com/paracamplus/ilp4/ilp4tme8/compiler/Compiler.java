/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme8.compiler;

import com.paracamplus.ilp1.compiler.AssignDestination;
import com.paracamplus.ilp4.compiler.interfaces.IASTCclassDefinition;
import com.paracamplus.ilp4.compiler.interfaces.IASTCfieldRead;
import com.paracamplus.ilp4.compiler.interfaces.IASTCfieldWrite;
import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp4.compiler.interfaces.IASTCprogram;
import com.paracamplus.ilp4.ilp4tme8.compiler.interfaces.IASTCvisitor;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASThasProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTreadProperty;
import com.paracamplus.ilp4.ilp4tme8.interfaces.IASTwriteProperty;
import com.paracamplus.ilp1.compiler.interfaces.IGlobalVariableEnvironment;
import com.paracamplus.ilp1.compiler.interfaces.IOperatorEnvironment;
import com.paracamplus.ilp4.ilp4tme8.compiler.normalizer.INormalizationFactory;
import com.paracamplus.ilp4.ilp4tme8.compiler.normalizer.NormalizationFactory;
import com.paracamplus.ilp4.ilp4tme8.compiler.normalizer.Normalizer;
import com.paracamplus.ilp4.interfaces.IASTprogram;
import com.paracamplus.ilp1.interfaces.IASTvariable;
import com.paracamplus.ilp1.interfaces.Inamed;


public class Compiler extends com.paracamplus.ilp4.compiler.Compiler
implements IASTCvisitor<Void, Compiler.Context, CompilationException> {

	public Compiler(IOperatorEnvironment ioe, IGlobalVariableEnvironment igve) {
		super(ioe, igve);
	}

	public IASTCprogram normalize(IASTprogram program, 
			IASTCclassDefinition objectClass) 
					throws CompilationException {
		INormalizationFactory nf = new NormalizationFactory();
		Normalizer normalizer = new Normalizer(nf, objectClass);
		IASTCprogram newprogram = normalizer.transform(program);
		return newprogram;
	}

	@Override
	public Void visit(IASTCfieldRead iast, Context context)
			throws CompilationException {
		emit("{ \n");
		IASTvariable tmpInstance = context.newTemporaryVariable();
		emit("  ILP_Object " + tmpInstance.getMangledName() + "; \n");
		Context c = context.redirect(new AssignDestination(tmpInstance));
		iast.getTarget().accept(this, c);

		IASTCclassDefinition clazz = iast.getDefiningClass();
		emit("if ( ILP_IsA(");
		emit(tmpInstance.getMangledName());
		emit(", ");
		emit(clazz.getMangledName());
		emit(" ) ) {\n");
		emit(context.destination.compile());
		emit(tmpInstance.getMangledName());
		emit("->_content.asInstance.field[");
		emit(clazz.getFieldOffset(iast.getFieldName()));
		emit("];\n} else {\n");
		emit(context.destination.compile());
		emit(" ILP_UnknownFieldError(\"");
		emit(Inamed.computeMangledName(iast.getFieldName()));
		emit("\", ");
		emit(tmpInstance.getMangledName());
		emit(");\n}\n}\n");
		return null;
	}

	@Override
	public Void visit(IASTCfieldWrite iast, Context context)
			throws CompilationException {
		emit("{ \n");
		IASTvariable tmpInstance = context.newTemporaryVariable();
		emit("  ILP_Object " + tmpInstance.getMangledName() + "; \n");
		Context c = context.redirect(new AssignDestination(tmpInstance));

		IASTvariable tmpValue = context.newTemporaryVariable();
		emit("  ILP_Object " + tmpValue.getMangledName() + "; \n");
		Context cv = context.redirect(new AssignDestination(tmpValue));

		iast.getTarget().accept(this, c);
		iast.getValue().accept(this, cv);

		IASTCclassDefinition clazz = iast.getDefiningClass();
		emit("if ( ILP_IsA(");
		emit(tmpInstance.getMangledName());
		emit(", ");
		emit(clazz.getMangledName());
		emit(" ) ) {\n");
		emit(context.destination.compile());
		emit(tmpInstance.getMangledName());
		emit("->_content.asInstance.field[");
		emit(clazz.getFieldOffset(iast.getFieldName()));
		emit("] = ");
		emit(tmpValue.getMangledName());
		emit(";\n} else {\n");
		emit(context.destination.compile());
		emit(" ILP_UnknownFieldError(\"");
		emit(Inamed.computeMangledName(iast.getFieldName()));
		emit("\", ");
		emit(tmpInstance.getMangledName());
		emit(");\n}\n}\n");
		return null;
	}

	@Override
	public Void visit(IASThasProperty iast, Context data) throws CompilationException {
		emit("{ \n");
		IASTvariable objInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context c = data.redirect(new AssignDestination(objInstance));
		iast.getObj().accept(this, c);
		IASTvariable propertyInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context cv = data.redirect(new AssignDestination(propertyInstance));
		iast.getProperty().accept(this, cv);
		emit("return ILP_has_property(");
		emit(objInstance.getMangledName()+",");
		emit(propertyInstance.getMangledName()+");\n");
		emit("} \n");
		return null;
	}

	@Override
	public Void visit(IASTreadProperty iast, Context data) throws CompilationException {
		emit("{ \n");
		IASTvariable objInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context c = data.redirect(new AssignDestination(objInstance));
		iast.getObj().accept(this, c);
		IASTvariable propertyInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context cv = data.redirect(new AssignDestination(propertyInstance));
		iast.getProperty().accept(this, cv);
		emit("return ILP_read_property(");
		emit(objInstance.getMangledName()+",");
		emit(propertyInstance.getMangledName()+");\n");
		emit("} \n");
		return null;
	}

	@Override
	public Void visit(IASTwriteProperty iast, Context data) throws CompilationException {
		emit("{ \n");
		IASTvariable objInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context c = data.redirect(new AssignDestination(objInstance));
		iast.getObj().accept(this, c);
		IASTvariable propertyInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context cv = data.redirect(new AssignDestination(propertyInstance));
		iast.getProperty().accept(this, cv);
		IASTvariable valueInstance = data.newTemporaryVariable();
		emit("  ILP_Object " + objInstance.getMangledName() + "; \n");
		Context cvv = data.redirect(new AssignDestination(valueInstance));
		iast.getProperty().accept(this, cvv);
		emit("return ILP_has_property(");
		emit(objInstance.getMangledName()+",");
		emit(propertyInstance.getMangledName()+",");
		emit(valueInstance.getMangledName()+");\n");
		emit("} \n");
		return null;
	}
}
