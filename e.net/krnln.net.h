#pragma once
#include "efs.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace Mono::Cecil;
using namespace Mono::Cecil::Cil;

enum krnln_method : UINT
{
	��� = 0x00,
	����� = 0x01,
	�ж� = 0x02,
	���� = 0x0D,
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
	����ֵ = 0x59,
	���ı� = 0x5A,
	���ֽ� = 0x0275,
	�������� = 0x0276,
	������ = 0x0277,
	�������� = 0x0278,
	��С�� = 0x0279,
	���� = 0x027E,
	���� = 0x027F,
	�ض�������
};

MethodDefinition^ CreateMethod(String^ name, TypeReference^ returntype, IList<ParameterDefinition^>^ params = nullptr, MethodAttributes attr = MethodAttributes::HideBySig);
ParameterDefinition^ CreateParameter(String^ name, TypeReference^ type, ParameterAttributes attr = ParameterAttributes::None);
MethodDefinition^ CreateReturn(ModuleDefinition^ module);
MethodDefinition^ CreateMod(ModuleDefinition^ module);
MethodDefinition^ CreateAdd(ModuleDefinition^ module);
MethodDefinition^ CreateEvenAdd(ModuleDefinition^ module);
MethodDefinition^ CreateIntAdd(ModuleDefinition^ module);
MethodDefinition^ CreateEvenIntAdd(ModuleDefinition^ module);
MethodDefinition^ CreateLongAdd(ModuleDefinition^ module);
MethodDefinition^ CreateEvenLongAdd(ModuleDefinition^ module);
MethodDefinition^ CreateDoubleAdd(ModuleDefinition^ module);
MethodDefinition^ CreateEvenDoubleAdd(ModuleDefinition^ module);
MethodDefinition^ CreateEvenBinAdd(ModuleDefinition^ module);
MethodDefinition^ CreateSub(ModuleDefinition^ module);
MethodDefinition^ CreateIntSub(ModuleDefinition^ module);
MethodDefinition^ CreateNeg(ModuleDefinition^ module);
MethodDefinition^ CreateMul(ModuleDefinition^ module);
MethodDefinition^ CreateDiv(ModuleDefinition^ module);
MethodDefinition^ CreateIDiv(ModuleDefinition^ module);
MethodDefinition^ CreateEqual(ModuleDefinition^ module);
MethodDefinition^ CreateNotEqual(ModuleDefinition^ module);
MethodDefinition^ CreateLess(ModuleDefinition^ module);
MethodDefinition^ CreateMore(ModuleDefinition^ module);
MethodDefinition^ CreateLessOrEqual(ModuleDefinition^ module);
MethodDefinition^ CreateMoreOrEqual(ModuleDefinition^ module);
MethodDefinition^ CreateAnd(ModuleDefinition^ module);
MethodDefinition^ CreateOr(ModuleDefinition^ module);
MethodDefinition^ CreateNot(ModuleDefinition^ module);
MethodDefinition^ CreateBnot(ModuleDefinition^ module);
MethodDefinition^ CreateBand(ModuleDefinition^ module);
MethodDefinition^ CreateBor(ModuleDefinition^ module);
MethodDefinition^ CreateBxor(ModuleDefinition^ module);
MethodDefinition^ CreateSet(ModuleDefinition^ module);
MethodDefinition^ CreateToDouble(ModuleDefinition^ module);
MethodDefinition^ CreateToStr(ModuleDefinition^ module);
MethodDefinition^ CreateToByte(ModuleDefinition^ module);
MethodDefinition^ CreateToShort(ModuleDefinition^ module);
MethodDefinition^ CreateToInt(ModuleDefinition^ module);
MethodDefinition^ CreateToLong(ModuleDefinition^ module);
MethodDefinition^ CreateToFloat(ModuleDefinition^ module);
MethodDefinition^ CreateShl(ModuleDefinition^ module);
MethodDefinition^ CreateShr(ModuleDefinition^ module);
MethodDefinition^ CreateIfe(ModuleDefinition^ module);
MethodDefinition^ CreateIf(ModuleDefinition^ module);
MethodDefinition^ CreateSwitch(ModuleDefinition^ module);
MethodDefinition^ CreateWhile(ModuleDefinition^ module);
MethodDefinition^ CreateWend(ModuleDefinition^ module);
MethodDefinition^ CreateDoWhile(ModuleDefinition^ module);
MethodDefinition^ CreateLoop(ModuleDefinition^ module);
MethodDefinition^ CreateCounter(ModuleDefinition^ module);
MethodDefinition^ CreateCounterLoop(ModuleDefinition^ module);
MethodDefinition^ CreateFor(ModuleDefinition^ module);
MethodDefinition^ CreateNext(ModuleDefinition^ module);