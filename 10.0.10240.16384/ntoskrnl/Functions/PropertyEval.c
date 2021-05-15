// PropertyEval 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PropertyEval(unsigned int a1, char *a2, unsigned int a3, int a4, int a5, unsigned __int8 *a6, unsigned int a7, int *a8)
{
  double v8; // d0
  int v9; // r8
  int v12; // r9
  int v13; // r2
  unsigned int v14; // r4
  int v15; // r0
  bool v16; // zf
  int v17; // r2
  int v18; // r3
  int v19; // r3
  unsigned int v21; // r3
  bool v22; // zf
  int v23; // r2
  int v24; // r3
  bool v25; // cc
  int v26; // r2
  int v27; // r3
  int v28; // r2
  int v29; // r3
  bool v30; // cc
  int v31; // r2
  int v32; // r3
  int v33; // r2
  int v34; // r3
  bool v35; // cc
  int v36; // r2
  int v37; // r3
  signed int v38; // r2
  signed int v39; // r3
  bool v40; // cc
  int v41; // r2
  int v42; // r3
  unsigned int v43; // r2
  unsigned int v44; // r3
  bool v45; // cc
  unsigned int v46; // r2
  unsigned int v47; // r3
  bool v48; // cf
  unsigned int v49; // r2
  unsigned int v50; // r3
  bool v51; // cf
  unsigned int v52; // r2
  unsigned int v53; // r3
  bool v54; // cc
  int v55; // r1 OVERLAPPED
  int v56; // r2 OVERLAPPED
  unsigned int v57; // r0
  int v58; // r1 OVERLAPPED
  int v59; // r2 OVERLAPPED
  unsigned int v60; // r0
  int v61; // r1 OVERLAPPED
  int v62; // r2 OVERLAPPED
  unsigned int v63; // r0
  int v64; // r1 OVERLAPPED
  int v65; // r2 OVERLAPPED
  unsigned int v66; // r0
  int v67; // r2
  int v68; // r1
  __int64 v69; // kr20_8
  _DWORD *v70; // r3
  int v71; // r0
  unsigned int v72; // r2 OVERLAPPED
  unsigned int v73; // r2 OVERLAPPED
  unsigned int v74; // r2 OVERLAPPED
  unsigned int v75; // r2 OVERLAPPED
  int v76; // r3
  float v77; // s0
  bool v78; // fcf
  bool v79; // fzf
  double v80; // d1
  int v81; // r3
  float v82; // s0
  bool v83; // fnf
  double v84; // d1
  int v85; // r3
  float v86; // s0
  bool v87; // fcf
  double v88; // d1
  int v89; // r3
  float v90; // s0
  bool v91; // fzf
  bool v92; // fnf
  double v93; // d1
  int v94; // r3
  float v95; // s0
  bool v96; // fzf
  double v97; // d1
  int v98; // r3
  double v99; // d0
  unsigned int v100; // r3
  int v101; // r3
  double v102; // d0
  unsigned int v103; // r3
  int v104; // r3
  double v105; // d0
  unsigned int v106; // r3
  int v107; // r3
  double v108; // d0
  unsigned int v109; // r3
  int v110; // r3
  double v111; // d0
  unsigned int v112; // r2
  unsigned int v113; // r1
  unsigned int v114; // r2
  unsigned int v115; // r1
  unsigned int v116; // r2
  unsigned int v117; // r1
  unsigned int v118; // r2
  unsigned int v119; // r1
  int v120; // r2
  _DWORD *v121; // r3
  int v122; // r1
  unsigned int v123; // r3
  int v124; // r2
  unsigned int v125; // r2
  unsigned int v126; // r3
  unsigned int v127; // r2
  unsigned int v128; // r3
  unsigned int v129; // r2
  unsigned int v130; // r3
  unsigned int v131; // r2
  unsigned int v132; // r3
  int v133; // r2
  int v134; // r3
  int v135; // r2
  bool v136; // cc
  int v137; // r2
  bool v138; // cc
  int v139; // r2
  bool v140; // cc
  int v141; // r2
  bool v142; // cc
  int v143; // r2
  int v144; // r1
  int v145; // r3
  __int64 v146; // kr88_8
  __int64 v147; // kr90_8
  int v148; // r2
  int v149; // r1
  int v150; // r3
  __int64 v151; // kr98_8
  __int64 v152; // krA0_8
  unsigned int v153; // r0
  unsigned int v154; // r1
  int v155; // r3
  unsigned int v156; // r0
  unsigned int v157; // r1
  int v158; // r3
  unsigned int v159; // r0
  unsigned int v160; // r1
  int v161; // r3
  unsigned int v162; // r0
  unsigned int v163; // r1
  int v164; // r3
  int v165; // r0
  int v166; // r2
  int v167; // r3
  int v168; // r1
  __int64 v169; // krA8_8
  int v170; // r2
  unsigned int v171; // r3
  bool v172; // cf
  bool v173; // cc
  int v174; // r2
  unsigned int v175; // r3
  bool v176; // cf
  bool v177; // cc
  int v178; // r2
  unsigned int v179; // r3
  bool v180; // cf
  bool v181; // cc
  int v182; // r2
  unsigned int v183; // r3
  bool v184; // cf
  bool v185; // cc
  unsigned int v186; // r3
  unsigned int v187; // r3
  unsigned int v188; // r3
  unsigned int v189; // r3
  int v190; // r3
  int v191; // r3
  int v192; // r3
  int v193; // r3
  int v194; // r3
  int v195; // r3
  int v196; // r3
  int v197; // r3
  int v198; // r3
  int v199; // r3
  unsigned int v200; // r3
  unsigned int v201; // r3
  unsigned int v202; // r3
  unsigned int v203; // r3
  unsigned int v204; // r3
  unsigned int v205; // r1
  int v206; // r2
  bool v207; // zf
  int v208; // r0

  v9 = 0;
  *a8 = 0;
  v12 = a4 & 0x10000;
  v13 = a4 & 0x20000;
  v14 = a4 & 0xF000FFFF;
  if ( (a4 & 0x20000) != 0 && a1 != 18 )
    return sub_7EBFE8();
  if ( v14 == 1 )
  {
    if ( !a1 )
    {
LABEL_31:
      v19 = 0;
      goto LABEL_25;
    }
LABEL_24:
    v19 = 1;
LABEL_25:
    *a8 = v19;
    goto LABEL_26;
  }
  if ( a1 && a5 )
  {
    if ( a1 <= 0x1003 )
    {
      if ( a1 != 4099 )
      {
        switch ( a1 )
        {
          case 1u:
            if ( a5 == 1 && v14 == 2 )
              goto LABEL_31;
            goto LABEL_43;
          case 2u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    goto LABEL_35;
                  case 3u:
                    v38 = *a2;
                    goto LABEL_122;
                  case 4u:
                    v33 = *a2;
                    goto LABEL_111;
                  case 5u:
                    v28 = *a2;
                    goto LABEL_101;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *a2;
                goto LABEL_92;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *a2;
                    goto LABEL_148;
                  case 3u:
                    v38 = *a2;
                    goto LABEL_145;
                  case 4u:
                    v33 = *a2;
                    goto LABEL_142;
                  case 5u:
                    v28 = *a2;
                    goto LABEL_139;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *a2;
                goto LABEL_136;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *a2;
                    goto LABEL_167;
                  case 3u:
                    v38 = *a2;
                    goto LABEL_164;
                  case 4u:
                    v33 = *a2;
                    goto LABEL_161;
                  case 5u:
                    v28 = *a2;
                    goto LABEL_158;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *a2;
                goto LABEL_155;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *a2;
                    goto LABEL_186;
                  case 3u:
                    v38 = *a2;
                    goto LABEL_183;
                  case 4u:
                    v33 = *a2;
                    goto LABEL_180;
                  case 5u:
                    v28 = *a2;
                    goto LABEL_177;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *a2;
                goto LABEL_174;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *a2;
                    goto LABEL_195;
                  case 3u:
                    v38 = *a2;
                    goto LABEL_124;
                  case 4u:
                    v33 = *a2;
                    goto LABEL_113;
                  case 5u:
                    v28 = *a2;
                    goto LABEL_103;
                  case 6u:
                    v23 = *a2;
                    goto LABEL_93;
                }
                goto LABEL_43;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *a2;
                    goto LABEL_42;
                  case 3u:
                    v52 = *a2;
                    goto LABEL_229;
                  case 4u:
                    v49 = *a2;
                    goto LABEL_220;
                  case 5u:
                    v46 = *a2;
                    goto LABEL_210;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = *a2;
                goto LABEL_202;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *a2;
                    goto LABEL_271;
                  case 3u:
                    v64 = *a2;
                    goto LABEL_264;
                  case 4u:
                    v61 = *a2;
                    goto LABEL_257;
                  case 5u:
                    v58 = *a2;
                    goto LABEL_250;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *a2;
                goto LABEL_244;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *a2;
                    goto LABEL_275;
                  case 3u:
                    v64 = *a2;
                    goto LABEL_305;
                  case 4u:
                    v61 = *a2;
                    goto LABEL_298;
                  case 5u:
                    v58 = *a2;
                    goto LABEL_291;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *a2;
                goto LABEL_285;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v94 = *a2;
                    goto LABEL_350;
                  case 3u:
                    v89 = *a2;
                    goto LABEL_341;
                  case 4u:
                    v85 = *a2;
                    goto LABEL_332;
                  case 5u:
                    v81 = *a2;
                    goto LABEL_323;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v76 = *a2;
                goto LABEL_316;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v110 = *a2;
                    goto LABEL_385;
                  case 3u:
                    v107 = *a2;
                    goto LABEL_379;
                  case 4u:
                    v104 = *a2;
                    goto LABEL_373;
                  case 5u:
                    v101 = *a2;
                    goto LABEL_367;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v98 = *a2;
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_362;
          case 3u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_36;
                  case 3u:
                    v38 = (unsigned __int8)*a2;
                    goto LABEL_122;
                  case 4u:
                    v33 = (unsigned __int8)*a2;
                    goto LABEL_111;
                  case 5u:
                    v28 = (unsigned __int8)*a2;
                    goto LABEL_101;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = (unsigned __int8)*a2;
                goto LABEL_92;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_148;
                  case 3u:
                    v52 = (unsigned __int8)*a2;
                    v53 = *a6;
                    goto LABEL_232;
                  case 4u:
                    v49 = (unsigned __int8)*a2;
                    v50 = *a6;
                    goto LABEL_223;
                  case 5u:
                    v46 = (unsigned __int8)*a2;
                    v47 = *a6;
                    goto LABEL_213;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = (unsigned __int8)*a2;
                v44 = *a6;
                goto LABEL_204;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_167;
                  case 3u:
                    v38 = (unsigned __int8)*a2;
                    goto LABEL_164;
                  case 4u:
                    v33 = (unsigned __int8)*a2;
                    goto LABEL_161;
                  case 5u:
                    v28 = (unsigned __int8)*a2;
                    goto LABEL_158;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = (unsigned __int8)*a2;
                goto LABEL_155;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_186;
                  case 3u:
                    v52 = (unsigned __int8)*a2;
                    goto LABEL_231;
                  case 4u:
                    v49 = (unsigned __int8)*a2;
                    goto LABEL_222;
                  case 5u:
                    v46 = (unsigned __int8)*a2;
                    goto LABEL_212;
                  case 6u:
                    v43 = (unsigned __int8)*a2;
                    goto LABEL_203;
                }
                goto LABEL_43;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_195;
                  case 3u:
                    v38 = (unsigned __int8)*a2;
                    goto LABEL_124;
                  case 4u:
                    v33 = (unsigned __int8)*a2;
                    goto LABEL_113;
                  case 5u:
                    v28 = (unsigned __int8)*a2;
                    goto LABEL_103;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = (unsigned __int8)*a2;
                goto LABEL_93;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v17 = (unsigned __int8)*a2;
                    goto LABEL_42;
                  case 3u:
                    v52 = (unsigned __int8)*a2;
                    goto LABEL_229;
                  case 4u:
                    v49 = (unsigned __int8)*a2;
                    goto LABEL_220;
                  case 5u:
                    v46 = (unsigned __int8)*a2;
                    goto LABEL_210;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = (unsigned __int8)*a2;
                goto LABEL_202;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v120 = (unsigned __int8)*a2;
                    goto LABEL_472;
                  case 3u:
                    v118 = (unsigned __int8)*a2;
                    goto LABEL_468;
                  case 4u:
                    v116 = (unsigned __int8)*a2;
                    goto LABEL_463;
                  case 5u:
                    v114 = (unsigned __int8)*a2;
                    goto LABEL_458;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v112 = (unsigned __int8)*a2;
                goto LABEL_453;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v120 = (unsigned __int8)*a2;
                    goto LABEL_474;
                  case 3u:
                    v118 = (unsigned __int8)*a2;
                    goto LABEL_495;
                  case 4u:
                    v116 = (unsigned __int8)*a2;
                    goto LABEL_491;
                  case 5u:
                    v114 = (unsigned __int8)*a2;
                    goto LABEL_487;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v112 = (unsigned __int8)*a2;
                goto LABEL_483;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v94 = (unsigned __int8)*a2;
                    goto LABEL_350;
                  case 3u:
                    v89 = (unsigned __int8)*a2;
                    goto LABEL_341;
                  case 4u:
                    v85 = (unsigned __int8)*a2;
                    goto LABEL_332;
                  case 5u:
                    v81 = (unsigned __int8)*a2;
                    goto LABEL_323;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v76 = (unsigned __int8)*a2;
                goto LABEL_316;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v21 = (unsigned __int8)*a2;
                    goto LABEL_387;
                  case 3u:
                    v109 = (unsigned __int8)*a2;
                    goto LABEL_381;
                  case 4u:
                    v106 = (unsigned __int8)*a2;
                    goto LABEL_375;
                  case 5u:
                    v103 = (unsigned __int8)*a2;
                    goto LABEL_369;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v100 = (unsigned __int8)*a2;
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_363;
          case 4u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v124 = (char)*a6;
                    v123 = *(__int16 *)a2;
                    goto LABEL_522;
                  case 3u:
                    v41 = (char)*a6;
                    v42 = *(__int16 *)a2;
                    goto LABEL_127;
                  case 4u:
                    v36 = (char)*a6;
                    v37 = *(__int16 *)a2;
                    goto LABEL_116;
                  case 5u:
                    v31 = (char)*a6;
                    v32 = *(__int16 *)a2;
                    goto LABEL_106;
                  case 6u:
                    v26 = (char)*a6;
                    v27 = *(__int16 *)a2;
                    goto LABEL_95;
                }
                goto LABEL_43;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(__int16 *)a2;
LABEL_148:
                    v18 = *a6;
                    goto LABEL_21;
                  case 3u:
                    v38 = *(__int16 *)a2;
LABEL_145:
                    v39 = *a6;
                    goto LABEL_125;
                  case 4u:
                    v33 = *(__int16 *)a2;
LABEL_142:
                    v34 = *a6;
                    goto LABEL_114;
                  case 5u:
                    v28 = *(__int16 *)a2;
LABEL_139:
                    v29 = *a6;
                    goto LABEL_104;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(__int16 *)a2;
LABEL_136:
                v24 = *a6;
                goto LABEL_94;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(__int16 *)a2;
                    goto LABEL_167;
                  case 3u:
                    v38 = *(__int16 *)a2;
                    goto LABEL_164;
                  case 4u:
                    v33 = *(__int16 *)a2;
                    goto LABEL_161;
                  case 5u:
                    v28 = *(__int16 *)a2;
                    goto LABEL_158;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(__int16 *)a2;
                goto LABEL_155;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(__int16 *)a2;
                    goto LABEL_186;
                  case 3u:
                    v38 = *(__int16 *)a2;
LABEL_183:
                    v39 = *(unsigned __int16 *)a6;
                    goto LABEL_125;
                  case 4u:
                    v33 = *(__int16 *)a2;
LABEL_180:
                    v34 = *(unsigned __int16 *)a6;
                    goto LABEL_114;
                  case 5u:
                    v28 = *(__int16 *)a2;
LABEL_177:
                    v29 = *(unsigned __int16 *)a6;
                    goto LABEL_104;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(__int16 *)a2;
LABEL_174:
                v24 = *(unsigned __int16 *)a6;
                goto LABEL_94;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(__int16 *)a2;
                    goto LABEL_195;
                  case 3u:
                    v38 = *(__int16 *)a2;
                    goto LABEL_124;
                  case 4u:
                    v33 = *(__int16 *)a2;
                    goto LABEL_113;
                  case 5u:
                    v28 = *(__int16 *)a2;
                    goto LABEL_103;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(__int16 *)a2;
                goto LABEL_93;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(__int16 *)a2;
                    goto LABEL_42;
                  case 3u:
                    v52 = *(__int16 *)a2;
                    goto LABEL_229;
                  case 4u:
                    v49 = *(__int16 *)a2;
                    goto LABEL_220;
                  case 5u:
                    v46 = *(__int16 *)a2;
                    goto LABEL_210;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = *(__int16 *)a2;
                goto LABEL_202;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *(__int16 *)a2;
LABEL_271:
                    v68 = v67 >> 31;
                    goto LABEL_273;
                  case 3u:
                    v64 = *(__int16 *)a2;
LABEL_264:
                    v65 = v64 >> 31;
                    goto LABEL_266;
                  case 4u:
                    v61 = *(__int16 *)a2;
LABEL_257:
                    v62 = v61 >> 31;
                    goto LABEL_259;
                  case 5u:
                    v58 = *(__int16 *)a2;
LABEL_250:
                    v59 = v58 >> 31;
                    goto LABEL_252;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *(__int16 *)a2;
LABEL_244:
                v56 = v55 >> 31;
                goto LABEL_245;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *(__int16 *)a2;
LABEL_275:
                    v68 = v67 >> 31;
                    goto LABEL_276;
                  case 3u:
                    v64 = *(__int16 *)a2;
LABEL_305:
                    v75 = v64 >> 31;
                    goto LABEL_307;
                  case 4u:
                    v61 = *(__int16 *)a2;
LABEL_298:
                    v74 = v61 >> 31;
                    goto LABEL_300;
                  case 5u:
                    v58 = *(__int16 *)a2;
LABEL_291:
                    v73 = v58 >> 31;
                    goto LABEL_293;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *(__int16 *)a2;
LABEL_285:
                v72 = v55 >> 31;
                goto LABEL_286;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v94 = *(__int16 *)a2;
                    goto LABEL_350;
                  case 3u:
                    v89 = *(__int16 *)a2;
                    goto LABEL_341;
                  case 4u:
                    v85 = *(__int16 *)a2;
                    goto LABEL_332;
                  case 5u:
                    v81 = *(__int16 *)a2;
                    goto LABEL_323;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v76 = *(__int16 *)a2;
                goto LABEL_316;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v110 = *(__int16 *)a2;
                    goto LABEL_385;
                  case 3u:
                    v107 = *(__int16 *)a2;
                    goto LABEL_379;
                  case 4u:
                    v104 = *(__int16 *)a2;
                    goto LABEL_373;
                  case 5u:
                    v101 = *(__int16 *)a2;
                    goto LABEL_367;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v98 = *(__int16 *)a2;
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_362;
          case 5u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(unsigned __int16 *)a2;
                    goto LABEL_36;
                  case 3u:
                    v38 = *(unsigned __int16 *)a2;
LABEL_122:
                    v39 = (char)*a6;
                    goto LABEL_125;
                  case 4u:
                    v33 = *(unsigned __int16 *)a2;
LABEL_111:
                    v34 = (char)*a6;
                    goto LABEL_114;
                  case 5u:
                    v28 = *(unsigned __int16 *)a2;
LABEL_101:
                    v29 = (char)*a6;
                    goto LABEL_104;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(unsigned __int16 *)a2;
LABEL_92:
                v24 = (char)*a6;
                goto LABEL_94;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *a6;
                    v123 = *(unsigned __int16 *)a2;
                    goto LABEL_522;
                  case 3u:
                    v131 = *a6;
                    v132 = *(unsigned __int16 *)a2;
                    goto LABEL_626;
                  case 4u:
                    v129 = *a6;
                    v130 = *(unsigned __int16 *)a2;
                    goto LABEL_622;
                  case 5u:
                    v127 = *a6;
                    v128 = *(unsigned __int16 *)a2;
                    goto LABEL_618;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v125 = *a6;
                v126 = *(unsigned __int16 *)a2;
                goto LABEL_614;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(unsigned __int16 *)a2;
LABEL_167:
                    v18 = *(__int16 *)a6;
                    goto LABEL_21;
                  case 3u:
                    v38 = *(unsigned __int16 *)a2;
LABEL_164:
                    v39 = *(__int16 *)a6;
                    goto LABEL_125;
                  case 4u:
                    v33 = *(unsigned __int16 *)a2;
LABEL_161:
                    v34 = *(__int16 *)a6;
                    goto LABEL_114;
                  case 5u:
                    v28 = *(unsigned __int16 *)a2;
LABEL_158:
                    v29 = *(__int16 *)a6;
                    goto LABEL_104;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(unsigned __int16 *)a2;
LABEL_155:
                v24 = *(__int16 *)a6;
                goto LABEL_94;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(unsigned __int16 *)a2;
LABEL_186:
                    v18 = *(unsigned __int16 *)a6;
                    goto LABEL_21;
                  case 3u:
                    v52 = *(unsigned __int16 *)a2;
LABEL_231:
                    v53 = *(unsigned __int16 *)a6;
                    goto LABEL_232;
                  case 4u:
                    v49 = *(unsigned __int16 *)a2;
LABEL_222:
                    v50 = *(unsigned __int16 *)a6;
                    goto LABEL_223;
                  case 5u:
                    v46 = *(unsigned __int16 *)a2;
LABEL_212:
                    v47 = *(unsigned __int16 *)a6;
                    goto LABEL_213;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = *(unsigned __int16 *)a2;
LABEL_203:
                v44 = *(unsigned __int16 *)a6;
                goto LABEL_204;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(unsigned __int16 *)a2;
                    goto LABEL_195;
                  case 3u:
                    v38 = *(unsigned __int16 *)a2;
                    goto LABEL_124;
                  case 4u:
                    v33 = *(unsigned __int16 *)a2;
                    goto LABEL_113;
                  case 5u:
                    v28 = *(unsigned __int16 *)a2;
                    goto LABEL_103;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v23 = *(unsigned __int16 *)a2;
                goto LABEL_93;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v17 = *(unsigned __int16 *)a2;
                    goto LABEL_42;
                  case 3u:
                    v52 = *(unsigned __int16 *)a2;
                    goto LABEL_229;
                  case 4u:
                    v49 = *(unsigned __int16 *)a2;
                    goto LABEL_220;
                  case 5u:
                    v46 = *(unsigned __int16 *)a2;
                    goto LABEL_210;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = *(unsigned __int16 *)a2;
                goto LABEL_202;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v120 = *(unsigned __int16 *)a2;
                    goto LABEL_472;
                  case 3u:
                    v118 = *(unsigned __int16 *)a2;
                    goto LABEL_468;
                  case 4u:
                    v116 = *(unsigned __int16 *)a2;
                    goto LABEL_463;
                  case 5u:
                    v114 = *(unsigned __int16 *)a2;
                    goto LABEL_458;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v112 = *(unsigned __int16 *)a2;
                goto LABEL_453;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v120 = *(unsigned __int16 *)a2;
                    goto LABEL_474;
                  case 3u:
                    v118 = *(unsigned __int16 *)a2;
                    goto LABEL_495;
                  case 4u:
                    v116 = *(unsigned __int16 *)a2;
                    goto LABEL_491;
                  case 5u:
                    v114 = *(unsigned __int16 *)a2;
                    goto LABEL_487;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v112 = *(unsigned __int16 *)a2;
                goto LABEL_483;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v94 = *(unsigned __int16 *)a2;
                    goto LABEL_350;
                  case 3u:
                    v89 = *(unsigned __int16 *)a2;
                    goto LABEL_341;
                  case 4u:
                    v85 = *(unsigned __int16 *)a2;
                    goto LABEL_332;
                  case 5u:
                    v81 = *(unsigned __int16 *)a2;
                    goto LABEL_323;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v76 = *(unsigned __int16 *)a2;
                goto LABEL_316;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v21 = *(unsigned __int16 *)a2;
                    goto LABEL_387;
                  case 3u:
                    v109 = *(unsigned __int16 *)a2;
                    goto LABEL_381;
                  case 4u:
                    v106 = *(unsigned __int16 *)a2;
                    goto LABEL_375;
                  case 5u:
                    v103 = *(unsigned __int16 *)a2;
                    goto LABEL_369;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v100 = *(unsigned __int16 *)a2;
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_363;
          case 6u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v124 = (char)*a6;
                    goto LABEL_722;
                  case 3u:
                    v41 = (char)*a6;
                    goto LABEL_719;
                  case 4u:
                    v36 = (char)*a6;
                    goto LABEL_716;
                  case 5u:
                    v31 = (char)*a6;
                    goto LABEL_713;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v26 = (char)*a6;
                goto LABEL_710;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *a6;
                    goto LABEL_722;
                  case 3u:
                    v41 = *a6;
                    goto LABEL_719;
                  case 4u:
                    v36 = *a6;
                    goto LABEL_716;
                  case 5u:
                    v31 = *a6;
                    goto LABEL_713;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v26 = *a6;
                goto LABEL_710;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *(__int16 *)a6;
                    goto LABEL_722;
                  case 3u:
                    v41 = *(__int16 *)a6;
                    goto LABEL_719;
                  case 4u:
                    v36 = *(__int16 *)a6;
                    goto LABEL_716;
                  case 5u:
                    v31 = *(__int16 *)a6;
                    goto LABEL_713;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v26 = *(__int16 *)a6;
                goto LABEL_710;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *(unsigned __int16 *)a6;
LABEL_722:
                    v123 = *(_DWORD *)a2;
                    goto LABEL_522;
                  case 3u:
                    v41 = *(unsigned __int16 *)a6;
LABEL_719:
                    v42 = *(_DWORD *)a2;
LABEL_127:
                    v40 = v42 <= v41;
                    goto LABEL_128;
                  case 4u:
                    v36 = *(unsigned __int16 *)a6;
LABEL_716:
                    v37 = *(_DWORD *)a2;
LABEL_116:
                    v35 = v37 < v36;
                    goto LABEL_117;
                  case 5u:
                    v31 = *(unsigned __int16 *)a6;
LABEL_713:
                    v32 = *(_DWORD *)a2;
LABEL_106:
                    v30 = v32 < v31;
                    goto LABEL_107;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v26 = *(unsigned __int16 *)a6;
LABEL_710:
                v27 = *(_DWORD *)a2;
LABEL_95:
                v25 = v27 <= v26;
                goto LABEL_96;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    goto LABEL_194;
                  case 3u:
                    v38 = *(_DWORD *)a2;
LABEL_124:
                    v39 = *(_DWORD *)a6;
LABEL_125:
                    v40 = v38 <= v39;
                    goto LABEL_128;
                  case 4u:
                    v33 = *(_DWORD *)a2;
LABEL_113:
                    v34 = *(_DWORD *)a6;
LABEL_114:
                    v35 = v33 < v34;
LABEL_117:
                    if ( v35 )
                      goto LABEL_24;
                    break;
                  case 5u:
                    v28 = *(_DWORD *)a2;
LABEL_103:
                    v29 = *(_DWORD *)a6;
LABEL_104:
                    v30 = v28 < v29;
                    goto LABEL_107;
                  case 6u:
                    v23 = *(_DWORD *)a2;
LABEL_93:
                    v24 = *(_DWORD *)a6;
LABEL_94:
                    v25 = v23 <= v24;
LABEL_96:
                    if ( v25 )
                      goto LABEL_24;
                    break;
                  default:
                    goto LABEL_43;
                }
                goto LABEL_31;
              case 7:
                goto LABEL_40;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *(_DWORD *)a2;
                    v68 = *(int *)a2 >> 31;
                    goto LABEL_273;
                  case 3u:
                    v64 = *(_DWORD *)a2;
                    v65 = *(int *)a2 >> 31;
                    goto LABEL_266;
                  case 4u:
                    v61 = *(_DWORD *)a2;
                    v62 = *(int *)a2 >> 31;
                    goto LABEL_259;
                  case 5u:
                    v58 = *(_DWORD *)a2;
                    v59 = *(int *)a2 >> 31;
                    goto LABEL_252;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *(_DWORD *)a2;
                v56 = *(int *)a2 >> 31;
                goto LABEL_245;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v67 = *(_DWORD *)a2;
                    v68 = *(int *)a2 >> 31;
                    goto LABEL_276;
                  case 3u:
                    v64 = *(_DWORD *)a2;
                    v75 = *(int *)a2 >> 31;
                    goto LABEL_307;
                  case 4u:
                    v61 = *(_DWORD *)a2;
                    v74 = *(int *)a2 >> 31;
                    goto LABEL_300;
                  case 5u:
                    v58 = *(_DWORD *)a2;
                    v73 = *(int *)a2 >> 31;
                    goto LABEL_293;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v55 = *(_DWORD *)a2;
                v72 = *(int *)a2 >> 31;
                goto LABEL_286;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v94 = *(_DWORD *)a2;
LABEL_350:
                    v95 = (float)v94;
                    goto LABEL_351;
                  case 3u:
                    v89 = *(_DWORD *)a2;
LABEL_341:
                    v90 = (float)v89;
                    goto LABEL_343;
                  case 4u:
                    v85 = *(_DWORD *)a2;
LABEL_332:
                    v86 = (float)v85;
                    goto LABEL_334;
                  case 5u:
                    v81 = *(_DWORD *)a2;
LABEL_323:
                    v82 = (float)v81;
                    goto LABEL_325;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v76 = *(_DWORD *)a2;
LABEL_316:
                v77 = (float)v76;
                goto LABEL_317;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v110 = *(_DWORD *)a2;
LABEL_385:
                    v111 = (double)v110;
                    goto LABEL_388;
                  case 3u:
                    v107 = *(_DWORD *)a2;
LABEL_379:
                    v108 = (double)v107;
                    goto LABEL_382;
                  case 4u:
                    v104 = *(_DWORD *)a2;
LABEL_373:
                    v105 = (double)v104;
                    goto LABEL_376;
                  case 5u:
                    v101 = *(_DWORD *)a2;
LABEL_367:
                    v102 = (double)v101;
                    goto LABEL_370;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v98 = *(_DWORD *)a2;
                break;
              default:
                goto LABEL_43;
            }
