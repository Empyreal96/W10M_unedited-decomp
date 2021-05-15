// CmRenameKey 
 
int CmRenameKey(int a1, ...)
{
  int v1; // r4
  _DWORD *v2; // r5
  int v3; // r7
  int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r1
  __int16 v7; // r3
  int v8; // r3
  unsigned int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  int v12; // r6
  int v13; // r8
  int v14; // r3
  int v15; // r5
  unsigned int v16; // r9
  int v17; // r3
  void *v18; // r0
  int v19; // r0
  int v20; // r0
  int v21; // r5
  unsigned int v22; // r1
  __int16 v23; // r3
  int v24; // r7
  int v25; // r9
  int v26; // r0
  unsigned int v27; // r1
  unsigned int v28; // r1
  __int16 v29; // r3
  unsigned int *v31; // r0
  unsigned int *v32; // r5
  int *v33; // r1
  int v34; // r2
  int **v35; // r5
  int v36; // r0
  int v37; // r0
  int v38; // r5
  unsigned int **v39; // r2
  unsigned int *v40; // r1
  int v41; // r2
  int *v42; // r1
  int v43; // r2
  int v44; // r0
  int *v45; // r7
  int v46; // r0
  int **v47; // r2
  unsigned int *v48; // r5
  int v49; // r7
  unsigned int *v50; // r5
  int v51; // r9
  int v52; // r3
  unsigned int v53; // r9
  int v54; // r1
  int v55; // r5
  int v56; // r5
  _WORD *v57; // r0
  _WORD *v58; // r5
  int v59; // r7
  _WORD *v60; // r8
  int v61; // t1
  int v62; // r5
  unsigned int v63; // r0
  unsigned int v64; // r9
  __int16 v65; // r3
  int v66; // r3
  int v67; // r10
  unsigned int *v68; // r10
  int v69; // r8
  unsigned int *v70; // r5
  unsigned int v71; // r7
  unsigned int *v72; // r8
  unsigned int v73; // t1
  int v74; // r3
  _DWORD *v75; // r0
  int v76; // r1
  int v77; // r2
  int v78; // r5
  int v79; // r0
  int v80; // r2
  unsigned int *v81; // r5
  unsigned int *v82; // r1
  unsigned int **v83; // r0
  int v84; // r0
  unsigned int **v85; // r1
  unsigned int *v86; // r0
  unsigned int *v87; // r1
  unsigned int *v88; // r1
  unsigned int *v89; // r3
  int v90; // r2
  _DWORD *v91; // r5
  unsigned int *v92; // r6
  unsigned int v93; // r8
  unsigned int *v94; // r9
  unsigned int v95; // r1
  unsigned int *v96; // r7
  unsigned int v97; // r8
  unsigned int *v98; // r10
  unsigned int v99; // t1
  unsigned int *v100; // r4
  unsigned int *v101; // r4
  int v102; // r4
  unsigned int *v103; // r4
  unsigned int v104; // r4
  unsigned int v105; // r1
  unsigned int v106; // r1
  int v107; // r3
  unsigned int *v108; // [sp+10h] [bp-80h]
  int v109; // [sp+14h] [bp-7Ch]
  int v110; // [sp+18h] [bp-78h] BYREF
  int v111; // [sp+1Ch] [bp-74h] BYREF
  int v112; // [sp+20h] [bp-70h] BYREF
  unsigned int *v113; // [sp+24h] [bp-6Ch]
  int v114; // [sp+28h] [bp-68h]
  unsigned int *v115; // [sp+2Ch] [bp-64h]
  int v116; // [sp+30h] [bp-60h] BYREF
  _DWORD *v117; // [sp+34h] [bp-5Ch]
  unsigned int *v118; // [sp+38h] [bp-58h]
  int v119; // [sp+3Ch] [bp-54h]
  int v120; // [sp+40h] [bp-50h] BYREF
  int v121; // [sp+44h] [bp-4Ch] BYREF
  int v122; // [sp+48h] [bp-48h] BYREF
  unsigned int v123; // [sp+4Ch] [bp-44h]
  int *v124; // [sp+50h] [bp-40h]
  unsigned int *v125; // [sp+54h] [bp-3Ch]
  char v126[8]; // [sp+58h] [bp-38h] BYREF
  int v127; // [sp+60h] [bp-30h] BYREF
  int v128; // [sp+64h] [bp-2Ch]
  int v129; // [sp+68h] [bp-28h]
  int v130; // [sp+6Ch] [bp-24h]
  int v131[8]; // [sp+70h] [bp-20h] BYREF
  int varg_r1; // [sp+9Ch] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+9Ch] [bp+Ch]
  int varg_r2; // [sp+A0h] [bp+10h]
  int varg_r3; // [sp+A4h] [bp+14h]
  va_list va1; // [sp+A8h] [bp+18h] BYREF

  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _DWORD);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v1 = 0;
  v120 = -1;
  v121 = -1;
  v119 = -1;
  v114 = -1;
  v131[0] = -1;
  v111 = -1;
  v129 = (char)varg_r3;
  v2 = (_DWORD *)a1;
  v117 = (_DWORD *)a1;
  v118 = 0;
  v108 = 0;
  v109 = 0;
  v127 = 0;
  v124 = 0;
  v125 = 0;
  v113 = 0;
  v115 = 0;
  v122 = 0;
  v3 = 0;
  while ( 1 )
  {
    if ( v3 )
    {
      __pld(&CmpShutdownRundown);
      v4 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v5 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v5 == v4 && __strex(v4 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v5 != v4 )
        v4 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v7 = *(_WORD *)(v6 + 0x134) + 1;
      *(_WORD *)(v6 + 308) = v7;
      if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
        KiCheckForKernelApcDelivery(v4);
    }
    v8 = __mrc(15, 0, 13, 0, 3);
    --*(_WORD *)((v8 & 0xFFFFFFC0) + 0x134);
    __pld(&CmpShutdownRundown);
    v9 = CmpShutdownRundown & 0xFFFFFFFE;
    v10 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
    do
      v11 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v11 == v9 && __strex(v10, (unsigned int *)&CmpShutdownRundown) );
    __dmb(0xBu);
    if ( v11 != v9 && !ExfAcquireRundownProtection(&CmpShutdownRundown) )
    {
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = *(_WORD *)(v22 + 0x134) + 1;
      *(_WORD *)(v22 + 308) = v23;
      if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
        KiCheckForKernelApcDelivery(0);
      return -1073741431;
    }
    v12 = v2[1];
    v13 = 0;
    v3 = 1;
    v130 = 0;
    v116 = 0;
    if ( CmRmIsKCBDeleted(v12, 0) == 1 )
      goto LABEL_175;
    v14 = v2[7];
    if ( v14 || v2[8] )
    {
      v15 = CmpSearchAddTrans((int)v2, 0, 0, v14, v2[8], 0, &v116);
      if ( v15 < 0 )
        goto LABEL_47;
      v13 = v116;
      v2 = v117;
      v130 = v116;
    }
    if ( CmRmIsKCBDeleted(v12, v13) == 1 )
    {
LABEL_175:
      v25 = 0;
      if ( (v2[6] & 1) != 0 )
        v15 = -1073740763;
      else
        v15 = -1073741444;
      goto LABEL_48;
    }
    v16 = *(_DWORD *)(v12 + 24);
    v1 = *(_DWORD *)(v12 + 20);
    v116 = v16 >> 31;
    v123 = v16;
    if ( (void *)v1 == CmpMasterHive
      || (v17 = *(_DWORD *)(v12 + 40)) == 0
      || (v18 = *(void **)(v17 + 20), v18 == CmpMasterHive) )
    {
      v15 = -1073741790;
LABEL_47:
      v25 = 0;
LABEL_48:
      __pld(&CmpShutdownRundown);
      v26 = CmpShutdownRundown & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
      while ( v27 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
      if ( v27 != v26 )
        v26 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
      v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v29 = *(_WORD *)(v28 + 0x134) + 1;
      *(_WORD *)(v28 + 308) = v29;
      if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
        KiCheckForKernelApcDelivery(v26);
      if ( v25 )
        (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v121);
      if ( v108 )
        (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v120);
      return v15;
    }
    v15 = CmpCheckKeyAccess(v18, *(_DWORD *)(v17 + 24), v129, 4);
    if ( v15 < 0 )
      goto LABEL_47;
    v15 = CmpDoAccessCheckOnSubtree(v1, v16, v129);
    if ( v15 < 0 )
      goto LABEL_47;
    v19 = CmpReportNotify(v12, (void (__fastcall **)(void *, int *))v1, v16, v13, 1, 0);
    if ( v13 )
      break;
    if ( CmpTryAcquireIXLockExclusive((_DWORD *)(v12 + 128)) )
    {
      if ( !CmpTryAcquireIXLockExclusive((_DWORD *)(v12 + 136)) )
      {
        v20 = v12 + 136;
        goto LABEL_31;
      }
      v21 = *(_DWORD *)(v12 + 40);
      if ( !CmpTryAcquireIXLockExclusive((_DWORD *)(v21 + 128)) )
      {
        v20 = v21 + 128;
        goto LABEL_31;
      }
      if ( !CmpTryAcquireIXLockExclusive((_DWORD *)(v21 + 136)) )
      {
        v20 = v21 + 136;
        goto LABEL_31;
      }
      v49 = v16 >> 31;
LABEL_78:
      v31 = (unsigned int *)(*(int (__fastcall **)(int, unsigned int, int *))(v1 + 4))(v1, v16, &v121);
      v50 = v31;
      v109 = (int)v31;
      if ( !v31 )
      {
        v15 = -1073741670;
        goto LABEL_156;
      }
      CmpUpdateKeyNodeAccessBits(v1, (int)v31, v16);
      v31 = (unsigned int *)(*(int (__fastcall **)(int, unsigned int, int *))(v1 + 4))(v1, v50[4], &v120);
      v51 = (int)v31;
      v108 = v31;
      if ( !v31 )
      {
        v15 = -1073741670;
LABEL_148:
        if ( v109 )
          v31 = (unsigned int *)(*(int (__fastcall **)(int, int *))(v1 + 8))(v1, &v121);
        if ( v51 )
          v31 = (unsigned int *)(*(int (__fastcall **)(int, int *))(v1 + 8))(v1, &v120);
        if ( v119 != -1 )
          v31 = (unsigned int *)HvFreeCell(v1, v119);
        if ( v124 )
          *(_DWORD *)(v12 + 44) = v124;
        goto LABEL_156;
      }
      CmpUpdateKeyNodeAccessBits(v1, (int)v31, v50[4]);
      v31 = (unsigned int *)CmpFindSubKeyByName(v1, v51, (int)varg_r1a, v52);
      if ( v31 != (unsigned int *)-1 )
      {
        v15 = -1073741535;
        goto LABEL_148;
      }
      v53 = CmpNameSize((unsigned __int16 *)varg_r1a);
      if ( !v13 )
      {
        if ( !HvpMarkCellDirty(v1, v50[4], 0, 0) )
          goto LABEL_86;
        v54 = v50[4];
        v55 = v123;
        if ( !CmpMarkIndexDirty(v1, v54, v123) )
          goto LABEL_86;
        if ( !HvpMarkCellDirty(v1, v55, 0, 0) )
          goto LABEL_86;
        v56 = v108[v49 + 7];
        v114 = v56;
        if ( v56 == -1 || !HvpMarkCellDirty(v1, v56, 0, 0) )
          goto LABEL_86;
        v57 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(v1 + 4))(v1, v56, &v111);
        v58 = v57;
        if ( !v57 )
        {
          v15 = -1073741670;
          goto LABEL_87;
        }
        if ( *v57 == 26994 )
        {
          v59 = 0;
          if ( v57[1] )
          {
            v60 = v57;
            while ( 1 )
            {
              v61 = *((_DWORD *)v60 + 1);
              v60 += 2;
              if ( !HvpMarkCellDirty(v1, v61, 0, 0) )
                break;
              if ( ++v59 >= (unsigned int)(unsigned __int16)v58[1] )
              {
                v13 = v130;
                goto LABEL_100;
              }
            }
            (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v111);
            goto LABEL_86;
          }
LABEL_100:
          v49 = v116;
        }
        (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v111);
      }
      v119 = HvAllocateCell(v1, v53 + 76);
      if ( v119 != -1 )
      {
        v62 = v127;
        memmove(v127, v109, 0x4Cu);
        v63 = CmpCopyName(v62 + 76, (unsigned __int16 *)varg_r1a);
        *(_WORD *)(v62 + 72) = v63;
        v64 = (unsigned __int16)varg_r1;
        if ( v63 >= (unsigned __int16)varg_r1 )
          v65 = *(_WORD *)(v62 + 2) & 0xFFDF;
        else
          v65 = *(_WORD *)(v62 + 2) | 0x20;
        *(_WORD *)(v62 + 2) = v65;
        KeQuerySystemTime(&v127);
        v67 = v127;
        v66 = v128;
        *(_DWORD *)(v62 + 4) = v127;
        *(_DWORD *)(v62 + 8) = v66;
        (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, v131);
        if ( v13 )
        {
          (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v120);
          v68 = 0;
          v108 = 0;
          (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v121);
          v25 = 0;
          v109 = 0;
          v31 = (unsigned int *)CmpCreateKeyControlBlock(
                                  __SPAIR64__(v119, v1),
                                  *(unsigned int **)(v12 + 40),
                                  0,
                                  (unsigned __int16 *)varg_r1a);
          v81 = v31;
          v125 = v31;
          if ( v31 )
          {
            v31 = (unsigned int *)CmpAllocateUnitOfWork(v31);
            v115 = v31;
            if ( v31 )
            {
              v82 = v31 + 4;
              v83 = (unsigned int **)v81[28];
              *v82 = (unsigned int)(v81 + 27);
              v82[1] = (unsigned int)v83;
              if ( *v83 != v81 + 27 )
                __fastfail(3u);
              *v83 = v82;
              v81[28] = (unsigned int)v82;
              v84 = CmpReferenceKeyControlBlock(v81);
              v115[6] = (unsigned int)v81;
              LOCK_TRANSACTION_LIST(v84);
              v85 = *(unsigned int ***)(v13 + 12);
              v86 = v115;
              *v115 = v13 + 8;
              v86[1] = (unsigned int)v85;
              if ( *v85 != (unsigned int *)(v13 + 8) )
                __fastfail(3u);
              *v85 = v86;
              *(_DWORD *)(v13 + 12) = v86;
              UNLOCK_TRANSACTION_LIST(v86);
              v87 = v115;
              v115[7] = v13;
              CmpLockIXLockExclusive(v81 + 32, v87, 0);
              CmpLockIXLockExclusive(v81 + 34, v115, 1);
              v88 = v115;
              v89 = v113;
              v90 = (int)v118;
              v81[31] = v13;
              v88[12] = v12;
              v89[12] = v12;
              *(_DWORD *)(v90 + 48) = v81;
              v89[13] = (unsigned int)v81;
              v89[9] = 10;
              *(_DWORD *)(v90 + 36) = 11;
              v88[9] = 12;
              v88[10] = v123 >> 31;
              v31 = (unsigned int *)CmAddLogForAction(v90);
              v15 = (int)v31;
              if ( (int)v31 >= 0 )
              {
                CmpDereferenceKeyControlBlockWithLock(v12, 1);
                v91 = v117;
                DelistKeyBodyFromKCB(v117, 1);
                v92 = v125;
                v91[1] = v125;
                EnlistKeyBodyWithKCB(v91, 2);
                CmpUnlockKcb(v92);
LABEL_133:
                v15 = 0;
                goto LABEL_48;
              }
LABEL_137:
              v93 = v114;
              if ( v114 != -1 )
              {
                v94 = &v68[v49];
                v95 = v94[7];
                if ( v95 != -1 )
                {
                  v31 = (unsigned int *)(*(int (__fastcall **)(int, unsigned int, int *))(v1 + 4))(v1, v95, &v111);
                  v96 = v31;
                  if ( v31 )
                  {
                    if ( *(_WORD *)v31 == 26994 )
                    {
                      v97 = 0;
                      if ( *((_WORD *)v31 + 1) )
                      {
                        v98 = v31;
                        do
                        {
                          v99 = v98[1];
                          ++v98;
                          HvFreeCell(v1, v99);
                          ++v97;
                        }
                        while ( v97 < *((unsigned __int16 *)v96 + 1) );
                      }
                      v93 = v114;
                    }
                    (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v111);
                    v31 = (unsigned int *)HvFreeCell(v1, v94[7]);
                  }
                }
                v94[7] = v93;
              }
              v51 = (int)v108;
              goto LABEL_148;
            }
          }
        }
        else
        {
          v31 = (unsigned int *)CmpDuplicateIndex(v1, v114, v49);
          v108[v49 + 7] = (unsigned int)v31;
          if ( v31 != (unsigned int *)-1 )
          {
            v69 = v119;
            v31 = (unsigned int *)CmpAddSubKeyEx(v1, *(_DWORD *)(v109 + 16), v119, 0);
            if ( v31 )
            {
              v31 = (unsigned int *)CmpRemoveSubKey(v1, *(_DWORD *)(v109 + 16), v123);
              if ( v31 )
              {
                v124 = *(int **)(v12 + 44);
                v31 = (unsigned int *)CmpGetNameControlBlock((unsigned __int16 *)varg_r1a, v126);
                *(_DWORD *)(v12 + 44) = v31;
                if ( v31 )
                {
                  v31 = (unsigned int *)CmpUpdateParentForEachSon(v1, v69);
                  if ( v31 )
                  {
                    v31 = (unsigned int *)(*(int (__fastcall **)(int, int, int *))(v1 + 4))(v1, v114, &v111);
                    v70 = v31;
                    if ( v31 )
                    {
                      if ( *(_WORD *)v31 == 26994 )
                      {
                        v71 = 0;
                        if ( *((_WORD *)v31 + 1) )
                        {
                          v72 = v31;
                          do
                          {
                            v73 = v72[1];
                            ++v72;
                            HvFreeCell(v1, v73);
                            ++v71;
                          }
                          while ( v71 < *((unsigned __int16 *)v70 + 1) );
                          v69 = v119;
                        }
                      }
                      (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v111);
                      HvFreeCell(v1, v114);
                      HvFreeCell(v1, v123);
                      v74 = v128;
                      v75 = *(_DWORD **)(v12 + 40);
                      *(_DWORD *)(v12 + 24) = v69;
                      *(_DWORD *)(v12 + 88) = v67;
                      *(_DWORD *)(v12 + 92) = v74;
                      CmpCleanUpSubKeyInfo(v75, v76, v77, v74);
                      if ( *((unsigned __int16 *)v108 + 26) < v64 )
                      {
                        *((_WORD *)v108 + 26) = v64;
                        *(_WORD *)(*(_DWORD *)(v12 + 40) + 96) = v64;
                      }
                      v78 = CmpComputeKcbConvKey(v12);
                      if ( v78 != *(_DWORD *)(v12 + 12) )
                      {
                        CmpRemoveKeyHash(*(_DWORD *)(v12 + 20), (_DWORD *)(v12 + 12));
                        v79 = *(_DWORD *)(v12 + 20);
                        *(_DWORD *)(v12 + 12) = v78;
                        CmpInsertKeyHash(v79, v12 + 12, 0);
                      }
                      (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v120);
                      v108 = 0;
                      (*(void (__fastcall **)(int, int *))(v1 + 8))(v1, &v121);
                      v25 = 0;
                      CmpSearchForOpenSubKeys(v12, 3, v80, 0);
                      CmpDereferenceNameControlBlockWithLock(v124);
                      goto LABEL_133;
                    }
                  }
                }
              }
            }
          }
          v68 = v108;
        }
LABEL_136:
        v15 = -1073741670;
        goto LABEL_137;
      }
LABEL_86:
      v15 = -1073741443;
LABEL_87:
      v25 = v109;
      goto LABEL_48;
    }
    v20 = v12 + 128;
