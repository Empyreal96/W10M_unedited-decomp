// NtSetInformationJobObject 
 
int __fastcall NtSetInformationJobObject(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r5
  unsigned int v6; // r3
  bool v7; // zf
  int v9; // r2
  int v10; // r1
  int v11; // r0
  int v12; // r8
  int v13; // r6
  int v14; // r3
  int v15; // r2
  int v16; // r5
  int v17; // r3
  int v18; // r4
  int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r3
  int v22; // r3
  unsigned int v23; // r2
  int v24; // r2
  char v25; // r0
  unsigned int v26; // r3
  int v27; // r2
  int v28; // r0
  unsigned int v29; // r2
  int v30; // r2
  int v31; // r3
  _DWORD *v32; // r3
  int v33; // r0
  int v34; // r1
  int v35; // r2
  int v36; // r3
  _DWORD *v37; // r5
  int v38; // r1
  int v39; // r3
  char v40; // r3
  int v41; // r4
  int v42; // r2
  int v43; // r3
  unsigned __int8 *v44; // r4
  int v45; // r1
  unsigned int v46; // r2
  unsigned int v47; // r1
  int v48; // r2
  unsigned __int64 v49; // kr18_8
  int v50; // r4
  unsigned int v51; // r1
  unsigned int *v52; // r2
  unsigned int v53; // r0
  _DWORD *i; // r4
  unsigned int v55; // r4
  unsigned int *v56; // r2
  unsigned int v57; // r0
  int v58; // r9
  int v59; // r5
  int v60; // r6
  unsigned int v61; // r4
  int v62; // r4
  unsigned __int8 *v63; // r9
  int v64; // r0
  int v65; // r5
  unsigned int v66; // r2
  int v67; // r5
  unsigned int *v68; // r4
  unsigned int v69; // r1
  int v70; // r1
  int v71; // r2
  int v72; // r3
  unsigned __int8 *v73; // r5
  int v74; // r1
  unsigned int v75; // r2
  unsigned int v76; // r1
  unsigned int v77; // r6
  unsigned int v78; // r3
  int v79; // r4
  int v80; // r3
  int v81; // r2
  int v82; // r1
  int v83; // r5
  unsigned int v84; // r0
  int v85; // r2
  char v86; // r0
  unsigned int v87; // r3
  _DWORD *v88; // r3
  int v89; // r0
  int v90; // r1
  int v91; // r2
  int v92; // r3
  _DWORD *v93; // r5
  int v94; // r1
  int v95; // r2
  int v96; // r3
  int v97; // r2
  int v98; // r3
  unsigned int *v99; // r2
  unsigned int v100; // r0
  unsigned int *v101; // r2
  unsigned int v102; // r4
  int v103; // r3
  int v104; // r4
  unsigned int v105; // r1
  int *v106; // r2
  int j; // r1
  __int64 v108; // r0
  int v109; // r1
  int *v110; // r3
  int v111; // r3
  int v112; // r3
  _BYTE *v113; // r4
  int v114; // r5
  int *v115; // r0
  int v116; // r4
  int v117; // r2
  unsigned int v118; // r1
  int v119; // r1
  int *v120; // r2
  __int64 v121; // r0
  int *v122; // r3
  int *v123; // r2
  unsigned __int64 v124; // kr28_8
  _DWORD *v125; // r2
  char v126; // r4
  __int16 v127; // r5
  bool v128; // cc
  int v129; // r3
  int v130; // r0
  int v131; // r5
  int v132; // r1
  _DWORD *v133; // r2
  _DWORD *v134; // r5
  _DWORD *v135; // r0
  _DWORD *v136; // r4
  int v137; // r1
  int v138; // r0
  unsigned int *v139; // r2
  unsigned int v140; // r0
  int v141; // r1
  _DWORD *v142; // r5
  int v143; // r4
  _DWORD *v144; // r0
  unsigned int *v145; // r2
  unsigned int v146; // r4
  int v147; // r1
  _DWORD *v148; // r2
  _DWORD *v149; // r5
  int v150; // r9
  int v151; // r3
  _DWORD *v152; // r8
  int v153; // r1
  _DWORD *v154; // r2
  unsigned int *v155; // r2
  unsigned int v156; // r0
  _DWORD *v157; // r0
  BOOL v158; // r4
  int v159; // r3
  int v160; // r4
  __int64 v161; // r0
  __int64 v162; // kr30_8
  int v163; // r1
  int v164; // r2
  int v165; // r3
  unsigned __int8 *v166; // r8
  int v167; // r0
  int v168; // r5
  unsigned int v169; // r2
  unsigned int *v170; // r4
  unsigned int v171; // r1
  int v172; // r4
  int v173; // r0
  int v174; // r2
  int v175; // r5
  int v176; // r3
  unsigned __int8 *v177; // r8
  int v178; // r0
  int v179; // r5
  unsigned int v180; // r2
  unsigned int *v181; // r4
  unsigned int v182; // r1
  int v183; // r3
  int v184; // r0
  _WORD *v185; // r5
  unsigned int v186; // r1
  unsigned int v187; // r0
  int v188; // r2
  int v189; // r3
  int v190; // r2
  int v191; // r3
  int v192; // r2
  int *v193; // r1
  int v194; // r4
  int v195; // r3
  int v196; // t1
  int v197; // r6
  int v198; // r3
  int v199; // r0
  int v200; // r2
  int *v201; // r1
  int v202; // t1
  int v203; // r0
  __int16 v204; // r3
  int v205; // r4
  int v206; // r0
  __int16 v207; // r3
  int v209; // [sp+0h] [bp-600h]
  int v210; // [sp+4h] [bp-5FCh]
  _DWORD *v213; // [sp+18h] [bp-5E8h]
  unsigned int v214; // [sp+1Ch] [bp-5E4h]
  int v215; // [sp+20h] [bp-5E0h]
  unsigned int v216; // [sp+24h] [bp-5DCh]
  unsigned int v217; // [sp+2Ch] [bp-5D4h]
  int v218; // [sp+30h] [bp-5D0h]
  int v219; // [sp+30h] [bp-5D0h]
  _DWORD *v220; // [sp+30h] [bp-5D0h]
  int v221; // [sp+30h] [bp-5D0h]
  char v222; // [sp+34h] [bp-5CCh]
  int v223; // [sp+34h] [bp-5CCh]
  int v224; // [sp+38h] [bp-5C8h]
  int v225; // [sp+38h] [bp-5C8h]
  unsigned int v226; // [sp+38h] [bp-5C8h]
  int v227; // [sp+38h] [bp-5C8h]
  unsigned int v228; // [sp+38h] [bp-5C8h]
  int v229; // [sp+38h] [bp-5C8h]
  int v230; // [sp+3Ch] [bp-5C4h]
  int v231; // [sp+3Ch] [bp-5C4h]
  _DWORD *v232; // [sp+40h] [bp-5C0h] BYREF
  int v233; // [sp+44h] [bp-5BCh]
  int v234; // [sp+48h] [bp-5B8h]
  int v235; // [sp+4Ch] [bp-5B4h]
  unsigned int v236; // [sp+50h] [bp-5B0h]
  int (__fastcall *v237)(_DWORD, _DWORD); // [sp+54h] [bp-5ACh]
  int v238; // [sp+58h] [bp-5A8h]
  _DWORD *v239; // [sp+5Ch] [bp-5A4h] BYREF
  int v240; // [sp+60h] [bp-5A0h]
  _DWORD v241[2]; // [sp+68h] [bp-598h] BYREF
  int v242; // [sp+70h] [bp-590h]
  char v243; // [sp+74h] [bp-58Ch]
  char v244; // [sp+75h] [bp-58Bh]
  int v245; // [sp+78h] [bp-588h] BYREF
  int v246; // [sp+7Ch] [bp-584h]
  int v247; // [sp+80h] [bp-580h] BYREF
  int v248; // [sp+84h] [bp-57Ch] BYREF
  unsigned int v249; // [sp+88h] [bp-578h]
  int v250; // [sp+8Ch] [bp-574h]
  unsigned int v251; // [sp+90h] [bp-570h] BYREF
  unsigned __int16 v252[2]; // [sp+98h] [bp-568h] BYREF
  int v253; // [sp+9Ch] [bp-564h]
  int v254; // [sp+A0h] [bp-560h]
  int *v255; // [sp+A4h] [bp-55Ch]
  int v256; // [sp+A8h] [bp-558h]
  int v257; // [sp+ACh] [bp-554h]
  int v258; // [sp+B0h] [bp-550h] BYREF
  int v259; // [sp+B4h] [bp-54Ch]
  _DWORD v260[6]; // [sp+B8h] [bp-548h] BYREF
  _DWORD *v261; // [sp+D0h] [bp-530h] BYREF
  int v262; // [sp+D4h] [bp-52Ch]
  int v263; // [sp+D8h] [bp-528h]
  unsigned __int16 *v264; // [sp+DCh] [bp-524h]
  unsigned int v265; // [sp+E0h] [bp-520h]
  int v266; // [sp+E8h] [bp-518h]
  int v267; // [sp+ECh] [bp-514h]
  int v268; // [sp+F0h] [bp-510h]
  int v269; // [sp+F8h] [bp-508h] BYREF
  int v270; // [sp+FCh] [bp-504h]
  unsigned int v271; // [sp+100h] [bp-500h]
  int v272; // [sp+104h] [bp-4FCh]
  int v273; // [sp+108h] [bp-4F8h]
  int v274; // [sp+10Ch] [bp-4F4h]
  int v275; // [sp+110h] [bp-4F0h]
  _DWORD v276[4]; // [sp+118h] [bp-4E8h] BYREF
  int v277[6]; // [sp+128h] [bp-4D8h] BYREF
  unsigned int v278; // [sp+140h] [bp-4C0h]
  int v279; // [sp+144h] [bp-4BCh]
  int v280; // [sp+148h] [bp-4B8h]
  unsigned __int16 v281; // [sp+14Ch] [bp-4B4h]
  _DWORD v282[4]; // [sp+150h] [bp-4B0h] BYREF
  int v283; // [sp+160h] [bp-4A0h] BYREF
  int v284; // [sp+164h] [bp-49Ch]
  int v285; // [sp+168h] [bp-498h]
  int v286; // [sp+16Ch] [bp-494h]
  int v287[6]; // [sp+170h] [bp-490h] BYREF
  __int64 v288[95]; // [sp+188h] [bp-478h] BYREF
  int v289; // [sp+480h] [bp-180h]
  int v290; // [sp+484h] [bp-17Ch]
  int v291[2]; // [sp+488h] [bp-178h]
  int v292; // [sp+490h] [bp-170h] BYREF
  int v293; // [sp+494h] [bp-16Ch]
  int v294; // [sp+498h] [bp-168h]
  int v295; // [sp+49Ch] [bp-164h]
  int v296; // [sp+4A0h] [bp-160h]
  __int64 v297; // [sp+4A8h] [bp-158h] BYREF
  __int64 v298; // [sp+4B0h] [bp-150h]
  __int64 v299; // [sp+4B8h] [bp-148h]
  unsigned __int64 v300; // [sp+4C0h] [bp-140h]
  int v301; // [sp+4D0h] [bp-130h]
  unsigned __int64 v302; // [sp+4D8h] [bp-128h]
  _DWORD v303[4]; // [sp+4F0h] [bp-110h] BYREF
  __int64 v304; // [sp+500h] [bp-100h] BYREF
  __int64 v305; // [sp+508h] [bp-F8h]
  int v306; // [sp+510h] [bp-F0h]
  unsigned int v307; // [sp+514h] [bp-ECh]
  unsigned int v308; // [sp+518h] [bp-E8h]
  int v309; // [sp+51Ch] [bp-E4h]
  int v310; // [sp+520h] [bp-E0h]
  unsigned int v311; // [sp+524h] [bp-DCh]
  unsigned int v312; // [sp+528h] [bp-D8h]
  unsigned int v313; // [sp+560h] [bp-A0h]
  unsigned int v314; // [sp+564h] [bp-9Ch]
  unsigned int v315; // [sp+570h] [bp-90h]
  _BYTE v316[48]; // [sp+578h] [bp-88h] BYREF
  _DWORD _5A8[28]; // [sp+5A8h] [bp-58h] BYREF

  _5A8[24] = a1;
  _5A8[26] = a3;
  _5A8[27] = a4;
  v5 = a3;
  _5A8[25] = a2;
  v254 = a3;
  if ( (unsigned int)(a2 - 1) > 0x28 )
    return -1073741821;
  if ( a2 == 9 )
  {
    if ( a4 == 112 )
      goto LABEL_16;
    v7 = a4 == 120;
  }
  else
  {
    if ( a2 != 12 )
    {
      v6 = PspJobInfoLengths[a2 - 1];
      if ( a4 != v6 && (a2 != 11 && a2 != 14 && a2 != 37 || a4 < v6) )
        return -1073741820;
LABEL_16:
      v214 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = *(char *)(v214 + 346);
      v230 = v9;
      if ( *(_BYTE *)(v214 + 346) && a4 )
      {
        if ( ((PspJobInfoAlign[a2 - 1] - 1) & v5) != 0 )
          ExRaiseDatatypeMisalignment(a1);
        if ( a4 + v5 > MmUserProbeAddress || a4 + v5 < v5 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      if ( a2 == 5 )
        v10 = 16;
      else
        v10 = 2;
      v11 = ObReferenceObjectByHandle(a1, v10, PsJobType, v9, &v232, 0);
      v12 = v11;
      v13 = (int)v232;
      v213 = v232;
      v215 = (int)v232;
      v240 = v11;
      if ( v11 < 0 )
        return v12;
      v222 = 0;
      LOBYTE(v235) = 0;
      v14 = *(__int16 *)(v214 + 310) - 1;
      *(_WORD *)(v214 + 310) = v14;
      v15 = a2 - 2;
      switch ( a2 )
      {
        case 2:
        case 9:
          memmove((int)&v304, v5, a4);
          v16 = v230;
          if ( a4 < 0x78 )
            memset((_BYTE *)&v304 + a4, 0, 120 - a4);
          v11 = a2;
          if ( a2 == 2 )
          {
            v17 = 255;
          }
          else if ( a4 == 112 )
          {
            v17 = 0x7FFF;
          }
          else
          {
            v17 = 2129919;
          }
          v256 = v17;
          v18 = v306;
          if ( (v306 & ~v17) != 0 )
            goto LABEL_37;
          memset(v288, 0, sizeof(v288));
          v11 = (int)memset(v260, 0, 20);
          v216 = 0;
          v218 = 0;
          v255 = 0;
          if ( (v306 & 8) != 0 )
            v19 = v309;
          else
            v19 = 0;
          HIDWORD(v288[22]) = v19;
          v235 = v19;
          if ( (v306 & 0x20) != 0 )
          {
            LOBYTE(v20) = v311;
            if ( v311 > 6 )
              goto LABEL_37;
            if ( v311 == 3 || v311 == 4 )
            {
              v11 = SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, a1, 2, v230);
              v222 = 4 * (v11 & 1);
              if ( (v222 & 4) == 0 )
                goto LABEL_46;
              LOBYTE(v20) = v311;
            }
            v20 = (unsigned __int8)v20;
          }
          else
          {
            v20 = 0;
          }
          BYTE1(v288[53]) = v20;
          v251 = v20;
          if ( (v18 & 0x80) != 0 )
          {
            v21 = v312;
            v249 = v312;
            if ( v312 >= 0xA )
              goto LABEL_37;
            if ( v312 > 5 )
            {
              v11 = SeCheckPrivilegedObject(SeIncreaseBasePriorityPrivilege, dword_9227C4, a1, 2, v230);
              v222 ^= (v222 ^ (4 * v11)) & 4;
              if ( (v222 & 4) == 0 )
                goto LABEL_46;
              v21 = v312;
            }
          }
          else
          {
            v21 = 5;
            v249 = 5;
          }
          HIDWORD(v288[29]) = v21;
          if ( (v18 & 2) != 0 )
          {
            v238 = HIDWORD(v304);
            v11 = v304;
            v248 = v304;
            if ( !v304 )
              goto LABEL_37;
            v22 = HIDWORD(v304);
            LODWORD(v288[19]) = v304;
          }
          else
          {
            v22 = 0;
            v248 = 0;
            LODWORD(v288[19]) = 0;
            v238 = 0;
          }
          HIDWORD(v288[19]) = v22;
          v224 = v18 & 4;
          if ( (v18 & 4) != 0 )
          {
            v11 = HIDWORD(v305);
            v231 = HIDWORD(v305);
            v234 = v305;
            if ( !v305 )
              goto LABEL_37;
            v288[20] = v305;
          }
          else
          {
            v231 = HIDWORD(v288[20]);
            v234 = v288[20];
          }
          if ( (v18 & 1) != 0 )
          {
            v23 = v307;
            v239 = (_DWORD *)v307;
            v11 = v308;
            v217 = v308;
            if ( !v307 && !v308 || v307 == -1 && v308 == -1 || v307 > v308 || v307 < 0x14 )
              goto LABEL_37;
            if ( v307 > PspMinimumWorkingSet )
            {
              v11 = SeSinglePrivilegeCheck(SeIncreaseBasePriorityPrivilege, dword_9227C4, v16);
              if ( !v11 )
                goto LABEL_46;
              v23 = v307;
              v11 = v308;
            }
            v288[21] = __PAIR64__(v11, v23);
          }
          else
          {
            v239 = 0;
            v288[21] = 0i64;
            v217 = 0;
          }
          if ( (v18 & 0x100) != 0 )
          {
            if ( v313 < 0x1000 )
              goto LABEL_37;
            v247 = v313 >> 12;
            LODWORD(v288[41]) = v313 >> 12;
          }
          else
          {
            v247 = 0;
            LODWORD(v288[41]) = 0;
          }
          if ( (v18 & 0x200) != 0 )
          {
            if ( v314 < 0x1000 )
              goto LABEL_37;
            v24 = v314 >> 12;
          }
          else
          {
            v24 = 0;
          }
          HIDWORD(v288[41]) = v24;
          v242 = v24;
          if ( (v18 & 0x200000) != 0 )
          {
            if ( v315 < 0x1000 )
              goto LABEL_37;
            v24 = v315 >> 12;
            v237 = (int (__fastcall *)(_DWORD, _DWORD))(v315 >> 12);
            LODWORD(v288[42]) = v315 >> 12;
          }
          else
          {
            v237 = 0;
            LODWORD(v288[42]) = 0;
          }
          v288[23] = 65537i64;
          LODWORD(v288[24]) = 0;
          if ( (v306 & 0x10) == 0 )
            goto LABEL_100;
          if ( (*(_DWORD *)(v13 + 744) & 2) == 0 && v310 )
          {
            if ( !*(_DWORD *)(v13 + 196) )
            {
              v11 = ExAllocatePoolWithTag(1, 20, 1632269136);
              v216 = v11;
              if ( !v11 )
              {
LABEL_93:
                v12 = -1073741670;
                goto LABEL_539;
              }
              v218 = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 20, 0);
              if ( !v218 )
              {
                v11 = ExFreePoolWithTag(v216);
                goto LABEL_93;
              }
            }
            SeCaptureSubjectContextEx(v214, *(_DWORD *)(v214 + 116), &v260[1]);
            v255 = &v260[1];
            if ( v16 )
            {
              v292 = 1;
              v293 = 1;
              v294 = SeDebugPrivilege;
              v295 = dword_922784;
              v296 = 0;
              v25 = SePrivilegeCheck(&v292, &v260[1], 1);
              v26 = v260[0] & 0xFFFFFFFE | v25 & 1;
            }
            else
            {
              v26 = v260[0] | 1;
            }
            v260[0] = v26;
            v222 |= 2u;
LABEL_100:
            v250 = v13 + 32;
            ExAcquireResourceExclusiveLite(v13 + 32, 1, v24, v13 + 32);
            v27 = v306;
            if ( (v18 & 4) == 0 )
            {
              if ( (v306 & 0x40) != 0 )
              {
                v27 = v306 | *(_DWORD *)(v13 + 176) & 4;
                v234 = *(_DWORD *)(v13 + 160);
                LODWORD(v288[20]) = v234;
                v28 = *(_DWORD *)(v13 + 164);
              }
              else
              {
                v28 = 0;
                v234 = 0;
                LODWORD(v288[20]) = 0;
              }
              v231 = v28;
              HIDWORD(v288[20]) = v28;
            }
            v29 = v27 & 0xFFFFFFBF;
            v233 = v29;
            LODWORD(v288[22]) = v29;
            if ( (v222 & 2) != 0 )
            {
              if ( (*(_DWORD *)(v13 + 744) & 2) != 0 )
              {
LABEL_107:
                v12 = -1073741811;
LABEL_153:
                if ( (v222 & 1) != 0 )
                {
                  v50 = KeAbPreAcquire((unsigned int)&dword_618E28, 0, 0);
                  do
                    v51 = __ldrex((unsigned __int8 *)&dword_618E28);
                  while ( __strex(v51 | 1, (unsigned __int8 *)&dword_618E28) );
                  __dmb(0xBu);
                  if ( (v51 & 1) != 0 )
                    ExfAcquirePushLockExclusiveEx(&dword_618E28, v50, (unsigned int)&dword_618E28);
                  if ( v50 )
                    *(_BYTE *)(v50 + 14) |= 1u;
                  __dmb(0xBu);
                  v52 = (unsigned int *)(v13 + 744);
                  do
                    v53 = __ldrex(v52);
                  while ( __strex(v53 | 0x100, v52) );
                  __dmb(0xBu);
                  for ( i = *(_DWORD **)(v13 + 24); i != (_DWORD *)(v13 + 24); i = (_DWORD *)*i )
                  {
                    if ( (*(i - 49) & 1) == 0 )
                      PspAddProcessToWorkingSetChangeList(i - 96);
                  }
                }
                v11 = ExReleaseResourceLite(v250);
                if ( (v222 & 1) != 0 )
                  v11 = PspApplyWorkingSetLimits(v13);
                if ( v255 )
                  v11 = SeReleaseSubjectContext(v255);
                if ( v216 )
                {
                  ExFreePoolWithTag(v216);
                  v11 = PsReturnSharedPoolQuota(v218, 0x14u, 0);
                }
                goto LABEL_539;
              }
              if ( (*(_DWORD *)(v13 + 176) & 0x10) != 0 )
              {
                if ( *(_DWORD *)(v13 + 192) )
                {
                  v266 = 0;
                  v267 = 0;
                  v268 = 0;
                }
                v30 = (unsigned __int16)v267;
              }
              else
              {
                v30 = *(unsigned __int8 *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x99C);
              }
              v31 = dword_681D78[v30];
              __dmb(0xBu);
              v13 = (int)v232;
              if ( v310 != (v31 & v310) )
              {
                v12 = -1073741811;
LABEL_115:
                v213 = (_DWORD *)v215;
                goto LABEL_153;
              }
              LODWORD(v288[24]) = v310;
              v12 = PspEnumJobsAndProcessesInJobHierarchy(v232, 0, 0, PspSetAffinityLimitCallback, v260, 1);
              if ( v12 < 0 )
                goto LABEL_115;
              v32 = *(_DWORD **)(v13 + 196);
              if ( v32 )
              {
                v33 = v32[1];
                v34 = v32[2];
                v35 = v32[3];
                v36 = v32[4];
                v283 = v33;
                v284 = v34;
                v285 = v35;
                v286 = v36;
                v255 = &v283;
              }
              else
              {
                *(_DWORD *)(v13 + 196) = v216;
                *(_DWORD *)(v13 + 200) = v218;
                v216 = 0;
                v255 = 0;
              }
              v37 = *(_DWORD **)(v13 + 196);
              v38 = v260[1];
              v29 = v260[2];
              v39 = v260[3];
              *v37 = v260[0];
              v37[1] = v38;
              v37[2] = v29;
              v37[3] = v39;
              v37[4] = v260[4];
              v213 = (_DWORD *)v215;
              v251 = BYTE1(v288[53]);
              v237 = (int (__fastcall *)(_DWORD, _DWORD))v288[42];
              v242 = HIDWORD(v288[41]);
              v247 = v288[41];
              v249 = HIDWORD(v288[29]);
              v235 = HIDWORD(v288[22]);
              LOBYTE(v29) = v288[22];
              v233 = v288[22];
              v217 = HIDWORD(v288[21]);
              v239 = (_DWORD *)v288[21];
              v231 = HIDWORD(v288[20]);
              v234 = v288[20];
              v238 = HIDWORD(v288[19]);
              v248 = v288[19];
            }
            else if ( (v29 & 0x4000) != 0 && (*(_DWORD *)(v13 + 744) & 2) == 0 )
            {
              goto LABEL_107;
            }
            if ( (*(_DWORD *)(v13 + 176) & 1) != 0 && (v29 & 1) == 0 )
            {
              __dmb(0xFu);
              v40 = dword_618E28;
              __dmb(0xBu);
              if ( (v40 & 1) != 0 )
              {
                v41 = KeAbPreAcquire((unsigned int)&dword_618E28, 0, 0);
                ExfAcquirePushLockExclusiveEx(&dword_618E28, v41, (unsigned int)&dword_618E28);
                if ( v41 )
                  *(_BYTE *)(v41 + 14) |= 1u;
                ExfReleasePushLockExclusive((unsigned int *)&dword_618E28);
                if ( v41 )
                  KeAbPostRelease((unsigned int)&dword_618E28);
              }
            }
            v261 = (_DWORD *)v13;
            v263 = *(_DWORD *)(v13 + 176);
            *(_DWORD *)(v13 + 168) = v239;
            *(_DWORD *)(v13 + 172) = v217;
            *(_DWORD *)(v13 + 180) = v235;
            v42 = HIDWORD(v288[23]);
            v43 = v288[24];
            *(_DWORD *)(v13 + 184) = v288[23];
            *(_DWORD *)(v13 + 188) = v42;
            *(_DWORD *)(v13 + 192) = v43;
            *(_BYTE *)(v13 + 425) = v251;
            *(_DWORD *)(v13 + 236) = v249;
            *(_DWORD *)(v13 + 152) = v248;
            *(_DWORD *)(v13 + 156) = v238;
            *(_DWORD *)(v13 + 160) = v234;
            *(_DWORD *)(v13 + 164) = v231;
            if ( a2 == 9 )
            {
              v44 = (unsigned __int8 *)(v13 + 552);
              v45 = KeAbPreAcquire(v13 + 552, 0, 0);
              v238 = v45;
              do
                v46 = __ldrex(v44);
              while ( __strex(v46 | 1, v44) );
              __dmb(0xBu);
              if ( (v46 & 1) != 0 )
              {
                ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 552), v45, v13 + 552);
                v45 = v238;
              }
              if ( v45 )
                *(_BYTE *)(v45 + 14) |= 1u;
              *(_DWORD *)(v13 + 176) = *(_DWORD *)(v13 + 176) & ~v256 | v233;
              *(_DWORD *)(v13 + 328) = v247;
              *(_DWORD *)(v13 + 332) = v242;
              *(_DWORD *)(v13 + 336) = v237;
              __dmb(0xBu);
              do
                v47 = __ldrex((unsigned int *)v44);
              while ( __strex(v47 - 1, (unsigned int *)v44) );
              if ( (v47 & 2) != 0 && (v47 & 4) == 0 )
                ExfTryToWakePushLock((unsigned int *)(v13 + 552));
              KeAbPostRelease(v13 + 552);
            }
            else
            {
              *(_DWORD *)(v13 + 176) = *(_DWORD *)(v13 + 176) & ~v256 | v233;
            }
            v48 = ~(v263 | *(_DWORD *)(v13 + 176));
            v262 = v48;
            if ( v224 )
            {
              PspEnumJobsAndProcessesInJobHierarchy(v13, 0, 0, PspSetJobTimeLimitCallback, v13 + 160, 1);
              *(_DWORD *)(v13 + 112) = 0;
              *(_DWORD *)(v13 + 116) = 0;
              *(_DWORD *)(v13 + 120) = 0;
              *(_DWORD *)(v13 + 124) = 0;
              KeResetEvent(v13);
              LOBYTE(v48) = v262;
            }
            if ( (*(_DWORD *)(v13 + 176) & 6) != 0 )
            {
              __dmb(0xBu);
              do
                v49 = __ldrexd((unsigned __int64 *)&PspJobTimeLimitsRequest);
              while ( __strexd(v49 + 1, (unsigned __int64 *)&PspJobTimeLimitsRequest) );
              __dmb(0xBu);
              LOBYTE(v48) = v262;
            }
            if ( (v48 & 1) == 0 )
              v222 |= 1u;
            PspEnumJobsAndProcessesInJobHierarchy(
              v13,
              PspSetJobLimitsJobPreCallback,
              PspSetJobLimitsJobPostCallback,
              PspSetJobLimitsProcessCallback,
              &v261,
              5);
            goto LABEL_153;
          }
          goto LABEL_37;
        case 4:
          v249 = *(_DWORD *)v5;
          v55 = v249;
          if ( (v249 & 0xFFFFFF00) != 0 )
            goto LABEL_37;
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, 0);
          if ( *(_DWORD *)(v13 + 564) == v13 + 564 )
          {
            if ( *(_DWORD *)(v13 + 232) == -2 )
            {
              v12 = -1073741790;
            }
            else
            {
              PspBindProcessSessionToJob(v13, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
              v251 = *(_DWORD *)(v13 + 232);
              if ( v251 > 0xFFFFFFFD
                || *(_DWORD *)(v13 + 204) == v55
                || (v282[0] = v13, v282[1] = 0, v282[2] = v55, v12 = PsInvokeWin32Callout(6, v282, 1, &v251), v12 >= 0) )
              {
                *(_DWORD *)(v13 + 204) = v55;
                __dmb(0xBu);
                v56 = (unsigned int *)(v13 + 744);
                do
                  v57 = __ldrex(v56);
                while ( __strex(v57 | 0x10, v56) );
                __dmb(0xBu);
              }
            }
          }
          else
          {
            v12 = -1073741637;
          }
          goto LABEL_184;
        case 5:
          v11 = memmove((int)v287, v5, 0x14u);
          v58 = (int)v213;
          v59 = a2;
          v60 = a1;
          if ( (v287[0] & 0xFFFFFFF0) != 0 )
            v12 = -1073741811;
          else
            v12 = -1073741637;
          goto LABEL_542;
        case 6:
          v236 = *(_DWORD *)v5;
          v61 = v236;
          if ( v236 > 1 )
            goto LABEL_37;
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, v14);
          *(_DWORD *)(v13 + 208) = v61;
LABEL_184:
          v11 = ExReleaseResourceLite(v13 + 32);
          goto LABEL_539;
        case 7:
          v62 = 0;
          v236 = 0;
          v225 = *(_DWORD *)v5;
          v271 = *(_DWORD *)v5;
          v272 = *(_DWORD *)(v5 + 4);
          if ( v272 )
          {
            v11 = ObReferenceObjectByHandle(v272, 2, IoCompletionObjectType, v230, &v247, 0);
            v12 = v11;
            if ( v11 >= 0 )
            {
              v72 = *(_DWORD *)(v13 + 528);
              if ( v72 || (v11 = IoAllocateMiniCompletionPacket(PspNotificationPacketCallback, v13), (v62 = v11) != 0) )
              {
                ExAcquireResourceExclusiveLite(v13 + 32, 1, v71, v72);
                if ( *(_DWORD *)(v13 + 212) || (*(_DWORD *)(v13 + 744) & 1) != 0 )
                {
                  ExReleaseResourceLite(v13 + 32);
                  v11 = ObfDereferenceObject(v247);
                  v12 = -1073741811;
                }
                else
                {
                  if ( !*(_DWORD *)(v13 + 528) )
                  {
                    *(_DWORD *)(v13 + 528) = v62;
                    v62 = 0;
                  }
                  v73 = (unsigned __int8 *)(v13 + 552);
                  v74 = KeAbPreAcquire(v13 + 552, 0, 0);
                  v236 = v74;
                  do
                    v75 = __ldrex(v73);
                  while ( __strex(v75 | 1, v73) );
                  __dmb(0xBu);
                  if ( (v75 & 1) != 0 )
                  {
                    ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 552), v74, v13 + 552);
                    v74 = v236;
                  }
                  if ( v74 )
                    *(_BYTE *)(v74 + 14) |= 1u;
                  *(_DWORD *)(v13 + 216) = v225;
                  *(_DWORD *)(v13 + 212) = v247;
                  *(_DWORD *)(v13 + 224) = 0;
                  *(_DWORD *)(v13 + 228) = 0;
                  __dmb(0xBu);
                  do
                    v76 = __ldrex((unsigned int *)v73);
                  while ( __strex(v76 - 1, (unsigned int *)v73) );
                  if ( (v76 & 2) != 0 && (v76 & 4) == 0 )
                    ExfTryToWakePushLock((unsigned int *)(v13 + 552));
                  KeAbPostRelease(v13 + 552);
                  if ( (*(_DWORD *)(v13 + 428) & 0x40) != 0 )
                    PspEnumJobsAndProcessesInJobHierarchy(v13, 0, 0, PspAssociateCompletionPortCallback, v13, 1);
                  v11 = ExReleaseResourceLite(v13 + 32);
                }
              }
              else
              {
                v12 = -1073741670;
              }
            }
            if ( v62 )
            {
              *(_DWORD *)(v62 + 28) = 0;
              v11 = IopFreeMiniCompletionPacket(v62, v70);
            }
          }
          else
          {
            ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, v225);
            if ( v13 )
            {
              v63 = (unsigned __int8 *)(v13 + 552);
              v64 = KeAbPreAcquire(v13 + 552, 0, 0);
              v65 = v64;
              do
                v66 = __ldrex(v63);
              while ( __strex(v66 | 1, v63) );
              __dmb(0xBu);
              if ( (v66 & 1) != 0 )
                ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 552), v64, v13 + 552);
              if ( v65 )
                *(_BYTE *)(v65 + 14) |= 1u;
            }
            v67 = *(_DWORD *)(v13 + 212);
            *(_DWORD *)(v13 + 212) = 0;
            v68 = (unsigned int *)(v13 + 552);
            __dmb(0xBu);
            do
              v69 = __ldrex(v68);
            while ( __strex(v69 - 1, v68) );
            if ( (v69 & 2) != 0 && (v69 & 4) == 0 )
              ExfTryToWakePushLock(v68);
            KeAbPostRelease((unsigned int)v68);
            v11 = ExReleaseResourceLite(v13 + 32);
            if ( v67 )
              v11 = ObfDereferenceObject(v67);
          }
          goto LABEL_539;
        case 11:
        case 14:
          v77 = 0;
          v250 = 0;
          v219 = 0;
          v237 = 0;
          if ( a2 == 14 )
            v78 = 12;
          else
            v78 = 2;
          v226 = v78;
          v11 = a4 / v78;
          v79 = a4 / v78;
          if ( a4 % v78 )
          {
            v12 = -1073741820;
            goto LABEL_539;
          }
          v265 = a4 / v78;
          v289 = 65537;
          v290 = 0;
          v291[0] = 0;
          v233 = (unsigned __int16)(KeQueryActiveGroupCount() - 1);
          v58 = (int)v213;
          v11 = v233;
          while ( 2 )
          {
            if ( v79 )
            {
              if ( a2 == 14 )
              {
                v81 = *(_DWORD *)(v5 + 4);
                v80 = *(_DWORD *)(v5 + 8);
                v266 = *(_DWORD *)v5;
                v267 = v81;
                v268 = v80;
                v81 = (unsigned __int16)v81;
                LOWORD(v235) = v81;
                v238 = v266;
                v11 = v233;
              }
              else
              {
                LOWORD(v235) = *(_WORD *)v5;
                v238 = dword_681D78[(unsigned __int16)v235];
                __dmb(0xBu);
                v81 = (unsigned __int16)v235;
              }
              v82 = dword_681D78[v81];
              __dmb(0xBu);
              if ( (unsigned __int16)v235 <= (unsigned int)v11 && !v291[v81] && v238 == (v238 & v82) )
              {
                v291[0] |= v238;
                v79 = --v265;
                v5 = v254 + v226;
                v254 += v226;
                v12 = v240;
                v58 = v215;
                v213 = (_DWORD *)v215;
                continue;
              }
              v12 = -1073741811;
              v240 = -1073741811;
              v58 = v215;
              v213 = (_DWORD *)v215;
            }
            break;
          }
          v83 = 0;
          if ( v12 < 0 )
            goto LABEL_540;
          if ( *(_DWORD *)(v58 + 196) )
            goto LABEL_252;
          v11 = ExAllocatePoolWithTag(1, 20, 1632269136);
          v77 = v11;
          if ( !v11 )
            goto LABEL_248;
          v83 = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 20, 0);
          v219 = v83;
          if ( !v83 )
          {
            v84 = v77;
            goto LABEL_251;
          }
