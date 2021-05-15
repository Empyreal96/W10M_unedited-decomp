// CmpCheckKey 
 
int __fastcall CmpCheckKey(int a1, int a2, int a3, int a4, char a5, int a6)
{
  _DWORD *v7; // r7
  int v8; // r8
  _WORD *v10; // r0
  _WORD *v11; // r4
  unsigned int v12; // r1
  int v13; // r2
  unsigned int v14; // r10
  __int64 v15; // kr00_8
  __int64 v16; // r8
  int v17; // r2
  int v18; // r0
  int v19; // r6
  unsigned int v20; // r2
  int v21; // r3
  __int16 v22; // r3
  int v23; // r0
  int v24; // r6
  int v25; // r10
  int v26; // r7
  unsigned int v27; // r6
  int v28; // r7
  int v29; // r1
  int v30; // r0
  int v31; // r8
  int v32; // r6
  unsigned __int16 *v33; // r0
  unsigned __int16 *v34; // r10
  unsigned int v35; // r6
  int v36; // r0
  int v37; // r1
  int v38; // r0
  int v39; // r1
  int v40; // r2
  int v41; // r3
  int v42; // r9
  unsigned int v43; // r2
  unsigned __int16 *v44; // r0
  unsigned __int16 *v45; // r9
  int v46; // r0
  int v47; // r1
  int v48; // r0
  int v49; // r1
  int v50; // r3
  int v51; // t1
  void (__fastcall *v52)(int, int *); // r3
  unsigned int v53; // r3
  void (__fastcall *v54)(int, int *); // r3
  int v55; // r0
  void (__fastcall *v56)(int, int *); // r3
  unsigned int v57; // r0
  unsigned int v58; // r1
  _WORD *v59; // r2
  int v60; // r0
  int v61; // r3
  int v62; // r10
  int v63; // r0
  int v64; // r6
  int v65; // r1
  int v66; // r3
  int v67; // r0
  int v68; // r6
  int v69; // r7
  __int16 v70; // r3
  int v71; // r0
  int v72; // r2
  int v73; // r3
  int v74; // r3
  int v75; // [sp+0h] [bp-70h]
  int v76; // [sp+10h] [bp-60h]
  int v77; // [sp+10h] [bp-60h]
  int v78; // [sp+14h] [bp-5Ch]
  unsigned __int16 *v80; // [sp+1Ch] [bp-54h]
  int v81; // [sp+20h] [bp-50h] BYREF
  int v82; // [sp+24h] [bp-4Ch]
  int v83; // [sp+28h] [bp-48h]
  int v84; // [sp+2Ch] [bp-44h] BYREF
  unsigned int v85; // [sp+30h] [bp-40h]
  int v86; // [sp+34h] [bp-3Ch] BYREF
  int v87; // [sp+38h] [bp-38h] BYREF
  int v88; // [sp+3Ch] [bp-34h] BYREF
  unsigned int v89; // [sp+40h] [bp-30h] BYREF
  unsigned int v90; // [sp+44h] [bp-2Ch] BYREF
  int v91; // [sp+48h] [bp-28h] BYREF
  int v92[9]; // [sp+4Ch] [bp-24h] BYREF

  v7 = *(_DWORD **)(a1 + 28);
  v8 = a3;
  v78 = (int)v7;
  v83 = a4;
  v84 = -1;
  v87 = -1;
  v88 = -1;
  v92[0] = -1;
  v81 = -1;
  v82 = a2;
  v7[58] = -1;
  v85 = 0;
  v89 = 0;
  v90 = 0;
  v80 = 0;
  v7[55] = a3;
  v7[56] = 0;
  v7[57] = 0;
  if ( !HvIsCellAllocated(a1, a3, a6) )
    return sub_7FD290();
  v10 = (_WORD *)(*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v8, &v87);
  v11 = v10;
  if ( !v10 )
  {
    SetFailureLocation((int)v7, 0, 14, 4095, 16);
    return 4095;
  }
  v7[56] = v10;
  if ( (unsigned int)(-80 - *((_DWORD *)v10 - 1)) > 0x410 )
  {
    v31 = 4020;
    v61 = 32;
    goto LABEL_261;
  }
  v12 = (unsigned __int16)v10[36];
  if ( !v10[36] || v12 + 76 > -4 - *((_DWORD *)v10 - 1) )
  {
    v31 = 4030;
    v61 = 48;
    goto LABEL_261;
  }
  if ( (v10[1] & 0x20) == 0 )
  {
    if ( (v12 & 1) != 0 )
    {
      v31 = 4032;
      v61 = 80;
    }
    else
    {
      if ( v10[38] )
      {
        v57 = 0;
        v58 = v12 >> 1;
        if ( v58 )
        {
          v59 = v11;
          while ( v59[38] != 92 )
          {
            ++v57;
            ++v59;
            if ( v57 >= v58 )
              goto LABEL_12;
          }
          v31 = 4035;
          v61 = 1296;
          goto LABEL_261;
        }
        goto LABEL_12;
      }
      v31 = 4033;
      v61 = 96;
    }
LABEL_261:
    v63 = (int)v7;
    goto LABEL_262;
  }
  if ( !*((_BYTE *)v10 + 76) )
  {
    v31 = 4031;
    v61 = 64;
    goto LABEL_261;
  }
  v13 = 0;
  if ( v10[36] )
  {
    while ( *((_BYTE *)v10 + v13 + 76) != 92 )
    {
      if ( ++v13 >= v12 )
        goto LABEL_12;
    }
    v31 = 4034;
    v61 = 1280;
    goto LABEL_261;
  }
LABEL_12:
  if ( *v11 == 27502 )
    goto LABEL_13;
  if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
  {
    v61 = 144;
    v31 = 4040;
    goto LABEL_261;
  }
  SetFailureLocation((int)v7, 1, 14, 4040, 112);
  if ( !HvpMarkCellDirty(a1, v8, 0, 0) )
  {
    v31 = 4040;
    v61 = 128;
    goto LABEL_261;
  }
  *v11 = 27502;
  *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
LABEL_13:
  v14 = (unsigned __int16)v11[37];
  v15 = *(_QWORD *)(v11 + 22);
  v16 = *(_QWORD *)(v11 + 18);
  if ( !v11[37] )
  {
    if ( HIDWORD(v15) != -1 && (v82 & 0x20000) == 0 )
    {
      HvpMarkCellDirty(a1, a3, 0, 0);
      *((_DWORD *)v11 + 12) = -1;
    }
    goto LABEL_15;
  }
  if ( HIDWORD(v15) == -1 )
  {
    if ( (v82 & 0x20000) == 0 )
    {
      HvpMarkCellDirty(a1, a3, 0, 0);
      v11[37] = 0;
      v14 = 0;
    }
    goto LABEL_15;
  }
  if ( !HvIsCellAllocated(a1, HIDWORD(v15), a6) )
  {
    v62 = (int)v7;
    goto LABEL_135;
  }
  v55 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, HIDWORD(v15), &v88);
  if ( !v55 )
  {
    v63 = (int)v7;
    v31 = 4081;
    v61 = 208;
    goto LABEL_262;
  }
  v56 = *(void (__fastcall **)(int, int *))(a1 + 8);
  if ( v14 > -4 - *(_DWORD *)(v55 - 4) )
  {
    v56(a1, &v88);
    v62 = (int)v7;
    SetFailureLocation((int)v7, 1, 14, 4080, 224);
LABEL_135:
    if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
    {
      SetFailureLocation(v62, 0, 14, 4080, 192);
      v31 = 4080;
      goto LABEL_55;
    }
    SetFailureLocation(v62, 1, 14, 4080, 160);
    if ( !HvpMarkCellDirty(a1, a3, 0, 0) )
    {
      SetFailureLocation(v62, 0, 14, 4080, 176);
      v31 = 4080;
      goto LABEL_55;
    }
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    *((_DWORD *)v11 + 12) = -1;
    v11[37] = 0;
    v14 = 0;
    goto LABEL_15;
  }
  v56(a1, &v88);
