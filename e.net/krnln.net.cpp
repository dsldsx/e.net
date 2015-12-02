#include "stdafx.h"
#include "common.h"
#include "common.net.h"
#include "krnln.net.h"

using namespace System::Text;

extern MethodDefinition^ CreateMethod(String^ name, TypeReference^ returntype, IList<ParameterDefinition^>^ params = nullptr, MethodAttributes attr = MethodAttributes::HideBySig);
extern ParameterDefinition^ CreateParameter(String^ name, TypeReference^ type, ParameterAttributes attr = ParameterAttributes::None);

MethodDefinition^ Krnln::CreateReturn(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Void, ToList(CreateParameter("���ص����÷���ֵ", module->TypeSystem->Void)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ret);
	return method;
}

MethodDefinition^ Krnln::CreateMod(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Int32, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Rem);
	return method;
}

MethodDefinition^ Krnln::CreateAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->String, ToList(CreateParameter("�����ı�", module->TypeSystem->Object), CreateParameter("���ı�", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(String, "Concat", typeof(Object), typeof(Object))));
	return method;
}

MethodDefinition^ Krnln::CreateEvenAdd(ModuleDefinition^ module)
{
	TypeReference^ objarr = gcnew ArrayType(module->TypeSystem->Object);
	ParameterDefinition^ params = CreateParameter("���ı�", objarr);
	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->String, ToList(CreateParameter("�����ı�", module->TypeSystem->Object), params), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateIntAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Int32, ToList(CreateParameter("������", module->TypeSystem->Int32), CreateParameter("����", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ Krnln::CreateEvenIntAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("����", gcnew ArrayType(module->TypeSystem->Int32));
	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Int32, ToList(CreateParameter("������", module->TypeSystem->Int32), params), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateLongAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Int64, ToList(CreateParameter("������", module->TypeSystem->Int64), CreateParameter("����", module->TypeSystem->Int64)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ Krnln::CreateEvenLongAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("����", gcnew ArrayType(module->TypeSystem->Int64));
	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Int64, ToList(CreateParameter("������", module->TypeSystem->Int64), params), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateDoubleAdd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Double, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ Krnln::CreateEvenDoubleAdd(ModuleDefinition^ module)
{
	ParameterDefinition^ params = CreateParameter("����", gcnew ArrayType(module->TypeSystem->Double));
	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Double, ToList(CreateParameter("������", module->TypeSystem->Double), params), STATICMETHOD);
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

//MethodDefinition^ Krnln::CreateEvenBinAdd(ModuleDefinition^ module)
//{
//	TypeReference^ Bin = gcnew ArrayType(module->TypeSystem->Byte);
//	MethodReference^ Copy = module->ImportReference(GetStaticMethod(Array, "Copy", typeof(Array), typeof(int), typeof(Array), typeof(int), typeof(int)));
//	ParameterDefinition^ params = CreateParameter("���ֽڼ�", gcnew ArrayType(Bin));
//	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
//	params->CustomAttributes->Add(gcnew CustomAttribute(ctor));
//	MethodDefinition^ method = CreateMethod("���", Bin, ToList(CreateParameter("�����ֽڼ�", Bin), params), STATICMETHOD);
//	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
//	method->Body->InitLocals = true;
//	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
//	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
//	method->Body->Variables->Add(gcnew VariableDefinition(module->TypeSystem->Int32));
//	method->Body->Variables->Add(gcnew VariableDefinition(Bin));
//	method->Body->Variables->Add(gcnew VariableDefinition(Bin));
//	AddILCode(ILProcessor, OpCodes::Ldarg_0);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Stloc_0);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Stloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Stloc_2);
//	Instruction^ ret = ILProcessor->Create(OpCodes::Ldloc_0);
//	Instruction^ loop = ILProcessor->Create(OpCodes::Ldloc_2);
//	ILProcessor->Append(loop);
//	AddILCode(ILProcessor, OpCodes::Ldarg_1);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
//	AddILCode(ILProcessor, OpCodes::Ldloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldarg_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc_2);
//	AddILCode(ILProcessor, OpCodes::Ldelem_Ref);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Add);
//	AddILCode(ILProcessor, OpCodes::Stloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc_2);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
//	AddILCode(ILProcessor, OpCodes::Add);
//	AddILCode(ILProcessor, OpCodes::Stloc_2);
//	AddILCode(ILProcessor, OpCodes::Br_S, loop);
//	ILProcessor->Append(ret);
//	AddILCode(ILProcessor, OpCodes::Ldloc_1);
//	AddILCode(ILProcessor, OpCodes::Add);
//	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Byte);
//	AddILCode(ILProcessor, OpCodes::Stloc_3);
//	AddILCode(ILProcessor, OpCodes::Ldarg_0);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Ldloc_3);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Ldloc_0);
//	AddILCode(ILProcessor, OpCodes::Call, Copy);
//	AddILCode(ILProcessor, OpCodes::Ldloc_0);
//	AddILCode(ILProcessor, OpCodes::Stloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Stloc_2);
//	ret = ILProcessor->Create(OpCodes::Ldloc_3);
//	loop = ILProcessor->Create(OpCodes::Ldloc_2);
//	ILProcessor->Append(loop);
//	AddILCode(ILProcessor, OpCodes::Ldarg_1);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Bge_S, ret);
//	AddILCode(ILProcessor, OpCodes::Ldarg_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc_2);
//	AddILCode(ILProcessor, OpCodes::Ldelem_Ref);
//	AddILCode(ILProcessor, OpCodes::Dup);
//	AddILCode(ILProcessor, OpCodes::Stloc, 4);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
//	AddILCode(ILProcessor, OpCodes::Ldloc_3);
//	AddILCode(ILProcessor, OpCodes::Ldloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc, 4);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Call, Copy);
//	AddILCode(ILProcessor, OpCodes::Ldloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc, 4);
//	AddILCode(ILProcessor, OpCodes::Ldlen);
//	AddILCode(ILProcessor, OpCodes::Add);
//	AddILCode(ILProcessor, OpCodes::Stloc_1);
//	AddILCode(ILProcessor, OpCodes::Ldloc_2);
//	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
//	AddILCode(ILProcessor, OpCodes::Add);
//	AddILCode(ILProcessor, OpCodes::Stloc_2);
//	AddILCode(ILProcessor, OpCodes::Br_S, loop);
//	ILProcessor->Append(ret);
//	AddILCode(ILProcessor, OpCodes::Ret);
//	return method;
//}

MethodDefinition^ Krnln::CreateSub(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Double, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Sub);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ Krnln::CreateIntSub(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Int32, ToList(CreateParameter("������", module->TypeSystem->Int32), CreateParameter("����", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Sub);
	return method;
}

MethodDefinition^ Krnln::CreateNeg(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��", module->TypeSystem->Double, ToList(CreateParameter("��ֵ", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Neg);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ Krnln::CreateMul(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Double, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Mul);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ Krnln::CreateDiv(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Double, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Div);
	AddILCode(ILProcessor, OpCodes::Conv_R8);
	return method;
}

MethodDefinition^ Krnln::CreateIDiv(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Int32, ToList(CreateParameter("������", module->TypeSystem->Double), CreateParameter("����", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Div);
	return method;
}

MethodDefinition^ Krnln::CreateEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Object), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Object, "Equals", typeof(Object), typeof(Object))));
	return method;
}

MethodDefinition^ Krnln::CreateEqualNull1(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Object), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Void)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateEqualNull2(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Void), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateNotEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Object), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Object, "Equals", typeof(Object), typeof(Object))));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateNotEqualNull1(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Object), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Void)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ceq);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateNotEqualNull2(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Void), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ceq);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateLess(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("С��", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Double), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Clt);
	return method;
}

