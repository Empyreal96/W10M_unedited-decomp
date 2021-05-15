// MmRemoveSystemCacheFromDump 
 
int __fastcall MmRemoveSystemCacheFromDump(int result)
{
  _DWORD *v1; // r4
  unsigned int v2; // r2
  int v3; // r8
  int v4; // r4
  unsigned int v5; // r1
  unsigned int v6; // r9
  unsigned int i; // r7
  unsigned int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // [sp+0h] [bp-28h]
  int v13; // [sp+4h] [bp-24h]

  v1 = (_DWORD *)dword_634E5C;
  v12 = dword_634E5C;
  v13 = result;
  if ( (KiBugCheckActive & 3) != 0 || (v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, dword_63437C == v2) )
  {
    v3 = 17;
  }
  else
  {
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockSharedAtDpcLevelInstrumented(dword_634E00);
    }
    else
    {
      v4 = dword_634E00[0] & 0x7FFFFFFF;
      v5 = (dword_634E00[0] & 0x7FFFFFFF) + 1;
      do
        result = __ldrex(dword_634E00);
      while ( result == v4 && __strex(v5, dword_634E00) );
      __dmb(0xBu);
      if ( result != v4 )
        result = ExpWaitForSpinLockSharedAndAcquire(dword_634E00);
      v1 = (_DWORD *)v12;
    }
  }
  v6 = v1[2];
  for ( i = 1; i <= v6; ++i )
  {
    v8 = *(_DWORD *)(v1[9] * i + v1[63]);
    if ( (v8 & 1) != 0 )
    {
      v9 = *(_DWORD *)(((v8 >> 10) & 0x3FFFFC) - 0x40000000);
      if ( (v9 & 2) != 0 && (*(_DWORD *)(MmPfnDatabase + 24 * (v9 >> 12) + 12) & 0x3FFFFFFF) == 1 )
      {
        result = (*(int (__fastcall **)(int, unsigned int, int, int))(v13 + 4))(v13, v9 >> 12, 1, 2);
        v1 = (_DWORD *)v12;
      }
    }
  }
  if ( v3 != 17 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(dword_634E00);
    }
    else
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(dword_634E00);
      while ( __strex(v10 & 0xBFFFFFFF, dword_634E00) );
      __dmb(0xBu);
      do
        v11 = __ldrex(dword_634E00);
      while ( __strex(v11 - 1, dword_634E00) );
    }
    result = KfLowerIrql(v3);
  }
  return result;
}
