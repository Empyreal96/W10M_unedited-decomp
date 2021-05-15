// _woutput_l 
 
int __fastcall woutput_l(int a1, unsigned __int16 *a2, __int64 a3)
{
  int v3; // r7
  int v5; // r1
  int v6; // r4
  int v7; // lr
  int v8; // r6
  int v9; // r0
  int i; // r10
  int v11; // r8
  int v12; // r9
  int v13; // r3
  int v14; // lr
  int v15; // r2
  __int16 v16; // r3
  unsigned __int16 **v17; // r3
  unsigned __int16 *v18; // r3
  unsigned int v19; // r2
  int *v20; // r3
  int v21; // r3
  int v22; // r5
  int v23; // r3
  int v24; // r7
  int v25; // r0
  int *v26; // r3
  _WORD *j; // r1
  __int16 *v28; // r3
  unsigned __int16 *v29; // r3
  int *v30; // r3
  int *v31; // r3
  bool v32; // cf
  int v33; // r7
  char v34; // r6
  char *k; // r9
  int v37; // r1
  _WORD **v38; // r3
  _WORD *v39; // r5
  int v40; // r7
  int v41; // r8
  int v42; // r5
  int v43; // r9
  int v44; // r5
  int v45; // r5
  int v46; // r9
  _BYTE *v47; // r7
  int v48; // r5
  int v49; // r0
  int v50; // r6
  int v52; // [sp+8h] [bp-468h]
  unsigned __int64 v53; // [sp+Ch] [bp-464h]
  int v54; // [sp+14h] [bp-45Ch] BYREF
  int v55; // [sp+18h] [bp-458h]
  int v56; // [sp+1Ch] [bp-454h]
  unsigned __int16 *v57; // [sp+20h] [bp-450h]
  int v58; // [sp+24h] [bp-44Ch]
  int v59; // [sp+28h] [bp-448h]
  const __int16 *v60; // [sp+30h] [bp-440h]
  int v61; // [sp+34h] [bp-43Ch]
  int v62; // [sp+38h] [bp-438h]
  __int16 v63[2]; // [sp+3Ch] [bp-434h] BYREF
  unsigned __int16 v64; // [sp+40h] [bp-430h] BYREF
  char v65[2]; // [sp+42h] [bp-42Eh] BYREF
  int v66; // [sp+44h] [bp-42Ch]
  int v67; // [sp+48h] [bp-428h]
  __int16 v68[255]; // [sp+50h] [bp-420h] BYREF
  char v69[545]; // [sp+24Fh] [bp-221h] BYREF

  v3 = HIDWORD(a3);
  v5 = a1;
  LODWORD(a3) = 0;
  v6 = 0;
  v55 = a1;
  v56 = 0;
  v66 = 0;
  v62 = 0;
  v53 = __PAIR64__(HIDWORD(a3), 0);
  v7 = 0;
  v58 = 0;
  v59 = 0;
  if ( a1 && a2 )
  {
    v9 = *a2;
    HIDWORD(a3) = 0;
    v52 = 0;
    v54 = 0;
    i = 0;
    v11 = 0;
    if ( !v9 )
      return HIDWORD(a3);
    v12 = v67;
    v8 = -1;
    v60 = (const __int16 *)v67;
    while ( 1 )
    {
      v57 = ++a2;
      if ( a3 < 0 )
        return HIDWORD(a3);
      if ( (unsigned int)v9 < 0x20 || (unsigned int)v9 > 0x78 )
        v13 = 0;
      else
        v13 = *((_BYTE *)&_lookuptable[-8] + v9) & 0xF;
      v67 = *((char *)&_lookuptable[2 * v13] + v11) >> 4;
      switch ( v67 )
      {
        case 0:
          goto LABEL_55;
        case 1:
          v6 = 0;
          LODWORD(a3) = -1;
          v7 = 0;
          v56 = 0;
          v62 = 0;
          v58 = 0;
          v59 = 0;
          LODWORD(v53) = -1;
          goto LABEL_198;
        case 2:
          switch ( v9 )
          {
            case ' ':
              v6 |= 2u;
              goto LABEL_198;
            case '#':
              v6 |= 0x80u;
              goto LABEL_198;
            case '+':
              v6 |= 1u;
              goto LABEL_198;
            case '-':
              v6 |= 4u;
              goto LABEL_198;
          }
          HIDWORD(a3) = v52;
          if ( v9 == 48 )
            v6 |= 8u;
          goto LABEL_199;
        case 3:
          if ( v9 != 42 )
          {
            v62 = v9 + 10 * v62 - 48;
            goto LABEL_198;
          }
          v3 += (-v3 & 3) + 4;
          v14 = *(_DWORD *)(v3 - 4);
          HIDWORD(a3) = v52;
          HIDWORD(v53) = v3;
          v62 = v14;
          if ( v14 < 0 )
          {
            v62 = -v14;
            v6 |= 4u;
          }
          goto LABEL_57;
        case 4:
          LODWORD(a3) = 0;
          goto LABEL_28;
        case 5:
          if ( v9 == 42 )
          {
            v3 += (-v3 & 3) + 4;
            LODWORD(a3) = *(_DWORD *)(v3 - 4);
            HIDWORD(a3) = v52;
            v53 = __PAIR64__(v3, a3);
            if ( (int)a3 < 0 )
            {
              LODWORD(a3) = -1;
              LODWORD(v53) = -1;
            }
            goto LABEL_199;
          }
          LODWORD(a3) = v9 + 10 * a3 - 48;
LABEL_28:
          LODWORD(v53) = a3;
          goto LABEL_198;
        case 6:
          if ( v9 != 73 )
          {
            if ( v9 == 104 )
            {
              v6 |= 0x20u;
              goto LABEL_198;
            }
            if ( v9 == 108 )
            {
              HIDWORD(a3) = v52;
              if ( *a2 == 108 )
              {
                ++a2;
                v6 |= 0x1000u;
              }
              else
              {
                v6 |= 0x10u;
              }
            }
            else
            {
              HIDWORD(a3) = v52;
              if ( v9 == 119 )
                v6 |= 0x800u;
            }
            goto LABEL_199;
          }
          v15 = *a2;
          if ( v15 == 54 && a2[1] == 52 )
          {
            a2 += 2;
            v6 |= 0x8000u;
            goto LABEL_197;
          }
          if ( v15 == 51 && a2[1] == 50 )
          {
            a2 += 2;
            v6 &= 0xFFFF7FFF;
            goto LABEL_197;
          }
          if ( v15 != 100 && v15 != 105 && v15 != 111 && v15 != 117 && v15 != 120 && v15 != 88 )
          {
            v67 = 0;
LABEL_55:
            v58 = 1;
            sub_4FBA18(v9, v5, &v54);
            HIDWORD(a3) = v54;
            v52 = v54;
            goto LABEL_56;
          }
          goto LABEL_197;
        case 7:
          if ( v9 > 105 )
          {
            if ( v9 != 110 )
            {
              if ( v9 == 111 )
              {
                v22 = 8;
                if ( (v6 & 0x80) != 0 )
                  v6 |= 0x200u;
                goto LABEL_98;
              }
              if ( v9 == 112 )
              {
                LODWORD(a3) = 8;
                LODWORD(v53) = 8;
LABEL_117:
                v23 = 7;
LABEL_118:
                v66 = v23;
                v22 = 16;
                if ( (v6 & 0x80) != 0 )
                {
                  v63[1] = v23 + 81;
                  v63[0] = 48;
                  v59 = 2;
                }
                goto LABEL_98;
              }
              if ( v9 != 115 )
              {
                if ( v9 == 117 )
                {
                  v22 = 10;
                  goto LABEL_98;
                }
                if ( v9 != 120 )
                  goto LABEL_66;
                v23 = 39;
                goto LABEL_118;
              }
              goto LABEL_100;
            }
            v38 = (_WORD **)((-v3 & 3) + v3);
            v3 = (int)(v38 + 1);
            v39 = *v38;
            HIDWORD(v53) = v38 + 1;
            if ( !get_printf_count_output() )
              goto LABEL_202;
            if ( (v6 & 0x20) != 0 )
              *v39 = v52;
            else
              *(_DWORD *)v39 = v52;
            v7 = 1;
            a2 = v57;
            v56 = 1;
          }
          else
          {
            switch ( v9 )
            {
              case 'i':
                goto LABEL_89;
              case 'C':
                if ( (v6 & 0x830) == 0 )
                  v6 |= 0x20u;
LABEL_83:
                v20 = (int *)((-v3 & 3) + v3);
                v3 = (int)(v20 + 1);
                v21 = *v20;
                v58 = 1;
                v64 = v21;
                HIDWORD(v53) = v3;
                if ( (v6 & 0x20) != 0 )
                {
                  v65[0] = v21;
                  v65[1] = 0;
                  if ( safecrt_mbtowc(v68, v65, _mb_cur_max, (int)&_mb_cur_max) >= 0 )
                  {
                    v7 = v56;
                  }
                  else
                  {
                    v7 = 1;
                    v56 = 1;
                  }
                }
                else
                {
                  v68[0] = v21;
                }
                v12 = (int)v68;
                v60 = v68;
                i = 1;
                goto LABEL_66;
              case 'S':
                if ( (v6 & 0x830) == 0 )
                  v6 |= 0x20u;
LABEL_100:
                if ( (_DWORD)a3 == -1 )
                  LODWORD(a3) = 0x7FFFFFFF;
                v26 = (int *)((-v3 & 3) + v3);
                v3 = (int)(v26 + 1);
                v12 = *v26;
                HIDWORD(v53) = v26 + 1;
                v60 = (const __int16 *)*v26;
                if ( (v6 & 0x20) != 0 )
                {
                  if ( !v12 )
                  {
                    v12 = (int)"(null)";
                    v60 = (const __int16 *)"(null)";
                  }
                  for ( i = 0; i < (int)a3; ++i )
                  {
                    if ( !*(_BYTE *)(v12 + i) )
                      break;
                  }
                }
                else
                {
                  if ( !v12 )
                  {
                    v12 = (int)L"(null)";
                    v60 = L"(null)";
                  }
                  v58 = 1;
                  for ( j = (_WORD *)v12; (_DWORD)a3; ++j )
                  {
                    LODWORD(a3) = a3 - 1;
                    if ( !*j )
                      break;
                  }
                  i = ((int)j - v12) >> 1;
                }
                goto LABEL_66;
              case 'X':
                goto LABEL_117;
            }
            if ( v9 != 90 )
            {
              if ( v9 == 99 )
                goto LABEL_83;
              if ( v9 != 100 )
                goto LABEL_66;
LABEL_89:
              v6 |= 0x40u;
              v22 = 10;
LABEL_98:
              if ( (v6 & 0x8000) != 0 || (v6 & 0x1000) != 0 )
              {
                v24 = (-v3 & 7) + v3 + 8;
                HIDWORD(a3) = *(_DWORD *)(v24 - 4);
                v25 = *(_DWORD *)(v24 - 8);
                goto LABEL_131;
              }
              if ( (v6 & 0x20) != 0 )
              {
                if ( (v6 & 0x40) != 0 )
                {
                  v28 = (__int16 *)((-v3 & 3) + v3);
                  v24 = (int)(v28 + 2);
                  v25 = *v28;
                  HIDWORD(a3) = v25 >> 31;
                  goto LABEL_131;
                }
                v29 = (unsigned __int16 *)((-v3 & 3) + v3);
                v24 = (int)(v29 + 2);
                v25 = *v29;
LABEL_130:
                HIDWORD(a3) = 0;
              }
              else
              {
                if ( (v6 & 0x40) == 0 )
                {
                  v31 = (int *)((-v3 & 3) + v3);
                  v24 = (int)(v31 + 1);
                  v25 = *v31;
                  goto LABEL_130;
                }
                v30 = (int *)((-v3 & 3) + v3);
                v24 = (int)(v30 + 1);
                v25 = *v30;
                HIDWORD(a3) = *v30 >> 31;
              }
LABEL_131:
              HIDWORD(v53) = v24;
              if ( (v6 & 0x40) != 0 && a3 < 0 )
              {
                v32 = v25 == 0;
                v25 = -v25;
                HIDWORD(a3) = -(HIDWORD(a3) + !v32);
                v6 |= 0x100u;
              }
              if ( (v6 & 0x9000) == 0 )
                HIDWORD(a3) = 0;
              if ( (int)a3 >= 0 )
              {
                v6 &= 0xFFFFFFF7;
                if ( (int)a3 > 512 )
                  LODWORD(v53) = 512;
              }
              else
              {
                LODWORD(v53) = 1;
              }
              if ( !(v25 | HIDWORD(a3)) )
                v59 = 0;
              v33 = v53;
              v34 = v66;
              for ( k = v69; v33-- > 0 || v25 | HIDWORD(a3); --k )
              {
                LODWORD(a3) = v25;
                v25 = _rt_udiv64((unsigned int)v22, a3);
                LODWORD(a3) = a3 + 48;
                if ( (int)a3 > 57 )
                  LOBYTE(a3) = a3 + v34;
                v61 = HIDWORD(a3);
                *k = a3;
                HIDWORD(a3) = v37;
              }
              i = v69 - k;
              v12 = (int)(k + 1);
              LODWORD(v53) = v33;
              v3 = HIDWORD(v53);
              v60 = (const __int16 *)v12;
              v8 = -1;
              if ( (v6 & 0x200) != 0 && (!i || *(_BYTE *)v12 != 48) )
              {
                v60 = (const __int16 *)--v12;
                *(_BYTE *)v12 = 48;
                ++i;
              }
              v7 = v56;
              a2 = v57;
              goto LABEL_66;
            }
            v17 = (unsigned __int16 **)((-v3 & 3) + v3);
            v3 = (int)(v17 + 1);
            v18 = *v17;
            HIDWORD(v53) = v3;
            if ( v18 && (v12 = *((_DWORD *)v18 + 1), (v60 = (const __int16 *)v12) != 0) )
            {
              v19 = *v18;
              if ( v18[1] < v19 )
                goto LABEL_202;
              if ( (v6 & 0x800) != 0 )
              {
                if ( (v19 & 1) != 0 || (v12 & 1) != 0 )
                {
LABEL_202:
                  PopPoCoalescinCallback();
                  return v8;
                }
                v58 = 1;
                i = v19 >> 1;
              }
              else
              {
                v58 = 0;
                v60 = (const __int16 *)v12;
                i = v19;
              }
            }
            else
            {
              v12 = (int)"(null)";
              i = 6;
              v60 = (const __int16 *)"(null)";
            }
          }
LABEL_66:
          if ( v7 )
            goto LABEL_196;
          if ( (v6 & 0x40) != 0 )
          {
            if ( (v6 & 0x100) != 0 )
            {
              v16 = 45;
            }
            else if ( (v6 & 1) != 0 )
            {
              v16 = 43;
            }
            else
            {
              if ( (v6 & 2) == 0 )
                goto LABEL_165;
              v16 = 32;
            }
            v63[0] = v16;
            v59 = 1;
          }
LABEL_165:
          v40 = v59;
          v41 = v62 - i - v59;
          if ( (v6 & 0xC) == 0 )
          {
            v42 = v62 - i - v59;
            if ( v41 > 0 )
            {
              v43 = v55;
              do
              {
                --v42;
                sub_4FBA18(32, v43, &v54);
              }
              while ( v54 != -1 && v42 > 0 );
              v12 = (int)v60;
            }
          }
          v44 = v55;
          sub_4FBA58(v63, v40, v55, &v54);
          if ( (v6 & 8) != 0 && (v6 & 4) == 0 )
          {
            v45 = v41;
            if ( v41 > 0 )
            {
              v46 = v55;
              do
              {
                --v45;
                sub_4FBA18(48, v46, &v54);
              }
              while ( v54 != -1 && v45 > 0 );
              v12 = (int)v60;
            }
            v44 = v55;
          }
          if ( v58 || i <= 0 )
          {
            sub_4FBA58(v12, i, v44, &v54);
LABEL_189:
            HIDWORD(a3) = v54;
          }
          else
          {
            v47 = (_BYTE *)v12;
            v48 = i;
            while ( 1 )
            {
              --v48;
              v49 = safecrt_mbtowc(&v64, v47, _mb_cur_max, (int)&_mb_cur_max);
              v50 = v49;
              if ( v49 == 2 )
                --v48;
              if ( v49 <= 0 )
                break;
              sub_4FBA18(v64, v55, &v54);
              v47 += v50;
              if ( v48 <= 0 )
              {
                v44 = v55;
                v8 = -1;
                goto LABEL_189;
              }
            }
            v8 = -1;
            v44 = v55;
            HIDWORD(a3) = -1;
            v54 = -1;
          }
          v52 = HIDWORD(a3);
          if ( a3 < 0 || (v6 & 4) == 0 || v41 <= 0 )
          {
            v3 = HIDWORD(v53);
            a2 = v57;
LABEL_56:
            LODWORD(a3) = v53;
            v5 = v55;
LABEL_57:
            v7 = v56;
            goto LABEL_199;
          }
          do
          {
            --v41;
            sub_4FBA18(32, v44, &v54);
            v52 = v54;
          }
          while ( v54 != -1 && v41 > 0 );
          v12 = (int)v60;
          v3 = HIDWORD(v53);
          v7 = v56;
          a2 = v57;
LABEL_196:
          v5 = v55;
LABEL_197:
          LODWORD(a3) = v53;
LABEL_198:
          HIDWORD(a3) = v52;
LABEL_199:
          v9 = *a2;
          if ( !*a2 )
            return HIDWORD(a3);
          v11 = v67;
          break;
        default:
          goto LABEL_198;
      }
    }
  }
  PopPoCoalescinCallback();
  return -1;
}