MethodDefinition^ Krnln::CreateMore(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Double), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Cgt);
	return method;
}

MethodDefinition^ Krnln::CreateLessOrEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("С�ڻ����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Double), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Cgt);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateMoreOrEqual(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���ڻ����", module->TypeSystem->Boolean, ToList(CreateParameter("���Ƚ�ֵ", module->TypeSystem->Double), CreateParameter("�Ƚ�ֵ", module->TypeSystem->Double)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Clt);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateAnd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("�߼�ֵһ", module->TypeSystem->Boolean), CreateParameter("�߼�ֵ��", module->TypeSystem->Boolean)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateOr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Boolean, ToList(CreateParameter("�߼�ֵһ", module->TypeSystem->Boolean), CreateParameter("�߼�ֵ��", module->TypeSystem->Boolean)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateNot(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ��", module->TypeSystem->Boolean, ToList(CreateParameter("����ת���߼�ֵ", module->TypeSystem->Boolean)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	return method;
}

MethodDefinition^ Krnln::CreateBnot(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("λȡ��", module->TypeSystem->Int32, ToList(CreateParameter("��ȡ������ֵ", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Not);
	return method;
}

MethodDefinition^ Krnln::CreateBand(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("λ��", module->TypeSystem->Int32, ToList(CreateParameter("λ������ֵһ", module->TypeSystem->Int32), CreateParameter("λ������ֵ��", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::And);
	return method;
}

MethodDefinition^ Krnln::CreateBor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("λ��", module->TypeSystem->Int32, ToList(CreateParameter("λ������ֵһ", module->TypeSystem->Int32), CreateParameter("λ������ֵ��", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Or);
	return method;
}

MethodDefinition^ Krnln::CreateBxor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("λ���", module->TypeSystem->Int32, ToList(CreateParameter("λ������ֵһ", module->TypeSystem->Int32), CreateParameter("λ������ֵ��", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Xor);
	return method;
}

MethodDefinition^ Krnln::CreateSet(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��ֵ", module->TypeSystem->Void, ToList(CreateParameter("����ֵ�ı������������", gcnew ByReferenceType(module->TypeSystem->Object), ParameterAttributes::Out), CreateParameter("�������ڵ�ֵ����Դ", module->TypeSystem->Object)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateToDouble(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����ֵ", module->TypeSystem->Double, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateToStr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���ı�", module->TypeSystem->String, ToList(CreateParameter("��ת��������", module->TypeSystem->Object)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Object, "ToString")));
	return method;
}

MethodDefinition^ Krnln::CreateToByte(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���ֽ�", module->TypeSystem->Byte, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateToShort(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��������", module->TypeSystem->Int16, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateToInt(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Int32, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateToLong(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��������", module->TypeSystem->Int64, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateToFloat(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��С��", module->TypeSystem->Single, ToList(CreateParameter("��ת�����ı�����ֵ", module->TypeSystem->Object)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateShl(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Int32, ToList(CreateParameter("���ƶ�������", module->TypeSystem->Int32), CreateParameter("���ƶ���λ��", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Shl);
	return method;
}

MethodDefinition^ Krnln::CreateShr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Int32, ToList(CreateParameter("���ƶ�������", module->TypeSystem->Int32), CreateParameter("���ƶ���λ��", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Shr);
	return method;
}

MethodDefinition^ Krnln::CreateIfe(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("���", module->TypeSystem->Void, ToList(CreateParameter("����", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateIf(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�����", module->TypeSystem->Void, ToList(CreateParameter("����", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateSwitch(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ж�", module->TypeSystem->Void, ToList(CreateParameter("����", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateWhile(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ж�ѭ����", module->TypeSystem->Void, ToList(CreateParameter("����", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateWend(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ж�ѭ��β", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateDoWhile(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ѭ���ж���", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateLoop(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ѭ���ж�β", module->TypeSystem->Void, ToList(CreateParameter("����", module->TypeSystem->Boolean)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateCounter(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ƴ�ѭ����", module->TypeSystem->Void, ToList(CreateParameter("ѭ������", module->TypeSystem->Int32), CreateParameter("��ѭ��������¼����", gcnew ByReferenceType(module->TypeSystem->Int32), ParameterAttributes::Out)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateCounterLoop(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ƴ�ѭ��β", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateFor(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����ѭ����", module->TypeSystem->Void, ToList(CreateParameter("������ʼֵ", module->TypeSystem->Int32), CreateParameter("����Ŀ��ֵ", module->TypeSystem->Int32), CreateParameter("��������ֵ", module->TypeSystem->Int32), CreateParameter("ѭ������", gcnew ByReferenceType(module->TypeSystem->Int32), ParameterAttributes::Out | ParameterAttributes::Optional)), STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateNext(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����ѭ��β", module->TypeSystem->Void, nullptr, STATICMETHOD);
	return method;
}

MethodDefinition^ Krnln::CreateEnd(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����", module->TypeSystem->Void, nullptr, STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Environment, "Exit", typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateReDim(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("��������", module->ImportReference(typeof(RuntimeTypeHandle))), CreateParameter("���ض�����������", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("�Ƿ�����ǰ������", module->TypeSystem->Boolean), CreateParameter("�����Ӧά������ֵ", gcnew ArrayType(module->TypeSystem->Int32)));
	MethodReference^ ctor = module->ImportReference(GetCtor(ParamArrayAttribute));
	params[3]->CustomAttributes->Add(gcnew CustomAttribute(ctor));
	MethodDefinition^ method = CreateMethod("�ض�������", module->TypeSystem->Void, params, STATICMETHOD);
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

MethodDefinition^ Krnln::CreateGetAryElementCount(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�����Ա��", module->TypeSystem->Int32, ToList(CreateParameter("�������������", module->ImportReference(typeof(Array)))), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateUBound(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�����±�", module->TypeSystem->Int32, ToList(CreateParameter("��ȡĳά����±���������", module->ImportReference(typeof(Array))), CreateParameter("��ȡ������±��ά", module->TypeSystem->Int32, ParameterAttributes::Optional)), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateCopyAry(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��������", module->TypeSystem->Void, ToList(CreateParameter("���Ƶ����������", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("�����Ƶ���������", module->ImportReference(typeof(Array)))), STATICMETHOD);
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

MethodDefinition^ Krnln::CreateAddElement(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("�������Ա���������", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("������ĳ�Ա����", module->TypeSystem->Object));
	MethodDefinition^ method = CreateMethod("�����Ա", module->TypeSystem->Void, params, STATICMETHOD);
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

MethodDefinition^ Krnln::CreateInsElement(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("�������Ա���������", gcnew ByReferenceType(module->ImportReference(typeof(Array))), ParameterAttributes::Out), CreateParameter("�������λ��", module->TypeSystem->Int32), CreateParameter("������ĳ�Ա����", module->TypeSystem->Object));
	MethodDefinition^ method = CreateMethod("�����Ա", module->TypeSystem->Void, params, STATICMETHOD);
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

MethodDefinition^ Krnln::CreateChr(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ַ�", module->TypeSystem->String, ToList(CreateParameter("��ȡ���ַ����ַ�����", module->TypeSystem->Byte)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(Char, "ToString")));
	return method;
}

MethodDefinition^ Krnln::CreateUCase(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("����д", module->TypeSystem->String, ToList(CreateParameter("���任���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(String, "ToUpper")));
	return method;
}

MethodDefinition^ Krnln::CreateLCase(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��Сд", module->TypeSystem->String, ToList(CreateParameter("���任���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(String, "ToLower")));
	return method;
}

MethodDefinition^ Krnln::CreateLTrim(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ɾ�׿�", module->TypeSystem->String, ToList(CreateParameter("��ɾ���ո���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_2);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Char);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 32);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 12288);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(String, "TrimStart", typeof(array<Char>))));
	return method;
}

MethodDefinition^ Krnln::CreateRTrim(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ɾβ��", module->TypeSystem->String, ToList(CreateParameter("��ɾ���ո���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_2);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Char);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 32);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 12288);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(String, "TrimEnd", typeof(array<Char>))));
	return method;
}

MethodDefinition^ Krnln::CreateTrim(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ɾ��β��", module->TypeSystem->String, ToList(CreateParameter("��ɾ���ո���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_2);
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Char);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 32);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Dup);
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 12288);
	AddILCode(ILProcessor, OpCodes::Stelem_I2);
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(String, "Trim", typeof(array<Char>))));
	return method;
}

MethodDefinition^ Krnln::CreateTrimAll(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ɾȫ����", module->TypeSystem->String, ToList(CreateParameter("��ɾ���ո���ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	MethodReference^ Replace = module->ImportReference(GetInstanceMethod(String, "Replace", typeof(String), typeof(String)));
	AddILCode(ILProcessor, OpCodes::Ldstr, " ");
	AddILCode(ILProcessor, OpCodes::Ldnull);
	AddILCode(ILProcessor, OpCodes::Callvirt, Replace);
	AddILCode(ILProcessor, OpCodes::Ldstr, ((Char)12288).ToString());
	AddILCode(ILProcessor, OpCodes::Ldnull);
	AddILCode(ILProcessor, OpCodes::Callvirt, Replace);
	return method;
}

MethodDefinition^ Krnln::CreateStrComp(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("�ı��Ƚ�", module->TypeSystem->Int32, ToList(CreateParameter("���Ƚ��ı�һ", module->TypeSystem->String), CreateParameter("���Ƚ��ı���", module->TypeSystem->String), CreateParameter("�Ƿ����ִ�Сд", module->TypeSystem->Boolean)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4_0);
	AddILCode(ILProcessor, OpCodes::Ceq);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(String, "Compare", typeof(String), typeof(String), typeof(bool))));
	return method;
}

MethodDefinition^ Krnln::CreateToTime(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("��ʱ��", module->ImportReference(typeof(DateTime)), ToList(CreateParameter("��ת�����ı�", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(DateTime, "Parse", typeof(String))));
	return method;
}

MethodDefinition^ Krnln::CreateGetDaysOfSpecMonth(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡĳ������", module->TypeSystem->Int32, ToList(CreateParameter("���", module->TypeSystem->Int32), CreateParameter("�·�", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(DateTime, "DaysInMonth", typeof(int), typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateYear(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ���", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Year")));
	return method;
}

MethodDefinition^ Krnln::CreateMonth(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�·�", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Month")));
	return method;
}

MethodDefinition^ Krnln::CreateDay(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ��", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Day")));
	return method;
}

MethodDefinition^ Krnln::CreateWeekDay(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ���ڼ�", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_DayOfWeek")));
	AddILCode(ILProcessor, OpCodes::Ldc_I4_1);
	AddILCode(ILProcessor, OpCodes::Add);
	return method;
}

