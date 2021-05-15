// MiSetProtectionOnSection 
 
int __fastcall MiSetProtectionOnSection(int a1, _DWORD *a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, _DWORD *a7, _DWORD *a8)
{
  int v10; // r4
  unsigned int v11; // r7
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r5
  int v16; // r0
  int v17; // r10
  _DWORD *v18; // r8
  unsigned int *v19; // r6
  int v20; // r4
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int v23; // r0
  int v24; // r10
  int v25; // r3
  int v26; // r4
  int v27; // r4
  unsigned int v28; // r6
  unsigned int v29; // r9
  unsigned int v30; // r10
  int v31; // r8
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned int v34; // r4
  _DWORD *v35; // r9
  int v36; // r0
  int v37; // r6
  unsigned int *v38; // r0
  unsigned int v39; // r1
  unsigned int v40; // r10
  int v41; // r0
  int v42; // r1
  int v43; // r8
  int v44; // r2
  char v45; // r0
  int v46; // r2
  int v47; // r2
  unsigned int *v48; // r0
  int v49; // r4
  unsigned int *v50; // lr
  unsigned __int8 *v51; // r3
  unsigned int v52; // r1
  unsigned int v53; // r0
  int v54; // r0
  int v55; // r2
  _DWORD *v56; // r4
  int v57; // r0
  unsigned int v58; // r8
  int v59; // r10
  _DWORD *v60; // r6
  unsigned int *v61; // r2
  unsigned int v62; // r0
  unsigned int v63; // r3
  int v64; // r0
  unsigned int *v65; // r2
  unsigned int v66; // r0
  int v67; // r0
  int v68; // r8
  unsigned int v69; // r8
  _DWORD *v70; // r8
  int v71; // r1
  char v72; // r0
  unsigned int v73; // r1
  int v74; // r3
  int v75; // r4
  unsigned int v76; // r1
  int v77; // r6
  unsigned int v78; // r1
  unsigned __int8 *v79; // r1
  int v80; // r3
  unsigned int v81; // r2
  char v82; // r1
  int v83; // r0
  unsigned int *v84; // r2
  unsigned int v85; // r0
  int v86; // r0
  int v87; // r2
  int v88; // r3
  unsigned int v91; // [sp+10h] [bp-198h]
  int v92; // [sp+14h] [bp-194h]
  int v93; // [sp+18h] [bp-190h]
  int v94; // [sp+1Ch] [bp-18Ch]
  unsigned int v95; // [sp+20h] [bp-188h]
  unsigned int *v96; // [sp+28h] [bp-180h]
  unsigned int v97; // [sp+2Ch] [bp-17Ch]
  int v98; // [sp+30h] [bp-178h]
  int v99; // [sp+38h] [bp-170h]
  __int16 v100; // [sp+3Ch] [bp-16Ch]
  int v101; // [sp+40h] [bp-168h]
  int v102; // [sp+44h] [bp-164h]
  int v103; // [sp+4Ch] [bp-15Ch]
  int v104; // [sp+50h] [bp-158h] BYREF
  unsigned int v105; // [sp+54h] [bp-154h]
  int v106; // [sp+58h] [bp-150h]
  int v107; // [sp+5Ch] [bp-14Ch]
  unsigned int *v108; // [sp+60h] [bp-148h] BYREF
  _DWORD *v109; // [sp+64h] [bp-144h]
  int v110; // [sp+68h] [bp-140h] BYREF
  char v111; // [sp+6Ch] [bp-13Ch]
  char v112; // [sp+6Dh] [bp-13Bh]
  int v113; // [sp+70h] [bp-138h]
  int v114; // [sp+74h] [bp-134h]
  int v115; // [sp+78h] [bp-130h]
  int v116; // [sp+7Ch] [bp-12Ch]
  unsigned int v117[42]; // [sp+100h] [bp-A8h] BYREF

  v10 = a2[7] & 7;
  v109 = a8;
  if ( v10 != 2 && (a2[10] & 0x8000000) == 0 )
  {
    v11 = a5;
LABEL_81:
    v100 = v11;
    goto LABEL_5;
  }
  v11 = a5;
  v100 = a5;
  if ( (a5 & 4) != 0 )
  {
    v11 = a5 & 0xFFFFFFF3 | 8;
    v100 = a5 & 0xFFF3 | 8;
  }
  if ( (v11 & 0x40) != 0 )
  {
    v11 = v11 & 0xFFFFFF3F | 0x80;
    goto LABEL_81;
  }
LABEL_5:
  v12 = MiMakeProtectionMask(v11);
  v106 = v12;
  if ( v12 == -1 )
    return -1073741755;
  v98 = 0;
  v99 = 0;
  v101 = v12;
  v102 = 0;
  v111 = 0;
  v113 = 33;
  v114 = 0;
  v110 = 1;
  v112 = 0;
  v115 = 0;
  v116 = 0;
  v13 = 0;
  if ( (v12 & 5) == 5 )
  {
    v98 = 1;
    v101 = v12 & 0xFFFFFFFE;
  }
  v14 = ((a3 >> 10) & 0x3FFFFC) - 0x40000000;
  v97 = ((a4 >> 10) & 0x3FFFFC) - 0x40000000;
  v105 = v14;
  v103 = __mrc(15, 0, 13, 0, 3);
  v95 = 0;
  v117[0] = 0;
  v107 = 0;
  v93 = 0;
  if ( MEMORY[0xC0402140] )
    return sub_5426EC(a2);
  if ( v98 )
  {
    v16 = MiCountSharedPages(a2, ((a3 >> 10) & 0x3FFFFC) - 0x40000000, ((a4 >> 10) & 0x3FFFFC) - 0x40000000);
    v13 = v16;
    if ( a6 == 1 )
    {
      v99 = ((int)(v97 - v14) >> 2) - v16 + 1;
      if ( ((int)(v97 - v14) >> 2) - v16 != -1
        && !MiChargeCommit((int)MiSystemPartition, ((int)(v97 - v14) >> 2) - v16 + 1, 0) )
      {
        return -1073741523;
      }
      v13 = 0;
    }
    else if ( v16 )
    {
      v17 = MiChargeFullProcessCommitment(a1, v16);
      if ( v17 < 0 )
        return v17;
    }
  }
  if ( MiVadPureReserve((int)a2) == 1 )
  {
    v107 = 1;
    LOCK_PAGE_TABLE_COMMITMENT(v103 & 0xFFFFFFC0, a1);
    v76 = a3;
    v18 = a2;
    v77 = MiCommitPageTablesForVad(a2, v76, a4);
    if ( v77 < 0 )
    {
      UNLOCK_PAGE_TABLE_COMMITMENT(v103 & 0xFFFFFFC0, a1);
      if ( v99 )
      {
        MiReturnCommit(MiSystemPartition, v13);
      }
      else if ( v13 )
      {
        MiReturnFullProcessCommitment(a1, v13);
      }
      return v77;
    }
  }
  else
  {
    v18 = a2;
  }
  if ( v13 )
    v18[8] = v18[8] & 0x80000000 | (v18[8] + v13) & 0x7FFFFFFF;
  v19 = (unsigned int *)(a1 + 492);
  v96 = (unsigned int *)(a1 + 492);
  v20 = KfRaiseIrql(2);
  v91 = v20;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v19);
  }
  else
  {
    v21 = (unsigned __int8 *)(a1 + 495);
    do
      v22 = __ldrex(v21);
    while ( __strex(v22 | 0x80, v21) );
    __dmb(0xBu);
    if ( v22 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v19);
    while ( 1 )
    {
      v23 = *v19;
      if ( (*v19 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v23 & 0x40000000) == 0 )
      {
        do
          v73 = __ldrex(v19);
        while ( v73 == v23 && __strex(v23 | 0x40000000, v19) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( MiGetNextPageTable(v14, v97, 0, v20, 1, &v104) == v14 && *(_DWORD *)v14 )
  {
    *a7 = MmProtectToValue[MiGetPageProtection((int)v18, v14, v20, 1)];
    MiMakeSystemAddressValid(v14, 0);
  }
  else
  {
    v47 = v18[7];
    if ( (v47 & 7) == 2 && (v47 & 0xF8) == 56 )
    {
      MiUnlockWorkingSetExclusive(a1 + 492, v20);
      v48 = (unsigned int *)MiGetProtoPteAddress(v18, (v14 >> 2) & 0xFFFFF, 1, &v108);
      *a7 = MmProtectToValue[MiCaptureProtectionFromProto(v48)];
      v49 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1 + 492);
      }
      else
      {
        v50 = (unsigned int *)(a1 + 492);
        v51 = (unsigned __int8 *)(a1 + 495);
        do
          v52 = __ldrex(v51);
        while ( __strex(v52 | 0x80, v51) );
        __dmb(0xBu);
        if ( v52 >> 7 )
        {
          ExpWaitForSpinLockExclusiveAndAcquire(v96);
          v50 = (unsigned int *)(a1 + 492);
        }
        while ( 1 )
        {
          v53 = *v50;
          if ( (*v50 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v53 & 0x40000000) == 0 )
          {
            do
              v78 = __ldrex(v50);
            while ( v78 == v53 && __strex(v53 | 0x40000000, v50) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        LOWORD(v11) = v100;
      }
      v24 = v49;
      v91 = v49;
      MiMakeSystemAddressValid(v14, 0);
      goto LABEL_28;
    }
    *a7 = MmProtectToValue[(unsigned __int8)v47 >> 3];
  }
  v24 = v20;
LABEL_28:
  v25 = 1;
  v26 = 0;
  v92 = 1;
  v94 = 0;
  if ( v14 <= v97 )
  {
    v104 = 134217721;
    while ( 1 )
    {
      v27 = v14 & 0xFFF;
      if ( v25 == 1 || (v14 & 0xFFF) == 0 )
      {
        v92 = 0;
        MiFlushTbList(&v110);
        MiMakeSystemAddressValid(v14, 0);
      }
      v28 = *(_DWORD *)v14;
      v29 = v14 << 10;
      if ( (*(_DWORD *)v14 & 2) == 0 )
        break;
      v30 = v28 >> 12;
      v31 = MmPfnDatabase + 24 * (v28 >> 12);
      if ( (*(_DWORD *)(v31 + 20) & 0x8000000) == 0
        || (v54 = MiGetProtoPteAddress(a2, v29 >> 12, 1, &v108), v55 = *(_DWORD *)(v31 + 4), (v55 | 0x80000000) == v54) )
      {
        if ( (v11 & 0x101) != 0 || a6 == 1 && (*(_DWORD *)(v31 + 20) & 0x8000000) == 0 )
        {
          v58 = v97;
          if ( ((v97 ^ v14) & 0xFFFFF000) != 0 )
            v58 = (v14 & 0xFFFFF000) + 4092;
          v59 = 0;
          v60 = (_DWORD *)v14;
          if ( v14 <= v58 )
          {
            while ( 1 )
            {
              if ( (*v60 & 2) == 0
                || (v61 = (unsigned int *)(MmPfnDatabase + 24 * (*v60 >> 12)), (v11 & 0x101) == 0)
                && (a6 != 1 || (v61[5] & 0x8000000) != 0) )
              {
LABEL_103:
                v14 = v105;
                LOWORD(v11) = v100;
                goto LABEL_104;
              }
              v62 = MiLocateWsle(v29, (int)v96, *v61);
              if ( v62 < MEMORY[0xC0402004] )
                break;
              v117[v95 + 1] = v62;
              v95 = ++v117[0];
              v63 = v117[0];
              if ( v117[0] == 32 )
                goto LABEL_185;
LABEL_102:
              ++v60;
              v29 += 4096;
              if ( (unsigned int)v60 > v58 )
                goto LABEL_103;
            }
            v59 = 1;
            *v109 = 1;
            v63 = v95;
LABEL_185:
            if ( v63 )
            {
              MiFreeWsleList((int)v96, v117, 0);
              v95 = 0;
              v117[0] = 0;
            }
            if ( v59 == 1 )
            {
              MiUnlockVa((int)v96, v29);
              v59 = 0;
            }
            goto LABEL_102;
          }
LABEL_104:
          if ( v95 )
          {
            MiFreeWsleList((int)v96, v117, 0);
            v95 = 0;
            v117[0] = 0;
          }
          goto LABEL_47;
        }
        if ( (*(_DWORD *)(v31 + 20) & 0x8000000) != 0 )
        {
          if ( !v98 && (v28 & 0x100) != 0 )
            ++v94;
          v56 = (_DWORD *)(MEMORY[0xC0402024] * MiLocateWsle(v14 << 10, (int)v96, *(_DWORD *)v31) - 1069537344);
          v57 = MiGetPfnProtection(v31, v56);
          v35 = a2;
          v37 = MiSanitizePfnProtection(a2, v57, v106);
          *v56 ^= (*v56 ^ (16 * v37)) & 0x1F0;
        }
        else
        {
          v32 = (unsigned __int8 *)(v31 + 15);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 | 0x80, v32) );
          __dmb(0xBu);
          if ( v33 >> 7 )
          {
            v79 = (unsigned __int8 *)(v31 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v80 = *(_DWORD *)(v31 + 12);
                __dmb(0xBu);
              }
              while ( (v80 & 0x80000000) != 0 );
              do
                v81 = __ldrex(v79);
              while ( __strex(v81 | 0x80, v79) );
              __dmb(0xBu);
            }
            while ( v81 >> 7 );
          }
          v34 = *(_DWORD *)(v31 + 8);
          v35 = a2;
          v36 = MiSanitizePfnProtection(a2, (v34 >> 5) & 0x1F, v101);
          *(_DWORD *)(v31 + 8) = (v34 ^ (32 * v36)) & 0x3E0 ^ v34;
          v37 = v36;
          __dmb(0xBu);
          v38 = (unsigned int *)(v31 + 12);
          do
            v39 = __ldrex(v38);
          while ( __strex(v39 & 0x7FFFFFFF, v38) );
        }
        if ( (v37 & 2) != 0 && (*(_BYTE *)(v31 + 23) & 7) != 3 && (BYTE2(MiFlags) & 3u) > 1 && (MiFlags & 0x40000) == 0 )
        {
          v82 = 2;
          if ( (v37 & 4) != 0 && (v37 & 5) != 5 )
            v82 = 3;
          MiMarkPfnVerified(v31, v82);
        }
        MiRevertValidPte(v35, v14, v37, v30, &v110);
LABEL_45:
        v14 += 4;
LABEL_46:
        v105 = v14;
LABEL_47:
        v40 = v91;
        goto LABEL_48;
      }
      v75 = 0;
      if ( (v55 & 0x80000000) != 0 )
      {
        v75 = MiLocateCloneAddress(a1);
        if ( MEMORY[0xC0402140] <= *(_QWORD *)(v75 + 40) )
          v75 = 0;
      }
      MiFlushTbList(&v110);
      v40 = v91;
      if ( MiCopyOnWriteEx(v14 << 10, v14, -1, v91, 0) )
      {
        if ( v75 )
          --v93;
      }
      else
      {
        v92 = 1;
      }
LABEL_48:
      v18 = a2;
      v25 = v92;
      if ( v14 > v97 )
      {
        v26 = v94;
        goto LABEL_50;
      }
      v24 = v91;
    }
    if ( (v28 & 0x400) == 0 )
    {
      if ( (v28 & 0x800) != 0 )
      {
        if ( a6 != 1 )
        {
          if ( !MiSetProtectionOnTransitionPte((int)v18, v14, v101, 1) )
            goto LABEL_45;
          goto LABEL_47;
        }
        v64 = MiDeleteTransitionPte((_DWORD *)v14, 1, 534769440);
        if ( v64 == 3 )
        {
          ++v102;
        }
        else if ( v64 == 1 )
        {
          goto LABEL_47;
        }
        v65 = (unsigned int *)(a1 + 276);
        do
          v66 = __ldrex(v65);
        while ( __strex(v66 - 1, v65) );
      }
      else
      {
        v43 = 0;
        if ( a6 != 1 )
        {
          if ( v28 )
          {
            v67 = MiSanitizePfnProtection(a2, (v28 >> 5) & 0x1F, v101);
            v46 = ((unsigned __int16)v28 ^ (unsigned __int16)(32 * v67)) & 0x3E0 ^ v28;
            v101 = v67;
            if ( v14 + 0x40000000 <= 0x3FFFFF )
            {
              v68 = 0;
              __dmb(0xBu);
              *(_DWORD *)v14 = v46;
              if ( (v28 & 2) == 0 && (v46 & 2) != 0 )
                v68 = 1;
              if ( v14 >= 0xC0300000 && v14 <= 0xC0300FFF )
              {
                v86 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v86, (_DWORD *)(v86 + 4 * v27), v46);
              }
              if ( v68 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
              goto LABEL_45;
            }
            goto LABEL_155;
          }
          goto LABEL_65;
        }
        if ( !v28 )
        {
LABEL_65:
          MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((v29 >> 22) - 534769440)), 1u);
          if ( !v98 && (v43 == 1 || !MiPteNeedsCommitCharge(a2, v14, v44, 0)) )
            ++v94;
          v45 = MiSanitizePfnProtection(0, (*(unsigned __int16 *)(a2[11] + 16) >> 1) & 0x1F, v106);
          v46 = 32 * (v45 & 0x1F | (32 * v104));
          if ( v14 + 0x40000000 <= 0x3FFFFF )
          {
            __dmb(0xBu);
            *(_DWORD *)v14 = v46;
            if ( v14 < 0xC0300000 || v14 > 0xC0300FFF )
              goto LABEL_45;
            goto LABEL_190;
          }
          goto LABEL_155;
        }
        MiReleasePageFileSpace((int)MiSystemPartition, *(_DWORD *)v14, 1, 1);
        if ( (v28 & 0x10) != 0 )
        {
          v84 = (unsigned int *)(a1 + 276);
          do
            v85 = __ldrex(v84);
          while ( __strex(v85 - 1, v84) );
        }
      }
      MI_DECREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((v29 >> 22) - 534769440)), 1);
      v43 = 1;
      goto LABEL_65;
    }
    v69 = v28 >> 13;
    if ( v28 >> 13 != 0x7FFFF
      && (v28 & 0x1FC | (v28 >> 2) & 0x3FFFFE00) - 0x40000000 != MiGetProtoPteAddress(a2, v29 >> 12, 1, &v108) )
    {
      MiFlushTbList(&v110);
      v92 = 1;
      v14 = (unsigned int)MiMakeProtoLeafValid((_DWORD *)v14, 1, v24, v74);
      goto LABEL_46;
    }
    if ( !v98 )
    {
      if ( v69 != 0x7FFFF )
        goto LABEL_153;
      if ( (v28 & 0xA0) == 160 )
        ++v94;
    }
    if ( v69 == 0x7FFFF )
    {
      v70 = a2;
      v71 = (v28 >> 5) & 0x1F;
      goto LABEL_137;
    }
