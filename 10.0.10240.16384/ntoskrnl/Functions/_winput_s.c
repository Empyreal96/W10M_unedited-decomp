// _winput_s 
 
int winput_s(int a1, ...)
{
  unsigned __int16 *v1; // r8
  int v2; // r7
  unsigned int v3; // r4
  int v4; // r1
  int v5; // r10
  unsigned int v6; // r0
  int v7; // r2
  int *v8; // r6
  unsigned int v9; // r0
  unsigned int v10; // r5
  int v11; // r5
  int v12; // r2
  int v13; // r7
  int v14; // r0
  int v15; // r6
  int v16; // lr
  int v17; // r1
  int v18; // r2
  int v19; // r9
  int v20; // r1
  _DWORD *v21; // r3
  char v22; // r3
  int v23; // r7
  int v24; // r3
  int v25; // r5
  int *v26; // r9
  int v27; // r10
  unsigned int v28; // r0
  char *v29; // r1
  int v30; // r9
  _BYTE *v31; // r2
  int v32; // r3
  int v33; // r2
  char v34; // r3
  char v35; // r3
  int v36; // r0
  int v37; // r9
  int *v38; // r6
  int *v39; // r6
  int v40; // r0
  char *v41; // r9
  int *v42; // r6
  char v43; // r1
  int v44; // r10
  int v45; // r8
  unsigned int v46; // r0
  int v47; // r1
  __int16 v48; // r3
  char v49; // r3
  bool v50; // cf
  _DWORD *v51; // r3
  int v52; // r10
  int v53; // r8
  int v54; // r1
  __int16 v55; // r3
  char v56; // r3
  int v57; // r0
  int v58; // r0
  int v59; // t1
  int v60; // r1
  int v62; // [sp+14h] [bp-8Ch]
  int *v63; // [sp+18h] [bp-88h]
  int v64; // [sp+1Ch] [bp-84h] BYREF
  int v65; // [sp+20h] [bp-80h]
  int *v66; // [sp+24h] [bp-7Ch] BYREF
  unsigned int v67; // [sp+28h] [bp-78h]
  int v68; // [sp+2Ch] [bp-74h]
  unsigned int v69; // [sp+30h] [bp-70h]
  char *v70; // [sp+34h] [bp-6Ch]
  unsigned int v71; // [sp+38h] [bp-68h]
  unsigned int v72; // [sp+3Ch] [bp-64h]
  int v73; // [sp+40h] [bp-60h]
  int v74; // [sp+44h] [bp-5Ch]
  int v75; // [sp+48h] [bp-58h]
  int v76; // [sp+4Ch] [bp-54h]
  int v77; // [sp+50h] [bp-50h]
  int v78; // [sp+54h] [bp-4Ch] BYREF
  _DWORD *v79; // [sp+58h] [bp-48h]
  int v80; // [sp+5Ch] [bp-44h]
  unsigned __int16 *v81; // [sp+60h] [bp-40h]
  int v82; // [sp+64h] [bp-3Ch]
  _BYTE *v83; // [sp+68h] [bp-38h] BYREF
  int v84; // [sp+6Ch] [bp-34h]
  int v85; // [sp+70h] [bp-30h]
  int v86; // [sp+74h] [bp-2Ch]
  unsigned int v87; // [sp+78h] [bp-28h]
  unsigned int v88; // [sp+7Ch] [bp-24h]
  unsigned __int16 *varg_r1; // [sp+ACh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]
  va_list varg_r3; // [sp+B4h] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, unsigned __int16 *);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = varg_r1;
  v2 = a1;
  v3 = 0;
  v4 = 0;
  v73 = a1;
  v71 = 0;
  LOWORD(v64) = 0;
  v84 = 0;
  v82 = varg_r2;
  if ( !varg_r1 )
  {
    PopPoCoalescinCallback();
    return -1;
  }
  if ( !a1 )
  {
    v5 = -1;
    goto LABEL_240;
  }
  v6 = *varg_r1;
  v7 = 0;
  v8 = 0;
  v65 = 0;
  v66 = 0;
  v63 = 0;
  v5 = 0;
  v77 = 0;
  v78 = 0;
  if ( !v6 )
    goto LABEL_223;
  v69 = v88;
  v67 = v87;
LABEL_7:
  if ( iswctype(v6, 8) )
  {
    v8 = (int *)((char *)v8 - 1);
    do
    {
      v8 = (int *)((char *)v8 + 1);
      v66 = v8;
      v9 = fgetwc_nolock(v2);
      v10 = v9;
    }
    while ( v9 != 0xFFFF && iswctype(v9, 8) );
    v63 = v8;
    if ( v10 != 0xFFFF )
      ungetwc_nolock(v10, v2);
    do
      ++v1;
    while ( iswctype(*v1, 8) );
    goto LABEL_220;
  }
  if ( *v1 != 37 )
    goto LABEL_215;
  if ( v1[1] == 37 )
  {
    ++v1;
LABEL_215:
    v8 = (int *)((char *)v8 + 1);
    v63 = v8;
    v66 = v8;
    v58 = fgetwc_nolock(v2);
    v59 = *v1++;
    v3 = v58;
    v71 = v58;
    LOWORD(v64) = v58;
    if ( v59 == v58 )
    {
      v7 = v65;
      goto LABEL_217;
    }
    if ( v58 == 0xFFFF )
      goto LABEL_221;
    v60 = v2;
    goto LABEL_229;
  }
  v11 = 0;
  v12 = 0;
  v13 = 1;
  v14 = 0;
  v15 = 0;
  v72 = 0;
  v74 = 0;
  v75 = 0;
  v16 = 0;
  v76 = 0;
  v70 = 0;
  v85 = 0;
  v86 = 0;
  v68 = 0;
  v80 = 1;
  do
  {
    v17 = *++v1;
    varg_r1 = v1;
    if ( (v17 & 0xFF00) == 0 )
    {
      v12 = v68;
      if ( (pctype[(unsigned __int8)v17] & 4) != 0 )
      {
        v11 = v17 + 10 * v11 - 48;
        ++v16;
        continue;
      }
    }
    if ( v17 > 78 )
    {
      if ( v17 == 104 )
      {
        v13 = (char)(v13 - 1);
        v22 = v15 - 1;
      }
      else
      {
        if ( v17 == 108 )
        {
          if ( v1[1] == 108 )
          {
            varg_r1 = ++v1;
            ++v75;
            v67 = 0;
            v69 = 0;
            continue;
          }
          v13 = (char)(v13 + 1);
        }
        else if ( v17 != 119 )
        {
          goto LABEL_48;
        }
        v22 = v15 + 1;
      }
      v15 = v22;
    }
    else
    {
      if ( v17 == 78 )
        continue;
      if ( v17 != 42 )
      {
        switch ( v17 )
        {
          case 'F':
            continue;
          case 'I':
            v18 = v1[1];
            if ( v18 == 54 && v1[2] == 52 )
            {
              v1 += 2;
              varg_r1 = v1;
              ++v75;
              v67 = 0;
              v69 = 0;
            }
            else if ( v18 == 51 && v1[2] == 50 )
            {
              v1 += 2;
              varg_r1 = v1;
            }
            else if ( v18 != 100 && v18 != 105 && v18 != 111 && v18 != 120 && v18 != 88 )
            {
              goto LABEL_48;
            }
            break;
          case 'L':
            v13 = (char)(v13 + 1);
            continue;
          default:
LABEL_48:
            v14 = (char)(v14 + 1);
            break;
        }
        v12 = v68;
        continue;
      }
      v12 = (char)(v12 + 1);
      v68 = v12;
    }
  }
  while ( !v14 );
  v3 = v71;
  v19 = v86;
  v5 = v77;
  v80 = v13;
  v81 = v1;
  v76 = v16;
  v70 = (char *)v11;
  if ( v12 )
  {
    v21 = 0;
  }
  else
  {
    v20 = v82;
    v82 += (-v82 & 3) + 4;
    v21 = *(_DWORD **)(v82 - 4);
    v84 = v20;
  }
  v23 = 0;
  v83 = v21;
  v79 = v21;
  if ( !v15 )
  {
    v24 = *v1;
    if ( v24 == 83 || v24 == 67 )
      v15 = -1;
    else
      v15 = 1;
  }
  v25 = *v1 | 0x20;
  v87 = v25;
  if ( v25 == 110 )
  {
LABEL_71:
    v29 = v70;
    if ( !v16 || v70 )
    {
      if ( !v12 && (v25 == 99 || v25 == 115 || v25 == 123) )
      {
        v30 = (-v84 & 3) + v84 + 4;
        v31 = *(_BYTE **)((-v84 & 3) + v84);
        v32 = (-v30 & 3) + v30 + 4;
        v83 = v31;
        v84 = v30;
        v19 = *(_DWORD *)((-v30 & 3) + v30);
        v79 = v31;
        v82 = v32;
        if ( !v19 )
        {
          if ( v15 <= 0 )
            *v31 = 0;
          else
            *(_WORD *)v31 = 0;
          v7 = v65;
          goto LABEL_222;
        }
        v12 = v68;
      }
      if ( v25 > 112 )
      {
        switch ( v25 )
        {
          case 's':
            v36 = 32;
            break;
          case 'u':
            goto LABEL_86;
          case 'x':
            goto LABEL_93;
          case '{':
            v36 = 64;
            break;
          default:
            goto LABEL_102;
        }
        if ( !v16 )
        {
LABEL_205:
          if ( v15 > 0 )
            v36 |= 2u;
          if ( v12 )
            v36 |= 4u;
          if ( v25 == 123 )
          {
            sub_4FF548(
              v36,
              (int)varg_r1a,
              (int)&v64,
              (int)&v66,
              (int)&v83,
              (int)v29,
              v73,
              v19,
              (int)&v78,
              v62,
              (int)v63,
              v64,
              v65,
              v66,
              v67,
              v68,
              v69,
              v70);
            v1 = varg_r1;
          }
          else
          {
            v57 = sub_4FF3AC(v36, 0, (unsigned __int16 *)&v64, &v66, (int *)&v83, (int)v29, v73, v19, &v78);
          }
          v3 = (unsigned __int16)v64;
          v5 = v78;
          if ( !v57 )
          {
            v8 = v66;
            v71 = (unsigned __int16)v64;
            v77 = v78;
            v63 = v66;
            goto LABEL_201;
          }
          goto LABEL_221;
        }
      }
      else
      {
        if ( v25 == 112 )
        {
          v80 = 1;
          goto LABEL_86;
        }
        if ( v25 != 99 )
        {
          if ( v25 == 100 )
          {
LABEL_86:
            if ( v3 == 45 )
            {
              v85 = 1;
              goto LABEL_141;
            }
            if ( v3 == 43 )
            {
LABEL_141:
              if ( --v70 || !v16 )
              {
                v42 = (int *)((char *)v63 + 1);
                v63 = v42;
                v66 = v42;
                v3 = fgetwc_nolock(v73);
                v41 = v70;
                v71 = v3;
                LOWORD(v64) = v3;
                goto LABEL_125;
              }
              v23 = 1;
            }
LABEL_123:
            v41 = v70;
LABEL_124:
            v42 = v63;
LABEL_125:
            v43 = v23;
            if ( v75 )
            {
              if ( v23 )
              {
LABEL_162:
                if ( v85 )
                {
                  v50 = v67 == 0;
                  v67 = -v67;
                  v69 = -(v69 + !v50);
                }
                goto LABEL_164;
              }
              v44 = v73;
              v45 = v76;
              while ( v25 != 120 && v25 != 112 )
              {
                if ( (v3 & 0xFF00) != 0 || (pctype[(unsigned __int8)v3] & 4) == 0 )
                  goto LABEL_151;
                if ( v25 == 111 )
                {
                  v46 = v69;
                  if ( v3 >= 0x38 )
                    goto LABEL_152;
                  v46 = (v67 >> 29) | (8 * v69);
                  v47 = 8 * v67;
                }
                else
                {
                  v47 = 10 * v67;
                  v46 = (10 * __PAIR64__(v69, v67)) >> 32;
                }
                v67 = v47;
                v69 = v46;
LABEL_153:
                if ( v23 )
                {
                  v42 = (int *)((char *)v42 - 1);
                  v66 = v42;
                  if ( v3 != 0xFFFF )
                    ungetwc_nolock(v3, v44);
                }
                else
                {
                  ++v74;
                  v69 = (__PAIR64__(v46, v47) + (int)(v3 - 48)) >> 32;
                  v67 = v47 + v3 - 48;
                  if ( !v45 || (--v41, v41) )
                  {
                    v42 = (int *)((char *)v42 + 1);
                    v66 = v42;
                    v3 = fgetwc_nolock(v44);
                    LOWORD(v64) = v3;
                  }
                  else
                  {
                    v23 = 1;
                  }
                }
                v43 = v23;
                if ( v23 )
                {
                  v1 = v81;
                  v5 = v77;
                  v63 = v42;
                  v71 = v3;
                  goto LABEL_162;
                }
              }
              if ( (v3 & 0xFF00) == 0 && (pctype[(unsigned __int8)v3] & 0x80) != 0 )
              {
                v46 = (v67 >> 28) | (16 * v69);
                v47 = 16 * v67;
                v67 *= 16;
                v48 = pctype[(unsigned __int8)v3];
                v69 = v46;
                if ( (v48 & 4) == 0 )
                  LOWORD(v3) = (v3 & 0xFFDF) - 7;
                v3 = (unsigned __int16)v3;
                LOWORD(v64) = v3;
                goto LABEL_153;
              }
LABEL_151:
              v46 = v69;
LABEL_152:
              v49 = v43 + 1;
              v47 = v67;
              v23 = v49;
              goto LABEL_153;
            }
            if ( v23 )
              goto LABEL_196;
            v52 = v73;
            v53 = v76;
            while ( v25 != 120 && v25 != 112 )
            {
              if ( (v3 & 0xFF00) != 0 || (pctype[(unsigned __int8)v3] & 4) == 0 )
                goto LABEL_186;
              if ( v25 == 111 )
              {
                if ( v3 >= 0x38 )
                  goto LABEL_186;
                v54 = 8 * v72;
              }
              else
              {
                v54 = 10 * v72;
              }
              v72 = v54;
LABEL_187:
              if ( v23 )
              {
                v42 = (int *)((char *)v42 - 1);
                v66 = v42;
                if ( v3 != 0xFFFF )
                  ungetwc_nolock(v3, v52);
              }
              else
              {
                ++v74;
                v72 = v3 + v54 - 48;
                if ( !v53 || (--v41, v41) )
                {
                  v42 = (int *)((char *)v42 + 1);
                  v66 = v42;
                  v3 = fgetwc_nolock(v52);
                  LOWORD(v64) = v3;
                }
                else
                {
                  v23 = 1;
                }
              }
              v43 = v23;
              if ( v23 )
              {
                v1 = v81;
                v5 = v77;
                v63 = v42;
                v71 = v3;
LABEL_196:
                if ( v85 )
                {
                  v33 = -v72;
LABEL_165:
                  if ( !v74 )
                    goto LABEL_221;
                  if ( v68 )
                    goto LABEL_89;
                  v77 = ++v5;
                  v78 = v5;
LABEL_168:
                  if ( v75 )
                  {
                    v51 = v79;
                    *v79 = v67;
                    v51[1] = v69;
                    goto LABEL_89;
                  }
                  v8 = v63;
                  if ( v80 )
                    *v79 = v33;
                  else
                    *(_WORD *)v79 = v33;
LABEL_201:
                  v34 = v65;
LABEL_91:
                  v35 = v34 + 1;
                  v7 = v35;
                  v2 = v73;
                  v65 = v35;
                  ++v1;
LABEL_217:
                  if ( v3 == 0xFFFF && (*v1 != 37 || v1[1] != 110) )
                    goto LABEL_222;
LABEL_220:
                  v6 = *v1;
                  if ( !*v1 )
                    goto LABEL_221;
                  goto LABEL_7;
                }
LABEL_164:
                v33 = v72;
                goto LABEL_165;
              }
            }
            if ( (v3 & 0xFF00) == 0 && (pctype[(unsigned __int8)v3] & 0x80) != 0 )
            {
              v55 = pctype[(unsigned __int8)v3];
              v54 = 16 * v72;
              v72 *= 16;
              if ( (v55 & 4) == 0 )
                LOWORD(v3) = (v3 & 0xFFDF) - 7;
              v3 = (unsigned __int16)v3;
              LOWORD(v64) = v3;
              goto LABEL_187;
            }
LABEL_186:
            v56 = v43 + 1;
            v54 = v72;
            v23 = v56;
            goto LABEL_187;
          }
          if ( v25 != 105 )
          {
            if ( v25 == 110 )
            {
              v33 = (int)v63;
              if ( !v68 )
                goto LABEL_168;
LABEL_89:
              v34 = v65;
              goto LABEL_90;
            }
            if ( v25 == 111 )
              goto LABEL_86;
LABEL_102:
            if ( *v1 != v3 )
            {
              if ( v3 != 0xFFFF )
                ungetwc_nolock(v3, v73);
              v7 = v65;
              v4 = 1;
              goto LABEL_223;
            }
            v34 = v65 - 1;
            if ( !v12 )
              v82 = v84;
LABEL_90:
            v8 = v63;
            goto LABEL_91;
          }
          v25 = 100;
LABEL_93:
          if ( v3 == 45 )
          {
            v85 = 1;
          }
          else if ( v3 != 43 )
          {
            goto LABEL_110;
          }
          if ( --v70 || !v16 )
          {
            v37 = v73;
            v38 = (int *)((char *)v63 + 1);
            v63 = v38;
            v66 = v38;
            v3 = fgetwc_nolock(v73);
            v71 = v3;
            LOWORD(v64) = v3;
LABEL_111:
            if ( v3 == 48 )
            {
              v39 = (int *)((char *)v38 + 1);
              v63 = v39;
              v66 = v39;
              v40 = fgetwc_nolock(v37);
              v3 = v40;
              v71 = v40;
              LOWORD(v64) = v40;
              if ( v40 == 120 || v40 == 88 )
              {
                v63 = (int *)((char *)v39 + 1);
                v66 = (int *)((char *)v39 + 1);
                v3 = fgetwc_nolock(v37);
                v41 = v70;
                v71 = v3;
                LOWORD(v64) = v3;
                if ( v76 )
                {
                  v41 = v70 - 2;
                  if ( (int)(v70 - 2) < 1 )
                    ++v23;
                }
                v25 = 120;
                goto LABEL_124;
              }
              v74 = 1;
              if ( v25 != 120 )
              {
                v41 = v70;
                if ( v76 )
                {
                  v41 = v70 - 1;
                  if ( v70 == (char *)1 )
                    ++v23;
                }
                v25 = 111;
                goto LABEL_124;
              }
              v63 = (int *)((char *)v39 - 1);
              v66 = (int *)((char *)v39 - 1);
              if ( v40 != 0xFFFF )
                ungetwc_nolock(v40, v37);
              v3 = 48;
              v71 = 48;
              LOWORD(v64) = 48;
            }
            goto LABEL_123;
          }
          v23 = 1;
LABEL_110:
          v37 = v73;
          v38 = v63;
          goto LABEL_111;
        }
        v36 = 16;
        if ( !v16 )
          v29 = v70 + 1;
      }
      v36 |= 1u;
      goto LABEL_205;
    }
    if ( v3 == 0xFFFF )
      goto LABEL_221;
    v60 = v73;
LABEL_229:
    ungetwc_nolock(v3, v60);
    goto LABEL_221;
  }
  if ( v25 == 99 || v25 == 123 )
  {
    v63 = (int *)((char *)v63 + 1);
    v66 = v63;
    v3 = fgetwc_nolock(v73);
    v71 = v3;
  }
  else
  {
    v26 = v63;
    v27 = v73;
    do
    {
      v26 = (int *)((char *)v26 + 1);
      v66 = v26;
      v28 = fgetwc_nolock(v27);
      v3 = v28;
      v71 = v28;
    }
    while ( v28 != 0xFFFF && iswctype(v28, 8) );
    v25 = v87;
    v5 = v77;
    v63 = v26;
    v19 = v86;
  }
  LOWORD(v64) = v3;
  if ( v3 != 0xFFFF )
  {
    v16 = v76;
    v12 = v68;
    goto LABEL_71;
  }
LABEL_221:
  v7 = v65;
LABEL_222:
  v4 = 0;
LABEL_223:
  if ( v3 != 0xFFFF )
  {
    if ( v4 != 1 )
      return v5;
LABEL_240:
    PopPoCoalescinCallback();
    return v5;
  }
  if ( !v5 && !v7 )
    v5 = 0;
  return v5;
}
