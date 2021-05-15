// PfSnOpenVolumesForPrefetch 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfSnOpenVolumesForPrefetch(int *a1, _DWORD *a2)
{
  unsigned __int16 *v3; // r6
  int v4; // r7
  char v5; // r5
  int v6; // r0
  int v7; // r0
  unsigned int v9; // r3
  int v10; // r0
  unsigned int v11; // r5
  int v12; // r4
  unsigned int v13; // r5
  int v14; // r4
  int v15; // r3
  unsigned __int16 *v16; // r10
  unsigned int v17; // r0
  int v18; // r3
  _BYTE *v19; // r0
  int v20; // r9
  int v21; // r2
  int v22; // r3
  int v23; // r4
  int v24; // r3
  int v25; // r1
  int **v26; // r2
  unsigned __int16 *v27; // r10
  int v28; // r2
  int v29; // r1
  _DWORD *v30; // r9
  int *v31; // r6
  int *v32; // r4
  __int64 v33; // r2
  int v34; // r4
  int v35; // r2
  int v36; // r3
  int *v37; // r4
  int v38; // r1
  int v39; // r2
  int v40; // r3
  int v41; // r3
  int v42; // r4
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int *v46; // r1
  int **v47; // r2 OVERLAPPED
  char v48; // r0
  int v49; // r4
  unsigned int v50; // r3
  unsigned int v51; // r3
  char v52; // r3
  unsigned int v53; // r5
  __int64 v54; // r2
  int **v55; // r1
  int v56; // r4
  char v57; // [sp+10h] [bp-B0h]
  int *v58; // [sp+18h] [bp-A8h] BYREF
  int **v59; // [sp+1Ch] [bp-A4h]
  unsigned int v60; // [sp+20h] [bp-A0h]
  int v61; // [sp+24h] [bp-9Ch]
  unsigned __int16 *v62; // [sp+28h] [bp-98h] BYREF
  int v63; // [sp+2Ch] [bp-94h]
  unsigned int v64; // [sp+30h] [bp-90h] BYREF
  int v65; // [sp+34h] [bp-8Ch]
  int *v66; // [sp+38h] [bp-88h] BYREF
  int v67; // [sp+3Ch] [bp-84h] BYREF
  int v68; // [sp+40h] [bp-80h] BYREF
  int v69; // [sp+48h] [bp-78h] BYREF
  int v70; // [sp+4Ch] [bp-74h]
  int v71[6]; // [sp+50h] [bp-70h] BYREF
  int v72[5]; // [sp+68h] [bp-58h] BYREF
  _DWORD *v73; // [sp+7Ch] [bp-44h]
  int v74[6]; // [sp+80h] [bp-40h] BYREF
  char v75[40]; // [sp+98h] [bp-28h] BYREF

  v59 = &v58;
  v73 = a2;
  v3 = 0;
  v58 = (int *)&v58;
  v62 = 0;
  memset(v72, 0, sizeof(v72));
  v57 = LOBYTE(v72[4]) | 2;
  v72[4] |= 2u;
  memset(v71, 0, 20);
  v4 = *a1;
  v5 = LOBYTE(v71[4]) | 2;
  v6 = *a1;
  v68 = 0;
  v65 = 0;
  v61 = v71[4] | 2;
  v71[4] |= 2u;
  v7 = PfSnLogOpenVolumesForPrefetch(v6, 1);
  if ( !v4 )
    return sub_806A54(v7);
  v9 = *(_DWORD *)(v4 + 112);
  if ( v9 >= 0x4000 )
    return sub_806A54(v7);
  v10 = ExAllocatePoolWithTag(1, 68 * v9, 1984979779);
  a1[21] = v10;
  if ( !v10 )
  {
    v14 = -1073741670;
    goto LABEL_38;
  }
  v11 = 0;
  if ( *(_DWORD *)(v4 + 112) )
  {
    v12 = 0;
    do
    {
      PfSnVolumeNodeInitialize(a1[21] + v12);
      ++v11;
      v12 += 68;
    }
    while ( v11 < *(_DWORD *)(v4 + 112) );
  }
  v74[0] = 24;
  v74[1] = 0;
  v74[3] = 512;
  v13 = 0;
  v74[2] = 0;
  v74[4] = 0;
  v74[5] = 0;
  v14 = NtCreateEvent((unsigned int)&v68, 2031619, (int)v74, 0, 0);
  if ( v14 < 0 )
    goto LABEL_37;
  v14 = IopGetDeviceInterfaces((int)&GUID_DEVINTERFACE_VOLUME, 0, 0, 0, &v62, 0);
  v3 = v62;
  if ( v14 < 0 )
    goto LABEL_37;
  v15 = *v62;
  v60 = 0;
  v16 = v62;
  if ( !v15 )
    goto LABEL_23;
  do
  {
    v17 = wcslen(v16);
    v63 = v17;
    if ( v13 <= 2 * v17 + 2 )
      v60 = 2 * v17 + 2;
    if ( PfSnIsVolumeMounted(v16, &v67, &v66) < 0 )
    {
      v18 = 0;
      v67 = 0;
    }
    else
    {
      v18 = v67;
    }
    if ( !v18 || v66 )
      goto LABEL_49;
    if ( PfSnQueryVolumeInfo(a1 + 1, v16, v72, &v69, &v64) < 0 )
    {
      v57 = v72[4];
LABEL_49:
      v25 = v63;
      goto LABEL_21;
    }
    v19 = (_BYTE *)ExAllocatePoolWithTag(1, 48, 1984979779);
    v20 = (int)v19;
    if ( !v19 )
    {
      v14 = -1073741670;
      v52 = v72[4];
      v5 = v61;
      v3 = v62;
      goto LABEL_39;
    }
    memset(v19, 0, 48);
    memset((_BYTE *)(v20 + 8), 0, 20);
    *(_DWORD *)(v20 + 24) |= 2u;
    *(_DWORD *)(v20 + 40) = v69;
    *(_DWORD *)(v20 + 44) = v70;
    *(_DWORD *)(v20 + 36) = v64;
    v21 = v72[1];
    v22 = v72[2];
    v23 = v72[3];
    *(_DWORD *)(v20 + 8) = v72[0];
    *(_DWORD *)(v20 + 12) = v21;
    *(_DWORD *)(v20 + 16) = v22;
    *(_DWORD *)(v20 + 20) = v23;
    *(_DWORD *)(v20 + 24) = v72[4];
    memset(v72, 0, sizeof(v72));
    v24 = v72[4];
    v25 = v63;
    *(_DWORD *)(v20 + 28) = v16;
    *(_DWORD *)(v20 + 32) = v25;
    v57 = v24 | 2;
    v72[4] = v24 | 2;
    v26 = v59;
    *(_DWORD *)v20 = &v58;
    *(_DWORD *)(v20 + 4) = v26;
    if ( *v26 != (int *)&v58 )
      __fastfail(3u);
    *v26 = (int *)v20;
    v59 = (int **)v20;
LABEL_21:
    v16 += v25 + 1;
    v13 = v60;
  }
  while ( *v16 );
  v3 = v62;
LABEL_23:
  v27 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v13 + 2, 1984979779);
  if ( v27 )
  {
    v28 = *(_DWORD *)(v4 + 108) + v4;
    v63 = v28;
    v64 = 0;
    if ( *(_DWORD *)(v4 + 112) )
    {
      v29 = 0;
      v67 = 0;
      v30 = (_DWORD *)v28;
      while ( 1 )
      {
        v31 = (int *)(a1[21] + v29);
        v31[2] = *v30 + v28;
        v31[3] = v30[1];
        v31[15] = 0;
        v31[14] = v30[7] + v28;
        v32 = v58;
        if ( v58 == (int *)&v58 )
          goto LABEL_56;
        do
        {
          v33 = *(_QWORD *)(v32 + 9);
          v69 = v32[10];
          HIDWORD(v33) = v32[11];
          v66 = v32;
          v70 = HIDWORD(v33);
          if ( PfMetadataRecordIsEqual(v30, &v69, v33) )
            break;
          v32 = (int *)*v32;
        }
        while ( v32 != (int *)&v58 );
        if ( v32 == (int *)&v58
          || (v34 = (int)v66,
              RtlStringCbPrintfW(v27, v60 + 2, (int)L"%s\\", v66[7]),
              RtlUnicodeStringInit((int)v75, v27, v35, v36),
              v66 = (int *)(v34 + 8),
              PfpOpenHandleCreate(v71, a1 + 1, v75, 0, 1179785, 33, 128, v34 + 8) < 0) )
        {
LABEL_56:
          memset(v71, 0, 20);
          v55 = (int **)a1[23];
          v61 = v71[4] | 2;
          v71[4] |= 2u;
          *v31 = (int)(a1 + 22);
          v31[1] = (int)v55;
          if ( *v55 != a1 + 22 )
            __fastfail(3u);
          *v55 = v31;
          a1[23] = (int)v31;
        }
        else
        {
          v37 = (int *)(v34 + 8);
          v38 = v37[1];
          v39 = v37[2];
          v40 = v37[3];
          v31[4] = *v37;
          v31[5] = v38;
          v31[6] = v39;
          v31[7] = v40;
          v41 = v37[4];
          v42 = (int)v66;
          v31[8] = v41;
          memset((_BYTE *)v42, 0, 20);
          *(_DWORD *)(v42 + 16) |= 2u;
          v43 = v71[1];
          v44 = v71[2];
          v45 = v71[3];
          v31[9] = v71[0];
          v31[10] = v43;
          v31[11] = v44;
          v31[12] = v45;
          v31[13] = v71[4];
          memset(v71, 0, 20);
          v46 = a1 + 24;
          v47 = (int **)a1[25];
          v61 = v71[4] | 2;
          v71[4] |= 2u;
          *(_QWORD *)v31 = *(_QWORD *)(&v47 - 1);
          if ( *v47 != a1 + 24 )
            __fastfail(3u);
          *v47 = v31;
          a1[25] = (int)v31;
          v48 = PfSnVolumeCheckSeekPenalty();
          v49 = v65;
          v50 = v31[16] & 0xFFFFFFFE | v48 & 1;
          v31[16] = v50;
          if ( (v50 & 1) != 0 )
          {
            v56 = v49 | 1;
LABEL_66:
            v65 = v56;
            goto LABEL_35;
          }
          if ( (v49 & 3) == 0 && !PfSnVolumeCheckIsSdBus() )
          {
            v56 = v49 | 2;
            goto LABEL_66;
          }
        }
LABEL_35:
        v51 = *(_DWORD *)(v4 + 112);
        v29 = v67 + 68;
        ++v64;
        v67 += 68;
        v30 += 24;
        if ( v64 >= v51 )
          break;
        v28 = v63;
      }
    }
    v14 = 0;
    *v73 = v65;
    ExFreePoolWithTag((unsigned int)v27);
    v3 = v62;
  }
  else
  {
    v14 = -1073741670;
  }
LABEL_37:
  v5 = v61;
LABEL_38:
  v52 = v57;
LABEL_39:
  if ( (v52 & 4) != 0 )
    PfpOpenHandleClose(v72, (int)(a1 + 1));
  if ( (v5 & 4) != 0 )
    PfpOpenHandleClose(v71, (int)(a1 + 1));
  while ( 1 )
  {
    v53 = (unsigned int)v58;
    if ( v58 == (int *)&v58 )
      break;
    v54 = *(_QWORD *)v58;
    if ( (int **)v58[1] != &v58 || *(int **)(v54 + 4) != v58 )
      __fastfail(3u);
    v58 = (int *)*v58;
    *(_DWORD *)(v54 + 4) = &v58;
    if ( (*(_DWORD *)(v53 + 24) & 4) != 0 )
      PfpOpenHandleClose((int *)(v53 + 8), (int)(a1 + 1));
    ExFreePoolWithTag(v53);
  }
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  if ( v68 )
    NtClose();
  PfSnLogOpenVolumesForPrefetch(v4, 0);
  return v14;
}
