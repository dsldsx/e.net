#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
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
	��ȫ�� = 0x56,
	����� = 0x57,
	��ʱ�� = 0x58,
	����ֵ = 0x59,
	���ı� = 0x5A,
	ɾ�׿� = 0x5B,
	ɾβ�� = 0x5C,
	ɾ��β�� = 0x5D,
	ɾȫ���� = 0x5E,
	�ı��滻 = 0x5F,
	���ı��滻 = 0x60,
	ȡ�հ��ı� = 0x61,
	ȡ�ظ��ı� = 0x62,
	�ı��Ƚ� = 0x63,
	�ָ��ı� = 0x64,
	ȡ�ֽڼ����� = 0x65,
	���ֽڼ� = 0x66,
	ȡ�ֽڼ����� = 0x67,
	ȡ�ֽڼ���� = 0x68,
	ȡ�ֽڼ��ұ� = 0x69,
	ȡ�ֽڼ��м� = 0x6A,
	Ѱ���ֽڼ� = 0x6B,
	�����ֽڼ� = 0x6C,
	�ֽڼ��滻 = 0x6D,
	���ֽڼ��滻 = 0x6E,
	ȡ�հ��ֽڼ� = 0x6F,
	ȡ�ظ��ֽڼ� = 0x70,
	�ָ��ֽڼ� = 0x71,
	��ֵ����д = 0x72,
	��ֵ����� = 0x73,
	��ֵ����ʽ�ı� = 0x74,
	ȡʮ�������ı� = 0x75,
	ȡ�˽����ı� = 0x76,
	����ʱ�� = 0x77,
	ȡʱ���� = 0x78,
	ȡĳ������ = 0x79,
	ʱ�䵽�ı� = 0x7A,
	ȡʱ�䲿�� = 0x7B,
	ȡ��� = 0x7C,
	ȡ�·� = 0x7D,
	ȡ�� = 0x7E,
	ȡ���ڼ� = 0x7F,
	ȡСʱ = 0x80,
	ȡ���� = 0x81,
	ȡ�� = 0x82,
	ָ��ʱ�� = 0x83,
	ȡ����ʱ�� = 0x84,
	������ʱ�� = 0x85,
	��Ϣ�� = 0xC0,
	ȡ����ʱ�� = 0xC2,
	���� = 0xC8,
	��ʱ = 0x019F,
	ȡ���� = 0x022F,
	ȡʱ�� = 0x0230,
	�������� = 0x0231,
	��׼��� = 0x0241,
	��׼���� = 0x0242,
	���ֽ� = 0x0275,
	�������� = 0x0276,
	������ = 0x0277,
	�������� = 0x0278,
	��С�� = 0x0279,
	���� = 0x027E,
	���� = 0x027F,
	ʮ������ = 0x029A,
	������ = 0x029B,
};

