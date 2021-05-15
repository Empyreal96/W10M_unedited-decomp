// PipInitComputerIds 
 
int __fastcall PipInitComputerIds(int a1)
{
  int v2; // r6
  unsigned int v3; // r8
  int v4; // r9
  int v5; // r10
  unsigned int v6; // r5
  int v7; // r4
  int v8; // r2
  __int64 v10; // r0
  int v11; // r9
  int v12; // r0
  int v13; // r8
  int v14; // r0
  int v15; // r6
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r6
  int v22; // r0
  unsigned __int8 *v23; // r6
  int v24; // r0
  int v25; // r0
  unsigned int v26; // r2
  int v27; // r0
  int v28; // r8
  int *v29; // r6
  int v30; // r7
  int v31; // r2
  int v32; // r1
  unsigned int v33; // r5
  const __int16 *v34; // r0
  unsigned int v35; // r7
  const __int16 *v36; // r2
  unsigned int v37; // r10
  _OWORD *v38; // r9
  int v39; // r3
  int *v40; // r5
  int v41; // r7
  int v42; // r0
  int v43; // r0
  int *v44; // [sp+0h] [bp-1D0h]
  int v45; // [sp+0h] [bp-1D0h]
  int v46; // [sp+0h] [bp-1D0h]
  int v47; // [sp+18h] [bp-1B8h]
  int v48; // [sp+1Ch] [bp-1B4h]
  unsigned __int16 v49; // [sp+20h] [bp-1B0h] BYREF
  __int16 v50; // [sp+22h] [bp-1AEh]
  const __int16 *v51; // [sp+24h] [bp-1ACh]
  int v52; // [sp+28h] [bp-1A8h] BYREF
  int v53; // [sp+2Ch] [bp-1A4h] BYREF
  int v54; // [sp+30h] [bp-1A0h]
  char v55[8]; // [sp+38h] [bp-198h] BYREF
  char v56[8]; // [sp+40h] [bp-190h] BYREF
  int *v57; // [sp+48h] [bp-188h] BYREF
  int *v58; // [sp+4Ch] [bp-184h]
  int *v59; // [sp+50h] [bp-180h]
  int *v60; // [sp+54h] [bp-17Ch]
  int *v61; // [sp+58h] [bp-178h]
  int *v62; // [sp+5Ch] [bp-174h]
  char *v63; // [sp+60h] [bp-170h]
  int v64[16]; // [sp+68h] [bp-168h] BYREF
  _OWORD v65[15]; // [sp+A8h] [bp-128h] BYREF
  unsigned __int16 v66[4]; // [sp+198h] [bp-38h] BYREF
  unsigned __int16 v67[24]; // [sp+1A0h] [bp-30h] BYREF

  v2 = 0;
  v52 = 0;
  v53 = 0;
  v3 = 0;
  v4 = 0;
  v54 = 0;
  v5 = 0;
  v6 = 0;
  memset(v64, 0, sizeof(v64));
  v50 = 96;
  v49 = 94;
  v51 = L"\\Registry\\Machine\\System\\HardwareConfig\\Current";
  v7 = IopOpenRegistryKeyEx(&v53);
  if ( v7 < 0 )
    goto LABEL_91;
  PnpCtxRegDeleteTree((int *)PiPnpRtlCtx, v53, L"ComputerIds");
  v50 = 24;
  v49 = 22;
  v51 = L"ComputerIds";
  v7 = IopCreateRegistryKeyEx(&v52, v53, (int)&v49, 983103, 0, 0);
  if ( v7 < 0 )
    JUMPOUT(0x968714);
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 132) + 36);
  if ( !v8 )
    return sub_96870C();
  v10 = *(_QWORD *)(v8 + 16);
  if ( !v10 )
    return sub_96870C();
  v11 = *(_DWORD *)(v8 + 12);
  v47 = v11;
  v12 = MmMapIoSpaceEx(v10, SHIDWORD(v10), v11, 2);
  v13 = v12;
  v48 = v12;
  if ( !v12 )
  {
    v7 = -1073741670;
    v2 = v52;
    goto LABEL_90;
  }
  v14 = PipSmBiosFindStruct(1, 0, v12, v11);
  v15 = v14;
  if ( v14 )
  {
    if ( v14 + 5 <= (unsigned int)*(unsigned __int8 *)(v14 + 1) + v14 )
    {
      v44 = v64;
      v16 = PipSmBiosGetString(v14);
      v7 = v16;
      if ( v16 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v16 < 0 )
      {
        goto LABEL_134;
      }
    }
    if ( v15 + 27 <= (unsigned int)*(unsigned __int8 *)(v15 + 1) + v15 )
    {
      v44 = &v64[2];
      v17 = PipSmBiosGetString(v15);
      v7 = v17;
      if ( v17 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v17 < 0 )
      {
        goto LABEL_134;
      }
    }
    if ( v15 + 6 <= (unsigned int)*(unsigned __int8 *)(v15 + 1) + v15 )
    {
      v44 = &v64[4];
      v18 = PipSmBiosGetString(v15);
      v7 = v18;
      if ( v18 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v18 < 0 )
      {
        goto LABEL_134;
      }
    }
    if ( v15 + 26 <= (unsigned int)*(unsigned __int8 *)(v15 + 1) + v15 )
    {
      v44 = &v64[6];
      v19 = PipSmBiosGetString(v15);
      v7 = v19;
      if ( v19 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v19 < 0 )
      {
        goto LABEL_134;
      }
    }
  }
  v20 = PipSmBiosFindStruct(2, 10, v13, v11);
  v21 = v20;
  if ( v20 )
  {
    if ( v20 + 5 <= (unsigned int)*(unsigned __int8 *)(v20 + 1) + v20 )
    {
      v44 = &v64[12];
      v42 = PipSmBiosGetString(v20);
      v7 = v42;
      if ( v42 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v42 < 0 )
      {
        goto LABEL_134;
      }
    }
    if ( v21 + 6 <= (unsigned int)*(unsigned __int8 *)(v21 + 1) + v21 )
    {
      v44 = &v64[14];
      v43 = PipSmBiosGetString(v21);
      v7 = v43;
      if ( v43 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v43 < 0 )
      {
        goto LABEL_134;
      }
    }
  }
  v22 = PipSmBiosFindStruct(0, 0, v13, v11);
  v23 = (unsigned __int8 *)v22;
  if ( v22 )
  {
    if ( v22 + 5 <= (unsigned int)*(unsigned __int8 *)(v22 + 1) + v22 )
    {
      v44 = &v64[8];
      v24 = PipSmBiosGetString(v22);
      v7 = v24;
      if ( v24 == -1073741275 )
      {
        v7 = 0;
      }
      else if ( v24 < 0 )
      {
        goto LABEL_134;
      }
    }
    if ( v23 + 6 > &v23[v23[1]] )
      goto LABEL_28;
    v44 = &v64[10];
    v25 = PipSmBiosGetString(v23);
    v7 = v25;
    if ( v25 == -1073741275 )
    {
      v7 = 0;
      goto LABEL_28;
    }
    if ( v25 >= 0 )
    {
LABEL_28:
      v26 = (unsigned int)&v23[v23[1]];
      if ( (unsigned int)(v23 + 21) <= v26 )
        v54 = v23[20];
      if ( (unsigned int)(v23 + 22) <= v26 )
        v5 = v23[21];
      goto LABEL_32;
    }
LABEL_134:
    JUMPOUT(0x968710);
  }
