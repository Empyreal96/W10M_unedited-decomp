// PnpSurpriseRemoveLockedDeviceNode 
 
_DWORD *__fastcall PnpSurpriseRemoveLockedDeviceNode(_DWORD *result, int a2)
{
  int v2; // r5
  int v3; // r2
  _DWORD *v4; // r6
  int v5; // r10
  int v6; // r9
  _DWORD *v7; // r4
  int v8; // r2
  int v9; // r4
  _DWORD *v10; // r0
  int v11; // r1
  int v12; // r3
  _DWORD *v13; // r7
  int v14; // r1
  int v15; // r3
  int v16; // r3
  int v17; // r0
  int v18; // r0
  int v19; // r1
  int v20; // r2
  int v21; // r3
  _DWORD *v22; // [sp+0h] [bp-30h]
  int v24; // [sp+8h] [bp-28h] BYREF
  _DWORD *v25; // [sp+Ch] [bp-24h]

  v2 = (int)result;
  v3 = result[43];
  v24 = 0;
  v4 = 0;
  v22 = (_DWORD *)result[4];
  v25 = 0;
  v5 = 768;
  if ( v3 == 782 || v3 == 783 )
  {
    v5 = v3;
    result = (_DWORD *)PipRestoreDevNodeState(result);
  }
  v6 = *(_DWORD *)(v2 + 172);
  *(_BYTE *)(v2 + 318) = 0;
  *(_BYTE *)(v2 + 319) = 0;
  if ( v6 == 785 )
    return (_DWORD *)sub_818C24(result);
  v7 = *(_DWORD **)(v2 + 4);
  if ( v7 )
  {
    do
    {
      v12 = v7[67];
      v13 = (_DWORD *)*v7;
      if ( (v12 & 0x10) != 0 )
        v7[67] = v12 & 0xFFFFFFEF;
      if ( v7[71] || v7[90] || (v7[67] & 0x40) != 0 )
        IopReleaseDeviceResources(v7, 0);
      result = (_DWORD *)PipSetDevNodeState(v7, 787);
      v7 = v13;
    }
    while ( v13 );
  }
  if ( v6 == 778 && (*(_DWORD *)(v2 + 268) & 0x1000000) != 0 )
  {
    PnpMarkDeviceForRemove((int)v22, 1, &v24);
    PnpUnlockMountableDevice((int)v22);
    result = (_DWORD *)PipClearDevNodeFlags(v2, 0x1000000);
    v4 = v25;
  }
  v8 = *(_DWORD *)(v2 + 172);
  if ( v8 < 769 || v8 > 770 && (v8 <= 776 || v8 == 778 || (unsigned int)(v8 - 785) > 3) )
  {
    v9 = IopRemoveDevice(v22, 23, v8);
    PnpDisableDeviceInterfaces((unsigned __int16 *)(v2 + 20));
    if ( v9 >= 0 )
      IopReleaseDeviceResources((_DWORD *)v2, 0);
    v10 = (_DWORD *)v2;
    if ( (*(_DWORD *)(v2 + 268) & 0x10) != 0 )
    {
      result = (_DWORD *)PipSetDevNodeState((_DWORD *)v2, 785);
      if ( v5 != 782 )
        goto LABEL_15;
      v14 = 782;
      v10 = (_DWORD *)v2;
    }
    else
    {
      v14 = 787;
    }
    result = (_DWORD *)PipSetDevNodeState(v10, v14);
  }
LABEL_15:
  if ( v6 == 778 && v4 )
  {
    IopDecrementDeviceObjectHandleCount(v4);
    result = (_DWORD *)ObfDereferenceObject((int)v4);
  }
  v11 = a2;
  if ( a2 )
  {
    v15 = *(_DWORD *)(v2 + 268);
    if ( (v15 & 0x6000) == 0 )
      result = (_DWORD *)PipSetDevNodeProblem(v2, a2, 0, v15);
  }
  *(_DWORD *)(v2 + 456) &= 0xFFFFFFFD;
  if ( (*(_DWORD *)(v2 + 268) & 0x10) == 0 )
  {
    PnpAcquireDependencyRelationsLock(1, v11);
    v16 = *(_DWORD *)(v2 + 16);
    if ( v16 )
      v17 = *(_DWORD *)(*(_DWORD *)(v16 + 176) + 44);
    else
      v17 = 0;
    if ( v17 )
      PipConvertResolutionsToReservations();
    ExReleaseResourceLite((int)&PiDependencyRelationsLock);
    v18 = PpDevNodeUnlockTree(0);
    result = (_DWORD *)PipProcessRebuildPowerRelationsQueue(v18, v19, v20, v21);
  }
  return result;
}
