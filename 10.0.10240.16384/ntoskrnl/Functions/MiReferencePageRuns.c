// MiReferencePageRuns 
 
int __fastcall MiReferencePageRuns(int a1, int a2)
{
  unsigned int *v3; // r5
  int v5; // r10
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  int v10; // r4
  unsigned int v11; // r1

  v3 = (unsigned int *)(a1 + 168);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_513B6C();
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
  if ( a2 == 1 )
  {
    v10 = *(_DWORD *)(a1 + 32);
  }
  else if ( (__int16 *)a1 == MiSystemPartition )
  {
    v10 = MmPhysicalMemoryBlock;
  }
  else
  {
    v10 = *(_DWORD *)(a1 + 116);
  }
  if ( v10 )
    ++*(_DWORD *)(v10 - 4);
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
  if ( !v10 )
    v10 = MiReferencePageRuns(MiSystemPartition, a2);
  return v10;
}
