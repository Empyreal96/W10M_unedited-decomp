// MiFinishHardFault 
 
int __fastcall MiFinishHardFault(int a1, int *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r6
  _DWORD *v6; // r9
  int *v7; // r3
  int v8; // r0
  int v9; // r7
  int v10; // r10
  int v11; // r4
  int v12; // r5
  int v13; // r0
  _DWORD *v14; // r8
  int v15; // r2
  int v16; // r4
  int v17; // r0
  int v18; // r3
  __int16 v19; // r3
  int v20; // r0
  int result; // r0
  unsigned __int8 *v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r7
  unsigned int v25; // r0
  int v26; // r3
  unsigned __int8 *v27; // r1
  int v28; // r5
  int v29; // r3
  unsigned __int8 *v30; // r1
  unsigned int v31; // r2
  unsigned int *v32; // r2
  unsigned int v33; // r0
  unsigned int v34; // r7
  unsigned int v35; // r3
  unsigned int v36; // r2
  int v37; // r0
  int v38; // lr
  int v39; // r2
  int *v40; // r1
  unsigned int v41; // r9
  int v42; // r7
  int v43; // r5
  unsigned __int8 *v44; // r3
  unsigned int v45; // r0
  int v46; // r4
  char v47; // r3
  int v48; // r4
  int v49; // r8
  int v50; // r7
  unsigned __int8 v51; // r3
  unsigned int v52; // r3
  unsigned __int8 *v53; // r3
  unsigned int v54; // r1
  int v55; // r7
  char v56; // r3
  unsigned int v57; // r3
  int *v58; // r4
  int v59; // r0
  int v60; // lr
  int v61; // r4
  int v62; // r7
  int *v63; // r1
  unsigned int v64; // r0
  int v65; // r3
  unsigned int *v66; // r2
  unsigned int v67; // r0
  unsigned int v68; // r1
  int v69; // r3
  unsigned int v70; // r2
  unsigned int v71; // r0
  unsigned __int8 *v72; // r1
  int v73; // r2
  int v74; // r3
  unsigned int v75; // r2
  int v76; // r0
  int v77; // r3
  unsigned int v78; // r2
  unsigned int v79; // r3
  int v80; // r3
  int v81; // r4
  int v82; // r0
  unsigned int v83; // r7
  unsigned int v84; // r5
  unsigned int *v85; // r10
  int v86; // r9
  unsigned int v87; // t1
  int v88; // r3
  int v89; // r4
  int v90; // r8
  unsigned __int8 *v91; // r3
  unsigned int v92; // r1
  unsigned __int8 *v93; // r1
  int v94; // r3
  unsigned int v95; // r2
  unsigned int *v96; // r2
  unsigned int v97; // r0
  unsigned int v98; // r4
  int v99; // [sp+8h] [bp-D0h]
  unsigned __int8 v100; // [sp+Ch] [bp-CCh] BYREF
  unsigned int v101; // [sp+10h] [bp-C8h]
  int v102; // [sp+14h] [bp-C4h]
  int v103; // [sp+18h] [bp-C0h]
  int v104; // [sp+1Ch] [bp-BCh]
  int v105; // [sp+20h] [bp-B8h]
  int v106; // [sp+24h] [bp-B4h]
  unsigned int v107; // [sp+28h] [bp-B0h]
  int *v108; // [sp+2Ch] [bp-ACh]
  int v109; // [sp+30h] [bp-A8h]
  int v110; // [sp+34h] [bp-A4h]
  int v111; // [sp+38h] [bp-A0h]
  unsigned int v112; // [sp+3Ch] [bp-9Ch]
  int v113; // [sp+40h] [bp-98h]
  _DWORD *v114; // [sp+44h] [bp-94h]
  int v115; // [sp+48h] [bp-90h]
  __int16 *v116; // [sp+4Ch] [bp-8Ch]
  int v117; // [sp+50h] [bp-88h]
  int v118; // [sp+54h] [bp-84h]
  unsigned int v119; // [sp+58h] [bp-80h]
  int v120; // [sp+5Ch] [bp-7Ch]
  int v121; // [sp+60h] [bp-78h]
  int v122; // [sp+64h] [bp-74h]
  unsigned int v123; // [sp+68h] [bp-70h]
  int v124; // [sp+6Ch] [bp-6Ch]
  int *v125; // [sp+70h] [bp-68h]
  int v126[24]; // [sp+78h] [bp-60h] BYREF

  v113 = a4;
  v5 = a1;
  v6 = (_DWORD *)(a1 + 152);
  v114 = a5;
  v115 = 0;
  v117 = a1 + 152;
  v118 = 0;
  v7 = *(int **)(a1 + 132);
  v8 = *(_DWORD *)(a1 + 144);
  v9 = *(_DWORD *)(v5 + 88);
  v10 = a3;
  v124 = a3;
  v125 = a2;
  v122 = v5;
  v108 = v7;
  if ( v8 )
  {
    v6 = (_DWORD *)v8;
    v117 = v8;
  }
  v11 = v6[5];
  v12 = ((unsigned __int16)v6[6] + (unsigned __int16)v6[4]) & 0xFFF;
  v13 = *(_DWORD *)(v5 + 108);
  v101 = (unsigned int)(v6 + 7);
  v14 = v6 + 7;
  v107 = (unsigned int)&v6[((unsigned int)(v12 + v11 + 4095) >> 12) + 6];
  v112 = -1;
  if ( v13 != -1 )
    v112 = (unsigned int)&v6[v13 + 7];
  v15 = -1073740748;
  v16 = *(_DWORD *)(v5 + 92);
  v106 = *(_DWORD *)(v5 + 140);
  v110 = *(_DWORD *)(v5 + 128);
  v111 = v16;
  if ( (*(_BYTE *)(v5 + 115) & 8) == 0 )
    v15 = 0;
  v105 = v15;
  v120 = 17;
  v100 = 17;
  v103 = 0x80000000;
  if ( !v10 )
  {
    v26 = 17;
    v24 = v103;
    v102 = 17;
    goto LABEL_21;
  }
  v17 = KfRaiseIrql(1);
  v18 = *(unsigned __int8 *)(v5 + 115);
  v102 = v17;
  if ( (v18 & 0xFFFFFF80) == 0 )
  {
    if ( (*(_BYTE *)(v10 + 112) & 7) != 0 )
    {
      v65 = (__int16)(*(_WORD *)(v9 + 310) + 1);
      *(_WORD *)(v9 + 310) = v65;
      if ( v65 || *(_DWORD *)(v9 + 100) == v9 + 100 )
        goto LABEL_12;
    }
    else
    {
      v19 = *(_WORD *)(v9 + 308) + 1;
      *(_WORD *)(v9 + 308) = v19;
      if ( v19 || *(_DWORD *)(v9 + 100) == v9 + 100 || *(_WORD *)(v9 + 310) )
        goto LABEL_12;
    }
    KiCheckForKernelApcDelivery(v17);
  }
LABEL_12:
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_543888(v20);
  v22 = (unsigned __int8 *)(v10 + 3);
  do
    v23 = __ldrex(v22);
  while ( __strex(v23 | 0x80, v22) );
  __dmb(0xBu);
  if ( v23 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v10);
  v24 = 0x80000000;
  while ( 1 )
  {
    v25 = *(_DWORD *)v10;
    if ( (*(_DWORD *)v10 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v25 & 0x40000000) == 0 )
    {
      do
        v68 = __ldrex((unsigned int *)v10);
      while ( v68 == v25 && __strex(v25 | 0x40000000, (unsigned int *)v10) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v26 = v102;
LABEL_21:
  if ( v16 )
  {
    if ( v26 == 17 )
      v27 = &v100;
    else
      v27 = 0;
    MiRelockProtoPoolPage(v16, v27);
    v120 = v100;
  }
  if ( (*(_BYTE *)(v5 + 112) & 1) != 0 )
  {
    *(_DWORD *)(v5 + 48) = -1073741670;
    *(_DWORD *)(v5 + 52) = 0;
  }
  v28 = *(_DWORD *)(v5 + 48);
  v109 = 17;
  v29 = *(_DWORD *)(v5 + 8);
  v104 = v28;
  if ( v29 != v5 + 8 )
  {
    v118 = MiInvalidateCollidedIos(v5);
    if ( v118 != 1 )
    {
      *(_DWORD *)(v5 + 48) = -1073741801;
      *(_DWORD *)(v5 + 52) = 0;
    }
  }
  if ( v16 )
  {
    v30 = (unsigned __int8 *)(v16 + 15);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 | 0x80, v30) );
    __dmb(0xBu);
    if ( v31 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v69 = *(_DWORD *)(v16 + 12);
          __dmb(0xBu);
        }
        while ( (v69 & v24) != 0 );
        do
          v70 = __ldrex(v30);
        while ( __strex(v70 | 0x80, v30) );
        __dmb(0xBu);
      }
      while ( v70 >> 7 );
    }
    MiRemoveLockedPageChargeAndDecRef(v16);
    __dmb(0xBu);
    v32 = (unsigned int *)(v16 + 12);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 & 0x7FFFFFFF, v32) );
  }
  if ( v10 && (*(_BYTE *)(v5 + 113) & 4) == 0 && !MiIsFaultPteIntact(v110, v108, v5 + 96) )
    v105 = -1073740748;
  v34 = v107;
  if ( v28 < 0 )
    goto LABEL_121;
  if ( (*(_BYTE *)(v5 + 113) & 4) == 0 && !*(_DWORD *)(v5 + 144) )
  {
    v35 = (unsigned int)(v6 + 7);
    if ( (_DWORD *)v107 == v6 + 7 )
    {
LABEL_122:
      v38 = 0;
      goto LABEL_47;
    }
    if ( v112 <= (unsigned int)(v6 + 8) )
      goto LABEL_121;
  }
  v36 = *(unsigned __int8 *)(v5 + 114);
  if ( (v36 & 7) == 0 || (*(_BYTE *)(v5 + 115) & 4) == 0 || (v36 & 0xFFFFFF80) != 0 )
  {
LABEL_121:
    v35 = v101;
    goto LABEL_122;
  }
  v37 = MiCreateDecayPfn((v36 >> 4) & 7);
  v35 = v101;
  v38 = v37;
