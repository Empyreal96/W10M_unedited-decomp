// MiEndingOffsetWithLock 
 
int __fastcall MiEndingOffsetWithLock(_DWORD *a1)
{
  unsigned int *v2; // r5
  int v3; // r7
  int v5; // r4
  unsigned int v6; // r1
  int v7; // r6
  unsigned int v8; // r1
  unsigned int v9; // r2

  v2 = (unsigned int *)(*a1 + 36);
  v3 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_544C1C();
  v5 = *v2 & 0x7FFFFFFF;
  do
    v6 = __ldrex(v2);
  while ( v6 == v5 && __strex(v5 + 1, v2) );
  __dmb(0xBu);
  if ( v6 != v5 )
    ExpWaitForSpinLockSharedAndAcquire(v2);
  v7 = MiEndingOffset(a1);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v2);
  }
  else
  {
    __dmb(0xBu);
    do
      v8 = __ldrex(v2);
    while ( __strex(v8 & 0xBFFFFFFF, v2) );
    __dmb(0xBu);
    do
      v9 = __ldrex(v2);
    while ( __strex(v9 - 1, v2) );
  }
  KfLowerIrql(v3);
  return v7;
}
