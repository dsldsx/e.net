//��Դ��ṹ
#pragma once

using namespace std;

enum ECode_Head : byte
{
	Call = 0x6A,
	Ife = 0x6B,
	If = 0x6C,
	Switch = 0x6E,
	LoopBegin = 0x70,
	LoopEnd = 0x71
};

enum class ECode_Type : byte
{
	ParamBegin = 0x36,
	ParamEnd = 0x01,
	NullParam = 0x16,
	NumberConst = 0x17,
	BoolConst = 0x18,
	DatetimeConst = 0x19,
	StringConst = 0x1A,
	Const = 0x1B,
	LibConst = 0x1C,
	Variable = 0x1D,
	n4 = 0x1E,
	BinConst = 0x1F,
	BinEnd = 0x20,
	Method = 0x21,
	ParameterBegin = 0x38,
	ParameterEnd = 0x37,
	Field = 0x39,
	ArrayBegin = 0x3A,
	NumberIndex = 0x3B
};

enum class EProcess_Tag : byte
{
	Else = 0x50,
	IfeEnd = 0x51,
	IfEnd = 0x52,
	Case = 0x53,
	SwitchEnd = 0x54
};

enum ECode_Method : UINT
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
	���� = 0x027F
};

enum FileType : UINT
{
	E = 0x01,
	EC = 0x03
};

enum CompileType : UINT
{
	WindowsForm = 0x00,
	WindowsConsole = 0x01,
	WindowsDLL = 0x02,
	WindowsEC = 0x03E8,
	LinuxConsole = 0x2710,
	LinuxEC = 0x2AF8
};

enum DataType : UINT
{
	EDT_VOID = _SDT_NULL,
	EDT_ALL = _SDT_ALL,
	EDT_BYTE = SDT_BYTE,
	EDT_SHORT = SDT_SHORT,
	EDT_INT = SDT_INT,
	EDT_LONG = SDT_INT64,
	EDT_FLOAT = SDT_FLOAT,
	EDT_DOUBLE = SDT_DOUBLE,
	EDT_BOOL = SDT_BOOL,
	EDT_DATETIME = SDT_DATE_TIME,
	EDT_TEXT = SDT_TEXT,
	EDT_BIN = SDT_BIN,
	EDT_SUBPTR = SDT_SUB_PTR
};

enum ETYPE : byte
{
	StaticClass = 0x09,
	Class = 0x49,
	Struct = 0x41,
	Variable = 0x25,
	Field = 0x15,
	GlobalField = 0x05,
	Method = 0x04
};

enum EMethodAttr : UINT
{
	Public = 0x08
};

enum EVariableAttr : USHORT
{
	Out = 0x02,
	Optional = 0x04,
	Array = 0x08
};

enum class ETagStatus : UINT
{
	None = 0x00,
	Public = 0x01,
	Extern = 0x02
};

struct ETAG
{
	USHORT ID;
	byte Type1;
	ETYPE Type2;
	ETAG();
	ETAG(UINT uint);
	ETAG* operator=(UINT uint);
	bool operator==(ETAG tag);
	bool operator!=(ETAG tag);
	bool operator==(ECode_Method code);
	bool operator!=(ECode_Method code);
	bool operator==(UINT uint);
	bool operator!=(UINT uint);
	bool operator==(int uint);
	bool operator!=(int uint);
	operator ECode_Method();
};

struct EFieldInfo
{
	ETAG Class;
	ETAG Field;
	EFieldInfo();
	EFieldInfo(UINT64 uint);
	operator UINT64();
};

struct EFile_Header
{
	byte Magic1[4];
	byte Magic2[4];
};

struct ESection_Header
{
	byte Magic[4];
	UINT Info_CheckSum;
};

struct ESection_Info
{
	byte Key[4];
	byte Name[30];
	short reserve_fill_1;
	UINT Index;
	UINT CodeType;
	UINT Data_CheckSum;
	UINT DataLength;
	int reserve_item[10];
};

struct ESection_SystemInfo
{
	USHORT Version1;
	USHORT Version2;
	int Unknow_1;
	int Unknow_2;
	int Unknow_3;
	FileType FileType;
	int Unknow_4;
	CompileType CompileType;
	int Unknow_5[8];
};

struct ESection_UserInfo
{
	string ProjectName;
	string Remark;
	string Author;
	UINT Major;
	UINT Minor;
	UINT Build;
	UINT Revision;
	string PluginName;
};

struct ESection_ArrayInfo
{
	byte Dimension;
	vector<UINT> Subscript;
};

struct ESection_Variable
{
	ETAG Tag;
	DataType DataType;
	EVariableAttr Attributes;
	ESection_ArrayInfo ArrayInfo;
	string Name;
	string Remark;
	ESection_Variable();
	ESection_Variable(nullptr_t);
	ESection_Variable* operator=(nullptr_t);
	bool operator==(nullptr_t);
	bool operator!=(nullptr_t);
};

struct ESection_Program_Assembly
{
	ETAG Tag;
	bool Public;
	ETAG Base;
	string Name;
	string Remark;
	vector<ETAG> Methods;
	vector<ESection_Variable> Variables;
	ESection_Program_Assembly();
	ESection_Program_Assembly(nullptr_t);
	bool operator==(nullptr_t);
	bool operator!=(nullptr_t);
};

struct ESection_Program_Method
{
	ETAG Tag;
	ETAG Class;
	EMethodAttr Attributes;
	DataType ReturnType;
	string Name;
	string Remark;
	vector<ESection_Variable> Variables;
	vector<ESection_Variable> Parameters;
	vector<byte> RowsOffset;
	vector<byte> Offset1;
	vector<byte> Offset2;
	vector<byte> ParameterOffset;
	vector<byte> VariableOffset;
	vector<byte> Code;
	ESection_Program_Method();
	ESection_Program_Method(nullptr_t);
	bool operator==(nullptr_t);
	bool operator!=(nullptr_t);
};

struct ESection_Program_Dll
{
	ETAG tag;
	bool Public;
	DataType ReturnType;
	string ShowName;
	string Remark;
	string Lib;
	string Name;
	vector<ESection_Variable> Parameters;
};

struct ESection_Program
{
	vector<string> Libraries;
	vector<ESection_Program_Assembly> Assemblies;
	vector<ESection_Program_Assembly> ReferAssemblies;
	vector<ESection_Program_Method> Methods;
	vector<ESection_Program_Method> ReferMethods;
	vector<ESection_Variable> GlobalVariables;
	vector<ESection_Program_Assembly> Structs;
	vector<ESection_Program_Assembly> ReferStructs;
	vector<ESection_Program_Dll> Dlls;
};

struct ESection_TagStatus
{
	ETAG Tag;
	ETagStatus Status;
};

struct ESection_AuxiliaryInfo2
{
	vector<ESection_TagStatus> Tags;
};

const byte Magic1[4] = { 'C', 'N', 'W', 'T' };
const byte Magic2[4] = { 'E', 'P', 'R', 'G' };
const byte Magic_Section[4] = { 0x19, 0x73, 0x11, 0x15 };
const byte KEY[4] = { 25, 115, 0, 7 };

#define KRNLN "krnln"
#define E_NET "e_net"
#define SP "\r"
#define DONET "@donet"
#define DONET_NAMESPACE "@namespace"
#define DONET_CLASS "@class"
#define ETAG2UINT(etag) (UINT)MAKELONG(etag.ID, MAKEWORD(etag.Type1, etag.Type2))

void Decode_Str(byte data[], const byte key[]);
ESection_UserInfo GetUserInfo(byte* pointer);
ESection_Program GetLibraries(byte* pointer);