LABEL_47:
  v39 = 0;
  v40 = MiState;
  v119 = 0;
  v116 = 0;
  v99 = v38;
  v41 = 0;
  if ( v35 > v34 )
  {
    v49 = v38;
    goto LABEL_74;
  }
  v121 = 4194300;
  v42 = v106;
  v123 = 0x3FFFFF;
  do
  {
    v39 = 3 * *v14;
    v43 = MmPfnDatabase + 24 * *v14;
    if ( v43 == v40[1950] )
      goto LABEL_70;
    if ( v41 )
    {
      v44 = (unsigned __int8 *)(v43 + 15);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 | 0x80, v44) );
      __dmb(0xBu);
      if ( v45 >> 7 )
      {
        MiInsertAndUnlockStandbyPages(v38, v126, v41, v109);
        v41 = 0;
        --v14;
        goto LABEL_69;
      }
    }
    else
    {
      v45 = KfRaiseIrql(2);
      v109 = v45;
      v53 = (unsigned __int8 *)(v43 + 15);
      do
        v54 = __ldrex(v53);
      while ( __strex(v54 | 0x80, v53) );
      __dmb(0xBu);
      if ( v54 >> 7 )
      {
        v72 = (unsigned __int8 *)(v43 + 15);
        do
        {
          v73 = v103;
          do
          {
            __dmb(0xAu);
            __yield();
            v74 = *(_DWORD *)(v43 + 12);
            __dmb(0xBu);
          }
          while ( (v74 & v73) != 0 );
          do
            v75 = __ldrex(v72);
          while ( __strex(v75 | 0x80, v72) );
          __dmb(0xBu);
        }
        while ( v75 >> 7 );
      }
    }
    v46 = 0;
    if ( (*v114 & 1) != 0 )
      MiStoreInPageComplete(v45, v114, v114, *v114);
    if ( (*(_DWORD *)(v43 + 12) & 0x40000000) != 0 )
    {
      v46 = 2;
      goto LABEL_60;
    }
    v47 = *(_BYTE *)(v43 + 19);
    if ( (v47 & 0x10) != 0 )
    {
      if ( v43 == v42 && v104 >= 0 )
        v104 = -1073741761;
      goto LABEL_149;
    }
    if ( v104 < 0 )
      goto LABEL_148;
    if ( (unsigned int)v14 >= v112 )
    {
      if ( v43 == v42 )
        v105 = -1073740748;
LABEL_148:
      *(_BYTE *)(v43 + 19) = v47 | 0x10;
LABEL_149:
      v46 = 1;
    }
