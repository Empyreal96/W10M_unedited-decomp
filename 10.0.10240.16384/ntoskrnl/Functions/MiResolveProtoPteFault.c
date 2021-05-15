// MiResolveProtoPteFault 
 
int __fastcall MiResolveProtoPteFault(int a1, unsigned int a2, unsigned int a3, int a4, unsigned __int8 a5, unsigned int a6, int a7, _DWORD *a8)
{
  unsigned int v8; // r2
  int v9; // r6
  int v10; // r9
  unsigned int v11; // r4
  _DWORD *v12; // r10
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r5
  unsigned int v17; // r0
  int v18; // r3
  _WORD *v19; // r7
  int v20; // r6
  int v21; // r4
  unsigned int *v22; // r1
  unsigned int v23; // r0
  unsigned __int8 *v24; // r1
  unsigned int v25; // r2
  int v26; // r2
  char v27; // r1
  int v28; // r7
  int v29; // r3
  int v30; // r2
  int v31; // r4
  unsigned int v32; // r1
  unsigned int v33; // r2
  unsigned int v34; // r0
  int v35; // lr
  unsigned int v36; // r3
  unsigned int *v37; // r6
  int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r0
  unsigned int *v41; // r1
  unsigned int v42; // r4
  unsigned int *v43; // r0
  unsigned int v44; // r2
  int v45; // r4
  int v46; // r6
  unsigned int v47; // r9
  int v48; // r7
  char v49; // r1
  int v50; // r1
  unsigned int v51; // r7
  int v53; // r6
  int v54; // r6
  unsigned int v55; // r0
  int v56; // r3
  int v57; // r2
  int v58; // r3
  int v59; // r2
  int v60; // r4
  int v61; // r3
  unsigned int v62; // r2
  unsigned __int8 *v63; // r1
  int v64; // r3
  unsigned int v65; // r0
  int v66; // r0
  int v67; // r2
  int v68; // r6
  unsigned int *v69; // r2
  unsigned int v70; // r0
  unsigned int v71; // r2
  unsigned int v72; // r0
  unsigned int v73; // r4
  unsigned int v74; // r3
  int v75; // r5
  int v76; // r0
  unsigned int v77; // r3
  int v78; // r5
  int v79; // r0
  unsigned int *v80; // r2
  unsigned int v81; // r0
  int v82; // r0
  int v84; // [sp+14h] [bp-3Ch]
  unsigned int v87; // [sp+24h] [bp-2Ch]
  _DWORD *v88; // [sp+28h] [bp-28h]

  v8 = a7;
  v9 = MmPfnDatabase;
  v10 = MmPfnDatabase + 24 * (*(_DWORD *)(((a6 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
  v84 = v10;
  if ( (a7 & 1) == 0 || (v87 = a7 & 0xFFFFFFFE, *(_BYTE *)(a7 & 0xFFFFFFFE) != 1) )
    v87 = 0;
  while ( 1 )
  {
    v11 = *(_DWORD *)a6;
    if ( (*(_DWORD *)a6 & 2) == 0 && ((v11 & 0x400) != 0 || (v11 & 0x800) == 0) )
      break;
    if ( MI_IS_PFN(v11 >> 12) )
    {
      v12 = (_DWORD *)(v9 + 24 * (v11 >> 12));
      v88 = v12;
      v13 = (unsigned __int8 *)v12 + 15;
      do
      {
        v14 = __ldrex(v13);
        v8 = __strex(v14 | 0x80, v13);
      }
      while ( v8 );
      __dmb(0xBu);
      if ( v14 >> 7 )
      {
        v63 = (unsigned __int8 *)v12 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v64 = v12[3];
            __dmb(0xBu);
          }
          while ( (v64 & 0x80000000) != 0 );
          do
            v8 = __ldrex(v63);
          while ( __strex(v8 | 0x80, v63) );
          __dmb(0xBu);
        }
        while ( v8 >> 7 );
      }
      if ( *(_DWORD *)a6 == v11 )
        goto LABEL_9;
      __dmb(0xBu);
      v8 = (unsigned int)(v12 + 3);
      do
        v65 = __ldrex((unsigned int *)v8);
      while ( __strex(v65 & 0x7FFFFFFF, (unsigned int *)v8) );
      v9 = MmPfnDatabase;
    }
  }
  v12 = 0;
  v88 = 0;
LABEL_9:
  v15 = *(_DWORD *)a6;
  if ( (*(_DWORD *)a6 & 2) != 0 )
  {
    if ( v87 )
      return sub_535528(2048, &MmHighestUserAddress, v8, 1024);
    v17 = a2;
    if ( a2 < dword_63389C || (MiFlags & 0x30000) != 0 )
    {
      v18 = v12[5];
      if ( (v18 & 0x8000000) != 0 && (v12[2] & 0x400) != 0 && (v18 & 0x7000000) != 50331648 )
      {
        v19 = (_WORD *)(v12[2] & 0xFFFFF800 | (2 * (v12[2] & 0x3FC)));
        v20 = *(_DWORD *)v19;
        if ( (*(_DWORD *)(*(_DWORD *)v19 + 28) & 0x20) != 0 )
        {
          if ( (BYTE2(MiFlags) & 3u) > 1
            && ((*(unsigned __int16 *)((v12[2] & 0xFFFFF800 | (2 * (v12[2] & 0x3FC))) + 0x10) >> 1) & 2) == 0 )
          {
            if ( MiCanPageMove((int)v12) )
              goto LABEL_19;
            v17 = a2;
          }
          v21 = *(_DWORD *)(*(_DWORD *)(v20 + 56) + 4);
          if ( v21 )
          {
            if ( (v21 & 0xFFFFFFF8) != 8 && (*(_DWORD *)(*(_DWORD *)(v20 + 56) + 4) & 3) != 2 )
            {
              if ( (MiFlags & 0x100000) == 0 || (*(_DWORD *)(v20 + 52) & 0xC000000) == 0 )
              {
                v66 = MiLocateAddress(v17);
                if ( v66 )
                {
                  v67 = *(_DWORD *)(v66 + 28);
                  if ( (v67 & 7) == 2
                    && ((v67 & 0xF8) == 8
                     || (*(_DWORD *)(v66 + 40) & 0x10000000) != 0 && (v21 & 4) == 0
                     || (MiFlags & 0x400) != 0 && (v19[9] & 2) != 0) )
                  {
                    goto LABEL_19;
                  }
                }
                v17 = a2;
              }
              if ( (a7 & 1) != 0 && *(_BYTE *)(a7 & 0xFFFFFFFE) == 1 )
              {
                v45 = -1073740748;
                v68 = v10;
                goto LABEL_156;
              }
              v68 = v10;
              v45 = MiMakeImagePageOk(v17, a6, v15, a4, v12, v10);
              if ( v45 < 0 )
              {
LABEL_156:
                __dmb(0xBu);
                v69 = v12 + 3;
                do
                  v70 = __ldrex(v69);
                while ( __strex(v70 & 0x7FFFFFFF, v69) );
                MiUnlockProtoPoolPage(v68, 17);
                return v45;
              }
            }
          }
        }
      }
    }
LABEL_19:
    v12[3] = v12[3] & 0xC0000000 | ((v12[3] & 0x3FFFFFFF) + 1) & 0x3FFFFFFF;
    __dmb(0xBu);
    v22 = v12 + 3;
    do
      v23 = __ldrex(v22);
    while ( __strex(v23 & 0x7FFFFFFF, v22) );
    v24 = (unsigned __int8 *)(v10 + 15);
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 | 0x80, v24) );
    __dmb(0xBu);
    if ( v25 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v61 = *(_DWORD *)(v10 + 12);
          __dmb(0xBu);
        }
        while ( (v61 & 0x80000000) != 0 );
        do
          v62 = __ldrex(v24);
        while ( __strex(v62 | 0x80, v24) );
        __dmb(0xBu);
      }
      while ( v62 >> 7 );
    }
    v26 = *(unsigned __int16 *)(v10 + 16);
    v27 = *(_BYTE *)(v10 + 18) & 0xDF;
    *(_BYTE *)(v10 + 18) = v27;
    if ( !v26 )
      KeBugCheckEx(78, 154, (v10 - MmPfnDatabase) / 24);
    v28 = *(_DWORD *)(v10 + 12);
    v29 = (unsigned __int16)(v26 - 1);
    *(_WORD *)(v10 + 16) = v29;
    v30 = v28 & 0x3FFFFFFF;
    if ( !v29 )
    {
      v31 = 1;
LABEL_29:
      v32 = (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000;
      v33 = *(_DWORD *)(v10 + 4) | 0x80000000;
      if ( v33 > v32 || v33 < 0xC0000000 )
      {
        v34 = *(unsigned __int8 *)(v10 + 19);
        if ( ((v34 >> 5) & 1) != 0 )
        {
          *(_BYTE *)(v10 + 19) = v34 & 0xDF;
          goto LABEL_40;
        }
      }
      if ( (*(_DWORD *)(v10 + 20) & 0x8000000) != 0 && (*(_DWORD *)(v10 + 8) & 0x400) != 0
        || v33 <= v32 && v33 >= 0xC0000000 && ((*(unsigned __int8 *)(v10 + 19) >> 5) & 1) != 0
        || v31 == 1 && (v28 & 0x40000000) != 0 )
      {
        MiReturnCommit(MiSystemPartition, 1);
      }
      v35 = 1;
      v36 = (unsigned int)KeGetPcr();
      v37 = (unsigned int *)((v36 & 0xFFFFF000) + 4992);
      v38 = *(_DWORD *)((v36 & 0xFFFFF000) + 0x1380);
      if ( v38 != -1 )
      {
        if ( (unsigned int)(v38 + 1) <= 0x100 )
        {
          do
          {
            do
              v39 = __ldrex(v37);
            while ( v39 == v38 && __strex(v38 + 1, v37) );
            if ( v39 == v38 )
              goto LABEL_39;
            v38 = v39;
          }
          while ( v39 != -1 && v39 + 1 <= 0x100 );
        }
        if ( v38 > 192 )
        {
          do
            v71 = __ldrex(v37);
          while ( v71 == v38 && __strex(0xC0u, v37) );
          if ( v71 == v38 )
            v35 = v38 - 191;
        }
      }
      do
        v72 = __ldrex((unsigned int *)&dword_640600);
      while ( __strex(v72 + v35, (unsigned int *)&dword_640600) );
      do
LABEL_39:
        v40 = __ldrex(&dword_634A2C[117]);
      while ( __strex(v40 + 1, &dword_634A2C[117]) );
LABEL_40:
      if ( v31 )
        MiPfnReferenceCountIsZero(v10, (v10 - MmPfnDatabase) / 24);
      goto LABEL_42;
    }
    if ( v29 == 1 )
    {
      if ( v30 || (v27 & 8) != 0 )
      {
LABEL_28:
        v31 = 0;
        goto LABEL_29;
      }
    }
    else if ( v29 == 2 && v30 && (v27 & 8) != 0 )
    {
      goto LABEL_28;
    }
LABEL_42:
    __dmb(0xBu);
    v41 = (unsigned int *)(v10 + 12);
    do
      v42 = __ldrex(v41);
    while ( __strex(v42 & 0x7FFFFFFF, v41) );
    v43 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2960);
    do
      v44 = __ldrex(v43);
    while ( __strex(v44 + 1, v43) );
    v45 = MiCompleteProtoPteFault(a4, a5, a2, v15, a1, 0, a7);
    if ( v45 >= 0 )
      v45 = 272;
    return v45;
  }
  if ( !v15 )
  {
    MiUnlockProtoPoolPage(v10, 17);
    return -1073741819;
  }
  LOBYTE(v46) = 0;
  v47 = *(_DWORD *)a3;
  v48 = *(_DWORD *)a3 >> 13;
  if ( v48 == 0x7FFFF )
  {
    v46 = (v47 >> 5) & 0x1F;
    goto LABEL_62;
  }
  if ( (v47 & 0x200) != 0 )
    goto LABEL_62;
  if ( (v15 & 0x400) != 0 )
    v46 = (*(unsigned __int16 *)((*(_DWORD *)a6 & 0xFFFFF800 | (2 * (*(_DWORD *)a6 & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v46 = (v15 >> 5) & 0x1F;
  v49 = a1;
  if ( (v15 & 2) != 0 )
  {
    if ( !a1 || (v15 & 0x180) != 0 )
      goto LABEL_62;
    v45 = -1073741819;
LABEL_211:
    if ( v88 )
    {
      __dmb(0xBu);
      v80 = v88 + 3;
      do
        v81 = __ldrex(v80);
      while ( __strex(v81 & 0x7FFFFFFF, v80) );
    }
    MiUnlockProtoPoolPage(v84, 17);
    return v45;
  }
  if ( a1 )
    v49 = 1;
  if ( MiReadWrite[v46 & 7] - v49 < 10 )
  {
    v45 = -1073741819;
    goto LABEL_211;
  }
  if ( (v46 & 0xFFFFFFF8) == 16 && ((a7 & 1) == 0 || *(_BYTE *)(a7 & 0xFFFFFFFE) != 1) )
  {
    if ( !MiAllowGuardFault(a7) )
    {
      v45 = -1073741819;
      goto LABEL_211;
    }
    if ( (v15 & 0x800) == 0 || (v15 & 0x400) != 0 )
    {
      v73 = v15 & 0xFFFFFC1F | (32 * (v46 & 0xF));
      if ( a6 + 0x40000000 <= 0x3FFFFF )
      {
        v77 = *(_DWORD *)a6;
        v78 = 0;
        __dmb(0xBu);
        *(_DWORD *)a6 = v73;
        if ( (v77 & 2) == 0 && (v73 & 2) != 0 )
          v78 = 1;
        if ( a6 + 1070596096 <= 0xFFF )
        {
          v79 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v79, v79 + 4 * (a6 & 0xFFF), v73);
        }
        if ( v78 != 1 )
          goto LABEL_210;
LABEL_208:
        __dsb(0xFu);
        __isb(0xFu);
LABEL_210:
        v45 = -2147483647;
        goto LABEL_211;
      }
    }
    else
    {
      v73 = v15 & 0xFFFFFC1F | (32 * (v46 & 0xF));
      if ( a6 + 0x40000000 <= 0x3FFFFF )
      {
        v74 = *(_DWORD *)a6;
        v75 = 0;
        __dmb(0xBu);
        *(_DWORD *)a6 = v73;
        if ( (v74 & 2) == 0 && (v73 & 2) != 0 )
          v75 = 1;
        if ( a6 + 1070596096 <= 0xFFF )
        {
          v76 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v76, v76 + 4 * (a6 & 0xFFF), v73);
        }
        if ( v75 != 1 )
          goto LABEL_210;
        goto LABEL_208;
      }
    }
    *(_DWORD *)a6 = v73;
    goto LABEL_210;
  }
LABEL_62:
  v50 = (v15 >> 10) & 1;
  if ( v50
    || (v15 & 0x800) != 0
    || (v15 & 0x10) != 0
    || (v46 & 5) != 5
    || !a1 && ((v15 >> 5) & 5) == 4
    || *(_DWORD *)(a4 + 92) == -1069539328
    && *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 272) )
  {
    v51 = dword_63389C;
    goto LABEL_65;
  }
  if ( (MiFlags & 0x30000) != 0 )
  {
    v51 = dword_63389C;
    if ( a2 < dword_63389C || (v46 & 2) == 0 )
    {
      v48 = v47 >> 13;
      goto LABEL_82;
    }
LABEL_65:
    if ( v50 )
    {
      v53 = v84;
      if ( a8 )
        return MiResolveMappedFileFault(a1, a2, a6, a4, a5, v84, a7, a8);
    }
    else
    {
      if ( (v15 & 0x800) != 0 )
        return MiResolveTransitionFault(a1, a2, a6, a4, a5, 1, a7, a8);
      if ( (v15 & 0x10) == 0 )
      {
        if ( v87 )
        {
          if ( (a7 & 1) == 0
            || (v60 = a7, *(_BYTE *)(a7 & 0xFFFFFFFE) != 1)
            || (*(_DWORD *)((a7 & 0xFFFFFFFE) + 40) & 0x4000) == 0 )
          {
            MiUnlockProtoPoolPage(v84, 17);
            v45 = 0;
            goto LABEL_105;
          }
        }
        else
        {
          v60 = a7;
        }
        if ( (a7 & 1) != 0 )
        {
          if ( *(_BYTE *)(v60 & 0xFFFFFFFE) != 1 && *(_BYTE *)(v60 & 0xFFFFFFFE) != 3 )
            goto LABEL_104;
        }
        else if ( KeInvalidAccessAllowed(v60) != 1 )
        {
LABEL_104:
          v45 = MiResolveDemandZeroFault(a1, a2, v60, a6, a4, a5, 1);
LABEL_105:
          if ( !a8 )
            return v45;
          *a8 = 0;
          return v45;
        }
        if ( a2 >= v51 )
        {
          MiUnlockProtoPoolPage(v84, 17);
          v45 = -1073741819;
          goto LABEL_105;
        }
        goto LABEL_104;
      }
      v53 = v84;
      if ( a8 )
        return MiResolvePageFileFault(a2, a6, a4, 1, v84, a7, a8);
    }
    MiUnlockProtoPoolPage(v53, 17);
    return -1073740748;
  }
LABEL_82:
  MiUnlockProtoPoolPage(v84, 17);
  if ( !v87 )
  {
    v54 = a7;
LABEL_84:
    if ( (a7 & 1) != 0 )
    {
      if ( *(_BYTE *)(v54 & 0xFFFFFFFE) != 1 && *(_BYTE *)(v54 & 0xFFFFFFFE) != 3 )
        goto LABEL_86;
    }
    else if ( KeInvalidAccessAllowed(v54) != 1 )
    {
LABEL_86:
      v55 = a2;
LABEL_87:
      v56 = (v47 >> 5) & 0x1F;
      if ( v48 != 0x7FFFF )
        v56 = (v15 >> 5) & 0x1F;
      if ( (v56 & 2) != 0 )
        v57 = 6;
      else
        v57 = 4;
      v58 = v56 & 0x18;
      if ( v58 == 8 )
      {
        v57 |= 8u;
      }
      else if ( v58 == 24 )
      {
        v57 |= 0x18u;
      }
      v59 = 32 * v57;
      if ( a3 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)a3 = v59;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)a3 = v59;
        if ( a3 >= 0xC0300000 && a3 <= 0xC0300FFF )
        {
          v82 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v82, v82 + 4 * (a3 & 0xFFF), v59);
          v55 = a2;
        }
      }
      return MiResolveDemandZeroFault(a1, v55, v54, a3, a4, a5, 0);
    }
    v55 = a2;
    if ( a2 < dword_63389C )
      goto LABEL_87;
    return -1073741819;
  }
  if ( (a7 & 1) != 0 )
  {
    v54 = a7;
    if ( *(_BYTE *)(a7 & 0xFFFFFFFE) == 1 && (*(_DWORD *)((a7 & 0xFFFFFFFE) + 40) & 0x4000) != 0 )
      goto LABEL_84;
  }
  return 0;
}
