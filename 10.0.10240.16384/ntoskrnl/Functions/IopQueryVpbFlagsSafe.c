// IopQueryVpbFlagsSafe 
 
int __fastcall IopQueryVpbFlagsSafe(int a1)
{
  int v2; // r5
  int v3; // r0
  int v4; // r3

  v2 = 0;
  v3 = KeAcquireQueuedSpinLock(9);
  v4 = *(_DWORD *)(a1 + 36);
  if ( v4 )
    v2 = *(unsigned __int16 *)(v4 + 4);
  KeReleaseQueuedSpinLock(9, v3);
  return v2;
}
