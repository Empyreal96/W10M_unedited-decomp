// PipProcessRebuildPowerRelationsQueue 
 
int __fastcall PipProcessRebuildPowerRelationsQueue(int a1, int a2, int a3, int a4)
{
  int *v4; // r4
  int *v6; // r5
  int v7; // r8
  _DWORD **v8; // r0
  _DWORD *v9; // r6
  _DWORD *v10; // r9
  _DWORD *v11; // r2
  __int64 v12; // r0
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  PnpAcquireDependencyRelationsLock(1);
  v4 = (int *)PiRebuildPowerRelationsQueue;
  do
  {
LABEL_2:
    if ( v4 == &PiRebuildPowerRelationsQueue )
      goto LABEL_3;
    v6 = v4 - 9;
    v7 = *(v4 - 3);
    v4 = (int *)*v4;
    if ( !v7 )
    {
      v11 = v6 + 9;
      v12 = *(_QWORD *)(v6 + 9);
      if ( *(int **)(v12 + 4) != v6 + 9 || *(_DWORD **)HIDWORD(v12) != v11 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v12) = v12;
      *(_DWORD *)(v12 + 4) = HIDWORD(v12);
      *v11 = v11;
      v6[10] = (int)(v6 + 9);
      PipDereferenceDependencyNode(v6);
LABEL_3:
      ExReleaseResourceLite((int)&PiDependencyRelationsLock);
      return PpDevNodeUnlockTree(0);
    }
  }
  while ( !PipIsDeviceReadyForPowerRelations(v7) );
  v8 = (_DWORD **)PiGetProviderList(v7);
  v9 = *v8;
  v10 = v8;
  while ( v9 != v10 )
  {
    PiEnumerateProviderListEntry(v9, v13, 0);
    if ( !PipIsDeviceReadyForPowerRelations(v13[0]) )
      goto LABEL_2;
    v9 = (_DWORD *)*v9;
  }
  return sub_7CAD48();
}