MethodDefinition^ Krnln::CreateHour(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡСʱ", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Hour")));
	return method;
}

MethodDefinition^ Krnln::CreateMinute(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ����", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Minute")));
	return method;
}

MethodDefinition^ Krnln::CreateSecond(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ��", module->TypeSystem->Int32, ToList(CreateParameter("ʱ��", module->ImportReference(typeof(DateTime)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Second")));
	return method;
}

MethodDefinition^ Krnln::CreateGetSpecTime(ModuleDefinition^ module)
{
	IList<ParameterDefinition^>^ params = ToList(CreateParameter("��", module->TypeSystem->Int32), CreateParameter("��", module->TypeSystem->Int32), CreateParameter("��", module->TypeSystem->Int32), CreateParameter("Сʱ", module->TypeSystem->Int32), CreateParameter("����", module->TypeSystem->Int32), CreateParameter("��", module->TypeSystem->Int32));
	params[1]->IsOptional = true;
	params[1]->Constant = 1;
	params[2]->IsOptional = true;
	params[2]->Constant = 1;
	params[3]->IsOptional = true;
	params[3]->Constant = 0;
	params[4]->IsOptional = true;
	params[4]->Constant = 0;
	params[5]->IsOptional = true;
	params[5]->Constant = 0;
	MethodDefinition^ method = CreateMethod("ָ��ʱ��", module->ImportReference(typeof(DateTime)), params, STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Newobj, module->ImportReference(GetCtor(DateTime, typeof(int), typeof(int), typeof(int), typeof(int), typeof(int), typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateNow(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ����ʱ��", module->ImportReference(typeof(DateTime)), nullptr, STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(DateTime, "get_Now")));
	return method;
}

MethodDefinition^ Krnln::CreateGetDatePart(ModuleDefinition^ module)
{
	TypeReference^ dt = module->ImportReference(typeof(DateTime));
	MethodDefinition^ method = CreateMethod("ȡ����", dt, ToList(CreateParameter("ʱ��", dt)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "get_Date")));
	return method;
}

MethodDefinition^ Krnln::CreateGetTimePart(ModuleDefinition^ module)
{
	TypeReference^ dt = module->ImportReference(typeof(DateTime));
	MethodDefinition^ method = CreateMethod("ȡʱ��", dt, ToList(CreateParameter("ʱ��", dt)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Callvirt, module->ImportReference(GetInstanceMethod(DateTime, "ToLongTimeString")));
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(DateTime, "Parse", typeof(String))));
	return method;
}

MethodDefinition^ Krnln::CreateGetHexText(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡʮ�������ı�", module->TypeSystem->String, ToList(CreateParameter("��ȡ�����ı�����ֵ", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 16);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ToString", typeof(int), typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateGetOctText(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�˽����ı�", module->TypeSystem->String, ToList(CreateParameter("��ȡ�����ı�����ֵ", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 8);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ToString", typeof(int), typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateHex(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ʮ������", module->TypeSystem->Int32, ToList(CreateParameter("ʮ�������ı�����", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 16);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ToInt32", typeof(String), typeof(int))));
	return method;
}

MethodDefinition^ Krnln::CreateBinary(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("������", module->TypeSystem->Int32, ToList(CreateParameter("�������ı�����", module->TypeSystem->String)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Ldc_I4, 2);
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Convert, "ToInt32", typeof(String), typeof(int))));
	return method;
}

