// AslStringAnsiToUnicode 
 
int __fastcall AslStringAnsiToUnicode(_DWORD *a1, unsigned int a2)
{
  int v3; // r0
  int v4; // r1
  int v5; // r2
  unsigned int v6; // r5
  int v7; // r4
  unsigned int v8; // r0
  int v9; // r0
  _BYTE *v10; // r3
  unsigned __int16 v12; // [sp+8h] [bp-20h] BYREF
  __int16 v13; // [sp+Ah] [bp-1Eh]
  _BYTE *v14; // [sp+Ch] [bp-1Ch]
  unsigned __int16 v15[12]; // [sp+10h] [bp-18h] BYREF

  v3 = RtlInitAnsiString((unsigned int)v15, a2);
  if ( NlsMbCodePageTag )
  {
    v3 = RtlxOemStringToUnicodeSize(v15, v4, v5, (unsigned __int8)NlsMbCodePageTag);
    v6 = v3;
  }
  else
  {
    v6 = 2 * (v15[0] + 1);
  }
  v12 = 0;
  v13 = 0;
  v14 = 0;
  *a1 = 0;
  if ( v6 > 0xFFFF )
  {
    v7 = -1073741811;
    AslLogCallPrintf(1, (int)"AslStringAnsiToUnicode", 383, "Ansi string is too long to convert at %d", v6);
LABEL_6:
    v8 = (unsigned int)v14;
    goto LABEL_12;
  }
  v14 = AslAlloc(v3, v6);
  if ( !v14 )
  {
    v7 = -1073741801;
    AslLogCallPrintf(1, (int)"AslStringAnsiToUnicode", 390, "Out of memory");
    goto LABEL_6;
  }
  v12 = 0;
  v13 = v6;
  v9 = RtlAnsiStringToUnicodeString(&v12, v15, 0, 0);
  v7 = v9;
  if ( v9 < 0 )
  {
    AslLogCallPrintf(1, (int)"AslStringAnsiToUnicode", 399, "RtlAnsiStringToUnicodeString failed [%x]", v9);
    goto LABEL_6;
  }
  v10 = v14;
  v8 = 0;
  v14 = 0;
  *a1 = v10;
  v7 = 0;
LABEL_12:
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v7;
}
