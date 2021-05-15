// IoReleaseCancelSpinLock 
 
int __fastcall IoReleaseCancelSpinLock(int a1)
{
  return KeReleaseQueuedSpinLock(7, a1);
}
