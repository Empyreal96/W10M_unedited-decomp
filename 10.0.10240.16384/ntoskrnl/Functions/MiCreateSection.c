// MiCreateSection 
 
int MiCreateSection(int *a1, int a2, char a3, unsigned __int64 *a4, int a5, unsigned int a6, ...)
{
  unsigned int v6; // r5
  _DWORD *v7; // r10
  unsigned int v8; // r2
  unsigned int v10; // r8
  int v11; // r7
  int v12; // r0
  int v13; // r0
  int v14; // r4
  int v15; // r1
  _DWORD *v16; // r4
  int v17; // r0
  int v18; // r7
  int v19; // r1
  int v20; // r4
  unsigned int v21; // r6
  int v22; // r0
  unsigned int v23; // r4
  int *v24; // r8
  __int16 v25; // r3
  _DWORD *v26; // r6
  int v27; // lr
  unsigned int v28; // r9
  _DWORD *v29; // r4
  _DWORD *v30; // r2
  int v31; // r5
  int v32; // r6
  int v33; // r2
  _DWORD *v34; // r5
  unsigned __int64 *v35; // r3
  unsigned int v36; // r1
  unsigned int v37; // r2
  unsigned __int64 v38; // kr00_8
  unsigned int v39; // r0
  unsigned int v40; // r4
  _DWORD **v41; // r7
  char v42; // r1
  unsigned int v43; // lr
  int v44; // r3
  unsigned int v45; // r5
  unsigned int v46; // r6
  _DWORD *v47; // r4
  int v48; // r10
  int v49; // r2
  int v50; // r1
  int v51; // r1
  int v52; // r2
  int v53; // r3
  int v54; // r6
  int v55; // r1
  unsigned __int64 v56; // r2
  int v57; // r2
  int v58; // r1
  int v59; // r3
  unsigned __int64 *v60; // r3
  unsigned __int64 v61; // kr10_8
  int v62; // r2
  _DWORD *v63; // r3
  int v64; // r8
  int *v65; // r2
  int v66; // lr
  int v67; // r3
  int **v68; // r3
  __int64 v69; // r2
  unsigned __int64 *v70; // r4
  int v71; // r0
  __int16 v72; // r3
  unsigned __int64 v73; // kr20_8
  _DWORD **v74; // lr
  bool v75; // zf
  unsigned __int64 *v76; // r3
  unsigned __int64 v77; // kr28_8
  int v78; // r3
  int v79; // r3
  int v80; // r3
  int v81; // r4
  unsigned int *v82; // r4
  unsigned int v83; // r2
  int **v84; // lr
  unsigned __int64 *v85; // r3
  unsigned __int64 v86; // kr38_8
  int v87; // r0
  int v88; // r2
  unsigned int v89; // r3
  int v90; // r2
  int v91; // r3
  _DWORD **v92; // r3
  unsigned __int64 *v93; // r3
  unsigned int v94; // r1
  unsigned int v95; // r2
  unsigned __int64 v96; // kr40_8
  int v97; // r3
  unsigned __int64 *v98; // r3
  unsigned __int64 v99; // kr48_8
  __int16 v100; // r3
  __int16 v101; // r3
  _DWORD *v102; // r0
  _DWORD *v103; // r4
  int v104; // r0
  _DWORD *v105; // r0
  int v106; // r3
  int v107; // r4
  unsigned int v108; // r2
  unsigned int *v109; // r2
  unsigned int v110; // r1
  unsigned int v111; // r2
  int v112; // r3
  unsigned __int64 v113; // r2
  unsigned int v114; // r10
  int v115; // lr
  unsigned int v116; // r1
  int v117; // r4
  unsigned int v118; // r5
  int v119; // r0
  __int16 v120; // r3
  __int64 v121; // r2
  unsigned int v122; // r0
  int v123; // r0
  int v124; // r3
  int v125; // [sp+0h] [bp-110h]
  int v126; // [sp+18h] [bp-F8h]
  _DWORD **v127; // [sp+1Ch] [bp-F4h] BYREF
  _DWORD *v128; // [sp+20h] [bp-F0h]
  int v129; // [sp+24h] [bp-ECh]
  unsigned int v130; // [sp+28h] [bp-E8h] BYREF
  _DWORD **v131; // [sp+2Ch] [bp-E4h] BYREF
  _DWORD *v132; // [sp+30h] [bp-E0h] BYREF
  char v133[4]; // [sp+34h] [bp-DCh] BYREF
  unsigned __int64 *v134; // [sp+38h] [bp-D8h]
  int v135; // [sp+3Ch] [bp-D4h]
  int v136; // [sp+40h] [bp-D0h] BYREF
  int v137; // [sp+44h] [bp-CCh]
  int v138; // [sp+48h] [bp-C8h]
  int v139; // [sp+4Ch] [bp-C4h]
  int v140; // [sp+50h] [bp-C0h]
  __int64 v141; // [sp+58h] [bp-B8h] BYREF
  int v142; // [sp+60h] [bp-B0h]
  int v143; // [sp+64h] [bp-ACh]
  int v144; // [sp+68h] [bp-A8h]
  int v145; // [sp+6Ch] [bp-A4h]
  int v146; // [sp+70h] [bp-A0h]
  int v147; // [sp+74h] [bp-9Ch]
  int v148; // [sp+78h] [bp-98h]
  int *v149; // [sp+7Ch] [bp-94h]
  unsigned __int64 v150; // [sp+80h] [bp-90h]
  unsigned int v151; // [sp+88h] [bp-88h]
  unsigned int v152; // [sp+8Ch] [bp-84h]
  int v153; // [sp+90h] [bp-80h] BYREF
  unsigned int v154; // [sp+94h] [bp-7Ch] BYREF
  int *v155; // [sp+98h] [bp-78h]
  int var70[29]; // [sp+A0h] [bp-70h] BYREF
  int v157; // [sp+130h] [bp+20h] BYREF
  va_list va; // [sp+130h] [bp+20h]
  int v159; // [sp+134h] [bp+24h]
  _DWORD *v160; // [sp+138h] [bp+28h]
  int v161; // [sp+13Ch] [bp+2Ch]
  int v162; // [sp+140h] [bp+30h]
  va_list va1; // [sp+144h] [bp+34h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v157 = va_arg(va1, _DWORD);
  v159 = va_arg(va1, _DWORD);
  v160 = va_arg(va1, _DWORD *);
  v161 = va_arg(va1, _DWORD);
  v162 = va_arg(va1, _DWORD);
  v142 = a2;
  v6 = 0;
  v134 = a4;
  v155 = a1;
  v130 = 0;
  v7 = 0;
  v128 = 0;
  if ( (a3 & 1) != 0 )
  {
    v6 = 2048;
    v130 = 2048;
  }
  if ( (a3 & 2) != 0 )
  {
    v6 |= 1u;
    v130 = v6;
    if ( (a3 & 4) != 0 )
      return -1073740761;
  }
  v8 = a6;
  if ( (a6 & 0x1100000) == 17825792 )
    return sub_802488(4, 0x100000);
  v138 = 0x400000;
  if ( (a6 & 0x100000) != 0 )
  {
    if ( (a6 & 0x200000) != 0 )
    {
      v8 = a6 & 0xFFDFFFFF;
      v6 |= 0x40u;
    }
    v6 |= 0x20u;
    v89 = v8 & 0xFFEFFFFF;
    v130 = v6;
    if ( (v8 & 0x400000) != 0 )
    {
      v6 |= 0x100u;
      v89 = v8 & 0xFFAFFFFF;
      v130 = v6;
      v90 = 12;
    }
    else
    {
      v90 = 1;
    }
    LOBYTE(v157) = v90;
    v126 = v90;
    v8 = v89 | 0x1000000;
  }
  else if ( (a6 & 0x2000000) != 0 )
  {
    v6 |= 0x10u;
    v130 = v6;
    if ( (a6 & 0x400000) != 0 )
    {
      v8 = a6 & 0xFFBFFFFF;
      v91 = 12;
    }
    else
    {
      v91 = 4;
    }
    LOBYTE(v157) = v91;
    v126 = v91;
    v8 = v8 & 0xFCFFFFFF | 0x1000000;
  }
  else
  {
    v126 = (unsigned __int8)v157;
  }
  v10 = v8 & 0x7F;
  LODWORD(v141) = v10;
  if ( v10 > (unsigned __int16)KeNumberNodes )
    return -1073741580;
  v11 = v8 & 0xFFFFFF80;
  v135 = v8 & 0xFFFFFF80;
  if ( (v8 & 0x1000000) == 0 )
  {
    if ( (v8 & 0x10000000) != 0 )
    {
      v12 = a5 | 0x200;
      goto LABEL_14;
    }
    if ( (v8 & 0x40000000) != 0 )
    {
      v12 = a5 | 0x400;
      goto LABEL_14;
    }
LABEL_13:
    v12 = a5;
LABEL_14:
    v129 = v12;
    goto LABEL_15;
  }
  if ( (BYTE2(MiFlags) & 3u) > 1 )
  {
    v6 |= 0x20000u;
    v130 = v6;
  }
  if ( (v8 & 0x11000000) != 285212672 )
  {
    v6 |= 0x400u;
    v130 = v6;
    if ( (v6 & 0x20) != 0 && (MiFlags & 0x30000) != 0 )
    {
      v6 |= 0x20000u;
      v130 = v6;
    }
    goto LABEL_13;
  }
  v12 = a5;
  v129 = a5;
  if ( a5 != 2 )
    return -1073741755;
  v11 = v8 & 0xEFFFFF80;
  v135 = v8 & 0xEFFFFF80;
LABEL_15:
  v13 = MiMakeProtectionMask(v12);
  v14 = v13;
  if ( v13 == -1 )
    return -1073741755;
  v15 = MmMakeFileAccess[v13 & 7];
  v149 = 0;
  v136 = v152 & 0xFFFFF000 | v129 & 0xFFF;
  v140 = 0x8000000;
  v143 = 4194305;
  if ( !v159 )
  {
    if ( !v160 )
    {
      v132 = (_DWORD *)(v11 & 0x1000000);
      if ( (v11 & 0x1000000) == 0 )
      {
        v137 = (char)v161;
        if ( (v11 & 0x80000000) != 0 )
        {
          if ( (v11 & 0x8000000) == 0 )
            return -1073741580;
          if ( !SeSinglePrivilegeCheck(SeLockMemoryPrivilege, dword_922B7C, (char)v161, (int)&SeLockMemoryPrivilege) )
            return -1073741727;
        }
        v18 = MiCreatePagingFileMap((unsigned int *)&v131, v134, v14, v11, v10);
        if ( v18 < 0 )
          return v18;
        __dmb(0xBu);
        v84 = v131;
        v127 = v131;
        v85 = (unsigned __int64 *)(v131 + 4);
        do
          v86 = __ldrexd(v85);
        while ( v86 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v85) );
        __dmb(0xBu);
        v150 = v86;
        v28 = v6 | 4;
        v24 = *v84;
        if ( (dword_682604 & v143) != 0 )
          MiLogSectionCreate(*v84, 1);
        v41 = v131;
LABEL_67:
        v16 = v160;
LABEL_68:
        v42 = v129;
LABEL_69:
        v43 = v126;
LABEL_70:
        v44 = v24[7];
        v45 = v136 & 0x7FFFFFFF;
        v46 = v44 & 0xFFF7FFFF;
        v149 = v24;
        v151 = v44 & 0xFFF7FFFF;
        v152 = v136 & 0x7FFFFFFF;
        if ( v132 )
        {
          if ( (v28 & 0x400) == 0 )
          {
            v46 |= 0x80000u;
            v151 = v46;
          }
          if ( v43 <= 1 && (v28 & 0x20000) == 0 )
            v45 |= 0x80000000;
          v152 = v45;
        }
        if ( (v44 & 0x4000000) != 0 )
        {
          v107 = v162;
          v18 = MiCreatePerSessionProtos(v24, v162);
          if ( v18 < 0 )
          {
            v102 = v7;
            goto LABEL_288;
          }
          v41 = v127;
          v45 ^= (v45 ^ (v107 << 12)) & 0x7FFFF000;
          v152 = v45;
        }
        else if ( !v16 && (v42 & 0x44) != 0 && (v44 & 0x20) == 0 )
        {
          if ( v24[8] )
          {
            v82 = (unsigned int *)(v24 + 13);
            v46 |= v140;
            v151 = v46;
            do
              v83 = __ldrex(v82);
            while ( __strex(v83 + 1, v82) );
            __dmb(0xBu);
            if ( !ObCheckActiveHandles((int)v7) )
            {
              __dmb(0xBu);
              do
                v108 = __ldrex(v82);
              while ( __strex(v108 - 1, v82) );
              ObfDereferenceObject((int)v7);
              v18 = -1073741788;
              goto LABEL_289;
            }
          }
        }
        v47 = v128;
        v48 = 0;
        if ( v128 )
        {
          if ( (*(_DWORD *)(v128[1] + 32) & 0x10) != 0 )
            v48 = 1;
          else
            ObfDereferenceObject((int)v128);
        }
        v49 = 80;
        if ( (v24[7] & 0x20) != 0 || !v24[8] )
        {
          v50 = 4 * ((_DWORD)v41[1] + 10);
          v63 = v24 + 20;
          do
          {
            v63 = (_DWORD *)v63[2];
            v49 += 40;
          }
          while ( v63 );
        }
        else
        {
          v50 = 0;
          v49 = 68 * v24[38] + 92;
        }
        v18 = ObCreateObjectEx(v137, (_DWORD *)MmSectionObjectType, v142, v137, v125, 40, v50, v49, &v136, 0);
        if ( v18 >= 0 )
        {
          v51 = v145;
          v52 = v146;
          v53 = v147;
          v54 = v136;
          *(_DWORD *)v136 = v144;
          *(_DWORD *)(v54 + 4) = v51;
          *(_DWORD *)(v54 + 8) = v52;
          *(_DWORD *)(v54 + 12) = v53;
          v55 = (int)v149;
          v56 = v150;
          *(_DWORD *)(v54 + 16) = v148;
          *(_DWORD *)(v54 + 20) = v55;
          *(_QWORD *)(v54 + 24) = v56;
          HIDWORD(v56) = v152;
          *(_DWORD *)(v54 + 32) = v151;
          *(_DWORD *)(v54 + 36) = HIDWORD(v56);
          *(_DWORD *)(v54 + 12) = 0;
          if ( v48 == 1 )
          {
            v111 = (unsigned int)v128;
            *(_DWORD *)(v54 + 20) = v128;
            if ( (v24[7] & 0x20) != 0 )
              v112 = v111 | 1;
            else
              v112 = v111 | 2;
            *(_DWORD *)(v54 + 20) = v112;
          }
          if ( (v28 & 1) == 0 )
          {
            v57 = v135;
            v58 = v138;
            v59 = *(_DWORD *)(v54 + 32) | 0x10000;
            *(_DWORD *)(v54 + 32) = v59;
            if ( (v57 & v58) != 0 )
              *(_DWORD *)(v54 + 32) = v59 | 0x4000;
            if ( (v129 & 0x44) == 0 )
              *(_DWORD *)(v54 + 32) |= 0x800u;
            if ( (v57 & 0x200000) != 0 )
            {
              *(_DWORD *)(v54 + 32) |= 0x40u;
              v113 = *(_QWORD *)(v54 + 24);
              v136 = *(_DWORD *)(v54 + 24);
              if ( v113 > dword_632E20 )
              {
                ObfDereferenceObject(v54);
                return -1073741801;
              }
              v114 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
              --*(_WORD *)(v114 + 310);
              v115 = KeAbPreAcquire((unsigned int)&dword_632E10, 0, 0);
              v138 = v115;
              do
                v116 = __ldrex((unsigned __int8 *)&dword_632E10);
              while ( __strex(v116 | 1, (unsigned __int8 *)&dword_632E10) );
              __dmb(0xBu);
              if ( (v116 & 1) != 0 )
              {
                ExfAcquirePushLockExclusiveEx(&dword_632E10, v115, (unsigned int)&dword_632E10);
                v115 = v138;
              }
              if ( v115 )
                *(_BYTE *)(v115 + 14) |= 1u;
              v117 = v136;
              v138 = MiFindEmptyAddressRangeDownTree(
                       &dword_632E0C,
                       v136,
                       0x10000u,
                       0x10000u,
                       dword_632E20,
                       (unsigned int *)&v141);
              if ( v138 < 0 )
              {
                __dmb(0xBu);
                do
                  v118 = __ldrex((unsigned int *)&dword_632E10);
                while ( __strex(v118 - 1, (unsigned int *)&dword_632E10) );
                if ( (v118 & 2) != 0 && (v118 & 4) == 0 )
                  ExfTryToWakePushLock((unsigned int *)&dword_632E10);
                v119 = KeAbPostRelease((unsigned int)&dword_632E10);
                v120 = *(_WORD *)(v114 + 310) + 1;
                *(_WORD *)(v114 + 310) = v120;
                if ( !v120 && *(_DWORD *)(v114 + 100) != v114 + 100 )
                  KiCheckForKernelApcDelivery(v119);
                ObfDereferenceObject(v54);
                return v138;
              }
              LODWORD(v121) = (unsigned int)v141 >> 12;
              HIDWORD(v121) = ((unsigned int)v141 >> 12) + ((unsigned int)(v117 + 4095) >> 12) - 1;
              *(_QWORD *)(v54 + 12) = v121;
              MiInsertBasedSection(v54);
              __dmb(0xBu);
              do
                v122 = __ldrex((unsigned int *)&dword_632E10);
              while ( __strex(v122 - 1, (unsigned int *)&dword_632E10) );
              if ( (v122 & 2) != 0 && (v122 & 4) == 0 )
                ExfTryToWakePushLock((unsigned int *)&dword_632E10);
              v123 = KeAbPostRelease((unsigned int)&dword_632E10);
              v124 = (__int16)(*(_WORD *)(v114 + 310) + 1);
              *(_WORD *)(v114 + 310) = v124;
              if ( !v124 && *(_DWORD *)(v114 + 100) != v114 + 100 )
                KiCheckForKernelApcDelivery(v123);
            }
          }
          __dmb(0xBu);
          v60 = (unsigned __int64 *)(v127 + 4);
          do
            v61 = __ldrexd(v60);
          while ( v61 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v60) );
          __dmb(0xBu);
          if ( ((v24[7] & 0x8000) == 0 || (v28 & 9) != 0) && *(_QWORD *)(v54 + 24) <= v61
            || (v78 = *(_DWORD *)(v54 + 24),
                *(_DWORD *)(v54 + 24) = v61,
                v138 = v78,
                v79 = *(_DWORD *)(v54 + 28),
                *(_DWORD *)(v54 + 28) = HIDWORD(v61),
                v139 = v79,
                v18 = MmExtendSection(v54),
                v18 >= 0) )
          {
            v62 = v143;
            *v155 = v54;
            if ( (dword_682604 & v62) != 0 && !v24[8] )
              MiLogSectionObjectEvent(v54, 1);
          }
          else
          {
            ObfDereferenceObject(v54);
          }
          return v18;
        }
        if ( (v46 & v140) != 0 )
        {
          __dmb(0xBu);
          v109 = (unsigned int *)(v24 + 13);
          do
            v110 = __ldrex(v109);
          while ( __strex(v110 - 1, v109) );
        }
        else if ( (v24[7] & 0x4000000) != 0 )
        {
          MiDereferencePerSessionProtos(v24, (v45 >> 12) & 0x7FFFF);
        }
        if ( v48 != 1 )
        {
LABEL_289:
          if ( (v28 & 4) != 0 )
            MiDereferenceControlAreaBySection(v24, (v28 & 1) == 0);
          return v18;
        }
        v102 = v47;
LABEL_288:
        ObfDereferenceObject((int)v102);
        goto LABEL_289;
      }
      return -1073741792;
    }
    v16 = v160;
