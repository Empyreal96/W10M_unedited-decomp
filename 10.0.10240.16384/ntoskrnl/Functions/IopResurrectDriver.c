// IopResurrectDriver 
 
int __fastcall IopResurrectDriver(int a1)
{
  int v2; // r5
  int v3; // r0

  v2 = *(_DWORD *)(a1 + 4);
  v3 = KeAcquireQueuedSpinLock(10);
  if ( (*(_DWORD *)(a1 + 8) & 1) == 0 && v2 && (*(_DWORD *)(*(_DWORD *)(v2 + 176) + 16) & 1) != 0 )
    return sub_528E0C(v3);
  KeReleaseQueuedSpinLock(10, v3);
  return -1073741554;
}
