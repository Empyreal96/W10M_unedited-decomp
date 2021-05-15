// KiResumeClockTimer 
 
void KiResumeClockTimer()
{
  int v0; // r5
  int v1; // r4
  unsigned int v2; // r4
  __int64 v3; // r0
  _DWORD v4[8]; // [sp+10h] [bp-20h] BYREF

  v0 = 0;
  v1 = KiClockState;
  if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) == KiClockTimerOwner )
  {
    v0 = 1;
  }
  else if ( !KiClockTimerPerCpu )
  {
    return;
  }
  off_617AE8();
  ((void (__cdecl *)())off_617AE4)();
  if ( v0 )
  {
    KiClockActive = 1;
    ++dword_624FA4;
    *(_BYTE *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x591) = 1;
    v4[0] = KiLastRequestedTimeIncrement;
    v4[1] = 0;
    ((void (__cdecl *)())off_617AF0)();
    KiSetPendingTick(1);
    if ( v1 == 2 )
    {
      __dmb(0xBu);
      do
        v2 = __ldrex((unsigned int *)&KiClockState);
      while ( __strex(0, (unsigned int *)&KiClockState) );
      __dmb(0xBu);
    }
    KiEventClockStateChange();
    LODWORD(v3) = RtlGetInterruptTimePrecise(v4);
    KiClockTimerNextTickTime = (unsigned int)KeTimeIncrement + v3;
  }
}
