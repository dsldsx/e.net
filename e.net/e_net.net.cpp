#include "stdafx.h"
#include "Plugins.h"
#include "e_net.net.h"

Object^ E_Net::ʵ����(RuntimeTypeHandle ����, ...array<Object^>^ ����)
{
	return Activator::CreateInstance(Type::GetTypeFromHandle(����), ����);
}