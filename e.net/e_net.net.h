#pragma once

#define E_NET LI_LIB_GUID_STR

enum e_net_method : UINT
{
	ʵ���� = 0x00
};

[LibGuid(E_NET)]
ref class E_Net : Plugin
{
	[LibMethod(e_net_method::ʵ����)]
	static Object^ ʵ����(RuntimeTypeHandle ����, ...array<Object^>^ ����);
};