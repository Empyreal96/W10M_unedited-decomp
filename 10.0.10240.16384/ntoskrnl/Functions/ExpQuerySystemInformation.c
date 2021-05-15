// ExpQuerySystemInformation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpQuerySystemInformation(int a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v6; // r6
  int v8; // r2
  unsigned int *v9; // r2
  int *v10; // r1
  unsigned int v11; // r10
  unsigned int v12; // r0
  int v13; // r3
  int v14; // lr
  int v15; // r8
  unsigned int v16; // r2
  int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r5
  unsigned int v20; // r2
  unsigned int v21; // r3
  int v22; // r1
  int v23; // r0
  unsigned int i; // lr
  int v25; // r2
  _DWORD *v26; // r1
  int v27; // r0
  unsigned __int8 v28; // r8
  _BYTE *v29; // r0
  unsigned int v30; // r5
  unsigned int v31; // r3
  int v32; // r5
  int v33; // r2
  _DWORD *v34; // r10
  unsigned int v35; // r2
  __int16 v36; // r3
  int v37; // r1
  int v38; // r2
  int v39; // r3
  int v40; // r1
  int v41; // r2
  int v42; // r3
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r1 OVERLAPPED
  int v47; // r2 OVERLAPPED
  __int64 v48; // kr28_8
  int v49; // r0
  int v50; // r4
  char v51; // r5
  int v52; // r2
  unsigned int v53; // r3
  unsigned int v54; // r0
  unsigned int v55; // r10
  unsigned int v56; // r5
  int v57; // r0
  int v58; // r3
  int v59; // r0
  __int16 v60; // r3
  int v61; // r4
  int v62; // r5
  int v63; // r3
  int v64; // r2
  int v65; // r0
  int v66; // r0
  int v67; // r0
  __int16 v68; // r2
  int v69; // r3
  int v70; // r2
  int v71; // r0
  unsigned int v72; // r3
  int v73; // r0
  int v74; // r5
  int v75; // r1
  int v76; // r5
  unsigned int v77; // lr
  void **v78; // r4
  int v79; // t1
  int v80; // r1
  unsigned int v81; // r2
  void **v82; // r4
  int v83; // t1
  unsigned int v84; // r1
  int v85; // r3
  int v86; // r5
  _DWORD *v87; // r5
  int v88; // r0
  int v89; // r0
  int v90; // r2
  unsigned int v91; // r1
  void **v92; // r4
  int v93; // t1
  unsigned int v94; // r0
  unsigned int v95; // r4
  unsigned int v96; // r5
  unsigned int v97; // r1
  int v98; // r3
  int v99; // r0
  int v100; // r3
  unsigned __int64 *v101; // r3
  unsigned __int64 v102; // t1
  unsigned __int64 v103; // kr30_8
  unsigned __int64 v104; // kr38_8
  unsigned int v105; // r5
  int v106; // lr
  int v107; // r2
  int v108; // r3
  unsigned int *v109; // r3
  unsigned int v110; // r10
  unsigned __int64 v111; // kr48_8
  int v112; // r1
  int v113; // r2
  int v114; // r3
  int v115; // r5
  int v116; // r8
  int v117; // r0
  int v118; // r0
  _DWORD *v119; // r5
  int v120; // r3
  int v121; // r3
  unsigned int v122; // r5
  unsigned int v123; // r5
  int v124; // r0
  unsigned int v125; // r3
  int v126; // lr
  int v127; // r1
  int v128; // r2
  unsigned int k; // r3
  unsigned int v130; // r5
  int v131; // r5
  unsigned int v133; // [sp+8h] [bp-248h] BYREF
  unsigned int v134; // [sp+Ch] [bp-244h]
  unsigned int *v135; // [sp+10h] [bp-240h]
  int v136; // [sp+18h] [bp-238h]
  int v137; // [sp+1Ch] [bp-234h]
  int v138; // [sp+20h] [bp-230h] BYREF
  char v139; // [sp+24h] [bp-22Ch]
  int v140; // [sp+28h] [bp-228h]
  __int16 v141; // [sp+2Ch] [bp-224h]
  unsigned int v142; // [sp+30h] [bp-220h] BYREF
  int v143; // [sp+34h] [bp-21Ch] BYREF
  unsigned int v144; // [sp+38h] [bp-218h] BYREF
  unsigned int v145; // [sp+3Ch] [bp-214h]
  _DWORD *v146; // [sp+40h] [bp-210h] BYREF
  int v147; // [sp+44h] [bp-20Ch]
  int v148[2]; // [sp+48h] [bp-208h] BYREF
  int v149; // [sp+50h] [bp-200h] BYREF
  __int16 v150; // [sp+54h] [bp-1FCh]
  int j; // [sp+58h] [bp-1F8h] BYREF
  int v152; // [sp+5Ch] [bp-1F4h]
  int v153; // [sp+60h] [bp-1F0h]
  unsigned int v154; // [sp+64h] [bp-1ECh] BYREF
  int v155; // [sp+68h] [bp-1E8h]
  unsigned int v156; // [sp+70h] [bp-1E0h]
  int v157; // [sp+74h] [bp-1DCh]
  unsigned int v158; // [sp+78h] [bp-1D8h]
  int v159; // [sp+7Ch] [bp-1D4h]
  int v160; // [sp+80h] [bp-1D0h]
  int v161; // [sp+84h] [bp-1CCh]
  unsigned int v162[4]; // [sp+88h] [bp-1C8h] BYREF
  int v163; // [sp+98h] [bp-1B8h]
  int v164; // [sp+9Ch] [bp-1B4h]
  int v165; // [sp+A0h] [bp-1B0h]
  unsigned int v166; // [sp+A4h] [bp-1ACh]
  unsigned int v167; // [sp+A8h] [bp-1A8h]
  int v168; // [sp+ACh] [bp-1A4h]
  int v169; // [sp+B0h] [bp-1A0h]
  int v170; // [sp+B4h] [bp-19Ch]
  int v171; // [sp+B8h] [bp-198h]
  int v172; // [sp+BCh] [bp-194h]
  int v173; // [sp+C0h] [bp-190h]
  int v174; // [sp+C8h] [bp-188h]
  int v175; // [sp+CCh] [bp-184h]
  int v176; // [sp+D0h] [bp-180h]
  int v177; // [sp+D4h] [bp-17Ch]
  int v178[10]; // [sp+D8h] [bp-178h] BYREF
  _DWORD v179[12]; // [sp+100h] [bp-150h] BYREF
  _BYTE v180[32]; // [sp+130h] [bp-120h] BYREF
  _DWORD v181[4]; // [sp+150h] [bp-100h] BYREF
  _DWORD v182[8]; // [sp+160h] [bp-F0h] BYREF
  _DWORD v183[12]; // [sp+180h] [bp-D0h] BYREF
  _DWORD _1B0[46]; // [sp+1B0h] [bp-A0h] BYREF

  _1B0[43] = a2;
  _1B0[45] = a4;
  v6 = a4;
  v142 = a3;
  _1B0[44] = a3;
  v138 = a2;
  _1B0[42] = a1;
  v144 = a2;
  v143 = a4;
  v135 = a6;
  v133 = 0;
  v137 = 0;
  v136 = 0;
  v140 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v139 = v140;
  if ( !v140 )
  {
    v134 = a5;
    v10 = (int *)v138;
    goto LABEL_39;
  }
  v8 = 4;
  switch ( a1 )
  {
    case 35:
      v8 = 1;
      break;
    case 12:
      v8 = 4;
      break;
    case 88:
      v8 = 4;
      break;
    default:
      if ( a1 != 5 && a1 != 57 && a1 != 148 )
      {
        if ( a1 == 17 )
        {
          v8 = 4;
          break;
        }
        if ( a1 == 95 )
        {
          v8 = 4;
          break;
        }
        if ( a1 != 108 && a1 != 133 && a1 != 138 && a1 != 139 && a1 != 126 )
        {
          if ( a1 == 140 )
          {
            v8 = 4;
            break;
          }
          if ( a1 == 147 )
          {
            v8 = 1;
            break;
          }
          if ( a1 != 154 )
          {
            if ( a1 == 157 )
            {
              v8 = 4;
              break;
            }
            if ( a1 == 158 )
            {
              v8 = 1;
              break;
            }
            if ( a1 != 160 )
            {
              if ( a1 == 173 )
                v8 = 4;
              break;
            }
          }
        }
      }
      v8 = 8;
      break;
  }
  v134 = a5;
  ProbeForWrite(a4, a5, v8);
  if ( a6 )
  {
    v9 = a6;
    if ( (unsigned int)a6 >= MmUserProbeAddress )
      v9 = (unsigned int *)MmUserProbeAddress;
    *v9 = *v9;
  }
  v10 = (int *)v138;
