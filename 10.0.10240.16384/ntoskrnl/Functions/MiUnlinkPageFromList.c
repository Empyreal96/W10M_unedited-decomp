// MiUnlinkPageFromList 
 
int __fastcall MiUnlinkPageFromList(int a1, int a2)
{
  int v2; // r4
  int v3; // r2
  int v4; // lr
  __int16 *v5; // r9
  int v6; // r2
  unsigned int *v7; // r6
  unsigned int v8; // r3
  int v9; // r8
  int v10; // r10
  unsigned int v11; // r3
  int v12; // r6
  int v13; // r7
  unsigned int v14; // r0
  unsigned int v15; // r1
  int *v16; // r0
  unsigned int v17; // r2
  unsigned int *v18; // r7
  unsigned int v19; // r1
  unsigned int v20; // r7
  unsigned int v21; // lr
  unsigned int v22; // r3
  int v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r3
  int v26; // r2
  int v27; // r3
  int v28; // r2
  unsigned int *v29; // r3
  unsigned int v30; // r0
  unsigned int v31; // r1
  unsigned int *v32; // r9
  unsigned int v33; // r3
  int v34; // r2
  int v35; // r0
  unsigned int *v36; // r1
  int *v37; // r0
  unsigned int *v38; // r2
  unsigned int v39; // r4
  unsigned int v40; // r4
  unsigned int v42; // r2
  unsigned int v43; // r1
  unsigned int *v44; // r6
  unsigned int v45; // r1
  unsigned int v46; // r3
  int v47; // r2
  unsigned int *v48; // r3
  unsigned int v49; // r0
  unsigned int v50; // r1
  unsigned int *v51; // r9
  unsigned int v52; // r3
  unsigned int v53; // r1
  unsigned int *v54; // r2
  int v55; // r2
  unsigned int *v56; // r8
  int v57; // r0
  int v58; // lr
  unsigned int v59; // r7
  unsigned int v60; // r1
  unsigned int *v61; // lr
  unsigned int v62; // r1
  int v63; // lr
  unsigned int *v64; // r5
  int v65; // r1
  unsigned int v66; // r4
  unsigned int *v67; // r2
  unsigned int v68; // r0
  int *v69; // r2
  unsigned int v70; // r1
  unsigned int v71; // r0
  unsigned int v72; // r1
  unsigned int v73; // r1
  unsigned int v74; // r9
  unsigned int v75; // r0
  unsigned int v76; // r1
  unsigned int v77; // r9
  unsigned int v78; // r0
  unsigned int v79; // r1
  unsigned int v80; // r5
  unsigned int *v81; // r6
  int v82; // r2
  int v83; // r2
  int v84; // r4
  int v85; // r2
  unsigned int v86; // r0
  unsigned int v87; // r3
  unsigned int v88; // r0
  unsigned int v89; // r0
  unsigned int v90; // r1
  int v91; // r3
  int v92; // [sp+8h] [bp-48h]
  int v93; // [sp+Ch] [bp-44h]
  unsigned int *v94; // [sp+Ch] [bp-44h]
  unsigned int *v95; // [sp+Ch] [bp-44h]
  int v98; // [sp+1Ch] [bp-34h]
  int v99; // [sp+20h] [bp-30h]
  int v100; // [sp+28h] [bp-28h] BYREF
  unsigned int *v101; // [sp+2Ch] [bp-24h]
  int v102; // [sp+30h] [bp-20h]

  v2 = a1;
  v3 = *(unsigned __int16 *)(a1 + 16);
  v4 = a2;
  v100 = 0;
  v101 = 0;
  v102 = 0;
  if ( v3 )
  {
    if ( (*(_DWORD *)(a1 + 12) & 0x3FFFFFFF) != 0 )
      sub_533670();
    return 1;
  }
  v5 = MiSystemPartition;
  v6 = *(_BYTE *)(a1 + 18) & 7;
  v7 = *(unsigned int **)&MiSystemPartition[2 * v6 + 1226];
  v8 = v7[1];
  if ( v6 == 5 )
  {
    MiUnlinkPageFromBadList(a1, a2, 5, v8);
    return 1;
  }
  v9 = 0;
  v98 = 1;
  v10 = 0;
  v92 = 0;
  if ( v8 == 2 )
  {
    v11 = *(unsigned __int8 *)(a1 + 19);
    v12 = (v11 >> 3) & 1;
    if ( v12 == 1 )
      v13 = 5;
    else
      v13 = v11 & 7;
    v93 = v13;
    v14 = (a1 - MmPfnDatabase) / 24;
    v15 = dword_634690;
    if ( v14 < dword_634690 || v14 >= dword_634690 + 2048 )
    {
      v10 = 0;
      if ( v12 == 1 )
        v92 = 1;
      if ( (*(_DWORD *)(v2 + 20) & 0x8000000) != 0 )
      {
        v16 = MiState;
        do
          v17 = __ldrex((unsigned int *)&dword_634680);
        while ( __strex(v17 - 1, (unsigned int *)&dword_634680) );
        v15 = dword_634690;
      }
      else
      {
        do
          v53 = __ldrex(dword_640300);
        while ( __strex(v53 - 1, dword_640300) );
        v16 = MiState;
        v15 = dword_634690;
      }
    }
    else
    {
      v16 = MiState;
      v10 = 1;
    }
    v7 = (unsigned int *)&dword_63FD00[5 * v13];
    if ( !v4 )
    {
      v18 = v7 + 4;
      v100 = 0;
      v101 = v7 + 4;
      __dmb(0xBu);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireQueuedSpinLockInstrumented(&v100, v7 + 4);
        v15 = dword_634690;
      }
      else
      {
        do
          v19 = __ldrex(v18);
        while ( __strex((unsigned int)&v100, v18) );
        __dmb(0xBu);
        if ( v19 )
        {
          KxWaitForLockOwnerShip(&v100);
          v15 = dword_634690;
        }
        else
        {
          v15 = v16[1796];
        }
      }
    }
    v20 = *(_DWORD *)v2;
    v21 = *(_DWORD *)(v2 + 12) & 0xFFFFF;
    if ( v92 == 1 )
    {
      if ( v20 >= v15 && v21 == v20 && v20 < v15 + 2048 )
      {
        MiDeleteParentDecayNode(v2);
        v24 = v93;
        v21 = 0xFFFFF;
        v20 = 0xFFFFF;
      }
      else
      {
        v54 = (unsigned int *)(MmPfnDatabase + 24 * v21);
        if ( v21 < v15 || v21 >= v15 + 2048 )
          *v54 = v20;
        else
          v54[2] = v54[2] & 0xFFF | (v20 << 12);
        v55 = MmPfnDatabase + 24 * v20;
        if ( v20 < dword_634690 || v20 >= dword_634690 + 2048 )
        {
          v56 = (unsigned int *)(v55 + 12);
          v57 = *(_DWORD *)(v55 + 12);
          v58 = v21 & 0xFFFFF;
          do
            v59 = __ldrex(v56);
          while ( v59 == v57 && __strex(v57 & 0xFFF00000 | v58, v56) );
          if ( v57 != v59 )
          {
            do
            {
              v71 = v59;
              do
                v72 = __ldrex(v56);
              while ( v72 == v59 && __strex(v59 & 0xFFF00000 | v58, v56) );
              v59 = v72;
            }
            while ( v71 != v72 );
          }
          v24 = v93;
          v20 = 0xFFFFF;
          v21 = 0xFFFFF;
        }
        else
        {
          v24 = v93;
          v20 = 0xFFFFF;
          *(_DWORD *)(v55 + 20) = *(_DWORD *)(v55 + 20) & 0xFFF00000 | v21 & 0xFFFFF;
          v21 = 0xFFFFF;
        }
      }
    }
    else
    {
      if ( v20 == 0xFFFFF )
      {
        v24 = v93;
      }
      else if ( v20 < v15 || v20 >= v15 + 2048 )
      {
        v22 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v20 + 19);
        if ( ((v22 >> 3) & 1) == 1 )
          v23 = 5;
        else
          v23 = v22 & 7;
        v24 = v93;
        if ( v93 != v23 )
          KeBugCheckEx(26, 34950, v2);
      }
      else
      {
        v24 = v93;
      }
      if ( v21 != 0xFFFFF && (v21 < v15 || v21 >= v15 + 2048) )
      {
        v25 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v21 + 19);
        v26 = ((v25 >> 3) & 1) == 1 ? 5 : v25 & 7;
        if ( v24 != v26 )
          KeBugCheckEx(26, 34951, v2);
      }
    }
    v9 = 1;
    if ( v24 < dword_634348 )
      v98 = 0;
    goto LABEL_31;
  }
  if ( v8 != 3 )
  {
    if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
    {
      v69 = &dword_634680;
      do
        v70 = __ldrex((unsigned int *)&dword_634680);
      while ( __strex(v70 - 1, (unsigned int *)&dword_634680) );
    }
    else
    {
      v69 = (int *)dword_640300;
      do
        v73 = __ldrex(dword_640300);
      while ( __strex(v73 - 1, dword_640300) );
    }
    if ( !v4 )
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v7 + 4, &v100, v69, 0);
    goto LABEL_74;
  }
  do
    v42 = __ldrex(v7);
  while ( __strex(v42 - 1, v7) );
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
  {
    do
      v60 = __ldrex((unsigned int *)&dword_634680);
    while ( __strex(v60 - 1, (unsigned int *)&dword_634680) );
  }
  else
  {
    do
      v43 = __ldrex(dword_640300);
    while ( __strex(v43 - 1, dword_640300) );
  }
  if ( (*(_DWORD *)(a1 + 8) & 0x400) == 0 )
  {
    if ( !v4 )
    {
      v44 = v7 + 4;
      v100 = 0;
      v101 = v44;
      __dmb(0xBu);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireQueuedSpinLockInstrumented(&v100, v44);
      }
      else
      {
        do
          v45 = __ldrex(v44);
        while ( __strex((unsigned int)&v100, v44) );
        __dmb(0xBu);
        if ( v45 )
          KxWaitForLockOwnerShip(&v100);
      }
    }
    --dword_640718;
    v46 = *(_DWORD *)(v2 + 8);
    v47 = (v46 >> 2) & 1;
    if ( (v46 & 8) != 0 || v47 == dword_63F99C )
      v7 = (unsigned int *)((char *)&unk_63FE80 + 20 * v47);
    else
      v7 = (unsigned int *)&dword_63FE00;
