// MiBuildMappedCluster 
 
int __fastcall MiBuildMappedCluster(_DWORD *a1, unsigned int a2, int a3)
{
  int v3; // r8
  int v4; // r9
  unsigned int v5; // r6
  unsigned int v6; // r10
  unsigned int v7; // r3
  unsigned int v8; // r5
  unsigned int v9; // r7
  int v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  int v13; // r2
  unsigned int v14; // r7
  int v15; // r3
  unsigned int *v16; // r4
  unsigned int v17; // r3
  unsigned int v18; // r10
  int v19; // lr
  unsigned int v20; // r5
  unsigned int v21; // r3
  unsigned int *v22; // r8
  int v23; // r4
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r4
  __int64 v27; // r1
  unsigned int v29; // r8
  unsigned int v30; // r10
  int v31; // r7
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned int *v34; // r3
  unsigned int *v35; // r2
  unsigned int v36; // r0
  unsigned int v37; // r3
  unsigned int v38; // r8
  int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r0
  unsigned int *v42; // r8
  unsigned int v43; // r2
  int v44; // r0
  int v45; // r10
  unsigned int *v46; // r9
  unsigned int *v47; // r7
  int v48; // r4
  int v49; // r0
  int v50; // r0
  unsigned int *v51; // r8
  int v52; // r5
  unsigned int v53; // r0
  int v54; // r4
  unsigned __int8 *v55; // r3
  unsigned int v56; // r1
  unsigned int *v57; // r2
  unsigned int v58; // r0
  unsigned int v59; // r3
  int v60; // r4
  unsigned int *v61; // r2
  unsigned int v62; // r0
  unsigned __int8 *v63; // r1
  int v64; // r3
  unsigned int v65; // r2
  unsigned int *v66; // r2
  unsigned int v67; // r4
  int v68; // r5
  unsigned int *v69; // r7
  unsigned int v70; // r9
  int v71; // t1
  int v72; // r4
  int v73; // r8
  unsigned __int8 *v74; // r3
  unsigned int v75; // r1
  unsigned __int8 *v76; // r1
  int v77; // r3
  unsigned int v78; // r2
  unsigned int *v79; // r2
  unsigned int v80; // r4
  unsigned int v81; // r3
  unsigned __int8 *v82; // r1
  int v83; // r3
  unsigned int v84; // r2
  unsigned int *v85; // r2
  unsigned int v86; // r0
  unsigned int *v87; // r2
  unsigned int v88; // r4
  unsigned int *v89; // r2
  unsigned int v90; // r0
  int v91; // r5
  int v92; // r4
  int v93; // r6
  unsigned __int8 *v94; // r3
  unsigned int v95; // r1
  unsigned __int8 *v96; // r1
  int v97; // r3
  unsigned int v98; // r2
  unsigned int *v99; // r2
  unsigned int v100; // r4
  __int16 v101; // r4
  int v102; // r0
  char v103[4]; // [sp+0h] [bp-50h] BYREF
  unsigned int *v104; // [sp+4h] [bp-4Ch]
  unsigned int v105; // [sp+8h] [bp-48h]
  unsigned int v106; // [sp+Ch] [bp-44h]
  unsigned int v107; // [sp+10h] [bp-40h]
  unsigned int v108; // [sp+14h] [bp-3Ch]
  int v109; // [sp+18h] [bp-38h]
  int v110; // [sp+1Ch] [bp-34h]
  unsigned int *v111; // [sp+20h] [bp-30h]
  _DWORD *v112; // [sp+24h] [bp-2Ch]
  unsigned int v113; // [sp+28h] [bp-28h]
  int v114; // [sp+2Ch] [bp-24h]
  unsigned int v115; // [sp+30h] [bp-20h]

  v3 = a3;
  v107 = a3;
  v4 = a2;
  v112 = a1;
  v113 = a2;
  v114 = ((int)a1 - MmPfnDatabase) / 24;
  v111 = (unsigned int *)(a2 + 28);
  v104 = (unsigned int *)(a2 + 28);
  v5 = a1[1] | 0x80000000;
  v6 = a1[2] & 0xFFFFF800 | (2 * (a1[2] & 0x3FC));
  v7 = *(_DWORD *)(v6 + 4);
  v8 = v5 & 0xFFFFF000;
  v108 = v5;
  v109 = v6;
  if ( (v5 & 0xFFFFF000) < v7 )
    v8 = v7;
  v9 = v8;
  if ( v8 < v5 - 60 )
    v8 = v5 - 60;
  v10 = MiMapPageInHyperSpaceWorker(a1[5] & 0xFFFFF, (int)v103, 0x80000000);
  v11 = (v5 & 0xFFF) + v10;
  if ( !v3 )
    v9 = v5;
  v12 = v5;
  v110 = v10;
  v115 = v5 & 0xFFF;
  v105 = v5;
  if ( v5 > v9 )
  {
    do
    {
      v11 -= 4;
      v37 = *(_DWORD *)v11;
      if ( (*(_DWORD *)v11 & 0x402) != 0 || (v37 & 0x800) == 0 )
        break;
      v38 = v37 >> 12;
      if ( !MI_IS_PFN(v37 >> 12)
        || (v39 = MmPfnDatabase + 24 * v38, (*(_BYTE *)(v39 + 18) & 0x10) == 0)
        || *(_WORD *)(v39 + 16) )
      {
        v12 = v105;
        break;
      }
      v5 -= 4;
      if ( v5 < v8 )
      {
        v12 = v105;
      }
      else
      {
        v12 = v5;
        v105 = v5;
      }
    }
    while ( v5 > v9 );
    v4 = v113;
    v6 = v109;
    v3 = v107;
  }
  v13 = *(_DWORD *)(v6 + 28);
  v14 = (v12 & 0xFFFFF000) + 4096;
  v15 = *(_DWORD *)(v6 + 4);
  v16 = (unsigned int *)(v11 & 0xFFFFF000 | v12 & 0xFFF);
  v107 = v14;
  v17 = v15 + 4 * v13;
  if ( v14 > v17 )
  {
    v14 = v17;
    v107 = v17;
  }
  v18 = v14;
  v106 = v14;
  if ( v14 > v12 + 64 )
  {
    v18 = v12 + 64;
    v106 = v12 + 64;
  }
  if ( !v3 )
  {
    v18 = v12 + 4;
    v14 = v12 + 4;
    v106 = v12 + 4;
    v107 = v12 + 4;
  }
  v19 = 1;
  v109 = 1;
  v20 = v12;
  if ( v12 < v14 )
  {
    v21 = v108;
    while ( v20 == v21 )
    {
      v22 = v104;
      *v104 = v114;
      v104 = v22 + 1;
LABEL_18:
      v20 += 4;
      v18 = v106;
      ++v16;
      if ( v20 >= v14 )
        goto LABEL_19;
    }
    if ( v19 == 3 )
      return sub_53AE2C(1026);
    v29 = *v16;
    if ( (*v16 & 0x402) == 0 && (v29 & 0x800) != 0 )
    {
      v30 = v29 >> 12;
      if ( MI_IS_PFN(v29 >> 12) )
      {
        v31 = MmPfnDatabase + 24 * v30;
        v32 = (unsigned __int8 *)(v31 + 15);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 | 0x80, v32) );
        __dmb(0xBu);
        if ( v33 >> 7 )
        {
          v63 = (unsigned __int8 *)(v31 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v64 = *(_DWORD *)(v31 + 12);
              __dmb(0xBu);
            }
            while ( (v64 & 0x80000000) != 0 );
            do
              v65 = __ldrex(v63);
            while ( __strex(v65 | 0x80, v63) );
            __dmb(0xBu);
          }
          while ( v65 >> 7 );
        }
        if ( v29 == *v16 )
        {
          if ( (*(_BYTE *)(v31 + 18) & 0x10) == 0 || *(_WORD *)(v31 + 16) )
          {
            __dmb(0xBu);
            v40 = (unsigned int *)(v31 + 12);
            do
              v41 = __ldrex(v40);
            while ( __strex(v41 & 0x7FFFFFFF, v40) );
          }
          else
          {
            if ( v20 >= v106 )
            {
              v19 = v109;
LABEL_42:
              __dmb(0xBu);
              v35 = (unsigned int *)(v31 + 12);
              do
                v36 = __ldrex(v35);
              while ( __strex(v36 & 0x7FFFFFFF, v35) );
              v14 = v107;
              v21 = v108;
              goto LABEL_18;
            }
            v19 = MiReferencePageForModifiedWrite(v31, 0);
            v109 = v19;
            if ( v19 )
            {
              v34 = v104;
              *v104 = v30;
              v104 = v34 + 1;
              goto LABEL_42;
            }
            __dmb(0xBu);
            v66 = (unsigned int *)(v31 + 12);
            do
              v67 = __ldrex(v66);
            while ( __strex(v67 & 0x7FFFFFFF, v66) );
          }
          v18 = v106;
          v14 = v107;
          goto LABEL_59;
        }
        __dmb(0xBu);
        v61 = (unsigned int *)(v31 + 12);
        do
          v62 = __ldrex(v61);
        while ( __strex(v62 & 0x7FFFFFFF, v61) );
        v14 = v107;
      }
      v21 = v108;
      --v16;
      v20 -= 4;
