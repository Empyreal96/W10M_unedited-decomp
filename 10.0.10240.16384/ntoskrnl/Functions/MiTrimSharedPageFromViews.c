// MiTrimSharedPageFromViews 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiTrimSharedPageFromViews(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r3
  unsigned int v6; // r9
  unsigned int *v7; // r4
  int v8; // r2
  int v9; // r5 OVERLAPPED
  unsigned int v10; // r6 OVERLAPPED
  unsigned int v11; // r7
  unsigned int v12; // r8
  char *v13; // r10
  int v14; // r9
  _DWORD *v15; // r10
  unsigned int v16; // r5
  unsigned int v17; // r7
  unsigned int v18; // kr10_4
  unsigned int v19; // r9
  int v20; // r6
  int v21; // r2
  int v22; // r8
  unsigned int v23; // r2
  unsigned __int8 *v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  int v29; // r2
  int v30; // r1
  unsigned int v31; // r2
  __int64 v32; // kr20_8
  int v33; // r3
  _DWORD *v34; // r0
  _DWORD *v35; // r2
  _DWORD *v36; // t1
  int v37; // r1
  int v38; // lr
  int v39; // r0
  unsigned int *v40; // r7
  unsigned int v41; // r1
  int v42; // r4
  int v43; // r1
  _DWORD *v44; // r2
  int v45; // r3
  unsigned int v46; // r3
  __int64 v47; // r2
  unsigned int v48; // kr28_4
  int v49; // r5
  int v50; // r8
  _DWORD *v51; // r4
  unsigned int v52; // r0
  int v53; // r6
  _DWORD *v54; // r5
  int v56; // r0
  int v57; // r3
  int v58; // r1
  __int64 v59; // r0
  _DWORD *v60; // r4
  int v61; // r0
  unsigned __int8 *v62; // r5
  int v63; // r0
  int v64; // r4
  unsigned int v65; // r2
  _DWORD *v66; // r4
  int v67; // r0
  unsigned int *v68; // r4
  unsigned int v69; // r1
  int v70; // r0
  int v71; // r3
  int v72; // r3
  unsigned int *v73; // r4
  unsigned int v74; // r1
  int v75; // r0
  __int16 v76; // r3
  unsigned int v77; // r1
  unsigned int v78; // r2
  int i; // r3
  int v80; // r2
  int v81; // r3
  int v82; // r4
  int v83; // r0
  int v84; // r0
  int v85; // r6
  int v86; // r7
  int v87; // r4
  int *v88; // [sp+0h] [bp-138h]
  int v89; // [sp+4h] [bp-134h]
  int v90; // [sp+8h] [bp-130h]
  unsigned __int8 v91; // [sp+Ch] [bp-12Ch] BYREF
  char v92[3]; // [sp+Dh] [bp-12Bh] BYREF
  unsigned int v93; // [sp+10h] [bp-128h]
  unsigned __int64 v94; // [sp+14h] [bp-124h]
  int v95; // [sp+1Ch] [bp-11Ch]
  int v96; // [sp+20h] [bp-118h]
  int v97; // [sp+24h] [bp-114h]
  int v98; // [sp+28h] [bp-110h]
  _DWORD *v99; // [sp+2Ch] [bp-10Ch] BYREF
  int v100; // [sp+30h] [bp-108h]
  int v101; // [sp+34h] [bp-104h]
  char *v102; // [sp+38h] [bp-100h]
  int v103; // [sp+3Ch] [bp-FCh]
  int v104; // [sp+40h] [bp-F8h]
  _DWORD *v105; // [sp+44h] [bp-F4h]
  _DWORD *v106; // [sp+48h] [bp-F0h]
  int v107; // [sp+4Ch] [bp-ECh]
  unsigned int v108; // [sp+50h] [bp-E8h]
  int v109; // [sp+54h] [bp-E4h]
  int v110; // [sp+58h] [bp-E0h]
  unsigned int v111; // [sp+5Ch] [bp-DCh]
  unsigned int v112; // [sp+60h] [bp-D8h]
  unsigned int v113; // [sp+64h] [bp-D4h]
  _DWORD v114[4]; // [sp+68h] [bp-D0h] BYREF
  int v115[34]; // [sp+78h] [bp-C0h] BYREF
  char v116[56]; // [sp+100h] [bp-38h] BYREF

  v101 = a3;
  v97 = a4;
  v104 = a2;
  v105 = a5;
  v5 = a1;
  __dmb(0xBu);
  v114[0] = 0;
  v114[1] = 0;
  v114[2] = 0;
  v96 = 17;
  v92[0] = 17;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = 0;
  v8 = 0;
  v88 = 0;
  v89 = 0;
  v111 = v6;
  v98 = 0;
  if ( !a1 )
    return v8;
  v108 = 0x80000000;
  while ( 2 )
  {
    v100 = v5;
    *(_QWORD *)&v9 = *(_QWORD *)(v5 + 4);
    v106 = *(_DWORD **)v5;
    v103 = 0;
    v11 = *(_DWORD *)(v5 + 16);
    v12 = *(_DWORD *)(v5 + 20);
    v13 = 0;
    v112 = *(_DWORD *)(v5 + 12);
    v110 = 0;
    v107 = 0;
    v90 = v9;
    v102 = 0;
    v95 = 0;
    v115[0] = 0;
    if ( v9 && v9 != *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
    {
      KeAcquireInStackQueuedSpinLock(&dword_634980, v114);
      v14 = MiPrepareAttachThread(v9, v9 + 492);
      v110 = v14;
      KeReleaseInStackQueuedSpinLock(v114);
      if ( !v14 )
        goto LABEL_40;
      KiStackAttachProcess(v9, 1, v116);
      goto LABEL_7;
    }
    if ( *(_DWORD *)(v5 + 28) < 2u )
    {
LABEL_7:
      v15 = 0;
      v18 = v11 - 4096;
      v17 = (__PAIR64__(v12, v11) - 4096) >> 32;
      v16 = v18;
      v19 = v10 - 4096;
      v7 = 0;
      v20 = v95;
      v21 = v19 >> 12;
      v88 = 0;
LABEL_8:
      v22 = v89;
      while ( 1 )
      {
        v19 += 4096;
        while ( 1 )
        {
          if ( v19 >= v112 )
            goto LABEL_39;
          v23 = v21 + 1;
          v17 = (__PAIR64__(v17, v16) + 4096) >> 32;
          v16 += 4096;
          v94 = __PAIR64__(v17, v16);
          v93 = v23;
          if ( !v90 )
            break;
          v7 = (unsigned int *)(v90 + 492);
          v109 = 0;
          v9 = v90;
          v88 = (int *)(v90 + 492);
          if ( !v22 )
          {
            v22 = 1;
            v89 = 1;
            v96 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
            }
            else
            {
              v24 = (unsigned __int8 *)(v90 + 495);
              do
                v25 = __ldrex(v24);
              while ( __strex(v25 | 0x80, v24) );
              __dmb(0xBu);
              if ( v25 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire(v7);
              v26 = v108;
              while ( 1 )
              {
                v27 = *v7;
                if ( (*v7 & 0xBFFFFFFF) == v26 )
                  break;
                if ( (v27 & 0x40000000) == 0 )
                {
                  do
                    v77 = __ldrex(v7);
                  while ( v77 == v27 && __strex(v27 | 0x40000000, v7) );
                  __dmb(0xBu);
                  v26 = 0x80000000;
                }
                __dmb(0xAu);
                __yield();
              }
              v22 = 1;
            }
            v23 = v93;
            v92[0] = v96;
          }
          if ( v15 && v23 >= v15[3] && v23 <= v15[4] )
          {
            v30 = v97;
          }
          else
          {
            v28 = MiLocateAddress(v19);
            v15 = (_DWORD *)v28;
            if ( !v28 )
              goto LABEL_40;
            v29 = *(_DWORD *)(v28 + 28);
            if ( (v29 & 0x8000) != 0 )
              goto LABEL_40;
            v30 = v97;
            if ( (*(_DWORD *)(v97 + 28) & 0x20) == 0 && (v29 & 7) != 0 )
              goto LABEL_40;
            v99 = *(_DWORD **)(v28 + 44);
            if ( *v99 != v97 )
              goto LABEL_40;
          }
          if ( (*(_DWORD *)(v30 + 28) & 0x20) != 0 )
          {
            v31 = v15[12];
            if ( (unsigned int)v105 < v31 )
              goto LABEL_40;
            v32 = *(_QWORD *)(v15 + 3);
            if ( (unsigned int)v105 >= v31 + 4 * (HIDWORD(v32) - (_DWORD)v32 + 1) )
              goto LABEL_40;
            v16 = v94;
            v19 = ((_DWORD)v32 + ((int)((int)v105 - v31) >> 2)) << 12;
          }
          else
          {
            v58 = MiGetProtoPteAddress(v15, v19 >> 12, 0, &v99);
            if ( !v58 || !v99 )
              goto LABEL_40;
            v59 = MiStartingOffset(v99, v58, -1);
            v16 = v94;
            if ( __PAIR64__(v17, v94) != v59 )
              goto LABEL_39;
          }
          v113 = ((v19 >> 20) & 0xFFC) - 1070596096;
          v33 = 1;
          v34 = v114;
          while ( 1 )
          {
            v36 = (_DWORD *)*--v34;
            v35 = v36;
            --v33;
            v37 = *v36;
            if ( (*v36 & 2) == 0 )
              break;
            if ( !v33 )
            {
              if ( (v37 & 0x400) == 0 )
              {
                v38 = v100;
                goto LABEL_36;
              }
              break;
            }
          }
          v78 = (unsigned int)(v35 + 1);
          for ( i = v33 + 2; i; --i )
            v78 <<= 10;
          v19 = v78;
          v21 = v93;
        }
        v109 = 1;
        if ( v22 != 1 )
          goto LABEL_108;
        if ( (v19 & 0x3FFFFF) == 0 )
          break;
LABEL_61:
        if ( !v7 || v7 == (unsigned int *)1 )
        {
          v7 = 0;
          v88 = 0;
          goto LABEL_39;
        }
        v38 = v100;
        v22 = 1;
        v89 = 1;
        if ( *(_DWORD *)(v100 + 28) )
        {
LABEL_36:
          v39 = v97;
        }
        else
        {
          if ( v19 < dword_63389C )
            goto LABEL_41;
          v43 = (int)(((v19 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2;
          if ( *((_BYTE *)&MiState[2423] + v43) != 8 )
            goto LABEL_41;
          v44 = (_DWORD *)(MiState[v43 + 1032] + 24 * ((v19 >> 18) & 0xF));
          v45 = v44[2];
          __dmb(0xFu);
          if ( !v45 )
            goto LABEL_41;
          v46 = v44[3];
          v99 = (_DWORD *)v46;
          if ( (v46 & 1) != 0 )
          {
            v46 &= 0xFFFFFFFE;
            v99 = (_DWORD *)v46;
          }
          v39 = v97;
          if ( *(_DWORD *)v46 != v97 )
            goto LABEL_41;
          v48 = (v44[4] & 0xFFFC0000) + (v19 & 0x3FFFF);
          LODWORD(v47) = (__PAIR64__(v44[5], v44[4] & 0xFFFC0000) + (v19 & 0x3FFFF)) >> 32;
          HIDWORD(v47) = v48;
          if ( v47 != __PAIR64__(v16, v17) )
            goto LABEL_41;
        }
        v40 = (unsigned int *)(((v19 >> 10) & 0x3FFFFC) - 0x40000000);
        v41 = *v40;
        v21 = v93;
        if ( (*v40 & 2) == 0 )
          goto LABEL_38;
        v49 = MmPfnDatabase + 24 * (v41 >> 12);
        v50 = v101 & 0x10000000;
        if ( (v101 & 0x10000000) != 0 )
        {
          v21 = v93;
          if ( (v41 & 0x200) == 0 )
            goto LABEL_118;
          v21 = v93;
          if ( (*(_BYTE *)(v49 + 18) & 0x10) != 0 )
            goto LABEL_118;
        }
        if ( (*(_DWORD *)(v49 + 20) & 0x8000000) == 0 )
        {
          v21 = v93;
LABEL_118:
          v17 = HIDWORD(v94);
          v16 = v94;
          goto LABEL_8;
        }
        if ( (*(_DWORD *)(v49 + 8) & 0x400) == 0 )
        {
          v21 = v93;
          if ( (*(_DWORD *)(v39 + 28) & 0x80) != 0 )
            goto LABEL_118;
        }
        if ( *(_DWORD *)(v38 + 28) == 3 )
        {
          v21 = v93;
          if ( !*(_DWORD *)v49 )
          {
            v16 = v94;
            v22 = v89;
LABEL_38:
            v17 = HIDWORD(v94);
            continue;
          }
          v21 = v93;
          if ( (*(_BYTE *)(v49 + 19) & 8) != 0 )
            goto LABEL_118;
        }
        v51 = (_DWORD *)v7[23];
        v52 = MiLocateWsle(v19, v88, *(_DWORD *)v49);
        v53 = v52;
        if ( v52 < v51[1] || (v101 & 0x1000000) != 0 )
        {
          if ( v50 )
            goto LABEL_153;
          v7 = (unsigned int *)v88;
          if ( v104
            && v88 != &dword_634E00
            && (*(_DWORD *)(v49 + 12) & 0x3FFFFFFF) == 1
            && *(_WORD *)(v49 + 16) == 1
            && MiCanPageMove(v49) )
          {
            v91 = 17;
            v82 = (v49 - MmPfnDatabase) / 24;
            v83 = MiPageToNode(v82, 0);
            v84 = MiGetPage(&MiSystemPartition, (v83 << byte_6337F5) | dword_633814 & v82, 0);
            if ( v84 != -1 )
            {
              v85 = 3 * v84;
              v86 = MmPfnDatabase;
              v87 = MiLockProtoPoolPage(*(_DWORD *)(v49 + 4) | v108, &v91);
              if ( v87 )
              {
                if ( MiTradeActivePage(v49, v86 + 8 * v85, v19, v109) )
                {
                  MiUnlockProtoPoolPage(v87, v91);
                  *(_DWORD *)(v49 + 8) = 128;
                  MiReleaseFreshPage(v49);
                  v7 = (unsigned int *)v88;
LABEL_126:
                  v20 = v95;
LABEL_127:
                  v21 = v93;
                  goto LABEL_118;
                }
                MiUnlockProtoPoolPage(v87, v91);
              }
              MiReleaseFreshPage(v86 + 8 * v85);
            }
LABEL_153:
            v7 = (unsigned int *)v88;
          }
          v98 = 277;
          goto LABEL_126;
        }
        if ( dword_634484 && (*v40 & 0x10) != 0 )
        {
          v80 = v51[9] * v52;
          v81 = v51[63];
          v7 = (unsigned int *)v88;
          if ( (*(_DWORD *)(v80 + v81) & 0xE00) != 3584 )
            MiLogPageAccess(v88, ((v19 >> 10) & 0x3FFFFC) - 0x40000000);
        }
        else
        {
          v7 = (unsigned int *)v88;
        }
        v17 = HIDWORD(v94);
        v16 = v94;
        v115[v95 + 1] = v53;
        v21 = v93;
        v22 = v89;
        v20 = ++v115[0];
        v95 = v115[0];
        if ( v115[0] == 32 )
        {
          if ( MiFreeWsleList(v7, v115, 0) )
            v98 = 277;
          v20 = 0;
          v95 = 0;
          v115[0] = 0;
          goto LABEL_127;
        }
      }
      if ( v20 )
      {
        if ( MiFreeWsleList(v7, v115, 0) )
          v98 = 277;
        v20 = 0;
        v95 = 0;
        v115[0] = 0;
      }
      MiUnlockWorkingSetExclusive(v7, v96);
      v89 = 0;
LABEL_108:
      v7 = (unsigned int *)MiAcquireProperVm(v19, v92);
      v88 = (int *)v7;
      v96 = (unsigned __int8)v92[0];
      goto LABEL_61;
    }
    v56 = *(_DWORD *)(v5 + 24);
    if ( v56 == -1 )
    {
      v13 = algn_632F64;
      v102 = algn_632F64;
    }
    else if ( v56 != -2 )
    {
      return sub_512068(v56, MiState, 4092);
    }
    if ( *(_DWORD *)(v5 + 28) == 3 )
    {
      if ( *(_DWORD *)(v5 + 24) == -2 )
      {
        if ( v10 < dword_63389C )
          goto LABEL_7;
        v57 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((v10 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v57 != 1 && v57 != 11 )
          goto LABEL_7;
      }
      else if ( v10 >= dword_63389C )
      {
        v72 = *((unsigned __int8 *)&MiState[2423]
              + ((int)(((v10 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
        if ( v72 == 1 || v72 == 11 )
          goto LABEL_7;
      }
      goto LABEL_40;
    }
    if ( (v101 & 0x140000) != 0 )
      goto LABEL_40;
    --*(_WORD *)(v6 + 310);
    v62 = (unsigned __int8 *)*((_DWORD *)v13 + 1);
    v63 = KeAbPreAcquire(v62, 0, 0);
    v64 = v63;
    do
      v65 = __ldrex(v62);
    while ( __strex(v65 | 1, v62) );
    __dmb(0xBu);
    if ( (v65 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v62, v63, v62);
    if ( v64 )
      *(_BYTE *)(v64 + 14) |= 1u;
    v66 = (_DWORD *)*((_DWORD *)v13 + 2);
    if ( !v66 )
      goto LABEL_161;
    while ( 1 )
    {
      v67 = MiSystemViewCompareVa(v10, v66);
      if ( v67 >= 0 )
        break;
      v66 = (_DWORD *)*v66;
LABEL_138:
      if ( !v66 )
        goto LABEL_142;
    }
    if ( v67 > 0 )
    {
      v66 = (_DWORD *)v66[1];
      goto LABEL_138;
    }
LABEL_142:
    if ( !v66 )
      goto LABEL_161;
    if ( v97 == (v66[8] & 0xFFFFFFF8) )
    {
      if ( (v66[4] << 12) - v11 + v10 == (v66[12] & 0xFFFFF000) )
      {
        v107 = 1;
        goto LABEL_7;
      }
LABEL_161:
      v73 = (unsigned int *)*((_DWORD *)v13 + 1);
      __dmb(0xBu);
      do
        v74 = __ldrex(v73);
      while ( __strex(v74 - 1, v73) );
    }
    else
    {
      v73 = (unsigned int *)*((_DWORD *)v13 + 1);
      __dmb(0xBu);
      do
        v74 = __ldrex(v73);
      while ( __strex(v74 - 1, v73) );
    }
    if ( (v74 & 2) != 0 && (v74 & 4) == 0 )
      ExfTryToWakePushLock(v73);
    v75 = KeAbPostRelease(v73);
    v76 = *(_WORD *)(v6 + 310) + 1;
    *(_WORD *)(v6 + 310) = v76;
    if ( !v76 && *(_DWORD *)(v6 + 100) != v6 + 100 )
      KiCheckForKernelApcDelivery(v75);
    v7 = (unsigned int *)v88;
LABEL_39:
    v9 = v90;
LABEL_40:
    if ( v89 == 1 )
    {
LABEL_41:
      if ( v95 )
      {
        if ( MiFreeWsleList(v7, v115, 0) )
          v98 = 277;
        v115[0] = 0;
      }
      v9 = v90;
      if ( v90 )
      {
        MiUnlockWorkingSetExclusive(v7, v96);
      }
      else if ( v7 )
      {
        MiUnlockWorkingSetExclusive(v7, v96);
        v88 = 0;
      }
      v89 = 0;
    }
    if ( v107 == 1 )
    {
      v68 = (unsigned int *)*((_DWORD *)v102 + 1);
      __dmb(0xBu);
      do
        v69 = __ldrex(v68);
      while ( __strex(v69 - 1, v68) );
      if ( (v69 & 2) != 0 && (v69 & 4) == 0 )
        ExfTryToWakePushLock(v68);
      v70 = KeAbPostRelease(v68);
      v6 = v111;
      v71 = (__int16)(*(_WORD *)(v111 + 310) + 1);
      *(_WORD *)(v111 + 310) = v71;
      if ( !v71 && *(_DWORD *)(v6 + 100) != v6 + 100 )
        KiCheckForKernelApcDelivery(v70);
    }
    else
    {
      v6 = v111;
    }
    v42 = v103;
    if ( v103 )
    {
      MmDetachSession(v103, v116);
      MmQuitNextSession(v42);
    }
    else if ( v110 == 1 )
    {
      KiUnstackDetachProcess(v116, 1);
      MiAttachThreadDone(v9 + 492);
    }
    if ( v9 )
      ObfDereferenceObjectWithTag(v9, 1953261124);
    ExFreePoolWithTag(v100, 0);
    if ( v104 == 1 && (*v105 & 2) == 0 )
    {
      v54 = v106;
      while ( v54 )
      {
        v60 = v54;
        v61 = v54[1];
        v54 = (_DWORD *)*v54;
        if ( v61 )
          ObfDereferenceObjectWithTag(v61, 1953261124);
        ExFreePoolWithTag(v60, 0);
      }
      v8 = 0;
    }
    else
    {
      v5 = (int)v106;
      if ( v106 )
      {
        v7 = (unsigned int *)v88;
        continue;
      }
      v8 = v98;
    }
    return v8;
  }
}
