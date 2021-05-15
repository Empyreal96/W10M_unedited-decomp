// PiDevCfgFindDeviceDriver 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PiDevCfgFindDeviceDriver(int a1, int a2, int *a3)
{
  int v3; // r9
  int v4; // r6
  int v5; // r5
  _WORD *v6; // r7
  int v7; // r8
  unsigned __int16 *v9; // r10
  unsigned int v10; // r2
  unsigned __int16 *v11; // r6
  int v12; // r0
  unsigned int v13; // r0
  int v14; // r3
  int v15; // r3
  unsigned __int16 *v16; // r2
  _WORD *v17; // r4
  unsigned __int16 *v18; // r5
  int v19; // r1
  unsigned int v20; // r3
  int v21; // r2
  int v22; // r4
  unsigned __int16 *v23; // r6
  unsigned __int16 *v24; // r5
  int v25; // r3
  int v26; // r4
  unsigned int v27; // r10
  int v28; // r7
  unsigned __int16 *v29; // r5
  int **v30; // r1
  int v31; // r5
  _WORD *v32; // r2
  _WORD *v33; // r5
  int v34; // r6
  int **v35; // r1
  int v36; // r2
  int v37; // r3
  unsigned int v38; // r3
  unsigned int v39; // r2
  __int64 v40; // kr00_8
  __int64 v41; // kr08_8
  __int64 v42; // kr10_8
  __int64 v43; // kr18_8
  int **v44; // r1
  int v45; // r3
  _WORD *v46; // r0
  _WORD *v47; // r4
  _WORD *v48; // r0
  int *v49; // r1
  __int64 v50; // kr20_8
  int **v51; // r0
  int *v52; // r4
  int *v53; // r1 OVERLAPPED
  unsigned __int16 *v54; // r5
  int i; // r3
  int v56; // r6
  unsigned __int16 *v57; // r2
  _WORD *v58; // r6
  int v59; // r7
  int *v60; // r5
  int v61; // r6
  int v62; // r2
  int v63; // r3
  int *v64; // r1 OVERLAPPED
  int **v65; // r2 OVERLAPPED
  int **v66; // r2
  unsigned int v67; // r3
  unsigned int v68; // r2
  __int64 v69; // kr28_8
  __int64 v70; // kr30_8
  __int64 v71; // kr38_8
  __int64 v72; // kr40_8
  int *v73; // r1 OVERLAPPED
  int *v74; // r1 OVERLAPPED
  int *v75; // [sp+20h] [bp-88h] BYREF
  int **v76; // [sp+24h] [bp-84h]
  int v77[2]; // [sp+28h] [bp-80h] BYREF
  int *v78; // [sp+30h] [bp-78h] BYREF
  int **v79; // [sp+34h] [bp-74h]
  unsigned __int16 *v80; // [sp+38h] [bp-70h]
  unsigned int v81; // [sp+3Ch] [bp-6Ch] BYREF
  int v82; // [sp+40h] [bp-68h] BYREF
  unsigned __int16 *v83; // [sp+44h] [bp-64h]
  char v84[2]; // [sp+48h] [bp-60h] BYREF
  unsigned __int16 v85; // [sp+4Ah] [bp-5Eh]
  unsigned int v86; // [sp+4Ch] [bp-5Ch]
  unsigned __int16 *v87; // [sp+50h] [bp-58h]
  unsigned int v88; // [sp+54h] [bp-54h]
  unsigned int v89; // [sp+58h] [bp-50h]
  int v90; // [sp+5Ch] [bp-4Ch]
  _WORD *v91; // [sp+60h] [bp-48h]
  unsigned __int16 *v92; // [sp+64h] [bp-44h]
  int v93; // [sp+68h] [bp-40h]
  int v94; // [sp+6Ch] [bp-3Ch]
  int *v95; // [sp+70h] [bp-38h]
  unsigned __int16 v96[4]; // [sp+78h] [bp-30h] BYREF
  unsigned __int16 v97[20]; // [sp+80h] [bp-28h] BYREF

  v92 = 0;
  v82 = 1;
  v81 = 0;
  v77[0] = 0;
  v3 = 0;
  v76 = &v75;
  v75 = (int *)&v75;
  v79 = &v78;
  v4 = a1;
  v5 = 0;
  v6 = 0;
  v78 = (int *)&v78;
  v95 = a3;
  v93 = a1;
  v7 = 0;
  v90 = 0;
  v91 = 0;
  if ( a2 )
    return sub_7E256C();
  v94 = 1;
  if ( PnpSetupInProgress )
    v94 = 3;
  v89 = 520;
  v9 = (unsigned __int16 *)ExAllocatePoolWithTag(1, 520, 1667526736);
  v87 = v9;
  if ( !v9 )
  {
    v7 = -1073741670;
    goto LABEL_182;
  }
  v10 = 0;
  v88 = 0;
  while ( 1 )
  {
    v11 = *(unsigned __int16 **)(v4 + 8 * v10 + 16);
    v80 = v11;
    if ( v11 )
    {
      v86 = 0;
      if ( *v11 )
      {
        do
        {
          v82 = 1;
          v81 = 0;
          while ( 1 )
          {
            v12 = PnpGetObjectProperty(
                    PiPnpRtlCtx,
                    (int)v11,
                    10,
                    -1,
                    0,
                    (int)DEVPKEY_DeviceId_DriverInfMatches,
                    (int)&v82,
                    (int)v9,
                    v89,
                    (int)&v81,
                    0);
            v7 = v12;
            if ( v12 >= 0 || v12 != -1073741789 )
              break;
            v26 = v81;
            if ( v81 <= v89 )
              goto LABEL_18;
            v89 = v81;
            if ( v9 )
              ExFreePoolWithTag((unsigned int)v9);
            v9 = (unsigned __int16 *)ExAllocatePoolWithTag(1, v26, 1667526736);
            v87 = v9;
            if ( !v9 )
            {
              v7 = -1073741670;
              break;
            }
          }
          if ( v7 == -1073741670 )
            break;
          if ( v7 < 0 )
          {
            if ( v7 == -1073741790 || v7 == -1073740697 )
            {
              if ( !v5 || v5 == -1073741772 )
                v90 = v7;
            }
            else if ( v7 == -1073741772 )
            {
              v90 = -1073741772;
            }
LABEL_18:
            v7 = 0;
            goto LABEL_19;
          }
          if ( v82 == 8210 )
          {
            v15 = *v9;
            v16 = v9;
            v83 = v9;
            if ( v15 )
            {
              while ( 1 )
              {
                v17 = wcschr(v16, 92);
                if ( v17 )
                  break;
LABEL_48:
                v24 = v83;
                v16 = &v24[wcslen(v83) + 1];
                v25 = *v16;
                v83 = v16;
                if ( !v25 )
                  goto LABEL_19;
              }
              v18 = v83;
              v7 = DrvDbSplitDeviceIdDriverInfMatch(v83, 0, 0, v84);
              if ( v7 < 0 )
                goto LABEL_19;
              *v17 = 0;
              v83 = v17 + 1;
              v19 = v94;
              if ( v88 == 2 )
              {
                if ( v84[0] != 3 )
                  goto LABEL_48;
                v19 = v94 | 8;
              }
              switch ( v84[0] )
              {
                case 1:
                  v20 = v86;
                  v21 = 0;
                  break;
                case 2:
                  v21 = 4096;
                  v20 = v86 + (v85 << 8);
                  break;
                case 3:
                  v21 = 0;
                  v20 = 0;
                  break;
                default:
                  goto LABEL_48;
              }
              if ( v20 >= 0x1000 )
                v20 = 4095;
              if ( v84[0] != 3 )
                v21 += v20 + (v88 << 13);
              v7 = PiDevCfgQueryDriverNode(v18, v11, v21, (unsigned __int8)v84[1] << 16, v19, v77);
              if ( v7 < 0 )
              {
                v7 = 0;
                goto LABEL_48;
              }
              v22 = v77[0];
              v23 = *(unsigned __int16 **)(v77[0] + 92);
              if ( v23 )
              {
                while ( *v23 )
                {
                  v27 = 0;
                  v28 = v93;
                  do
                  {
                    v29 = *(unsigned __int16 **)(v28 + 16);
                    if ( v29 )
                    {
                      RtlInitUnicodeString((unsigned int)v97, v23);
                      while ( *v29 )
                      {
                        RtlInitUnicodeString((unsigned int)v96, v29);
                        if ( RtlEqualUnicodeString(v97, v96, 1) )
                        {
                          *(_DWORD *)(v22 + 96) = v23;
                          goto LABEL_80;
                        }
                        v29 += (v96[0] >> 1) + 1;
                      }
                    }
                    ++v27;
                    v28 += 8;
                  }
                  while ( v27 < 3 );
LABEL_80:
                  if ( *(_DWORD *)(v22 + 96) )
                    goto LABEL_84;
                  v23 += wcslen(v23) + 1;
                }
                if ( !*(_DWORD *)(v22 + 96) )
                  goto LABEL_42;
LABEL_84:
                *(_DWORD *)(v22 + 56) |= 0xFFFFu;
              }
LABEL_42:
              if ( v84[0] == 3 )
              {
                v30 = v79;
                *(_DWORD *)v22 = &v78;
                *(_DWORD *)(v22 + 4) = v30;
                if ( *v30 != (int *)&v78 )
                  __fastfail(3u);
                v6 = v91;
                *v30 = (int *)v22;
                v79 = (int **)v22;
                goto LABEL_47;
              }
              v6 = v91;
              if ( v91 )
              {
                v31 = *(unsigned __int16 *)(v22 + 20) >> 1;
                if ( wcsnicmp((int)v91, *(unsigned __int16 **)(v22 + 24), v31)
                  || (v32 = &v6[v31], *v32 != 58)
                  || (v33 = v32 + 1,
                      v34 = *(unsigned __int16 *)(v22 + 36) >> 1,
                      wcsnicmp((int)(v32 + 1), *(unsigned __int16 **)(v22 + 40), v34))
                  || v33[v34] != 44 )
                {
                  v35 = v76;
                  *(_DWORD *)v22 = &v75;
                  *(_DWORD *)(v22 + 4) = v35;
                  if ( *v35 != (int *)&v75 )
                    __fastfail(3u);
                  goto LABEL_93;
                }
              }
              if ( *(_DWORD *)(v22 + 96) )
              {
                v35 = v76;
                *(_DWORD *)v22 = &v75;
                *(_DWORD *)(v22 + 4) = v35;
                if ( *v35 != (int *)&v75 )
                  __fastfail(3u);
              }
              else
              {
                if ( !v3 )
                  goto LABEL_46;
                v36 = *(_DWORD *)(v22 + 100);
                v37 = *(_DWORD *)(v3 + 100);
                if ( (v36 & 4) == 0 )
                {
                  if ( (v37 & 4) == 0 )
                    goto LABEL_100;
                  goto LABEL_114;
                }
                if ( (v37 & 4) == 0 )
                  goto LABEL_112;
LABEL_100:
                if ( (v36 & 2) != 0 )
                {
                  if ( (v37 & 2) == 0 )
                    goto LABEL_114;
LABEL_104:
                  v38 = *(_DWORD *)(v22 + 56);
                  v39 = *(_DWORD *)(v3 + 56);
                  if ( v38 >= v39 )
                  {
                    if ( v38 != v39 )
                      goto LABEL_112;
                    v40 = *(_QWORD *)(v22 + 64);
                    v41 = *(_QWORD *)(v3 + 64);
                    if ( v40 <= v41 )
                    {
                      if ( v40 != v41 )
                        goto LABEL_112;
                      v42 = *(_QWORD *)(v22 + 72);
                      v43 = *(_QWORD *)(v3 + 72);
                      if ( v42 <= v43 && (v42 != v43 || !*(_DWORD *)(v22 + 84) || *(_DWORD *)(v3 + 84)) )
                        goto LABEL_112;
                    }
                  }
LABEL_114:
                  v44 = v76;
                  *(_DWORD *)v3 = &v75;
                  *(_DWORD *)(v3 + 4) = v44;
                  if ( *v44 != (int *)&v75 )
                    __fastfail(3u);
                  *v44 = (int *)v3;
                  v76 = (int **)v3;
                  if ( (*(_DWORD *)(v3 + 100) & 0xC) != 0 )
                  {
                    v45 = *(_DWORD *)(v22 + 100);
                    if ( (v45 & 4) == 0 )
                      *(_DWORD *)(v22 + 100) = v45 | 8;
                  }
LABEL_46:
                  v3 = v22;
LABEL_47:
                  v11 = v80;
                  goto LABEL_48;
                }
                if ( (v37 & 2) == 0 )
                  goto LABEL_104;
LABEL_112:
                v35 = v76;
                *(_DWORD *)v22 = &v75;
                *(_DWORD *)(v22 + 4) = v35;
                if ( *v35 != (int *)&v75 )
                  __fastfail(3u);
              }
LABEL_93:
              *v35 = (int *)v22;
              v76 = (int **)v22;
              goto LABEL_47;
            }
          }
LABEL_19:
          v13 = wcslen(v11);
          v9 = v87;
          v11 += v13 + 1;
          v14 = *v11;
          v5 = v90;
          ++v86;
          v80 = v11;
        }
        while ( v14 );
        v10 = v88;
      }
      if ( v7 < 0 )
        goto LABEL_182;
      v9 = v87;
    }
    v88 = ++v10;
    if ( v10 >= 3 )
      break;
    v4 = v93;
  }
  if ( !v6 )
  {
LABEL_26:
    if ( !v3 )
      goto LABEL_27;
    goto LABEL_127;
  }
  if ( v3 )
  {
LABEL_127:
    while ( 1 )
    {
      v49 = v75;
      if ( v75 == (int *)&v75 )
        break;
      v50 = *(_QWORD *)v75;
      if ( (int **)v75[1] != &v75 || *(int **)(v50 + 4) != v75 )
        __fastfail(3u);
      v75 = (int *)*v75;
      *(_DWORD *)(v50 + 4) = &v75;
      v51 = *(int ***)(v3 + 132);
      *v49 = v3 + 128;
      v49[1] = (int)v51;
      if ( *v51 != (int *)(v3 + 128) )
        __fastfail(3u);
      *v51 = v49;
      *(_DWORD *)(v3 + 132) = v49;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        v52 = v78;
        if ( v78 == (int *)&v78 )
        {
          *v95 = v3;
          v3 = 0;
          goto LABEL_182;
        }
        *(_QWORD *)&v53 = *(_QWORD *)v78;
        if ( (int **)v78[1] != &v78 || (int *)v53[1] != v78 )
          __fastfail(3u);
        v78 = v53;
        v53[1] = (int)&v78;
        if ( !PnpIsNullGuid((int)(v52 + 26)) && !v52[24] )
          break;
LABEL_147:
        PiDevCfgFreeDriverNode();
      }
      if ( v92 )
      {
        v54 = v92;
        for ( i = *v92; i; i = *v54 )
        {
          v56 = *((unsigned __int16 *)v52 + 10) >> 1;
          if ( !wcsnicmp((int)v54, (unsigned __int16 *)v52[6], v56) )
          {
            v57 = &v54[v56];
            if ( *v57 == 58 )
            {
              v58 = v57 + 1;
              v59 = *((unsigned __int16 *)v52 + 18) >> 1;
              if ( !wcsnicmp((int)(v57 + 1), (unsigned __int16 *)v52[10], v59) && v58[v59] == 44 )
                goto LABEL_148;
            }
          }
          v54 += wcslen(v54) + 1;
        }
        goto LABEL_147;
      }
LABEL_148:
      v60 = *(int **)(v3 + 120);
      v61 = v3 + 120;
      while ( v60 != (int *)v61 )
      {
        if ( !memcmp((unsigned int)(v60 + 26), (unsigned int)(v52 + 26), 16)
          && RtlEqualUnicodeString((unsigned __int16 *)v60 + 18, (unsigned __int16 *)v52 + 18, 1) )
        {
          v62 = v52[25];
          v63 = v60[25];
          if ( (v62 & 4) != 0 )
          {
            if ( (v63 & 4) == 0 )
              goto LABEL_177;
LABEL_158:
            if ( (v62 & 2) != 0 )
            {
              if ( (v63 & 2) == 0 )
                goto LABEL_160;
            }
            else if ( (v63 & 2) != 0 )
            {
              goto LABEL_177;
            }
            v67 = v52[14];
            v68 = v60[14];
            if ( v67 >= v68 )
            {
              if ( v67 != v68
                || (v69 = *((_QWORD *)v52 + 8), v70 = *((_QWORD *)v60 + 8), v69 <= v70)
                && (v69 != v70
                 || (v71 = *((_QWORD *)v52 + 9), v72 = *((_QWORD *)v60 + 9), v71 <= v72)
                 && (v71 != v72 || !v52[21] || v60[21])) )
              {
LABEL_177:
                v60 = v52;
                v52 = 0;
LABEL_163:
                if ( v60 )
                  PiDevCfgFreeDriverNode();
                break;
              }
            }
          }
          else if ( (v63 & 4) == 0 )
          {
            goto LABEL_158;
          }
LABEL_160:
          *(_QWORD *)&v64 = *(_QWORD *)v60;
          if ( *(int **)(*v60 + 4) != v60 || *v65 != v60 )
            __fastfail(3u);
          *v65 = v64;
          v64[1] = (int)v65;
          goto LABEL_163;
        }
        v60 = (int *)*v60;
      }
      if ( v52 )
      {
        v66 = *(int ***)(v3 + 124);
        *v52 = v61;
        v52[1] = (int)v66;
        if ( *v66 != (int *)v61 )
          __fastfail(3u);
        *v66 = v52;
        *(_DWORD *)(v3 + 124) = v52;
      }
    }
  }
  v46 = wcschr(v6, 58);
  v47 = v46;
  if ( !v46 || (*v46 = 0, (v48 = wcschr(v46 + 1, 44)) == 0) )
  {
    v7 = -1073741773;
    goto LABEL_182;
  }
  *v48 = 0;
  if ( PiDevCfgQueryDriverNode(v6, v47 + 1, 0, 0, 4, v77) >= 0 )
  {
    v3 = v77[0];
    goto LABEL_26;
  }
LABEL_27:
  if ( v5 )
    v7 = v5;
  else
    v7 = -1073741772;
LABEL_182:
  while ( v75 != (int *)&v75 )
  {
    *(_QWORD *)&v73 = *(_QWORD *)v75;
    if ( (int **)v75[1] != &v75 || (int *)v73[1] != v75 )
      __fastfail(3u);
    v75 = v73;
    v73[1] = (int)&v75;
    PiDevCfgFreeDriverNode();
  }
  while ( v78 != (int *)&v78 )
  {
    *(_QWORD *)&v74 = *(_QWORD *)v78;
    if ( (int **)v78[1] != &v78 || (int *)v74[1] != v78 )
      __fastfail(3u);
    v78 = v74;
    v74[1] = (int)&v78;
    PiDevCfgFreeDriverNode();
  }
  if ( v3 )
    PiDevCfgFreeDriverNode();
  if ( v87 )
    ExFreePoolWithTag((unsigned int)v87);
  return v7;
}
