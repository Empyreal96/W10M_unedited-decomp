// punycode_encode 
 
int punycode_encode(char *a1, int a2, ...)
{
  int *v2; // r8
  unsigned __int16 *v3; // r5
  char *v4; // r6
  char *v5; // r10
  unsigned __int16 *v6; // r9
  int result; // r0
  int v8; // r3
  int v9; // r7
  unsigned __int16 *v10; // r0
  unsigned __int16 *v11; // r4
  const __int16 *v12; // r2
  unsigned int v13; // r8
  int v14; // r10
  unsigned __int16 *i; // r1
  unsigned int v16; // r2
  int v17; // r2
  char *v18; // r0
  unsigned __int16 *j; // r2
  __int16 *v20; // r1
  int v21; // r3
  int v22; // r8
  int v23; // r1
  unsigned __int16 *v24; // r6
  int v25; // r7
  int v26; // r0
  int v27; // r3
  int v28; // r6
  unsigned __int16 *v29; // r8
  bool v30; // cf
  int v31; // r0
  int v32; // r3
  bool v33; // zf
  int v34; // r3
  int v35; // r1
  int v36; // r8
  int v37; // r2
  int v38; // r1
  int v39; // r0
  int v40; // t0
  unsigned __int16 v41; // r0
  int v42; // r2
  BOOL v43; // r0
  int v44; // r3
  _BYTE v45[48]; // [sp+10h] [bp-60h]
  int v46; // [sp+10h] [bp-60h]
  int v47; // [sp+10h] [bp-60h]
  int v48; // [sp+14h] [bp-5Ch]
  unsigned int v49; // [sp+18h] [bp-58h]
  int v50; // [sp+1Ch] [bp-54h]
  int *v51; // [sp+20h] [bp-50h]
  unsigned __int16 *v52; // [sp+24h] [bp-4Ch]
  int v53; // [sp+28h] [bp-48h]
  unsigned __int16 *v54; // [sp+2Ch] [bp-44h]
  int v55; // [sp+30h] [bp-40h]
  int v56; // [sp+34h] [bp-3Ch]
  int v57; // [sp+38h] [bp-38h]
  unsigned __int16 *v58; // [sp+3Ch] [bp-34h]
  __int128 v59; // [sp+44h] [bp-2Ch]
  __int64 v60; // [sp+44h] [bp-2Ch]
  int v61; // [sp+4Ch] [bp-24h]
  int v62; // [sp+50h] [bp-20h]
  unsigned __int16 *varg_r2; // [sp+80h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+80h] [bp+10h]
  int *varg_r3; // [sp+84h] [bp+14h]
  int v66; // [sp+88h] [bp+18h]
  int v67; // [sp+8Ch] [bp+1Ch]
  va_list va1; // [sp+90h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, unsigned __int16 *);
  varg_r3 = va_arg(va1, int *);
  v66 = va_arg(va1, _DWORD);
  v67 = va_arg(va1, _DWORD);
  v2 = varg_r3;
  *(_DWORD *)&v45[16] = varg_r3;
  v3 = varg_r2;
  v4 = &a1[2 * a2];
  *(_DWORD *)&v45[8] = &varg_r2[*varg_r3];
  v5 = a1;
  *(_QWORD *)&v59 = __PAIR64__((unsigned int)a1, (unsigned int)v4);
  v6 = (unsigned __int16 *)a1;
  *(_DWORD *)&v45[44] = varg_r2;
  *(_DWORD *)&v45[20] = varg_r2;
  HIDWORD(v59) = varg_r2;
  if ( a2 <= 0 )
  {
    result = -1073740010;
    v8 = 0;
LABEL_113:
    *v2 = v8;
    return result;
  }
  v9 = (unsigned __int8)v66;
  if ( a1 < v4 )
  {
    v56 = (unsigned __int8)v66;
    while ( 1 )
    {
      v10 = FindLabelEnd(v6, (unsigned int)v4, v9);
      v11 = v10;
      if ( v10 == v6 )
        break;
      if ( v9 )
      {
        v12 = L"xl--";
      }
      else
      {
        if ( (_BYTE)v67 && (*v6 == 45 || v10 > (unsigned __int16 *)v5 && *(v10 - 1) == 45) )
          goto LABEL_110;
        v12 = L"xn--";
      }
      v13 = v49;
      if ( RtlStringCchCopyNExW(v3, (int)(v49 - (_DWORD)v3) >> 1, (int)v12, 4, (unsigned __int16 **)varg_r2a, 0, 0) < 0 )
      {
LABEL_100:
        result = -1073741789;
        goto LABEL_111;
      }
      v3 = varg_r2;
      v14 = 0;
      for ( i = v6; i < v11; ++i )
      {
        v16 = *i;
        if ( v16 >= 0x80 )
        {
          if ( v16 >= 0xD800 && v16 <= 0xDBFF )
            ++i;
        }
        else
        {
          if ( !v9 && ((_BYTE)v67 && !ValidateStd3Range(*i) || v16 < 0x20 || v16 == 127) || !v16 )
            goto LABEL_110;
          if ( (unsigned int)v3 >= v49 )
            goto LABEL_100;
          if ( !v9 && v16 >= 0x41 && v16 <= 0x5A )
            LOWORD(v16) = v16 + 32;
          *v3++ = v16;
          varg_r2 = v3;
          ++v14;
        }
      }
      v17 = (char *)v11 - (char *)v6;
      v61 = v14;
      if ( v14 == v11 - v6 )
      {
        v18 = (char *)v52;
        for ( j = v52; j < v3 - 4; ++j )
          *j = j[4];
        v3 -= 4;
        varg_r2 = v3;
      }
      else
      {
        if ( (int)((v4 - (char *)v6) & 0xFFFFFFFE) >= 8 )
        {
          if ( v9 )
            v20 = L"xl--";
          else
            v20 = L"xn--";
          if ( !wcsnicmp((int)v6, (unsigned __int16 *)v20, 4) )
            goto LABEL_110;
          v17 = (char *)v11 - (char *)v6;
        }
        v21 = 0;
        v50 = 0;
        if ( v14 > 0 )
        {
          if ( (unsigned int)v3 >= v49 )
            goto LABEL_100;
          *v3++ = 45;
          varg_r2 = v3;
        }
        v46 = 0;
        v53 = 72;
        v22 = 128;
        if ( v14 < v17 >> 1 )
        {
          do
          {
            v23 = 0x7FFFFFF;
            v48 = 0x7FFFFFF;
            v24 = v6;
            if ( v6 < v11 )
            {
              v25 = 0x7FFFFFF;
              do
              {
                v26 = GetUTF32(v24);
                if ( v26 >= v22 && v26 < v25 )
                  v25 = v26;
                if ( IsSupplementary(v26) )
                  v27 = 2;
                else
                  v27 = 1;
                v24 += v27;
              }
              while ( v24 < v11 );
              v48 = v25;
              v9 = v56;
              v23 = v48;
              v21 = v50;
            }
            v28 = v46 + (v14 - v21 + 1) * (v23 - v22);
            v29 = v6;
            v30 = v6 >= v11;
            v47 = v28;
            while ( 1 )
            {
              v54 = v29;
              if ( v30 )
                break;
              v31 = GetUTF32(v29);
              v32 = v31;
              v57 = v31;
              v33 = v31 == v48;
              if ( v31 < v48 )
              {
                v47 = ++v28;
                v33 = v31 == v48;
              }
              if ( v33 )
              {
                v34 = v53;
                v35 = v28;
                v36 = 36;
                v37 = 36 - v53;
                while ( 1 )
                {
                  if ( v36 <= v34 )
                    v28 = 1;
                  v55 = v37;
                  if ( v36 > v34 )
                  {
                    if ( v36 < v34 + 26 )
                      v28 = v37;
                    else
                      v28 = 26;
                  }
                  if ( v35 < v28 )
                    break;
                  if ( (unsigned int)v3 >= v49 )
                    goto LABEL_100;
                  v38 = v35 - v28;
                  v39 = 36 - v28;
                  if ( 36 == v28 )
                    __brkdiv0();
                  v40 = v38 / v39;
                  v41 = encode_digit(v38 % v39 + v28);
                  v35 = v40;
                  v34 = v53;
                  v37 = v55 + 36;
                  *v3++ = v41;
                  v36 += 36;
                }
                if ( (unsigned int)v3 >= v49 )
                  goto LABEL_100;
                *v3++ = encode_digit(v35);
                if ( v14 == v61 )
                  v42 = 1;
                if ( v14 != v61 )
                  v42 = 0;
                varg_r2 = v3;
                v53 = adapt(v47, v14 - v50 + 1, v42);
                v28 = 0;
                v47 = 0;
                ++v14;
                v43 = IsSupplementary(v48);
                v32 = v57;
                if ( v43 )
                {
                  ++v50;
                  ++v14;
                }
                v29 = v54;
              }
              if ( IsSupplementary(v32) )
                v44 = 2;
              else
                v44 = 1;
              v29 += v44;
              v30 = v29 >= v11;
            }
            v21 = v50;
            v46 = v28 + 1;
            v22 = v23 + 1;
          }
          while ( v14 < v11 - v6 );
          v4 = (char *)v60;
        }
        v18 = (char *)v52;
        v13 = v49;
      }
      if ( !v9 && (int)(((char *)v3 - v18) & 0xFFFFFFFE) > 126 )
        goto LABEL_110;
      if ( v11 != (unsigned __int16 *)v4 )
      {
        if ( (unsigned int)v3 >= v13 )
          goto LABEL_100;
        *v3++ = *v11;
        varg_r2 = v3;
        if ( v9 )
        {
          if ( *v11 == 64 )
          {
            v9 = 0;
            v56 = 0;
            v58 = v3;
          }
        }
      }
      v6 = v11 + 1;
      v52 = v3;
      if ( v11 >= (unsigned __int16 *)v4 )
      {
        v2 = v51;
        goto LABEL_105;
      }
      v5 = (char *)HIDWORD(v60);
    }
    if ( v9 || v10 != (unsigned __int16 *)v4 )
    {
      result = -1073740010;
      *v51 = 0;
      return result;
    }
    v2 = v51;
LABEL_108:
    if ( v3 - v58 > 255 - (*(v3 - 1) != 46) )
      goto LABEL_110;
    goto LABEL_109;
  }
LABEL_105:
  if ( !v9 )
    goto LABEL_108;
LABEL_109:
  if ( *(v3 - 1) != 64 )
  {
    v8 = ((int)v3 - v62) >> 1;
    result = 0;
    goto LABEL_113;
  }
LABEL_110:
  result = -1073740010;
LABEL_111:
  *v51 = 0;
  return result;
}