LABEL_60:
    if ( v43 == v42
      && !v46
      && v10
      && v105 != -1073740748
      && (*(_BYTE *)(v5 + 113) & 4) == 0
      && !MiImagePageOk(v110, v43, -1073740748) )
    {
      *(_BYTE *)(v5 + 113) |= 0x10u;
      if ( v41 )
      {
        MiInsertAndUnlockStandbyPages(v99, v126, v41, 17);
        v41 = 0;
      }
      v76 = MiMakeImagePageOk(v110, v108, *(_DWORD *)(*(_DWORD *)(v43 + 4) | v103), v10, v43, v111);
      v77 = *(_DWORD *)(v43 + 12);
      v105 = v76;
      if ( (v77 & 0x40000000) != 0 )
        v46 = 2;
    }
    *(_BYTE *)(v43 + 18) &= 0xDFu;
    if ( v46 )
    {
      if ( v41 )
      {
        MiInsertAndUnlockStandbyPages(v99, v126, v41, 17);
        v41 = 0;
      }
      if ( v46 == 1 )
      {
        if ( ((*(_BYTE *)(v5 + 113) & 8) == 0 || v118 == 1) && (*(_DWORD *)(v43 + 8) & 0x400) == 0 )
        {
          v78 = v103 | *(_DWORD *)(v43 + 4);
          if ( v78 > (v121 & ((unsigned int)MmHighestUserAddress >> 10)) - 0x40000000
            || v78 < 0xC0000000
            || ((*(unsigned __int8 *)(v43 + 19) >> 5) & 1) == 0 )
          {
            MiChargeCommit((int)MiSystemPartition, 1u, 4);
          }
        }
        MiRestoreTransitionPte(v43, 2);
        *(_DWORD *)(v43 + 12) |= 0x40000000u;
        if ( (*(_DWORD *)(v43 + 8) & 0x400) == 0 )
        {
          v79 = *(_DWORD *)(v43 + 8) & 0xFFFFFFEF;
          *(_DWORD *)(v43 + 8) = v79;
          *(_DWORD *)(v43 + 8) = v79 & 0xFFFFFFF7;
        }
      }
      MiRemoveLockedPageChargeAndDecRef(v43);
      __dmb(0xBu);
      v66 = (unsigned int *)(v43 + 12);
      do
        v67 = __ldrex(v66);
      while ( __strex(v67 & 0x7FFFFFFF, v66) );
      KfLowerIrql(v109);
      goto LABEL_69;
    }
    v48 = v106;
    *(_DWORD *)v43 = 0;
    if ( v43 != v48 )
      goto LABEL_63;
    v55 = v113;
    v115 = 1;
    if ( v113 )
    {
      if ( v41 )
      {
        MiInsertAndUnlockStandbyPages(v99, v126, v41, 17);
        v41 = 0;
      }
      MiSwapHardFaultPage(v108, v43, v55);
      v48 = v55;
      v106 = v55;
      v113 = 0;
      v43 = v55;
    }
    if ( v43 == v48 && v10 && v105 >= 0 && (*(_BYTE *)(v5 + 113) & 4) == 0 )
    {
      if ( v41 )
      {
        MiInsertAndUnlockStandbyPages(v99, v126, v41, 17);
        v41 = 0;
      }
      MiAddLockedPageCharge(v43, 3);
      v56 = *(_BYTE *)(v43 + 18);
      *(_DWORD *)(v43 + 12) = *(_DWORD *)(v43 + 12) & 0xC0000000 | (*(_DWORD *)(v43 + 12) + 1) & 0x3FFFFFFF;
      *(_BYTE *)(v43 + 18) = v56 & 0xF8 | 6;
      MiRemoveLockedPageChargeAndDecRef(v43);
      v57 = *(_DWORD *)(v43 + 8);
      v116 = MiSystemPartition;
      if ( (v57 & 0x400) == 0 && (v57 & 0x10) != 0 && ((v57 >> 2) & 1) == dword_63F99C )
        v119 = MiCaptureDirtyBitToPfn(v43);
      if ( (*(_DWORD *)(v43 + 20) & 0x8000000) != 0 )
      {
        v58 = v108;
        v59 = MiDetermineUserGlobalPteMask((unsigned int)v108);
        v60 = *v58;
        v61 = ((unsigned int)*v58 >> 5) & 0x1F;
        v62 = v59 | (MmProtectToPteMask[v61] ^ v60) & 0xFED ^ v60 | 0x12;
        if ( v61 == 24 )
        {
          if ( (*(_DWORD *)(v43 + 8) & 0x400) == 0 )
            v62 = v59 | (unk_681170 ^ v60) & 0xFED ^ v60 | 0x13;
          v80 = *(unsigned __int8 *)(v43 + 18) >> 6;
          if ( v80 != 1 )
          {
            if ( v80 )
            {
              if ( v80 == 2 )
                v62 |= 0xCu;
            }
            else
            {
              v62 = v62 & 0xFFFFFFF3 | 4;
            }
          }
        }
        v63 = v108;
        if ( (unsigned int)(v108 + 0x10000000) <= v123 )
        {
          v81 = 0;
          __dmb(0xBu);
          *v63 = v62;
          if ( (v60 & 2) == 0 )
            v81 = 1;
          if ( (unsigned int)(v63 + 267649024) <= 0xFFF )
          {
            v82 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v82, (_DWORD *)(v82 + 4 * ((unsigned __int16)v63 & 0xFFF)), v62);
          }
          if ( v81 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        else
        {
          *v108 = v62;
        }
        if ( v125 )
          *v125 = v62;
      }
    }
    else
    {
LABEL_63:
      if ( (*(_BYTE *)(v5 + 114) & 0x80) == 128 )
      {
        *v14 |= v103;
      }
      else if ( MI_REMOVE_LOCKED_PAGE_CHARGE_RETURN_DECREF(v43) )
      {
        if ( v41 == 16 )
        {
          MiInsertAndUnlockStandbyPages(v99, v126, 0x10u, 17);
          v41 = 0;
        }
        v126[v41++] = v43;
        goto LABEL_68;
      }
    }
    __dmb(0xBu);
    v39 = v43 + 12;
    if ( v41 )
    {
      do
        v71 = __ldrex((unsigned int *)v39);
      while ( __strex(v71 & 0x7FFFFFFF, (unsigned int *)v39) );
    }
    else
    {
      do
        v64 = __ldrex((unsigned int *)v39);
      while ( __strex(v64 & 0x7FFFFFFF, (unsigned int *)v39) );
      KfLowerIrql(v109);
    }
LABEL_68:
    v42 = v106;
LABEL_69:
    v40 = MiState;
LABEL_70:
    ++v14;
    v38 = v99;
  }
  while ( (unsigned int)v14 <= v107 );
  v49 = v99;
  if ( v41 )
    MiInsertAndUnlockStandbyPages(v99, v126, v41, v109);
  v28 = v104;
  v16 = v111;
