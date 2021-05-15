// PiCMCreateDevice 
 
int __fastcall PiCMCreateDevice(unsigned int a1, unsigned int a2, int a3, unsigned int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r9
  int v7; // r5
  unsigned __int16 *v8; // r6
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r7
  unsigned __int16 *v13; // r10
  unsigned __int16 *v14; // r8
  int v15; // r1
  int v16; // r2
  int v17; // r4
  int v18; // r0
  unsigned int v19; // r3
  int v20; // r4
  char v22; // r9
  BOOL v23; // r7
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r3
  int v30; // r0
  int v31; // r0
  int v32; // r0
  int v33; // r1
  char v34; // r3
  int v35; // r0
  int v36; // r3
  unsigned int v37; // r0
  _WORD *v38; // r9
  int v39; // r2
  char v40[4]; // [sp+18h] [bp-90h] BYREF
  int v41; // [sp+1Ch] [bp-8Ch] BYREF
  int v42; // [sp+20h] [bp-88h] BYREF
  unsigned int v43; // [sp+24h] [bp-84h] BYREF
  int v44[2]; // [sp+28h] [bp-80h] BYREF
  int v45[2]; // [sp+30h] [bp-78h] BYREF
  unsigned int v46; // [sp+38h] [bp-70h]
  int v47; // [sp+3Ch] [bp-6Ch]
  int v48; // [sp+40h] [bp-68h] BYREF
  int v49; // [sp+44h] [bp-64h]
  int v50; // [sp+48h] [bp-60h] BYREF
  unsigned int v51; // [sp+4Ch] [bp-5Ch]
  unsigned __int16 v52[4]; // [sp+50h] [bp-58h] BYREF
  int v53; // [sp+58h] [bp-50h] BYREF
  char v54[4]; // [sp+60h] [bp-48h] BYREF
  int v55; // [sp+64h] [bp-44h]
  unsigned __int16 *v56; // [sp+68h] [bp-40h]
  unsigned int v57; // [sp+6Ch] [bp-3Ch]
  unsigned __int16 *v58; // [sp+70h] [bp-38h]
  unsigned int v59; // [sp+74h] [bp-34h]
  int v60; // [sp+78h] [bp-30h]
  int v61; // [sp+7Ch] [bp-2Ch] BYREF
  int v62; // [sp+80h] [bp-28h] BYREF
  int v63[9]; // [sp+84h] [bp-24h] BYREF

  v6 = a4;
  v46 = a4;
  v47 = a3;
  v7 = 0;
  *a6 = 0;
  v48 = 0;
  v49 = 0;
  v45[0] = 0;
  v41 = 0;
  v42 = 0;
  v50 = 0;
  v8 = 0;
  v51 = 0;
  v12 = PiCMCaptureCreateDeviceInputData(a1, a2, 0, (int)v54);
  v13 = v58;
  v14 = v56;
  if ( v12 < 0 )
    goto LABEL_12;
  if ( !PiAuDoesClientHaveAccess(2, v9, v10, v11) )
  {
    v17 = -1073741790;
    goto LABEL_4;
  }
  if ( !v14 || v57 < 2 || !v13 || v59 < 2 )
  {
    v17 = -1073741811;
    goto LABEL_84;
  }
  if ( !v47
    || v6 < 0x14
    || (v22 = v55, (v55 & 0xFFFFFFF0) != 0)
    || (v23 = (v55 & 2) != 0, !CmIsRootDevice(v13, v15, v16, 0)) )
  {
    v17 = -1073741811;
    goto LABEL_4;
  }
  v17 = PiPnpRtlBeginOperation(&v41, v24, v25, v26);
  if ( v17 < 0 )
    goto LABEL_33;
  v27 = ExAllocatePoolWithTag(1, 400, 879783504);
  v8 = (unsigned __int16 *)v27;
  if ( !v27 )
  {
LABEL_32:
    v17 = -1073741670;
    goto LABEL_33;
  }
  if ( (v22 & 4) != 0 )
  {
    v17 = PiCMGenerateDeviceInstance(v14, v23, v27);
    if ( v23 )
      goto LABEL_81;
  }
  else
  {
    v17 = CmValidateDeviceName(v27, v14, v28, v29);
  }
  if ( v17 < 0 )
    goto LABEL_33;
  if ( (v22 & 4) == 0 )
  {
    v17 = RtlStringCchCopyExW(v8, 200, v14);
    if ( v17 < 0 )
      goto LABEL_33;
  }
  v30 = CmOpenDeviceRegKey(PiPnpRtlCtx, (int)v8, 16, 0, 131103, 0, (int)&v42, 0);
  v17 = v30;
  if ( v30 >= 0 || v30 == -1073741810 )
  {
    if ( v23 )
    {
      if ( v42 )
      {
LABEL_45:
        v17 = -1073741771;
        goto LABEL_33;
      }
      v40[0] = 0;
      v31 = CmCreateDevice(PiPnpRtlCtx, (int)v8, 131078, v45, v40, 0);
      v17 = v31;
      if ( v31 < 0 )
        goto LABEL_33;
      if ( !v40[0] )
      {
        v17 = -1073741771;
        ZwClose();
        goto LABEL_33;
      }
      v53 = 1;
      v17 = PnpCtxRegSetValue(v31, v45[0], (int)L"Phantom", 4, (int)&v53, 4);
      ZwClose();
      goto LABEL_81;
    }
    if ( v42 )
    {
      v32 = CmGetDeviceStatus(PiPnpRtlCtx, v8, v42, &v61, v63, &v62);
      if ( v32 >= 0 )
        goto LABEL_45;
      if ( v32 == -1073741810 )
        PiPnpRtlEnsureObjectCached(-1073741810, v8);
    }
    else
    {
      v40[0] = 0;
      v17 = CmCreateDevice(PiPnpRtlCtx, (int)v8, 131103, &v42, v40, 0);
      if ( v17 < 0 )
        goto LABEL_33;
      if ( !v40[0] )
        goto LABEL_45;
    }
    v17 = RtlInitUnicodeStringEx((int)v52, v8);
    if ( v17 >= 0 )
    {
      v43 = 4;
      v44[0] = 0;
      if ( CmGetDeviceRegProp(PiPnpRtlCtx, (int)v8, v42, 11, (int)v44, (int)&v48, (int)&v43) < 0 )
        v48 = 0;
      if ( PnpGetDeviceInstanceCsConfigFlags(v52, v33, v45) >= 0 )
        v34 = v45[0];
      else
        v34 = 0;
      if ( (v34 & 2) != 0 || (v48 & 0x12) != 0 )
      {
        v17 = -1073741808;
        goto LABEL_33;
      }
      v35 = PiInitializeDevice(v52);
      v17 = v35;
      if ( v35 >= 0 )
      {
        v43 = 4;
        if ( PnpCtxRegQueryValue(v35, v42, L"Phantom", v44, (int)v45, &v43) >= 0 && v44[0] == 4 && v43 == 4 )
          v36 = v45[0];
        else
          v36 = 0;
        if ( v36 && RtlInitUnicodeStringEx((int)v45, L"Phantom") >= 0 )
          ZwDeleteValueKey();
        if ( (v22 & 8) != 0 )
        {
          v43 = 512;
          v37 = ExAllocatePoolWithTag(1, 512, 879783504);
          v38 = (_WORD *)v37;
          v51 = v37;
          if ( !v37 )
            goto LABEL_32;
          if ( CmGetDeviceRegProp(PiPnpRtlCtx, (int)v8, v42, 5, (int)v44, v37, (int)&v43) >= 0
            && v44[0] == 1
            && v43 <= 0x200
            && *v38 )
          {
            v17 = RtlInitUnicodeStringEx((int)v52, v8);
            if ( v17 < 0 )
              goto LABEL_33;
            v17 = PpDeviceRegistration((int)v52, 1, 0, 0);
          }
        }
        goto LABEL_81;
      }
    }
LABEL_33:
    v7 = v41;
    goto LABEL_4;
  }
LABEL_81:
  v7 = v41;
  v6 = v46;
LABEL_84:
  if ( v17 >= 0 )
  {
    v17 = RtlStringCchLengthW(v8, 0xC8u, &v50);
    if ( v17 < 0 )
    {
      v39 = 0;
      v49 = 0;
    }
    else
    {
      v39 = v50 + 1;
      v49 = v50 + 1;
      if ( v6 - 20 < 2 * (v50 + 1) )
        v17 = -1073741789;
    }
    if ( v17 >= 0 )
    {
      v18 = PiCMReturnBufferResultData(v17, 2 * v39, 0, (int)v8, 2 * v39, v60, v47, v6, a6);
      goto LABEL_5;
    }
  }
LABEL_4:
  v18 = PiCMReturnBufferResultData(v17, 2 * v49, 0, 0, 0, v60, v47, v46, a6);
LABEL_5:
  v12 = v18;
  if ( v42 )
    ZwClose();
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  if ( v51 )
    ExFreePoolWithTag(v51);
  v13 = v58;
  v14 = v56;
LABEL_12:
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = *(char *)(v19 + 346);
  if ( v14 && *(_BYTE *)(v19 + 346) )
    ExFreePoolWithTag((unsigned int)v14);
  if ( v13 && v20 )
    ExFreePoolWithTag((unsigned int)v13);
  if ( v7 )
    PiPnpRtlEndOperation(v7);
  return v12;
}