LABEL_121:
      v19 = v109;
      goto LABEL_18;
    }
LABEL_59:
    v42 = v104;
    v24 = v110;
    v23 = (unsigned __int8)v103[0];
    if ( v110 )
    {
      MiUnmapPageInHyperSpaceWorker(v110, (unsigned __int8)v103[0], 0x80000000);
      v24 = 0;
    }
    v43 = v108;
    if ( v20 >= v108 )
      goto LABEL_20;
    v68 = ((int)v42 - v4 - 28) >> 2;
    if ( v68 )
    {
      if ( (unsigned int)v42 > v4 + 28 )
      {
        v69 = v104;
        v70 = (unsigned int)v111;
        do
        {
          v71 = *--v69;
          v72 = MmPfnDatabase + 24 * v71;
          v73 = KfRaiseIrql(2);
          v74 = (unsigned __int8 *)(v72 + 15);
          do
            v75 = __ldrex(v74);
          while ( __strex(v75 | 0x80, v74) );
          __dmb(0xBu);
          if ( v75 >> 7 )
          {
            v76 = (unsigned __int8 *)(v72 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v77 = *(_DWORD *)(v72 + 12);
                __dmb(0xBu);
              }
              while ( (v77 & 0x80000000) != 0 );
              do
                v78 = __ldrex(v76);
              while ( __strex(v78 | 0x80, v76) );
              __dmb(0xBu);
            }
            while ( v78 >> 7 );
          }
          MiWriteCompletePfn(v72, 1);
          __dmb(0xBu);
          v79 = (unsigned int *)(v72 + 12);
          do
            v80 = __ldrex(v79);
          while ( __strex(v80 & 0x7FFFFFFF, v79) );
          KfLowerIrql(v73);
        }
        while ( (unsigned int)v69 > v70 );
        v4 = v113;
        v18 = v106;
        v104 = v69;
        v14 = v107;
      }
      MiReleaseWriteInProgressCharges(MiSystemPartition, v68, 1);
      v43 = v108;
    }
    if ( v18 == v105 + 4 )
    {
      v81 = v43 + 4;
      v14 = v43 + 4;
      v107 = v43 + 4;
    }
    else
    {
      v81 = v43 + 64;
      if ( v14 <= v43 + 64 )
      {
LABEL_120:
        v105 = v43;
        v110 = MiMapPageInHyperSpaceWorker(v112[5] & 0xFFFFF, (int)v103, 0x80000000);
        v16 = (unsigned int *)(v110 + v115 - 4);
        v21 = v108;
        v20 = v108 - 4;
        goto LABEL_121;
      }
    }
    v106 = v81;
    goto LABEL_120;
  }