MethodDefinition^ CreateSpaceBin(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�հ��ֽڼ�", gcnew ArrayType(module->TypeSystem->Byte), ToList(CreateParameter("���ֽ���Ŀ", module->TypeSystem->Int32)), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Newarr, module->TypeSystem->Byte);
	return method;
}

array<byte>^ Krnln::���(array<byte>^ �����ֽڼ�, ...array<array<byte>^>^ ���ֽڼ�)
{
	int num;
	if (�����ֽڼ� == nullptr) num = 0;
	else num = �����ֽڼ�->Length;
	int num2 = 0;
	for (int i = 0; i < ���ֽڼ�->Length; i++) num2 += ���ֽڼ�[i]->Length;
	array<byte>^ arr = gcnew array<byte>(num + num2);
	if (�����ֽڼ� != nullptr) Array::Copy(�����ֽڼ�, 0, arr, 0, num);
	num2 = num;
	for (int i = 0; i < ���ֽڼ�->Length; i++)
	{
		array<byte>^ arr2 = ���ֽڼ�[i];
		Array::Copy(arr2, 0, arr, num2, arr2->Length);
		num2 += arr2->Length;
	}
	return arr;
}

int Krnln::ɾ����Ա(Array^% ��ɾ����Ա���������, int ��ɾ����λ��, int ��ɾ���ĳ�Ա��Ŀ)
{
	if (��ɾ����Ա��������� == nullptr) return 0;
	int len = ��ɾ����Ա���������->Length;
	if (��ɾ����λ�� < 1 || ��ɾ����λ��> len + 1) return 0;
	��ɾ����λ��--;
	System::Type^ type = ��ɾ����Ա���������->GetType();
	len -= ��ɾ���ĳ�Ա��Ŀ + ��ɾ����λ��;
	if (len <= 0)
	{
		��ɾ���ĳ�Ա��Ŀ += len;
		if (��ɾ����λ�� == 0)
		{
			��ɾ����Ա��������� = (Array^)Activator::CreateInstance(type, (Object^)0);
			return ��ɾ���ĳ�Ա��Ŀ;
		}
	}
	Array^ arr = (Array^)Activator::CreateInstance(type, (Object^)(��ɾ����Ա���������->Length - ��ɾ���ĳ�Ա��Ŀ));
	if (��ɾ����λ�� > 0) Array::Copy(��ɾ����Ա���������, 0, arr, 0, ��ɾ����λ��);
	if (len > 0) Array::Copy(��ɾ����Ա���������, ��ɾ����λ�� + ��ɾ���ĳ�Ա��Ŀ, arr, ��ɾ����λ��, len);
	��ɾ����Ա��������� = arr;
	return ��ɾ���ĳ�Ա��Ŀ;
}

void Krnln::�������(Array^% ��ɾ����Ա���������)
{
	if (��ɾ����Ա��������� != nullptr) ��ɾ����Ա��������� = (Array^)Activator::CreateInstance(��ɾ����Ա���������->GetType(), (Object^)0);
}

void Krnln::��������(Array^% ��ֵ�������, bool �������Ƿ�Ϊ��С����)
{
	if (��ֵ������� != nullptr)
	{
		Array::Sort(��ֵ�������);
		if (!�������Ƿ�Ϊ��С����) Array::Reverse(��ֵ�������);
	}
}

void Krnln::��������(Array^% ��ֵ�������)
{
	if (��ֵ������� != nullptr)
	{
		System::Type^ type = ��ֵ�������->GetType();
		Object^ null;
		if (type->GetElementType()->IsValueType) null = 0;
		for (int i = 0; i < ��ֵ�������->Length; i++) ��ֵ�������->SetValue(null, i);
	}
}

int Krnln::ȡ�ı�����(String^ �ı�����)
{
	if (�ı����� == nullptr) return 0;
	return �ı�����->Length;
}

String^ Krnln::ȡ�ı����(String^ ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ�����Ŀ)
{
	if (��ȡ�䲿�ֵ��ı� == nullptr) return nullptr;
	return ��ȡ�䲿�ֵ��ı�->Substring(0, ��ȡ���ַ�����Ŀ);
}

String^ Krnln::ȡ�ı��ұ�(String^ ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ�����Ŀ)
{
	if (��ȡ�䲿�ֵ��ı� == nullptr) return nullptr;
	return ��ȡ�䲿�ֵ��ı�->Substring(��ȡ�䲿�ֵ��ı�->Length - ��ȡ���ַ�����Ŀ);
}

