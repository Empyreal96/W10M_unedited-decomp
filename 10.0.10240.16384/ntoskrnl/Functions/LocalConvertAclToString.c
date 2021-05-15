// LocalConvertAclToString 
 
int __fastcall LocalConvertAclToString(int a1, int a2, int a3, unsigned int *a4, unsigned int *a5, int a6, int a7, int a8, unsigned __int8 a9)
{
  unsigned int *v9; // r6
  unsigned int v11; // r4
  char *v12; // r9
  unsigned int v13; // r5
  int v14; // r0
  int v15; // r3
  unsigned __int16 **v16; // r8
  int v17; // r7
  unsigned int v18; // r0
  unsigned __int8 *v19; // r7
  unsigned __int16 **v20; // r0
  int *v21; // r6
  unsigned int v22; // r4
  int v23; // r5
  int v24; // t1
  unsigned __int16 **v25; // r0
  int v26; // r3
  _WORD *v27; // r7
  unsigned int v28; // r8
  unsigned int v29; // r6
  int v30; // r10
  unsigned int *v31; // r7
  unsigned int v32; // r8
  unsigned int *v33; // r4
  int v34; // r3
  int v35; // r1
  int v36; // r2
  int v37; // r0
  int v38; // r3
  int v39; // r6
  unsigned __int8 *v40; // r3
  unsigned __int8 *v41; // r3
  unsigned int v42; // r6
  int v43; // r9
  int v44; // r4
  unsigned __int16 **v45; // r0
  int v46; // r2
  int v47; // r4
  unsigned __int16 **v48; // r0
  unsigned int v49; // r0
  unsigned int v50; // r3
  int v51; // r6
  int v52; // r0
  unsigned int v53; // r6
  char *v54; // r0
  signed int v55; // r0
  int v56; // r1
  unsigned __int16 *v57; // t1
  unsigned int v58; // r3
  int v59; // r3
  unsigned int v60; // r6
  char *v61; // r7
  int v62; // r6
  char **v63; // r0
  char **v64; // r4
  char *v65; // r3
  int *v66; // r8
  unsigned __int8 *v67; // r4
  char *v68; // r7
  int v69; // r6
  int v70; // r5
  int v71; // t1
  char **v72; // r0
  char **v73; // r4
  char *v74; // r3
  int v75; // r10
  char *v76; // r7
  int v77; // r3
  int v78; // r6
  int v79; // r5
  int v80; // r3
  unsigned __int16 *v81; // r7
  unsigned int v82; // r0
  __int64 v83; // kr00_8
  int v84; // r0
  int v85; // r2
  int v86; // r3
  int v87; // r3
  char **v88; // r0
  char **v89; // r4
  char *v90; // r3
  int v91; // r2
  unsigned int i; // r4
  char **v93; // r0
  char **v94; // r8
  char *v95; // r3
  int v96; // r6
  char *v97; // r7
  char *v98; // r8
  unsigned int v99; // r4
  int v100; // r3
  int v101; // r6
  char *v102; // r7
  char *v103; // r8
  unsigned int v104; // r4
  char **v105; // r8
  char *v106; // r7
  int v107; // r6
  char *v108; // r4
  unsigned int v109; // r0
  unsigned int v110; // r6
  char *v111; // r7
  char *v112; // r7
  int v113; // r6
  unsigned int v114; // r0
  int v115; // r2
  int v116; // r2
  unsigned int v117; // r3
  unsigned int v119; // [sp+18h] [bp-60h] BYREF
  unsigned __int16 **v120; // [sp+1Ch] [bp-5Ch]
  char *v121; // [sp+20h] [bp-58h] BYREF
  int v122; // [sp+24h] [bp-54h]
  unsigned __int8 *v123; // [sp+28h] [bp-50h]
  unsigned __int8 *v124; // [sp+2Ch] [bp-4Ch]
  int v125; // [sp+30h] [bp-48h]
  char **v126; // [sp+34h] [bp-44h]
  int v127; // [sp+38h] [bp-40h]
  int v128; // [sp+3Ch] [bp-3Ch]
  int v129; // [sp+40h] [bp-38h]
  int v130; // [sp+44h] [bp-34h] BYREF
  unsigned int v131; // [sp+48h] [bp-30h]
  char *v132; // [sp+4Ch] [bp-2Ch] BYREF
  unsigned int *v133; // [sp+50h] [bp-28h]
  int v134; // [sp+54h] [bp-24h]
  unsigned int v135; // [sp+58h] [bp-20h]

  v9 = a4;
  v11 = 0;
  v121 = 0;
  v122 = 0;
  v124 = 0;
  v126 = 0;
  v127 = a1;
  v12 = 0;
  v133 = a4;
  v119 = 0;
  if ( !a4 || !a5 )
    return 87;
  if ( !a2 )
  {
    *a4 = 0;
    *a5 = 0;
    return 0;
  }
  if ( !a1 )
  {
    *a4 = 0;
    *a5 = 36;
    v14 = SddlpAlloc(36);
    *v9 = v14;
    if ( v14 )
    {
      memmove(v14, (int)L"NO_ACCESS_CONTROL", 0x24u);
      return 0;
    }
    v13 = 8;
LABEL_12:
    *a5 = 0;
    return v13;
  }
  v15 = *(unsigned __int16 *)(a1 + 4);
  if ( !*(_WORD *)(a1 + 4) )
  {
    *v9 = 0;
    v13 = 0;
    goto LABEL_12;
  }
  if ( a3 )
    v125 = 1;
  else
    v125 = 2;
  v16 = (unsigned __int16 **)SddlpAlloc(4 * v15);
  v120 = v16;
  if ( !v16 )
    return 8;
  v17 = SddlpAlloc(*(unsigned __int16 *)(a1 + 4));
  v129 = v17;
  if ( !v17 )
  {
    v18 = (unsigned int)v16;
LABEL_20:
    ExFreePoolWithTag(v18);
    return 8;
  }
  v131 = SddlpAlloc(4 * *(unsigned __int16 *)(a1 + 4));
  if ( !v131 )
  {
    ExFreePoolWithTag((unsigned int)v16);
    v18 = v17;
    goto LABEL_20;
  }
  v123 = 0;
  v19 = (unsigned __int8 *)(a1 + 8);
  if ( !*(_WORD *)(a1 + 4) )
    goto LABEL_38;
  while ( 2 )
  {
    v11 += 2;
    v119 = v11;
    v20 = (unsigned __int16 **)LookupAceTypeInTable();
    if ( !v20 )
    {
LABEL_36:
      v13 = 1336;
      goto LABEL_37;
    }
    v21 = &dword_41D9CC;
    v22 = v11 + 2 * (wcslen(*v20) + 1);
    v23 = 7;
    do
    {
      v24 = *v21++;
      if ( (v19[1] & (unsigned __int8)v24) != 0 )
      {
        v25 = (unsigned __int16 **)LookupAceFlagsInTable();
        if ( v25 )
          v22 += 2 * wcslen(*v25);
      }
      --v23;
    }
    while ( v23 );
    v26 = *v19;
    v11 = v22 + 2;
    v119 = v11;
    if ( v26 > 11 )
    {
      if ( v26 != 13 && (unsigned int)(v26 - 17) > 3 )
        goto LABEL_36;
    }
    else
    {
      if ( v26 == 11 )
        goto LABEL_58;
      if ( v26 > 3 )
      {
        if ( v26 <= 4 )
          goto LABEL_36;
        if ( v26 <= 8 )
        {
LABEL_58:
          v122 = *((_DWORD *)v19 + 1);
          v34 = *((_DWORD *)v19 + 2);
          v35 = v34 & 1;
          if ( (v34 & 1) != 0 )
            v36 = 16;
          else
            v36 = 0;
          v37 = v34 & 2;
          if ( (v34 & 2) != 0 )
            v38 = 16;
          else
            v38 = 0;
          v39 = (int)&v19[v38 + 12 + v36];
          v124 = (unsigned __int8 *)v39;
          v40 = v19 + 12;
          if ( !v35 )
            v40 = 0;
          if ( v40 )
          {
            v11 += 72;
            v119 = v11;
          }
          if ( v37 )
          {
            if ( v35 )
              v41 = v19 + 28;
            else
              v41 = v19 + 12;
          }
          else
          {
            v41 = 0;
          }
          if ( v41 )
            v119 = v11 + 72;
          goto LABEL_75;
        }
      }
    }
    v44 = *((_DWORD *)v19 + 1);
    v39 = (int)(v19 + 8);
    v124 = v19 + 8;
    v122 = v44;
LABEL_75:
    if ( v12 )
    {
      ExFreePoolWithTag((unsigned int)v12);
      v121 = 0;
    }
    v130 = 0;
    v13 = LocalGetAceCondition(v19, v39, &v121, &v130, &v119, a6, a7, 0, a9);
    if ( v13 )
    {
      v11 = v119;
      goto LABEL_101;
    }
    v42 = 0;
    v43 = v131 - (_DWORD)v120;
    *(unsigned __int16 **)((char *)v16 + v131 - (_DWORD)v120) = 0;
    v45 = (unsigned __int16 **)LookupAccessMaskInTable();
    if ( v45 )
    {
      *(unsigned __int16 **)((char *)v16 + v43) = (unsigned __int16 *)1;
      v42 = 2 * wcslen(*v45);
      goto LABEL_91;
    }
    v46 = v122;
    v47 = 0;
    while ( ((1 << v47) & v46) == 0 )
    {
LABEL_88:
      if ( (unsigned int)++v47 >= 0x20 )
        goto LABEL_91;
    }
    v48 = (unsigned __int16 **)LookupAccessMaskInTable();
    if ( v48 )
    {
      v49 = wcslen(*v48);
      v46 = v122;
      v42 += 2 * v49;
      goto LABEL_88;
    }
    *(unsigned __int16 **)((char *)v16 + v43) = (unsigned __int16 *)2;
    v42 = 20;
LABEL_91:
    v50 = v119 + v42;
    v51 = (int)v124;
    v11 = v50 + 6;
    v119 = v50 + 6;
    v52 = LookupSidInTable();
    if ( v52 )
    {
      *v16 = (unsigned __int16 *)(v52 + 2);
      goto LABEL_98;
    }
    if ( !v126 )
    {
      v55 = LocalConvertSidToStringSidW(v51, v16);
      if ( v55 < 0 )
      {
        v13 = RtlNtStatusToDosError(v55, v56);
        goto LABEL_101;
      }
LABEL_96:
      v123[v129] = 1;
LABEL_98:
      v57 = *v16++;
      v11 += 2 * (wcslen(v57) + 2);
      v12 = v121;
      v19 += *((unsigned __int16 *)v19 + 1);
      v119 = v11;
      v58 = *(unsigned __int16 *)(v127 + 4);
      if ( (unsigned int)++v123 >= v58 )
        goto LABEL_37;
      continue;
    }
    break;
  }
  v53 = 2 * (wcslen(L"SA") + 1);
  v54 = (char *)SddlpAlloc(v53);
  *v16 = (unsigned __int16 *)v54;
  if ( v54 )
  {
    wcscpy_s(v54, v53 >> 1, (char *)L"SA");
    goto LABEL_96;
  }
  v13 = 8;
LABEL_101:
  v12 = v121;
LABEL_37:
  v9 = v133;
  if ( !v11 )
LABEL_38:
    v13 = 1336;
  if ( v13 )
  {
LABEL_44:
    v28 = (unsigned int)v120;
    goto LABEL_45;
  }
  if ( (v11 & 1) != 0 )
    v119 = ++v11;
  v27 = (_WORD *)SddlpAlloc(v11);
  *v9 = (unsigned int)v27;
  if ( !v27 )
  {
    v13 = 8;
    goto LABEL_44;
  }
  v135 = 0;
  v59 = *(unsigned __int16 *)(v127 + 4);
  v60 = v11 >> 1;
  v123 = (unsigned __int8 *)(v127 + 8);
  if ( !v59 )
    goto LABEL_44;
  v28 = (unsigned int)v120;
  v126 = (char **)v120;
  while ( 2 )
  {
    if ( v60 )
    {
      *v27 = 40;
      v61 = (char *)(v27 + 1);
      v62 = v60 - 1;
      v63 = (char **)LookupAceTypeInTable();
      v64 = v63;
      if ( v63 )
      {
        wcscpy_s(v61, v62, *v63);
        v65 = v64[1];
        v61 += 2 * (_DWORD)v65;
        v62 -= (int)v65;
      }
      if ( v62 )
      {
        v66 = &dword_41D9CC;
        v67 = v123;
        *(_WORD *)v61 = 59;
        v68 = v61 + 2;
        v69 = v62 - 1;
        v70 = 7;
        do
        {
          v71 = *v66++;
          if ( (v67[1] & (unsigned __int8)v71) != 0 )
          {
            v72 = (char **)LookupAceFlagsInTable();
            v73 = v72;
            if ( v72 )
            {
              wcscpy_s(v68, v69, *v72);
              v74 = v73[1];
              v68 += 2 * (_DWORD)v74;
              v69 -= (int)v74;
            }
            v67 = v123;
          }
          --v70;
        }
        while ( v70 );
        v75 = 0;
        if ( !v69 )
        {
          v11 = v119;
          v13 = 1336;
          goto LABEL_44;
        }
        *(_WORD *)v68 = 59;
        v76 = v68 + 2;
        v77 = *v67;
        v78 = v69 - 1;
        v134 = 0;
        v128 = 0;
        if ( v77 > 11 )
        {
          if ( v77 == 13 || (unsigned int)(v77 - 17) <= 3 )
          {
LABEL_143:
            v87 = *((_DWORD *)v67 + 1);
            v79 = (int)(v67 + 8);
            v124 = v67 + 8;
            v122 = v87;
            goto LABEL_124;
          }
        }
        else
        {
          if ( v77 == 11 )
            goto LABEL_129;
          if ( v77 <= 3 )
            goto LABEL_143;
          if ( v77 > 4 )
          {
            if ( v77 > 8 )
              goto LABEL_143;
LABEL_129:
            v83 = *(_QWORD *)(v67 + 4);
            v84 = *((_DWORD *)v67 + 2) & 1;
            if ( (v83 & 0x100000000i64) != 0 )
              v85 = 16;
            else
              v85 = 0;
            v79 = (int)&v67[HIDWORD(v83) + 12 + v85];
            v124 = (unsigned __int8 *)v79;
            v122 = v83;
            if ( (v83 & 0x200000000i64) != 0 )
            {
              if ( v84 )
                v86 = (int)(v67 + 28);
              else
                v86 = (int)(v67 + 12);
            }
            else
            {
              v86 = 0;
            }
            v128 = v86;
            if ( v84 )
              v75 = (int)(v67 + 12);
            else
              v75 = 0;
            v134 = v75;
LABEL_124:
            if ( v12 )
            {
              ExFreePoolWithTag((unsigned int)v12);
              v121 = 0;
            }
            v130 = 0;
            v13 = LocalGetAceCondition(v67, v79, &v121, &v130, &v119, a6, a7, 0, a9);
            if ( v13 )
              goto LABEL_174;
            v28 = (unsigned int)v120;
            v80 = *(int *)((char *)v126 + v131 - (_DWORD)v120);
            if ( v80 == 2 )
            {
              wcscpy_s(v76, v78, (char *)L"0x");
              v81 = (unsigned __int16 *)(v76 + 4);
              ultow_s();
              v82 = wcslen(v81);
              v76 = (char *)&v81[v82];
              v78 = v78 - 2 - v82;
            }
            else if ( v80 == 1 )
            {
              v88 = (char **)LookupAccessMaskInTable();
              v89 = v88;
              if ( v88 )
              {
                wcscpy_s(v76, v78, *v88);
                v90 = v89[1];
                v76 += 2 * (_DWORD)v90;
                v78 -= (int)v90;
              }
            }
            else
            {
              v91 = v122;
              for ( i = 0; i < 0x20; ++i )
              {
                if ( ((1 << i) & v91) != 0 )
                {
                  v93 = (char **)LookupAccessMaskInTable();
                  v94 = v93;
                  if ( v93 )
                  {
                    wcscpy_s(v76, v78, *v93);
                    v95 = v94[1];
                    v76 += 2 * (_DWORD)v95;
                    v78 -= (int)v95;
                  }
                  v91 = v122;
                }
              }
              v75 = v134;
              v28 = (unsigned int)v120;
            }
            if ( !v78 )
            {
              v11 = v119;
              v12 = v121;
              v13 = 1336;
              goto LABEL_45;
            }
            v96 = v78 - 1;
            *(_WORD *)v76 = 59;
            v97 = v76 + 2;
            if ( v75 )
            {
              if ( !SddlpUuidToString(v75, &v132) )
                goto LABEL_174;
              v98 = v132;
              v99 = wcslen((unsigned __int16 *)v132);
              wcscpy_s(v97, v96, v98);
              v96 -= v99;
              v97 += 2 * v99;
              if ( v98 )
                ExFreePoolWithTag((unsigned int)v98);
            }
            if ( !v96 )
              goto LABEL_173;
            v100 = v128;
            v101 = v96 - 1;
            *(_WORD *)v97 = 59;
            v102 = v97 + 2;
            if ( v100 )
            {
              if ( !SddlpUuidToString(v100, &v132) )
                goto LABEL_174;
              v103 = v132;
              v104 = wcslen((unsigned __int16 *)v132);
              wcscpy_s(v102, v101, v103);
              v101 -= v104;
              v102 += 2 * v104;
              if ( v103 )
                ExFreePoolWithTag((unsigned int)v103);
            }
            if ( !v101 )
            {
LABEL_173:
              v13 = 1336;
LABEL_174:
              v12 = v121;
LABEL_172:
              v11 = v119;
              goto LABEL_44;
            }
            v105 = v126;
            *(_WORD *)v102 = 59;
            v106 = v102 + 2;
            v107 = v101 - 1;
            v108 = *v105;
            v126 = v105 + 1;
            wcscpy_s(v106, v107, v108);
            v109 = wcslen((unsigned __int16 *)v108);
            v12 = v121;
            v110 = v107 - v109;
            v111 = &v106[2 * v109];
            if ( v121 )
            {
              if ( !v110 )
              {
                v13 = 1336;
                goto LABEL_172;
              }
              *(_WORD *)v111 = 59;
              v112 = v111 + 2;
              v113 = v110 - 1;
              wcscpy_s(v112, v113, v12);
              v114 = wcslen((unsigned __int16 *)v12);
              v111 = &v112[2 * v114];
              v110 = v113 - v114;
            }
            v28 = (unsigned int)v120;
            if ( v110 <= 1 )
              break;
            v115 = (int)v123;
            *(_WORD *)v111 = 41;
            *((_WORD *)v111 + 1) = 0;
            v27 = v111 + 2;
            v60 = v110 - 1;
            v116 = v115 + *(unsigned __int16 *)(v115 + 2);
            ++v135;
            v117 = *(unsigned __int16 *)(v127 + 4);
            v123 = (unsigned __int8 *)v116;
            if ( v135 >= v117 )
              goto LABEL_178;
            continue;
          }
        }
        v79 = (int)v124;
        goto LABEL_124;
      }
    }
    break;
  }
  v13 = 1336;
LABEL_178:
  v11 = v119;
LABEL_45:
  v29 = 0;
  if ( *(_WORD *)(v127 + 4) )
  {
    v30 = v127;
    v31 = (unsigned int *)v28;
    v32 = v129;
    do
    {
      if ( *(_BYTE *)(v29 + v32) && *v31 )
        ExFreePoolWithTag(*v31);
      ++v29;
      ++v31;
    }
    while ( v29 < *(unsigned __int16 *)(v30 + 4) );
    v28 = (unsigned int)v120;
  }
  ExFreePoolWithTag(v28);
  ExFreePoolWithTag(v129);
  ExFreePoolWithTag(v131);
  if ( v12 )
    ExFreePoolWithTag((unsigned int)v12);
  if ( v13 )
  {
    v33 = v133;
    if ( *v133 )
      ExFreePoolWithTag(*v133);
    *v33 = 0;
    *a5 = 0;
  }
  else
  {
    *a5 = v11;
  }
  return v13;
}
