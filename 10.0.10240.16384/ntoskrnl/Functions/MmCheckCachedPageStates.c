// MmCheckCachedPageStates 
 
int __fastcall MmCheckCachedPageStates(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r8
  int v6; // r9
  char v7; // lr
  unsigned int v8; // r6
  int v9; // r1
  int v10; // r7
  int v11; // r0
  char v12; // r5
  char v13; // r6
  unsigned int v14; // r2
  bool v15; // zf
  _BYTE *v16; // r7
  unsigned int v18; // r9
  int v19; // r10
  unsigned int v20; // r9
  int v21; // r10
  _DWORD *v22; // r0
  unsigned int v23; // r2
  unsigned int v24; // r9
  int v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // lr
  int v29; // r0
  unsigned __int8 *v30; // r1
  unsigned int v31; // r2
  unsigned int *v32; // r1
  unsigned int v33; // r2
  _DWORD *v34; // r10
  unsigned int v35; // r3
  unsigned int v36; // r9
  unsigned int v37; // r2
  unsigned int v38; // r10
  unsigned int v39; // r3
  int v40; // r0
  int v41; // r2
  unsigned int v42; // r3
  int v43; // r3
  int v44; // r0
  int v45; // r9
  int v46; // r0
  unsigned int *v47; // r1
  int *v48; // r0
  __int16 v49; // r1
  int v50; // r0
  unsigned int *i; // r7
  unsigned int *v52; // r0
  unsigned __int8 *v53; // r3
  unsigned int v54; // r1
  unsigned int v55; // r2
  unsigned int v56; // lr
  int v57; // r9
  unsigned int *v58; // r10
  int v59; // r0
  int v60; // r1
  unsigned int v61; // r2
  unsigned int *v62; // r2
  unsigned int v63; // r0
  unsigned int *v64; // r2
  unsigned int v65; // r0
  int v66; // r2
  int v67; // r3
  unsigned int v68; // r2
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned int *v71; // r2
  unsigned int v72; // r0
  unsigned int v73; // r1
  int v74; // r2
  int v75; // r10
  unsigned int v76; // r3
  int v77; // r0
  char v78[4]; // [sp+8h] [bp-C0h] BYREF
  int v79; // [sp+Ch] [bp-BCh]
  int v80; // [sp+10h] [bp-B8h]
  _DWORD *v81; // [sp+14h] [bp-B4h]
  int v82; // [sp+18h] [bp-B0h]
  int v83; // [sp+1Ch] [bp-ACh]
  int v84; // [sp+20h] [bp-A8h] BYREF
  unsigned int v85; // [sp+24h] [bp-A4h]
  int v86; // [sp+28h] [bp-A0h]
  unsigned int v87; // [sp+2Ch] [bp-9Ch]
  int v88; // [sp+30h] [bp-98h]
  int v89; // [sp+34h] [bp-94h]
  int v90; // [sp+38h] [bp-90h] BYREF
  unsigned int *v91; // [sp+3Ch] [bp-8Ch]
  int v92; // [sp+40h] [bp-88h]
  int v93; // [sp+44h] [bp-84h]
  int v94; // [sp+48h] [bp-80h]
  _BYTE *v95; // [sp+4Ch] [bp-7Ch]
  _WORD *v96; // [sp+50h] [bp-78h] BYREF
  __int16 v97; // [sp+54h] [bp-74h]
  unsigned __int16 v98; // [sp+56h] [bp-72h]
  int v99; // [sp+58h] [bp-70h]
  unsigned int v100; // [sp+5Ch] [bp-6Ch]
  int v101; // [sp+60h] [bp-68h]
  _DWORD v102[24]; // [sp+68h] [bp-60h] BYREF

  v95 = (_BYTE *)a4;
  v93 = 1;
  v86 = 0;
  v4 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v90 = 0;
  v91 = 0;
  v92 = 0;
  v5 = 0;
  v81 = 0;
  v82 = 0;
  v6 = 0;
  v83 = 0;
  v7 = a3;
  v80 = a3;
  v8 = (((a1 + a2 - 1) >> 10) & 0x3FFFFC) - 0x40000000;
  v9 = *(_DWORD *)(((v4 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
  v87 = v8;
  v88 = MmPfnDatabase + 24 * v9;
  v94 = 0x80000000;
  v10 = 17;
  v100 = 0x3FFFFF;
  v11 = 1073741312;
  v99 = 1070596096;
  v79 = 17;
  v78[0] = 17;
  v89 = 1073741312;
  while ( v4 <= v8 )
  {
    v12 = 0;
    if ( (*(_DWORD *)v4 & 2) != 0 )
    {
      if ( (v7 & 4) != 0 )
      {
        if ( v10 != 17 )
          JUMPOUT(0x52CAA2);
        MiMarkPteDirty((unsigned int *)v4);
      }
      goto LABEL_5;
    }
    if ( (*(_DWORD *)v4 & 0x200) != 0 )
      v12 = 1;
    v18 = (unsigned int)v81;
    v19 = (*(_DWORD *)v4 & 0x1FC | v11 & (*(_DWORD *)v4 >> 2)) - 0x40000000;
    v81 = (_DWORD *)v19;
    if ( v10 != 17 )
    {
      if ( ((v18 ^ v19) & 0xFFFFF000) == 0 )
        goto LABEL_35;
      MiUnlockProtoPoolPage(v82, v10);
      v10 = 17;
      v78[0] = 17;
    }
    if ( v5 && ((v18 ^ v19) & 0xFFFFF000) != 0 )
    {
      MiMakeSystemCacheRangeValid(v4 - 4 * v5, v102, v5, v88);
      v5 = 0;
    }
    v20 = *(_DWORD *)v19;
    if ( (*(_DWORD *)v19 & 2) == 0 && ((v20 & 0x400) != 0 || (v20 & 0x800) == 0) )
    {
      v82 = 0;
      goto LABEL_63;
    }
    while ( 1 )
    {
      v82 = MiLockProtoPoolPage(v19, v78);
      if ( v82 )
        break;
      MmAccessFault(1, v19, 0, 0);
    }
    v10 = (unsigned __int8)v78[0];
    v8 = v87;
LABEL_35:
    if ( (*(_DWORD *)v4 & 2) != 0 )
      goto LABEL_72;
    v20 = *(_DWORD *)v19;
    if ( ((*(_DWORD *)v19 & 2) != 0 || (v20 & 0x400) == 0 && (v20 & 0x800) != 0)
      && (v21 = MiLockLeafPage(v19, 0), v22 = v81, v20 = *v81, v21) )
    {
      if ( (v20 & 2) != 0 )
      {
        if ( (*(_BYTE *)(v21 + 19) & 0x40) != 0 )
          goto LABEL_132;
        *(_DWORD *)(v21 + 12) = *(_DWORD *)(v21 + 12) & 0xC0000000 | (*(_DWORD *)(v21 + 12) + 1) & 0x3FFFFFFF;
        goto LABEL_48;
      }
      if ( (*(_BYTE *)(v21 + 18) & 0x20) != 0
        || (*(_BYTE *)(v21 + 19) & 0x40) != 0
        || (v23 = dword_640580, (unsigned int)dword_640580 < 0x80)
        && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v23 < 2) )
      {
LABEL_132:
        __dmb(0xBu);
        v62 = (unsigned int *)(v21 + 12);
        do
          v63 = __ldrex(v62);
        while ( __strex(v63 & 0x7FFFFFFF, v62) );
        v6 = v83;
        goto LABEL_5;
      }
      v24 = ((int)(v8 - v4) >> 2) + 1;
      if ( v24 > 1 && (*(_BYTE *)(v21 + 18) & 7) == 2 )
      {
        v41 = 4 * *(_DWORD *)((*(_DWORD *)(v21 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v21 + 8) & 0x3FC))) + 0x1C)
            - (_DWORD)v22;
        if ( (*(_DWORD *)((*(_DWORD *)(v21 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v21 + 8) & 0x3FC))) + 4) + v41) >> 2 < v24 )
          v24 = (*(_DWORD *)((*(_DWORD *)(v21 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v21 + 8) & 0x3FC))) + 4) + v41) >> 2;
        v42 = 4096 - ((unsigned __int16)v22 & 0xFFF);
        if ( v24 > v42 >> 2 )
          v24 = v42 >> 2;
        if ( v24 > 16 - v5 )
          v24 = 16 - v5;
        if ( v24 > 1 )
        {
          v101 = 0;
          v84 = 0;
          if ( (*(_BYTE *)(v21 + 19) & 8) != 0 )
            v43 = 5;
          else
            v43 = *(_BYTE *)(v21 + 19) & 7;
          v79 = v43;
          KeAcquireInStackQueuedSpinLockAtDpcLevel((char *)&unk_63FD10 + 20 * v43, &v90, v41, &unk_63FD10);
          v85 = MiUnlinkPageFromList(v21, 1);
          if ( v85 == 1 )
          {
            v44 = MiUnlinkStandbyBatch(1, v81 + 1, v79, v4, v24 - 1, &v84);
            v45 = v84;
            v83 = v44;
          }
          else
          {
            v45 = v101;
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(&v90);
          }
          else
          {
            v46 = v90;
            if ( !v90 )
            {
              v47 = v91;
              __dmb(0xBu);
              do
                v48 = (int *)__ldrex(v47);
              while ( v48 == &v90 && __strex(0, v47) );
              if ( v48 == &v90 )
                goto LABEL_94;
              v46 = KxWaitForLockChainValid(&v90);
            }
            v90 = 0;
            __dmb(0xBu);
            v64 = (unsigned int *)(v46 + 4);
            do
              v65 = __ldrex(v64);
            while ( __strex(v65 ^ 1, v64) );
          }
LABEL_94:
          if ( v45 )
          {
            MiDiscardTransitionPte(v45);
            __dmb(0xBu);
            v69 = (unsigned int *)(v45 + 12);
            do
              v70 = __ldrex(v69);
            while ( __strex(v70 & 0x7FFFFFFF, v69) );
          }
          v25 = v85;
          goto LABEL_46;
        }
      }
      v25 = MiUnlinkPageFromList(v21, 0);