LABEL_74:
    v20 = *(_DWORD *)v2;
    v21 = *(_DWORD *)(v2 + 12) & 0xFFFFF;
    goto LABEL_31;
  }
  v7 = (unsigned int *)((char *)&unk_63FF00 + 20 * (*(_DWORD *)(a1 + 20) >> 28));
  v99 = MiPageToNode();
  if ( !a2 )
  {
    v61 = v7 + 4;
    v100 = 0;
    v101 = v7 + 4;
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireQueuedSpinLockInstrumented(&v100, v7 + 4);
    }
    else
    {
      do
        v62 = __ldrex(v61);
      while ( __strex((unsigned int)&v100, v61) );
      __dmb(0xBu);
      if ( v62 )
        KxWaitForLockOwnerShip(&v100);
    }
  }
  v63 = *(_DWORD *)(v2 + 12);
  v20 = *(_DWORD *)v2;
  *(_DWORD *)(v2 + 20) = *(_DWORD *)(v2 + 20) & 0xFFFFFFF | (v99 << 28);
  v21 = v63 & 0xFFFFF;
LABEL_31:
  if ( v20 != 0xFFFFF )
  {
    v27 = MmPfnDatabase + 24 * v20;
    v28 = v21 & 0xFFFFF;
    if ( v9 == 1 )
    {
      v29 = (unsigned int *)(v27 + 12);
      v30 = *v29;
      v94 = v29;
      v31 = *v29 & 0xFFF00000 | v28;
      v32 = v29;
      do
        v33 = __ldrex(v32);
      while ( v33 == v30 && __strex(v31, v32) );
      v5 = MiSystemPartition;
      if ( v30 == v33 )
        goto LABEL_37;
      v74 = v33;
      do
      {
        v75 = v74;
        do
          v76 = __ldrex(v94);
        while ( v76 == v74 && __strex(v74 & 0xFFF00000 | v21 & 0xFFFFF, v94) );
        v74 = v76;
      }
      while ( v75 != v76 );
    }
    else
    {
      v48 = (unsigned int *)(v27 + 12);
      v49 = *v48;
      v95 = v48;
      v50 = *v48 & 0xFFF00000 | v28;
      v51 = v48;
      do
        v52 = __ldrex(v51);
      while ( v52 == v49 && __strex(v50, v51) );
      v5 = MiSystemPartition;
      if ( v49 == v52 )
        goto LABEL_37;
      v77 = v52;
      do
      {
        v78 = v77;
        do
          v79 = __ldrex(v95);
        while ( v79 == v77 && __strex(v77 & 0xFFF00000 | v21 & 0xFFFFF, v95) );
        v77 = v79;
      }
      while ( v78 != v79 );
    }
    v2 = a1;
    v5 = MiSystemPartition;
LABEL_37:
    v34 = v92;
    goto LABEL_38;
  }
  v34 = v92;
  if ( !v92 )
    v7[3] = v21;