LABEL_362:
            v99 = (double)v98;
            goto LABEL_364;
          case 7u:
            if ( v14 == 7 || v14 == 8 )
            {
              if ( a5 != 7 )
                goto LABEL_43;
              v133 = *(_DWORD *)a2;
              v134 = *(_DWORD *)a6;
              if ( v14 == 7 )
                v19 = v134 & v133;
              else
                v19 = v134 | v133;
              goto LABEL_25;
            }
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v124 = (char)*a6;
                    goto LABEL_521;
                  case 3u:
                    v131 = (char)*a6;
                    goto LABEL_625;
                  case 4u:
                    v129 = (char)*a6;
                    goto LABEL_621;
                  case 5u:
                    v127 = (char)*a6;
                    goto LABEL_617;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v125 = (char)*a6;
                goto LABEL_613;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *a6;
                    goto LABEL_521;
                  case 3u:
                    v131 = *a6;
                    goto LABEL_625;
                  case 4u:
                    v129 = *a6;
                    goto LABEL_621;
                  case 5u:
                    v127 = *a6;
                    goto LABEL_617;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v125 = *a6;
                goto LABEL_613;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *(__int16 *)a6;
                    goto LABEL_521;
                  case 3u:
                    v131 = *(__int16 *)a6;
                    goto LABEL_625;
                  case 4u:
                    v129 = *(__int16 *)a6;
                    goto LABEL_621;
                  case 5u:
                    v127 = *(__int16 *)a6;
                    goto LABEL_617;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v125 = *(__int16 *)a6;
                goto LABEL_613;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v124 = *(unsigned __int16 *)a6;
