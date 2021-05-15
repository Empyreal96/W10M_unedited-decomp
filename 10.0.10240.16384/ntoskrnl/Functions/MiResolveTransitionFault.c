// MiResolveTransitionFault 
 
int __fastcall MiResolveTransitionFault(int a1, unsigned int a2, unsigned int a3, int a4, unsigned __int8 a5, int a6, int a7, _DWORD *a8)
{
  unsigned int v8; // r4
  unsigned int v10; // r4
  int v11; // r6
  unsigned __int8 *v12; // r1
  unsigned int v13; // r3
  int v15; // r10
  unsigned int *v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r2
  int v19; // r3
  _WORD *v20; // r7
  int v21; // r4
  int v22; // r5
  int v23; // r4
  unsigned int v24; // r7
  int v25; // r5
  int v26; // r4
  int v27; // r0
  char v28; // r1
  int v29; // r2
  int v30; // r0
  unsigned int v31; // r4
  int v32; // r3
  unsigned int v33; // r7
  unsigned int v34; // r3
  int v35; // lr
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r4
  int v39; // r1
  unsigned int v40; // r0
  int v41; // r5
  unsigned __int8 *v42; // r1
  unsigned int v43; // r2
  int v44; // r2
  char v45; // r1
  int v46; // r4
  int v47; // r3
  int v48; // r2
  int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r2
  unsigned int v52; // r0
  unsigned int v53; // r3
  unsigned int *v54; // r4
  int v55; // r1
  unsigned int v56; // r0
  unsigned int v57; // r0
  unsigned int *v58; // r2
  unsigned int v59; // r5
  int v60; // r3
  unsigned int *v61; // r2
  unsigned int v62; // r4
  unsigned int v63; // r3
  int v64; // r4
  unsigned int v65; // r2
  int v66; // r1
  BOOL v67; // r0
  unsigned __int8 *v68; // r1
  unsigned int v69; // r2
  unsigned int *v70; // r2
  unsigned int v71; // r0
  unsigned int *v72; // r2
  unsigned int v73; // r0
  int v74; // r4
  unsigned int *v75; // r2
  unsigned int v76; // r0
  char v77; // r3
  int v78; // r3
  unsigned int v79; // r2
  unsigned int *v80; // r2
  unsigned int v81; // r0
  unsigned int v82; // r0
  unsigned int *v83; // r1
  unsigned int v84; // r4
  unsigned int *v85; // r2
  unsigned int v86; // r0
  int v87; // r3
  unsigned int v88; // r2
  unsigned int *v89; // r2
  unsigned int v90; // r0
  int v91; // r0
  int v92; // r2
  unsigned int *v93; // r2
  unsigned int v94; // r0
  int v95; // r3
  unsigned int v96; // r3
  int v97; // r4
  int v98; // r0
  unsigned int v99; // r2
  int v100; // r4
  unsigned int v101; // r0
  int v102; // r0
  unsigned int v105; // [sp+1Ch] [bp-3Ch]
  int v107; // [sp+28h] [bp-30h] BYREF
  unsigned int v108; // [sp+2Ch] [bp-2Ch] BYREF
  int v109; // [sp+30h] [bp-28h]
  int v110; // [sp+34h] [bp-24h]

  v8 = a2;
  if ( a8 )
    *a8 = 0;
  if ( !a6 )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)a3;
      if ( (*(_DWORD *)a3 & 0x800) == 0 )
        return -1073740748;
      if ( MI_IS_PFN(v10 >> 12) )
      {
        v11 = MmPfnDatabase + 24 * (v10 >> 12);
        v12 = (unsigned __int8 *)(v11 + 15);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 | 0x80, v12) );
        __dmb(0xBu);
        if ( v13 >> 7 )
          return sub_532654(0x80000000);
        if ( *(_DWORD *)a3 == v10 )
        {
          if ( (*(_DWORD *)(v11 + 4) | 0x80000000) != a3 )
            KeBugCheckEx(26, 1041, a3);
          v8 = a2;
          v15 = 0;
          v105 = *(_DWORD *)a3;
          goto LABEL_13;
        }
        __dmb(0xBu);
        v80 = (unsigned int *)(v11 + 12);
        do
          v81 = __ldrex(v80);
        while ( __strex(v81 & 0x7FFFFFFF, v80) );
      }
    }
  }
  v105 = *(_DWORD *)a3;
  v15 = MmPfnDatabase + 24 * (*(_DWORD *)(((a3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v11 = MmPfnDatabase + 24 * (*(_DWORD *)a3 >> 12);
LABEL_13:
  v110 = a7 & 1;
  if ( (a7 & 1) != 0 && *(_BYTE *)(a7 & 0xFFFFFFFE) == 1 )
  {
    MiUpdatePfnPriority(v11, *(_DWORD *)((a7 & 0xFFFFFFFE) + 40) & 7, 0);
    v41 = 0;
LABEL_107:
    __dmb(0xBu);
    v61 = (unsigned int *)(v11 + 12);
    if ( v15 )
    {
      do
        v62 = __ldrex(v61);
      while ( __strex(v62 & 0x7FFFFFFF, v61) );
      MiUnlockProtoPoolPage(v15, 17);
      return v41;
    }
    do
      v82 = __ldrex(v61);
    while ( __strex(v82 & 0x7FFFFFFF, v61) );
    return v41;
  }
  v16 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2960);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + 1, v16) );
  if ( (*(_BYTE *)(v11 + 18) & 0x20) == 0 )
  {
    v18 = dword_640580;
    if ( (unsigned int)dword_640580 < 0x80
      && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v18 < 2) )
    {
      __dmb(0xBu);
      v89 = (unsigned int *)(v11 + 12);
      do
        v90 = __ldrex(v89);
      while ( __strex(v90 & 0x7FFFFFFF, v89) );
      if ( v15 )
        MiUnlockProtoPoolPage(v15, 17);
      return -1073741801;
    }
    if ( v8 >= dword_63389C && (MiFlags & 0x30000) == 0
      || (v19 = *(_DWORD *)(v11 + 20), (v19 & 0x8000000) == 0)
      || (*(_DWORD *)(v11 + 8) & 0x400) == 0
      || (v19 & 0x7000000) == 50331648
      || (v20 = (_WORD *)(*(_DWORD *)(v11 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v11 + 8) & 0x3FC))),
          v21 = *(_DWORD *)v20,
          (*(_DWORD *)(*(_DWORD *)v20 + 28) & 0x20) == 0)
      || (BYTE2(MiFlags) & 3u) > 1
      && ((*(unsigned __int16 *)((*(_DWORD *)(v11 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v11 + 8) & 0x3FC))) + 0x10) >> 1) & 2) == 0
      && MiCanPageMove(v11)
      || (v22 = *(_DWORD *)(*(_DWORD *)(v21 + 56) + 4)) == 0
      || (v22 & 0xFFFFFFF8) == 8
      || (*(_DWORD *)(*(_DWORD *)(v21 + 56) + 4) & 3) == 2
      || ((MiFlags & 0x100000) == 0 || (*(_DWORD *)(v21 + 52) & 0xC000000) == 0)
      && (v91 = MiLocateAddress(a2)) != 0
      && (v92 = *(_DWORD *)(v91 + 28), (v92 & 7) == 2)
      && ((v92 & 0xF8) == 8
       || (*(_DWORD *)(v91 + 40) & 0x10000000) != 0 && (v22 & 4) == 0
       || (MiFlags & 0x400) != 0 && (v20[9] & 2) != 0) )
    {
      v23 = v15;
      v24 = a2;
    }
    else
    {
      v23 = v15;
      v24 = a2;
      v41 = MiMakeImagePageOk(a2, a3, v105, a4, v11, v15);
      if ( v41 < 0 )
      {
LABEL_150:
        __dmb(0xBu);
        v72 = (unsigned int *)(v11 + 12);
        do
          v73 = __ldrex(v72);
        while ( __strex(v73 & 0x7FFFFFFF, v72) );
        if ( v23 )
        {
          MiUnlockProtoPoolPage(v23, 17);
          return v41;
        }
        return v41;
      }
    }
    if ( (*(_DWORD *)(v11 + 20) & 0x8000000) == 0 && a3 != (*(_DWORD *)(v11 + 4) | 0x80000000) )
      KeBugCheckEx(26, 34954, a3);
    v107 = 0;
    if ( MiUnlinkPageFromList(v11, 0) )
    {
      v25 = v15;
      v26 = a7;
      v27 = MiMigratePfn(a4, v24, v11, v15, a7, &v107);
      v11 = v27;
      if ( v27 )
      {
        v28 = *(_BYTE *)(v27 + 18);
        *(_DWORD *)(v27 + 12) = *(_DWORD *)(v27 + 12) & 0xC0000000 | 1;
        ++*(_WORD *)(v27 + 16);
        v29 = v107;
        *(_BYTE *)(v27 + 18) = v28 & 0xF8 | 6;
        v109 = v29;
        goto LABEL_31;
      }
      v74 = v107;
      if ( v107 )
      {
        if ( *(int *)(v107 + 100) > 1 )
          KeSetEvent(v107 + 32, 0, 0);
        MiFreeInPageSupportBlock(v74);
        return -1073740748;
      }
    }
    else
    {
      MiDiscardTransitionPte(v11);
      __dmb(0xBu);
      v93 = (unsigned int *)(v11 + 12);
      do
        v94 = __ldrex(v93);
      while ( __strex(v94 & 0x7FFFFFFF, v93) );
      if ( v23 )
        MiUnlockProtoPoolPage(v23, 17);
    }
    return -1073740748;
  }
  v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( (*(_BYTE *)(v65 + 0x3C8) & 4) != 0 )
  {
    v41 = -1073741663;
    goto LABEL_107;
  }
  if ( !a8 )
  {
    v41 = -1073740748;
    goto LABEL_107;
  }
  if ( (*(_BYTE *)(v11 + 18) & 8) != 0 )
  {
    v41 = -1073741801;
    goto LABEL_107;
  }
  v66 = *(_DWORD *)v11;
  v67 = (*(_BYTE *)(*(_DWORD *)v11 + 97) & 0x40) != 0
     && ((*(_DWORD *)(*(_DWORD *)(v65 + 336) + 192) & 0x100000) == 0 && ((*(_DWORD *)(v65 + 960) >> 9) & 7u) >= 2
      || v65 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *(_DWORD *)(v65 + 1000))
     || v65 == *(_DWORD *)(v66 + 72)
     || (*(_DWORD *)(v65 + 76) & 0x8000) != 0
     || *(_DWORD *)(*(_DWORD *)(v65 + 336) + 792) && (*(_DWORD *)(v66 + 128) || (*(_BYTE *)(v66 + 97) & 4) != 0);
  if ( (*(_DWORD *)(v11 + 20) & 0x8000000) == 0 )
  {
    if ( !*(_BYTE *)(v65 + 974) && (*(_BYTE *)(v66 + 97) & 4) == 0 && !v67 || (*(_BYTE *)(v66 + 97) & 0x10) != 0 )
    {
      v23 = v15;
      goto LABEL_142;
    }
    __dmb(0xBu);
    v85 = (unsigned int *)(v11 + 12);
    do
      v86 = __ldrex(v85);
    while ( __strex(v86 & 0x7FFFFFFF, v85) );
    return MiResolvePageFileFault(a2, a3, a4, a6, v15, a7, a8);
  }
  if ( (*(_DWORD *)(v11 + 8) & 0x400) != 0 )
  {
    if ( (*(_DWORD *)(v65 + 308) || (*(_DWORD *)(v65 + 76) & 0x400) != 0 || v67 || a5)
      && (*(_BYTE *)(v66 + 97) & 0x10) == 0 )
    {
      __dmb(0xBu);
      v75 = (unsigned int *)(v11 + 12);
      do
        v76 = __ldrex(v75);
      while ( __strex(v76 & 0x7FFFFFFF, v75) );
      return MiResolveMappedFileFault(a1, a2, a3, a4, 17, v15, 0, a8);
    }
    goto LABEL_141;
  }
  if ( (*(_BYTE *)(v65 + 974) || (*(_BYTE *)(v66 + 97) & 4) != 0 || v67) && (*(_BYTE *)(v66 + 97) & 0x10) == 0 )
  {
    __dmb(0xBu);
    v83 = (unsigned int *)(v11 + 12);
    do
      v84 = __ldrex(v83);
    while ( __strex(v84 & 0x7FFFFFFF, v83) );
    return MiResolvePageFileFault(a2, a3, a4, a6, v15, a7, a8);
  }
