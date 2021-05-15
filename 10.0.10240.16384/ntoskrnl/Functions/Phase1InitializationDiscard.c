// Phase1InitializationDiscard 
 
int __fastcall Phase1InitializationDiscard(int a1)
{
  int v1; // r9
  void **v2; // r10
  char *v3; // r0
  char *v4; // r8
  int v5; // r0
  int v6; // r6
  void **v7; // r4
  unsigned int v8; // r5
  int v9; // r4
  int v10; // r0
  int v11; // r0
  int v12; // r2
  int v13; // r3
  int v14; // r3
  int v15; // r2
  int v16; // r2
  _BYTE *v17; // r0
  _BYTE *v18; // r0
  _BYTE *v19; // r0
  _BYTE *v20; // r0
  _BYTE *v21; // r0
  _BYTE *v22; // r0
  const char *v23; // r4
  int v24; // r0
  int v25; // r2
  int v26; // r4
  int i; // r1
  int v28; // r3
  const char *v29; // r2
  int v30; // r0
  int v31; // r0
  int v32; // r1
  int v33; // r2
  unsigned int v34; // r5
  unsigned int v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r4
  int *v38; // r3
  int v39; // r10
  int v40; // r0
  void **v41; // r2
  int v42; // r3
  int *v43; // r2
  int v44; // r0
  int v45; // r0
  int v46; // r0
  int v47; // r1
  int v48; // r0
  int v49; // r0
  int v50; // r1
  int v51; // r0
  int v52; // r0
  int v53; // r0
  int v54; // r4
  int v55; // r0
  int v56; // r4
  int v57; // r0
  int v58; // r1
  int v59; // r0
  int v60; // r0
  int v61; // r0
  int v62; // r4
  int v63; // r0
  int v64; // r1
  int v65; // r2
  __int64 v66; // r0
  int v67; // r0
  int v68; // r1
  int v69; // r0
  int v70; // r1
  int v71; // r2
  int v72; // r1
  int v73; // r2
  _BYTE *v74; // r4
  _BYTE *v75; // r0
  int v76; // r0
  int v77; // r1
  int v78; // r2
  int v79; // r0
  int v80; // r1
  int v81; // r2
  int v82; // r0
  int v83; // r2
  unsigned int v85; // r3
  int v86; // r3
  int v87; // r0
  int v88; // r0
  _BYTE *v89; // r0
  __int16 v90; // r4
  int v91; // r2
  int v92; // r3
  _BYTE *v93; // r0
  _BYTE *v94; // r0
  _BYTE *v95; // r0
  _BYTE *v96; // r0
  _BYTE *v97; // r0
  unsigned int v98; // r2
  int *v99; // r4
  int v100; // r10
  unsigned int v101; // r0
  unsigned int v102; // r3
  _DWORD *v103; // r2
  int *v104; // r5
  _DWORD *v105; // lr
  int v106; // t1
  void **v107; // r5
  void **v108; // r8
  int v109; // r2
  int v110; // t1
  int v111; // r7
  int v112; // r3
  void **v113; // r4
  void **v114; // r5
  int v115; // t1
  __int16 v116; // r3
  int v117; // r2
  char *v118; // r1
  unsigned int v119; // r10
  void **v120; // r7
  int v121; // r0
  int v122; // r5
  unsigned int v123; // r4
  void **v124; // r0
  unsigned int v125; // r1
  unsigned int v126; // r2
  __int64 v127; // r4
  int v128; // r1
  __int64 v129; // r0
  void **v130; // r5
  int v131; // lr
  int v132; // r9
  unsigned int v133; // r10
  void **v134; // r7
  int v135; // t1
  int v136; // r2
  int *v137; // lr
  int *v138; // r2
  unsigned int v139; // r10
  char *v140; // r7
  unsigned int v141; // r5
  int v142; // r3
  void **v143; // lr
  char *v144; // r0
  int v145; // r6
  int v146; // r3
  int v147; // t1
  int *v148; // r2
  __int64 v149; // r2
  char *v150; // r4
  int v151; // t1
  unsigned int v152; // r2
  int v153; // r2
  int v154; // r3
  int v155; // r0
  int v156; // r1
  int v157; // r2
  int v158; // r3
  int v159; // r5
  int v160; // r0
  unsigned int v161; // r4
  int v162; // r10
  int v163; // r5
  int v164; // r10
  __int16 v165; // r3
  void **v166; // r3
  int v167; // r2
  unsigned int v168; // r4
  __int16 v169; // r3
  void **v170; // r3
  int v171; // r2
  unsigned int v172; // r3
  _BYTE *v173; // r2
  int v174; // r2
  int v175; // r1
  int v176; // r0
  int v177; // r1
  int *v178; // r4
  __int64 v179; // r0
  unsigned __int64 v180; // r0
  unsigned int v181; // r4
  unsigned int v182; // r5
  int v183; // r4
  int v184; // r5
  _BYTE *v185; // r4
  int v186; // r5
  unsigned int v187; // r3
  void **v188; // [sp+18h] [bp-200h] BYREF
  void **v189; // [sp+1Ch] [bp-1FCh] BYREF
  int v190; // [sp+20h] [bp-1F8h]
  int v191; // [sp+24h] [bp-1F4h] BYREF
  int *v192; // [sp+28h] [bp-1F0h] BYREF
  int v193; // [sp+2Ch] [bp-1ECh] BYREF
  int v194[2]; // [sp+30h] [bp-1E8h] BYREF
  __int64 v195; // [sp+38h] [bp-1E0h] BYREF
  char *v196; // [sp+40h] [bp-1D8h]
  int v197; // [sp+44h] [bp-1D4h]
  int v198; // [sp+48h] [bp-1D0h]
  int v199; // [sp+4Ch] [bp-1CCh]
  __int64 v200; // [sp+50h] [bp-1C8h] BYREF
  int v201; // [sp+58h] [bp-1C0h] BYREF
  int v202; // [sp+5Ch] [bp-1BCh]
  int v203; // [sp+60h] [bp-1B8h]
  int v204; // [sp+64h] [bp-1B4h] BYREF
  unsigned __int16 v205[4]; // [sp+68h] [bp-1B0h] BYREF
  void **v206; // [sp+70h] [bp-1A8h]
  unsigned int v207; // [sp+74h] [bp-1A4h]
  int v208; // [sp+78h] [bp-1A0h] BYREF
  int v209; // [sp+7Ch] [bp-19Ch]
  int v210; // [sp+80h] [bp-198h]
  int v211; // [sp+84h] [bp-194h] BYREF
  int v212[4]; // [sp+88h] [bp-190h] BYREF
  char v213[8]; // [sp+98h] [bp-180h] BYREF
  char v214[8]; // [sp+A0h] [bp-178h] BYREF
  char v215[8]; // [sp+A8h] [bp-170h] BYREF
  __int16 v216[8]; // [sp+B0h] [bp-168h] BYREF
  char v217[16]; // [sp+C0h] [bp-158h] BYREF
  char v218[16]; // [sp+D0h] [bp-148h] BYREF
  char v219[256]; // [sp+E0h] [bp-138h] BYREF
  char v220[56]; // [sp+1E0h] [bp-38h] BYREF

  v1 = a1;
  v190 = a1;
  v198 = 0;
  v2 = (void **)ExAllocatePoolWithTag(512, 512, 1953066569);
  v206 = v2;
  if ( !v2 )
    sub_96761C();
  v199 = 0;
  InitializationPhase = 1;
  KeSetPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, 31);
  KePerformGroupConfiguration();
  if ( !HalInitSystem(InitializationPhase, v1) )
    KeBugCheck(97);
  KeInitializeClock(InitializationPhase, v1);
  v3 = *(char **)(v1 + 120);
  if ( v3 )
    v4 = strupr(v3);
  else
    v4 = 0;
  v196 = v4;
  if ( !v4 || !strstr(v4, "NOGUIBOOT") )
  {
    byte_637608 = 0;
    v5 = BgkDisplayProgressIndicator();
    BgkDisplayBackgroundUpdate(v5);
    dword_637604 = (int (__fastcall *)(_DWORD))DisplayFilter;
    InbvDriverInitialize(1, v1, 7);
    DisplayBootBitmap(0);
  }
  if ( v4 && strstr(v4, "MININT") )
  {
    InitIsWinPEMode = 1;
    if ( strstr(v4, "INRAM") )
      v86 = InitWinPEModeType | 0x80000000;
    else
      v86 = InitWinPEModeType | 1;
    InitWinPEModeType = v86;
  }
  v6 = RtlFindMessage(0x400000, 11, 0, 0x4000007Eu, &v193);
  v7 = v2;
  v189 = v2;
  v191 = 256;
  if ( (_WORD)CmCSDVersionString )
  {
    v87 = RtlStringCbPrintfExA(v2, 0xFFu, &v189, &v191, 0, ": %wZ");
    if ( v87 < 0 )
      KeBugCheckEx(50, v87, 7, 0, 0);
    v7 = v189;
    v8 = v191;
  }
  else
  {
    v8 = 255;
    v191 = 255;
  }
  *(_BYTE *)v7 = 0;
  v9 = (int)v7 + 1;
  v189 = (void **)v9;
  v10 = RtlStringCbPrintfA((int)v220, 0x18u, (int)"%u.%u", 10);
  if ( v10 < 0 )
    KeBugCheckEx(50, v10, 7, 1, 0);
  if ( v6 < 0 )
  {
    v88 = RtlStringCbCopyA(v9);
    if ( v88 < 0 )
      KeBugCheckEx(50, v88, 7, 3, 0);
  }
  else
  {
    v11 = RtlStringCbPrintfA(v9, v8, v193 + 4, (int)v220);
    if ( v11 < 0 )
      KeBugCheckEx(50, v11, 7, 2, 0);
  }
  InbvDisplayString();
  memmove((int)(v2 + 64), (int)v2, 0x100u);
  if ( !PoInitSystem(0, v1, v12) )
    KeBugCheck(160);
  if ( !ExpRealTimeIsUniversal )
  {
    v13 = ExpLastTimeZoneBias;
    if ( ExpLastTimeZoneBias == -1 )
    {
      v199 = 1;
      v13 = ExpAltTimeZoneBias;
      ExpLastTimeZoneBias = ExpAltTimeZoneBias;
    }
    v14 = 15 * v13;
    ExpTimeZoneBias = 4 * v14 * (__int64)(int)dword_989680;
    MEMORY[0xFFFF925C] = 0;
    __dmb(0xBu);
    MEMORY[0xFFFF9028] = (unsigned __int64)(4 * v14 * (__int64)(int)dword_989680) >> 32;
    v15 = ExpTimeZoneBias;
    __dmb(0xBu);
    MEMORY[0xFFFF9020] = v15;
    v16 = HIDWORD(ExpTimeZoneBias);
    __dmb(0xBu);
    MEMORY[0xFFFF9024] = v16;
  }
  GetBootSystemTime(*(_DWORD *)(v1 + 132), &v195);
  if ( v4 )
  {
    v17 = strstr(v4, "YEAR");
    if ( v17 )
    {
      v89 = strstr(v17, "=");
      if ( v89 )
      {
        v90 = atol((int)(v89 + 1));
        RtlTimeToTimeFields((int)&v195, v216, v91, v92);
        v216[0] = v90;
        RtlTimeFieldsToTime(v216, &v195);
      }
    }
  }
  if ( ExpRealTimeIsUniversal )
    v200 = v195;
  else
    ExSystemTimeToLocalTime(&v195, (int *)&v200);
  KeSetSystemTime((int)&v195, (int)v213, 4);
  PoNotifySystemTimeSet();
  RtlInitUnicodeString((unsigned int)v214, L"Kernel-RegisteredProcessors");
  if ( ZwQueryLicenseValue() < 0 || v212[1] != 4 || v210 != 4 )
    KeRegisteredProcessors = 1;
  if ( v4 )
  {
    v18 = strstr(v4, " BOOTPROC=");
    if ( v18 )
    {
      v93 = strstr(v18, "=");
      if ( v93 )
        KeBootprocSpecified = atol((int)(v93 + 1));
    }
    v19 = strstr(v4, " NUMPROC=");
    if ( v19 )
    {
      v94 = strstr(v19, "=");
      if ( v94 )
        KeNumprocSpecified = atol((int)(v94 + 1));
    }
    v20 = strstr(v4, " HYPERVISORNUMPROC=");
    if ( v20 )
    {
      v95 = strstr(v20, "=");
      if ( v95 )
        KeHypervisorNumprocSpecified = atol((int)(v95 + 1));
    }
    v21 = strstr(v4, " HYPERVISORROOTPROC=");
    if ( v21 )
    {
      v96 = strstr(v21, "=");
      if ( v96 )
        KeRootProcSpecified = atol((int)(v96 + 1));
    }
    v22 = strstr(v4, " HYPERVISORROOTPROCPERNODE=");
    if ( v22 )
    {
      v97 = strstr(v22, "=");
      if ( v97 )
        KeRootProcPerNodeSpecified = atol((int)(v97 + 1));
    }
    if ( strstr(v4, " MAXPROC") )
      KeMaximumProcessors = 32;
  }
  KeStartAllProcessors();
  KeSetAffinityProcess(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, &KeActiveProcessors);
  if ( RtlFindMessage(0x400000, 11, 0, 0x40000089u, &v192) < 0 )
    v23 = "MultiProcessor Kernel\r\n";
  else
    v23 = (const char *)(v192 + 1);
  if ( !HalAllProcessorsStarted() )
    KeBugCheck(97);
  RtlInitAnsiString((unsigned int)v205, (unsigned int)v23);
  if ( v205[0] >= 2u )
    v205[0] -= 2;
  if ( (unsigned int)KeNumberProcessors_0 > 1 )
    v85 = 1073741981;
  else
    v85 = 1073741960;
  v24 = RtlFindMessage(0x400000, 11, 0, v85, &v193);
  v25 = MmPhysicalMemoryBlock;
  v26 = 0;
  for ( i = *(_DWORD *)MmPhysicalMemoryBlock; i; --i )
  {
    v28 = *(_DWORD *)(v25 + 12);
    v25 += 8;
    v26 += v28;
  }
  if ( v24 < 0 )
    v29 = "%u System Processor [%u MB Memory] %Z\n";
  else
    v29 = (const char *)(v193 + 4);
  v30 = RtlStringCbPrintfA((int)v2, 0x100u, (int)v29, KeNumberProcessors_0);
  if ( v30 < 0 )
    KeBugCheckEx(50, v30, 7, 4, 0);
  InbvDisplayString();
  ExFreePoolWithTag((unsigned int)v2);
  v31 = ObInitSystem();
  if ( !v31 )
    KeBugCheck(98);
  if ( !ExInitSystem(v31, v32, v33) )
    KeBugCheckEx(50, -1073741823, 0, 1, 0);
  if ( !IoCreateObjectTypes() )
    KeBugCheckEx(50, -1073741823, 0, 4, 0);
  v34 = KeNumberProcessors_0;
  if ( !KeMaximumIncrement )
    __brkdiv0();
  if ( !KeNumberProcessors_0 )
    __brkdiv0();
  KiClockKeepAliveCycle = ((KeMaximumIncrement + 29999999) / (unsigned int)KeMaximumIncrement + KeNumberProcessors_0 - 1)
                        / KeNumberProcessors_0;
  v35 = KeDpcWatchdogPeriod;
  if ( KeDpcWatchdogPeriod )
  {
    if ( (unsigned int)KeDpcWatchdogPeriod < 0x7D0 )
    {
      v35 = 2000;
      KeDpcWatchdogPeriod = 2000;
    }
    if ( v35 > 0x3A980 )
    {
      v35 = 240000;
      KeDpcWatchdogPeriod = 240000;
    }
  }
  v36 = KiDPCTimeout;
  if ( KiDPCTimeout )
  {
    if ( (unsigned int)KiDPCTimeout < 0x14 )
    {
      v36 = 20;
      KiDPCTimeout = 20;
    }
    if ( v36 > 0x4E20 )
    {
      v36 = 20000;
      KiDPCTimeout = 20000;
    }
  }
  if ( ViVerifierEnabled )
  {
    v98 = KeVerifierDpcScalingFactor;
    if ( !KeVerifierDpcScalingFactor )
    {
      v98 = 1;
      KeVerifierDpcScalingFactor = 1;
    }
    if ( v98 > 0x64 )
    {
      v98 = 100;
      KeVerifierDpcScalingFactor = 100;
    }
    KeDpcWatchdogPeriod = v98 * v35;
    KiDPCTimeout = v98 * v36;
  }
  v37 = 0;
  v38 = (int *)&KiProcessorBlock;
  do
  {
    v39 = *v38;
    v192 = v38 + 1;
    v40 = KiInitializeProcessor(v39, v36);
    if ( KeThreadDpcEnable )
    {
      v40 = KiStartDpcThread(v39);
      if ( v40 < 0 )
        goto LABEL_238;
    }
    ++v37;
    v38 = v192;
  }
  while ( v37 < v34 );
  v42 = (unsigned __int16)KeNumberNodes;
  if ( (unsigned __int16)KeNumberNodes > 1u )
  {
    v40 = ExAllocatePoolWithTag(
            512,
            ((2 * (unsigned __int16)KeNumberNodes * (unsigned __int16)KeNumberNodes + 3) & 0xFFFFFFFC)
          + 8 * (unsigned __int16)KeNumberNodes * (unsigned __int16)KeNumberNodes,
            1666082123);
    v42 = (int)&KiNodeGraph;
    KiNodeGraph = v40;
    if ( v40 )
    {
      v36 = (unsigned __int16)KeNumberNodes;
      v99 = (int *)((v40 + 2 * v36 * v36 + 3) & 0xFFFFFFFC);
      KiActualNodeCost = (int)v99;
      v100 = 0;
      v191 = 0;
      v101 = (unsigned __int16)KeNumberNodes;
      if ( v36 * v36 )
      {
        v102 = (8 * (unsigned __int16)KeNumberNodes * (unsigned int)(unsigned __int16)KeNumberNodes - 5) >> 2;
        *v99 = -1;
        v99[1] = -1;
        v103 = v99 + 2;
        v104 = v99;
        if ( v102 )
        {
          v105 = &v103[v102];
          do
          {
            v106 = *v104++;
            *v103++ = v106;
          }
          while ( v103 != v105 );
        }
      }
      v42 = 0;
      v107 = 0;
      v201 = 0;
      v202 = 0;
      v203 = 0;
      v188 = 0;
      if ( v36 )
      {
        v108 = &KeNodeBlock;
        while ( 1 )
        {
          v110 = (int)*v108++;
          v109 = v110;
          v111 = *(unsigned __int16 *)(v110 + 266);
          v112 = *(unsigned __int16 *)(v110 + 268);
          v194[0] = (int)v108;
          if ( v111 == v112 )
          {
            v112 = *(_DWORD *)(v109 + 260);
            if ( v112 )
            {
              v189 = v107;
            }
            else
            {
              v113 = 0;
              v189 = 0;
              if ( v101 )
              {
                v114 = &KeNodeBlock;
                do
                {
                  v115 = (int)*v114++;
                  v109 = v115;
                  v112 = *(unsigned __int16 *)(v115 + 268);
                  if ( v112 == v111 )
                  {
                    v112 = *(_DWORD *)(v109 + 260);
                    if ( v112 )
                      break;
                  }
                  v113 = (void **)((char *)v113 + 1);
                }
                while ( (unsigned int)v113 < v101 );
                v107 = v188;
                v189 = v113;
              }
              if ( v113 == (void **)v101 )
                goto LABEL_187;
            }
            v116 = *(_WORD *)(v109 + 264);
            v117 = *(_DWORD *)(v109 + 260);
            LOWORD(v202) = v116;
            v201 = ((v117 - 1) ^ v117) & v117;
            if ( v100 )
            {
              v118 = 0;
            }
            else
            {
              v118 = v217;
              v191 = 1;
            }
            KeSetSystemGroupAffinityThread((int)&v201, v118);
            v36 = (unsigned __int16)KeNumberNodes;
            v119 = 0;
            if ( KeNumberNodes )
            {
              v120 = v189;
              do
              {
                v121 = MmAllocateNodePagesForMdlEx(0, 0, -1, -1, 0i64, 0x1000u, 0, v119, 7);
                v122 = v121;
                v209 = v121;
                if ( v121 )
                {
                  v123 = MmMapLockedPagesSpecifyCache(v121, 0, 0, 0, 0, 1073741856);
                  if ( v123 )
                  {
                    v192 = (int *)KfRaiseIrql(2);
                    v124 = (void **)ReadTimeStampCounter();
                    v207 = v125;
                    v189 = v124;
                    v126 = v123 + 4096;
                    while ( v123 < v126 )
                      v123 += 4;
                    LODWORD(v127) = ReadTimeStampCounter();
                    HIDWORD(v127) = v128;
                    KfLowerIrql(v192);
                    v129 = v127 - __PAIR64__(v207, (unsigned int)v189);
                    v122 = v209;
                    *(_QWORD *)(KiActualNodeCost + 8 * (v119 + (unsigned __int16)KeNumberNodes * (_DWORD)v120)) = v129;
                  }
                  MiFreePagesFromMdl(MiSystemPartition, v122, 0);
                  ExFreePoolWithTag(v122);
                }
                v36 = (unsigned __int16)KeNumberNodes;
                ++v119;
              }
              while ( v119 < (unsigned __int16)KeNumberNodes );
              v107 = v188;
              v108 = (void **)v194[0];
            }
            v100 = v191;
          }
LABEL_187:
          v107 = (void **)((char *)v107 + 1);
          v188 = v107;
          v101 = v36;
          if ( (unsigned int)v107 >= v36 )
          {
            v4 = v196;
            v1 = v190;
            if ( v100 == 1 )
            {
              KeRevertToUserGroupAffinityThread((int)v217, v36, v109, v112);
              v36 = (unsigned __int16)KeNumberNodes;
            }
            v42 = (int)&KiActualNodeCost;
            v99 = (int *)KiActualNodeCost;
            break;
          }
        }
      }
      v41 = 0;
      v188 = 0;
      v40 = v36;
      if ( v36 )
      {
        v130 = &KeNodeBlock;
        do
        {
          v131 = *((unsigned __int16 *)*v130 + 133);
          v42 = *((unsigned __int16 *)*v130 + 134);
          if ( v131 == v42 )
          {
            v132 = v131 * v40;
            v133 = 0;
            if ( v40 )
            {
              v134 = &KeNodeBlock;
              do
              {
                v135 = (int)*v134++;
                v136 = *(unsigned __int16 *)(v135 + 266);
                v42 = *(unsigned __int16 *)(v135 + 268);
                v194[0] = v136;
                if ( v136 == v42 )
                {
                  v137 = &v99[2 * v136 + 2 * v132];
                  v42 = v137[1] & *v137;
                  if ( v42 == -1 )
                  {
                    v138 = &v99[2 * *((unsigned __int16 *)*v130 + 133) + 2 * v194[0] * v40];
                    *v137 = *v138;
                    v42 = v138[1];
                    v137[1] = v42;
                    v36 = (unsigned __int16)KeNumberNodes;
                    v99 = (int *)KiActualNodeCost;
                  }
                }
                ++v133;
                v40 = v36;
              }
              while ( v133 < v36 );
              v41 = v188;
            }
          }
          v41 = (void **)((char *)v41 + 1);
          ++v130;
          v188 = v41;
          v40 = v36;
        }
        while ( (unsigned int)v41 < v36 );
        v4 = v196;
        v1 = v190;
      }
      v139 = 0;
      v188 = 0;
      if ( v36 )
      {
        v41 = &KeNodeBlock;
        v140 = v219;
        v189 = &KeNodeBlock;
        while ( 1 )
        {
          v141 = 0;
          v142 = *((unsigned __int16 *)*v41 + 134);
          v194[0] = v142;
          if ( v36 )
          {
            v143 = &KeNodeBlock;
            v144 = v219;
            v145 = v142;
            do
            {
              v147 = (int)*v143++;
              v146 = v147;
              *(_DWORD *)v144 = v141;
              if ( v147 )
              {
                v148 = &v99[2 * *(unsigned __int16 *)(v146 + 266) + 2 * v145 * v36];
                *((_DWORD *)v144 + 2) = *v148;
                HIDWORD(v149) = v148[1];
                LODWORD(v149) = *((_DWORD *)v144 + 2);
                *((_DWORD *)v144 + 3) = HIDWORD(v149);
                if ( !v149 )
                {
                  *((_DWORD *)v144 + 2) = 1;
                  *((_DWORD *)v144 + 3) = 0;
                }
              }
              else
              {
                *((_DWORD *)v144 + 2) = -1;
                *((_DWORD *)v144 + 3) = -1;
              }
              ++v141;
              v144 += 16;
            }
            while ( v141 < v36 );
            v139 = (unsigned int)v188;
          }
          *((_DWORD *)v140 + 2) = 0;
          *((_DWORD *)v140 + 3) = 0;
          qsort((unsigned int)v219, v36, 0x10u, (int (__fastcall *)(unsigned int, _BYTE *))MiNodeCostSort);
          v42 = (unsigned __int16)KeNumberNodes;
          v40 = 0;
          if ( KeNumberNodes )
          {
            v150 = v219;
            do
            {
              v151 = *(_DWORD *)v150;
              v150 += 16;
              v152 = v40 + v42 * v139;
              ++v40;
              *(_WORD *)(KiNodeGraph + 2 * v152) = v151;
              v42 = (unsigned __int16)KeNumberNodes;
            }
            while ( v40 < (unsigned int)(unsigned __int16)KeNumberNodes );
          }
          ++v139;
          v140 += 16;
          v41 = v189 + 1;
          v188 = (void **)v139;
          ++v189;
          v36 = v42;
          if ( v139 >= v42 )
            break;
          v99 = (int *)KiActualNodeCost;
        }
        v4 = v196;
        v1 = v190;
      }
    }
  }
  KiIntSteerInit(v40, v36, (int)v41, v42);
  KiSetSystemAffinityThreadToProcessor(0, (int)v218, v153, v154);
  v155 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x7C);
  v190 = v155;
  v156 = __mrc(15, 0, 0, 0, 0);
  v157 = v156 & 0xFFF0;
  v158 = 49296;
  if ( v157 == 49296 )
  {
    v158 = v156 & 0xFF000000;
    if ( (v156 & 0xFF000000) == 1090519040 )
    {
      if ( v155 )
      {
        v159 = 2 * v155;
        v160 = ExAllocatePoolWithTag(512, 2 * v155, 1095912265);
        v161 = v160;
        v194[0] = v160;
        if ( v160 )
        {
          v189 = (void **)(v160 & 0xFFF);
          v162 = 4 * ((((unsigned int)v189 + v159 + 4095) >> 12) + 7);
          v188 = (void **)v162;
          v163 = ExAllocatePoolWithTag(512, v162, 1667525965);
          if ( v163 )
          {
            v164 = ExAllocatePoolWithTag(512, v162, 1668050253);
            if ( v164 )
            {
              v165 = (__int16)v188;
              *(_DWORD *)v163 = 0;
              *(_WORD *)(v163 + 4) = v165;
              v166 = v189;
              *(_WORD *)(v163 + 6) = 0;
              v167 = v190;
              *(_DWORD *)(v163 + 24) = v166;
              v168 = v161 & 0xFFFFF000;
              *(_DWORD *)(v163 + 16) = v168;
              *(_DWORD *)(v163 + 20) = 2 * v167;
              MmBuildMdlForNonPagedPool(v163);
              v169 = (__int16)v188;
              *(_DWORD *)v164 = 0;
              *(_WORD *)(v164 + 4) = v169;
              v170 = v189;
              *(_WORD *)(v164 + 6) = 0;
              v171 = v190;
              *(_DWORD *)(v164 + 24) = v170;
              *(_DWORD *)(v164 + 16) = v168;
              v172 = 2 * v171;
              v173 = (_BYTE *)v194[0];
              *(_DWORD *)(v164 + 20) = v172;
              KiCacheInterpolateFlushThreshold(v163, v164, v173, v172, 1u);
            }
            ExFreePoolWithTag(v163);
          }
          ExFreePoolWithTag(v161);
        }
      }
    }
  }
  KeRevertToUserGroupAffinityThread((int)v218, v156, v157, v158);
  v174 = __mrc(15, 0, 0, 0, 0);
  v175 = (unsigned __int16)v174 >> 4;
  if ( v175 == 3081 && (v174 & 0xFF000000) == 1090519040
    || v175 == 77 && (v174 & 0xFF000000) == 1358954496 && (v174 & 0xF00000) == 0x100000
    || v175 == 111 && (v174 & 0xFF000000) == 1358954496 && (v174 & 0xF00000) == 0 )
  {
    KiA9ErrataProfileObject = ExAllocatePoolWithTag(512, 52, 538993995);
    if ( !KiA9ErrataProfileObject
      || (v176 = _rt_udiv64(10i64, *(_QWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x948)),
          v194[1] = v177,
          v178 = (int *)v176,
          KeInitializeProfileCallback(KiA9ErrataProfileObject, (unsigned int)PopPoCoalescinCallback, 0, 19),
          KeSetIntervalProfile(v178, 19),
          !KeStartProfile(KiA9ErrataProfileObject)) )
    {
LABEL_238:
      KeBugCheckEx(50, -1073741823, 0, 2, 0);
    }
  }
  if ( off_617B54(41, 4, &v211, v215) >= 0 && (v211 & 1) != 0 )
  {
    KiTbIpiTypeToSendForBroadcast = 3;
    KiTbSendIpiForBroadcastFlushes = 1;
  }
  LODWORD(v179) = _rt_udiv64(1000000i64, *((_QWORD *)KiProcessorBlock + 121));
  LODWORD(v180) = _rt_udiv64(10i64, v179 * (unsigned int)KeMaximumIncrement);
  v181 = HIDWORD(v180);
  v182 = v180;
  KiShortExecutionCycles = _rt_udiv64(240i64, v180);
  KiCyclesPerClockQuantum = _rt_udiv64(3i64, __PAIR64__(v181, v182));
  KiLockQuantumTarget = 3 * KiCyclesPerClockQuantum;
  KiDirectQuantumTarget = KiCyclesPerClockQuantum;
  if ( KdpBootedNodebug )
  {
    v43 = &KdDebuggerDataBlock;
    v183 = KiWaitNever;
    v184 = KiWaitAlways;
    KdpDataBlockEncoded = 1;
    v44 = 216;
    do
    {
      *v43 = __ROR4__(bswap32(*v43 ^ v184) ^ (unsigned int)&KdpDataBlockEncoded, v183) ^ v183;
      ++v43;
      --v44;
    }
    while ( v44 );
  }
  v45 = KeExpandKernelStackAndCalloutEx((int)KiVerifyScopesExecute, 0, 49152, 1, 0);
  if ( v45 < 0 )
    KeBugCheckEx(50, v45, 1398171979, 0, 0);
  if ( !KdInitSystem(InitializationPhase, 0) )
    KeBugCheckEx(50, -1073741823, 0, 3, 0);
  v46 = TmInitSystem();
  if ( v46 != -1073741637 && v46 < 0 )
    KeBugCheckEx(50, 0, 0, 0, 0);
  v48 = DbgkInitialize(v46, v47);
  if ( v48 < 0 )
    KeBugCheckEx(50, v48, 0, 0, 0);
  BcdInitializeBcdSyncMutant();
  v49 = VerifierInitSystem(0);
  if ( !SeInitSystem(v49, v50) )
    KeBugCheck(99);
  v51 = PspInitializeNetRateControl();
  ExInitLicenseCallback(v51);
  v52 = CreateSystemRootLink(v1);
  if ( v52 < 0 )
    KeBugCheckEx(100, v52, 0, 0, 0);
  if ( !MmInitSystem(1, v1) )
    KeBugCheck(101);
  InitMultiSessionSku();
  v212[2] = InitNlsTableSize;
  v212[3] = 0;
  v53 = ZwCreateSection();
  if ( v53 < 0 )
    KeBugCheckEx(50, v53, 1, 0, 0);
  v54 = ObReferenceObjectByHandle(v197, 983071, MmSectionObjectType, 0, (int)&v204, 0);
  InitNlsSectionPointer = v204;
  ZwClose();
  if ( v54 < 0 )
    KeBugCheckEx(50, v54, 2, 0, 0);
  v188 = 0;
  v194[0] = 0;
  v55 = MmMapViewInSystemSpace(InitNlsSectionPointer, (int)&v188, (int)v194);
  if ( v55 < 0 )
    KeBugCheckEx(50, v55, 3, 0, 0);
  v56 = (int)v188;
  memmove((int)v188, InitNlsTableBase, InitNlsTableSize);
  InitNlsTableBase = v56;
  v57 = RtlInitNlsTables(
          v56 + InitAnsiCodePageDataOffset,
          v56 + InitOemCodePageDataOffset,
          v56 + InitUnicodeCaseTableDataOffset);
  RtlResetRtlTranslations(v57, v58);
  if ( !CcInitializeCacheManager() )
    KeBugCheck(102);
  if ( !CmInitSystem1(v1) )
    KeBugCheck(103);
  v59 = KsrInitSystem_0();
  if ( v59 != -1073741637 && v59 < 0 )
    KeBugCheckEx(50, v59, 0, 1, 0);
  v60 = EmInitSystem(0, v1);
  if ( v60 < 0 )
    KeBugCheckEx(50, v60, 8, 0, 0);
  v61 = MfgInitSystem(v1);
  if ( v61 < 0 )
    KeBugCheckEx(50, v61, 9, 0, 0);
  PfInitializeSuperfetch();
  SmInitSystem(0);
  if ( (*(_DWORD *)(*(_DWORD *)(v1 + 132) + 2168) & 2) == 0 || strstr(v4, "FORCETIMESYNC") )
    ZwUpdateWnfStateData();
  v208 = 0;
  FsRtlSendModernAppTermination((int)&v208, 1u, 1);
  ExInitializeUtcTimeZoneBias(&v200);
  v62 = ExpLastTimeZoneBias;
  v63 = ExpRefreshTimeZoneInformation();
  if ( v199 )
  {
    ExLocalTimeToSystemTime(&v200, &v195);
    v63 = KeSetSystemTime((int)&v195, (int)v213, 4);
  }
  else if ( v62 != ExpLastTimeZoneBias )
  {
    v63 = ZwSetSystemTime();
  }
  if ( !FsRtlInitSystem(v63, v64, v65) )
    KeBugCheck(104);
  v66 = RtlInitializeCompression();
  RtlInitializeRangeListPackage(v66, HIDWORD(v66));
  HalReportResourceUsage(0);
  v67 = KdInitialize_0();
  v69 = PpInitSystem(v67, v68);
  if ( !v69 )
    KeBugCheck(144);
  if ( !LpcInitSystem(v69, v70, v71) )
    KeBugCheck(106);
  if ( v4 )
    v74 = strstr(v4, "SAFEBOOT:");
  else
    v74 = 0;
  if ( v74 )
  {
    v185 = v74 + 9;
    if ( !strncmp(v185, "MINIMAL", 7u) )
    {
      v186 = 1;
    }
    else
    {
      if ( strncmp(v185, "NETWORK", 7u) )
      {
        if ( !strncmp(v185, "DSREPAIR", 8u) )
        {
          v186 = 3;
          v185 += 8;
        }
        else
        {
          v186 = 0;
        }
        goto LABEL_274;
      }
      v186 = 2;
    }
    v185 += 7;
LABEL_274:
    InitSafeBootMode = v186;
    if ( *v185 && !strncmp(v185, "(ALTERNATESHELL)", 0x10u) )
      v198 = 1;
    if ( v186 )
    {
      if ( v186 == 1 )
        v187 = 168;
      else
        v187 = v186 == 2 ? 169 : 170;
      if ( RtlFindMessage(0x400000, 11, 0, v187, v212) >= 0 )
        InbvDisplayString();
    }
  }
  if ( v4 )
    v75 = strstr(v4, "BOOTLOG");
  else
    v75 = 0;
  if ( v75 )
  {
    if ( RtlFindMessage(0x400000, 11, 0, 0xB7u, &v193) >= 0 )
      InbvDisplayString();
    v75 = IopInitializeBootLogging((_BYTE *)v1, (int)(v206 + 64));
  }
  ExInitSystemPhase2(v75, v72, v73);
  v76 = SeCodeIntegrityInitializePolicy(v1);
  if ( v76 < 0 )
    KeBugCheckEx(50, v76, 1766024531, 0, 0);
  v78 = 0;
  KdpTimeSlipPending = 0;
  if ( InitIsWinPEMode )
    v76 = CreateMiniNtBootKey(v76, v77, 0);
  v79 = ExInitializeNls(v76, v77, v78);
  if ( v79 < 0 )
    KeBugCheckEx(50, v79, 7, 0, 0);
  v82 = ExInitializeExternalBootSupport(v79, v80, v81);
  if ( v82 < 0 )
    KeBugCheckEx(50, v82, 8, 0, 0);
  if ( !PoInitSystem(1, v1, v83) )
    KeBugCheck(160);
  return v198;
}
