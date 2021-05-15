// NtQueryInformationProcess 
 
int __fastcall NtQueryInformationProcess(int a1, int a2, int a3, unsigned int a4, unsigned int *a5)
{
  BOOL *v6; // r8
  int v8; // lr
  int v9; // r3
  unsigned int v10; // r3
  unsigned int v11; // r2
  int *v12; // r9
  int v13; // r9
  unsigned int v14; // r3
  int v15; // r5
  unsigned int v16; // r4
  unsigned int v17; // r6
  _DWORD *v18; // r5
  int v19; // r0
  _DWORD *v20; // r6
  int v21; // r1
  int v22; // r2
  unsigned int v23; // r2
  int v24; // r8
  int v25; // r2
  int v26; // r5
  int v27; // r4
  int v28; // r5
  int v29; // r1
  int v30; // r2
  int v31; // r3
  _DWORD *v32; // r8
  int v33; // r1
  int v34; // r2
  int v35; // r3
  int v36; // r1
  int v37; // r2
  int v38; // r3
  _DWORD *v39; // r4
  int v40; // r3
  int v41; // r1
  unsigned int v42; // r1
  _DWORD *v43; // r5
  int v44; // r0
  int v45; // r1
  int v46; // r3
  int v47; // r4
  _DWORD *v48; // r0
  int v49; // r6
  int v50; // r5
  BOOL v51; // r6
  BOOL v52; // r6
  int v53; // r6
  int v54; // r5
  BOOL v55; // r5
  int v56; // r0
  int v57; // r4
  unsigned int v58; // r1
  unsigned int v59; // r0
  int v60; // r2
  unsigned int v61; // r1
  char *v62; // r6
  int *v63; // r6
  int v64; // r0
  int v65; // r2
  int v66; // r3
  int v67; // r4
  int v68; // r0
  int v69; // r1
  int v70; // r2
  int v71; // r3
  int v72; // r0
  int v73; // r1
  int v74; // r2
  int v75; // r3
  int v76; // r0
  int v77; // r1
  int v78; // r2
  int v79; // r3
  int v80; // r1
  int v81; // r2
  int v82; // r3
  int v83; // r1
  int v84; // r2
  int v85; // r3
  _DWORD *v86; // r6
  int v87; // r1
  int v88; // r2
  int v89; // r3
  int v90; // r1
  int v91; // r2
  int v92; // r3
  int v93; // r1
  int v94; // r2
  int v95; // r3
  int v96; // r1
  int v97; // r2
  int v98; // r3
  _DWORD *v99; // r3
  _DWORD *v100; // r4
  int v101; // r3
  int v102; // r0
  _DWORD *v103; // r4
  int v104; // r0
  int v105; // r1
  int v106; // r3
  int v107; // r0
  unsigned int *v108; // r2
  unsigned int v109; // r1
  _DWORD *v110; // r6
  unsigned int *v111; // lr
  unsigned int v112; // r0
  unsigned int v113; // r1
  int v114; // r4
  int v115; // r0
  unsigned int v116; // r4
  unsigned int v117; // r1
  int v118; // r3
  int v119; // r3
  _DWORD *v120; // r6
  int v121; // r4
  int v122; // r5
  int v123; // r3
  _DWORD *v124; // r6
  unsigned int v125; // r2
  int v126; // r3
  unsigned int v127; // r6
  int v128; // r0
  int v129; // r3
  int v130; // r4
  int v131; // r5
  _DWORD *v132; // r9
  unsigned int *v133; // r0
  unsigned int v134; // r4
  unsigned int v135; // r1
  _DWORD *v136; // r5
  int v137; // r0
  _DWORD *v138; // r3
  unsigned int *v139; // r2
  int v140; // r4
  int v141; // r1
  unsigned int v142; // r3
  int v143; // r0
  int v144; // r2
  unsigned int *v145; // r0
  unsigned int v146; // r4
  unsigned int v147; // r1
  int v148; // r4
  int v149; // r0
  __int16 v150; // r3
  int v151; // r10
  _DWORD *v152; // r5
  int v153; // r3
  int v154; // r3
  int v155; // r3
  int v156; // r3
  int v157; // r0
  int v158; // r3
  int v159; // r3
  int v160; // r3
  int v161; // r3
  int v162; // r3
  int v163; // r3
  int v164; // r3
  int v165; // r3
  int v166; // r3
  _DWORD *v167; // r5
  int v168; // r0
  BOOL v169; // r3
  int v170; // r0
  _DWORD *v171; // r4
  _DWORD *v172; // r4
  _DWORD *v173; // r10
  unsigned int v174; // r2
  int v175; // r3
  unsigned int v176; // r2
  int v177; // r3
  int v178; // r0
  int v179; // r2
  int v180; // r4
  unsigned int v181; // r2
  _DWORD *v183; // [sp+10h] [bp-328h] BYREF
  int v184; // [sp+14h] [bp-324h]
  char v185; // [sp+18h] [bp-320h]
  _DWORD v186[2]; // [sp+1Ch] [bp-31Ch] BYREF
  int v187; // [sp+24h] [bp-314h] BYREF
  BOOL *v188; // [sp+28h] [bp-310h]
  int v189; // [sp+2Ch] [bp-30Ch]
  unsigned int v190; // [sp+30h] [bp-308h] BYREF
  unsigned int v191; // [sp+34h] [bp-304h] BYREF
  int v192; // [sp+38h] [bp-300h]
  int v193; // [sp+3Ch] [bp-2FCh]
  BOOL *v194; // [sp+40h] [bp-2F8h] BYREF
  int v195; // [sp+44h] [bp-2F4h] BYREF
  char v196[8]; // [sp+48h] [bp-2F0h] BYREF
  _DWORD *v197; // [sp+50h] [bp-2E8h]
  int v198; // [sp+54h] [bp-2E4h]
  int v199; // [sp+58h] [bp-2E0h] BYREF
  int v200; // [sp+5Ch] [bp-2DCh]
  int v201; // [sp+60h] [bp-2D8h] BYREF
  unsigned __int64 v202; // [sp+68h] [bp-2D0h]
  unsigned int v203; // [sp+70h] [bp-2C8h] BYREF
  char v204; // [sp+74h] [bp-2C4h]
  unsigned int v205; // [sp+78h] [bp-2C0h] BYREF
  int v206; // [sp+80h] [bp-2B8h]
  unsigned int v207; // [sp+84h] [bp-2B4h]
  int v208; // [sp+88h] [bp-2B0h] BYREF
  unsigned int v209; // [sp+8Ch] [bp-2ACh]
  int v210; // [sp+90h] [bp-2A8h]
  int v211; // [sp+98h] [bp-2A0h] BYREF
  int v212; // [sp+9Ch] [bp-29Ch]
  int v213; // [sp+A0h] [bp-298h]
  int v214; // [sp+A4h] [bp-294h]
  int v215; // [sp+A8h] [bp-290h]
  int v216; // [sp+ACh] [bp-28Ch]
  int v217; // [sp+B0h] [bp-288h]
  int v218; // [sp+B4h] [bp-284h]
  int v219; // [sp+B8h] [bp-280h]
  int v220; // [sp+BCh] [bp-27Ch]
  int v221; // [sp+C0h] [bp-278h]
  int v222; // [sp+C4h] [bp-274h]
  int v223; // [sp+C8h] [bp-270h] BYREF
  unsigned int v224; // [sp+CCh] [bp-26Ch]
  int v225; // [sp+D0h] [bp-268h]
  int v226; // [sp+D4h] [bp-264h] BYREF
  int v227; // [sp+D8h] [bp-260h]
  BOOL *v228; // [sp+DCh] [bp-25Ch]
  int v229; // [sp+E0h] [bp-258h]
  char v230[4]; // [sp+E4h] [bp-254h] BYREF
  _DWORD *v231; // [sp+E8h] [bp-250h] BYREF
  _DWORD v232[3]; // [sp+ECh] [bp-24Ch] BYREF
  _DWORD v233[2]; // [sp+F8h] [bp-240h] BYREF
  _DWORD v234[2]; // [sp+100h] [bp-238h] BYREF
  _DWORD v235[3]; // [sp+108h] [bp-230h] BYREF
  int v236; // [sp+114h] [bp-224h] BYREF
  _DWORD v237[5]; // [sp+118h] [bp-220h] BYREF
  int v238; // [sp+12Ch] [bp-20Ch]
  int v239; // [sp+130h] [bp-208h]
  int v240; // [sp+134h] [bp-204h]
  int v241; // [sp+138h] [bp-200h] BYREF
  unsigned __int64 v242; // [sp+140h] [bp-1F8h]
  unsigned int v243; // [sp+148h] [bp-1F0h]
  int v244; // [sp+14Ch] [bp-1ECh]
  int v245; // [sp+150h] [bp-1E8h]
  _DWORD v246[2]; // [sp+158h] [bp-1E0h] BYREF
  int v247; // [sp+160h] [bp-1D8h] BYREF
  int v248; // [sp+164h] [bp-1D4h] BYREF
  _DWORD v249[3]; // [sp+168h] [bp-1D0h] BYREF
  int v250; // [sp+174h] [bp-1C4h] BYREF
  int v251; // [sp+178h] [bp-1C0h]
  _DWORD v252[20]; // [sp+180h] [bp-1B8h] BYREF
  int v253; // [sp+1D0h] [bp-168h] BYREF
  int v254; // [sp+1D8h] [bp-160h]
  int v255; // [sp+1DCh] [bp-15Ch]
  int v256; // [sp+1E0h] [bp-158h]
  int v257; // [sp+1E4h] [bp-154h]
  int v258; // [sp+1E8h] [bp-150h]
  int v259; // [sp+1ECh] [bp-14Ch]
  int v260; // [sp+1F0h] [bp-148h]
  int v261; // [sp+1F4h] [bp-144h]
  int v262; // [sp+1F8h] [bp-140h]
  int v263; // [sp+1FCh] [bp-13Ch]
  int v264; // [sp+200h] [bp-138h]
  int v265; // [sp+204h] [bp-134h]
  int v266; // [sp+208h] [bp-130h]
  int v267; // [sp+20Ch] [bp-12Ch]
  int v268; // [sp+210h] [bp-128h]
  int v269; // [sp+214h] [bp-124h]
  int v270; // [sp+218h] [bp-120h]
  int v271; // [sp+21Ch] [bp-11Ch]
  int v272; // [sp+220h] [bp-118h]
  int v273; // [sp+224h] [bp-114h]
  int v274; // [sp+228h] [bp-110h]
  int v275; // [sp+22Ch] [bp-10Ch]
  int v276; // [sp+230h] [bp-108h]
  int v277; // [sp+234h] [bp-104h]
  int v278; // [sp+238h] [bp-100h]
  int v279; // [sp+23Ch] [bp-FCh]
  _DWORD v280[4]; // [sp+250h] [bp-E8h] BYREF
  _DWORD v281[4]; // [sp+260h] [bp-D8h] BYREF
  _BYTE v282[24]; // [sp+270h] [bp-C8h] BYREF
  _BYTE v283[40]; // [sp+288h] [bp-B0h] BYREF
  int v284; // [sp+2B0h] [bp-88h]
  int v285; // [sp+304h] [bp-34h]
  int v286; // [sp+310h] [bp-28h]
  int varg_r0; // [sp+340h] [bp+8h]
  int varg_r1; // [sp+344h] [bp+Ch]
  int varg_r2; // [sp+348h] [bp+10h]
  unsigned int varg_r3; // [sp+34Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = (BOOL *)a3;
  varg_r1 = a2;
  v189 = a1;
  v186[1] = a1;
  v192 = a3;
  v197 = a5;
  v8 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v193 = v8;
  v185 = v8;
  v190 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v191 = v190;
  if ( v8 )
  {
    if ( a2 == 61 )
    {
      v9 = 1;
    }
    else if ( a2 == 65 || a2 != 70 )
    {
      v9 = 4;
    }
    else
    {
      v9 = 1;
    }
    v188 = (BOOL *)v9;
    if ( a4 )
    {
      if ( ((v9 - 1) & a3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v10 = a3 + a4;
      v11 = MmUserProbeAddress;
      if ( (unsigned int)v6 + a4 > MmUserProbeAddress || v10 < (unsigned int)v6 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v11 = MmUserProbeAddress;
      }
    }
    else
    {
      v11 = MmUserProbeAddress;
    }
    if ( a5 )
    {
      v12 = (int *)a5;
      if ( (unsigned int)a5 >= v11 )
        v12 = (int *)v11;
      v251 = *v12;
      *v12 = v251;
    }
  }
  switch ( a2 )
  {
    case 0:
      if ( a4 == 32 )
      {
        v194 = v6;
        v188 = v6;
        *v6++ = 32;
        v192 = 32;
        v187 = 32;
      }
      else
      {
        if ( a4 != 24 )
          goto LABEL_365;
        v194 = 0;
        v188 = 0;
        v192 = 24;
        v187 = 24;
      }
      v186[0] = v6;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v13;
      if ( v13 < 0 )
        return v13;
      v20 = v183;
      *v6 = v183[158];
      v6[1] = v20[80];
      v195 = KeQueryGroupMaskProcess((int)v20);
      if ( ((v195 - 1) & v195) != 0 && v20 != *(_DWORD **)(v22 + 336) )
        goto LABEL_62;
      KeQueryAffinityProcess((int)v20, v280, &v195, 0);
      if ( ((v195 - 1) & v195) != 0 )
      {
        if ( v20 != *(_DWORD **)(v190 + 336)
          || (v23 = *(unsigned __int16 *)(v190 + 344), v200 = v23, ((1 << v23) & v195) == 0) )
        {
          v200 = 1;
          goto LABEL_61;
        }
      }
      else
      {
        v23 = __clz(__rbit(v195));
        v200 = v23;
      }
      if ( v23 != 1 )
      {
        v21 = v280[v23 + 2];
        goto LABEL_62;
      }
LABEL_61:
      v21 = 0;
LABEL_62:
      v6[2] = v21;
      v6[3] = *((char *)v20 + 104);
      v6[4] = v20[44];
      v6[5] = v20[78];
      v24 = (int)v194;
      if ( v194 )
      {
        v194[7] = 0;
        LOBYTE(v190) = *((_BYTE *)v20 + 734);
        if ( (v190 & 7) != 0 )
          *(_DWORD *)(v24 + 28) = 1;
        v25 = v20[48];
        __dmb(0xBu);
        if ( (v25 & 0x40000008) != 0 )
          *(_DWORD *)(v24 + 28) |= 4u;
        v20 = v183;
        *(_DWORD *)(v24 + 28) ^= ((unsigned __int8)*(_DWORD *)(v24 + 28) ^ (unsigned __int8)(8 * ((v183[47] & 0x80) != 0))) & 8;
        if ( v20[37] + ((v20[25] >> 3) & 1) )
          *(_DWORD *)(v24 + 28) |= 0x10u;
        *(_DWORD *)(v24 + 28) ^= ((unsigned __int8)*(_DWORD *)(v24 + 28) ^ (unsigned __int8)(32
                                                                                           * ((v20[48] & 0x100000) != 0))) & 0x20;
        v26 = PsReferencePrimaryToken(v20);
        v27 = SeSecurityAttributePresent(v26, (int)&PspSysAppIdClaim);
        v204 = v27;
        ObFastDereferenceObject(v20 + 61, v26);
        if ( v27 )
          *(_DWORD *)(v24 + 28) |= 0x40u;
        v13 = v184;
      }
      if ( a5 )
        *a5 = v192;
      ObfDereferenceObjectWithTag((int)v20);
      return v13;
    case 1:
      return PspQueryQuotaLimits(a1, 0);
    case 2:
      if ( a4 != 48 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        PsQueryStatisticsProcess((int)v183, (int)v252);
        v211 = v252[8];
        v212 = v252[9];
        v213 = v252[10];
        v214 = v252[11];
        v215 = v252[12];
        v216 = v252[13];
        v217 = v252[14];
        v218 = v252[15];
        v219 = v252[16];
        v220 = v252[17];
        v221 = v252[18];
        v222 = v252[19];
        ObfDereferenceObjectWithTag((int)v183);
        v29 = v212;
        v30 = v213;
        v31 = v214;
        *v6 = v211;
        v6[1] = v29;
        v6[2] = v30;
        v6[3] = v31;
        v32 = v6 + 4;
        v33 = v216;
        v34 = v217;
        v35 = v218;
        *v32 = v215;
        v32[1] = v33;
        v32[2] = v34;
        v32[3] = v35;
        v32 += 4;
        v36 = v220;
        v37 = v221;
        v38 = v222;
        *v32 = v219;
        v32[1] = v36;
        v32[2] = v37;
        v32[3] = v38;
        if ( a5 )
          *a5 = 48;
      }
      return v13;
    case 3:
      if ( a4 != 44 && a4 != 48 && a4 != 64 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v39 = v183;
      v235[0] = v183[56];
      v235[1] = v183[57];
      v235[2] = v183[148];
      KiStackAttachProcess((int)v183, 0, (int)v282);
      v184 = MmQueryWorkingSetInformation(&v236, v237, &v241, &v250, &v248, v249);
      KiUnstackDetachProcess((unsigned int)v282, 0);
      v237[2] = v39[53];
      __dmb(0xBu);
      v237[1] = v183[55];
      __dmb(0xBu);
      v237[4] = v183[52];
      __dmb(0xBu);
      v237[3] = v183[54];
      __dmb(0xBu);
      v40 = v183[121];
      __dmb(0xBu);
      v238 = v40 << 12;
      v41 = v183[122];
      __dmb(0xBu);
      v239 = v41 << 12;
      v42 = v183[216];
      __dmb(0xBu);
      v242 = (unsigned __int64)v42 << 12;
      v240 = v238;
      ObfDereferenceObjectWithTag((int)v183);
      if ( v184 >= 0 )
      {
        memmove((int)v6, (int)v235, a4);
        if ( a5 )
          *a5 = a4;
        return 0;
      }
      return v184;
    case 4:
      if ( a4 != 32 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        v43 = v183;
        v44 = PsQueryRuntimeProcess(v183, &v205);
        v45 = KeMaximumIncrement;
        *((_QWORD *)v6 + 2) = (unsigned int)v44 * (unsigned __int64)(unsigned int)KeMaximumIncrement;
        *((_QWORD *)v6 + 3) = v205 * (unsigned __int64)(unsigned int)v45;
        *v6 = v43[50];
        v6[1] = v43[51];
        v6[2] = v43[174];
        v6[3] = v43[175];
        if ( a5 )
          *a5 = 32;
        goto LABEL_203;
      }
      return v13;
    case 7:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      if ( v183[85] )
        v46 = -1;
      else
        v46 = 0;
      v199 = v46;
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v199;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 10:
      v13 = ObReferenceObjectByHandleWithTag(a1, 1040, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        v13 = xKdEnumerateDebuggingDevices();
        ObfDereferenceObjectWithTag((int)v183);
      }
      return v13;
    case 12:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v28 = v183[103];
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v28;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 14:
      return PspQueryPooledQuotaLimits(a1);
    case 15:
    case 42:
      return PspQueryWorkingSetWatch(a1, a2);
    case 18:
      if ( a4 != 2 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      LOBYTE(v190) = 0;
      BYTE1(v190) = *((_BYTE *)v183 + 375);
      ObfDereferenceObjectWithTag((int)v183);
      *(_WORD *)v6 = v190;
      if ( a5 )
        *a5 = 2;
      return 0;
    case 19:
      if ( a4 != 4 )
        goto LABEL_365;
      v50 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v50;
      if ( v50 >= 0 )
      {
        v51 = (v183[48] & 0x1000000) != 0;
        ObfDereferenceObjectWithTag((int)v183);
        *v6 = v51;
        if ( a5 )
          *a5 = 4;
      }
      return v50;
    case 20:
      if ( a4 != 4 && a4 != 8 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v49 = ObGetProcessHandleCount(v183, &v203);
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v49;
      if ( a4 != 4 )
        v6[1] = v203;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 21:
      if ( a4 != 4 && a4 != 12 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v124 = v183;
      v195 = KeQueryGroupMaskProcess((int)v183);
      if ( ((v195 - 1) & v195) != 0 || (KeQueryAffinityProcess((int)v124, v281, &v195, 0), ((v195 - 1) & v195) != 0) )
      {
        v13 = -1073741811;
      }
      else
      {
        v125 = __clz(__rbit(v195));
        v200 = v125;
        v126 = v281[v125 + 2];
        if ( a4 == 12 )
          *((_WORD *)v6 + 2) = v125;
        *v6 = v126;
        if ( a5 )
          *a5 = a4;
      }
      v48 = v124;
      goto LABEL_51;
    case 22:
      if ( a4 != 4 )
        goto LABEL_365;
      v50 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v50;
      if ( v50 >= 0 )
      {
        v52 = (v183[25] & 2) != 0;
        ObfDereferenceObjectWithTag((int)v183);
        *v6 = v52;
        if ( a5 )
          *a5 = 4;
      }
      return v50;
    case 23:
      if ( a4 < 0x24 )
        goto LABEL_365;
      if ( a4 == 40 )
      {
        v188 = (BOOL *)v6[9];
        v228 = v188;
        if ( ((unsigned int)v188 & 0xFFFFFFFE) != 0 )
          return -1073741811;
      }
      else
      {
        if ( a4 != 36 )
          goto LABEL_365;
        v188 = 0;
      }
      v19 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v53 = ObQueryDeviceMapInformation(v183, v6, v188);
      v184 = v53;
      ObfDereferenceObjectWithTag((int)v183);
      if ( v53 >= 0 && a5 )
        *a5 = a4;
      return v53;
    case 24:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v54 = MmGetSessionId((int)v183);
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v54;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 26:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = 0;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 27:
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        if ( a4 >= 8 )
        {
          v14 = a4 - 8;
          v15 = (int)(v6 + 2);
        }
        else
        {
          v14 = 0;
          v6 = &v253;
          v15 = 0;
        }
        v191 = v14;
        v13 = PsQueryFullProcessImageName((int)v183, v6, v15, &v191);
        ObfDereferenceObjectWithTag((int)v183);
        if ( v13 >= 0 && !v15 )
          v13 = -1073741820;
        if ( a5 && (v13 >= 0 || v13 == -1073741820) )
          *a5 = v191 + 8;
      }
      return v13;
    case 28:
      if ( a4 != 4 )
        goto LABEL_365;
      *v6 = 1;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 29:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v55 = (v183[48] & 0x2000) != 0;
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v55;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 30:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v47 = DbgkOpenProcessDebugPort(v183, v193, &v199);
      v184 = v47;
      if ( v47 < 0 )
        v199 = 0;
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v199;
      if ( a5 )
        *a5 = 4;
      return v47;
    case 31:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      *v6 = (v183[48] & 2) == 0;
      if ( a5 )
        *a5 = 4;
      goto LABEL_51;
    case 32:
      if ( a4 < 8 )
        goto LABEL_365;
      if ( ExIsRestrictedCaller(v8, 0) )
        return -1073741790;
      v186[0] = (a4 - 8) / 0x50;
      v197 = v6 + 2;
      v13 = ObReferenceObjectByHandleWithTag(v189, 1024, PsProcessType, v193, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v203 = ObReferenceProcessHandleTable(v183);
      v205 = v203;
      if ( v203 )
      {
        v56 = ExReferenceHandleDebugInfo();
        v57 = v56;
        v187 = v56;
        v201 = v56;
        if ( !v56 )
        {
          v13 = -1073741811;
          v43 = v183;
LABEL_201:
          ObDereferenceProcessHandleTable(v43);
          goto LABEL_203;
        }
        v6[1] = 0;
        v58 = *(_DWORD *)(v56 + 44);
        v59 = *(_DWORD *)(v56 + 4);
        if ( !v59 )
          __brkdiv0();
        v60 = v58 % v59;
        v188 = (BOOL *)(v58 % v59);
        v209 = v58 % v59;
        v61 = 0;
        v227 = 0;
        v62 = (char *)(v6 + 2);
        while ( 1 )
        {
          v191 = v61;
          if ( v61 >= *(_DWORD *)(v57 + 4) )
          {
            if ( a5 )
              *a5 = v62 - (char *)v6;
            v43 = v183;
            ExDereferenceHandleDebugInfo(v203, v57);
            goto LABEL_201;
          }
          v63 = (int *)(v57 + 80 * v60 + 48);
          v64 = *v63;
          v65 = *(_DWORD *)(v57 + 80 * v60 + 52);
          v66 = v63[2];
          v67 = v63[3];
          v63 += 4;
          v254 = v64;
          v255 = v65;
          v256 = v66;
          v257 = v67;
          v68 = *v63;
          v69 = v63[1];
          v70 = v63[2];
          v71 = v63[3];
          v63 += 4;
          v258 = v68;
          v259 = v69;
          v260 = v70;
          v261 = v71;
          v72 = *v63;
          v73 = v63[1];
          v74 = v63[2];
          v75 = v63[3];
          v63 += 4;
          v262 = v72;
          v263 = v73;
          v264 = v74;
          v265 = v75;
          v76 = *v63;
          v77 = v63[1];
          v78 = v63[2];
          v79 = v63[3];
          v63 += 4;
          v266 = v76;
          v267 = v77;
          v268 = v78;
          v269 = v79;
          v80 = v63[1];
          v81 = v63[2];
          v82 = v63[3];
          v270 = *v63;
          v271 = v80;
          v272 = v81;
          v273 = v82;
          v83 = v256;
          if ( *v6 == v256 || !*v6 )
          {
            v84 = v257;
            if ( v257 )
            {
              ++v6[1];
              v85 = v186[0];
              if ( v186[0] )
              {
                --v186[0];
                v245 = v85 - 1;
                v86 = v197;
                *v197 = v83;
                v86[1] = v254;
                v86[2] = v255;
                v86[3] = v84;
                v87 = v259;
                v88 = v260;
                v89 = v261;
                v86[4] = v258;
                v86[5] = v87;
                v86[6] = v88;
                v86[7] = v89;
                v90 = v263;
                v91 = v264;
                v92 = v265;
                v86[8] = v262;
                v86[9] = v90;
                v86[10] = v91;
                v86[11] = v92;
                v93 = v267;
                v94 = v268;
                v95 = v269;
                v86[12] = v266;
                v86[13] = v93;
                v86[14] = v94;
                v86[15] = v95;
                v96 = v271;
                v97 = v272;
                v98 = v273;
                v86[16] = v270;
                v86[17] = v96;
                v86[18] = v97;
                v86[19] = v98;
                v62 = (char *)(v86 + 20);
                v197 = v62;
                v249[2] = v62;
                goto LABEL_193;
              }
              v13 = -1073741820;
              v184 = -1073741820;
            }
          }
          v62 = (char *)v197;
LABEL_193:
          if ( v188 )
          {
            v60 = (int)v188 - 1;
            v209 = (unsigned int)v188 - 1;
            v57 = v187;
          }
          else
          {
            v57 = v187;
            v60 = *(_DWORD *)(v187 + 4) - 1;
            v209 = v60;
          }
          v188 = (BOOL *)v60;
          v61 = v191 + 1;
          v227 = v191 + 1;
        }
      }
      v13 = -1073741558;
      v43 = v183;
LABEL_203:
      ObfDereferenceObjectWithTag((int)v43);
      return v13;
    case 33:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v13;
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      v118 = (v183[48] >> 27) & 7;
      __dmb(0xBu);
      *v6 = v118;
      if ( a5 )
        *a5 = 4;
      goto LABEL_51;
    case 34:
      if ( a4 != 4 )
        goto LABEL_365;
      if ( a1 == -1 )
      {
        v99 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      }
      else
      {
        v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
        if ( v13 < 0 )
          return v13;
        v99 = v183;
        a1 = v189;
      }
      if ( a1 == -1 )
        return -1073741811;
      ObfDereferenceObjectWithTag((int)v99);
      return -1073741811;
    case 36:
      if ( a4 != 4 )
        goto LABEL_365;
      if ( a1 == -1 )
      {
        v100 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v183 = v100;
      }
      else
      {
        v13 = ObReferenceObjectByHandle(a1, 32, PsProcessType, v8, &v231, 0);
        v100 = v231;
        v183 = v231;
        if ( v13 < 0 )
          return v13;
        a1 = v189;
      }
      v13 = 0;
      v184 = 0;
      while ( 1 )
      {
        v101 = v100[75];
        if ( v101 )
          break;
        KeQuerySystemTime(v233);
        v103 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
        v104 = ReadTimeStampCounter();
        v198 = v105;
        v106 = v103[738];
        __dmb(0xBu);
        v107 = v104 ^ v106 ^ v103[932] ^ v103[928] ^ v103[748] ^ v233[1] ^ v233[0];
        __dmb(0xBu);
        v100 = v183;
        v108 = v183 + 75;
        do
          v109 = __ldrex(v108);
        while ( !v109 && __strex(v107, v108) );
        __dmb(0xBu);
        v13 = v184;
        a1 = v189;
      }
      *v6 = v101;
      if ( a5 )
        *a5 = 4;
      if ( a1 != -1 )
      {
        v102 = (int)v100;
LABEL_222:
        ObfDereferenceObject(v102);
      }
      return v13;
    case 37:
      if ( a4 != 48 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v110 = v183;
      if ( v183 == *(_DWORD **)(v190 + 336) )
      {
        v114 = v183[73];
        if ( !v114 )
          v13 = -1073741558;
        v187 = 0;
      }
      else
      {
        v187 = 1;
        v111 = v183 + 43;
        __pld(v183 + 43);
        v112 = v183[43] & 0xFFFFFFFE;
        do
          v113 = __ldrex(v111);
        while ( v113 == v112 && __strex(v112 + 2, v111) );
        __dmb(0xBu);
        if ( v113 != v112 )
        {
          if ( !ExfAcquireRundownProtection(v110 + 43) )
          {
            v13 = -1073741558;
            v114 = 0;
            goto LABEL_249;
          }
          v111 = v110 + 43;
        }
        v115 = v110[73];
        v186[0] = v115;
        if ( v115 )
        {
          ObfReferenceObject(v115);
          v111 = v110 + 43;
        }
        else
        {
          v13 = -1073741811;
        }
        __pld(v111);
        v116 = *v111 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v117 = __ldrex(v111);
        while ( v117 == v116 && __strex(v116 - 2, v111) );
        if ( v117 != v116 )
          ExfReleaseRundownProtection((unsigned __int8 *)v111);
        v114 = v186[0];
      }
LABEL_249:
      ObfDereferenceObjectWithTag((int)v110);
      if ( v13 >= 0 )
      {
        v13 = MmGetSectionInformation(v114, 1, v6);
        if ( v187 )
          ObfDereferenceObject(v114);
        if ( v13 >= 0 && a5 )
          *a5 = 48;
      }
      return v13;
    case 38:
      if ( a4 != 16 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v43 = v183;
      *(_QWORD *)v6 = PsQueryTotalCycleTimeProcess(v183, v234);
      v6[2] = v234[0];
      v6[3] = v234[1];
      if ( a5 )
        *a5 = 16;
      goto LABEL_203;
    case 39:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      *v6 = (v183[47] >> 12) & 7;
      if ( a5 )
        *a5 = 4;
      goto LABEL_51;
    case 43:
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        v13 = PsReferenceProcessFilePointer(v183, &v194);
        ObfDereferenceObjectWithTag((int)v183);
        if ( v13 >= 0 )
        {
          v13 = IoQueryFileDosDeviceName(v194, v186);
          ObfDereferenceObject((int)v194);
          if ( v13 >= 0 )
          {
            v16 = v186[0];
            v17 = *(unsigned __int16 *)(v186[0] + 2) + 8;
            if ( v17 <= a4 )
            {
              *(_WORD *)v6 = *(_WORD *)v186[0];
              *((_WORD *)v6 + 1) = *(_WORD *)(v16 + 2);
              if ( *(_WORD *)(v16 + 2) )
              {
                v18 = v6 + 2;
                memmove((int)(v6 + 2), *(_DWORD *)(v16 + 4), *(unsigned __int16 *)(v16 + 2));
              }
              else
              {
                v18 = 0;
              }
              v6[1] = (BOOL)v18;
            }
            else
            {
              v13 = -1073741820;
              v184 = -1073741820;
            }
            if ( a5 )
              *a5 = v17;
            ExFreePoolWithTag(v16);
          }
        }
      }
      return v13;
    case 44:
      if ( a4 != 4 )
        goto LABEL_365;
      v186[0] = *v6;
      v232[1] = v186[0];
      v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v13 = ObReferenceObjectByHandleWithTag(v186[0], 1048608, IoFileObjectType, v193, 2035381072, &v194, 0);
      v48 = v183;
      if ( v13 < 0 )
        goto LABEL_51;
      v13 = PsReferenceProcessFilePointer(v183, &v226);
      ObfDereferenceObjectWithTag((int)v183);
      v102 = (int)v194;
      if ( v13 < 0 )
        goto LABEL_222;
      v121 = v226;
      if ( v194[5] == *(_DWORD *)(v226 + 20) )
        v13 = 0;
      else
        v13 = -1073741823;
      ObfDereferenceObject((int)v194);
      ObfDereferenceObject(v121);
      if ( v13 >= 0 && a5 )
        *a5 = 0;
      return v13;
    case 45:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v122 = v183[47];
      __dmb(0xBu);
      ObfDereferenceObjectWithTag((int)v183);
      v123 = (v122 & 0x80000) != 0;
      if ( (v122 & 0x40000) != 0 )
        v123 |= 2u;
      *v6 = v123;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 46:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v130 = v183[48];
      __dmb(0xBu);
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = (v130 & 0x200000) != 0;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 47:
      if ( !a5 || (a4 & 1) != 0 )
        return -1073741811;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v127 = 0;
      v128 = KeQueryGroupMaskProcess((int)v183);
      v195 = v128;
      do
      {
        v129 = __clz(__rbit(v128));
        v200 = v129;
        v127 += 2;
        v191 = v127;
        if ( v127 <= a4 )
        {
          *(_WORD *)v6 = v129;
          v6 = (BOOL *)((char *)v6 + 2);
          v249[1] = v6;
          v129 = v200;
        }
        *((_BYTE *)&v195 + (v129 >> 3)) &= ~(unsigned __int8)(1 << (v129 & 7));
        v128 = v195;
      }
      while ( v195 );
      *a5 = v127;
      if ( v127 > a4 )
      {
        v13 = -1073741789;
        v184 = -1073741789;
      }
      else
      {
        v13 = 0;
        v184 = 0;
      }
      v48 = v183;
      goto LABEL_51;
    case 49:
      if ( a4 != 4 )
        goto LABEL_365;
      v19 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v19 < 0 )
        return v19;
      v131 = v183[79];
      ObfDereferenceObjectWithTag((int)v183);
      *v6 = v131;
      if ( a5 )
        *a5 = 4;
      return 0;
    case 50:
      v210 = 0;
      v202 = 0i64;
      if ( v8 != 1 )
        return -1073741823;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, 1, 2035381072, &v183, 0);
      v184 = v13;
      if ( v13 < 0 )
        return v13;
      v132 = v183;
      v133 = v183 + 43;
      __pld(v183 + 43);
      v134 = *v133 & 0xFFFFFFFE;
      do
        v135 = __ldrex(v133);
      while ( v135 == v134 && __strex(v134 + 2, v133) );
      __dmb(0xBu);
      if ( v135 == v134 || ExfAcquireRundownProtection(v133) )
      {
        KiStackAttachProcess((int)v132, 0, (int)v283);
        v137 = *(_DWORD *)(v132[80] + 16);
        __dmb(0xBu);
        v138 = (_DWORD *)(v137 + 104);
        if ( v137 + 104 >= (unsigned int)MmUserProbeAddress )
          v138 = (_DWORD *)MmUserProbeAddress;
        v186[0] = *v138;
        v210 = v186[0];
        v139 = (unsigned int *)(v137 + 112);
        if ( v137 + 112 >= (unsigned int)MmUserProbeAddress )
          v139 = (unsigned int *)MmUserProbeAddress;
        v243 = *v139;
        v187 = v139[1];
        v244 = v187;
        v202 = __PAIR64__(v187, v243);
        v13 = v184;
        v140 = v193;
        KiUnstackDetachProcess((unsigned int)v283, 0);
        if ( v13 < 0 )
          goto LABEL_355;
        v141 = (unsigned __int16)v202;
        v142 = (unsigned __int16)v202 + 6;
        if ( a5 )
          *a5 = v142;
        if ( a4 >= v142 )
        {
          *v6 = v186[0];
          *((_WORD *)v6 + 2) = v141;
        }
        else
        {
          v13 = -1073741820;
          v184 = -1073741820;
        }
        v143 = v187;
        if ( v13 >= 0 && v141 )
        {
          v144 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v136 = v183;
          v13 = MmCopyVirtualMemory(v183, v143, v144, (char *)v6 + 6, v141, v140, &v247);
        }
        else
        {
LABEL_355:
          v136 = v183;
        }
        v145 = v136 + 43;
        __pld(v136 + 43);
        v146 = v136[43] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v147 = __ldrex(v145);
        while ( v147 == v146 && __strex(v146 - 2, v145) );
        if ( v147 != v146 )
          ExfReleaseRundownProtection((unsigned __int8 *)v145);
      }
      else
      {
        v13 = -1073741558;
        v136 = v183;
      }
      v48 = v136;
      goto LABEL_51;
    case 51:
      if ( a4 >= 8 )
      {
        v13 = ObReferenceObjectByHandle(a1, 1024, PsProcessType, v8, &v187, 0);
        if ( v13 >= 0 )
        {
          v148 = v190;
          --*(_WORD *)(v190 + 308);
          v149 = ObReferenceProcessHandleTable(v187);
          if ( v149 )
          {
            v13 = ExQueryProcessHandleInformation(v149, v6, a4, a5);
            v149 = ObDereferenceProcessHandleTable(v187);
          }
          else
          {
            v13 = -1073741558;
          }
          v150 = *(_WORD *)(v148 + 308) + 1;
          *(_WORD *)(v148 + 308) = v150;
          if ( !v150 && *(_DWORD *)(v148 + 100) != v148 + 100 && !*(_WORD *)(v148 + 310) )
            KiCheckForKernelApcDelivery(v149);
          ObfDereferenceObject(v187);
        }
      }
      else
      {
        if ( a5 )
          *a5 = 8;
LABEL_365:
        v13 = -1073741820;
      }
      return v13;
    case 52:
      if ( a4 != 8 )
        goto LABEL_365;
      v151 = *v6;
      __dmb(0xBu);
      v229 = v151;
      if ( a1 == -1 )
      {
        v152 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
        v183 = v152;
      }
      else
      {
        v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
        if ( v13 < 0 )
          return v13;
        v152 = v183;
        a1 = v189;
      }
      if ( v151 == 6 )
      {
        v13 = 0;
        v184 = 0;
        __dmb(0xBu);
        v6[1] = 0;
        if ( (v152[47] & 0x4000000) != 0 )
        {
          v166 = v6[1] | 1;
          __dmb(0xBu);
          v6[1] = v166;
          v13 = v184;
          v152 = v183;
        }
      }
      else
      {
        switch ( v151 )
        {
          case 1:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            if ( (v152[47] & 0x20000) == 0 )
            {
              v153 = v6[1] | 1;
              __dmb(0xBu);
              v6[1] = v153;
              v13 = v184;
              v152 = v183;
            }
            if ( (v152[47] & 0x8000000) != 0 )
            {
              v154 = v6[1] | 2;
              __dmb(0xBu);
              v6[1] = v154;
              v13 = v184;
              v152 = v183;
            }
            if ( (v152[47] & 0x2000000) != 0 )
            {
              v155 = v6[1] | 4;
              __dmb(0xBu);
              v6[1] = v155;
              v13 = v184;
              v152 = v183;
            }
            if ( (v152[47] & 0x1000000) != 0 )
            {
              v156 = v6[1] | 8;
              __dmb(0xBu);
              v6[1] = v156;
              v13 = v184;
              v152 = v183;
            }
            break;
          case 2:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            if ( (v152[47] & 0x400) != 0 )
            {
              v161 = v6[1] | 1;
              __dmb(0xBu);
              v6[1] = v161;
              v13 = v184;
              v152 = v183;
            }
            break;
          case 3:
            v13 = 0;
            v184 = 0;
            v157 = ObReferenceProcessHandleTable(v152);
            if ( v157 )
            {
              ExQueryHandleExceptionsPermanency(v157, v196, &v190);
              __dmb(0xBu);
              v6[1] = 0;
              if ( v196[0] )
              {
                v158 = v6[1] | 1;
                __dmb(0xBu);
                v6[1] = v158;
                v13 = v184;
                v152 = v183;
              }
              if ( (_BYTE)v190 )
              {
                v159 = v6[1] | 2;
                __dmb(0xBu);
                v6[1] = v159;
                v13 = v184;
                v152 = v183;
              }
              ObDereferenceProcessHandleTable(v152);
              a1 = v189;
            }
            else
            {
              v13 = -1073741558;
              a1 = v189;
            }
            break;
          case 4:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            if ( (int)v152[47] < 0 )
            {
              v160 = v6[1] | 1;
              __dmb(0xBu);
              v6[1] = v160;
              v13 = v184;
              v152 = v183;
            }
            break;
          case 7:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            if ( (v152[48] & 0x10) != 0 )
            {
              v162 = v6[1] | 1;
              __dmb(0xBu);
              v6[1] = v162;
              v13 = v184;
              v152 = v183;
            }
            break;
          case 8:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            if ( *((unsigned __int8 *)v152 + 732) >= 8u && *((unsigned __int8 *)v152 + 733) >= 8u )
            {
              v163 = v6[1] | 1;
              __dmb(0xBu);
              v6[1] = v163;
              v13 = v184;
              v152 = v183;
            }
            break;
          case 9:
            v13 = 0;
            v184 = 0;
            __dmb(0xBu);
            v6[1] = 0;
            v164 = v152[184];
            if ( (v164 & 4) != 0 )
            {
              v165 = v6[1] | 1;
            }
            else
            {
              if ( (v164 & 8) == 0 )
                break;
              v165 = v6[1] | 2;
            }
            __dmb(0xBu);
            v6[1] = v165;
            v152 = v183;
            v13 = v184;
            break;
          default:
            v13 = -1073741637;
            break;
        }
      }
      if ( a1 != -1 )
      {
        v48 = v152;
LABEL_51:
        ObfDereferenceObjectWithTag((int)v48);
      }
      return v13;
    case 54:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v13;
      if ( v13 < 0 )
        return v13;
      v167 = v183;
      v168 = ObReferenceProcessHandleTable(v183);
      if ( !v168 )
        goto LABEL_427;
      v169 = (*(_BYTE *)(v168 + 28) & 2) != 0;
      __dmb(0xBu);
      *v6 = v169;
      goto LABEL_426;
    case 55:
      if ( a4 != 8 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      *v6 = v183[196] & 0x7FFFFFFF;
      v6[1] = v48[197];
      goto LABEL_51;
    case 58:
      if ( a4 < 4 )
        goto LABEL_365;
      v13 = ExLockUserBuffer(v6, a4, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, v232, &v201);
      if ( v13 >= 0 )
      {
        v13 = ObReferenceObjectByHandleWithTag(v189, 1088, PsProcessType, v193, 2035381072, &v183, 0);
        if ( v13 >= 0 )
        {
          v223 = 0;
          v224 = 0;
          v225 = 0;
          v170 = ObReferenceProcessHandleTable(v183);
          if ( v170 )
          {
            v223 = v232[0];
            v224 = a4 >> 2;
            v225 = 0;
            ExEnumHandleTable(v170, PspHandleTableWalker, &v223, 0);
            v13 = 0;
            ObDereferenceProcessHandleTable(v183);
          }
          else
          {
            v13 = -1073741558;
          }
          ObfDereferenceObjectWithTag((int)v183);
          if ( a5 )
            *a5 = 4 * v225;
        }
        ExUnlockUserBuffer(v201);
      }
      return v13;
    case 59:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 1024, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      *v6 = (v183[25] >> 5) & 1;
      goto LABEL_51;
    case 60:
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v171 = v183;
      v13 = PsQueryProcessCommandLine((int)v183, (int)v6, a4, v193, a5);
      if ( !v171 )
        return v13;
      v48 = v171;
      goto LABEL_51;
    case 61:
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        if ( a4 )
        {
          v48 = v183;
          *(_BYTE *)v6 = *((_BYTE *)v183 + 734);
          if ( a5 )
            *a5 = 1;
          v13 = 0;
        }
        else
        {
          v13 = -1073741820;
          v48 = v183;
        }
        if ( v48 )
          goto LABEL_51;
      }
      return v13;
    case 64:
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v172 = v183;
      v13 = EtwQueryProcessTelemetryInfo(v183, v6, a4, v193, a5);
      if ( !v172 )
        return v13;
      v48 = v172;
      goto LABEL_51;
    case 65:
      v173 = 0;
      v183 = 0;
      if ( a4 == 12 )
      {
        v174 = v6[1];
        v175 = v6[2];
        v206 = *v6;
        v207 = v174;
        v208 = v175;
        if ( v206 == 2 )
        {
          if ( (v207 & 0xFFFFFFFE) != 0 || v208 )
          {
            v13 = -1073741811;
          }
          else
          {
            v13 = ObReferenceObjectByHandleWithTag(v189, 4096, PsProcessType, v8, 2035381072, &v183, 0);
            v173 = v183;
            if ( v13 >= 0 )
            {
              MmQueryCommitReleaseState(v183, v230, &v208);
              v207 = v207 & 0xFFFFFFFE | v230[0] & 1;
              v208 <<= 12;
              v176 = v207;
              v177 = v208;
              *v6 = v206;
              v6[1] = v176;
              v6[2] = v177;
              v13 = 0;
            }
          }
        }
        else
        {
          v13 = -1073741735;
        }
      }
      else
      {
        v13 = -1073741820;
      }
      if ( !v173 )
        return v13;
      v48 = v173;
      goto LABEL_51;
    case 66:
    case 67:
      if ( (a4 & 7) != 0 || a4 > 8 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 >= 0 )
      {
        v180 = KeQueryCpuSetsProcess((int)v183, v246, v179, a2 == 67);
        ObfDereferenceObjectWithTag((int)v183);
        v181 = 8 * v180;
        if ( a5 )
          *a5 = v181;
        if ( v181 >= a4 )
          v181 = a4;
        memmove((int)v6, (int)v246, v181);
      }
      return v13;
    case 69:
      if ( a4 != 40 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v211 = 0;
      v212 = 0;
      v213 = 0;
      v214 = 0;
      v215 = 0;
      v216 = 0;
      v217 = 0;
      v218 = 0;
      v219 = 0;
      v220 = 0;
      v119 = v183[72];
      __dmb(0xBu);
      v120 = v183;
      if ( v119 )
      {
        KiStackAttachProcess((int)v183, 0, (int)v282);
        ZwQueryInformationJobObject();
        ZwQueryInformationJobObject();
        KiUnstackDetachProcess((unsigned int)v282, 0);
        v213 = v274;
        v214 = v275;
        v215 = v276;
        v216 = v277;
        v211 = v278;
        v212 = v279;
        if ( (v284 & 0x200000) != 0 )
        {
          v219 = v286;
          v220 = 0;
        }
        if ( (v284 & 0x200) != 0 )
        {
          v217 = v285;
          v218 = 0;
        }
        memmove((int)v6, (int)&v211, 0x28u);
        if ( a5 )
          *a5 = 40;
        v13 = 0;
      }
      else
      {
        v13 = -1073741394;
      }
      v48 = v120;
      goto LABEL_51;
    case 70:
      if ( a4 != 1 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      if ( v13 < 0 )
        return v13;
      v48 = v183;
      *(_BYTE *)v6 = (v183[184] & 0x400) != 0;
      goto LABEL_51;
    case 71:
      if ( a4 != 4 )
        goto LABEL_365;
      v13 = ObReferenceObjectByHandleWithTag(a1, 4096, PsProcessType, v8, 2035381072, &v183, 0);
      v184 = v13;
      if ( v13 < 0 )
        return v13;
      v167 = v183;
      if ( ObReferenceProcessHandleTable(v183) )
      {
        v178 = ExQueryRaiseUMExceptionOnInvalidHandleClose();
        __dmb(0xBu);
        *v6 = v178 != 0;
LABEL_426:
        ObDereferenceProcessHandleTable(v167);
      }
      else
      {
LABEL_427:
        v13 = -1073741558;
      }
      v48 = v167;
      goto LABEL_51;
    default:
      return -1073741821;
  }
}