LABEL_19:
  v23 = (unsigned __int8)v103[0];
  v24 = v110;
LABEL_20:
  if ( v24 )
    MiUnmapPageInHyperSpaceWorker(v24, v23, 0x80000000);
  v25 = v20;
  v113 = v20;
  if ( v20 > v18 )
    v20 = v18;
  v26 = (int)(v20 - v105) >> 2;
  if ( v109 == 3 || v25 <= v18 && v5 >= v105 )
    goto LABEL_27;
  v44 = ExAllocatePoolWithTag(512, 4 * (((int)(v25 - v5) >> 2) + 7), 1700228429);
  v45 = v44;
  v114 = v44;
  if ( !v44 )
    goto LABEL_27;
  v46 = v111;
  v47 = (unsigned int *)(v44 + 28);
  v48 = 1;
  v49 = v112[5] & 0xFFFFF;
  v110 = 1;
  v50 = MiMapPageInHyperSpaceWorker(v49, (int)v103, 0x80000000);
  v51 = (unsigned int *)((v5 & 0xFFF) + v50);
  v52 = v50;
  while ( v5 < v113 )
  {
    if ( v5 >= v105 && v5 < v106 )
    {
      v59 = *v46++;
      *v47 = v59;
LABEL_81:
      v5 += 4;
      ++v47;
      ++v51;
      goto LABEL_82;
    }
    if ( v48 != 3 || (int)(((unsigned int)v47 - v45 - 28) & 0xFFFFFFFC) < 64 )
    {
      v53 = *v51;
      if ( (*v51 & 0x402) == 0 && (v53 & 0x800) != 0 )
      {
        v115 = v53 >> 12;
        v54 = MmPfnDatabase + 24 * (v53 >> 12);
        v55 = (unsigned __int8 *)(v54 + 15);
        do
          v56 = __ldrex(v55);
        while ( __strex(v56 | 0x80, v55) );
        __dmb(0xBu);
        if ( v56 >> 7 )
        {
          v82 = (unsigned __int8 *)(v54 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v83 = *(_DWORD *)(v54 + 12);
              __dmb(0xBu);
            }
            while ( (v83 & 0x80000000) != 0 );
            do
              v84 = __ldrex(v82);
            while ( __strex(v84 | 0x80, v82) );
            __dmb(0xBu);
          }
          while ( v84 >> 7 );
        }
        if ( v53 != *v51 )
        {
          __dmb(0xBu);
          v85 = (unsigned int *)(v54 + 12);
          do
            v86 = __ldrex(v85);
          while ( __strex(v86 & 0x7FFFFFFF, v85) );
          goto LABEL_82;
        }
        if ( (*(_BYTE *)(v54 + 18) & 0x10) == 0 || *(_WORD *)(v54 + 16) )
        {
          __dmb(0xBu);
          v89 = (unsigned int *)(v54 + 12);
          do
            v90 = __ldrex(v89);
          while ( __strex(v90 & 0x7FFFFFFF, v89) );
        }
        else
        {
          v110 = MiReferencePageForModifiedWrite(v54, 0);
          if ( v110 )
          {
            *v47 = v115;
            __dmb(0xBu);
            v57 = (unsigned int *)(v54 + 12);
            do
              v58 = __ldrex(v57);
            while ( __strex(v58 & 0x7FFFFFFF, v57) );
            goto LABEL_81;
          }
          __dmb(0xBu);
          v87 = (unsigned int *)(v54 + 12);
          do
            v88 = __ldrex(v87);
          while ( __strex(v88 & 0x7FFFFFFF, v87) );
        }
      }
    }
    v60 = (unsigned __int8)v103[0];
    if ( v52 )
    {
      MiUnmapPageInHyperSpaceWorker(v52, (unsigned __int8)v103[0], 0x80000000);
      v52 = 0;
    }
    if ( v5 >= v105 )
      goto LABEL_85;
    v91 = ((int)v47 - v45 - 28) >> 2;
    if ( v91 )
    {
      if ( (unsigned int)v47 > v45 + 28 )
      {
        do
        {
          v92 = MmPfnDatabase + 24 * *--v47;
          v93 = KfRaiseIrql(2);
          v94 = (unsigned __int8 *)(v92 + 15);
          do
            v95 = __ldrex(v94);
          while ( __strex(v95 | 0x80, v94) );
          __dmb(0xBu);
          if ( v95 >> 7 )
          {
            v96 = (unsigned __int8 *)(v92 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v97 = *(_DWORD *)(v92 + 12);
                __dmb(0xBu);
              }
              while ( (v97 & 0x80000000) != 0 );
              do
                v98 = __ldrex(v96);
              while ( __strex(v98 | 0x80, v96) );
              __dmb(0xBu);
            }
            while ( v98 >> 7 );
          }
          MiWriteCompletePfn(v92, 1);
          __dmb(0xBu);
          v99 = (unsigned int *)(v92 + 12);
          do
            v100 = __ldrex(v99);
          while ( __strex(v100 & 0x7FFFFFFF, v99) );
          KfLowerIrql(v93);
        }
        while ( (unsigned int)v47 > v45 + 28 );
        v45 = v114;
      }
      MiReleaseWriteInProgressCharges(MiSystemPartition, v91, 1);
    }
    v46 = v111;
    v101 = v105;
    v5 = v105;
    v102 = MiMapPageInHyperSpaceWorker(v112[5] & 0xFFFFF, (int)v103, 0x80000000);
    v51 = (unsigned int *)((v101 & 0xFFF) + v102);
    v52 = v102;
LABEL_82:
    v48 = v110;
  }
  v60 = (unsigned __int8)v103[0];
LABEL_85:
  if ( v52 )
    MiUnmapPageInHyperSpaceWorker(v52, v60, 0x80000000);
  v26 = ((int)v47 - v45 - 28) >> 2;
  v4 = v45;
LABEL_27:
  HIDWORD(v27) = v26 << 12;
  *(_WORD *)(v4 + 4) = 4 * (((unsigned int)((v26 << 12) + 4095) >> 12) + 7);
  LODWORD(v27) = 0;
  *(_WORD *)(v4 + 6) = 2;
  *(_DWORD *)v4 = 0;
  *(_QWORD *)(v4 + 16) = v27;
  *(_DWORD *)(v4 + 24) = 0;
  return v4;
}
