// MiAllocateMostlyContiguous 
 
int __fastcall MiAllocateMostlyContiguous(__int16 *a1, int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, unsigned int a7)
{
  int v7; // r5
  unsigned int v8; // r8
  int v9; // r10
  int v11; // r9
  unsigned int v12; // r6
  unsigned int *v13; // r4
  int *v14; // r2
  unsigned int v15; // r10
  int v16; // r3
  unsigned __int8 *v17; // lr
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r5
  unsigned int v21; // r7
  unsigned int v22; // r7
  int v23; // r6
  int v24; // r10
  int v25; // r8
  unsigned __int8 *v26; // r1
  unsigned int v27; // r2
  __int16 *v28; // r1
  unsigned int v29; // r2
  unsigned int v30; // r5
  unsigned int *v31; // r2
  unsigned int v32; // r4
  int v33; // r5
  unsigned int *v34; // r2
  unsigned int v35; // r0
  int v36; // r0
  int v37; // r0
  int v38; // r5
  int v39; // r4
  unsigned int *v40; // r10
  unsigned int v41; // r1
  int v42; // r0
  unsigned __int8 *v43; // r1
  unsigned int v44; // r2
  unsigned int v45; // r2
  unsigned int *v46; // r2
  unsigned int v47; // r0
  unsigned __int8 *v48; // r1
  int v49; // r3
  unsigned int v50; // r2
  unsigned int *v51; // r2
  unsigned int v52; // r0
  unsigned __int8 *v53; // r1
  unsigned int v54; // r3
  unsigned int v55; // r2
  unsigned int v56; // r1
  unsigned int *v57; // r2
  unsigned int v58; // r0
  unsigned int *v59; // r2
  unsigned int v60; // r0
  unsigned int *v61; // r2
  unsigned int v62; // r0
  unsigned int v63; // r2
  unsigned int *v64; // r2
  unsigned int v65; // r0
  unsigned int *v66; // r2
  unsigned int v67; // r0
  unsigned int *v68; // r2
  unsigned int v69; // r4
  unsigned int v71; // [sp+14h] [bp-7Ch]
  int v72; // [sp+18h] [bp-78h]
  unsigned int *v73; // [sp+1Ch] [bp-74h]
  int v74; // [sp+24h] [bp-6Ch]
  unsigned int v75; // [sp+28h] [bp-68h]
  int v77; // [sp+34h] [bp-5Ch]
  int v79; // [sp+40h] [bp-50h]
  unsigned int *v81; // [sp+50h] [bp-40h]
  int v82; // [sp+58h] [bp-38h]
  char v83[4]; // [sp+60h] [bp-30h] BYREF
  int v84; // [sp+64h] [bp-2Ch]
  int v85; // [sp+6Ch] [bp-24h]

  v7 = a2;
  v8 = a3;
  v9 = (int)a1;
  if ( KeGetCurrentIrql(a1) == 2 )
    return sub_5502F4();
  MiCreatePteCopyList(v8, 0x40u, (int)v83);
  v11 = 0;
  if ( !v84 )
    return v11;
  v12 = a7;
  v13 = (unsigned int *)(v7 + 4 * ((*(_DWORD *)(v7 + 20) >> 12) + 7));
  v77 = 0;
  v74 = 0;
  v75 = a7;
  v73 = v13;
  if ( a7 >= (unsigned __int16)KeNumberNodes )
  {
    v12 = a7 | 0x80000000;
    v75 = a7 | 0x80000000;
  }
  v14 = (int *)MiReferencePageRuns(v9, 1);
  v15 = a5;
  v79 = (int)v14;
  v16 = *v14;
  if ( !*v14 )
    goto LABEL_53;
  v17 = (unsigned __int8 *)&v14[2 * *v14 + 2] + 2 * v16;
  v18 = (unsigned int *)&v14[2 * v16];
  while ( 1 )
  {
    v19 = v18[1];
    v20 = *v18;
    v17 -= 2;
    v81 = v18 - 2;
    v71 = *v18;
    v82 = v16 - 1;
    if ( (v12 & 0x80000000) == 0 && *v17 != v12 )
      goto LABEL_121;
    v21 = v19 + v20;
    if ( v19 + v20 - 1 > v15 )
      v21 = v15 + 1;
    if ( v20 < a4 )
    {
      v20 = a4;
      v71 = a4;
    }
    if ( v20 >= v21 )
      goto LABEL_121;
    v22 = v21 - 1;
    v23 = MmPfnDatabase + 24 * v22;
    if ( v22 >= v20 )
      break;
LABEL_120:
    v12 = v75;
LABEL_121:
    v16 = v82;
    v18 = v81;
    if ( !v82 )
      goto LABEL_53;
  }
  v24 = 24 * (v11 - v8);
  v72 = v24;
  while ( 1 )
  {
    if ( !v20 )
      goto LABEL_119;
    v25 = KfRaiseIrql(2);
    v26 = (unsigned __int8 *)(v23 + 15);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 | 0x80, v26) );
    __dmb(0xBu);
    if ( v27 >> 7 )
    {
      v48 = (unsigned __int8 *)(v23 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v49 = *(_DWORD *)(v23 + 12);
          __dmb(0xBu);
        }
        while ( (v49 & 0x80000000) != 0 );
        do
          v50 = __ldrex(v48);
        while ( __strex(v50 | 0x80, v48) );
        __dmb(0xBu);
      }
      while ( v50 >> 7 );
    }
    v28 = a1;
    if ( MiSystemPartition != a1 )
      goto LABEL_82;
    v29 = *(_BYTE *)(v23 + 18) & 7;
    if ( v29 == 5 )
    {
      if ( (*(_DWORD *)(v23 + 4) | 0x80000000) == -4 )
        goto LABEL_82;
      v38 = *(_DWORD *)(v23 + 20) >> 28 << byte_6337F5;
      v39 = dword_633814 & v22;
      __dmb(0xBu);
      v40 = (unsigned int *)(v23 + 12);
      do
        v41 = __ldrex(v40);
      while ( __strex(v41 & 0x7FFFFFFF, v40) );
      KfLowerIrql(v25);
      MiDrainZeroLookasides((int)a1, v72 + v23 + 24, a3 - v11, v38 | v39);
      v42 = KfRaiseIrql(2);
      v43 = (unsigned __int8 *)(v23 + 15);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 | 0x80, v43) );
      __dmb(0xBu);
      if ( v44 >> 7 )
      {
        v53 = (unsigned __int8 *)(v23 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v54 = *v40;
            __dmb(0xBu);
          }
          while ( (v54 & 0x80000000) != 0 );
          do
            v55 = __ldrex(v53);
          while ( __strex(v55 | 0x80, v53) );
          __dmb(0xBu);
        }
        while ( v55 >> 7 );
      }
      v25 = v42;
      v29 = *(_BYTE *)(v23 + 18) & 7;
      if ( v29 == 5 )
      {
        __dmb(0xBu);
        do
          v56 = __ldrex(v40);
        while ( __strex(v56 & 0x7FFFFFFF, v40) );
LABEL_96:
        KfLowerIrql(v42);
LABEL_51:
        v20 = v71;
LABEL_52:
        v8 = a3;
        goto LABEL_34;
      }
      v24 = v72;
      v13 = v73;
      v20 = v71;
      v28 = a1;
    }
    if ( v29 <= 1 )
      break;
    if ( !v85 || (*(_BYTE *)(v23 + 19) & 0x80) == 128 )
    {
      if ( v29 == 2 && !*(_WORD *)(v23 + 16) )
      {
        v63 = *((_DWORD *)v28 + 928);
        if ( v63 < 0x80 && ((*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 || v63 < 2) )
        {
          __dmb(0xBu);
          v68 = (unsigned int *)(v23 + 12);
          do
            v69 = __ldrex(v68);
          while ( __strex(v69 & 0x7FFFFFFF, v68) );
          goto LABEL_125;
        }
        MiReuseStandbyPage(v23);
        __dmb(0xBu);
        v64 = (unsigned int *)(v23 + 12);
        do
          v65 = __ldrex(v64);
        while ( __strex(v65 & 0x7FFFFFFF, v64) );
        KfLowerIrql(v25);
        goto LABEL_47;
      }
      __dmb(0xBu);
      v66 = (unsigned int *)(v23 + 12);
      do
        v67 = __ldrex(v66);
      while ( __strex(v67 & 0x7FFFFFFF, v66) );
      goto LABEL_117;
    }
    if ( v29 <= 4 )
    {
      if ( (*(_DWORD *)(v23 + 4) & 0x80000000) != 0 )
      {
        v37 = MiObtainTransitionPage(v23, v25, (int)v83, -1, 0);
        if ( v37 == 3 )
          goto LABEL_46;
        if ( v37 == 1 )
          goto LABEL_53;
        if ( v37 != 2 )
          goto LABEL_51;
        v23 += 24;
        ++v22;
        goto LABEL_52;
      }
LABEL_82:
      __dmb(0xBu);
      v51 = (unsigned int *)(v23 + 12);
      do
        v52 = __ldrex(v51);
      while ( __strex(v52 & 0x7FFFFFFF, v51) );
LABEL_117:
      KfLowerIrql(v25);
      goto LABEL_52;
    }
    if ( v29 != 6 )
      goto LABEL_82;
    if ( (*(_BYTE *)(v23 + 23) & 7) == 2 )
    {
      if ( (a6 & 8) != 0 || *(_DWORD *)v23 == -5 )
        goto LABEL_82;
      v33 = a6;
      if ( (*(_DWORD *)v23 & 1) == 0 )
        v77 = 1;
    }
    else
    {
      v30 = MiActivePageClaimCandidate(v23, 1);
      if ( v30 )
      {
        __dmb(0xBu);
        v31 = (unsigned int *)(v23 + 12);
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 & 0x7FFFFFFF, v31) );
        KfLowerIrql(v25);
        v8 = a3;
        if ( v30 > v22 - v71 )
        {
          v13 = v73;
LABEL_119:
          v15 = a5;
          goto LABEL_120;
        }
        v22 = v22 - v30 + 1;
        v23 = v23 - 24 * v30 + 24;
        goto LABEL_33;
      }
      v33 = a6;
      if ( (a6 & 8) != 0 )
      {
        __dmb(0xBu);
        v57 = (unsigned int *)(v23 + 12);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 & 0x7FFFFFFF, v57) );
        v42 = v25;
        goto LABEL_96;
      }
    }
    __dmb(0xBu);
    v34 = (unsigned int *)(v23 + 12);
    do
      v35 = __ldrex(v34);
    while ( __strex(v35 & 0x7FFFFFFF, v34) );
    v36 = KfLowerIrql(v25);
    if ( v77 == 1 )
    {
      MiEmptyKernelStackCache(v36);
      v77 = 0;
    }
    if ( MiClaimPhysicalRun(a1, v22, 1, (int)v83, v33, -1, 0) )
      goto LABEL_51;
    v8 = a3;
    ++v11;
    *v13 = v22;
    v72 = v24 + 24;
    if ( v11 == a3 )
      goto LABEL_53;
    v73 = v13 + 1;
