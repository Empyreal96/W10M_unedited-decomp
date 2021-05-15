// punycode_decode 
 
int __fastcall punycode_decode(char *a1, int a2, char *a3, int *a4, unsigned __int8 a5, char a6, _BYTE *a7, _DWORD *a8)
{
  char *v8; // r9
  char *v9; // r5
  int v10; // r2
  char *v11; // r4
  unsigned __int16 *v12; // r7
  char *v13; // r10
  int v14; // r8
  unsigned __int16 *v15; // r0
  char *v16; // r6
  __int16 *v18; // r1
  unsigned __int16 *v19; // r2
  int v20; // t1
  unsigned __int16 *v21; // r2
  int v22; // r4
  unsigned __int16 *v23; // r1
  unsigned int v24; // r3
  unsigned int v25; // r3
  int v26; // r3
  unsigned __int16 *v27; // r2
  int v28; // r1
  int v29; // r10
  int v30; // r8
  int v31; // r9
  int v32; // r3
  unsigned int v33; // r3
  int v34; // r4
  int v35; // r3
  int v36; // r4
  int v37; // r0
  int v38; // r0
  int v39; // r1
  int v40; // r10
  __int16 *v41; // r1
  int v42; // r1
  int v43; // r2
  int v44; // r1
  unsigned int v45; // r1
  unsigned __int16 *i; // r3
  unsigned int v47; // r2
  unsigned int v48; // r2
  unsigned int v49; // t1
  char *v50; // [sp+0h] [bp-58h]
  char *v51; // [sp+4h] [bp-54h]
  int v52; // [sp+8h] [bp-50h]
  int v53; // [sp+Ch] [bp-4Ch]
  int v54; // [sp+10h] [bp-48h]
  int v55; // [sp+14h] [bp-44h]
  unsigned __int16 *v56; // [sp+18h] [bp-40h]
  char *v57; // [sp+1Ch] [bp-3Ch]
  int v58; // [sp+20h] [bp-38h]
  char *v59; // [sp+24h] [bp-34h]
  int v60; // [sp+28h] [bp-30h]
  char *v61; // [sp+2Ch] [bp-2Ch]
  char *v62; // [sp+30h] [bp-28h]
  char *varg_r0; // [sp+60h] [bp+8h]
  int varg_r2[2]; // [sp+68h] [bp+10h] BYREF

  varg_r0 = a1;
  varg_r2[0] = (int)a3;
  varg_r2[1] = (int)a4;
  v8 = a1;
  v61 = a1;
  v9 = a3;
  v10 = *a4;
  *a4 = 0;
  varg_r2[0] = (int)v9;
  *a7 = 1;
  if ( a2 > 0 )
  {
    v11 = &a1[2 * a2];
    v57 = v11;
    v59 = a1 - 2;
    v50 = &v9[2 * v10];
    v51 = v9;
    *a8 = v9 - 2;
    v12 = (unsigned __int16 *)a1;
    v13 = v9;
    v62 = v9;
    if ( a1 < v11 )
    {
      v14 = a5;
      v58 = a5;
      while ( 1 )
      {
        v15 = FindLabelEnd(v12, (unsigned int)v11, v14);
        v16 = (char *)v15;
        if ( v15 == v12 )
          break;
        if ( !v14
          && (a6 && (*v12 == 45 || v15 > (unsigned __int16 *)v8 && *(v15 - 1) == 45)
           || (int)(((char *)v15 - (char *)v12) & 0xFFFFFFFE) > 126) )
        {
          return -1073740010;
        }
        if ( (int)((v11 - (char *)v12) & 0xFFFFFFFE) < 8
          || (!v14 ? (v18 = L"xn--") : (v18 = L"xl--"), wcsnicmp((int)v12, (unsigned __int16 *)v18, 4)) )
        {
          v45 = (unsigned int)v50;
          if ( (int)((v50 - v9) & 0xFFFFFFFE) < (int)((v16 - (char *)v12) & 0xFFFFFFFE) )
            return -1073740010;
          for ( i = v12; i < (unsigned __int16 *)v16; varg_r2[0] = (int)v9 )
          {
            if ( !v14 )
            {
              if ( a6 && !ValidateStd3Range(*i) )
                return -1073740010;
              v47 = *i;
              if ( v47 < 0x20 || v47 == 127 )
                return -1073740010;
            }
            v49 = *i++;
            v48 = v49;
            if ( !v49 || v48 >= 0x80 )
              return -1073740010;
            *(_WORD *)v9 = v48;
            v9 += 2;
          }
        }
        else
        {
          v12 += 4;
          *a7 = 0;
          v19 = (unsigned __int16 *)(v16 - 2);
          do
          {
            if ( v19 < v12 )
            {
              v21 = 0;
              goto LABEL_21;
            }
            v20 = *v19--;
          }
          while ( v20 != 45 );
          v21 = v19 + 1;
LABEL_21:
          if ( v21 == (unsigned __int16 *)(v16 - 2) )
            return -1073740010;
          if ( v21 && v21 > v12 )
          {
            v22 = v21 - v12;
            v23 = v12;
            if ( v12 != v21 )
            {
              do
              {
                if ( v9 >= v50 )
                  break;
                if ( !v14 )
                {
                  if ( a6 && !ValidateStd3Range(*v23) )
                    return -1073740010;
                  v24 = *v23;
                  if ( v24 < 0x20 || v24 == 127 )
                    return -1073740010;
                }
                v25 = *v23;
                if ( !*v23 || v25 >= 0x80 )
                  return -1073740010;
                if ( !v14 && v25 >= 0x41 && v25 <= 0x5A )
                  LOWORD(v25) = v25 + 32;
                *(_WORD *)v9 = v25;
                v9 += 2;
                ++v23;
                varg_r2[0] = (int)v9;
              }
              while ( v23 != v21 );
              if ( v23 != v21 )
                return -1073740010;
            }
          }
          else
          {
            v22 = 0;
          }
          if ( v22 <= 0 )
            v26 = 0;
          else
            v26 = v22 + 1;
          v27 = &v12[v26];
          v54 = 128;
          v28 = 72;
          v55 = 0;
          v53 = 72;
          v29 = 0;
          if ( v27 < (unsigned __int16 *)v16 )
          {
LABEL_46:
            v60 = v29;
            v30 = 1;
            v31 = 36;
            v32 = 36 - v28;
            while ( 1 )
            {
              v52 = v32;
              if ( v27 >= (unsigned __int16 *)v16 )
                return -1073740010;
              v33 = *v27;
              v56 = v27 + 1;
              if ( v33 < 0x30 || v33 > 0x39 )
              {
                if ( v33 < 0x61 || v33 > 0x7A )
                  v34 = v33 < 0x41 || v33 > 0x5A ? -1 : v33 - 65;
                else
                  v34 = v33 - 97;
              }
              else
              {
                v34 = v33 - 22;
              }
              if ( v34 < 0 )
                return -1073740010;
              if ( !v30 )
                __brkdiv0();
              if ( v34 > (0x7FFFFFF - v29) / v30 )
                return -1073740010;
              v29 += v34 * v30;
              if ( v31 > v53 )
              {
                if ( v31 < v53 + 26 )
                  v35 = v52;
                else
                  v35 = 26;
              }
              else
              {
                v35 = 1;
              }
              if ( v34 < v35 )
              {
                v36 = ((v9 - v51) >> 1) - v55;
                v53 = adapt(v29 - v60, v36 + 1, v60 == 0);
                v37 = v36 + 1;
                if ( v36 == -1 )
                  __brkdiv0();
                v39 = v29 % v37;
                v38 = v29 / v37;
                v40 = v39;
                if ( v38 > 0x7FFFFFF - v54 )
                  return -1073740010;
                v54 += v38;
                if ( (unsigned int)(v54 - 128) > 0x10FF7F || v54 >= 55296 && v54 <= 57343 )
                  return -1073740010;
                if ( v55 <= 0 )
                {
                  v41 = (__int16 *)&v51[2 * v39];
                }
                else
                {
                  v41 = (__int16 *)v51;
                  if ( v40 > 0 )
                  {
                    while ( v41 < (__int16 *)v9 )
                    {
                      if ( IsSurrogate((unsigned __int16)*v41) )
                        v42 += 2;
                      v41 = (__int16 *)(v42 + 2);
                      if ( v43 - 1 <= 0 )
                        goto LABEL_86;
                    }
                    return -1073740010;
                  }
                }
LABEL_86:
                if ( v54 >= 0x10000 )
                {
                  if ( v9 >= v50 - 2 || v41 > (__int16 *)v9 )
                    return -1073740010;
                  InsertChar((v54 - 0x10000) / 1024 - 10240, v41, varg_r2);
                  InsertChar((v54 - 0x10000) % 1024 - 9216, (__int16 *)(v44 + 2), varg_r2);
                  ++v55;
                }
                else
                {
                  if ( v9 >= v50 || v41 > (__int16 *)v9 )
                    return -1073740010;
                  InsertChar(v54, v41, varg_r2);
                }
                v27 = v56;
                v9 = (char *)varg_r2[0];
                v29 = v40 + 1;
                if ( v56 < (unsigned __int16 *)v16 )
                {
                  v28 = v53;
                  goto LABEL_46;
                }
                v14 = v58;
                v8 = v61;
                break;
              }
              if ( 36 == v35 )
                __brkdiv0();
              if ( v30 > 0x7FFFFFF / (36 - v35) )
                return -1073740010;
              ++v27;
              v30 *= 36 - v35;
              v32 = v52 + 36;
              v31 += 36;
            }
          }
          v45 = (unsigned int)v50;
          v13 = v51;
          v11 = v57;
        }
        if ( !v14 && ((int)((v16 - (char *)v12) & 0xFFFFFFFE) > 126 || v9 == v13) )
          return -1073740010;
        if ( v16 != v11 )
        {
          if ( (unsigned int)v9 >= v45 )
            return -1073740010;
          *(_WORD *)v9 = *(_WORD *)v16;
          v9 += 2;
          varg_r2[0] = (int)v9;
        }
        if ( v14 )
        {
          v14 = 0;
          v58 = 0;
          v59 = v16;
          *a8 = &v9[-2 * (v16 != v11)];
          if ( v16 == v11 - 2 )
            return -1073740010;
        }
        v12 = (unsigned __int16 *)(v16 + 2);
        v13 = v9;
        v51 = v9;
        if ( v16 >= v11 )
          goto LABEL_121;
      }
      if ( v14 || v15 != (unsigned __int16 *)v11 )
        return -1073740010;
LABEL_121:
      if ( v9 != v62 && (v11 - v59) >> 1 <= (*((_WORD *)v11 - 1) == 46) + 255 )
      {
        *a4 = (v9 - v62) >> 1;
        return 0;
      }
    }
  }
  return -1073740010;
}