LABEL_252:
          SeCaptureSubjectContextEx(v214, *(_DWORD *)(v214 + 116), &v260[1]);
          v233 = (int)&v260[1];
          if ( v230 )
          {
            v292 = 1;
            v293 = 1;
            v294 = SeDebugPrivilege;
            v295 = dword_922784;
            v296 = 0;
            v86 = SePrivilegeCheck(&v292, &v260[1], 1);
            v87 = v260[0] & 0xFFFFFFFE | v86 & 1;
          }
          else
          {
            v87 = v260[0] | 1;
          }
          v260[0] = v87;
          ExAcquireResourceExclusiveLite((int)(v213 + 8), 1, v85, (int)v213);
          v58 = (int)v213;
          v12 = PspEnumJobsAndProcessesInJobHierarchy(v213, 0, 0, PspSetAffinityLimitCallback, v260, 1);
          if ( v12 >= 0 )
          {
            v88 = (_DWORD *)v213[49];
            if ( v88 )
            {
              v89 = v88[1];
              v90 = v88[2];
              v91 = v88[3];
              v92 = v88[4];
              v283 = v89;
              v284 = v90;
              v285 = v91;
              v286 = v92;
              v233 = (int)&v283;
            }
            else
            {
              v213[49] = v77;
              v213[50] = v83;
              v77 = 0;
              v233 = 0;
            }
            v93 = (_DWORD *)v213[49];
            v94 = v260[1];
            v95 = v260[2];
            v96 = v260[3];
            *v93 = v260[0];
            v93[1] = v94;
            v93[2] = v95;
            v93[3] = v96;
            v93[4] = v260[4];
            v261 = v213;
            v263 = v213[44];
            v262 = -17;
            v97 = v290;
            v98 = v291[0];
            v213[46] = v289;
            v213[47] = v97;
            v213[48] = v98;
            if ( a2 != 14 || v213[48] )
            {
              v213[44] |= 0x10u;
              __dmb(0xBu);
              v101 = v213 + 186;
              do
                v102 = __ldrex(v101);
              while ( __strex(v102 | 2, v101) );
            }
            else
            {
              v213[44] &= 0xFFFFFFEF;
              __dmb(0xBu);
              v99 = v213 + 186;
              do
                v100 = __ldrex(v99);
              while ( __strex(v100 & 0xFFFFFFFD, v99) );
            }
            __dmb(0xBu);
            PspEnumJobsAndProcessesInJobHierarchy(
              v213,
              PspSetJobLimitsJobPreCallback,
              0,
              PspSetJobLimitsProcessCallback,
              &v261,
              5);
            v83 = v219;
          }
          v11 = ExReleaseResourceLite((int)(v213 + 8));
          if ( v233 )
            v11 = SeReleaseSubjectContext(v233);
          if ( v77 )
          {
            ExFreePoolWithTag(v77);
            v11 = PsReturnSharedPoolQuota(v83, 0x14u, 0);
          }
          goto LABEL_540;
        case 12:
        case 33:
          if ( a4 == 48 )
          {
            memmove((int)v316, v5, 0x30u);
            v11 = PspConvertJobNotificationLimitFromV1(v316, &v297);
            v103 = 459268;
          }
          else if ( a4 == 56 )
          {
            memmove((int)_5A8, v5, 0x38u);
            v11 = PspConvertJobNotificationLimitFromV2(_5A8, &v297);
            v103 = 492036;
          }
          else
          {
            v11 = memmove((int)&v297, v5, a4);
            v103 = 2064900;
          }
          v257 = v103;
          v58 = (int)v213;
          v104 = v301;
          if ( (v301 & ~v103) != 0 )
            goto LABEL_277;
          if ( (v301 & 0x8000) != 0 )
          {
            v105 = HIDWORD(v302);
            v106 = (int *)v302;
            if ( v302 < 0x1000 )
            {
LABEL_277:
              v12 = -1073741811;
LABEL_540:
              v59 = a2;
              goto LABEL_541;
            }
          }
          else
          {
            v106 = 0;
            v302 = 0i64;
            v105 = 0;
          }
          if ( (v301 & 0x200) != 0 )
          {
            v11 = v300;
            if ( v300 < 0x1000 || v300 < __PAIR64__(v105, (unsigned int)v106) )
              goto LABEL_277;
          }
          else
          {
            v300 = 0i64;
          }
          if ( (v301 & 4) != 0 )
          {
            v106 = (int *)v299;
            if ( !v299 )
              goto LABEL_277;
          }
          else
          {
            v299 = 0i64;
          }
          if ( (v301 & 0x10000) != 0 )
          {
            v106 = (int *)v297;
            if ( !v297 )
              goto LABEL_277;
          }
          else
          {
            v297 = 0i64;
          }
          if ( (v301 & 0x20000) != 0 )
          {
            v106 = (int *)v298;
            if ( !v298 )
              goto LABEL_277;
          }
          else
          {
            v298 = 0i64;
          }
          for ( j = 0; j < 3; j = v109 + 1 )
          {
            PspNotificationLimitRateControlToleranceField(&v297, j, v106);
            v108 = PspNotificationLimitRateControlToleranceIntervalField(&v297);
            v11 = PspRateControlLimitFlag(HIDWORD(v108));
            if ( (v11 & v104) != 0 )
            {
              v111 = *v110;
              if ( !v111 || v111 > 3 || !*v106 || *v106 > 3 )
                goto LABEL_277;
            }
            else
            {
              *v110 = 0;
              *v106 = 0;
              v104 = v301;
            }
          }
          v112 = *(_DWORD *)(v13 + 520);
          if ( !v112 )
          {
            v11 = ExAllocatePoolWithTag(1, 136, 1649046352);
            v113 = (_BYTE *)v11;
            if ( v11 )
            {
              v114 = PsChargeSharedPoolQuota(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 136, 0);
              v84 = (unsigned int)v113;
              if ( v114 )
              {
                memset(v113, 0, 136);
                goto LABEL_314;
              }
LABEL_251:
              v11 = ExFreePoolWithTag(v84);
            }
LABEL_248:
            v12 = -1073741670;
            goto LABEL_540;
          }
          v113 = 0;
          v114 = 0;
