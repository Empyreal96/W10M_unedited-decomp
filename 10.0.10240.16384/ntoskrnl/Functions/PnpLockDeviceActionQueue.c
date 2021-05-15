// PnpLockDeviceActionQueue 
 
int __fastcall PnpLockDeviceActionQueue(int a1, int a2)
{
  int v2; // r8
  unsigned int v4; // r2
  int v5; // r1
  int v6; // r2

  while ( 1 )
  {
    PpDevNodeLockTree(1, a2);
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_50B94C();
    do
      v4 = __ldrex((unsigned int *)&PnpSpinLock);
    while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
    __dmb(0xBu);
    if ( v4 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
    if ( !PnpEnumerationInProgress )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PnpSpinLock);
    }
    else
    {
      __dmb(0xBu);
      PnpSpinLock = 0;
    }
    KfLowerIrql(v2);
    PpDevNodeUnlockTree(1, v5, v6);
    KeWaitForSingleObject((unsigned int)&PnpEnumerationLock, 0, 0, 0, 0);
  }
  PnpEnumerationInProgress = 1;
  KeResetEvent((int)&PnpEnumerationLock);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  return KfLowerIrql(v2);
}
