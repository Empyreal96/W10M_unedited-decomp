// AslStringUpcaseToMultiByteN 
 
int __fastcall AslStringUpcaseToMultiByteN(int a1, int a2, unsigned __int16 *a3)
{
  unsigned int v4; // r0
  __int16 v5; // r4
  int v7; // r4
  unsigned __int16 v8; // [sp+8h] [bp-20h] BYREF
  __int16 v9; // [sp+Ah] [bp-1Eh]
  unsigned int v10; // [sp+Ch] [bp-1Ch]
  unsigned __int16 v11; // [sp+10h] [bp-18h] BYREF
  __int16 v12; // [sp+12h] [bp-16h]
  int v13; // [sp+14h] [bp-14h]
  _DWORD v14[4]; // [sp+18h] [bp-10h] BYREF

  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14[0] = 0;
  v14[1] = 0;
  v8 = 0;
  v9 = 0;
  v4 = RtlInitUnicodeString((unsigned int)v14, a3);
  v5 = HIWORD(v14[0]);
  v10 = AslAlloc(v4, HIWORD(v14[0]));
  if ( !v10 )
    return sub_7CCF40();
  v8 = 0;
  v9 = v5;
  v7 = RtlUpcaseUnicodeString(&v8, (unsigned __int16 *)v14, 0, 0);
  if ( v7 < 0 )
  {
    AslLogCallPrintf(1, "AslStringUpcaseToMultiByteN", 723, "RtlUpcaseUnicodeString failed [%x]", v7);
  }
  else
  {
    v12 = 256;
    v11 = 0;
    v13 = a1;
    v7 = RtlUnicodeStringToAnsiString(&v11, &v8, 0, 0);
    if ( v7 < 0 )
    {
      AslLogCallPrintf(1, "AslStringUpcaseToMultiByteN", 738, "RtlUnicodeStringToAnsiString failed [%x]", v7);
    }
    else
    {
      v7 = 0;
      *(_BYTE *)(v11 + a1) = 0;
    }
  }
  if ( v10 )
    ExFreePoolWithTag(v10);
  return v7;
}
