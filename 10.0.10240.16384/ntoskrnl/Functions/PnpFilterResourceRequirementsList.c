// PnpFilterResourceRequirementsList 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpFilterResourceRequirementsList(int *a1, _DWORD *a2, unsigned int *a3, _DWORD *a4)
{
  int v5; // r7
  unsigned int *v6; // r8
  _DWORD *v7; // r9
  int v8; // r0
  unsigned int v9; // r10
  int v10; // r5
  unsigned __int8 *v11; // r1
  int v12; // r0
  unsigned int v13; // r2
  int v14; // r4
  int v15; // r3
  int v16; // r4
  int v17; // r0
  unsigned int i; // r1
  unsigned int v19; // r2
  int v20; // r3
  unsigned __int16 *v21; // r6
  int v22; // r5
  int v23; // r0
  int v24; // r1
  int v26; // r3
  unsigned int v27; // r8
  unsigned __int16 *v28; // r5
  int v29; // r4
  int v30; // r7
  int v31; // r2
  bool v32; // zf
  int v33; // r3
  unsigned __int8 *v34; // lr
  unsigned int v35; // r1
  unsigned int v36; // r3
  int v37; // r0
  unsigned int v38; // r2
  unsigned int v39; // r4
  int v40; // r6
  unsigned int v41; // r0
  unsigned int v42; // r3
  unsigned int v43; // r7 OVERLAPPED
  unsigned int v44; // r9
  unsigned int v45; // r8 OVERLAPPED
  unsigned int v46; // r1
  unsigned __int64 v47; // r2
  unsigned int v48; // lr
  unsigned int v49; // r10
  unsigned int v50; // r0
  unsigned int v51; // r2
  unsigned __int16 *v52; // r4
  char v53; // t1
  int v54; // r3
  char v55; // t1
  unsigned int v56; // r3
  bool v57; // cf
  int v58; // r2
  int v59; // r3
  int v60; // r4
  int *v61; // r0
  unsigned int v62; // r3
  unsigned __int16 *v63; // r2
  char *v64; // r9
  unsigned __int16 *v65; // r6
  unsigned int v66; // lr
  int v67; // r3
  char *v68; // r7
  int v69; // r1
  int v70; // r2
  int v71; // r3
  int v72; // r1
  int v73; // r2
  int v74; // r3
  __int64 v75; // r0
  int v76; // r0
  unsigned int v77; // r1
  unsigned __int64 v78; // kr10_8
  unsigned int v79; // r5
  unsigned __int16 *v80; // r1
  int v81; // t1
  unsigned __int16 *v82; // r4
  char v83; // t1
  unsigned __int16 *v84; // r2
  int v85; // t1
  char v86; // t1
  unsigned int v87; // [sp+0h] [bp-B8h]
  int v88; // [sp+4h] [bp-B4h]
  unsigned int v89; // [sp+8h] [bp-B0h]
  unsigned __int8 *v90; // [sp+Ch] [bp-ACh]
  unsigned int v91; // [sp+10h] [bp-A8h] BYREF
  unsigned int v92; // [sp+14h] [bp-A4h]
  unsigned int v93; // [sp+18h] [bp-A0h] BYREF
  unsigned int v94; // [sp+1Ch] [bp-9Ch]
  __int64 v95; // [sp+20h] [bp-98h] BYREF
  int v96; // [sp+28h] [bp-90h]
  unsigned __int16 *v97; // [sp+2Ch] [bp-8Ch]
  unsigned int v98; // [sp+30h] [bp-88h]
  unsigned int v99; // [sp+34h] [bp-84h]
  unsigned int v100; // [sp+38h] [bp-80h]
  int v101; // [sp+3Ch] [bp-7Ch]
  unsigned int v102; // [sp+40h] [bp-78h]
  unsigned __int16 *v103; // [sp+44h] [bp-74h]
  int v104; // [sp+48h] [bp-70h]
  _DWORD *v105; // [sp+4Ch] [bp-6Ch]
  unsigned int *v106; // [sp+50h] [bp-68h]
  _DWORD *v107; // [sp+54h] [bp-64h]
  int v108; // [sp+58h] [bp-60h]
  int v109; // [sp+5Ch] [bp-5Ch]
  unsigned int v110; // [sp+60h] [bp-58h]
  int v111; // [sp+64h] [bp-54h]
  int v112; // [sp+68h] [bp-50h]
  unsigned __int16 *v113; // [sp+6Ch] [bp-4Ch]
  unsigned int v114; // [sp+70h] [bp-48h]
  int v115; // [sp+74h] [bp-44h]
  int v116; // [sp+78h] [bp-40h]
  int v117; // [sp+7Ch] [bp-3Ch]
  int v118; // [sp+80h] [bp-38h] BYREF
  int v119; // [sp+84h] [bp-34h]
  unsigned int v120; // [sp+88h] [bp-30h]
  int v121; // [sp+8Ch] [bp-2Ch]
  _DWORD *v122; // [sp+90h] [bp-28h]
  unsigned __int16 *v123; // [sp+94h] [bp-24h]
  int v124; // [sp+98h] [bp-20h]

  v5 = 0;
  v113 = 0;
  v88 = 0;
  v106 = a3;
  v107 = a4;
  v6 = a3;
  v7 = a2;
  v122 = a2;
  *a3 = 0;
  *a4 = 0;
  if ( a1 && a1[7] )
  {
    v8 = ExAllocatePoolWithTag(1, *a1, 1970499664);
    v9 = v8;
    v108 = v8;
    if ( !v8 )
      return -1073741670;
    memmove(v8, (int)a1, *a1);
    if ( !v7 )
      goto LABEL_108;
    v10 = *v7;
    if ( !*v7 )
      goto LABEL_108;
    v11 = (unsigned __int8 *)(v7 + 1);
    while ( 1 )
    {
      v12 = *((_DWORD *)v11 + 3);
      v11 += 16;
      v5 += v12;
      if ( !v12 )
        goto LABEL_13;
      do
      {
        v13 = *v11;
        v14 = 0;
        if ( v13 >= 5 )
        {
          if ( v13 == 5 )
          {
            v14 = *((_DWORD *)v11 + 1);
LABEL_104:
            --v5;
            goto LABEL_11;
          }
          if ( v13 - 128 <= 1 )
            goto LABEL_104;
        }
        if ( v13 >= 8 || !*v11 )
          goto LABEL_104;
LABEL_11:
        v11 += v14 + 16;
        --v12;
      }
      while ( v12 );
      v96 = v5;
LABEL_13:
      if ( !--v10 )
      {
        v96 = v5;
        if ( v5 )
        {
          v15 = *(_DWORD *)(v9 + 28);
          v16 = 0;
          v116 = 0;
          v17 = v15 - 1;
          for ( i = v9 + 32; v17 >= 0; --v17 )
          {
            v19 = i + 8;
            i += 8 + 32 * *(_DWORD *)(i + 4);
            if ( v19 < i )
            {
              do
              {
                if ( !*(_BYTE *)(v19 + 1) )
                  ++v16;
                *(_BYTE *)(v19 + 3) = 0;
                v19 += 32;
              }
              while ( v19 < i );
              v116 = v16;
            }
          }
          v20 = *(_DWORD *)(v9 + 28);
          v21 = (unsigned __int16 *)(v9 + 32);
          v97 = (unsigned __int16 *)(v9 + 32);
          v22 = v20 - 1;
          v23 = v20 - 1;
          v111 = v20 - 1;
          v104 = v20 - 1;
          if ( v20 - 1 >= 0 )
          {
            while ( 2 )
            {
              v24 = *v21;
              v109 = v24;
              if ( v24 == 0xFFFF )
                return sub_80E14C();
              *v21 = 0;
              v26 = *((_DWORD *)v21 + 1);
              v27 = (unsigned int)(v21 + 4);
              v123 = v21 + 4;
              v124 = v26;
              v28 = &v21[16 * v26 + 4];
              v103 = v28;
              if ( v21 + 4 == v28 )
              {
                *v21 = -1;
                --*(_DWORD *)(v9 + 28);
              }
              else
              {
                v29 = 1;
                v30 = (int)(v7 + 1);
                v31 = 0;
                v32 = *v7 == 0;
                v101 = 1;
                v105 = v7 + 1;
                v112 = 0;
                if ( !v32 )
                {
                  do
                  {
                    v33 = *(_DWORD *)(v30 + 12);
                    v34 = (unsigned __int8 *)(v30 + 16);
                    v35 = 0;
                    v90 = (unsigned __int8 *)(v30 + 16);
                    v114 = 0;
                    if ( v33 )
                    {
                      do
                      {
                        v36 = *v34;
                        v37 = 0;
                        v121 = 0;
                        if ( v36 == 5 )
                        {
                          v37 = *((_DWORD *)v34 + 1);
                        }
                        else if ( v36 < 8 && v36 )
                        {
                          v38 = 0;
                          v89 = 0;
                          while ( 1 )
                          {
                            v39 = v27;
                            if ( v27 >= (unsigned int)v28 )
                              goto LABEL_67;
                            v40 = *v34;
                            while ( 1 )
                            {
                              if ( *(unsigned __int8 *)(v39 + 1) != v40 || *(_BYTE *)(v39 + 3) )
                                goto LABEL_36;
                              v100 = 1;
                              v99 = 0;
                              v87 = 1;
                              v41 = *(unsigned __int8 *)(v39 + 2);
                              v98 = 0;
                              v42 = v34[1];
                              v110 = v41;
                              v102 = v42;
                              if ( !v42 || v42 > 3 )
                              {
                                v42 = v41;
                                v102 = v41;
                              }
                              if ( !v41 || v41 > 3 )
                                v110 = v42;
                              v115 = 1;
                              v118 = 1;
                              v117 = 0;
                              v119 = 0;
                              if ( v40 == 2 )
                              {
                                v43 = *((_DWORD *)v34 + 2);
                                v44 = 0;
                                v95 = v43;
                                v45 = v43;
                                v46 = 0;
LABEL_44:
                                v47 = *(_QWORD *)(v39 + 8);
LABEL_45:
                                v48 = 0;
                                v49 = 0;
                                v91 = HIDWORD(v47);
                                v92 = 0;
                                v93 = v47;
                                v94 = 0;
                              }
                              else
                              {
                                switch ( v40 )
                                {
                                  case 1:
                                  case 3:
                                  case 7:
                                    LODWORD(v75) = RtlCmDecodeMemIoResource((int)v34, &v95);
                                    v44 = HIDWORD(v95);
                                    v43 = v95;
                                    v99 = HIDWORD(v75);
                                    v100 = v75;
                                    v120 = (unsigned __int64)(v95 + v75 - 1) >> 32;
                                    v45 = v95 + v75 - 1;
                                    v76 = RtlIoDecodeMemIoResource(v39, &v118, &v93, &v91);
                                    v48 = v92;
                                    v47 = __PAIR64__(v91, v93);
                                    v49 = v94;
                                    v117 = v119;
                                    v98 = v77;
                                    v46 = v120;
                                    v115 = v118;
                                    v87 = v76;
                                    break;
                                  case 4:
                                    v45 = *((_DWORD *)v34 + 1);
                                    v46 = 0;
                                    v44 = 0;
                                    v43 = v45;
                                    v95 = v45;
                                    goto LABEL_44;
                                  case 6:
                                    v43 = *((_DWORD *)v34 + 1);
                                    LODWORD(v47) = *(_DWORD *)(v39 + 12);
                                    v79 = *(_DWORD *)(v39 + 8);
                                    v46 = 0;
                                    v100 = *((_DWORD *)v34 + 2);
                                    v45 = v100 + v43 - 1;
                                    v87 = v79;
                                    v44 = 0;
                                    v98 = 0;
                                    v99 = 0;
                                    HIDWORD(v47) = *(_DWORD *)(v39 + 16);
                                    v95 = v43;
                                    goto LABEL_45;
                                  default:
                                    v43 = 0;
                                    v47 = 0i64;
                                    v95 = 0i64;
                                    v44 = 0;
                                    v45 = 0;
                                    v46 = 0;
                                    goto LABEL_45;
                                }
                              }
                              if ( v89 )
                              {
                                v101 = 0;
                                v28 = v103;
                                if ( v102 == v110
                                  && v49 <= v44
                                  && (v49 < v44 || (unsigned int)v47 <= v43)
                                  && v48 >= v46
                                  && (v48 > v46 || HIDWORD(v47) >= v45)
                                  && v98 >= v99
                                  && (v98 > v99 || v87 >= v100)
                                  && !(((v115 != 0) + v117 - 1) & v44 | (v115 - 1) & v43) )
                                {
                                  switch ( v40 )
                                  {
                                    case 1:
                                    case 3:
                                    case 7:
                                      *(_QWORD *)(v39 + 24) = __PAIR64__(v44, v43) + __PAIR64__(v98, v87) - 1;
                                      *(_DWORD *)(v39 + 16) = v43;
                                      *(_DWORD *)(v39 + 20) = v44;
                                      break;
                                    case 2:
                                    case 4:
                                      *(_QWORD *)(v39 + 8) = *(_QWORD *)&v43;
                                      break;
                                    case 6:
                                      *(_DWORD *)(v39 + 12) = v43;
                                      *(_DWORD *)(v39 + 16) = v87 + v43 - 1;
                                      break;
                                    default:
                                      break;
                                  }
                                  v21 = v97;
                                  v34 = v90;
                                  v27 = (unsigned int)(v97 + 4);
                                  ++*v97;
                                  *(_BYTE *)(v39 + 3) = 0x80;
                                  *(_WORD *)(v39 + 4) = *((_WORD *)v90 + 1);
                                  v83 = *(_BYTE *)v39;
                                  v82 = (unsigned __int16 *)(v39 + 32);
                                  if ( (v83 & 8) != 0 )
                                  {
                                    v84 = v82 - 32;
                                    if ( (unsigned int)(v82 - 32) >= v27 )
                                    {
                                      do
                                      {
                                        *((_BYTE *)v84 + 1) = 0;
                                        --*((_DWORD *)v21 + 1);
                                        v85 = *(unsigned __int8 *)v84;
                                        v84 -= 16;
                                      }
                                      while ( v85 == 8 && (unsigned int)v84 >= v27 );
                                    }
                                  }
                                  for ( *((_BYTE *)v82 - 32) = 1; v82 < v28; --*((_DWORD *)v21 + 1) )
                                  {
                                    v86 = *(_BYTE *)v82;
                                    v82 += 16;
                                    if ( (v86 & 8) == 0 )
                                      break;
                                    *((_BYTE *)v82 - 31) = 0;
                                  }
                                  goto LABEL_147;
                                }
                                goto LABEL_130;
                              }
                              v28 = v103;
                              if ( v102 == v110
                                && (_DWORD)v47 == v43
                                && v49 == v44
                                && v48 >= v46
                                && (v48 > v46 || HIDWORD(v47) >= v45) )
                              {
                                break;
                              }
LABEL_130:
                              v34 = v90;
LABEL_36:
                              v39 += 32;
                              if ( v39 >= (unsigned int)v28 )
                              {
                                v21 = v97;
                                v27 = (unsigned int)v123;
LABEL_147:
                                v38 = v89;
                                goto LABEL_67;
                              }
                            }
                            v50 = v98;
                            if ( v98 <= v99 )
                              break;
                            v51 = v87;
LABEL_56:
                            if ( HIDWORD(v47) != v45 || v48 != v46 )
                              v101 = 0;
                            v21 = v97;
                            v27 = (unsigned int)(v97 + 4);
                            ++*v97;
                            *(_BYTE *)(v39 + 3) = 0x80;
                            v53 = *(_BYTE *)v39;
                            v52 = (unsigned __int16 *)(v39 + 32);
                            if ( (v53 & 8) != 0 )
                            {
                              v80 = v52 - 32;
                              if ( (unsigned int)(v52 - 32) >= v27 )
                              {
                                do
                                {
                                  *((_BYTE *)v80 + 1) = 0;
                                  --*((_DWORD *)v21 + 1);
                                  v81 = *(unsigned __int8 *)v80;
                                  v80 -= 16;
                                }
                                while ( v81 == 8 && (unsigned int)v80 >= v27 );
                              }
                            }
                            v34 = v90;
                            *((_BYTE *)v52 - 32) = 1;
                            *(v52 - 14) = *((_WORD *)v90 + 1);
                            v54 = *((unsigned __int8 *)v52 - 31);
                            if ( v54 == 3 || v54 == 1 || v54 == 7 )
                            {
                              v78 = __PAIR64__(v44, v43) + __PAIR64__(v50, v51) - 1;
                              *((_DWORD *)v52 - 3) = v44;
                              *((_DWORD *)v52 - 2) = v78;
                              *((_DWORD *)v52 - 5) = 1;
                              *((_DWORD *)v52 - 4) = v43;
                              *((_DWORD *)v52 - 1) = HIDWORD(v78);
                            }
                            else if ( v54 == 6 )
                            {
                              *((_DWORD *)v52 - 5) = v43;
                              *((_DWORD *)v52 - 4) = v51 + v43 - 1;
                            }
                            for ( ; v52 < v28; --*((_DWORD *)v21 + 1) )
                            {
                              v55 = *(_BYTE *)v52;
                              v52 += 16;
                              if ( (v55 & 8) == 0 )
                                break;
                              *((_BYTE *)v52 - 31) = 0;
                            }
                            v38 = 1;
LABEL_67:
                            v89 = ++v38;
                            if ( v38 >= 2 )
                            {
                              v35 = v114;
                              v37 = v121;
                              v30 = (int)v105;
                              goto LABEL_69;
                            }
                          }
                          if ( v98 >= v99 )
                          {
                            v51 = v87;
                            if ( v87 >= v100 )
                              goto LABEL_56;
                          }
                          goto LABEL_130;
                        }
LABEL_69:
                        v34 += v37 + 16;
                        v56 = *(_DWORD *)(v30 + 12);
                        ++v35;
                        v90 = v34;
                        v114 = v35;
                      }
                      while ( v35 < v56 );
                      v7 = v122;
                      v31 = v112;
                    }
                    v30 = (int)v34;
                    v57 = (unsigned int)++v31 >= *v7;
                    v105 = v34;
                    v112 = v31;
                  }
                  while ( !v57 );
                  v9 = v108;
                  LOWORD(v24) = v109;
                  v23 = v111;
                  v29 = v101;
                }
                if ( *v21 == (unsigned __int16)v96 )
                {
                  v58 = *((_DWORD *)v21 + 1);
                  if ( v58 == v96 || v58 == v96 + 1 && *((unsigned __int8 *)v21 + 9) == 128 )
                  {
                    if ( v113 )
                    {
                      *v21 = -1;
                      --*(_DWORD *)(v9 + 28);
                    }
                    else
                    {
                      v113 = v21;
                      *v21 = v24;
                      v88 += v58;
                      if ( v29 )
                        *v107 = 1;
                    }
                  }
                  else
                  {
                    *v21 = v24;
                    v88 += v58;
                  }
                }
                else
                {
                  *v21 = -1;
                  --*(_DWORD *)(v9 + 28);
                }
                *((_DWORD *)v21 + 1) = v124;
                v21 = v28;
                v97 = v28;
              }
              v111 = --v23;
              if ( v23 >= 0 )
                continue;
              break;
            }
            v22 = v104;
            v16 = v116;
            v6 = v106;
          }
          v59 = *(_DWORD *)(v9 + 28);
          if ( !v59 )
          {
            *v6 = PnpCmResourcesToIoResources(v23, v7, 1);
            ExFreePoolWithTag(v9);
            return 0;
          }
          v60 = 40 * (v59 - 1) + 32 * (v88 - v16) + 72;
          v61 = (int *)ExAllocatePoolWithTag(1, v60, 1970499664);
          if ( v61 )
          {
            *v61 = v60;
            v61[1] = v7[1];
            v61[2] = v7[2];
            v61[3] = *(_DWORD *)(v9 + 12);
            v62 = *(_DWORD *)(v9 + 28);
            if ( v62 > 1 )
              *v107 = 0;
            v61[7] = v62;
            v63 = (unsigned __int16 *)(v9 + 32);
            v64 = (char *)(v61 + 8);
            if ( v22 >= 0 )
            {
              do
              {
                v65 = v63 + 4;
                v66 = (unsigned int)&v63[16 * *((_DWORD *)v63 + 1) + 4];
                v67 = *v63;
                if ( v67 != 0xFFFF )
                {
                  *(_WORD *)v64 = v67;
                  v68 = v64 + 8;
                  *((_WORD *)v64 + 1) = v63[1];
                  if ( *((unsigned __int8 *)v63 + 9) == 128 )
                  {
                    *v61 -= 32;
                  }
                  else
                  {
                    *v68 = 1;
                    v64[9] = 0x80;
                    *((_DWORD *)v64 + 4) = 1;
                    v64[10] = 3;
                    *((_WORD *)v64 + 6) = 0;
                    v64[11] = 0;
                    *((_WORD *)v64 + 7) = 0;
                    v68 = v64 + 40;
                  }
                  if ( (unsigned int)v65 < v66 )
                  {
                    do
                    {
                      if ( *((_BYTE *)v65 + 1) )
                      {
                        v69 = *((_DWORD *)v65 + 1);
                        v70 = *((_DWORD *)v65 + 2);
                        v71 = *((_DWORD *)v65 + 3);
                        *(_DWORD *)v68 = *(_DWORD *)v65;
                        *((_DWORD *)v68 + 1) = v69;
                        *((_DWORD *)v68 + 2) = v70;
                        *((_DWORD *)v68 + 3) = v71;
                        v72 = *((_DWORD *)v65 + 5);
                        v73 = *((_DWORD *)v65 + 6);
                        v74 = *((_DWORD *)v65 + 7);
                        *((_DWORD *)v68 + 4) = *((_DWORD *)v65 + 4);
                        *((_DWORD *)v68 + 5) = v72;
                        *((_DWORD *)v68 + 6) = v73;
                        *((_DWORD *)v68 + 7) = v74;
                        v68 += 32;
                      }
                      v65 += 16;
                    }
                    while ( (unsigned int)v65 < v66 );
                    v22 = v104;
                  }
                  *((_DWORD *)v64 + 1) = (v68 - v64 - 8) >> 5;
                  *((_DWORD *)v64 + 4) = 1;
                  v64 = v68;
                }
                v104 = --v22;
                v63 = (unsigned __int16 *)v66;
              }
              while ( v22 >= 0 );
              v9 = v108;
            }
            *v106 = (unsigned int)v61;
            ExFreePoolWithTag(v9);
            return 0;
          }
          ExFreePoolWithTag(v9);
          return -1073741670;
        }
LABEL_108:
        *v6 = v9;
        return 0;
      }
    }
  }
  if ( a2 && *a2 )
    *a3 = PnpCmResourcesToIoResources(a1, a2, 1);
  return 0;
}