LABEL_38:
  if ( v21 == 0xFFFFF )
  {
    if ( !v34 )
      v7[2] = v20;
  }
  else
  {
    *(_DWORD *)(MmPfnDatabase + 24 * v21) = v20;
    v34 = v92;
  }
  if ( !v10 )
  {
    --*v7;
    if ( v34 == 1 && v9 == 1 )
      *(_BYTE *)(v2 + 19) &= 0xF7u;
  }
  *(_DWORD *)v2 = 0;
  if ( v10 )
  {
    v64 = (unsigned int *)(v2 + 12);
    v65 = *(_DWORD *)(v2 + 12);
    do
      v66 = __ldrex(v64);
    while ( v66 == v65 && __strex(v65 & 0xFFF00000, v64) );
    if ( v65 != v66 )
    {
      do
      {
        v89 = v66;
        do
          v90 = __ldrex(v64);
        while ( v90 == v66 && __strex(v66 & 0xFFF00000, v64) );
        v66 = v90;
      }
      while ( v89 != v90 );
    }
  }
  else
  {
    *(_DWORD *)(v2 + 12) &= 0xFFF00000;
    if ( dword_634380 != 1 )
      goto LABEL_44;
    LOBYTE(v80) = 1;
    v81 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * ((unsigned int)((v2 - MmPfnDatabase) / 24) >> 5));
    v82 = ((v2 - MmPfnDatabase) / 24) & 0x1F;
    if ( (unsigned int)(v82 + 1) <= 0x20 )
    {
      __dmb(0xBu);
      v83 = 1 << v82;
      do
LABEL_175:
        v88 = __ldrex(v81);
      while ( __strex(v88 | v83, v81) );
      __dmb(0xBu);
      goto LABEL_44;
    }
    if ( !v82 )
      goto LABEL_174;
    v84 = 32 - v82;
    __dmb(0xBu);
    v85 = ((1 << (32 - v82)) - 1) << v82;
    do
      v86 = __ldrex(v81);
    while ( __strex(v86 | v85, v81) );
    __dmb(0xBu);
    v80 = 1 - v84;
    ++v81;
    if ( (unsigned int)(1 - v84) >= 0x20 )
    {
      v87 = v80 >> 5;
      do
      {
        v80 -= 32;
        --v87;
        *v81++ = -1;
      }
      while ( v87 );
    }
    if ( v80 )
    {
LABEL_174:
      __dmb(0xBu);
      v83 = (1 << v80) - 1;
      goto LABEL_175;
    }
  }
