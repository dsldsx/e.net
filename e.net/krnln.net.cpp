#include "stdafx.h"
#include "common.h"
#include "common.net.h"
#include "e.net.h"
#include "krnln.net.h"

MethodDefinition^ CreateReturn(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("返回", module->TypeSystem->Void, ToList(CreateParameter("返回到调用方的值", module->TypeSystem->Void)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateMod(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("求余数", module->TypeSystem->Int32, ToList(CreateParameter("被除数", module->TypeSystem->Double), CreateParameter("除数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Rem);
	return method;
}

MethodDefinition^ CreateAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->String, ToList(CreateParameter("被加文本", module->TypeSystem->Object), CreateParameter("加文本", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(String, "Concat", typeof(Object), typeof(Object))));
	return method;
}

MethodDefinition^ CreateEvenAdd(ModuleDefinition^ module)
{
	TypeReference^ objarr = gcnew ArrayType(module->TypeSystem->Object);
	ParameterDefinition^ params = CreateParameter("加文本", objarr);
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->String, ToList(CreateParameter("被加文本", module->TypeSystem->Object), params), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	method->Body->Variables->Add(gcnew VariableDefinition(objarr));
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Object);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Stelem_Ref);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int))));
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(String, "Concat", typeof(array<Object^>))));
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateIntAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Int32, ToList(CreateParameter("被加数", module->TypeSystem->Int32), CreateParameter("加数", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ CreateEvenIntAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("加数", gcnew ArrayType(module->TypeSystem->Int32));
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Int32, ToList(CreateParameter("被加数", module->TypeSystem->Int32), params), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ldloc_0);
	Instruction^ loop = ILProcessor->Create(OpCodes::Ldloc_1);
	ILProcessor->Append(loop);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldelem_I4);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Br_S, loop);
	ILProcessor->Append(ret);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateLongAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Int64, ToList(CreateParameter("被加数", module->TypeSystem->Int64), CreateParameter("加数", module->TypeSystem->Int64)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ CreateEvenLongAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("加数", gcnew ArrayType(module->TypeSystem->Int64));
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Int64, ToList(CreateParameter("被加数", module->TypeSystem->Int64), params), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int64));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ldloc_0);
	Instruction^ loop = ILProcessor->Create(OpCodes::Ldloc_1);
	ILProcessor->Append(loop);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldelem_I8);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Br_S, loop);
	ILProcessor->Append(ret);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateDoubleAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Double, ToList(CreateParameter("被加数", module->TypeSystem->Double), CreateParameter("加数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ CreateEvenDoubleAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("加数", gcnew ArrayType(module->TypeSystem->Double));
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("相加", module->TypeSystem->Double, ToList(CreateParameter("被加数", module->TypeSystem->Double), params), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Double));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ldloc_0);
	Instruction^ loop = ILProcessor->Create(OpCodes::Ldloc_1);
	ILProcessor->Append(loop);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldelem_R8);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Br_S, loop);
	ILProcessor->Append(ret);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateEvenBinAdd(ModuleDefinition^ module)
{
	TypeReference^ Bin = gcnew ArrayType(module->TypeSystem->Byte);
	MethodReference^ Copy = module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int)));
	ParameterDefinition^ params = CreateParameter("加字节集", gcnew ArrayType(Bin));
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("相加", Bin, ToList(CreateParameter("被加字节集", Bin), params), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	method->Body->Variables->Add(gcnew VariableDefinition(Bin));
	method->Body->Variables->Add(gcnew VariableDefinition(Bin));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_2);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ldloc_0);
	Instruction^ loop = ILProcessor->Create(OpCodes::Ldloc_2);
	ILProcessor->Append(loop);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_2);
	AddILCode(ILProcessor, OpCodes::Ldelem_Ref);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_2);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_2);
	AddILCode(ILProcessor, OpCodes::Br_S, loop);
	ILProcessor->Append(ret);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Byte);
	AddILCode(ILProcessor, OpCodes::Stloc_3);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_3);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Call, Copy);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_2);
	ret = ILProcessor->Create(OpCodes::Ldloc_3);
	loop = ILProcessor->Create(OpCodes::Ldloc_2);
	ILProcessor->Append(loop);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_2);
	AddILCode(ILProcessor, OpCodes::Ldelem_Ref);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Stloc, 4);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_3);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc, 4);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Call, Copy);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc, 4);
	AddILCode(ILProcessor, OpCodes::Ldlen);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_2);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_2);
	AddILCode(ILProcessor, OpCodes::Br_S, loop);
	ILProcessor->Append(ret);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateSub(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相减", module->TypeSystem->Double, ToList(CreateParameter("被减数", module->TypeSystem->Double), CreateParameter("减数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Sub);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ CreateIntSub(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相减", module->TypeSystem->Int32, ToList(CreateParameter("被减数", module->TypeSystem->Int32), CreateParameter("减数", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Sub);
	return method;
}

