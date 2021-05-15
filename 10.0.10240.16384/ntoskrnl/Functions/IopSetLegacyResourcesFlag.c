// IopSetLegacyResourcesFlag 
 
int __fastcall IopSetLegacyResourcesFlag(int a1)
{
  int v2; // r0

  v2 = KeAcquireQueuedSpinLock(10);
  *(_DWORD *)(a1 + 8) |= 0x40u;
  return KeReleaseQueuedSpinLock(10, v2);
}