LABEL_314:
          ExAcquireResourceExclusiveLite(v13 + 32, 1, (int)v106, v112);
          if ( *(_DWORD *)(v13 + 520) )
          {
            if ( v113 )
            {
              ExFreePoolWithTag((unsigned int)v113);
              PsReturnSharedPoolQuota(v114, 0x88u, 0);
            }
          }
          else
          {
            *(_DWORD *)(v13 + 520) = v113;
            *(_DWORD *)(v13 + 524) = v114;
          }
          v115 = *(int **)(v13 + 520);
          v116 = *v115;
          *((_QWORD *)v115 + 1) = v297;
          *((_QWORD *)v115 + 2) = v298;
          *((_QWORD *)v115 + 3) = v299;
          v117 = HIDWORD(v302) >> 12;
          v115[8] = (__int64)v302 >> 12;
          v115[9] = v117;
          v118 = HIDWORD(v300);
          v115[10] = (__int64)v300 >> 12;
          v115[11] = v118 >> 12;
          v119 = 0;
          v120 = v115 + 2;
          while ( v119 < 3 )
          {
            PspNotificationLimitRateControlToleranceField(&v297, v119, v120);
            v121 = PspNotificationLimitRateControlToleranceIntervalField(&v297);
            v123[10] = *v122;
            v123[13] = *(_DWORD *)v121;
            v119 = HIDWORD(v121) + 1;
            v120 = v123 + 1;
          }
          **(_DWORD **)(v13 + 520) = v301;
          if ( (**(_DWORD **)(v13 + 520) & 0xFFFF7DFF) != 0 )
          {
            __dmb(0xBu);
            do
              v124 = __ldrexd((unsigned __int64 *)&PspJobTimeLimitsRequest);
            while ( __strexd(v124 + 1, (unsigned __int64 *)&PspJobTimeLimitsRequest) );
            __dmb(0xBu);
          }
          if ( v116 )
          {
            v125 = *(_DWORD **)(v13 + 520);
            if ( *v125 )
            {
LABEL_330:
              v59 = a2;
              if ( (PerfGlobalGroupMask & 0x80000) != 0 )
                EtwTraceJobSetQuery(v13, a1, a2, &v297, 0, v12, 1829);
              v11 = ExReleaseResourceLite(v13 + 32);
              v12 = 0;
LABEL_541:
              v60 = a1;
LABEL_542:
              v207 = *(_WORD *)(v214 + 310) + 1;
              *(_WORD *)(v214 + 310) = v207;
              if ( !v207 && *(_DWORD *)(v214 + 100) != v214 + 100 )
                KiCheckForKernelApcDelivery(v11);
              if ( v12 && (PerfGlobalGroupMask & 0x80000) != 0 )
                EtwTraceJobSetQuery(v58, v60, v59, 0, 0, v12, 1831);
              ObfDereferenceObject(v58);
              return v12;
            }
          }
          else
          {
            v125 = *(_DWORD **)(v13 + 520);
            if ( !*v125 )
              goto LABEL_330;
          }
          PspEnumJobsAndProcessesInJobHierarchy(v13, PspSetJobNotificationCountCallback, 0, 0, v125, 5);
          goto LABEL_330;
        case 15:
          v11 = memmove((int)&v258, v5, a4);
          v58 = (int)v213;
          v126 = v258;
          if ( (v258 & 0xFFFFFFE0) != 0 )
            goto LABEL_277;
          v246 = 0;
          v245 = v259;
          v227 = v258 & 1;
          if ( (v258 & 1) == 0 )
          {
            v127 = v259;
            goto LABEL_349;
          }
          if ( (v258 & 2) != 0 )
          {
            if ( (v258 & 0x10) == 0 )
            {
              v127 = v259;
              if ( (_WORD)v259 )
              {
                v128 = (unsigned __int16)v259 > 9u;
                goto LABEL_339;
              }
            }
          }
          else
          {
            v127 = v259;
            if ( (_WORD)v259 && (unsigned __int16)v259 <= 0x2710u )
            {
              if ( (v258 & 0x10) == 0 )
                goto LABEL_349;
              if ( (v258 & 4) == 0 && HIWORD(v259) >= (unsigned int)(unsigned __int16)v259 )
              {
                v128 = HIWORD(v259) > 0x2710u;
LABEL_339:
                if ( v128 )
                  goto LABEL_37;
LABEL_349:
                v220 = 0;
                PspLockJobChain(v13, v214);
                v129 = *(_DWORD *)(v13 + 744);
                if ( v227 )
                {
                  if ( (v129 & 0x20) == 0 )
                  {
                    v130 = PspAllocateRateControl(2);
                    v220 = (_DWORD *)v130;
                    if ( !v130 )
                    {
                      v12 = -1073741670;
                      goto LABEL_422;
                    }
                    *(_DWORD *)(v13 + 532) = v130;
                  }
                }
                else if ( (v129 & 0x20) == 0 )
                {
                  v12 = -1073741811;
LABEL_422:
                  v11 = PspUnlockJobChain(v13, v214);
                  v58 = (int)v213;
                  goto LABEL_540;
                }
                *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) = 0;
                *(_DWORD *)(*(_DWORD *)(v13 + 532) + 24) = v259;
                if ( !v227 )
                {
                  v246 = 3;
                  v245 = 655370000;
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) |= 0x40u;
                  v160 = v245;
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 24) = v245;
                  v239 = (_DWORD *)(*(_DWORD *)(v13 + 532) + 128);
                  v161 = KeQuerySchedulingGroupReadyTime((int)v239);
                  v162 = *(_QWORD *)(v13 + 544) + v161;
                  *(_QWORD *)(v13 + 544) = v162;
                  KeSetSchedulingGroupCpuRates(v161, &v239, &v245, v162);
                  v269 = 0;
                  v270 = v160;
                  PspEnumJobsAndProcessesInJobHierarchy(
                    v13,
                    0,
                    0,
                    PspUpdateSharedReadyQueueAffinityProcessCallback,
                    0,
                    5);
LABEL_420:
                  v12 = 0;
                  if ( (PerfGlobalGroupMask & 0x80000) != 0 )
                    EtwTraceJobSetQuery(v13, a1, 15, &v269, 0, 0, 1829);
                  goto LABEL_422;
                }
                if ( (v126 & 4) != 0 )
                {
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) |= 1u;
                  HIWORD(v245) = v127;
                  v131 = v245;
                }
                else
                {
                  v131 = v259;
                }
                if ( (v126 & 2) != 0 )
                {
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) |= 4u;
                  v132 = 0;
                  v246 = 0;
                }
                else
                {
                  v132 = 1;
                  v246 = 1;
                  if ( (v126 & 0x14) == 0 )
                  {
                    HIWORD(v245) = 10000;
                    v131 = v245;
                  }
                }
                if ( (v126 & 8) != 0 )
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) |= 2u;
                if ( (v126 & 0x10) != 0 )
                  *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20) |= 0x20u;
                v133 = *(_DWORD **)(v13 + 532);
                if ( v133 != v220 )
                {
                  v239 = v133 + 32;
                  v158 = (v133[33] & 2) != 0;
                  v159 = v133[5];
                  if ( (v159 & 4) != 0 )
                    KeSetSchedulingGroupWeights(1, (int)&v239, &v245, v159);
                  else
                    KeSetSchedulingGroupCpuRates(32, &v239, &v245, v159);
                  if ( v158 )
                    PspEnumJobsAndProcessesInJobHierarchy(
                      v13,
                      0,
                      0,
                      PspUpdateSharedReadyQueueAffinityProcessCallback,
                      0,
                      5);
LABEL_418:
                  v269 = *(_DWORD *)(*(_DWORD *)(v13 + 532) + 20);
                  v270 = *(_DWORD *)(*(_DWORD *)(v13 + 532) + 24);
                  goto LABEL_420;
                }
                v133[32] = v131;
                v133[33] = v132;
                v241[1] = v241;
                v241[0] = v241;
                v134 = *(_DWORD **)(v13 + 572);
                v135 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1649046352);
                v136 = v135;
                if ( v135 )
                {
                  v135[2] = v13;
                  v137 = v241[0];
                  *v135 = v241[0];
                  v135[1] = v241;
                  if ( *(_DWORD **)(v137 + 4) != v241 )
                    __fastfail(3u);
                  *(_DWORD *)(v137 + 4) = v135;
                  v241[0] = v135;
                  if ( !v134 )
                  {
LABEL_394:
                    while ( v136 != v241 )
                    {
                      v149 = (_DWORD *)v136[2];
                      v150 = v149[133];
                      v151 = v149[143];
                      if ( v151 )
                      {
                        v152 = (_DWORD *)(*(_DWORD *)(v151 + 532) + 128);
                      }
                      else
                      {
                        v152 = (_DWORD *)v149[134];
                        if ( PsCpuFairShareEnabled && v152 )
                          ObfReferenceObject(v149[148]);
                      }
                      KeInsertSchedulingGroup(v150 + 128, *(_DWORD *)(v150 + 128), *(_DWORD *)(v150 + 132), v152);
                      if ( v149[134] )
                        PspEnumJobsAndProcessesInJobHierarchy(
                          v149,
                          PspSetCpuRateControlJobPreCallback,
                          PspSetCpuRateControlJobPostCallback,
                          0,
                          0,
                          5);
                      PspEnumJobsAndProcessesInJobHierarchy(
                        v149,
                        PspSetCpuRateControlJobPreCallback,
                        PspSetCpuRateControlJobPostCallback,
                        0,
                        v149[133],
                        5);
                      v153 = *v136;
                      v154 = (_DWORD *)v136[1];
                      if ( *(_DWORD **)(*v136 + 4) != v136 || (_DWORD *)*v154 != v136 )
                        __fastfail(3u);
                      *v154 = v153;
                      *(_DWORD *)(v153 + 4) = v154;
                      ExFreePoolWithTag((unsigned int)v136);
                      v136 = (_DWORD *)v241[0];
                    }
                    v12 = 0;
                    goto LABEL_407;
                  }
                  while ( 1 )
                  {
                    if ( (v134[186] & 0x20) != 0 )
                      goto LABEL_394;
                    v138 = PspAllocateRateControl(2);
                    v134[133] = v138;
                    if ( !v138 )
                      goto LABEL_385;
                    *(_WORD *)(v138 + 128) = 10000;
                    *(_WORD *)(v138 + 130) = 10000;
                    *(_DWORD *)(v138 + 132) |= 3u;
                    *(_DWORD *)(v134[133] + 24) = *(_DWORD *)(v138 + 128);
                    *(_DWORD *)(v134[133] + 20) |= 0x40u;
                    v136 = (_DWORD *)ExAllocatePoolWithTag(1, 12, 1649046352);
                    if ( !v136 )
                      break;
                    __dmb(0xBu);
                    v139 = v134 + 186;
                    do
                      v140 = __ldrex(v139);
                    while ( __strex(v140 | 0x20, v139) );
                    __dmb(0xBu);
                    v136[2] = v134;
                    v141 = v241[0];
                    *v136 = v241[0];
                    v136[1] = v241;
                    if ( *(_DWORD **)(v141 + 4) != v241 )
                      __fastfail(3u);
                    *(_DWORD *)(v141 + 4) = v136;
                    v241[0] = v136;
                    v134 = (_DWORD *)v134[143];
                    if ( !v134 )
                      goto LABEL_394;
                  }
                  PspFreeRateControl((_DWORD *)v134[133], 2);
                  v134[133] = 0;
LABEL_385:
                  while ( 1 )
                  {
                    v142 = (_DWORD *)v241[0];
                    if ( (_DWORD *)v241[0] == v241 )
                      break;
                    v143 = *(_DWORD *)(v241[0] + 8);
                    v144 = *(_DWORD **)(v143 + 532);
                    if ( v144 )
                    {
                      PspFreeRateControl(v144, 2);
                      *(_DWORD *)(v143 + 532) = 0;
                      __dmb(0xBu);
                      v145 = (unsigned int *)(v143 + 744);
                      do
                        v146 = __ldrex(v145);
                      while ( __strex(v146 & 0xFFFFFFDF, v145) );
                      __dmb(0xBu);
                    }
                    v147 = *v142;
                    v148 = (_DWORD *)v142[1];
                    if ( *(_DWORD **)(*v142 + 4) != v142 || (_DWORD *)*v148 != v142 )
                      __fastfail(3u);
                    *v148 = v147;
                    *(_DWORD *)(v147 + 4) = v148;
                    ExFreePoolWithTag((unsigned int)v142);
                  }
                }
                v12 = -1073741670;
