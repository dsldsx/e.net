#pragma once
#include "efs.h"
#include "Plugins.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Mono::Cecil;
using namespace Mono::Cecil::Cil;
using namespace wnxd::E_NET;

#define KRNLN "d09f2340818511d396f6aaf844c7e325"

enum krnln_method : UINT
{
	��� = 0x00,
	����� = 0x01,
	�ж� = 0x02,
	�ж�ѭ���� = 0x03,
	�ж�ѭ��β = 0x04,
	ѭ���ж��� = 0x05,
	ѭ���ж�β = 0x06,
	�ƴ�ѭ���� = 0x07,
	�ƴ�ѭ��β = 0x08,
	����ѭ���� = 0x09,
	����ѭ��β = 0x0A,
	���� = 0x0D,
	���� = 0x0E,
	������ = 0x12,
	��� = 0x13,
	��� = 0x14,
	�� = 0x15,
	��� = 0x0F,
	��� = 0x10,
	���� = 0x11,
	���� = 0x26,
	������ = 0x27,
	С�� = 0x28,
	���� = 0x29,
	С�ڻ���� = 0x2A,
	���ڻ���� = 0x2B,
	���� = 0x2D,
	���� = 0x2E,
	ȡ�� = 0x2F,
	λȡ�� = 0x30,
	λ�� = 0x31,
	λ�� = 0x32,
	λ��� = 0x33,
	��ֵ = 0x34,
	�ض������� = 0x37,
	ȡ�����Ա�� = 0x38,
	ȡ�����±� = 0x39,
	�������� = 0x3A,
	�����Ա = 0x3B,
	�����Ա = 0x3C,
	ɾ����Ա = 0x3D,
	������� = 0x3E,
	�������� = 0x3F,
	ȡ�ı����� = 0x4C,
	ȡ�ı���� = 0x4D,
	ȡ�ı��ұ� = 0x4E,
	ȡ�ı��м� = 0x4F,
	�ַ� = 0x50,
	ȡ���� = 0x51,
	Ѱ���ı� = 0x52,
	�����ı� = 0x53,
	����д = 0x54,
	��Сд = 0x55,
	����ֵ = 0x59,
	���ı� = 0x5A,
	�������� = 0x0231,
	���ֽ� = 0x0275,
	�������� = 0x0276,
	������ = 0x0277,
	�������� = 0x0278,
	��С�� = 0x0279,
	���� = 0x027E,
	���� = 0x027F
};

[LibGuid(KRNLN)]
ref class Krnln : Plugin, MonoPlugin
{
public:
	property PluginType Type
	{
		virtual PluginType get() override;
	}
	virtual IList<MonoInfo^>^ GetMethods(ModuleDefinition^ module) override;
private:
	[LibMethod(krnln_method::ɾ����Ա)]
	static int ɾ����Ա([Out]Array^% ��ɾ����Ա���������, int ��ɾ����λ��, [Optional][DefaultValue(1)]int ��ɾ���ĳ�Ա��Ŀ);
	[LibMethod(krnln_method::�������)]
	static void �������([Out]Array^% ��ɾ����Ա���������);
	[LibMethod(krnln_method::��������)]
	static void ��������([Out]Array^% ��ֵ�������, [Optional][DefaultValue(true)]bool �������Ƿ�Ϊ��С����);
	[LibMethod(krnln_method::��������)]
	static void ��������([Out]Array^% ��ֵ�������);
	[LibMethod(krnln_method::ȡ�ı�����)]
	static int ȡ�ı�����(String^ �ı�����);
	[LibMethod(krnln_method::ȡ�ı����)]
	static String^ ȡ�ı����(String^ ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ�����Ŀ);
	[LibMethod(krnln_method::ȡ�ı��ұ�)]
	static String^ ȡ�ı��ұ�(String^ ��ȡ�䲿�ֵ��ı�, int ��ȡ���ַ�����Ŀ);
	[LibMethod(krnln_method::ȡ�ı��м�)]
	static String^ ȡ�ı��м�(String^ ��ȡ�䲿�ֵ��ı�, int ��ʼȡ��λ��, int ��ȡ���ַ�����Ŀ);
	[LibMethod(krnln_method::ȡ����)]
	static int ȡ����(String^ ��ȡ�ַ�������ı�, [Optional][DefaultValue(1)]int ��ȡ�������ַ�λ��);
	[LibMethod(krnln_method::Ѱ���ı�)]
	static int Ѱ���ı�(String^ ����Ѱ���ı�, String^ ��Ѱ�ҵ��ı�, [Optional][DefaultValue(1)]int ��ʼ��Ѱλ��, bool �Ƿ����ִ�Сд);
	[LibMethod(krnln_method::�����ı�)]
	static int �����ı�(String^ ����Ѱ���ı�, String^ ��Ѱ�ҵ��ı�, [Optional][DefaultValue(1)]int ��ʼ��Ѱλ��, bool �Ƿ����ִ�Сд);
};