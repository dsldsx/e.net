#include "stdafx.h"

using namespace System;
using namespace System::Reflection;
using namespace System::Runtime::CompilerServices;
using namespace System::Runtime::InteropServices;
using namespace System::Security::Permissions;

//
// �йس��򼯵ĳ�����Ϣͨ���������Լ�
// ���ơ�������Щ����ֵ���޸�
// ����򼯹�������Ϣ��
//
[assembly:AssemblyTitleAttribute(L"e.net")];
[assembly:AssemblyDescriptionAttribute(L"")];
[assembly:AssemblyConfigurationAttribute(L"")];
[assembly:AssemblyCompanyAttribute(L"Ϊ��о��")];
[assembly:AssemblyProductAttribute(L"e.net")];
[assembly:AssemblyCopyrightAttribute(L"Ϊ��о��")];
[assembly:AssemblyTrademarkAttribute(L"")];
[assembly:AssemblyCultureAttribute(L"")];

//
// ���򼯵İ汾��Ϣ�������ĸ�ֵ���: 
//
//      ���汾
//      �ΰ汾
//      ���ɺ�
//      �޶���
//
// ������ָ������ֵ��Ҳ����ʹ�á��޶��š��͡����ɺš���Ĭ��ֵ��
// �����ǰ�������ʾʹ�á�*��: 
#define _V(x) #x
#define V(x) _V(x)
#define _F MAJOR.MINOR.BUILD.REVISION
#define FULLVISON V(_F)

[assembly:AssemblyVersionAttribute(FULLVISON)];

[assembly:ComVisible(false)];

[assembly:CLSCompliantAttribute(true)];