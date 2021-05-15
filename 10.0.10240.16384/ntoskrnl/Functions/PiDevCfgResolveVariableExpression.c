// PiDevCfgResolveVariableExpression 
 
int __fastcall PiDevCfgResolveVariableExpression(int a1, int a2, int a3)
{
  unsigned int v3; // r9
  unsigned int v4; // r7
  unsigned int v5; // r10
  int v6; // r5
  unsigned int v7; // r8
  __int64 v8; // kr00_8
  _WORD *v9; // r1
  _WORD *v10; // r0
  int v13; // r4
  unsigned __int16 *v14; // r6
  unsigned int v15; // r9
  _DWORD **v16; // r6
  int v17; // r3
  unsigned __int16 *v18; // r1
  _DWORD *v19; // lr
  int *v20; // r2
  int v21; // r0
  int *v22; // r1
  unsigned int v23; // r2
  unsigned __int16 *v24; // r4
  int v25; // r0
  unsigned int v26; // r0
  int v27; // r3
  unsigned int v28; // r4
  int *v29; // r1
  _DWORD **v30; // r0
  int v31; // t1
  int v32; // r6
  unsigned int v33; // r7
  int v34; // r4
  unsigned __int16 *v35; // r10
  int *v36; // r8
  int v37; // r2
  unsigned int v38; // r3
  bool v39; // zf
  unsigned __int16 *v40; // r6
  int v41; // r0
  int v42; // r6
  bool v43; // zf
  int *v44; // r3
  int v45; // r6
  unsigned __int16 *v46; // r0
  unsigned __int16 *v47; // r0
  int v48; // r3
  int v49; // r2
  unsigned int v51; // r0
  unsigned int v52; // r3
  int v53; // r3
  unsigned __int16 *v54; // r7
  unsigned int v55; // r8
  unsigned int v56; // r6
  unsigned __int16 *v57; // r9
  int v58; // r0
  unsigned __int16 *v59; // r0
  unsigned int v60; // r2
  int v61; // r1
  unsigned int v62; // r10
  int v63; // r3
  unsigned __int16 *i; // r6
  int v65; // r6
  unsigned int *v66; // r3
  unsigned int v67; // r0
  unsigned int v68; // r0
  signed int v69; // r0
  signed int v70; // r0
  signed int v71; // r0
  signed int v72; // r0
  int v73; // r9
  unsigned int v74; // r7
  unsigned __int16 *v75; // r6
  int v76; // r8
  unsigned __int16 *v77; // r6
  unsigned int v78; // r10
  unsigned __int16 *v79; // r8
  unsigned int v80; // r9
  int v81; // r3
  int v82; // r3
  unsigned __int16 *v83; // r7
  unsigned __int16 v84; // r3
  unsigned int *v85; // r0
  unsigned int v86; // r3
  int v87; // r3
  unsigned __int16 *j; // r7
  unsigned int *v89; // r0
  int v90; // r8
  unsigned int v91; // r3
  unsigned int v92; // r1
  unsigned int v93; // r0
  int v94; // r2
  unsigned int v95; // r0
  int v96; // r3
  __int64 v97; // kr28_8
  int v98; // r3
  unsigned int v99; // r8
  unsigned __int16 *v100; // r10
  unsigned __int16 *v101; // r6
  unsigned int v102; // r9
  int v103; // r3
  int v104; // r3
  unsigned __int16 *v105; // r7
  unsigned __int16 v106; // r3
  unsigned int *v107; // r0
  int v108; // r1
  unsigned int v109; // r3
  unsigned int v110; // r1
  unsigned int v111; // r6
  _WORD *v112; // r8
  unsigned int v113; // r7
  int v114; // r3
  unsigned __int16 v115; // r3
  int v116; // r0
  unsigned int v117; // r3
  int v118; // r3
  unsigned __int8 *v119; // r1
  int v120; // r2
  int *v122; // r0
  int v123; // r7
  int v124; // r8
  int *v125; // r6
  unsigned int v126; // r4
  unsigned int v127; // t1
  unsigned int v128; // r0
  int v129; // r8
  int *v130; // r6
  unsigned int v131; // r4
  unsigned int v132; // t1
  unsigned int v133; // r0
  unsigned int *v134; // r4
  unsigned int v135; // r0
  int v137; // [sp+8h] [bp-D8h]
  int v138; // [sp+Ch] [bp-D4h]
  _DWORD **v139; // [sp+14h] [bp-CCh]
  unsigned int *v140; // [sp+18h] [bp-C8h] BYREF
  int v141; // [sp+1Ch] [bp-C4h]
  unsigned int v142; // [sp+20h] [bp-C0h]
  unsigned __int16 *v143; // [sp+24h] [bp-BCh]
  unsigned int v144; // [sp+28h] [bp-B8h] BYREF
  unsigned __int16 v145[2]; // [sp+30h] [bp-B0h] BYREF
  unsigned __int16 *v146; // [sp+34h] [bp-ACh]
  unsigned __int16 v147[2]; // [sp+38h] [bp-A8h] BYREF
  _WORD *v148; // [sp+3Ch] [bp-A4h]
  unsigned __int16 *v149; // [sp+40h] [bp-A0h] BYREF
  int v150; // [sp+44h] [bp-9Ch]
  int v151; // [sp+48h] [bp-98h]
  unsigned int v152; // [sp+4Ch] [bp-94h]
  unsigned __int16 v153[4]; // [sp+50h] [bp-90h] BYREF
  unsigned __int16 v154[4]; // [sp+58h] [bp-88h] BYREF
  unsigned __int16 v155[4]; // [sp+60h] [bp-80h] BYREF
  unsigned __int16 v156[4]; // [sp+68h] [bp-78h] BYREF
  unsigned __int16 v157[4]; // [sp+70h] [bp-70h] BYREF
  unsigned __int16 v158[4]; // [sp+78h] [bp-68h] BYREF
  unsigned __int16 v159[4]; // [sp+80h] [bp-60h] BYREF
  unsigned __int16 v160[4]; // [sp+88h] [bp-58h] BYREF
  unsigned __int16 v161[4]; // [sp+90h] [bp-50h] BYREF
  unsigned __int16 v162[4]; // [sp+98h] [bp-48h] BYREF
  unsigned __int16 v163[4]; // [sp+A0h] [bp-40h] BYREF
  unsigned __int16 v164[4]; // [sp+A8h] [bp-38h] BYREF
  _DWORD *v165; // [sp+B0h] [bp-30h] BYREF
  int v166; // [sp+B4h] [bp-2Ch]
  _DWORD *v167; // [sp+B8h] [bp-28h]

  v144 = 0;
  v3 = 0;
  v150 = a3;
  v151 = a1;
  v4 = 0;
  v141 = 0;
  v142 = 0;
  v5 = 0;
  v6 = IopGetRegistryValue(a2, L"Tokens", 0, (int *)&v144);
  v7 = v144;
  if ( v6 < 0 )
    goto LABEL_341;
  if ( *(_DWORD *)(v144 + 4) != 7 )
    goto LABEL_14;
  v8 = *(_QWORD *)(v144 + 8);
  v9 = (_WORD *)(v8 + v144);
  if ( HIDWORD(v8) < 4 || (v10 = &v9[HIDWORD(v8) >> 1], *(v10 - 1)) || *(v10 - 2) )
  {
    if ( HIDWORD(v8) != 2 || *v9 )
      goto LABEL_14;
  }
  v13 = *(_DWORD *)(v144 + 8);
  v14 = (unsigned __int16 *)(v13 + v144);
  if ( !*(_WORD *)(v13 + v144) )
    goto LABEL_14;
  v15 = 0;
  do
  {
    ++v15;
    v14 += wcslen(v14) + 1;
  }
  while ( *v14 );
  v152 = v15;
  if ( !v15 )
  {
LABEL_14:
    v6 = -1073741823;
    goto LABEL_359;
  }
  v16 = (_DWORD **)ExAllocatePoolWithTag(1, 4 * v15, 1667526736);
  v139 = v16;
  if ( !v16 )
  {
    v6 = -1073741670;
    goto LABEL_359;
  }
  v17 = *(unsigned __int16 *)(v13 + v7);
  v18 = (unsigned __int16 *)(v13 + v7);
  v143 = (unsigned __int16 *)(v13 + v7);
  if ( !v17 )
    goto LABEL_336;
  while ( 1 )
  {
    v19 = v165;
    v20 = 0;
    if ( !*v18 )
      goto LABEL_34;
    if ( v18[1] && v18[2] )
      break;
    v21 = *(_DWORD *)v18;
    v22 = &dword_8C6BF4;
    v23 = 1;
    while ( v21 != *(_DWORD *)v22[1] )
    {
      ++v23;
      v22 += 3;
      if ( v23 >= 0x1A )
        goto LABEL_28;
    }
    v20 = &PiDevCfgNullSid[3 * v23 + 3];
LABEL_34:
    if ( !v20 )
      break;
    v28 = v20[2];
    if ( v28 )
    {
      v29 = (int *)&v165;
      v30 = &v16[v4];
      while ( v4 )
      {
        v31 = (int)*--v30;
        --v4;
        ++v5;
        *v29++ = v31;
        v141 = v5;
        v142 = v4;
        if ( v5 >= v28 )
          goto LABEL_41;
      }
      v6 = -1073741823;
LABEL_41:
      v19 = v165;
    }
    if ( v6 < 0 )
      goto LABEL_340;
    v32 = 0;
    v33 = 0;
    v34 = 0;
    v137 = 0;
    v138 = 0;
    v35 = 0;
    v140 = 0;
    v36 = 0;
    if ( v141 == 1 )
    {
      v37 = *v20;
      v38 = v19[4];
      if ( v37 != 22 )
      {
        if ( !v38 )
          goto LABEL_163;
        if ( v38 > 2 )
        {
          if ( v38 == 4 )
          {
            v44 = (int *)v19[6];
            v45 = *v44;
            if ( v37 == 11 )
            {
              v34 = ~v45;
              goto LABEL_55;
            }
            if ( v37 != 12 )
            {
              if ( v37 == 24 )
              {
                v34 = *v44;
              }
              else
              {
                if ( v37 == 25 )
                {
                  v33 = 20;
                  v137 = 22;
                  v46 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 22, 1667526736);
                  v35 = v46;
                  if ( !v46 )
                    goto LABEL_329;
                  v6 = RtlStringCchPrintfW(v46, 0xBu, (int)L"%u", v45);
                  if ( v6 >= 0 )
                  {
                    v33 = (unsigned __int16)(2 * wcslen(v35));
                    v32 = (unsigned __int16)(v33 + 2);
                    v137 = v32;
                    goto LABEL_56;
                  }
                  ExFreePoolWithTag((unsigned int)v35);
                  v35 = 0;
                  goto LABEL_55;
                }
LABEL_54:
                v36 = dword_8C6BC0;
              }
LABEL_55:
              v32 = v137;
              goto LABEL_56;
            }
            v43 = v45 == 0;
          }
          else
          {
            if ( v38 != 7 )
              goto LABEL_163;
            v40 = (unsigned __int16 *)v19[6];
            if ( v37 == 11 )
            {
              v34 = 0;
              while ( *v40 )
              {
                ++v34;
                v40 += wcslen(v40) + 1;
              }
              goto LABEL_55;
            }
            if ( v37 != 12 )
              goto LABEL_54;
            v43 = *v40 == 0;
          }
          goto LABEL_63;
        }
        v47 = (unsigned __int16 *)v19[6];
        if ( v37 == 11 )
        {
          v51 = wcslen(v47);
LABEL_100:
          v34 = v51;
          goto LABEL_56;
        }
        if ( v37 != 12 )
        {
          if ( v37 == 24 )
          {
            if ( *v47 == 48 && ((v48 = v47[1], v48 == 120) || v48 == 88) )
            {
              v47 += 2;
              v49 = 16;
            }
            else
            {
              v49 = 10;
            }
            v34 = wcstoul(v47, &v149, v49);
            if ( v149 && !*v149 )
              goto LABEL_56;
LABEL_97:
            v34 = 0;
            goto LABEL_56;
          }
          if ( v37 != 25 )
            goto LABEL_163;
          goto LABEL_86;
        }
        v43 = *v47 == 0;
LABEL_64:
        if ( !v43 )
          goto LABEL_97;
        goto LABEL_47;
      }
      v39 = v38 == 0;
      goto LABEL_46;
    }
    if ( v141 != 2 )
    {
      if ( v141 != 3 )
        goto LABEL_56;
      v117 = v167[4];
      if ( v117 )
      {
        if ( v117 <= 2 )
        {
          if ( v167[5] >= 2u )
            goto LABEL_309;
        }
        else
        {
          switch ( v117 )
          {
            case 3u:
              v119 = (unsigned __int8 *)v167[6];
              v120 = v167[5];
              if ( v120 )
              {
                while ( !*v119++ )
                {
                  if ( !--v120 )
                    goto LABEL_86;
                }
LABEL_306:
                v36 = (int *)v166;
                goto LABEL_56;
              }
              goto LABEL_86;
            case 4u:
              v117 = *(_DWORD *)v167[6];
              break;
            case 7u:
              if ( v167[5] <= 4u )
                goto LABEL_304;
LABEL_309:
              v118 = 1;
LABEL_305:
              if ( v118 )
                goto LABEL_306;
LABEL_86:
              v36 = v19;
              goto LABEL_56;
          }
          if ( v117 )
            goto LABEL_309;
        }
      }
LABEL_304:
      v118 = 0;
      goto LABEL_305;
    }
    v52 = *(_DWORD *)(v166 + 16);
    if ( !v52 )
      goto LABEL_163;
    if ( v52 > 2 )
    {
      if ( v52 != 3 )
      {
        if ( v52 == 4 )
        {
          if ( v19[4] == 4 )
          {
            v92 = **(_DWORD **)(v166 + 24);
            v93 = *(_DWORD *)v19[6];
            switch ( *v20 )
            {
              case 1:
                v34 = v93 + v92;
                goto LABEL_56;
              case 2:
                v34 = v92 - v93;
                goto LABEL_56;
              case 3:
                v34 = v93 * v92;
                goto LABEL_56;
              case 4:
                if ( !v93 )
                  goto LABEL_214;
                v51 = v92 / v93;
                goto LABEL_100;
              case 5:
                if ( v93 )
                  v34 = v92 % v93;
                else
LABEL_214:
                  v6 = -1073741676;
                goto LABEL_56;
              case 6:
                v34 = v92 << v93;
                goto LABEL_56;
              case 7:
                v34 = v92 >> v93;
                goto LABEL_56;
              case 8:
                v34 = v93 & v92;
                goto LABEL_56;
              case 9:
                v34 = v93 | v92;
                goto LABEL_56;
              case 10:
                v34 = v93 ^ v92;
                goto LABEL_56;
              case 13:
                if ( !v92 )
                  goto LABEL_97;
                v39 = v93 == 0;
                goto LABEL_46;
              case 14:
                if ( !v92 && !v93 )
                  goto LABEL_97;
                goto LABEL_47;
              case 15:
                v43 = v92 == v93;
                goto LABEL_64;
              case 16:
                v39 = v92 == v93;
                goto LABEL_46;
              case 17:
                if ( v92 < v93 )
                  goto LABEL_47;
                goto LABEL_97;
              case 18:
                if ( v92 > v93 )
                  goto LABEL_47;
                goto LABEL_97;
              case 19:
                if ( v92 <= v93 )
                  goto LABEL_47;
                goto LABEL_97;
              case 20:
                if ( v92 >= v93 )
                  goto LABEL_47;
                goto LABEL_97;
              default:
                break;
            }
          }
LABEL_163:
          v36 = dword_8C6BC0;
          goto LABEL_56;
        }
        if ( v52 != 7 )
          goto LABEL_163;
        v53 = v19[4];
        if ( v53 == 7 )
        {
          v54 = *(unsigned __int16 **)(v166 + 24);
          v55 = *(_DWORD *)(v166 + 20);
          v57 = (unsigned __int16 *)v19[6];
          v56 = v19[5];
          if ( v55 > 0xFFFE || v56 > 0xFFFE )
            goto LABEL_331;
          switch ( *v20 )
          {
            case 1:
            case 9:
              if ( !*v54 )
                goto LABEL_112;
              if ( !*v57 )
                goto LABEL_115;
              if ( v56 + v55 - 2 > 0xFFFE )
                goto LABEL_331;
              v137 = (unsigned __int16)(v56 + v55 - 2);
              v138 = v137;
              v58 = ExAllocatePoolWithTag(1, v137, 1667526736);
              v35 = (unsigned __int16 *)v58;
              if ( !v58 )
                goto LABEL_329;
              memmove(v58, (int)v54, v55 - 2);
              v59 = &v35[(v55 >> 1) - 1];
              v60 = v56;
              goto LABEL_119;
            case 8:
              if ( !*v54 )
                goto LABEL_141;
              break;
            case 13:
              if ( v55 <= 2 )
                goto LABEL_141;
              goto LABEL_140;
            case 14:
              if ( v55 > 2 )
                goto LABEL_282;
LABEL_140:
              if ( v56 <= 2 )
                goto LABEL_141;
              goto LABEL_282;
            case 15:
              v67 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_143;
            case 16:
              v68 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_145;
            case 17:
              v69 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_147;
            case 18:
              v70 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_150;
            case 19:
              v71 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_153;
            case 20:
              v72 = RtlCompareUnicodeStrings(v54, v55 >> 1, (int)v57, v56 >> 1, 1);
              goto LABEL_156;
            default:
              goto LABEL_158;
          }
          while ( 2 )
          {
            v62 = 2 * (wcslen(v54) + 1);
            RtlInitUnicodeString((unsigned int)v159, v54);
            v63 = *v57;
            for ( i = v57; ; v63 = *i )
            {
              if ( !v63 )
              {
                LOWORD(v65) = v138;
                goto LABEL_128;
              }
              RtlInitUnicodeString((unsigned int)v154, i);
              if ( RtlEqualUnicodeString(v159, v154, 1) )
                break;
              i += (v154[0] >> 1) + 1;
            }
            v66 = v140;
            if ( v140 )
            {
              v65 = v138;
            }
            else
            {
              v65 = 0;
              v138 = 0;
              v66 = (unsigned int *)ExAllocatePoolWithTag(1, v55, 1667526736);
              v140 = v66;
              if ( !v66 )
              {
                v6 = -1073741670;
                break;
              }
            }
            memmove((int)v66 + v65, (int)v54, v62);
            v65 = (unsigned __int16)(v65 + v62);
            v138 = v65;
LABEL_128:
            v54 += v62 >> 1;
            if ( *v54 )
              continue;
            break;
          }
          v35 = (unsigned __int16 *)v140;
          if ( v140 )
          {
            v33 = (unsigned __int16)(v65 + 2);
            v32 = v33;
            v36 = 0;
            *((_WORD *)v140 + (v33 >> 1) - 1) = 0;
            v137 = v33;
            goto LABEL_56;
          }
LABEL_141:
          v34 = 0;
LABEL_121:
          v36 = 0;
LABEL_113:
          v33 = v138;
          goto LABEL_55;
        }
        if ( v53 != 1 && v53 != 2 )
        {
          if ( v53 != 4 )
            goto LABEL_163;
          v73 = *(_DWORD *)v19[6];
          if ( *v20 != 23 )
            goto LABEL_163;
          v74 = 0;
          v75 = *(unsigned __int16 **)(v166 + 24);
          v76 = 0;
          while ( *v75 )
          {
            v74 = 2 * (wcslen(v75) + 1);
            if ( v76 == v73 )
              goto LABEL_169;
            v75 += v74 >> 1;
            ++v76;
          }
          if ( v76 != v73 )
            goto LABEL_158;
LABEL_169:
          if ( !*v75 || v74 <= 2 )
          {
LABEL_158:
            v33 = 0;
            v36 = dword_8C6BC0;
            goto LABEL_55;
          }
          v137 = (unsigned __int16)v74;
          v138 = (unsigned __int16)(v74 - 8);
          v59 = (unsigned __int16 *)ExAllocatePoolWithTag(1, (unsigned __int16)v74, 1667526736);
          v35 = v59;
          if ( !v59 )
            goto LABEL_329;
          v60 = v74;
          v61 = (int)v75;
LABEL_120:
          memmove((int)v59, v61, v60);
          goto LABEL_121;
        }
        v77 = *(unsigned __int16 **)(v166 + 24);
        v78 = *(_DWORD *)(v166 + 20);
        v79 = (unsigned __int16 *)v19[6];
        v80 = v19[5];
        if ( v78 > 0xFFFE || v80 > 0xFFFE )
          goto LABEL_331;
        v81 = *v20;
        if ( *v20 == 1 )
          goto LABEL_184;
        if ( v81 == 2 )
        {
          RtlInitUnicodeString((unsigned int)v160, v79);
          v87 = *v77;
          for ( j = v77; ; v87 = *j )
          {
            if ( !v87 )
              goto LABEL_188;
            RtlInitUnicodeString((unsigned int)v153, j);
            if ( RtlEqualUnicodeString(v160, v153, 1) )
              break;
            j += (v153[0] >> 1) + 1;
          }
          if ( !j )
          {
LABEL_188:
            v36 = (int *)v166;
            goto LABEL_189;
          }
          v137 = (unsigned __int16)(v78 - v80);
          v138 = v137;
          v89 = (unsigned int *)ExAllocatePoolWithTag(1, v137, 1667526736);
          v140 = v89;
          if ( !v89 )
            goto LABEL_329;
          v90 = j - v77;
          if ( v90 > 0 )
            memmove((int)v89, (int)v77, j - v77);
          v91 = v78 - v90;
          v35 = (unsigned __int16 *)v140;
          v60 = v91 - v80;
          v61 = (int)j + v80;
          v59 = (unsigned __int16 *)((char *)v140 + v90);
          goto LABEL_120;
        }
        if ( v81 != 8 )
        {
          if ( v81 != 9 )
          {
LABEL_179:
            v35 = (unsigned __int16 *)v140;
            v36 = dword_8C6BC0;
            goto LABEL_55;
          }
          RtlInitUnicodeString((unsigned int)v164, v79);
          v82 = *v77;
          v83 = v77;
          while ( v82 )
          {
            RtlInitUnicodeString((unsigned int)v155, v83);
            if ( RtlEqualUnicodeString(v164, v155, 1) )
              goto LABEL_188;
            v83 += (v155[0] >> 1) + 1;
            v82 = *v83;
          }
LABEL_184:
          v84 = v80 + v78;
          if ( v80 + v78 > 0xFFFE )
            goto LABEL_331;
          v33 = v84;
          v137 = v84;
          v85 = (unsigned int *)ExAllocatePoolWithTag(1, v84, 1667526736);
          v140 = v85;
          if ( !v85 )
            goto LABEL_329;
          memmove((int)v85, (int)v77, v78 - 2);
          v86 = v78 >> 1;
          v35 = (unsigned __int16 *)v140;
          memmove((int)v140 + 2 * v86 - 2, (int)v79, v80);
          v35[(v33 >> 1) - 1] = 0;
LABEL_187:
          v36 = 0;
          goto LABEL_55;
        }
        RtlInitUnicodeString((unsigned int)v162, v79);
        while ( *v77 )
        {
          RtlInitUnicodeString((unsigned int)v157, v77);
          if ( RtlEqualUnicodeString(v162, v157, 1) )
          {
            v36 = v165;
            goto LABEL_196;
          }
          v77 += (v157[0] >> 1) + 1;
        }
LABEL_194:
        v36 = 0;
        v34 = 0;
LABEL_196:
        v35 = (unsigned __int16 *)v140;
        goto LABEL_55;
      }
      if ( v19[4] != 3 )
        goto LABEL_163;
      v94 = *v20;
      v95 = *(_DWORD *)(v166 + 24);
      v96 = *(_DWORD *)(v166 + 20);
      v97 = *(_QWORD *)(v19 + 5);
      if ( v94 == 15 )
      {
        if ( v96 != (_DWORD)v97 || memcmp(v95, HIDWORD(v97), *(_DWORD *)(v166 + 20)) )
          goto LABEL_242;
      }
      else
      {
        if ( v94 != 16 )
          goto LABEL_54;
        if ( v96 == (_DWORD)v97 && !memcmp(v95, HIDWORD(v97), *(_DWORD *)(v166 + 20)) )
        {
LABEL_242:
          v34 = 0;
          goto LABEL_55;
        }
      }
      v34 = 1;
      goto LABEL_55;
    }
    v98 = v19[4];
    if ( v98 != 1 && v98 != 2 )
    {
      if ( v98 != 7 )
        goto LABEL_163;
      v100 = *(unsigned __int16 **)(v166 + 24);
      v99 = *(_DWORD *)(v166 + 20);
      v101 = (unsigned __int16 *)v19[6];
      v102 = v19[5];
      if ( v99 > 0xFFFE || v102 > 0xFFFE )
        goto LABEL_331;
      v103 = *v20;
      if ( *v20 != 1 )
      {
        if ( v103 == 8 )
        {
          RtlInitUnicodeString((unsigned int)v163, v100);
          while ( *v101 )
          {
            RtlInitUnicodeString((unsigned int)v158, v101);
            if ( RtlEqualUnicodeString(v163, v158, 1) )
            {
              v36 = (int *)v166;
              goto LABEL_196;
            }
            v101 += (v158[0] >> 1) + 1;
          }
          goto LABEL_194;
        }
        if ( v103 != 9 )
          goto LABEL_179;
        RtlInitUnicodeString((unsigned int)v161, v100);
        v104 = *v101;
        v105 = v101;
        while ( v104 )
        {
          RtlInitUnicodeString((unsigned int)v156, v105);
          if ( RtlEqualUnicodeString(v161, v156, 1) )
          {
            v36 = v165;
LABEL_189:
            v35 = (unsigned __int16 *)v140;
            goto LABEL_113;
          }
          v105 += (v156[0] >> 1) + 1;
          v104 = *v105;
        }
      }
      v106 = v102 + v99;
      if ( v102 + v99 > 0xFFFE )
        goto LABEL_331;
      v33 = v106;
      v137 = v106;
      v107 = (unsigned int *)ExAllocatePoolWithTag(1, v106, 1667526736);
      v140 = v107;
      if ( !v107 )
        goto LABEL_329;
      v108 = (int)v100;
      v35 = (unsigned __int16 *)v107;
      memmove((int)v107, v108, v99);
      memmove((int)&v35[v99 >> 1], (int)v101, v102);
      goto LABEL_187;
    }
    v109 = *(_DWORD *)(v166 + 20);
    if ( v109 > 0xFFFE || (v110 = v19[5], v110 > 0xFFFE) )
    {
LABEL_331:
      v6 = -2147483643;
      goto LABEL_330;
    }
    v147[1] = *(_DWORD *)(v166 + 20);
    v111 = (unsigned __int16)(v109 - 2);
    v112 = *(_WORD **)(v166 + 24);
    v57 = (unsigned __int16 *)v19[6];
    v113 = (unsigned __int16)(v110 - 2);
    v114 = *v20;
    v148 = v112;
    v147[0] = v111;
    v146 = v57;
    v145[1] = v110;
    v145[0] = v110 - 2;
    if ( v114 <= 16 )
    {
      if ( v114 != 16 )
      {
        switch ( v114 )
        {
          case 1:
            if ( !*v112 )
            {
LABEL_112:
              v36 = v19;
              goto LABEL_113;
            }
            if ( !*v57 )
            {
LABEL_115:
              v36 = (int *)v166;
              goto LABEL_113;
            }
            v115 = v111 + v113;
            if ( v111 + v113 >= 0xFFFE )
              goto LABEL_331;
            v137 = (unsigned __int16)(v115 + 2);
            v138 = v115;
            v116 = ExAllocatePoolWithTag(1, v137, 1667526736);
            v35 = (unsigned __int16 *)v116;
            if ( !v116 )
            {
LABEL_329:
              v6 = -1073741670;
LABEL_330:
              v129 = v141;
              v3 = (unsigned int)v139;
              goto LABEL_342;
            }
            memmove(v116, (int)v112, v111);
            v60 = v113 + 2;
            v59 = &v35[v111 >> 1];
LABEL_119:
            v61 = (int)v57;
            goto LABEL_120;
          case 13:
            if ( v111 < 2 || v113 < 2 )
              goto LABEL_141;
            goto LABEL_282;
          case 14:
            if ( v111 < 2 && v113 < 2 )
              goto LABEL_141;
LABEL_282:
            v34 = 1;
            goto LABEL_121;
        }
        if ( v114 != 15 )
          goto LABEL_158;
        v67 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_143:
        v33 = 0;
        v36 = 0;
        v43 = v67 == 0;
LABEL_63:
        v32 = 0;
        goto LABEL_64;
      }
      v68 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_145:
      v33 = 0;
      v36 = 0;
      v32 = 0;
      v39 = v68 == 0;
LABEL_46:
      if ( v39 )
        goto LABEL_97;
      goto LABEL_47;
    }
    switch ( v114 )
    {
      case 17:
        v69 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_147:
        v33 = 0;
        v36 = 0;
        v32 = 0;
        if ( v69 >= 0 )
          goto LABEL_97;
        break;
      case 18:
        v70 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_150:
        v33 = 0;
        v36 = 0;
        v32 = 0;
        if ( v70 <= 0 )
          goto LABEL_97;
        break;
      case 19:
        v71 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_153:
        v33 = 0;
        v36 = 0;
        v32 = 0;
        if ( v71 > 0 )
          goto LABEL_97;
        break;
      case 20:
        v72 = RtlCompareUnicodeString(v147, v145, 1);
LABEL_156:
        v33 = 0;
        v36 = 0;
        v32 = 0;
        if ( v72 < 0 )
          goto LABEL_97;
        break;
      default:
        goto LABEL_158;
    }
LABEL_47:
    v34 = 1;
LABEL_56:
    if ( v6 < 0 )
      goto LABEL_340;
    if ( !v36 )
    {
      v41 = ExAllocatePoolWithTag(1, 28, 1667526736);
      v36 = (int *)v41;
      if ( !v41 )
        goto LABEL_332;
      *(_WORD *)(v41 + 10) = 0;
      *(_WORD *)(v41 + 8) = 0;
      *(_DWORD *)(v41 + 12) = 0;
      if ( v35 )
      {
        if ( v33 == v32 )
          v42 = 7;
        else
          v42 = 1;
      }
      else
      {
        v42 = 4;
        v137 = 4;
        v122 = (int *)ExAllocatePoolWithTag(1, 4, 1667526736);
        v35 = (unsigned __int16 *)v122;
        if ( !v122 )
        {
LABEL_332:
          v6 = -1073741670;
          goto LABEL_340;
        }
        *v122 = v34;
      }
      v36[4] = v42;
      v36[5] = v137;
      v36[6] = (int)v35;
    }
    v123 = v142;
    v16 = v139;
    v139[v142] = v36;
    v124 = v141;
    v4 = v123 + 1;
    v142 = v4;
    if ( v141 )
    {
      v125 = (int *)&v165;
      do
      {
        v127 = *v125++;
        v126 = v127;
        if ( !*(_DWORD *)(v127 + 12) )
        {
          v128 = *(_DWORD *)(v126 + 24);
          if ( v128 )
            ExFreePoolWithTag(v128);
          ExFreePoolWithTag(v126);
        }
        --v124;
      }
      while ( v124 );
      v16 = v139;
    }
    v5 = 0;
    v24 = v143;
    v141 = 0;
LABEL_31:
    v26 = wcslen(v24);
    v18 = &v143[v26 + 1];
    v27 = *v18;
    v143 = v18;
    if ( !v27 )
      goto LABEL_336;
  }
