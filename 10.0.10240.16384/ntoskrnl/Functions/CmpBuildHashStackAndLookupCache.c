// CmpBuildHashStackAndLookupCache 
 
int __fastcall CmpBuildHashStackAndLookupCache(int a1, int *a2, int *a3, int *a4, _DWORD *a5, _DWORD *a6, unsigned int *a7, unsigned int *a8, _DWORD *a9, _DWORD *a10, int a11, int *a12, _BYTE *a13, _BYTE *a14)
{
  int *v14; // r5
  int *v15; // r4
  _BYTE *v17; // r0
  int v18; // r10
  int v19; // r1
  unsigned int v20; // r7
  int v22; // r4
  int v23; // r6
  unsigned int v24; // r9
  int v25; // r8
  int v26; // r10
  _WORD *i; // r5
  __int16 v28; // r7
  unsigned int v29; // r4
  int *v30; // r4
  unsigned int v31; // r2
  unsigned int v32; // r2
  int v33; // r6
  int *v34; // r5
  unsigned int *v35; // r9
  int *v36; // r2
  _DWORD *v37; // r8
  int v38; // r4
  int v39; // r0
  int *v40; // r6
  int v41; // r10
  int v42; // r4
  int *v43; // r4
  unsigned int v44; // r2
  int v45; // r2
  unsigned int v46; // r1
  unsigned int v47; // r3
  unsigned int v48; // r6
  unsigned int v49; // r9
  _WORD *v50; // r4
  char *v51; // r10
  unsigned int v52; // r8
  unsigned __int16 *v53; // r7
  unsigned int v54; // r5
  unsigned int v55; // r0
  unsigned int v56; // t1
  int v57; // r0
  int v58; // r4
  unsigned int v59; // r1
  unsigned int v60; // r0
  unsigned int v61; // r3
  unsigned int v62; // r1
  unsigned int v63; // r0
  int v64; // r9
  int v65; // r8
  int v66; // r7
  char *v67; // r6
  unsigned int v68; // r4
  unsigned int v69; // t1
  unsigned __int16 *v70; // r5
  int v71; // r10
  int v72; // r2
  unsigned int v73; // r0
  unsigned int v74; // r6
  unsigned int v75; // r2
  int v76; // r6
  int v77; // r7
  int v78; // r0
  unsigned int v79; // r5
  int v80; // r0
  unsigned int v81; // r1
  unsigned int v82; // r1
  int v83; // r3
  int v84; // r1
  unsigned int v85; // r5
  unsigned int v86; // r0
  int v87; // r7
  int v88; // r8
  unsigned int v89; // r6
  int v90; // r0
  int v91; // r5
  unsigned int v92; // r2
  _DWORD *v93; // r6
  unsigned __int8 *v94; // r7
  int v95; // r0
  int v96; // r5
  unsigned int v97; // r2
  unsigned int v98; // r3
  int v99; // r0
  _DWORD *v100; // r0
  int v101; // r0
  unsigned int v102; // r2
  __int16 v103; // r3
  int v104; // r0
  int v105; // r1
  int *v106; // r4
  int v107; // r3
  int v108; // [sp+28h] [bp-E8h]
  int v110; // [sp+30h] [bp-E0h]
  int v111; // [sp+34h] [bp-DCh]
  unsigned int v112; // [sp+34h] [bp-DCh]
  int v114; // [sp+40h] [bp-D0h] BYREF
  int v115; // [sp+44h] [bp-CCh]
  unsigned int v116; // [sp+48h] [bp-C8h]
  int v117; // [sp+4Ch] [bp-C4h]
  int *v118; // [sp+50h] [bp-C0h]
  _DWORD *v119; // [sp+54h] [bp-BCh]
  int v120; // [sp+58h] [bp-B8h]
  unsigned int *v121; // [sp+5Ch] [bp-B4h]
  int v122; // [sp+60h] [bp-B0h]
  int v123; // [sp+64h] [bp-ACh]
  _DWORD *v124; // [sp+68h] [bp-A8h]
  _DWORD *v125; // [sp+6Ch] [bp-A4h]
  _DWORD *v126; // [sp+70h] [bp-A0h]
  int *v127; // [sp+74h] [bp-9Ch]
  _BYTE *v128; // [sp+78h] [bp-98h]
  int v129; // [sp+7Ch] [bp-94h] BYREF
  unsigned int *v130; // [sp+80h] [bp-90h]
  int v131; // [sp+84h] [bp-8Ch]
  _BYTE *v132; // [sp+88h] [bp-88h]
  int v133; // [sp+8Ch] [bp-84h]
  unsigned int v134; // [sp+90h] [bp-80h]
  int v135; // [sp+94h] [bp-7Ch]
  int v136; // [sp+98h] [bp-78h]
  char v137[16]; // [sp+A0h] [bp-70h] BYREF
  __int16 v138; // [sp+B0h] [bp-60h] BYREF
  _WORD v139[31]; // [sp+B2h] [bp-5Eh] BYREF

  v14 = a4;
  v15 = a2;
  v126 = a5;
  v127 = a3;
  v123 = a1;
  v124 = a6;
  v130 = a7;
  v138 = 0;
  v121 = a8;
  v125 = a10;
  v119 = a9;
  v120 = a11;
  v132 = a14;
  v118 = a12;
  v128 = a13;
  v17 = memset(v139, 0, sizeof(v139));
  v129 = 0;
  v108 = 0;
  v18 = *v15;
  v19 = 0;
  v136 = *v14;
  v20 = 0;
  v110 = 0;
  v131 = v14[1];
  *a14 = 0;
  v116 = 0;
  v117 = v18;
  if ( a9 )
  {
    v122 = a9[13];
    if ( v122 )
      return sub_7FE670(v17);
    v19 = 0;
  }
  v122 = *(_DWORD *)(a1 + 28);
  while ( 1 )
  {
    while ( 1 )
    {
      do
      {
        v22 = *(_DWORD *)(v18 + 12);
        v23 = *(unsigned __int16 *)v14;
        v24 = 0;
        v111 = v22;
        v25 = v22;
        v26 = 0;
        if ( *(_WORD *)v14 )
        {
          for ( i = (_WORD *)v14[1]; *i == 92; v23 = (unsigned __int16)(v23 - 2) )
            ++i;
          v28 = 0;
          *(_DWORD *)&v139[1] = i;
          if ( !v23 )
            goto LABEL_16;
          do
          {
            v29 = (unsigned __int16)*i;
            if ( v29 == 92 )
            {
              v43 = v118;
              if ( v24 < 0x20 )
              {
                CmpSetConvKeyAtIndex(v120, *v118, v24, v25);
                *(_WORD *)CmpFindKeyNameAtIndex((int)&v138, *v43, v44) = v28;
                v28 = 0;
                ++v24;
              }
              ++v26;
              if ( v24 == 8 && !*v43 )
              {
                v100 = CmpAllocateExtraHashInfo();
                *v43 = (int)v100;
                if ( !v100 )
                {
                  v42 = -1073741801;
                  goto LABEL_32;
                }
              }
              for ( ; *i == 92; v23 = (unsigned __int16)(v23 - 2) )
                ++i;
              if ( v24 < 0x20 )
                *(_DWORD *)(CmpFindKeyNameAtIndex((int)&v138, *v43, v24) + 4) = i;
            }
            else
            {
              if ( v29 >= 0x61 )
              {
                if ( v29 > 0x7A )
                  v29 = (unsigned __int16)(*(_WORD *)(Nls844UnicodeUpcaseTable
                                                    + 2
                                                    * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                           + 2
                                                                           * (*(unsigned __int16 *)(Nls844UnicodeUpcaseTable
                                                                                                  + 2 * (v29 >> 8))
                                                                            + ((unsigned __int8)v29 >> 4)))
                                                     + (v29 & 0xF)))
                                         + v29);
                else
                  v29 -= 32;
              }
              v23 = (unsigned __int16)(v23 - 2);
              ++i;
              v28 += 2;
              v25 = 37 * v25 + v29;
            }
          }
          while ( v23 );
          if ( v24 < 0x20 )
          {
LABEL_16:
            v30 = v118;
            CmpSetConvKeyAtIndex(v120, *v118, v24, v25);
            *(_WORD *)CmpFindKeyNameAtIndex((int)&v138, *v30, v31) = v28;
            ++v24;
          }
          v20 = v26 + 1;
          v19 = v110;
          v22 = v111;
          v116 = v26 + 1;
        }
        *v130 = v24;
        if ( !v19 )
        {
          if ( !CmpPuntBoot )
          {
            PsBoostThreadIo(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 0);
            v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            --*(_WORD *)(v32 + 308);
            ExAcquireResourceSharedLite((int)&CmpRegistryLock, 1);
          }
          v19 = 1;
          v110 = 1;
        }
        if ( v20 > 0x20 )
        {
          v42 = -1073741562;
          goto LABEL_32;
        }
        v18 = v117;
        v14 = a4;
      }
      while ( *(_DWORD *)(v117 + 12) != v22 );
      v33 = v123;
      if ( (*(_DWORD *)(*(_DWORD *)(v123 + 4) + 4) & 0x20000) != 0 )
      {
        if ( (*(_DWORD *)(v123 + 24) & 1) != 0 )
          v42 = -1073740763;
        else
          v42 = -1073741444;
        goto LABEL_32;
      }
      v34 = a4;
      *v126 = *(_DWORD *)(v117 + 20);
      *v124 = *(_DWORD *)(v18 + 24);
      if ( *(void **)(v18 + 20) != CmpMasterHive )
      {
        v35 = (unsigned int *)a2;
        goto LABEL_27;
      }
      v45 = a4[1];
      v46 = 0;
      v133 = *(_DWORD *)(v18 + 24);
      v47 = *(unsigned __int16 *)a4;
      v48 = 0;
      v135 = v45;
      v49 = v45 + 2 * (v47 >> 1);
      v134 = v49;
      v50 = (_WORD *)v45;
      v112 = 0;
      v51 = v137;
      while ( v49 > (unsigned int)v50 )
      {
        do
        {
          if ( *v50 != 92 )
            break;
          ++v50;
          v48 = (unsigned __int16)(v48 + 2);
        }
        while ( (unsigned int)v50 < v49 );
        if ( v50 == (_WORD *)v49 )
        {
          if ( !v46 )
          {
            v42 = -1073741811;
            v77 = v114;
            v76 = v115;
            v71 = v108;
            goto LABEL_108;
          }
          break;
        }
        for ( ; (unsigned int)v50 < v49; v48 = (unsigned __int16)(v48 + 2) )
        {
          if ( *v50 == 92 )
            break;
          ++v50;
        }
        v52 = 0;
        v53 = (unsigned __int16 *)v45;
        if ( v48 )
        {
          LOWORD(v54) = 0;
          do
          {
            v56 = *v53++;
            v55 = v56;
            if ( v56 != 92 )
            {
              if ( v55 >= 0x61 )
              {
                if ( v55 > 0x7A )
                  v55 = RtlUpcaseUnicodeChar(v55);
                else
                  v55 -= 32;
              }
              v52 = 37 * v52 + v55;
            }
            v54 = (unsigned __int16)(v54 + 2);
          }
          while ( v54 < v48 );
          v49 = v134;
          v45 = v135;
          v46 = v112;
        }
        v112 = ++v46;
        *(_DWORD *)v51 = v52;
        v51 += 4;
        if ( v46 >= 3 )
          break;
      }
      v57 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
      v58 = v57;
      do
        v59 = __ldrex((unsigned int *)&CmpParseCacheLock);
      while ( !v59 && __strex(0x11u, (unsigned int *)&CmpParseCacheLock) );
      __dmb(0xBu);
      if ( v59 )
        ExfAcquirePushLockSharedEx(&CmpParseCacheLock, v57, (unsigned int)&CmpParseCacheLock);
      if ( v58 )
        *(_BYTE *)(v58 + 14) |= 1u;
      v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v60 + 0x134);
      __pld(&CmpShutdownRundown);
      v61 = CmpShutdownRundown & 0xFFFFFFFE;
      v62 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
      do
        v63 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v63 == v61 && __strex(v62, (unsigned int *)&CmpShutdownRundown) );
      __dmb(0xBu);
      if ( v63 == v61 )
      {
        v64 = 1;
      }
      else
      {
        v64 = ExfAcquireRundownProtection(&CmpShutdownRundown);
        if ( !v64 )
        {
          v62 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v103 = *(_WORD *)(v62 + 0x134) + 1;
          *(_WORD *)(v62 + 308) = v103;
          if ( !v103 && *(_DWORD *)(v62 + 100) != v62 + 100 && !*(_WORD *)(v62 + 310) )
            KiCheckForKernelApcDelivery(0);
          v42 = -1073741431;
          v71 = v108;
          goto LABEL_94;
        }
      }
      v65 = 0;
      v66 = CmpParseCacheTable;
      if ( v112 )
      {
        v67 = v137;
        while ( 1 )
        {
          v69 = *(_DWORD *)v67;
          v67 += 4;
          v68 = v69;
          v70 = *(unsigned __int16 **)(v66
                                     + 4
                                     * (((unsigned __int8)(-93 * (v69 ^ (v69 >> 9))) ^ (unsigned __int8)((101027 * (v69 ^ (v69 >> 9))) >> 9)) & 0x1F)
                                     + 4);
          if ( v70 )
            break;
LABEL_75:
          if ( ++v65 >= v112 )
            goto LABEL_76;
        }
        while ( *((_DWORD *)v70 + 5) != v68
             || *((_DWORD *)v70 + 6) != v133
             || !CmpParseCacheCompareUnicodeStrings(v70 + 6, (unsigned __int16 *)a4, (int)&v114, &v129) )
        {
          v70 = *(unsigned __int16 **)v70;
          if ( !v70 )
            goto LABEL_75;
        }
        v72 = *((_DWORD *)v70 + 7);
        if ( (*(_DWORD *)(v72 + 4) & 0x20000) != 0 )
        {
          v42 = -1073741444;
          goto LABEL_77;
        }
        v62 = *(_DWORD *)(v72 + 20);
        if ( (*(_DWORD *)(v62 + 92) & 0x20) == 0 || *(_DWORD *)(v62 + 3268) == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
        {
          v62 = *((_DWORD *)v70 + 7);
          if ( (*(_DWORD *)(v62 + 4) & 0x40000) != 0 )
          {
            v42 = -1073740763;
          }
          else
          {
            v73 = *(_DWORD *)v62;
            v42 = 0;
            __dmb(0xBu);
            v74 = v73 + 1;
            if ( v73 != -1 )
            {
              while ( 1 )
              {
                if ( v74 == 1 )
                  KeBugCheckEx(81, 21, 0, 0, 0);
                __dmb(0xBu);
                do
                  v75 = __ldrex((unsigned int *)v62);
                while ( v75 == v73 && __strex(v74, (unsigned int *)v62) );
                __dmb(0xBu);
                if ( v75 == v73 )
                  break;
                v73 = v75;
                v74 = v75 + 1;
                if ( v75 == -1 )
                  goto LABEL_153;
              }
              v71 = *((_DWORD *)v70 + 7);
              v108 = v71;
              goto LABEL_94;
            }
LABEL_153:
            v42 = -1073741670;
          }
          goto LABEL_77;
        }
      }
LABEL_76:
      v42 = -1073741772;
LABEL_77:
      v71 = v108;
LABEL_94:
      v77 = v114;
      v76 = v115;
      __pld(&CmpParseCacheLock);
      v78 = CmpParseCacheLock;
      if ( (CmpParseCacheLock & 0xFFFFFFF0) > 0x10 )
        v79 = CmpParseCacheLock - 16;
      else
        v79 = 0;
      if ( (CmpParseCacheLock & 2) != 0 )
        goto LABEL_151;
      __dmb(0xBu);
      do
        v62 = __ldrex((unsigned int *)&CmpParseCacheLock);
      while ( v62 == v78 && __strex(v79, (unsigned int *)&CmpParseCacheLock) );
      if ( v62 != v78 )
LABEL_151:
        ExfReleasePushLock(&CmpParseCacheLock, v62);
      KeAbPostRelease((unsigned int)&CmpParseCacheLock);
      if ( v64 )
      {
        __pld(&CmpShutdownRundown);
        v80 = CmpShutdownRundown & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v81 = __ldrex((unsigned int *)&CmpShutdownRundown);
        while ( v81 == v80 && __strex(v80 - 2, (unsigned int *)&CmpShutdownRundown) );
        if ( v81 != v80 )
          v80 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
        v82 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v83 = (__int16)(*(_WORD *)(v82 + 0x134) + 1);
        *(_WORD *)(v82 + 308) = v83;
        if ( !v83 && *(_DWORD *)(v82 + 100) != v82 + 100 && !*(_WORD *)(v82 + 310) )
          KiCheckForKernelApcDelivery(v80);
      }
LABEL_108:
      if ( v42 >= 0 )
        break;
      if ( v42 != -1073741772 )
        goto LABEL_32;
      if ( !CmpLoadingSystemHivesActive )
      {
        v35 = (unsigned int *)a2;
LABEL_136:
        v20 = v116;
        v98 = ((*(_DWORD *)(*v35 + 4) >> 21) & 0x3FF) + v116;
        if ( v98 > 3 )
          goto LABEL_32;
        if ( v98 == 3 && (*v119 & 2) == 0 && CmpNoMasterCreates == 1 )
        {
          if ( (*v119 & 1) == 0 )
            goto LABEL_32;
LABEL_150:
          v42 = -1073741811;
          goto LABEL_32;
        }
        v34 = a4;
        v18 = v117;
        v33 = v123;
        v108 = 0;
        goto LABEL_27;
      }
      v102 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v35 = (unsigned int *)a2;
      if ( CmpMountThread != v102 )
      {
        v14 = a4;
        v101 = CmpWaitForHiveMount(a4, (*(_DWORD *)(*a2 + 4) >> 21) & 0x3FF, 1, 0);
        v20 = v116;
        v18 = v117;
        v19 = v110;
        if ( v101 )
          continue;
      }
      goto LABEL_136;
    }
    *v127 = v71;
    v84 = *(_DWORD *)(v71 + 20);
    if ( (*(_DWORD *)(v84 + 92) & 0x20) != 0 && *(_DWORD *)(v84 + 3268) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    {
      v42 = -1073741772;
      goto LABEL_32;
    }
    v35 = (unsigned int *)a2;
    v34 = a4;
    *v126 = *(_DWORD *)(v71 + 20);
    *v124 = *(_DWORD *)(v71 + 24);
    *a2 = v71;
    v18 = v117;
    *a4 = v77;
    a4[1] = v76;
    v20 = v116;
    v33 = v123;
LABEL_27:
    v36 = *(int **)(*v35 + 20);
    if ( v36 == CmpMasterHive && (*(_DWORD *)(v33 + 32) || v122) )
    {
      if ( (*(_WORD *)(*v35 + 106) & 0x10) == 0 )
        goto LABEL_150;
      v37 = v119;
      if ( (*v119 & 0x200) != 0 )
        goto LABEL_150;
    }
    else
    {
      v37 = v119;
    }
    v38 = v122;
    v39 = CmpSearchAddTrans(0, v36[814], 0, v122, *(_DWORD *)(v33 + 32), 0, v125);
    if ( v39 >= 0 )
      break;
    CmpUnlockRegistry(v39);
    v104 = CmpSearchAddTrans(0, *(_DWORD *)(*(_DWORD *)(*v35 + 20) + 3256), 0, v38, *(_DWORD *)(v33 + 32), 1, v125);
    if ( v104 < 0 )
      goto LABEL_189;
    CmpLockRegistry(v104, v105);
    v106 = v127;
    v19 = 1;
    v110 = 1;
    if ( *v127 )
    {
      CmpDereferenceKeyControlBlock(*v127);
      v19 = 1;
      *v106 = 0;
    }
    v14 = a4;
    v107 = v136;
    *v35 = v18;
    *a4 = v107;
    a4[1] = v131;
  }
  v40 = v118;
  v41 = v120;
  v42 = CmpKcbCacheLookup(v120, &v138, *v118, v129, v20, v121, v35, v34, v126, v124, v128, *v125, (*v37 & 1) != 0, v132);
  if ( v42 >= 0 && *v128 != 1 )
  {
    v85 = *v35;
    if ( (*(_DWORD *)(*v35 + 4) & 0x10) != 0 )
    {
      if ( (*v37 & 1) != 0 && *v121 == v20 )
      {
        v99 = CmpGetConvKeyAtIndex(v41, *v40, *v121 - 1);
        CmpLockHashEntryExclusive(*(_DWORD *)(v85 + 20), v99);
        CmpLockTwoKcbsExclusive(*v35, *(_DWORD *)(*v35 + 40));
      }
    }
    else
    {
      v86 = CmpGetConvKeyAtIndex(v41, *v40, *v121);
      v87 = *(_DWORD *)(v85 + 20);
      v88 = v86;
      v89 = *(_DWORD *)(v87 + 1844)
          + 12
          * (((101027 * (v86 ^ (v86 >> 9))) ^ ((101027 * (v86 ^ (v86 >> 9))) >> 9)) & (*(_DWORD *)(v87 + 1848) - 1));
      v90 = KeAbPreAcquire(v89, 0, 0);
      v91 = v90;
      do
        v92 = __ldrex((unsigned __int8 *)v89);
      while ( __strex(v92 | 1, (unsigned __int8 *)v89) );
      __dmb(0xBu);
      if ( (v92 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx((_DWORD *)v89, v90, v89);
      if ( v91 )
        *(_BYTE *)(v91 + 14) |= 1u;
      *(_DWORD *)(v89 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      if ( !CmpReferenceHive(v87) )
        KeBugCheckEx(81, 23, v87, 12, v88);
      v93 = (_DWORD *)*v35;
      if ( (*(_DWORD *)(*v35 + 4) & 0x100000) != 0 )
        v93[9] = CmpLockTableAdd(*v35, 1);
      v94 = (unsigned __int8 *)(v93 + 7);
      v95 = KeAbPreAcquire((unsigned int)(v93 + 7), 0, 0);
      v96 = v95;
      do
        v97 = __ldrex(v94);
      while ( __strex(v97 | 1, v94) );
      __dmb(0xBu);
      if ( (v97 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(v93 + 7, v95, (unsigned int)(v93 + 7));
      if ( v96 )
        *(_BYTE *)(v96 + 14) |= 1u;
      v93[8] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    }
  }
LABEL_32:
  if ( !v110 )
LABEL_189:
    JUMPOUT(0x7FE67C);
  return v42;
}
