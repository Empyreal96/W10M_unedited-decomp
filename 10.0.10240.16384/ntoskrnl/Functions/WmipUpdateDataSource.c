// WmipUpdateDataSource 
 
int __fastcall WmipUpdateDataSource(int a1, int a2, int a3)
{
  _DWORD *v3; // r6
  int v6; // r5
  int **v7; // r4
  int v8; // r8
  unsigned int v9; // r10
  unsigned int v10; // r9
  int v11; // r8
  unsigned int v12; // r4
  _DWORD *v13; // r0
  int v14; // r5
  int v15; // r0
  int *v16; // r3
  int *v17; // r2
  int **v18; // r7
  unsigned int *v19; // r9
  int **v20; // r6
  int v21; // r4
  int *v22; // t1
  __int64 v23; // r0
  int **v24; // r4
  unsigned int *v25; // r4
  int v26; // r6
  int v27; // r6
  int **v28; // r4
  int v29; // r1
  int *v30; // t1
  int *v31; // [sp+0h] [bp-58h]
  int v32; // [sp+8h] [bp-50h] BYREF
  int v33; // [sp+Ch] [bp-4Ch] BYREF
  int v34; // [sp+10h] [bp-48h] BYREF
  unsigned int v35; // [sp+14h] [bp-44h] BYREF
  unsigned int *v36; // [sp+18h] [bp-40h] BYREF
  int **v37; // [sp+1Ch] [bp-3Ch] BYREF
  int **v38; // [sp+20h] [bp-38h] BYREF
  int **v39; // [sp+24h] [bp-34h]
  int v40; // [sp+28h] [bp-30h]
  int v41; // [sp+2Ch] [bp-2Ch] BYREF
  int v42; // [sp+30h] [bp-28h] BYREF
  int v43; // [sp+34h] [bp-24h] BYREF

  v3 = *(_DWORD **)(a1 + 16);
  v40 = a3;
  if ( !v3 )
    return -1073741772;
  WmipReferenceEntry((int)v3);
  v6 = 0;
  v7 = 0;
  v32 = 0;
  v33 = 0;
  v8 = 0;
  v34 = 0;
  v35 = 0;
  v9 = 0;
  v42 = 0;
  v43 = 0;
  v41 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v10 = 0;
  if ( *(_DWORD *)(a2 + 16) )
  {
    v11 = v40;
    v12 = a2 + 20;
    while ( 1 )
    {
      if ( (*(_DWORD *)(v12 + 16) & 0x10000) != 0 )
      {
        v13 = WmipFindISInDSByGuid((int)v3, v12);
        v14 = (int)v13;
        if ( v13 )
        {
          WmipUnreferenceEntry((int *)&WmipISChunkInfo, v13);
          v32 = v14;
          WmipCachePtrs(v12, v14, (int *)&v35, &v41, (int *)&v38);
        }
        goto LABEL_13;
      }
      v15 = WmipUpdateModifyGuid(v3, v12, a2, v11, &v32);
      if ( v15 == 1 )
        break;
      if ( v15 == 2 )
      {
        v31 = (int *)&v36;
        v16 = &v43;
        v17 = &v34;
        goto LABEL_12;
      }
LABEL_13:
      ++v10;
      v12 += 28;
      if ( v10 >= *(_DWORD *)(a2 + 16) )
      {
        v6 = v33;
        v8 = v34;
        v18 = v37;
        v7 = v38;
        v9 = v35;
        v19 = v36;
        v32 = v33;
        v39 = v38;
        goto LABEL_16;
      }
    }
    v31 = (int *)&v37;
    v16 = &v42;
    v17 = &v33;
LABEL_12:
    WmipCachePtrs(v12, v32, v17, v16, v31);
    goto LABEL_13;
  }
  v18 = 0;
  v19 = 0;
LABEL_16:
  KeReleaseMutex((int)&WmipSMMutex);
  WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v3);
  if ( v9 )
  {
    v38 = 0;
    v20 = v7;
    do
    {
      if ( !memcmp((unsigned int)*v20, (unsigned int)WmipBinaryMofGuid, 16) )
        WmipGenerateBinaryMofNotification((int)v20[1], &GUID_MOF_RESOURCE_REMOVED_NOTIFICATION);
      v21 = (int)v20[1];
      v22 = *v20;
      v20 += 2;
      WmipDisableCollectionForRemovedGuid(v22, v21);
      KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      if ( *(_DWORD *)v21 )
        WmipUnlinkInstanceSetFromGuidEntry((_DWORD *)v21);
      if ( (*(_DWORD *)(v21 + 8) & 8) == 0 )
        WmipUnreferenceEntry((int *)&WmipGEChunkInfo, *(_DWORD **)(v21 + 28));
      *(_DWORD *)(v21 + 28) = 0;
      v23 = *(_QWORD *)(v21 + 20);
      if ( *(_DWORD *)(v23 + 4) != v21 + 20 || *(_DWORD *)HIDWORD(v23) != v21 + 20 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v23) = v23;
      *(_DWORD *)(v23 + 4) = HIDWORD(v23);
      WmipUnreferenceEntry((int *)&WmipISChunkInfo, (_DWORD *)v21);
      KeReleaseMutex((int)&WmipSMMutex);
      v38 = (int **)((char *)v38 + 1);
    }
    while ( (unsigned int)v38 < v9 );
    v24 = v39;
    WmipSendGuidUpdateNotifications(2, v9, v39);
    ExFreePoolWithTag((unsigned int)v24);
  }
  if ( v8 )
  {
    v25 = v19;
    v26 = v8;
    do
    {
      if ( !memcmp(*v25, (unsigned int)WmipBinaryMofGuid, 16) )
        WmipGenerateBinaryMofNotification(v25[1], &GUID_MOF_RESOURCE_ADDED_NOTIFICATION);
      v25 += 2;
      --v26;
    }
    while ( v26 );
    v6 = v32;
    WmipSendGuidUpdateNotifications(4, v8, (_DWORD **)v19);
    ExFreePoolWithTag((unsigned int)v19);
  }
  if ( v6 )
  {
    v27 = v6;
    v28 = v18;
    do
    {
      if ( !memcmp((unsigned int)*v28, (unsigned int)WmipBinaryMofGuid, 16) )
        WmipGenerateBinaryMofNotification((int)v28[1], &GUID_MOF_RESOURCE_ADDED_NOTIFICATION);
      v29 = (int)v28[1];
      v30 = *v28;
      v28 += 2;
      WmipEnableCollectionForNewGuid(v30, v29);
      --v27;
    }
    while ( v27 );
    WmipSendGuidUpdateNotifications(1, v32, v18);
    ExFreePoolWithTag((unsigned int)v18);
  }
  return 0;
}
