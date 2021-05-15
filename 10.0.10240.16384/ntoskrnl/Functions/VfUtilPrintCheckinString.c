// VfUtilPrintCheckinString 
 
int __fastcall VfUtilPrintCheckinString(unsigned __int16 *a1)
{
  unsigned int v1; // r8
  unsigned int v2; // r6
  unsigned int v3; // r7
  int v4; // r5
  char v5; // r0
  unsigned int v6; // r4
  _WORD *v7; // r7
  int v8; // r6
  int result; // r0
  unsigned int i; // r5
  unsigned int v11; // r0
  unsigned int v12; // r3
  int v13; // [sp+10h] [bp-80h]
  int v14[4]; // [sp+18h] [bp-78h] BYREF
  _WORD v15[52]; // [sp+28h] [bp-68h] BYREF

  v14[0] = -268425216;
  v14[1] = MmVerifierData;
  v14[2] = 0;
  v14[3] = 134957056 * (MmVerifierData + 1);
  v1 = *a1 >> 1;
  v2 = v1;
  if ( v1 < 0x10 )
    v2 = 16;
  v3 = 0;
  if ( v2 )
  {
    v13 = *((_DWORD *)a1 + 1);
    do
    {
      v4 = v3 & 0xF;
      if ( !v1 )
        __brkdiv0();
      v5 = RtlUpcaseUnicodeChar(*(unsigned __int16 *)(v13 + 2 * (v3 % v1)));
      ++v3;
      *((_BYTE *)v14 + v4) ^= v5;
    }
    while ( v3 < v2 );
  }
  v6 = 0;
  v7 = v15;
  while ( 1 )
  {
    v8 = 1;
    result = 0;
    for ( i = 0; i < 0x10; ++i )
    {
      v11 = *((unsigned __int8 *)v14 + i) + (result << 8);
      v12 = v11 / 0x3E;
      result = v11 % 0x3E;
      *((_BYTE *)v14 + i) = v12;
      if ( (_BYTE)v12 )
        v8 = 0;
    }
    ++v6;
    *v7++ = Printable[result];
    if ( v6 >= 0x21 )
      break;
    if ( v8 )
    {
      if ( 2 * v6 >= 0x42 )
        _report_rangecheckfailure();
      v15[v6] = 0;
      return VfUtilDbgPrint((int)"Driver Verifier: Enabled for %wZ, flags 0x%x, build %ld, key %wZ\n");
    }
  }
  return result;
}
