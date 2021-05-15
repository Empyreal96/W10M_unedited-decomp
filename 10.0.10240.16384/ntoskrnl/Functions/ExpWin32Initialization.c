// ExpWin32Initialization 
 
int ExpWin32Initialization()
{
  int v0; // r0
  int result; // r0
  _BYTE v2[8]; // [sp+0h] [bp-70h] BYREF
  int v3[22]; // [sp+8h] [bp-68h] BYREF

  RtlInitUnicodeString((unsigned int)v2, L"WindowStation");
  memset(v3, 0, sizeof(v3));
  LOWORD(v3[0]) = 88;
  v3[3] = 0x20000;
  v3[4] = 0x20000;
  v3[5] = 0x20000;
  v3[6] = 983040;
  v3[9] = 512;
  v3[14] = (int)ExpWin32CloseProcedure;
  v3[15] = (int)ExpWin32DeleteProcedure;
  v3[19] = (int)ExpWin32OkayToCloseProcedure;
  v3[16] = (int)ExpWin32ParseProcedure;
  v3[13] = (int)ExpWin32OpenProcedure;
  v3[2] = 304;
  v3[7] = 983040;
  BYTE2(v3[0]) = (BYTE2(v3[0]) | 0x18) & 0xBF;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_7;
  RtlInitUnicodeString((unsigned int)v2, L"Desktop");
  v3[16] = 0;
  v3[3] = 0x20000;
  v3[4] = 0x20000;
  v3[5] = 0x20000;
  v3[6] = 983040;
  BYTE2(v3[0]) |= 0x40u;
  if ( ObCreateObjectType() < 0 )
    goto LABEL_7;
  RtlInitUnicodeString((unsigned int)v2, L"Composition");
  v3[16] = 0;
  BYTE2(v3[0]) |= 2u;
  v3[3] = 0x20000;
  v3[4] = 0x20000;
  v3[5] = 0x20000;
  v3[6] = 983040;
  v3[1] = 1024;
  BYTE2(v3[0]) &= 0xBFu;
  v0 = ObCreateObjectType();
  v3[1] = 0;
  if ( v0 < 0 )
    goto LABEL_7;
  RtlInitUnicodeString((unsigned int)v2, L"RawInputManager");
  BYTE2(v3[0]) |= 2u;
  v3[16] = 0;
  v3[3] = 0x20000;
  v3[4] = 0x20000;
  v3[5] = 0x20000;
  v3[6] = 983040;
  BYTE2(v3[0]) &= 0xBFu;
  if ( ObCreateObjectType() < 0 )
LABEL_7:
    result = 0;
  else
    result = 1;
  return result;
}