LABEL_141:
  v23 = v15;
  MiObtainProtoReference(v15, 1);
LABEL_142:
  v108 = 0;
  v41 = MiWaitForCollidedFaultComplete(v11, v23, a2, a4, a5, 2, &v108);
  if ( v108 == 1 )
    return v41;
  if ( v23 )
  {
    v68 = (unsigned __int8 *)(v23 + 15);
    do
      v69 = __ldrex(v68);
    while ( __strex(v69 | 0x80, v68) );
    __dmb(0xBu);
    if ( v69 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v87 = *(_DWORD *)(v23 + 12);
          __dmb(0xBu);
        }
        while ( (v87 & 0x80000000) != 0 );
        do
          v88 = __ldrex(v68);
        while ( __strex(v88 | 0x80, v68) );
        __dmb(0xBu);
      }
      while ( v88 >> 7 );
    }
    MiRemoveLockedPageChargeAndDecRef(v23);
    __dmb(0xBu);
    v70 = (unsigned int *)(v23 + 12);
    do
      v71 = __ldrex(v70);
    while ( __strex(v71 & 0x7FFFFFFF, v70) );
  }
  if ( v41 )
    goto LABEL_150;
  MiAddLockedPageCharge(v11, 3);
  v77 = *(_BYTE *)(v11 + 18);
  *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | ((*(_DWORD *)(v11 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
  *(_BYTE *)(v11 + 18) = v77 & 0xF8 | 6;
  MiRemoveLockedPageChargeAndDecRef(v11);
  v25 = v15;
  v26 = a7;
  v109 = 0;
LABEL_31:
  if ( v110 && *(_BYTE *)(v26 & 0xFFFFFFFE) == 4 )
  {
    v105 = v105 & 0xFFFFFC1F | 0x80;
    *(_DWORD *)a3 = *(_DWORD *)a3 & 0xFFFFFC1F | 0x80;
  }
  v30 = (MmProtectToPteMask[(*(_DWORD *)a3 >> 5) & 0x1F] ^ *(_DWORD *)a3) & 0xFED ^ *(_DWORD *)a3 | 0x12;
  v108 = 0x3FFFFF;
  v31 = dword_63389C;
  if ( a3 > (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 || a3 < 0xC0000000 )
  {
    if ( a3 >= 0xC0300000 && a3 <= dword_633898
      || a3 + 0x40000000 <= v108
      && a3 << 10 >= dword_63389C
      && ((v60 = *((unsigned __int8 *)&MiState[2423]
                 + ((int)(((a3 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v60 == 1)
       || v60 == 11) )
    {
      v32 = 2048;
    }
    else
    {
      v32 = 0;
    }
  }
  else
  {
    v32 = 2080;
  }
  v33 = v32 | v30;
  if ( ((v105 >> 5) & 0x1F) == 24 )
  {
    v95 = *(unsigned __int8 *)(v11 + 18) >> 6;
    if ( v95 != 1 )
    {
      if ( v95 )
      {
        if ( v95 == 2 )
          v33 |= 0xCu;
      }
      else
      {
        v33 = v33 & 0xFFFFFFF3 | 4;
      }
    }
  }
  v34 = *(_DWORD *)(v11 + 8);
  v35 = 0;
  if ( (v34 & 0x400) == 0 && (v34 & 0x10) != 0 && ((v34 >> 2) & 1) == dword_63F99C )
  {
    v35 = MiCaptureDirtyBitToPfn(v11);
    v31 = dword_63389C;
  }
  if ( (v33 & 0x80) != 0 )
  {
    if ( (*(_BYTE *)(v11 + 18) & 0x10) != 0 )
    {
      if ( a1 || a2 >= v31 )
        v33 &= 0xFFFFFDFF;
    }
    else if ( a1 && (*(_DWORD *)(v11 + 20) & 0x8000000) == 0 )
    {
      v35 = MiCaptureDirtyBitToPfn(v11);
      v33 &= 0xFFFFFDFF;
    }
  }
  if ( (*(_DWORD *)(v11 + 20) & 0x8000000) != 0 )
  {
    if ( ((v105 >> 5) & 0x1F) == 24 )
      v33 |= 1u;
    if ( a3 + 0x40000000 <= v108 )
    {
      v96 = *(_DWORD *)a3;
      v97 = 0;
      __dmb(0xBu);
      *(_DWORD *)a3 = v33;
      if ( (v96 & 2) == 0 )
        v97 = 1;
      if ( a3 + 1070596096 <= 0xFFF )
      {
        v98 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v98, v98 + 4 * (a3 & 0xFFF), v33);
      }
      if ( v97 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    else
    {
      *(_DWORD *)a3 = v33;
    }
  }
  __dmb(0xBu);
  v36 = (unsigned int *)(v11 + 12);
  do
    v37 = __ldrex(v36);
  while ( __strex(v37 & 0x7FFFFFFF, v36) );
  if ( v25 )
  {
    v42 = (unsigned __int8 *)(v25 + 15);
    do
      v43 = __ldrex(v42);
    while ( __strex(v43 | 0x80, v42) );
    __dmb(0xBu);
    if ( v43 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v78 = *(_DWORD *)(v25 + 12);
          __dmb(0xBu);
        }
        while ( (v78 & 0x80000000) != 0 );
        do
          v79 = __ldrex(v42);
        while ( __strex(v79 | 0x80, v42) );
        __dmb(0xBu);
      }
      while ( v79 >> 7 );
    }
    v44 = *(unsigned __int16 *)(v25 + 16);
    v45 = *(_BYTE *)(v25 + 18) & 0xDF;
    *(_BYTE *)(v25 + 18) = v45;
    if ( !v44 )
      KeBugCheckEx(78, 154, (v25 - MmPfnDatabase) / 24);
    v46 = *(_DWORD *)(v25 + 12);
    v47 = (unsigned __int16)(v44 - 1);
    *(_WORD *)(v25 + 16) = v47;
    v48 = v46 & 0x3FFFFFFF;
    if ( !v47 )
    {
      v49 = 1;
LABEL_67:
      v107 = v49;
      v50 = (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000;
      v51 = *(_DWORD *)(v25 + 4) | 0x80000000;
      if ( v51 > v50 || v51 < 0xC0000000 )
      {
        v52 = *(unsigned __int8 *)(v25 + 19);
        if ( ((v52 >> 5) & 1) != 0 )
        {
          *(_BYTE *)(v25 + 19) = v52 & 0xDF;
          goto LABEL_79;
        }
        v49 = v107;
      }
      if ( (*(_DWORD *)(v25 + 20) & 0x8000000) != 0 && (*(_DWORD *)(v25 + 8) & 0x400) != 0
        || v51 <= v50 && v51 >= 0xC0000000 && ((*(unsigned __int8 *)(v25 + 19) >> 5) & 1) != 0
        || v49 == 1 && (v46 & 0x40000000) != 0 )
      {
        MiReturnCommit(MiSystemPartition, 1);
      }
      v53 = (unsigned int)KeGetPcr();
      v54 = (unsigned int *)((v53 & 0xFFFFF000) + 4992);
      v55 = *(_DWORD *)((v53 & 0xFFFFF000) + 0x1380);
      if ( v55 == -1 )
        goto LABEL_266;
      if ( (unsigned int)(v55 + 1) <= 0x100 )
      {
        do
        {
          do
            v56 = __ldrex(v54);
          while ( v56 == v55 && __strex(v55 + 1, v54) );
          if ( v56 == v55 )
            goto LABEL_78;
          v55 = v56;
        }
        while ( v56 != -1 && v56 + 1 <= 0x100 );
      }
      if ( v55 <= 192 )
        goto LABEL_266;
      do
        v99 = __ldrex(v54);
      while ( v99 == v55 && __strex(0xC0u, v54) );
      if ( v99 != v55 )
LABEL_266:
        v100 = 1;
      else
        v100 = v55 - 191;
      do
        v101 = __ldrex((unsigned int *)&dword_640600);
      while ( __strex(v101 + v100, (unsigned int *)&dword_640600) );
      do
LABEL_78:
        v57 = __ldrex(&dword_634A2C[117]);
      while ( __strex(v57 + 1, &dword_634A2C[117]) );
LABEL_79:
      if ( v107 )
        MiPfnReferenceCountIsZero(v25, (v25 - MmPfnDatabase) / 24);
      goto LABEL_81;
    }
    if ( v47 == 1 )
    {
      if ( v48 || (v45 & 8) != 0 )
      {
LABEL_66:
        v49 = 0;
        goto LABEL_67;
      }
    }
    else if ( v47 == 2 && v48 && (v45 & 8) != 0 )
    {
      goto LABEL_66;
    }
LABEL_81:
    __dmb(0xBu);
    v58 = (unsigned int *)(v25 + 12);
    do
      v59 = __ldrex(v58);
    while ( __strex(v59 & 0x7FFFFFFF, v58) );
  }
  if ( v35 )
    MiReleasePageFileInfo(MiSystemPartition, v35, 1);
  v38 = v109;
  if ( v109 )
  {
    if ( *(int *)(v109 + 100) > 1 )
      KeSetEvent(v109 + 32, 0, 0);
    MiFreeInPageSupportBlock(v38);
  }
  if ( (*(_DWORD *)(v11 + 20) & 0x8000000) != 0 )
  {
    v41 = MiCompleteProtoPteFault(a4, a5, a2, v33, a1, 0, a7);
    if ( v41 < 0 )
      return v41;
    return 272;
  }
  if ( !v110 || *(_BYTE *)(a7 & 0xFFFFFFFE) != 4 )
  {
    v39 = 0;
    v40 = 0;
    if ( v110 )
    {
      if ( *(_BYTE *)(a7 & 0xFFFFFFFE) == 3 )
      {
        if ( a3 < 0xC0300000 || a3 > 0xC0300FFF )
          v33 &= 0xFFFFFFEF;
        v39 = 512;
      }
      else if ( *(_BYTE *)(a7 & 0xFFFFFFFE) == 5 )
      {
        v40 = a7 & 0xFFFFFFFE;
      }
    }
    if ( !MiAllocateWsle(a4, a3, v11, v39, v33, v40) )
    {
      MiLockAndDecrementShareCount(v11, 0);
      return -1073741801;
    }
    return 272;
  }
  if ( a3 + 0x40000000 > v108 )
  {
    *(_DWORD *)a3 = v33;
  }
  else
  {
    v63 = *(_DWORD *)a3;
    v64 = 0;
    __dmb(0xBu);
    *(_DWORD *)a3 = v33;
    if ( (v63 & 2) == 0 )
      v64 = 1;
    if ( a3 >= 0xC0300000 && a3 <= 0xC0300FFF )
    {
      v102 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v102, v102 + 4 * (a3 & 0xFFF), v33);
    }
    if ( v64 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  *(_DWORD *)v11 = 0;
  return 272;
}
