// MiMapViewOfImageSection 
 
int __fastcall MiMapViewOfImageSection(_DWORD *a1, int a2, _DWORD *a3, unsigned int *a4, _DWORD *a5, int *a6, _DWORD *a7, int a8, int a9, int a10, int a11, char a12)
{
  _DWORD *v12; // r5
  int v16; // r0
  __int64 v17; // kr00_8
  unsigned int v18; // r3
  int v19; // r2
  int v20; // r1
  _DWORD *v21; // r2
  int v22; // r3
  unsigned int v23; // r10
  _BYTE *v24; // r0
  _DWORD *v25; // r4
  int v26; // r0
  int v27; // r3
  int v28; // r3
  unsigned int *v29; // r5
  int v30; // r2
  unsigned int v31; // r9
  int v32; // r3
  char v33; // r3
  int v34; // r7
  unsigned int v35; // r3
  int v36; // lr
  int v37; // r3
  unsigned int v38; // r0
  _DWORD *v39; // r2
  unsigned int i; // r3
  int v41; // r5
  int v42; // r2
  unsigned int v43; // r2
  int v44; // r2
  int v45; // r5
  int v46; // r2
  unsigned int v47; // r2
  int v48; // r5
  int v49; // r0
  int v50; // r6
  int v51; // r2
  unsigned int v52; // r1
  unsigned __int64 *v53; // r3
  unsigned __int64 v54; // kr08_8
  int v55; // r8
  int v56; // r0
  int v57; // r9
  int v58; // r8
  int v59; // r2
  _DWORD *v60; // r5
  _DWORD *v61; // r6
  int v62; // r0
  int v63; // r0
  int v64; // r0
  int v65; // r10
  int v67; // [sp+14h] [bp-84h]
  int v68; // [sp+18h] [bp-80h]
  int v69; // [sp+1Ch] [bp-7Ch]
  unsigned int v70; // [sp+20h] [bp-78h] BYREF
  unsigned int v71; // [sp+24h] [bp-74h]
  int v72; // [sp+28h] [bp-70h]
  int v73; // [sp+2Ch] [bp-6Ch] BYREF
  unsigned int v74; // [sp+30h] [bp-68h]
  int v75; // [sp+34h] [bp-64h]
  _DWORD *v76; // [sp+38h] [bp-60h]
  int v77; // [sp+3Ch] [bp-5Ch]
  unsigned int *v78; // [sp+40h] [bp-58h]
  _DWORD *v79; // [sp+44h] [bp-54h]
  int v80; // [sp+48h] [bp-50h]
  char v81[4]; // [sp+50h] [bp-48h] BYREF
  unsigned int v82; // [sp+54h] [bp-44h]
  unsigned int v83; // [sp+58h] [bp-40h]
  int v84; // [sp+5Ch] [bp-3Ch]
  unsigned int v85; // [sp+60h] [bp-38h]
  int v86; // [sp+64h] [bp-34h]
  int v87; // [sp+70h] [bp-28h]
  int v88; // [sp+74h] [bp-24h]

  v78 = a4;
  v12 = a1;
  v76 = a3;
  if ( (a11 & 0x7Fu) > (unsigned __int16)KeNumberNodes )
    return sub_802BBC();
  v16 = *a1;
  v68 = v16;
  v17 = *(_QWORD *)(v16 + 32);
  v74 = *(_DWORD *)(v16 + 24);
  v18 = a7[8];
  v87 = HIDWORD(v17);
  v19 = (v18 >> 19) & 1;
  if ( v19 && a9 != 1 )
    return -1073741755;
  v20 = a3[47];
  v67 = 2;
  if ( (v20 & 0x8000000) != 0 && (*(_BYTE *)(HIDWORD(v17) + 35) & 4) == 0 )
  {
    if ( (*(_WORD *)(HIDWORD(v17) + 28) & 1) != 0 )
    {
      if ( (v20 & 0x1000000) != 0 )
        return -1073741207;
    }
    else
    {
      v67 = 3;
    }
  }
  if ( (*(_BYTE *)(v16 + 11) & 1) != 0 && (v20 & 0x20000) == 0 )
  {
    v67 = 3;
    if ( (v12[7] & 0x10000000) == 0 )
      v67 = 1;
  }
  if ( !v19 )
  {
    v21 = v12 + 20;
    if ( v12 != (_DWORD *)-80 )
    {
      while ( (v21[4] & 0xEu) < 0xC )
      {
        v21 = (_DWORD *)v21[2];
        if ( !v21 )
          goto LABEL_11;
      }
      if ( MiArbitraryCodeBlocked(a2) < 0 )
        JUMPOUT(0x802BBE);
    }
  }
LABEL_11:
  v79 = v12 + 20;
  MiCheckPurgeAndUpMapCount(v12);
  v22 = *a6;
  if ( !*a6 )
    v22 = a7[6] - *a5;
  v23 = (v22 + 4095) & 0xFFFFF000;
  v71 = MmHighestUserAddress - 0x10000;
  v77 = a10;
  if ( a10 )
  {
    v71 = 0xFFFFFFFF >> a10;
    if ( 0xFFFFFFFF >> a10 > MmHighestUserAddress - 0x10000 )
      v71 = MmHighestUserAddress - 0x10000;
  }
  v24 = (_BYTE *)ExAllocatePoolWithTag(512, 76, 543449430);
  v25 = v24;
  if ( !v24 )
  {
    MiDereferenceControlArea(v12);
    return -1073741670;
  }
  memset(v24, 0, 76);
  v25[2] = -2;
  v25[10] ^= (v25[10] ^ ((a8 == 1) << 26)) & 0x4000000;
  v25[7] = v25[7] & 0xFFFFC0FA | ((a11 & 0x3F) << 8) | 2;
  v26 = MiReferenceFileObjectForMap((int)a7);
  v27 = v25[10];
  v25[18] = v26;
  v25[10] = (v27 ^ (a7[9] >> 3)) & 0x10000000 ^ v27;
  v25[6] = 0;
  v28 = a7[8];
  v80 = 0x80000;
  if ( (v28 & 0x80000) != 0 )
  {
    v47 = v25[7] & 0xFFFFFF07 | 8;
    v25[7] = v47;
    v67 |= 1u;
    if ( (v12[7] & 0x10000000) == 0 )
      v67 = 1;
    v25[7] = v47 | 0x4000;
  }
  else
  {
    *(_DWORD *)(HIDWORD(v17) + 28) = *(_DWORD *)(HIDWORD(v17) + 28) & 0xFFFFFF07 | 0x38;
    *(_DWORD *)(HIDWORD(v17) + 32) = *(_DWORD *)(HIDWORD(v17) + 32) & 0x80000000 | v17 & 0x7FFFFFFF;
  }
  v75 = 0;
  v73 = 0;
  v69 = 0;
  v29 = v78;
  v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v72 = v30;
  if ( *v78 )
    v31 = *v78 & 0xFFFF0000;
  else
    v31 = (*a5 & 0xFFFF0000) + v74;
  v32 = v25[7];
  v70 = v31;
  if ( (v32 & 0xF8) == 56 && a3[44] && a3 != (_DWORD *)PsInitialSystemProcess )
  {
    v33 = PspNotifyEnableMask;
    __dmb(0xBu);
    if ( (v33 & 1) != 0 || (PerfGlobalGroupMask & 4) != 0 )
    {
      v31 = v70;
      v34 = 1;
      v75 = v73;
      v29 = v78;
      goto LABEL_24;
    }
    v31 = v70;
    v75 = v73;
  }
  v34 = 0;
LABEL_24:
  LOCK_ADDRESS_SPACE(v30, (int)a3);
  if ( (a3[48] & 0x20) != 0 )
  {
    v41 = -1073741558;
    goto LABEL_120;
  }
  if ( *v29 )
  {
    if ( !MiIsVaRangeAvailable(a3, v31, v23, v71) )
      goto LABEL_119;
  }
  else
  {
    if ( v23 > MmHighestUserAddress - 0x10000 )
    {
      v41 = -1073741801;
      goto LABEL_120;
    }
    if ( (v67 & 1) != 0 || !MiIsVaRangeAvailable(a3, v31, v23, v71) )
    {
      v45 = a10;
      if ( dword_63388C && !a10 )
      {
        v45 = 1;
        v77 = 1;
      }
      v41 = MiSelectUserAddress(a11, v45, v23, 0x10000, (unsigned __int8)v25[7] >> 3, &v73, &v70);
      if ( v41 < 0 )
      {
        if ( v77 != a10 )
          v41 = MiSelectUserAddress(a11, a10, v23, 0x10000, (unsigned __int8)v25[7] >> 3, &v73, &v70);
        if ( v41 < 0 )
          goto LABEL_120;
      }
      v31 = v70;
      v75 = v73;
    }
  }
  v35 = v31 - (*a5 & 0xFFFF0000);
  v77 = 1073741827;
  if ( v35 == v74 )
  {
    v36 = 0;
  }
  else
  {
    v36 = 1073741827;
    v69 = 1073741827;
  }
  v74 = (v31 + v23 - 1) >> 12;
  v25[3] = v31 >> 12;
  v25[4] = (v31 + v23 - 1) >> 12;
  v37 = a5[1];
  v71 = v31 >> 12;
  *(_WORD *)a5 = 0;
  v38 = (v37 << 20) | (*a5 >> 12);
  v39 = v79;
  for ( i = v79[7]; v38 >= i; i = v39[7] )
  {
    v39 = (_DWORD *)v39[2];
    v38 -= i;
  }
  v25[11] = v39;
  v25[12] = v39[1] + 4 * v38;
  v25[13] = *(_DWORD *)(v68 + 40) + 4 * *(_DWORD *)(v68 + 4) - 4;
  if ( (a12 & 4) != 0 )
  {
    v60 = a1;
    goto LABEL_35;
  }
  v60 = a1;
  if ( v36 == 1073741827 )
  {
    v46 = (a1[7] >> 28) & 1;
    if ( (v46 || (a11 & 0x800000) != 0) && (*(_BYTE *)(v68 + 10) & 1) == 0 && (v67 & 2) != 0 )
    {
      v79 = MiAllocateFixupVad((int)v25);
      if ( v79 )
      {
        ExFreePoolWithTag((unsigned int)v25);
        v25 = v79;
        v69 = 1073741878;
      }
      else if ( (a1[7] & 0x10000000) != 0 )
      {
        v41 = -1073741670;
        goto LABEL_120;
      }
      goto LABEL_35;
    }
    if ( !v46 )
      goto LABEL_35;
LABEL_119:
    v41 = -1073741800;
    goto LABEL_120;
  }
LABEL_35:
  if ( (a11 & 0x7F) != 0 )
    MEMORY[0xC040213C] = 1;
  if ( (v60[7] & 0x4000000) != 0 )
  {
    v63 = MmGetSessionIdEx((int)a3);
    v41 = MiCreatePerSessionProtos(v60, v63);
    if ( v41 >= 0 )
    {
      v60 = a1;
      goto LABEL_38;
    }
LABEL_120:
    v61 = a1;
LABEL_121:
    UNLOCK_ADDRESS_SPACE(v72, (int)a3);
    if ( v25 )
    {
      v62 = v25[18];
      if ( v62 )
        ObfDereferenceObject(v62);
      ExFreePoolWithTag((unsigned int)v25);
    }
    MiDereferenceControlArea(v61);
    return v41;
  }
LABEL_38:
  v41 = MiInsertSharedCommitNode(v60, (int)a3, 0);
  if ( v41 < 0 )
  {
    v61 = a1;
    goto LABEL_141;
  }
  v41 = MiInsertVadCharges((int)v25, (int)a3);
  if ( v41 < 0 )
  {
    v61 = a1;
    MiRemoveSharedCommitNode(a1, (int)a3, 0);
LABEL_141:
    if ( (v61[7] & 0x4000000) != 0 )
    {
      v64 = MmGetSessionIdEx((int)a3);
      MiDereferencePerSessionProtos(v61, v64);
    }
    goto LABEL_121;
  }
  if ( v69 == 1073741878 )
    ++MEMORY[0xC0402148];
  MiGetWsAndInsertVad(v25);
  if ( v75 == 1 )
    MiAdvanceVadHint(v31 >> 12, v74);
  v42 = v87;
  *a6 = v23;
  *v78 = v31;
  if ( *(_BYTE *)(v42 + 34)
    && ((v43 = *(unsigned __int16 *)(v42 + 32), v43 < MEMORY[0xFFFF902C]) || v43 > MEMORY[0xFFFF902E]) )
  {
    v44 = 1073741838;
    v69 = 1073741838;
  }
  else
  {
    v44 = v69;
  }
  if ( (PerfGlobalGroupMask & 0x8000) != 0 )
  {
    MiLogMapFileEvent(v25, 1061);
    v44 = v69;
  }
  v48 = v67 | 4;
  if ( (v25[7] & 0xF8) != 56 )
  {
    v57 = v72;
LABEL_99:
    v58 = (int)v76;
LABEL_94:
    if ( (v48 & 4) != 0 )
      UNLOCK_ADDRESS_SPACE(v57, v58);
    return v69;
  }
  if ( (NtGlobalFlag & 0x40000) == 0 || v44 == v77 || v44 == 1073741878 || v44 == 1073741838 )
    goto LABEL_74;
  v49 = v68;
  if ( (*(_BYTE *)(v72 + 968) & 0x20) == 0
    && (*(_WORD *)(v68 + 8) & 0x2000) == 0
    && (*(_BYTE *)(v68 + 10) & 0x80) == 128 )
  {
    v59 = (int)v76;
    *(_WORD *)(v68 + 8) |= 0x2000u;
    MiLoadUserSymbols(a1, v31, v59);
LABEL_74:
    v49 = v68;
  }
  v50 = 0;
  v51 = 8;
  if ( v34 )
  {
    v82 = 3;
    if ( (v25[10] & 0x10000000) != 0 )
    {
      v52 = v82 & 0xFFF80FFF;
    }
    else
    {
      v82 = v82 & 0xFFFF0FFF | ((*(_BYTE *)(v49 + 11) & 0xF0) << 8);
      v52 = (v82 ^ (*(unsigned __int8 *)(v49 + 11) << 15)) & 0x70000 ^ v82;
    }
    v82 = v52 ^ ((unsigned __int16)v52 ^ ((v69 == 1073741838) << 11)) & 0x800;
    v83 = v31;
    v85 = v23;
    __dmb(0xBu);
    v53 = (unsigned __int64 *)(v49 + 16);
    do
      v54 = __ldrexd(v53);
    while ( v54 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v53) );
    v88 = HIDWORD(v54);
    __dmb(0xBu);
    v55 = v80;
    if ( v23 != (_DWORD)v54 )
      v82 |= v80;
    v84 = 0;
    v86 = 0;
    v56 = MI_REFERENCE_CONTROL_AREA_FILE((int)a1);
    v51 = 8;
    v48 = v67 | 0xC;
    v50 = v56;
  }
  else
  {
    v55 = v80;
  }
  if ( (a7[8] & v55) == 0 && MiIsProcessCfgEnabled() )
  {
    v48 |= 0x18u;
  }
  else if ( (v25[10] & 0x20000000) != 0 )
  {
    v48 |= v51;
  }
  v57 = v72;
  if ( (v48 & v51) == 0 )
    goto LABEL_99;
  MiLockVad(v72, (int)v25);
  v58 = (int)v76;
  UNLOCK_ADDRESS_SPACE_UNORDERED(v57, (int)v76);
  LOBYTE(v48) = v48 & 0xFB;
  if ( (v48 & 0x10) == 0 || (v65 = MiCommitVadCfgBits((int)v25, 0, 0), v65 >= 0) )
  {
    if ( !v34 || (v34 = MiAddSecureEntry(v25, v71 << 12, (v74 << 12) | 0xFFF, -2147483647, 0)) != 0 )
    {
      MiUnlockVad(v57, (int)v25);
      if ( v34 )
      {
        PsCallImageNotifyRoutines(v50 + 48, *(_DWORD *)(v58 + 176), v81, v50);
        ObfDereferenceObject(v50);
        MmUnsecureVirtualMemory(v34);
      }
      goto LABEL_94;
    }
    v65 = -1073741670;
  }
  MiReferenceVad((int)v25);
  if ( v50 )
    ObfDereferenceObject(v50);
  MiUnmapVad(v25, 0);
  return v65;
}
