// MmEnableProcessSvm 
 
int MmEnableProcessSvm()
{
  int v0; // r6
  unsigned int *v1; // r4
  int v2; // r7
  unsigned __int8 *v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r1

  v0 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v1 = (unsigned int *)(v0 + 492);
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v0 + 492));
  }
  else
  {
    v4 = (unsigned __int8 *)(v0 + 495);
    do
      v5 = __ldrex(v4);
    while ( __strex(v5 | 0x80, v4) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v0 + 492));
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
  *(_BYTE *)(v0 + 607) |= 8u;
  return MiUnlockWorkingSetExclusive(v0 + 492, v2);
}
