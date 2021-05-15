// FsRtlAcquireFileForModWriteEx 
 
int __fastcall FsRtlAcquireFileForModWriteEx(_DWORD *a1, int a2, int *a3)
{
  int v4; // r4
  int v5; // r6
  int v6; // r10
  int v7; // r0
  int v8; // r3
  int *v9; // r9
  _DWORD *v10; // r5
  int v12; // r8
  int v13; // r10
  int v14; // r0
  int v15; // r3
  int v16; // r2
  int v17; // r10
  int (__fastcall *v18)(int, int, int *, int, int, int); // r4
  int v19; // r5
  int v20; // r2
  __int64 v21; // kr00_8
  __int64 v22; // kr10_8
  int v23; // r4
  int v24; // r6
  int v25; // r0
  int v26; // r0
  int v27; // r0
  int v28; // r3
  int v29; // [sp+0h] [bp-168h]
  int v30; // [sp+4h] [bp-164h]
  char v31[4]; // [sp+8h] [bp-160h] BYREF
  int v32; // [sp+Ch] [bp-15Ch]
  int *v33; // [sp+10h] [bp-158h]
  int v34; // [sp+14h] [bp-154h]
  char *v35; // [sp+18h] [bp-150h]
  _DWORD *v36; // [sp+1Ch] [bp-14Ch]
  char v37[8]; // [sp+20h] [bp-148h] BYREF
  int v38; // [sp+28h] [bp-140h]
  int v39; // [sp+2Ch] [bp-13Ch]
  int v40; // [sp+30h] [bp-138h]
  int *v41; // [sp+34h] [bp-134h]
  int v42; // [sp+44h] [bp-124h]

  v4 = 0;
  v5 = 0;
  v35 = v37;
  v36 = a1;
  v31[0] = 0;
  v32 = a2;
  v33 = a3;
  v6 = IoGetRelatedDeviceObject(a1);
  v7 = IoGetBaseFileSystemDeviceObject(a1);
  v8 = *(_DWORD *)(v7 + 8);
  v34 = v7;
  v9 = *(int **)(v8 + 40);
  v10 = *(_DWORD **)(*(_DWORD *)(v8 + 24) + 24);
  if ( v10 && (*v10 >= 0x2Cu && v10[10] || *v10 >= 0x30u && v10[11]) )
    return sub_53B168();
  if ( v6 == v7 )
  {
    v15 = 0;
    v16 = v42;
    v12 = (int)v36;
    v35 = 0;
    goto LABEL_13;
  }
  v12 = (int)v36;
  v29 = (int)v36;
  v30 = 1;
  v4 = FsFilterCtrlInit(v37, 253, v6);
  if ( v4 < 0 )
    return v4;
  v13 = v32;
  v40 = v32;
  v41 = v33;
  v14 = FsFilterPerformCallbacks(v37, 1, 1, v31);
  v4 = v14;
  if ( v14 >= 0 )
  {
    if ( !v14 )
    {
      v16 = v42;
      v12 = v39;
      if ( (v42 & 4) != 0 )
      {
        v7 = IoGetDeviceAttachmentBaseRef(v38);
        v28 = *(_DWORD *)(v7 + 8);
        v16 = v42;
        v5 = (unsigned __int8)v31[0];
        v9 = *(int **)(v28 + 40);
        v15 = *(_DWORD *)(v28 + 24);
        v34 = v7;
        v17 = 1;
        v10 = *(_DWORD **)(v15 + 24);
LABEL_14:
        if ( !v10 || (*v10 < 0x2Cu || (v15 = v10[10]) == 0) && (*v10 < 0x30u || (v15 = v10[11]) == 0) )
        {
          if ( v9
            && (v15 = *v9, (unsigned int)*v9 >= 0x40)
            && (v18 = (int (__fastcall *)(int, int, int *, int, int, int))v9[15]) != 0 )
          {
            v27 = v18(v12, v32, v33, v7, v29, v30);
            v16 = v42;
            v4 = v27;
          }
          else
          {
            v4 = -1073741808;
          }
          v5 = 1;
        }
        if ( v17 )
        {
          ObfDereferenceObjectWithTag(v34);
          v16 = v42;
        }
        v13 = v32;
        goto LABEL_27;
      }
      v5 = (unsigned __int8)v31[0];
      v7 = v34;
LABEL_13:
      v17 = 0;
      goto LABEL_14;
    }
    if ( v14 == 294 )
      v4 = 0;
  }
  v16 = v42;
  v5 = (unsigned __int8)v31[0];
LABEL_27:
  if ( v4 != -1073741808 || !v5 )
    goto LABEL_48;
  v19 = *(_DWORD *)(v12 + 12);
  if ( !*(_DWORD *)(v19 + 8) )
  {
    v4 = 0;
    *v33 = 0;
    goto LABEL_48;
  }
  v20 = *(unsigned __int8 *)(v19 + 4);
  if ( (v20 & 8) != 0
    || (v21 = *(_QWORD *)(v19 + 32), v15 = *(_DWORD *)(v13 + 4), *(_QWORD *)v13 > v21)
    && (v22 = *(_QWORD *)(v19 + 24), v15 = v22, v21 != v22) )
  {
    v24 = 1;
  }
  else
  {
    if ( (v20 & 0x10) == 0 )
    {
      v23 = *(_DWORD *)(v19 + 12);
      if ( v23 )
      {
        v24 = 0;
        goto LABEL_36;
      }
    }
    v24 = 0;
  }
  v23 = *(_DWORD *)(v19 + 8);
  while ( 1 )
  {
LABEL_36:
    if ( v24 )
      v25 = ExAcquireResourceExclusiveLite(v23, 0, v20, v15);
    else
      v25 = ExAcquireSharedWaitForExclusive(v23, 0);
    if ( !v25 )
      goto LABEL_56;
    if ( (*(_BYTE *)(v19 + 4) & 8) != 0 || *(_QWORD *)v13 > *(_QWORD *)(v19 + 32) )
    {
      if ( v24 )
        goto LABEL_46;
      goto LABEL_42;
    }
    if ( (*(_BYTE *)(v19 + 4) & 0x10) == 0 )
      break;
    if ( v24 )
      goto LABEL_74;
    if ( v23 == *(_DWORD *)(v19 + 8) )
      goto LABEL_46;
LABEL_42:
    ExpReleaseResourceForThreadLite(v23, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v23 = *(_DWORD *)(v19 + 8);
    v24 = 1;
  }
  v26 = *(_DWORD *)(v19 + 12);
  if ( v23 == v26 || !v26 )
  {
    if ( v24 )
LABEL_74:
      ExConvertExclusiveToSharedLite(v23);
LABEL_46:
    *v33 = v23;
    v4 = 0;
    goto LABEL_47;
  }
  v23 = 0;
  if ( ExAcquireSharedWaitForExclusive(v26, 0) )
    v23 = *(_DWORD *)(v19 + 12);
  ExpReleaseResourceForThreadLite(*(_DWORD *)(v19 + 8), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( v23 )
    goto LABEL_46;
LABEL_56:
  v4 = -1073741608;
LABEL_47:
  v16 = v42;
LABEL_48:
  if ( v35 )
  {
    if ( *((_WORD *)v35 + 23) )
    {
      FsFilterPerformCompletionCallbacks(v37, v4, v16);
      LOBYTE(v16) = v42;
    }
    if ( (v16 & 1) != 0 )
      FsFilterFreeCompletionStack(v37);
  }
  return v4;
}