LABEL_112:
    v64 = v11 & 0x1000000;
    v132 = (_DWORD *)(v11 & 0x1000000);
    if ( (v11 & 0x1000000) != 0 )
    {
      if ( (v6 & 1) != 0 )
        return -1073741580;
      if ( *v134 )
        return -1073741582;
    }
    v65 = (int *)v16[5];
    if ( v65 )
    {
      if ( v142 && (*(_DWORD *)(v142 + 12) & 0x200) != 0 )
        v66 = 0;
      else
        v66 = (char)v161;
      v137 = v66;
      if ( v64 )
        v67 = v65[2];
      else
        v67 = *v65;
      v127 = (_DWORD **)v67;
      if ( !v67 || MiReferenceControlAreaForCacheManager((int)v16, v11, v6, v67) < 0 )
      {
        v7 = v16;
        v128 = v16;
        ObReferenceObjectExWithTag((int)v16, 2);
        goto LABEL_22;
      }
      v68 = (int **)v16[5];
      v28 = v6 | 4;
      if ( v64 )
      {
        v24 = v68[2];
        v92 = (_DWORD **)*v24;
        __dmb(0xBu);
        v93 = (unsigned __int64 *)(v92 + 4);
        do
        {
          v96 = __ldrexd(v93);
          v95 = HIDWORD(v96);
          v94 = v96;
        }
        while ( v96 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v93) );
      }
      else
      {
        v24 = *v68;
        LODWORD(v69) = *((_DWORD *)v134 + 1);
        HIDWORD(v69) = *(_DWORD *)v134;
        v150 = *v134;
        if ( (v28 & 1) != 0 || v69 )
          goto LABEL_122;
        v97 = *v24;
        __dmb(0xBu);
        v98 = (unsigned __int64 *)(v97 + 16);
        do
        {
          v99 = __ldrexd(v98);
          v95 = HIDWORD(v99);
          v94 = v99;
        }
        while ( v99 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v98) );
      }
      __dmb(0xBu);
      v150 = __PAIR64__(v95, v94);
