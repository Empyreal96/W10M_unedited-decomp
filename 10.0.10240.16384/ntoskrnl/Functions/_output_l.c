// _output_l 
 
int __fastcall output_l(int a1, char *a2, int a3, int a4)
{
  int v5; // r7
  int v6; // r4
  char *v7; // r5
  int v8; // r9
  int v9; // r0
  int v10; // r6
  int v11; // r1
  signed __int64 v12; // r2
  int v13; // r8
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int *v17; // r3
  int v18; // r2
  int v19; // r5
  unsigned __int16 *v20; // r3
  unsigned int v21; // r2
  int v22; // r2
  int v23; // r3
  int v24; // r0
  int v25; // r3
  int v26; // r3
  int v27; // r0
  int *v28; // r3
  _WORD *j; // r1
  _BYTE *k; // r1
  bool v31; // cf
  char v32; // r9
  char *i; // r8
  int v35; // r1
  _WORD **v36; // r3
  _WORD *v37; // r5
  char v38; // r3
  int v39; // r7
  int v40; // r5
  int v41; // r5
  int v42; // r5
  int v43; // r6
  int v46; // [sp+Ch] [bp-264h] BYREF
  int v47; // [sp+10h] [bp-260h] BYREF
  char v48[4]; // [sp+14h] [bp-25Ch] BYREF
  const char *v49; // [sp+18h] [bp-258h]
  int v50; // [sp+1Ch] [bp-254h]
  int v51; // [sp+20h] [bp-250h]
  int v52; // [sp+24h] [bp-24Ch]
  char *v53; // [sp+28h] [bp-248h]
  int v54; // [sp+2Ch] [bp-244h]
  int v55; // [sp+30h] [bp-240h]
  int v56; // [sp+38h] [bp-238h]
  int v57; // [sp+3Ch] [bp-234h]
  int v58; // [sp+40h] [bp-230h]
  const char *v59; // [sp+44h] [bp-22Ch] BYREF
  char v60[511]; // [sp+48h] [bp-228h] BYREF
  char v61; // [sp+247h] [bp-29h] BYREF
  char v62[40]; // [sp+248h] [bp-28h] BYREF

  v5 = 0;
  v6 = 0;
  v58 = 0;
  v50 = 0;
  v51 = 0;
  v54 = 0;
  v52 = 0;
  v7 = a2;
  v56 = 0;
  if ( a1 && a2 )
  {
    v9 = *a2;
    v10 = 0;
    v11 = 0;
    LODWORD(v12) = v9;
    v46 = 0;
    v47 = 0;
    v55 = 0;
    if ( v9 )
    {
      v13 = (int)v59;
      v8 = -1;
      v49 = v59;
      while ( 1 )
      {
        v53 = ++v7;
        if ( v10 < 0 )
          break;
        if ( (int)v12 < 32 || (int)v12 > 120 )
          v14 = 0;
        else
          v14 = *((_BYTE *)&_lookuptable[-8] + v12) & 0xF;
        v55 = *((char *)&_lookuptable[2 * v14] + v55) >> 4;
        switch ( v55 )
        {
          case 0:
            goto LABEL_56;
          case 1:
            v5 = -1;
            v54 = 0;
            v50 = 0;
            v51 = 0;
            v56 = -1;
            v52 = 0;
            v6 = 0;
            goto LABEL_194;
          case 2:
            switch ( (_DWORD)v12 )
            {
              case ' ':
                v6 |= 2u;
                break;
              case '#':
                v6 |= 0x80u;
                break;
              case '+':
                v6 |= 1u;
                break;
              case '-':
                v6 |= 4u;
                break;
              case '0':
                v6 |= 8u;
                break;
            }
            goto LABEL_194;
          case 3:
            if ( (_DWORD)v12 == 42 )
            {
              a4 += (-a4 & 3) + 4;
              v15 = *(_DWORD *)(a4 - 4);
              v51 = v15;
              if ( v15 >= 0 )
                goto LABEL_194;
              v6 |= 4u;
              v16 = -v15;
            }
            else
            {
              v16 = v12 + 10 * v51 - 48;
            }
            v51 = v16;
            goto LABEL_194;
          case 4:
            v5 = 0;
            v56 = 0;
            goto LABEL_194;
          case 5:
            if ( (_DWORD)v12 == 42 )
            {
              v17 = (int *)((-a4 & 3) + a4);
              a4 = (int)(v17 + 1);
              v5 = *v17;
              v56 = v5;
              if ( v5 >= 0 )
                goto LABEL_194;
              v5 = -1;
            }
            else
            {
              v5 = v12 + 10 * v5 - 48;
            }
            v56 = v5;
            goto LABEL_194;
          case 6:
            if ( (_DWORD)v12 != 73 )
            {
              switch ( (_DWORD)v12 )
              {
                case 'h':
                  v6 |= 0x20u;
                  break;
                case 'l':
                  if ( *v7 == 108 )
                  {
                    ++v7;
                    v6 |= 0x1000u;
                  }
                  else
                  {
                    v6 |= 0x10u;
                  }
                  break;
                case 'w':
                  v6 |= 0x800u;
                  break;
              }
              goto LABEL_194;
            }
            v18 = *v7;
            if ( v18 == 54 && v7[1] == 52 )
            {
              v7 += 2;
              v6 |= 0x8000u;
              goto LABEL_194;
            }
            if ( v18 == 51 && v7[1] == 50 )
            {
              v7 += 2;
              v6 &= 0xFFFF7FFF;
              goto LABEL_194;
            }
            if ( v18 == 100 || v18 == 105 || v18 == 111 || v18 == 117 || v18 == 120 || v18 == 88 )
              goto LABEL_194;
            v55 = 0;
LABEL_56:
            v52 = 0;
            sub_4FC120(v9, a1, &v47);
            v10 = v47;
            goto LABEL_193;
          case 7:
            if ( (int)v12 > 105 )
            {
              if ( (_DWORD)v12 == 110 )
              {
                v36 = (_WORD **)((-a4 & 3) + a4);
                a4 = (int)(v36 + 1);
                v37 = *v36;
                if ( !get_printf_count_output() )
                  goto LABEL_197;
                if ( (v6 & 0x20) != 0 )
                  *v37 = v10;
                else
                  *(_DWORD *)v37 = v10;
                v54 = 1;
                v11 = v46;
              }
              else
              {
                if ( (_DWORD)v12 == 111 )
                {
                  v19 = 8;
                  if ( (v6 & 0x80) != 0 )
                    v6 |= 0x200u;
                }
                else
                {
                  switch ( (_DWORD)v12 )
                  {
                    case 'p':
                      v5 = 8;
LABEL_115:
                      v26 = 7;
                      break;
                    case 's':
                      goto LABEL_78;
                    case 'u':
                      v19 = 10;
                      goto LABEL_95;
                    case 'x':
                      v26 = 39;
                      break;
                    default:
                      goto LABEL_158;
                  }
                  v58 = v26;
                  v19 = 16;
                  if ( (v6 & 0x80) != 0 )
                  {
                    v48[0] = 48;
                    v50 = 2;
                    v48[1] = v26 + 81;
                  }
                }
LABEL_95:
                if ( (v6 & 0x8000) == 0 && (v6 & 0x1000) == 0 )
                {
                  a4 += (-a4 & 3) + 4;
                  if ( (v6 & 0x20) != 0 )
                  {
                    if ( (v6 & 0x40) != 0 )
                    {
                      v27 = *(__int16 *)(a4 - 4);
                      HIDWORD(v12) = v27 >> 31;
                      goto LABEL_129;
                    }
                    v27 = *(unsigned __int16 *)(a4 - 4);
                  }
                  else
                  {
                    if ( (v6 & 0x40) != 0 )
                    {
                      v27 = *(_DWORD *)(a4 - 4);
                      HIDWORD(v12) = v27 >> 31;
                      goto LABEL_129;
                    }
                    v27 = *(_DWORD *)(a4 - 4);
                  }
                  HIDWORD(v12) = 0;
                  goto LABEL_129;
                }
                a4 += (-a4 & 7) + 8;
                HIDWORD(v12) = *(_DWORD *)(a4 - 4);
                v27 = *(_DWORD *)(a4 - 8);
LABEL_129:
                if ( (v6 & 0x40) != 0 && v12 < 0 )
                {
                  v31 = v27 == 0;
                  v27 = -v27;
                  HIDWORD(v12) = -(HIDWORD(v12) + !v31);
                  v6 |= 0x100u;
                }
                if ( (v6 & 0x9000) == 0 )
                  HIDWORD(v12) = 0;
                if ( v5 >= 0 )
                {
                  if ( v5 > 512 )
                    v5 = 512;
                  v6 &= 0xFFFFFFF7;
                }
                else
                {
                  v5 = 1;
                }
                if ( !(v27 | HIDWORD(v12)) )
                  v50 = 0;
                v32 = v58;
                for ( i = &v61; v5-- > 0 || v27 | HIDWORD(v12); --i )
                {
                  LODWORD(v12) = v27;
                  v27 = _rt_udiv64((unsigned int)v19, v12);
                  LODWORD(v12) = v12 + 48;
                  if ( (int)v12 > 57 )
                    LOBYTE(v12) = v12 + v32;
                  v57 = HIDWORD(v12);
                  *i = v12;
                  HIDWORD(v12) = v35;
                }
                v11 = &v61 - i;
                v13 = (int)(i + 1);
                v49 = (const char *)v13;
                v56 = v5;
                v46 = v11;
                v8 = -1;
                if ( (v6 & 0x200) != 0 && (!v11 || *(_BYTE *)v13 != 48) )
                {
                  ++v11;
                  --v13;
                  v46 = v11;
                  v49 = (const char *)v13;
                  *(_BYTE *)v13 = 48;
                }
              }
              v7 = v53;
              goto LABEL_158;
            }
            switch ( (_DWORD)v12 )
            {
              case 'i':
                goto LABEL_65;
              case 'C':
                if ( (v6 & 0x830) == 0 )
                  v6 |= 0x800u;
LABEL_82:
                v23 = -a4;
                if ( (v6 & 0x810) != 0 )
                {
                  a4 += (v23 & 1) + 4;
                  v24 = wctomb_s(&v46, (int)v60, 0x200u);
                  v11 = v46;
                  if ( v24 )
                    v54 = 1;
                }
                else
                {
                  a4 += (v23 & 3) + 4;
                  v25 = *(_DWORD *)(a4 - 4);
                  v11 = 1;
                  v46 = 1;
                  v60[0] = v25;
                }
                v13 = (int)v60;
                v49 = v60;
                goto LABEL_158;
              case 'S':
                if ( (v6 & 0x830) == 0 )
                  v6 |= 0x800u;
LABEL_78:
                if ( v5 == -1 )
                  v22 = 0x7FFFFFFF;
                else
                  v22 = v5;
                v28 = (int *)((-a4 & 3) + a4);
                a4 = (int)(v28 + 1);
                v13 = *v28;
                v49 = (const char *)*v28;
                if ( (v6 & 0x810) != 0 )
                {
                  if ( !v13 )
                  {
                    v13 = (int)L"(null)";
                    v49 = (const char *)L"(null)";
                  }
                  v52 = 1;
                  for ( j = (_WORD *)v13; v22; ++j )
                  {
                    --v22;
                    if ( !*j )
                      break;
                  }
                  v11 = ((int)j - v13) >> 1;
                }
                else
                {
                  if ( !v13 )
                  {
                    v13 = (int)"(null)";
                    v49 = "(null)";
                  }
                  for ( k = (_BYTE *)v13; v22; ++k )
                  {
                    --v22;
                    if ( !*k )
                      break;
                  }
                  v11 = (int)&k[-v13];
                }
LABEL_75:
                v46 = v11;
                goto LABEL_158;
              case 'X':
                goto LABEL_115;
            }
            if ( (_DWORD)v12 != 90 )
            {
              if ( (_DWORD)v12 != 99 )
              {
                if ( (_DWORD)v12 != 100 )
                  goto LABEL_158;
LABEL_65:
                v6 |= 0x40u;
                v19 = 10;
                goto LABEL_95;
              }
              goto LABEL_82;
            }
            a4 += (-a4 & 3) + 4;
            v20 = *(unsigned __int16 **)(a4 - 4);
            if ( !v20 || (v13 = *((_DWORD *)v20 + 1), (v49 = (const char *)v13) == 0) )
            {
              v13 = (int)"(null)";
              v11 = 6;
              v49 = "(null)";
              goto LABEL_75;
            }
            v21 = *v20;
            if ( v20[1] < v21 )
              goto LABEL_197;
            if ( (v6 & 0x800) != 0 )
            {
              if ( (v21 & 1) != 0 || (v13 & 1) != 0 )
              {
LABEL_197:
                PopPoCoalescinCallback();
                return v8;
              }
              v11 = v21 >> 1;
              v52 = 1;
              v46 = v21 >> 1;
            }
            else
            {
              v52 = 0;
              v49 = (const char *)v13;
              v11 = v21;
              v46 = v21;
            }
LABEL_158:
            if ( !v54 )
            {
              if ( (v6 & 0x40) != 0 )
              {
                if ( (v6 & 0x100) != 0 )
                {
                  v38 = 45;
                  goto LABEL_166;
                }
                if ( (v6 & 1) != 0 )
                {
                  v38 = 43;
                  goto LABEL_166;
                }
                if ( (v6 & 2) != 0 )
                {
                  v38 = 32;
LABEL_166:
                  v48[0] = v38;
                  v50 = 1;
                }
              }
              v39 = v51 - v11 - v50;
              if ( (v6 & 0xC) == 0 )
              {
                v40 = v51 - v11 - v50;
                if ( v39 > 0 )
                {
                  do
                  {
                    --v40;
                    sub_4FC120(32, a1, &v47);
                  }
                  while ( v47 != -1 && v40 > 0 );
                }
              }
              sub_4FC164(v48, v50, a1, &v47);
              if ( (v6 & 8) != 0 && (v6 & 4) == 0 )
              {
                v41 = v39;
                if ( v39 > 0 )
                {
                  do
                  {
                    --v41;
                    sub_4FC120(48, a1, &v47);
                  }
                  while ( v47 != -1 && v41 > 0 );
                }
              }
              v42 = v46;
              if ( v52 && v46 > 0 )
              {
                v43 = v13;
                while ( 1 )
                {
                  v43 += 2;
                  --v42;
                  if ( wctomb_s((int *)&v59, (int)v62, 6u) || !v59 )
                    break;
                  sub_4FC164(v62, v59, a1, &v47);
                  if ( !v42 )
                    goto LABEL_185;
                }
                v10 = -1;
                v47 = -1;
              }
              else
              {
                sub_4FC164(v13, v46, a1, &v47);
LABEL_185:
                v10 = v47;
              }
              if ( v10 >= 0 && (v6 & 4) != 0 && v39 > 0 )
              {
                do
                {
                  --v39;
                  sub_4FC120(32, a1, &v47);
                  v10 = v47;
                }
                while ( v47 != -1 && v39 > 0 );
                v13 = (int)v49;
              }
              v7 = v53;
              v5 = v56;
LABEL_193:
              v11 = v46;
            }
LABEL_194:
            v9 = *v7;
            LODWORD(v12) = v9;
            if ( !*v7 )
              goto LABEL_195;
            break;
          default:
            goto LABEL_194;
        }
      }
    }
LABEL_195:
    v8 = v10;
  }
  else
  {
    PopPoCoalescinCallback();
    v8 = -1;
  }
  return v8;
}