LABEL_407:
                if ( v12 < 0 )
                {
                  v157 = *(_DWORD **)(v13 + 532);
                  if ( v157 )
                  {
                    PspFreeRateControl(v157, 2);
                    *(_DWORD *)(v13 + 532) = 0;
                  }
                  goto LABEL_422;
                }
                __dmb(0xBu);
                v155 = (unsigned int *)(v13 + 744);
                do
                  v156 = __ldrex(v155);
                while ( __strex(v156 | 0x20, v155) );
                __dmb(0xBu);
                goto LABEL_418;
              }
            }
          }
LABEL_37:
          v12 = -1073741811;
LABEL_539:
          v58 = (int)v213;
          goto LABEL_540;
        case 16:
          v228 = *(_DWORD *)v5;
          v276[2] = v228;
          v58 = (int)v213;
          if ( (v228 & 0xFFFFE001) != 0 )
            goto LABEL_277;
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, 0);
          if ( v13 )
          {
            v166 = (unsigned __int8 *)(v13 + 552);
            v167 = KeAbPreAcquire(v13 + 552, 0, 0);
            v168 = v167;
            do
              v169 = __ldrex(v166);
            while ( __strex(v169 | 1, v166) );
            __dmb(0xBu);
            if ( (v169 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 552), v167, v13 + 552);
            if ( v168 )
              *(_BYTE *)(v168 + 14) |= 1u;
          }
          *(_DWORD *)(v13 + 428) = v228;
          v170 = (unsigned int *)(v13 + 552);
          __dmb(0xBu);
          do
            v171 = __ldrex(v170);
          while ( __strex(v171 - 1, v170) );
          if ( (v171 & 2) != 0 && (v171 & 4) == 0 )
            ExfTryToWakePushLock(v170);
          KeAbPostRelease((unsigned int)v170);
