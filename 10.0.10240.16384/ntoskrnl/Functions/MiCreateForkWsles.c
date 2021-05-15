// MiCreateForkWsles 
 
int MiCreateForkWsles()
{
  unsigned int *v0; // r4
  unsigned int v1; // r7
  int v2; // r6
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  v0 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  v1 = (((((unsigned int)(dword_63389C - 1) >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v0);
  }
  else
  {
    v4 = (unsigned __int8 *)v0 + 3;
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v0);
    while ( 1 )
    {
      v6 = *v0;
      if ( (*v0 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v6 & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex(v0);
        while ( v7 == v6 && __strex(v6 | 0x40000000, v0) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  MiCreateForkWsle((int)v0, v2, 0xC0300000, v1 - 0x40000000, 1u);
  return MiUnlockWorkingSetExclusive((int)v0, v2);
}
