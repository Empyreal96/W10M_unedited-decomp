// SmKmStoreFileCreate 
 
int __fastcall SmKmStoreFileCreate(int a1, int a2, unsigned int a3, unsigned int a4, __int64 *a5, int a6, int *a7, _DWORD *a8, _DWORD *a9, unsigned int *a10, int a11)
{
  int v14; // r6
  int v15; // r5
  int v16; // r8
  __int64 v17; // kr00_8
  int v18; // r3
  int v19; // r4
  int v20; // r0
  __int64 v21; // r2
  __int64 v22; // r0
  _DWORD *v23; // r5
  int v24; // r1
  __int64 v25; // r2
  int v26; // r1
  __int64 v27; // r2
  _DWORD *v28; // r2
  __int64 v30; // [sp+18h] [bp-C8h] BYREF
  unsigned int v31; // [sp+20h] [bp-C0h]
  unsigned int v32; // [sp+24h] [bp-BCh] BYREF
  int v33; // [sp+28h] [bp-B8h]
  int v34; // [sp+30h] [bp-B0h]
  int v35; // [sp+34h] [bp-ACh]
  int v36; // [sp+38h] [bp-A8h] BYREF
  __int64 v37[4]; // [sp+40h] [bp-A0h] BYREF
  __int64 *v38; // [sp+60h] [bp-80h]
  _DWORD *v39; // [sp+64h] [bp-7Ch]
  int v40; // [sp+68h] [bp-78h]
  _DWORD *v41; // [sp+6Ch] [bp-74h]
  unsigned int *v42; // [sp+70h] [bp-70h]
  int *v43; // [sp+74h] [bp-6Ch]
  int v44; // [sp+78h] [bp-68h]
  _DWORD *v45; // [sp+7Ch] [bp-64h]
  __int64 v46; // [sp+80h] [bp-60h]
  __int64 v47; // [sp+88h] [bp-58h]
  int v48[6]; // [sp+90h] [bp-50h] BYREF
  __int64 v49; // [sp+B0h] [bp-30h]

  v40 = a1;
  v41 = a8;
  v38 = a5;
  v39 = a9;
  v42 = a10;
  v43 = a7;
  v31 = a3;
  v32 = a4;
  v45 = (_DWORD *)a11;
  memset(v37, 0, sizeof(v37));
  v14 = *a7;
  v35 = 0;
  v36 = v14;
  v34 = 0;
  v44 = IoSetThreadHardErrorMode(0);
  if ( (a2 & 1) != 0 )
  {
    v17 = *(_QWORD *)(a2 & 0xFFFFFFFE);
    v15 = HIDWORD(v17);
    v16 = v17;
    v18 = *(_DWORD *)((a2 & 0xFFFFFFFE) + 20);
    v37[0] = v17;
    HIDWORD(v37[2]) = v18;
    memset((_BYTE *)(a2 & 0xFFFFFFFE), 0, 32);
    a2 = 0;
    v30 = -1i64;
  }
  else
  {
    v16 = v37[0];
    LODWORD(v30) = *(_DWORD *)a5;
    v15 = HIDWORD(v37[0]);
    HIDWORD(v30) = *((_DWORD *)a5 + 1);
  }
  if ( a4 > a3 )
  {
    v19 = -1073741811;
    goto LABEL_43;
  }
  if ( a2 )
  {
    v19 = SmKmStoreFileCreateForIoType(v37, a2, &v36);
    if ( v19 < 0 )
      goto LABEL_43;
    v34 = 1;
    v16 = v37[0];
    v46 = v30;
    v19 = ZwSetInformationFile();
    v15 = HIDWORD(v37[0]);
    if ( v19 == 259 )
    {
      KeWaitForSingleObject(HIDWORD(v37[0]) + 92, 0, 0, 0, 0);
      v19 = v33;
    }
    if ( v19 < 0 )
    {
LABEL_42:
      SmKmStoreFileDelete(v37);
      goto LABEL_43;
    }
    v14 = v36;
    if ( v36 )
    {
      v47 = v30;
      v20 = ZwSetInformationFile();
      if ( v20 == 259 )
      {
        KeWaitForSingleObject(v15 + 92, 0, 0, 0, 0);
        v20 = v33;
      }
      if ( v20 < 0 )
        v35 = 1;
    }
    v21 = v30;
LABEL_21:
    if ( !v31 )
      __brkdiv0();
    LODWORD(v22) = _rt_sdiv64(v31, v21);
    if ( v22 < 0xFFFFFFFFi64 )
    {
      memset(v48, 0, sizeof(v48));
      v19 = ZwQueryVolumeInformationFile();
      if ( v19 == 259 )
      {
        KeWaitForSingleObject(v15 + 92, 0, 0, 0, 0);
        v19 = v33;
      }
      if ( v19 >= 0 )
      {
        if ( !v48[5] || ((v48[5] - 1) & v48[5]) != 0 || v48[5] > v32 || v48[5] > v31 || v48[5] > 0x1000u )
        {
          v19 = -1070071787;
        }
        else
        {
          v19 = ((int (__fastcall *)(int, int, __int64 *, unsigned int, unsigned int))SmKmStoreFileGetExtents)(
                  v16,
                  v15,
                  &v30,
                  v31,
                  v32);
          if ( v19 >= 0 )
          {
            if ( v14 || (v19 = SmKmStoreFileOpenVolume(HIDWORD(v37[0]), &v37[1], (char *)&v37[1] + 4), v19 >= 0) )
            {
              if ( !a2 || (v19 = SmKmStoreFileWriteHeader(v37, v14), v19 >= 0) )
              {
                v19 = IoRegisterPlugPlayNotification(
                        3,
                        0,
                        (void **)HIDWORD(v37[0]),
                        v40,
                        (int)SmcVolumePnpNotification,
                        0,
                        (unsigned __int16 *)&v32);
                if ( v19 >= 0 )
                {
                  v23 = v41;
                  LODWORD(v37[2]) = v32;
                  v24 = HIDWORD(v37[0]);
                  v25 = v37[1];
                  *v41 = v37[0];
                  v23[1] = v24;
                  *((_QWORD *)v23 + 1) = v25;
                  v23 += 4;
                  v26 = HIDWORD(v37[2]);
                  v27 = v37[3];
                  *v23 = v37[2];
                  v23[1] = v26;
                  *((_QWORD *)v23 + 1) = v27;
                  memset(v37, 0, sizeof(v37));
                  v19 = 0;
                  *v39 = v48[5];
                  *v42 = v31;
                  *v38 = v30;
                  v28 = v45;
                  *v43 = v14;
                  *v28 = v35;
                  goto LABEL_43;
                }
              }
            }
          }
        }
      }
    }
    else
    {
      v19 = -1073741811;
    }
    if ( !v34 )
      goto LABEL_43;
    goto LABEL_42;
  }
  v19 = ZwQueryInformationFile();
  if ( v19 == 259 )
  {
    KeWaitForSingleObject(v15 + 92, 0, 0, 0, 0);
    v19 = v33;
  }
  if ( v19 >= 0 )
  {
    v21 = v49;
    v30 = v49;
    goto LABEL_21;
  }
LABEL_43:
  SmKmFileInfoCleanup(v37);
  IoSetThreadHardErrorMode(v44);
  return v19;
}