LABEL_46:
      if ( v25 )
      {
        MiReadyStandbyPageForActive(v21, v4);
        v20 = *v81;
LABEL_48:
        __dmb(0xBu);
        v26 = (unsigned int *)(v21 + 12);
        do
          v27 = __ldrex(v26);
        while ( __strex(v27 & 0x7FFFFFFF, v26) );
LABEL_50:
        v13 = v80;
        while ( 1 )
        {
          v28 = KfRaiseIrql(2);
          v29 = v88;
          v30 = (unsigned __int8 *)(v88 + 15);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 | 0x80, v30) );
          __dmb(0xBu);
          if ( v31 >> 7 )
          {
            do
            {
              v66 = v94;
              do
              {
                __dmb(0xAu);
                __yield();
                v67 = *(_DWORD *)(v29 + 12);
                __dmb(0xBu);
              }
              while ( (v67 & v66) != 0 );
              do
                v68 = __ldrex(v30);
              while ( __strex(v68 | 0x80, v30) );
              __dmb(0xBu);
            }
            while ( v68 >> 7 );
          }
          *(_DWORD *)(v29 + 12) = *(_DWORD *)(v29 + 12) & 0xC0000000 | (*(_DWORD *)(v29 + 12) + 1) & 0x3FFFFFFF;
          __dmb(0xBu);
          v32 = (unsigned int *)(v29 + 12);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 & 0x7FFFFFFF, v32) );
          KfLowerIrql(v28);
          if ( (v12 & 1) != 0 )
          {
            v20 = ((dword_681114 ^ v20) & 0x3ED ^ v20 | MiDetermineUserGlobalPteMask(v4)) & 0xFFFFF3FF | 0x12;
          }
          else if ( (v13 & 4) != 0 && (v20 & 0x200) != 0 && (v20 & 0x80) != 0 )
          {
            v20 &= 0xFFFFFDFF;
          }
          v14 = v20 & 0xFFFFF7DF;
          v6 = v83;
