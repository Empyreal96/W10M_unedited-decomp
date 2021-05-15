// MiInitSystem 
 
int __fastcall MiInitSystem(int a1, int a2)
{
  int v2; // r9
  __int64 v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  int *v7; // r0
  unsigned int *v8; // r8
  unsigned int v9; // r6
  unsigned int v10; // lr
  unsigned int v11; // r1
  int v12; // r1
  unsigned int *v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r1
  unsigned int v16; // r4
  int v17; // r0
  int v18; // r1
  int v19; // r5
  int v20; // r7
  unsigned int v21; // r2
  _DWORD *v22; // r4
  int v23; // r0
  int v24; // r0
  int v25; // r1
  int v26; // r4
  int *v27; // r8
  int v28; // r0
  int v29; // r0
  int *v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r1
  int v33; // r3
  int v34; // r4
  int v35; // r0
  int v36; // r0
  int v37; // r2
  int v38; // r0
  unsigned int v39; // r4
  _DWORD *v40; // r5
  unsigned int v41; // r0
  unsigned int v42; // r6
  unsigned int v43; // r4
  __int16 v44; // r0
  _DWORD *v45; // r8
  int v46; // r7
  unsigned int v47; // r2
  int v48; // r1
  unsigned int v49; // r9
  unsigned int v50; // r2
  int v51; // r3
  int v52; // r0
  unsigned int v53; // r4
  char *v54; // r7
  unsigned int i; // r1
  char **v56; // r2
  char *v57; // t1
  _DWORD *v58; // r4
  unsigned int j; // r5
  unsigned int v60; // r2
  __int16 v61; // r3
  int v62; // r8
  unsigned int v63; // r10
  int v64; // r0
  int v65; // r8
  int v66; // r2
  int v67; // r3
  unsigned int v68; // r0
  unsigned __int8 *v69; // r4
  char v70; // r5
  unsigned int v71; // r0
  unsigned int v72; // r2
  unsigned int v73; // r1
  unsigned int v74; // r3
  int v75; // r4
  int v76; // r3
  int v77; // r3
  __int16 v78; // r3
  unsigned __int8 *v79; // r3
  unsigned int v80; // r2
  int v81; // r1
  int v82; // r2
  unsigned int v83; // r1
  unsigned int v84; // r0
  unsigned int v85; // r4
  unsigned int v86; // r3
  int v87; // r0
  int v88; // r8
  int v89; // r4
  int v90; // r3
  int v91; // r1
  int v92; // r2
  int v93; // r2
  int v94; // r5
  int v95; // r3
  __int16 v96; // r3
  unsigned int *v97; // r2
  unsigned int v98; // r1
  int v99; // r3
  unsigned __int8 *v100; // r2
  unsigned int v101; // r4
  int v102; // r1
  int v103; // r3
  int v104; // [sp+10h] [bp-88h] BYREF
  unsigned int v105; // [sp+14h] [bp-84h] BYREF
  int v106; // [sp+18h] [bp-80h]
  unsigned int v107; // [sp+1Ch] [bp-7Ch]
  _DWORD *v108; // [sp+20h] [bp-78h]
  int v109; // [sp+24h] [bp-74h]
  int v110; // [sp+28h] [bp-70h]
  int v111[6]; // [sp+30h] [bp-68h] BYREF
  _DWORD v112[6]; // [sp+48h] [bp-50h] BYREF
  int v113[14]; // [sp+60h] [bp-38h] BYREF

  v2 = a2;
  v106 = a2;
  v111[0] = (int)MiModifiedPageWriter;
  v111[1] = (int)MiMappedPageWriter;
  v111[2] = (int)KeBalanceSetManager;
  v111[3] = (int)KeSwapProcessOrStack;
  v111[4] = (int)MiZeroPageThread;
  if ( a1 )
  {
    if ( a1 != 1 )
    {
      if ( a1 == 2 )
      {
        MiUnlockBootPageSections();
        v4 = TraceLoggingRegister((int)&unk_617650, v3);
        __dmb(0xBu);
        dword_634CA0 = (int)&unk_617650;
        MiFlushStrongCodeDriverLoadFailures(v4);
        if ( MmNonPagedPoolLimit | MmSessionSpaceLimit | MmSystemPtesLimit | MmSystemCacheLimit | MmPagedPoolLimit
          && !byte_634C8D )
        {
          v113[0] = 5;
          v113[1] = 6;
          v113[2] = 8;
          v113[3] = 9;
          v113[4] = 1;
          v105 = -dword_63389C;
          v112[0] = &MmNonPagedPoolLimit;
          v112[1] = &MmPagedPoolLimit;
          v112[2] = &MmSystemCacheLimit;
          v112[3] = &MmSystemPtesLimit;
          v112[4] = &MmSessionSpaceLimit;
          v60 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v61 = *(_WORD *)(v60 + 0x136);
          v106 = v60;
          *(_WORD *)(v60 + 310) = v61 - 1;
          v62 = 2147483644;
          v63 = -1;
          v64 = 4092;
          v104 = 2147483644;
          if ( !KiAbEnabled || ((unsigned int)&dword_63378C & 0x7FFFFFFC) == 0 )
          {
            v75 = 0;
            goto LABEL_144;
          }
          v65 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          if ( (__get_CPSR() & 0x80) != 0 )
          {
            v66 = 0;
          }
          else
          {
            __disable_irq();
            v66 = 1;
          }
          v67 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
          if ( v66 )
            __enable_irq();
          if ( (v67 & 0x10001) != 0 )
          {
            v68 = KeGetCurrentIrql(4092);
            KeBugCheck2(402, v65, (unsigned int)&dword_63378C, v68, 0, 0);
          }
          --*(_WORD *)(v65 + 310);
          if ( !*(_BYTE *)(v65 + 484) )
          {
            if ( !*(_BYTE *)(v65 + 810) )
            {
              v75 = 0;
              if ( (dword_682604 & 0x200) != 0 )
                v64 = (int)EtwTraceAutoBoostEntryExhaustion(v65, (int)&dword_63378C);
              goto LABEL_137;
            }
            v69 = (unsigned __int8 *)(v65 + 810);
            v70 = *(_BYTE *)(v65 + 810);
            __dmb(0xBu);
            do
              v71 = __ldrex(v69);
            while ( __strex(v71 & ~v70, v69) );
            __dmb(0xBu);
            v64 = 4092;
            *(_BYTE *)(v65 + 484) |= v70;
          }
          v72 = *(unsigned __int8 *)(v65 + 484);
          v73 = __clz(__rbit(v72));
          v108 = (_DWORD *)v73;
          *(_BYTE *)(v65 + 484) = v72 & ~(unsigned __int8)(1 << v73);
          v74 = v65 + 48 * v73;
          v75 = v74 + 488;
          if ( v74 != -488 )
          {
            if ( (unsigned int)&dword_63378C >= dword_63389C
              && ((v76 = *((unsigned __int8 *)&MiState[2423]
                         + ((int)((((unsigned int)&dword_63378C >> 20) & 0xFFC)
                                - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
                   v76 == 1)
               || v76 == 11)
              && (v81 = *(_DWORD *)(v65 + 116), (v82 = *(_DWORD *)(v81 + 324)) != 0)
              && v81 != PsInitialSystemProcess )
            {
              v77 = *(_DWORD *)(v82 + 8);
            }
            else
            {
              v77 = -1;
            }
            *(_DWORD *)(v75 + 20) = v77;
            *(_DWORD *)(v75 + 16) = (unsigned int)&dword_63378C & 0x7FFFFFFC;
            goto LABEL_131;
          }
LABEL_137:
          v79 = (unsigned __int8 *)(v65 + 81);
          do
            v80 = __ldrex(v79);
          while ( __strex(v80 | 0x80, v79) );
LABEL_131:
          v78 = *(_WORD *)(v65 + 310) + 1;
          *(_WORD *)(v65 + 310) = v78;
          if ( !v78 && *(_DWORD *)(v65 + 100) != v65 + 100 )
            KiCheckForKernelApcDelivery(v64);
          v62 = v104;
          do
LABEL_144:
            v83 = __ldrex((unsigned __int8 *)&dword_63378C);
          while ( __strex(v83 | 1, (unsigned __int8 *)&dword_63378C) );
          __dmb(0xBu);
          if ( (v83 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&dword_63378C, v75, (unsigned int)&dword_63378C);
          if ( v75 )
            *(_BYTE *)(v75 + 14) |= 1u;
          v84 = 0;
          v85 = v105;
          do
          {
            v86 = *(_DWORD *)v112[v84];
            if ( v86 && v86 < v85 >> 20 )
              MiState[v113[v84] + 2566] = ((v86 << 20) + 0x3FFFFF) >> 22;
            ++v84;
          }
          while ( v84 < 5 );
          __dmb(0xBu);
          do
            v87 = __ldrex((unsigned int *)&dword_63378C);
          while ( __strex(v87 - 1, (unsigned int *)&dword_63378C) );
          if ( (v87 & 2) != 0 && (v87 & 4) == 0 )
            v87 = (int)ExfTryToWakePushLock((unsigned int *)&dword_63378C);
          if ( !KiAbEnabled || ((unsigned int)&dword_63378C & v62) == 0 )
            goto LABEL_194;
          v88 = 0;
          v89 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          if ( (unsigned int)&dword_63378C >= dword_63389C )
          {
            v90 = *((unsigned __int8 *)&MiState[2423]
                  + ((int)((((unsigned int)&dword_63378C >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
            if ( v90 == 1 || v90 == 11 )
            {
              v91 = *(_DWORD *)(v89 + 116);
              v92 = *(_DWORD *)(v91 + 324);
              if ( v92 )
              {
                if ( v91 != PsInitialSystemProcess )
                  v63 = *(_DWORD *)(v92 + 8);
              }
            }
          }
          if ( (unsigned int)KeGetCurrentIrql(v87) <= 1 )
          {
            v88 = 1;
            --*(_WORD *)(v89 + 310);
          }
          v87 = KiAbThreadClearAcquiredLockEntry(v89, (int)&dword_63378C, v63);
          v94 = v87;
          if ( v87 )
          {
            *(_BYTE *)(v87 + 16) |= 2u;
            if ( *(int *)(v87 + 16) < 0 )
              v87 = KiAbEntryRemoveFromTree(v87);
            v96 = *(_WORD *)(v94 + 44);
            if ( v96 )
            {
              if ( (v96 & 1) != 0 )
              {
                __dmb(0xBu);
                v97 = (unsigned int *)(v89 + 804);
                do
                  v98 = __ldrex(v97);
                while ( __strex(v98 - 1, v97) );
                __dmb(0xBu);
                v87 = PsBoostThreadIoEx(v89, 1, 0);
              }
              if ( (*(_WORD *)(v94 + 44) & 0xFFFE) != 0 )
                v87 = KiAbThreadUnboostCpuPriority(v89, v94, v93, *(_WORD *)(v94 + 44) & 0xFFFE);
              if ( (dword_682604 & 0x200) != 0 )
                v87 = (int)EtwTraceAutoBoostClearFloor(
                             v89,
                             *(_DWORD *)(v94 + 16) & 0xFFFFFFFC | 0x80000000,
                             *(_WORD *)(v94 + 44));
              *(_WORD *)(v94 + 44) = 0;
            }
            *(_BYTE *)(v94 + 13) &= 0xFEu;
            *(_DWORD *)(v94 + 16) = 0;
            v99 = (v94 - v89 - 488) / 48;
            if ( !v88 )
            {
              __dmb(0xBu);
              v87 = (char)(1 << v99);
              v100 = (unsigned __int8 *)(v89 + 810);
              do
                v101 = __ldrex(v100);
              while ( __strex(v101 | v87, v100) );
              __dmb(0xBu);
LABEL_194:
              v102 = v106;
              v103 = (__int16)(*(_WORD *)(v106 + 310) + 1);
              *(_WORD *)(v106 + 310) = v103;
              if ( !v103 && *(_DWORD *)(v102 + 100) != v102 + 100 )
                KiCheckForKernelApcDelivery(v87);
              return 1;
            }
            *(_BYTE *)(v89 + 484) |= 1 << v99;
          }
          else
          {
            if ( (*(_DWORD *)(v89 + 80) & 0x8000) == 0 )
              KeBugCheck2(354, v89, (unsigned int)&dword_63378C, v63, 0, 0);
            if ( !v88 )
              goto LABEL_194;
          }
          v95 = (__int16)(*(_WORD *)(v89 + 310) + 1);
          *(_WORD *)(v89 + 310) = v95;
          if ( !v95 && *(_DWORD *)(v89 + 100) != v89 + 100 )
            v87 = KiCheckForKernelApcDelivery(v87);
          goto LABEL_194;
        }
        return 1;
      }
      return 0;
    }
    v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    *(_DWORD *)(MmPfnDatabase + 24 * (*(_DWORD *)(v12 + 24) >> 12)) = v12;
    __dmb(0xBu);
    v13 = (unsigned int *)(v12 + 192);
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x400, v13) );
    __dmb(0xBu);
    do
      v15 = __ldrex(v13);
    while ( __strex(v15 | 0x800, v13) );
    __dmb(0xBu);
    v16 = 0x3FFFFF;
    MEMORY[0xFFFF9244] = 0x400000;
    v107 = 0x3FFFFF;
    if ( !BBTPagesToReserve )
    {
LABEL_29:
      v17 = MiSectionInitialization();
      if ( v17 )
      {
        if ( MiInitializeCfg(v17, v18) >= 0 )
        {
          dword_634308 = 0;
          v19 = ExAllocatePoolWithTag(1, 4, 538996045);
          if ( v19 )
          {
            v20 = MEMORY[0xC03FFFE4] >> 12;
            v21 = (dword_681114 & 0x3ED | (v20 << 12) | MiDetermineUserGlobalPteMask(0xC03FFFE4)) & 0xFFFFF3FF | 0x12;
            if ( v19 + 0x40000000 <= v16 )
            {
              v33 = *(_DWORD *)v19;
              v34 = 0;
              __dmb(0xBu);
              *(_DWORD *)v19 = v21;
              if ( (v33 & 2) == 0 )
                v34 = 1;
              if ( (unsigned int)(v19 + 1070596096) <= 0xFFF )
              {
                v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v35, (_DWORD *)(v35 + 4 * (v19 & 0xFFF)), v21);
              }
              if ( v34 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
            }
            else
            {
              *(_DWORD *)v19 = v21;
            }
            dword_6337D8 = v19;
            v22 = (_DWORD *)(MmPfnDatabase + 24 * v20);
            v23 = MiLockPage((int)v22);
            v22[1] = v19;
            v22[2] = 128;
            v22[5] |= 0x8000000u;
            MiUnlockPage((int)v22, v23);
            dword_634D2C = (int)&dword_634D28;
            dword_634D28 = (int)&dword_634D28;
            MiInitializeSessionIds();
            if ( MiInitializePartitions(1) )
            {
              MiInitializeCacheFlushing();
              MiComputeOptimalZeroPath();
              v24 = MiInitializeMemoryEvents(MiSystemPartition);
              if ( v24 )
              {
                MiInitializeModifiedWriterParameters(v24, v25);
                if ( MiAllocateMappedWriterMdls((int)MiSystemPartition) >= 0 )
                {
                  v26 = 0;
                  v27 = v111;
                  while ( 1 )
                  {
                    ++v27;
                    if ( PsCreateSystemThread((int)&v104, 0x1FFFFF, 0) < 0 )
                      break;
                    ObCloseHandle(v104);
                    if ( (unsigned int)++v26 >= 5 )
                    {
                      v28 = MiInitializeMirroring(1);
                      v29 = MiStartZeroPageWorkers(v28);
                      if ( KernelVerifier )
                      {
                        v54 = VfRegularThunks;
                        for ( i = 0; i < 2; ++i )
                        {
                          v56 = &VfRegularThunks;
                          if ( v54 )
                          {
                            while ( v56[4] != (char *)ViKernelVerifierMap[i] )
                            {
                              v57 = v56[5];
                              v56 += 5;
                              if ( !v57 )
                                goto LABEL_96;
                            }
                          }
                          else
                          {
LABEL_96:
                            v56 = 0;
                          }
                          ViKernelVerifierThunks[i] = (int)v56;
                        }
                        v29 = RtlImageDirectoryEntryToData(PsNtosImageBase, 1, 12, (int)&v105);
                        v58 = (_DWORD *)v29;
                        if ( v29 )
                        {
                          for ( j = v105 >> 2; j; --j )
                          {
                            v30 = ViKernelVerifierThunks;
                            v31 = 0;
                            while ( 1 )
                            {
                              if ( v30 )
                              {
                                v29 = *(_DWORD *)(*v30 + 8);
                                if ( *v58 == v29 )
                                  break;
                              }
                              ++v31;
                              ++v30;
                              if ( v31 >= 2 )
                                goto LABEL_106;
                            }
                            if ( !ViKernelVerifierOriginalCalls[v31] )
                              ViKernelVerifierOriginalCalls[v31] = v29;
                            v29 = MmReplaceImportEntry((unsigned int)v58, *(_DWORD *)(*v30 + 4));
LABEL_106:
                            ++v58;
                          }
                        }
                      }
                      dword_63378C = 0;
                      MiWriteProtectSystemImages(v29, (int)v30, v31);
                      __dmb(0xBu);
                      do
                        v32 = __ldrex((unsigned int *)algn_634984);
                      while ( __strex(v32 - 1, (unsigned int *)algn_634984) );
                      return MiInitializeApiSets(v2) >= 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
      return 0;
    }
    v39 = (BBTPagesToReserve + 1023) & 0xFFFFFC00;
    v40 = *(_DWORD **)(*(_DWORD *)(v2 + 132) + 2288);
    if ( !v40 )
    {
      v41 = MiObtainSystemVa(v39 >> 10, 9);
      v40 = (_DWORD *)v41;
      v105 = v41;
      if ( !v41 )
      {
LABEL_68:
        BBTPagesToReserve = 0;
LABEL_90:
        v16 = v107;
        BBTBuffer = (int)v40;
        goto LABEL_29;
      }
      v42 = ((v41 >> 10) & 0x3FFFFC) - 0x40000000;
      v43 = v42 + 4 * v39;
      if ( !MiMakeZeroedPageTables(v42, v43 - 4, 0) )
      {
        MiReturnSystemVa((unsigned int)v40, v43 << 10, 9, 0);
        v40 = 0;
        goto LABEL_68;
      }
      v44 = MiDetermineUserGlobalPteMask(v42);
      v45 = *(_DWORD **)(v2 + 24);
      v39 = 0;
      v108 = v45;
      LOWORD(v46) = (dword_681120 | v44) & 0x1ED | 0xF012;
      v47 = BBTPagesToReserve;
      v104 = v2 + 24;
      if ( v45 != (_DWORD *)(v2 + 24) )
      {
        do
        {
          if ( v45[2] == 23 )
          {
            v49 = v45[4];
            v48 = v45[3];
            v109 = v48;
            if ( v49 + v39 > v47 )
              v49 = v47 - v39;
            v50 = v107;
            v39 += v49;
            do
            {
              v46 = v46 & 0xFFF | (v48 << 12);
              if ( v42 + 0x40000000 > v50 )
              {
                *(_DWORD *)v42 = v46;
              }
              else
              {
                v51 = *(_DWORD *)v42;
                v110 = 0;
                __dmb(0xBu);
                *(_DWORD *)v42 = v46;
                if ( (v51 & 2) == 0 && (v46 & 2) != 0 )
                  v110 = 1;
                if ( v42 + 1070596096 <= 0xFFF )
                {
                  v52 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                  MiArmWriteConvertedHardwarePde(v52, (_DWORD *)(v52 + 4 * (v42 & 0xFFF)), v46);
                  v48 = v109;
                }
                if ( v110 == 1 )
                {
                  __dsb(0xFu);
                  __isb(0xFu);
                }
                v50 = v107;
              }
              ++v48;
              v42 += 4;
              v109 = v48;
              --v49;
            }
            while ( v49 );
            v40 = (_DWORD *)v105;
            v45 = v108;
            v47 = BBTPagesToReserve;
            if ( v39 == BBTPagesToReserve )
              break;
          }
          v45 = (_DWORD *)*v45;
          v108 = v45;
        }
        while ( v45 != (_DWORD *)v104 );
        v2 = v106;
      }
      if ( v39 < v47 )
        BBTPagesToReserve = v39;
    }
    v53 = v39 << 12;
    KeZeroPages(v40, v53);
    *v40 = v53;
    goto LABEL_90;
  }
  MmTrackLockedPages &= 1u;
  MiInitializeCrashDumpPtes();
  do
    v5 = __ldrex((unsigned int *)algn_634984);
  while ( __strex(v5 + 1, (unsigned int *)algn_634984) );
  __dmb(0xBu);
  if ( !MiInitializeWorkingSetManagerParameters((int)MiSystemPartition) )
    return 0;
  dword_6337A0 = 305419896;
  if ( MiInitializeBootProcess(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 24) >> 12) < 0 )
    return 0;
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  MiAddLoaderHalIoMappings(MiLowHalVa, -1);
  if ( (unsigned int)MmSystemRangeStart < 0xC0000000 )
    MiAddLoaderHalIoMappings(MmSystemRangeStart, -1073741825);
  MiAddLoaderHalIoMappings(-1069547520, MiLowHalVa - 1);
  if ( KdPrintBufferAllocateSize )
    return sub_96A0FC();
  if ( !MiInitializeDriverImages() )
    return 0;
  MEMORY[0xFFFF92E8] = dword_640508;
  MEMORY[0xFFFF9244] = 0;
  if ( !MiInitializeSystemCache() )
    return 0;
  MiInitializeSystemSpaceMap((int)algn_632F64);
  dword_632EB8 = 0;
  if ( !PsInitializeQuotaSystem(0) || !MiInitializeLoadedModuleList(v2) )
    return 0;
  unk_632E04 = 0;
  unk_632E08 = 0;
  dword_63F95C = 0;
  MmConfigurePrefetchSeekThreshold(32);
  v7 = (int *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v8 = (unsigned int *)(v7 + 240);
  v9 = v7[240];
  __dmb(0xBu);
  do
  {
    v10 = v9;
    __dmb(0xBu);
    do
      v11 = __ldrex(v8);
    while ( v11 == v9 && __strex(v9 & 0xFFFF8FFF | 0x5000, v8) );
    v9 = v11;
    __dmb(0xBu);
  }
  while ( v11 != v10 );
  if ( (dword_682604 & 0x2000) != 0 )
    EtwTracePriority(v7, 1331, (v10 >> 12) & 7, 5, 0);
  MiEnablePagingTheExecutive();
  ExPageLockHandle = MmLockPagableDataSection((unsigned int)MmShutdownSystem);
  v36 = MmUnlockPagableImageSection(ExPageLockHandle);
  if ( dword_68126C )
  {
    if ( (unsigned int)dword_68126C >= 5 )
    {
      if ( (unsigned int)dword_68126C <= 0x64 )
        goto LABEL_54;
      v37 = 100;
    }
    else
    {
      v37 = 5;
    }
  }
  else
  {
    v37 = 80;
  }
  dword_68126C = v37;
LABEL_54:
  dword_6348F8 = MiAllocateDummyPage(v36);
  dword_6348FC = (dword_6348F8 - MmPfnDatabase) / 24;
  v38 = MiReservePtes(&dword_634D58, 1u);
  MmBadPointer = v38;
  if ( v38 )
  {
    MmBadPointer = v38 << 10;
    if ( MiInitializeRelocations() )
    {
      MiInitializeTbFlushing();
      return 1;
    }
  }
  return 0;
}
