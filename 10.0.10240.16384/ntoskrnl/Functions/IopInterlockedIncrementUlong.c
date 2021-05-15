// IopInterlockedIncrementUlong 
 
int __fastcall IopInterlockedIncrementUlong(int a1, int *a2)
{
  int v4; // r0
  int v5; // r3
  int v6; // r4

  v4 = KeAcquireQueuedSpinLock(a1);
  v5 = *a2 + 1;
  __dmb(0xBu);
  *a2 = v5;
  v6 = *a2;
  __dmb(0xBu);
  KeReleaseQueuedSpinLock(a1, v4);
  return v6;
}