LABEL_28:
  if ( v4 >= v152 )
  {
    v6 = -1073741571;
    goto LABEL_336;
  }
  v24 = v143;
  v140 = 0;
  v25 = PiDevCfgResolveVariable(v151, v143, &v140);
  v6 = v25;
  if ( v25 >= 0 )
  {
    v16[v4++] = v140;
    v142 = v4;
    goto LABEL_31;
  }
  if ( v25 == -1073741772 )
    v6 = -1073741823;
LABEL_336:
  if ( v6 >= 0 )
  {
    if ( v4 != 1 )
    {
      v6 = -1073741823;
      v3 = (unsigned int)v139;
      goto LABEL_349;
    }
    v6 = PiDevCfgCopyVariableData(v150, *v16);
  }
LABEL_340:
  v3 = (unsigned int)v139;
LABEL_341:
  v129 = v141;
  if ( v141 )
  {
LABEL_342:
    v130 = (int *)&v165;
    do
    {
      v132 = *v130++;
      v131 = v132;
      if ( !*(_DWORD *)(v132 + 12) )
      {
        v133 = *(_DWORD *)(v131 + 24);
        if ( v133 )
          ExFreePoolWithTag(v133);
        ExFreePoolWithTag(v131);
      }
      --v129;
    }
    while ( v129 );
  }
  v4 = v142;
LABEL_349:
  if ( v3 )
  {
    if ( v4 )
    {
      v134 = (unsigned int *)v3;
      do
      {
        if ( !*(_DWORD *)(*v134 + 12) )
        {
          v135 = *(_DWORD *)(*v134 + 24);
          if ( v135 )
            ExFreePoolWithTag(v135);
          ExFreePoolWithTag(*v134);
        }
        ++v134;
        --v4;
      }
      while ( v4 );
    }
    ExFreePoolWithTag(v3);
  }
  v7 = v144;
LABEL_359:
  if ( v7 )
    ExFreePoolWithTag(v7);
  return v6;
}