String^ Krnln::ȡ�ı��м�(String^ ��ȡ�䲿�ֵ��ı�, int ��ʼȡ��λ��, int ��ȡ���ַ�����Ŀ)
{
	if (��ȡ�䲿�ֵ��ı� == nullptr) return nullptr;
	return ��ȡ�䲿�ֵ��ı�->Substring(��ʼȡ��λ�� - 1, ��ȡ���ַ�����Ŀ);
}

int Krnln::ȡ����(String^ ��ȡ�ַ�������ı�, [Optional][DefaultValue(1)]int ��ȡ�������ַ�λ��)
{
	if (��ȡ�ַ�������ı� == nullptr) return 0;
	return (int)��ȡ�ַ�������ı�[��ȡ�������ַ�λ��];
}

int Krnln::Ѱ���ı�(String^ ����Ѱ���ı�, String^ ��Ѱ�ҵ��ı�, int ��ʼ��Ѱλ��, bool �Ƿ����ִ�Сд)
{
	if (����Ѱ���ı� == nullptr) return -1;
	int index = ����Ѱ���ı�->IndexOf(��Ѱ�ҵ��ı�, ��ʼ��Ѱλ�� - 1, �Ƿ����ִ�Сд ? StringComparison::CurrentCultureIgnoreCase : StringComparison::CurrentCulture);
	if (index != -1) index++;
	return index;
}

int Krnln::�����ı�(String^ ����Ѱ���ı�, String^ ��Ѱ�ҵ��ı�, int ��ʼ��Ѱλ��, bool �Ƿ����ִ�Сд)
{
	if (����Ѱ���ı� == nullptr) return -1;
	int index = ����Ѱ���ı�->LastIndexOf(��Ѱ�ҵ��ı�, ��ʼ��Ѱλ�� - 1, �Ƿ����ִ�Сд ? StringComparison::CurrentCultureIgnoreCase : StringComparison::CurrentCulture);
	if (index != -1) index++;
	return index;
}

String^ Krnln::��ȫ��(String^ ���任���ı�)
{
	array<Char>^ c = ���任���ı�->ToCharArray();
	for (int i = 0; i < c->Length; i++)
	{
		if (c[i] == 32) c[i] = (Char)12288;
		else if (c[i] < 127) c[i] = (Char)(c[i] + 65248);
	}
	return gcnew String(c);
}

String^ Krnln::�����(String^ ���任���ı�)
{
	array<Char>^ c = ���任���ı�->ToCharArray();
	for (int i = 0; i < c->Length; i++)
	{
		if (c[i] == 12288) c[i] = (Char)32;
		else if (c[i] > 65280 && c[i] < 65375) c[i] = (Char)(c[i] - 65248);
	}
	return gcnew String(c);
}

String^ Krnln::�ı��滻(String^ �����滻���ı�, int ��ʼ�滻λ��, int �滻����, String^ �����滻���ı�)
{
	if (�����滻���ı� != nullptr)
	{
		int len = �����滻���ı�->Length;
		��ʼ�滻λ��--;
		if (��ʼ�滻λ�� >= 0 && ��ʼ�滻λ�� < len)
		{
			len -= �滻���� + ��ʼ�滻λ��;
			if (len <= 0)
			{
				�滻���� += len;
				if (��ʼ�滻λ�� == 0) return �����滻���ı�;
			}
			String^ str;
			if (��ʼ�滻λ�� > 0) str += �����滻���ı�->Substring(0, ��ʼ�滻λ��);
			str += �����滻���ı�;
			if (len > 0) str += �����滻���ı�->Substring(��ʼ�滻λ�� + �滻����, len);
			return str;
		}
	}
	return �����滻���ı�;
}

String^ Krnln::���ı��滻(String^ �����滻���ı�, String^ �����滻�����ı�, String^ �����滻�����ı�, int �����滻����ʼλ��, int �滻���еĴ���, bool �Ƿ����ִ�Сд)
{
	if (�����滻���ı� != nullptr && !String::IsNullOrEmpty(�����滻�����ı�))
	{
		�����滻����ʼλ��--;
		if (�����滻����ʼλ�� >= 0 && �����滻����ʼλ�� < �����滻���ı�->Length)
		{
			int len = �����滻�����ı�->Length;
			StringComparison sc = �Ƿ����ִ�Сд ? StringComparison::CurrentCulture : StringComparison::CurrentCultureIgnoreCase;
			do
			{
				�����滻����ʼλ�� = �����滻���ı�->IndexOf(�����滻�����ı�, �����滻����ʼλ��, sc);
				if (�����滻����ʼλ�� == -1) break;
				�����滻���ı� = Krnln::�ı��滻(�����滻���ı�, �����滻����ʼλ�� + 1, len, �����滻�����ı�);
				�滻���еĴ���--;
			} while (�滻���еĴ��� > 0);
		}
	}
	return �����滻���ı�;
}

String^ Krnln::ȡ�հ��ı�(int �ظ�����)
{
	String^ str = "";
	return str->PadLeft(�ظ�����);
}

String^ Krnln::ȡ�ظ��ı�(int �ظ�����, String^ ���ظ��ı�)
{
	String^ str;
	while (�ظ����� > 0)
	{
		str += ���ظ��ı�;
		�ظ�����--;
	}
	return str;
}

array<String^>^ Krnln::�ָ��ı�(String^ ���ָ��ı�, String^ �����ָ���ı�, int Ҫ���ص����ı���Ŀ)
{
	if (���ָ��ı� == nullptr) return nullptr;
	array<String^>^ arr = ���ָ��ı�->Split(�����ָ���ı�->ToCharArray());
	if (Ҫ���ص����ı���Ŀ > 0)  Array::Resize(arr, Ҫ���ص����ı���Ŀ);
	return arr;
}

DateTime Krnln::����ʱ��(DateTime ʱ��, int �����Ӳ���, int ����ֵ)
{
	switch (�����Ӳ���)
	{
	case 1:
		ʱ�� = ʱ��.AddYears(����ֵ);
		break;
	case 2:
		ʱ�� = ʱ��.AddMonths(����ֵ * 3);
		break;
	case 3:
		ʱ�� = ʱ��.AddMonths(����ֵ);
		break;
	case 4:
		ʱ�� = ʱ��.AddDays(����ֵ * 7);
		break;
	case 5:
		ʱ�� = ʱ��.AddDays(����ֵ);
		break;
	case 6:
		ʱ�� = ʱ��.AddHours(����ֵ);
		break;
	case 7:
		ʱ�� = ʱ��.AddMinutes(����ֵ);
		break;
	case 8:
		ʱ�� = ʱ��.AddSeconds(����ֵ);
		break;
	}
	return ʱ��;
}

