// IopGetFsRegistrationInProgress 
 
int IopGetFsRegistrationInProgress()
{
  int v0; // r0
  int v1; // r4

  v0 = KeAcquireQueuedSpinLock(10);
  v1 = (unsigned __int8)IopFsRegistrationInProgress;
  KeReleaseQueuedSpinLock(10, v0);
  return v1;
}
