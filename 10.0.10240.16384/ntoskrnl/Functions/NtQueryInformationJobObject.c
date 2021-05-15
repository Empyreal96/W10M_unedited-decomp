// NtQueryInformationJobObject 
 
int __fastcall NtQueryInformationJobObject(int a1, int a2, unsigned int a3, unsigned int a4, _DWORD *a5)
{
  int v7; // r5
  unsigned int v8; // r10
  bool v9; // zf
  int v10; // r3
  unsigned int v11; // r6
  int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r3
  _DWORD *v15; // r2
  int v16; // r0
  int v17; // r8
  int *v18; // r10
  int v19; // r4
  int v20; // r3
  unsigned int *v21; // r4
  int v22; // r0
  int v23; // r5
  unsigned int v24; // r2
  unsigned int v25; // r2
  int v26; // r0
  __int16 v27; // r3
  int v28; // r0
  __int16 v29; // r3
  int v30; // r0
  __int16 v31; // r3
  int v32; // r6
  int v33; // r5
  unsigned int v34; // r9
  int v35; // r0
  int v36; // r5
  unsigned int v37; // r2
  unsigned int v38; // r2
  int v39; // r0
  __int16 v40; // r3
  int v41; // r4
  int v42; // r2
  unsigned int v43; // r5
  unsigned __int16 v44; // r0
  int *v45; // r1
  int v46; // r0
  __int16 v47; // r3
  int v48; // r2
  int v49; // r3
  int v50; // r0
  __int16 v51; // r3
  unsigned int v52; // r4
  unsigned int v53; // r5
  int v54; // r2
  unsigned __int16 k; // r0
  _DWORD *v56; // r0
  int v57; // r1
  int v58; // r2
  unsigned int v59; // r3
  int v60; // r1
  int v61; // r1
  _DWORD *v62; // r2
  _DWORD *v63; // r0
  int v64; // r2
  __int64 v65; // r0
  int v66; // r2
  int v67; // r0
  __int16 v68; // r3
  int v69; // r3
  int v70; // r2
  unsigned int *v71; // r2
  unsigned int v72; // r0
  unsigned int *v73; // r4
  int v74; // r0
  int v75; // r10
  unsigned int v76; // r2
  unsigned int v77; // r3
  int v78; // r1
  unsigned int v79; // r2
  int *v80; // r3
  _DWORD *v81; // r3
  int *v82; // r4
  _DWORD *v83; // r0
  int v84; // r1
  int v85; // r1
  int v86; // r1
  unsigned int v87; // r1
  int v88; // lr
  int v89; // r3
  int v90; // r1
  int v91; // r2
  unsigned int v92; // r1
  int v93; // lr
  int v94; // r3
  int v95; // r1
  int v96; // r2
  int v97; // r1
  int v98; // r5
  __int64 v99; // r0
  int v100; // r2
  int i; // r1
  __int64 v102; // r0
  int j; // r4
  int v104; // r0
  _DWORD *v105; // r2
  int v106; // r1
  unsigned int *v107; // r2
  int v108; // r3
  int v109; // r0
  __int16 v110; // r3
  int v111; // r3
  int v112; // r2
  int v113; // r3
  int v114; // r0
  __int16 v115; // r3
  int v116; // r3
  int v117; // r0
  __int16 v118; // r3
  unsigned int *v119; // r4
  int v120; // r0
  int v121; // r5
  unsigned int v122; // r2
  int v123; // r1
  unsigned __int64 v124; // kr18_8
  unsigned int v125; // r2
  int v126; // r0
  __int16 v127; // r3
  int v128; // r1
  int v129; // r2
  int v130; // r4
  int v131; // r0
  __int16 v132; // r3
  int *v133; // r5
  int v134; // r1
  int v135; // r2
  int v136; // r3
  int v137; // r0
  _DWORD *v138; // r5
  unsigned int v139; // r2
  int v140; // r3
  int v141; // r3
  int v142; // r0
  bool v143; // r3
  int v144; // r0
  unsigned int v145; // r1
  __int16 v146; // r3
  int v147; // r0
  int v148; // r5
  unsigned int v149; // r2
  _WORD *v150; // r3
  int v151; // r0
  unsigned int v152; // r6
  int v153; // r0
  int v154; // r5
  unsigned int v155; // r2
  int v156; // r0
  int v157; // r2
  _DWORD *v158; // r2
  int v159; // r0
  unsigned int v160; // r1
  __int16 v161; // r3
  int v162; // r0
  int v163; // r5
  unsigned int v164; // r2
  int v165; // r0
  int v166; // r2
  int v167; // r0
  unsigned int v168; // r1
  __int16 v169; // r3
  int v170; // r0
  int v171; // r5
  unsigned int v172; // r2
  int v173; // r0
  int v174; // r2
  int v175; // r0
  unsigned int v176; // r1
  __int16 v177; // r3
  unsigned int v179; // [sp+14h] [bp-4F4h]
  unsigned int v180; // [sp+14h] [bp-4F4h]
  int v181; // [sp+18h] [bp-4F0h]
  int v182; // [sp+18h] [bp-4F0h]
  char v183; // [sp+1Dh] [bp-4EBh] BYREF
  unsigned int v184; // [sp+20h] [bp-4E8h]
  _DWORD *v185; // [sp+24h] [bp-4E4h]
  int v186; // [sp+28h] [bp-4E0h]
  int v187; // [sp+2Ch] [bp-4DCh]
  int v188; // [sp+30h] [bp-4D8h] BYREF
  int v189; // [sp+34h] [bp-4D4h]
  int v190; // [sp+38h] [bp-4D0h]
  int v191; // [sp+3Ch] [bp-4CCh] BYREF
  int v192; // [sp+40h] [bp-4C8h] BYREF
  int v193; // [sp+44h] [bp-4C4h]
  unsigned int v194; // [sp+48h] [bp-4C0h]
  _DWORD *v195; // [sp+4Ch] [bp-4BCh]
  __int16 v196; // [sp+50h] [bp-4B8h] BYREF
  char v197; // [sp+52h] [bp-4B6h]
  unsigned int v198; // [sp+54h] [bp-4B4h] BYREF
  _WORD v199[2]; // [sp+58h] [bp-4B0h] BYREF
  unsigned int v200; // [sp+5Ch] [bp-4ACh]
  int v201; // [sp+60h] [bp-4A8h] BYREF
  int v202; // [sp+64h] [bp-4A4h]
  int v203; // [sp+68h] [bp-4A0h] BYREF
  int v204; // [sp+6Ch] [bp-49Ch]
  int v205; // [sp+70h] [bp-498h] BYREF
  int v206; // [sp+74h] [bp-494h] BYREF
  int v207; // [sp+78h] [bp-490h] BYREF
  int v208; // [sp+7Ch] [bp-48Ch] BYREF
  int v209; // [sp+80h] [bp-488h] BYREF
  int v210; // [sp+88h] [bp-480h] BYREF
  _DWORD v211[3]; // [sp+8Ch] [bp-47Ch] BYREF
  _DWORD v212[2]; // [sp+98h] [bp-470h] BYREF
  _DWORD v213[2]; // [sp+A0h] [bp-468h] BYREF
  _DWORD v214[4]; // [sp+A8h] [bp-460h] BYREF
  bool v215; // [sp+B8h] [bp-450h]
  _BYTE v216[24]; // [sp+C0h] [bp-448h] BYREF
  int v217; // [sp+D8h] [bp-430h] BYREF
  int v218; // [sp+DCh] [bp-42Ch]
  int v219; // [sp+E0h] [bp-428h]
  int v220; // [sp+E4h] [bp-424h]
  int v221; // [sp+E8h] [bp-420h] BYREF
  bool v222; // [sp+ECh] [bp-41Ch]
  bool v223; // [sp+EDh] [bp-41Bh]
  __int16 v224; // [sp+EEh] [bp-41Ah]
  int v225; // [sp+F0h] [bp-418h]
  int v226; // [sp+F4h] [bp-414h]
  int v227; // [sp+F8h] [bp-410h] BYREF
  int v228; // [sp+FCh] [bp-40Ch]
  int v229; // [sp+100h] [bp-408h]
  int v230; // [sp+104h] [bp-404h]
  int v231; // [sp+108h] [bp-400h]
  int v232; // [sp+10Ch] [bp-3FCh]
  int v233; // [sp+110h] [bp-3F8h]
  int v234; // [sp+114h] [bp-3F4h]
  int v235; // [sp+118h] [bp-3F0h]
  int v236; // [sp+11Ch] [bp-3ECh]
  int v237; // [sp+120h] [bp-3E8h]
  int v238; // [sp+124h] [bp-3E4h]
  int v239; // [sp+128h] [bp-3E0h]
  int v240; // [sp+12Ch] [bp-3DCh]
  unsigned int v241; // [sp+130h] [bp-3D8h]
  unsigned int v242; // [sp+134h] [bp-3D4h]
  int v243; // [sp+138h] [bp-3D0h]
  int v244; // [sp+13Ch] [bp-3CCh]
  int v245; // [sp+140h] [bp-3C8h] BYREF
  unsigned int v246; // [sp+148h] [bp-3C0h]
  int v247; // [sp+14Ch] [bp-3BCh]
  int v248; // [sp+150h] [bp-3B8h] BYREF
  int v249; // [sp+158h] [bp-3B0h] BYREF
  int v250; // [sp+160h] [bp-3A8h]
  int v251; // [sp+164h] [bp-3A4h]
  int v252[2]; // [sp+168h] [bp-3A0h]
  _DWORD v253[18]; // [sp+170h] [bp-398h] BYREF
  _DWORD v254[2]; // [sp+1B8h] [bp-350h] BYREF
  unsigned __int64 v255; // [sp+1C0h] [bp-348h]
  unsigned __int64 v256; // [sp+1C8h] [bp-340h]
  _DWORD v257[12]; // [sp+1E0h] [bp-328h] BYREF
  _BYTE v258[48]; // [sp+210h] [bp-2F8h] BYREF
  int v259; // [sp+240h] [bp-2C8h]
  int v260; // [sp+244h] [bp-2C4h]
  int v261; // [sp+248h] [bp-2C0h]
  int v262; // [sp+24Ch] [bp-2BCh]
  int v263; // [sp+250h] [bp-2B8h]
  _DWORD v264[4]; // [sp+258h] [bp-2B0h] BYREF
  _BYTE v265[48]; // [sp+268h] [bp-2A0h] BYREF
  _BYTE v266[48]; // [sp+298h] [bp-270h] BYREF
  _BYTE v267[56]; // [sp+2C8h] [bp-240h] BYREF
  _DWORD v268[76]; // [sp+300h] [bp-208h] BYREF
  _BYTE v269[80]; // [sp+430h] [bp-D8h] BYREF
  _BYTE v270[88]; // [sp+480h] [bp-88h] BYREF
  _DWORD _4D8[18]; // [sp+4D8h] [bp-30h] BYREF

  _4D8[14] = a1;
  _4D8[15] = a2;
  _4D8[16] = a3;
  _4D8[17] = a4;
  v186 = a3;
  v7 = a2;
  v193 = a2;
  v202 = a1;
  v191 = a1;
  v187 = a2;
  v194 = a3;
  v185 = a5;
  v195 = a5;
  if ( (unsigned int)(a2 - 1) > 0x28 )
    return -1073741821;
  switch ( a2 )
  {
    case 9:
      if ( a4 == 112 )
        goto LABEL_28;
      v9 = a4 == 120;
      goto LABEL_26;
    case 12:
      if ( a4 == 48 )
        goto LABEL_28;
      v9 = a4 == 56;
      goto LABEL_26;
    case 13:
      if ( a4 == 80 )
        goto LABEL_28;
      v9 = a4 == 88;
      goto LABEL_26;
    case 20:
      if ( a4 == 40 )
        goto LABEL_28;
      v9 = a4 == 48;
LABEL_26:
      if ( !v9 )
        return -1073741820;
      goto LABEL_28;
    case 28:
      if ( a4 != 16 )
      {
        v9 = a4 == 40;
        goto LABEL_26;
      }
LABEL_28:
      v8 = a4;
      v184 = a4;
      v179 = a4;
      goto LABEL_29;
  }
  v8 = PspJobInfoLengths[a2 - 1];
  v179 = v8;
  v184 = v8;
  if ( a4 != v8 )
  {
    if ( a2 != 3 && a2 != 5 && a2 != 11 && a2 != 14 && a2 != 31 && a2 != 37 || a4 < v8 )
      return -1073741820;
    goto LABEL_28;
  }
LABEL_29:
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v192 = v11;
  v183 = *(_BYTE *)(v11 + 0x15A);
  v12 = v183;
  if ( v183 )
  {
    if ( a4 )
    {
      if ( ((PspJobInfoAlign[a2 - 1] - 1) & a3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v13 = a3 + a4;
      v14 = MmUserProbeAddress;
      if ( a3 + a4 > MmUserProbeAddress || v13 < a3 )
      {
        *(_BYTE *)MmUserProbeAddress = 0;
        v14 = MmUserProbeAddress;
      }
    }
    else
    {
      v14 = MmUserProbeAddress;
    }
    if ( v185 )
    {
      v15 = v185;
      if ( (unsigned int)v185 >= v14 )
        v15 = (_DWORD *)v14;
      *v15 = *v15;
    }
    v190 = v189;
  }
  else
  {
    v190 = v189;
  }
  if ( a1 )
  {
    v16 = ObReferenceObjectByHandle(a1, 4, PsJobType, v12, &v191, 0);
    v17 = v191;
    v187 = v191;
    if ( v16 < 0 )
      return v16;
  }
  else
  {
    v17 = *(_DWORD *)(*(_DWORD *)(v11 + 116) + 288);
    v187 = v17;
    __dmb(0xBu);
    if ( v17 )
    {
      ObfReferenceObject(v17);
    }
    else if ( a2 != 31 )
    {
      return -1073741790;
    }
  }
  v181 = v8;
  v188 = v8;
  v192 = 0;
  v18 = 0;
  v191 = 0;
  v19 = 0;
  switch ( v7 )
  {
    case 1:
    case 8:
    case 19:
      PspQueryJobHierarchyAccountingInformation(v17, v268);
      v18 = v268;
      goto LABEL_52;
    case 2:
    case 9:
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v257[4] = *(_DWORD *)(v17 + 176);
      v257[5] = *(_DWORD *)(v17 + 168);
      v257[6] = *(_DWORD *)(v17 + 172);
      v257[7] = *(_DWORD *)(v17 + 180);
      v257[9] = *(unsigned __int8 *)(v17 + 425);
      v257[10] = *(_DWORD *)(v17 + 236);
      v20 = *(_DWORD *)(v17 + 192);
      if ( !v20 )
        v20 = 0;
      v257[8] = v20;
      v257[0] = *(_DWORD *)(v17 + 152);
      v257[1] = *(_DWORD *)(v17 + 156);
      v257[2] = *(_DWORD *)(v17 + 160);
      v257[3] = *(_DWORD *)(v17 + 164);
      if ( v7 == 9 )
      {
        v21 = (unsigned int *)(v17 + 552);
        v22 = KeAbPreAcquire(v17 + 552, 0, 0);
        v23 = v22;
        do
          v24 = __ldrex(v21);
        while ( !v24 && __strex(0x11u, v21) );
        __dmb(0xBu);
        if ( v24 )
          ExfAcquirePushLockSharedEx((_DWORD *)(v17 + 552), v22, v17 + 552);
        if ( v23 )
          *(_BYTE *)(v23 + 14) |= 1u;
        v259 = *(_DWORD *)(v17 + 328) << 12;
        v260 = *(_DWORD *)(v17 + 332) << 12;
        v262 = *(_DWORD *)(v17 + 344) << 12;
        v263 = *(_DWORD *)(v17 + 336) << 12;
        __dmb(0xBu);
        do
          v25 = __ldrex(v21);
        while ( v25 == 17 && __strex(0, v21) );
        if ( v25 != 17 )
          ExfReleasePushLockShared((_DWORD *)(v17 + 552));
        KeAbPostRelease(v17 + 552);
        v26 = ExReleaseResourceLite(v17 + 32);
        v27 = *(_WORD *)(v11 + 310) + 1;
        *(_WORD *)(v11 + 310) = v27;
        if ( !v27 && *(_DWORD *)(v11 + 100) != v11 + 100 )
          KiCheckForKernelApcDelivery(v26);
        v261 = *(_DWORD *)(v17 + 340) << 12;
        memset(v258, 0, sizeof(v258));
      }
      else
      {
        v28 = ExReleaseResourceLite(v17 + 32);
        v29 = *(_WORD *)(v11 + 310) + 1;
        *(_WORD *)(v11 + 310) = v29;
        if ( !v29 && *(_DWORD *)(v11 + 100) != v11 + 100 )
          KiCheckForKernelApcDelivery(v28);
      }
      v18 = v257;
      goto LABEL_52;
    case 3:
      v188 = 0;
      v19 = PspQueryJobHierarchyProcessIdList(v17, v186, a4, &v188);
      v32 = 1;
      v33 = v188;
      goto LABEL_321;
    case 4:
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v207 = *(_DWORD *)(v17 + 204);
      v30 = ExReleaseResourceLite(v17 + 32);
      v31 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v31;
      if ( !v31 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v30);
      v18 = &v207;
      goto LABEL_52;
    case 5:
      memset(v216, 0, 20);
      v32 = 1;
      memmove(v186, (int)v216, 0x14u);
      v34 = v179;
      v33 = v181;
      goto LABEL_322;
    case 6:
      v206 = *(_DWORD *)(v17 + 208);
      v18 = &v206;
      goto LABEL_52;
    case 10:
      --*(_WORD *)(v11 + 310);
      v35 = KeAbPreAcquire((unsigned int)&PspJobListLock, 0, 0);
      v36 = v35;
      do
        v37 = __ldrex((unsigned int *)&PspJobListLock);
      while ( !v37 && __strex(0x11u, (unsigned int *)&PspJobListLock) );
      __dmb(0xBu);
      if ( v37 )
        ExfAcquirePushLockSharedEx(&PspJobListLock, v35, (unsigned int)&PspJobListLock);
      if ( v36 )
        *(_BYTE *)(v36 + 14) |= 1u;
      v209 = 0;
      __dmb(0xBu);
      do
        v38 = __ldrex((unsigned int *)&PspJobListLock);
      while ( v38 == 17 && __strex(0, (unsigned int *)&PspJobListLock) );
      if ( v38 != 17 )
        ExfReleasePushLockShared(&PspJobListLock);
      v39 = KeAbPostRelease((unsigned int)&PspJobListLock);
      v40 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v40;
      if ( !v40 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v39);
      v18 = &v209;
      goto LABEL_52;
    case 11:
      if ( !v185 || (a4 & 1) != 0 )
        goto LABEL_113;
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v41 = 0;
      v42 = 0;
      v43 = *(unsigned __int16 *)(v17 + 184);
      if ( *(_WORD *)(v17 + 184) )
      {
        v44 = 0;
        v45 = &v201;
        do
        {
          if ( *(_DWORD *)(v17 + 4 * v42 + 192) )
          {
            *(_WORD *)v45 = v42;
            ++v41;
            v45 = (int *)((char *)v45 + 2);
          }
          v42 = ++v44;
        }
        while ( v44 < v43 );
      }
      v46 = ExReleaseResourceLite(v17 + 32);
      v47 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v47;
      if ( !v47 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v46);
      v33 = 2 * v41;
      v188 = 2 * v41;
      v32 = 1;
      if ( 2 * v41 > a4 )
      {
        v19 = -1073741789;
        v34 = v179;
      }
      else
      {
        v19 = 0;
        v34 = v33;
        v184 = v33;
      }
      memmove(v186, (int)&v201, v34);
      goto LABEL_322;
    case 12:
    case 33:
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v56 = *(_DWORD **)(v17 + 520);
      if ( v56 )
      {
        v253[10] = *v56;
        v253[0] = v56[2];
        v253[1] = v56[3];
        v253[2] = v56[4];
        v253[3] = v56[5];
        v253[4] = v56[6];
        v253[5] = v56[7];
        v57 = v56[9];
        v58 = (unsigned __int64)(unsigned int)v56[8] >> 20;
        v253[12] = v56[8] << 12;
        v253[13] = v58 | (v57 << 12);
        v59 = v56[10];
        v60 = v56[11];
        v253[6] = v59 << 12;
        v253[7] = (v59 >> 20) | (v60 << 12);
        v61 = 0;
        v62 = v56 + 2;
        do
        {
          v63 = (_DWORD *)PspNotificationLimitRateControlToleranceField(v253, v61, v62);
          *v63 = *(_DWORD *)(v64 + 40);
          v65 = PspNotificationLimitRateControlToleranceIntervalField(v253);
          *(_DWORD *)v65 = *(_DWORD *)(v66 + 52);
          v61 = HIDWORD(v65) + 1;
          v62 = (_DWORD *)(v66 + 4);
        }
        while ( v61 < 3 );
      }
      else
      {
        memset(v253, 0, sizeof(v253));
      }
      v67 = ExReleaseResourceLite(v17 + 32);
      v68 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v68;
      if ( !v68 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v67);
      if ( a4 == 48 )
      {
        PspConvertJobNotificationLimitToV1(v253, v265);
        v18 = (int *)v265;
      }
      else if ( a4 == 56 )
      {
        PspConvertJobNotificationLimitToV2(v253, v267);
        v18 = (int *)v267;
      }
      else
      {
        v18 = v253;
      }
      goto LABEL_52;
    case 13:
    case 34:
      v196 = 0;
      v197 = 0;
      PspQueryJobHierarchyAccountingInformation(v17, v268);
      v229 = v268[18];
      v230 = v268[19];
      v233 = v268[20];
      v234 = v268[21];
      v237 = v268[0];
      v238 = v268[1];
      v69 = *(__int16 *)(v11 + 310) - 1;
      *(_WORD *)(v11 + 310) = v69;
      ExAcquireResourceExclusiveLite(v17 + 32, 1, v70, v69);
      if ( (*(_DWORD *)(v17 + 744) & 0x4008) != 16392 )
      {
        __dmb(0xBu);
        v71 = (unsigned int *)(v17 + 744);
        do
          v72 = __ldrex(v71);
        while ( __strex(v72 & 0xFFFFFFFB, v71) );
        __dmb(0xBu);
      }
      v73 = (unsigned int *)(v17 + 552);
      v74 = KeAbPreAcquire(v17 + 552, 0, 0);
      v75 = v74;
      do
        v76 = __ldrex(v73);
      while ( !v76 && __strex(0x11u, v73) );
      __dmb(0xBu);
      if ( v76 )
        ExfAcquirePushLockSharedEx((_DWORD *)(v17 + 552), v74, v17 + 552);
      if ( v75 )
        *(_BYTE *)(v75 + 14) |= 1u;
      v77 = *(_DWORD *)(v17 + 512);
      v78 = *(_DWORD *)(v17 + 516);
      v241 = v77 << 12;
      v242 = (v77 >> 20) | (v78 << 12);
      __dmb(0xBu);
      do
        v79 = __ldrex(v73);
      while ( v79 == 17 && __strex(0, v73) );
      if ( v79 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v17 + 552));
      KeAbPostRelease(v17 + 552);
      v80 = *(int **)(v17 + 520);
      if ( v80 )
      {
        v227 = *v80;
        v228 = *(_DWORD *)(*(_DWORD *)(v17 + 520) + 4);
        v81 = *(_DWORD **)(v17 + 520);
        v82 = v81 + 2;
        v83 = v81 + 18;
        v84 = v81[19];
        if ( *((_QWORD *)v81 + 9) )
        {
          v231 = v81[18];
          v232 = v84;
        }
        else
        {
          v231 = *v82;
          v232 = v81[3];
        }
        v85 = v81[21];
        if ( *((_QWORD *)v81 + 10) )
        {
          v235 = v81[20];
          v236 = v85;
        }
        else
        {
          v235 = v81[4];
          v236 = v81[5];
        }
        v86 = v81[23];
        if ( *((_QWORD *)v81 + 11) )
        {
          v239 = v81[22];
          v240 = v86;
        }
        else
        {
          v239 = v81[6];
          v240 = v81[7];
        }
        v87 = v81[24];
        v88 = v81[25];
        if ( *((_QWORD *)v81 + 12) )
        {
          v246 = v87 << 12;
          v89 = (v87 >> 20) | (v88 << 12);
        }
        else
        {
          v90 = v81[9];
          v91 = (unsigned __int64)(unsigned int)v81[8] >> 20;
          v246 = v81[8] << 12;
          v89 = v91 | (v90 << 12);
        }
        v247 = v89;
        v92 = v83[8];
        v93 = v83[9];
        if ( *((_QWORD *)v83 + 4) )
        {
          v243 = v92 << 12;
          v94 = (v92 >> 20) | (v93 << 12);
        }
        else
        {
          v95 = v82[9];
          v96 = (unsigned __int64)(unsigned int)v82[8] >> 20;
          v243 = v82[8] << 12;
          v94 = v96 | (v95 << 12);
        }
        v244 = v94;
        v97 = 0;
        v98 = (char *)v83 - (char *)v82;
        do
        {
          v99 = PspLimitViolationRateControlToleranceLimitField(&v227, v97);
          v100 = *(int *)((char *)v82 + v98 + 40);
          if ( v100 )
          {
            *((_BYTE *)&v196 + HIDWORD(v99)) = 1;
            *(_DWORD *)v99 = v100;
          }
          else
          {
            *(_DWORD *)v99 = v82[10];
          }
          v97 = HIDWORD(v99) + 1;
          ++v82;
        }
        while ( v97 < 3 );
        v7 = v193;
      }
      else
      {
        v227 = 0;
        v228 = 0;
        v231 = 0;
        v232 = 0;
        v235 = 0;
        v236 = 0;
        v239 = 0;
        v240 = 0;
        v246 = 0;
        v247 = 0;
        v243 = 0;
        v244 = 0;
        for ( i = 0; i < 3; i = HIDWORD(v102) + 1 )
        {
          v102 = PspLimitViolationRateControlToleranceLimitField(&v227, i);
          *(_DWORD *)v102 = 0;
        }
      }
      for ( j = 0; j < 3; ++j )
      {
        if ( *(_DWORD *)(v17 + 520) && (v104 = PspRateControlLimitFlag(j), (v104 & *v105) != 0) )
          v106 = v105[j + 15];
        else
          v106 = 1;
        v192 = v106;
        PspQueryRateControlHistory(v17, v106, *((unsigned __int8 *)&v196 + j), &v198, j);
        if ( j )
        {
          if ( j == 1 )
            v107 = (unsigned int *)&v248;
          else
            v107 = (unsigned int *)&v245;
        }
        else
        {
          v107 = (unsigned int *)&v249;
        }
        *v107 = v198;
      }
      v108 = *(_DWORD *)(v17 + 520);
      if ( v108 )
      {
        *(_DWORD *)(v108 + 4) = 0;
        memset((_BYTE *)(*(_DWORD *)(v17 + 520) + 72), 0, 64);
      }
      v109 = ExReleaseResourceLite(v17 + 32);
      v110 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v110;
      if ( !v110 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v109);
      if ( a4 == 88 )
      {
        PspConvertJobLimitViolationToV2(&v227, v270);
        v18 = (int *)v270;
      }
      else if ( a4 == 80 )
      {
        PspConvertJobLimitViolationToV1(&v227, v269);
        v18 = (int *)v269;
      }
      else
      {
        v18 = &v227;
      }
      v19 = 0;
      if ( (PerfGlobalGroupMask & 0x80000) != 0 )
        EtwTraceJobSetQuery(v17, v202, v7, &v227, &v192, 0, 1830);
      goto LABEL_319;
    case 14:
      if ( !v185 || a4 % 0xC )
      {
LABEL_113:
        v19 = -1073741811;
LABEL_319:
        v33 = v181;
LABEL_320:
        v32 = 0;
LABEL_321:
        v34 = v179;
      }
      else
      {
        --*(_WORD *)(v11 + 310);
        v193 = v17 + 32;
        ExAcquireResourceSharedLite(v17 + 32, 1);
        if ( (*(_DWORD *)(v17 + 176) & 0x10) != 0 )
        {
          v48 = *(_DWORD *)(v17 + 188);
          v49 = *(_DWORD *)(v17 + 192);
          v250 = *(_DWORD *)(v17 + 184);
          v251 = v48;
          v252[0] = v49;
        }
        else
        {
          v250 = *(_DWORD *)&KeActiveProcessors;
          v251 = dword_681D74;
          v252[0] = dword_681D78[0];
          __dmb(0xBu);
          v17 = v187;
        }
        v50 = ExReleaseResourceLite(v193);
        v51 = *(_WORD *)(v11 + 310) + 1;
        *(_WORD *)(v11 + 310) = v51;
        if ( !v51 && *(_DWORD *)(v11 + 100) != v11 + 100 )
          KiCheckForKernelApcDelivery(v50);
        v52 = (unsigned __int16)v250;
        v53 = 12 * (unsigned __int16)v250;
        v180 = v53;
        memset(_4D8, 0, v53);
        v54 = 0;
        if ( v52 )
        {
          for ( k = 0; k < v52; v54 = ++k )
          {
            LOWORD(_4D8[3 * v54 + 1]) = v54;
            _4D8[3 * v54] = v252[v54];
          }
        }
        v182 = v53;
        v188 = v53;
        if ( a4 >= v53 )
        {
          v19 = 0;
          v184 = v53;
        }
        else
        {
          v19 = -1073741789;
          v53 = a4;
          v180 = a4;
          v184 = a4;
        }
        v32 = 1;
        memmove(v186, (int)_4D8, v53);
        v34 = v180;
        v33 = v182;
      }
LABEL_322:
      if ( v17 )
        ObfDereferenceObject(v17);
      if ( v19 >= 0 && !v32 )
        memmove(v186, (int)v18, v34);
      if ( v185 )
        *v185 = v33;
      v10 = v19;
      break;
    case 15:
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v111 = *(_DWORD *)(v17 + 532);
      if ( !v111 || (v112 = *(_DWORD *)(v111 + 20), (v112 & 0x40) != 0) )
      {
        v203 = 0;
        v204 = 0;
      }
      else
      {
        v204 = *(_DWORD *)(v111 + 24);
        v113 = 1;
        if ( (v112 & 4) != 0 )
          v113 = 3;
        if ( (v112 & 1) != 0 )
          v113 |= 4u;
        if ( (v112 & 2) != 0 )
          v113 |= 8u;
        if ( (v112 & 0x20) != 0 )
          v113 |= 0x10u;
        v203 = v113;
      }
      v114 = ExReleaseResourceLite(v17 + 32);
      v115 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v115;
      if ( !v115 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v114);
      v18 = &v203;
      goto LABEL_52;
    case 16:
      v208 = *(_DWORD *)(v17 + 428);
      v18 = &v208;
      goto LABEL_52;
    case 17:
      v212[0] = *(_DWORD *)(v17 + 224);
      v212[1] = *(_DWORD *)(v17 + 228);
      v18 = v212;
      goto LABEL_52;
    case 18:
      v221 = 7;
      v224 = 0;
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v116 = *(_DWORD *)(v17 + 744);
      v222 = (v116 & 0x200) != 0;
      v223 = (v116 & 0x80000) != 0;
      v225 = *(_DWORD *)(v17 + 488);
      v226 = *(_DWORD *)(v17 + 492);
      v117 = ExReleaseResourceLite(v17 + 32);
      v118 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v118;
      if ( !v118 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v117);
      v18 = &v221;
      goto LABEL_52;
    case 20:
      v19 = PspAllocateAndQueryNotificationChannel(v11, v17, v266);
      if ( v19 < 0 )
        goto LABEL_319;
      v18 = (int *)v266;
      goto LABEL_52;
    case 21:
      v183 = (*(_DWORD *)(v17 + 744) & 0x400) != 0;
      v18 = (int *)&v183;
      goto LABEL_52;
    case 26:
      v19 = PspQueryJobHierarchyInterferenceCount(v17, v186);
      v34 = v179;
      if ( v19 < 0 )
      {
        v33 = 0;
        v32 = 0;
      }
      else
      {
        v32 = 1;
        v33 = 8;
      }
      goto LABEL_322;
    case 28:
      --*(_WORD *)(v11 + 310);
      v119 = (unsigned int *)(v17 + 552);
      v120 = KeAbPreAcquire(v17 + 552, 0, 0);
      v121 = v120;
      do
        v122 = __ldrex(v119);
      while ( !v122 && __strex(0x11u, v119) );
      __dmb(0xBu);
      if ( v122 )
        ExfAcquirePushLockSharedEx((_DWORD *)(v17 + 552), v120, v17 + 552);
      if ( v121 )
        *(_BYTE *)(v121 + 14) |= 1u;
      v255 = (unsigned __int64)*(unsigned int *)(v17 + 344) << 12;
      v123 = *(_DWORD *)(v17 + 516);
      v124 = (unsigned __int64)*(unsigned int *)(v17 + 512) << 12;
      v254[0] = *(_DWORD *)(v17 + 512) << 12;
      v254[1] = HIDWORD(v124) | (v123 << 12);
      v256 = (unsigned __int64)*(unsigned int *)(v17 + 756) << 12;
      __dmb(0xBu);
      do
        v125 = __ldrex(v119);
      while ( v125 == 17 && __strex(0, v119) );
      if ( v125 != 17 )
        ExfReleasePushLockShared((_DWORD *)(v17 + 552));
      v126 = KeAbPostRelease(v17 + 552);
      v127 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v127;
      if ( !v127 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v126);
      v18 = v254;
      v19 = 0;
      v17 = v187;
      v33 = v188;
      goto LABEL_320;
    case 29:
      v213[0] = *(_DWORD *)(v17 + 756);
      v213[1] = 0;
      v18 = v213;
      goto LABEL_52;
    case 30:
      v134 = *(_DWORD *)(v17 + 708);
      v135 = *(_DWORD *)(v17 + 712);
      v136 = *(_DWORD *)(v17 + 716);
      v264[0] = *(_DWORD *)(v17 + 704);
      v264[1] = v134;
      v264[2] = v135;
      v264[3] = v136;
      v18 = v264;
      goto LABEL_52;
    case 31:
      if ( v17 )
        v133 = (int *)(v17 + 704);
      else
        v133 = PspNullGuid;
      v19 = IoQueryFlowInformation((int)v133, v186, a4, (int)v185);
      if ( v19 == -1073741822 )
      {
        v19 = IoEnableIoQos();
        if ( v19 >= 0 )
          v19 = IoQueryFlowInformation((int)v133, v186, a4, (int)v185);
      }
      v32 = 1;
      v185 = 0;
      v33 = v181;
      goto LABEL_321;
    case 32:
      --*(_WORD *)(v11 + 310);
      ExAcquireResourceSharedLite(v17 + 32, 1);
      v217 = 0;
      v218 = 0;
      v219 = 0;
      v220 = 0;
      v128 = *(_DWORD *)(v17 + 736);
      if ( v128 )
      {
        v129 = 1;
        v219 = 1;
        v130 = *(_DWORD *)(v128 + 32);
        if ( (v130 & 1) != 0 )
        {
          v129 = 3;
          v219 = 3;
          v217 = *(_DWORD *)(v128 + 24);
          v218 = *(_DWORD *)(v128 + 28);
        }
        if ( (v130 & 2) != 0 )
        {
          v219 = v129 | 4;
          LOBYTE(v220) = *(_BYTE *)(v128 + 40);
        }
      }
      v131 = ExReleaseResourceLite(v17 + 32);
      v132 = *(_WORD *)(v11 + 310) + 1;
      *(_WORD *)(v11 + 310) = v132;
      if ( !v132 && *(_DWORD *)(v11 + 100) != v11 + 100 )
        KiCheckForKernelApcDelivery(v131);
      v18 = &v217;
      goto LABEL_52;
    case 36:
      v19 = -1073740535;
      v137 = PspReferenceJobSilo(v17, v11);
      v138 = (_DWORD *)v137;
      if ( !v137 )
        goto LABEL_319;
      v139 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v139 + 310);
      ExAcquireResourceSharedLite(v137 + 28, 1);
      v214[0] = v138[4];
      v140 = v138[21];
      if ( v140 )
        v141 = *(_DWORD *)(v140 + 16);
      else
        v141 = 0;
      v214[1] = v141;
      v214[3] = v138[24];
      v214[2] = v138[25];
      v142 = PspGetServerSiloForSilo((int)v138);
      v143 = v142 && *(_DWORD *)(v142 + 144);
      v215 = v143;
      v144 = ExReleaseResourceLite((int)(v138 + 7));
      v145 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v146 = *(_WORD *)(v145 + 0x136) + 1;
      *(_WORD *)(v145 + 310) = v146;
      if ( !v146 && *(_DWORD *)(v145 + 100) != v145 + 100 )
        KiCheckForKernelApcDelivery(v144);
      PspDereferenceSiloObject((int)v138);
      v18 = v214;
LABEL_52:
      v19 = 0;
      goto LABEL_319;
    case 37:
      v19 = -1073740535;
      v147 = PspReferenceJobSilo(v17, v11);
      v148 = v147;
      v193 = v147;
      if ( !v147 )
        goto LABEL_319;
      v199[0] = 0;
      v199[1] = 0;
      v200 = 0;
      v19 = ObGetRootDirectoryNameByPointer(v147, v199);
      if ( v19 < 0 )
      {
        v34 = v179;
      }
      else
      {
        v192 = 1;
        v149 = v199[0];
        v198 = v199[0] + 8;
        if ( v198 > a4 )
        {
          v19 = -1073741789;
          v152 = v200;
          v34 = v179;
        }
        else
        {
          v150 = (_WORD *)v186;
          v151 = v186 + 8;
          *(_DWORD *)(v186 + 4) = v186 + 8;
          *v150 = v149;
          v150[1] = v149;
          v152 = v200;
          memmove(v151, v200, v149);
          if ( v185 )
            *v185 = v198;
          v34 = v179;
        }
        ExFreePoolWithTag(v152);
      }
      PspDereferenceSiloObject(v148);
      v32 = v192;
      v33 = v181;
      goto LABEL_322;
    case 38:
      v19 = -1073740535;
      v153 = PspReferenceJobSilo(v17, v11);
      v154 = v153;
      if ( v153 )
      {
        v155 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v155 + 310);
        ExAcquireResourceSharedLite(v153 + 28, 1);
        v156 = PspGetServerSiloForSilo(v154);
        if ( v156 && PsGetServerSiloState(v156) < 3 )
        {
          v210 = *(_DWORD *)(v154 + 16);
          v158 = *(_DWORD **)(v157 + 144);
          v211[0] = *v158;
          v211[2] = v158[14];
          v211[1] = v158[15];
          v19 = 0;
        }
        else
        {
          v19 = -1073741816;
        }
        v159 = ExReleaseResourceLite(v154 + 28);
        v160 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v161 = *(_WORD *)(v160 + 0x136) + 1;
        *(_WORD *)(v160 + 310) = v161;
        if ( !v161 && *(_DWORD *)(v160 + 100) != v160 + 100 )
          KiCheckForKernelApcDelivery(v159);
        PspDereferenceSiloObject(v154);
        v18 = &v210;
      }
      goto LABEL_319;
    case 39:
      v19 = -1073740535;
      v162 = PspReferenceJobSilo(v17, v11);
      v163 = v162;
      if ( v162 )
      {
        v164 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v164 + 310);
        ExAcquireResourceSharedLite(v162 + 28, 1);
        v165 = PspGetServerSiloForSilo(v163);
        if ( v165 )
        {
          if ( PsGetServerSiloState(v165) < 3 )
          {
            v211[0] = *(_DWORD *)PsGetServerSiloGlobals(v166);
            v19 = 0;
          }
          else
          {
            v19 = -1073740720;
          }
        }
        else
        {
          v19 = -1073741816;
        }
        v167 = ExReleaseResourceLite(v163 + 28);
        v168 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v169 = *(_WORD *)(v168 + 0x136) + 1;
        *(_WORD *)(v168 + 310) = v169;
        if ( !v169 && *(_DWORD *)(v168 + 100) != v168 + 100 )
          KiCheckForKernelApcDelivery(v167);
        PspDereferenceSiloObject(v163);
        v18 = v211;
      }
      goto LABEL_319;
    case 41:
      v19 = -1073740535;
      v170 = PspReferenceJobSilo(v17, v11);
      v171 = v170;
      if ( v170 )
      {
        v172 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v172 + 310);
        ExAcquireResourceSharedLite(v170 + 28, 1);
        v173 = PspGetServerSiloForSilo(v171);
        if ( v173 )
        {
          if ( PsGetServerSiloState(v173) < 3 )
          {
            v205 = *((_DWORD *)PsGetServerSiloGlobals(v174) + 15);
            v19 = 0;
          }
          else
          {
            v19 = -1073740720;
          }
        }
        else
        {
          v19 = -1073741816;
        }
        v175 = ExReleaseResourceLite(v171 + 28);
        v176 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v177 = *(_WORD *)(v176 + 0x136) + 1;
        *(_WORD *)(v176 + 310) = v177;
        if ( !v177 && *(_DWORD *)(v176 + 100) != v176 + 100 )
          KiCheckForKernelApcDelivery(v175);
        PspDereferenceSiloObject(v171);
        v18 = &v205;
      }
      goto LABEL_319;
    default:
      v19 = -1073741821;
      goto LABEL_319;
  }
  return v10;
}
