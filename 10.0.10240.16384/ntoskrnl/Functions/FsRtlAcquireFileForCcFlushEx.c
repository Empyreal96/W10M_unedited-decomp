// FsRtlAcquireFileForCcFlushEx 
 
int __fastcall FsRtlAcquireFileForCcFlushEx(_DWORD *a1)
{
  int v2; // r9
  int v3; // r0
  int v4; // r3
  int v5; // r8
  _DWORD *v6; // r7
  unsigned int *v7; // r5
  int v9; // r4
  unsigned int v10; // r2
  int v11; // r0
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r9
  int (*v15)(void); // r3
  int v16; // r0
  int v17; // r3
  int v18; // r4
  int v19; // r0
  bool v20; // zf
  int v21; // r2
  int v22; // r3
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r3
  char v26[4]; // [sp+8h] [bp-158h] BYREF
  _DWORD *v27; // [sp+Ch] [bp-154h]
  int v28; // [sp+10h] [bp-150h]
  char v29[8]; // [sp+18h] [bp-148h] BYREF
  int v30; // [sp+20h] [bp-140h]
  _DWORD *v31; // [sp+24h] [bp-13Ch]
  int v32; // [sp+3Ch] [bp-124h]
  __int16 v33; // [sp+46h] [bp-11Ah]

  v27 = a1;
  v28 = 0;
  v26[0] = 0;
  v2 = IoGetRelatedDeviceObject(a1);
  v3 = IoGetBaseFileSystemDeviceObject(a1);
  v4 = *(_DWORD *)(v3 + 8);
  v5 = v3;
  v6 = *(_DWORD **)(v4 + 40);
  v7 = *(unsigned int **)(*(_DWORD *)(v4 + 24) + 24);
  if ( v2 == v3 )
    return sub_7E59D0();
  v9 = FsFilterCtrlInit((int)v29, 251, v2, (int)v27, (int)v27);
  if ( v9 >= 0 )
  {
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = FsFilterPerformCallbacks((int)v29, 1, 1, v26);
    v14 = (unsigned __int8)v26[0];
    v9 = v11;
    if ( v11 < 0 )
    {
LABEL_20:
      if ( v9 == -1073741808 && v14 )
      {
        v18 = v27[3];
        v19 = *(_DWORD *)(v18 + 8);
        if ( v19 )
        {
          v20 = ExIsResourceAcquiredSharedLite(v19, v12, v13, (int)v27) == 0;
          v23 = *(_DWORD *)(v18 + 8);
          if ( v20 )
            ExAcquireResourceExclusiveLite(v23, 1, v21, v22);
          else
            ExAcquireResourceSharedLite(v23, 1);
        }
        v11 = *(_DWORD *)(v18 + 12);
        if ( v11 )
          v11 = ExAcquireResourceSharedLite(v11, 1);
        v9 = 0;
      }
      if ( v29 )
      {
        if ( v33 )
          FsFilterPerformCompletionCallbacks((int)v29, v9);
        v11 = FsFilterCtrlFree((int)v29);
      }
      if ( v9 < 0 )
      {
        v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v25 = (__int16)(*(_WORD *)(v24 + 0x134) + 1);
        *(_WORD *)(v24 + 308) = v25;
        if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
          KiCheckForKernelApcDelivery(v11);
      }
      return v9;
    }
    if ( v11 )
    {
      if ( v11 == 294 )
        v9 = 0;
      goto LABEL_20;
    }
    if ( v29 )
    {
      v11 = (int)v31;
      v27 = v31;
      if ( (v32 & 4) == 0 )
        goto LABEL_8;
      v16 = IoGetDeviceAttachmentBaseRef(v30);
      v28 = 1;
      v17 = *(_DWORD *)(v16 + 8);
      v5 = v16;
      v6 = *(_DWORD **)(v17 + 40);
      v7 = *(unsigned int **)(*(_DWORD *)(v17 + 24) + 24);
    }
    v11 = (int)v27;
LABEL_8:
    if ( !v7 || ((v13 = *v7, *v7 < 0x1C) || !v7[6]) && (v13 < 0x20 || !v7[7]) )
    {
      if ( v6 && *v6 >= 0x6Cu && (v15 = (int (*)(void))v6[26]) != 0 )
      {
        v11 = v15();
        v9 = v11;
      }
      else
      {
        v9 = -1073741808;
      }
      v14 = 1;
    }
    if ( v28 )
      v11 = ObfDereferenceObject(v5);
    goto LABEL_20;
  }
  return v9;
}