LABEL_39:
  v11 = 0;
  v133 = 0;
  v149 = 0xFFFF;
  v152 = 0xFFFF;
  v12 = 0;
  v147 = 0;
  v146 = 0;
  v148[0] = 0;
  v141 = 0;
  v144 = 0;
  v150 = 0;
  v13 = 0;
  v138 = 0;
  v153 = 0;
  if ( a1 >= 3 && a1 < 8 || a1 >= 74 && a1 < 83 || a1 >= 109 && a1 < 121 || a1 < 2 )
    goto LABEL_54;
  if ( a1 <= 83 )
  {
    if ( a1 == 83 )
      goto LABEL_85;
    if ( a1 <= 36 )
    {
      if ( a1 != 36 )
      {
        if ( a1 > 23 )
        {
          if ( a1 != 33 )
          {
            v14 = 0;
            goto LABEL_93;
          }
        }
        else
        {
          if ( a1 == 23 )
            goto LABEL_85;
          if ( a1 != 2 )
          {
            if ( a1 != 8 )
            {
LABEL_54:
              v14 = 0;
              goto LABEL_93;
            }
            goto LABEL_85;
          }
        }
      }
LABEL_62:
      v13 = 0xFFFF;
      v148[0] = 0xFFFF;
      v141 = -1;
      v12 = KeNumberProcessors_0;
      v147 = KeNumberProcessors_0;
      v146 = (_DWORD *)KeNumberProcessors_0;
      v14 = 0;
      goto LABEL_93;
    }
    if ( a1 > 65 )
    {
      if ( a1 != 73 )
      {
        v14 = 0;
        goto LABEL_93;
      }
    }
    else
    {
      if ( a1 == 65 )
        goto LABEL_62;
      if ( a1 != 42 && a1 != 61 )
      {
        v14 = 0;
        goto LABEL_93;
      }
    }
LABEL_85:
    if ( v142 >= 2 )
    {
      v148[0] = *(unsigned __int16 *)v10;
      v141 = v148[0];
      if ( v148[0] < (unsigned int)KeQueryActiveGroupCount() )
      {
        v13 = 0xFFFF;
        if ( v148[0] == 0xFFFF )
        {
          v12 = KeNumberProcessors_0;
        }
        else
        {
          v13 = (unsigned __int16)KiActiveGroups;
          if ( v148[0] >= (unsigned int)(unsigned __int16)KiActiveGroups )
          {
            v12 = 0;
          }
          else
          {
            v16 = ~dword_681D78[v148[0]];
            v13 = *((unsigned __int8 *)RtlpBitsClearTotal + HIBYTE(v16))
                + *((unsigned __int8 *)RtlpBitsClearTotal + BYTE2(v16))
                + *((unsigned __int8 *)RtlpBitsClearTotal + (unsigned __int8)v16)
                + *((unsigned __int8 *)RtlpBitsClearTotal + BYTE1(v16));
            v12 = (unsigned __int8)v13;
            v11 = v133;
          }
        }
        v147 = v12;
        v146 = (_DWORD *)v12;
        v14 = v138;
        goto LABEL_93;
      }
    }
    return -1073741811;
  }
  if ( a1 > 141 )
  {
    if ( a1 != 160 )
    {
      if ( a1 == 165 )
      {
        if ( !v142 )
          goto LABEL_54;
        if ( v142 == 8 )
        {
          v14 = 0;
          goto LABEL_93;
        }
      }
      else
      {
        if ( a1 != 175 )
          goto LABEL_54;
        if ( v142 == 4 )
        {
          v138 = *v10;
          v13 = v138;
          v153 = v138;
          v14 = v138;
          goto LABEL_93;
        }
      }
      return -1073741811;
    }
    goto LABEL_85;
  }
  if ( a1 == 141 )
    goto LABEL_85;
  if ( a1 <= 108 )
  {
    if ( a1 != 108 && a1 != 100 )
    {
      if ( a1 != 107 )
        goto LABEL_54;
      if ( v142 >= 4 )
      {
        v149 = *v10;
        v152 = v149;
        v14 = 0;
        goto LABEL_93;
      }
      return -1073741811;
    }
    goto LABEL_85;
  }
  if ( a1 != 121 )
    goto LABEL_54;
  if ( v142 < 2 )
    return -1073741811;
  v144 = *(unsigned __int16 *)v10;
  v150 = v144;
  v14 = 0;
  v13 = (unsigned __int16)KeNumberNodes;
  if ( v144 >= (unsigned __int16)KeNumberNodes )
    return -1073741811;
