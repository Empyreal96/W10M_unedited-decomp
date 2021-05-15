// MiRelocateImage 
 
int __fastcall MiRelocateImage(int a1, int a2, unsigned int a3, int a4, int a5)
{
  unsigned int v7; // lr
  _WORD *v8; // r8
  int v9; // r5
  unsigned int v10; // r5
  int v11; // r4
  unsigned int v12; // r6
  int v13; // r1
  int v14; // r0
  int v15; // r2
  unsigned int v16; // r3
  unsigned int v17; // r1
  int v18; // r4
  int v19; // r0
  int v20; // r4
  unsigned int v21; // r2
  int v22; // r8
  int v23; // r9
  int v24; // r2
  int v25; // r6
  int v26; // r8
  char v27; // r10
  unsigned int v28; // r2
  unsigned int v29; // r6
  unsigned int v30; // r9
  unsigned int v31; // r5
  unsigned int v32; // r4
  int v33; // r3
  int v34; // r0
  int *v35; // r5
  _DWORD *v36; // r5
  unsigned int v37; // r6
  unsigned int v38; // r4
  unsigned int v39; // r2
  unsigned int v40; // r2
  unsigned int v41; // r1
  unsigned __int16 *v42; // r0
  __int16 v43; // r2
  int v44; // t1
  int v45; // r1
  int v46; // lr
  _DWORD *v47; // r6
  int v48; // r0
  int v49; // r8
  _DWORD *v51; // [sp+8h] [bp-D8h]
  int v52; // [sp+Ch] [bp-D4h]
  _DWORD *v53; // [sp+10h] [bp-D0h]
  unsigned int v54; // [sp+14h] [bp-CCh]
  unsigned int v55; // [sp+14h] [bp-CCh]
  int v56; // [sp+18h] [bp-C8h]
  int v57; // [sp+1Ch] [bp-C4h]
  int v58; // [sp+20h] [bp-C0h] BYREF
  int v59; // [sp+24h] [bp-BCh]
  int v60; // [sp+28h] [bp-B8h]
  int v61; // [sp+2Ch] [bp-B4h]
  int v62; // [sp+30h] [bp-B0h]
  int *v63; // [sp+34h] [bp-ACh]
  int v64; // [sp+38h] [bp-A8h]
  int v65; // [sp+3Ch] [bp-A4h]
  int v66; // [sp+40h] [bp-A0h]
  int v67; // [sp+44h] [bp-9Ch]
  unsigned int v68; // [sp+48h] [bp-98h]
  int v69; // [sp+4Ch] [bp-94h]
  int v70; // [sp+50h] [bp-90h]
  _DWORD *v71; // [sp+54h] [bp-8Ch]
  int *v72; // [sp+58h] [bp-88h]
  int v73; // [sp+5Ch] [bp-84h]
  _DWORD *v74; // [sp+60h] [bp-80h]
  int v75; // [sp+64h] [bp-7Ch]
  int v76; // [sp+68h] [bp-78h]
  int v77; // [sp+6Ch] [bp-74h]
  int v78; // [sp+70h] [bp-70h]
  _DWORD v79[4]; // [sp+78h] [bp-68h] BYREF
  _DWORD v80[4]; // [sp+88h] [bp-58h] BYREF
  int v81; // [sp+98h] [bp-48h] BYREF
  int v82; // [sp+9Ch] [bp-44h]
  int varg_r0; // [sp+E8h] [bp+8h]
  int varg_r1; // [sp+ECh] [bp+Ch]
  unsigned int varg_r2; // [sp+F0h] [bp+10h]
  int varg_r3; // [sp+F4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v60 = a4;
  varg_r3 = a4;
  v66 = a1;
  v79[0] = a1;
  v7 = 2;
  v8 = *(_WORD **)(a1 + 36);
  v71 = v8;
  v80[2] = v8;
  v9 = (unsigned __int16)v8[16];
  if ( v9 != 332 && v9 != 34404 )
    goto LABEL_5;
  v7 = 34;
  if ( (v8[14] & 1) != 0 )
    return 0;
  v52 = 0;
  v67 = 0;
  if ( (v8[15] & 0x1000) != 0 )
  {
LABEL_5:
    v67 = -1073741701;
    v52 = -1073741701;
  }
  v10 = *(_DWORD *)(a2 + 76);
  v80[0] = v10;
  v11 = *(_DWORD *)(a2 + 80);
  v61 = v11;
  v80[1] = v11;
  if ( v10 )
  {
    if ( !v11 )
      return v52;
  }
  else
  {
    if ( v11 )
      return v52;
    v7 &= 0xFFFFFFFD;
  }
  if ( (*(_BYTE *)(a1 + 11) & 1) != 0 )
    return 0;
  v51 = *(_DWORD **)a1;
  v74 = v51;
  v63 = (int *)v51[14];
  v72 = v63;
  if ( (a3 & 0xFFF) > 0xFFC || (a3 & 3) != 0 )
    return v52;
  v12 = *(_DWORD *)(a1 + 24);
  if ( (v7 & 0x20) != 0 && !v60 && (v8[15] & 0x40) == 0 && MmRegistryState != -1 && (v8[15] & 0x1000) == 0 )
    return 0;
  v65 = v11;
  v76 = v11;
  v13 = *(_DWORD *)(a1 + 4);
  v14 = v13;
  v59 = v13;
  v15 = (v7 >> 1) & 1;
  if ( !v15 )
  {
    v14 = (a3 >> 12) + 1;
    v59 = v14;
  }
  v16 = v13 << 12;
  v68 = v13 << 12;
  v79[2] = v13 << 12;
  v17 = v11 + v10;
  if ( v11 + v10 > v16 || v15 && (v17 <= v10 || v12 + v10 <= v12 || v17 + v12 <= v12) )
    return v52;
  v18 = v11 + 4 * (v14 + 10);
  v58 = 0;
  v54 = v7 & 0xFFFFFFF6;
  v64 = 0;
  v69 = 0;
  v82 = 0;
  v62 = 0;
  v70 = 0;
  v57 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v73 = v57;
  v19 = ExAllocatePoolWithTag(1, v18, 1699900749);
  v53 = (_DWORD *)v19;
  v78 = v19;
  if ( !v19 )
    return -1073741670;
  v21 = v19;
  do
    v21 += 4096;
  while ( v21 < v19 + v18 );
  *(_DWORD *)(v19 + 20) = 0;
  *(_BYTE *)(v19 + 32) = 0;
  *(_DWORD *)(v19 + 4) = 0;
  *(_DWORD *)(v19 + 24) = v59;
  *(_DWORD *)(v19 + 36) = 0;
  *(_DWORD *)(v19 + 8) = 0;
  *(_DWORD *)(v19 + 12) = 0;
  if ( (v7 & 2) == 0 )
  {
    v23 = v19;
LABEL_38:
    v20 = MiSelectImageBase(v23, v66, v60, a5, &v58);
    if ( v20 < 0 )
    {
      ExFreePoolWithTag(v23);
      if ( !v60 )
        v20 = v52;
      goto LABEL_105;
    }
    v20 = MiUpdateCfgSystemWideBitmap(v51, v58, 0);
    if ( v20 < 0 )
    {
      MiFreeRelocations(v51, v23);
      goto LABEL_105;
    }
    *(_DWORD *)(v23 + 28) = a3;
    v24 = v58;
    *(_DWORD *)(v23 + 20) = v58 - v12;
    if ( v24 != v12 || a5 )
    {
      v56 = v23 + 40;
      v75 = v23 + 40;
      *(_DWORD *)v23 = v23 + 40;
      v25 = v59;
      memset((_BYTE *)(v23 + 40), 0, 4 * v59);
      v26 = v23 + 40 + 4 * v25;
      v77 = v26;
      *(_DWORD *)(v23 + 16) = v26;
      v27 = v54 | 4;
      v59 = v54 | 4;
      if ( ((v54 | 4) & 2) != 0 )
      {
        memmove(v23 + 40 + 4 * v25, v64 + v10, v61);
        v28 = v68;
        v55 = 0;
        v29 = v61;
        v27 &= 0xEFu;
        v30 = 0;
        if ( v61 )
        {
          while ( v29 >= 0xA )
          {
            v31 = *(_DWORD *)(v26 + 4);
            if ( v31 > v29 )
              goto LABEL_69;
            if ( (v31 & 1) != 0 )
              goto LABEL_69;
            if ( v31 < 8 )
              goto LABEL_69;
            v32 = *(_DWORD *)v26;
            if ( (*(_DWORD *)v26 & 0xFFF) != 0 || v32 + 4096 <= v32 || v32 + 4096 > v28 || v32 < v30 || v31 == 8 )
              goto LABEL_69;
            if ( (BYTE2(MiFlags) & 3) == 3
              && (v63[1] & 0xFFFFFFF8) > 8
              && (MiOffsetToProtos(v51, v32, (int)v79)[4] & 4) != 0 )
            {
              v20 = -1073741701;
              v23 = (int)v53;
              goto LABEL_102;
            }
            if ( v32 >> 12 > v55 )
              v55 = v32 >> 12;
            *(_DWORD *)(v56 + 4 * (v32 >> 12)) |= v26;
            v30 = (v32 & 0xFFFFF000) + 4096;
            v33 = v26 + 8;
            v26 += v31;
            v29 -= v31;
            v34 = MiScanRelocationPage(v64, v32, (v31 - 8) >> 1, v33, v51, v53);
            v20 = v34;
            if ( v34 < 0 )
            {
              v23 = (int)v53;
              if ( v34 == -1073741207 )
              {
                v20 = 0;
                goto LABEL_102;
              }
              v35 = v51;
              if ( v34 == -1073741701 )
                v20 = v52;
              goto LABEL_103;
            }
            v27 |= 0x10u;
            if ( !v29 )
              goto LABEL_72;
            v28 = v68;
          }
          if ( v29 != 8 )
          {
LABEL_69:
            v20 = v52;
            v23 = (int)v53;
            goto LABEL_102;
          }
          v65 = v61 - 8;
        }
LABEL_72:
        MiUnmapImageInSystemSpace(&v81);
        PsRevertToUserPagePriorityThread(v57, v62);
        v27 &= 0xFEu;
        v23 = (int)v53;
        v36 = (_DWORD *)v53[2];
        v37 = v55;
        if ( v36 )
        {
          while ( 1 )
          {
            v38 = v36[2];
            v39 = *(_DWORD *)(v56 + 4 * (v38 >> 12));
            if ( v38 >> 12 > v37 )
              v37 = v38 >> 12;
            if ( v39 > 1 )
            {
              v40 = v39 & 0xFFFFFFFE;
              v41 = (unsigned int)(*(_DWORD *)(v40 + 4) - 8) >> 1;
              v42 = (unsigned __int16 *)(v40 + 8);
              if ( v41 )
                break;
            }
LABEL_80:
            v36 = (_DWORD *)*v36;
            if ( !v36 )
              goto LABEL_83;
          }
          while ( 1 )
          {
            v44 = *v42++;
            v43 = v44;
            if ( (v44 & 0xFFFFF000) != 0 && (v43 & 0xFFFu) < (v36[2] & 0xFFFu) )
              break;
            if ( !--v41 )
              goto LABEL_80;
          }
          v20 = v52;
          goto LABEL_102;
        }
LABEL_83:
        v35 = v51;
        MiLogRelocationFaults(v51, v80, v53);
        v53[6] = v37 + 1;
        if ( (v27 & 0x14) == 20 )
        {
          v23 = MiCompressRelocations(v53, v65);
          v56 = v23 + 40;
        }
      }
      else
      {
        v35 = v51;
      }
      *(_DWORD *)(v56 + 4 * (*(_DWORD *)(v23 + 28) >> 12)) |= 1u;
      v27 |= 8u;
      MI_LOCK_RELOCATIONS_EXCLUSIVE(v57, v23);
      *v63 = v23;
      v45 = v66;
      v46 = v58;
      *(_DWORD *)(v66 + 24) = v58;
      v47 = v71;
      *v71 += *(_DWORD *)(v23 + 20);
      v35[13] |= 0x80000000;
      if ( (*(_BYTE *)(v45 + 10) & 1) != 0 )
      {
        MiSetDeleteOnClose(v35, 0);
        v46 = v58;
      }
      if ( (MiFlags & 0x100000) != 0
        && (v35[13] & 0xC000000) != 0
        && (v20 = SeSetImageBaseAddress(v63[1] & 0xFFFFFFF8, v46), v20 < 0) )
      {
        v49 = a5;
      }
      else
      {
        if ( v60 )
          v48 = -1;
        else
          v48 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
        v49 = a5;
        if ( a5 )
          v20 = 0;
        else
          v20 = MiValidateImagePages(v35, 0, 2, v48);
      }
      MI_UNLOCK_RELOCATIONS_EXCLUSIVE(v57, v23);
      if ( v20 >= 0 && !v49 )
        *((_BYTE *)v47 + 35) |= 4u;
      goto LABEL_103;
    }
    v27 = v54;
LABEL_102:
    v35 = v51;
LABEL_103:
    if ( (v27 & 8) == 0 )
      MiFreeRelocations(v35, v23);
    goto LABEL_106;
  }
  if ( MiMapImageInSystemSpace(v51, 3, &v81) < 0 )
  {
    ExFreePoolWithTag((unsigned int)v53);
    MiSetDeleteOnClose(v51, 0);
    return 0;
  }
  v22 = v81;
  v64 = v81;
  v69 = v81;
  v62 = PsSetSystemPagePriorityThread(v57, 1);
  v70 = v62;
  v54 |= 1u;
  v20 = MiParseImageCfgBits(v51, v22, v82 << 12, a2);
  if ( v20 >= 0 )
  {
    v23 = (int)v53;
    v53[9] = 0;
    goto LABEL_38;
  }
  ExFreePoolWithTag((unsigned int)v53);
LABEL_105:
  v27 = v54;
LABEL_106:
  if ( (v27 & 1) != 0 )
  {
    MiUnmapImageInSystemSpace(&v81);
    PsRevertToUserPagePriorityThread(v57, v62);
  }
  return v20;
}