LABEL_15:
  if ( (_DWORD)v15 == -1 )
  {
    v65 = 4130;
    v64 = (int)v7;
    v77 = 4130;
    goto LABEL_148;
  }
  v17 = v83;
  if ( v83 == -1 )
    goto LABEL_78;
  if ( (CmpSelfHeal || (CmpBootType & 6) != 0) && a5 )
  {
    v64 = (int)v7;
    v77 = 4090;
    SetFailureLocation((int)v7, 1, 14, 4090, 240);
    v65 = 4090;
    goto LABEL_148;
  }
  while ( 1 )
  {
    if ( v17 == -1 )
    {
LABEL_78:
      v21 = (unsigned __int16)v11[1];
      if ( (v21 & 0x50) != 0 )
      {
        v71 = v78;
        v31 = 4048;
        v66 = 432;
        goto LABEL_258;
      }
      if ( (v21 & 2) != 0 )
      {
        if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
        {
          SetFailureLocation(v78, 1, 14, 4049, 448);
          if ( HvpMarkCellDirty(a1, a3, 0, 0) )
          {
            v11[1] &= 0xFFFDu;
            v17 = *(_DWORD *)(a1 + 32);
            *(_DWORD *)(v17 + 4088) |= 4u;
            v21 = 0;
            goto LABEL_28;
          }
          SetFailureLocation(v78, 0, 14, 4049, 464);
        }
        else
        {
          SetFailureLocation(v78, 0, 14, 4049, 480);
        }
        v31 = 4049;
        goto LABEL_53;
      }
    }
    else
    {
      if ( *((_DWORD *)v11 + 4) != v17 )
      {
        if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
        {
          SetFailureLocation(v78, 0, 14, 4045, 352);
          v31 = 4045;
          goto LABEL_53;
        }
        SetFailureLocation(v78, 1, 14, 4045, 320);
        if ( !HvpMarkCellDirty(a1, a3, 0, 0) )
        {
          SetFailureLocation(v78, 0, 14, 4045, 336);
          v31 = 4045;
          goto LABEL_53;
        }
        *((_DWORD *)v11 + 4) = v83;
        *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
      }
      v18 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v83, v92);
      v19 = v18;
      if ( !v18 )
      {
        v71 = v78;
        v31 = 4046;
        v66 = 368;
        goto LABEL_258;
      }
      if ( (v82 & 0x20000) == 0 )
      {
        if ( (v11[1] & 0x20) != 0 )
          v20 = (unsigned __int16)(2 * v11[36]);
        else
          v20 = (unsigned __int16)v11[36];
        if ( *(unsigned __int16 *)(v18 + 52) < v20 && HvpMarkCellDirty(a1, v83, 0, 0) )
        {
          v70 = v11[36];
          if ( (v11[1] & 0x20) != 0 )
            v70 *= 2;
          *(_WORD *)(v19 + 52) = v70;
        }
        if ( *(_DWORD *)(v19 + 56) < v14 && HvpMarkCellDirty(a1, v83, 0, 0) )
          *(_DWORD *)(v19 + 56) = v14;
      }
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v92);
      v21 = (unsigned __int16)v11[1];
      if ( (v21 & 0xE) != 0 )
      {
        if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
        {
          SetFailureLocation(v78, 0, 14, 4047, 416);
          v31 = 4047;
          goto LABEL_53;
        }
        SetFailureLocation(v78, 1, 14, 4047, 384);
        if ( !HvpMarkCellDirty(a1, a3, 0, 0) )
        {
          SetFailureLocation(v78, 0, 14, 4047, 400);
          v31 = 4047;
          goto LABEL_53;
        }
        v11[1] &= 0xFFF1u;
        v17 = *(_DWORD *)(a1 + 32);
        *(_DWORD *)(v17 + 4088) |= 4u;
        v21 = 0;
      }
    }