LABEL_153:
    v70 = a2;
    v71 = (*(unsigned __int16 *)(a2[11] + 16) >> 1) & 0x1F;
LABEL_137:
    v72 = MiSanitizePfnProtection(v70, v71, v106);
    v46 = 32 * (v72 & 0x1F | (32 * v104));
    if ( v14 + 0x40000000 <= 0x3FFFFF )
    {
      __dmb(0xBu);
      *(_DWORD *)v14 = v46;
      if ( v14 < 0xC0300000 || v14 > 0xC0300FFF )
        goto LABEL_45;
LABEL_190:
      v83 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v83, (_DWORD *)(v83 + 4 * v27), v46);
      goto LABEL_45;
    }
LABEL_155:
    *(_DWORD *)v14 = v46;
    goto LABEL_45;
  }
  v40 = v91;
LABEL_50:
  MiFlushTbList(&v110);
  MiUnlockWorkingSetExclusive(v96, v40);
  if ( v107 == 1 )
    UNLOCK_PAGE_TABLE_COMMITMENT(v103 & 0xFFFFFFC0, a1);
  v41 = v102;
  v42 = v99;
  if ( v102 && v98 )
  {
    v42 = v99 - v102;
    v41 = 0;
    v102 = 0;
  }
  if ( v42 )
  {
    MiReturnCommit(MiSystemPartition, v42);
    v41 = v102;
  }
  if ( v26 )
  {
    v18[8] = v18[8] & 0x80000000 | (v18[8] - v26) & 0x7FFFFFFF;
    MiReturnCommit(MiSystemPartition, v26 - v41);
    MiReturnFullProcessCharges(a1, v26, v87, v88);
  }
  if ( v93 )
    MiReturnFullProcessCommitment(a1, v93);
  return 0;
}
