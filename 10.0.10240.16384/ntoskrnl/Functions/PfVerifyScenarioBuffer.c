// PfVerifyScenarioBuffer 
 
int __fastcall PfVerifyScenarioBuffer(unsigned int a1, unsigned int a2, int *a3)
{
  _DWORD *v4; // r8
  int v6; // r3
  unsigned int v7; // r9
  unsigned int v8; // r10
  unsigned int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // lr
  int v15; // t1
  unsigned int v16; // r5
  int v17; // r4
  int v18; // r10
  int v19; // r2
  int v20; // r7
  int v21; // r0
  int v22; // r9
  _DWORD *v23; // r5
  unsigned int v24; // r1
  int v25; // r6
  int v26; // r0
  unsigned int v27; // r2
  unsigned int v28; // lr
  unsigned int v29; // r2
  int *v30; // r5
  unsigned int v31; // r1
  unsigned int v32; // lr
  unsigned int v33; // r10
  unsigned int v34; // r9
  int v35; // r8
  unsigned int v36; // r4
  int v37; // t1
  char *v38; // r7
  int v39; // r7
  unsigned int v40; // r3
  unsigned int v41; // r2
  unsigned __int16 *v42; // r1
  unsigned int v43; // r1
  int v44; // r0
  int v45; // r7
  int *v46; // r4
  int v47; // lr
  int v48; // r2
  int v49; // r3
  int v50; // r3
  unsigned int v51; // r4
  int v52; // r2
  int *v53; // r1
  int v54; // r3
  __int64 v55; // kr00_8
  unsigned int v56; // r3
  unsigned int v57; // r3
  unsigned int v58; // r3
  unsigned int v59; // r3
  unsigned int v60; // r5
  unsigned int v61; // r3
  unsigned int v62; // r3
  _WORD *v63; // r3
  char *v64; // r3
  _DWORD *v65; // r2
  unsigned int v66; // r8
  unsigned int v67; // r3
  unsigned int v68; // r0
  unsigned __int16 *v69; // r3
  int v70; // [sp+8h] [bp-C8h]
  unsigned int v71; // [sp+8h] [bp-C8h]
  unsigned int v72; // [sp+Ch] [bp-C4h]
  unsigned int v73; // [sp+10h] [bp-C0h]
  unsigned int v75; // [sp+18h] [bp-B8h]
  unsigned int v76; // [sp+1Ch] [bp-B4h]
  int v77; // [sp+24h] [bp-ACh]
  __int64 v78; // [sp+28h] [bp-A8h] BYREF
  unsigned int v79; // [sp+30h] [bp-A0h]
  int v80; // [sp+34h] [bp-9Ch]
  unsigned int v81; // [sp+38h] [bp-98h]
  unsigned int v82; // [sp+3Ch] [bp-94h]
  int *v83; // [sp+40h] [bp-90h]
  int v84; // [sp+44h] [bp-8Ch]
  unsigned int v85; // [sp+48h] [bp-88h]
  __int16 v86[12]; // [sp+50h] [bp-80h] BYREF
  _WORD v87[52]; // [sp+68h] [bp-68h] BYREF

  v83 = a3;
  v4 = (_DWORD *)a1;
  if ( a2 < 0x130 )
    return sub_808A4C();
  if ( (a1 & 7) != 0 )
  {
    v25 = 15;
  }
  else if ( *(_DWORD *)a1 == 30 && *(_DWORD *)(a1 + 4) == 1094927187 )
  {
    if ( a2 > 0x10000000 )
    {
      v25 = 25;
    }
    else if ( a2 == *(_DWORD *)(a1 + 12) )
    {
      v6 = *(_DWORD *)(a1 + 80);
      if ( v6 < 0 || v6 >= 2 )
      {
        v25 = 27;
      }
      else
      {
        v7 = *(_DWORD *)(a1 + 88);
        v85 = v7;
        if ( v7 > 0x4000
          || (v8 = *(_DWORD *)(a1 + 112), v75 = v8, v8 > 0x4000)
          || (v9 = *(_DWORD *)(a1 + 96), v9 > 0x100000)
          || (v10 = *(_DWORD *)(a1 + 104), v10 > 0x400000) )
        {
          v25 = 30;
        }
        else if ( v7 && v9 && v10 )
        {
          v11 = *(_DWORD *)(a1 + 212);
          if ( !v11 || v11 > 8 )
          {
            *v83 = 35;
            return 0;
          }
          if ( PfVerifyScenarioId(a1 + 16) )
          {
            v13 = (unsigned int)v4 + v4[21];
            if ( (v13 & 3) != 0 )
            {
              v25 = 38;
            }
            else if ( v13 < (unsigned int)v4
                   || (v28 = (unsigned int)v4 + a2, v72 = (unsigned int)v4 + a2, v13 >= (unsigned int)v4 + a2) )
            {
              v25 = 40;
            }
            else
            {
              v56 = v13 + 32 * v7 - 1;
              if ( v56 < (unsigned int)v4 || v56 >= v28 )
              {
                v25 = 45;
              }
              else
              {
                v57 = (unsigned int)v4 + v4[23];
                v79 = v57;
                if ( (v57 & 3) != 0 )
                {
                  v25 = 47;
                }
                else if ( v57 < (unsigned int)v4 || v57 >= v28 )
                {
                  v25 = 50;
                }
                else
                {
                  v58 = v57 + 8 * v9 - 1;
                  if ( v58 < (unsigned int)v4 || v58 >= v28 )
                  {
                    v25 = 55;
                  }
                  else
                  {
                    v27 = (unsigned int)v4 + v4[25];
                    LODWORD(v78) = v27;
                    if ( (v27 & 1) != 0 )
                    {
                      v25 = 57;
                    }
                    else if ( v27 < (unsigned int)v4 || v27 >= v28 )
                    {
                      v25 = 60;
                    }
                    else
                    {
                      v59 = v10 + v27 - 1;
                      if ( v59 < (unsigned int)v4 || v59 >= v28 )
                      {
                        v25 = 70;
                      }
                      else
                      {
                        v60 = (unsigned int)v4 + v4[27];
                        v73 = v60;
                        if ( (v60 & 7) != 0 )
                        {
                          v25 = 72;
                        }
                        else if ( v60 < (unsigned int)v4 || v60 >= v28 )
                        {
                          v25 = 73;
                        }
                        else
                        {
                          v61 = v4[29] + v60 - 1;
                          if ( v61 < (unsigned int)v4 || v61 >= v28 )
                          {
                            v25 = 74;
                          }
                          else
                          {
                            v62 = v60 + 96 * v8 - 1;
                            if ( v62 >= (unsigned int)v4 && v62 < v28 )
                            {
                              if ( v4[31] > 7u )
                              {
                                v25 = 76;
                              }
                              else
                              {
                                v26 = 0;
                                v77 = 0;
                                while ( 1 )
                                {
                                  v29 = v27 + *(_DWORD *)(v13 + 12);
                                  if ( (v29 & 1) != 0 )
                                  {
                                    v25 = 77;
                                    goto LABEL_38;
                                  }
                                  if ( v29 < (unsigned int)v4 || v29 >= v28 )
                                  {
                                    v25 = 80;
                                    goto LABEL_38;
                                  }
                                  v40 = *(_DWORD *)(v13 + 16);
                                  if ( !v40 )
                                  {
                                    v25 = 90;
                                    goto LABEL_38;
                                  }
                                  if ( v40 > 0x400 )
                                  {
                                    v25 = 100;
                                    goto LABEL_38;
                                  }
                                  v63 = (_WORD *)(v29 + 2 * v40);
                                  if ( (_DWORD *)((char *)v63 + 1) < v4 || (unsigned int)v63 + 1 >= v28 )
                                  {
                                    v25 = 110;
                                    goto LABEL_38;
                                  }
                                  if ( *v63 )
                                  {
                                    v25 = 120;
                                    goto LABEL_38;
                                  }
                                  v12 = *(_DWORD *)(v13 + 4);
                                  if ( v12 > 0x2000 )
                                  {
                                    v25 = 140;
                                    goto LABEL_38;
                                  }
                                  if ( v12 > v9 )
                                  {
                                    v25 = 150;
                                    goto LABEL_38;
                                  }
                                  v15 = *(_DWORD *)v13;
                                  v13 += 32;
                                  v14 = v15;
                                  v76 = v9 - v12;
                                  v81 = v13;
                                  if ( v15 == -1 && v12 )
                                  {
                                    v25 = 152;
                                    goto LABEL_38;
                                  }
                                  if ( v14 != v26 && v14 != -1 )
                                  {
                                    v25 = 153;
                                    goto LABEL_38;
                                  }
                                  v16 = *(_DWORD *)(v13 - 12);
                                  v80 = v26 + v12;
                                  v17 = v16 & 1;
                                  v84 = v17;
                                  v82 = v16;
                                  if ( (v16 & 1) == 0 && (v16 & 0x7F00) == 0 && (v16 & 0xFE) == 0 )
                                  {
                                    v25 = 155;
                                    goto LABEL_38;
                                  }
                                  if ( (v16 & 1) == 0 && !*(_DWORD *)(v13 - 24) )
                                  {
                                    v25 = 157;
                                    goto LABEL_38;
                                  }
                                  v18 = v14 + v12;
                                  v19 = 0;
                                  v20 = 0;
                                  v70 = 0;
                                  v21 = v14;
                                  v22 = 0;
                                  if ( v14 < v18 )
                                  {
                                    v23 = (_DWORD *)(v79 + 8 * v14);
                                    while ( v21 >= 0 && (unsigned int)v21 < v4[24] )
                                    {
                                      if ( v21 != v14 && *v23 <= *(v23 - 2) )
                                      {
                                        v25 = 165;
                                        goto LABEL_38;
                                      }
                                      v24 = v23[1];
                                      if ( (v24 & 1) == 0 && ((v24 >> 4) & 7) > v4[31] )
                                      {
                                        v25 = 167;
                                        goto LABEL_38;
                                      }
                                      if ( (v24 & 0xE) == 0 )
                                      {
                                        v25 = 173;
                                        goto LABEL_38;
                                      }
                                      if ( (v24 & 1) != 0 )
                                      {
                                        if ( (v24 & 8) != 0 )
                                        {
                                          v25 = 175;
                                          goto LABEL_38;
                                        }
                                      }
                                      else
                                      {
                                        ++v20;
                                        if ( (v24 & 4) != 0 )
                                          v70 |= 1 << ((v24 >> 4) & 7);
                                        if ( (v24 & 2) != 0 )
                                          v22 |= 1 << ((v24 >> 4) & 7);
                                      }
                                      ++v21;
                                      v23 += 2;
                                      if ( v21 >= v18 )
                                      {
                                        v13 = v81;
                                        v16 = v82;
                                        v19 = v70;
                                        v17 = v84;
                                        goto LABEL_46;
                                      }
                                    }
                                    v25 = 160;
                                    goto LABEL_38;
                                  }
LABEL_46:
                                  if ( v20 != *(_DWORD *)(v13 - 24) )
                                  {
                                    v25 = 185;
                                    goto LABEL_38;
                                  }
                                  if ( !v17 && (v19 != (unsigned __int8)v16 >> 1 || v22 != ((v16 >> 8) & 0x7F)) )
                                  {
                                    v25 = 187;
                                    goto LABEL_38;
                                  }
                                  v9 = v76;
                                  if ( ++v77 >= v85 )
                                    break;
                                  v26 = v80;
                                  v27 = v78;
                                  v28 = v72;
                                }
                                v30 = (int *)v73;
                                if ( v76 )
                                {
                                  v25 = 190;
                                }
                                else
                                {
                                  v31 = v75;
                                  v32 = 0;
                                  v71 = 0;
                                  v33 = 0;
                                  if ( v75 )
                                  {
                                    v34 = 1;
                                    while ( 1 )
                                    {
                                      v35 = v30[4];
                                      v36 = v34;
                                      v78 = *((_QWORD *)v30 + 1);
                                      if ( v34 < v31 )
                                        break;
LABEL_64:
                                      v37 = *v30;
                                      v30 += 24;
                                      v38 = (char *)(v37 + v73);
                                      if ( ((v37 + v73) & 1) != 0 )
                                      {
                                        *v83 = 195;
                                        return 0;
                                      }
                                      if ( (unsigned int)v38 < a1 || (unsigned int)v38 >= v72 )
                                      {
                                        v25 = 200;
                                        goto LABEL_38;
                                      }
                                      v64 = &v38[2 * *(v30 - 23)];
                                      if ( (unsigned int)(v64 + 1) < a1 || (unsigned int)(v64 + 1) >= v72 )
                                      {
                                        v25 = 210;
                                        goto LABEL_38;
                                      }
                                      if ( *(_WORD *)v64 )
                                      {
                                        v25 = 220;
                                        goto LABEL_38;
                                      }
                                      memset(v86, 0, sizeof(v86));
                                      v55 = *((_QWORD *)v30 - 11);
                                      v86[11] &= 0xFFE1u;
                                      StringCchPrintfW(v87, 0x23u, (int)L"\\VOLUME{%08lx%08lx-%08lx}", SHIDWORD(v55));
                                      if ( wcscmp(v38, (char *)v87) )
                                      {
                                        *v83 = 222;
                                        return 0;
                                      }
                                      v65 = (_DWORD *)(v73 + *(v30 - 19));
                                      if ( ((unsigned __int8)v65 & 7) != 0 )
                                      {
                                        v25 = 225;
                                        goto LABEL_38;
                                      }
                                      if ( (unsigned int)v65 < a1 || (unsigned int)v65 >= v72 )
                                      {
                                        v25 = 230;
                                        goto LABEL_38;
                                      }
                                      v66 = *(v30 - 18);
                                      if ( v66 < 0x18 )
                                      {
                                        v25 = 240;
                                        goto LABEL_38;
                                      }
                                      v67 = (unsigned int)v65 + v66 - 1;
                                      if ( v67 < a1 || v67 >= v72 )
                                      {
                                        v25 = 245;
                                        goto LABEL_38;
                                      }
                                      if ( *v65 != 3 )
                                      {
                                        v25 = 250;
                                        goto LABEL_38;
                                      }
                                      v43 = v65[1];
                                      if ( v43 > 0x84000 )
                                      {
                                        v25 = 260;
                                        goto LABEL_38;
                                      }
                                      v44 = *(_DWORD *)(a1 + 124);
                                      v45 = 0;
                                      if ( v44 )
                                      {
                                        v46 = v30 - 24;
                                        v47 = *(_DWORD *)(a1 + 124);
                                        do
                                        {
                                          v48 = v46[16];
                                          v49 = v46[9];
                                          ++v46;
                                          v45 += v49 + v48;
                                          --v47;
                                        }
                                        while ( v47 );
                                      }
                                      if ( v45 != v43 )
                                      {
                                        v25 = 265;
                                        goto LABEL_38;
                                      }
                                      v50 = 24;
                                      if ( v43 )
                                        v50 = 8 * (v43 + 2);
                                      if ( v50 != v66 )
                                      {
                                        v25 = 270;
                                        goto LABEL_38;
                                      }
                                      v51 = *(v30 - 16);
                                      if ( v51 > 0x80000 )
                                      {
                                        v25 = 280;
                                        goto LABEL_38;
                                      }
                                      v52 = 0;
                                      if ( v44 )
                                      {
                                        v53 = v30 - 24;
                                        do
                                        {
                                          v54 = v53[16];
                                          ++v53;
                                          v52 += v54;
                                          --v44;
                                        }
                                        while ( v44 );
                                      }
                                      if ( v52 != v51 )
                                      {
                                        *v83 = 281;
                                        return 0;
                                      }
                                      v32 = v71 + v52;
                                      v71 += v52;
                                      v42 = (unsigned __int16 *)(*(v30 - 17) + v73);
                                      if ( ((unsigned __int8)v42 & 1) != 0 )
                                      {
                                        v25 = 283;
                                        goto LABEL_38;
                                      }
                                      v4 = (_DWORD *)a1;
                                      v41 = 0;
                                      if ( v51 )
                                      {
                                        while ( (unsigned int)v42 >= a1 && (unsigned int)v42 < v72 )
                                        {
                                          if ( (unsigned int)v42 + 3 < a1 || (unsigned int)v42 + 3 >= v72 )
                                          {
                                            v25 = 290;
                                            goto LABEL_38;
                                          }
                                          v68 = *v42;
                                          if ( v68 >= 0x400 )
                                          {
                                            v25 = 300;
                                            goto LABEL_38;
                                          }
                                          v69 = &v42[v68];
                                          if ( (unsigned int)v69 + 3 < a1 || (v32 = v71, (unsigned int)v69 + 3 >= v72) )
                                          {
                                            v25 = 310;
                                            goto LABEL_38;
                                          }
                                          if ( v69[1] )
                                          {
                                            v25 = 320;
                                            goto LABEL_38;
                                          }
                                          ++v41;
                                          v42 += v68 + 2;
                                          if ( v41 >= v51 )
                                            goto LABEL_75;
                                        }
                                        v25 = 285;
                                        goto LABEL_38;
                                      }
LABEL_75:
                                      v31 = *(_DWORD *)(a1 + 112);
                                      ++v33;
                                      ++v34;
                                      v75 = v31;
                                      if ( v33 >= v31 )
                                        goto LABEL_76;
                                    }
                                    v39 = (int)(v30 + 24);
                                    while ( !PfMetadataRecordIsEqual(v39, &v78, v35) )
                                    {
                                      ++v36;
                                      v39 += 96;
                                      if ( v36 >= v75 )
                                        goto LABEL_64;
                                    }
                                    v25 = 192;
                                  }
                                  else
                                  {
LABEL_76:
                                    if ( v32 == v4[30] )
                                    {
                                      if ( v32 <= 0x80000 )
                                      {
                                        *v83 = 0;
                                        return 1;
                                      }
                                      v25 = 340;
                                    }
                                    else
                                    {
                                      v25 = 330;
                                    }
                                  }
                                }
                              }
                            }
                            else
                            {
                              v25 = 75;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else
          {
            v25 = 37;
          }
        }
        else
        {
          v25 = 33;
        }
      }
    }
    else
    {
      v25 = 26;
    }
  }
  else
  {
    v25 = 20;
  }
LABEL_38:
  *v83 = v25;
  return 0;
}
