#include "stdafx.h"
#include "Plugins.h"
#include "common.net.h"
#include "e_net.net.h"

MethodDefinition^ E_Net::GetType(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ����", module->ImportReference(typeof(Type)), ToList(CreateParameter("����", module->ImportReference(typeof(RuntimeTypeHandle)))), STATICMETHOD);
	ILProcessor^ ILProcessor = method->Body->GetILProcessor();
	AddILCode(ILProcessor, OpCodes::Call, module->ImportReference(GetStaticMethod(Type, "GetTypeFromHandle", typeof(RuntimeTypeHandle))));
	return method;
}

MethodDefinition^ E_Net::GetFunction(ModuleDefinition^ module)
{
	MethodDefinition^ method = CreateMethod("ȡ�ຯ��", module->ImportReference(typeof(Delegate)), ToList(CreateParameter("���", module->TypeSystem->Int32)), STATICMETHOD);
	return method;
}

Object^ E_Net::ʵ����(RuntimeTypeHandle ����, ...array<Object^>^ ����)
{
	return Activator::CreateInstance(Type::GetTypeFromHandle(����), ����);
}