LABEL_31:
    v15 = CmpSnapshotTxOwnerArray(v20, &v110, &v112);
    if ( v15 < 0 )
      goto LABEL_47;
    CmpUnlockRegistry();
    v15 = CmpRollbackTransactionArray(v110, v112, 0, &v122);
    CmpLockRegistryExclusive();
    if ( v15 < 0 )
      goto LABEL_47;
    v2 = v117;
  }
  v24 = v12 + 108;
  if ( *(_DWORD *)(v12 + 108) != v12 + 108 )
  {
    v15 = -1072103423;
    goto LABEL_47;
  }
  v31 = (unsigned int *)CmpAllocateUnitOfWork(v19);
  v32 = v31;
  v113 = v31;
  if ( !v31 || (v31 = (unsigned int *)CmpAllocateUnitOfWork(v31), (v118 = v31) == 0) )
  {
    v49 = v116;
    v68 = 0;
    goto LABEL_136;
  }
  v33 = (int *)(v32 + 4);
  v34 = *(_DWORD *)(v12 + 40) + 108;
  v35 = *(int ***)(*(_DWORD *)(v12 + 40) + 112);
  *v33 = v34;
  v33[1] = (int)v35;
  if ( *v35 != (int *)v34 )
    __fastfail(3u);
  *v35 = v33;
  *(_DWORD *)(v34 + 4) = v33;
  v36 = CmpReferenceKeyControlBlock(*(unsigned int **)(v12 + 40));
  v113[6] = *(_DWORD *)(v12 + 40);
  v37 = LOCK_TRANSACTION_LIST(v36);
  v38 = v13 + 8;
  v39 = *(unsigned int ***)(v13 + 12);
  v40 = v113;
  *v113 = v13 + 8;
  v40[1] = (unsigned int)v39;
  if ( *v39 != (unsigned int *)(v13 + 8) )
    __fastfail(3u);
  *v39 = v40;
  *(_DWORD *)(v13 + 12) = v40;
  UNLOCK_TRANSACTION_LIST(v37);
  v113[7] = v13;
  v41 = (int)v118;
  v42 = *(int **)(v12 + 112);
  v118[4] = v24;
  *(_DWORD *)(v41 + 20) = v42;
  v43 = v41 + 16;
  if ( *v42 != v24 )
    __fastfail(3u);
  *v42 = v43;
  *(_DWORD *)(v12 + 112) = v43;
  v44 = CmpReferenceKeyControlBlock((unsigned int *)v12);
  v45 = (int *)v118;
  v118[6] = v12;
  v46 = LOCK_TRANSACTION_LIST(v44);
  v47 = *(int ***)(v13 + 12);
  *v45 = v38;
  v45[1] = (int)v47;
  if ( *v47 != (int *)v38 )
    __fastfail(3u);
  *v47 = v45;
  *(_DWORD *)(v13 + 12) = v45;
  UNLOCK_TRANSACTION_LIST(v46);
  v48 = v113;
  v45[7] = v13;
  v31 = (unsigned int *)CmpLockIXLockExclusive(*(_DWORD *)(v12 + 40) + 128, v48, 0);
  if ( v31 )
  {
    v31 = (unsigned int *)CmpLockIXLockExclusive(*(_DWORD *)(v12 + 40) + 136, v48, 1);
    if ( v31 )
    {
      v31 = (unsigned int *)CmpLockIXLockExclusive(v12 + 128, v45, 0);
      if ( v31 )
      {
        v31 = (unsigned int *)CmpLockIXLockExclusive(v12 + 136, v45, 1);
        if ( v31 )
        {
          v49 = 1;
          v116 = 1;
          goto LABEL_78;
        }
      }
    }
  }
  v15 = -1072103423;