LABEL_521:
                    v123 = *(_DWORD *)a2;
LABEL_522:
                    v16 = v123 == v124;
                    goto LABEL_22;
                  case 3u:
                    v131 = *(unsigned __int16 *)a6;
LABEL_625:
                    v132 = *(_DWORD *)a2;
LABEL_626:
                    v54 = v132 > v131;
                    goto LABEL_234;
                  case 4u:
                    v129 = *(unsigned __int16 *)a6;
LABEL_621:
                    v130 = *(_DWORD *)a2;
LABEL_622:
                    v51 = v130 >= v129;
                    goto LABEL_225;
                  case 5u:
                    v127 = *(unsigned __int16 *)a6;
LABEL_617:
                    v128 = *(_DWORD *)a2;
LABEL_618:
                    v48 = v128 >= v127;
                    goto LABEL_215;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v125 = *(unsigned __int16 *)a6;
LABEL_613:
                v126 = *(_DWORD *)a2;
LABEL_614:
                v45 = v126 > v125;
                goto LABEL_206;
              case 6:
              case 7:
LABEL_40:
                switch ( v14 )
                {
                  case 2u:
                    goto LABEL_41;
                  case 3u:
                    v52 = *(_DWORD *)a2;
LABEL_229:
                    v53 = *(_DWORD *)a6;
LABEL_232:
                    v54 = v52 > v53;
                    goto LABEL_234;
                  case 4u:
                    v49 = *(_DWORD *)a2;
LABEL_220:
                    v50 = *(_DWORD *)a6;
LABEL_223:
                    v51 = v49 >= v50;
                    goto LABEL_225;
                  case 5u:
                    v46 = *(_DWORD *)a2;
LABEL_210:
                    v47 = *(_DWORD *)a6;
LABEL_213:
                    v48 = v46 >= v47;
                    goto LABEL_215;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v43 = *(_DWORD *)a2;
LABEL_202:
                v44 = *(_DWORD *)a6;
LABEL_204:
                v45 = v43 > v44;
                goto LABEL_206;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v120 = *(_DWORD *)a2;
LABEL_472:
                    v121 = a6;
                    v122 = *((_DWORD *)a6 + 1);
                    goto LABEL_475;
                  case 3u:
                    v118 = *(_DWORD *)a2;
LABEL_468:
                    v119 = *(_DWORD *)a6;
                    if ( *((int *)a6 + 1) > 0 )
                      goto LABEL_31;
                    if ( *((int *)a6 + 1) < 0 )
                      goto LABEL_24;
                    goto LABEL_470;
                  case 4u:
                    v116 = *(_DWORD *)a2;
LABEL_463:
                    v117 = *(_DWORD *)a6;
                    if ( *((int *)a6 + 1) < 0 )
                      goto LABEL_31;
                    if ( *((int *)a6 + 1) > 0 )
                      goto LABEL_24;
                    goto LABEL_465;
                  case 5u:
                    v114 = *(_DWORD *)a2;
LABEL_458:
                    v115 = *(_DWORD *)a6;
                    if ( *((int *)a6 + 1) > 0 )
                      goto LABEL_31;
                    if ( *((int *)a6 + 1) < 0 )
                      goto LABEL_24;
                    goto LABEL_460;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v112 = *(_DWORD *)a2;
LABEL_453:
                v113 = *(_DWORD *)a6;
                if ( *((int *)a6 + 1) >= 0 )
                {
                  if ( *((int *)a6 + 1) > 0 )
                    goto LABEL_24;
                  goto LABEL_455;
                }
                goto LABEL_31;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    v120 = *(_DWORD *)a2;
LABEL_474:
                    v121 = a6;
                    v122 = *((_DWORD *)a6 + 1);
LABEL_475:
                    if ( v120 == *v121 )
                    {
                      v16 = v122 == 0;
                      goto LABEL_22;
                    }
                    goto LABEL_31;
                  case 3u:
                    v118 = *(_DWORD *)a2;
LABEL_495:
                    v119 = *(_DWORD *)a6;
                    if ( !*((_DWORD *)a6 + 1) )
                    {
LABEL_470:
                      v54 = v118 > v119;
                      goto LABEL_234;
                    }
                    goto LABEL_31;
                  case 4u:
                    v116 = *(_DWORD *)a2;
LABEL_491:
                    v117 = *(_DWORD *)a6;
                    if ( !*((_DWORD *)a6 + 1) )
                    {
LABEL_465:
                      v51 = v116 >= v117;
                      goto LABEL_225;
                    }
                    break;
                  case 5u:
                    v114 = *(_DWORD *)a2;
LABEL_487:
                    v115 = *(_DWORD *)a6;
                    if ( !*((_DWORD *)a6 + 1) )
                    {
LABEL_460:
                      v48 = v114 >= v115;
                      goto LABEL_215;
                    }
                    goto LABEL_31;
                  case 6u:
                    v112 = *(_DWORD *)a2;
LABEL_483:
                    v113 = *(_DWORD *)a6;
                    if ( !*((_DWORD *)a6 + 1) )
                    {
LABEL_455:
                      v45 = v112 > v113;
                      goto LABEL_206;
                    }
                    break;
                  default:
                    goto LABEL_43;
                }
                goto LABEL_24;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v95 = (float)*(unsigned int *)a2;