LABEL_33:
    v20 = v71;
LABEL_34:
    --v22;
    v24 = v72;
    v13 = v73;
    v23 -= 24;
    if ( v22 < v20 )
      goto LABEL_119;
  }
  if ( (*(_DWORD *)(v23 + 20) & 0xFFFFF) == 1048574 )
  {
    __dmb(0xBu);
    v59 = (unsigned int *)(v23 + 12);
    do
      v60 = __ldrex(v59);
    while ( __strex(v60 & 0x7FFFFFFF, v59) );
    KfLowerIrql(v25);
    if ( MiDemoteLargeFreePage(v22) == 1 )
    {
      ++v22;
      v23 += 24;
    }
    goto LABEL_52;
  }
  v45 = dword_640580;
  if ( (unsigned int)dword_640580 >= 0x80
    || (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) != 0 && v45 >= 2 )
  {
    MiUnlinkFreeOrZeroedPage(v22, 0);
    __dmb(0xBu);
    v46 = (unsigned int *)(v23 + 12);
    do
      v47 = __ldrex(v46);
    while ( __strex(v47 & 0x7FFFFFFF, v46) );
    KfLowerIrql(v25);
    if ( *(_DWORD *)(v23 + 8) == 128 )
LABEL_46:
      ++v74;
LABEL_47:
    v8 = a3;
    ++v11;
    *v13 = v22;
    v72 = v24 + 24;
    if ( v11 == a3 )
      goto LABEL_53;
    v73 = v13 + 1;
    goto LABEL_34;
  }
  __dmb(0xBu);
  v61 = (unsigned int *)(v23 + 12);
  do
    v62 = __ldrex(v61);
  while ( __strex(v62 & 0x7FFFFFFF, v61) );
LABEL_125:
  KfLowerIrql(v25);
LABEL_53:
  MiDereferencePageRuns(v79);
  MiReleasePteCopyList((int)v83);
  if ( v74 )
    *(_DWORD *)(a2 + 12) = 1;
  *(_DWORD *)(a2 + 20) += v11 << 12;
  return v11;
}
