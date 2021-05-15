// PnpUnlockDeviceActionQueue 
 
int PnpUnlockDeviceActionQueue()
{
  int v0; // r6
  unsigned int v2; // r2
  int v3; // r1
  int v4; // r2

  v0 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_50B918();
  do
    v2 = __ldrex((unsigned int *)&PnpSpinLock);
  while ( __strex(1u, (unsigned int *)&PnpSpinLock) );
  __dmb(0xBu);
  if ( v2 )
    KxWaitForSpinLockAndAcquire((unsigned int *)&PnpSpinLock);
  if ( (int *)PnpEnumerationRequestList == &PnpEnumerationRequestList )
  {
    PnpEnumerationInProgress = 0;
    KeSetEvent((int)&PnpEnumerationLock, 0, 0);
  }
  else
  {
    dword_62FBB8 = (int)PnpDeviceActionWorker;
    dword_62FBBC = 0;
    PnpDeviceEnumerationWorkItem = 0;
    ExQueueWorkItem(&PnpDeviceEnumerationWorkItem, 1);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PnpSpinLock);
  }
  else
  {
    __dmb(0xBu);
    PnpSpinLock = 0;
  }
  KfLowerIrql(v0);
  return PpDevNodeUnlockTree(1, v3, v4);
}
