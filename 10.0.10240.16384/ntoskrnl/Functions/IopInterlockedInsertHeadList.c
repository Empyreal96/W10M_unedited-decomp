// IopInterlockedInsertHeadList 
 
int __fastcall IopInterlockedInsertHeadList(int *a1, int *a2)
{
  int v4; // r0
  int v5; // r2

  v4 = KeAcquireQueuedSpinLock(10);
  v5 = *a1;
  *a2 = *a1;
  a2[1] = (int)a1;
  if ( *(int **)(v5 + 4) != a1 )
    sub_51A0B0(v4);
  *(_DWORD *)(v5 + 4) = a2;
  *a1 = (int)a2;
  return KeReleaseQueuedSpinLock(10, v4);
}