LABEL_74:
  v50 = v102;
  if ( v16 )
  {
    if ( v102 == 17 )
      v51 = v120;
    else
      v51 = 17;
    MiUnlockProtoPoolPage(v16, v51);
  }
  v52 = *(_BYTE *)(v5 + 114) & 0x80;
  if ( v52 == 128 )
  {
    MmCheckCachedPageStates((*(_DWORD *)(v5 + 56) & 0x3FFFF) + v110, *(_DWORD *)(v117 + 20), 2, 0);
    v39 = v107;
    v40 = (int *)v101;
    v83 = 1;
    v52 = v107 - v101 + 4;
    if ( v101 > v107 )
      v84 = 0;
    else
      v84 = v52 >> 2;
    if ( v84 )
    {
      v85 = (unsigned int *)v101;
      v86 = v103;
      do
      {
        v87 = *v85++;
        v52 = v87;
        if ( (v87 & v86) != 0 )
        {
          v88 = v52 & ~v86;
          *(v85 - 1) = v88;
          v89 = MmPfnDatabase + 24 * v88;
          v90 = KfRaiseIrql(2);
          v91 = (unsigned __int8 *)(v89 + 15);
          do
            v92 = __ldrex(v91);
          while ( __strex(v92 | 0x80, v91) );
          __dmb(0xBu);
          if ( v92 >> 7 )
          {
            v93 = (unsigned __int8 *)(v89 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v94 = *(_DWORD *)(v89 + 12);
                __dmb(0xBu);
              }
              while ( (v94 & v86) != 0 );
              do
                v95 = __ldrex(v93);
              while ( __strex(v95 | 0x80, v93) );
              __dmb(0xBu);
            }
            while ( v95 >> 7 );
          }
          MiRemoveLockedPageChargeAndDecRef(v89);
          __dmb(0xBu);
          v96 = (unsigned int *)(v89 + 12);
          do
            v97 = __ldrex(v96);
          while ( __strex(v97 & 0x7FFFFFFF, v96) );
          KfLowerIrql(v90);
        }
        ++v83;
      }
      while ( v83 <= v84 );
      v5 = v122;
      v10 = v124;
      v49 = v99;
    }
    v50 = v102;
    v28 = v104;
  }
  if ( v49 )
    MiDecayPfnFullyInitialized(v49, (int)v40, v39, v52);
  if ( v119 )
    MiReleasePageFileInfo((int)v116, v119, 0, v119);
  if ( v10 && (*(_BYTE *)(v5 + 115) & 0x80) == 128 )
    MiUnlockWorkingSetExclusive(v10, v50);
  if ( (*(_BYTE *)(v5 + 115) & 0x10) == 0 )
    ObDereferenceObjectDeferDeleteWithTag(*(_DWORD *)(v5 + 116));
  if ( *(int *)(v5 + 100) > 1 )
    KeSetEvent(v5 + 32, 0, 0);
  MiFreeInPageSupportBlock(v5);
  if ( v113 )
  {
    MiReleaseFreshPage(v113);
    MiReturnResidentAvailable(1);
    do
      v98 = __ldrex(&dword_634A2C[39]);
    while ( __strex(v98 + 1, &dword_634A2C[39]) );
    MiReturnCommit(MiSystemPartition, 1);
  }
  if ( v28 < 0 )
  {
    if ( (*v114 & 1) != 0 && (*v114 & 2) == 0 )
      v28 = -1073740748;
    result = v28;
  }
  else if ( v115 )
  {
    result = v105;
  }
  else
  {
    result = -1073740748;
  }
  return result;
}