LABEL_156:
  v100 = v113;
  if ( v113 )
  {
    CmpRundownUnitOfWork(v113);
    v31 = (unsigned int *)CmpFreeUnitOfWork(v100);
  }
  v101 = v115;
  if ( v115 )
  {
    CmpRundownUnitOfWork(v115);
    v31 = (unsigned int *)CmpFreeUnitOfWork(v101);
  }
  v102 = (int)v118;
  if ( v118 )
  {
    CmpRundownUnitOfWork(v118);
    v31 = (unsigned int *)CmpFreeUnitOfWork(v102);
  }
  v103 = v125;
  if ( v125 )
  {
    CmpDereferenceKeyControlBlockWithLock((int)v125, 1);
    v31 = (unsigned int *)CmpUnlockKcb(v103);
  }
  __pld(&CmpShutdownRundown);
  v104 = CmpShutdownRundown & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v105 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v105 == v104 && __strex(v104 - 2, (unsigned int *)&CmpShutdownRundown) );
  if ( v105 != v104 )
    v31 = (unsigned int *)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
  v106 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v107 = (__int16)(*(_WORD *)(v106 + 0x134) + 1);
  *(_WORD *)(v106 + 308) = v107;
  if ( !v107 && *(_DWORD *)(v106 + 100) != v106 + 100 && !*(_WORD *)(v106 + 310) )
    KiCheckForKernelApcDelivery((int)v31);
  return v15;
}
