// MiZeroFault 
 
int __fastcall MiZeroFault(char a1, unsigned int a2, int a3, unsigned int a4, _BYTE *a5, int *a6, int *a7, int *a8)
{
  char v8; // r7
  unsigned int v9; // r8
  unsigned int v10; // lr
  int v12; // r0
  int v13; // r4
  int v14; // r1
  unsigned int v15; // r5
  int v16; // r2
  int v17; // r1
  int v18; // r9
  unsigned int v19; // r2
  unsigned int v20; // r5
  unsigned int v21; // r2
  unsigned int v22; // r1
  int v23; // r5
  unsigned int v24; // r6
  unsigned int v25; // r0
  unsigned int v26; // r3
  int v27; // r3
  unsigned int v28; // r2
  int v29; // r1
  _WORD *v30; // r1
  unsigned int v31; // r2
  char *v32; // r1
  int *v33; // t1
  int v34; // r3
  int v35; // r2
  int v36; // r3
  unsigned int v37; // r2
  unsigned int v38; // r1
  unsigned int v40; // r3
  int v41; // r3
  int v42; // r7
  int v43; // r5
  unsigned int v44; // r0
  int v45; // r2
  _DWORD *v46; // r1
  _DWORD *v48; // r5
  unsigned int v49; // r6
  unsigned int v50; // r9
  _WORD *v51; // r1
  unsigned int *v52; // r1
  unsigned int v53; // r0
  int v54; // lr
  int v55; // r1
  int v56; // r0
  unsigned int v57; // r10
  int v58; // r9
  unsigned int v59; // r4
  int v60; // r7
  int v61; // r6
  int v62; // r2
  BOOL v63; // r8
  unsigned int v64; // r4
  int *v65; // r0
  _DWORD *v66; // r6
  int v67; // r7
  int v68; // r2
  unsigned int v69; // r3
  int v70; // r0
  unsigned int *v71; // r2
  unsigned int v72; // r0
  int v73; // r9
  unsigned int v74; // r2
  int *v75; // r7
  char v76; // lr
  int v77; // t1
  unsigned int v78; // r3
  unsigned int v79; // r5
  int v80; // r0
  int v81; // r0
  int v82; // r0
  _DWORD *v83; // r0
  int v84; // r2
  unsigned int v85; // r5
  int v86; // r0
  unsigned int *v87; // r2
  unsigned int v88; // r1
  int v89; // r0
  int v90; // r2
  __int64 v91; // kr08_8
  int v92; // r3
  unsigned int v93; // r8
  _DWORD *v94; // r0
  unsigned int v95; // r1
  int v96; // r7
  unsigned int v97; // r3
  unsigned int v98; // r10
  int v99; // r9
  unsigned int v100; // r1
  int v101; // t1
  int v102; // r8
  _QWORD *v103; // r2
  unsigned int v104; // r2
  int v105; // r0
  unsigned int v106; // r9
  int v107; // [sp+8h] [bp-58h]
  int v109; // [sp+Ch] [bp-54h]
  int v110; // [sp+10h] [bp-50h]
  int v111; // [sp+14h] [bp-4Ch]
  unsigned int v112; // [sp+18h] [bp-48h] BYREF
  unsigned int v113; // [sp+1Ch] [bp-44h] BYREF
  int v114; // [sp+20h] [bp-40h]
  unsigned int v115; // [sp+24h] [bp-3Ch]
  int v116; // [sp+28h] [bp-38h]
  unsigned int v117; // [sp+2Ch] [bp-34h]
  unsigned int v118; // [sp+30h] [bp-30h]
  int v119; // [sp+34h] [bp-2Ch]
  int v120[2]; // [sp+38h] [bp-28h] BYREF
  char v121; // [sp+40h] [bp-20h] BYREF

  v117 = a4;
  v8 = a3;
  v9 = 0;
  *a5 = 1;
  v10 = a2;
  v114 = 0;
  if ( (a3 & 1) != 0 && *(_BYTE *)(a3 & 0xFFFFFFFE) == 2 )
  {
    v9 = 1;
    v114 = 1;
  }
  else if ( (a3 & 1) != 0 )
  {
    if ( *(_BYTE *)(a3 & 0xFFFFFFFE) != 1 )
      return sub_533E50();
    v9 = 2;
    v114 = 2;
  }
  if ( (v9 & 0xB) != 0 )
    v110 = a3 & 0xFFFFFFFE;
  else
    v110 = 0;
  v118 = 4194300;
  v112 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
  v115 = 0x3FFFFF;
  if ( a2 >= dword_63389C )
  {
    if ( (v9 & 2) != 0 )
      return 0;
    if ( a3 && a2 + 0x40000000 <= 0x3FFFFF )
      KeBugCheckEx(80, a2, a1);
  }
  v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v13 = 0;
  v111 = v12;
  if ( a2 <= MmHighestUserAddress )
  {
    if ( (a2 & 0xFFFFF000) == 2147352576
      && (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 736) & 1) == 0 )
    {
      v107 = 1;
      v18 = dword_6337D8;
      v20 = 1;
      goto LABEL_27;
    }
    v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v13 = *(_DWORD *)(v14 + 640);
    if ( v13 )
    {
      v15 = v10 >> 12;
      if ( v10 >> 12 >= *(_DWORD *)(v13 + 12) && v15 <= *(_DWORD *)(v13 + 16) )
      {
LABEL_11:
        if ( (v10 & 0xFFFFF000) == 2147352576
          && (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 736) & 1) == 0 )
        {
          v18 = dword_6337D8;
          v107 = 1;
          v20 = 1;
          goto LABEL_26;
        }
        if ( (*(_DWORD *)(v13 + 28) & 7) == 2 && (*(_DWORD *)(v13 + 40) & 0x20000000) != 0 )
        {
          v83 = MiLocateVadEvent(v13, 32);
          if ( v83 )
          {
            v10 = a2;
            if ( v83[2] != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
            {
              v107 = 24;
              v18 = 0;
              v20 = 24;
              goto LABEL_26;
            }
          }
          else
          {
            v10 = a2;
          }
        }
        v16 = *(_DWORD *)(v13 + 28);
        if ( v16 < 0 )
        {
          v107 = 24;
          v18 = 0;
          v20 = 24;
        }
        else
        {
          v17 = *(_DWORD *)(v13 + 28) & 7;
          if ( v17 == 1 )
          {
            v107 = 24;
            v18 = 0;
            v20 = 24;
          }
          else if ( (v16 & 0x8000) != 0 )
          {
            if ( v17 == 3 || v17 == 5 || (*(_DWORD *)(v13 + 32) & 0x80000000) == 0 )
              v73 = 24;
            else
              v73 = (unsigned __int8)v16 >> 3;
            v107 = v73;
            v18 = 0;
            v20 = v107;
          }
          else if ( (*(_BYTE *)(v13 + 43) & 1) != 0 )
          {
            v107 = 24;
            v18 = 0;
            v20 = 24;
          }
          else
          {
            v107 = (unsigned __int8)v16 >> 3;
            if ( v107 == 7 && v17 == 2 )
              v107 = 256;
            v18 = MiGetProtoPteAddress(v13, v15, 0, v120);
            if ( !v18 )
              v107 = 24;
            v19 = *(_DWORD *)(v13 + 68);
            if ( (v19 & 0x80000000) != 0 && v15 - *(_DWORD *)(v13 + 12) > (unsigned int)((*(_QWORD *)v19 - 1i64) >> 12) )
            {
              v20 = 24;
              v107 = 24;
            }
            else
            {
              v20 = v107;
            }
            v10 = a2;
          }
        }
LABEL_26:
        if ( v20 != 24 )
        {
LABEL_27:
          v12 = v111;
          goto LABEL_28;
        }
LABEL_77:
        MiCheckBadSystemProcessAccess(__PAIR64__(v13, v10), a1);
        if ( (v9 & 2) != 0 && v13 )
          MiPrefetchJumpVad(v110, v13, a2);
        return -1073741819;
      }
      v13 = *(_DWORD *)(v14 + 636);
      while ( v13 )
      {
        if ( v15 > *(_DWORD *)(v13 + 16) )
        {
          v41 = 1;
        }
        else if ( v15 >= *(_DWORD *)(v13 + 12) )
        {
          v41 = 0;
        }
        else
        {
          v41 = -1;
        }
        if ( v41 < 0 )
        {
          v13 = *(_DWORD *)v13;
        }
        else
        {
          if ( v41 <= 0 )
          {
            *(_DWORD *)(v14 + 640) = v13;
            goto LABEL_11;
          }
          v13 = *(_DWORD *)(v13 + 4);
        }
      }
    }
    v13 = 0;
    goto LABEL_77;
  }
  if ( a2 + 0x40000000 > 0x3FFFFF )
    goto LABEL_77;
  v107 = 4;
  v18 = 0;
  v20 = 4;
