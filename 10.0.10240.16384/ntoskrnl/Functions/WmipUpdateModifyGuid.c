// WmipUpdateModifyGuid 
 
// local variable allocation has failed, the output may be wrong!
BOOL __fastcall WmipUpdateModifyGuid(_DWORD *a1, _DWORD *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r5
  int v9; // r6
  _DWORD *v10; // r4
  _DWORD *v11; // r0
  _DWORD *v12; // r5
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  int v15; // r7
  unsigned int v16; // r0
  int *v17; // r2 OVERLAPPED
  int v18; // r1 OVERLAPPED
  char v21[48]; // [sp+10h] [bp-88h] BYREF
  unsigned int v22; // [sp+40h] [bp-58h]
  char v23[80]; // [sp+48h] [bp-50h] BYREF

  v5 = a3;
  *a5 = 0;
  v9 = 0;
  v10 = WmipFindISInDSByGuid((int)a1, (unsigned int)a2);
  if ( !v10 )
    return WmipUpdateAddGuid(a1, a2, v5, a4, a5);
  v11 = WmipAllocEntry((int *)&WmipISChunkInfo);
  v12 = v11;
  if ( v11 && WmipBuildInstanceSet(a2, a3, a4, v11, a1[7]) >= 0 && !WmipIsEqualInstanceSets(v10, v12) )
  {
    memmove((int)v23, (int)v10, 0x34u);
    __dmb(0xBu);
    memmove((int)v21, (int)v23, 0x34u);
    v10[12] = 0;
    *(_QWORD *)&v13 = *(_QWORD *)v10;
    if ( *(_DWORD **)(*v10 + 4) != v10 || (_DWORD *)*v14 != v10 )
      __fastfail(3u);
    *v14 = v13;
    *(_DWORD *)(v13 + 4) = v14;
    v15 = WmipBuildInstanceSet(a2, a3, a4, v10, a1[7]);
    if ( v15 < 0 )
    {
      v16 = v10[12];
      if ( v16 )
        ExFreePoolWithTag(v16);
      memmove((int)v23, (int)v21, 0x34u);
      __dmb(0xBu);
      memmove((int)v10, (int)v23, 0x34u);
    }
    v17 = (int *)(v10[7] + 32);
    v18 = *v17;
    *(_QWORD *)v10 = *(_QWORD *)&v18;
    if ( *(int **)(v18 + 4) != v17 )
      __fastfail(3u);
    *(_DWORD *)(v18 + 4) = v10;
    *v17 = (int)v10;
    if ( v15 >= 0 )
    {
      if ( v22 )
        ExFreePoolWithTag(v22);
      *a5 = v10;
      v9 = 2;
    }
  }
  WmipUnreferenceEntry((int *)&WmipISChunkInfo, v10);
  if ( v12 )
    WmipUnreferenceEntry((int *)&WmipISChunkInfo, v12);
  return v9;
}