LABEL_351:
                    v96 = v95 == *(float *)a6;
                    goto LABEL_355;
                  case 3u:
                    v90 = (float)*(unsigned int *)a2;
LABEL_343:
                    v91 = v90 == *(float *)a6;
                    v92 = v90 < *(float *)a6;
                    goto LABEL_347;
                  case 4u:
                    v86 = (float)*(unsigned int *)a2;
LABEL_334:
                    v87 = v86 >= *(float *)a6;
                    goto LABEL_338;
                  case 5u:
                    v82 = (float)*(unsigned int *)a2;
LABEL_325:
                    v83 = v82 < *(float *)a6;
                    goto LABEL_329;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v77 = (float)*(unsigned int *)a2;
LABEL_317:
                v79 = v77 == *(float *)a6;
                v78 = v77 >= *(float *)a6;
                goto LABEL_320;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v21 = *(_DWORD *)a2;
LABEL_387:
                    v111 = (double)v21;
LABEL_388:
                    v96 = v111 == *(double *)a6;
                    goto LABEL_355;
                  case 3u:
                    v109 = *(_DWORD *)a2;
LABEL_381:
                    v108 = (double)v109;
LABEL_382:
                    v91 = v108 == *(double *)a6;
                    v92 = v108 < *(double *)a6;
                    goto LABEL_347;
                  case 4u:
                    v106 = *(_DWORD *)a2;
