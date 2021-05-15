// MiWaitForForkToComplete 
 
int __fastcall MiWaitForForkToComplete(int a1, int a2)
{
  int v3; // r6
  unsigned int *v5; // r4
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  unsigned int v8; // r0
  unsigned int v9; // r1

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( *(_DWORD *)(a1 + 264) == v3 )
    return 0;
  v5 = (unsigned int *)(a1 + 492);
  MiUnlockWorkingSetExclusive(a1 + 492, a2);
  LOCK_ADDRESS_SPACE(v3, a1);
  UNLOCK_ADDRESS_SPACE(v3, a1);
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(a1 + 492));
  }
  else
  {
    v6 = (unsigned __int8 *)(a1 + 495);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 0x80, v6) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(a1 + 492));
    while ( 1 )
    {
      v8 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v8 & 0x40000000) == 0 )
      {
        do
          v9 = __ldrex(v5);
        while ( v9 == v8 && __strex(v8 | 0x40000000, v5) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  return 1;
}