MethodDefinition^ CreateNeg(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("负", module->TypeSystem->Double, ToList(CreateParameter("数值", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Neg);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ CreateMul(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相乘", module->TypeSystem->Double, ToList(CreateParameter("被乘数", module->TypeSystem->Double), CreateParameter("乘数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Mul);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ CreateDiv(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("相除", module->TypeSystem->Double, ToList(CreateParameter("被除数", module->TypeSystem->Double), CreateParameter("除数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Div);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ CreateIDiv(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("整除", module->TypeSystem->Int32, ToList(CreateParameter("被除数", module->TypeSystem->Double), CreateParameter("除数", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Div);
	return method;
}

MethodDefinition^ CreateEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("等于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Object), CreateParameter("比较值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Object, "Equals", typeof(Object), typeof(Object))));
	return method;
}

MethodDefinition^ CreateNotEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("不等于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Object), CreateParameter("比较值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Object, "Equals", typeof(Object), typeof(Object))));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ CreateLess(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("小于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Double), CreateParameter("比较值", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Clt);
	return method;
}

MethodDefinition^ CreateMore(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("大于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Double), CreateParameter("比较值", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Cgt);
	return method;
}

MethodDefinition^ CreateLessOrEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("小于或等于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Double), CreateParameter("比较值", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Cgt);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ CreateMoreOrEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("大于或等于", module->TypeSystem->Boolean, ToList(CreateParameter("被比较值", module->TypeSystem->Double), CreateParameter("比较值", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Clt);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ CreateAnd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("并且", module->TypeSystem->Boolean, ToList(CreateParameter("逻辑值一", module->TypeSystem->Boolean), CreateParameter("逻辑值二", module->TypeSystem->Boolean)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	Instruction^ onefalse = ILProcessor->Create(OpCodes::Pop);
	Instruction^ nop = ILProcessor->Create(OpCodes::Nop);
	AddILCode(ILProcessor, OpCodes::Brfalse, onefalse);
	AddILCode(ILProcessor, OpCodes::Br, nop);
	ILProcessor->Append(onefalse);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	ILProcessor->Append(nop);
	return method;
}

MethodDefinition^ CreateOr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("或者", module->TypeSystem->Boolean, ToList(CreateParameter("逻辑值一", module->TypeSystem->Boolean), CreateParameter("逻辑值二", module->TypeSystem->Boolean)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	Instruction^ onetrue = ILProcessor->Create(OpCodes::Pop);
	Instruction^ nop = ILProcessor->Create(OpCodes::Nop);
	AddILCode(ILProcessor, OpCodes::Brtrue, onetrue);
	AddILCode(ILProcessor, OpCodes::Br, nop);
	ILProcessor->Append(onetrue);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	ILProcessor->Append(nop);
	return method;
}

MethodDefinition^ CreateNot(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("取反", module->TypeSystem->Boolean, ToList(CreateParameter("被反转的逻辑值", module->TypeSystem->Boolean)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ CreateBnot(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("位取反", module->TypeSystem->Int32, ToList(CreateParameter("欲取反的数值", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Not);
	return method;
}

MethodDefinition^ CreateBand(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("位与", module->TypeSystem->Int32, ToList(CreateParameter("位运算数值一", module->TypeSystem->Int32), CreateParameter("位运算数值二", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::And);
	return method;
}

MethodDefinition^ CreateBor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("位或", module->TypeSystem->Int32, ToList(CreateParameter("位运算数值一", module->TypeSystem->Int32), CreateParameter("位运算数值二", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Or);
	return method;
}

MethodDefinition^ CreateBxor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("位异或", module->TypeSystem->Int32, ToList(CreateParameter("位运算数值一", module->TypeSystem->Int32), CreateParameter("位运算数值二", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Xor);
	return method;
}

MethodDefinition^ CreateSet(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("赋值", module->TypeSystem->Void, ToList(CreateParameter("被赋值的变量或变量数组", gcnew ByReferenceType(module->TypeSystem->Object), ParameterAttributes::Out), CreateParameter("用作赋于的值或资源", module->TypeSystem->Object)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateToDouble(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到数值", module->TypeSystem->Double, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Double);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Double);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(double, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateToStr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到文本", module->TypeSystem->String, ToList(CreateParameter("待转换的数据", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	return method;
}

MethodDefinition^ CreateToByte(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到字节", module->TypeSystem->Byte, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Byte);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Byte);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(byte, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateToShort(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到短整数", module->TypeSystem->Int16, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Int16);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Int16);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(short, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateToInt(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到整数", module->TypeSystem->Int32, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Int32);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Int32);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(int, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateToLong(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到长整数", module->TypeSystem->Int64, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Int64);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Int64);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Int64, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateToFloat(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("到小数", module->TypeSystem->Single, ToList(CreateParameter("待转换的文本或数值", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldtoken, module->TypeSystem->Single);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ChangeType", typeof(Object), typeof(Type))));
	AddILCode(ILProcessor, OpCodes::Dup);
	Instruction^ brfalse = ILProcessor->Create(OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, brfalse);
	Instruction^ ret = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Unbox_Any, module->TypeSystem->Single);
	AddILCode(ILProcessor, OpCodes::Br_S, ret);
	ILProcessor->Append(brfalse);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(float, "Parse", typeof(String))));
	ILProcessor->Append(ret);
	return method;
}

MethodDefinition^ CreateShl(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("左移", module->TypeSystem->Int32, ToList(CreateParameter("欲移动的整数", module->TypeSystem->Int32), CreateParameter("欲移动的位数", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Shl);
	return method;
}

MethodDefinition^ CreateShr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("右移", module->TypeSystem->Int32, ToList(CreateParameter("欲移动的整数", module->TypeSystem->Int32), CreateParameter("欲移动的位数", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Shr);
	return method;
}

MethodDefinition^ CreateIfe(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("如果", module->TypeSystem->Void, ToList(CreateParameter("条件", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateIf(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("如果真", module->TypeSystem->Void, ToList(CreateParameter("条件", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateSwitch(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("判断", module->TypeSystem->Void, ToList(CreateParameter("条件", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateWhile(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("判断循环首", module->TypeSystem->Void, ToList(CreateParameter("条件", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateWend(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("判断循环尾", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ CreateDoWhile(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("循环判断首", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ CreateLoop(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("循环判断尾", module->TypeSystem->Void, ToList(CreateParameter("条件", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateCounter(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("计次循环首", module->TypeSystem->Void, ToList(CreateParameter("循环次数", module->TypeSystem->Int32), CreateParameter("已循环次数记录变量", gcnew ByReferenceType(module->TypeSystem->Int32), ParameterAttributes::Out)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateCounterLoop(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("计次循环尾", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ CreateFor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("变量循环首", module->TypeSystem->Void, ToList(CreateParameter("变量起始值", module->TypeSystem->Int32), CreateParameter("变量目标值", module->TypeSystem->Int32), CreateParameter("变量递增值", module->TypeSystem->Int32), CreateParameter("循环变量", gcnew ByReferenceType(module->TypeSystem->Int32), ParameterAttributes::Out | ParameterAttributes::Optional)), STATICMETHOD);
	return method;
}

MethodDefinition^ CreateNext(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("变量循环尾", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ CreateEnd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("结束", module->TypeSystem->Void, nullptr, STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Environment, "Exit", typeof(int))));
	return method;
}

MethodDefinition^ CreateReDim(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("数组类型", module->ImportReference(typeof(RuntimeTypeHandle))), CreateParameter("欲重定义的数组变量", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("是否保留以前的内容", module->TypeSystem->Boolean), CreateParameter("数组对应维的上限值", gcnew ArrayType(module->TypeSystem->Int32)));
	MethodReference^ ctor = module->ImportReference(typeof(ParamArrayAttribute)->GetConstructor(Type::EmptyTypes));
	params[3]->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("重定义数组", module->TypeSystem->Void, params, STATICMETHOD);
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Object));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	MethodReference^ get_Length = module->ImportReference(GetInstanceMethod(Array, "get_Length"));
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_2);
	Instruction^ ins = ILProcessor->Create(OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Ldnull);
	AddILCode(ILProcessor, OpCodes::Ceq);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Starg_S, params[2]);
	ILProcessor->Append(ins);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod_D(Type, "GetTypeFromHandle")));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Object);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	ins = ILProcessor->Create(OpCodes::Ldarg_3);
	Instruction^ ins2 = ILProcessor->Create(OpCodes::Box, module->TypeSystem->Int32);
	ILProcessor->Append(ins);
	AddILCode(ILProcessor, OpCodes::Callvirt, get_Length);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ble_S, ins2);
	AddILCode(ILProcessor, OpCodes::Ldarg_3);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldelem_I4);
	AddILCode(ILProcessor, OpCodes::Mul);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Br_S, ins);
	ILProcessor->Append(ins2);
	AddILCode(ILProcessor, OpCodes::Stelem_Ref);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Activator, "CreateInstance", typeof(Type), typeof(array<Object^>))));
	AddILCode(ILProcessor, OpCodes::Ldarg_2);
	ins = ILProcessor->Create(OpCodes::Stind_Ref);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins);
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Callvirt, get_Length);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, get_Length);
	ins2 = ILProcessor->Create(OpCodes::Call, module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int))));
	AddILCode(ILProcessor, OpCodes::Blt_S, ins2);
	AddILCode(ILProcessor, OpCodes::Pop);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Callvirt, get_Length);
	ILProcessor->Append(ins2);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	ILProcessor->Append(ins);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateGetAryElementCount(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("取数组成员数", module->TypeSystem->Int32, ToList(CreateParameter("欲检查的数组变量", module->ImportReference(typeof(Array)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldnull);
	AddILCode(ILProcessor, OpCodes::Ceq);
	Instruction^ ins = ILProcessor->Create(OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_M1);
	AddILCode(ILProcessor, OpCodes::Ret);
	ILProcessor->Append(ins);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "get_Length")));
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateUBound(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("取数组下标", module->TypeSystem->Int32, ToList(CreateParameter("欲取某维最大下标的数组变量", module->ImportReference(typeof(Array))), CreateParameter("欲取其最大下标的维", module->TypeSystem->Int32, ParameterAttributes::Optional)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldnull);
	AddILCode(ILProcessor, OpCodes::Ceq);
	Instruction^ ins = ILProcessor->Create(OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ret);
	ILProcessor->Append(ins);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "get_Length")));
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateCopyAry(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("复制数组", module->TypeSystem->Void, ToList(CreateParameter("复制到的数组变量", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("待复制的数组数据", module->ImportReference(typeof(Array)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldnull);
	Instruction^ ins = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Beq_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "Clone")));
	AddILCode(ILProcessor, OpCodes::Stind_Ref);
	ILProcessor->Append(ins);
	return method;
}

MethodDefinition^ CreateAddElement(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("欲加入成员的数组变量", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("欲加入的成员数据", module->TypeSystem->Object));
	MethodDefinition^ method = CreateMethod("加入成员", module->TypeSystem->Void, params, STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Object));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetInstanceMethod(Object, "GetType")));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Object);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "get_Length")));
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Box, module->TypeSystem->Int32);
	AddILCode(ILProcessor, OpCodes::Stelem_Ref);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Activator, "CreateInstance", typeof(Type), typeof(array<Object^>))));
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int))));
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "SetValue", typeof(Object), typeof(int))));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Stind_Ref);
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ CreateInsElement(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("欲插入成员的数组变量", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("欲插入的位置", module->TypeSystem->Int32), CreateParameter("欲插入的成员数据", module->TypeSystem->Object));
	MethodDefinition^ method = CreateMethod("插入成员", module->TypeSystem->Void, params, STATICMETHOD);
	MethodReference^ Copy = module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int)));
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	method->Body->InitLocals = true;
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Object));
	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	Instruction^ ins = ILProcessor->Create(OpCodes::Ret);
	AddILCode(ILProcessor, OpCodes::Blt_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "get_Length")));
	AddILCode(ILProcessor, OpCodes::Stloc_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Blt_S, ins);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Sub);
	AddILCode(ILProcessor, OpCodes::Starg_S, params[1]);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetInstanceMethod(Object, "GetType")));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Object);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Box, module->TypeSystem->Int32);
	AddILCode(ILProcessor, OpCodes::Stelem_Ref);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Activator, "CreateInstance", typeof(Type), typeof(array<Object^>))));
	AddILCode(ILProcessor, OpCodes::Stloc_0);
	Instruction^ ins2 = ILProcessor->Create(OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Brfalse_S, ins2);
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Call, Copy);
	ILProcessor->Append(ins2);
	AddILCode(ILProcessor, OpCodes::Ldind_Ref);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	AddILCode(ILProcessor, OpCodes::Ldloc_1);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Sub);
	AddILCode(ILProcessor, OpCodes::Call, Copy);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Ldarg_2);
	AddILCode(ILProcessor, OpCodes::Ldarg_1);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Array, "SetValue", typeof(Object), typeof(int))));
	AddILCode(ILProcessor, OpCodes::Ldarg_0);
	AddILCode(ILProcessor, OpCodes::Ldloc_0);
	AddILCode(ILProcessor, OpCodes::Stind_Ref);
	ILProcessor->Append(ins);
	return method;
}