LABEL_375:
                    v105 = (double)v106;
LABEL_376:
                    v87 = v105 >= *(double *)a6;
                    goto LABEL_338;
                  case 5u:
                    v103 = *(_DWORD *)a2;
LABEL_369:
                    v102 = (double)v103;
LABEL_370:
                    v83 = v102 < *(double *)a6;
                    goto LABEL_329;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v100 = *(_DWORD *)a2;
                break;
              default:
                goto LABEL_43;
            }
LABEL_363:
            v99 = (double)v100;
LABEL_364:
            v79 = v99 == *(double *)a6;
            v78 = v99 >= *(double *)a6;
LABEL_320:
            v45 = !v79 && v78;
LABEL_206:
            if ( v45 )
              goto LABEL_31;
            goto LABEL_24;
          case 8u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v143 = (char)*a6;
                    goto LABEL_884;
                  case 3u:
                    v141 = (char)*a6;
                    goto LABEL_878;
                  case 4u:
                    v139 = (char)*a6;
                    goto LABEL_871;
                  case 5u:
                    v137 = (char)*a6;
                    goto LABEL_865;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v135 = (char)*a6;
                goto LABEL_858;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *a6;
                    goto LABEL_897;
                  case 3u:
                    goto LABEL_879;
                  case 4u:
                    goto LABEL_872;
                  case 5u:
                    goto LABEL_866;
                  case 6u:
                    goto LABEL_859;
                }
                goto LABEL_43;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v143 = *(__int16 *)a6;
LABEL_884:
                    v146 = *(_QWORD *)a2;
                    v144 = *((_DWORD *)a2 + 1);
                    v145 = v146;
                    goto LABEL_887;
                  case 3u:
                    v141 = *(__int16 *)a6;
LABEL_878:
                    v142 = *((_DWORD *)a2 + 1) < v141 >> 31;
                    goto LABEL_880;
                  case 4u:
                    v139 = *(__int16 *)a6;
LABEL_871:
                    v140 = *((_DWORD *)a2 + 1) <= v139 >> 31;
                    goto LABEL_873;
                  case 5u:
                    v137 = *(__int16 *)a6;
LABEL_865:
                    v138 = *((_DWORD *)a2 + 1) < v137 >> 31;
                    goto LABEL_867;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v135 = *(__int16 *)a6;
LABEL_858:
                v136 = *((_DWORD *)a2 + 1) <= v135 >> 31;
                goto LABEL_860;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *(unsigned __int16 *)a6;
                    goto LABEL_897;
                  case 3u:
                    goto LABEL_879;
                  case 4u:
                    goto LABEL_872;
                  case 5u:
                    goto LABEL_866;
                  case 6u:
                    goto LABEL_859;
                }
                goto LABEL_43;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v165 = *((_DWORD *)a2 + 1);
                    v166 = *(_DWORD *)a6;
                    v167 = *(_DWORD *)a2;
                    v168 = *(_DWORD *)a6;
                    goto LABEL_937;
                  case 3u:
                    v162 = *(_DWORD *)a2;
                    v163 = *(_DWORD *)a6;
                    v164 = *((_DWORD *)a2 + 1);
                    if ( v164 < *(int *)a6 >> 31 )
                      goto LABEL_31;
                    if ( v164 > *(int *)a6 >> 31 )
                      goto LABEL_24;
                    goto LABEL_233;
                  case 4u:
                    v159 = *(_DWORD *)a2;
                    v160 = *(_DWORD *)a6;
                    v161 = *((_DWORD *)a2 + 1);
                    if ( v161 > *(int *)a6 >> 31 )
                      goto LABEL_31;
                    if ( v161 < *(int *)a6 >> 31 )
                      goto LABEL_24;
                    goto LABEL_224;
                }
                if ( v14 != 5 )
                {
                  if ( v14 != 6 )
                    goto LABEL_43;
                  v153 = *(_DWORD *)a2;
                  v154 = *(_DWORD *)a6;
                  v155 = *((_DWORD *)a2 + 1);
                  if ( v155 > *(int *)a6 >> 31 )
                    goto LABEL_31;
                  if ( v155 < *(int *)a6 >> 31 )
                    goto LABEL_24;
                  goto LABEL_205;
                }
                v156 = *(_DWORD *)a2;
                v157 = *(_DWORD *)a6;
                v158 = *((_DWORD *)a2 + 1);
                if ( v158 < *(int *)a6 >> 31 )
                  goto LABEL_31;
                if ( v158 > *(int *)a6 >> 31 )
                  goto LABEL_24;
                goto LABEL_214;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *(_DWORD *)a6;
LABEL_897:
                    v151 = *(_QWORD *)a2;
                    v149 = *((_DWORD *)a2 + 1);
                    v150 = v151;
                    goto LABEL_900;
                  case 3u:
LABEL_879:
                    v142 = *((int *)a2 + 1) < 0;
LABEL_880:
                    if ( v142 )
                      goto LABEL_31;
                    goto LABEL_24;
                  case 4u:
LABEL_872:
                    v140 = *((_DWORD *)a2 + 1) <= 0;
LABEL_873:
                    if ( v140 )
                      goto LABEL_24;
                    break;
                  case 5u:
LABEL_866:
                    v138 = *((int *)a2 + 1) < 0;
LABEL_867:
                    if ( v138 )
                      goto LABEL_31;
                    goto LABEL_24;
                  case 6u:
LABEL_859:
                    v136 = *((_DWORD *)a2 + 1) <= 0;
LABEL_860:
                    if ( v136 )
                      goto LABEL_24;
                    break;
                  default:
                    goto LABEL_43;
                }
                goto LABEL_31;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    v69 = *(_QWORD *)a2;
                    v68 = *((_DWORD *)a2 + 1);
                    v67 = v69;
LABEL_273:
                    v70 = a6;
                    v71 = *((_DWORD *)a6 + 1);
                    goto LABEL_277;
                  case 3u:
                    *(_QWORD *)&v64 = *(_QWORD *)a2;
LABEL_266:
                    v66 = *(_DWORD *)a6;
                    if ( v65 < *((_DWORD *)a6 + 1) )
                      goto LABEL_31;
                    if ( v65 > *((_DWORD *)a6 + 1) )
                      goto LABEL_24;
                    goto LABEL_268;
                  case 4u:
                    *(_QWORD *)&v61 = *(_QWORD *)a2;
LABEL_259:
                    v63 = *(_DWORD *)a6;
                    if ( v62 > *((_DWORD *)a6 + 1) )
                      goto LABEL_31;
                    if ( v62 < *((_DWORD *)a6 + 1) )
                      goto LABEL_24;
                    goto LABEL_261;
                  case 5u:
                    *(_QWORD *)&v58 = *(_QWORD *)a2;
LABEL_252:
                    v60 = *(_DWORD *)a6;
                    if ( v59 < *((_DWORD *)a6 + 1) )
                      goto LABEL_31;
                    if ( v59 > *((_DWORD *)a6 + 1) )
                      goto LABEL_24;
                    goto LABEL_254;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                *(_QWORD *)&v55 = *(_QWORD *)a2;
LABEL_245:
                v57 = *(_DWORD *)a6;
                if ( v56 <= *((_DWORD *)a6 + 1) )
                {
                  if ( v56 < *((_DWORD *)a6 + 1) )
                    goto LABEL_24;
                  goto LABEL_247;
                }
                goto LABEL_31;
              case 9:
                goto LABEL_954;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    _i64tos(*(_QWORD *)a2);
                    goto LABEL_979;
                  case 3u:
                    _i64tos(*(_QWORD *)a2);
                    goto LABEL_976;
                  case 4u:
                    _i64tos(*(_QWORD *)a2);
                    goto LABEL_973;
                  case 5u:
                    _i64tos(*(_QWORD *)a2);
                    goto LABEL_970;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _i64tos(*(_QWORD *)a2);
                goto LABEL_967;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    _i64tod(*(_QWORD *)a2);
                    goto LABEL_998;
                  case 3u:
                    _i64tod(*(_QWORD *)a2);
                    goto LABEL_995;
                  case 4u:
                    _i64tod(*(_QWORD *)a2);
                    goto LABEL_992;
                  case 5u:
                    _i64tod(*(_QWORD *)a2);
                    goto LABEL_989;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _i64tod(*(_QWORD *)a2);
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_986;
          case 9u:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v143 = (char)*a6;
                    goto LABEL_886;
                  case 3u:
                    v182 = (char)*a6;
                    goto LABEL_1032;
                  case 4u:
                    v178 = (char)*a6;
                    goto LABEL_1023;
                  case 5u:
                    v174 = (char)*a6;
                    goto LABEL_1014;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v170 = (char)*a6;
                goto LABEL_1006;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *a6;
                    goto LABEL_899;
                  case 3u:
                    v182 = *a6;
                    goto LABEL_1034;
                  case 4u:
                    v178 = *a6;
                    goto LABEL_1025;
                  case 5u:
                    v174 = *a6;
                    goto LABEL_1016;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v170 = *a6;
                goto LABEL_1007;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v143 = *(__int16 *)a6;
