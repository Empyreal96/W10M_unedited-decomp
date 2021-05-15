// CmpReorganizeHive 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpReorganizeHive(int a1, int a2)
{
  int v3; // r8
  int v4; // r3
  unsigned int v5; // r0
  unsigned int v6; // r2
  unsigned int v7; // r1
  unsigned int v9; // r9
  unsigned __int8 *v10; // r0
  unsigned __int64 v11; // kr08_8
  unsigned int v12; // lr
  unsigned int v13; // r4
  unsigned int v14; // r1
  bool v15; // zf
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r4
  int v19; // r3
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r7
  int v23; // r0
  unsigned int v24; // r1
  unsigned int v25; // r1
  __int16 v26; // r3
  int v27; // r1
  int v28; // r0
  int v29; // r0
  int v30; // r1
  unsigned int v31; // r8
  unsigned int v32; // r9
  int v33; // r0
  int v34; // r4
  unsigned int v35; // r2
  int v36; // r0
  unsigned int *v37; // r8
  unsigned int v38; // r1
  int v39; // r0
  unsigned int v40; // r8
  int v41; // r4 OVERLAPPED
  int v42; // r0
  int v43; // r0
  unsigned int v44; // r3
  int v45; // r2
  int v46; // r1
  unsigned int i; // r8
  int v48; // r0
  _DWORD *v49; // r4
  int v50; // r0
  unsigned int v51; // r9
  int v52; // r2
  int v53; // r1
  int v54; // r1
  int v55; // r9
  int v56; // r8
  int *v57; // r4
  int v58; // r2
  int **v59; // r1
  _DWORD *v60; // r8
  _DWORD *v61; // r2
  int *v62; // r10
  _DWORD *v63; // r1
  _DWORD *v64; // r2 OVERLAPPED
  int v65; // r1 OVERLAPPED
  int v66; // r2
  int v67; // r3
  __int64 v68; // r0
  unsigned int v69; // lr
  _DWORD *v70; // r2
  int v71; // r4
  _DWORD *v72; // r4
  unsigned int v73; // r10
  int v74; // r3
  unsigned int v75; // r8
  unsigned int v76; // r9
  int v77; // r0
  int v78; // r4
  unsigned __int64 v79; // r2
  unsigned int *v80; // r4
  unsigned int v81; // r1
  int v82; // r0
  int v83; // r1
  int v84; // r0
  int v85; // r0
  unsigned int v86; // r1
  unsigned int v87; // r1
  int v88; // r3
  int v89; // [sp+10h] [bp-1F0h]
  int v90; // [sp+14h] [bp-1ECh]
  int v91; // [sp+18h] [bp-1E8h]
  unsigned int v93; // [sp+20h] [bp-1E0h]
  _DWORD *v94; // [sp+24h] [bp-1DCh]
  int v95; // [sp+28h] [bp-1D8h]
  unsigned int v96; // [sp+2Ch] [bp-1D4h]
  int v97; // [sp+30h] [bp-1D0h]
  unsigned int v98; // [sp+34h] [bp-1CCh]
  int v99; // [sp+38h] [bp-1C8h] BYREF
  unsigned int v100; // [sp+3Ch] [bp-1C4h]
  char v101[448]; // [sp+40h] [bp-1C0h] BYREF

  v89 = 0;
  v90 = 0;
  v3 = a2;
  if ( (*(_DWORD *)(*(_DWORD *)(a1 + 32) + 144) & 1) == 0
    && (*(_DWORD *)(a1 + 1776) || (*(_DWORD *)(a1 + 92) & 0x10) != 0)
    && (*(_DWORD *)(a1 + 92) & 0x8001) == 0
    && *(_DWORD *)(a1 + 96)
    && a2 )
  {
    v4 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v4 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v5 = CmpShutdownRundown & 0xFFFFFFFE;
    v6 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v7 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v7 == v5 && __strex(v6, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v7 != v5 )
      return sub_7D2E98();
    KeQuerySystemTime(&v99);
    v9 = v100;
    v11 = *(_QWORD *)(*(_DWORD *)(a1 + 32) + 168);
    v10 = (unsigned __int8 *)v11;
    v12 = v99 & 0xFFFFFFFC;
    if ( v11 <= __PAIR64__(v100, v99 & 0xFFFFFFFC) )
    {
      if ( __PAIR64__(v100, v12) - v11 < 86400
                                       * (unsigned int)CmpReorganizeDelayDays
                                       * (unsigned __int64)(unsigned int)dword_989680 )
      {
        __pld(&CmpShutdownRundown);
        v13 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v14 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v14 == v13 && __strex(v13 - 2, (unsigned int *)&CmpShutdownRundown) );
        v15 = v14 == v13;
LABEL_17:
        if ( !v15 )
          v10 = ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
        *(_WORD *)(v16 + 308) = v17;
        if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
          KiCheckForKernelApcDelivery((int)v10);
        return 0;
      }
      v3 = a2;
    }
    if ( v11 == 2 || v11 != 1 && (*(_DWORD *)(a1 + 3228) & 0x400) == 0 )
    {
      CmpClearKeyAccessBits(a1, v3);
      v19 = *(_DWORD *)(a1 + 32);
      *(_DWORD *)(v19 + 168) = v12 | 2;
      *(_DWORD *)(v19 + 172) = v9;
      __pld(&CmpShutdownRundown);
      v10 = (unsigned __int8 *)(CmpShutdownRundown & 0xFFFFFFFE);
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( (unsigned __int8 *)v20 == v10 && __strex((unsigned int)(v10 - 2), (unsigned int *)&CmpShutdownRundown) );
      v15 = v20 == (_DWORD)v10;
      goto LABEL_17;
    }
    v95 = v12 | 1;
    v21 = CmpCreateTemporaryHive();
    v22 = v21;
    if ( !v21 )
    {
      __pld(&CmpShutdownRundown);
      v23 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v24 == v23 && __strex(v23 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v24 != v23 )
        v23 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(_WORD *)(v25 + 0x134) + 1;
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(v23);
      return -1073741670;
    }
    *(_DWORD *)(*(_DWORD *)(v21 + 32) + 24) = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 24);
    *(_DWORD *)(v21 + 148) = *(_DWORD *)(a1 + 148);
    v27 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36);
    if ( v27 == -1 )
    {
      v18 = 0;
      goto LABEL_146;
    }
    v28 = CmpCopyKeyPartial(a1, v27, v21, -1, 6);
    if ( v28 == -1
      || (*(_DWORD *)(*(_DWORD *)(v22 + 32) + 36) = v28,
          (v29 = CmpCopySyncTree(a1, *(_DWORD *)(*(_DWORD *)(a1 + 32) + 36), v22, v28, 66, 0)) == 0) )
    {
      v18 = -1073741670;
LABEL_146:
      CmpDestroyTemporaryHive(v22);
      __pld(&CmpShutdownRundown);
      v85 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v86 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v86 == v85 && __strex(v85 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v86 != v85 )
        v85 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v87 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v88 = (__int16)(*(_WORD *)(v87 + 0x134) + 1);
      *(_WORD *)(v87 + 308) = v88;
      if ( !v88 && *(_DWORD *)(v87 + 100) != v87 + 100 && !*(_WORD *)(v87 + 310) )
        KiCheckForKernelApcDelivery(v85);
      return v18;
    }
    v96 = *(_DWORD *)(v22 + 952);
    CmpLockRegistry(v29, v30);
    ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 1872), 1);
    v31 = *(_DWORD *)(a1 + 1868);
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = KeAbPreAcquire(v31, 0, 0);
    v34 = v33;
    do
      v35 = __ldrex((unsigned __int8 *)v31);
    while ( __strex(v35 & 0xFE, (unsigned __int8 *)v31) );
    __dmb(0xBu);
    if ( (v35 & 1) == 0 )
      ExpAcquireFastMutexContended(v31, v33);
    if ( v34 )
      *(_BYTE *)(v34 + 14) |= 1u;
    *(_DWORD *)(v31 + 4) = v32;
    v36 = CmpDoFileSetSizeEx(a1, 0, v96 + 4096, 0, 1);
    v37 = *(unsigned int **)(a1 + 1868);
    v18 = v36;
    v37[1] = 0;
    __dmb(0xBu);
    do
      v38 = __ldrex(v37);
    while ( !v38 && __strex(1u, v37) );
    if ( v38 )
      ExpReleaseFastMutexContended(v37, v38);
    KeAbPostRelease((unsigned int)v37);
    v39 = ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
    CmpUnlockRegistry(v39);
    if ( v18 < 0 )
      goto LABEL_146;
    v98 = *(_DWORD *)(a1 + 952);
    v40 = ((v96 >> 12) + 3) & 0xFFFFFFFC;
    v93 = v40;
    if ( v40 < *(_DWORD *)(a1 + 48) )
    {
      v40 = *(_DWORD *)(a1 + 48);
      v93 = v40;
    }
    else
    {
      v89 = (*(int (__fastcall **)(unsigned int, int, int))(a1 + 12))(((v96 >> 12) + 3) & 0xFFFFFFFC, 1, 842157379);
      if ( !v89 )
      {
        v18 = -1073741801;
        goto LABEL_146;
      }
      v90 = (*(int (__fastcall **)(unsigned int, int, int))(a1 + 12))(((v96 >> 12) + 3) & 0xFFFFFFFC, 1, 842157379);
      if ( !v90 )
      {
        v18 = -1073741801;
LABEL_142:
        if ( v89 )
          (*(void (__fastcall **)(int, unsigned int))(a1 + 16))(v89, v93);
        if ( v90 )
          (*(void (__fastcall **)(int, unsigned int))(a1 + 16))(v90, v93);
        goto LABEL_146;
      }
    }
    if ( (*(_BYTE *)(a1 + 72) & 4) == 0 || (v18 = HvViewMapPinForFileOffset(a1 + 152, 4096, v96), v18 >= 0) )
    {
      v41 = v90;
      if ( v89 || v90 )
      {
        v42 = *(_DWORD *)(a1 + 40);
        if ( v42 )
          (*(void (__fastcall **)(int, _DWORD))(a1 + 16))(v42, *(_DWORD *)(a1 + 48));
        v43 = *(_DWORD *)(a1 + 56);
        if ( v43 )
          (*(void (__fastcall **)(int, _DWORD))(a1 + 16))(v43, *(_DWORD *)(a1 + 48));
      }
      else
      {
        v41 = *(_DWORD *)(a1 + 56);
        v89 = *(_DWORD *)(a1 + 40);
      }
      v44 = v96 >> 9;
      *(_DWORD *)(a1 + 36) = v96 >> 9;
      *(_DWORD *)(a1 + 40) = v89;
      *(_QWORD *)(a1 + 52) = *(_QWORD *)(&v41 - 1);
      v89 = 0;
      v90 = 0;
      *(_DWORD *)(a1 + 48) = v40;
      RtlSetAllBits((_DWORD *)(a1 + 36));
      *(_DWORD *)(a1 + 44) = *(_DWORD *)(a1 + 36);
      RtlClearAllBits(a1 + 52);
      *(_DWORD *)(a1 + 60) = 0;
      v45 = *(_DWORD *)(a1 + 32);
      v46 = *(_DWORD *)(v45 + 36);
      *(_DWORD *)(v45 + 36) = *(_DWORD *)(*(_DWORD *)(v22 + 32) + 36);
      *(_DWORD *)(*(_DWORD *)(v22 + 32) + 36) = v46;
      if ( (*(_BYTE *)(a1 + 72) & 4) != 0 )
      {
        for ( i = 0; i < *(_DWORD *)(v22 + 952); i += 4096 )
        {
          v48 = HvpGetCellMap(v22, i);
          v49 = (_DWORD *)v48;
          if ( !v48 )
            KeBugCheckEx(81, 1, v22, i, 1384);
          v50 = HvpMapEntryGetFreeBin(v48);
          if ( v50 )
            v51 = *(_DWORD *)(v50 + 12);
          else
            v51 = i - *v49;
          v52 = v49[1];
          v53 = *(_DWORD *)((v52 & 0xFFFFFFF0) + 8);
          v49[2] = v52 & 0xFFFFFFF0;
          v49[1] = v52 & 0xF;
          if ( HvpCheckViewBoundary(v51, v53 + v51 - 1) )
            v49[1] |= HvViewMapAddressForFileOffset(a1 + 152, v51 + 4096);
          v49[3] = 0;
        }
        *(_BYTE *)(v22 + 72) |= 4u;
      }
      v54 = v22;
      v97 = 0;
      v91 = v22;
      v55 = a1 + 960;
      v56 = v22 - a1;
      do
      {
        v57 = (int *)(v55 + 392);
        v58 = *(_DWORD *)(v55 + 392);
        v94 = 0;
        if ( v58 != v55 + 392 )
        {
          v59 = *(int ***)(v55 + 396);
          v94 = *(_DWORD **)(v55 + 392);
          if ( *(int **)(v58 + 4) != v57 || *v59 != v57 )
            __fastfail(3u);
          *v59 = (int *)v58;
          *(_DWORD *)(v58 + 4) = v59;
          v54 = v91;
        }
        v60 = (int *)((char *)v57 + v56);
        v61 = (_DWORD *)*v60;
        v62 = 0;
        if ( (_DWORD *)*v60 != v60 )
        {
          v62 = *(int **)(v54 + 1352);
          v63 = (_DWORD *)v60[1];
          if ( (_DWORD *)v61[1] != v60 || (_DWORD *)*v63 != v60 )
            __fastfail(3u);
          *v63 = v61;
          v61[1] = v63;
        }
        memmove((int)v101, v55 - 8, 0x19Cu);
        memmove(v55 - 8, v91 + 952, 0x19Cu);
        memmove(v91 + 952, (int)v101, 0x19Cu);
        v64 = v94;
        *v57 = (int)v57;
        *(_DWORD *)(v55 + 396) = v55 + 392;
        *v60 = v60;
        v60[1] = v60;
        if ( v94 )
        {
          v65 = *v94;
          *(_QWORD *)v60 = *(_QWORD *)(&v64 - 1);
          if ( *(_DWORD **)(v65 + 4) != v94 )
            __fastfail(3u);
          *(_DWORD *)(v65 + 4) = v60;
          *v94 = v60;
        }
        if ( v62 )
        {
          v66 = *v62;
          *v57 = *v62;
          *(_DWORD *)(v55 + 396) = v62;
          if ( *(int **)(v66 + 4) != v62 )
            __fastfail(3u);
          *(_DWORD *)(v66 + 4) = v57;
          *v62 = (int)v57;
        }
        v56 = v22 - a1;
        if ( *(_DWORD *)(v91 + 956) == v55 )
          *(_DWORD *)(v91 + 956) = v56 + v55;
        if ( *(_DWORD *)(v55 - 4) == v56 + v55 )
          *(_DWORD *)(v55 - 4) = v55;
        v54 = v91 + 412;
        ++v97;
        v91 += 412;
        v55 += 412;
      }
      while ( v97 <= 1 );
      v67 = *(_DWORD *)(a1 + 92);
      if ( (v67 & 0x10) != 0 )
      {
        *(_DWORD *)(a1 + 92) = v67 & 0xFFFFFFEF;
        *(_DWORD *)(v22 + 92) |= 0x10u;
      }
      CmpDestroySecurityCache((_DWORD *)a1);
      v69 = 0;
      *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40) = *(_DWORD *)(*(_DWORD *)(v22 + 32) + 40);
      v70 = (_DWORD *)(a1 + 2008);
      *(_DWORD *)(a1 + 1992) = *(_DWORD *)(v22 + 1992);
      *(_DWORD *)(a1 + 1996) = *(_DWORD *)(v22 + 1996);
      *(_DWORD *)(a1 + 2000) = *(_DWORD *)(v22 + 2000);
      *(_DWORD *)(a1 + 2004) = *(_DWORD *)(v22 + 2004);
      do
      {
        *v70 = v70;
        v70[1] = v70;
        LODWORD(v68) = (char *)v70 + v56;
        while ( *(_DWORD *)v68 != (_DWORD)v68 )
        {
          HIDWORD(v68) = *(_DWORD *)v68;
          v71 = **(_DWORD **)v68;
          if ( __PAIR64__(*(_DWORD *)(v71 + 4), *(_DWORD *)(*(_DWORD *)v68 + 4)) != v68 )
            __fastfail(3u);
          *(_DWORD *)v68 = v71;
          *(_DWORD *)(v71 + 4) = v68;
          v72 = (_DWORD *)v70[1];
          *(_DWORD *)HIDWORD(v68) = v70;
          *(_DWORD *)(HIDWORD(v68) + 4) = v72;
          if ( (_DWORD *)*v72 != v70 )
            __fastfail(3u);
          *v72 = HIDWORD(v68);
          v70[1] = HIDWORD(v68);
        }
        ++v69;
        v70 += 2;
      }
      while ( v69 < 0x40 );
      *(_DWORD *)(v22 + 2004) = 0;
      *(_DWORD *)(v22 + 1996) = 0;
      *(_DWORD *)(v22 + 1992) = 0;
      v73 = v100;
      *(_DWORD *)(a1 + 3840) = *(_DWORD *)(v22 + 3840);
      *(_DWORD *)(a1 + 3844) = *(_DWORD *)(v22 + 3844);
      *(_DWORD *)(a1 + 3848) = *(_DWORD *)(v22 + 3848);
      v74 = *(_DWORD *)(a1 + 32);
      *(_DWORD *)(v74 + 168) = v95;
      *(_DWORD *)(v74 + 172) = v73;
      CmpLockRegistry(v68, HIDWORD(v68));
      ExAcquireResourceSharedLite(*(_DWORD *)(a1 + 1872), 1);
      v75 = *(_DWORD *)(a1 + 1868);
      v76 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v77 = KeAbPreAcquire(v75, 0, 0);
      v78 = v77;
      do
      {
        LODWORD(v79) = __ldrex((unsigned __int8 *)v75);
        HIDWORD(v79) = __strex(v79 & 0xFE, (unsigned __int8 *)v75);
      }
      while ( HIDWORD(v79) );
      __dmb(0xBu);
      if ( (v79 & 1) == 0 )
        ExpAcquireFastMutexContended(v75, v77);
      if ( v78 )
      {
        HIDWORD(v79) = *(unsigned __int8 *)(v78 + 14) | 1;
        *(_BYTE *)(v78 + 14) = BYTE4(v79);
      }
      *(_DWORD *)(v75 + 4) = v76;
      HvMarkBaseBlockDirty(a1, v79);
      v80 = *(unsigned int **)(a1 + 1868);
      v80[1] = 0;
      __dmb(0xBu);
      do
        v81 = __ldrex(v80);
      while ( !v81 && __strex(1u, v80) );
      if ( v81 )
        ExpReleaseFastMutexContended(v80, v81);
      KeAbPostRelease((unsigned int)v80);
      v82 = ExReleaseResourceLite(*(_DWORD *)(a1 + 1872));
      CmpUnlockRegistry(v82);
      CmpLogReorganizeEvent(a2, v98, v96);
      if ( v96 < v98 )
      {
        if ( CmpFirstReorganize )
        {
          v83 = 0;
          v84 = 0;
          CmpReorganizeLastRun = v95;
          unk_64B074 = v73;
          CmpFirstReorganize = 0;
        }
        else
        {
          v84 = MEMORY[0x64A424];
          v83 = CmpReorganizeTotalBytesSaved;
        }
        CmpReorganizeTotalBytesSaved = v98 - v96 + v83;
        MEMORY[0x64A424] = __CFADD__(v98 - v96, v83) + v84;
        CmpUpdateReorganizeRegistryValues();
      }
      v18 = 0;
    }
    goto LABEL_142;
  }
  return 0;
}
