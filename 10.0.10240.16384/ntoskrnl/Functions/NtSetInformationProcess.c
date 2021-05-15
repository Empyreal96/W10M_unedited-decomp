// NtSetInformationProcess 
 
int __fastcall NtSetInformationProcess(int a1, int a2, int a3, unsigned int a4)
{
  int *v5; // r6
  int v7; // lr
  unsigned int v8; // r5
  int v9; // r3
  unsigned int v10; // r2
  int v11; // r8
  int v12; // r6
  _DWORD *v13; // r0
  unsigned int v14; // r5
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r6
  unsigned int *v19; // r2
  unsigned int v20; // r0
  unsigned int v21; // r4
  int v22; // r5
  char v23; // r9
  int v24; // r8
  int v25; // r2
  int v26; // r3
  int v27; // r2
  int v28; // r5
  int v29; // r2
  int v30; // r3
  _DWORD *v31; // r10
  unsigned int *v32; // r6
  unsigned int v33; // r0
  unsigned int v34; // r1
  int v35; // r0
  int v36; // r6
  int v37; // r9
  unsigned int *v38; // r6
  unsigned int v39; // r4
  unsigned int v40; // r1
  int v41; // r0
  int v42; // r4
  int v43; // r0
  int v44; // lr
  unsigned int v45; // r1
  int v46; // r4
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned int *v49; // r0
  int v50; // r3
  int v51; // r6
  int v52; // r8
  __int16 v53; // r3
  int v54; // r6
  unsigned __int8 *v55; // r9
  int v56; // r0
  int v57; // r8
  unsigned int v58; // r2
  unsigned int v59; // r1
  int v60; // r3
  unsigned int v61; // r3
  unsigned int v62; // r1
  int v63; // r0
  __int16 v64; // r3
  int v65; // r4
  unsigned int *v66; // r2
  unsigned int v67; // r0
  unsigned int v68; // r4
  int v69; // r2
  int v70; // r3
  int v71; // r0
  int v72; // r2
  int v73; // r2
  unsigned int *v74; // r9
  unsigned int v75; // r0
  unsigned int v76; // r1
  int v77; // r0
  unsigned int *v78; // r4
  int v79; // r0
  int v80; // r8
  unsigned int v81; // r2
  unsigned int v82; // r2
  unsigned int v83; // r4
  unsigned int v84; // r1
  unsigned int *v85; // r2
  __int16 v86; // r3
  unsigned int *v87; // r9
  unsigned int v88; // r0
  unsigned int v89; // r1
  unsigned __int8 *v90; // r10
  int v91; // r1
  unsigned int v92; // r2
  unsigned int v93; // r9
  _DWORD *v94; // r6
  _DWORD *v95; // r4
  unsigned int v96; // r1
  int v97; // r5
  _DWORD *v98; // r9
  int v99; // r0
  __int16 v100; // r3
  unsigned int v101; // r4
  unsigned int v102; // r1
  char v103; // r1
  unsigned int *v104; // r2
  unsigned int v105; // r0
  unsigned int v106; // r0
  int v107; // r5
  int v108; // r5
  int v109; // r5
  int v110; // r4
  unsigned int *v111; // r2
  unsigned int v112; // r0
  unsigned int v113; // r4
  int v114; // r2
  int v115; // r5
  int *v116; // r1
  unsigned int v117; // r2
  int v118; // r3
  _DWORD *v119; // r9
  unsigned int *v120; // lr
  unsigned int v121; // r3
  unsigned int v122; // r0
  int v123; // r10
  unsigned __int8 *v124; // r0
  unsigned int v125; // r2
  unsigned int *v126; // r9
  unsigned int v127; // lr
  unsigned int v128; // t1
  int v129; // r10
  unsigned int v130; // r0
  unsigned int v131; // r1
  _DWORD *v132; // r9
  _DWORD *v133; // r6
  unsigned int v134; // r8
  int v135; // r0
  unsigned int *v136; // lr
  unsigned int v137; // r0
  unsigned int v138; // r1
  int v139; // r1
  unsigned int *v140; // r9
  unsigned int v141; // r1
  int v142; // r5
  int v143; // r0
  __int16 v144; // r3
  unsigned int *v145; // r0
  unsigned int v146; // r4
  unsigned int v147; // r1
  int v148; // r3
  unsigned int v149; // r0
  unsigned int v150; // r3
  unsigned int v151; // r0
  int v152; // r1
  int v153; // r2
  unsigned int v154; // r3
  unsigned int *v155; // lr
  unsigned int v156; // r3
  unsigned int v157; // r0
  int v158; // r10
  unsigned __int8 *v159; // r0
  unsigned int v160; // r2
  unsigned int *v161; // lr
  unsigned int v162; // r6
  int v163; // r4
  unsigned int v164; // r0
  unsigned int v165; // r1
  _DWORD *v166; // r6
  _DWORD *v167; // r9
  int v168; // r5
  unsigned int v169; // r4
  unsigned int *v170; // r10
  unsigned int v171; // lr
  unsigned int v172; // r1
  unsigned int *v173; // r6
  unsigned int v174; // r1
  int v175; // r0
  __int16 v176; // r3
  unsigned int *v177; // r0
  unsigned int v178; // r4
  unsigned int v179; // r1
  _DWORD *v180; // r10
  unsigned int v181; // r0
  unsigned int v182; // r2
  int v183; // r2
  int v184; // lr
  unsigned int v185; // r9
  _DWORD *v186; // r1
  int i; // r0
  int v188; // r0
  _DWORD *v189; // r5
  unsigned int v190; // r2
  unsigned int v191; // r1
  unsigned int *v192; // r0
  unsigned int v193; // r4
  unsigned int v194; // r1
  int v195; // r9
  int v196; // r10
  int v197; // r1
  int v198; // r4
  int v199; // r2
  int v200; // r4
  int v201; // r4
  int v202; // lr
  int *v203; // r0
  int *v204; // r3
  int v205; // r4
  _DWORD *v206; // r2
  int *v207; // r2
  unsigned int *v208; // r0
  unsigned int v209; // r4
  int v210; // r1
  int v211; // r2
  int v212; // r3
  int v213; // r2
  int v214; // r8
  int v215; // r0
  unsigned int *v216; // r10
  unsigned int v217; // r0
  unsigned int v218; // r1
  int v219; // r1
  unsigned __int8 *v220; // r0
  unsigned int v221; // r2
  int v222; // r10
  _DWORD *j; // lr
  unsigned __int8 *v224; // r3
  unsigned int v225; // r2
  unsigned __int8 *v226; // r3
  unsigned int v227; // r2
  unsigned int v228; // r1
  int v229; // r5
  int v230; // r0
  __int16 v231; // r3
  unsigned int v232; // r4
  unsigned int v233; // r1
  _DWORD *v234; // r4
  int v235; // r1
  int v236; // r2
  int v237; // r3
  int v238; // r2
  int v239; // r3
  int v240; // r6
  bool v241; // zf
  unsigned int *v242; // r2
  unsigned int v243; // r0
  unsigned int v244; // r4
  int v245; // r4
  int v246; // r2
  unsigned int v247; // r9
  int v248; // r2
  int v249; // r4
  unsigned int *v250; // r2
  unsigned int v251; // r0
  unsigned int *v252; // r2
  unsigned int v253; // r0
  unsigned int *v254; // r2
  unsigned int v255; // r0
  int v256; // r3
  int v257; // r0
  unsigned int *v258; // r2
  unsigned int v259; // r0
  int v260; // r3
  unsigned int *v261; // r2
  unsigned int v262; // r0
  unsigned int *v263; // r2
  unsigned int v264; // r0
  unsigned int *v265; // r2
  unsigned int v266; // r0
  unsigned int *v267; // r0
  unsigned int v268; // r1
  unsigned int v269; // r1
  unsigned int *v270; // r0
  unsigned int v271; // r1
  unsigned int v272; // r1
  _DWORD *v273; // r0
  int v274; // r3
  int v275; // r6
  int v276; // r0
  unsigned int v277; // r5
  unsigned int v278; // r3
  int v279; // r1
  int v280; // r0
  BOOL v281; // r6
  int v282; // r5
  int v283; // r2
  int v284; // r3
  int v285; // r5
  unsigned int *v286; // r2
  unsigned int v287; // r4
  int v288; // r0
  unsigned int *v289; // r2
  unsigned int v290; // r4
  int v291; // r5
  int v292; // r0
  int v293; // r6
  int v294; // r4
  unsigned __int8 *v295; // r9
  int v296; // r0
  int v297; // r8
  unsigned int v298; // r2
  unsigned int v299; // r1
  int v300; // r0
  __int16 v301; // r3
  char v303; // [sp+10h] [bp-1D0h]
  int v304; // [sp+14h] [bp-1CCh] BYREF
  _DWORD *v305; // [sp+18h] [bp-1C8h]
  int v306; // [sp+1Ch] [bp-1C4h]
  unsigned int v307; // [sp+20h] [bp-1C0h]
  unsigned int v308; // [sp+24h] [bp-1BCh]
  int v309; // [sp+28h] [bp-1B8h]
  int *v310; // [sp+2Ch] [bp-1B4h]
  int v311; // [sp+30h] [bp-1B0h]
  int v312; // [sp+34h] [bp-1ACh]
  int v313; // [sp+38h] [bp-1A8h]
  int v314; // [sp+3Ch] [bp-1A4h] BYREF
  int v315; // [sp+40h] [bp-1A0h] BYREF
  int v316; // [sp+44h] [bp-19Ch]
  int v317; // [sp+48h] [bp-198h]
  _DWORD *v318; // [sp+4Ch] [bp-194h]
  unsigned int v319; // [sp+50h] [bp-190h]
  char v320; // [sp+54h] [bp-18Ch]
  char v321; // [sp+55h] [bp-18Bh]
  char v322; // [sp+56h] [bp-18Ah]
  unsigned int v323; // [sp+58h] [bp-188h]
  int v324; // [sp+5Ch] [bp-184h]
  int *v325; // [sp+60h] [bp-180h]
  int v326; // [sp+68h] [bp-178h] BYREF
  int v327; // [sp+6Ch] [bp-174h]
  int v328; // [sp+70h] [bp-170h]
  int v329; // [sp+74h] [bp-16Ch]
  int v330; // [sp+78h] [bp-168h]
  int v331; // [sp+80h] [bp-160h] BYREF
  int v332; // [sp+84h] [bp-15Ch]
  int v333; // [sp+88h] [bp-158h]
  int v334; // [sp+90h] [bp-150h]
  int v335; // [sp+94h] [bp-14Ch]
  int v336; // [sp+98h] [bp-148h]
  int v337; // [sp+9Ch] [bp-144h]
  int v338; // [sp+A0h] [bp-140h] BYREF
  int v339; // [sp+A4h] [bp-13Ch]
  int v340; // [sp+A8h] [bp-138h]
  unsigned int v341; // [sp+ACh] [bp-134h]
  int v342; // [sp+B0h] [bp-130h]
  int v343; // [sp+B4h] [bp-12Ch]
  int v344; // [sp+B8h] [bp-128h]
  unsigned int v345; // [sp+C0h] [bp-120h]
  int v346; // [sp+C4h] [bp-11Ch]
  int v347; // [sp+C8h] [bp-118h]
  int v348; // [sp+D0h] [bp-110h]
  unsigned int v349; // [sp+D4h] [bp-10Ch]
  int v350; // [sp+D8h] [bp-108h]
  _DWORD *v351; // [sp+E0h] [bp-100h]
  int v352; // [sp+E4h] [bp-FCh]
  int v353; // [sp+E8h] [bp-F8h]
  int v354; // [sp+ECh] [bp-F4h]
  int v355; // [sp+F0h] [bp-F0h]
  int v356; // [sp+F4h] [bp-ECh]
  int v357; // [sp+F8h] [bp-E8h]
  int v358; // [sp+FCh] [bp-E4h]
  BOOL v359; // [sp+100h] [bp-E0h]
  int v360; // [sp+104h] [bp-DCh]
  int v361; // [sp+108h] [bp-D8h] BYREF
  unsigned int v362; // [sp+10Ch] [bp-D4h]
  int v363; // [sp+110h] [bp-D0h]
  _DWORD v364[2]; // [sp+118h] [bp-C8h] BYREF
  int v365; // [sp+120h] [bp-C0h]
  int v366; // [sp+124h] [bp-BCh]
  int v367; // [sp+128h] [bp-B8h]
  int v368; // [sp+12Ch] [bp-B4h]
  _DWORD v369[2]; // [sp+130h] [bp-B0h] BYREF
  _WORD v370[12]; // [sp+138h] [bp-A8h] BYREF
  int v371; // [sp+150h] [bp-90h]
  _DWORD v372[4]; // [sp+158h] [bp-88h] BYREF
  int v373; // [sp+168h] [bp-78h] BYREF
  int v374; // [sp+16Ch] [bp-74h]
  int v375; // [sp+170h] [bp-70h]
  int v376; // [sp+178h] [bp-68h]
  int v377; // [sp+17Ch] [bp-64h]
  int v378; // [sp+180h] [bp-60h]
  _BYTE v379[24]; // [sp+188h] [bp-58h] BYREF
  _DWORD _1A0[22]; // [sp+1A0h] [bp-40h] BYREF

  _1A0[18] = a1;
  _1A0[20] = a3;
  _1A0[21] = a4;
  v5 = (int *)a3;
  _1A0[19] = a2;
  v7 = a1;
  v306 = a1;
  v305 = (_DWORD *)a1;
  v310 = (int *)a3;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v311 = v8;
  v308 = v8;
  v303 = *(_BYTE *)(v8 + 0x15A);
  if ( !v303 )
    goto LABEL_32;
  switch ( a2 )
  {
    case 5:
      goto LABEL_25;
    case 17:
      v9 = 1;
      goto LABEL_26;
    case 25:
      v9 = 1;
      goto LABEL_26;
    case 18:
      v9 = 1;
      goto LABEL_26;
  }
  if ( a2 == 21
    || a2 == 33
    || a2 == 39
    || a2 == 35
    || a2 == 8
    || a2 == 40
    || a2 == 41
    || a2 == 45
    || a2 == 46
    || a2 == 49
    || a2 == 53
    || a2 == 56
    || a2 == 62
    || a2 == 65
    || a2 != 70 )
  {
LABEL_25:
    v9 = 4;
  }
  else
  {
    v9 = 1;
  }
LABEL_26:
  if ( a4 )
  {
    if ( ((v9 - 1) & a3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    v10 = a3 + a4;
    if ( (unsigned int)v5 + a4 > MmUserProbeAddress || v10 < (unsigned int)v5 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
LABEL_32:
  if ( a2 != 12 )
  {
    switch ( a2 )
    {
      case 1:
        return PspSetQuotaLimits(a1, (int)v5, a4, v303);
      case 5:
        if ( a4 != 4 )
          return -1073741820;
        v363 = *v5;
        v22 = v363;
        if ( v363 >= 0 )
        {
          v23 = 0;
        }
        else
        {
          v23 = 2;
          v22 = v363 & 0x7FFFFFFF;
        }
        if ( (unsigned int)(v22 - 1) > 0x1E )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v24 = v304;
        if ( v22 > *(char *)(v304 + 104)
          && !SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, v306, 512, v303) )
        {
          ObfDereferenceObjectWithTag(v24);
          return -1073741727;
        }
        KeSetPriorityAndQuantumProcess(v24, v22, 0, 0);
        MmSetMemoryPriorityProcess(v24, v23, v25, v26);
        ObfDereferenceObjectWithTag(v24);
        return 0;
      case 6:
        if ( a4 != 4 )
          return -1073741820;
        v307 = *v5;
        v341 = v307;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v31 = (_DWORD *)v304;
        v32 = (unsigned int *)(v304 + 172);
        __pld((void *)(v304 + 172));
        v33 = *v32 & 0xFFFFFFFE;
        do
          v34 = __ldrex(v32);
        while ( v34 == v33 && __strex(v33 + 2, v32) );
        __dmb(0xBu);
        if ( v34 == v33 || ExfAcquireRundownProtection(v31 + 43) )
        {
          v35 = PsGetNextProcessThread(v31, 0);
          v36 = v307;
          while ( 1 )
          {
            v37 = v35;
            if ( !v35 )
              break;
            KeBoostPriorityThread(v35, v36);
            v35 = PsGetNextProcessThread(v31, v37);
          }
          v38 = v31 + 43;
          __pld(v31 + 43);
          v39 = v31[43] & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v40 = __ldrex(v38);
          while ( v40 == v39 && __strex(v39 - 2, v38) );
          if ( v40 != v39 )
            ExfReleaseRundownProtection((unsigned __int8 *)v31 + 172);
        }
        else
        {
          v11 = -1073741558;
        }
        goto LABEL_91;
      case 8:
        if ( a4 == 4 )
        {
          v314 = 0;
          v333 = 0;
          v313 = *v5;
          v330 = v313;
          v42 = v306;
        }
        else
        {
          if ( a4 != 8 )
            return -1073741820;
          v313 = *v5;
          v330 = v313;
          v314 = v5[1];
          v333 = v314;
          v42 = v306;
          if ( (v314 & 0xFFFFFFF8) != 0 )
            return -1073741811;
        }
        if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v303, (int)&SeDebugPrivilege) )
          return -1073741727;
        v11 = ObReferenceObjectByHandle(v313, 0, LpcPortObjectType, v303, &v315);
        v317 = v315;
        if ( v11 >= 0 )
        {
          v11 = ObReferenceObjectByHandleWithTag(v42, 2048, PsProcessType, v303, 2035381072, &v304, 0);
          v43 = v315;
          if ( v11 >= 0 )
          {
            v44 = v315 | v314;
            v311 = v315 | v314;
            v45 = *(_DWORD *)(v304 + 240);
            v307 = v45;
            __dmb(0xBu);
            v46 = v304;
            while ( 1 )
            {
              if ( a4 == 8 )
              {
                v5[1] = v45 & 7;
              }
              else if ( (v45 & 7) != 0 )
              {
                ObfDereferenceObject(v317);
                v11 = -1073741811;
LABEL_127:
                ObfDereferenceObjectWithTag(v46);
                return v11;
              }
              __dmb(0xBu);
              v47 = (unsigned int *)(v46 + 240);
              do
                v48 = __ldrex(v47);
              while ( v48 == v45 && __strex(v44, v47) );
              v307 = v48;
              __dmb(0xBu);
              if ( v48 == v45 )
              {
                if ( v48 )
                {
                  v370[1] = 32;
                  v370[0] = 8;
                  v370[2] = 13;
                  v370[3] = 0;
                  v371 = *(_DWORD *)(v46 + 176);
                  while ( 1 )
                  {
                    v49 = (unsigned int *)LpcRequestPort(v48 & 0xFFFFFFF8, (int)v370);
                    if ( v49 != (unsigned int *)-1073741801 && v49 != (unsigned int *)-1073741670 )
                      break;
                    KeDelayExecutionThread(0, 0, (unsigned int *)PspShortTime);
                    v48 = v307;
                  }
                  --*(_WORD *)(v8 + 308);
                  __dmb(0xFu);
                  v50 = *(_DWORD *)(v46 + 168);
                  __dmb(0xBu);
                  if ( (v50 & 1) != 0 )
                  {
                    v51 = v304;
                    v52 = KeAbPreAcquire(v304 + 168, 0, 0);
                    ExfAcquirePushLockExclusiveEx((_DWORD *)(v51 + 168), v52, v51 + 168);
                    if ( v52 )
                      *(_BYTE *)(v52 + 14) |= 1u;
                    v46 = v304;
                    v49 = ExfReleasePushLockExclusive((unsigned int *)(v304 + 168));
                    if ( v52 )
                      v49 = (unsigned int *)KeAbPostRelease(v46 + 168);
                  }
                  else
                  {
                    v46 = v304;
                  }
                  v53 = *(_WORD *)(v8 + 308) + 1;
                  *(_WORD *)(v8 + 308) = v53;
                  if ( !v53 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
                    KiCheckForKernelApcDelivery((int)v49);
                  ObfDereferenceObject(v307 & 0xFFFFFFF8);
                }
                v11 = 0;
                goto LABEL_127;
              }
              v45 = v48;
              v307 = v48;
            }
          }
LABEL_735:
          ObfDereferenceObject(v43);
        }
        return v11;
      case 9:
        if ( a4 != 8 )
          return -1073741820;
        v343 = *v5;
        return PspAssignPrimaryToken(v8, v303, a1);
      case 10:
        v11 = ObReferenceObjectByHandleWithTag(a1, 544, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
          goto LABEL_136;
        return v11;
      case 11:
        v11 = ObReferenceObjectByHandleWithTag(a1, 544, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
          goto LABEL_136;
        return v11;
      case 13:
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
LABEL_136:
          v11 = xKdEnumerateDebuggingDevices();
          ObfDereferenceObjectWithTag(v304);
        }
        return v11;
      case 15:
      case 42:
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v12 = v304;
        v11 = PsChargeProcessNonPagedPoolQuota(v304, 12312);
        if ( v11 < 0 )
          goto LABEL_674;
        v13 = (_DWORD *)ExAllocatePoolWithTag(512, 12312, 1935110992);
        v14 = (unsigned int)v13;
        if ( v13 )
        {
          PsWatchEnabled = 1;
          *v13 = 0;
          v13[1] = 0;
          KeInitializeGate((int)(v13 + 2));
          __dmb(0xBu);
          v15 = (unsigned int *)(v12 + 304);
          do
            v16 = __ldrex(v15);
          while ( !v16 && __strex(v14, v15) );
          __dmb(0xBu);
          if ( !v16 )
          {
            v11 = 0;
            goto LABEL_674;
          }
          ExFreePoolWithTag(v14);
          v11 = -1073741752;
        }
        else
        {
          v11 = -1073741801;
        }
        PsReturnProcessNonPagedPoolQuota(v12, 0x3018u);
        goto LABEL_674;
      case 16:
        if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v303, (int)&SeDebugPrivilege) )
          return -1073741727;
        v11 = ObReferenceObjectByHandleWithTag(v306, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          ObfDereferenceObjectWithTag(v304);
          v11 = -1073741822;
        }
        return v11;
      case 17:
        if ( a4 != 1 )
          return -1073741820;
        v307 = *(unsigned __int8 *)v5;
        v321 = v307;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          --*(_WORD *)(v8 + 308);
          v54 = v304;
          v55 = (unsigned __int8 *)(v304 + 168);
          v56 = KeAbPreAcquire(v304 + 168, 0, 0);
          v57 = v56;
          do
            v58 = __ldrex(v55);
          while ( __strex(v58 | 1, v55) );
          __dmb(0xBu);
          if ( (v58 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx((_DWORD *)(v54 + 168), v56, v54 + 168);
          if ( v57 )
            *(_BYTE *)(v57 + 14) |= 1u;
          v59 = v307;
          v60 = *(_DWORD *)(v54 + 412);
          if ( v307 )
            v61 = v60 | 4;
          else
            v61 = v60 & 0xFFFFFFFB;
          *(_DWORD *)(v54 + 412) = v61;
          KeSetAutoAlignmentProcess(v54, v59);
          __dmb(0xBu);
          do
            v62 = __ldrex((unsigned int *)v55);
          while ( __strex(v62 - 1, (unsigned int *)v55) );
          if ( (v62 & 2) != 0 && (v62 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(v54 + 168));
          v63 = KeAbPostRelease(v54 + 168);
          v64 = *(_WORD *)(v8 + 308) + 1;
          *(_WORD *)(v8 + 308) = v64;
          if ( !v64 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
            KiCheckForKernelApcDelivery(v63);
          ObfDereferenceObjectWithTag(v54);
          v11 = 0;
        }
        return v11;
      case 18:
        if ( a4 != 2 )
          return -1073741820;
        LOWORD(v309) = *(_WORD *)v5;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v11 = PspSetProcessPriorityClass(v304, BYTE1(v309));
        if ( v11 >= 0 )
          PsSetProcessPriorityByClass(v304, (_BYTE)v309 != 0, v27, (unsigned __int8)v309);
        goto LABEL_704;
      case 19:
        if ( a4 != 4 )
          return -1073741820;
        v65 = *v5;
        v340 = *v5;
        if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v303, (int)&SeDebugPrivilege) )
          return -1073741727;
        v11 = ObReferenceObjectByHandleWithTag(v306, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v12 = v304;
        if ( *(_DWORD *)(v304 + 780) )
        {
          v11 = -1073741790;
        }
        else
        {
          __dmb(0xBu);
          v66 = (unsigned int *)(v12 + 192);
          if ( v65 )
          {
            do
              v67 = __ldrex(v66);
            while ( __strex(v67 | 0x1000000, v66) );
          }
          else
          {
            do
              v68 = __ldrex(v66);
            while ( __strex(v68 & 0xFEFFFFFF, v66) );
          }
          __dmb(0xBu);
        }
        goto LABEL_674;
      case 21:
        if ( a4 == 4 )
        {
          v326 = 0;
          v327 = 0;
          v328 = 0;
          v326 = *v5;
          if ( !v326 )
            return -1073741811;
LABEL_180:
          v11 = ObReferenceObjectByHandleWithTag(v7, 512, PsProcessType, v303, 2035381072, &v304, 0);
          if ( v11 < 0 )
            return v11;
          v31 = (_DWORD *)v304;
          v71 = KeQueryGroupMaskProcess(v304);
          if ( ((v71 - 1) & v71) != 0 )
            goto LABEL_182;
          if ( a4 == 4 )
          {
            v362 = __clz(__rbit(v71));
            v72 = dword_681D78[v362];
            __dmb(0xBu);
            v73 = v72 & v326;
            v31 = (_DWORD *)v304;
            if ( v73 != v326 )
            {
LABEL_182:
              v11 = -1073741811;
LABEL_91:
              ObfDereferenceObjectWithTag((int)v31);
              return v11;
            }
            LOWORD(v327) = v362;
            v326 = v73;
          }
          --*(_WORD *)(v8 + 308);
          v74 = v31 + 43;
          __pld(v31 + 43);
          v75 = v31[43] & 0xFFFFFFFE;
          do
            v76 = __ldrex(v74);
          while ( v76 == v75 && __strex(v75 + 2, v74) );
          __dmb(0xBu);
          if ( v76 == v75 || (v77 = ExfAcquireRundownProtection(v31 + 43)) != 0 )
          {
            v78 = v31 + 42;
            v79 = KeAbPreAcquire((unsigned int)(v31 + 42), 0, 0);
            v80 = v79;
            do
              v81 = __ldrex(v78);
            while ( !v81 && __strex(0x11u, v78) );
            __dmb(0xBu);
            if ( v81 )
              ExfAcquirePushLockSharedEx(v31 + 42, v79, (unsigned int)(v31 + 42));
            if ( v80 )
              *(_BYTE *)(v80 + 14) |= 1u;
            v11 = PspSetProcessAffinitySafe(v31, 0, 0, &v326);
            __dmb(0xBu);
            do
              v82 = __ldrex(v78);
            while ( v82 == 17 && __strex(0, v78) );
            if ( v82 != 17 )
              ExfReleasePushLockShared(v31 + 42);
            v77 = KeAbPostRelease((unsigned int)(v31 + 42));
            __pld(v74);
            v83 = *v74 & 0xFFFFFFFE;
            __dmb(0xBu);
            do
              v84 = __ldrex(v74);
            while ( v84 == v83 && __strex(v83 - 2, v74) );
            if ( v84 != v83 )
              v77 = (int)ExfReleaseRundownProtection((unsigned __int8 *)v31 + 172);
            if ( v11 >= 0 )
            {
              if ( v316 )
                PspWritePebAffinityInfo((unsigned int *)v8, v31);
              __dmb(0xBu);
              v85 = v31 + 47;
              do
                v77 = __ldrex(v85);
              while ( __strex(v77 | 0x200000, v85) );
              __dmb(0xBu);
            }
          }
          else
          {
            v11 = -1073741558;
          }
          v86 = *(_WORD *)(v8 + 308) + 1;
          *(_WORD *)(v8 + 308) = v86;
          if ( !v86 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
            KiCheckForKernelApcDelivery(v77);
          goto LABEL_91;
        }
        if ( a4 == 12 )
        {
          v69 = v5[1];
          v70 = v5[2];
          v326 = *v5;
          v327 = v69;
          v328 = v70;
          if ( (unsigned __int16)v69 >= (unsigned int)KeQueryActiveGroupCount()
            || !v326
            || (dword_681D78[(unsigned __int16)v327] & v326) != v326
            || HIWORD(v328) | (unsigned __int16)v328 | HIWORD(v327) )
          {
            return -1073741811;
          }
          v7 = v306;
          goto LABEL_180;
        }
        return -1073741820;
      case 22:
        if ( a4 != 4 )
          return -1073741820;
        v342 = *v5;
        v307 = v342 != 0;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v87 = (unsigned int *)(v304 + 172);
        v313 = (int)v87;
        __pld((void *)(v304 + 172));
        v88 = *v87 & 0xFFFFFFFE;
        do
          v89 = __ldrex(v87);
        while ( v89 == v88 && __strex(v88 + 2, v87) );
        __dmb(0xBu);
        if ( v89 == v88 || ExfAcquireRundownProtection(v87) )
        {
          --*(_WORD *)(v8 + 308);
          v90 = (unsigned __int8 *)(v304 + 168);
          v91 = KeAbPreAcquire(v304 + 168, 0, 0);
          v310 = (int *)v91;
          do
            v92 = __ldrex(v90);
          while ( __strex(v92 | 1, v90) );
          __dmb(0xBu);
          if ( (v92 & 1) != 0 )
          {
            ExfAcquirePushLockExclusiveEx(v90, v91, (unsigned int)v90);
            v91 = (int)v310;
          }
          if ( v91 )
            *(_BYTE *)(v91 + 14) |= 1u;
          v93 = v307;
          KeSetDisableBoostProcess(v304, v307);
          v94 = *(_DWORD **)(v304 + 396);
          v95 = (_DWORD *)(v304 + 396);
          while ( v94 != v95 )
          {
            KeSetDisableBoostThread(v94 - 233, v93);
            v94 = (_DWORD *)*v94;
          }
          __dmb(0xBu);
          do
            v96 = __ldrex((unsigned int *)v90);
          while ( __strex(v96 - 1, (unsigned int *)v90) );
          v97 = v311;
          v98 = (_DWORD *)v313;
          if ( (v96 & 2) != 0 && (v96 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v90);
          v99 = KeAbPostRelease((unsigned int)v90);
          v100 = *(_WORD *)(v97 + 308) + 1;
          *(_WORD *)(v97 + 308) = v100;
          if ( !v100 && *(_DWORD *)(v97 + 100) != v97 + 100 && !*(_WORD *)(v97 + 310) )
            KiCheckForKernelApcDelivery(v99);
          __pld(v98);
          v101 = *v98 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v102 = __ldrex(v98);
          while ( v102 == v101 && __strex(v101 - 2, v98) );
          if ( v102 != v101 )
            ExfReleaseRundownProtection((unsigned __int8 *)v98);
        }
        else
        {
          v11 = -1073741558;
        }
        goto LABEL_704;
      case 23:
        if ( a4 != 4 )
          return -1073741820;
        v108 = *v5;
        v344 = *v5;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          v11 = ObSetDeviceMap(v304, v108);
          ObfDereferenceObjectWithTag(v304);
        }
        return v11;
      case 24:
        if ( a4 != 4 )
          return -1073741820;
        v109 = *v5;
        v318 = (_DWORD *)*v5;
        if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v303, (int)&SeDebugPrivilege) )
          return -1073741727;
        v11 = ObReferenceObjectByHandleWithTag(v306, 516, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        if ( v109 == MmGetSessionId(v304) )
          v11 = 0;
        else
          v11 = -1073741790;
        goto LABEL_704;
      case 25:
        if ( a4 != 1 )
          return -1073741820;
        v28 = *(unsigned __int8 *)v5;
        v322 = *(_BYTE *)v5;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          PsSetProcessPriorityByClass(v304, v28 != 0, v29, v30);
          ObfDereferenceObjectWithTag(v304);
          v11 = 0;
        }
        return v11;
      case 29:
        if ( a4 != 4 )
          return -1073741820;
        v110 = *v5;
        v354 = *v5;
        if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v303, (int)&SeDebugPrivilege) )
          return -1073741727;
        v11 = ObReferenceObjectByHandleWithTag(v306, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        __dmb(0xBu);
        v18 = v304;
        v111 = (unsigned int *)(v304 + 192);
        if ( v110 )
        {
          do
            v112 = __ldrex(v111);
          while ( __strex(v112 | 0x2000, v111) );
        }
        else
        {
          do
            v113 = __ldrex(v111);
          while ( __strex(v113 & 0xFFFFDFFF, v111) );
        }
        goto LABEL_543;
      case 31:
        if ( a4 != 4 )
          return -1073741820;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v358 = *v5;
        v103 = v358;
        if ( (v358 & 0xFFFFFFFE) != 0 )
        {
          v11 = -1073741811;
          v107 = v304;
        }
        else
        {
          __dmb(0xBu);
          v107 = v304;
          v104 = (unsigned int *)(v304 + 192);
          if ( (v103 & 1) != 0 )
          {
            do
              v105 = __ldrex(v104);
            while ( __strex(v105 & 0xFFFFFFFD, v104) );
          }
          else
          {
            do
              v106 = __ldrex(v104);
            while ( __strex(v106 | 2, v104) );
          }
          __dmb(0xBu);
        }
        goto LABEL_261;
      case 32:
        if ( !a4 )
          goto LABEL_286;
        if ( a4 != 4 && a4 != 8 )
          return -1073741820;
        v114 = *v5;
        v338 = *v5;
        if ( a4 == 8 )
          v339 = v5[1];
        else
          v339 = 0;
        if ( v114 )
          return -1073741811;
LABEL_286:
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          v115 = v304;
          if ( a4 )
            v116 = &v338;
          else
            v116 = 0;
          v11 = PsSetProcessHandleTracingInformation(v304, v116);
          ObfDereferenceObjectWithTag(v115);
        }
        return v11;
      case 33:
        if ( a4 == 4 )
        {
          v117 = *v5;
          __dmb(0xBu);
          v324 = v117;
          v118 = 0;
        }
        else
        {
          if ( a4 != 8 )
            return -1073741820;
          v117 = *v5;
          v118 = v5[1];
          __dmb(0xBu);
          v345 = v117;
          v346 = v118;
          v118 = (unsigned __int8)v118;
          v324 = v117;
        }
        v307 = v118;
        if ( v117 >= 4 )
          return -1073741811;
        if ( v117 >= 3 )
        {
          if ( !SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, a1, 512, v303) )
            return -1073741727;
          v7 = v306;
        }
        v11 = ObReferenceObjectByHandleWithTag(v7, 512, PsProcessType, v303, 2035381072, &v304, 0);
        v310 = (int *)v11;
        if ( v11 < 0 )
          return v11;
        v119 = (_DWORD *)v304;
        v120 = (unsigned int *)(v304 + 172);
        v312 = (int)v120;
        __pld((void *)(v304 + 172));
        v121 = *v120 & 0xFFFFFFFE;
        do
          v122 = __ldrex(v120);
        while ( v122 == v121 && __strex(v121 + 2, v120) );
        __dmb(0xBu);
        if ( v122 == v121 || ExfAcquireRundownProtection(v119 + 43) )
        {
          --*(_WORD *)(v8 + 308);
          v308 = (unsigned int)(v119 + 42);
          v123 = KeAbPreAcquire((unsigned int)(v119 + 42), 0, 0);
          v124 = (unsigned __int8 *)(v119 + 42);
          do
            v125 = __ldrex(v124);
          while ( __strex(v125 | 1, v124) );
          __dmb(0xBu);
          if ( (v125 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v124, v123, (unsigned int)(v119 + 42));
          if ( v123 )
            *(_BYTE *)(v123 + 14) |= 1u;
          v128 = v119[48];
          v126 = v119 + 48;
          v127 = v128;
          __dmb(0xBu);
          v129 = v324;
          do
          {
            v130 = v127;
            __dmb(0xBu);
            do
              v131 = __ldrex(v126);
            while ( v131 == v127 && __strex(v127 & 0xC7FFFFFF | (v129 << 27), v126) );
            v127 = v131;
            __dmb(0xBu);
          }
          while ( v131 != v130 );
          v132 = *(_DWORD **)(v304 + 396);
          v133 = (_DWORD *)(v304 + 396);
          v134 = v307;
          while ( v132 != v133 )
          {
            v135 = (int)(v132 - 233);
            v307 = (unsigned int)(v132 - 233);
            if ( v134 == 1 && ((v132[7] >> 9) & 7) < v129 )
            {
              IoBoostThreadIoPriority(v135, v129, 0);
              v135 = v307;
            }
            v136 = (unsigned int *)(v135 + 960);
            v137 = *(_DWORD *)(v135 + 960);
            __dmb(0xBu);
            do
            {
              v307 = v137;
              __dmb(0xBu);
              do
                v138 = __ldrex(v136);
              while ( v138 == v137 && __strex(v137 & 0xFFFFF1FF | (v129 << 9), v136) );
              v137 = v138;
              __dmb(0xBu);
            }
            while ( v138 != v307 );
            v139 = (v307 >> 9) & 7;
            v307 = v139;
            v129 = v324;
            if ( (dword_682604 & 0x2000) != 0 )
            {
              EtwTracePriority(v132 - 233, 1332, v139, v324, 0);
              v139 = v307;
            }
            if ( v129 != v139 )
              KeAbProcessBaseIoPriorityChange((int)(v132 - 233), v139, v129);
            v132 = (_DWORD *)*v132;
          }
          __dmb(0xBu);
          v140 = (unsigned int *)v308;
          do
            v141 = __ldrex(v140);
          while ( __strex(v141 - 1, v140) );
          v11 = (int)v310;
          v142 = v311;
          if ( (v141 & 2) != 0 && (v141 & 4) == 0 )
            ExfTryToWakePushLock(v140);
          v143 = KeAbPostRelease((unsigned int)v140);
          v144 = *(_WORD *)(v142 + 308) + 1;
          *(_WORD *)(v142 + 308) = v144;
          if ( !v144 && *(_DWORD *)(v142 + 100) != v142 + 100 && !*(_WORD *)(v142 + 310) )
            KiCheckForKernelApcDelivery(v143);
          v145 = (unsigned int *)v312;
          __pld((void *)v312);
          v146 = *v145 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v147 = __ldrex(v145);
          while ( v147 == v146 && __strex(v146 - 2, v145) );
          if ( v147 != v146 )
            ExfReleaseRundownProtection((unsigned __int8 *)v145);
          v119 = (_DWORD *)v304;
        }
        else
        {
          v11 = -1073741558;
        }
        goto LABEL_347;
      case 34:
        if ( a4 != 4 )
          return -1073741820;
        if ( a1 != -1 )
          return -1073741811;
        v368 = *v5;
        __mrc(15, 0, 13, 0, 3);
        return KeSetExecuteOptions();
      case 35:
        if ( a1 != -1 )
          return -1073741811;
        if ( v303 != 1 )
          return -1073741823;
        if ( a4 < 0x1C || (a4 - 16) % 0xC )
          return -1073741820;
        if ( a4 == 28 )
        {
          v180 = _1A0;
          v305 = _1A0;
          v318 = _1A0;
        }
        else
        {
          v180 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, a4, 1936479312);
          v305 = v180;
          v318 = v180;
          if ( !v180 )
            return -1073741670;
        }
        memmove((int)v180, (int)v5, a4);
        v309 = v317;
        if ( v180[1] < 2u && (*v180 & 0xFFFFFFFE) == 0 && (v181 = v180[2]) != 0 && (a4 - 16) / 0xC == v180[2] )
        {
          v182 = 0;
          v319 = 0;
          while ( v182 < v181 )
          {
            if ( v180[3 * v182 + 4] )
              goto LABEL_415;
            v319 = ++v182;
          }
          v183 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v315 = v183;
          v304 = v183;
          if ( (*v180 & 1) != 0 )
          {
LABEL_415:
            v184 = -1073741811;
            v309 = -1073741811;
            goto LABEL_459;
          }
          v308 = 4;
          v314 = 4;
          v316 = 4;
          v313 = 4;
          v310 = v5;
          v185 = 0;
          v306 = 0;
          v319 = 0;
          v309 = 0;
          v317 = 0;
          v186 = 0;
          for ( i = v183; ; i = v315 )
          {
            v188 = PsGetNextProcessThread(i, v186);
            v189 = (_DWORD *)v188;
            v190 = 940;
            v191 = 1024;
            v311 = v188;
            if ( !v188 || v185 >= v180[2] )
              break;
            if ( (*(_DWORD *)(v188 + 76) & 0x400) == 0 )
            {
              v192 = (unsigned int *)(v188 + 940);
              __pld(v189 + 235);
              v193 = v189[235] & 0xFFFFFFFE;
              do
                v194 = __ldrex(v192);
              while ( v194 == v193 && __strex(v193 + 2, v192) );
              __dmb(0xBu);
              if ( v194 == v193 || ExfAcquireRundownProtection(v192) )
              {
                v195 = v189[39];
                v307 = v195;
                v329 = v195 + 44;
                v323 = *(_DWORD *)(v195 + 44);
                v196 = v323;
                v197 = (int)v305;
                v198 = v306;
                if ( v323 )
                {
                  if ( v305[1] == 1 )
                  {
                    if ( v323 == v195 + 44 )
                    {
                      v196 = 0;
                      v323 = 0;
                    }
                    else
                    {
                      v199 = v305[3] * v308;
                      if ( v199 )
                      {
                        if ( ((v316 - 1) & v323) != 0 )
                          ExRaiseDatatypeMisalignment(1);
                        if ( v323 + v199 > MmUserProbeAddress || v323 + v199 < v323 )
                          *(_BYTE *)MmUserProbeAddress = 0;
                      }
                      v200 = v197 + 12 * v198;
                      ProbeForWrite(*(_DWORD *)(v200 + 20), *(_DWORD *)(v197 + 12) * v308, v316);
                      memmove(*(_DWORD *)(v200 + 20), v196, v305[3] * v308);
                      __dmb(0xFu);
                      v197 = (int)v305;
                    }
                    v201 = v306;
                    v5[3 * v306 + 4] |= 1u;
                    v202 = v309;
                    *(_DWORD *)(v195 + 44) = *(_DWORD *)(v197 + 12 * v201 + 20);
                    v185 = v306;
                    if ( v202 < 0 )
                    {
                      v5[3 * v306 + 4] &= 0xFFFFFFFE;
                    }
                    else
                    {
                      v5[3 * v306 + 6] = v189[220];
                      v203 = &v5[3 * v185];
                      v203[5] = v196;
                      v203[4] ^= 3u;
                      v306 = ++v185;
                      v319 = v185;
                    }
                    v180 = v305;
                    v184 = v309;
                  }
                  else
                  {
                    v185 = v306;
                    v5[3 * v306 + 4] |= 1u;
                    v204 = (int *)(v196 + 4 * *(_DWORD *)(v197 + 12));
                    if ( (unsigned int)v204 >= MmUserProbeAddress )
                      v204 = (int *)MmUserProbeAddress;
                    v205 = *v204;
                    v329 = *v204;
                    v206 = (_DWORD *)(v196 + 4 * *(_DWORD *)(v197 + 12));
                    if ( (unsigned int)v206 >= MmUserProbeAddress )
                      v206 = (_DWORD *)MmUserProbeAddress;
                    v180 = v305;
                    *v206 = v305[3 * v185 + 5];
                    v184 = v309;
                    if ( v309 < 0 )
                    {
                      v5[3 * v185 + 4] &= 0xFFFFFFFE;
                    }
                    else
                    {
                      v207 = &v5[3 * v185];
                      v207[5] = v205;
                      v207[4] ^= 3u;
                      v306 = ++v185;
                      v319 = v185;
                    }
                  }
                }
                else
                {
                  v185 = v306;
                  v180 = v305;
                  v184 = v309;
                }
                v208 = v189 + 235;
                __pld(v189 + 235);
                v209 = v189[235] & 0xFFFFFFFE;
                __dmb(0xBu);
                v190 = v209 - 2;
                do
                  v191 = __ldrex(v208);
                while ( v191 == v209 && __strex(v190, v208) );
                if ( v191 != v209 )
                {
                  ExfReleaseRundownProtection((unsigned __int8 *)v208);
                  v184 = v309;
                }
                if ( v184 < 0 )
                  goto LABEL_456;
              }
            }
            v186 = v189;
          }
          v184 = v309;
LABEL_456:
          if ( v189 )
          {
            PsQuitNextProcessThread(v189, v191, v190);
            v184 = v309;
          }
        }
        else
        {
          v184 = -1073741820;
          v309 = -1073741820;
        }
LABEL_459:
        if ( v180 != _1A0 )
        {
          ExFreePoolWithTag((unsigned int)v180);
          v184 = v309;
        }
        return v184;
      case 39:
        if ( a4 != 4 )
          return -1073741820;
        v148 = *v5;
        __dmb(0xBu);
        v313 = v148;
        v149 = MmGetDefaultPagePriority();
        if ( v150 > v149 )
          return -1073741811;
        v151 = MmGetMinWsPagePriority();
        if ( v154 < v151 )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(v306, 512, *(_DWORD *)(v152 + 2072), v303, 2035381072, &v304, v153);
        v310 = (int *)v11;
        if ( v11 < 0 )
          return v11;
        v12 = v304;
        v155 = (unsigned int *)(v304 + 172);
        v312 = (int)v155;
        __pld((void *)(v304 + 172));
        v156 = *v155 & 0xFFFFFFFE;
        do
          v157 = __ldrex(v155);
        while ( v157 == v156 && __strex(v156 + 2, v155) );
        __dmb(0xBu);
        if ( v157 == v156 || ExfAcquireRundownProtection((_DWORD *)(v12 + 172)) )
        {
          --*(_WORD *)(v8 + 308);
          v308 = v12 + 168;
          v158 = KeAbPreAcquire(v12 + 168, 0, 0);
          v159 = (unsigned __int8 *)(v12 + 168);
          do
            v160 = __ldrex(v159);
          while ( __strex(v160 | 1, v159) );
          __dmb(0xBu);
          if ( (v160 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(v159, v158, v12 + 168);
          if ( v158 )
            *(_BYTE *)(v158 + 14) |= 1u;
          v161 = (unsigned int *)(v12 + 188);
          v162 = *(_DWORD *)(v12 + 188);
          __dmb(0xBu);
          v163 = v313;
          v307 = v313;
          do
          {
            v164 = v162;
            __dmb(0xBu);
            do
              v165 = __ldrex(v161);
            while ( v165 == v162 && __strex(v162 & 0xFFFF8FFF | (v163 << 12), v161) );
            v162 = v165;
            __dmb(0xBu);
          }
          while ( v165 != v164 );
          v166 = *(_DWORD **)(v304 + 396);
          v167 = (_DWORD *)(v304 + 396);
          v168 = v311;
          v169 = v307;
          while ( v166 != v167 )
          {
            v170 = v166 + 7;
            v171 = v166[7];
            __dmb(0xBu);
            do
            {
              v307 = v171;
              __dmb(0xBu);
              do
                v172 = __ldrex(v170);
              while ( v172 == v171 && __strex(v171 & 0xFFFF8FFF | (v169 << 12), v170) );
              v171 = v172;
              __dmb(0xBu);
            }
            while ( v172 != v307 );
            v168 = v311;
            if ( (dword_682604 & 0x2000) != 0 )
              EtwTracePriority(v166 - 233, 1331, (v307 >> 12) & 7, v313, 0);
            v166 = (_DWORD *)*v166;
          }
          __dmb(0xBu);
          v173 = (unsigned int *)v308;
          do
            v174 = __ldrex(v173);
          while ( __strex(v174 - 1, v173) );
          v11 = (int)v310;
          if ( (v174 & 2) != 0 && (v174 & 4) == 0 )
            ExfTryToWakePushLock(v173);
          v175 = KeAbPostRelease((unsigned int)v173);
          v176 = *(_WORD *)(v168 + 308) + 1;
          *(_WORD *)(v168 + 308) = v176;
          if ( !v176 && *(_DWORD *)(v168 + 100) != v168 + 100 && !*(_WORD *)(v168 + 310) )
            KiCheckForKernelApcDelivery(v175);
          v177 = (unsigned int *)v312;
          __pld((void *)v312);
          v178 = *v177 & 0xFFFFFFFE;
          __dmb(0xBu);
          do
            v179 = __ldrex(v177);
          while ( v179 == v178 && __strex(v178 - 2, v177) );
          if ( v179 != v178 )
            ExfReleaseRundownProtection((unsigned __int8 *)v177);
          v12 = v304;
        }
        else
        {
          v11 = -1073741558;
        }
        goto LABEL_674;
      case 40:
        if ( a4 != 4 && a4 != 12 )
          return -1073741820;
        if ( a4 == 4 )
        {
          v210 = 0;
          v334 = 0;
          v211 = 0;
          v335 = 0;
          v212 = *v5;
          v336 = *v5;
        }
        else
        {
          v210 = *v5;
          v211 = v5[1];
          v212 = v5[2];
          v334 = *v5;
          v335 = v211;
          v336 = v212;
        }
        v310 = (int *)v212;
        if ( v211 )
          return -1073741811;
        if ( v210 )
          return -1073741736;
        if ( v212 )
          v213 = v212 | 1;
        else
          v213 = 0;
        if ( v212 != v213 )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          v214 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v215 = SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v303, (int)&SeDebugPrivilege);
          v119 = (_DWORD *)v304;
          if ( v215 || v304 == v214 )
          {
            v216 = (unsigned int *)(v304 + 172);
            __pld((void *)(v304 + 172));
            v217 = *(_DWORD *)(v304 + 172) & 0xFFFFFFFE;
            do
              v218 = __ldrex(v216);
            while ( v218 == v217 && __strex(v217 + 2, v216) );
            __dmb(0xBu);
            if ( v218 == v217 || ExfAcquireRundownProtection(v119 + 43) )
            {
              v11 = 0;
              KiStackAttachProcess((int)v119, 0, (int)v379);
              if ( !MmValidateUserCallTarget(v310) )
                v11 = -1073741811;
              KiUnstackDetachProcess((unsigned int)v379, 0);
              if ( v11 >= 0 )
              {
                --*(_WORD *)(v8 + 308);
                v219 = KeAbPreAcquire((unsigned int)(v119 + 42), 0, 0);
                v307 = v219;
                v220 = (unsigned __int8 *)(v119 + 42);
                do
                  v221 = __ldrex(v220);
                while ( __strex(v221 | 1, v220) );
                __dmb(0xBu);
                if ( (v221 & 1) != 0 )
                {
                  ExfAcquirePushLockExclusiveEx(v220, v219, (unsigned int)(v119 + 42));
                  v220 = (unsigned __int8 *)(v119 + 42);
                  v219 = v307;
                }
                if ( v219 )
                  *(_BYTE *)(v219 + 14) |= 1u;
                v222 = (int)v310;
                v119[40] = v310;
                for ( j = (_DWORD *)v119[99]; j != v119 + 99; j = (_DWORD *)*j )
                {
                  __dmb(0xBu);
                  if ( v222 )
                  {
                    v224 = (unsigned __int8 *)j - 929;
                    do
                      v225 = __ldrex(v224);
                    while ( __strex(v225 | 2, v224) );
                  }
                  else
                  {
                    v226 = (unsigned __int8 *)j - 929;
                    do
                      v227 = __ldrex(v226);
                    while ( __strex(v227 & 0xFD, v226) );
                  }
                  __dmb(0xBu);
                }
                __dmb(0xBu);
                do
                  v228 = __ldrex((unsigned int *)v220);
                while ( __strex(v228 - 1, (unsigned int *)v220) );
                v229 = v311;
                v216 = v119 + 43;
                if ( (v228 & 2) != 0 && (v228 & 4) == 0 )
                {
                  ExfTryToWakePushLock((unsigned int *)v220);
                  v220 = (unsigned __int8 *)(v119 + 42);
                }
                v230 = KeAbPostRelease((unsigned int)v220);
                v231 = *(_WORD *)(v229 + 308) + 1;
                *(_WORD *)(v229 + 308) = v231;
                if ( !v231 && *(_DWORD *)(v229 + 100) != v229 + 100 && !*(_WORD *)(v229 + 310) )
                  KiCheckForKernelApcDelivery(v230);
              }
              __pld(v216);
              v232 = *v216 & 0xFFFFFFFE;
              __dmb(0xBu);
              do
                v233 = __ldrex(v216);
              while ( v233 == v232 && __strex(v232 - 2, v216) );
              if ( v233 != v232 )
                ExfReleaseRundownProtection((unsigned __int8 *)v216);
LABEL_347:
              ObfDereferenceObjectWithTag((int)v119);
            }
            else
            {
              ObfDereferenceObjectWithTag((int)v119);
              v11 = -1073741558;
            }
          }
          else
          {
            ObfDereferenceObjectWithTag(v304);
            v11 = -1073741727;
          }
        }
        return v11;
      case 41:
        if ( a1 != -1 )
          return -1073741811;
        v234 = 0;
        if ( a4 == 28 )
        {
          if ( v303 )
          {
            v235 = v5[1];
            v236 = v5[2];
            v237 = v5[3];
            v372[0] = *v5;
            v372[1] = v235;
            v372[2] = v236;
            v372[3] = v237;
            v238 = v5[5];
            v239 = v5[6];
            v373 = v5[4];
            v374 = v238;
            v375 = v239;
            v234 = v5 + 6;
            v5 = v372;
          }
          if ( (unsigned int)*v5 > 0x10 || v5[1] | v5[3] | v5[2] )
            return -1073741811;
          v5 += 4;
        }
        else
        {
          if ( a4 != 12 )
            return -1073741820;
          v307 = 0;
          if ( v303 )
          {
            v373 = *v5;
            v374 = v5[1];
            v234 = v5 + 2;
            v5 = &v373;
          }
        }
        if ( !*v5 )
          return -1073741811;
        v347 = *v5;
        v5[2] = 0;
        v11 = ZwAllocateVirtualMemory();
        if ( v11 >= 0 && v303 )
          *v234 = v5[2];
        return v11;
      case 45:
        if ( a1 != -1 )
          return -1073741811;
        if ( a4 != 4 )
          return -1073741820;
        v314 = *v5;
        if ( (v314 & 0xFFFFFFFC) != 0 )
          return -1073741811;
        return PspSetProcessAffinityUpdateMode(v8, &v314);
      case 46:
        if ( a4 != 4 )
          return -1073741820;
        v240 = *v5;
        v355 = v240;
        if ( (v240 & 0xFFFFFFFE) != 0 )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v241 = (v240 & 1) == 0;
        __dmb(0xBu);
        v18 = v304;
        v242 = (unsigned int *)(v304 + 192);
        if ( v241 )
        {
          do
            v244 = __ldrex(v242);
          while ( __strex(v244 & 0xFFDFFFFF, v242) );
        }
        else
        {
          do
            v243 = __ldrex(v242);
          while ( __strex(v243 | 0x200000, v242) );
        }
        goto LABEL_543;
      case 48:
        if ( a4 != 4 )
          return -1073741820;
        v350 = *v5;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          v245 = PsReferencePrimaryToken(v304);
          SeSetVirtualizationToken(v245);
          ObfDereferenceObject(v245);
          ObfDereferenceObjectWithTag(v304);
          v11 = 0;
        }
        return v11;
      case 49:
        if ( a4 != 4 )
          return -1073741820;
        if ( a1 != -1 )
          return -1073741811;
        v357 = *v5;
        if ( (v357 & 3) != 1 )
          return -1073741811;
        *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 316) = v357;
        return 0;
      case 52:
        v307 = 0;
        v320 = 0;
        if ( a4 != 8 )
          return -1073741820;
        v246 = *v5;
        v247 = v5[1];
        __dmb(0xBu);
        v348 = v246;
        v349 = v247;
        if ( a1 != -1 && v246 != 2 )
          return -1073741811;
        break;
      case 53:
        if ( a1 != -1 )
          return -1073741811;
        if ( a4 != 8 )
          return -1073741820;
        v273 = (_DWORD *)*v5;
        v274 = v5[1];
        __dmb(0xBu);
        v351 = v273;
        v352 = v274;
        if ( (_BYTE)v274 )
          v11 = RtlRemoveDynamicFunctionTable((int)v273);
        else
          v11 = RtlInsertDynamicFunctionTable(v273, (int)&KeActiveProcessors);
        return v11;
      case 54:
        if ( a4 != 4 )
          return -1073741820;
        v275 = *v5;
        __dmb(0xBu);
        v353 = v275;
        if ( (v275 & 0xFFFFFFFE) != 0 )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v276 = ObReferenceProcessHandleTable(v304);
        if ( !v276 )
          goto LABEL_685;
        ExEnableHandleExceptions(v276, (v275 & 1) != 0);
        ObDereferenceProcessHandleTable(v304);
        v11 = 0;
        goto LABEL_704;
      case 56:
        v277 = 0;
        v337 = 0;
        if ( v303 != 1 )
          goto LABEL_699;
        if ( (unsigned int)v5 >= MmUserProbeAddress )
          v5 = (int *)MmUserProbeAddress;
        v331 = *v5;
        v278 = v5[1];
        v332 = v278;
        v279 = (unsigned __int16)v331;
        if ( (_WORD)v331 )
        {
          if ( (v278 & 1) != 0 )
            ExRaiseDatatypeMisalignment(0);
          if ( (unsigned __int16)v331 + v278 > MmUserProbeAddress || (unsigned __int16)v331 + v278 < v278 )
          {
            *(_BYTE *)MmUserProbeAddress = 0;
            v279 = (unsigned __int16)v331;
          }
          v280 = ExAllocatePoolWithTag(512, v279, 1850307408);
          v277 = v280;
          v337 = v280;
          if ( v280 )
          {
            memmove(v280, v332, (unsigned __int16)v331);
            v332 = v277;
            v5 = &v331;
            v325 = &v331;
            v7 = v306;
LABEL_699:
            v11 = ObReferenceObjectByHandleWithTag(v7, 512, PsProcessType, v303, 2035381072, &v304, 0);
            if ( v11 >= 0 )
            {
              v11 = IoRevokeHandlesForProcess((int)v5, v304);
              if ( v277 )
                ExFreePoolWithTag(v277);
LABEL_704:
              ObfDereferenceObjectWithTag(v304);
            }
            else if ( v277 )
            {
              ExFreePoolWithTag(v277);
            }
          }
          else
          {
            v11 = -1073741670;
            v312 = -1073741670;
          }
        }
        else
        {
          v11 = -1073741811;
          v312 = -1073741811;
        }
        return v11;
      case 57:
        return MmProcessWorkingSetControl(a1, v5, a4, v303);
      case 59:
        if ( a4 != 4 )
          return -1073741820;
        v41 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v41 < 0 )
          return v41;
        v281 = *v5 != 0;
        v359 = v281;
        v107 = v304;
        if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) == v107 )
        {
          v11 = -1073741790;
        }
        else if ( SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v303, (int)&SeDebugPrivilege) )
        {
          v11 = 0;
          KeSetCheckStackExtentsProcess(v107, v281);
        }
        else
        {
          v11 = -1073741727;
        }