LABEL_28:
    if ( CmpIncrementCachedSecurityRefcount(a1, *((_DWORD *)v11 + 11), v17, v21) )
    {
      v22 = v11[1];
      if ( (v22 & 0x40) != 0 )
      {
        if ( (v22 & 0x1E) != 0 )
        {
          v77 = 4097;
          if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
          {
            v71 = v78;
            v66 = 656;
            goto LABEL_257;
          }
          v28 = v78;
          SetFailureLocation(v78, 1, 14, 4097, 624);
          v25 = a3;
          if ( !HvpMarkCellDirty(a1, a3, 0, 0) )
          {
            v66 = 640;
            v71 = v78;
            goto LABEL_257;
          }
          v11[1] &= 0xFFE1u;
          *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
        }
        else
        {
          v28 = v78;
          v25 = a3;
        }
        if ( *((int *)v11 + 9) >= 0 )
        {
          v31 = 4098;
          v66 = 672;
          v71 = v28;
          goto LABEL_258;
        }
        goto LABEL_42;
      }
      if ( (_DWORD)v16 )
      {
        if ( HvIsCellAllocated(a1, HIDWORD(v16), a6) )
        {
          v86 = -1;
          v23 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, HIDWORD(v16), &v86);
          v24 = v23;
          if ( !v23 )
          {
            v31 = 4094;
            SetFailureLocation(v78, 0, 14, 4094, 528);
            goto LABEL_53;
          }
          if ( (unsigned int)(4 * v16) >> 2 == (_DWORD)v16 && 4 * (int)v16 <= (unsigned int)(-4 - *(_DWORD *)(v23 - 4)) )
          {
            v25 = a3;
            v26 = CmpCheckValueList(a1, (v11[1] & 0x10) != 0, v23, v16, a3, a6, &v90, &v89);
            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v86);
            if ( !v26 )
            {
              v27 = v90;
              v85 = v89;
LABEL_37:
              v28 = v78;
LABEL_38:
              if ( !*((_DWORD *)v11 + 9) )
              {
                v27 = 0;
                v85 = 0;
              }
              v29 = v82;
              if ( *((_DWORD *)v11 + 15) != v27 && (v82 & 0x20000) == 0 )
              {
                v60 = HvpMarkCellDirty(a1, v25, 0, 0);
                v29 = v82;
                if ( v60 )
                  *((_DWORD *)v11 + 15) = v27;
              }
              if ( *((_DWORD *)v11 + 16) != v85 && (v29 & 0x20000) == 0 && HvpMarkCellDirty(a1, v25, 0, 0) )
                *((_DWORD *)v11 + 16) = v85;
LABEL_42:
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v87);
              v30 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v25, &v87);
              v11 = (_WORD *)v30;
              if ( !v30 )
              {
                v31 = 4093;
                v66 = 688;
                v71 = v28;
                goto LABEL_258;
              }
              *(_DWORD *)(v28 + 224) = v30;
              if ( v25 < 0 && *(_DWORD *)(v30 + 20) )
              {
                v31 = 4108;
                v66 = 704;
                v71 = v28;
                goto LABEL_258;
              }
              if ( !*(_DWORD *)(v30 + 20) )
                goto LABEL_45;
              if ( !HvIsCellAllocated(a1, *(_DWORD *)(v30 + 28), a6) )
              {
                v31 = 4110;
                SetFailureLocation(v28, 1, 14, 4110, 720);
                goto LABEL_220;
              }
              v33 = (unsigned __int16 *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(
                                          a1,
                                          *((_DWORD *)v11 + 7),
                                          &v81);
              v34 = v33;
              v80 = v33;
              if ( !v33 )
              {
                v31 = 4094;
                SetFailureLocation(v28, 0, 14, 4094, 736);
                goto LABEL_55;
              }
              v35 = -4 - *((_DWORD *)v33 - 1);
              if ( v35 < 8
                || (v36 = CmpGetIndexElementSize(v33), (unsigned int)(v36 * v37) >= 0xFFFFFFFC)
                || (v38 = CmpGetIndexElementSize(v34), v38 * v39 + 4 > v35) )
              {
                (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                v80 = 0;
                if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
                {
                  SetFailureLocation(v28, 0, 14, 4095, 768);
                  v31 = 4095;
                  goto LABEL_55;
                }
                SetFailureLocation(v28, 1, 14, 4095, 752);
                v31 = 4095;
                goto LABEL_219;
              }
              if ( v39 )
              {
                *(_DWORD *)(v28 + 228) = v34;
                v40 = *v34;
                if ( v40 != 26988 )
                {
                  if ( v40 != 26220 && v40 != 26732 )
                  {
                    if ( v40 == 26994 )
                    {
                      v41 = v34[1];
                      v42 = 0;
                      v43 = 0;
                      v90 = 0;
                      v91 = 0;
                      if ( v41 )
                      {
                        while ( 1 )
                        {
                          *(_DWORD *)(v78 + 232) = v43;
                          if ( !HvIsCellAllocated(a1, *((_DWORD *)v34 + 1), a6) )
                          {
                            v31 = 4130;
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                            v75 = 848;
                            v74 = 4130;
                            goto LABEL_217;
                          }
                          v44 = (unsigned __int16 *)(*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(
                                                      a1,
                                                      *((_DWORD *)v34 + 1),
                                                      &v84);
                          v45 = v44;
                          if ( !v44 )
                          {
                            v71 = v78;
                            v31 = 4092;
                            v66 = 864;
                            goto LABEL_258;
                          }
                          v89 = -4 - *((_DWORD *)v44 - 1);
                          if ( v89 < 8 )
                            break;
                          v46 = CmpGetIndexElementSize(v44);
                          if ( (unsigned int)(v46 * v47) >= 0xFFFFFFFC )
                            break;
                          v48 = CmpGetIndexElementSize(v45);
                          if ( v48 * v49 + 4 > v89 )
                            break;
                          if ( !v49 )
                          {
                            v31 = 4135;
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v84);
                            if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
                            {
                              v71 = v78;
                              v66 = 928;
                              goto LABEL_258;
                            }
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                            v80 = 0;
                            v28 = v78;
                            SetFailureLocation(v78, 1, 14, 4135, 912);
                            v25 = a3;
                            goto LABEL_220;
                          }
                          v50 = *v45;
                          if ( v50 != 26732 && v50 != 26988 && v50 != 26220 )
                          {
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v84);
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                            v31 = 4140;
                            v75 = 944;
                            v74 = 4140;
LABEL_217:
                            v80 = 0;
                            v28 = v78;
                            SetFailureLocation(v78, 1, 14, v74, v75);
                            goto LABEL_219;
                          }
                          v51 = *((_DWORD *)v34 + 1);
                          v34 += 2;
                          v76 = CmpCheckLeaf(a1, v82, v45, v51);
                          if ( v76 )
                          {
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v84);
                            (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                            v31 = v76;
                            v80 = 0;
                            goto LABEL_218;
                          }
                          v42 = v91 + v45[1];
                          v52 = *(void (__fastcall **)(int, int *))(a1 + 8);
                          v91 = v42;
                          v52(a1, &v84);
                          v53 = v80[1];
                          v43 = v90 + 1;
                          v90 = v43;
                          if ( v43 >= v53 )
                            goto LABEL_93;
                        }
                        v31 = 4131;
                        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v84);
                        if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
                        {
                          v71 = v78;
                          v66 = 896;
                          goto LABEL_258;
                        }
                        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                        v80 = 0;
                        v28 = v78;
                        SetFailureLocation(v78, 1, 14, 4131, 880);
                        v25 = a3;
LABEL_220:
                        if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
                        {
                          v66 = 1040;
                          v71 = v28;
                          goto LABEL_258;
                        }
                        SetFailureLocation(v28, 1, 14, v31, 1008);
                        if ( !HvpMarkCellDirty(a1, v25, 0, 0) )
                        {
                          v66 = 1024;
                          v71 = v28;
                          goto LABEL_258;
                        }
                        *((_DWORD *)v11 + 7) = -1;
                        *((_DWORD *)v11 + 5) = 0;
                        v31 = 0;
                        *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
LABEL_46:
                        if ( (v82 & 4) != 0 && *(_DWORD *)(a1 + 148) >= 4u )
                          v32 = -1163005939;
                        else
                          v32 = -1;
                        if ( (v82 & 2) != 0
                          || (v82 & 5) != 0 && (*((_DWORD *)v11 + 6) || *((_DWORD *)v11 + 8) != -1)
                          || (v82 & 8) != 0
                          && (*((_DWORD *)v11 + 8) != -1 || *((_DWORD *)v11 + 6) || *(_DWORD *)(a1 + 148) < 4u) )
                        {
                          if ( !HvpMarkCellDirty(a1, v25, 0, 0) )
                          {
                            v31 = 4121;
                            v66 = 1056;
                            v71 = v28;
                            goto LABEL_258;
                          }
                          *((_DWORD *)v11 + 6) = 0;
                          *((_DWORD *)v11 + 8) = v32;
                        }
                        goto LABEL_53;
                      }
LABEL_93:
                      v54 = *(void (__fastcall **)(int, int *))(a1 + 8);
                      if ( *((_DWORD *)v11 + 5) != v42 )
                      {
                        v31 = 4150;
                        v54(a1, &v81);
                        v80 = 0;
                        if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
                        {
                          v28 = v78;
                          SetFailureLocation(v78, 1, 14, 4150, 960);
                          v25 = a3;
                          goto LABEL_220;
                        }
                        v63 = v78;
                        v61 = 976;
                        goto LABEL_262;
                      }
                      v54(a1, &v81);
                      v28 = v78;
                      v25 = a3;
                      v80 = 0;
LABEL_45:
                      v31 = 0;
                      goto LABEL_46;
                    }
                    v31 = 4120;
                    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                    v28 = v78;
                    v80 = 0;
                    SetFailureLocation(v78, 1, 14, 4120, 992);
LABEL_219:
                    v25 = a3;
                    goto LABEL_220;
                  }
                  v28 = v78;
                }
                if ( v34[1] != *((_DWORD *)v11 + 5) )
                {
                  v31 = 4120;
                  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                  v80 = 0;
                  if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
                  {
                    SetFailureLocation(v28, 1, 14, 4120, 816);
                    v25 = a3;
                    goto LABEL_220;
                  }
                  SetFailureLocation(v28, 0, 14, 4120, 832);
                  goto LABEL_55;
                }
                v31 = CmpCheckLeaf(a1, v82, v34, *((_DWORD *)v11 + 7));
                (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
                v80 = 0;
                if ( !v31 )
                {
                  v28 = v78;
                  v25 = a3;
                  goto LABEL_46;
                }
LABEL_218:
                v28 = v78;
                goto LABEL_219;
              }
              (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
              v80 = 0;
              if ( CmpSelfHeal || (CmpBootType & 6) != 0 )
              {
                v31 = 4105;
                v28 = v78;
                SetFailureLocation(v78, 1, 14, 4105, 784);
                goto LABEL_219;
              }
              v31 = 4105;
              v63 = v78;
              v61 = 800;
LABEL_262:
              SetFailureLocation(v63, 0, 14, v31, v61);
              goto LABEL_55;
            }
            v72 = v26;
            v28 = v78;
            v73 = v89;
            v77 = v72;
            *(_DWORD *)(v78 + 224) = v24;
            v27 = v90;
            v85 = v73;
LABEL_189:
            if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
            {
              v66 = 592;
              v71 = v28;
              goto LABEL_257;
            }
            SetFailureLocation(v28, 1, 14, v72, 560);
            if ( !HvpMarkCellDirty(a1, v25, 0, 0) )
            {
              v66 = 576;
              v71 = v28;
              goto LABEL_257;
            }
            *((_DWORD *)v11 + 9) = 0;
            *((_DWORD *)v11 + 10) = -1;
            *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
            goto LABEL_38;
          }
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v86);
          v28 = v78;
          v77 = 4095;
          SetFailureLocation(v78, 1, 14, 4095, 544);
          v72 = 4095;
        }
        else
        {
          v28 = v78;
          v77 = 4100;
          SetFailureLocation(v78, 1, 14, 4100, 512);
          v72 = 4100;
        }
      }
      else
      {
        if ( HIDWORD(v16) == -1 )
        {
          v25 = a3;
          v27 = 0;
          goto LABEL_37;
        }
        v28 = v78;
        v77 = 4096;
        SetFailureLocation(v78, 1, 14, 4096, 608);
        v72 = 4096;
      }
      v25 = a3;
      v27 = 0;
      goto LABEL_189;
    }
    v64 = v78;
    v77 = 4130;
    SetFailureLocation(v78, 1, 14, 4130, 496);
    v65 = 4130;
