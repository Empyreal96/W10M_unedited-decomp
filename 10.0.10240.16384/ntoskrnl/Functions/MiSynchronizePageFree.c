// MiSynchronizePageFree 
 
int __fastcall MiSynchronizePageFree(int a1)
{
  unsigned int *v1; // r4
  int v2; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  v1 = (unsigned int *)(a1 + 492);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v1);
  }
  else
  {
    v4 = (unsigned __int8 *)v1 + 3;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v1);
    while ( 1 )
    {
      v6 = *v1;
      if ( (*v1 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v6 & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex(v1);
        while ( v7 == v6 && __strex(v6 | 0x40000000, v1) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  return MiUnlockWorkingSetExclusive((int)v1, v2);
}