LABEL_261:
        ObfDereferenceObjectWithTag(v107);
        return v11;
      case 62:
        if ( a4 != 12 )
          return -1073741820;
        v376 = *v5;
        v377 = v5[1];
        v378 = v5[2];
        if ( (unsigned __int16)v376 != 1 || v377 >= 1 || v377 )
          return -1073741811;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v17 = v378;
        __dmb(0xBu);
        v18 = v304;
        v19 = (unsigned int *)(v304 + 192);
        if ( v17 )
        {
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 | 0x100, v19) );
        }
        else
        {
          do
            v21 = __ldrex(v19);
          while ( __strex(v21 & 0xFFFFFEFF, v19) );
        }
LABEL_543:
        __dmb(0xBu);
        ObfDereferenceObjectWithTag(v18);
        return 0;
      case 63:
        if ( a4 != 8 )
          return -1073741820;
        v41 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v41 < 0 )
          return v41;
        v364[0] = *v5;
        v364[1] = v5[1];
        v282 = v304;
        v11 = PsSetProcessFaultInformation(v304, v364);
        ObfDereferenceObjectWithTag(v282);
        return v11;
      case 65:
        if ( a4 != 12 )
          return -1073741820;
        v41 = ObReferenceObjectByHandleWithTag(a1, 521, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v41 < 0 )
          return v41;
        v283 = v5[1];
        v284 = v5[2];
        v365 = *v5;
        v366 = v283;
        v367 = v284;
        v285 = v304;
        if ( v365 == 2 )
        {
          if ( (v366 & 0xFFFFFFFE) != 0 || v367 )
          {
            ObfDereferenceObjectWithTag(v304);
            v11 = -1073741811;
          }
          else
          {
            v11 = MmSetCommitReleaseEligibility(v304, v366 & 1);
            ObfDereferenceObjectWithTag(v285);
          }
        }
        else
        {
          ObfDereferenceObjectWithTag(v304);
          v11 = -1073741735;
        }
        return v11;
      case 66:
      case 67:
        if ( (a4 & 7) != 0 || a4 > 8 )
          return -1073741820;
        memmove((int)v369, (int)v5, a4);
        if ( a2 != 67 || (v11 = ExCpuSetResourceManagerAccessCheck(v303), v11 >= 0) )
        {
          v11 = ObReferenceObjectByHandleWithTag(v306, 0x2000, PsProcessType, v303, 2035381072, &v304, 0);
          if ( v11 >= 0 )
          {
            v11 = KeSetCpuSetsProcess(v304, a4 >> 3, v369, (_DWORD *)(a2 == 67));
            ObfDereferenceObjectWithTag(v304);
          }
        }
        return v11;
      case 68:
        if ( (*(_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 605) & 1) == 0 )
          return -1073741727;
        v11 = ObReferenceObjectByHandle(a1, 512, PsProcessType, v303, &v361);
        if ( v11 < 0 )
          return v11;
        __dmb(0xBu);
        v43 = v361;
        v286 = (unsigned int *)(v361 + 736);
        do
          v287 = __ldrex(v286);
        while ( __strex(v287 | 0x100, v286) );
        __dmb(0xBu);
        goto LABEL_735;
      case 70:
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 >= 0 )
        {
          __dmb(0xBu);
          v288 = v304;
          v289 = (unsigned int *)(v304 + 736);
          do
            v290 = __ldrex(v289);
          while ( __strex(v290 | 0x400, v289) );
          __dmb(0xBu);
          ObfDereferenceObjectWithTag(v288);
          v11 = 0;
        }
        return v11;
      case 71:
        if ( a4 != 4 )
          return -1073741820;
        v291 = *v5;
        __dmb(0xBu);
        v356 = v291;
        v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
        if ( v11 < 0 )
          return v11;
        v292 = ObReferenceProcessHandleTable(v304);
        if ( v292 )
        {
          ExEnableRaiseUMExceptionOnInvalidHandleClose(v292, v291);
          ObDereferenceProcessHandleTable(v304);
          v11 = 0;
        }
        else
        {
LABEL_685:
          v11 = -1073741558;
        }
        goto LABEL_704;
      default:
        return -1073741821;
    }
    v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v310 = (int *)v12;
    v304 = v12;
    switch ( v246 )
    {
      case 1:
        if ( (v247 & 0xFFFFFFF0) != 0 )
        {
          v11 = -1073741811;
          goto LABEL_673;
        }
        v248 = (v247 >> 1) & 1;
        if ( !v248 && (*(_DWORD *)(v12 + 188) & 0x8000000) != 0
          || (v247 & 1) == 0 && (*(_DWORD *)(v12 + 188) & 0x20000) == 0 )
        {
          goto LABEL_563;
        }
        v249 = (v247 >> 3) & 1;
        if ( v249 )
        {
          if ( !v248 )
          {
            v11 = -1073741776;
            goto LABEL_673;
          }
        }
        else
        {
          if ( (*(_DWORD *)(v12 + 188) & 0x1000000) != 0 )
            goto LABEL_563;
          if ( !v248 )
            goto LABEL_571;
        }
        __dmb(0xBu);
        v250 = (unsigned int *)(v12 + 188);
        do
          v251 = __ldrex(v250);
        while ( __strex(v251 | 0x8000000, v250) );
        __dmb(0xBu);
LABEL_571:
        if ( (v247 & 1) != 0 )
        {
          __dmb(0xBu);
          v252 = (unsigned int *)(v12 + 188);
          do
            v253 = __ldrex(v252);
          while ( __strex(v253 & 0xFFFDFFFF, v252) );
          __dmb(0xBu);
        }
        if ( v249 )
        {
          __dmb(0xBu);
          v254 = (unsigned int *)(v12 + 188);
          do
            v255 = __ldrex(v254);
          while ( __strex(v255 | 0x1000000, v254) );
          __dmb(0xBu);
        }
        v11 = 0;
LABEL_673:
        if ( v307 == 1 )
LABEL_674:
          ObfDereferenceObjectWithTag(v12);
        return v11;
      case 2:
        if ( (v247 & 0xFFFFFFFE) != 0 )
        {
          v11 = -1073741811;
          goto LABEL_673;
        }
        if ( PsIsSystemWideMitigationOptionSet(36, &KeActiveProcessors, 0, 32) )
          goto LABEL_672;
        if ( v306 == -1 )
        {
          v12 = (int)v310;
        }
        else
        {
          if ( !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v303, (int)&SeDebugPrivilege) )
          {
            v11 = -1073741727;
            v12 = (int)v310;
            goto LABEL_673;
          }
          v11 = ObReferenceObjectByHandleWithTag(v306, 512, PsProcessType, v303, 2035381072, &v304, 0);
          if ( v11 < 0 )
          {
            v12 = v304;
            goto LABEL_673;
          }
          v307 = 1;
          v260 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v12 = v304;
          if ( v304 != v260 )
          {
            if ( (v247 & 1) != 0 && (*(_DWORD *)(v304 + 188) & 0x400) == 0 )
            {
              v11 = -1073741790;
              goto LABEL_673;
            }
            if ( (v247 & 1) != 0 )
              goto LABEL_628;
            __dmb(0xBu);
            v261 = (unsigned int *)(v12 + 188);
            do
              v262 = __ldrex(v261);
            while ( __strex(v262 & 0xFFFFFBFF, v261) );
            goto LABEL_627;
          }
        }
        if ( (v247 & 1) == 0 && (*(_DWORD *)(v12 + 188) & 0x400) != 0 )
          goto LABEL_623;
        if ( (v247 & 1) == 0 )
          goto LABEL_628;
        __dmb(0xBu);
        v263 = (unsigned int *)(v12 + 188);
        do
          v264 = __ldrex(v263);
        while ( __strex(v264 | 0x400, v263) );
