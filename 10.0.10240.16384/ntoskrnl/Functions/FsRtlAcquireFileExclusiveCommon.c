// FsRtlAcquireFileExclusiveCommon 
 
int __fastcall FsRtlAcquireFileExclusiveCommon(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r5
  char *v7; // r8
  int v8; // r10
  int v9; // r6
  int v10; // r1
  int v11; // r3
  int v12; // r4
  _DWORD *v13; // r0
  int v14; // r4
  unsigned int *v15; // r7
  int result; // r0
  int v17; // r10
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v20; // r6
  int v21; // r3
  int v22; // r9
  int (__fastcall *v23)(int); // r3
  int v24; // r3
  unsigned int v25; // r1
  int v26; // r3
  char v27[4]; // [sp+8h] [bp-160h] BYREF
  int v28; // [sp+Ch] [bp-15Ch]
  _DWORD *v29; // [sp+10h] [bp-158h]
  int v30; // [sp+14h] [bp-154h]
  _DWORD *v31; // [sp+18h] [bp-150h]
  int v32; // [sp+1Ch] [bp-14Ch]
  char v33[8]; // [sp+20h] [bp-148h] BYREF
  int v34; // [sp+28h] [bp-140h]
  int v35; // [sp+2Ch] [bp-13Ch]
  int v36; // [sp+30h] [bp-138h]
  int v37; // [sp+34h] [bp-134h]
  int v38; // [sp+38h] [bp-130h]
  int v39; // [sp+44h] [bp-124h]

  v32 = a4;
  v5 = 0;
  v27[0] = 0;
  v29 = a1;
  v30 = a3;
  v7 = v33;
  v8 = 0;
  v9 = IoGetRelatedDeviceObject(a1);
  v10 = IoGetBaseFileSystemDeviceObject(a1);
  v12 = *(_DWORD *)(v10 + 8);
  v28 = v10;
  v13 = *(_DWORD **)(v12 + 40);
  v14 = *(_DWORD *)(v12 + 24);
  v31 = v13;
  v15 = *(unsigned int **)(v14 + 24);
  if ( v15 )
  {
    if ( *v15 < 0xC )
      return sub_802AB8();
    v11 = v15[2];
    if ( !v11 )
      return sub_802AB8();
    v8 = 1;
  }
  if ( v9 == v10 && !v8 )
  {
    v7 = 0;
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v19 + 308);
    v17 = (int)v29;
    v20 = 0;
    goto LABEL_27;
  }
  v17 = (int)v29;
  result = FsFilterCtrlInit((int)v33, 255, v9, v11, (int)v29);
  if ( result < 0 )
    return result;
  v36 = a2;
  v37 = v30;
  v38 = v32;
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v18 + 308);
  v13 = (_DWORD *)FsFilterPerformCallbacks((int)v33, a2 == 1, a2 == 1, v27);
  v5 = (int)v13;
  if ( (int)v13 < 0 )
    goto LABEL_17;
  if ( !v13 )
  {
    v17 = v35;
    if ( (v39 & 4) != 0 )
    {
      v10 = IoGetDeviceAttachmentBaseRef(v34);
      v21 = *(_DWORD *)(v10 + 8);
      v20 = (unsigned __int8)v27[0];
      v28 = v10;
      v13 = *(_DWORD **)(v21 + 40);
      v22 = 1;
      v15 = *(unsigned int **)(*(_DWORD *)(v21 + 24) + 24);
      goto LABEL_28;
    }
    v20 = (unsigned __int8)v27[0];
    v10 = v28;
    v13 = v31;
LABEL_27:
    v22 = 0;
LABEL_28:
    if ( !v15 || ((v19 = *v15, *v15 < 0xC) || !v15[2]) && (v19 < 0x10 || !v15[3]) )
    {
      if ( v13 && *v13 >= 0x30u && (v23 = (int (__fastcall *)(int))v13[11]) != 0 )
      {
        v13 = (_DWORD *)v23(v17);
        v10 = v28;
      }
      else
      {
        v5 = -1073741808;
      }
      v20 = 1;
    }
    if ( v22 )
      v13 = (_DWORD *)ObfDereferenceObject(v10);
LABEL_18:
    if ( v5 == -1073741808 && v20 )
    {
      v24 = *(_DWORD *)(v17 + 12);
      if ( v24 )
      {
        v13 = *(_DWORD **)(v24 + 8);
        if ( v13 )
          v13 = (_DWORD *)ExAcquireResourceExclusiveLite((int)v13, 1, v19, v24);
      }
      v5 = 0;
    }
    if ( !v7 )
      goto LABEL_15;
    goto LABEL_12;
  }
  if ( v13 != (_DWORD *)294 )
  {
LABEL_17:
    v20 = (unsigned __int8)v27[0];
    goto LABEL_18;
  }
  v5 = 0;
LABEL_12:
  if ( *((_WORD *)v7 + 23) )
    FsFilterPerformCompletionCallbacks((int)v33, v5);
  v13 = (_DWORD *)FsFilterCtrlFree((int)v33);
LABEL_15:
  if ( v5 < 0 )
  {
    v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
    *(_WORD *)(v25 + 308) = v26;
    if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
      KiCheckForKernelApcDelivery((int)v13);
  }
  return v5;
}