LABEL_28:
  v21 = v20 >> 3;
  if ( v20 >> 3 == 2 )
  {
    if ( (v9 & 2) != 0 )
      return 0;
    if ( MiAllowGuardFault(v8) )
    {
      MiUpdatePageTableUseCount(a2, 1);
      v84 = 32 * (v20 & 0xF);
      if ( v18 )
        v84 |= 0xFFFFE400;
      v85 = v112;
      if ( v112 + 0x40000000 > v115 )
      {
        *(_DWORD *)v112 = v84;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v112 = v84;
        if ( v85 + 1070596096 <= 0xFFF )
        {
          v86 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v86, v86 + 4 * (v85 & 0xFFF), v84);
        }
      }
      MiUnlockWorkingSetExclusive(v111 + 492, v117);
      *a5 = 2;
      return MiCheckForUserStackOverflow(a2);
    }
    return -1073741819;
  }
  if ( (v9 & 2) != 0 && (*(_DWORD *)(v110 + 40) & 0x4000) != 0 )
  {
    v9 |= 4u;
    v114 = v9;
  }
  if ( !v18 )
  {
    v42 = v107;
    if ( ((v9 & 2) == 0 || (v21 == 3 && (v107 & 7) != 0 || v21 == 1) && (v9 & 4) != 0)
      && (!*(_DWORD *)(v12 + 264) || MiWaitForForkToComplete() != 1) )
    {
      v43 = 0;
      if ( v13 )
        v43 = (*(_DWORD *)(v13 + 28) >> 8) & 0x3F;
      v113 = 1;
      if ( v13 )
      {
        if ( (v9 & 5) != 0 )
        {
          v44 = MiComputeZeroClusterMaximum(v110, v13);
          v45 = 1;
          v113 = v44;
          if ( v44 > 1 )
          {
            v46 = (_DWORD *)(v112 + 4);
            while ( !*v46++ )
            {
              if ( ++v45 >= v44 )
                goto LABEL_92;
            }
            v113 = v45;
          }
        }
      }
LABEL_92:
      v48 = (_DWORD *)MiGetZeroedPages(MiSystemPartition, v111 + 492, v43, v107, 66, &v113);
      if ( !v48 )
        return -1073741801;
      v49 = a2;
      v50 = v113;
      if ( a2 <= MmHighestUserAddress )
      {
        v51 = (_WORD *)(2 * ((a2 >> 22) - 534769440));
        *v51 += v113;
        if ( (unsigned int)(v51 + 534769440) <= 0x5FF && v50 <= 1 )
          MiIsAddressValid((((int)(v51 + 534769440) >> 1) - 0x40000) << 12, 0);
      }
      v52 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2964);
      do
        v53 = __ldrex(v52);
      while ( __strex(v53 + 1, v52) );
      v116 = 273;
      v54 = 0;
      v109 = 0;
      if ( (BYTE2(MiFlags) & 3u) > 1 && (v107 & 2) != 0 && (v49 < 0xC0000000 || v49 > 0xC03FFFFF) )
      {
        v54 = 2;
        v109 = 2;
        if ( (v107 & 4) != 0 )
        {
          v54 = 3;
          v109 = 3;
        }
      }
      v55 = 272;
      v56 = (v9 >> 2) & 1;
      v117 = 272;
      v119 = v56;
      if ( v56 )
      {
        v55 = 304;
        v117 = 304;
      }
      if ( v13 && (*(_DWORD *)(v13 + 32) & 0x7FFFFFFF) == 524286 )
        v117 = v55 | 0x40;
      if ( v50 )
      {
        v120[0] = 32 * v107;
        v57 = v50;
        v58 = 32 * v107;
        v59 = v112;
        do
        {
          v120[0] = ((int)v48 - MmPfnDatabase) / 24;
          if ( v59 + 0x40000000 > v115 )
          {
            *(_DWORD *)v59 = v58;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v59 = v58;
            if ( v59 >= 0xC0300000 && v59 <= 0xC0300FFF )
            {
              v80 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v80, v80 + 4 * (v59 & 0xFFF), v58);
              v54 = v109;
            }
          }
          *v48 = 0;
          v60 = MmPfnDatabase;
          v61 = 3 * (v48[3] & 0xFFFFF);
          if ( v54 )
            MiMarkPfnVerified((int)v48, v54);
          MiInitializePfn(v48, v59, v107, v117);
          v62 = 32 * (v107 & 0x1F | (v120[0] << 7) | 0x40);
          if ( v59 + 0x40000000 > v115 )
          {
            *(_DWORD *)v59 = v62;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v59 = v62;
            if ( v59 >= 0xC0300000 && v59 <= 0xC0300FFF )
            {
              v81 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v81, v81 + 4 * (v59 & 0xFFF), v62);
            }
          }
          v54 = v109;
          v59 += 4;
          --v57;
          v48 = (_DWORD *)(v60 + 8 * v61);
        }
        while ( v57 );
        v50 = v113;
        LOBYTE(v9) = v114;
        v56 = v119;
        v42 = v107;
      }
      if ( (v9 & 8) != 0 )
        v117 = v110;
      else
        v117 = 0;
      v63 = v56 == 0;
      v64 = 0;
      if ( !v50 )
      {
LABEL_129:
        v71 = (unsigned int *)(v111 + 276);
        do
          v72 = __ldrex(v71);
        while ( __strex(v72 + v64, v71) );
        return v116;
      }
      v65 = &MmProtectToPteMask[v42];
      v120[0] = (int)v65;
      while ( 1 )
      {
        v66 = (_DWORD *)(v112 + 4 * v64);
        v67 = *v66 >> 12;
        v68 = MmPfnDatabase;
        v115 = MmPfnDatabase;
        if ( v63 )
        {
          if ( (unsigned int)v66 > (v118 & ((unsigned int)MmHighestUserAddress >> 10)) - 0x40000000
            || (unsigned int)v66 < 0xC0000000 )
          {
            v82 = MiDetermineUserGlobalPteMask(v112 + 4 * v64);
            v68 = v115;
            v69 = MmProtectToPteMask[v107] & 0xFED | (v67 << 12) | v82 | 0x12;
          }
          else
          {
            v69 = (*v65 | (v67 << 12)) & 0xFFFFFBFF | 0x832;
          }
          if ( (v69 & 0x80) != 0 )
            v69 &= 0xFFFFFDFF;
          v70 = MiAllocateWsle(v111 + 492, v66, v68 + 24 * v67, 0, v69, v117);
          v117 = 0;
          v63 = v70;
          if ( v70 )
            goto LABEL_126;
          v68 = v115;
        }
        MiLockAndDecrementShareCount(v68 + 24 * v67, 0);
        if ( !v64 && !v119 )
          v116 = -1073741801;
LABEL_126:
        if ( v110 )
          MiAdvanceFaultList((_DWORD *)v110);
        ++v64;
        v65 = (int *)v120[0];
        if ( v64 >= v50 )
          goto LABEL_129;
      }
    }
    return 0;
  }
  v116 = 0;
  if ( (v9 & 2) == 0 )
  {
    if ( v13 )
    {
      v22 = *(_DWORD *)(v13 + 68);
      if ( (v22 & 0x80000000) == 0 )
      {
        v23 = *(_DWORD *)(v13 + 68) & 0x7FF;
        v24 = (v10 & 0xFFFFF001 | 2) >> 1;
        v25 = (v23 + (v22 >> 11)) << 12;
        LOBYTE(v9) = v9 | 0x10;
        if ( (v10 & 0xFFFFF000) == v25 )
        {
          if ( v23 == 2047 )
            v24 = ((v22 & 0xFFFFF800) + 2048) | 0x7FF;
          else
            v24 = v22 & 0xFFFFF800 | (v22 + 1) & 0x7FF;
        }
        else if ( v10 > v25 && (v26 = (v10 - v25) >> 12, v26 < 8) )
        {
          v74 = (v112 >> 2) & 0x3FF;
          if ( v74 <= v26 )
          {
            if ( v74 )
              LOBYTE(v9) = v9 & 0xEF;
          }
          else
          {
            v74 = (v10 - v25) >> 12;
          }
          if ( (v9 & 0x10) != 0 )
          {
            v75 = (int *)(v112 - 4);
            if ( v74 )
            {
              do
              {
                v77 = *v75--;
                v76 = v77;
                if ( (v77 & 2) == 0 || (v76 & 0x10) == 0 )
                  goto LABEL_38;
              }
              while ( --v74 );
            }
            v78 = v26 + 1;
            v79 = v23 + v78;
            if ( v79 > 0x7FF )
              v24 = ((v22 & 0xFFFFF800) + ((v79 - 2047) << 11)) | 0x7FF;
            else
              v24 = v22 & 0xFFFFF800 | (v78 + v22) & 0x7FF;
          }
        }
        else if ( v25 || v10 >> 12 != *(_DWORD *)(v13 + 12) )
        {
LABEL_38:
          LOBYTE(v9) = v9 & 0xEF;
          goto LABEL_39;
        }
LABEL_39:
        v27 = *(_DWORD *)(v13 + 40);
        if ( (v9 & 0x10) != 0 )
        {
          if ( (v27 & 0x2000000) != 0 )
          {
            v10 = a2;
            if ( v25 )
              v40 = v25 - 4096;
            else
              v40 = a2;
            if ( (((v40 >> 12) - *(_DWORD *)(v13 + 12)) >> 8) + 1 == ((a2 >> 12) - *(_DWORD *)(v13 + 12)) >> 8 )
            {
              v87 = (unsigned int *)(v13 + 20);
              do
                v88 = __ldrex(v87);
              while ( __strex(v88 + 1, v87) );
              __dmb(0xBu);
              v116 = -1073741280;
            }
            goto LABEL_42;
          }
        }
        else
        {
          *(_DWORD *)(v13 + 40) = v27 & 0xFDFFFFFF;
        }
        v10 = a2;
LABEL_42:
        *(_DWORD *)(v13 + 68) = v24;
        goto LABEL_43;
      }
    }
  }