LABEL_627:
        __dmb(0xBu);
LABEL_628:
        v11 = 0;
        goto LABEL_673;
      case 3:
        if ( (v247 & 0xFFFFFFFC) != 0 )
        {
          v11 = -1073741811;
        }
        else
        {
          v256 = (v247 >> 1) & 1;
          if ( v256 || (v247 & 1) == 0 )
          {
            if ( !v256 || (v247 & 1) != 0 )
            {
              v257 = ObReferenceProcessHandleTable(v12);
              if ( v257 )
              {
                if ( ExEnableHandleExceptions(v257, (v247 & 1) != 0) )
                  v11 = 0;
                else
                  v11 = -1073741790;
                ObDereferenceProcessHandleTable(v12);
              }
              else
              {
                v11 = -1073741558;
              }
            }
            else
            {
              v11 = -1073741811;
            }
          }
          else
          {
            v11 = -1073741811;
          }
        }
        goto LABEL_673;
      case 4:
        if ( (v247 & 0xFFFFFFFE) != 0 )
        {
          v11 = -1073741811;
        }
        else if ( (v247 & 1) != 0 || *(int *)(v12 + 188) >= 0 )
        {
          v11 = 0;
          if ( (v247 & 1) != 0 )
          {
            __dmb(0xBu);
            v258 = (unsigned int *)(v12 + 188);
            do
              v259 = __ldrex(v258);
            while ( __strex(v259 | 0x80000000, v258) );
            __dmb(0xBu);
            if ( (*(_DWORD *)(v8 + 80) & 0x40) != 0 )
              v11 = -1073741431;
          }
        }
        else
        {
          v11 = -1073741790;
        }
        goto LABEL_673;
      case 6:
        if ( (v247 & 0xFFFFFFFE) != 0 )
        {
          v11 = -1073741811;
        }
        else if ( (v247 & 1) != 0 || (*(_DWORD *)(v12 + 188) & 0x4000000) == 0 )
        {
          v11 = 0;
          if ( (v247 & 1) != 0 )
          {
            __dmb(0xBu);
            v265 = (unsigned int *)(v12 + 188);
            do
              v266 = __ldrex(v265);
            while ( __strex(v266 | 0x4000000, v265) );
            goto LABEL_671;
          }
        }
        else
        {
          v11 = -1073741790;
        }
        goto LABEL_673;
      case 7:
        if ( (v247 & 0xFFFFFFFE) != 0 )
          v11 = -1073741811;
        else