LABEL_44:
  if ( !a2 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v100);
    }
    else
    {
      v35 = v100;
      if ( !v100 )
      {
        v36 = v101;
        __dmb(0xBu);
        do
          v37 = (int *)__ldrex(v36);
        while ( v37 == &v100 && __strex(0, v36) );
        if ( v37 == &v100 )
          goto LABEL_51;
        v35 = KxWaitForLockChainValid(&v100);
      }
      v100 = 0;
      __dmb(0xBu);
      v67 = (unsigned int *)(v35 + 4);
      do
        v68 = __ldrex(v67);
      while ( __strex(v68 ^ 1, v67) );
    }
  }
LABEL_51:
  if ( v9 == 1 && !v10 )
  {
    v38 = (unsigned int *)(v5 + 1856);
    do
    {
      v39 = __ldrex(v38);
      v40 = v39 - 1;
    }
    while ( __strex(v40, v38) );
    if ( v40 == *((_DWORD *)v5 + 747) || v40 == *((_DWORD *)v5 + 748) )
      MiUpdateAvailableEvents(v5);
    if ( v40 <= 0x400 )
    {
      v91 = *((_DWORD *)v5 + 878);
      if ( !v91 || !*(_BYTE *)(v91 + 44) )
        MiObtainFreePages(v5);
    }
  }
  return v98;
}