LABEL_443:
          v11 = ExReleaseResourceLite(v13 + 32);
LABEL_444:
          v12 = 0;
          goto LABEL_539;
        case 18:
          v11 = *(_DWORD *)v5;
          v163 = *(_DWORD *)(v5 + 4);
          v164 = *(_DWORD *)(v5 + 8);
          v165 = *(_DWORD *)(v5 + 12);
          v303[0] = *(_DWORD *)v5;
          v303[1] = v163;
          v303[2] = v164;
          v303[3] = v165;
          v58 = (int)v213;
          if ( !v303[0] || (v303[0] & 0xFFFFFFF8) != 0 )
            goto LABEL_277;
          v11 = PspFreezeJobTree((_DWORD *)v13, (int)v303, v164, 0, v209, v210);
          v12 = v11;
          if ( v11 < 0 )
            goto LABEL_540;
          *(_DWORD *)v5 = v303[0];
          v59 = a2;
          v60 = a1;
          goto LABEL_542;
        case 21:
          v243 = *(_BYTE *)v5;
          v58 = (int)v213;
          v11 = PspSetBackgroundJobTree(v13);
          v12 = v11;
          if ( v11 >= 0 )
            goto LABEL_428;
          goto LABEL_540;
        case 22:
          v172 = *(unsigned __int8 *)v5;
          v244 = *(_BYTE *)v5;
          v58 = (int)v213;
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, v14);
          if ( (*(_DWORD *)(v13 + 744) & 0x20) == 0 )
            goto LABEL_452;
          v173 = *(_DWORD *)(v13 + 532);
          v174 = *(_DWORD *)(v173 + 20);
          if ( (v174 & 0x40) != 0 )
            goto LABEL_452;
          if ( (v174 & 0x21) != 0 )
          {
            v12 = -1073741637;
          }
          else if ( ((*(_DWORD *)(v173 + 20) & 8) != 0) == (v172 != 0) )
          {
LABEL_452:
            v12 = -1073741811;
          }
          else
          {
            *(_DWORD *)(v173 + 20) = (v174 ^ (8 * (v172 != 0))) & 8 ^ v174;
            KeSetSchedulingGroupRankBias(*(_DWORD *)(v13 + 532) + 128, v172);
LABEL_450:
            v12 = 0;
          }
          v11 = ExReleaseResourceLite(v13 + 32);
          goto LABEL_540;
        case 23:
          if ( *(_BYTE *)v5 == 1 )
          {
            v58 = (int)v213;
            v11 = PspEnumJobsAndProcessesInJobHierarchy(
                    v13,
                    0,
                    PspEnableTimerVirtualization,
                    PspEnableProcessTimerVirtualization,
                    0,
                    0);
LABEL_428:
            v12 = 0;
          }
          else
          {
            v12 = -1073741811;
            v240 = -1073741811;
            v58 = (int)v213;
          }
          goto LABEL_540;
        case 24:
          v221 = *(_DWORD *)v5;
          v229 = *(_DWORD *)(v5 + 4);
          v273 = v221;
          v274 = v229;
          v58 = (int)v213;
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v229, v221);
          if ( (*(_DWORD *)(v13 + 744) & 0x20) == 0 )
            goto LABEL_452;
          v175 = *(_DWORD *)(v13 + 532);
          v176 = *(_DWORD *)(v175 + 20);
          if ( (v176 & 0x10) == 0 )
          {
            *(_DWORD *)(v175 + 20) = v176 | 0x10;
            KeInitializeDpc(v175 + 28, (int)PspJobCycleTimeNotificationDpcRoutine, v13);
          }
          KeSetSchedulingGroupCycleNotification(v175 + 128, v175 + 28, v221, v229);
          goto LABEL_450;
        case 25:
          ExAcquireResourceExclusiveLite(v13 + 32, 1, v15, v14);
          KeResetEvent(v13);
          goto LABEL_443;
        case 27:
          if ( v13 )
          {
            v177 = (unsigned __int8 *)(v13 + 552);
            v178 = KeAbPreAcquire(v13 + 552, 0, 0);
            v179 = v178;
            do
              v180 = __ldrex(v177);
            while ( __strex(v180 | 1, v177) );
            __dmb(0xBu);
            if ( (v180 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v13 + 552), v178, v13 + 552);
            if ( v179 )
              *(_BYTE *)(v179 + 14) |= 1u;
          }
          *(_DWORD *)(v13 + 344) = 0;
          *(_DWORD *)(v13 + 340) = 0;
          v181 = (unsigned int *)(v13 + 552);
          __dmb(0xBu);
          do
            v182 = __ldrex(v181);
          while ( __strex(v182 - 1, v181) );
          if ( (v182 & 2) != 0 && (v182 & 4) == 0 )
            ExfTryToWakePushLock(v181);
          v11 = KeAbPostRelease((unsigned int)v181);
          goto LABEL_444;
        case 31:
          v242 = 0;
          LOBYTE(v235) = 0;
          v237 = 0;
          v236 = 0;
          v233 = 0;
          v250 = 0;
          v264 = 0;
          v253 = 0;
          v184 = memmove((int)v277, v5, a4);
          v185 = (_WORD *)v278;
          if ( v278 )
          {
            v186 = v281;
            if ( v281 )
            {
              if ( (v278 & 1) != 0 )
                ExRaiseDatatypeMisalignment(v184);
              if ( v281 + v278 > MmUserProbeAddress || v281 + v278 < v278 )
                *(_BYTE *)MmUserProbeAddress = 0;
            }
            v187 = 1;
            v275 = 1;
            if ( v230 == 1 )
            {
              v187 = 9;
              v275 = 9;
            }
            v264 = v252;
            v11 = ExAllocatePoolWithQuotaTag(v187, v186, 1649046352);
            v253 = v11;
            if ( !v11 )
            {
              v12 = -1073741801;
              v240 = -1073741801;
LABEL_526:
              v58 = (int)v213;
              goto LABEL_527;
            }
            v252[0] = 0;
            v252[1] = v281;
            v12 = RtlUnicodeStringCbCopyStringN(v252, v185, v281);
            v240 = v12;
            v11 = v253;
          }
          else
          {
            v11 = 0;
          }
          v188 = v214;
          if ( v12 < 0 )
            goto LABEL_526;
          v257 = 1;
          if ( (v280 & 0xFFFFFFFE) != 0 || v279 )
          {
            v12 = -1073741811;
            goto LABEL_526;
          }
          --*(_WORD *)(v214 + 310);
          while ( 1 )
          {
            v189 = *(_DWORD *)(v13 + 576);
            __dmb(0xBu);
            v223 = v189;
            __dmb(0xBu);
            ExAcquireResourceExclusiveLite(v189 + 32, 1, v188, v189);
            v190 = v223;
            __dmb(0xBu);
            v191 = *(_DWORD *)(v13 + 576);
            __dmb(0xBu);
            if ( v190 == v191 )
              break;
            __dmb(0xBu);
            ExReleaseResourceLite(v223 + 32);
          }
          v236 = v223;
          v248 = v223;
          __dmb(0xBu);
          v192 = 0;
          v193 = &v248;
          v194 = (int)v232;
          while ( 1 )
          {
            v196 = *v193++;
            v195 = v196;
            if ( v232 == (_DWORD *)v196 )
              break;
            if ( ++v192 )
            {
              ExAcquireResourceExclusiveLite((int)(v232 + 8), 1, v192, v195);
              break;
            }
          }
          v197 = v280;
          if ( (v280 & 1) != 0 )
          {
            if ( *(_DWORD *)(v194 + 740) )
            {
LABEL_510:
              v199 = IoSetFlowPolicy(v194 + 704, (int)v264, v277[0], v277[1], v277[2], v277[3], v277[4], v277[5]);
LABEL_514:
              v12 = v199;
              if ( v199 >= 0 )
              {
                v12 = PspSetJobRateControl(v194, 1, v197);
                if ( v12 >= 0 )
                  goto LABEL_518;
              }
              goto LABEL_516;
            }
            v12 = IoCreateFlow(v194 + 704);
            if ( v12 == -1073741822 )
            {
              v12 = IoEnableIoQos();
              if ( v12 < 0 )
                goto LABEL_516;
              v12 = IoCreateFlow(v194 + 704);
            }
            if ( v12 >= 0 )
            {
              v242 = 1;
              v237 = PspIoRateControlProcessCallback;
              v233 = (int)v276;
              v276[0] = v194 + 704;
              v197 = v280;
              if ( v230 == 1 )
                v198 = 6;
              else
                v198 = 0;
              v276[1] = v198;
              goto LABEL_510;
            }
          }
          else
          {
            if ( (*(_DWORD *)(v194 + 744) & 0x10000000) != 0 )
            {
              v199 = IoDeleteFlow(v194 + 704);
              goto LABEL_514;
            }
            v12 = -1073741811;
          }
