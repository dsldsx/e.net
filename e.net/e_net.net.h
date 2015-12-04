#pragma once

#define E_NET LI_LIB_GUID_STR

using namespace System;
using namespace Mono::Cecil;

enum e_net_method : UINT
{
	ʵ���� = 0x00,
	ȡ�ຯ�� = 0x01,
	ȡ���� = 0x02
};

[LibGuid(E_NET)]
ref class E_Net : Plugin
{
	[LibMethod(e_net_method::ȡ����, EMethodMode::Embed)]
	MethodDefinition^ GetType(ModuleDefinition^ module);
	[LibMethod(e_net_method::ȡ�ຯ��, EMethodMode::Embed)]
	MethodDefinition^ GetFunction(ModuleDefinition^ module);
	[LibMethod(e_net_method::ʵ����)]
	static Object^ ʵ����(RuntimeTypeHandle ����, ...array<Object^>^ ����);
};