double Krnln::ȡʱ����(DateTime ʱ��1, DateTime ʱ��2, int ȡ�������)
{
	TimeSpan time = ʱ��1 - ʱ��2;
	double span;
	switch (ȡ�������)
	{
	case 1:
		span = time.TotalDays / 365;
		break;
	case 2:
		span = time.TotalDays / 91.25;
		break;
	case 3:
		span = time.TotalDays / 30.4166;
		break;
	case 4:
		span = time.TotalDays / 7;
		break;
	case 5:
		span = time.TotalDays;
		break;
	case 6:
		span = time.TotalHours;
		break;
	case 7:
		span = time.TotalMinutes;
		break;
	case 8:
		span = time.TotalSeconds;
		break;
	}
	return span;
}

String^ Krnln::ʱ�䵽�ı�(DateTime ��ת�����ı���ʱ��, int ת������)
{
	String^ str;
	switch (ת������)
	{
	case 1:
		str = ��ת�����ı���ʱ��.ToString();
		break;
	case 2:
		str = ��ת�����ı���ʱ��.ToLongDateString();
		break;
	case 3:
		str = ��ת�����ı���ʱ��.ToLongTimeString();
		break;
	}
	return str;
}

int Krnln::ȡʱ�䲿��(DateTime ��ȡ�䲿�ֵ�ʱ��, int ת������)
{
	int num;
	switch (ת������)
	{
	case 1:
		num = ��ȡ�䲿�ֵ�ʱ��.Year;
		break;
	case 2:
		num = Math::Ceiling(��ȡ�䲿�ֵ�ʱ��.Month / 3);
		break;
	case 3:
		num = ��ȡ�䲿�ֵ�ʱ��.Month;
		break;
	case 4:
		num = Math::Ceiling(��ȡ�䲿�ֵ�ʱ��.DayOfYear / 7);
		break;
	case 5:
		num = ��ȡ�䲿�ֵ�ʱ��.Day;
		break;
	case 6:
		num = ��ȡ�䲿�ֵ�ʱ��.Hour;
		break;
	case 7:
		num = ��ȡ�䲿�ֵ�ʱ��.Minute;
		break;
	case 8:
		num = ��ȡ�䲿�ֵ�ʱ��.Second;
		break;
	case 9:
		num = (int)��ȡ�䲿�ֵ�ʱ��.DayOfWeek + 1;
		break;
	case 10:
		num = ��ȡ�䲿�ֵ�ʱ��.DayOfYear;
		break;
	}
	return num;
}

[DllImport("Kernel32.dll")]
extern bool SetLocalTime(SYSTEMTIME% sysTime);

bool Krnln::������ʱ��(DateTime �����õ�ʱ��)
{
	SYSTEMTIME st;
	st.wYear = �����õ�ʱ��.Year;
	st.wMonth = �����õ�ʱ��.Month;
	st.wDay = �����õ�ʱ��.Day;
	st.wDayOfWeek = (WORD)�����õ�ʱ��.DayOfWeek;
	st.wHour = �����õ�ʱ��.Hour;
	st.wMinute = �����õ�ʱ��.Minute;
	st.wSecond = �����õ�ʱ��.Second;
	st.wMilliseconds = �����õ�ʱ��.Millisecond;
	return SetLocalTime(st);
}

String^ getunit(int i, bool jt)
{

	int a = i / 9;
	int b = i % 9;
	int c = b / 5;
	int d = b % 5;
	String^ str = "";
	if (a != 0 || c != 0) d++;
	switch (d)
	{
	case 1:
		str = str->PadRight(c, (Char)19975);
		str = str->PadRight(a, (Char)20159);
		break;
	case 2:
		str = jt ? "ʮ" : "ʰ";
		break;
	case 3:
		str = jt ? "��" : "��";
		break;
	case 4:
		str = jt ? "ǧ" : "Ǫ";
		break;
	}
	return str;
}

String^ getint(Char c, bool jt)
{
	String^ str;
	switch (c)
	{
	case '0':
		str = "��";
		break;
	case '1':
		str = jt ? "һ" : "Ҽ";
		break;
	case '2':
		str = jt ? "��" : "��";
		break;
	case '3':
		str = jt ? "��" : "��";
		break;
	case '4':
		str = jt ? "��" : "��";
		break;
	case '5':
		str = jt ? "��" : "��";
		break;
	case '6':
		str = jt ? "��" : "½";
		break;
	case '7':
		str = jt ? "��" : "��";
		break;
	case '8':
		str = jt ? "��" : "��";
		break;
	case '9':
		str = "��";
		break;
	}
	return str;
}

String^ Krnln::��ֵ����д(double ��ת����ʽ����ֵ, bool �Ƿ�ת��Ϊ����)
{
	String^ str = ��ת����ʽ����ֵ.ToString();
	array<String^>^ arr = str->Split('.');
	str = arr[0];
	int len = str->Length;
	String^ prev;
	String^ ret = "";
	for (int i = str->Length - 1, n = 1; i >= 0; i--, n++)
	{
		String^ s = getint(str[i], �Ƿ�ת��Ϊ����);
		String^ ui;
		if (s == "��")
		{
			ui = "";
			if (prev == "��") s = "";
		}
		else ui = getunit(n, �Ƿ�ת��Ϊ����);
		prev = s;
		ret = s + ui + ret;
	}
	ret = ret->TrimEnd((Char)38646);
	if (ret == "") ret = "��";
	if (arr->Length == 2)
	{
		str = arr[1];
		prev = "��";
		for (int i = 0; i < str->Length; i++) prev += getint(str[i], �Ƿ�ת��Ϊ����);
		prev = prev->TrimEnd((Char)38646);
		if (prev != "��") ret += prev;
	}
	return ret;
}

String^ Krnln::��ֵ�����(double ��ת����ʽ����ֵ, bool �Ƿ�ת��Ϊ����)
{
	��ת����ʽ����ֵ = Math::Round(��ת����ʽ����ֵ, 2);
	double num = Math::Truncate(��ת����ʽ����ֵ);
	String^ str = Krnln::��ֵ����д(num, �Ƿ�ת��Ϊ����);
	str += �Ƿ�ת��Ϊ���� ? "Ԫ" : "Բ";
	��ת����ʽ����ֵ = ��ת����ʽ����ֵ - num;
	if (��ת����ʽ����ֵ > 0)
	{
		String^ d = ��ת����ʽ����ֵ.ToString("F2");
		String^ j = getint(d[2], �Ƿ�ת��Ϊ����);
		String^ f = getint(d[3], �Ƿ�ת��Ϊ����);
		bool b1 = !String::IsNullOrEmpty(j);
		bool b2 = !String::IsNullOrEmpty(f);
		if (b1 || b2)
		{
			if (b1) str += j + "��";
			if (b2) str += f + "��";
		}
	}
	return str;
}