LABEL_516:
          if ( v242 )
            IoDeleteFlow(v194 + 704);
LABEL_518:
          v200 = 0;
          v201 = &v248;
          while ( 1 )
          {
            v202 = *v201++;
            if ( v194 == v202 )
              break;
            if ( ++v200 )
            {
              ExReleaseResourceLite(v194 + 32);
              break;
            }
          }
          v203 = ExReleaseResourceLite(v236 + 32);
          v204 = *(_WORD *)(v214 + 310) + 1;
          *(_WORD *)(v214 + 310) = v204;
          if ( !v204 && *(_DWORD *)(v214 + 100) != v214 + 100 )
            KiCheckForKernelApcDelivery(v203);
          v58 = v215;
          v11 = v253;
LABEL_527:
          if ( v11 )
            v11 = ExFreePoolWithTag(v11);
          goto LABEL_540;
        case 32:
          v183 = v13;
          v60 = a1;
          v11 = PspSetNetRateControl(a1, v5, a4, v183);
          v12 = v11;
          v58 = (int)v213;
          v59 = a2;
          goto LABEL_542;
        case 35:
          v11 = SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v230);
          if ( !v11 )
            goto LABEL_46;
          v11 = PspCreateSilo(v13);
          v12 = v11;
          goto LABEL_539;
        case 37:
          v11 = SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v230);
          if ( !v11 )
            goto LABEL_46;
          v12 = -1073740535;
          v11 = PspReferenceJobSilo(v13, v214);
          v205 = v11;
          if ( !v11 )
            goto LABEL_539;
          v206 = PsSetSiloObjectRootDirectoryByPointer(v11, v5);
          goto LABEL_534;
        case 40:
          v11 = SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v230);
          if ( v11 )
          {
            v12 = -1073740535;
            v11 = PspReferenceJobSilo(v13, v214);
            v205 = v11;
            if ( v11 )
            {
              v206 = PsSetSiloObjectServerPropertyByPointer(v11, (_DWORD *)v5);
LABEL_534:
              v12 = v206;
              v11 = PspDereferenceSiloObject(v205);
            }
          }
          else
          {
LABEL_46:
            v12 = -1073741727;
          }
          goto LABEL_539;
        default:
          v12 = -1073741821;
          goto LABEL_539;
      }
    }
    if ( a4 == 48 )
      goto LABEL_16;
    v7 = a4 == 56;
  }
  if ( v7 )
    goto LABEL_16;
  return -1073741820;
}
