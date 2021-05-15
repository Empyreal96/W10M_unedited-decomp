// IopSetFsRegistrationInProgress 
 
int __fastcall IopSetFsRegistrationInProgress(char a1)
{
  int v2; // r0

  v2 = KeAcquireQueuedSpinLock(10);
  IopFsRegistrationInProgress = a1;
  return KeReleaseQueuedSpinLock(10, v2);
}