LABEL_93:
  switch ( a1 )
  {
    case 0:
    case 114:
      if ( v134 == 44 )
        goto LABEL_98;
      if ( a6 )
        *a6 = 44;
      return -1073741820;
    case 1:
      if ( v134 >= 0xC )
        goto LABEL_106;
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 2:
      v19 = v134;
      if ( v134 < 0x138 )
      {
        if ( a6 )
          *a6 = 344;
        return -1073741820;
      }
      if ( v134 > 0x158 )
        v19 = 344;
      ExpQuerySystemPerformanceInformation();
      v17 = v137;
      v11 = v19;
      v133 = v19;
      goto LABEL_613;
    case 3:
      if ( v134 <= 0x30 )
      {
        memset(v179, 0, sizeof(v179));
        KeQueryBootTimeValues(&v179[2], v179, &v179[8]);
        v179[4] = ExpTimeZoneBias;
        v179[5] = MEMORY[0x61A4BC];
        v179[6] = ExpCurrentTimeZoneId;
        do
        {
          *(_QWORD *)&v46 = MEMORY[0xFFFF93B0];
          __dmb(0xBu);
          v48 = MEMORY[0xFFFF93B0];
          __dmb(0xBu);
        }
        while ( *(_QWORD *)&v46 != v48 );
        v179[10] = v46;
        v179[11] = v47;
        memmove(v6, (int)v179, v134);
        v11 = v134;
        v133 = v134;
        v17 = v136;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 48;
      return -1073741820;
    case 4:
    case 10:
    case 25:
    case 29:
    case 96:
      return -1073741822;
    case 5:
    case 57:
    case 148:
      v17 = ExpGetProcessInformation(v6, v134, &v133, 0, a1);
      v11 = v133;
      goto LABEL_613;
    case 6:
    case 72:
      return -1073741637;
    case 7:
      if ( v134 == 24 )
      {
        *(_DWORD *)v6 = dword_920074;
        *(_DWORD *)(v6 + 4) = dword_920078;
        *(_DWORD *)(v6 + 8) = dword_92007C;
        *(_DWORD *)(v6 + 12) = dword_920080;
        *(_DWORD *)(v6 + 16) = dword_920088;
        *(_DWORD *)(v6 + 20) = dword_92008C;
        v17 = v137;
        v11 = 24;
        v133 = 24;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 24;
      return -1073741820;
    case 8:
    case 141:
      if ( a1 == 8 )
        v20 = 48;
      else
        v20 = 72;
      v144 = v20;
      v138 = v20;
      if ( !v134 )
        goto LABEL_137;
      if ( !(v134 % v20) )
      {
        v11 = 0;
        v142 = 0;
        v145 = 0;
        v21 = v147;
        v22 = v148[0];
        v23 = v138;
        for ( i = 0; ; v145 = i )
        {
          v149 = v6;
          if ( i >= v21 )
            break;
          LOWORD(v143) = v22;
          i = (unsigned __int8)i;
          HIWORD(v143) = (unsigned __int8)i;
          if ( v22 || (unsigned __int8)i >= (unsigned int)KeNumberProcessors_0 )
            i = -1;
          v140 = (int)*(&KiProcessorBlock + i);
          v25 = v23 + v11;
          if ( v134 < v23 + v11 )
            break;
          v11 += v23;
          j = v25;
          PoGetIdleTimes((int)&v143, 0, (int)v181);
          v26 = (_DWORD *)v140;
          v27 = KeMaximumIncrement;
          *(_QWORD *)(v6 + 16) = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v140 + 2312);
          *(_QWORD *)(v6 + 8) = v181[1] * (unsigned __int64)(unsigned int)v27;
          *(_QWORD *)(v6 + 24) = (unsigned int)v27 * (unsigned __int64)(unsigned int)v26[579];
          *(_QWORD *)(v6 + 32) = (unsigned int)v27 * (unsigned __int64)(unsigned int)v26[580];
          *(_QWORD *)v6 = v181[0] * (unsigned __int64)(unsigned int)v27;
          *(_DWORD *)(v6 + 40) = v26[576];
          if ( a1 == 141 )
          {
            *(_QWORD *)(v6 + 48) = (unsigned int)v27 * (unsigned __int64)(unsigned int)v26[587];
            *(_DWORD *)(v6 + 44) = 0;
            *(_DWORD *)(v6 + 56) = 0;
            *(_DWORD *)(v6 + 60) = 0;
            *(_DWORD *)(v6 + 64) = 0;
            *(_DWORD *)(v6 + 68) = 0;
          }
          v21 = v147;
          v22 = v148[0];
          v23 = v138;
          v6 += v138;
          i = v142 + 1;
          v142 = i;
        }
        goto LABEL_528;
      }
      v12 = v147;
      v20 = v138;
LABEL_137:
      if ( a6 )
        *a6 = v20 * v12;
      return -1073741820;
    case 9:
      if ( v134 == 4 )
      {
        *(_DWORD *)v6 = NtGlobalFlag;
        v17 = v137;
        goto LABEL_213;
      }
      if ( a6 )
        *a6 = 4;
      return -1073741820;
    case 11:
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v63 = __mrc(15, 0, 13, 0, 3);
      v64 = *(__int16 *)((v63 & 0xFFFFFFC0) + 0x134);
      *(_WORD *)((v63 & 0xFFFFFFC0) + 0x134) = v64 - 1;
      v65 = ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v64, v63);
      v66 = ExpQueryModuleInformation(v65, (_DWORD *)v6, v134, &v133);
      goto LABEL_218;
    case 12:
      if ( v134 < 0x28 )
      {
        if ( a6 )
          *a6 = 40;
        return -1073741820;
      }
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v17 = ExpGetLockInformation(v6, v134, &v133);
      goto LABEL_144;
    case 13:
      if ( v134 >= 0x9C )
        goto LABEL_233;
      if ( a6 )
        *a6 = 156;
      return -1073741820;
    case 14:
    case 15:
    case 19:
LABEL_233:
      v17 = -1073741822;
      goto LABEL_613;
    case 16:
      if ( v134 < 0x14 )
      {
        if ( a6 )
          *a6 = 20;
        return -1073741820;
      }
      if ( (v6 & 3) != 0 )
        return -2147483646;
      if ( !ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
      {
        v17 = ExpGetHandleInformation(v6, v134, &v133);
        goto LABEL_144;
      }
      return -1073741790;
    case 17:
      if ( v134 < 0x38 )
      {
        if ( a6 )
          *a6 = 56;
        return -1073741820;
      }
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v17 = ExpGetObjectInformation(v6, v134, &v133);
      goto LABEL_144;
    case 18:
    case 144:
      if ( a1 == 18 )
        v72 = 24;
      else
        v72 = 32;
      v133 = v72;
      if ( v134 >= v72 )
      {
        v133 = 0;
        v17 = MmGetPageFileInformation(v6, v134, a1 == 144, &v133);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = v72;
      return -1073741820;
    case 21:
    case 81:
    case 119:
    case 120:
      if ( v134 < 0x24 )
      {
        if ( a6 )
          *a6 = 36;
        return -1073741820;
      }
      v73 = 2;
      if ( a1 == 119 )
      {
        v73 = 3;
      }
      else if ( a1 == 120 )
      {
        v73 = 4;
      }
      MmQuerySystemWorkingSetInformation(v73, v178);
      *(_DWORD *)v6 = v178[0];
      *(_DWORD *)(v6 + 4) = v178[1];
      *(_DWORD *)(v6 + 8) = v178[2];
      v17 = v137;
      *(_DWORD *)(v6 + 12) = v178[3];
      *(_DWORD *)(v6 + 16) = v178[4];
      *(_DWORD *)(v6 + 20) = v178[5];
      *(_DWORD *)(v6 + 24) = v178[6];
      *(_DWORD *)(v6 + 28) = v178[7];
      *(_DWORD *)(v6 + 32) = v178[8];
      v11 = 36;
      v133 = 36;
      goto LABEL_613;
    case 22:
      if ( v134 >= 0x20 )
      {
        v17 = ExGetPoolTagInfo(v6, v134, &v133);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = 32;
      return -1073741820;
    case 23:
      v11 = 24 * v12;
      v133 = 24 * v12;
      if ( v134 < 24 * v12 )
      {
        if ( a6 )
          *a6 = v11;
        return -1073741820;
      }
      v84 = 0;
      v85 = v148[0];
      while ( 1 )
      {
        v145 = v84;
        v138 = v6;
        if ( v84 >= v12 )
          break;
        v86 = (unsigned __int8)v84;
        if ( v85 || (unsigned __int8)v84 >= (unsigned int)KeNumberProcessors_0 )
          v86 = -1;
        v87 = *(&KiProcessorBlock + v86);
        *(_DWORD *)v6 = v87[397];
        *(_DWORD *)(v6 + 4) = v87[424];
        *(_DWORD *)(v6 + 8) = v87[435];
        *(_DWORD *)(v6 + 12) = KeTimeIncrement;
        *(_DWORD *)(v6 + 16) = 0;
        *(_DWORD *)(v6 + 20) = 0;
        v85 = v148[0];
        v6 += 24;
        ++v84;
      }
      goto LABEL_339;
    case 24:
      if ( v134 == 20 )
      {
        *(_DWORD *)(v6 + 4) = KiMaximumDpcQueueDepth;
        *(_DWORD *)(v6 + 8) = KiMinimumDpcRate;
        *(_DWORD *)(v6 + 12) = KiAdjustDpcThreshold;
        *(_DWORD *)(v6 + 16) = KiIdealDpcRate;
        v17 = v137;
        v11 = 20;
        v133 = 20;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 20;
      return -1073741820;
    case 28:
      if ( v134 == 12 )
      {
        v49 = ExAcquireTimeRefreshLock(1);
        v50 = KeTimeAdjustment;
        __dmb(0xBu);
        v51 = KeTimeSynchronization;
        __dmb(0xBu);
        ExReleaseTimeRefreshLock(v49);
        *(_DWORD *)v6 = v50;
        *(_DWORD *)(v6 + 4) = KeMaximumIncrement;
        *(_BYTE *)(v6 + 8) = v51;
        v11 = 12;
        v133 = 12;
        v17 = v136;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 31:
      v17 = EtwQueryPerformanceTraceInformation(v6, v134, v140, &v133);
      goto LABEL_144;
    case 33:
      if ( v134 >= 0x10 )
      {
        v11 = 16;
        v133 = 16;
        v75 = 0;
        v76 = 0;
        v77 = 0;
        v78 = &KiProcessorBlock;
        while ( v77 < v12 )
        {
          v79 = (int)*v78++;
          v75 += *(_DWORD *)(v79 + 3280);
          v76 += *(_DWORD *)(v79 + 2356);
          ++v77;
        }
        *(_DWORD *)v6 = v75;
        *(_DWORD *)(v6 + 4) = v76;
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 12) = 0;
        v17 = v137;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 16;
      return -1073741820;
    case 35:
      if ( v134 >= 2 )
      {
        *(_BYTE *)v6 = KdDebuggerEnabled;
        *(_BYTE *)(v6 + 1) = KdDebuggerNotPresent;
        v17 = v137;
        v11 = 2;
        v133 = 2;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 2;
      return -1073741820;
    case 36:
      if ( v134 >= 0x30 )
      {
        v80 = 0;
        v81 = 0;
        v82 = &KiProcessorBlock;
        while ( v81 < v12 )
        {
          v83 = (int)*v82++;
          v80 += *(_DWORD *)(v83 + 1588);
          ++v81;
        }
        *(_DWORD *)v6 = v80;
        *(_DWORD *)(v6 + 4) = KeThreadSwitchCounters;
        *(_DWORD *)(v6 + 8) = dword_624D48;
        *(_DWORD *)(v6 + 12) = dword_624D44;
        *(_DWORD *)(v6 + 16) = dword_624D4C;
        *(_DWORD *)(v6 + 20) = dword_624D50;
        *(_DWORD *)(v6 + 24) = dword_624D58;
        *(_DWORD *)(v6 + 28) = dword_624D54;
        *(_DWORD *)(v6 + 32) = dword_624D5C;
        *(_DWORD *)(v6 + 36) = dword_624D60;
        *(_DWORD *)(v6 + 40) = dword_624D64;
        *(_DWORD *)(v6 + 44) = dword_624D68;
        v17 = v137;
        v11 = 48;
        v133 = 48;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 48;
      return -1073741820;
    case 37:
      if ( v134 >= 0xC )
      {
        v17 = CmQueryRegistryQuotaInformation(v6, &DbgkErrorPortCommTimeout);
        v11 = 12;
        v133 = 12;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 42:
      v11 = 48 * v12;
      v133 = 48 * v12;
      if ( v134 < 48 * v12 )
        goto LABEL_149;
      v35 = 0;
      v17 = v137;
      v36 = v148[0];
      while ( 1 )
      {
        v145 = v35;
        v144 = v35;
        v138 = v6;
        if ( v35 >= v12 )
          break;
        LOWORD(v143) = v36;
        HIWORD(v143) = (unsigned __int8)v35;
        PoGetIdleTimes((int)&v143, (int)v183, 0);
        v37 = v183[1];
        v38 = v183[2];
        v39 = v183[3];
        *(_DWORD *)v6 = v183[0];
        *(_DWORD *)(v6 + 4) = v37;
        *(_DWORD *)(v6 + 8) = v38;
        *(_DWORD *)(v6 + 12) = v39;
        v40 = v183[5];
        v41 = v183[6];
        v42 = v183[7];
        *(_DWORD *)(v6 + 16) = v183[4];
        *(_DWORD *)(v6 + 20) = v40;
        *(_DWORD *)(v6 + 24) = v41;
        *(_DWORD *)(v6 + 28) = v42;
        v43 = v183[9];
        v44 = v183[10];
        v45 = v183[11];
        *(_DWORD *)(v6 + 32) = v183[8];
        *(_DWORD *)(v6 + 36) = v43;
        *(_DWORD *)(v6 + 40) = v44;
        *(_DWORD *)(v6 + 44) = v45;
        v17 = v137;
        v12 = v147;
        v36 = v148[0];
        v6 += 48;
        v35 = v144 + 1;
        v11 = v133;
      }
      goto LABEL_613;
    case 43:
      if ( v134 >= 0xC )
      {
        v133 = v134;
        v17 = ExpQueryLegacyDriverInformation(v6, &v133);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 44:
      if ( v134 < 0xAC )
      {
        if ( a6 )
          *a6 = 172;
        return -1073741820;
      }
      ExAcquireTimeRefreshLock(1);
      v88 = memmove(v6, (int)&ExpTimeZoneInformation, 0xACu);
      ExReleaseTimeRefreshLock(v88);
      v11 = 172;
      v133 = 172;
LABEL_339:
      v17 = 0;
      goto LABEL_613;
    case 45:
      v17 = ExpGetLookasideInformation(v6, v134, (int)&v133);
      goto LABEL_144;
    case 50:
      if ( v134 == 4 )
      {
        *(_DWORD *)v6 = MmSystemRangeStart;
        v17 = v137;
        goto LABEL_213;
      }
      if ( a6 )
        *a6 = 4;
      return -1073741820;
    case 51:
      if ( v134 >= 0x68 )
      {
        v17 = VfGetVerifierInformation(v6, v134, &v133, 0);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = 104;
      return -1073741820;
    case 53:
      if ( v134 >= 0xC )
      {
        v142 = *(_DWORD *)v6;
        v61 = *(_DWORD *)(v6 + 8);
        v169 = v61;
        v62 = *(_DWORD *)(v6 + 4);
        v171 = v62;
        ProbeForWrite(v61, v62, 8);
        v17 = ExpGetProcessInformation(v61, v62, &v133, &v142, 5);
        v11 = v133;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 55:
      v17 = ExpQueryNumaProcessorMap((int *)v6, v134, &v133);
      goto LABEL_144;
    case 56:
      v17 = PfSnQueryPrefetcherInformation(v12);
      goto LABEL_144;
    case 58:
      if ( v134 >= 4 )
      {
        *(_DWORD *)v6 = KeGetRecommendedSharedDataAlignment();
        v17 = v137;
        goto LABEL_213;
      }
      if ( a6 )
        *a6 = 4;
      return -1073741820;
    case 59:
      if ( v134 != 4 )
      {
        if ( a6 )
          *a6 = 4;
        return -1073741820;
      }
      if ( MEMORY[0xFFFF92E0] == -1 )
      {
        MEMORY[0xFFFF92E0] = 0;
        v17 = ExpReadComPlusPackage();
        v136 = v17;
        if ( v17 < 0 )
          goto LABEL_381;
      }
      else
      {
        v17 = v137;
      }
      *(_DWORD *)v6 = MEMORY[0xFFFF92E0];
      goto LABEL_213;
    case 60:
      v17 = ExpQueryNumaAvailableMemory(v6, v134, &v133);
      goto LABEL_144;
    case 61:
      v11 = 80 * v12;
      v133 = 80 * v12;
      if ( v134 < 80 * v12 )
        goto LABEL_149;
      v155 = v6;
      v31 = 0;
      v32 = v148[0];
      while ( 1 )
      {
        v145 = v31;
        v138 = v31;
        if ( v31 >= v12 )
          break;
        LOWORD(v143) = v32;
        v33 = (unsigned __int8)v31;
        HIWORD(v143) = (unsigned __int8)v31;
        if ( v32 || (unsigned __int8)v31 >= (unsigned int)KeNumberProcessors_0 )
          v33 = -1;
        v34 = *(&KiProcessorBlock + v33);
        PoGetPerfStateAndParkingInfo((int)&v143, (int)v180, 0, v148);
        memset((_BYTE *)v6, 0, 80);
        *(_QWORD *)(v6 + 40) = (unsigned int)(v34[578] + v34[577]) * (unsigned __int64)(unsigned int)KeMaximumIncrement;
        *(_QWORD *)(v6 + 48) = (unsigned int)KeMaximumIncrement * (unsigned __int64)*(unsigned int *)(v34[3] + 404);
        if ( v180[28] )
        {
          *(_BYTE *)v6 = v180[8];
          *(_BYTE *)(v6 + 7) = v180[12];
          *(_BYTE *)(v6 + 8) = v180[16];
          *(_DWORD *)(v6 + 12) = 1;
        }
        *(_DWORD *)(v6 + 72) = v148[0];
        *(_DWORD *)(v6 + 76) = v148[1];
        v6 += 80;
        v155 = v6;
        v12 = v147;
        v31 = v138 + 1;
        v11 = v133;
      }
      goto LABEL_612;
    case 62:
      if ( v134 == 44 )
      {
LABEL_98:
        v17 = ExpGetSystemBasicInformation(v6);
        v11 = 44;
        goto LABEL_99;
      }
      if ( a6 )
        *a6 = 44;
      return -1073741820;
    case 63:
      if ( v134 >= 0xC )
      {
LABEL_106:
        v17 = ExpGetSystemProcessorInformation(v6);
        v11 = 12;
        v133 = 12;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 12;
      return -1073741820;
    case 64:
      if ( v134 < 0x24 )
      {
        if ( a6 )
          *a6 = 36;
        return -1073741820;
      }
      if ( (v6 & 3) != 0 )
        return -2147483646;
      if ( !ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
      {
        v17 = ExpGetHandleInformationEx(v6, v134, &v133);
        goto LABEL_144;
      }
      return -1073741790;
    case 65:
      if ( v134 >= 4 )
      {
        v90 = 0;
        v91 = 0;
        v92 = &KiProcessorBlock;
        while ( v91 < v12 )
        {
          v93 = (int)*v92++;
          v90 += *(_DWORD *)(v93 + 2876);
          ++v91;
        }
        *(_DWORD *)v6 = v90;
        v17 = v137;
        goto LABEL_213;
      }
      if ( a6 )
        *a6 = 4;
      return -1073741820;
    case 66:
      if ( v134 < 0x10 )
      {
        if ( a6 )
          *a6 = 16;
        return -1073741820;
      }
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v17 = ExGetBigPoolInfo((_DWORD *)v6, v134, 1, &v133);
      goto LABEL_144;
    case 67:
      if ( v134 < 0xC )
      {
        if ( a6 )
          *a6 = 12;
        return -1073741820;
      }
      v142 = *(_DWORD *)v6;
      v173 = *(_DWORD *)(v6 + 8);
      v168 = *(_DWORD *)(v6 + 4);
      if ( (v173 & 7) != 0 )
        return -2147483646;
      v17 = ExGetSessionPoolTagInformation();
      goto LABEL_144;
    case 68:
      if ( v134 < 0x14 )
      {
        if ( a6 )
          *a6 = 20;
        return -1073741820;
      }
      v142 = *(_DWORD *)(v6 + 4);
      if ( (v6 & 7) != 0 )
        return -2147483646;
      v17 = MmGetSessionMappedViewInformation(v6, v134, &v133, &v142);
      goto LABEL_144;
    case 69:
      goto LABEL_601;
    case 70:
      if ( v134 != 4 )
      {
        if ( a6 )
          *a6 = 4;
        return -1073741820;
      }
      *(_DWORD *)v6 = ObpObjectSecurityMode;
      v17 = v137;
LABEL_213:
      v11 = 4;
      goto LABEL_214;
    case 73:
      v17 = KeBuildLogicalProcessorSystemInformation(v148[0], v6, v134, &v133);
      v136 = v17;
      goto LABEL_144;
    case 76:
      v17 = ExpGetSystemFirmwareTableInformation(v6, v140, v134, &v133);
      goto LABEL_144;
    case 77:
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v69 = __mrc(15, 0, 13, 0, 3);
      v70 = *(__int16 *)((v69 & 0xFFFFFFC0) + 0x134);
      *(_WORD *)((v69 & 0xFFFFFFC0) + 0x134) = v70 - 1;
      v71 = ExAcquireResourceExclusiveLite((int)&PsLoadedModuleResource, 1, v70, v69);
      v66 = ExpQueryModuleInformationEx(v71, v6, v134, &v133);
LABEL_218:
      v17 = v66;
      ExReleaseResourceLite((int)&PsLoadedModuleResource);
      v67 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v68 = *(_WORD *)(v67 + 0x134);
      *(_WORD *)(v67 + 308) = v68 + 1;
      if ( v68 != -1 || *(_DWORD *)(v67 + 100) == v67 + 100 || *(_WORD *)(v67 + 310) )
        goto LABEL_144;
      KiCheckForKernelApcDelivery(v67);
      v11 = v133;
      goto LABEL_613;
    case 79:
      v17 = PfQuerySuperfetchInformation(v12);
      goto LABEL_144;
    case 80:
      v17 = MmQueryMemoryListInformation(v6, v134, (int)&KeNumberProcessors_0, &v133);
      goto LABEL_144;
    case 83:
      v11 = 8 * v12;
      v133 = 8 * v12;
      if ( v134 < 8 )
        goto LABEL_522;
      if ( v134 >= v11 )
      {
        v17 = v137;
        v96 = v147;
      }
      else
      {
        v96 = v134 >> 3;
        v146 = (_DWORD *)(v134 >> 3);
        v17 = -1073741820;
        v136 = -1073741820;
      }
      v160 = v6;
      KeFlushProcessWriteBuffers(1);
      v97 = 0;
      v98 = v148[0];
      while ( 1 )
      {
        v145 = v97;
        if ( v97 >= v96 )
          break;
        v99 = (unsigned __int8)v97;
        if ( v98 || (unsigned __int8)v97 >= (unsigned int)KeNumberProcessors_0 )
          v99 = -1;
        v100 = *((_DWORD *)*(&KiProcessorBlock + v99) + 3);
        for ( j = v100; ; v100 = j )
        {
          v102 = *(_QWORD *)(v100 + 48);
          v101 = (unsigned __int64 *)(v100 + 48);
          v103 = v102;
          do
            v104 = __ldrexd(v101);
          while ( v104 == v103 && __strexd(v103, v101) );
          if ( v103 == v104 )
            break;
          __dmb(0xAu);
          __yield();
        }
        *(_DWORD *)v6 = v103;
        v6 += 8;
        *(_DWORD *)(v6 - 4) = HIDWORD(v103);
        v160 = v6;
        v98 = v148[0];
        ++v97;
      }
      goto LABEL_144;
    case 86:
      v17 = ObQueryRefTraceInformation(v6, v134, &v133);
      goto LABEL_144;
    case 87:
      v11 = 8;
      v133 = 8;
      if ( v134 != 8 )
        goto LABEL_149;
      *(_DWORD *)v6 = MmSpecialPoolTag;
      *(_DWORD *)(v6 + 4) = MmSpecialPoolCatchOverruns != 0;
      v17 = v137;
      goto LABEL_613;
    case 88:
      v11 = 12;
      v133 = 12;
      if ( v134 != 12 )
        goto LABEL_149;
      v52 = *(_DWORD *)(v6 + 4);
      v53 = *(_DWORD *)(v6 + 8);
      v156 = *(_DWORD *)v6;
      v157 = v52;
      v158 = v53;
      if ( (_WORD)v52 )
        return -1073741811;
      v54 = HIWORD(v157);
      j = HIWORD(v157);
      if ( (v157 & 0x10000) != 0 )
        return -1073741811;
      if ( v140 )
      {
        v55 = v158;
        if ( HIWORD(v157) )
        {
          if ( (v158 & 1) != 0 )
            ExRaiseDatatypeMisalignment(HIWORD(v157));
          if ( HIWORD(v157) + v158 > MmUserProbeAddress || HIWORD(v157) + v158 < v158 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        v55 = v158;
      }
      v56 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v144 = v54;
      --*(_WORD *)(v56 + 308);
      v57 = PsLookupProcessByProcessId(v156, &v138);
      v15 = v57;
      if ( v57 < 0 )
      {
        v58 = (__int16)(*(_WORD *)(v56 + 308) + 1);
        *(_WORD *)(v56 + 308) = v58;
        if ( !v58 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
          KiCheckForKernelApcDelivery(v57);
        return v15;
      }
      v17 = PsQueryFullProcessImageName(v138, v6 + 4, v55, &v144);
      v59 = ObfDereferenceObjectWithTag(v138);
      v60 = *(_WORD *)(v56 + 308) + 1;
      *(_WORD *)(v56 + 308) = v60;
      if ( !v60 && *(_DWORD *)(v56 + 100) != v56 + 100 && !*(_WORD *)(v56 + 310) )
        KiCheckForKernelApcDelivery(v59);
      if ( v17 == -1073741820 )
      {
        *(_WORD *)(v6 + 6) = v144;
        v11 = v133;
        goto LABEL_613;
      }
      goto LABEL_144;
    case 90:
      v11 = 32;
      v133 = 32;
      if ( v134 < 0x14 )
      {
        if ( a6 )
          *a6 = 32;
        return -1073741820;
      }
      v112 = unk_61A1E4;
      v113 = unk_61A1E8;
      v114 = unk_61A1EC;
      *(_DWORD *)v6 = ExpBootEnvironmentInformation;
      *(_DWORD *)(v6 + 4) = v112;
      *(_DWORD *)(v6 + 8) = v113;
      *(_DWORD *)(v6 + 12) = v114;
      *(_DWORD *)(v6 + 16) = dword_61A1F0;
      v17 = v137;
      if ( v134 >= 0x20 )
      {
        *(_DWORD *)(v6 + 24) = dword_61A1F8;
        *(_DWORD *)(v6 + 28) = dword_61A1FC;
        goto LABEL_613;
      }
      v11 = 20;
      goto LABEL_214;
    case 91:
    case 159:
      v11 = 0;
      v133 = 0;
      if ( !v140 )
        goto LABEL_601;
      v17 = -1073741790;
      goto LABEL_613;
    case 92:
      if ( v134 != 36 )
      {
        if ( a6 )
          *a6 = 36;
        return -1073741820;
      }
      v17 = VfGetVerifierInformationEx(v6, &DbgkErrorPortCommTimeout);
      if ( v17 >= 0 )
      {
        v11 = 36;
        goto LABEL_214;
      }
      v11 = 0;
      v133 = 0;
      goto LABEL_613;
    case 95:
      if ( !v140 || !SeSinglePrivilegeCheck(SeDebugPrivilege, dword_922784, v140) )
        return -1073741790;
      if ( v134 >= 0x34 )
      {
        v17 = ExpCovQueryInformation(v6, v134, &v133);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = 52;
      return -1073741820;
    case 98:
      v17 = IoQuerySystemDeviceName(98, v6, v134, &v133);
      goto LABEL_144;
    case 99:
      v17 = IopRetrieveSystemDeviceName(SyspartDirectGetSystemDisk, v6, v134, &v133);
      if ( v17 == -1073740718 && IopAmbiguousSystemDisk )
        v17 = -1073740719;
      goto LABEL_144;
    case 100:
      v162[0] = 0;
      v162[2] = 0;
      v162[1] = LOWORD(v148[0]);
      v162[0] = KeQueryGroupAffinity(v148[0]);
      v28 = *((_BYTE *)RtlpBitsClearTotal + (~v162[0] >> 24))
          + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)(~v162[0] >> 16))
          + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~LOBYTE(v162[0]))
          + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~LOWORD(v162[0]) >> 8));
      v17 = PpmCapturePerformanceDistribution(0, 0, v28, v162, &v154);
      if ( v17 != -1073741820 )
        goto LABEL_144;
      v11 = v154;
      if ( v154 > v134 )
      {
        v17 = -1073741820;
        v133 = v154;
        goto LABEL_613;
      }
      v29 = (_BYTE *)ExAllocatePoolWithTag(512, v154, 1951223888);
      v30 = (unsigned int)v29;
      v138 = (int)v29;
      if ( !v29 )
        goto LABEL_143;
      memset(v29, 0, v154);
      v17 = PpmCapturePerformanceDistribution(v30, v154, v28, v162, &v133);
      if ( v17 >= 0 )
        memmove(v6, v30, v133);
      ExFreePoolWithTag(v30);
      v11 = v133;
      goto LABEL_613;
    case 101:
      v17 = ExpQueryNumaProximityNode(v6, v134, &v133);
      goto LABEL_144;
    case 102:
      if ( v134 >= 0x1B0 )
      {
        ExAcquireTimeRefreshLock(1);
        v89 = memmove(v6, (int)&ExpTimeZoneInformation, 0x1B0u);
        ExReleaseTimeRefreshLock(v89);
        v11 = 432;
        v133 = 432;
        v17 = 0;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 432;
      return -1073741820;
    case 103:
      v17 = SeCodeIntegrityQueryInformation(v6, v134, &v133);
      goto LABEL_144;
    case 105:
      v17 = off_617B54(23, 0, 0, &v154);
      if ( v17 != -1073741820 )
      {
        v17 = -1073741637;
        goto LABEL_144;
      }
      v11 = v154;
      if ( v134 < v154 || !v6 )
      {
LABEL_99:
        v133 = v11;
        goto LABEL_613;
      }
      v115 = v140;
      if ( v140 )
      {
        v116 = ExAllocatePoolWithQuotaTag(9u, v154, 1868983881);
        v138 = v116;
        if ( !v116 )
          goto LABEL_143;
        v11 = v154;
      }
      else
      {
        v116 = v6;
        v138 = v6;
      }
      v117 = off_617B54(23, v11, v116, &v133);
      v17 = v117;
      if ( v115 )
      {
        if ( v117 >= 0 )
          memmove(v6, v116, v133);
        ExFreePoolWithTag(v116);
      }
      goto LABEL_144;
    case 106:
      v17 = MmQuerySystemVaInformation(v6, v134, &v133);
      goto LABEL_144;
    case 107:
      v133 = v134;
      v17 = KeQueryLogicalProcessorRelationship(0, v149, v6, &v133);
      v136 = v17;
      goto LABEL_144;
    case 108:
      v11 = 8 * v12;
      v133 = 8 * v12;
      if ( v134 < 8 )
        goto LABEL_522;
      if ( v134 >= v11 )
      {
        v17 = v137;
      }
      else
      {
        v12 = v134 >> 3;
        v146 = (_DWORD *)(v134 >> 3);
        v17 = -1073741820;
        v137 = -1073741820;
        v136 = -1073741820;
      }
      v159 = v6;
      v105 = 0;
      v106 = v148[0];
      while ( 1 )
      {
        v145 = v105;
        if ( v105 >= v12 )
          break;
        v107 = (unsigned __int8)v105;
        if ( v106 || (unsigned __int8)v105 >= (unsigned int)KeNumberProcessors_0 )
          v107 = -1;
        v108 = (int)*(&KiProcessorBlock + v107);
        for ( j = v108; ; v108 = j )
        {
          v109 = (unsigned int *)(v108 + 2744);
          v110 = v109[1];
          v144 = *v109;
          v138 = v106;
          do
            v111 = __ldrexd((unsigned __int64 *)v109);
          while ( v111 == __PAIR64__(v110, v144) && __strexd(__PAIR64__(v110, v144), (unsigned __int64 *)v109) );
          v138 = HIDWORD(v111);
          v17 = v137;
          v106 = v148[0];
          if ( v144 == (_DWORD)v111 && v110 == v138 )
            break;
          __dmb(0xAu);
          __yield();
        }
        *(_DWORD *)v6 = v144;
        v6 += 8;
        *(_DWORD *)(v6 - 4) = v110;
        v159 = v6;
        ++v105;
        v11 = v133;
      }
      goto LABEL_613;
    case 109:
      v17 = SmQueryStoreInformation(v12);
      goto LABEL_144;
    case 112:
      v17 = IoQueryVhdBootInformation();
      goto LABEL_144;
    case 113:
      v17 = PsQueryCpuQuotaInformation((unsigned int *)v6, v134, v140, (unsigned int)&v133);
      goto LABEL_144;
    case 115:
      if ( v142 )
      {
        v17 = -1073741820;
      }
      else
      {
        v11 = 4;
        v133 = 4;
        if ( v134 >= 4 )
        {
          *(_DWORD *)v6 = DbgkErrorPortStartTimeout;
          *(_DWORD *)(v6 + 4) = DbgkErrorPortCommTimeout;
          v17 = v137;
        }
        else
        {
          v17 = -1073741820;
        }
      }
      goto LABEL_613;
    case 116:
      v17 = IoQueryLowPriorityIoInformation();
      goto LABEL_144;
    case 117:
      v11 = 888;
      v133 = 888;
      if ( v134 != 888 )
      {
        v17 = -1073741820;
        goto LABEL_613;
      }
      if ( v140 )
        return -1073741790;
      v17 = ExQueryBootEntropyInformation(v6, &DbgkErrorPortCommTimeout);
      goto LABEL_144;
    case 118:
      if ( v134 >= 0xBC )
      {
        v17 = VfGetVerifierInformation(v6, v134, &v133, 1);
        goto LABEL_144;
      }
      if ( a6 )
        *a6 = 188;
      return -1073741820;
    case 121:
      v11 = 4 * (unsigned __int16)KeNumberNodes;
      v133 = v11;
      if ( v134 >= v11 )
      {
        v94 = 0;
        v145 = 0;
        v95 = v144;
        while ( v94 < (unsigned __int16)KeNumberNodes )
        {
          *(_DWORD *)(v6 + 4 * v94) = KeNodeDistance[v94 + (unsigned __int16)KeNumberNodes * v95];
          v145 = ++v94;
          v11 = v133;
        }
        v17 = v137;
      }
      else
      {
        v17 = -1073741820;
      }
      goto LABEL_613;
    case 122:
      v11 = 8;
      v133 = 8;
      if ( v134 != 8 || !v6 )
        goto LABEL_149;
      v118 = ExAllocatePoolWithQuotaTag(9u, 8u, 1868983881);
      v119 = (_DWORD *)v118;
      j = v118;
      if ( !v118 )
        goto LABEL_143;
      v17 = off_617B54(26, 8, v118, &v133);
      if ( v17 >= 0 )
      {
        *(_DWORD *)v6 = *v119;
        *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 4) & 0xFFFFFFFE | v119[1] & 1;
        v120 = *(_DWORD *)(v6 + 4) ^ ((unsigned __int8)*(_DWORD *)(v6 + 4) ^ (unsigned __int8)v119[1]) & 2;
        *(_DWORD *)(v6 + 4) = v120;
        *(_DWORD *)(v6 + 4) ^= ((unsigned __int8)v120 ^ (unsigned __int8)v119[1]) & 4;
      }
      goto LABEL_496;
    case 123:
      if ( v134 != 16 )
      {
        if ( a6 )
          *a6 = 16;
        return -1073741820;
      }
      v163 = MmGetAvailablePages();
      v164 = MmGetTotalCommittedPages();
      v165 = MmGetTotalCommitLimit();
      v166 = MmGetPeakCommitment();
      if ( v166 < v18 )
        v166 = v18;
      *(_DWORD *)v6 = v163;
      *(_DWORD *)(v6 + 4) = v164;
      *(_DWORD *)(v6 + 8) = v165;
      *(_DWORD *)(v6 + 12) = v166;
      v17 = v137;
      v11 = 16;
      v133 = 16;
      goto LABEL_613;
    case 124:
      v11 = 12;
      v133 = 12;
      if ( v134 < 4 )
      {
        v17 = -1073741820;
        goto LABEL_613;
      }
      v167 = *(_DWORD *)v6;
      if ( v167 != 1 )
      {
        v17 = -1073741637;
        goto LABEL_613;
      }
      v11 = 12;
      v133 = 12;
      if ( v134 < 0xC )
        goto LABEL_149;
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 4) = 0;
      *(_DWORD *)(v6 + 8) = 1;
      *(_DWORD *)(v6 + 4) = 1;
      v121 = MEMORY[0xFFFF93C6];
      __dmb(0xBu);
      if ( v121 )
        *(_DWORD *)(v6 + 4) &= 0xFFFFFFFE;
      v11 = v133;
      v17 = v136;
      goto LABEL_613;
    case 125:
      if ( v134 < 0xC )
      {
        if ( a6 )
          *a6 = 12;
        return -1073741820;
      }
      v142 = *(_DWORD *)v6;
      v172 = *(_DWORD *)(v6 + 8);
      v74 = *(_DWORD *)(v6 + 4);
      v170 = v74;
      if ( (v172 & 7) != 0 )
        return -2147483646;
      if ( ExIsRestrictedCaller(v140, &DbgkErrorPortCommTimeout) )
        return -1073741790;
      v17 = ExGetSessionBigPoolInformation(v172, v74, &v133, &v142);
      goto LABEL_144;
    case 126:
      v11 = 32;
      v133 = 32;
      if ( v134 != 32 )
        goto LABEL_149;
      v17 = BgkQueryBootGraphicsInformation(0, v182);
      if ( v17 < 0 )
        goto LABEL_144;
      if ( v140 )
      {
        v182[0] = 0;
        v182[1] = 0;
      }
      v11 = v133;
      memmove(v6, (int)v182, v133);
      goto LABEL_613;
    case 128:
      if ( v142 )
      {
        v17 = -1073741820;
        goto LABEL_613;
      }
      v17 = MmEnumerateBadPages(&v146, (int)&DbgkErrorPortCommTimeout, (int)&KeNumberProcessors_0, 0);
      v119 = v146;
      if ( v146 )
        v11 = 4 * *v146;
      else
        v11 = 0;
      v133 = v11;
      if ( v134 < v11 )
        v17 = -1073741820;
      if ( !v146 )
        goto LABEL_613;
      if ( v17 >= 0 )
        memmove(v6, (int)(v146 + 1), v11);
LABEL_496:
      ExFreePoolWithTag((unsigned int)v119);
      goto LABEL_144;
    case 133:
      if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v140) )
        return -1073741727;
      v17 = ExpGetSystemPlatformBinary(v6, v134, v140);
      goto LABEL_144;
    case 134:
      v11 = 20;
      v133 = 20;
      if ( v134 != 20 )
        goto LABEL_149;
      v17 = sub_6B4F20(v12, (int *)v6);
      goto LABEL_144;
    case 135:
      v11 = 8;
      v133 = 8;
      if ( v134 >= 8 )
        goto LABEL_601;
      v17 = -1073741820;
      goto LABEL_613;
    case 136:
    case 137:
      if ( v134 == 28 )
        return ExpGetDeviceDataInformation(a1, v6, 28);
      if ( a6 )
        *a6 = 28;
      return -1073741820;
    case 138:
      v17 = ExpQueryMemoryTopologyInformation(v6, v134, &v133);
      goto LABEL_144;
    case 139:
      v17 = ExpQueryChannelInformation(v6, v134, &v133);
      goto LABEL_144;
    case 140:
      v122 = v134;
      if ( !a6 && v134 < 8 )
      {
        v17 = -1073741811;
        goto LABEL_613;
      }
      v17 = BgkQueryBootGraphicsInformation(2, &v133);
      if ( v17 < 0 )
        goto LABEL_144;
      v11 = v133;
      if ( !v133 )
      {
        v17 = -1073741670;
        goto LABEL_613;
      }
      if ( v122 < v133 )
      {
LABEL_522:
        v17 = -1073741789;
        goto LABEL_613;
      }
      v17 = BgkQueryBootGraphicsInformation(1, &v149);
      if ( v17 >= 0 )
      {
        v123 = v149;
        if ( v149 )
        {
          memmove(v6, v149, v133);
          ExFreePoolWithTag(v123);
        }
        else
        {
LABEL_143:
          v17 = -1073741670;
        }
      }
      goto LABEL_144;
    case 143:
    case 145:
    case 171:
      v17 = SeSecureBootQueryInformation(a1, v6, v134, &v133);
      goto LABEL_144;
    case 147:
      v17 = ExpQueryPortableWorkspaceEfiLauncherInformation(v6, v134, &v133);
      goto LABEL_144;
    case 149:
      if ( v134 >= 3 )
      {
        *(_BYTE *)v6 = KdpBootedNodebug == 0;
        *(_BYTE *)(v6 + 1) = KdDebuggerEnabled;
        *(_BYTE *)(v6 + 2) = KdDebuggerNotPresent == 0;
        v17 = v137;
        v11 = 3;
        v133 = 3;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 3;
      return -1073741820;
    case 150:
      if ( !ExBootLoaderMetadata )
      {
        v11 = 0;
LABEL_528:
        v133 = v11;
        goto LABEL_612;
      }
      v11 = *(_DWORD *)ExBootLoaderMetadata;
      v133 = *(_DWORD *)ExBootLoaderMetadata;
      if ( !v6 )
      {
LABEL_612:
        v17 = v137;
        goto LABEL_613;
      }
      if ( v134 >= v11 )
      {
        if ( !SeSinglePrivilegeCheck(SeTcbPrivilege, dword_9227BC, v140) )
          return -1073741727;
        v11 = v133;
        memmove(v6, ExBootLoaderMetadata + 4, v133);
        v17 = v137;
      }
      else
      {
        v17 = -1073741820;
      }
LABEL_613:
      if ( a6 )
        *a6 = v11;
LABEL_381:
      v15 = v17;
      break;
    case 151:
      v11 = 4;
      v133 = 4;
      if ( v134 >= 4 )
      {
        *(_DWORD *)v6 = ExSoftRebootFlags;
        v17 = v137;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 4;
      return -1073741820;
    case 153:
      if ( v142 )
      {
        v17 = -1073741820;
        goto LABEL_613;
      }
      v11 = 32;
      v133 = 32;
      if ( v134 < 0x20 )
      {
        if ( v134 < 0xC )
        {
          v17 = -1073741820;
          v136 = -1073741820;
          goto LABEL_613;
        }
        v133 = 12;
        *(_DWORD *)v6 = PoOffCrashConfigTable;
        *(_DWORD *)(v6 + 4) = dword_61F9A4;
        *(_DWORD *)(v6 + 8) = dword_61F9A8;
      }
      else
      {
        *(_DWORD *)v6 = PoOffCrashConfigTable;
        *(_DWORD *)(v6 + 4) = dword_61F9A4;
        *(_DWORD *)(v6 + 8) = dword_61F9A8;
        *(_DWORD *)(v6 + 16) = dword_61F9B0;
        *(_DWORD *)(v6 + 20) = dword_61F9B4;
        *(_DWORD *)(v6 + 24) = dword_61F9B8;
      }
      v11 = v133;
      v17 = v137;
      goto LABEL_613;
    case 154:
      if ( v134 < 0x20 )
      {
        if ( a6 )
          *a6 = 32;
        return -1073741820;
      }
      v17 = ExpGetSystemProcessorFeaturesInformation(v6, &DbgkErrorPortCommTimeout);
      v11 = 32;
LABEL_214:
      v133 = v11;
      goto LABEL_613;
    case 156:
      v11 = 128;
      v133 = 128;
      if ( v134 != 128 )
        goto LABEL_149;
      v17 = BgkQueryBootGraphicsInformation(3, _1B0);
      if ( v17 < 0 )
        goto LABEL_144;
      v11 = v133;
      memmove(v6, (int)_1B0, v133);
      goto LABEL_613;
    case 157:
      v11 = (unsigned __int16)word_61A1C6 + 12;
      v133 = v11;
      if ( v134 < v11 )
        goto LABEL_149;
      v124 = v6 + 12;
      *(_DWORD *)v6 = 0;
      *(_DWORD *)(v6 + 4) = 0;
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)v6 = ExpManufacturingInformation;
      *(_WORD *)(v6 + 4) = word_61A1C4;
      *(_WORD *)(v6 + 6) = word_61A1C6;
      if ( word_61A1C4 )
      {
        *(_DWORD *)(v6 + 8) = v124;
        memmove(v124, dword_61A1C8, (unsigned __int16)word_61A1C6);
      }
      v17 = v137;
      goto LABEL_613;
    case 158:
      v11 = 1;
      v133 = 1;
      if ( v134 )
      {
        *(_BYTE *)v6 = PoEnergyEstimationEnabled();
        v17 = v137;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 1;
      goto LABEL_149;
    case 160:
      v11 = v12 << 6;
      v133 = v12 << 6;
      if ( v134 < 0x40 )
        goto LABEL_522;
      if ( v134 >= v11 )
      {
        v17 = v137;
      }
      else
      {
        v12 = v134 >> 6;
        v146 = (_DWORD *)(v134 >> 6);
        v17 = -1073741820;
        v136 = -1073741820;
      }
      v161 = v6;
      v125 = 0;
      v126 = v148[0];
      while ( 1 )
      {
        v145 = v125;
        v144 = v125;
        if ( v125 >= v12 )
          break;
        v127 = (unsigned __int8)v125;
        if ( v126 || (unsigned __int8)v125 >= (unsigned int)KeNumberProcessors_0 )
          v127 = -1;
        v128 = (int)*(&KiProcessorBlock + v127);
        j = v128;
        for ( k = 0; ; ++k )
        {
          v138 = k;
          if ( k >= 4 )
            break;
          v130 = 0;
          while ( v130 < 2 )
          {
            *(_QWORD *)(v6 + 8 * (v130 + 2 * v138)) = *(_QWORD *)(v128 + 8 * (v130 + 2 * (k + 1144)));
            ++v130;
            v11 = v133;
            k = v138;
            v128 = j;
          }
        }
        v6 += 64;
        v161 = v6;
        v125 = v144 + 1;
      }
      goto LABEL_613;
    case 162:
      v17 = SeQueryTrustedPlatformModuleInformation((_DWORD *)v6, v134, &v133);
      goto LABEL_144;
    case 163:
      if ( v134 )
      {
        *(_BYTE *)v6 = KdIgnoreUmExceptions;
        v17 = v137;
        v11 = 1;
        v133 = 1;
        goto LABEL_613;
      }
      if ( a6 )
        *a6 = 1;
      return -1073741820;
    case 164:
    case 172:
      if ( !dword_61D8C4 )
      {
        v17 = -1073741823;
        goto LABEL_613;
      }
      v17 = dword_61D8C4(a1, v6, v134, &v133);
      goto LABEL_144;
    case 165:
      v11 = 16;
      v133 = 16;
      if ( v134 == 16 )
      {
        v174 = 0;
        v175 = 0;
        v176 = 0;
        v177 = 0;
        *(_DWORD *)v6 = 0;
        *(_DWORD *)(v6 + 4) = 0;
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 12) = 0;
        v17 = v137;
      }
      else
      {
        if ( a6 )
          *a6 = 16;
LABEL_149:
        v17 = -1073741820;
      }
      goto LABEL_613;
    case 166:
      v17 = SeQueryHSTIResults(v6, v134, &v133);
      goto LABEL_144;
    case 167:
      v17 = ExpQuerySingleModuleInformation(v6, v134, v140, &v133);
      goto LABEL_144;
    case 169:
      v11 = 0;
      v133 = 0;
LABEL_601:
      v17 = -1073741637;
      goto LABEL_613;
    case 173:
      v15 = ExCpuSetResourceManagerAccessCheck(v140);
      if ( v15 < 0 )
        return v15;
      v11 = 12;
      v133 = 12;
      if ( v134 != 12 )
        goto LABEL_149;
      v17 = KeGetAffinitizedInterruptsInfo((_DWORD *)v6);
      goto LABEL_144;
    case 174:
      v17 = PsRootSiloInformation((_DWORD *)v6, v134, (int *)&v133, v13);
      goto LABEL_144;
    case 175:
      if ( v14 )
      {
        v15 = ObReferenceObjectByHandle(v14, 4096, PsProcessType, v140, &j, 0);
        v131 = j;
        if ( v15 < 0 )
          return v15;
      }
      else
      {
        v131 = 0;
      }
      v17 = KeQueryCpuSetInformation(v6, v134, &v133, v131);
      if ( v131 )
        ObfDereferenceObject(v131);
LABEL_144:
      v11 = v133;
      goto LABEL_613;
    default:
      return -1073741821;
  }
  return v15;
}