LABEL_886:
                    v147 = *(_QWORD *)a2;
                    v144 = *((_DWORD *)a2 + 1);
                    v145 = v147;
LABEL_887:
                    if ( v145 == v143 )
                    {
                      v16 = v144 == v143 >> 31;
                      goto LABEL_22;
                    }
                    goto LABEL_31;
                  case 3u:
                    v182 = *(__int16 *)a6;
LABEL_1032:
                    v183 = *((_DWORD *)a2 + 1);
                    v184 = v183 >= v182 >> 31;
                    v185 = v183 > v182 >> 31;
                    goto LABEL_1035;
                  case 4u:
                    v178 = *(__int16 *)a6;
LABEL_1023:
                    v179 = *((_DWORD *)a2 + 1);
                    v180 = v179 >= v178 >> 31;
                    v181 = v179 > v178 >> 31;
                    goto LABEL_1026;
                  case 5u:
                    v174 = *(__int16 *)a6;
LABEL_1014:
                    v175 = *((_DWORD *)a2 + 1);
                    v176 = v175 >= v174 >> 31;
                    v177 = v175 > v174 >> 31;
                    goto LABEL_1017;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v170 = *(__int16 *)a6;
LABEL_1006:
                v171 = *((_DWORD *)a2 + 1);
                v172 = v171 >= v170 >> 31;
                v173 = v171 > v170 >> 31;
                goto LABEL_1008;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *(unsigned __int16 *)a6;
                    goto LABEL_899;
                  case 3u:
                    v182 = *(unsigned __int16 *)a6;
                    goto LABEL_1034;
                  case 4u:
                    v178 = *(unsigned __int16 *)a6;
                    goto LABEL_1025;
                  case 5u:
                    v174 = *(unsigned __int16 *)a6;
                    goto LABEL_1016;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v170 = *(unsigned __int16 *)a6;
                goto LABEL_1007;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v165 = *((_DWORD *)a2 + 1);
                    v166 = *(_DWORD *)a6;
                    v167 = *(_DWORD *)a2;
                    v168 = *(_DWORD *)a6;
LABEL_937:
                    if ( v167 == v166 )
                    {
                      v16 = v165 == v168 >> 31;
                      goto LABEL_22;
                    }
                    goto LABEL_31;
                  case 3u:
                    v162 = *(_DWORD *)a2;
                    v163 = *(_DWORD *)a6;
                    v189 = *((_DWORD *)a2 + 1);
                    if ( v189 < *(int *)a6 >> 31 )
                      goto LABEL_31;
                    if ( v189 <= *(int *)a6 >> 31 )
                    {
LABEL_233:
                      v54 = v162 > v163;
                      goto LABEL_234;
                    }
                    goto LABEL_24;
                  case 4u:
                    v159 = *(_DWORD *)a2;
                    v160 = *(_DWORD *)a6;
                    v188 = *((_DWORD *)a2 + 1);
                    if ( v188 > *(int *)a6 >> 31 )
                      goto LABEL_31;
                    if ( v188 >= *(int *)a6 >> 31 )
                    {
LABEL_224:
                      v51 = v159 >= v160;
                      goto LABEL_225;
                    }
                    goto LABEL_24;
                  case 5u:
                    v156 = *(_DWORD *)a2;
                    v157 = *(_DWORD *)a6;
                    v187 = *((_DWORD *)a2 + 1);
                    if ( v187 < *(int *)a6 >> 31 )
                      goto LABEL_31;
                    if ( v187 <= *(int *)a6 >> 31 )
                    {
LABEL_214:
                      v48 = v156 >= v157;
                      goto LABEL_215;
                    }
                    goto LABEL_24;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v153 = *(_DWORD *)a2;
                v154 = *(_DWORD *)a6;
                v186 = *((_DWORD *)a2 + 1);
                if ( v186 <= *(int *)a6 >> 31 )
                {
                  if ( v186 >= *(int *)a6 >> 31 )
                  {
LABEL_205:
                    v45 = v153 > v154;
                    goto LABEL_206;
                  }
                  goto LABEL_24;
                }
                goto LABEL_31;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v148 = *(_DWORD *)a6;
LABEL_899:
                    v152 = *(_QWORD *)a2;
                    v149 = *((_DWORD *)a2 + 1);
                    v150 = v152;
LABEL_900:
                    if ( v150 == v148 )
                    {
                      v16 = v149 == 0;
                      goto LABEL_22;
                    }
                    goto LABEL_31;
                  case 3u:
                    v182 = *(_DWORD *)a6;
LABEL_1034:
                    v184 = 1;
                    v185 = *((_DWORD *)a2 + 1) != 0;
LABEL_1035:
                    if ( !v184 )
                      goto LABEL_31;
                    if ( v185 )
                      goto LABEL_24;
                    v54 = *(_DWORD *)a2 > (unsigned int)v182;
                    goto LABEL_234;
                  case 4u:
                    v178 = *(_DWORD *)a6;
LABEL_1025:
                    v180 = 1;
                    v181 = *((_DWORD *)a2 + 1) != 0;
LABEL_1026:
                    if ( v181 )
                      goto LABEL_31;
                    if ( !v180 )
                      goto LABEL_24;
                    v51 = *(_DWORD *)a2 >= (unsigned int)v178;
                    goto LABEL_225;
                  case 5u:
                    v174 = *(_DWORD *)a6;
LABEL_1016:
                    v176 = 1;
                    v177 = *((_DWORD *)a2 + 1) != 0;
LABEL_1017:
                    if ( !v176 )
                      goto LABEL_31;
                    if ( v177 )
                      goto LABEL_24;
                    v48 = *(_DWORD *)a2 >= (unsigned int)v174;
                    goto LABEL_215;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v170 = *(_DWORD *)a6;
LABEL_1007:
                v172 = 1;
                v173 = *((_DWORD *)a2 + 1) != 0;
LABEL_1008:
                if ( !v173 )
                {
                  if ( !v172 )
                    goto LABEL_24;
                  v45 = *(_DWORD *)a2 > (unsigned int)v170;
                  goto LABEL_206;
                }
                goto LABEL_31;
              case 8:
              case 9:
              case 14:
LABEL_954:
                switch ( v14 )
                {
                  case 2u:
                    v169 = *(_QWORD *)a2;
                    v68 = *((_DWORD *)a2 + 1);
                    v67 = v169;
LABEL_276:
                    v70 = a6;
                    v71 = *((_DWORD *)a6 + 1);
LABEL_277:
                    if ( v67 == *v70 )
                    {
                      v16 = v68 == v71;
                      goto LABEL_22;
                    }
                    goto LABEL_31;
                  case 3u:
                    *(_QWORD *)&v64 = *(_QWORD *)a2;
LABEL_307:
                    v66 = *(_DWORD *)a6;
                    if ( v75 >= *((_DWORD *)a6 + 1) )
                    {
                      if ( v75 > *((_DWORD *)a6 + 1) )
                        goto LABEL_24;
LABEL_268:
                      v54 = v64 > v66;
LABEL_234:
                      if ( v54 )
                        goto LABEL_24;
                    }
                    break;
                  case 4u:
                    *(_QWORD *)&v61 = *(_QWORD *)a2;
LABEL_300:
                    v63 = *(_DWORD *)a6;
                    if ( v74 > *((_DWORD *)a6 + 1) )
                      goto LABEL_31;
                    if ( v74 >= *((_DWORD *)a6 + 1) )
                    {
LABEL_261:
                      v51 = v61 >= v63;
                      goto LABEL_225;
                    }
                    goto LABEL_24;
                  case 5u:
                    *(_QWORD *)&v58 = *(_QWORD *)a2;
LABEL_293:
                    v60 = *(_DWORD *)a6;
                    if ( v73 >= *((_DWORD *)a6 + 1) )
                    {
                      if ( v73 > *((_DWORD *)a6 + 1) )
                        goto LABEL_24;
LABEL_254:
                      v48 = v58 >= v60;
LABEL_215:
                      if ( v48 )
                        goto LABEL_24;
                    }
                    break;
                  case 6u:
                    *(_QWORD *)&v55 = *(_QWORD *)a2;
LABEL_286:
                    v57 = *(_DWORD *)a6;
                    if ( v72 <= *((_DWORD *)a6 + 1) )
                    {
                      if ( v72 >= *((_DWORD *)a6 + 1) )
                      {
LABEL_247:
                        v45 = v55 > v57;
                        goto LABEL_206;
                      }
                      goto LABEL_24;
                    }
                    break;
                  default:
                    goto LABEL_43;
                }
                goto LABEL_31;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    _u64tos(*(_QWORD *)a2);
LABEL_979:
                    v96 = *(float *)&v8 == *(float *)a6;
                    goto LABEL_355;
                  case 3u:
                    _u64tos(*(_QWORD *)a2);
LABEL_976:
                    v91 = *(float *)&v8 == *(float *)a6;
                    v92 = *(float *)&v8 < *(float *)a6;
                    goto LABEL_347;
                  case 4u:
                    _u64tos(*(_QWORD *)a2);
LABEL_973:
                    v87 = *(float *)&v8 >= *(float *)a6;
                    goto LABEL_338;
                  case 5u:
                    _u64tos(*(_QWORD *)a2);
LABEL_970:
                    v83 = *(float *)&v8 < *(float *)a6;
                    goto LABEL_329;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _u64tos(*(_QWORD *)a2);
LABEL_967:
                v79 = *(float *)&v8 == *(float *)a6;
                v78 = *(float *)&v8 >= *(float *)a6;
                goto LABEL_320;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    _u64tod(*(_QWORD *)a2);
