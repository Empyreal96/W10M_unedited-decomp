// MiLogRelocationRva 
 
unsigned int *__fastcall MiLogRelocationRva(unsigned int a1, int a2, int a3, _DWORD *a4)
{
  __int16 v5; // r7
  unsigned int *result; // r0
  int v8; // r5
  unsigned int v9; // r6
  _DWORD *v10; // r1
  int v11; // r2
  unsigned int v12; // r4
  unsigned int v13; // r5
  __int64 v14[5]; // [sp+8h] [bp-28h] BYREF

  v5 = a1;
  result = MiOffsetToProtos(a4, a1, (int)v14);
  if ( result )
  {
    v9 = ((v14[0] << 12) + __PAIR64__(result[5] >> 23, result[5] << 9)) >> 32;
    v8 = (LODWORD(v14[0]) << 12) + (result[5] << 9);
    result = (unsigned int *)&PfKernelGlobals;
    if ( PfSnNumActiveTraces || dword_643B70 )
    {
      v10 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v11 = (v10[240] >> 9) & 7;
      if ( (*(_DWORD *)(v10[84] + 192) & 0x100000) != 0 )
        v11 = 0;
      if ( v11 >= 2 )
        goto LABEL_6;
      if ( v10 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v10[250] )
        v11 = 2;
      if ( v11 >= 2 )
      {
LABEL_6:
        v12 = ((v5 & 0xFFFu) + a2 + 4095) >> 12;
        if ( (v8 & 0xFFF) != 0 )
          ++v12;
        v13 = v8 & 0xFFFFF000;
        if ( dword_643B70 )
        {
          result = (unsigned int *)sub_7D4F28();
        }
        else if ( PfSnNumActiveTraces && v12 )
        {
          do
          {
            result = (unsigned int *)PfSnLogPageFault(a3, (int)v10, v13, v9, 2);
            v9 = (__PAIR64__(v9, v13) + 4096) >> 32;
            v13 += 4096;
            --v12;
          }
          while ( v12 );
        }
      }
    }
  }
  return result;
}
