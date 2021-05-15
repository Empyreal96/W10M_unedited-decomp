// _woutput_s 
 
int __fastcall woutput_s(int a1, unsigned __int16 *a2, int a3)
{
  int v5; // r1
  signed __int64 v6; // r2
  int v7; // r5
  int v8; // r9
  int v9; // r0
  int i; // r10
  int v11; // r8
  int v12; // r7
  int v13; // r3
  int v14; // lr
  int v15; // r2
  __int16 v16; // r3
  unsigned __int16 **v17; // r3
  unsigned __int16 *v18; // r3
  unsigned int v19; // r2
  int *v20; // r3
  int v21; // r3
  int v22; // r4
  int v23; // r3
  int *v24; // r3
  _WORD *j; // r1
  int v26; // r6
  int v27; // r0
  __int16 *v28; // r3
  unsigned __int16 *v29; // r3
  int *v30; // r3
  int *v31; // r3
  bool v32; // cf
  int v33; // r6
  char v34; // r9
  char *k; // r7
  int v37; // r1
  int v38; // r2
  int v39; // r8
  int v40; // r4
  __int16 *v41; // r6
  int v42; // r4
  int v43; // t1
  int v44; // r4
  int v45; // r4
  int v46; // r0
  int v47; // r6
  int v48; // r4
  unsigned __int16 *v49; // r6
  int v50; // t1
  int v52; // [sp+8h] [bp-460h]
  int v53; // [sp+Ch] [bp-45Ch]
  signed __int64 v54; // [sp+10h] [bp-458h] BYREF
  int *v55; // [sp+18h] [bp-450h]
  int v56; // [sp+1Ch] [bp-44Ch]
  const __int16 *v57; // [sp+20h] [bp-448h]
  int v58; // [sp+24h] [bp-444h]
  int v59; // [sp+28h] [bp-440h]
  unsigned __int16 *v60; // [sp+2Ch] [bp-43Ch]
  int v61; // [sp+30h] [bp-438h]
  int v62; // [sp+34h] [bp-434h]
  __int16 v63[2]; // [sp+38h] [bp-430h] BYREF
  char v64[2]; // [sp+3Ch] [bp-42Ch] BYREF
  unsigned __int16 v65; // [sp+3Eh] [bp-42Ah] BYREF
  int v66; // [sp+40h] [bp-428h]
  int v67; // [sp+44h] [bp-424h]
  __int16 v68[255]; // [sp+48h] [bp-420h] BYREF
  char v69[545]; // [sp+247h] [bp-221h] BYREF

  v5 = a1;
  LODWORD(v6) = 0;
  v7 = 0;
  v61 = 0;
  v62 = a1;
  LODWORD(v54) = 0;
  v55 = (int *)a3;
  v56 = 0;
  v59 = 0;
  v66 = 0;
  v67 = 0;
  if ( a1 && a2 )
  {
    v9 = *a2;
    HIDWORD(v6) = 0;
    v52 = 0;
    HIDWORD(v54) = 0;
    i = 0;
    v11 = 0;
    if ( !v9 )
      goto LABEL_209;
    v12 = v66;
    v8 = -1;
    v57 = (const __int16 *)v66;
    while ( 1 )
    {
      v60 = ++a2;
      if ( v6 < 0 )
        break;
      if ( (unsigned int)v9 < 0x20 || (unsigned int)v9 > 0x78 )
        v13 = 0;
      else
        v13 = *((_BYTE *)&_lookuptable_s[-8] + v9) & 0xF;
      v11 = *((unsigned __int8 *)_lookuptable_s + 9 * v13 + v11) >> 4;
      v53 = v11;
      if ( v11 == 8 )
        goto LABEL_211;
      switch ( v11 )
      {
        case 0:
          goto LABEL_56;
        case 1:
          v7 = 0;
          LODWORD(v6) = -1;
          v66 = 0;
          v61 = 0;
          v56 = 0;
          LODWORD(v54) = -1;
          v59 = 0;
          goto LABEL_204;
        case 2:
          switch ( v9 )
          {
            case ' ':
              v7 |= 2u;
              goto LABEL_204;
            case '#':
              v7 |= 0x80u;
              goto LABEL_204;
            case '+':
              v7 |= 1u;
              goto LABEL_204;
            case '-':
              v7 |= 4u;
              goto LABEL_204;
          }
          HIDWORD(v6) = v52;
          if ( v9 == 48 )
            v7 |= 8u;
          goto LABEL_206;
        case 3:
          if ( v9 != 42 )
          {
            v61 = v9 + 10 * v61 - 48;
            goto LABEL_204;
          }
          a3 += (-a3 & 3) + 4;
          v14 = *(_DWORD *)(a3 - 4);
          HIDWORD(v6) = v52;
          v55 = (int *)a3;
          v61 = v14;
          if ( v14 < 0 )
          {
            v61 = -v14;
            v7 |= 4u;
          }
          goto LABEL_206;
        case 4:
          LODWORD(v6) = 0;
          goto LABEL_29;
        case 5:
          if ( v9 == 42 )
          {
            a3 += (-a3 & 3) + 4;
            LODWORD(v6) = *(_DWORD *)(a3 - 4);
            HIDWORD(v6) = v52;
            v55 = (int *)a3;
            LODWORD(v54) = v6;
            if ( (int)v6 < 0 )
            {
              LODWORD(v6) = -1;
              LODWORD(v54) = -1;
            }
            goto LABEL_206;
          }
          LODWORD(v6) = v9 + 10 * v6 - 48;
LABEL_29:
          LODWORD(v54) = v6;
          goto LABEL_204;
        case 6:
          if ( v9 != 73 )
          {
            if ( v9 == 104 )
            {
              v7 |= 0x20u;
              goto LABEL_204;
            }
            if ( v9 == 108 )
            {
              HIDWORD(v6) = v52;
              if ( *a2 == 108 )
              {
                ++a2;
                v7 |= 0x1000u;
              }
              else
              {
                v7 |= 0x10u;
              }
            }
            else
            {
              HIDWORD(v6) = v52;
              if ( v9 == 119 )
                v7 |= 0x800u;
            }
            goto LABEL_206;
          }
          v15 = *a2;
          if ( v15 == 54 && a2[1] == 52 )
          {
            a2 += 2;
            v7 |= 0x8000u;
            goto LABEL_203;
          }
          if ( v15 == 51 && a2[1] == 50 )
          {
            a2 += 2;
            v7 &= 0xFFFF7FFF;
            goto LABEL_203;
          }
          if ( v15 != 100 && v15 != 105 && v15 != 111 && v15 != 117 && v15 != 120 && v15 != 88 )
          {
            v11 = 0;
LABEL_56:
            v59 = 1;
            sub_4FE8C0(v9, v5, (char *)&v54 + 4);
            v6 = v54;
            v52 = HIDWORD(v54);
            goto LABEL_206;
          }
          goto LABEL_203;
        case 7:
          if ( v9 > 105 )
          {
            switch ( v9 )
            {
              case 'n':
                goto LABEL_211;
              case 'o':
                v22 = 8;
                if ( (v7 & 0x80) != 0 )
                  v7 |= 0x200u;
                goto LABEL_118;
              case 'p':
                LODWORD(v6) = 8;
                LODWORD(v54) = 8;
LABEL_113:
                v23 = 7;
LABEL_114:
                v67 = v23;
                v22 = 16;
                if ( (v7 & 0x80) != 0 )
                {
                  v63[0] = 48;
                  v56 = 2;
                  v63[1] = v23 + 81;
                }
                goto LABEL_118;
            }
            if ( v9 != 115 )
            {
              if ( v9 == 117 )
              {
                v22 = 10;
                goto LABEL_118;
              }
              if ( v9 != 120 )
                goto LABEL_65;
              v23 = 39;
              goto LABEL_114;
            }
            goto LABEL_96;
          }
          switch ( v9 )
          {
            case 'i':
              goto LABEL_87;
            case 'C':
              if ( (v7 & 0x830) == 0 )
                v7 |= 0x20u;
LABEL_82:
              v20 = (int *)((-a3 & 3) + a3);
              a3 = (int)(v20 + 1);
              v21 = *v20;
              v59 = 1;
              v65 = v21;
              v55 = (int *)a3;
              if ( (v7 & 0x20) != 0 )
              {
                v64[0] = v21;
                v64[1] = 0;
                if ( safecrt_mbtowc(v68, v64, _mb_cur_max, (int)&_mb_cur_max) < 0 )
                  v66 = 1;
              }
              else
              {
                v68[0] = v21;
              }
              v12 = (int)v68;
              v57 = v68;
              i = 1;
              goto LABEL_65;
            case 'S':
              if ( (v7 & 0x830) == 0 )
                v7 |= 0x20u;
LABEL_96:
              if ( (_DWORD)v6 == -1 )
                LODWORD(v6) = 0x7FFFFFFF;
              v24 = (int *)((-a3 & 3) + a3);
              a3 = (int)(v24 + 1);
              v12 = *v24;
              v55 = v24 + 1;
              v57 = (const __int16 *)v12;
              if ( (v7 & 0x20) != 0 )
              {
                if ( !v12 )
                {
                  v12 = (int)"(null)";
                  v57 = (const __int16 *)"(null)";
                }
                for ( i = 0; i < (int)v6; ++i )
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
                  v57 = L"(null)";
                }
                v59 = 1;
                for ( j = (_WORD *)v12; (_DWORD)v6; ++j )
                {
                  LODWORD(v6) = v6 - 1;
                  if ( !*j )
                    break;
                }
                i = ((int)j - v12) >> 1;
              }
              goto LABEL_65;
            case 'X':
              goto LABEL_113;
          }
          if ( v9 != 90 )
          {
            if ( v9 != 99 )
            {
              if ( v9 != 100 )
                goto LABEL_65;
LABEL_87:
              v7 |= 0x40u;
              v22 = 10;
LABEL_118:
              if ( (v7 & 0x8000) != 0 || (v7 & 0x1000) != 0 )
              {
                v26 = (-a3 & 7) + a3 + 8;
                HIDWORD(v6) = *(_DWORD *)(v26 - 4);
                v27 = *(_DWORD *)(v26 - 8);
                goto LABEL_129;
              }
              if ( (v7 & 0x20) != 0 )
              {
                if ( (v7 & 0x40) != 0 )
                {
                  v28 = (__int16 *)((-a3 & 3) + a3);
                  v26 = (int)(v28 + 2);
                  v27 = *v28;
                  HIDWORD(v6) = v27 >> 31;
                  goto LABEL_129;
                }
                v29 = (unsigned __int16 *)((-a3 & 3) + a3);
                v26 = (int)(v29 + 2);
                v27 = *v29;
LABEL_128:
                HIDWORD(v6) = 0;
              }
              else
              {
                if ( (v7 & 0x40) == 0 )
                {
                  v31 = (int *)((-a3 & 3) + a3);
                  v26 = (int)(v31 + 1);
                  v27 = *v31;
                  goto LABEL_128;
                }
                v30 = (int *)((-a3 & 3) + a3);
                v26 = (int)(v30 + 1);
                v27 = *v30;
                HIDWORD(v6) = *v30 >> 31;
              }
LABEL_129:
              v55 = (int *)v26;
              if ( (v7 & 0x40) != 0 && v6 < 0 )
              {
                v32 = v27 == 0;
                v27 = -v27;
                HIDWORD(v6) = -(HIDWORD(v6) + !v32);
                v7 |= 0x100u;
              }
              if ( (v7 & 0x9000) == 0 )
                HIDWORD(v6) = 0;
              if ( (int)v6 >= 0 )
              {
                v7 &= 0xFFFFFFF7;
                if ( (int)v6 > 512 )
                  LODWORD(v54) = 512;
              }
              else
              {
                LODWORD(v54) = 1;
              }
              if ( !(v27 | HIDWORD(v6)) )
                v56 = 0;
              v33 = v54;
              v34 = v67;
              for ( k = v69; v33-- > 0 || v27 | HIDWORD(v6); --k )
              {
                LODWORD(v6) = v27;
                v27 = _rt_udiv64((unsigned int)v22, v6);
                LODWORD(v6) = v6 + 48;
                if ( (int)v6 > 57 )
                  LOBYTE(v6) = v6 + v34;
                v58 = HIDWORD(v6);
                *k = v6;
                HIDWORD(v6) = v37;
              }
              i = v69 - k;
              v12 = (int)(k + 1);
              LODWORD(v54) = v33;
              a3 = (int)v55;
              v57 = (const __int16 *)v12;
              v8 = -1;
              if ( (v7 & 0x200) != 0 && (!i || *(_BYTE *)v12 != 48) )
              {
                *(_BYTE *)--v12 = 48;
                v57 = (const __int16 *)v12;
                ++i;
              }
              a2 = v60;
              goto LABEL_65;
            }
            goto LABEL_82;
          }
          v17 = (unsigned __int16 **)((-a3 & 3) + a3);
          a3 = (int)(v17 + 1);
          v18 = *v17;
          v55 = (int *)a3;
          if ( v18 && (v12 = *((_DWORD *)v18 + 1), (v57 = (const __int16 *)v12) != 0) )
          {
            v19 = *v18;
            if ( v18[1] < v19 )
              goto LABEL_211;
            if ( (v7 & 0x800) != 0 )
            {
              if ( (v19 & 1) != 0 || (v12 & 1) != 0 )
                goto LABEL_211;
              v59 = 1;
              i = v19 >> 1;
            }
            else
            {
              v59 = 0;
              v57 = (const __int16 *)v12;
              i = v19;
            }
          }
          else
          {
            v12 = (int)"(null)";
            i = 6;
            v57 = (const __int16 *)"(null)";
          }
LABEL_65:
          if ( v66 )
          {
            v5 = v62;
            goto LABEL_203;
          }
          if ( (v7 & 0x40) == 0 )
            goto LABEL_158;
          if ( (v7 & 0x100) != 0 )
          {
            v16 = 45;
LABEL_155:
            v38 = 1;
            v56 = 1;
            v63[0] = v16;
            goto LABEL_159;
          }
          if ( (v7 & 1) != 0 )
          {
            v16 = 43;
            goto LABEL_155;
          }
          if ( (v7 & 2) != 0 )
          {
            v16 = 32;
            goto LABEL_155;
          }
LABEL_158:
          v38 = v56;
LABEL_159:
          v5 = v62;
          v39 = v61 - i - v38;
          if ( (v7 & 0xC) == 0 )
          {
            v40 = v61 - i - v38;
            if ( v39 > 0 )
            {
              do
              {
                --v40;
                sub_4FE8C0(32, v5, (char *)&v54 + 4);
                v52 = HIDWORD(v54);
              }
              while ( HIDWORD(v54) != -1 && v40 > 0 );
              v38 = v56;
              v12 = (int)v57;
            }
          }
          v41 = v63;
          v42 = v38;
          if ( (*(_DWORD *)(v5 + 12) & 0x40) == 0 || *(_DWORD *)(v5 + 8) )
          {
            if ( v38 > 0 )
            {
              do
              {
                v43 = (unsigned __int16)*v41++;
                --v42;
                sub_4FE8C0(v43, v5, (char *)&v54 + 4);
                v52 = HIDWORD(v54);
              }
              while ( HIDWORD(v54) != -1 && v42 > 0 );
              v12 = (int)v57;
            }
          }
          else
          {
            v52 += v38;
            HIDWORD(v54) = v52;
          }
          if ( (v7 & 8) != 0 && (v7 & 4) == 0 )
          {
            v44 = v39;
            if ( v39 > 0 )
            {
              do
              {
                --v44;
                sub_4FE8C0(48, v5, (char *)&v54 + 4);
                v52 = HIDWORD(v54);
              }
              while ( HIDWORD(v54) != -1 && v44 > 0 );
              v12 = (int)v57;
            }
          }
          if ( v59 || i <= 0 )
          {
            v48 = i;
            v49 = (unsigned __int16 *)v12;
            if ( (*(_DWORD *)(v5 + 12) & 0x40) == 0 || *(_DWORD *)(v5 + 8) )
            {
              if ( i > 0 )
              {
                do
                {
                  v50 = *v49++;
                  --v48;
                  sub_4FE8C0(v50, v5, (char *)&v54 + 4);
                  v52 = HIDWORD(v54);
                }
                while ( HIDWORD(v54) != -1 && v48 > 0 );
                v12 = (int)v57;
              }
              HIDWORD(v6) = v52;
            }
            else
            {
              HIDWORD(v6) = v52 + i;
              v52 = HIDWORD(v6);
              HIDWORD(v54) = HIDWORD(v6);
            }
          }
          else
          {
            v45 = i;
            while ( 1 )
            {
              --v45;
              v46 = safecrt_mbtowc(&v65, (_BYTE *)v12, _mb_cur_max, (int)&_mb_cur_max);
              v47 = v46;
              v5 = v62;
              if ( v46 == 2 )
                --v45;
              if ( v46 <= 0 )
                break;
              sub_4FE8C0(v65, v62, (char *)&v54 + 4);
              v12 += v47;
              if ( v45 <= 0 )
              {
                HIDWORD(v6) = HIDWORD(v54);
                goto LABEL_186;
              }
            }
            HIDWORD(v6) = -1;
            HIDWORD(v54) = -1;
LABEL_186:
            v12 = (int)v57;
            v52 = HIDWORD(v6);
          }
          if ( v6 < 0 || (v7 & 4) == 0 || v39 <= 0 )
          {
            a3 = (int)v55;
            a2 = v60;
            LODWORD(v6) = v54;
            goto LABEL_205;
          }
          do
          {
            --v39;
            sub_4FE8C0(32, v5, (char *)&v54 + 4);
            v52 = HIDWORD(v54);
          }
          while ( HIDWORD(v54) != -1 && v39 > 0 );
          v12 = (int)v57;
          a3 = (int)v55;
          a2 = v60;
LABEL_203:
          LODWORD(v6) = v54;
LABEL_204:
          HIDWORD(v6) = v52;
LABEL_205:
          v11 = v53;
LABEL_206:
          v9 = *a2;
          if ( !*a2 )
            goto LABEL_207;
          break;
        default:
          goto LABEL_204;
      }
    }
LABEL_207:
    if ( v11 && v11 != 7 )
LABEL_211:
      PopPoCoalescinCallback();
    else
LABEL_209:
      v8 = HIDWORD(v6);
  }
  else
  {
    PopPoCoalescinCallback();
    v8 = -1;
  }
  return v8;
}
