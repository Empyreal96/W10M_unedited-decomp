// PnpRemoveLockedDeviceNode 
 
int __fastcall PnpRemoveLockedDeviceNode(_DWORD *a1, int a2)
{
  _DWORD *v2; // r4
  int v3; // r10
  int v4; // r9
  int v5; // r6
  int result; // r0
  int v7; // r2
  int v8; // r3
  int *v9; // r5
  _BYTE *v10; // r8
  int v11; // r6
  int v12; // r6
  int *v13; // r9
  _DWORD *v14; // r4
  int v15; // r0
  int *v16; // r1
  int i; // r3
  int *v18; // r6
  int v19; // r0
  int v20; // t1
  int v21; // r0
  int v22; // r1
  int v23; // r1
  int v24; // t1
  int v25; // r3
  int v26; // [sp+0h] [bp-28h]

  v2 = a1;
  v3 = a1[4];
  v26 = a2;
  v4 = a2;
  v5 = 0;
  result = PpHotSwapInitRemovalPolicy();
  if ( v2[1] )
    return sub_51FD18(result);
  v7 = v2[43];
  if ( v7 == 782 || v7 == 783 )
  {
    if ( v2[44] == 785 )
      return result;
    PipRestoreDevNodeState(v2);
  }
  if ( v2[43] != 788 )
    JUMPOUT(0x4DB098);
  v8 = *(_DWORD *)(v3 + 16);
  while ( v8 )
  {
    v8 = *(_DWORD *)(v8 + 16);
    ++v5;
  }
  v9 = 0;
  v10 = 0;
  if ( v5 )
  {
    v11 = v5 + 2;
    v9 = (int *)ExAllocatePoolWithTag(512, 4 * v11, 1701081168);
    if ( v9 )
    {
      v10 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v11, 1701081168);
      if ( v10 )
      {
        memset(v9, 0, 4 * v11);
        memset(v10, 0, 4 * v11);
        v12 = *(_DWORD *)(v3 + 16);
        if ( v12 )
        {
          v13 = v9;
          v14 = v10;
          do
          {
            ObfReferenceObject(v12);
            *v13++ = v12;
            *v14++ = *(_DWORD *)(v12 + 8);
            v12 = *(_DWORD *)(v12 + 16);
          }
          while ( v12 );
          v4 = v26;
          v2 = a1;
        }
      }
      else
      {
        ExFreePoolWithTag(v9, 0);
        v9 = 0;
      }
    }
  }
  v15 = KeAcquireQueuedSpinLock(10);
  v16 = v9;
  if ( v9 )
  {
    for ( i = *v9; i; i = v24 )
    {
      *(_DWORD *)(*(_DWORD *)(i + 176) + 16) &= 0xFFFFFFFB;
      *(_DWORD *)(*(_DWORD *)(*v16 + 176) + 16) |= 8u;
      v24 = v16[1];
      ++v16;
    }
  }
  *(_DWORD *)(*(_DWORD *)(v3 + 176) + 16) &= 0xFFFFFFFB;
  *(_DWORD *)(*(_DWORD *)(v3 + 176) + 16) |= 8u;
  KeReleaseQueuedSpinLock(10, v15);
  if ( (v2[67] & 0x10) == 0 )
  {
    v25 = v2[93];
    if ( v25 == 3 || v25 == 4 )
      PpProfileCommitTransitioningDock(v2, 3);
  }
  v18 = v9;
  if ( v9 )
  {
    if ( *v9 )
    {
      do
      {
        v19 = KeAcquireQueuedSpinLock(10);
        *(_DWORD *)(*(_DWORD *)(*v18 + 176) + 16) &= 0xFFFFFFF7;
        *(_DWORD *)(*(_DWORD *)(*v18 + 176) + 16) |= 0x10u;
        KeReleaseQueuedSpinLock(10, v19);
        PnpUnloadAttachedDriver(*(int *)((char *)v18 + v10 - (_BYTE *)v9));
        ObfDereferenceObject(*v18);
        v20 = v18[1];
        ++v18;
      }
      while ( v20 );
    }
    ExFreePoolWithTag(v9, 0);
    ExFreePoolWithTag(v10, 0);
  }
  v21 = KeAcquireQueuedSpinLock(10);
  *(_DWORD *)(*(_DWORD *)(v3 + 176) + 16) &= 0xFFFFFFF7;
  *(_DWORD *)(*(_DWORD *)(v3 + 176) + 16) |= 0x10u;
  KeReleaseQueuedSpinLock(10, v21);
  if ( (v2[67] & 0x10) != 0 )
    v22 = 786;
  else
    v22 = 788;
  result = PipSetDevNodeState(v2, v22);
  if ( v4 )
  {
    if ( (v2[67] & 0x6000) == 0
      || v4 == 24
      || v4 == 22
      || (result = PipIsProblemReadonly(v2, v4)) != 0 && (result = PipIsProblemReadonly(v2, v2[69])) == 0 )
    {
      PipClearDevNodeProblem(v2);
      result = PipSetDevNodeProblem(v2, v4, v2[66]);
    }
  }
  if ( (v2[67] & 0x10) == 0 )
    result = IoDeleteAllDependencyRelations(v3);
  v23 = v2[6];
  if ( v23 )
    result = PnpRaiseNtPlugPlayDevicePropertyChangeEvent(PiPnpRtlCtx, v23, 23);
  return result;
}
