// _input_s 
 
int input_s(_DWORD *a1, ...)
{
  _DWORD *v1; // r5
  int v2; // r4
  unsigned __int8 *v3; // r8
  int v4; // r10
  int v5; // r1
  int v6; // lr
  int v7; // lr
  int v8; // r0
  int v9; // r0
  int v10; // r5
  int v11; // r6
  int v12; // r7
  int v13; // r1
  int v14; // r10
  int v15; // lr
  int v16; // r2
  int v17; // r2
  char v18; // r3
  int v19; // r2
  int v20; // r9
  int v21; // lr
  _WORD *v22; // r3
  int v23; // r7
  int v24; // r3
  int v25; // r5
  _DWORD *v26; // r10
  int v27; // r0
  int v28; // r3
  int v29; // r1
  int v30; // r0
  _WORD *v31; // r2
  int v32; // r2
  char v33; // r0
  char v34; // r3
  _DWORD *v35; // r9
  int v36; // r6
  int v37; // r0
  int v38; // r9
  char v39; // r1
  _DWORD *v40; // r10
  int v41; // r8
  unsigned int v42; // r0
  int v43; // r1
  char v44; // r3
  bool v45; // cf
  _DWORD *v46; // r3
  _DWORD *v47; // r10
  int v48; // r8
  int v49; // r1
  __int16 v50; // r3
  char v51; // r3
  int v52; // r0
  int v53; // r0
  int v54; // t1
  _DWORD *v55; // r1
  int v56; // r9
  int v58; // [sp+18h] [bp-88h]
  int v59; // [sp+1Ch] [bp-84h] BYREF
  int v60; // [sp+20h] [bp-80h] BYREF
  int v61; // [sp+24h] [bp-7Ch]
  unsigned int v62; // [sp+28h] [bp-78h]
  unsigned int v63; // [sp+2Ch] [bp-74h]
  int v64; // [sp+30h] [bp-70h]
  int v65; // [sp+34h] [bp-6Ch]
  _DWORD *v66; // [sp+38h] [bp-68h]
  int v67; // [sp+3Ch] [bp-64h]
  int v68; // [sp+40h] [bp-60h]
  int v69; // [sp+44h] [bp-5Ch]
  int v70; // [sp+48h] [bp-58h]
  int v71; // [sp+4Ch] [bp-54h]
  int v72; // [sp+50h] [bp-50h] BYREF
  int v73; // [sp+54h] [bp-4Ch]
  _DWORD *v74; // [sp+58h] [bp-48h]
  unsigned __int8 *v75; // [sp+5Ch] [bp-44h]
  int v76; // [sp+60h] [bp-40h]
  int v77; // [sp+64h] [bp-3Ch]
  _WORD *v78; // [sp+68h] [bp-38h] BYREF
  int v79; // [sp+6Ch] [bp-34h]
  int v80; // [sp+70h] [bp-30h]
  int v81; // [sp+74h] [bp-2Ch]
  unsigned int v82; // [sp+78h] [bp-28h]
  unsigned int v83; // [sp+7Ch] [bp-24h]
  unsigned __int8 *varg_r1; // [sp+ACh] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]
  va_list varg_r3; // [sp+B4h] [bp+14h] BYREF

  va_start(varg_r3, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(varg_r3, unsigned __int8 *);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v1 = a1;
  v2 = 0;
  v66 = a1;
  v61 = 0;
  v59 = 0;
  v76 = 0;
  v77 = varg_r2;
  v3 = varg_r1;
  if ( !varg_r1 )
  {
    PopPoCoalescinCallback();
    return -1;
  }
  if ( !a1 )
  {
    v4 = -1;
    goto LABEL_229;
  }
  v5 = *varg_r1;
  v67 = 0;
  v6 = 0;
  v58 = 0;
  v60 = 0;
  v4 = 0;
  v71 = 0;
  v72 = 0;
  if ( v5 )
  {
    v62 = v83;
    v63 = v82;
    while ( 1 )
    {
      if ( (pctype[v5] & 8) != 0 )
      {
        v7 = v6 - 1;
        while ( 1 )
        {
          v58 = v7 + 1;
          v60 = v7 + 1;
          v8 = sub_4FEB60(v1);
          if ( v8 == -1 )
            break;
          ++v7;
          if ( (pctype[(unsigned __int8)v8] & 8) == 0 )
          {
            ungetc_nolock(v8, v1);
            goto LABEL_12;
          }
        }
        do
LABEL_12:
          ++v3;
        while ( (pctype[*v3] & 8) != 0 );
        goto LABEL_213;
      }
      if ( v5 != 37 )
        goto LABEL_209;
      if ( v3[1] == 37 )
      {
        ++v3;
LABEL_209:
        v58 = v6 + 1;
        v60 = v6 + 1;
        v53 = sub_4FEB60(v1);
        v54 = *v3++;
        v2 = v53;
        v61 = v53;
        v59 = v53;
        if ( v54 == v53 )
          goto LABEL_210;
        if ( v53 == -1 )
          goto LABEL_230;
        v55 = v1;
LABEL_225:
        ungetc_nolock(v2, v55);
        goto LABEL_226;
      }
      v9 = 0;
      v10 = 0;
      v11 = 0;
      v12 = 1;
      v13 = 0;
      v64 = 0;
      v65 = 0;
      v69 = 0;
      v70 = 0;
      v68 = 0;
      v80 = 0;
      v81 = 0;
      v79 = 0;
      v14 = 0;
      v73 = 1;
      v15 = 0;
      do
      {
        v16 = *++v3;
        varg_r1 = v3;
        if ( (pctype[v16] & 4) != 0 )
        {
          v9 = v16 + 10 * v9 - 48;
          ++v10;
          continue;
        }
        if ( v16 > 78 )
        {
          if ( v16 == 104 )
          {
            v12 = (char)(v12 - 1);
            v18 = v11 - 1;
          }
          else
          {
            if ( v16 == 108 )
            {
              if ( v3[1] == 108 )
              {
                ++v3;
                goto LABEL_29;
              }
              v12 = (char)(v12 + 1);
            }
            else if ( v16 != 119 )
            {
              goto LABEL_43;
            }
            v18 = v11 + 1;
          }
          v11 = v18;
        }
        else
        {
          switch ( v16 )
          {
            case 'N':
              continue;
            case '*':
              v14 = (char)(v14 + 1);
              continue;
            case 'F':
              continue;
          }
          if ( v16 != 73 )
          {
            if ( v16 == 76 )
            {
              v12 = (char)(v12 + 1);
              continue;
            }
LABEL_43:
            v13 = (char)(v13 + 1);
            continue;
          }
          v17 = v3[1];
          if ( v17 == 54 && v3[2] == 52 )
          {
            v3 += 2;
LABEL_29:
            v62 = 0;
            v63 = 0;
            varg_r1 = v3;
            ++v15;
            continue;
          }
          if ( v17 == 51 && v3[2] == 50 )
          {
            v3 += 2;
            varg_r1 = v3;
            continue;
          }
          if ( v17 != 100 && v17 != 105 && v17 != 111 && v17 != 120 && v17 != 88 )
            goto LABEL_43;
        }
      }
      while ( !v13 );
      v68 = v10;
      v69 = v14;
      v19 = v14;
      v2 = v61;
      v20 = v81;
      v4 = v71;
      v80 = v15;
      v21 = v58;
      v73 = v12;
      v65 = v9;
      v75 = v3;
      if ( v19 )
      {
        v22 = 0;
      }
      else
      {
        v76 = v77;
        v77 += (-v77 & 3) + 4;
        v22 = *(_WORD **)(v77 - 4);
      }
      v23 = 0;
      v78 = v22;
      v74 = v22;
      if ( !v11 )
      {
        v24 = *v3;
        if ( v24 == 83 || v24 == 67 )
          v11 = 1;
        else
          v11 = -1;
      }
      v25 = *v3 | 0x20;
      v82 = v25;
      if ( v25 != 110 )
      {
        if ( v25 == 99 || v25 == 123 )
        {
          v60 = ++v58;
          v2 = sub_4FEB60(v66);
          v61 = v2;
        }
        else
        {
          v26 = v66;
          do
          {
            v58 = v21 + 1;
            v60 = v21 + 1;
            v27 = sub_4FEB60(v26);
            v2 = v27;
            v61 = v27;
            if ( v27 == -1 )
              break;
            ++v21;
          }
          while ( (pctype[(unsigned __int8)v27] & 8) != 0 );
          v20 = v81;
          v25 = v82;
          v4 = v71;
        }
        v59 = v2;
        if ( v2 == -1 )
          goto LABEL_230;
        v21 = v58;
        v19 = v69;
      }
      v28 = v68;
      v29 = v65;
      if ( v68 && !v65 )
      {
        if ( v2 == -1 )
          goto LABEL_230;
        v55 = v66;
        goto LABEL_225;
      }
      if ( !v19 && (v25 == 99 || v25 == 115 || v25 == 123) )
      {
        v30 = (-v76 & 3) + v76 + 4;
        v20 = *(_DWORD *)((-v30 & 3) + v30);
        v31 = *(_WORD **)((-v76 & 3) + v76);
        v76 = v30;
        v77 = (-v30 & 3) + v30 + 4;
        v74 = v31;
        v78 = v31;
        if ( !v20 )
        {
          v56 = 0;
          if ( v11 <= 0 )
            *(_BYTE *)v31 = 0;
          else
            *v31 = 0;
          goto LABEL_227;
        }
        v28 = v68;
        v19 = v69;
      }
      else
      {
        v30 = v76;
      }
      if ( v25 > 112 )
      {
        if ( v25 == 115 )
        {
          v33 = 32;
          goto LABEL_195;
        }
        if ( v25 != 117 )
        {
          if ( v25 != 120 )
          {
            if ( v25 != 123 )
              goto LABEL_99;
            v33 = 64;
LABEL_195:
            if ( v28 )
LABEL_196:
              v33 |= 1u;
            if ( v11 > 0 )
              v33 |= 2u;
            if ( v19 )
              v33 |= 4u;
            if ( v25 == 123 )
            {
              v52 = sub_4FEA68(v33, (unsigned __int8 **)varg_r1a, &v59, &v60, &v78, v29, (int)v66, v20, &v72);
              v3 = varg_r1;
            }
            else
            {
              v52 = sub_4FE914(v33, 0, &v59, &v60, &v78, v29, (int)v66, v20, &v72);
            }
            v2 = v59;
            v4 = v72;
            if ( !v52 )
            {
              v61 = v59;
              v71 = v72;
              v58 = v60;
              goto LABEL_206;
            }
            goto LABEL_226;
          }
LABEL_90:
          if ( v2 == 45 )
          {
            v79 = 1;
LABEL_104:
            if ( !--v65 && v28 )
            {
              v23 = 1;
              goto LABEL_107;
            }
            v35 = v66;
            v58 = v21 + 1;
            v60 = v21 + 1;
            v2 = sub_4FEB60(v66);
            v61 = v2;
            v59 = v2;
          }
          else
          {
            if ( v2 == 43 )
              goto LABEL_104;
LABEL_107:
            v35 = v66;
          }
          v36 = v58;
          if ( v2 != 48 )
            goto LABEL_130;
          v36 = v58 + 1;
          v58 = v36;
          v60 = v36;
          v37 = sub_4FEB60(v35);
          v2 = v37;
          v61 = v37;
          v59 = v37;
          if ( (char)v37 != 120 && (char)v37 != 88 )
          {
            v70 = 1;
            if ( v25 != 120 )
            {
              v38 = v65;
              if ( v68 )
              {
                v38 = v65 - 1;
                if ( v65 == 1 )
                  ++v23;
              }
              v25 = 111;
              goto LABEL_131;
            }
            v58 = --v36;
            v60 = v36;
            if ( v37 != -1 )
              ungetc_nolock(v37, v35);
            v2 = 48;
            v61 = 48;
            v59 = 48;
LABEL_130:
            v38 = v65;
            goto LABEL_131;
          }
          v58 = ++v36;
          v60 = v36;
          v2 = sub_4FEB60(v35);
          v38 = v65;
          v61 = v2;
          v59 = v2;
          if ( v68 )
          {
            v38 = v65 - 2;
            if ( v65 - 2 < 1 )
              ++v23;
          }
          v25 = 120;
LABEL_131:
          v39 = v23;
          if ( v80 )
          {
            if ( v23 )
            {
LABEL_157:
              if ( v79 )
              {
                v45 = v63 == 0;
                v63 = -v63;
                v62 = -(v62 + !v45);
              }
              goto LABEL_159;
            }
            v40 = v66;
            v41 = v68;
            while ( 2 )
            {
              if ( v25 == 120 || v25 == 112 )
              {
                if ( (pctype[(unsigned __int8)v2] & 0x80) != 0 )
                {
                  v2 = (char)v2;
                  v42 = (v63 >> 28) | (16 * v62);
                  v43 = 16 * v63;
                  v62 = v42;
                  v63 *= 16;
                  if ( (pctype[(unsigned __int8)v2] & 4) == 0 )
                    v2 = ((char)v2 & 0xFFFFFFDF) - 7;
                  v59 = v2;
                  goto LABEL_148;
                }
              }
              else if ( (pctype[(unsigned __int8)v2] & 4) != 0 )
              {
                if ( v25 == 111 )
                {
                  v42 = v62;
                  if ( v2 < 56 )
                  {
                    v42 = (v63 >> 29) | (8 * v62);
                    v43 = 8 * v63;
                    goto LABEL_140;
                  }
LABEL_147:
                  v44 = v39 + 1;
                  v43 = v63;
                  v23 = v44;
                }
                else
                {
                  v43 = 10 * v63;
                  v42 = (10 * __PAIR64__(v62, v63)) >> 32;
LABEL_140:
                  v62 = v42;
                  v63 = v43;
                }
LABEL_148:
                if ( v23 )
                {
                  v60 = --v36;
                  if ( v2 != -1 )
                    ungetc_nolock(v2, v40);
                }
                else
                {
                  ++v70;
                  v62 = (__PAIR64__(v42, v43) + v2 - 48) >> 32;
                  v63 = v43 + v2 - 48;
                  if ( !v41 || (--v38, v38) )
                  {
                    v60 = ++v36;
                    v2 = sub_4FEB60(v40);
                    v59 = v2;
                  }
                  else
                  {
                    v23 = 1;
                  }
                }
                v39 = v23;
                if ( v23 )
                {
                  v3 = v75;
                  v4 = v71;
                  v61 = v2;
                  v58 = v36;
                  goto LABEL_157;
                }
                continue;
              }
              break;
            }
            v42 = v62;
            goto LABEL_147;
          }
          if ( v23 )
            goto LABEL_189;
          v47 = v66;
          v48 = v68;
          while ( 2 )
          {
            if ( v25 == 120 || v25 == 112 )
            {
              if ( (pctype[(unsigned __int8)v2] & 0x80) == 0 )
                goto LABEL_179;
              v2 = (char)v2;
              v50 = pctype[(unsigned __int8)v2];
              v49 = 16 * v64;
              v64 *= 16;
              if ( (v50 & 4) == 0 )
                v2 = ((char)v2 & 0xFFFFFFDF) - 7;
              v59 = v2;
            }
            else
            {
              if ( (pctype[(unsigned __int8)v2] & 4) == 0 )
                goto LABEL_179;
              if ( v25 == 111 )
              {
                if ( v2 < 56 )
                {
                  v49 = 8 * v64;
                  goto LABEL_173;
                }
LABEL_179:
                v51 = v39 + 1;
                v49 = v64;
                v23 = v51;
              }
              else
              {
                v49 = 10 * v64;
LABEL_173:
                v64 = v49;
              }
            }
            if ( v23 )
            {
              v60 = --v36;
              if ( v2 != -1 )
                ungetc_nolock(v2, v47);
            }
            else
            {
              ++v70;
              v64 = v49 + v2 - 48;
              if ( !v48 || (--v38, v38) )
              {
                v60 = ++v36;
                v2 = sub_4FEB60(v47);
                v59 = v2;
              }
              else
              {
                v23 = 1;
              }
            }
            v39 = v23;
            if ( v23 )
            {
              v3 = v75;
              v4 = v71;
              v61 = v2;
              v58 = v36;
LABEL_189:
              if ( v79 )
              {
                v32 = -v64;
LABEL_160:
                if ( v70 )
                {
                  if ( !v69 )
                  {
                    v71 = ++v4;
                    v72 = v4;
                    goto LABEL_163;
                  }
                  goto LABEL_206;
                }
LABEL_226:
                v56 = 0;
LABEL_227:
                if ( v2 != -1 )
                {
                  if ( v56 == 1 )
LABEL_229:
                    PopPoCoalescinCallback();
                  return v4;
                }
LABEL_230:
                if ( v4 || v67 )
                  return v4;
                return -1;
              }
LABEL_159:
              v32 = v64;
              goto LABEL_160;
            }
            continue;
          }
        }
LABEL_85:
        if ( v2 == 45 )
        {
          v79 = 1;
          goto LABEL_125;
        }
        if ( v2 == 43 )
        {
LABEL_125:
          if ( --v65 || !v28 )
          {
            v58 = v21 + 1;
            v60 = v21 + 1;
            v2 = sub_4FEB60(v66);
            v61 = v2;
            v59 = v2;
          }
          else
          {
            v23 = 1;
          }
        }
        v36 = v58;
        goto LABEL_130;
      }
      switch ( v25 )
      {
        case 'p':
          v73 = 1;
          goto LABEL_85;
        case 'c':
          v33 = 16;
          if ( !v28 )
            v29 = v65 + 1;
          goto LABEL_196;
        case 'd':
          goto LABEL_85;
        case 'i':
          v25 = 100;
          goto LABEL_90;
        case 'n':
          v32 = v21;
          if ( !v69 )
          {
LABEL_163:
            if ( v80 )
            {
              v46 = v74;
              *v74 = v63;
              v46[1] = v62;
            }
            else if ( v73 )
            {
              *v74 = v32;
            }
            else
            {
              *(_WORD *)v74 = v32;
            }
          }
LABEL_206:
          v34 = v67;
          break;
        case 'o':
          goto LABEL_85;
        default:
LABEL_99:
          if ( *v3 != v2 )
          {
            if ( v2 != -1 )
              ungetc_nolock(v2, v66);
            v56 = 1;
            goto LABEL_227;
          }
          v34 = v67 - 1;
          if ( !v19 )
            v77 = v30;
          break;
      }
      v1 = v66;
      v67 = (char)(v34 + 1);
      ++v3;
LABEL_210:
      if ( v2 == -1 && (*v3 != 37 || v3[1] != 110) )
        goto LABEL_230;
LABEL_213:
      v5 = *v3;
      if ( !*v3 )
        goto LABEL_226;
      v6 = v58;
    }
  }
  return v4;
}