[LibGuid(KRNLN)]
ref class Krnln : Plugin
{
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateReturn(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Embed)]
	MethodDefinition^ CreateMod(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateIntAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Call)]
	MethodDefinition^ CreateEvenIntAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateLongAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Call)]
	MethodDefinition^ CreateEvenLongAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateDoubleAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Call)]
	MethodDefinition^ CreateEvenDoubleAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Call)]
	MethodDefinition^ CreateEvenAdd(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateSub(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateIntSub(ModuleDefinition^ module);
	[LibMethod(krnln_method::��, EMethodMode::Embed)]
	MethodDefinition^ CreateNeg(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateMul(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateDiv(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateIDiv(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateEqualNull1(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateEqualNull2(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateEqual(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Embed)]
	MethodDefinition^ CreateNotEqualNull1(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Embed)]
	MethodDefinition^ CreateNotEqualNull2(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Embed)]
	MethodDefinition^ CreateNotEqual(ModuleDefinition^ module);
	[LibMethod(krnln_method::С��, EMethodMode::Embed)]
	MethodDefinition^ CreateLess(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateMore(ModuleDefinition^ module);
	[LibMethod(krnln_method::С�ڻ����, EMethodMode::Embed)]
	MethodDefinition^ CreateLessOrEqual(ModuleDefinition^ module);
	[LibMethod(krnln_method::���ڻ����, EMethodMode::Embed)]
	MethodDefinition^ CreateMoreOrEqual(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateAnd(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateOr(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ��, EMethodMode::Embed)]
	MethodDefinition^ CreateNot(ModuleDefinition^ module);
	[LibMethod(krnln_method::λȡ��, EMethodMode::Embed)]
	MethodDefinition^ CreateBnot(ModuleDefinition^ module);
	[LibMethod(krnln_method::λ��, EMethodMode::Embed)]
	MethodDefinition^ CreateBand(ModuleDefinition^ module);
	[LibMethod(krnln_method::λ��, EMethodMode::Embed)]
	MethodDefinition^ CreateBor(ModuleDefinition^ module);
	[LibMethod(krnln_method::λ���, EMethodMode::Embed)]
	MethodDefinition^ CreateBxor(ModuleDefinition^ module);
	[LibMethod(krnln_method::��ֵ, EMethodMode::Embed)]
	MethodDefinition^ CreateSet(ModuleDefinition^ module);
	[LibMethod(krnln_method::����ֵ, EMethodMode::Call)]
	MethodDefinition^ CreateToDouble(ModuleDefinition^ module);
	[LibMethod(krnln_method::���ı�, EMethodMode::Embed)]
	MethodDefinition^ CreateToStr(ModuleDefinition^ module);
	[LibMethod(krnln_method::���ֽ�, EMethodMode::Call)]
	MethodDefinition^ CreateToByte(ModuleDefinition^ module);
	[LibMethod(krnln_method::��������, EMethodMode::Call)]
	MethodDefinition^ CreateToShort(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Call)]
	MethodDefinition^ CreateToInt(ModuleDefinition^ module);
	[LibMethod(krnln_method::��������, EMethodMode::Call)]
	MethodDefinition^ CreateToLong(ModuleDefinition^ module);
	[LibMethod(krnln_method::��С��, EMethodMode::Call)]
	MethodDefinition^ CreateToFloat(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateShl(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateShr(ModuleDefinition^ module);
	[LibMethod(krnln_method::���, EMethodMode::Embed)]
	MethodDefinition^ CreateIfe(ModuleDefinition^ module);
	[LibMethod(krnln_method::�����, EMethodMode::Embed)]
	MethodDefinition^ CreateIf(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ж�, EMethodMode::Embed)]
	MethodDefinition^ CreateSwitch(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ж�ѭ����, EMethodMode::Embed)]
	MethodDefinition^ CreateWhile(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ж�ѭ��β, EMethodMode::Embed)]
	MethodDefinition^ CreateWend(ModuleDefinition^ module);
	[LibMethod(krnln_method::ѭ���ж���, EMethodMode::Embed)]
	MethodDefinition^ CreateDoWhile(ModuleDefinition^ module);
	[LibMethod(krnln_method::ѭ���ж�β, EMethodMode::Embed)]
	MethodDefinition^ CreateLoop(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ƴ�ѭ����, EMethodMode::Embed)]
	MethodDefinition^ CreateCounter(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ƴ�ѭ��β, EMethodMode::Embed)]
	MethodDefinition^ CreateCounterLoop(ModuleDefinition^ module);
	[LibMethod(krnln_method::����ѭ����, EMethodMode::Embed)]
	MethodDefinition^ CreateFor(ModuleDefinition^ module);
	[LibMethod(krnln_method::����ѭ��β, EMethodMode::Embed)]
	MethodDefinition^ CreateNext(ModuleDefinition^ module);
	[LibMethod(krnln_method::����, EMethodMode::Embed)]
	MethodDefinition^ CreateEnd(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ض�������, EMethodMode::Call)]
	MethodDefinition^ CreateReDim(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ�����Ա��, EMethodMode::Call)]
	MethodDefinition^ CreateGetAryElementCount(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ�����±�, EMethodMode::Call)]
	MethodDefinition^ CreateUBound(ModuleDefinition^ module);
	[LibMethod(krnln_method::��������, EMethodMode::Call)]
	MethodDefinition^ CreateCopyAry(ModuleDefinition^ module);
	[LibMethod(krnln_method::�����Ա, EMethodMode::Call)]
	MethodDefinition^ CreateAddElement(ModuleDefinition^ module);
	[LibMethod(krnln_method::�����Ա, EMethodMode::Call)]
	MethodDefinition^ CreateInsElement(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ַ�, EMethodMode::Embed)]
	MethodDefinition^ CreateChr(ModuleDefinition^ module);
	[LibMethod(krnln_method::����д, EMethodMode::Embed)]
	MethodDefinition^ CreateUCase(ModuleDefinition^ module);
	[LibMethod(krnln_method::��Сд, EMethodMode::Embed)]
	MethodDefinition^ CreateLCase(ModuleDefinition^ module);
	[LibMethod(krnln_method::ɾ�׿�, EMethodMode::Embed)]
	MethodDefinition^ CreateLTrim(ModuleDefinition^ module);
	[LibMethod(krnln_method::ɾβ��, EMethodMode::Embed)]
	MethodDefinition^ CreateRTrim(ModuleDefinition^ module);
	[LibMethod(krnln_method::ɾ��β��, EMethodMode::Embed)]
	MethodDefinition^ CreateTrim(ModuleDefinition^ module);
	[LibMethod(krnln_method::ɾȫ����, EMethodMode::Embed)]
	MethodDefinition^ CreateTrimAll(ModuleDefinition^ module);
	[LibMethod(krnln_method::�ı��Ƚ�, EMethodMode::Embed)]
	MethodDefinition^ CreateStrComp(ModuleDefinition^ module);
	[LibMethod(krnln_method::��ʱ��, EMethodMode::Embed)]
	MethodDefinition^ CreateToTime(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡĳ������, EMethodMode::Embed)]
	MethodDefinition^ CreateGetDaysOfSpecMonth(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ���, EMethodMode::Embed)]
	MethodDefinition^ CreateYear(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ�·�, EMethodMode::Embed)]
	MethodDefinition^ CreateMonth(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ��, EMethodMode::Embed)]
	MethodDefinition^ CreateDay(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ���ڼ�, EMethodMode::Embed)]
	MethodDefinition^ CreateWeekDay(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡСʱ, EMethodMode::Embed)]
	MethodDefinition^ CreateHour(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ����, EMethodMode::Embed)]
	MethodDefinition^ CreateMinute(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ��, EMethodMode::Embed)]
	MethodDefinition^ CreateSecond(ModuleDefinition^ module);
	[LibMethod(krnln_method::ָ��ʱ��, EMethodMode::Embed)]
	MethodDefinition^ CreateGetSpecTime(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ����ʱ��, EMethodMode::Embed)]
	MethodDefinition^ CreateNow(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ����, EMethodMode::Embed)]
	MethodDefinition^ CreateGetDatePart(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡʱ��, EMethodMode::Embed)]
	MethodDefinition^ CreateGetTimePart(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡʮ�������ı�, EMethodMode::Embed)]
	MethodDefinition^ CreateGetHexText(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ�˽����ı�, EMethodMode::Embed)]
	MethodDefinition^ CreateGetOctText(ModuleDefinition^ module);
	[LibMethod(krnln_method::ʮ������, EMethodMode::Embed)]
	MethodDefinition^ CreateHex(ModuleDefinition^ module);
	[LibMethod(krnln_method::������, EMethodMode::Embed)]
	MethodDefinition^ CreateBinary(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ�հ��ֽڼ�, EMethodMode::Embed)]
	MethodDefinition^ CreateSpaceBin(ModuleDefinition^ module);
	[LibMethod(krnln_method::ȡ����ʱ��, EMethodMode::Embed)]
	MethodDefinition^ CreateGetTickCount(ModuleDefinition^ module);
	[LibMethod(krnln_method::��ʱ, EMethodMode::Embed)]
	MethodDefinition^ CreateSleep(ModuleDefinition^ module);
	[LibMethod(krnln_method::���)]
	static array<byte>^ ���(array<byte>^ �����ֽڼ�, ...array<array<byte>^>^ ���ֽڼ�);
	[LibMethod(krnln_method::���)]
	static double ���(Nullable<double> ���ӿɿ���, ...array<Nullable<double>>^ �ӿɿ���);
	[LibMethod(krnln_method::���)]
	static double ���(Nullable<double> ���ӿɿ���, ...array<Nullable<double>>^ �ӿɿ���);
	[LibMethod(krnln_method::���)]
	static double ���(Nullable<double> ���ӿɿ���, ...array<Nullable<double>>^ �ӿɿ���);
	[LibMethod(krnln_method::���)]
	static double ���(Nullable<double> ���ӿɿ���, ...array<Nullable<double>>^ �ӿɿ���);
	[LibMethod(krnln_method::���ı�)]
	static String^ ���ı�(array<byte>^ ��ת��������);
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
	[LibMethod(krnln_method::��ȫ��)]
	static String^ ��ȫ��(String^ ���任���ı�);
	[LibMethod(krnln_method::�����)]
	static String^ �����(String^ ���任���ı�);
	[LibMethod(krnln_method::�ı��滻)]
	static String^ �ı��滻(String^ �����滻���ı�, int ��ʼ�滻λ��, int �滻����, [Optional]String^ �����滻���ı�);
	[LibMethod(krnln_method::���ı��滻)]
	static String^ ���ı��滻(String^ �����滻���ı�, String^ �����滻�����ı�, [Optional]String^ �����滻�����ı�, [Optional][DefaultValue(1)]int �����滻����ʼλ��, [Optional]int �滻���еĴ���, bool �Ƿ����ִ�Сд);
	[LibMethod(krnln_method::ȡ�հ��ı�)]
	static String^ ȡ�հ��ı�(int �ظ�����);
	[LibMethod(krnln_method::ȡ�ظ��ı�)]
	static String^ ȡ�ظ��ı�(int �ظ�����, String^ ���ظ��ı�);
	[LibMethod(krnln_method::�ָ��ı�)]
	static array<String^>^ �ָ��ı�(String^ ���ָ��ı�, [Optional][DefaultValue(",")]String^ �����ָ���ı�, [Optional]int Ҫ���ص����ı���Ŀ);
	[LibMethod(krnln_method::����ʱ��)]
	static DateTime ����ʱ��(DateTime ʱ��, int �����Ӳ���, int ����ֵ);
	[LibMethod(krnln_method::ȡʱ����)]
	static double ȡʱ����(DateTime ʱ��1, DateTime ʱ��2, int ȡ�������);
	[LibMethod(krnln_method::ʱ�䵽�ı�)]
	static String^ ʱ�䵽�ı�(DateTime ��ת�����ı���ʱ��, [Optional][DefaultValue(1)]int ת������);
	[LibMethod(krnln_method::ȡʱ�䲿��)]
	static int ȡʱ�䲿��(DateTime ��ȡ�䲿�ֵ�ʱ��, int ת������);
	[LibMethod(krnln_method::������ʱ��)]
	static bool ������ʱ��(DateTime �����õ�ʱ��);
	[LibMethod(krnln_method::��ֵ����д)]
	static String^ ��ֵ����д(double ��ת����ʽ����ֵ, bool �Ƿ�ת��Ϊ����);
	[LibMethod(krnln_method::��ֵ�����)]
	static String^ ��ֵ�����(double ��ת����ʽ����ֵ, bool �Ƿ�ת��Ϊ����);
	[LibMethod(krnln_method::��ֵ����ʽ�ı�)]
	static String^ ��ֵ����ʽ�ı�(double ��ת��Ϊ�ı�����ֵ, [Optional]Nullable<int> С������λ��, bool �Ƿ����ǧ��λ�ָ�);
	[LibMethod(krnln_method::ȡ�ֽڼ�����)]
	static int ȡ�ֽڼ�����(array<byte>^ �ֽڼ�����);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(String^ ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(DateTime ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(IntPtr ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(bool ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(byte ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(short ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(int ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(Int64 ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(float ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::���ֽڼ�)]
	static array<byte>^ ���ֽڼ�(double ��ת��Ϊ�ֽڼ�������);
	[LibMethod(krnln_method::ȡ�ֽڼ�����)]
	static Object^ ȡ�ֽڼ�����(array<byte>^ ��ȡ���������ݵ��ֽڼ�, int ��ȡ�����ݵ�����, [Optional][DefaultValue(1)]int ��ʼ����λ��);
	[LibMethod(krnln_method::ȡ�ֽڼ����)]
	static array<byte>^ ȡ�ֽڼ����(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ȡ���ֽڵ���Ŀ);
	[LibMethod(krnln_method::ȡ�ֽڼ��ұ�)]
	static array<byte>^ ȡ�ֽڼ��ұ�(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ȡ���ֽڵ���Ŀ);
	[LibMethod(krnln_method::ȡ�ֽڼ��м�)]
	static array<byte>^ ȡ�ֽڼ��м�(array<byte>^ ��ȡ�䲿�ֵ��ֽڼ�, int ��ʼȡ��λ��, int ��ȡ���ֽڵ���Ŀ);
	[LibMethod(krnln_method::Ѱ���ֽڼ�)]
	static int Ѱ���ֽڼ�(array<byte>^ ����Ѱ���ֽڼ�, array<byte>^ ��Ѱ�ҵ��ֽڼ�, [Optional][DefaultValue(1)]int ��ʼ��Ѱλ��);
	[LibMethod(krnln_method::�����ֽڼ�)]
	static int �����ֽڼ�(array<byte>^ ����Ѱ���ֽڼ�, array<byte>^ ��Ѱ�ҵ��ֽڼ�, [Optional][DefaultValue(1)]int ��ʼ��Ѱλ��);
	[LibMethod(krnln_method::�ֽڼ��滻)]
	static array<byte>^ �ֽڼ��滻(array<byte>^ ���滻�䲿�ֵ��ֽڼ�, int ��ʼ�滻λ��, int �滻����, [Optional]array<byte>^ �����滻���ֽڼ�);
	[LibMethod(krnln_method::���ֽڼ��滻)]
	static array<byte>^ ���ֽڼ��滻(array<byte>^ �����滻���ֽڼ�, array<byte>^ �����滻�����ֽڼ�, [Optional]array<byte>^ �����滻�����ֽڼ�, [Optional][DefaultValue(1)]int �����滻����ʼλ��, [Optional]int �滻���еĴ���);
	[LibMethod(krnln_method::ȡ�ظ��ֽڼ�)]
	static array<byte>^ ȡ�ظ��ֽڼ�(int �ظ�����, array<byte>^ ���ظ����ֽڼ�);
	[LibMethod(krnln_method::�ָ��ֽڼ�)]
	static array<array<byte>^>^ �ָ��ֽڼ�(array<byte>^ ���ָ��ֽڼ�, [Optional]array<byte>^ �����ָ���ֽڼ�, [Optional]int Ҫ���ص����ֽڼ���Ŀ);
	[LibMethod(krnln_method::��Ϣ��)]
	static int ��Ϣ��(Object^ ��ʾ��Ϣ, int ��ť, [Optional]String^ ���ڱ���, [Optional]IWin32Window^ ������);
	[LibMethod(krnln_method::��׼���)]
	static void ��׼���([Optional][DefaultValue(1)]int �������, ...array<Object^>^ ���������);
	[LibMethod(krnln_method::��׼����)]
	static String^ ��׼����([Optional][DefaultValue(true)]bool �Ƿ����);
};