LABEL_148:
    if ( !CmpSelfHeal && (CmpBootType & 6) == 0 )
    {
      v66 = 304;
      goto LABEL_256;
    }
    v86 = -1;
    v91 = -1;
    SetFailureLocation(v64, 1, 14, v65, 256);
    if ( v83 == -1 )
      goto LABEL_255;
    v67 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v83, &v86);
    v68 = v67;
    if ( !v67 )
      goto LABEL_254;
    v69 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v67 + 44), &v91);
    if ( !v69 )
      break;
    if ( !HvpMarkCellDirty(a1, a3, 0, 0) || !HvpMarkCellDirty(a1, *(_DWORD *)(v68 + 44), 0, 0) )
    {
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v91);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v86);
      v71 = v78;
      v66 = 288;
      goto LABEL_257;
    }
    *((_DWORD *)v11 + 11) = *(_DWORD *)(v68 + 44);
    ++*(_DWORD *)(v69 + 12);
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4088) |= 4u;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v91);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v86);
    v17 = v83;
  }
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v86);
LABEL_254:
  v64 = v78;
LABEL_255:
  v66 = 272;
LABEL_256:
  v71 = v64;
LABEL_257:
  v31 = v77;
LABEL_258:
  SetFailureLocation(v71, 0, 14, v31, v66);
LABEL_53:
  if ( v80 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v81);
LABEL_55:
  if ( v11 )
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v87);
  return v31;
}
