// PnpQueuePendingSurpriseRemoval 
 
int __fastcall PnpQueuePendingSurpriseRemoval(int a1, _DWORD ***a2, int a3, int a4)
{
  _DWORD **v4; // r7
  unsigned int v5; // r4
  int v6; // r1
  int v7; // r0
  int result; // r0
  int *v9; // r0
  int **v10; // r2
  int *v11; // r5
  int v12; // r4
  int v13; // r10
  int v14; // r3
  unsigned int v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h]
  int v20; // [sp+10h] [bp-30h]
  int v21; // [sp+14h] [bp-2Ch]
  int v22[10]; // [sp+18h] [bp-28h] BYREF

  v4 = *a2;
  v20 = a3;
  v21 = a4;
  v19 = a1;
  *a2 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  ExAcquireResourceExclusiveLite((int)&IopSurpriseRemoveListLock, 1, a3, 0);
  v7 = PnpAcquireDependencyRelationsLock(1, v6);
  if ( (int *)IopPendingSurpriseRemovals != &IopPendingSurpriseRemovals )
    return sub_81A780(v7);
  ExReleaseResourceLite((int)&PiDependencyRelationsLock);
  PpDevNodeUnlockTree(0);
  v9 = (int *)PnpAllocateCriticalMemory(3, 512, 68, 1416654416);
  v10 = (int **)dword_630744;
  v11 = v9;
  *v9 = (int)&IopPendingSurpriseRemovals;
  v9[1] = (int)v10;
  if ( *v10 != &IopPendingSurpriseRemovals )
    __fastfail(3u);
  *v10 = v9;
  dword_630744 = (int)v9;
  v22[0] = 0;
  v22[1] = 0;
  while ( IopEnumerateRelations((int)v4, v22, &v18, 0, 0) )
  {
    if ( v18 )
      v12 = *(_DWORD *)(*(_DWORD *)(v18 + 176) + 20);
    else
      v12 = 0;
    if ( (*(_DWORD *)(v12 + 412) & 1) != 0 )
    {
      if ( IopIsDescendantNode(v4, v18) )
      {
        v17 = *(_DWORD *)(v12 + 412) & 0xFFFFFFFE;
        *(_DWORD *)(v12 + 412) = v17;
        --*(_DWORD *)(v17 + 416);
      }
    }
  }
  v13 = v19;
  v11[11] = v20;
  v14 = v21;
  v11[7] = v13;
  v11[8] = (int)v4;
  *((_BYTE *)v11 + 48) = 0;
  v11[16] = v14;
  *((_BYTE *)v11 + 60) = 0;
  result = ExReleaseResourceLite((int)&IopSurpriseRemoveListLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
