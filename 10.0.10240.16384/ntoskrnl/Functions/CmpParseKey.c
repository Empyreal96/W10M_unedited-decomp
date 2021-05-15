// CmpParseKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpParseKey(int a1, void *a2, _DWORD *a3, char a4, int a5, int a6, unsigned __int16 *a7, int *a8, int a9, int *a10)
{
  int v10; // r8
  int *v12; // r6
  int v13; // r10
  _BYTE *v14; // r0
  int v16; // r2
  unsigned int v17; // r1
  int v18; // r1
  int v19; // r2
  __int16 v20; // r4
  int v21; // r3
  int v22; // r0
  int v23; // r8
  int v24; // r9
  _DWORD *v25; // r5
  int v26; // r4
  int v27; // r3
  int v28; // r1
  unsigned int *v29; // r2
  unsigned int v30; // r3
  unsigned int v31; // r3
  int v32; // r4
  unsigned int v33; // r2
  int v34; // r1
  int v35; // lr
  int v36; // r0
  int v37; // r0
  unsigned __int64 v38; // kr00_8
  char v39; // r0
  int v40; // r9
  int v41; // r7
  int v42; // r7
  int v43; // r3
  int v44; // r0
  int v45; // r1
  int v46; // r3
  int v47; // r2
  int v48; // r0
  unsigned int v49; // r1
  __int16 v50; // r3
  unsigned int v51; // r0
  unsigned __int16 *v52; // r1
  int v53; // r2
  int v54; // t1
  int v55; // r3
  int v56; // r0
  unsigned int *v57; // r3
  int v58; // r2
  unsigned int v59; // r4
  int *v60; // r1
  int v61; // r3
  int v62; // t1
  int v63; // r2
  int v64; // r0
  int v65; // r5
  int v66; // r8
  int v67; // r0
  int v68; // r4
  int v69; // r0
  int v70; // r2
  int v71; // r0
  int v72; // r8
  int v73; // r0
  int v74; // r2
  unsigned __int64 v75; // r0
  unsigned __int64 v76; // r0
  int v77; // r8
  unsigned int v78; // r0
  int v79; // lr
  int v80; // r4
  int v81; // r0
  unsigned int v82; // r0
  unsigned int *v83; // r4
  unsigned int v84; // r5
  unsigned int v85; // r3
  int v86; // r0
  int v87; // r3 OVERLAPPED
  _WORD *v88; // r4 OVERLAPPED
  __int16 v89; // r1
  __int16 v90; // r2
  int v91; // r3
  int v92; // r0
  int *v93; // r0
  int *v94; // r4
  unsigned __int16 *v95; // r2
  int v96; // r1
  int v97; // t1
  int v98; // r3
  _DWORD *v99; // r5
  int v100; // r3
  int v101; // r0
  int v102; // r4
  int v103; // r2
  unsigned int v104; // r1
  __int16 v105; // r3
  int v106; // r3
  int v107; // r0
  int v108; // r2
  int v109; // r3
  _DWORD *v110; // r4
  int v111; // r1
  int v112; // r0
  int v113; // r2
  int v114; // r3
  int v115; // [sp+38h] [bp-148h]
  _DWORD *v116; // [sp+40h] [bp-140h] BYREF
  int v117; // [sp+44h] [bp-13Ch]
  char v118[4]; // [sp+48h] [bp-138h] BYREF
  unsigned int *v119; // [sp+4Ch] [bp-134h]
  int v120[2]; // [sp+50h] [bp-130h] BYREF
  unsigned __int64 v121; // [sp+58h] [bp-128h] BYREF
  int v122; // [sp+60h] [bp-120h]
  int v123; // [sp+64h] [bp-11Ch] BYREF
  char v124[4]; // [sp+68h] [bp-118h] BYREF
  _WORD *v125; // [sp+6Ch] [bp-114h]
  unsigned int v126; // [sp+70h] [bp-110h] BYREF
  char v127[4]; // [sp+74h] [bp-10Ch] BYREF
  unsigned int v128; // [sp+78h] [bp-108h]
  int v129; // [sp+80h] [bp-100h] BYREF
  unsigned __int16 *v130; // [sp+84h] [bp-FCh]
  int v131; // [sp+88h] [bp-F8h]
  int v132; // [sp+8Ch] [bp-F4h] BYREF
  int v133; // [sp+90h] [bp-F0h]
  _DWORD *v134; // [sp+94h] [bp-ECh] BYREF
  int *v135; // [sp+98h] [bp-E8h]
  int v136; // [sp+9Ch] [bp-E4h] BYREF
  int v137; // [sp+A0h] [bp-E0h]
  _DWORD *v138; // [sp+A4h] [bp-DCh]
  _DWORD *v139; // [sp+A8h] [bp-D8h] BYREF
  int v140; // [sp+ACh] [bp-D4h] BYREF
  int v141; // [sp+B0h] [bp-D0h]
  int v142; // [sp+B4h] [bp-CCh] BYREF
  unsigned int v143; // [sp+B8h] [bp-C8h] BYREF
  int v144[2]; // [sp+C0h] [bp-C0h] BYREF
  int *v145; // [sp+C8h] [bp-B8h]
  int v146[2]; // [sp+D0h] [bp-B0h] BYREF
  int v147; // [sp+D8h] [bp-A8h]
  int v148[2]; // [sp+E0h] [bp-A0h] BYREF
  int v149; // [sp+E8h] [bp-98h] BYREF
  int v150; // [sp+ECh] [bp-94h] BYREF
  int v151; // [sp+F0h] [bp-90h] BYREF
  _DWORD v152[18]; // [sp+F4h] [bp-8Ch] BYREF
  char v153[64]; // [sp+140h] [bp-40h] BYREF

  v141 = a4;
  v137 = a6;
  v138 = a3;
  v10 = a1;
  v147 = a1;
  v135 = a10;
  v136 = -1;
  v12 = a8;
  v120[0] = 0;
  v123 = -1;
  v121 = 0i64;
  v142 = 0;
  v143 = 0;
  v116 = 0;
  v117 = 0;
  v13 = -1;
  v131 = 0;
  v132 = -1;
  v151 = 0;
  v145 = 0;
  v125 = 0;
  v140 = 0;
  v14 = memset(v152, 0, sizeof(v152));
  v150 = 0;
  v127[0] = 0;
  if ( a2 != CmKeyObjectType )
    return sub_7FE958(v14);
  if ( *a7 )
  {
    v16 = *((_DWORD *)a7 + 1);
    do
    {
      v17 = *a7;
      if ( *(_WORD *)(v16 + 2 * (v17 >> 1) - 2) != 92 )
        break;
      *a7 = v17 - 2;
    }
    while ( (_WORD)v17 != 2 );
  }
  v129 = *(_DWORD *)a7;
  v130 = (unsigned __int16 *)*((_DWORD *)a7 + 1);
  if ( v10 == CmpRegistryRootObject && (!a8 || (*a8 & 0x40) == 0) )
  {
    v52 = (unsigned __int16 *)*((_DWORD *)a7 + 1);
    v148[0] = *(_DWORD *)a7;
    v53 = LOWORD(v148[0]);
    if ( LOWORD(v148[0]) )
    {
      while ( 1 )
      {
        v54 = *v52++;
        if ( v54 != 92 )
          break;
        v53 = (unsigned __int16)(v53 - 2);
        if ( !v53 )
          goto LABEL_7;
      }
      if ( v53 )
      {
        v55 = *(v52 - 1);
        if ( v55 == 65 || v55 == 97 )
          return -1073741790;
      }
    }
  }
LABEL_7:
  v144[1] = (int)v144;
  v144[0] = (int)v144;
  *v135 = 0;
  if ( !a8 )
  {
    v93 = (int *)ExAllocatePoolWithTag(1, 80, 538987843);
    v94 = v93;
    v145 = v93;
    if ( !v93 )
      return -1073741670;
    memset(v93, 0, 80);
    v12 = v94;
  }
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(__int16 *)(v18 + 0x134) - 1;
  *(_WORD *)(v18 + 0x134) = v19;
  v20 = a5;
  if ( CmpCallBackCount && !ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v18, v19, CmpCallBackCount) )
  {
    v95 = v130;
    if ( v130 )
    {
      v96 = (unsigned __int16)v129;
      do
      {
        if ( !v96 )
          break;
        v97 = *v95++;
        if ( v97 != 92 )
          break;
        v96 = (unsigned __int16)(v96 - 2);
        LOWORD(v129) = v96;
        v130 = v95;
      }
      while ( v95 );
    }
    v152[13] = 1;
    v152[15] = v12[6];
    v152[16] = a5;
    v152[14] = &v129;
    LOBYTE(v152[17]) = v141;
    v98 = v12[5];
    v151 = v137;
    v152[0] = v10;
    v152[2] = v98;
    v99 = v138;
    v152[1] = CmKeyObjectType;
    v152[6] = v138[4];
    v152[9] = v135;
    v152[12] = v12[13];
    if ( (*v12 & 1) != 0 )
    {
      v152[8] = v12 + 7;
      LOWORD(v146[0]) = v12[1];
      HIWORD(v146[0]) = v146[0];
      v100 = v12[2];
      v152[5] = a9;
      v146[1] = v100;
      v152[3] = v146;
      v152[4] = v138[11];
      v101 = CmpCallCallBacks(26, &v151, 1, 27, v10, v144);
    }
    else
    {
      v101 = CmpCallCallBacks(28, &v151, 1, 29, v10, v144);
    }
    v102 = v101;
    if ( v101 < 0 )
    {
      if ( v101 == -1073740541 )
      {
        v103 = v152[7];
        v99[5] |= v152[7];
        v99[4] &= ~(v103 | 0x2000000);
        v102 = 0;
      }
      v104 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v105 = *(_WORD *)(v104 + 0x134) + 1;
      *(_WORD *)(v104 + 308) = v105;
      if ( !v105 && *(_DWORD *)(v104 + 100) != v104 + 100 && !*(_WORD *)(v104 + 310) )
        KiCheckForKernelApcDelivery(v101);
      if ( v145 )
        ExFreePoolWithTag((unsigned int)v145);
      return v102;
    }
    v20 = a5;
  }
  v21 = *v12;
  v139 = 0;
  v146[0] = v21;
  v133 = v121;
  while ( 1 )
  {
    v134 = *(_DWORD **)(v10 + 4);
    if ( (v20 & 0x100) != 0 )
      *v12 |= 0x200u;
    v22 = CmpBuildHashStackAndLookupCache(
            v10,
            (int *)&v134,
            &v142,
            &v129,
            v120,
            &v123,
            &v126,
            &v143,
            v12,
            &v140,
            (int)v153,
            (int *)&v139,
            v124,
            v127);
    v23 = v22;
    if ( v22 < 0 || v22 == 260 )
      break;
    v24 = (int)v134;
    v128 = v143;
    if ( v124[0] == 1 )
    {
      v25 = v134;
      v116 = v134;
LABEL_16:
      v26 = v117;
      goto LABEL_17;
    }
    if ( (v134[1] & 0x10) == 0 )
    {
      v25 = v134;
      v116 = v134;
      v51 = CmpGetConvKeyAtIndex((int)v153, (int)v139, v143);
      v13 = ((101027 * (v51 ^ (v51 >> 9))) ^ ((101027 * (v51 ^ (v51 >> 9))) >> 9)) & (*(_DWORD *)(*(_DWORD *)(v24 + 20)
                                                                                                + 1848)
                                                                                    - 1);
      v132 = v13;
      goto LABEL_16;
    }
    if ( (*v12 & 1) == 0 || v143 != v126 )
    {
      v25 = v116;
      goto LABEL_16;
    }
    v116 = v134;
    v26 = v134[10];
    v117 = v26;
    v25 = v134;
    v82 = CmpGetConvKeyAtIndex((int)v153, (int)v139, v143 - 1);
    v13 = ((101027 * (v82 ^ (v82 >> 9))) ^ ((101027 * (v82 ^ (v82 >> 9))) >> 9)) & (*(_DWORD *)(*(_DWORD *)(v24 + 20)
                                                                                              + 1848)
                                                                                  - 1);
    v132 = v13;
LABEL_17:
    v27 = *(_DWORD *)(v24 + 4);
    v28 = 0x20000;
    v119 = (unsigned int *)v24;
    if ( (v27 & 0x20000) != 0 )
    {
      v40 = v120[0];
      v23 = -1073741772;
      v115 = v120[0];
      goto LABEL_43;
    }
    v12[4] = *(unsigned __int16 *)(v147 + 26);
    if ( CmpVEEnabled && !CmpIsMasterHive(v24) )
    {
      if ( !CmpIsSystemEntity(v12 + 3, v28, v29, v30) && (*v12 & 8) == 0 )
      {
        v23 = CmpVEExecuteParseLogic(v24, &v129, v12, v137);
        if ( v23 != -1073741199 )
        {
LABEL_236:
          v40 = v120[0];
          v25 = v116;
          v26 = v117;
          v115 = v120[0];
          goto LABEL_43;
        }
        v23 = 0;
      }
      v28 = 0x20000;
    }
    v31 = v126;
    if ( !v126 )
    {
      v35 = v123;
LABEL_34:
      v37 = 1;
      __dmb(0xBu);
      do
        v38 = __ldrexd(qword_920988);
      while ( __strexd(v38 + 1, qword_920988) );
      __dmb(0xBu);
LABEL_37:
      if ( v37 )
        v39 = 4;
      else
        v39 = 0;
      v23 = CmpDoOpen(
              v120,
              v35,
              (int)v138,
              v141,
              a5,
              v12,
              v39 | 2,
              &v116,
              &v132,
              (int *)&v134,
              (int)&v121,
              v12[11],
              v140,
              v135,
              v137,
              v118,
              v124);
      if ( v23 != 260 )
        goto LABEL_40;
      CmpUnlockTwoKcbs(v116, v117);
      v40 = v120[0];
      v13 = v132;
      v26 = 0;
      v25 = 0;
      v115 = v120[0];
      v116 = 0;
      v117 = 0;
      if ( v132 != -1 )
      {
        CmpUnlockHashEntryByIndex(v120[0], v132);
        v25 = v116;
        v26 = v117;
        v13 = -1;
      }
      if ( !v124[0] )
      {
        v23 = CmpGetSymbolicLink(v40, v137, v134, v12, 0);
        if ( v23 >= 0 )
          v23 = 260;
        if ( v118[0] )
          CmpDereferenceKeyControlBlock(v134);
        *v12 &= 0xFFFFFFF7;
        goto LABEL_41;
      }
LABEL_42:
      if ( v12[7] == 2 )
      {
        v41 = (int)v119;
        if ( v127[0] )
        {
          v12[7] = 1;
          v25 = v116;
          v26 = v117;
        }
        goto LABEL_44;
      }
LABEL_43:
      v41 = (int)v119;
      goto LABEL_44;
    }
    v32 = *(_DWORD *)(v24 + 4);
    v33 = v128;
    if ( (v32 & 0x17) == 0 )
    {
      v115 = v120[0];
      goto LABEL_23;
    }
    if ( v128 == v126 )
    {
      if ( (v32 & 0x10) == 0 )
        goto LABEL_103;
      if ( (*v12 & 1) == 0 )
      {
LABEL_121:
        v23 = -1073741772;
        v34 = 2;
        v33 = v128;
        v115 = v120[0];
        v31 = v126;
        v131 = 2;
        goto LABEL_24;
      }
      v83 = *(unsigned int **)(v24 + 40);
      v84 = 0;
      v85 = v83[1];
      v119 = v83;
      if ( (v85 & v28) == 0 && CmpReferenceKeyControlBlock(v83) )
      {
        CmpMarkKcbDeleted(v24);
        CmpDereferenceKeyControlBlockWithLock(v24, 0);
        v115 = v83[5];
        v120[0] = v115;
        v122 = v83[6];
        v123 = v122;
        CmpLockHiveFlusherShared(v115);
        v86 = (*(int (__fastcall **)(int, int, int *))(v115 + 4))(v115, v122, &v136);
        if ( !v86 )
        {
          v40 = v115;
          CmpUnlockHiveFlusher(v115);
          v23 = -1073741670;
LABEL_233:
          v25 = v116;
          v26 = v117;
          goto LABEL_43;
        }
        CmpUpdateKeyNodeAccessBits(v115, v86, v122);
        CmpUnlockHiveFlusher(v115);
        (*(void (__fastcall **)(int, int *))(v115 + 8))(v115, &v136);
        *(_QWORD *)&v87 = *(_QWORD *)a7;
        v121 = __PAIR64__((unsigned int)v88, v87);
        v89 = v87;
        v133 = v87;
        v125 = v88;
        if ( (!v88 || !(_WORD)v87) && KdDebuggerEnabled && !KdDebuggerNotPresent )
          __debugbreak();
        v90 = WORD1(v121);
        if ( *v88 == 92 )
        {
          do
          {
            v89 -= 2;
            ++v88;
            v90 -= 2;
            v106 = (unsigned __int16)*v88;
            HIDWORD(v121) = v88;
            LOWORD(v121) = v89;
            WORD1(v121) = v90;
          }
          while ( v106 == 92 );
          v125 = v88;
          v133 = v121;
        }
        if ( v126 != 1 )
        {
          do
          {
            if ( *v88 == 92 )
            {
              ++v84;
              do
              {
                v89 -= 2;
                ++v88;
                v90 -= 2;
                v91 = (unsigned __int16)*v88;
                HIDWORD(v121) = v88;
                LOWORD(v121) = v89;
                WORD1(v121) = v90;
              }
              while ( v91 == 92 );
              v125 = v88;
            }
            else
            {
              v89 -= 2;
              v90 -= 2;
              ++v88;
              WORD1(v121) = v90;
              HIDWORD(v121) = v88;
              LOWORD(v121) = v89;
            }
          }
          while ( v84 < v126 - 1 );
          v125 = v88;
          v133 = v121;
        }
        CmpUnlockAndLockKcbs(&v116, v24, 0, 0);
        v34 = 1;
        v35 = v122;
        v31 = v126;
        v33 = v128;
        v131 = 1;
        goto LABEL_25;
      }
      v23 = -1073741670;
      v34 = 3;
      v33 = v128;
      v115 = v120[0];
      v31 = v126;
      v131 = 3;
LABEL_24:
      v35 = v123;
      v122 = v123;
LABEL_25:
      v36 = (int)v125;
      goto LABEL_26;
    }
    if ( (v32 & 0x10) != 0 )
      goto LABEL_121;
    if ( (v32 & 1) != 0 )
    {
      if ( v126 - v128 != 1 || (*v12 & 1) == 0 )
        goto LABEL_121;
LABEL_103:
      v33 = v128;
      v115 = v120[0];
      v31 = v126;
LABEL_23:
      v34 = v131;
      goto LABEL_24;
    }
    v148[0] = v129;
    v148[1] = (int)v130;
    if ( CmpGetNextName((__int16 *)v148, (int)&v121, v118) )
    {
      v56 = CmpComputeHashKey(0, &v121);
      if ( (v32 & 2) != 0 )
      {
        v59 = 1;
        v58 = 0;
        v60 = (int *)(v24 + 60);
        goto LABEL_85;
      }
      v57 = *(unsigned int **)(v24 + 60);
      v58 = 0;
      v59 = *v57;
      v60 = (int *)(v57 + 1);
      if ( *v57 )
      {
LABEL_85:
        while ( 1 )
        {
          v62 = *v60++;
          v61 = v62;
          if ( v56 == v62 || !v61 )
            break;
          if ( ++v58 >= v59 )
            goto LABEL_88;
        }
        v35 = v123;
        v36 = HIDWORD(v121);
        v33 = v128;
        v34 = v131;
        v115 = v120[0];
        v31 = v126;
        v122 = v123;
        v125 = (_WORD *)HIDWORD(v121);
        v133 = v121;
      }
      else
      {
LABEL_88:
        v33 = v128;
        if ( v126 - v128 == 1 && (*v12 & 1) != 0 )
        {
          v35 = v123;
          v36 = HIDWORD(v121);
          v115 = v120[0];
          v34 = v131;
          v122 = v123;
          v133 = v121;
          v31 = v126;
          v125 = (_WORD *)HIDWORD(v121);
        }
        else
        {
          v35 = v123;
          v36 = HIDWORD(v121);
          v23 = -1073741772;
          v34 = 2;
          v115 = v120[0];
          v31 = v126;
          v131 = 2;
          v122 = v123;
          v125 = (_WORD *)HIDWORD(v121);
          v133 = v121;
        }
      }
    }
    else
    {
      v35 = v123;
      v36 = HIDWORD(v121);
      v115 = v120[0];
      v23 = -1073741772;
      v34 = 2;
      v33 = v128;
      v133 = v121;
      v31 = v126;
      v131 = 2;
      v122 = v123;
      v125 = (_WORD *)HIDWORD(v121);
    }
LABEL_26:
    v25 = v116;
    v26 = v117;
    if ( v116 && v117 )
    {
      CmpUnlockAndLockKcbs(&v116, *(_DWORD *)(v24 + 40), 0, 0);
      v35 = v122;
      v25 = v116;
      v26 = v117;
      v36 = (int)v125;
      v31 = v126;
      v33 = v128;
      v34 = v131;
    }
    if ( v34 == 2 )
      goto LABEL_92;
    if ( v34 != 1 )
    {
      if ( v34 == 3 )
        goto LABEL_48;
      if ( v33 == v31 && v33 )
        goto LABEL_34;
      if ( (*(_WORD *)(v24 + 106) & 0x10) != 0 )
      {
        if ( CmpGetNextName((__int16 *)&v129, (int)&v121, v118) )
        {
          v130 = (unsigned __int16 *)HIDWORD(v121);
          if ( (unsigned __int16)v129 + (unsigned __int16)v121 > 0xFFFF )
          {
            v23 = -1073741562;
          }
          else
          {
            LOWORD(v129) = v129 + v121;
            if ( HIWORD(v129) + WORD1(v121) <= 0xFFFF )
            {
              HIWORD(v129) += WORD1(v121);
              CmpUnlockTwoKcbs(v25, v26);
              v116 = 0;
              v117 = 0;
              if ( v13 != -1 )
              {
                CmpUnlockHashEntryByIndex(v115, v13);
                v13 = -1;
              }
              v63 = v24;
              v40 = v115;
              v64 = CmpGetSymbolicLink(v115, v137, v63, v12, &v129);
              v41 = (int)v119;
              v23 = v64;
              if ( v64 >= 0 )
              {
                v23 = 260;
                *v12 &= 0xFFFFFFF7;
              }
              v25 = v116;
              v26 = v117;
LABEL_44:
              CmpUnlockTwoKcbs(v25, v26);
              v26 = 0;
              v25 = 0;
              v116 = 0;
              v117 = 0;
              if ( v13 != -1 )
              {
                CmpUnlockHashEntryByIndex(v40, v13);
                v25 = v116;
                v26 = v117;
                v13 = -1;
              }
              if ( v41 )
              {
                CmpDereferenceKeyControlBlock(v41);
                v25 = v116;
                v26 = v117;
              }
LABEL_48:
              v42 = v115;
              goto LABEL_49;
            }
            v23 = -1073741562;
          }
        }
        else
        {
          v23 = -1073741562;
        }
LABEL_92:
        v40 = v115;
        goto LABEL_43;
      }
      v65 = v115;
      CmpLockHiveFlusherShared(v115);
      v66 = v122;
      v67 = (*(int (__fastcall **)(int, int, int *))(v65 + 4))(v65, v122, &v136);
      if ( !v67 )
      {
LABEL_237:
        CmpUnlockHiveFlusher(v65);
LABEL_238:
        v23 = -1073741670;
LABEL_235:
        v25 = v116;
        v26 = v117;
        goto LABEL_92;
      }
      CmpUpdateKeyNodeAccessBits(v115, v67, v66);
      (*(void (__fastcall **)(int, int *))(v115 + 8))(v115, &v136);
      CmpUnlockHiveFlusher(v115);
      v68 = (int)v119;
      while ( 1 )
      {
        v69 = CmpGetNextName((__int16 *)&v129, (int)&v121, v118);
        if ( !(_WORD)v121 )
          break;
        if ( v69 != 1 )
          goto LABEL_247;
        if ( (*(_WORD *)(v24 + 106) & 0x10) != 0 )
        {
          v130 = (unsigned __int16 *)HIDWORD(v121);
          if ( (unsigned __int16)v129 + (unsigned __int16)v121 > 0xFFFF
            || (LOWORD(v129) = v129 + v121, HIWORD(v129) + WORD1(v121) > 0xFFFF) )
          {
            v23 = -1073741562;
            goto LABEL_235;
          }
          HIWORD(v129) += WORD1(v121);
          CmpUnlockTwoKcbs(v116, v117);
          v116 = 0;
          v117 = 0;
          if ( v13 != -1 )
          {
            CmpUnlockHashEntryByIndex(v65, v13);
            v13 = -1;
          }
          v92 = CmpGetSymbolicLink(v65, v137, v24, v12, &v129);
          v40 = v115;
          v23 = v92;
          if ( v92 >= 0 )
          {
            v23 = 260;
            *v12 &= 0xFFFFFFF7;
            v25 = v116;
            v26 = v117;
            goto LABEL_42;
          }
          goto LABEL_233;
        }
        v71 = (*(int (__fastcall **)(int, int, int *))(v65 + 4))(v65, v66, &v136);
        if ( !v71 )
          goto LABEL_238;
        v23 = CmpFindSubKeyByNameWithStatus(v65, v71, &v121, &v149);
        (*(void (__fastcall **)(int, int *))(v65 + 8))(v65, &v136);
        if ( v23 < 0 )
        {
          if ( v23 != -1073741772 )
          {
            v40 = v115;
            goto LABEL_41;
          }
          if ( v118[0] == 1 && (*v12 & 1) != 0 )
          {
            v36 = HIDWORD(v121);
            v79 = v121;
            v25 = v116;
            v26 = v117;
            v125 = (_WORD *)HIDWORD(v121);
            v133 = v121;
            goto LABEL_148;
          }
          v41 = CmpAddInfoAfterParseFailure(v65, v122, &v116, v24, &v121);
          v23 = -1073741772;
          __dmb(0xBu);
          do
            v76 = __ldrexd(&qword_920988[2]);
          while ( __strexd(v76 + 1, &qword_920988[2]) );
          __dmb(0xBu);
          v25 = v116;
          v26 = v117;
          v40 = v115;
          goto LABEL_44;
        }
        v72 = v149;
        v123 = v149;
        CmpLockHiveFlusherShared(v65);
        v73 = (*(int (__fastcall **)(int, int, int *))(v65 + 4))(v65, v72, &v136);
        if ( !v73 )
          goto LABEL_237;
        CmpUpdateKeyNodeAccessBits(v65, v73, v72);
        (*(void (__fastcall **)(int, int *))(v65 + 8))(v65, &v136);
        CmpUnlockHiveFlusher(v65);
        if ( v118[0] == 1 )
        {
          v23 = CmpStepThroughExit(v120, &v123, v74, 1);
          if ( v23 < 0 )
            goto LABEL_236;
          __dmb(0xBu);
          do
            v75 = __ldrexd(&qword_920988[1]);
          while ( __strexd(v75 + 1, &qword_920988[1]) );
          __dmb(0xBu);
          v35 = v123;
          v37 = 0;
          goto LABEL_37;
        }
        v23 = CmpStepThroughExit(v120, &v123, v74, (unsigned __int8)v118[0]);
        if ( v23 < 0 )
          goto LABEL_236;
        v65 = v120[0];
        v122 = v123;
        v115 = v120[0];
        v24 = CmpCreateKeyControlBlock(v120[0], v123, v68, 2, &v121);
        v134 = (_DWORD *)v24;
        if ( !v24 )
          goto LABEL_238;
        CmpDereferenceKeyControlBlockWithLock(v68, 0);
        CmpUnlockAndLockKcbs(&v116, v68, v24, 0);
        v68 = v24;
        v143 = ++v128;
        v119 = (unsigned int *)v24;
        v77 = v13;
        v78 = CmpGetConvKeyAtIndex((int)v153, (int)v139, v128);
        v13 = ((101027 * (v78 ^ (v78 >> 9))) ^ ((101027 * (v78 ^ (v78 >> 9))) >> 9)) & (*(_DWORD *)(v65 + 1848) - 1);
        v132 = v13;
        if ( v77 != v13 )
        {
          if ( v77 != -1 )
            CmpUnlockHashEntryByIndex(v65, v77);
          CmpUnlockKcb((_DWORD *)v24);
          CmpLockHashEntryByIndexExclusive(v65, v13);
          CmpLockKcbExclusive(v24);
          if ( (*(_DWORD *)(v24 + 4) & 0x20000) != 0 )
          {
            v23 = -1073741772;
            goto LABEL_235;
          }
        }
        v66 = v122;
      }
      if ( v69 != 1 || v118[0] != 1 )
      {
LABEL_247:
        v23 = -1073741811;
        goto LABEL_235;
      }
      v23 = CmpStepThroughExit(v120, &v123, v70, 1);
      if ( v23 < 0 )
        goto LABEL_236;
      v23 = CmpDoOpen(
              v120,
              v123,
              (int)v138,
              v141,
              a5,
              v12,
              6,
              &v116,
              &v132,
              (int *)&v134,
              (int)&v121,
              v12[11],
              v140,
              v135,
              v137,
              0,
              0);
      if ( v23 == 260 )
      {
        if ( !v12[11] )
        {
          v108 = v134[5];
          if ( (*(_DWORD *)(v108 + 3228) & 1) != 0 )
            v12[11] = v108;
        }
        v40 = v120[0];
        v13 = v132;
        *v12 &= 0xFFFFFFF7;
        v25 = v116;
        v26 = v117;
        v115 = v40;
        goto LABEL_42;
      }
LABEL_40:
      v40 = v120[0];
      v13 = v132;
      v115 = v120[0];
      goto LABEL_41;
    }
    v79 = v133;
LABEL_148:
    if ( (*v12 & 2) != 0 )
    {
      v81 = CmpCreateLinkNode(v115, v122, (int)v138, v79, v36, v141, a5, v12, &v116, &v132, v119, v140, v135);
      v13 = v132;
      v23 = v81;
      *v12 &= 0xFFFFFFF7;
LABEL_151:
      v40 = v115;
      if ( v23 != 260 )
        v12[7] = 1;
LABEL_41:
      v25 = v116;
      v26 = v117;
      if ( v23 >= 0 )
        goto LABEL_42;
      goto LABEL_43;
    }
    v40 = v115;
    if ( (void *)v115 == CmpMasterHive && CmpNoMasterCreates == 1 )
    {
      v23 = -1073741811;
      goto LABEL_43;
    }
    v80 = (int)v119;
    v23 = CmpDoCreate(v115, v122, v138, &v121, v141, v12, &v116, v119, v12[11], v135, &v140, v137);
    if ( v23 != -1073741739 )
      goto LABEL_151;
    CmpUnlockTwoKcbs(v116, v117);
    if ( v13 != -1 )
    {
      CmpUnlockHashEntryByIndex(v115, v13);
      v13 = -1;
      v132 = -1;
    }
    CmpDereferenceKeyControlBlock(v80);
    v107 = v142;
    if ( v142 )
      v107 = CmpDereferenceKeyControlBlock(v142);
    CmpUnlockRegistry(v107);
    v116 = 0;
    v117 = 0;
    v142 = 0;
    v10 = v147;
    v20 = a5;
    v129 = *(_DWORD *)a7;
    v130 = (unsigned __int16 *)*((_DWORD *)a7 + 1);
    *v12 = v146[0];
  }
  v42 = v120[0];
  v25 = v116;
  v26 = v117;
