// MiBuildReservationCluster 
 
unsigned int __fastcall MiBuildReservationCluster(_DWORD *a1, int a2, int *a3, int a4)
{
  __int16 v4; // r4
  int v5; // r3
  int v7; // r8
  int v8; // r3
  int v9; // r4
  unsigned int v10; // r10
  _DWORD *v11; // r6
  int v12; // r9
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned __int8 *v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r5
  unsigned int v21; // r5
  int v22; // r2
  unsigned int *v23; // r2
  unsigned int v24; // r4
  int v25; // r3
  unsigned int v26; // r4
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r8
  int v30; // r10
  int v31; // r7
  unsigned __int8 *v32; // r1
  unsigned int v33; // r2
  int v34; // r3
  unsigned int *v35; // r0
  unsigned int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned int v39; // r7
  int v40; // r0
  unsigned int v41; // r8
  unsigned int v42; // r6
  int v43; // r3
  int v44; // r5
  int v45; // r0
  unsigned int v46; // r2
  unsigned int v47; // r9
  unsigned int v48; // r2
  int v49; // r10
  unsigned int v50; // r7
  unsigned int v51; // r5
  int v52; // r3
  unsigned int v53; // r6
  unsigned int v54; // r8
  int v55; // r10
  int v56; // r0
  _DWORD *v57; // r3
  unsigned int v58; // r3
  unsigned int v59; // r5
  _DWORD *v60; // r10
  _DWORD *v61; // r6
  int v62; // r8
  int v63; // r0
  int v64; // r1
  int v65; // r2
  int v66; // r6
  unsigned __int8 *v67; // r1
  unsigned int v68; // r2
  unsigned int *v69; // r8
  unsigned int v70; // r3
  unsigned int v71; // r2
  int v72; // r2
  int v73; // r3
  unsigned int v74; // r1
  unsigned int *v75; // r2
  unsigned int v76; // r0
  unsigned int *v77; // r9
  int v78; // r2
  unsigned int v79; // r2
  _DWORD *v80; // r7
  unsigned int v81; // r0
  int v82; // r6
  int *v83; // r0
  _DWORD *v84; // r2
  int v86; // [sp+10h] [bp-88h] BYREF
  int v87; // [sp+14h] [bp-84h]
  unsigned int v88; // [sp+18h] [bp-80h]
  int v89; // [sp+1Ch] [bp-7Ch]
  int v90; // [sp+20h] [bp-78h]
  _DWORD *v91; // [sp+24h] [bp-74h]
  _DWORD *v92; // [sp+28h] [bp-70h]
  _DWORD *v93; // [sp+2Ch] [bp-6Ch]
  int *v94; // [sp+30h] [bp-68h]
  unsigned int v95; // [sp+34h] [bp-64h]
  int v96; // [sp+38h] [bp-60h]
  int v97; // [sp+3Ch] [bp-5Ch]
  _DWORD *v98; // [sp+40h] [bp-58h]
  unsigned int v99; // [sp+44h] [bp-54h]
  int v100; // [sp+48h] [bp-50h]
  int *v101; // [sp+50h] [bp-48h] BYREF
  unsigned int v102[5]; // [sp+54h] [bp-44h] BYREF
  char v103[8]; // [sp+68h] [bp-30h] BYREF
  unsigned int v104; // [sp+70h] [bp-28h]
  unsigned int v105; // [sp+74h] [bp-24h]

  v4 = *(_WORD *)(a2 + 96);
  v98 = (_DWORD *)a4;
  v89 = 0;
  v5 = *(_DWORD *)(a2 + 128);
  v94 = a3;
  v7 = v5 + 20 * ((v4 & 0xF) + 96);
  v91 = (_DWORD *)a2;
  v92 = a1;
  v90 = v5;
  MiRefPageFileSpaceBitmaps(v91, &v101, (int)v91, v5);
  v86 = 0;
  v87 = 0;
  v8 = 1;
  v9 = *(_DWORD *)(v7 + 8);
  v93 = a1;
  if ( v9 == 0xFFFFF )
  {
LABEL_101:
    v26 = 0;
    v20 = 0;
    goto LABEL_102;
  }
  v10 = v102[1];
  while ( 1 )
  {
    v11 = (_DWORD *)(MmPfnDatabase + 24 * v9);
    v12 = KfRaiseIrql(2);
    v13 = (unsigned __int8 *)v11 + 15;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
    {
      v15 = (unsigned __int8 *)v11 + 15;
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v16 = v11[3];
          __dmb(0xBu);
        }
        while ( (v16 & 0x80000000) != 0 );
        do
          v17 = __ldrex(v15);
        while ( __strex(v17 | 0x80, v15) );
        __dmb(0xBu);
      }
      while ( v17 >> 7 );
    }
    if ( v9 == *(_DWORD *)(v7 + 8) )
      break;
    __dmb(0xBu);
    v18 = v11 + 3;
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    KfLowerIrql(v12);
LABEL_19:
    v9 = *(_DWORD *)(v7 + 8);
    v8 = (int)&MmPfnDatabase;
    if ( v9 == 0xFFFFF )
      goto LABEL_101;
  }
  v20 = v11[2] >> 13;
  if ( v20 >= v102[0] )
  {
    __dmb(0xBu);
    v75 = v11 + 3;
    do
      v76 = __ldrex(v75);
    while ( __strex(v76 & 0x7FFFFFFF, v75) );
    KfLowerIrql(v12);
    goto LABEL_101;
  }
  if ( ((*(int *)(v10 + 4 * (v11[2] >> 18)) >> (v20 & 0x1F)) & 1) != 0 )
  {
    MiUnlinkPageFromList((int)v11, 0);
    v21 = v11[2];
    v11[2] = v21 & 0xFFFFFFF7;
    MiInsertPageInList((int)v11, 8, v22);
    __dmb(0xBu);
    v23 = v11 + 3;
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 & 0x7FFFFFFF, v23) );
    KfLowerIrql(v12);
    MiReleasePageFileInfo(v90, v21, 0, v25);
    goto LABEL_19;
  }
  MiReferencePageForModifiedWrite((int)v11, 1);
  *v92 = v9;
  v26 = 1;
  if ( *v94 == 1 )
  {
    __dmb(0xBu);
    v27 = v11 + 3;
    do
      v28 = __ldrex(v27);
    while ( __strex(v28 & 0x7FFFFFFF, v27) );
    KfLowerIrql(v12);
    goto LABEL_102;
  }
  v29 = v11[1] | 0x80000000;
  v30 = v11[5] & 0xFFFFF;
  v100 = v11[2];
  v88 = v29;
  v31 = MmPfnDatabase + 24 * v30;
  v90 = v31;
  v32 = (unsigned __int8 *)(v31 + 15);
  do
    v33 = __ldrex(v32);
  while ( __strex(v33 | 0x80, v32) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v33 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v34 = *(_DWORD *)(v31 + 12);
      __dmb(0xBu);
    }
    while ( (v34 & 0x80000000) != 0 );
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 | 0x80, v32) );
  }
  *(_DWORD *)(v31 + 12) = *(_DWORD *)(v31 + 12) & 0xC0000000 | (*(_DWORD *)(v31 + 12) + 1) & 0x3FFFFFFF;
  __dmb(0xBu);
  v35 = (unsigned int *)(v31 + 12);
  do
    v36 = __ldrex(v35);
  while ( __strex(v36 & 0x7FFFFFFF, v35) );
  __dmb(0xBu);
  v37 = v11 + 3;
  do
    v38 = __ldrex(v37);
  while ( __strex(v38 & 0x7FFFFFFF, v37) );
  KfLowerIrql(v12);
  if ( (v11[5] & 0x8000000) == 0 )
  {
    v39 = 0;
    v104 = 0;
    v105 = 0;
    v95 = 0;
    goto LABEL_40;
  }
  if ( MiGetPageFileSectionForReservation(v29, v103, 0) )
  {
    v89 = 1;
    if ( (v11[3] & 0x40000000) == 0 )
    {
      v39 = v105;
      v95 = v104;
LABEL_40:
      v40 = MiReservePtes(&dword_634D58, 1u);
      v41 = v40;
      v96 = v40;
      if ( v40 )
      {
        v42 = (dword_681114 & 0x3ED | (v30 << 12) | MiDetermineUserGlobalPteMask(v40)) & 0xFFFFF3FF | 0x12;
        if ( v41 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v41 = v42;
        }
        else
        {
          v43 = *(_DWORD *)v41;
          v44 = 0;
          __dmb(0xBu);
          if ( (v43 & 2) == 0 )
            v44 = 1;
          *(_DWORD *)v41 = v42;
          if ( v41 + 1070596096 <= 0xFFF )
          {
            v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v45, (_DWORD *)(v45 + 4 * (v41 & 0xFFF)), v42);
          }
          if ( v44 == 1 )
          {
            __dsb(0xFu);
            __isb(0xFu);
          }
        }
        v46 = v41 << 10;
        v47 = (v41 << 10) + 4 * ((v88 >> 2) & 0x3FF);
        v99 = v47;
        if ( v89 )
          v48 = v46 + 4 * ((v39 >> 2) & 0x3FF);
        else
          v48 = v46 + 4092;
        v49 = *v94;
        v97 = v49;
        v50 = v100 & 0xFFFFFC1F;
        v51 = (int)(v48 - v47) >> 2;
        if ( v51 >= v49 - 1 )
          v51 = v49 - 1;
        if ( v51 + (v50 >> 13) >= v102[0] )
          v51 = v102[0] - (v50 >> 13) - 1;
        v52 = 0;
        v86 = 0;
        v53 = (v41 << 10) + 4 * ((v88 >> 2) & 0x3FF);
        if ( v51 )
        {
          v54 = v100 & 0xFFFFFC1F;
          v55 = 0;
          do
          {
            v54 = v54 & 0x1FFF ^ ((v54 & 0xFFFFE000) + 0x2000);
            v53 += 4;
            v56 = MiGetPageForWriteCluster(v102, v53, v54);
            if ( v56 == -1 )
              break;
            v57 = v92;
            --v51;
            ++v26;
            v92[1] = v56;
            v92 = v57 + 1;
            if ( v56 == dword_6348F4 )
              ++v55;
          }
          while ( (v88 != 3 || v26 < 0x10) && v51 );
          v52 = v86;
          v41 = v96;
          v47 = v99;
          v87 = v55;
          v49 = v97;
        }
        v26 -= v52;
        v86 = v87 - v52;
        v87 -= v52;
        if ( v89 )
          v58 = 4 * (((v95 >> 2) & 0x3FF) + (v41 << 8));
        else
          v58 = v47 & 0xFFFFF000;
        v59 = (int)(v47 - v58) >> 2;
        if ( v59 >= v49 - v26 )
          v59 = v49 - v26;
        if ( v59 > (v50 >> 13) - 1 )
          v59 = (v50 >> 13) - 1;
        v60 = v93;
        if ( v59 )
        {
          v61 = &v93[v59];
          memmove((int)v61, (int)v93, 4 * v26);
          v62 = v87;
          v86 = 0;
          do
          {
            v50 = v50 & 0x1FFF | (((v50 >> 13) - 1) << 13);
            v47 -= 4;
            v63 = MiGetPageForWriteCluster(v102, v47, v50);
            if ( v63 == -1 )
              break;
            *--v61 = v63;
            --v59;
            ++v26;
            if ( v63 == dword_6348F4 )
              ++v62;
          }
          while ( (v88 != 3 || v26 < 0x10) && v59 );
          v64 = (int)&v61[v86];
          v65 = v62 - v86;
          v41 = v96;
          v26 -= v86;
          v86 = v65;
          v87 = v65;
          if ( v60 != (_DWORD *)v64 )
            memmove((int)v60, v64, 4 * v26);
        }
        v20 = *(_DWORD *)(MmPfnDatabase + 24 * *v60 + 8) >> 13;
        MiReleasePtes(&dword_634D58, v41, 1u);
        v31 = v90;
      }
      else
      {
        v31 = v90;
      }
    }
  }
  v66 = KfRaiseIrql(2);
  v67 = (unsigned __int8 *)(v31 + 15);
  do
    v68 = __ldrex(v67);
  while ( __strex(v68 | 0x80, v67) );
  __dmb(0xBu);
  v69 = (unsigned int *)(v31 + 12);
  if ( v68 >> 7 )
  {
    do
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v70 = *v69;
        __dmb(0xBu);
      }
      while ( (v70 & 0x80000000) != 0 );
      do
        v71 = __ldrex(v67);
      while ( __strex(v71 | 0x80, v67) );
      __dmb(0xBu);
    }
    while ( v71 >> 7 );
  }
  v72 = *(_DWORD *)(v31 + 12);
  v73 = *(_BYTE *)(v31 + 18) & 7;
  if ( v73 != 6 )
    KeBugCheckEx(78, 153, (v31 - MmPfnDatabase) / 24, v73, v72 & 0x3FFFFFFF);
  *(_DWORD *)(v31 + 12) = v72 & 0xC0000000 | ((v72 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
  if ( (v72 & 0x3FFFFFFF) == 1 )
    MiPfnShareCountIsZero(v31, 0);
  __dmb(0xBu);
  do
    v74 = __ldrex(v69);
  while ( __strex(v74 & 0x7FFFFFFF, v69) );
  KfLowerIrql(v66);
  v8 = v89;
  if ( v89 )
    MiReleasePageFileSectionInfo(v103);
LABEL_102:
  v77 = (unsigned int *)v94;
  v78 = *v94;
  if ( v26 < *v94 && v26 && v20 + v26 < v102[0] )
  {
    if ( v78 + v20 <= v102[0] )
      v79 = v78 - v26;
    else
      v79 = v102[0] - v20 - v26;
    v80 = v91;
    v81 = MiAddToReservationCluster((int)v91, v102, v79, v20 + v26, &v93[v26], &v86);
    v82 = v86;
    v26 += v81;
  }
  else
  {
    v82 = v87;
    v80 = v91;
  }
  v83 = MiDerefPageFileSpaceBitmaps((int)v80, &v101, 0, v8);
  if ( v83 )
    ExFreePoolWithTag(v83);
  v84 = v98;
  *v77 = v26;
  *v84 = v26 - v82;
  return v20;
}
