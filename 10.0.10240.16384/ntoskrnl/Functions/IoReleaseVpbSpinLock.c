// IoReleaseVpbSpinLock 
 
int __fastcall IoReleaseVpbSpinLock(int a1)
{
  return KeReleaseQueuedSpinLock(9, a1);
}
