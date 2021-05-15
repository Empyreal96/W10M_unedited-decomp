// IoCheckQuotaBufferValidity 
 
int __fastcall IoCheckQuotaBufferValidity(int a1, unsigned int a2, _DWORD *a3)
{
  unsigned int v3; // r5
  int v5; // r7
  int v6; // r4
  int result; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r3

  v3 = a2;
  v5 = a1;
  v6 = a1;
  if ( a2 > 0x7FFFFFFF )
  {
    result = -2147483628;
    goto LABEL_5;
  }
  if ( (a1 & 7) != 0 )
  {
    result = -2147483646;
LABEL_5:
    v8 = 0;
LABEL_17:
    *a3 = v8;
    return result;
  }
  while ( 1 )
  {
    if ( v3 < 0x34
      || !RtlValidSid((_BYTE *)(v6 + 40))
      || (v9 = RtlLengthSid(v6 + 40), v3 < v9 + 40)
      || *(_DWORD *)(v6 + 4) != v9 )
    {
LABEL_16:
      result = -1073741210;
      v8 = v6 - v5;
      goto LABEL_17;
    }
    v10 = *(_DWORD *)v6;
    if ( !*(_DWORD *)v6 )
      return 0;
    if ( v9 + 40 > (unsigned int)v10 || (v10 & 7) != 0 || v10 < 0 || v3 < v10 )
      goto LABEL_16;
    v3 -= v10;
    v6 += v10;
  }
}
