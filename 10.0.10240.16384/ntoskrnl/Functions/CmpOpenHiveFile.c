// CmpOpenHiveFile 
 
int __fastcall CmpOpenHiveFile(int a1, unsigned int a2, _DWORD *a3, int *a4, char a5, int a6, int a7, int *a8)
{
  int v10; // r4
  int v11; // r4
  int v12; // r3
  BOOL v13; // r2
  int v14; // r7
  int v15; // r3
  int v16; // r6
  int v17; // r6
  int v18; // r5
  int v20; // r5
  int v21; // r2
  int v22; // r3
  BOOL v23; // [sp+8h] [bp-C8h]
  int v24; // [sp+Ch] [bp-C4h]
  int v25; // [sp+20h] [bp-B0h] BYREF
  int v26; // [sp+28h] [bp-A8h] BYREF
  int v27; // [sp+2Ch] [bp-A4h]
  unsigned int v28; // [sp+30h] [bp-A0h] BYREF
  int v29; // [sp+34h] [bp-9Ch] BYREF
  int v30[2]; // [sp+38h] [bp-98h] BYREF
  _DWORD *v31; // [sp+40h] [bp-90h]
  int *v32; // [sp+44h] [bp-8Ch]
  int v33; // [sp+48h] [bp-88h]
  int v34; // [sp+4Ch] [bp-84h]
  int *v35; // [sp+50h] [bp-80h]
  int v36[16]; // [sp+58h] [bp-78h] BYREF
  __int64 v37; // [sp+A0h] [bp-30h]

  v34 = a6;
  v35 = a4;
  v31 = a3;
  v32 = a8;
  *a3 = 0;
  if ( a2 < 6 )
  {
    v10 = CmpCreateEvent(0, &v29, &v28);
    if ( v10 < 0 )
      return v10;
    v11 = CmFileNameExtensions[a2];
    if ( v11 )
    {
      v20 = (unsigned __int16)(*(_WORD *)a1 + 2 * (wcslen((unsigned __int16 *)CmFileNameExtensions[a2]) + 1));
      v27 = ExAllocatePoolWithTag(1, v20, 1651985731);
      if ( !v27 )
      {
        v10 = -1073741670;
LABEL_33:
        ZwClose();
        ObfDereferenceObject(v28);
        return v10;
      }
      LOWORD(v26) = 0;
      HIWORD(v26) = v20;
      RtlAppendUnicodeStringToString((unsigned __int16 *)&v26, (unsigned __int16 *)a1);
      RtlAppendUnicodeToString((unsigned __int16 *)&v26, v11, v21, v22);
    }
    else
    {
      v26 = *(_DWORD *)a1;
      v27 = *(_DWORD *)(a1 + 4);
    }
    v36[0] = 24;
    v12 = 0;
    v36[1] = 0;
    if ( (a5 & 0x40) != 0 )
      v12 = 1024;
    v36[3] = v12 | 0x240;
    v36[4] = a7;
    v36[2] = (int)&v26;
    v36[5] = 0;
    v13 = (a5 & 0x20) != 0 && (a5 & 0x80) == 0;
    if ( a2 )
    {
      v14 = 6;
      if ( (a5 & 0x20) != 0 )
      {
        v15 = 1;
      }
      else if ( (a5 & 0x10) != 0 )
      {
        v15 = 0;
      }
      else
      {
        v15 = 3;
      }
      v16 = 32780;
    }
    else
    {
      v14 = 128;
      if ( (a5 & 1) == 0 || (a5 & 0x20) != 0 )
        v15 = 1;
      else
        v15 = 3;
      v16 = 49188;
    }
    v24 = v15;
    v23 = v13;
    v10 = ZwCreateFile();
    if ( v10 == -1073741790 )
      v10 = CmpOpenFileWithExtremePrejudice(&v25, v36, v30, v14, v16, v14, v23, v24, v16, 0, 0);
    if ( v10 < 0 )
    {
LABEL_30:
      if ( v27 )
      {
        if ( v27 != *(_DWORD *)(a1 + 4) )
          ExFreePoolWithTag(v27);
      }
      goto LABEL_33;
    }
    v17 = v30[1];
    if ( (a5 & 0x28) == 0 )
    {
      v36[6] = -1;
      v36[7] = -1;
      v36[8] = -1;
      v36[9] = -1;
      v36[10] = -1;
      v36[11] = -1;
      v36[12] = -1;
      v36[13] = -1;
      v36[14] = 0;
      ZwSetInformationFile();
    }
    if ( (a5 & 2) == 0 || (a5 & 0x20) != 0 )
      goto LABEL_19;
    v10 = ZwFsControlFile();
    if ( v10 == 259 )
    {
      KeWaitForSingleObject(v28, 0, 0, 0, 0);
      v10 = v30[0];
    }
    if ( v10 >= 0 || v10 == -1073741808 )
    {
LABEL_19:
      v33 = 0;
      if ( ZwFsControlFile() == 259 )
        KeWaitForSingleObject(v28, 0, 0, 0, 0);
      if ( a2 )
        goto LABEL_29;
      if ( v17 != 2 && ZwQueryInformationFile() >= 0 && !v37 )
        v17 = 2;
      v18 = v34;
      if ( !v34 )
        goto LABEL_27;
      v10 = CmpGetVolumeClusterSize(v25, v34);
      if ( v10 >= 0 )
      {
        *(_DWORD *)(v18 + 4) = CmpGetVolumeLogFileSizeCap(v25);
LABEL_27:
        if ( !v32 || (v10 = CmpQueryFileSecurityDescriptor(v25, v32), v10 >= 0) )
        {
LABEL_29:
          v10 = 0;
          *v31 = v25;
          *v35 = v17;
          goto LABEL_30;
        }
        goto LABEL_55;
      }
    }
LABEL_55:
    ZwClose();
    goto LABEL_30;
  }
  return sub_7C35A4();
}