LABEL_43:
  *a5 = 0;
  v28 = v10;
  *a6 = v107;
  v29 = 0;
  *a7 = v18;
  *a8 = v13;
  while ( v28 > MmHighestUserAddress )
  {
    ++v29;
    v28 <<= 10;
    if ( v29 )
      goto LABEL_55;
  }
  v30 = (_WORD *)(2 * ((v10 >> 22) - 534769440));
  ++*v30;
  if ( (unsigned int)(v30 + 534769440) <= 0x5FF )
  {
    v120[0] = (v118 & (4 * (((int)(v30 + 534769440) >> 1) - 0x40000)) & 0x3FFFFF) - 0x40000000;
    v31 = 2;
    v120[1] = (v118 & ((unsigned int)v120[0] >> 10)) - 0x40000000;
    v32 = &v121;
    while ( 1 )
    {
      v33 = (int *)*((_DWORD *)v32 - 1);
      v32 -= 4;
      --v31;
      v34 = *v33;
      if ( (*v33 & 2) == 0 )
        break;
      if ( v31 <= 1 && (v34 & 0x400) != 0 )
      {
        if ( !v31 )
          break;
LABEL_51:
        v35 = 2;
        while ( 1 )
        {
          v36 = *(_DWORD *)v120[--v35];
          if ( (v36 & 0x10) == 0 )
            goto LABEL_55;
          if ( v35 == 1 )
          {
            if ( (v36 & 0x400) != 0 )
              goto LABEL_55;
          }
          else if ( !v35 )
          {
            goto LABEL_55;
          }
        }
      }
      if ( !v31 )
        goto LABEL_51;
    }
  }
