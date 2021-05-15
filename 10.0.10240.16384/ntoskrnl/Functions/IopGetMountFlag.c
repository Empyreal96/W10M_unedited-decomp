// IopGetMountFlag 
 
int __fastcall IopGetMountFlag(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r3

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(9);
  v4 = *(_DWORD *)(a1 + 36);
  if ( v4 && (*(_WORD *)(v4 + 4) & 1) != 0 )
    v2 = 1;
  KeReleaseQueuedSpinLock(9, v3);
  return v2;
}
