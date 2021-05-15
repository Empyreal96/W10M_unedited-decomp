// MmCopyToCachedPage 
 
int __fastcall MmCopyToCachedPage(unsigned int a1, int a2, int a3, unsigned int a4, char a5)
{
  unsigned int v5; // r9
  int v6; // lr
  unsigned int v7; // r6
  unsigned int v8; // r3
  unsigned int v9; // r1
  int v10; // lr
  unsigned int v11; // r0
  unsigned int v12; // r1
  unsigned int v13; // lr
  int v14; // r3
  int v15; // r5
  int v16; // r0
  unsigned int v17; // r10
  unsigned int v18; // r4
  int v19; // r0
  int v20; // r9
  unsigned int *v21; // r2
  unsigned int v22; // r0
  char v23; // r3
  unsigned int v24; // r4
  unsigned int v25; // r2
  unsigned int *v26; // r2
  unsigned int v27; // r0
  int v28; // r0
  unsigned int v29; // r1
  char v30; // r2
  unsigned int v31; // r2
  int v32; // r3
  unsigned int v33; // r2
  int v34; // r2
  unsigned int v35; // r1
  unsigned int v36; // r3
  int v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r0
  unsigned int v40; // r3
  __int16 v41; // r3
  int v42; // r2
  int v43; // r0
  unsigned int v44; // r2
  int v45; // r2
  int v46; // r0
  unsigned int v47; // r4
  unsigned int v48; // r4
  unsigned int v49; // r4
  int v50; // r0
  unsigned int v51; // lr
  int v52; // r2
  int v53; // r3
  int v54; // r0
  int v55; // r0
  unsigned int v56; // r2
  BOOL v57; // r3
  int v58; // r0
  unsigned int v59; // r2
  int v60; // r3
  int v61; // lr
  unsigned __int8 *v62; // r1
  unsigned int v63; // r2
  int v64; // r3
  unsigned int v65; // r2
  char v66; // r2
  unsigned int *v67; // lr
  unsigned __int8 *v68; // r3
  unsigned int v69; // r1
  int i; // r9
  int v71; // r2
  unsigned int v72; // r4
  unsigned int v73; // r1
  int v74; // lr
  int v75; // r1
  unsigned int v76; // r3
  int v77; // r0
  int v78; // r0
  int v79; // r2
  unsigned int *v80; // r2
  unsigned int v81; // r0
  int v82; // r0
  unsigned __int8 *v83; // r1
  unsigned int v84; // r2
  int v85; // r3
  unsigned int v86; // r2
  unsigned int *v87; // r1
  unsigned int v88; // r0
  unsigned int v89; // r1
  int v90; // r1
  unsigned int *v91; // r0
  unsigned int v92; // lr
  unsigned int v93; // r1
  unsigned int v94; // r2
  int v95; // r4
  _DWORD *v96; // r4
  int v97; // r6
  int v98; // r5
  __int64 v99; // r0
  char v101[4]; // [sp+8h] [bp-D0h] BYREF
  unsigned int v102; // [sp+Ch] [bp-CCh]
  int v103; // [sp+10h] [bp-C8h]
  unsigned int v104; // [sp+14h] [bp-C4h]
  unsigned int v105; // [sp+18h] [bp-C0h]
  int v106; // [sp+1Ch] [bp-BCh]
  int v107; // [sp+20h] [bp-B8h]
  int v108; // [sp+24h] [bp-B4h]
  unsigned int v109; // [sp+28h] [bp-B0h]
  unsigned int v110; // [sp+2Ch] [bp-ACh]
  int v111; // [sp+30h] [bp-A8h]
  unsigned int v112; // [sp+34h] [bp-A4h]
  int v113; // [sp+38h] [bp-A0h]
  unsigned int v114; // [sp+3Ch] [bp-9Ch]
  int v115; // [sp+40h] [bp-98h]
  int v116; // [sp+44h] [bp-94h]
  int v117; // [sp+48h] [bp-90h]
  int v118; // [sp+4Ch] [bp-8Ch]
  int v119; // [sp+50h] [bp-88h]
  int v120; // [sp+54h] [bp-84h]
  int v121; // [sp+58h] [bp-80h]
  unsigned int v122; // [sp+5Ch] [bp-7Ch]
  int v123; // [sp+60h] [bp-78h]
  unsigned int v124; // [sp+64h] [bp-74h]
  int v125; // [sp+68h] [bp-70h]
  int v126; // [sp+6Ch] [bp-6Ch]
  int v127; // [sp+70h] [bp-68h]
  unsigned int v128; // [sp+74h] [bp-64h]
  int v129; // [sp+78h] [bp-60h]
  unsigned int v130; // [sp+7Ch] [bp-5Ch]
  int v131; // [sp+80h] [bp-58h]
  unsigned int v132; // [sp+84h] [bp-54h]
  int v133; // [sp+88h] [bp-50h]
  _DWORD v134[6]; // [sp+90h] [bp-48h] BYREF
  _WORD *v135; // [sp+A8h] [bp-30h] BYREF
  int v136; // [sp+ACh] [bp-2Ch]
  int v137; // [sp+B0h] [bp-28h]
  int v138; // [sp+B4h] [bp-24h]

  v5 = a4;
  v104 = a4;
  v6 = a3;
  v106 = a3;
  v107 = a2;
  v105 = a1;
  v128 = a1;
  v127 = a2;
  v126 = a3;
  v115 = a4;
  v102 = 0;
  v114 = 0;
  v118 = 0;
  v125 = 0;
  if ( a4 + a3 > 0x1000 || a4 + a3 < a4 )
    KeBugCheckEx(26, 1910, a1);
  v7 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v122 = v7;
  v8 = *(_DWORD *)v7;
  if ( (*(_DWORD *)v7 & 2) != 0 )
  {
    if ( (v8 & 0x10) != 0 && ((v8 & 0x200) == 0 || (v8 & 0x80) == 0) )
      goto LABEL_231;
    v117 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E00);
    }
    else
    {
      do
        v9 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
      while ( __strex(v9 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
      __dmb(0xBu);
      if ( v9 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
      while ( 1 )
      {
        v10 = dword_634E00;
        if ( (dword_634E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_634E00 & 0x40000000) == 0 )
        {
          do
            v11 = __ldrex((unsigned int *)&dword_634E00);
          while ( v11 == v10 && __strex(v10 | 0x40000000, (unsigned int *)&dword_634E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v5 = v104;
    }
    v12 = *(_DWORD *)v7;
    v13 = *(_DWORD *)v7;
    if ( (*(_DWORD *)v7 & 2) != 0 )
    {
      if ( (v12 & 0x10) != 0 )
      {
        v14 = 0;
      }
      else
      {
        v13 = v12 | 0x10;
        v14 = 1;
      }
      if ( (v13 & 0x200) != 0 && (v13 & 0x80) != 0 )
      {
        v13 = v13 & 0xFFFFFDFF | 0x10;
        goto LABEL_27;
      }
      if ( v14 )
      {
LABEL_27:
        if ( v7 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v7 = v13;
        }
        else
        {
          v15 = 0;
          __dmb(0xBu);
          *(_DWORD *)v7 = v13;
          if ( (v12 & 2) == 0 && (v13 & 2) != 0 )
            v15 = 1;
          if ( v7 + 1070596096 <= 0xFFF )
          {
            v16 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v16, (_DWORD *)(v16 + 4 * (v7 & 0xFFF)), v13);
          }
          if ( v15 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        goto LABEL_36;
      }
    }
LABEL_36:
    MiUnlockWorkingSetExclusive(&dword_634E00, v117);
    a2 = v107;
    v6 = v106;
    a1 = v105;
LABEL_231:
    v23 = 0;
    goto LABEL_232;
  }
  v119 = MmPfnDatabase + 24 * (*(_DWORD *)(((v7 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v129 = v119;
  if ( (*(_DWORD *)v7 & 2) != 0 )
  {
    a2 = v107;
    v23 = v102;
    a1 = v105;
    goto LABEL_232;
  }
  v17 = (*(_DWORD *)v7 & 0x1FC | (*(_DWORD *)v7 >> 2) & 0x3FFFFE00) - 0x40000000;
  v130 = v17;
  v18 = *(_DWORD *)v17;
  if ( (*(_DWORD *)v17 & 2) != 0 )
  {
LABEL_43:
    v112 = 0x3FFFFF;
    goto LABEL_44;
  }
  if ( (v18 & 0x400) == 0 )
  {
    if ( (v18 & 0x800) == 0 )
    {
      v112 = 0x3FFFFF;
      goto LABEL_87;
    }
    goto LABEL_43;
  }
  v112 = 0x3FFFFF;
  while ( 1 )
  {
LABEL_87:
    v109 = v18 & 0xFFFFF800 | (2 * (v18 & 0x3FC));
    v132 = v109;
    v120 = *(_DWORD *)v109;
    v121 = v120;
    v40 = *(_DWORD *)(v120 + 28);
    if ( (v40 & 0x40000000) != 0 )
    {
      MmAccessFault(0, v105, 0, 0);
      goto LABEL_44;
    }
    v101[0] = 17;
    MI_INITIALIZE_COLOR_BASE(0, (v40 >> 20) & 0x3F, &v135);
    v41 = *v135 + 1;
    *v135 = v41;
    if ( v5 == 4096 )
      v42 = 0;
    else
      v42 = 2;
    v43 = MiGetPage((int)MiSystemPartition, HIWORD(v136) | (unsigned __int16)(v41 & v136), v42);
    v123 = v43;
    v108 = v43;
    if ( v43 == -1 )
    {
      MiWaitForFreePage(MiSystemPartition);
      goto LABEL_44;
    }
    v20 = MmPfnDatabase + 24 * v43;
    v111 = v20;
    v133 = v20;
    if ( v104 != 4096 && *(_DWORD *)(v20 + 8) )
    {
      v102 |= 4u;
      v114 = v102;
    }
    v44 = (v18 & 0x400) != 0 ? (*(unsigned __int16 *)(v109 + 16) >> 1) & 0x1F : (v18 >> 5) & 0x1F;
    v124 = v44;
    v116 = v44;
    v103 = 1;
    if ( v44 >> 3 == 3 && (v44 & 7) != 0 )
    {
      v45 = 2;
    }
    else
    {
      if ( v44 >> 3 != 1 )
        goto LABEL_106;
      v45 = 0;
    }
    v103 = v45;
LABEL_106:
    MiFinalizePageAttribute(v20, v103, 0);
    v46 = MiReservePtes(&dword_634D58);
    v47 = v46;
    v131 = v46;
    v110 = v46;
    if ( v46 )
    {
      v50 = MiDetermineUserGlobalPteMask(v46);
      v51 = (dword_681120 & 0x1EC | (v108 << 12) | v50) & 0xFFFFF1FF | 0x13;
      if ( v47 + 0x40000000 > v112 )
      {
        *(_DWORD *)v47 = v51;
      }
      else
      {
        v52 = 0;
        v103 = 0;
        v53 = *(_DWORD *)v47;
        __dmb(0xBu);
        *(_DWORD *)v47 = v51;
        if ( (v53 & 2) == 0 )
        {
          v52 = 1;
          v103 = 1;
        }
        if ( v47 >= 0xC0300000 && v47 <= 0xC0300FFF )
        {
          v54 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v54, (_DWORD *)(v54 + 4 * (v47 & 0xFFF)), v51);
          v52 = v103;
        }
        if ( v52 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      v55 = v106 + (v47 << 10);
      v103 = v55;
      if ( (v102 & 4) != 0 )
      {
        if ( v106 )
        {
          memset((_BYTE *)(v47 << 10), 0, v106);
          v55 = v103;
        }
        v56 = v104;
        if ( 4096 - v104 == v106 )
          goto LABEL_127;
        memset((_BYTE *)(v55 + v104), 0, 4096 - v104 - v106);
        v55 = v103;
      }
      v56 = v104;
LABEL_127:
      v113 = 0;
      memmove(v55, v107, v56);
      MiReleasePtes(&dword_634D58, v131, 1);
      v49 = v102 | 2;
      goto LABEL_128;
    }
    if ( (a5 & 1) == 0 )
    {
      MiReleaseFreshPage(v20);
      v5 = v104;
      a2 = v107;
      v23 = v102;
      v6 = v106;
      a1 = v105;
      goto LABEL_232;
    }
    v48 = v102;
    if ( (v102 & 4) != 0 )
    {
      v48 = v102 & 0xFFFFFFFB;
      MiZeroPhysicalPage(v108, 1, v103);
    }
    v49 = v48 | 8;
LABEL_128:
    v102 = v49;
    if ( (v49 & 0x10) != 0 )
      v57 = 0;
    else
      v57 = (dword_682604 & 1) != 0;
    v103 = v57;
    v58 = MiLockProtoPoolPage(v17, v101);
    v121 = v58;
    if ( !v58 )
    {
      v102 = v49 & 0xFFFFFFFD;
      v114 = v49 & 0xFFFFFFFD;
      MiLockAndInsertPageInFreeList(v20);
      v5 = v104;
      goto LABEL_44;
    }
    v59 = *(_DWORD *)v17;
    if ( (*(_DWORD *)v17 & 2) == 0 && ((v59 & 0x800) == 0 || (v59 & 0x400) != 0) )
    {
      v60 = (v59 & 0x400) != 0 ? (*(unsigned __int16 *)((*(_DWORD *)v17 & 0xFFFFF800 | (2 * (*(_DWORD *)v17 & 0x3FC)))
                                                      + 0x10) >> 1) & 0x1F : (v59 >> 5) & 0x1F;
      v61 = v116;
      if ( v116 == v60 )
        break;
    }
    MiUnlockProtoPoolPage(v58, (unsigned __int8)v101[0]);
    v102 = v49 & 0xFFFFFFFD;
    v114 = v49 & 0xFFFFFFFD;
    MiLockAndInsertPageInFreeList(v20);
    v5 = v104;
LABEL_44:
    while ( 1 )
    {
      v108 = MiLockProtoPoolPage(v17, v101);
      if ( v108 )
        break;
      MmAccessFault(1, v17, 0, 0);
    }
    v19 = MiLockLeafPage((unsigned int *)v17, 0);
    v18 = *(_DWORD *)v17;
    if ( v19 )
    {
      if ( (v18 & 2) != 0 )
      {
        v20 = MmPfnDatabase + 24 * (v18 >> 12);
        if ( (*(_BYTE *)(v20 + 19) & 0x40) != 0 )
        {
LABEL_49:
          __dmb(0xBu);
          v21 = (unsigned int *)(v20 + 12);
          do
            v22 = __ldrex(v21);
          while ( __strex(v22 & 0x7FFFFFFF, v21) );
          MiUnlockProtoPoolPage(v108, (unsigned __int8)v101[0]);
          goto LABEL_52;
        }
        *(_DWORD *)(v20 + 12) = *(_DWORD *)(v20 + 12) & 0xC0000000 | ((*(_DWORD *)(v20 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
        goto LABEL_83;
      }
      v24 = v18 >> 12;
      v20 = MmPfnDatabase + 24 * v24;
      if ( (*(_BYTE *)(v20 + 18) & 0x20) != 0 )
        goto LABEL_49;
      if ( (*(_BYTE *)(v20 + 19) & 0x40) != 0 )
        goto LABEL_49;
      v25 = dword_640580;
      if ( (unsigned int)dword_640580 < 0x80
        && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v25 < 2) )
      {
        goto LABEL_49;
      }
      if ( !MiUnlinkPageFromList(v20, 0) )
      {
        MiDiscardTransitionPte(v20);
        __dmb(0xBu);
        v26 = (unsigned int *)(v20 + 12);
        do
          v27 = __ldrex(v26);
        while ( __strex(v27 & 0x7FFFFFFF, v26) );
        MiUnlockProtoPoolPage(v108, (unsigned __int8)v101[0]);
        v5 = v104;
        a2 = v107;
        v23 = v102;
        v6 = v106;
        a1 = v105;
LABEL_232:
        v113 = 0;
        if ( (v23 & 2) == 0 )
          memmove(a1 + v6, a2, v5);
        return 0;
      }
      ++*(_WORD *)(v20 + 16);
      v28 = *(_BYTE *)(v20 + 18) & 0xE8;
      v29 = v28 | 0x16;
      *(_BYTE *)(v20 + 18) = v28 | 0x16;
      *(_DWORD *)(v20 + 12) = *(_DWORD *)(v20 + 12) & 0xC0000000 | 1;
      if ( (a5 & 2) != 0 )
      {
        v30 = *(_BYTE *)(v20 + 19);
        if ( (v30 & 8) != 0 || (v30 & 7u) > 2 )
          *(_BYTE *)(v20 + 19) = v30 & 0xF8 | 2;
      }
      v31 = *(_DWORD *)(v20 + 8);
      if ( (v31 & 0x400) != 0 )
        v32 = (*(unsigned __int16 *)((*(_DWORD *)(v20 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v20 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
      else
        v32 = (v31 >> 5) & 0x1F;
      v33 = v32 & 0xFFFFFFE7;
      v103 = v32 & 0xFFFFFFE7;
      if ( v29 >> 6 )
      {
        if ( v29 >> 6 != 2 )
          goto LABEL_75;
        v34 = v33 | 0x18;
      }
      else
      {
        v34 = v33 | 8;
      }
      v103 = v34;
LABEL_75:
      v18 = (MiDetermineUserGlobalPteMask(0) | MmProtectToPteMask[v103] & 0xDED | (v24 << 12)) & 0xFFFFFDFF | 0x12;
      if ( v17 + 0x40000000 > v112 )
      {
        *(_DWORD *)v17 = v18;
      }
      else
      {
        v35 = 0;
        v109 = 0;
        v36 = *(_DWORD *)v17;
        __dmb(0xBu);
        *(_DWORD *)v17 = v18;
        if ( (v36 & 2) == 0 )
        {
          v35 = 1;
          v109 = 1;
        }
        if ( v17 + 1070596096 <= 0xFFF )
        {
          v37 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v37, (_DWORD *)(v37 + 4 * (v17 & 0xFFF)), v18);
          v35 = v109;
        }
        if ( v35 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
LABEL_83:
      __dmb(0xBu);
      v38 = (unsigned int *)(v20 + 12);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 & 0x7FFFFFFF, v38) );
      MiUnlockProtoPoolPage(v108, (unsigned __int8)v101[0]);
LABEL_198:
      v111 = KfRaiseIrql(2);
      v82 = v119;
      v83 = (unsigned __int8 *)(v119 + 15);
      do
        v84 = __ldrex(v83);
      while ( __strex(v84 | 0x80, v83) );
      __dmb(0xBu);
      if ( v84 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v85 = *(_DWORD *)(v82 + 12);
            __dmb(0xBu);
          }
          while ( (v85 & 0x80000000) != 0 );
          do
            v86 = __ldrex(v83);
          while ( __strex(v86 | 0x80, v83) );
          __dmb(0xBu);
        }
        while ( v86 >> 7 );
      }
      *(_DWORD *)(v82 + 12) = *(_DWORD *)(v82 + 12) & 0xC0000000 | ((*(_DWORD *)(v82 + 12) & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
      __dmb(0xBu);
      v87 = (unsigned int *)(v82 + 12);
      do
        v88 = __ldrex(v87);
      while ( __strex(v88 & 0x7FFFFFFF, v87) );
      v110 = (unsigned int)&dword_634E00;
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634E00);
      }
      else
      {
        v109 = 0;
        do
          v89 = __ldrex((unsigned __int8 *)&dword_634E00 + 3);
        while ( __strex(v89 | 0x80, (unsigned __int8 *)&dword_634E00 + 3) );
        __dmb(0xBu);
        if ( v89 >> 7 )
        {
          v90 = ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_634E00);
          v109 = v90;
        }
        else
        {
          v90 = 0;
        }
        v91 = (unsigned int *)v110;
        while ( 1 )
        {
          v92 = *v91;
          if ( (*v91 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v92 & 0x40000000) == 0 )
          {
            do
              v93 = __ldrex(v91);
            while ( v93 == v92 && __strex(v92 | 0x40000000, v91) );
            __dmb(0xBu);
            v90 = v109;
          }
          v109 = ++v90;
          __dmb(0xAu);
          __yield();
        }
      }
      if ( (*(_DWORD *)v7 & 2) != 0 )
        goto LABEL_227;
      if ( (*(_DWORD *)v7 & 0x200) != 0 )
      {
        v18 = (dword_681114 & 0x3ED | (v18 >> 12 << 12) | MiDetermineUserGlobalPteMask(v7)) & 0xFFFFF3FF | 0x12;
        v102 |= 1u;
      }
      v94 = v18 & 0xFFFFF7DF;
      v95 = *(_DWORD *)(v20 + 8);
      if ( !MiAllocateWsle((int)&dword_634E00, v7, v20, v118, v94, 0) )
      {
LABEL_227:
        MiUnlockWorkingSetExclusive(&dword_634E00, v111);
        MiLockAndDecrementShareCount(v20, 0);
        MiLockAndDecrementShareCount(v119, 0);
        v5 = v104;
        a2 = v107;
        v23 = v102;
        v6 = v106;
        a1 = v105;
        goto LABEL_232;
      }
      MiUnlockWorkingSetExclusive(&dword_634E00, v111);
      if ( PfSnNumActiveTraces && (v95 & 0x400) != 0 )
      {
        v96 = (_DWORD *)(v95 & 0xFFFFF800 | (2 * (v95 & 0x3FC)));
        v97 = *v96;
        v98 = MI_REFERENCE_CONTROL_AREA_FILE(*v96);
        v99 = MiStartingOffset(v96, v17, -1);
        PfSnLogPageFault(v98, 4, v99, HIDWORD(v99), 4);
        MI_DEREFERENCE_CONTROL_AREA_FILE(v97, v98);
        v5 = v104;
        a2 = v107;
        v23 = v102;
        v6 = v106;
        a1 = v105;
        goto LABEL_232;
      }
LABEL_52:
      v5 = v104;
      a2 = v107;
      v23 = v102;
      v6 = v106;
      a1 = v105;
      goto LABEL_232;
    }
    MiUnlockProtoPoolPage(v108, (unsigned __int8)v101[0]);
  }
  v62 = (unsigned __int8 *)(v20 + 15);
  do
    v63 = __ldrex(v62);
  while ( __strex(v63 | 0x80, v62) );
  __dmb(0xBu);
  if ( v63 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v64 = *(_DWORD *)(v20 + 12);
        __dmb(0xBu);
      }
      while ( (v64 & 0x80000000) != 0 );
      do
        v65 = __ldrex(v62);
      while ( __strex(v65 | 0x80, v62) );
      __dmb(0xBu);
    }
    while ( v65 >> 7 );
  }
  MiInitializePfn(v20, v17, v61, 3);
  if ( (a5 & 2) != 0 )
  {
    v66 = *(_BYTE *)(v20 + 19);
    if ( (v66 & 8) != 0 || (v66 & 7u) > 2 )
      *(_BYTE *)(v20 + 19) = v66 & 0xF8 | 2;
  }
  v67 = (unsigned int *)(v120 + 36);
  v110 = v120 + 36;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v67);
  }
  else
  {
    v115 = 0;
    v68 = (unsigned __int8 *)(v120 + 39);
    do
      v69 = __ldrex(v68);
    while ( __strex(v69 | 0x80, v68) );
    __dmb(0xBu);
    if ( v69 >> 7 )
    {
      v115 = ExpWaitForSpinLockExclusiveAndAcquire(v67);
      v67 = (unsigned int *)v110;
    }
    for ( i = v115; ; ++i )
    {
      v110 = *v67;
      if ( (v110 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v110 & 0x40000000) == 0 )
      {
        v71 = v110 | 0x40000000;
        v72 = v110;
        do
          v73 = __ldrex(v67);
        while ( v73 == v72 && __strex(v71, v67) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v20 = v111;
    v49 = v102;
  }
  v74 = v120;
  ++*(_DWORD *)(v120 + 16);
  if ( *(_DWORD *)(v74 + 32) )
    ++*(_DWORD *)(v109 + 64);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v74 + 36);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v74 + 36) = 0;
  }
  v110 = (v49 >> 4) & 1;
  if ( v110 )
  {
    v18 = (MiDetermineUserGlobalPteMask(0) | (v108 << 12)) & 0xFFFFFDFF | MmProtectToPteMask[v116] & 0x5ED | 0x812;
    if ( v17 + 0x40000000 > v112 )
    {
      *(_DWORD *)v17 = v18;
    }
    else
    {
      v75 = 0;
      v111 = 0;
      v76 = *(_DWORD *)v17;
      __dmb(0xBu);
      *(_DWORD *)v17 = v18;
      if ( (v76 & 2) == 0 && (v18 & 2) != 0 )
      {
        v75 = 1;
        v111 = 1;
      }
      if ( v17 + 1070596096 <= 0xFFF )
      {
        v77 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v77, (_DWORD *)(v77 + 4 * (v17 & 0xFFF)), v18);
        v75 = v111;
      }
      if ( v75 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  else
  {
    if ( v103 )
    {
      memset(v134, 0, sizeof(v134));
      MiIdentifyPfn(v20, v134);
    }
    v18 = 32 * (v116 & 0x1F | (v108 << 7) | 0x40);
    if ( v17 + 0x40000000 > v112 )
    {
      *(_DWORD *)v17 = v18;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v17 = v18;
      if ( v17 + 1070596096 <= 0xFFF )
      {
        v78 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v78, (_DWORD *)(v78 + 4 * (v17 & 0xFFF)), v18);
      }
    }
    v79 = *(_DWORD *)(v20 + 12);
    if ( (*(_BYTE *)(v20 + 18) & 7) != 6 )
      KeBugCheckEx(78, 153, (v20 - MmPfnDatabase) / 24);
    *(_DWORD *)(v20 + 12) = v79 & 0xC0000000 | ((v79 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
    if ( (v79 & 0x3FFFFFFF) == 1 )
      MiPfnShareCountIsZero(v20, 0);
  }
  __dmb(0xBu);
  v80 = (unsigned int *)(v20 + 12);
  do
    v81 = __ldrex(v80);
  while ( __strex(v81 & 0x7FFFFFFF, v80) );
  MiUnlockProtoPoolPage(v121, (unsigned __int8)v101[0]);
  if ( v110 )
    goto LABEL_198;
  if ( v103 )
  {
    v134[4] |= 4u;
    v135 = v134;
    v136 = 0;
    v137 = 24;
    v138 = 0;
    EtwTraceKernelEvent(&v135, 1, 536870913, 642, 289413890);
  }
  v23 = v102;
  if ( (v102 & 8) != 0 )
  {
    v5 = v104;
    a2 = v107;
    v6 = v106;
    a1 = v105;
    goto LABEL_232;
  }
  return 0;
}
