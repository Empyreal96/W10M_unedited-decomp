// PopFxArmResidentTimer 
 
int __fastcall PopFxArmResidentTimer(int a1)
{
  int v2; // r8
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r3
  unsigned int v7; // r1

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51ECB4();
  do
    v4 = __ldrex((unsigned __int8 *)&PopFxResidentTimerLock + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&PopFxResidentTimerLock + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&PopFxResidentTimerLock);
  while ( 1 )
  {
    v5 = PopFxResidentTimerLock;
    if ( (PopFxResidentTimerLock & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (PopFxResidentTimerLock & 0x40000000) == 0 )
    {
      do
        v7 = __ldrex((unsigned int *)&PopFxResidentTimerLock);
      while ( v7 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&PopFxResidentTimerLock) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( a1 )
  {
    v6 = 0;
    PopFxResidentTimerArmed = 0;
  }
  else
  {
    v6 = (unsigned __int8)PopFxResidentTimerArmed;
  }
  if ( !v6 && PopFxResidentComponentCount > 0 )
  {
    PopFxResidentTimerArmed = 1;
    KeSetCoalescableTimer(&PopFxResidentTimer);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&PopFxResidentTimerLock);
  }
  else
  {
    __dmb(0xBu);
    PopFxResidentTimerLock = 0;
  }
  return KfLowerIrql(v2);
}