LABEL_32:
  v27 = PipSmBiosFindStruct(3, 0, v13, v11);
  if ( v27 && v27 + 6 <= (unsigned int)*(unsigned __int8 *)(v27 + 1) + v27 )
    v28 = *(_BYTE *)(v27 + 5) & 0x7F;
  else
    v28 = 0;
  v29 = v64;
  v30 = 8;
  do
  {
    if ( v29[1] && !*(_WORD *)v29 )
      RtlFreeAnsiString(v29);
    v29 += 2;
    --v30;
  }
  while ( v30 );
  v31 = v64[1];
  v2 = v52;
  if ( !v64[1] )
  {
LABEL_80:
    v34 = (const __int16 *)ExAllocatePoolWithTag(1, 112 * v6 + 2, 1852403792);
    v35 = (unsigned int)v34;
    if ( v34 )
    {
      v36 = v34;
      v51 = v34;
      v50 = 112 * v6 + 2;
      v37 = 0;
      if ( v6 )
      {
        v38 = v65;
        while ( 1 )
        {
          v49 = 0;
          v7 = RtlUnicodeStringCopyStringEx(&v49, L"ComputerMetadata\\", &v49, 0);
          if ( v7 < 0 )
            break;
          v7 = RtlStringFromGUIDEx((int)v38, (int)&v49, 0);
          if ( v7 < 0 )
            break;
          v7 = RtlUpcaseUnicodeString(&v49, &v49, 0, v39);
          if ( v7 < 0 )
            break;
          v36 = v51 + 39;
          ++v37;
          v51 += 39;
          v50 -= 78;
          ++v38;
          if ( v37 >= v6 )
            goto LABEL_87;
        }
      }
      else
      {
LABEL_87:
        if ( v7 >= 0 )
        {
          *v36 = 0;
          ++v51;
          v7 = PnpSetObjectProperty(
                 PiPnpRtlCtx,
                 (int)L"{00000000-0000-0000-FFFF-FFFFFFFFFFFF}",
                 5,
                 0,
                 0,
                 (int)DEVPKEY_Device_HardwareIds,
                 8210,
                 v35,
                 112 * v6 + 2,
                 0);
        }
      }
      ExFreePoolWithTag(v35);
    }
    else
    {
      v7 = -1073741670;
    }
    goto LABEL_90;
  }
  v32 = v64[5];
  if ( v64[5] && v64[9] && v64[11] )
  {
    v45 = v5;
    v7 = RtlStringCchPrintfW(v67, 8u, (int)L"%02x&%02x", v54);
    if ( v7 < 0 )
      goto LABEL_90;
    RtlInitUnicodeString((unsigned int)v55, v67);
    if ( v64[7] )
    {
      v57 = v64;
      v58 = &v64[2];
      v59 = &v64[4];
      v60 = &v64[6];
      v61 = &v64[8];
      v62 = &v64[10];
      v63 = v55;
      v7 = PipCreateComputerId(v2, &v57, 7, v65, v5);
      v6 = 1;
      if ( v7 < 0 )
        goto LABEL_90;
    }
    v57 = v64;
    v58 = &v64[2];
    v59 = &v64[4];
    v60 = &v64[8];
    v61 = &v64[10];
    v62 = (int *)v55;
    v7 = PipCreateComputerId(v2, &v57, 6, &v65[v6], v45);
    v33 = v6 + 1;
    if ( v7 < 0 )
      goto LABEL_90;
    v57 = v64;
    v58 = &v64[4];
    v59 = &v64[8];
    v60 = &v64[10];
    v61 = (int *)v55;
    v7 = PipCreateComputerId(v2, &v57, 5, &v65[v33], v46);
    v6 = v33 + 1;
    if ( v7 < 0 )
      goto LABEL_90;
    v32 = v64[5];
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( v32 )
  {
    if ( v64[7] )
    {
      if ( v64[13] )
      {
        if ( v64[15] )
        {
          v57 = v64;
          v58 = &v64[2];
          v59 = &v64[4];
          v60 = &v64[6];
          v61 = &v64[12];
          v62 = &v64[14];
          v7 = PipCreateComputerId(v2, &v57, 6, &v65[v6++], v44);
          if ( v7 < 0 )
            goto LABEL_90;
        }
      }
      v57 = v64;
      v58 = &v64[2];
      v59 = &v64[4];
      v60 = &v64[6];
      v7 = PipCreateComputerId(v2, &v57, 4, &v65[v6++], v44);
      if ( v7 < 0 )
        goto LABEL_90;
    }
    v57 = v64;
    v58 = &v64[2];
    v59 = &v64[4];
    v7 = PipCreateComputerId(v2, &v57, 3, &v65[v6++], v44);
    if ( v7 < 0 )
      goto LABEL_90;
    v32 = v64[5];
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( v64[7] )
  {
    if ( v64[13] )
    {
      if ( v64[15] )
      {
        v57 = v64;
        v58 = &v64[6];
        v59 = &v64[12];
        v60 = &v64[14];
        v7 = PipCreateComputerId(v2, &v57, 4, &v65[v6++], v44);
        if ( v7 < 0 )
          goto LABEL_90;
      }
    }
    v57 = v64;
    v58 = &v64[6];
    v7 = PipCreateComputerId(v2, &v57, 2, &v65[v6++], v44);
    if ( v7 < 0 )
      goto LABEL_90;
    v32 = v64[5];
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( v32 )
  {
    if ( v64[13] )
    {
      if ( v64[15] )
      {
        v57 = v64;
        v58 = &v64[4];
        v59 = &v64[12];
        v60 = &v64[14];
        v7 = PipCreateComputerId(v2, &v57, 4, &v65[v6++], v44);
        if ( v7 < 0 )
          goto LABEL_90;
      }
    }
    v57 = v64;
    v58 = &v64[4];
    v7 = PipCreateComputerId(v2, &v57, 2, &v65[v6++], v44);
    if ( v7 < 0 )
      goto LABEL_90;
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( v64[3] )
  {
    if ( v64[15] )
    {
      if ( v64[13] )
      {
        v57 = v64;
        v58 = &v64[2];
        v59 = &v64[12];
        v60 = &v64[14];
        v7 = PipCreateComputerId(v2, &v57, 4, &v65[v6++], v44);
        if ( v7 < 0 )
          goto LABEL_90;
      }
    }
    v57 = v64;
    v58 = &v64[2];
    v7 = PipCreateComputerId(v2, &v57, 2, &v65[v6++], v44);
    if ( v7 < 0 )
      goto LABEL_90;
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( v28 )
  {
    v7 = RtlStringCchPrintfW(v66, 4u, (int)L"%x", v28);
    if ( v7 < 0 )
      goto LABEL_90;
    RtlInitUnicodeString((unsigned int)v56, v66);
    v57 = v64;
    v58 = (int *)v56;
    v7 = PipCreateComputerId(v2, &v57, 2, &v65[v6++], v44);
    if ( v7 < 0 )
      goto LABEL_90;
    v31 = v64[1];
  }
  if ( !v31 )
    goto LABEL_80;
  if ( !v64[15]
    || !v64[13]
    || (v57 = v64, v58 = &v64[12], v59 = &v64[14], v7 = PipCreateComputerId(v2, &v57, 3, &v65[v6], v44), ++v6, v7 >= 0) )
  {
    v57 = v64;
    v7 = PipCreateComputerId(v2, &v57, 1, &v65[v6++], v44);
    if ( v7 >= 0 )
      goto LABEL_80;
  }
LABEL_90:
  v4 = v47;
  v3 = v48;
LABEL_91:
  v40 = v64;
  v41 = 8;
  do
  {
    RtlFreeAnsiString(v40);
    v40 += 2;
    --v41;
  }
  while ( v41 );
  if ( v3 )
    MmUnmapIoSpace(v3, v4);
  if ( v2 )
    ZwClose();
  if ( v53 )
    ZwClose();
  return v7;
}
