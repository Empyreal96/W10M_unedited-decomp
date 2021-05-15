// MiWaitForInPageComplete 
 
int __fastcall MiWaitForInPageComplete(int a1, int a2, int a3, int a4, int *a5)
{
  int v6; // lr
  unsigned int v8; // r3
  int v9; // r7
  char *v10; // r0
  char v11; // r10
  int v12; // r9
  int v13; // r4
  int *v14; // r8
  unsigned int v15; // r4
  unsigned int v16; // lr
  int v17; // r3
  unsigned int v18; // r0
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r0
  int v22; // r6
  unsigned int i; // r3
  int v24; // r8
  int v25; // r10
  unsigned int *v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r1
  char v30; // r4
  int v31; // r9
  int v32; // r6
  int v33; // r6
  int v34; // r4
  int v35; // r4
  int v36; // r1
  int v37; // r2
  _DWORD *v39; // r0
  unsigned __int64 *v40; // r3
  unsigned __int64 v41; // kr00_8
  char *v42; // r4
  unsigned int v43; // r2
  int v44; // r6
  int *v45; // r10
  int v46; // r4
  unsigned int v47; // r7
  unsigned int v48; // r6
  int v49; // t1
  int v50; // r4
  unsigned int v51; // r0
  int v52; // r7
  int v53; // r4
  int *v54; // r7
  unsigned int v55; // r6
  unsigned int v56; // r4
  int v57; // t1
  unsigned int v58; // r3
  unsigned int v59; // r1
  unsigned int v60; // r6
  unsigned int v61; // r4
  int *v62; // r7
  int v63; // t1
  int v64; // r0
  char v65; // r1
  int *v66; // r1
  unsigned int v67; // r2
  int v68; // r2
  int v69; // r3
  unsigned int v70; // r5
  int v71; // r6
  unsigned __int8 *v72; // r1
  unsigned int v73; // r2
  int v74; // r3
  unsigned int v75; // r2
  unsigned int *v76; // r2
  unsigned int v77; // r0
  int v78; // [sp+Ch] [bp-6Ch]
  char v79[4]; // [sp+18h] [bp-60h] BYREF
  char *v80; // [sp+1Ch] [bp-5Ch]
  unsigned int v81; // [sp+20h] [bp-58h]
  unsigned int v82; // [sp+24h] [bp-54h]
  int v83; // [sp+28h] [bp-50h]
  int v84; // [sp+2Ch] [bp-4Ch] BYREF
  unsigned int v85; // [sp+30h] [bp-48h]
  int v86; // [sp+34h] [bp-44h] BYREF
  int v87; // [sp+38h] [bp-40h]
  unsigned int v88; // [sp+3Ch] [bp-3Ch]
  int v89; // [sp+40h] [bp-38h]
  unsigned int v90; // [sp+44h] [bp-34h]
  int v91; // [sp+48h] [bp-30h]
  int v92; // [sp+4Ch] [bp-2Ch]
  char v93[40]; // [sp+50h] [bp-28h] BYREF

  v6 = *(_DWORD *)(a1 + 140);
  v90 = *(_DWORD *)(a1 + 132);
  v91 = v6;
  v8 = *(_DWORD *)(a1 + 128);
  v9 = a1 + 152;
  v10 = *(char **)(a1 + 144);
  v11 = 0;
  v12 = a3;
  v86 = 0;
  v87 = a3;
  v92 = a2;
  v83 = 0;
  v85 = v8;
  v80 = (char *)v9;
  if ( v10 )
  {
    v9 = (int)v10;
    v80 = v10;
  }
  v13 = *(_DWORD *)(v6 + 4);
  v88 = v9 + 28;
  v14 = (int *)(v9 + 28);
  v89 = -1;
  v84 = -1;
  if ( v13 >= 0 )
  {
    v51 = (v6 - MmPfnDatabase) / 24;
    if ( v51 < dword_633850 )
    {
      if ( *(void (__noreturn **)())((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x39C) == KeSwapProcessOrStack )
        return sub_543538();
      MiFindContiguousPages(
        MiSystemPartition,
        v51 + 1,
        dword_633850,
        0,
        1u,
        *(unsigned __int8 *)(v6 + 18) >> 6,
        *(_DWORD *)(v6 + 20) >> 28,
        v78,
        1074003968,
        (unsigned int *)&v84);
      v89 = v84;
    }
  }
  if ( (a4 & 1) != 0 && *(_BYTE *)(a4 & 0xFFFFFFFE) == 2 && v12 )
    MiPrefetchRestOfCluster(a1, a4 & 0xFFFFFFFE, v12, 2);
  KeWaitForSingleObject(a1 + 16, 9, 0, 0, 0);
  if ( v12 && (*(_BYTE *)(v12 + 115) & 0xC0) == 192 && !*(_DWORD *)(v12 + 124) )
    KiUnstackDetachProcess(a1 + 64, 0);
  if ( (*(_WORD *)(v9 + 6) & 0x200) != 0 )
  {
    MiRetardMdl(v9);
    *(_DWORD *)(a1 + 48) = -1073741670;
    *(_DWORD *)(a1 + 52) = 0;
  }
  if ( (*(_BYTE *)(a1 + 113) & 8) != 0 )
  {
    v53 = *(_DWORD *)(a1 + 188);
    if ( v53 )
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)(v53 + 116), (unsigned int)v93);
      RtlAvlRemoveNode(v53 + 124, a1 + 196);
      KeReleaseInStackQueuedSpinLock((int)v93);
    }
  }
  v15 = *(_DWORD *)(a1 + 104);
  v16 = v9 + 28;
  v17 = *(unsigned __int8 *)(a1 + 113);
  v18 = v9
      + 28
      + 4
      * (((((unsigned __int16)*(_DWORD *)(v9 + 24) + (unsigned __int16)*(_DWORD *)(v9 + 16)) & 0xFFFu)
        + *(_DWORD *)(v9 + 20)
        + 4095) >> 12)
      - 4;
  v81 = v15;
  v82 = v18;
  v84 = 0;
  if ( (v17 & 0xFFFFFF80) != 0 )
  {
    MiStoreFaultComplete(a1, &v86);
    v11 = v86;
    v18 = v82;
    v16 = v9 + 28;
    v83 = v86;
  }
  v19 = *(_DWORD *)(a1 + 48);
  if ( *(_DWORD *)(a1 + 120) )
  {
    if ( v19 >= 0 )
    {
      v84 = MiValidateInPage(a1);
      if ( v84 == -1073740748 )
        *(_BYTE *)(a1 + 115) |= 8u;
    }
    v39 = *(_DWORD **)(a1 + 120);
    v40 = (unsigned __int64 *)(v39 + 16);
    do
    {
      v41 = __ldrexd(v40);
      v20 = (v41 - 1) >> 32;
    }
    while ( __strexd(v41 - 1, v40) );
    if ( v41 == 1 )
      MiDeleteControlArea(v39);
  }
  else
  {
    if ( v19 >= 0 && (*(_BYTE *)(a1 + 115) & 0x20) != 0 )
    {
      v84 = MiValidatePagefilePageHash(a1);
      v18 = v82;
      v16 = v9 + 28;
    }
    v20 = BYTE2(MiFlags) & 3;
    if ( v20 )
    {
      if ( (MiFlags & 0x40000) == 0 )
      {
        v59 = *(_DWORD *)(a1 + 128);
        if ( (v59 < 0xC0000000 || v59 > 0xC03FFFFF) && (v20 > 1 || v59 >= dword_63389C) )
        {
          v60 = 1;
          if ( v16 > v18 )
            v61 = 0;
          else
            v61 = (v18 - v16 + 4) >> 2;
          v62 = (int *)v16;
          if ( v61 )
          {
            do
            {
              v63 = *v62++;
              v64 = MmPfnDatabase + 24 * v63;
              v20 = *(_DWORD *)(v64 + 8);
              if ( (v20 & 0x400) == 0 && v64 != dword_6348F8 && ((v20 >> 5) & 0x1F) != 31 && ((v20 >> 5) & 2) != 0 )
              {
                v65 = 2;
                if ( ((v20 >> 5) & 4) != 0 && ((v20 >> 5) & 5) != 5 )
                  v65 = 3;
                MiMarkPfnVerified(v64, v65);
              }
              ++v60;
            }
            while ( v60 <= v61 );
            v12 = v87;
            v16 = v88;
            v11 = v83;
          }
          v9 = (int)v80;
          v15 = v81;
          v14 = (int *)v16;
        }
      }
    }
  }
  if ( *(int *)(a1 + 48) >= 0 )
  {
    if ( (*(_WORD *)(v9 + 6) & 1) != 0 )
    {
      v21 = *(_DWORD *)(v9 + 20);
      v22 = *(_DWORD *)(v9 + 12);
      if ( v21 > KiICacheFlushPromoteThreshold )
      {
        KeSweepIcache();
      }
      else
      {
        v20 = KiMinimumDcacheLine;
        for ( i = v22 & ~(KiMinimumDcacheLine - 1); i < v22 + v21; i += KiMinimumDcacheLine )
          __mcr(15, 0, i, 7, 11, 1);
        __dsb(0xFu);
        if ( (KiCacheType & 0xC000) == 49152 )
          KiVoidIcacheRangePoUWithCatch(v22, v21);
        else
          __mcr(15, 0, 0, 7, 1, 0);
        __mcr(15, 0, 0, 7, 5, 6);
        __dsb(0xFu);
        __isb(0xFu);
        v15 = v81;
      }
    }
    else
    {
      v20 = v82;
      v47 = 1;
      if ( (unsigned int)v14 > v82 )
        v48 = 0;
      else
        v48 = (v82 - (unsigned int)v14 + 4) >> 2;
      if ( v48 )
      {
        do
        {
          v49 = *v14++;
          v50 = MiMapPageInHyperSpaceWorker(v49, (int)v79, 0x80000000);
          KeSweepIcacheRange(1, v50, 4096);
          MiUnmapPageInHyperSpaceWorker(v50, (unsigned __int8)v79[0], 0x80000000);
          ++v47;
        }
        while ( v47 <= v48 );
        v12 = v87;
        v15 = v81;
        v11 = v83;
      }
      v9 = (int)v80;
    }
  }
  v24 = *(_DWORD *)(a1 + 48);
  v25 = v11 & 1;
  if ( !v25 )
  {
    v26 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2972);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 + 1, v26) );
    v20 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 2968;
    do
      v28 = __ldrex((unsigned int *)v20);
    while ( __strex(v28 + ((v15 & 0xFFF) != 0) + (v15 >> 12), (unsigned int *)v20) );
    if ( v12 && (*(_BYTE *)(a1 + 113) & 4) == 0 )
    {
      v20 = v12 + 88;
      do
        v29 = __ldrex((unsigned int *)v20);
      while ( __strex(v29 + 1, (unsigned int *)v20) );
    }
  }
  if ( v25 )
    v30 = 2;
  else
    v30 = 0;
  if ( *a5 )
    PfHardFaultLog(*a5, v30 & 3);
  *a5 = v30 & 3;
  if ( (*(_WORD *)(v9 + 6) & 1) != 0 )
    MmUnmapLockedPages(*(_DWORD *)(v9 + 12), v9, v20);
  v31 = 0;
  *(_DWORD *)(a1 + 108) = -1;
  if ( v24 >= 0 )
  {
    v32 = *(_DWORD *)(a1 + 52);
    if ( v32 != v81 )
    {
      if ( v32 || (*(_BYTE *)(a1 + 113) & 4) == 0 )
      {
        if ( (*(_BYTE *)(a1 + 115) & 0x10) != 0 && !v25 )
          KeBugCheckEx(122, 4, *(_DWORD *)(a1 + 52));
        v42 = v80;
        v43 = ((((unsigned __int16)*((_DWORD *)v80 + 6) + (unsigned __int16)*((_DWORD *)v80 + 4)) & 0xFFF)
             - v81
             + *((_DWORD *)v80 + 5)
             + v32
             + 4095) >> 12;
        v44 = *(_DWORD *)(a1 + 52) & 0xFFF;
        v45 = (int *)&v80[4 * v43 + 24];
        if ( v44 )
        {
          v46 = MiMapPageInHyperSpaceWorker(*v45, (int)v79, 0x80000000);
          memset((_BYTE *)(v46 + v44), 0, 4096 - v44);
          MiUnmapPageInHyperSpaceWorker(v46 + v44, (unsigned __int8)v79[0], 0x80000000);
          v42 = v80;
        }
        if ( (unsigned int)(v45 + 1) <= v82 )
          *(_DWORD *)(a1 + 108) = (((char *)v45 - v42 - 28) >> 2) + 1;
      }
      else
      {
        v24 = -1073741801;
      }
    }
    v33 = v84;
    if ( v84 != -1073741761 )
      goto LABEL_43;
    v66 = MiState;
    goto LABEL_129;
  }
  if ( v24 == -1073741807 )
  {
    if ( (*(_BYTE *)(a1 + 115) & 0x10) != 0 )
      KeBugCheckEx(122, 3, -1073741807);
    v54 = (int *)v88;
    v55 = 1;
    if ( v88 > v82 )
      v56 = 0;
    else
      v56 = (v82 - v88 + 4) >> 2;
    if ( v56 )
    {
      do
      {
        v57 = *v54++;
        v58 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v57 + 18);
        MiZeroPhysicalPage(v57, 3, v58 >> 6, v58);
        ++v55;
      }
      while ( v55 <= v56 );
    }
    v24 = 0;
    goto LABEL_43;
  }
  if ( v24 != -2147483626 )
  {
    if ( v24 == -1073741670
      || v24 == -1073741663
      || v24 == -1073741801
      || *((_DWORD *)v80 + 5) > 0x1000u && !FsRtlIsTotalDeviceFailure(v24) )
    {
      v66 = MiState;
      v31 = 1;
      if ( !dword_6348DC && (!v25 || (v83 & 2) != 0) )
        dword_6348DC = 32;
    }
    else
    {
      v66 = MiState;
      v31 = 0;
    }
    if ( (*(_BYTE *)(a1 + 113) & 4) != 0 )
    {
LABEL_138:
      v24 = -1073741801;
      goto LABEL_43;
    }
    v33 = v84;
LABEL_129:
    if ( v85 <= MmHighestUserAddress )
      goto LABEL_43;
    v67 = v66[903];
    if ( v85 >= v67 && *((_BYTE *)v66 + ((int)(((v85 >> 20) & 0xFFC) - ((v67 >> 20) & 0xFFC)) >> 2) + 9692) == 8 )
      goto LABEL_43;
    if ( MiExceptionForMappedVa(v85) )
      goto LABEL_43;
    if ( !v31 )
    {
      v70 = v90;
      MiIsAddressValid(v90, 0, v68, v69);
      MmFlushAllFilesystemPages(1);
      if ( v33 < 0 )
        v24 = v33;
      KeBugCheckEx(122, v70, v24);
    }
    if ( v33 == -1073741761 )
      goto LABEL_43;
    goto LABEL_138;
  }
