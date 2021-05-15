// WmipAddDataSource 
 
int __fastcall WmipAddDataSource(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // r4
  int v6; // r7
  int v9; // r0
  unsigned int v11; // r6
  unsigned int v12; // r9
  int v13; // r3
  _DWORD *v14; // r0
  int v15; // r5
  int v16; // r3
  int v17; // r7
  unsigned int *v18; // r5
  int v19; // r9
  int v20; // r3
  _WORD *v21; // r6
  _WORD *v22; // r5
  unsigned int v23; // r6
  __int64 **v24; // r5
  __int64 v25; // r0
  int v26; // r2
  __int64 v27; // r2
  _DWORD **v28; // r8
  _DWORD *v29; // r1
  __int64 v30; // r2
  __int64 *v31; // r6
  __int64 v32; // r2
  char v33[4]; // [sp+8h] [bp-48h] BYREF
  int v34; // [sp+Ch] [bp-44h]
  int v35; // [sp+10h] [bp-40h]
  int v36; // [sp+14h] [bp-3Ch]
  int v37; // [sp+18h] [bp-38h]
  int v38[2]; // [sp+20h] [bp-30h] BYREF
  int v39[10]; // [sp+28h] [bp-28h] BYREF

  v5 = (_DWORD *)a1[4];
  v6 = a3;
  v36 = a3;
  v37 = a4;
  v34 = 0;
  v35 = 0;
  if ( !v5 )
  {
    v9 = WmipAllocDataSource();
    v5 = (_DWORD *)v9;
    if ( !v9 )
      return sub_7CB9A8();
    v34 = 1;
    *(_DWORD *)(v9 + 28) = a1[2];
  }
  v11 = a2 + 20;
  v12 = 0;
  if ( !*(_DWORD *)(a2 + 16) )
  {
LABEL_12:
    v18 = 0;
    if ( (a1[6] & 0x40000000) != 0 )
    {
      v38[1] = (int)v38;
      v38[0] = (int)v38;
      v39[1] = (int)v39;
      v18 = (unsigned int *)v38;
      v39[0] = (int)v39;
    }
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v19 = v34;
    v17 = WmipLinkDataSourceToList(v5, v34, v18);
    KeReleaseMutex((int)&WmipSMMutex);
    if ( v18 )
    {
      while ( 1 )
      {
        v23 = *v18;
        if ( (unsigned int *)*v18 == v18 )
          break;
        v27 = *(_QWORD *)v23;
        if ( *(unsigned int **)(v23 + 4) != v18 || *(_DWORD *)(v27 + 4) != v23 )
          __fastfail(3u);
        *v18 = v27;
        *(_DWORD *)(v27 + 4) = v18;
        WmipLegacyEtwWorker(*(_DWORD *)(v23 + 8));
        v28 = (_DWORD **)(v23 + 20);
        while ( *v28 != v28 )
        {
          LODWORD(v30) = *v28;
          HIDWORD(v30) = (*v28)[1];
          v29 = (_DWORD *)**v28;
          if ( v30 != __PAIR64__((unsigned int)v28, v29[1]) )
            __fastfail(3u);
          *v28 = v29;
          v29[1] = v28;
          KeSetEvent(v30 + 8, 0, 0);
        }
        ExFreePoolWithTag(v23);
      }
      v24 = (__int64 **)(v18 + 2);
      while ( *v24 != (__int64 *)v24 )
      {
        v31 = *v24;
        v32 = **v24;
        if ( (__int64 **)HIDWORD(v32) != v24 || *(__int64 **)(v32 + 4) != v31 )
          __fastfail(3u);
        *v24 = (__int64 *)v32;
        *(_DWORD *)(v32 + 4) = v24;
        KeWaitForSingleObject((unsigned int)(v31 + 2), 0, 0, 0, 0);
        ExFreePoolWithTag((unsigned int)v31);
      }
    }
    if ( v17 >= 0 )
    {
      v20 = v35;
      a1[4] = v5;
      if ( v20 )
        WmipGenerateBinaryMofNotification(v20, &GUID_MOF_RESOURCE_ADDED_NOTIFICATION);
      if ( v37 )
        v21 = (_WORD *)WmipCountedToSz(v37);
      else
        v21 = 0;
      if ( a5 )
        v22 = (_WORD *)WmipCountedToSz(a5);
      else
        v22 = 0;
      if ( v21 )
      {
        if ( *v21 && v22 && *v22 && WmipAddMofResource(v5, v21, 0, v22, v33) >= 0 && v33[0] )
          WmipGenerateMofResourceNotification(v21, v22, &GUID_MOF_RESOURCE_ADDED_NOTIFICATION, 1);
        ExFreePoolWithTag((unsigned int)v21);
      }
      if ( v22 )
        ExFreePoolWithTag((unsigned int)v22);
      WmipGenerateRegistrationNotification(v5, 1);
      v5 = 0;
      v17 = 0;
    }
    goto LABEL_30;
  }
  while ( 1 )
  {
    v13 = *(_DWORD *)(v11 + 16);
    if ( (v13 & 0x10000) != 0 || (v13 & 0x80000) != 0 && (v13 & 0x1000) == 0 )
      goto LABEL_11;
    v14 = (_DWORD *)WmipAllocEntry(&WmipISChunkInfo);
    v15 = (int)v14;
    if ( !v14 )
      break;
    v16 = v14[2];
    v14[7] = v11;
    v14[8] = v5;
    v14[2] = v16 | 8;
    v17 = WmipBuildInstanceSet(v11, a2, v6, v14, v5[7]);
    if ( !memcmp(v11, (unsigned int)WmipBinaryMofGuid, 16) )
      v35 = v15;
    HIDWORD(v25) = v5 + 5;
    LODWORD(v25) = v5[5];
    v26 = v15 + 20;
    *(_QWORD *)(v15 + 20) = v25;
    if ( *(_DWORD **)(v25 + 4) != v5 + 5 )
      __fastfail(3u);
    *(_DWORD *)(v25 + 4) = v26;
    *(_DWORD *)HIDWORD(v25) = v26;
    if ( v17 < 0 )
      goto LABEL_48;
    v6 = v36;
LABEL_11:
    ++v12;
    v11 += 28;
    if ( v12 >= *(_DWORD *)(a2 + 16) )
      goto LABEL_12;
  }
  v17 = -1073741670;
LABEL_48:
  v19 = v34;
LABEL_30:
  if ( v5 )
  {
    if ( v19 )
    {
      v5[2] |= 1u;
      WmipUnreferenceEntry((int *)&WmipDSChunkInfo, v5);
    }
  }
  return v17;
}