LABEL_623:
          v11 = -1073741790;
        goto LABEL_673;
      case 8:
        if ( (v247 & 0xFFFFFFFE) != 0 )
        {
          v11 = -1073741811;
        }
        else
        {
          if ( (v247 & 1) != 0 )
            goto LABEL_646;
          if ( *(unsigned __int8 *)(v12 + 732) >= 8u )
          {
LABEL_563:
            v11 = -1073741790;
            goto LABEL_673;
          }
          if ( *(unsigned __int8 *)(v12 + 733) < 8u )
          {
LABEL_646:
            v11 = 0;
            if ( (v247 & 1) != 0 )
            {
              if ( *(unsigned __int8 *)(v12 + 732) < 8u )
                *(_BYTE *)(v12 + 732) = 8;
              if ( *(unsigned __int8 *)(v12 + 733) < 8u )
                *(_BYTE *)(v12 + 733) = 8;
            }
          }
          else
          {
            v11 = -1073741790;
          }
        }
        goto LABEL_673;
      case 9:
        if ( (v247 & 0xFFFFFFFC) != 0 )
        {
          v11 = -1073741811;
          goto LABEL_673;
        }
        if ( (v247 & 1) == 0 && (*(_DWORD *)(v12 + 736) & 4) != 0 )
        {
          v11 = -1073741790;
          goto LABEL_673;
        }
        if ( (v247 & 1) == 0 && (v247 & 2) == 0 && (*(_DWORD *)(v12 + 736) & 8) != 0 )
        {
          v11 = -1073741790;
          goto LABEL_673;
        }
        v11 = 0;
        if ( (v247 & 1) != 0 )
        {
          __dmb(0xBu);
          v267 = (unsigned int *)(v12 + 736);
          do
            v268 = __ldrex(v267);
          while ( __strex(v268 | 4, v267) );
          __dmb(0xBu);
          do
            v269 = __ldrex(v267);
          while ( __strex(v269 & 0xFFFFFFF7, v267) );
        }
        else
        {
          if ( (v247 & 2) == 0 )
            goto LABEL_673;
          __dmb(0xBu);
          v270 = (unsigned int *)(v12 + 736);
          do
            v271 = __ldrex(v270);
          while ( __strex(v271 | 8, v270) );
          __dmb(0xBu);
          do
            v272 = __ldrex(v270);
          while ( __strex(v272 & 0xFFFFFFFB, v270) );
        }
