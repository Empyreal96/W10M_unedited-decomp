// PnpChainDereferenceComplete 
 
int __fastcall PnpChainDereferenceComplete(int a1)
{
  int v2; // r2
  int v3; // r3
  int v4; // r4
  int *v5; // r3
  int v6; // r2
  int v7; // r1
  int v8; // r3
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  int v12; // r3
  int result; // r0
  unsigned int v14; // r1
  int v15; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = *(__int16 *)(v2 + 0x134) - 1;
  *(_WORD *)(v2 + 308) = v3;
  ExAcquireResourceExclusiveLite((int)&IopSurpriseRemoveListLock, 1, v2, v3);
  v4 = IopPendingSurpriseRemovals;
  if ( (int *)IopPendingSurpriseRemovals == &IopPendingSurpriseRemovals )
    goto LABEL_16;
  while ( 1 )
  {
    if ( !*(_BYTE *)(v4 + 60) && IopSetRelationsTag(*(_DWORD *)(v4 + 32), a1) >= 0 )
    {
      v5 = **(int ***)(v4 + 32);
      v6 = v5[2];
      v7 = *v5;
      v8 = *(_DWORD *)(v4 + 28);
      v9 = v8 ? *(_DWORD *)(*(_DWORD *)(v8 + 176) + 20) : 0;
      if ( *(_DWORD *)(v9 + 172) != 782 && v6 == v7 )
        break;
    }
    v4 = *(_DWORD *)v4;
    if ( (int *)v4 == &IopPendingSurpriseRemovals )
      goto LABEL_16;
  }
  *(_BYTE *)(v4 + 60) = 1;
  if ( PnpDelayedRemovePending )
  {
LABEL_16:
    result = ExReleaseResourceLite((int)&IopSurpriseRemoveListLock);
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = (__int16)(*(_WORD *)(v14 + 0x134) + 1);
    *(_WORD *)(v14 + 308) = v15;
    if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  else
  {
    PnpDelayedRemovePending = 1;
    v10 = ExReleaseResourceLite((int)&IopSurpriseRemoveListLock);
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = (__int16)(*(_WORD *)(v11 + 0x134) + 1);
    *(_WORD *)(v11 + 308) = v12;
    if ( v12 )
      JUMPOUT(0x8197E0);
    result = sub_8197CC(v10);
  }
  return result;
}
