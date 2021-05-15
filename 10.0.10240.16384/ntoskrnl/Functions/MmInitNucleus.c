// MmInitNucleus 
 
int __fastcall MmInitNucleus(int a1, int a2)
{
  unsigned int v3; // r0
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r2
  int v8; // r2
  unsigned int v9; // r3
  unsigned int v10; // r3
  _DWORD *v11; // r7
  int v12; // r1
  unsigned int v13; // r2
  int v14; // r3
  int v15; // r1
  char v16; // r2
  int v17; // r0
  unsigned int *v18; // r5
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r0
  unsigned int v24; // r8
  unsigned int *v25; // r7
  unsigned int v26; // r2
  unsigned int v27; // r5
  int v28; // r0
  int v29; // r0
  unsigned int v30; // r5
  unsigned int v31; // r2
  __int64 v32; // r0
  _DWORD *v33; // r0
  _DWORD *v34; // r1
  int v35; // r2
  int v36; // r3
  int v37; // r0
  int v38; // r3
  int v39; // r6
  int v40; // r0
  char *v41; // r3
  int v42; // r10
  int v43; // r0
  int v44; // r0
  int v45; // r1
  _DWORD *v46; // r0
  __int16 v47; // r2
  char v48; // r2
  unsigned int v49; // r2
  int *v50; // r1
  unsigned int v51; // r3
  int v52; // r0
  int v53; // [sp+8h] [bp-E0h] BYREF
  char v54; // [sp+Ch] [bp-DCh]
  char v55; // [sp+Dh] [bp-DBh]
  int v56; // [sp+10h] [bp-D8h]
  int v57; // [sp+14h] [bp-D4h]
  int v58; // [sp+18h] [bp-D0h]
  int v59; // [sp+1Ch] [bp-CCh]
  char v60[33]; // [sp+A0h] [bp-48h] BYREF
  _BYTE v61[3]; // [sp+C1h] [bp-27h] BYREF

  dword_633808 = 32;
  MiFlags |= 0x800u;
  MiLowHalVa = MiExamineHalVa(a1, a2);
  MiInitializeBootDefaults(a1);
  v3 = ((((unsigned int)MmUserProbeAddress >> 12) + 2) >> 10) + 1 + ((unsigned int)MmUserProbeAddress >> 12) + 2;
  v4 = (16 * v3 - 1065343041) & 0xFFC00000;
  dword_6342A8 = v4 | 1;
  dword_6342A0 = v4 + 4096;
  dword_6342A4 = v4 + 4096 + 4 * v3;
  dword_633894 = ((dword_6342A4 + 0x3FFFFF) & 0xFFC00000) - 1;
  dword_633898 = (((unsigned int)dword_633894 >> 10) & 0x3FFFFC) - 0x40000000;
  v5 = MiInitializeDynamicVa();
  v6 = dword_681280;
  if ( (_UNKNOWN *)dword_681280 != &unk_690057 )
    return sub_96ACDC(v5, 2);
  MEMORY[0xFFFF9264] = 1;
  dword_681280 = 0;
  MiInitializeNumaRanges(v5, (_DWORD *)2, v6, 0);
  sub_95E330(a1);
  if ( !MiFindLargestLoaderDescriptor(a1) )
  {
    v48 = 3;
LABEL_64:
    byte_634429 = v48;
    return 0;
  }
  MiInitMachineDependent();
  if ( (BYTE2(MiFlags) & 3u) > 1 )
  {
    v49 = 0;
    v50 = MmProtectToPteMask;
    do
    {
      if ( (v49 & 2) != 0 )
        *v50 |= 0x400u;
      ++v49;
      ++v50;
    }
    while ( v49 < 0x40 );
  }
  dword_63382C = -1;
  v8 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x7C);
  dword_633800 = v8;
  if ( !dword_633818 )
  {
    dword_633818 = v8;
    v9 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( *(_BYTE *)(v9 + 29) )
      dword_633818 /= (unsigned int)*(unsigned __int8 *)(v9 + 29);
  }
  v10 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v11 = (_DWORD *)(v10 + 1408);
  v12 = *(unsigned __int8 *)(v10 + 4984);
  v13 = v10 + 4912;
  if ( *(_BYTE *)(v10 + 4984) )
  {
    do
    {
      if ( *(_BYTE *)v13 == 1 )
      {
        v14 = *(_DWORD *)(v13 + 8);
        if ( v14 == 2 || !v14 )
          dword_633804 = *(_DWORD *)(v13 + 4);
      }
      v13 += 12;
      --v12;
    }
    while ( v12 );
  }
  if ( (unsigned int)dword_633804 < 0x4000 )
    dword_633804 = 0x4000;
  dword_633828 = 256;
  v57 = 0;
  v58 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v15 = -1069547548;
  v56 = 33;
  v59 = 0;
  v16 = MEMORY[0xC03FFFE4];
  if ( (MEMORY[0xC03FFFE4] & 1) == 0 || (MEMORY[0xC03FFFE4] & 0x800) != 0 )
  {
    v51 = MEMORY[0xC03FFFE4] & 0xFFFFF7FF | 1;
    __dmb(0xBu);
    MEMORY[0xC03FFFE4] = v51;
    if ( (v16 & 2) == 0 && (v51 & 2) != 0 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
    MiInsertTbFlushEntry((int)&v53, 0xFFFF9000, 1, 0);
  }
  MiFlushTbList((unsigned int)&v53, v15);
  v42 = MiCheckLargePageOk(a1);
  if ( !MiCreatePfnDatabase(a1) )
  {
    v48 = 6;
    goto LABEL_64;
  }
  MiInitializePfnsForValidMappings(a1);
  MiSwitchToPfns(a1);
  MxRelocatePageTables(a1);
  v43 = MiZeroBootMappings();
  MiInitializeDecayPfns(v43);
  MiInitializeSections((int)MiSystemPartition);
  v44 = MiInitializeCommitment((int)MiSystemPartition);
  MiInitializeDummyPages(v44);
  if ( !MiInitializeSystemPtes() )
  {
    v48 = 9;
    goto LABEL_64;
  }
  if ( !MiInitializeNonPagedPool() )
  {
    v48 = 7;
    goto LABEL_64;
  }
  if ( !MiMapDummyPages() )
  {
    v48 = 5;
    goto LABEL_64;
  }
  if ( !MmDynamicPfn )
    MiFreeUnusedSparsePages();
  v45 = 0;
  if ( (MiFlags & 0x30000) != 0 )
    v45 = 2048;
  if ( !InitializePool(0, v45) )
  {
    v48 = 2;
    goto LABEL_64;
  }
  MiInitializeKernelStacks();
  if ( !MmInitializeProcessor(v11) )
  {
    v48 = 10;
    goto LABEL_64;
  }
  v46 = (_DWORD *)MiReservePtes(&dword_634D58, 1u);
  v47 = (__int16)v46;
  dword_634584 = (int)v46;
  if ( !v46 )
  {
    v48 = 11;
    goto LABEL_64;
  }
  if ( (unsigned int)(v46 + 0x10000000) <= 0x3FFFFF )
  {
    __dmb(0xBu);
    *v46 = 0;
    if ( (unsigned int)(v46 + 267649024) <= 0xFFF )
    {
      v52 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v52, (_DWORD *)(v52 + 4 * (v47 & 0xFFF)), 0);
    }
  }
  else
  {
    *v46 = 0;
  }
  v41 = v60;
  do
    *v41++ = 1;
  while ( v41 != v61 );
  v60[3] = 0;
  v60[30] = 0;
  v60[31] = 0;
  v60[6] = 0;
  v60[32] = 0;
  v60[22] = 0;
  v60[23] = 0;
  v17 = MmInitializeMemoryLimits(a1, (int)v60);
  if ( !v17 || (v18 = (unsigned int *)MiConvertInitialMemoryBlock(MiSystemPartition, v17)) == 0 )
  {
    v48 = 12;
    goto LABEL_64;
  }
  if ( v42 == 1 && (MiFlags & 0x30000) == 0 )
    MxConvertKernelHal();
  v19 = MiCreateNodeLists(v18);
  dword_63F720 = v19;
  if ( !v19 )
  {
    v48 = 13;
    goto LABEL_64;
  }
  MiComputeNodeMemory(v19, v20, v21, v22);
  if ( !MiFillPfnGaps() )
  {
    v48 = 18;
    goto LABEL_64;
  }
  if ( !MiInitializeGapFrames(-1, &dword_63490C) )
  {
    v48 = 19;
    goto LABEL_64;
  }
  if ( !MiBuildPagedPool() )
    return 0;
  MiInitializeSpecialPool(0);
  v23 = ExAllocatePoolWithTag(
          512,
          4 * ((((dword_633850 + 1) & 0x1F) != 0) + ((unsigned int)(dword_633850 + 1) >> 5)),
          538996045);
  if ( !v23 )
  {
    v48 = 14;
    goto LABEL_64;
  }
  dword_634C98 = dword_633850 + 1;
  dword_634C9C = v23;
  RtlClearAllBits((int)&dword_634C98);
  v24 = 0;
  if ( *v18 )
  {
    v25 = v18 + 2;
    do
    {
      v26 = v25[1];
      if ( v26 )
        RtlSetBits(&dword_634C98, *v25, v26);
      ++v24;
      v25 += 2;
    }
    while ( v24 < *v18 );
  }
  MmPhysicalMemoryBlock = (int)v18;
  v27 = ((((_WORD)dword_633850 + 1) & 0x3FF) != 0) + ((unsigned int)(dword_633850 + 1) >> 10);
  v28 = ExAllocatePoolWithTag(512, 4 * (((v27 & 0x1F) != 0) + (v27 >> 5)), 1884056909);
  if ( !v28 )
  {
    v48 = 15;
    goto LABEL_64;
  }
  dword_634C90 = v27;
  dword_634C94 = v28;
  RtlClearAllBits((int)&dword_634C90);
  MiMarkLargePageRange(MmPfnDatabase, (((MxPfnAllocation << 12) + 0x3FFFFF) & 0xFFC00000) + MmPfnDatabase);
  if ( MxUseLargePagesForKernelAndHal == 1 )
  {
    MiMarkLargePageRange(PsNtosImageBase, (PsNtosImageEnd + 0x3FFFFF) & 0xFFC00000);
    MiMarkLargePageRange(PsHalImageBase, (PsHalImageEnd + 0x3FFFFF) & 0xFFC00000);
  }
  MiUpdatePoolLargePages();
  v29 = MiReservePtes(&dword_634D58, 1u);
  v30 = v29;
  if ( !v29 )
  {
    v48 = 4;
    goto LABEL_64;
  }
  v31 = (dword_681114 & 0x3ED | (dword_634900 << 12) | MiDetermineUserGlobalPteMask(v29)) & 0xFFFFF3FF | 0x12;
  if ( v30 + 0x40000000 <= 0x3FFFFF )
  {
    v38 = *(_DWORD *)v30;
    v39 = 0;
    __dmb(0xBu);
    *(_DWORD *)v30 = v31;
    if ( (v38 & 2) == 0 )
      v39 = 1;
    if ( v30 + 1070596096 <= 0xFFF )
    {
      v40 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v40, (_DWORD *)(v40 + 4 * (v30 & 0xFFF)), v31);
    }
    if ( v39 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  else
  {
    *(_DWORD *)v30 = v31;
  }
  LODWORD(v32) = MiComputeHash64(v30 << 10);
  qword_634310 = v32;
  MiReleasePtes(&dword_634D58, v30, 1u);
  v33 = MiInitializeWsSwapping(MiSystemPartition);
  v37 = MiInitializeNumaRanges((int)v33, v34, v35, v36);
  MiInitializeMdlTracking(v37);
  return 1;
}
