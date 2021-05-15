// KdUpdateTimeSlipEvent 
 
int __fastcall KdUpdateTimeSlipEvent(int result)
{
  int v1; // r6
  int v2; // r7
  unsigned int v3; // r2
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = result;
  if ( !KdPitchDebugger )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&KdpTimeSlipEventLock);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&KdpTimeSlipEventLock);
      while ( __strex(1u, (unsigned int *)&KdpTimeSlipEventLock) );
      __dmb(0xBu);
      if ( v3 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&KdpTimeSlipEventLock);
    }
    if ( KdpTimeSlipEvent )
      ObfDereferenceObjectWithTag(KdpTimeSlipEvent);
    KdpTimeSlipEvent = v1;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&KdpTimeSlipEventLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      KdpTimeSlipEventLock = 0;
    }
    result = KfLowerIrql(v2);
  }
  return result;
}
