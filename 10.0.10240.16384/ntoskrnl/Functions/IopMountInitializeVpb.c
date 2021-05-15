// IopMountInitializeVpb 
 
int __fastcall IopMountInitializeVpb(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  int v9; // r4
  int v10; // r8

  v8 = KeAcquireQueuedSpinLock(9);
  v9 = *(_DWORD *)(a1 + 36);
  v10 = v8;
  *(_WORD *)(v9 + 4) = 1;
  if ( a3 )
    *(_WORD *)(v9 + 4) = 17;
  if ( a4 )
    *(_WORD *)(v9 + 4) |= 0x20u;
  *(_BYTE *)(*(_DWORD *)(v9 + 8) + 48) = *(_BYTE *)(a2 + 48) + 1;
  *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v9 + 8) + 176) + 40) = v9;
  IopIncrementVpbRefCount(v9, 0);
  KeReleaseQueuedSpinLock(9, v10);
  return v9;
}