LABEL_43:
  v34 = v89;
  if ( v89 == -1 )
  {
    v35 = 0;
  }
  else
  {
    v52 = v91;
    MiCopyPage(v89, (v91 - MmPfnDatabase) / 24, 0, 1);
    v35 = MmPfnDatabase + 24 * v34;
    *(_DWORD *)(v35 + 8) = 128;
    if ( (*(_BYTE *)(v35 + 23) & 7) == 3 )
    {
      v71 = KfRaiseIrql(2);
      v72 = (unsigned __int8 *)(v35 + 15);
      do
        v73 = __ldrex(v72);
      while ( __strex(v73 | 0x80, v72) );
      __dmb(0xBu);
      if ( v73 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v74 = *(_DWORD *)(v35 + 12);
            __dmb(0xBu);
          }
          while ( (v74 & 0x80000000) != 0 );
          do
            v75 = __ldrex(v72);
          while ( __strex(v75 | 0x80, v72) );
          __dmb(0xBu);
        }
        while ( v75 >> 7 );
      }
      *(_DWORD *)(v35 + 4) = *(_DWORD *)(v52 + 4);
      __dmb(0xBu);
      v76 = (unsigned int *)(v35 + 12);
      do
        v77 = __ldrex(v76);
      while ( __strex(v77 & 0x7FFFFFFF, v76) );
      KfLowerIrql(v71);
    }
  }
  v36 = v92;
  v37 = v87;
  *(_DWORD *)(a1 + 48) = v24;
  return MiFinishHardFault(a1, v36, v37, v35, &v86);
}