LABEL_998:
                    v96 = v8 == *(double *)a6;
                    goto LABEL_355;
                  case 3u:
                    _u64tod(*(_QWORD *)a2);
LABEL_995:
                    v91 = v8 == *(double *)a6;
                    v92 = v8 < *(double *)a6;
                    goto LABEL_347;
                  case 4u:
                    _u64tod(*(_QWORD *)a2);
LABEL_992:
                    v87 = v8 >= *(double *)a6;
                    goto LABEL_338;
                  case 5u:
                    _u64tod(*(_QWORD *)a2);
LABEL_989:
                    v83 = v8 < *(double *)a6;
                    goto LABEL_329;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _u64tod(*(_QWORD *)a2);
                break;
              default:
                goto LABEL_43;
            }
LABEL_986:
            v79 = v8 == *(double *)a6;
            v78 = v8 >= *(double *)a6;
            goto LABEL_320;
          case 0xAu:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v194 = (char)*a6;
                    goto LABEL_1127;
                  case 3u:
                    v193 = (char)*a6;
                    goto LABEL_1122;
                  case 4u:
                    v192 = (char)*a6;
                    goto LABEL_1117;
                  case 5u:
                    v191 = (char)*a6;
                    goto LABEL_1112;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v190 = (char)*a6;
                goto LABEL_1108;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v194 = *a6;
                    goto LABEL_1127;
                  case 3u:
                    v193 = *a6;
                    goto LABEL_1122;
                  case 4u:
                    v192 = *a6;
                    goto LABEL_1117;
                  case 5u:
                    v191 = *a6;
                    goto LABEL_1112;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v190 = *a6;
                goto LABEL_1108;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v194 = *(__int16 *)a6;
                    goto LABEL_1127;
                  case 3u:
                    v193 = *(__int16 *)a6;
                    goto LABEL_1122;
                  case 4u:
                    v192 = *(__int16 *)a6;
                    goto LABEL_1117;
                  case 5u:
                    v191 = *(__int16 *)a6;
                    goto LABEL_1112;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v190 = *(__int16 *)a6;
                goto LABEL_1108;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v194 = *(unsigned __int16 *)a6;
                    goto LABEL_1127;
                  case 3u:
                    v193 = *(unsigned __int16 *)a6;
                    goto LABEL_1122;
                  case 4u:
                    v192 = *(unsigned __int16 *)a6;
                    goto LABEL_1117;
                  case 5u:
                    v191 = *(unsigned __int16 *)a6;
                    goto LABEL_1112;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v190 = *(unsigned __int16 *)a6;
                goto LABEL_1108;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v194 = *(_DWORD *)a6;
LABEL_1127:
                    *(float *)&v8 = (float)v194;
                    goto LABEL_1129;
                  case 3u:
                    v193 = *(_DWORD *)a6;
LABEL_1122:
                    *(float *)&v8 = (float)v193;
                    goto LABEL_1124;
                  case 4u:
                    v192 = *(_DWORD *)a6;
LABEL_1117:
                    *(float *)&v8 = (float)v192;
                    goto LABEL_1119;
                  case 5u:
                    v191 = *(_DWORD *)a6;
LABEL_1112:
                    *(float *)&v8 = (float)v191;
                    goto LABEL_1114;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v190 = *(_DWORD *)a6;
LABEL_1108:
                *(float *)&v8 = (float)v190;
                goto LABEL_1109;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    *(float *)&v8 = (float)*(unsigned int *)a6;
                    goto LABEL_1129;
                  case 3u:
                    *(float *)&v8 = (float)*(unsigned int *)a6;
                    goto LABEL_1124;
                  case 4u:
                    *(float *)&v8 = (float)*(unsigned int *)a6;
                    goto LABEL_1119;
                  case 5u:
                    *(float *)&v8 = (float)*(unsigned int *)a6;
                    goto LABEL_1114;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                *(float *)&v8 = (float)*(unsigned int *)a6;
                goto LABEL_1109;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    _i64tos(*(_QWORD *)a6);
                    goto LABEL_1129;
                  case 3u:
                    _i64tos(*(_QWORD *)a6);
                    goto LABEL_1124;
                  case 4u:
                    _i64tos(*(_QWORD *)a6);
                    goto LABEL_1119;
                  case 5u:
                    _i64tos(*(_QWORD *)a6);
                    goto LABEL_1114;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _i64tos(*(_QWORD *)a6);
                goto LABEL_1109;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    _u64tos(*(_QWORD *)a6);
                    goto LABEL_1129;
                  case 3u:
                    _u64tos(*(_QWORD *)a6);
                    goto LABEL_1124;
                  case 4u:
                    _u64tos(*(_QWORD *)a6);
                    goto LABEL_1119;
                  case 5u:
                    _u64tos(*(_QWORD *)a6);
                    goto LABEL_1114;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _u64tos(*(_QWORD *)a6);
                goto LABEL_1109;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    LODWORD(v8) = *(_DWORD *)a6;
LABEL_1129:
                    v96 = *(float *)a2 == *(float *)&v8;
                    goto LABEL_355;
                  case 3u:
                    LODWORD(v8) = *(_DWORD *)a6;
LABEL_1124:
                    v91 = *(float *)a2 == *(float *)&v8;
                    v92 = *(float *)a2 < *(float *)&v8;
                    goto LABEL_347;
                  case 4u:
                    LODWORD(v8) = *(_DWORD *)a6;
LABEL_1119:
                    v87 = *(float *)a2 >= *(float *)&v8;
                    goto LABEL_338;
                  case 5u:
                    LODWORD(v8) = *(_DWORD *)a6;
LABEL_1114:
                    v83 = *(float *)a2 < *(float *)&v8;
                    goto LABEL_329;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                LODWORD(v8) = *(_DWORD *)a6;
LABEL_1109:
                v79 = *(float *)a2 == *(float *)&v8;
                v78 = *(float *)a2 >= *(float *)&v8;
                goto LABEL_320;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v97 = *(float *)a2;
                    goto LABEL_353;
                  case 3u:
                    v93 = *(float *)a2;
                    goto LABEL_345;
                  case 4u:
                    v88 = *(float *)a2;
                    goto LABEL_336;
                  case 5u:
                    v84 = *(float *)a2;
                    goto LABEL_327;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v80 = *(float *)a2;
                break;
              default:
                goto LABEL_43;
            }
LABEL_318:
            v8 = *(double *)a6;
