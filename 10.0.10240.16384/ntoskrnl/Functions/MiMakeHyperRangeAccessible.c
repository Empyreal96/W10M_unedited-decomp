// MiMakeHyperRangeAccessible 
 
int __fastcall MiMakeHyperRangeAccessible(unsigned int a1, unsigned int a2, unsigned int *a3)
{
  unsigned int *v3; // r9
  unsigned int v4; // r8
  unsigned int v5; // r5
  int v6; // r6
  unsigned int v7; // r7
  unsigned int v8; // r4
  int v10; // t1
  __int16 *v11; // r0

  *a3 = 0;
  v3 = a3;
  v4 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = 0;
  v6 = 0;
  v7 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  while ( 1 )
  {
    v8 = v4;
    if ( v4 <= v7 )
    {
      do
      {
        if ( !*(_DWORD *)(((v8 >> 10) & 0x3FFFFC) - 0x40000000) )
          return sub_7F55D8();
        v10 = *(_DWORD *)v8;
        v8 += 4;
        if ( !v10 )
        {
          if ( v6 )
            MiWriteDemandZeroPte((_DWORD *)(v8 - 4));
          else
            ++v5;
        }
      }
      while ( v8 <= v7 );
      v3 = a3;
    }
    if ( !v6 )
    {
      if ( v5 )
      {
        __mrc(15, 0, 13, 0, 3);
        v11 = MiGetThreadPartition();
        if ( !MiChargeCommit((int)v11, v5, 0) )
          break;
      }
    }
    if ( (unsigned int)++v6 >= 2 )
    {
      *v3 = v5;
      return 0;
    }
  }
  return -1073741523;
}
