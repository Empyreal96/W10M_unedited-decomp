// MiPrepareSegmentForDeletion 
 
int __fastcall MiPrepareSegmentForDeletion(int a1, int a2)
{
  unsigned int *v3; // r5
  int v5; // r8
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r6
  unsigned int v11; // r1

  v3 = (unsigned int *)(a1 + 36);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53E570();
  v7 = (unsigned __int8 *)v3 + 3;
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 | 0x80, v7) );
  __dmb(0xBu);
  if ( v8 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v3);
  while ( 1 )
  {
    v9 = *v3;
    if ( (*v3 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v9 & 0x40000000) == 0 )
    {
      do
        v11 = __ldrex(v3);
      while ( v11 == v9 && __strex(v9 | 0x40000000, v3) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  MiDrainControlAreaWrites(a1, v5);
  MiRemoveUnusedSegment(a1);
  v10 = MiBuildWakeList(a1, 1);
  while ( a2 )
  {
    if ( (*(_WORD *)(a2 + 18) & 8) != 0 )
      MiRemoveUnusedSubsection(a2);
    ++*(_DWORD *)(a2 + 60);
    a2 = *(_DWORD *)(a2 + 8);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v5);
  return v10;
}
