// MiMapViewOfDataSection 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiMapViewOfDataSection(unsigned int *a1, int a2, unsigned int *a3, int a4, int *a5, int a6, int a7, int a8, unsigned int a9, int a10, int a11, int a12, unsigned __int8 *a13, _DWORD *a14)
{
  unsigned int *v15; // r7
  int result; // r0
  int v18; // r4
  int v19; // r3
  int v20; // r2
  int v21; // r1
  int v22; // r5
  int v23; // r7
  __int64 v24; // r8
  unsigned __int64 v25; // r0
  int v26; // r5
  unsigned int *v27; // r6
  unsigned int v28; // r3
  unsigned int v29; // r2
  int v30; // r1
  int v31; // r7
  int v32; // r8
  int v33; // kr10_4
  int v34; // r5
  int v35; // r4
  _BYTE *v36; // r0
  int *v37; // r2
  int v38; // r4
  unsigned int v39; // r9
  unsigned int v40; // r5
  _DWORD *v41; // r0
  int v42; // r3
  unsigned int v43; // r10
  int v44; // r1
  __int64 v45; // r2
  unsigned int v46; // r3
  unsigned int v47; // r1
  unsigned int v48; // kr04_4
  unsigned __int64 v49; // r2
  int v50; // r3
  int v51; // r5
  int v52; // r2
  int v53; // r6
  int v54; // r7
  int v55; // r0
  int v56; // r3
  unsigned __int64 v57; // kr18_8
  int v58; // r4
  unsigned int v59; // r1
  int v60; // r9
  int v61; // r1
  int v62; // r0
  int v63; // r1
  int v64; // r0
  unsigned int v65; // r1
  int v66; // r4
  int v67; // r0
  unsigned int v68; // r0
  int v69; // r0
  __int16 v70; // r3
  unsigned int v71; // r0
  unsigned __int64 *v72; // r3
  unsigned __int64 v73; // kr20_8
  unsigned __int64 v74; // kr28_8
  unsigned int v75; // r3
  unsigned int v76; // r0
  int v77; // r0
  __int16 v78; // r3
  unsigned int v79; // r4
  _DWORD *v80; // r5
  int *v81; // r8
  unsigned int v82; // r3
  int v83; // r7
  unsigned int v84; // r10
  int v85; // r4
  unsigned int *v86; // r2
  unsigned int v87; // r1
  _DWORD *v88; // [sp+10h] [bp-80h]
  int v89; // [sp+14h] [bp-7Ch]
  int v90; // [sp+18h] [bp-78h]
  unsigned int v92; // [sp+20h] [bp-70h] BYREF
  unsigned int v93; // [sp+24h] [bp-6Ch] BYREF
  int v94; // [sp+28h] [bp-68h]
  unsigned int v95; // [sp+2Ch] [bp-64h]
  int v96; // [sp+30h] [bp-60h]
  int v97; // [sp+34h] [bp-5Ch]
  unsigned int v98; // [sp+38h] [bp-58h]
  int v99[2]; // [sp+40h] [bp-50h] BYREF
  int *v100; // [sp+48h] [bp-48h]
  int v101; // [sp+4Ch] [bp-44h]
  unsigned int v102; // [sp+50h] [bp-40h]
  int v103; // [sp+54h] [bp-3Ch]
  unsigned int *v104; // [sp+58h] [bp-38h]
  __int16 *v105; // [sp+5Ch] [bp-34h]
  int v106; // [sp+60h] [bp-30h]
  unsigned int v107; // [sp+64h] [bp-2Ch]
  unsigned int *v108; // [sp+68h] [bp-28h]
  int v109; // [sp+6Ch] [bp-24h]

  v94 = a2;
  v15 = a1;
  v101 = 0;
  v103 = 0;
  v95 = *a1;
  v92 = a11 & 0x7F;
  v108 = a3;
  if ( v92 > (unsigned __int16)KeNumberNodes )
    return sub_801A68();
  v18 = a11 & 0x2000;
  v97 = v18;
  if ( (a11 & 0x2000) != 0 && !a1[8] )
    return sub_801A68();
  v96 = a11 & 0x40000000;
  v19 = 0x10000;
  if ( (a11 & 0x40000000) != 0 )
  {
    if ( (a11 & 0x2000) != 0 )
      return -1073741583;
    v19 = 4096;
  }
  v90 = v19;
  v20 = *a5;
  if ( !*a5 )
  {
    v56 = *(_DWORD *)a4 & ~(v19 - 1);
    *(_DWORD *)a4 = v56;
    v57 = *(_QWORD *)(a6 + 24) - __PAIR64__(*(_DWORD *)(a4 + 4), v56);
    *a5 = v57;
    if ( !HIDWORD(v57) )
      goto LABEL_8;
    return -1073741793;
  }
  v21 = (v19 - 1) & *(_DWORD *)a4;
  if ( (unsigned int)v20 + (unsigned __int64)(unsigned int)v21 < (unsigned int)v21 )
    return -1073741793;
  *a5 = v21 + v20;
  v18 = v97;
  *(_DWORD *)a4 &= ~(v19 - 1);
LABEL_8:
  if ( *a5 > MmHighestUserAddress - *a3 - 0xFFFF || *a5 <= 0 || v18 && *(_DWORD *)(a4 + 4) >= 0x100u )
    return -1073741793;
  v88 = 0;
  v102 = 0;
  v106 = 0;
  v105 = MiGetThreadPartition();
  v89 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  MiCheckPurgeAndUpMapCount(v15);
  v22 = *(__int64 *)a4 >> 12;
  v23 = *(int *)(a4 + 4) >> 12;
  v24 = (*(_QWORD *)a4 + (unsigned int)*a5 + 4095i64) >> 12;
  LODWORD(v25) = MiGetControlAreaPtes(a1);
  v98 = HIDWORD(v25);
  v93 = v25;
  if ( __PAIR64__(v23, v22) >= v25 )
  {
    v26 = -1073741793;
LABEL_114:
    MiDereferenceControlArea(a1);
    if ( v102 )
      ExFreePoolWithTag(v102);
    if ( v88 )
    {
      if ( (v88[17] & 0x80000000) != 0 )
        MiDereferenceExtendInfo((int)v88, (int)a1);
      v62 = v88[18];
      if ( v62 )
        ObfDereferenceObject(v62);
      ExFreePoolWithTag((unsigned int)v88);
    }
    if ( v103 )
      MiReturnCommit((int)v105, v103);
    return v26;
  }
  v58 = 0;
  if ( a1[8] )
  {
    v27 = (unsigned int *)MiLocateSubsectionNode(a1, *(_QWORD *)a4, 0);
    v104 = v27;
  }
  else
  {
    v99[0] = v22;
    v99[1] = v23;
    v27 = MiLocatePagefileSubsection(a1 + 20, (int)v99);
    v104 = v27;
    if ( !a9 && a8 == 24 && (a1[7] & 0x1000) != 0 )
      v58 = 1;
  }
  v28 = v27[5];
  v29 = *((unsigned __int16 *)v27 + 8);
  v107 = v22 - v28;
  __SET_PAIR__(v30, v30, __PAIR64__(v23, v22) - __PAIR64__(v29 >> 6, v28));
  v33 = v24 - v28;
  v32 = (v24 - __PAIR64__(v29 >> 6, v28)) >> 32;
  v31 = v33;
  v99[0] = v30;
  if ( v58 == 1 )
  {
    v31 = 1;
    v32 = 0;
  }
  v26 = MiAddViewsForSection((int)v27, __PAIR64__(v32, v31), 0);
  if ( v26 < 0 )
    goto LABEL_114;
  v100 = (int *)(v27[1] + 4 * v107);
  if ( !a1[8] && a9 && (v98 || *(_DWORD *)(v95 + 12) < v93) )
    v101 = (int)(4 * (((a9 & 0xFFF) != 0) + (a9 >> 12))) >> 2;
  v98 = 0;
  v93 = 0;
  v34 = *(_DWORD *)(a6 + 12) << 12;
  v35 = (*(_DWORD *)(a6 + 32) >> 11) & 1;
  if ( (*(_WORD *)(v95 + 8) & 0x1000) != 0
    && (*a5 & 0x3FFFFF) == 0
    && !v97
    && (a8 & 0xFFFFFFF8) != 16
    && a8 != 24
    && (a8 & 5) != 5 )
  {
    v90 = 0x400000;
  }
  v36 = (_BYTE *)ExAllocatePoolWithTag(512, 76, 543449430);
  v88 = v36;
  if ( !v36 )
  {
    v26 = -1073741670;
LABEL_112:
    v61 = a1[8];
    if ( v61 )
      MiRemoveViewsFromSectionWithPfn(v27, v61, v31, v32);
    goto LABEL_114;
  }
  memset(v36, 0, 76);
  v88[2] = -2;
  v37 = v100;
  v88[11] = v27;
  v88[12] = v37;
  v59 = v92;
  v88[10] = v88[10] & 0xF3FFFFFF | (((a7 == 1) | (2 * (v35 & 1))) << 26);
  v88[7] = v88[7] & 0xFFFFC007 | (8 * (a8 & 0x1F | (32 * (v59 & 0x3F))));
  if ( v59 )
    MEMORY[0xC040213C] = 1;
  if ( a1[8] && !v97 )
    v88[10] |= 0x2000000u;
  v88[6] = 0;
  v88[10] = v88[10] & 0xFF000000 | (*(__int64 *)a4 >> 16) & 0xFFFFFF;
  v88[18] = MiReferenceFileObjectForMap(a6);
  LOCK_ADDRESS_SPACE(v89, v94);
  if ( (*(_DWORD *)(v94 + 192) & 0x20) != 0 )
  {
    v26 = -1073741558;
    goto LABEL_110;
  }
  if ( *v108 )
  {
    v39 = *v108 & ~(v90 - 1);
  }
  else
  {
    if ( !v34 )
    {
      v38 = a11;
      v26 = MiSelectUserAddress(a11, a10, *a5, v90, a8, &v93, &v92);
      if ( v26 < 0 )
      {
        if ( v90 == 0x400000 )
        {
          if ( v96 )
            v63 = 4096;
          else
            v63 = 0x10000;
          v90 = v63;
          v26 = MiSelectUserAddress(a11, a10, *a5, v63, a8, &v93, &v92);
        }
        if ( v26 < 0 )
          goto LABEL_110;
      }
      v39 = v92;
      v40 = (*a5 + v92 - 1) | 0xFFF;
      v92 = v40;
      v98 = v93;
      goto LABEL_30;
    }
    v39 = *(_DWORD *)a4 + v34;
  }
  if ( v39 < 0x10000 && !*(_DWORD *)(v94 + 780) )
  {
    v26 = -1073741583;
    goto LABEL_110;
  }
  if ( (v39 & 0x3FFFFF) != 0 )
  {
    if ( v96 )
      v90 = 4096;
    else
      v90 = 0x10000;
  }
  v40 = (*a5 + v39 - 1) | 0xFFF;
  v92 = v40;
  if ( MiCheckForConflictingVadExistence() )
  {
    v26 = -1073741800;
    goto LABEL_110;
  }
  v38 = a11;
LABEL_30:
  v41 = v88;
  v42 = v97;
  v43 = v39 >> 12;
  v44 = v40 >> 12;
  v88[3] = v39 >> 12;
  v88[4] = v40 >> 12;
  v109 = v40 >> 12;
  if ( v42 )
  {
    --*(_WORD *)(v89 + 310);
    v64 = KeAbPreAcquire((unsigned int)&dword_632E10, 0, 0);
    v96 = v64;
    do
      v65 = __ldrex((unsigned __int8 *)&dword_632E10);
    while ( __strex(v65 | 1, (unsigned __int8 *)&dword_632E10) );
    __dmb(0xBu);
    if ( (v65 & 1) != 0 )
    {
      ExfAcquirePushLockExclusiveEx(&dword_632E10, v96, (unsigned int)&dword_632E10);
      v64 = v96;
    }
    if ( v64 )
      *(_BYTE *)(v64 + 14) |= 1u;
    v66 = *(_DWORD *)(v95 + 24);
    if ( v66 )
    {
      ++*(_DWORD *)(v66 + 8);
    }
    else
    {
      v67 = ExAllocatePoolWithTag(512, 16, 2017684813);
      v66 = v67;
      if ( !v67 )
      {
        __dmb(0xBu);
        do
          v68 = __ldrex((unsigned int *)&dword_632E10);
        while ( __strex(v68 - 1, (unsigned int *)&dword_632E10) );
        if ( (v68 & 2) != 0 && (v68 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&dword_632E10);
        v69 = KeAbPostRelease((unsigned int)&dword_632E10);
        v70 = *(_WORD *)(v89 + 310) + 1;
        *(_WORD *)(v89 + 310) = v70;
        if ( !v70 && *(_DWORD *)(v89 + 100) != v89 + 100 )
          KiCheckForKernelApcDelivery(v69);
        v26 = -1073741670;
        goto LABEL_110;
      }
      *(_DWORD *)(v67 + 8) = 1;
      __dmb(0xBu);
      v71 = v95;
      v72 = (unsigned __int64 *)(v95 + 16);
      do
        v73 = __ldrexd(v72);
      while ( v73 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v72) );
      __dmb(0xBu);
      *(_QWORD *)v66 = v73;
      *(_DWORD *)(v71 + 24) = v66;
    }
    v74 = *(_QWORD *)(a6 + 24);
    v75 = *(_DWORD *)(v66 + 4);
    if ( *(_QWORD *)v66 < v74 )
      *(_QWORD *)v66 = v74;
    __dmb(0xBu);
    v93 = v75;
    do
      v76 = __ldrex((unsigned int *)&dword_632E10);
    while ( __strex(v76 - 1, (unsigned int *)&dword_632E10) );
    v93 = v76;
    if ( (v76 & 2) != 0 && (v76 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&dword_632E10);
    v77 = KeAbPostRelease((unsigned int)&dword_632E10);
    v78 = *(_WORD *)(v89 + 310) + 1;
    *(_WORD *)(v89 + 310) = v78;
    if ( !v78 && *(_DWORD *)(v89 + 100) != v89 + 100 )
      KiCheckForKernelApcDelivery(v77);
    v41 = v88;
    v44 = v109;
    v88[17] = v66;
    v38 = a11;
  }
  if ( (a8 & 5) == 5 )
    v41[8] = v41[8] & 0x80000000 | (v41[4] - v41[3] + 1) & 0x7FFFFFFF;
  LODWORD(v45) = v107;
  v46 = v44 - v43;
  v47 = v27[7];
  v48 = v46;
  HIDWORD(v45) = v99[0];
  v49 = v45 + v48;
  if ( v49 >= v47 )
    v50 = v27[1] + 4 * (v47 + v27[9]) - 4;
  else
    v50 = v27[1] + 4 * v49;
  v41[13] = v50;
  if ( (v38 & 0x400000) != 0 || (*(_DWORD *)(a6 + 32) & 0x4000) != 0 )
  {
    v102 = MiAddSecureEntry(v41, v39, v40, 0x80000000, 0);
    if ( !v102 )
    {
      v26 = -1073741670;
      goto LABEL_110;
    }
  }
  v51 = v101;
  if ( v101 )
  {
    if ( !MiChargeCommit((int)v105, v101, 0) )
    {
      v26 = -1073741523;
      goto LABEL_110;
    }
    v103 = v51;
  }
  v52 = (int)v88;
  if ( v90 == 0x400000 )
  {
    v88[7] |= 7u;
    v88[10] |= 0x1000000u;
  }
  if ( !a1[8] )
  {
    v26 = MiInsertSharedCommitNode(a1, v94, 0);
    if ( v26 < 0 )
      goto LABEL_110;
    v52 = (int)v88;
    v106 = 1;
  }
  v26 = MiInsertVadCharges(v52, v94);
  if ( v26 < 0 )
  {
LABEL_110:
    v60 = v94;
    UNLOCK_ADDRESS_SPACE(v89, v94);
    if ( v106 == 1 )
      MiRemoveSharedCommitNode(a1, v60, 0);
    goto LABEL_112;
  }
  MiGetWsAndInsertVad(v88);
  v79 = v92;
  if ( v90 == 0x400000 )
  {
    v80 = (_DWORD *)(((v39 >> 20) & 0xFFC) - 1070596096);
    v99[0] = ((v92 >> 20) & 0xFFC) - 1070596096;
    v81 = v100;
    v82 = MiDetermineUserGlobalPteMask(((v39 >> 10) & 0x3FFFFC) - 0x40000000) | MmProtectToPteMask[a8] | 0xFFFFF012;
    if ( (v82 & 0x80) != 0 )
      LOWORD(v82) = v82 & 0xFDFF | 0x10;
    LOWORD(v83) = v82 | 0x400;
    MiLockVad(v89, (int)v88);
    v84 = v99[0];
    v85 = v94;
    do
    {
      v83 = *v81 & 0xFFFFF000 | v83 & 0xFFF;
      MiWriteLargePde(v85, v80++, v83, v83);
      v81 += 1024;
    }
    while ( (unsigned int)v80 <= v84 );
    MiUnlockVad(v89, (int)v88);
    v27 = v104;
    v79 = v92;
    v43 = v39 >> 12;
  }
  if ( !a1[8] && !*(_DWORD *)(v95 + 36) )
    *(_DWORD *)(v95 + 36) = v39;
  if ( v101 )
    MiChargeSegmentCommit((int **)v27, v100, v101, 1);
  if ( v98 == 1 )
    MiAdvanceVadHint(v43, v79 >> 12);
  *a5 = v79 - v39 + 1;
  *v108 = v39;
  if ( (a8 == 4 || a8 == 6) && a1[8] )
  {
    v86 = a1 + 13;
    do
      v87 = __ldrex(v86);
    while ( __strex(v87 + 1, v86) );
    __dmb(0xBu);
  }
  if ( (PerfGlobalGroupMask & 0x8000) != 0 )
    MiLogMapFileEvent(v88, 1061);
  v26 = 0;
  if ( a14 )
    MiReferenceVad((int)v88);
  v53 = 0;
  if ( (a8 & 2) != 0 && MiIsProcessCfgEnabled() )
  {
    MiLockVad(v89, (int)v88);
    UNLOCK_ADDRESS_SPACE_UNORDERED(v89, v94);
    v54 = 0;
    v53 = 1;
    v26 = MiCommitVadCfgBits((int)v88, 0, a13);
    if ( v26 < 0 )
    {
      if ( !a14 )
        MiReferenceVad((int)v88);
      MiUnmapVad(v88, 0);
      return v26;
    }
  }
  else
  {
    v54 = 1;
  }
  if ( !a14 )
  {
    if ( v53 == 1 )
      MiUnlockVad(v89, (int)v88);
    if ( v54 == 1 )
      UNLOCK_ADDRESS_SPACE(v89, v94);
    return v26;
  }
  if ( v53 != 1 )
    MiLockVad(v89, (int)v88);
  if ( v54 == 1 )
    UNLOCK_ADDRESS_SPACE_UNORDERED(v89, v94);
  if ( a12 != 1 && a12 != 2 && a12 != -2147483647 && a12 != 4 )
  {
    v55 = -1073741755;
    goto LABEL_196;
  }
  v55 = MiSecureVad((int)v88, v39, *a5, a12, v99);
  if ( v55 < 0 )
  {
LABEL_196:
    v26 = v55;
    MiUnmapVad(v88, 0);
    return v26;
  }
  MiUnlockAndDereferenceVad((int)v88);
  result = v26;
  *a14 = v99[0];
  return result;
}
