// IoReadPartitionTable 
 
int __fastcall IoReadPartitionTable(int a1, unsigned int a2, int a3, int *a4)
{
  unsigned int v5; // r7
  int v7; // r0
  __int64 v8; // r8
  int v9; // r6
  unsigned __int64 v10; // kr10_8
  int v11; // r1
  int v12; // r10
  unsigned __int8 *v13; // r7
  int v15; // r6
  unsigned int v16; // r3
  int v17; // r6
  _DWORD *v18; // r0
  int v19; // r1
  int v20; // r4
  int v21; // r3
  unsigned __int8 *v22; // r4
  int v23; // r7
  int v24; // r2
  bool v25; // cc
  int v26; // r7
  unsigned __int8 v27; // r3
  int v28; // r2
  int v29; // r3
  unsigned __int8 *v30; // r1
  int v31; // r3
  int v32; // r2
  int v33; // r3
  int v34; // r1
  int v35; // r10
  int v36; // r3
  unsigned int v37; // r0
  unsigned int v38; // lr
  unsigned __int64 v39; // kr20_8
  unsigned int v40; // r2
  int v41; // r0
  int v42; // r7
  unsigned int v43; // r1
  unsigned int v44; // r3
  unsigned __int64 v45; // kr40_8
  int v46; // kr00_4
  int v47; // r3
  unsigned __int64 v48; // kr50_8
  int v49; // r0
  int v50; // [sp+10h] [bp-B0h]
  unsigned __int64 v51; // [sp+18h] [bp-A8h] BYREF
  int v52; // [sp+20h] [bp-A0h]
  unsigned int v53; // [sp+24h] [bp-9Ch]
  unsigned int v54; // [sp+28h] [bp-98h] BYREF
  unsigned int v55; // [sp+2Ch] [bp-94h]
  unsigned __int64 v56; // [sp+30h] [bp-90h] BYREF
  __int64 v57; // [sp+38h] [bp-88h]
  unsigned __int8 *v58; // [sp+40h] [bp-80h]
  int v59; // [sp+44h] [bp-7Ch]
  int v60; // [sp+48h] [bp-78h]
  int v61; // [sp+4Ch] [bp-74h]
  int v62; // [sp+50h] [bp-70h]
  int v63; // [sp+54h] [bp-6Ch]
  int v64; // [sp+58h] [bp-68h]
  int v65; // [sp+5Ch] [bp-64h]
  int v66; // [sp+60h] [bp-60h]
  int v67; // [sp+64h] [bp-5Ch]
  int v68; // [sp+68h] [bp-58h]
  int v69; // [sp+6Ch] [bp-54h]
  int v70; // [sp+70h] [bp-50h] BYREF
  char v71[16]; // [sp+78h] [bp-48h] BYREF
  char v72[8]; // [sp+88h] [bp-38h] BYREF
  int v73; // [sp+90h] [bp-30h]
  unsigned int v74; // [sp+9Ch] [bp-24h]

  v5 = a2;
  v68 = a3;
  v50 = -1;
  v52 = 0;
  v53 = 2048;
  v60 = 1;
  v55 = a2;
  v69 = a1;
  v62 = 0;
  v7 = ExAllocatePoolWithTag(512, 2048, 1651798854);
  *a4 = v7;
  if ( !v7 )
    JUMPOUT(0x7D5E00);
  if ( v5 < 0x200 )
    v5 = 512;
  v63 = v5;
  HalExamineMBR(a1, v5, 85, &v54);
  if ( v54 )
  {
    v62 = 1;
    ExFreePoolWithTag(v54);
    HIDWORD(v8) = 512;
    LODWORD(v56) = 512;
  }
  else
  {
    HIDWORD(v8) = 0;
    LODWORD(v56) = 0;
  }
  LODWORD(v8) = 0;
  HIDWORD(v56) = 0;
  v9 = HalpGetFullGeometry(a1, (int)v72, &v51);
  if ( v9 < 0 )
    goto LABEL_52;
  v10 = (v51 >> 1) + v51;
  v54 = HIDWORD(v10);
  v66 = v10;
  v61 = 1;
  v11 = 4096;
  v57 = 0i64;
  v12 = -1;
  if ( v5 >= 0x1000 )
    v11 = v5;
  v13 = (unsigned __int8 *)ExAllocatePoolWithTag(516, v11, 1651798854);
  v58 = v13;
  if ( !v13 )
    return sub_7D5DF8();
  while ( 1 )
  {
    v65 = 1;
    KeInitializeEvent((int)v71, 0, 0);
    v15 = v63;
    memset(v13, 0, v63);
    v16 = v15;
    v17 = v69;
    v18 = IoBuildSynchronousFsdRequest(3, v69, (int)v13, v16, &v56, (int)v71, (int)&v70);
    if ( !v18 )
      break;
    *(_BYTE *)(v18[24] - 38) |= 2u;
    v9 = IofCallDriver(v17, (int)v18);
    if ( v9 == 259 )
    {
      KeWaitForSingleObject((unsigned int)v71, 0, 0, 0, 0);
      v9 = v70;
    }
    if ( v9 == -2147483614 )
      v9 = 0;
    if ( v9 < 0 )
      goto LABEL_45;
    if ( v62 && v8 == 0x20000000000i64 )
      v8 = 0i64;
    if ( *((unsigned __int16 *)v13 + 255) != 43605 )
      goto LABEL_45;
    v52 = 1;
    if ( v61 == 1 )
    {
      v20 = v73;
      if ( v73 == 11 )
      {
        v21 = *v13;
        if ( (v21 == 235 || v21 == 233) && !memcmp((unsigned int)(v13 + 3), (unsigned int)"NTFS    ", 8) )
          goto LABEL_46;
      }
    }
    if ( !v8 )
      *(_DWORD *)(*a4 + 4) = *((_DWORD *)v13 + 110);
    v22 = v13 + 446;
    ++v50;
    v64 = 1;
    v67 = 0;
    v59 = 32 * v12;
    while ( 1 )
    {
      v23 = v22[4];
      if ( v23 == 238 )
      {
        v40 = *((_DWORD *)v22 + 2);
        v19 = v40 + *((_DWORD *)v22 + 3);
        if ( v40 + (unsigned __int64)*((unsigned int *)v22 + 3) > v51 )
          *((_DWORD *)v22 + 3) = v51 - v40;
      }
      if ( !HalpIsValidPartitionEntry(v22, v19, v51, HIDWORD(v51), v66, v54) && !v50 )
        break;
      if ( (v23 == 5 || v23 == 15) && ++v67 != 1 )
        break;
      if ( v60
        && (v22[8] + ((v22[9] + ((v22[10] + (v22[11] << 8)) << 8)) << 8)
         || v22[12] + ((v22[13] + ((v22[14] + (v22[15] << 8)) << 8)) << 8)) )
      {
        v60 = 0;
      }
      if ( !v68 || v23 && v23 != 5 && v23 != 15 )
      {
        v19 = v53;
        ++v12;
        v24 = v59 + 32;
        v25 = v59 + 72 > v53;
        v59 += 32;
        if ( v25 )
        {
          v41 = ExAllocatePoolWithTag(512, 2 * v53, 1651798854);
          v42 = v41;
          if ( !v41 )
          {
            v9 = -1073741670;
            --v12;
LABEL_37:
            v29 = v65;
            goto LABEL_38;
          }
          memmove(v41, *a4, v53);
          ExFreePoolWithTag(*a4);
          v43 = v53;
          v24 = v59;
          *a4 = v42;
          v19 = 2 * v43;
          v53 = v19;
        }
        v26 = *a4 + v24;
        v27 = v22[4];
        v28 = 0;
        *(_BYTE *)(v26 + 35) = 0;
        *(_BYTE *)(v26 + 32) = v27;
        if ( v22[4] )
        {
          *(_BYTE *)(v26 + 33) = (*v22 & 0x80u) != 0;
          v36 = v22[4];
          if ( v36 == 5 || v36 == 15 )
          {
            v37 = HIDWORD(v57);
            v44 = v57;
            *(_BYTE *)(v26 + 34) = 0;
            v38 = v44;
          }
          else
          {
            *(_BYTE *)(v26 + 34) = 1;
            v37 = HIDWORD(v8);
            v38 = v8;
          }
          v39 = (v22[8] + ((v22[9] + ((v22[10] + (v22[11] << 8)) << 8)) << 8)) * (unsigned __int64)v55
              + __PAIR64__(v38, v37);
          *(_QWORD *)(v26 + 8) = v39;
          if ( !v55 )
            __brkdiv0();
          *(_DWORD *)(v26 + 24) = _rt_sdiv64(v55, v39 - __PAIR64__(v38, v37));
          v28 = ((v22[12] + ((v22[13] + ((v22[14] + (v22[15] << 8)) << 8)) << 8)) * (unsigned __int64)v55) >> 32;
          *(_DWORD *)(v26 + 16) = (v22[12] + ((v22[13] + ((v22[14] + (v22[15] << 8)) << 8)) << 8)) * v55;
        }
        else
        {
          *(_BYTE *)(v26 + 33) = 0;
          *(_BYTE *)(v26 + 34) = 0;
          *(_DWORD *)(v26 + 8) = 0;
          *(_DWORD *)(v26 + 12) = 0;
          *(_DWORD *)(v26 + 16) = 0;
          *(_DWORD *)(v26 + 24) = 0;
        }
        *(_DWORD *)(v26 + 20) = v28;
      }
      v22 += 16;
      v64 = (char)(v64 + 1);
      if ( v64 > 4 )
        goto LABEL_37;
    }
    v29 = 0;
LABEL_38:
    v13 = v58;
    if ( v9 < 0 )
      goto LABEL_45;
    if ( !v29 )
    {
      --v50;
      goto LABEL_45;
    }
    v56 = 0i64;
    v8 = 0i64;
    v30 = v58 + 446;
    LOBYTE(v31) = 1;
    while ( 1 )
    {
      v32 = v30[4];
      if ( v32 == 5 || v32 == 15 )
        break;
      v31 = (char)(v31 + 1);
      v30 += 16;
      if ( v31 > 4 )
        goto LABEL_44;
    }
    v45 = (v30[8] + ((v30[9] + ((v30[10] + (v30[11] << 8)) << 8)) << 8)) * (unsigned __int64)v55;
    v46 = (v30[8] + ((v30[9] + ((v30[10] + (v30[11] << 8)) << 8)) << 8)) * v55;
    v56 = v45 + __PAIR64__(v57, HIDWORD(v57));
    LODWORD(v8) = (__PAIR64__(HIDWORD(v45), v46) + __PAIR64__(v57, HIDWORD(v57))) >> 32;
    HIDWORD(v8) = v46 + HIDWORD(v57);
    if ( v61 )
      v57 = v8;
    v66 = v30[12] + ((v30[13] + ((v30[14] + (v30[15] << 8)) << 8)) << 8);
    v54 = 0;
LABEL_44:
    v61 = 0;
    if ( !v8 )
      goto LABEL_45;
  }
  v9 = -1073741670;
LABEL_45:
  v20 = v73;
  if ( v73 != 11 )
  {
    v33 = v50;
    v34 = v52;
    goto LABEL_94;
  }
LABEL_46:
  v33 = v50;
  v34 = v52;
  if ( !v50 )
  {
    if ( v52 != 1 )
      goto LABEL_49;
    if ( v60 != 1 )
      goto LABEL_49;
    v47 = *v13;
    if ( v47 != 235 && v47 != 233 )
      goto LABEL_49;
    v33 = -1;
  }
LABEL_94:
  if ( v33 == -1 )
  {
    if ( v34 == 1 || v20 == 11 )
    {
      v48 = v51;
      if ( v51 )
      {
        v49 = *a4;
        *(_WORD *)(v49 + 34) = 1;
        *(_BYTE *)(v49 + 32) = 4;
        *(_BYTE *)(v49 + 33) = 0;
        *(_DWORD *)(v49 + 24) = 0;
        *(_DWORD *)(v49 + 8) = 0;
        *(_DWORD *)(v49 + 12) = 0;
        v12 = 0;
        *(_QWORD *)(v49 + 16) = v48 * v74;
        *(_DWORD *)(*a4 + 4) = 1;
      }
    }
    else
    {
      v12 = -1;
    }
  }
LABEL_49:
  v35 = v12 + 1;
  *(_DWORD *)*a4 = v35;
  if ( !v35 )
    *(_DWORD *)(*a4 + 4) = 0;
  ExFreePoolWithTag((unsigned int)v13);
  if ( v9 < 0 )
  {
LABEL_52:
    ExFreePoolWithTag(*a4);
    *a4 = 0;
  }
  return v9;
}
