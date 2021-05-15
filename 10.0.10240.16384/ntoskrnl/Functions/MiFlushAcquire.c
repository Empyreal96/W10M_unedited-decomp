// MiFlushAcquire 
 
int __fastcall MiFlushAcquire(int a1, int a2, int a3)
{
  unsigned int *v4; // r4
  int v7; // r10
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  int v12; // r5
  unsigned int v13; // r1

  v4 = (unsigned int *)(a1 + 36);
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_520508();
  v9 = (unsigned __int8 *)v4 + 3;
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 | 0x80, v9) );
  __dmb(0xBu);
  if ( v10 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v4);
  while ( 1 )
  {
    v11 = *v4;
    if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v11 & 0x40000000) == 0 )
    {
      do
        v13 = __ldrex(v4);
      while ( v13 == v11 && __strex(v11 | 0x40000000, v4) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( *(_DWORD *)(a1 + 20) == -1 )
  {
    v12 = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
  }
  else
  {
    if ( a2 )
    {
      MiReferenceSubsection(a2);
      MiReferenceSubsection(a3);
    }
    ++*(_DWORD *)(a1 + 20);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    v12 = 1;
  }
  KfLowerIrql(v7);
  return v12;
}
