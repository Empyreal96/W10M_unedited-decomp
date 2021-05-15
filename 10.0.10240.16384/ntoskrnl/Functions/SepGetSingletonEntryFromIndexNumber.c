// SepGetSingletonEntryFromIndexNumber 
 
int __fastcall SepGetSingletonEntryFromIndexNumber(unsigned int a1)
{
  unsigned int v1; // r6
  int v2; // r7
  unsigned int *v3; // r4
  int v4; // r5
  int v5; // r10
  int v7; // r0
  unsigned int v8; // r1
  unsigned int *v9; // r0
  unsigned int v10; // r1
  unsigned int v11; // r2

  v1 = a1 >> 6;
  v2 = a1 & 0x3F;
  v3 = (unsigned int *)SepSingletonGlobal;
  v4 = 0;
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52AF7C();
  v7 = *v3 & 0x7FFFFFFF;
  do
    v8 = __ldrex(v3);
  while ( v8 == v7 && __strex(v7 + 1, v3) );
  __dmb(0xBu);
  if ( v8 != v7 )
    ExpWaitForSpinLockSharedAndAcquire(v3);
  v9 = (unsigned int *)SepSingletonGlobal;
  if ( v1 < SepSingletonGlobal[1] )
    v4 = *(_DWORD *)(SepSingletonGlobal[2] + 4 * v1) + 24 * v2;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(SepSingletonGlobal);
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
  KfLowerIrql(v5);
  return v4;
}
