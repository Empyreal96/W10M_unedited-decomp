// _output_s 
 
int __fastcall output_s(int a1, char *a2, __int16 *a3)
{
  int v4; // r1
  __int16 *v5; // r7
  int v6; // r5
  int v7; // lr
  int v8; // r9
  int v9; // r0
  int v10; // r6
  signed __int64 v11; // r2
  int v12; // r8
  char *v13; // r10
  int v14; // r3
  int v15; // lr
  int v16; // r2
  char v17; // r3
  unsigned __int16 **v18; // r3
  unsigned __int16 *v19; // r3
  unsigned int v20; // r2
  int v21; // r2
  __int16 *v22; // r3
  _DWORD *v23; // r3
  int v24; // r4
  int v25; // r3
  int v26; // r7
  int v27; // r0
  char **v28; // r3
  char *j; // r1
  _BYTE *k; // r1
  __int16 *v31; // r3
  unsigned __int16 *v32; // r3
  int *v33; // r3
  int *v34; // r3
  bool v35; // cf
  int v36; // r7
  char v37; // r9
  char *i; // r10
  int v40; // r1
  int v41; // r8
  int v42; // r4
  int v43; // r6
  int v44; // r7
  int v45; // r4
  __int16 *v46; // r7
  __int16 v47; // t1
  int v48; // r4
  int v49; // r3
  int v51; // [sp+0h] [bp-280h]
  int v52; // [sp+0h] [bp-280h]
  int v53; // [sp+8h] [bp-278h]
  int v54; // [sp+Ch] [bp-274h]
  __int16 *v55; // [sp+10h] [bp-270h]
  int v56; // [sp+14h] [bp-26Ch]
  int v57; // [sp+18h] [bp-268h] BYREF
  char v58[4]; // [sp+1Ch] [bp-264h] BYREF
  int v59; // [sp+20h] [bp-260h]
  int v60; // [sp+28h] [bp-258h]
  int v61; // [sp+2Ch] [bp-254h]
  char *v62; // [sp+30h] [bp-250h]
  __int16 v63; // [sp+34h] [bp-24Ch] BYREF
  int v64; // [sp+38h] [bp-248h]
  int v65; // [sp+3Ch] [bp-244h]
  int v66; // [sp+40h] [bp-240h]
  int v67; // [sp+44h] [bp-23Ch]
  int v68; // [sp+48h] [bp-238h]
  char *v69; // [sp+4Ch] [bp-234h] BYREF
  int v70; // [sp+50h] [bp-230h] BYREF
  char v71[512]; // [sp+58h] [bp-228h] BYREF
  int v72; // [sp+258h] [bp-28h] BYREF
  __int16 v73; // [sp+25Ch] [bp-24h]

  v4 = 0;
  v5 = a3;
  v6 = 0;
  v55 = a3;
  v56 = 0;
  v7 = a1;
  v66 = a1;
  v67 = 0;
  v64 = 0;
  v65 = 0;
  v59 = 0;
  v68 = 0;
  if ( a1 && a2 )
  {
    v9 = *a2;
    v10 = 0;
    v11 = (unsigned int)v9;
    v53 = 0;
    v57 = 0;
    v60 = 0;
    v12 = 0;
    if ( !v9 )
      goto LABEL_201;
    v13 = v69;
    v8 = -1;
    while ( 1 )
    {
      v62 = ++a2;
      if ( v11 < 0 )
        break;
      if ( (int)v11 < 32 || (int)v11 > 120 )
        v14 = 0;
      else
        v14 = *((_BYTE *)&_lookuptable_s[-8] + v11) & 0xF;
      v12 = *((unsigned __int8 *)_lookuptable_s + 9 * v14 + v12) >> 4;
      v54 = v12;
      if ( v12 == 8 )
        goto LABEL_198;
      switch ( v12 )
      {
        case 0:
          goto LABEL_56;
        case 1:
          v6 = 0;
          v4 = -1;
          v68 = 0;
          v64 = 0;
          v65 = 0;
          v59 = 0;
          v56 = -1;
          goto LABEL_193;
        case 2:
          switch ( (_DWORD)v11 )
          {
            case ' ':
              v6 |= 2u;
              goto LABEL_193;
            case '#':
              v6 |= 0x80u;
              goto LABEL_193;
            case '+':
              v6 |= 1u;
              goto LABEL_193;
            case '-':
              v6 |= 4u;
              goto LABEL_193;
          }
          HIDWORD(v11) = v53;
          if ( (_DWORD)v11 == 48 )
            v6 |= 8u;
          goto LABEL_195;
        case 3:
          if ( (_DWORD)v11 != 42 )
          {
            v64 = v11 + 10 * v64 - 48;
            goto LABEL_193;
          }
          v5 = (__int16 *)((char *)v5 + (-(int)v5 & 3) + 4);
          v15 = *((_DWORD *)v5 - 1);
          HIDWORD(v11) = v53;
          v55 = v5;
          v64 = v15;
          if ( v15 < 0 )
          {
            v64 = -v15;
            v6 |= 4u;
          }
          goto LABEL_195;
        case 4:
          v4 = 0;
          goto LABEL_29;
        case 5:
          if ( (_DWORD)v11 == 42 )
          {
            v5 = (__int16 *)((char *)v5 + (-(int)v5 & 3) + 4);
            v4 = *((_DWORD *)v5 - 1);
            HIDWORD(v11) = v53;
            v55 = v5;
            v56 = v4;
            if ( v4 < 0 )
            {
              v4 = -1;
              v56 = -1;
            }
            goto LABEL_195;
          }
          v4 = v11 + 10 * v4 - 48;
LABEL_29:
          v56 = v4;
          goto LABEL_193;
        case 6:
          if ( (_DWORD)v11 != 73 )
          {
            if ( (_DWORD)v11 == 104 )
            {
              v6 |= 0x20u;
              goto LABEL_193;
            }
            if ( (_DWORD)v11 == 108 )
            {
              HIDWORD(v11) = v53;
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
              HIDWORD(v11) = v53;
              if ( (_DWORD)v11 == 119 )
                v6 |= 0x800u;
            }
            goto LABEL_195;
          }
          v16 = *a2;
          if ( v16 == 54 && a2[1] == 52 )
          {
            a2 += 2;
            v6 |= 0x8000u;
            goto LABEL_193;
          }
          if ( v16 == 51 && a2[1] == 50 )
          {
            a2 += 2;
            v6 &= 0xFFFF7FFF;
            goto LABEL_193;
          }
          if ( v16 != 100 && v16 != 105 && v16 != 111 && v16 != 117 && v16 != 120 && v16 != 88 )
          {
            v12 = 0;
LABEL_56:
            v65 = 0;
            sub_4FC120(v9, v7, &v57);
            v4 = v56;
            HIDWORD(v11) = v57;
            v53 = v57;
            goto LABEL_195;
          }
          goto LABEL_193;
        case 7:
          if ( (int)v11 > 105 )
          {
            if ( (_DWORD)v11 == 110 )
              goto LABEL_198;
            if ( (_DWORD)v11 == 111 )
            {
              v24 = 8;
              if ( (v6 & 0x80) != 0 )
                v6 |= 0x200u;
            }
            else
            {
              switch ( (_DWORD)v11 )
              {
                case 'p':
                  v4 = 8;
                  v56 = 8;
LABEL_120:
                  v25 = 7;
                  break;
                case 's':
                  goto LABEL_81;
                case 'u':
                  v24 = 10;
                  goto LABEL_101;
                case 'x':
                  v25 = 39;
                  break;
                default:
                  goto LABEL_65;
              }
              v67 = v25;
              v24 = 16;
              if ( (v6 & 0x80) != 0 )
              {
                v59 = 2;
                v58[0] = 48;
                v58[1] = v25 + 81;
              }
            }
LABEL_101:
            if ( (v6 & 0x8000) != 0 || (v6 & 0x1000) != 0 )
            {
              v26 = (int)v5 + (-(int)v5 & 7) + 8;
              HIDWORD(v11) = *(_DWORD *)(v26 - 4);
              v27 = *(_DWORD *)(v26 - 8);
              goto LABEL_134;
            }
            if ( (v6 & 0x20) != 0 )
            {
              if ( (v6 & 0x40) != 0 )
              {
                v31 = (__int16 *)((char *)v5 + (-(int)v5 & 3));
                v26 = (int)(v31 + 2);
                v27 = *v31;
                HIDWORD(v11) = v27 >> 31;
                goto LABEL_134;
              }
              v32 = (unsigned __int16 *)((char *)v5 + (-(int)v5 & 3));
              v26 = (int)(v32 + 2);
              v27 = *v32;
LABEL_133:
              HIDWORD(v11) = 0;
            }
            else
            {
              if ( (v6 & 0x40) == 0 )
              {
                v34 = (int *)((char *)v5 + (-(int)v5 & 3));
                v26 = (int)(v34 + 1);
                v27 = *v34;
                goto LABEL_133;
              }
              v33 = (int *)((char *)v5 + (-(int)v5 & 3));
              v26 = (int)(v33 + 1);
              v27 = *v33;
              HIDWORD(v11) = *v33 >> 31;
            }
LABEL_134:
            v55 = (__int16 *)v26;
            if ( (v6 & 0x40) != 0 && v11 < 0 )
            {
              v35 = v27 == 0;
              v27 = -v27;
              HIDWORD(v11) = -(HIDWORD(v11) + !v35);
              v6 |= 0x100u;
            }
            if ( (v6 & 0x9000) == 0 )
              HIDWORD(v11) = 0;
            if ( v4 >= 0 )
            {
              v6 &= 0xFFFFFFF7;
              if ( v4 > 512 )
                v56 = 512;
            }
            else
            {
              v56 = 1;
            }
            if ( !(v27 | HIDWORD(v11)) )
              v59 = 0;
            v36 = v56;
            v37 = v67;
            for ( i = &v71[511]; v36-- > 0 || v27 | HIDWORD(v11); --i )
            {
              LODWORD(v11) = v27;
              v27 = _rt_udiv64((unsigned int)v24, v11);
              LODWORD(v11) = v11 + 48;
              if ( (int)v11 > 57 )
                LOBYTE(v11) = v11 + v37;
              v61 = HIDWORD(v11);
              *i = v11;
              HIDWORD(v11) = v40;
            }
            v10 = &v71[511] - i;
            v56 = v36;
            v5 = v55;
            v60 = &v71[511] - i;
            v13 = i + 1;
            v8 = -1;
            if ( (v6 & 0x200) != 0 && (!v10 || *v13 != 48) )
            {
              ++v10;
              --v13;
              v60 = v10;
              *v13 = 48;
            }
            a2 = v62;
            goto LABEL_65;
          }
          switch ( (_DWORD)v11 )
          {
            case 'i':
              goto LABEL_92;
            case 'C':
              if ( (v6 & 0x830) == 0 )
                v6 |= 0x800u;
LABEL_85:
              if ( (v6 & 0x810) != 0 )
              {
                v22 = (__int16 *)((char *)v5 + (-(int)v5 & 1));
                v5 = v22 + 2;
                v10 = -1;
                v63 = *v22;
                v51 = 2;
                v55 = v22 + 2;
                v60 = -1;
                if ( RtlUnicodeToMultiByteN(v71, 512, &v70, &v63) < 0 )
                {
                  memset(v71, 0, sizeof(v71));
                  v68 = 1;
LABEL_91:
                  v13 = v71;
                  goto LABEL_65;
                }
                v10 = v70;
              }
              else
              {
                v23 = (_DWORD *)((char *)v5 + (-(int)v5 & 3));
                v5 = (__int16 *)(v23 + 1);
                v55 = (__int16 *)(v23 + 1);
                v10 = 1;
                v71[0] = *v23;
              }
              v60 = v10;
              goto LABEL_91;
            case 'S':
              if ( (v6 & 0x830) == 0 )
                v6 |= 0x800u;
LABEL_81:
              if ( v4 == -1 )
                v21 = 0x7FFFFFFF;
              else
                v21 = v4;
              v28 = (char **)((char *)v5 + (-(int)v5 & 3));
              v5 = (__int16 *)(v28 + 1);
              v13 = *v28;
              v55 = (__int16 *)(v28 + 1);
              if ( (v6 & 0x810) != 0 )
              {
                if ( !v13 )
                  v13 = (char *)L"(null)";
                v65 = 1;
                for ( j = v13; v21; j += 2 )
                {
                  --v21;
                  if ( !*(_WORD *)j )
                    break;
                }
                v10 = (j - v13) >> 1;
              }
              else
              {
                if ( !v13 )
                  v13 = "(null)";
                for ( k = v13; v21; ++k )
                {
                  --v21;
                  if ( !*k )
                    break;
                }
                v10 = k - v13;
              }
LABEL_77:
              v60 = v10;
              goto LABEL_65;
            case 'X':
              goto LABEL_120;
          }
          if ( (_DWORD)v11 != 90 )
          {
            if ( (_DWORD)v11 == 99 )
              goto LABEL_85;
            if ( (_DWORD)v11 != 100 )
              goto LABEL_65;
LABEL_92:
            v6 |= 0x40u;
            v24 = 10;
            goto LABEL_101;
          }
          v18 = (unsigned __int16 **)((char *)v5 + (-(int)v5 & 3));
          v5 = (__int16 *)(v18 + 1);
          v19 = *v18;
          v55 = v5;
          if ( !v19 || (v13 = (char *)*((_DWORD *)v19 + 1)) == 0 )
          {
            v13 = "(null)";
            v10 = 6;
            goto LABEL_77;
          }
          v20 = *v19;
          if ( v19[1] < v20 )
            goto LABEL_198;
          if ( (v6 & 0x800) == 0 )
          {
            v65 = 0;
            v10 = v20;
            goto LABEL_77;
          }
          if ( (v20 & 1) != 0 || ((unsigned __int8)v13 & 1) != 0 )
            goto LABEL_198;
          v10 = v20 >> 1;
          v65 = 1;
          v60 = v20 >> 1;
LABEL_65:
          if ( v68 )
            goto LABEL_192;
          if ( (v6 & 0x40) == 0 )
            goto LABEL_162;
          if ( (v6 & 0x100) != 0 )
          {
            v17 = 45;
          }
          else if ( (v6 & 1) != 0 )
          {
            v17 = 43;
          }
          else
          {
            if ( (v6 & 2) == 0 )
              goto LABEL_162;
            v17 = 32;
          }
          v58[0] = v17;
          v59 = 1;
LABEL_162:
          v41 = v64 - v10 - v59;
          if ( (v6 & 0xC) == 0 )
          {
            v42 = v64 - v10 - v59;
            if ( v41 > 0 )
            {
              v43 = v66;
              do
              {
                --v42;
                sub_4FC120(32, v43, &v57);
              }
              while ( v57 != -1 && v42 > 0 );
              v10 = v60;
            }
          }
          v44 = v66;
          sub_4FE0B8(v58, v59, v66, &v57, v51);
          if ( (v6 & 8) != 0 && (v6 & 4) == 0 )
          {
            v45 = v41;
            if ( v41 > 0 )
            {
              do
              {
                --v45;
                sub_4FC120(48, v44, &v57);
              }
              while ( v57 != -1 && v45 > 0 );
            }
          }
          if ( v65 && v10 > 0 )
          {
            v46 = (__int16 *)v13;
            while ( 1 )
            {
              v47 = *v46++;
              v63 = v47;
              v51 = 2;
              --v10;
              v48 = -1;
              if ( RtlUnicodeToMultiByteN(&v72, 6, &v69, &v63) >= 0 )
              {
                v48 = (int)v69;
                v49 = 0;
              }
              else
              {
                v72 = 0;
                v73 = 0;
                v49 = 42;
              }
              if ( v49 || !v48 )
                break;
              sub_4FE0B8(&v72, v48, v66, &v57, 2);
              if ( !v10 )
              {
                v10 = v60;
                v44 = v66;
                goto LABEL_185;
              }
            }
            v10 = v60;
            v44 = v66;
            HIDWORD(v11) = -1;
            v57 = -1;
          }
          else
          {
            sub_4FE0B8(v13, v10, v44, &v57, v52);
LABEL_185:
            HIDWORD(v11) = v57;
          }
          v53 = HIDWORD(v11);
          if ( v11 >= 0 && (v6 & 4) != 0 && v41 > 0 )
          {
            do
            {
              --v41;
              sub_4FC120(32, v44, &v57);
              v53 = v57;
            }
            while ( v57 != -1 && v41 > 0 );
            v10 = v60;
            v5 = v55;
            a2 = v62;
LABEL_192:
            v4 = v56;
LABEL_193:
            HIDWORD(v11) = v53;
          }
          else
          {
            v5 = v55;
            v4 = v56;
            a2 = v62;
          }
          v12 = v54;
LABEL_195:
          v9 = *a2;
          LODWORD(v11) = v9;
          if ( !*a2 )
            goto LABEL_199;
          v7 = v66;
          break;
        default:
          goto LABEL_193;
      }
    }
LABEL_199:
    if ( v12 && v12 != 7 )
LABEL_198:
      PopPoCoalescinCallback();
    else
LABEL_201:
      v8 = HIDWORD(v11);
  }
  else
  {
    PopPoCoalescinCallback();
    v8 = -1;
  }
  return v8;
}
