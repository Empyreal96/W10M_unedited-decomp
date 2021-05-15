// IopReferenceVerifyVpb 
 
int __fastcall IopReferenceVerifyVpb(int a1, int *a2, _DWORD *a3)
{
  int v6; // r5
  int v7; // r6
  int v8; // r0

  v6 = 0;
  v7 = KeAcquireQueuedSpinLock(9);
  v8 = *(_DWORD *)(a1 + 36);
  *a2 = 0;
  *a3 = 0;
  if ( v8 && (*(_WORD *)(v8 + 4) & 1) != 0 )
  {
    v6 = 1;
    *a3 = *(_DWORD *)(v8 + 8);
    *a2 = v8;
    IopIncrementVpbRefCount(v8, 0);
  }
  KeReleaseQueuedSpinLock(9, v7);
  return v6;
}