PluginType Krnln::Type::get()
{
	return PluginType::Mono;
}

IList<MonoInfo^>^ Krnln::GetMethods(ModuleDefinition^ module)
{
	IList<MonoInfo^>^ list = gcnew List<MonoInfo^>();
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::返回, CreateReturn(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::求余数, CreateMod(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::相加, CreateIntAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, NOT, CreateEvenIntAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, NOT, CreateLongAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, NOT, CreateEvenLongAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, NOT, CreateDoubleAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, NOT, CreateEvenDoubleAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, NOT, CreateEvenBinAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, NOT, CreateAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, NOT, CreateEvenAdd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::相减, CreateSub(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, NOT, CreateIntSub(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::负, CreateNeg(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::相乘, CreateMul(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::相除, CreateDiv(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::整除, CreateIDiv(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::等于, CreateEqual(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::不等于, CreateNotEqual(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::小于, CreateLess(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::大于, CreateMore(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::小于或等于, CreateLessOrEqual(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::大于或等于, CreateMoreOrEqual(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::并且, CreateAnd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::或者, CreateOr(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::取反, CreateNot(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::位取反, CreateBnot(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::位与, CreateBand(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::位或, CreateBor(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::位异或, CreateBxor(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::赋值, CreateSet(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到数值, CreateToDouble(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::到文本, CreateToStr(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到字节, CreateToByte(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到短整数, CreateToShort(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到整数, CreateToInt(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到长整数, CreateToLong(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::到小数, CreateToFloat(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::左移, CreateShl(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::右移, CreateShr(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::如果, CreateIfe(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::如果真, CreateIf(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::判断, CreateSwitch(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::判断循环首, CreateWhile(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::判断循环尾, CreateWend(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::循环判断首, CreateDoWhile(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::循环判断尾, CreateLoop(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::计次循环首, CreateCounter(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::计次循环尾, CreateCounterLoop(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::变量循环首, CreateFor(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::变量循环尾, CreateNext(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Embed, krnln_method::结束, CreateEnd(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::重定义数组, CreateReDim(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::取数组成员数, CreateGetAryElementCount(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::取数组下标, CreateUBound(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::复制数组, CreateCopyAry(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::加入成员, CreateAddElement(module)));
	list->Add(gcnew MonoInfo(EMethodMode::Call, krnln_method::插入成员, CreateInsElement(module)));
	return list;
}

int Krnln::删除成员(Array^% 欲删除成员的数组变量, int 欲删除的位置, int 欲删除的成员数目)
{
	int len = 欲删除成员的数组变量->Length;
	if (欲删除的位置 < 1 || 欲删除的位置> len + 1) return 0;
	欲删除的位置--;
	if (欲删除的成员数目 == NULL) 欲删除的成员数目 = 1;
	System::Type^ type = 欲删除成员的数组变量->GetType();
	len -= 欲删除的成员数目 + 欲删除的位置;
	if (len <= 0)
	{
		欲删除的成员数目 += len;
		if (欲删除的位置 == 0)
		{
			欲删除成员的数组变量 = (Array^)Activator::CreateInstance(type);
			return 欲删除的成员数目;
		}
	}
	Array^ arr = (Array^)Activator::CreateInstance(type, (Object^)(欲删除成员的数组变量->Length - 欲删除的成员数目));
	if (欲删除的位置 > 0) Array::Copy(欲删除成员的数组变量, 0, arr, 0, 欲删除的位置);
	if (len > 0) Array::Copy(欲删除成员的数组变量, 欲删除的位置 + 欲删除的成员数目, arr, 欲删除的位置, len);
	欲删除成员的数组变量 = arr;
	return 欲删除的成员数目;
}