LABEL_319:
            v79 = v80 == v8;
            v78 = v80 >= v8;
            goto LABEL_320;
          case 0xBu:
            switch ( a5 )
            {
              case 2:
                switch ( v14 )
                {
                  case 2u:
                    v199 = (char)*a6;
                    goto LABEL_1227;
                  case 3u:
                    v198 = (char)*a6;
                    goto LABEL_1224;
                  case 4u:
                    v197 = (char)*a6;
                    goto LABEL_1221;
                  case 5u:
                    v196 = (char)*a6;
                    goto LABEL_1218;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v195 = (char)*a6;
                goto LABEL_1215;
              case 3:
                switch ( v14 )
                {
                  case 2u:
                    v204 = *a6;
                    goto LABEL_1246;
                  case 3u:
                    v203 = *a6;
                    goto LABEL_1243;
                  case 4u:
                    v202 = *a6;
                    goto LABEL_1240;
                  case 5u:
                    v201 = *a6;
                    goto LABEL_1237;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v200 = *a6;
                goto LABEL_1234;
              case 4:
                switch ( v14 )
                {
                  case 2u:
                    v199 = *(__int16 *)a6;
                    goto LABEL_1227;
                  case 3u:
                    v198 = *(__int16 *)a6;
                    goto LABEL_1224;
                  case 4u:
                    v197 = *(__int16 *)a6;
                    goto LABEL_1221;
                  case 5u:
                    v196 = *(__int16 *)a6;
                    goto LABEL_1218;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v195 = *(__int16 *)a6;
                goto LABEL_1215;
              case 5:
                switch ( v14 )
                {
                  case 2u:
                    v204 = *(unsigned __int16 *)a6;
                    goto LABEL_1246;
                  case 3u:
                    v203 = *(unsigned __int16 *)a6;
                    goto LABEL_1243;
                  case 4u:
                    v202 = *(unsigned __int16 *)a6;
                    goto LABEL_1240;
                  case 5u:
                    v201 = *(unsigned __int16 *)a6;
                    goto LABEL_1237;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v200 = *(unsigned __int16 *)a6;
                goto LABEL_1234;
              case 6:
                switch ( v14 )
                {
                  case 2u:
                    v199 = *(_DWORD *)a6;
LABEL_1227:
                    v97 = *(double *)a2;
                    v8 = (double)v199;
                    goto LABEL_354;
                  case 3u:
                    v198 = *(_DWORD *)a6;
LABEL_1224:
                    v93 = *(double *)a2;
                    v8 = (double)v198;
                    goto LABEL_346;
                  case 4u:
                    v197 = *(_DWORD *)a6;
LABEL_1221:
                    v88 = *(double *)a2;
                    v8 = (double)v197;
                    goto LABEL_337;
                  case 5u:
                    v196 = *(_DWORD *)a6;
LABEL_1218:
                    v84 = *(double *)a2;
                    v8 = (double)v196;
                    goto LABEL_328;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v195 = *(_DWORD *)a6;
LABEL_1215:
                v80 = *(double *)a2;
                v8 = (double)v195;
                goto LABEL_319;
              case 7:
                switch ( v14 )
                {
                  case 2u:
                    v204 = *(_DWORD *)a6;
LABEL_1246:
                    v97 = *(double *)a2;
                    v8 = (double)v204;
                    goto LABEL_354;
                  case 3u:
                    v203 = *(_DWORD *)a6;
LABEL_1243:
                    v93 = *(double *)a2;
                    v8 = (double)v203;
                    goto LABEL_346;
                  case 4u:
                    v202 = *(_DWORD *)a6;
LABEL_1240:
                    v88 = *(double *)a2;
                    v8 = (double)v202;
                    goto LABEL_337;
                  case 5u:
                    v201 = *(_DWORD *)a6;
LABEL_1237:
                    v84 = *(double *)a2;
                    v8 = (double)v201;
                    goto LABEL_328;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v200 = *(_DWORD *)a6;
LABEL_1234:
                v80 = *(double *)a2;
                v8 = (double)v200;
                goto LABEL_319;
              case 8:
              case 14:
                switch ( v14 )
                {
                  case 2u:
                    _i64tod(*(_QWORD *)a6);
                    goto LABEL_1297;
                  case 3u:
                    _i64tod(*(_QWORD *)a6);
                    goto LABEL_1294;
                  case 4u:
                    _i64tod(*(_QWORD *)a6);
                    goto LABEL_1291;
                  case 5u:
                    _i64tod(*(_QWORD *)a6);
                    goto LABEL_1288;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _i64tod(*(_QWORD *)a6);
                goto LABEL_1285;
              case 9:
                switch ( v14 )
                {
                  case 2u:
                    _u64tod(*(_QWORD *)a6);
LABEL_1297:
                    v97 = *(double *)a2;
                    goto LABEL_354;
                  case 3u:
                    _u64tod(*(_QWORD *)a6);
LABEL_1294:
                    v93 = *(double *)a2;
                    goto LABEL_346;
                  case 4u:
                    _u64tod(*(_QWORD *)a6);
LABEL_1291:
                    v88 = *(double *)a2;
                    goto LABEL_337;
                  case 5u:
                    _u64tod(*(_QWORD *)a6);
LABEL_1288:
                    v84 = *(double *)a2;
                    goto LABEL_328;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                _u64tod(*(_QWORD *)a6);
LABEL_1285:
                v80 = *(double *)a2;
                goto LABEL_319;
              case 10:
                switch ( v14 )
                {
                  case 2u:
                    v97 = *(double *)a2;
                    v8 = *(float *)a6;
                    goto LABEL_354;
                  case 3u:
                    v93 = *(double *)a2;
                    v8 = *(float *)a6;
                    goto LABEL_346;
                  case 4u:
                    v88 = *(double *)a2;
                    v8 = *(float *)a6;
                    goto LABEL_337;
                  case 5u:
                    v84 = *(double *)a2;
                    v8 = *(float *)a6;
                    goto LABEL_328;
                }
                if ( v14 != 6 )
                  goto LABEL_43;
                v80 = *(double *)a2;
                v8 = *(float *)a6;
                goto LABEL_319;
              case 11:
              case 15:
                switch ( v14 )
                {
                  case 2u:
                    v97 = *(double *)a2;
LABEL_353:
                    v8 = *(double *)a6;
LABEL_354:
                    v96 = v97 == v8;
LABEL_355:
                    v16 = v96;
                    goto LABEL_22;
                  case 3u:
                    v93 = *(double *)a2;
LABEL_345:
                    v8 = *(double *)a6;
LABEL_346:
                    v91 = v93 == v8;
                    v92 = v93 < v8;
LABEL_347:
                    v40 = v92 || v91;
LABEL_128:
                    if ( v40 )
                      goto LABEL_31;
                    break;
                  case 4u:
                    v88 = *(double *)a2;
LABEL_336:
                    v8 = *(double *)a6;
LABEL_337:
                    v87 = v88 >= v8;
LABEL_338:
                    v51 = v87;
LABEL_225:
                    if ( v51 )
                      goto LABEL_31;
                    break;
                  case 5u:
                    v84 = *(double *)a2;
LABEL_327:
                    v8 = *(double *)a6;
LABEL_328:
                    v83 = v84 < v8;
LABEL_329:
                    v30 = v83;
LABEL_107:
                    if ( v30 )
                      goto LABEL_31;
                    break;
                  case 6u:
                    v80 = *(double *)a2;
                    goto LABEL_318;
                  default:
                    goto LABEL_43;
                }
                break;
              default:
                goto LABEL_43;
            }
            goto LABEL_24;
          case 0xCu:
            v22 = a5 == 12;
            goto LABEL_63;
          case 0xDu:
            if ( a5 != 13 || v14 != 2 )
              goto LABEL_43;
            if ( *(_DWORD *)a2 != *(_DWORD *)a6
              || *((_DWORD *)a2 + 1) != *((_DWORD *)a6 + 1)
              || *((_DWORD *)a2 + 2) != *((_DWORD *)a6 + 2) )
            {
              goto LABEL_31;
            }
            v17 = *((_DWORD *)a2 + 3);
            v18 = *((_DWORD *)a6 + 3);
            goto LABEL_21;
          case 0xEu:
            if ( (unsigned int)(a5 - 2) <= 0xD )
              __asm { ADD             PC, R3 }
            goto LABEL_43;
          case 0xFu:
            if ( (unsigned int)(a5 - 2) <= 0xD )
              __asm { ADD             PC, R3 }
            goto LABEL_43;
          case 0x10u:
            if ( a5 != 16 )
              goto LABEL_43;
            switch ( v14 )
            {
              case 2u:
                v15 = CompareFileTimeType(a2, a6, v13);
                goto LABEL_14;
              case 3u:
                v16 = CompareFileTimeType(a2, a6, v13) == 1;
                goto LABEL_22;
              case 4u:
                v16 = CompareFileTimeType(a2, a6, v13) == -1;
                goto LABEL_22;
              case 5u:
                v15 = CompareFileTimeType(a2, a6, v13);
                v207 = v15 == 1;
                break;
              case 6u:
                v15 = CompareFileTimeType(a2, a6, v13);
                v207 = v15 == -1;
                break;
              default:
                goto LABEL_43;
            }
            if ( !v207 )
              goto LABEL_14;
            goto LABEL_24;
          case 0x11u:
            if ( a5 != 17 || v14 != 2 )
              goto LABEL_43;
LABEL_35:
            v17 = *a2;
LABEL_36:
            v18 = (char)*a6;
            goto LABEL_21;
          case 0x12u:
            if ( a5 != 18 )
              goto LABEL_43;
            if ( v14 == 2 )
              goto LABEL_10;
            if ( v14 - 9 > 2 )
              goto LABEL_43;
            v208 = SubstringMatch(a2, a6, v13, v14);
            goto LABEL_1370;
          case 0x15u:
            if ( a5 != 21 || v14 != 2 )
              goto LABEL_26;
            v205 = (unsigned int)a6;
            if ( *((_DWORD *)a2 + 4) != *((_DWORD *)a6 + 4) )
              goto LABEL_31;
            v206 = 16;
            goto LABEL_1327;
          case 0x16u:
            if ( a5 != 22 || v14 != 2 )
              goto LABEL_43;
LABEL_41:
            v17 = *(_DWORD *)a2;
LABEL_42:
            v18 = *(_DWORD *)a6;
            goto LABEL_21;
          case 0x17u:
            v22 = a5 == 23;
LABEL_63:
            if ( !v22 )
              goto LABEL_43;
            goto LABEL_1324;
          case 0x18u:
            if ( a5 != 24 || v14 != 2 )
              goto LABEL_43;
LABEL_194:
            v17 = *(_DWORD *)a2;
LABEL_195:
            v18 = *(_DWORD *)a6;
LABEL_21:
            v16 = v17 == v18;
            goto LABEL_22;
          case 0x19u:
            if ( a5 != 25 && a5 != 18 || v14 != 2 )
              goto LABEL_43;
LABEL_10:
            if ( !v13 )
              goto LABEL_1325;
            if ( a3 && a3 == a7 )
            {
              v15 = wcsicmp((int)a2, (unsigned __int16 *)a6);
              goto LABEL_14;
            }
            *a8 = 0;
            break;
          default:
            goto LABEL_43;
        }
        goto LABEL_26;
      }
LABEL_1324:
      if ( v14 == 2 )
      {
LABEL_1325:
        if ( a3 != a7 )
          goto LABEL_31;
        v205 = (unsigned int)a6;
        v206 = a3;
LABEL_1327:
        v15 = memcmp((unsigned int)a2, v205, v206);
LABEL_14:
        v16 = v15 == 0;
LABEL_22:
        if ( !v16 )
          goto LABEL_31;
        goto LABEL_24;
      }
LABEL_43:
      v9 = -1073741637;
      goto LABEL_26;
    }
    if ( a1 == 4109 )
    {
      if ( a5 != 4109 && a5 != 13 )
        goto LABEL_43;
      if ( v14 == 2 )
        goto LABEL_1325;
      if ( v14 != 0x10000000 )
        goto LABEL_43;
      v208 = ArrayContains((int)a2, a3, (int)a6, a7);
    }
    else
    {
      if ( a1 != 8210 || a5 != 8210 && a5 != 18 )
        goto LABEL_43;
      switch ( v14 )
      {
        case 2u:
          if ( !v13 )
            goto LABEL_1325;
          goto LABEL_43;
        case 0x1000u:
          v208 = StringListContains(a2, a5, a6, v13);
          break;
        case 0x2000u:
        case 0x3000u:
        case 0x4000u:
          v208 = StringListElementSubstringMatch(a2, a5, a6, v13);
          break;
        default:
          goto LABEL_43;
      }
    }
LABEL_1370:
    *a8 = v208;
  }
LABEL_26:
  if ( v12 )
    *a8 = *a8 == 0;
  return v9;
}