LABEL_55:
  if ( v107 == 256 )
    v37 = v18 & 0x1FC | (4 * (v18 & 0xFFFFFE00 | 0x100));
  else
    v37 = 32 * (v107 & 0x1F | 0xFFFFFF20);
  v38 = v112;
  if ( v112 + 0x40000000 > v115 )
  {
    *(_DWORD *)v112 = v37;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v112 = v37;
    if ( v38 >= 0xC0300000 && v38 <= 0xC0300FFF )
    {
      v89 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v89, v89 + 4 * (v38 & 0xFFF), v37);
    }
  }
  if ( (v9 & 2) != 0 && v13 )
  {
    v90 = *(_DWORD *)(v110 + 12);
    v91 = *(_QWORD *)(v110 + 4);
    v113 = *(_DWORD *)(v110 + 16);
    v114 = v90;
    v92 = *(_DWORD *)(v91 + 8 * v90);
    v120[0] = HIDWORD(v91);
    v93 = v92 + (v113 << 12);
    v94 = MiAdvanceFaultList((_DWORD *)v110);
    v95 = v94[3];
    v119 = 1;
    if ( v95 < HIDWORD(v91) )
    {
      v117 = 256;
      v96 = (v118 & (v93 >> 10)) - 1073741820;
      v97 = *(_DWORD *)(v13 + 16) - (a2 >> 12) + 1;
      if ( v97 >= 0x100 || (v117 = *(_DWORD *)(v13 + 16) - (a2 >> 12) + 1, v97 > 1) )
      {
        v98 = (v118 & (v93 >> 10)) - 3145724;
        while ( 1 )
        {
          v99 = v96 & 0xFFF;
          if ( (v96 & 0xFFF) == 0 )
            break;
          v100 = *(_DWORD *)(v94[1] + 8 * v95) + (v94[4] << 12);
          v118 = v100;
          if ( (v100 & 0xFFFFF000) - 4096 != (v93 & 0xFFFFF000) )
            break;
          v101 = *(_DWORD *)v96;
          v96 += 4;
          if ( !v101 )
          {
            v102 = MiGetProtoPteAddress(v13, v100 >> 12, 0, &v112);
            if ( !v102
              || (v103 = *(_QWORD **)(v13 + 68), (int)v103 < 0)
              && (v118 >> 12) - *(_DWORD *)(v13 + 12) > (unsigned int)((*v103 - 1i64) >> 12) )
            {
              v94 = (_DWORD *)v110;
              break;
            }
            MiUpdatePageTableUseCount(a2, 1);
            if ( v107 == 256 )
              v104 = v102 & 0x1FC | (4 * (v102 & 0xFFFFFE00 | 0x100));
            else
              v104 = 32 * (v107 & 0x1F | 0xFFFFFF20);
            if ( v98 + 3145728 > v115 )
            {
              *(_DWORD *)(v96 - 4) = v104;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)(v96 - 4) = v104;
              if ( v98 <= 0xFFF )
              {
                v105 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v105, v105 + 4 * v99, v104);
              }
            }
            v94 = (_DWORD *)v110;
          }
          v98 += 4;
          v106 = ++v119;
          v94 = MiAdvanceFaultList(v94);
          v95 = v94[3];
          if ( v95 != v120[0] )
          {
            v93 = v118;
            if ( v106 < v117 )
              continue;
          }
          break;
        }
      }
    }
    v94[3] = v114;
    v94[4] = v113;
  }
  return v116;
}