LABEL_49:
  CmpUnlockTwoKcbs(v25, v26);
  if ( v13 != -1 )
    CmpUnlockHashEntryByIndex(v42, v13);
  if ( v23 >= 0 )
  {
    v43 = v12[14];
    if ( v43 )
    {
      if ( (v43 & 2) != 0 )
        CmpSearchKeyControlBlockTree(CmpSyncKcbCacheForHive, v12[16], 0);
    }
  }
  v44 = v142;
  if ( v142 )
    v44 = CmpDereferenceKeyControlBlock(v142);
  CmpUnlockRegistry(v44);
  v46 = v12[14];
  if ( v46 && (v46 & 4) != 0 )
  {
    CmpRollbackTransactionArray(v12[17], v12[18], 0, &v150);
    v109 = v12[14];
    v47 = 0;
    v12[17] = 0;
    v12[18] = 0;
    v12[14] = v109 & 0xFFFFFFFB;
  }
  else
  {
    v47 = 0;
  }
  if ( (*v12 & 0x100) != 0 )
  {
    KeWaitForSingleObject((unsigned int)&unk_60E7C0 + 96 * v12[19], 0, 0, 0, 0);
    *v12 &= 0xFFFFFEFF;
  }
  if ( CmpCallBackCount && !ExIsResourceAcquiredSharedLite((int)&CmpRegistryLock, v45, v47, CmpCallBackCount) )
  {
    v110 = v138;
    v111 = *v135;
    v152[7] = v138[5];
    v112 = (*v12 & 1) != 0 ? CmPostCallbackNotification(27, v111, v23, &v151, v144) : CmPostCallbackNotification(
                                                                                        29,
                                                                                        v111,
                                                                                        v23,
                                                                                        &v151,
                                                                                        v144);
    v23 = v112;
    if ( v112 >= 0 )
    {
      v113 = v152[7];
      if ( v152[7] != v110[5] )
      {
        v114 = v110[6];
        v110[5] = v152[7];
        v110[4] = v114 & ~(v113 | 0x2000000);
      }
    }
  }
  if ( v139 )
    CmpFreeExtraHashInfo(v139);
  v48 = (int)v145;
  if ( v145 )
    v48 = ExFreePoolWithTag((unsigned int)v145);
  v49 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v50 = *(_WORD *)(v49 + 0x134) + 1;
  *(_WORD *)(v49 + 308) = v50;
  if ( !v50 && *(_DWORD *)(v49 + 100) != v49 + 100 && !*(_WORD *)(v49 + 310) )
    KiCheckForKernelApcDelivery(v48);
  return v23;
}