String^ Krnln::��ֵ����ʽ�ı�(double ��ת��Ϊ�ı�����ֵ, [Optional]Nullable<int> С������λ��, bool �Ƿ����ǧ��λ�ָ�)
{
	String^ str;
	if (�Ƿ����ǧ��λ�ָ�)
	{
		str = "N";
		if (С������λ��.HasValue) str += С������λ��.Value;
		else
		{
			array<String^>^ arr = ��ת��Ϊ�ı�����ֵ.ToString()->Split('.');
			int len;
			if (arr->Length == 2) len = arr[1]->Length;
			else len = 0;
			str += len;
		}
	}
	else
	{
		if (С������λ��.HasValue) str = "F" + С������λ��.Value;
	}
	return ��ת��Ϊ�ı�����ֵ.ToString(str);
}

int Krnln::ȡ�ֽڼ�����(array<byte>^ �ֽڼ�����)
{
	if (�ֽڼ����� == nullptr) return 0;
	return �ֽڼ�����->Length;
}

array<byte>^ Krnln::���ֽڼ�(String^ ��ת��Ϊ�ֽڼ�������)
{
	if (��ת��Ϊ�ֽڼ������� == nullptr) return gcnew array<byte>(0);
	return Encoding::ASCII->GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(DateTime ��ת��Ϊ�ֽڼ�������)
{
	return ���ֽڼ�(��ת��Ϊ�ֽڼ�������.Ticks);
}

array<byte>^ Krnln::���ֽڼ�(IntPtr ��ת��Ϊ�ֽڼ�������)
{
	if (IntPtr::Size == 4) return ���ֽڼ�(��ת��Ϊ�ֽڼ�������.ToInt32());
	else return ���ֽڼ�(��ת��Ϊ�ֽڼ�������.ToInt64());
}

array<byte>^ Krnln::���ֽڼ�(bool ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(byte ��ת��Ϊ�ֽڼ�������)
{
	return gcnew array<byte>{ ��ת��Ϊ�ֽڼ������� };
}

array<byte>^ Krnln::���ֽڼ�(short ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(int ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(Int64 ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(float ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

array<byte>^ Krnln::���ֽڼ�(double ��ת��Ϊ�ֽڼ�������)
{
	return BitConverter::GetBytes(��ת��Ϊ�ֽڼ�������);
}

Object^ Krnln::ȡ�ֽڼ�����(array<byte>^ ��ȡ���������ݵ��ֽڼ�, int ��ȡ�����ݵ�����, int ��ʼ����λ��)
{
	if (��ȡ���������ݵ��ֽڼ� == nullptr || ��ȡ���������ݵ��ֽڼ�->Length == 0) return nullptr;
	��ʼ����λ��--;
	if (��ʼ����λ�� < 0) return nullptr;
	Object^ obj;
	switch (��ȡ�����ݵ�����)
	{
	case 1:
		obj = ��ȡ���������ݵ��ֽڼ�[��ʼ����λ��];
		break;
	case 2:
		obj = BitConverter::ToInt16(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 3:
		obj = BitConverter::ToInt32(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 4:
		obj = BitConverter::ToInt64(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 5:
		obj = BitConverter::ToSingle(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 6:
		obj = BitConverter::ToDouble(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 7:
		obj = BitConverter::ToBoolean(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��);
		break;
	case 8:
		obj = DateTime(BitConverter::ToInt64(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��));
		break;
	case 9:
		if (IntPtr::Size == 4) obj = IntPtr(BitConverter::ToInt32(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��));
		else obj = IntPtr(BitConverter::ToInt64(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��));
		break;
	case 10:
		obj = Encoding::ASCII->GetString(��ȡ���������ݵ��ֽڼ�, ��ʼ����λ��, ��ȡ���������ݵ��ֽڼ�->Length - ��ʼ����λ��);
		break;
	}
	return obj;
}

array<byte>^ Krnln::ȡ�ֽڼ����(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ȡ���ֽڵ���Ŀ)
{
	if (��ȡ�䲿�ֵ��ֽڼ� != nullptr && ��ȡ���ֽڵ���Ŀ > 0)
	{
		if (��ȡ���ֽڵ���Ŀ > ��ȡ�䲿�ֵ��ֽڼ�->Length) ��ȡ���ֽڵ���Ŀ = ��ȡ�䲿�ֵ��ֽڼ�->Length;
		array<byte>^ arr = gcnew array<byte>(��ȡ���ֽڵ���Ŀ);
		Array::Copy(��ȡ�䲿�ֵ��ֽڼ�, arr, ��ȡ���ֽڵ���Ŀ);
		return arr;
	}
	return nullptr;
}

array<byte>^ Krnln::ȡ�ֽڼ��ұ�(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ȡ���ֽڵ���Ŀ)
{
	if (��ȡ�䲿�ֵ��ֽڼ� != nullptr && ��ȡ���ֽڵ���Ŀ > 0)
	{
		if (��ȡ���ֽڵ���Ŀ > ��ȡ�䲿�ֵ��ֽڼ�->Length) ��ȡ���ֽڵ���Ŀ = ��ȡ�䲿�ֵ��ֽڼ�->Length;
		int index = ��ȡ�䲿�ֵ��ֽڼ�->Length - ��ȡ���ֽڵ���Ŀ;
		array<byte>^ arr = gcnew array<byte>(��ȡ���ֽڵ���Ŀ);
		Array::Copy(��ȡ�䲿�ֵ��ֽڼ�, index, arr, 0, ��ȡ���ֽڵ���Ŀ);
		return arr;
	}
	return nullptr;
}

array<byte>^ Krnln::ȡ�ֽڼ��м�(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ʼȡ��λ��, int ��ȡ���ֽڵ���Ŀ)
{
	if (��ȡ�䲿�ֵ��ֽڼ� != nullptr && ��ʼȡ��λ�� > 0 && ��ȡ���ֽڵ���Ŀ > 0)
	{
		��ʼȡ��λ��--;
		int len = ��ȡ�䲿�ֵ��ֽڼ�->Length - ��ʼȡ��λ��;
		if (len >= 0)
		{
			if (��ȡ���ֽڵ���Ŀ > len) ��ȡ���ֽڵ���Ŀ = len;
			array<byte>^ arr = gcnew array<byte>(��ȡ���ֽڵ���Ŀ);
			Array::Copy(��ȡ�䲿�ֵ��ֽڼ�, ��ʼȡ��λ��, arr, 0, ��ȡ���ֽڵ���Ŀ);
			return arr;
		}
	}
	return nullptr;
}

int Krnln::Ѱ���ֽڼ�(array<byte>^ ����Ѱ���ֽڼ�, array<byte>^ ��Ѱ�ҵ��ֽڼ�, int ��ʼ��Ѱλ��)
{
	if (����Ѱ���ֽڼ� != nullptr && ��ʼ��Ѱλ�� > 0)
	{
		if (��Ѱ�ҵ��ֽڼ� != nullptr && ��Ѱ�ҵ��ֽڼ�->Length > 0)
		{
			if (����Ѱ���ֽڼ�->Length > 0)
			{
				��ʼ��Ѱλ��--;
				byte f = ��Ѱ�ҵ��ֽڼ�[0];
				do
				{
					��ʼ��Ѱλ�� = Array::IndexOf(����Ѱ���ֽڼ�, f, ��ʼ��Ѱλ��);
					if (��ʼ��Ѱλ�� >= 0)
					{
						int len = ����Ѱ���ֽڼ�->Length - ��ʼ��Ѱλ��;
						if (len < ��Ѱ�ҵ��ֽڼ�->Length) break;
						for (int i = 0; i < ��Ѱ�ҵ��ֽڼ�->Length; i++) if (����Ѱ���ֽڼ�[��ʼ��Ѱλ�� + i] != ��Ѱ�ҵ��ֽڼ�[i]) goto rt;
						return ��ʼ��Ѱλ�� + 1;
					rt:;
					}
				} while (��ʼ��Ѱλ�� >= 0);
			}
		}
		else return 1;
	}
	return -1;
}

int Krnln::�����ֽڼ�(array<byte>^ ����Ѱ���ֽڼ�, array<byte>^ ��Ѱ�ҵ��ֽڼ�, [Optional][DefaultValue(1)]int ��ʼ��Ѱλ��)
{
	if (����Ѱ���ֽڼ� != nullptr && ��ʼ��Ѱλ�� > 0)
	{
		if (��Ѱ�ҵ��ֽڼ� != nullptr && ��Ѱ�ҵ��ֽڼ�->Length > 0)
		{
			if (����Ѱ���ֽڼ�->Length > 0)
			{
				��ʼ��Ѱλ��--;
				byte f = ��Ѱ�ҵ��ֽڼ�[0];
				do
				{
					��ʼ��Ѱλ�� = Array::LastIndexOf(����Ѱ���ֽڼ�, f, ��ʼ��Ѱλ��);
					if (��ʼ��Ѱλ�� >= 0)
					{
						int len = ����Ѱ���ֽڼ�->Length - ��ʼ��Ѱλ��;
						if (len < ��Ѱ�ҵ��ֽڼ�->Length) break;
						for (int i = 0; i < ��Ѱ�ҵ��ֽڼ�->Length; i++) if (����Ѱ���ֽڼ�[��ʼ��Ѱλ�� + i] != ��Ѱ�ҵ��ֽڼ�[i]) goto rt;
						return ��ʼ��Ѱλ�� + 1;
					rt:;
					}
				} while (��ʼ��Ѱλ�� >= 0);
			}
		}
		else return 1;
	}
	return -1;
}

array<byte>^ Krnln::�ֽڼ��滻(array<byte>^ ���滻�䲿�ֵ��ֽڼ�, int ��ʼ�滻λ��, int �滻����, array<byte>^ �����滻���ֽڼ�)
{
	if (���滻�䲿�ֵ��ֽڼ� != nullptr)
	{
		int len = ���滻�䲿�ֵ��ֽڼ�->Length;
		��ʼ�滻λ��--;
		if (��ʼ�滻λ�� >= 0 && ��ʼ�滻λ�� < len)
		{
			len -= �滻���� + ��ʼ�滻λ��;
			if (len <= 0)
			{
				�滻���� += len;
				if (��ʼ�滻λ�� == 0) return ���滻�䲿�ֵ��ֽڼ�;
			}
			array<byte>^ bin;
			if (��ʼ�滻λ�� > 0) bin = ȡ�ֽڼ����(���滻�䲿�ֵ��ֽڼ�, ��ʼ�滻λ��);
			bin = ���(bin, �����滻���ֽڼ�);
			if (len > 0) bin = ���(bin, ȡ�ֽڼ��ұ�(���滻�䲿�ֵ��ֽڼ�, len));
			return bin;
		}
	}
	return ���滻�䲿�ֵ��ֽڼ�;
}

array<byte>^ Krnln::���ֽڼ��滻(array<byte>^ �����滻���ֽڼ�, array<byte>^ �����滻�����ֽڼ�, array<byte>^ �����滻�����ֽڼ�, int �����滻����ʼλ��, int �滻���еĴ���)
{
	if (�����滻���ֽڼ� != nullptr && �����滻�����ֽڼ� != nullptr && �����滻�����ֽڼ�->Length > 0)
	{
		if (�����滻����ʼλ�� > 0 && �����滻����ʼλ�� < �����滻�����ֽڼ�->Length)
		{
			int len = �����滻�����ֽڼ�->Length;
			do
			{
				�����滻����ʼλ�� = Ѱ���ֽڼ�(�����滻���ֽڼ�, �����滻�����ֽڼ�, �����滻����ʼλ��);
				if (�����滻����ʼλ�� == -1) break;
				�����滻���ֽڼ� = �ֽڼ��滻(�����滻���ֽڼ�, �����滻����ʼλ��, len, �����滻�����ֽڼ�);
				�滻���еĴ���--;
			} while (�滻���еĴ��� > 0);
		}
	}
	return �����滻���ֽڼ�;
}

array<byte>^ Krnln::ȡ�ظ��ֽڼ�(int �ظ�����, array<byte>^ ���ظ����ֽڼ�)
{
	if (���ظ����ֽڼ� != nullptr && �ظ����� > 0)
	{
		int len = ���ظ����ֽڼ�->Length;
		array<byte>^ arr = gcnew array<byte>(len * �ظ�����);
		for (int i = 0; i < �ظ�����; i++) Array::Copy(���ظ����ֽڼ�, 0, arr, i * len, len);
		return arr;
	}
	return nullptr;
}