LABEL_122:
      v41 = (_DWORD **)*v24;
      v127 = (_DWORD **)*v24;
      goto LABEL_68;
    }
    return -1073741792;
  }
  v16 = v160;
  if ( v160 )
    goto LABEL_112;
  if ( (v11 & 0x80000000) != 0 )
    return -1073741580;
  v137 = (char)v161;
  v17 = ObReferenceObjectByHandle(v159, v15, (int)IoFileObjectType, v161, (int)&v132, 0);
  v7 = v132;
  v18 = v17;
  v128 = v132;
  if ( v17 < 0 )
    return v18;
  if ( !v132[5] )
  {
    ObfDereferenceObject((int)v132);
    return -1073741792;
  }
  ObfReferenceObject((int)v132);
  v11 = v135;
LABEL_22:
  memset(var70, 0, 80);
  var70[7] |= 2u;
  if ( v7 )
    var70[8] = (int)v7;
  else
    var70[8] = 0;
  v131 = 0;
  v132 = (_DWORD *)(v11 & 0x1000000);
  if ( (v11 & 0x1000000) == 0 )
  {
LABEL_29:
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v21 + 308);
    do
    {
      if ( (v6 & 1) == 0 )
      {
        v22 = FsRtlAcquireToCreateMappedSection(v7, v129, &v153, &v154);
        v18 = v22;
        if ( v22 < 0 )
        {
          v101 = *(_WORD *)(v21 + 308) + 1;
          *(_WORD *)(v21 + 308) = v101;
          if ( !v101 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
            KiCheckForKernelApcDelivery(v22);
          ObDereferenceObjectEx((int)v7, 2);
          return v18;
        }
        if ( (v153 & 2) != 0 )
        {
          v100 = *(_WORD *)(v21 + 308) + 1;
          *(_WORD *)(v21 + 308) = v100;
          if ( !v100 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
            KiCheckForKernelApcDelivery(v22);
          ObDereferenceObjectEx((int)v7, 2);
          return -1073740761;
        }
        if ( v154 )
        {
          if ( ((v154 - 1) & v154) == 0 )
          {
            v6 |= 0x2000u;
            if ( v154 < dword_6348E4 )
              dword_6348E4 = v154;
          }
        }
        if ( v22 == 298 || v22 != 299 )
          v23 = v6 & 0xFFFFFF7F;
        else
          v23 = v6 | 0x80;
        IoSetTopLevelIrp(1);
        v6 = v23 | 2;
        v11 = v135;
        v130 = v23 | 2;
      }
    }
    while ( MiReferenceControlArea(v11, (int)v7, var70, v6 & 1, &v127) != 1 );
    v24 = (int *)v127;
    if ( ((unsigned int)v127[7] & 2) != 0 )
    {
      v70 = v134;
      v71 = MiCreateNewSection((int)v7, v11, v129, v141, v162, (unsigned __int8 *)va, (int)v134, (int *)&v130, &v131);
      v18 = v71;
      if ( v71 >= 0 )
      {
        v72 = *(_WORD *)(v21 + 308) + 1;
        *(_WORD *)(v21 + 308) = v72;
        if ( !v72 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
          KiCheckForKernelApcDelivery(v71);
        v73 = *v70;
        v74 = v131;
        v75 = *v70 == 0;
        v127 = v131;
        if ( v75 )
        {
          __dmb(0xBu);
          v76 = (unsigned __int64 *)(v74 + 4);
          do
            v77 = __ldrexd(v76);
          while ( v77 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v76) );
          __dmb(0xBu);
          v24 = *v74;
          v43 = (unsigned __int8)v157;
          v28 = v130;
          v41 = v131;
          v16 = v160;
          v150 = v77;
          v42 = v129;
        }
        else
        {
          v24 = *v131;
          v43 = (unsigned __int8)v157;
          v28 = v130;
          v41 = v131;
          v16 = v160;
          v150 = v73;
          v42 = v129;
        }
        goto LABEL_70;
      }
      if ( v131 )
        v24 = *v131;
      v103 = (_DWORD *)MiZeroSectionObjectPointer((int)v7, v24, v135);
      ObfDereferenceObject((int)v7);
      if ( v24 == var70 )
      {
        v104 = ObFastReplaceObject((unsigned int *)v24 + 8, 0);
        ObfDereferenceObject(v104);
      }
      else
      {
        MiDereferenceControlAreaBySection(v24, 1);
      }
      v105 = MiReleaseControlAreaWaiters(v103);
      v106 = (__int16)(*(_WORD *)(v21 + 308) + 1);
      *(_WORD *)(v21 + 308) = v106;
      if ( !v106 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery((int)v105);
      return v18;
    }
    v25 = *(_WORD *)(v21 + 308) + 1;
    *(_WORD *)(v21 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
      KiCheckForKernelApcDelivery(1);
    if ( (v24[7] & 0x200) != 0 )
    {
      v87 = PsIsCurrentThreadPrefetching();
      v26 = v132;
      if ( !v87 )
      {
        if ( v132 )
          v88 = 2;
        else
          v88 = 1;
        MmChangeSectionBackingFile(0, (int)v7, v88);
      }
    }
    else
    {
      v26 = v132;
    }
    ObfDereferenceObject((int)v7);
    v27 = *v24;
    v28 = v6 | 4;
    v127 = (_DWORD **)*v24;
    if ( ((v6 | 4) & 1) != 0 || (v24[7] & 0x20) != 0 )
    {
      if ( (v28 & 2) != 0 )
      {
        IoSetTopLevelIrp(0);
        v29 = v128;
        FsRtlReleaseFile(v128);
        v27 = (int)v127;
        v28 &= 0xFFFFFFFD;
      }
      else
      {
        v29 = v128;
      }
      if ( !v26 )
        goto LABEL_60;
      if ( (*(_BYTE *)(v27 + 10) & 1) != 0 && (v28 & 0x20000) != 0 )
      {
        v18 = -1073740749;
        dword_632EE4 = 81;
        ObfDereferenceObject((int)v29);
        goto LABEL_289;
      }
      v18 = MiRelocateImageAgain(v24);
      if ( v18 < 0 )
      {
        ObfDereferenceObject((int)v29);
        goto LABEL_289;
      }
      v27 = (int)v127;
      v30 = v127[9];
      if ( (*((_WORD *)v30 + 15) & 0x80) != 0 && v30[4] == 17 )
        v28 |= 0x8000u;
      if ( (v28 & 0x100) != 0 )
      {
        v31 = 4;
      }
      else if ( (v28 & 0x20) != 0 )
      {
        v31 = 1;
      }
      else if ( (v28 & 0x10) != 0 )
      {
        if ( (v28 & 0x1000) != 0 )
          v31 = 8;
        else
          v31 = 2;
      }
      else
      {
        v31 = 0;
      }
      v32 = (v28 >> 11) & 1;
      if ( v32 )
        v31 |= 0x10u;
      v33 = v126;
      if ( (v28 & 0x8400) != 0 && (v28 & 0x810) == 0 && v126 )
      {
        v18 = SeGetImageRequiredSigningLevel((int)v128, v31, v126, *((unsigned __int8 *)v127 + 11) >> 4, v133);
        if ( v18 < 0 )
        {
          v102 = v128;
          goto LABEL_288;
        }
        v33 = (unsigned __int8)v133[0];
        v27 = (int)v127;
        v126 = (unsigned __int8)v133[0];
      }
      if ( (v28 & 0x20000) != 0 )
      {
        v31 |= 0x40000000u;
        if ( !v33 )
          v126 = 4;
      }
      if ( (v28 & 0x8400) != 0
        && ((v28 & 0x10) != 0
         || !SeCompareSigningLevels()
         || (v31 & 0x40000000) != 0 && (v24[13] & 0xC000000) != v140
         || (v27 = (int)v127, (*((_BYTE *)v127 + 11) & 0xF0) == 0) && (*((_WORD *)v127[9] + 15) & 0x80) != 0) )
      {
        v80 = v31;
        v34 = v128;
        v18 = MiValidateSectionCreate((int)v128, v24, v162, v80, v126);
        if ( v18 < 0 )
        {
          v102 = v34;
          dword_632EE4 = 60;
          goto LABEL_288;
        }
        v81 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        if ( !SeCompareSigningLevels() && (v32 || (*(_BYTE *)(v81 + 734) & 8) == 0) )
        {
          v18 = -1073740760;
          v102 = v34;
          goto LABEL_288;
        }
        v27 = (int)v127;
      }
      else
      {
LABEL_60:
        v34 = v128;
      }
      __dmb(0xBu);
      v35 = (unsigned __int64 *)(v27 + 16);
      do
      {
        v38 = __ldrexd(v35);
        v37 = HIDWORD(v38);
        v36 = v38;
      }
      while ( v38 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v35) );
      __dmb(0xBu);
    }
    else
    {
      v34 = v128;
      v18 = FsRtlGetFileSize(v128, &v141);
      IoSetTopLevelIrp(0);
      FsRtlReleaseFile(v34);
      v28 &= 0xFFFFFFFD;
      if ( v18 < 0 )
      {
        v102 = v34;
        goto LABEL_288;
      }
      v37 = HIDWORD(v141);
      v36 = v141;
      if ( !v141 )
      {
        v40 = *((_DWORD *)v134 + 1);
        v39 = *(_DWORD *)v134;
        if ( !*v134 )
        {
          ObfDereferenceObject((int)v34);
          v18 = -1073741538;
          goto LABEL_289;
        }
        goto LABEL_174;
      }
    }
    v40 = *((_DWORD *)v134 + 1);
    v39 = *(_DWORD *)v134;
    if ( !*v134 )
    {
      v41 = v127;
      v28 |= 8u;
      v7 = v128;
      v150 = __PAIR64__(v37, v36);
      goto LABEL_67;
    }
LABEL_174:
    if ( v37 >= v40 && (v37 > v40 || v36 >= v39) )
    {
      v41 = v127;
      v28 |= 8u;
      v7 = v128;
      v150 = __PAIR64__(v40, v39);
      goto LABEL_67;
    }
    v42 = v129;
    if ( (v129 & 0x44) == 0 )
    {
      ObfDereferenceObject((int)v34);
      v18 = -1073741760;
      goto LABEL_289;
    }
    v41 = v127;
    v7 = v128;
    v150 = __PAIR64__(v40, v39);
    v16 = v160;
    goto LABEL_69;
  }
  v20 = (v6 >> 10) & 1;
  if ( !v20 || IoAllowExecution((int)v7) )
  {
    CcWaitForUninitializeCacheMap((int)v7, v19);
    if ( v20 && (v126 & 0x10) != 0 )
    {
      v6 |= 0x10u;
      v130 = v6;
      if ( (v126 & 0x30) == 48 )
      {
        v6 |= 0x1000u;
        v130 = v6;
      }
      LOBYTE(v157) = v126 & 0xF;
      v126 &= 0xFu;
    }
    goto LABEL_29;
  }
  ObDereferenceObjectEx((int)v7, 2);
  return -1073741790;
}