LABEL_671:
        __dmb(0xBu);
        goto LABEL_673;
      default:
LABEL_672:
        v11 = -1073741637;
        goto LABEL_673;
    }
  }
  if ( a4 != 4 )
    return -1073741820;
  v293 = *v5;
  v360 = v293;
  v11 = ObReferenceObjectByHandleWithTag(a1, 512, PsProcessType, v303, 2035381072, &v304, 0);
  if ( v11 >= 0 )
  {
    --*(_WORD *)(v8 + 308);
    v294 = v304;
    v295 = (unsigned __int8 *)(v304 + 168);
    v296 = KeAbPreAcquire(v304 + 168, 0, 0);
    v297 = v296;
    do
      v298 = __ldrex(v295);
    while ( __strex(v298 | 1, v295) );
    __dmb(0xBu);
    if ( (v298 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(v294 + 168), v296, v294 + 168);
    if ( v297 )
      *(_BYTE *)(v297 + 14) |= 1u;
    if ( *(_DWORD *)(v294 + 412) != v293 )
    {
      *(_DWORD *)(v294 + 412) = v293;
      KeSetAutoAlignmentProcess(v294, (v293 & 4) != 0);
    }
    __dmb(0xBu);
    do
      v299 = __ldrex((unsigned int *)v295);
    while ( __strex(v299 - 1, (unsigned int *)v295) );
    if ( (v299 & 2) != 0 && (v299 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)(v294 + 168));
    v300 = KeAbPostRelease(v294 + 168);
    v301 = *(_WORD *)(v8 + 308) + 1;
    *(_WORD *)(v8 + 308) = v301;
    if ( !v301 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      KiCheckForKernelApcDelivery(v300);
    ObfDereferenceObjectWithTag(v294);
    v11 = 0;
  }
  return v11;
}
