// MiStartingOffsetNeedLock 
 
int __fastcall MiStartingOffsetNeedLock(_DWORD *a1)
{
  int v2; // r4
  int v3; // r6
  int v4; // r7
  unsigned int *v6; // r5
  int v7; // r0
  unsigned int v8; // r1
  unsigned int *v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2

  v2 = *a1;
  if ( (*(_DWORD *)(*a1 + 28) & 0x20) != 0 || !*(_DWORD *)(v2 + 32) )
  {
    v3 = 17;
  }
  else
  {
    v6 = (unsigned int *)(v2 + 36);
    v3 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_5456E4();
    v7 = *v6 & 0x7FFFFFFF;
    do
      v8 = __ldrex(v6);
    while ( v8 == v7 && __strex(v7 + 1, v6) );
    __dmb(0xBu);
    if ( v8 != v7 )
      ExpWaitForSpinLockSharedAndAcquire((unsigned int *)(v2 + 36));
  }
  v4 = MiStartingOffset(a1, a1[1]);
  if ( v3 != 17 )
  {
    v9 = (unsigned int *)(v2 + 36);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v9);
    }
    else
    {
      __dmb(0xBu);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 & 0xBFFFFFFF, v9) );
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( __strex(v11 - 1, v9) );
    }
    KfLowerIrql(v3);
  }
  return v4;
}
