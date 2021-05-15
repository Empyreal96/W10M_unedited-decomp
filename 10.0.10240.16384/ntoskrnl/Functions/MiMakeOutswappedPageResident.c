// MiMakeOutswappedPageResident 
 
unsigned int __fastcall MiMakeOutswappedPageResident(int a1, unsigned int a2, int a3, int a4, int a5)
{
  int v5; // r0
  int v6; // r5
  int v7; // r0
  unsigned int v8; // r6
  int v9; // r10
  bool v10; // zf
  int v11; // r5
  int v12; // r7
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned __int8 *v15; // r1
  int v16; // r3
  unsigned int v17; // r2
  int v18; // r0
  int v19; // r4
  unsigned int *v20; // r2
  unsigned int v21; // r0
  unsigned int v22; // r6
  unsigned int *v23; // r2
  unsigned int v24; // r4
  int v25; // r3
  unsigned int v26; // r4
  unsigned int v27; // r5
  int v28; // r0
  int v29; // r4
  int v30; // r3
  int v31; // r6
  int v32; // r0
  int v33; // r5
  int v34; // r2
  int v35; // r3
  int v36; // r4
  int v37; // r0
  int v38; // r7
  int v39; // r8
  int v40; // r5
  int v41; // r0
  int v42; // r4
  int v43; // r0
  unsigned int v44; // r4
  int v45; // r5
  unsigned int v46; // r8
  unsigned int v47; // r3
  int v48; // r2
  unsigned int v49; // r2
  unsigned int v50; // r3
  int v51; // r6
  unsigned int v52; // r3
  unsigned int v53; // r2
  int v54; // r8
  int v55; // r0
  int v56; // r2
  char v57; // r5
  int v58; // r0
  int v59; // r4
  unsigned __int8 *v60; // r1
  unsigned int v61; // r2
  int v62; // r3
  unsigned int *v63; // r2
  unsigned int v64; // r0
  int v65; // r4
  int v66; // r0
  unsigned __int8 *v67; // r1
  unsigned int v68; // r2
  int v69; // r3
  unsigned int v70; // r6
  unsigned int *v71; // r2
  unsigned int v72; // r5
  int v73; // r3
  char v75[4]; // [sp+8h] [bp-148h] BYREF
  int v76; // [sp+Ch] [bp-144h]
  int v77; // [sp+10h] [bp-140h]
  int v78; // [sp+14h] [bp-13Ch] BYREF
  int v79; // [sp+18h] [bp-138h]
  unsigned int v80; // [sp+1Ch] [bp-134h]
  unsigned int v81; // [sp+20h] [bp-130h]
  _WORD *v82; // [sp+28h] [bp-128h] BYREF
  unsigned __int16 v83; // [sp+2Ch] [bp-124h]
  unsigned __int16 v84; // [sp+2Eh] [bp-122h]
  unsigned int v85; // [sp+30h] [bp-120h]
  char v86[16]; // [sp+38h] [bp-118h] BYREF
  char v87[32]; // [sp+48h] [bp-108h] BYREF
  int v88; // [sp+68h] [bp-E8h] BYREF
  int v89; // [sp+6Ch] [bp-E4h]
  int v90; // [sp+70h] [bp-E0h] BYREF
  int v91; // [sp+74h] [bp-DCh]
  int v92; // [sp+A0h] [bp-B0h]
  char v93; // [sp+A9h] [bp-A7h]
  char v94; // [sp+ABh] [bp-A5h]
  int v95; // [sp+D0h] [bp-80h] BYREF
  __int16 v96; // [sp+D4h] [bp-7Ch]
  __int16 v97; // [sp+D6h] [bp-7Ah]
  unsigned int v98; // [sp+DCh] [bp-74h]
  unsigned int v99; // [sp+E0h] [bp-70h]
  int v100; // [sp+E4h] [bp-6Ch]
  int v101; // [sp+E8h] [bp-68h]
  int v102; // [sp+ECh] [bp-64h]

  v5 = a4;
  v6 = a3;
  v76 = a4;
  v77 = a3;
  v85 = a2;
  while ( 1 )
  {
    v7 = MiMapPageInHyperSpaceWorker(v5, (int)v75, 0x80000000);
    v8 = *(_DWORD *)(v7 + v6);
    MiUnmapPageInHyperSpaceWorker(v7 + v6, (unsigned __int8)v75[0], 0x80000000);
    v80 = 0x3FFFFF;
    if ( (v8 & 0x800) == 0 )
      break;
    v9 = v8 >> 12;
    v10 = MI_IS_PFN(v8 >> 12) == 0;
    v5 = v76;
    if ( !v10 )
    {
      v11 = MmPfnDatabase + 24 * v9;
      v12 = KfRaiseIrql(2);
      v13 = (unsigned __int8 *)(v11 + 15);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 | 0x80, v13) );
      __dmb(0xBu);
      if ( v14 >> 7 )
      {
        v15 = (unsigned __int8 *)(v11 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v16 = *(_DWORD *)(v11 + 12);
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
      v18 = MiMapPageInHyperSpaceWorker(v76, 0, 0x80000000);
      v19 = *(_DWORD *)(v18 + v77);
      MiUnmapPageInHyperSpaceWorker(v18 + v77, 17, 0x80000000);
      if ( v19 == v8 )
      {
        if ( (*(_BYTE *)(v11 + 18) & 7) == 6 )
        {
          *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | (*(_DWORD *)(v11 + 12) + 1) & 0x3FFFFFFF;
          goto LABEL_20;
        }
        if ( MiUnlinkPageFromList(v11, 0) )
        {
          ++*(_WORD *)(v11 + 16);
          *(_BYTE *)(v11 + 18) = *(_BYTE *)(v11 + 18) & 0xF8 | 6;
          *(_DWORD *)(v11 + 12) = *(_DWORD *)(v11 + 12) & 0xC0000000 | 1;
LABEL_20:
          v22 = MiCaptureDirtyBitToPfn(v11);
          __dmb(0xBu);
          v23 = (unsigned int *)(v11 + 12);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 & 0x7FFFFFFF, v23) );
          KfLowerIrql(v12);
          if ( v22 )
            MiReleasePageFileInfo((int)MiSystemPartition, v22, 0, v25);
          goto LABEL_24;
        }
        MiDiscardTransitionPte(v11);
      }
      __dmb(0xBu);
      v20 = (unsigned int *)(v11 + 12);
      do
        v21 = __ldrex(v20);
      while ( __strex(v21 & 0x7FFFFFFF, v20) );
      KfLowerIrql(v12);
      v5 = v76;
      v6 = v77;
    }
  }
  MI_INITIALIZE_COLOR_BASE(0, a5 + 1, (int)&v82);
  v33 = v84;
  v34 = (unsigned __int16)(*v82 + 1);
  v35 = v83;
  *v82 = v34;
  v36 = v35 & v34;
  while ( 1 )
  {
    v37 = MiGetPage((int)MiSystemPartition, v33 | v36, 0);
    v9 = v37;
    if ( v37 != -1 )
      break;
    MiWaitForFreePage(MiSystemPartition);
  }
  v38 = MmPfnDatabase + 24 * v37;
  MiFinalizePageAttribute(v38, 1, 0);
  v39 = v76;
  v40 = 32 * ((v8 >> 5) & 0x1F | (v9 << 7) | 0x40);
  v41 = MiMapPageInHyperSpaceWorker(v76, (int)v75, 0x80000000);
  v42 = v41 + v77;
  if ( v41 + v77 + 0x40000000 > v80 )
  {
    *(_DWORD *)v42 = v40;
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)v42 = v40;
    if ( (unsigned int)(v42 + 1070596096) <= 0xFFF )
    {
      v43 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v43, (_DWORD *)(v43 + 4 * (v42 & 0xFFF)), v40);
    }
  }
  MiUnmapPageInHyperSpaceWorker(v42, (unsigned __int8)v75[0], 0x80000000);
  v44 = v85;
  if ( v85 == -1070593024 )
  {
    MiInitializePfnForOtherProcess(v9, -1070593024, -1, 0);
    *(_DWORD *)(v38 + 20) = *(_DWORD *)(v38 + 20) & 0xFFF00000 | v9 & 0xFFFFF;
  }
  else
  {
    MiInitializePfnForOtherProcess(v9, v85, v39, 0);
  }
  MiMarkPageActive(v38);
  v45 = (v44 << 10) & 0xFFF;
  v46 = (v44 << 10) & 0xFFFFF000;
  v82 = (_WORD *)(4 * (((unsigned int)(v45 + 0x1FFF) >> 12) + 7));
  *(_DWORD *)(v38 + 8) = v8;
  v79 = v45;
  v81 = v46;
  while ( 1 )
  {
    MiInitializeInPageSupport((unsigned int)v86, 0);
    v94 |= 0x10u;
    v47 = *(_DWORD *)(v38 + 8);
    v48 = (v47 & 0x10) != 0 && ((v47 >> 2) & 1) == dword_63F99C;
    v49 = v93 & 0x7F | (v48 << 7);
    v93 = v49;
    v50 = *(_DWORD *)(v38 + 8);
    v51 = (v50 >> 2) & 1;
    if ( (v50 & 0x10) != 0 )
      v52 = v50 >> 13;
    else
      v52 = 0;
    v53 = v49 >> 7;
    if ( v53 )
    {
      v90 = v52 & 0xFFFFFFF | (v51 << 28);
      v91 = 0;
    }
    else
    {
      v90 = v52 << 12;
      v91 = 0;
    }
    v95 = 0;
    v99 = v46;
    v100 = 4096;
    v101 = v45;
    v102 = v9;
    v96 = (__int16)v82;
    v97 = 16386;
    v54 = *(_DWORD *)&MiSystemPartition[2 * v51 + 1800];
    v92 = 4096;
    if ( v53 )
    {
      v88 = 0;
      v89 = 0;
      v55 = SmPageRead(&v90, &v95, v87, &v88);
    }
    else
    {
      v55 = IoPageRead(*(_DWORD *)(v54 + 32), (int)&v95, &v90, (int)v87, (int)&v88);
    }
    if ( v55 < 0 )
    {
      v88 = v55;
      v89 = 0;
      KeSetEvent((int)v87, 0, 0);
    }
    KeWaitForSingleObject((unsigned int)v87, 9, 0, 0, 0);
    v57 = 0;
    v78 = 0;
    if ( (v93 & 0x80) != 0 )
    {
      MiStoreFaultComplete(v86, &v78);
      v58 = KfRaiseIrql(2);
      v59 = v58;
      v60 = (unsigned __int8 *)(v38 + 15);
      do
        v61 = __ldrex(v60);
      while ( __strex(v61 | 0x80, v60) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v61 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v62 = *(_DWORD *)(v38 + 12);
          __dmb(0xBu);
        }
        while ( (v62 & 0x80000000) != 0 );
        do
          v61 = __ldrex(v60);
        while ( __strex(v61 | 0x80, v60) );
      }
      MiStoreInPageComplete(v58, &v78, v61, 0);
      __dmb(0xBu);
      v63 = (unsigned int *)(v38 + 12);
      do
        v64 = __ldrex(v63);
      while ( __strex(v64 & 0x7FFFFFFF, v63) );
      KfLowerIrql(v59);
      v57 = v78;
    }
    v65 = v88;
    if ( v88 >= 0 && *(_DWORD *)(v54 + 108) )
    {
      v94 |= 0x20u;
      v65 = MiValidatePagefilePageHash((int)v86);
    }
    if ( (v97 & 1) != 0 )
      MmUnmapLockedPages(v98, (int)&v95, v56);
    if ( v65 >= 0 )
      break;
    if ( v65 != -1073741670 && v65 != -1073741663 && v65 != -1073741801 )
    {
      MmFlushAllFilesystemPages(1);
      KeBugCheck2(119, v65, v65, v51, v90, 0);
    }
    if ( (v57 & 1) != 0 )
    {
      v46 = v81;
      v10 = (v57 & 2) == 0;
      v45 = v79;
      if ( v10 )
        continue;
    }
    KeDelayExecutionThread(0, 0, (unsigned int *)MiHalfSecond);
    v45 = v79;
    v46 = v81;
  }
  if ( v89 != 4096 )
  {
    MmFlushAllFilesystemPages(1);
    KeBugCheck2(119, 2, v65, v51, v90, 0);
  }
  v66 = KfRaiseIrql(2);
  v67 = (unsigned __int8 *)(v38 + 15);
  do
    v68 = __ldrex(v67);
  while ( __strex(v68 | 0x80, v67) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v68 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v69 = *(_DWORD *)(v38 + 12);
      __dmb(0xBu);
    }
    while ( (v69 & 0x80000000) != 0 );
    do
      v68 = __ldrex(v67);
    while ( __strex(v68 | 0x80, v67) );
  }
  v70 = *(_DWORD *)(v38 + 8);
  *(_DWORD *)(v38 + 8) = 128;
  *(_BYTE *)(v38 + 18) |= 0x10u;
  __dmb(0xBu);
  v71 = (unsigned int *)(v38 + 12);
  do
    v72 = __ldrex(v71);
  while ( __strex(v72 & 0x7FFFFFFF, v71) );
  KfLowerIrql(v66);
  MiReleasePageFileInfo((int)MiSystemPartition, v70, 0, v73);
LABEL_24:
  v26 = v85;
  v27 = (MiDetermineUserGlobalPteMask(v85) | (v9 << 12)) & 0xFFFFFDFF | dword_681120 & 0x5ED | 0x812;
  if ( v26 == -1070593024 )
    v27 |= 1u;
  v28 = MiMapPageInHyperSpaceWorker(v76, (int)v75, 0x80000000);
  v29 = v28 + v77;
  if ( v28 + v77 + 0x40000000 > v80 )
  {
    *(_DWORD *)v29 = v27;
  }
  else
  {
    v30 = *(_DWORD *)v29;
    v31 = 0;
    __dmb(0xBu);
    *(_DWORD *)v29 = v27;
    if ( (v30 & 2) == 0 && (v27 & 2) != 0 )
      v31 = 1;
    if ( (unsigned int)(v29 + 1070596096) <= 0xFFF )
    {
      v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v32, (_DWORD *)(v32 + 4 * (v29 & 0xFFF)), v27);
    }
    if ( v31 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  MiUnmapPageInHyperSpaceWorker(v29, (unsigned __int8)v75[0], 0x80000000);
  return v27;
}