LABEL_6:
          v4 += 4;
          if ( (v12 & 2) != 0 )
            v14 &= 0xFFFFFFFC;
          if ( v14 || v5 )
          {
            v102[v5++] = v14;
            if ( v5 == 16 )
            {
              if ( v10 != 17 )
              {
                MiUnlockProtoPoolPage(v82, v10);
                v10 = 17;
                v78[0] = 17;
              }
              MiMakeSystemCacheRangeValid(v4 - 64, v102, 16, v88);
              v5 = 0;
            }
          }
          if ( !v6 )
            break;
          v83 = v6 - 1;
          v20 = v81[1];
          ++v81;
          v12 = 0;
          if ( (*(_DWORD *)v4 & 2) != 0 )
          {
            v12 = 2;
          }
          else if ( (*(_DWORD *)v4 & 0x200) != 0 )
          {
            v12 = 1;
          }
        }
        v8 = v87;
        v7 = v80;
        v11 = v89;
        v79 = v10;
      }
      else
      {
        MiDiscardTransitionPte(v21);
        __dmb(0xBu);
        v71 = (unsigned int *)(v21 + 12);
        do
          v72 = __ldrex(v71);
        while ( __strex(v72 & 0x7FFFFFFF, v71) );
        v7 = v80;
        v6 = v83;
        v11 = v89;
        v81 = 0;
      }
    }
    else
    {
LABEL_63:
      v34 = *(_DWORD **)(v20 & 0xFFFFF800 | (2 * (v20 & 0x3FC)));
      v85 = v20 & 0xFFFFF800 | (2 * (v20 & 0x3FC));
      v35 = v34[7];
      if ( (v35 & 0x40000000) != 0
        || (v80 & 1) == 0
        || (MI_INITIALIZE_COLOR_BASE(0, (v35 >> 20) & 0x3F, &v96),
            v49 = *v96 + 1,
            *v96 = v49,
            v50 = MiGetPage(MiSystemPartition, (unsigned __int16)(v49 & v97) | v98, 2),
            v84 = v50,
            v50 == -1) )
      {
        if ( (v80 & 2) == 0 )
        {
          if ( v10 != 17 )
          {
            MiUnlockProtoPoolPage(v82, v10);
            v10 = 17;
            v78[0] = 17;
          }
          v36 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v37 = *(_DWORD *)(v36 + 0x3B4);
          v38 = *(unsigned __int8 *)(v36 + 0x3CC) + 4 * v37;
          *(_BYTE *)(v36 + 0x3CC) = 1;
          v39 = (int)(v8 - v4) >> 2;
          if ( v39 > v37 )
          {
            if ( v39 > 0xF )
              v39 = 15;
            *(_DWORD *)(v36 + 948) = v39;
          }
          v40 = MmAccessFault(0, v4 << 10, 0, 0);
          if ( v40 < 0 && v86 >= 0 )
            v86 = v40;
          *(_BYTE *)(v36 + 972) = v38 & 3;
          *(_DWORD *)(v36 + 948) = v38 >> 2;
        }
        v93 = 0;
LABEL_72:
        v6 = v83;
LABEL_5:
        v13 = v80;
        v14 = 0;
        goto LABEL_6;
      }
      v79 = MmPfnDatabase + 24 * v50;
      if ( *(_DWORD *)(v79 + 8) )
      {
        if ( v10 != 17 )
        {
          MiUnlockProtoPoolPage(v82, v10);
          v10 = 17;
          v50 = v84;
          v78[0] = 17;
        }
        v60 = 1;
        if ( (v20 & 0x400) != 0 )
          v61 = (*(unsigned __int16 *)(v85 + 16) >> 1) & 0x1F;
        else
          v61 = (v20 >> 5) & 0x1F;
        if ( v61 >> 3 == 3 && (v61 & 7) != 0 )
        {
          v60 = 2;
        }
        else if ( v61 >> 3 == 1 )
        {
          v60 = 0;
        }
        MiZeroPhysicalPage(v50, 1, v60);
        *(_DWORD *)(v79 + 8) = 0;
      }
      if ( v10 != 17 )
        goto LABEL_105;
      for ( i = v81; ; MmAccessFault(1, i, 0, 0) )
      {
        v82 = MiLockProtoPoolPage(i, v78);
        if ( v82 )
          break;
      }
      v20 = *i;
      v8 = v87;
      if ( (*i & 2) == 0 && ((v20 & 0x800) == 0 || (v20 & 0x400) != 0) )
      {
        v10 = (unsigned __int8)v78[0];
LABEL_105:
        v52 = v34 + 9;
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v52);
          v52 = v34 + 9;
        }
        else
        {
          v53 = (unsigned __int8 *)v34 + 39;
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 | 0x80, v53) );
          __dmb(0xBu);
          if ( v54 >> 7 )
          {
            ExpWaitForSpinLockExclusiveAndAcquire(v52);
            v52 = v34 + 9;
          }
          v55 = v94;
          while ( 1 )
          {
            v56 = *v52;
            if ( (*v52 & 0xBFFFFFFF) == v55 )
              break;
            if ( (v56 & 0x40000000) == 0 )
            {
              do
                v73 = __ldrex(v52);
              while ( v73 == v56 && __strex(v56 | 0x40000000, v52) );
              __dmb(0xBu);
              v55 = 0x80000000;
            }
            __dmb(0xAu);
            __yield();
          }
        }
        ++v34[4];
        if ( v34[8] )
          ++*(_DWORD *)(v85 + 64);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v52);
        }
        else
        {
          __dmb(0xBu);
          *v52 = 0;
        }
        if ( (v20 & 0x400) != 0 )
          v57 = (*(unsigned __int16 *)((v20 & 0xFFFFF800 | (2 * (v20 & 0x3FC))) + 0x10) >> 1) & 0x1F;
        else
          v57 = (v20 >> 5) & 0x1F;
        v58 = v81;
        MiInitializePfn(v79, v81, v57, 18);
        v59 = MiDetermineUserGlobalPteMask(v4);
        v20 = (v59 | MmProtectToPteMask[v57] & 0x3ED | (v84 << 12)) & 0xFFFFF3FF | 0x12;
        if ( (unsigned int)(v58 + 0x10000000) <= v100 )
        {
          v74 = (int)v81;
          v75 = 0;
          v76 = *v81;
          __dmb(0xBu);
          *(_DWORD *)v74 = v20;
          if ( (v76 & 2) == 0 )
            v75 = 1;
          if ( (unsigned int)(v99 + v74) <= 0xFFF )
          {
            v77 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v77, v77 + 4 * (v74 & 0xFFF), v20);
          }
          if ( v75 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        else
        {
          *v58 = v20;
        }
        goto LABEL_50;
      }
      MiUnlockProtoPoolPage(v82, (unsigned __int8)v78[0]);
      MiReleaseFreshPage(v79);
      v10 = 17;
      v7 = v80;
      v6 = v83;
      v11 = v89;
      v81 = 0;
      v78[0] = 17;
    }
  }
  v79 = v10;
  v15 = v10 == 17;
  v16 = v95;
  if ( !v15 )
    MiUnlockProtoPoolPage(v82, v79);
  if ( v5 )
    MiMakeSystemCacheRangeValid(v4 - 4 * v5, v102, v5, v88);
  if ( v16 )
    *v16 = v93;
  return v86;
}
