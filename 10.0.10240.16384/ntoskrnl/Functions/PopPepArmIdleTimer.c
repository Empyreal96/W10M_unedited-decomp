// PopPepArmIdleTimer 
 
int __fastcall PopPepArmIdleTimer(int a1)
{
  int v2; // r9
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r3
  unsigned int v7; // r1
  int v8; // [sp+0h] [bp-28h]

  v8 = a1;
  if ( PopPepIdleStateTimeout )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_525A2C();
    do
      v4 = __ldrex((unsigned __int8 *)&PopPepIdleTimerLock + 3);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)&PopPepIdleTimerLock + 3) );
    __dmb(0xBu);
    if ( v4 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&PopPepIdleTimerLock);
    while ( 1 )
    {
      v5 = PopPepIdleTimerLock;
      if ( (PopPepIdleTimerLock & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (PopPepIdleTimerLock & 0x40000000) == 0 )
      {
        do
          v7 = __ldrex((unsigned int *)&PopPepIdleTimerLock);
        while ( v7 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&PopPepIdleTimerLock) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    if ( a1 )
    {
      v6 = 0;
      PopPepIdleTimerArmed = 0;
    }
    else
    {
      v6 = (unsigned __int8)PopPepIdleTimerArmed;
    }
    if ( !v6 && PopPepPoweredIdleComponentCount > 0 )
    {
      PopPepIdleTimerArmed = 1;
      v8 = 0;
      KeSetCoalescableTimer(&PopPepIdleTimer);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&PopPepIdleTimerLock);
    }
    else
    {
      __dmb(0xBu);
      PopPepIdleTimerLock = 0;
    }
    KfLowerIrql(v2);
  }
  return v8;
}
