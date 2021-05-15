// sub_903B04 
 
void __fastcall sub_903B04(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  unsigned int v14; // r2
  int v15; // r7
  int v16; // r6

  ExUpdateSystemTimeFromCmos(0, 0);
  ExReleaseTimeRefreshLock();
  v16 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&KdpTimeSlipEventLock);
  }
  else
  {
    do
      v14 = __ldrex((unsigned int *)&KdpTimeSlipEventLock);
    while ( __strex(1u, (unsigned int *)&KdpTimeSlipEventLock) );
    __dmb(0xBu);
    if ( v14 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&KdpTimeSlipEventLock);
  }
  if ( KdpTimeSlipEvent )
    KeSetEvent(KdpTimeSlipEvent, 0, 0);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KdpTimeSlipEventLock, a14);
  }
  else
  {
    __dmb(0xBu);
    KdpTimeSlipEventLock = v15;
  }
  KfLowerIrql(v16);
  JUMPOUT(0x903B5A);
}
