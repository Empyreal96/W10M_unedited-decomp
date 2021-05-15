// IopInterlockedInsertTailList 
 
int __fastcall IopInterlockedInsertTailList(int a1, _DWORD *a2)
{
  int v4; // r0
  _DWORD *v5; // r2

  v4 = KeAcquireQueuedSpinLock(10);
  v5 = *(_DWORD **)(a1 + 4);
  *a2 = a1;
  a2[1] = v5;
  if ( *v5 != a1 )
    sub_51A0B0(v4);
  *v5 = a2;
  *(_DWORD *)(a1 + 4) = a2;
  return KeReleaseQueuedSpinLock(10, v4);
}
