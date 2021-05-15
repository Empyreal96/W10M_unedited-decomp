// RtlDecompressBufferXpressLzProgress 
 
int __fastcall RtlDecompressBufferXpressLzProgress(_BYTE *a1, unsigned int a2, unsigned __int8 *a3, unsigned int a4, _DWORD *a5, int a6, int a7)
{
  int v8; // r2
  int result; // r0
  unsigned int v10; // r10
  unsigned int v11; // lr
  _BYTE *v12; // r4
  unsigned int v13; // r9
  unsigned int v14; // r0
  unsigned __int8 *v15; // r8
  int v16; // r6
  int v17; // t1
  int v18; // r7
  char v19; // t1
  __int16 v20; // t1
  int v21; // t1
  int v22; // t1
  unsigned int v23; // t1
  int v24; // r6
  unsigned int v25; // r2
  char v26; // r3
  int v27; // r6
  int v28; // r6
  int v29; // r6
  _BYTE *v30; // r8
  int v31; // r6
  char *j; // r8
  unsigned int v33; // lr
  _BYTE *v34; // r2
  int v35; // r1
  unsigned int v36; // r3
  int v37; // r6
  char v38; // r3
  int v39; // r6
  int v40; // r6
  int v41; // t1
  int v42; // r6
  _BYTE *v43; // r8
  int v44; // r6
  char *i; // r8
  int v46; // t1
  __int16 v47; // t1
  char v48; // t1
  int v49; // t1
  int v50; // r1
  unsigned int v51; // r9
  _BYTE *v52; // r1
  __int16 v53; // r3
  char v54; // t1
  unsigned int v55; // t1
  int v56; // r2
  int v57; // r1
  char v58; // r3
  int v59; // r2
  int v60; // r2
  int v61; // r2
  _BYTE *v62; // r3
  int v63; // r2
  int v64; // r0
  unsigned __int8 *v65; // [sp+0h] [bp-38h]
  unsigned int v66; // [sp+4h] [bp-34h]
  unsigned int v67; // [sp+8h] [bp-30h]
  unsigned int v68; // [sp+Ch] [bp-2Ch]
  int v69[10]; // [sp+10h] [bp-28h] BYREF

  v8 = 4096;
  v68 = (unsigned int)a1;
  if ( a4 < 5 )
    return -1073741246;
  v10 = (unsigned int)&a3[a4];
  v11 = (unsigned int)&a1[a2 - 352];
  v66 = v11;
  v67 = (unsigned int)&a1[a2];
  v12 = a1;
  v13 = (unsigned int)&a3[a4 - 86];
  if ( !a6 || a2 < 0x1000 )
    v8 = a2;
  v69[0] = a6;
  v14 = (unsigned int)&a1[v8];
  v15 = 0;
  v69[1] = a7;
  v69[2] = v8;
  if ( v11 < v14 )
    v14 = v11;
  v65 = 0;
  while ( 1 )
  {
    __pld(a3 + 48);
    __pld(a3 + 64);
    v17 = *(_DWORD *)a3;
    a3 += 4;
    v16 = v17;
    if ( (unsigned int)a3 >= v13 )
    {
      while ( 1 )
      {
        if ( (unsigned int)v12 >= v14 )
        {
          if ( (unsigned int)v12 >= v11 )
            goto LABEL_135;
          v14 = RtlpMakeXpressCallback(v69, v11, v12);
          v11 = v66;
        }
        if ( v16 >= 0 )
        {
          v18 = 2 * v16 + 1;
          goto LABEL_109;
        }
        v18 = 2 * v16 + 1;
        do
        {
          if ( a3 == (unsigned __int8 *)v10 )
          {
            v33 = v67;
            goto LABEL_131;
          }
          if ( (unsigned int)(a3 + 1) >= v10 )
          {
            v33 = v67;
            if ( (unsigned int)v12 < v67 )
              return -1073741246;
LABEL_131:
            v51 = v68;
            goto LABEL_143;
          }
          v36 = *(unsigned __int16 *)a3;
          a3 += 2;
          v37 = v36 & 7;
          v25 = (v36 >> 3) + 1;
          if ( v37 == 7 )
          {
            if ( v15 )
            {
              v39 = *v15 >> 4;
              v65 = 0;
            }
            else
            {
              if ( (unsigned int)a3 >= v10 )
                return -1073741246;
              v65 = a3;
              v38 = *a3++;
              v39 = v38 & 0xF;
            }
            if ( v39 == 15 )
            {
LABEL_78:
              if ( (unsigned int)a3 >= v10 )
                return -1073741246;
              v41 = *a3++;
              v40 = v41;
              if ( v41 == 255 )
              {
                if ( (unsigned int)(a3 + 1) >= v10 )
                  return -1073741246;
                v42 = *(unsigned __int16 *)a3;
                a3 += 2;
                if ( !v42 )
                {
                  if ( (unsigned int)(a3 + 3) >= v10 )
                    return -1073741246;
                  v42 = *(_DWORD *)a3;
                  a3 += 4;
                }
                if ( v42 < 22 || &v12[v42 + 3] < v12 )
                  return -1073741246;
                v40 = v42 - 22;
              }
              v39 = v40 + 15;
            }
            v37 = v39 + 7;
          }
          v43 = &v12[-v25];
          v44 = v37 + 3;
          if ( (unsigned int)&v12[-v25] < v68 )
            return -1073741246;
          if ( v25 >= 4 )
            goto LABEL_97;
          *v12 = *v43;
          if ( v25 == 1 )
          {
            v44 -= 3;
            v12[1] = *v43;
            v12[2] = *v43;
            v12 += 3;
          }
          else
          {
            v12[1] = v43[1];
            if ( v25 == 2 )
            {
              v44 -= 2;
              v12 += 2;
            }
            else
            {
              v12[2] = v43[2];
              v12 += 3;
              v44 -= 3;
            }
          }
          if ( v44 )
          {
LABEL_97:
            *(_DWORD *)v12 = *(_DWORD *)v43;
            *((_DWORD *)v12 + 1) = *((_DWORD *)v43 + 1);
            if ( v44 >= 9 )
            {
              v12 += 8;
              v44 -= 8;
              for ( i = v43 + 8; ; i += 16 )
              {
                if ( (unsigned int)v12 >= v14 )
                {
                  if ( (unsigned int)v12 >= v11 )
                  {
                    v33 = v67;
                    v34 = &v12[v44];
                    if ( (unsigned int)&v12[v44] > v67 )
                      return -1073741246;
                    if ( v44 )
                    {
                      v50 = i - v12;
                      do
                      {
                        --v44;
                        *v12 = v12[v50];
                        ++v12;
                      }
                      while ( v44 );
                    }
LABEL_127:
                    v15 = v65;
                    v12 = v34;
                    goto LABEL_131;
                  }
                  v14 = RtlpMakeXpressCallback(v69, v11, v12);
                }
                if ( v44 > 32 )
                  __pld(i + 32);
                *(_DWORD *)v12 = *(_DWORD *)i;
                *((_DWORD *)v12 + 1) = *((_DWORD *)i + 1);
                *((_DWORD *)v12 + 2) = *((_DWORD *)i + 2);
                *((_DWORD *)v12 + 3) = *((_DWORD *)i + 3);
                if ( v44 < 17 )
                  break;
                v11 = v66;
                v12 += 16;
                v44 -= 16;
              }
            }
            v12 += v44;
          }
          while ( 2 )
          {
            if ( v18 >= 0 )
            {
              v18 *= 2;
LABEL_109:
              if ( v18 < 0 )
              {
                if ( (unsigned int)a3 >= v10 )
                  return -1073741246;
                v48 = *a3++;
                *v12++ = v48;
              }
              else
              {
                v18 *= 2;
                if ( v18 < 0 )
                {
                  if ( (unsigned int)(a3 + 1) >= v10 )
                    return -1073741246;
                  v47 = *(_WORD *)a3;
                  a3 += 2;
                  *(_WORD *)v12 = v47;
                  v12 += 2;
                }
                else
                {
                  v18 *= 2;
                  if ( v18 >= 0 )
                  {
                    v18 *= 2;
                    if ( (unsigned int)(a3 + 3) >= v10 )
                      return -1073741246;
                    v46 = *(_DWORD *)a3;
                    a3 += 4;
                    *(_DWORD *)v12 = v46;
                    v12 += 4;
                    continue;
                  }
                  if ( (unsigned int)(a3 + 2) >= v10 )
                    return -1073741246;
                  *(_WORD *)v12 = *(_WORD *)a3;
                  v12[2] = a3[2];
                  v12 += 3;
                  a3 += 3;
                }
              }
            }
            break;
          }
          v15 = v65;
          v11 = v66;
          v18 *= 2;
        }
        while ( v18 );
        if ( (unsigned int)(a3 + 3) >= v10 )
          return -1073741246;
        v49 = *(_DWORD *)a3;
        a3 += 4;
        v16 = v49;
      }
    }
    if ( (unsigned int)v12 >= v14 )
      break;
LABEL_13:
    if ( v16 >= 0 )
    {
      v18 = 2 * v16 + 1;
      goto LABEL_16;
    }
    v18 = 2 * v16 + 1;
    do
    {
      v23 = *(unsigned __int16 *)a3;
      a3 += 2;
      v24 = v23 & 7;
      v25 = (v23 >> 3) + 1;
      if ( v24 == 7 )
      {
        if ( v15 )
        {
          v27 = *v15 >> 4;
          v65 = 0;
        }
        else
        {
          v65 = a3;
          v26 = *a3++;
          v27 = v26 & 0xF;
        }
        if ( v27 == 15 )
        {
          if ( (unsigned int)(a3 + 7) >= v13 )
            goto LABEL_78;
          v28 = *a3++;
          if ( v28 == 255 )
          {
            v29 = *(unsigned __int16 *)a3;
            a3 += 2;
            if ( !v29 )
            {
              v29 = *(_DWORD *)a3;
              a3 += 4;
            }
            if ( v29 < 22 || &v12[v29 + 3] < v12 )
              return -1073741246;
            v28 = v29 - 22;
          }
          v27 = v28 + 15;
        }
        v24 = v27 + 7;
      }
      v30 = &v12[-v25];
      v31 = v24 + 3;
      if ( (unsigned int)&v12[-v25] < v68 )
        return -1073741246;
      if ( v25 >= 4 )
        goto LABEL_46;
      *v12 = *v30;
      if ( v25 == 1 )
      {
        v31 -= 3;
        v12[1] = *v30;
        v12[2] = *v30;
        v12 += 3;
      }
      else
      {
        v12[1] = v30[1];
        if ( v25 == 2 )
        {
          v31 -= 2;
          v12 += 2;
        }
        else
        {
          v12[2] = v30[2];
          v12 += 3;
          v31 -= 3;
        }
      }
      if ( v31 )
      {
LABEL_46:
        *(_DWORD *)v12 = *(_DWORD *)v30;
        *((_DWORD *)v12 + 1) = *((_DWORD *)v30 + 1);
        if ( v31 >= 9 )
        {
          v12 += 8;
          v31 -= 8;
          for ( j = v30 + 8; ; j += 16 )
          {
            if ( (unsigned int)v12 >= v14 )
            {
              if ( (unsigned int)v12 >= v11 )
              {
                v33 = v67;
                v34 = &v12[v31];
                if ( (unsigned int)&v12[v31] <= v67 )
                {
                  if ( v31 )
                  {
                    v35 = j - v12;
                    do
                    {
                      --v31;
                      *v12 = v12[v35];
                      ++v12;
                    }
                    while ( v31 );
                  }
                  goto LABEL_127;
                }
                return -1073741246;
              }
              v14 = RtlpMakeXpressCallback(v69, v11, v12);
            }
            if ( v31 > 32 )
              __pld(j + 32);
            *(_DWORD *)v12 = *(_DWORD *)j;
            *((_DWORD *)v12 + 1) = *((_DWORD *)j + 1);
            *((_DWORD *)v12 + 2) = *((_DWORD *)j + 2);
            *((_DWORD *)v12 + 3) = *((_DWORD *)j + 3);
            if ( v31 < 17 )
              break;
            v11 = v66;
            v12 += 16;
            v31 -= 16;
          }
        }
        v12 += v31;
      }
      v15 = v65;
      v11 = v66;
      if ( v18 >= 0 )
      {
        for ( v18 *= 2; ; v18 *= 2 )
        {
LABEL_16:
          if ( v18 < 0 )
          {
            v19 = *a3++;
            *v12++ = v19;
            goto LABEL_23;
          }
          v18 *= 2;
          if ( v18 < 0 )
          {
            v20 = *(_WORD *)a3;
            a3 += 2;
            *(_WORD *)v12 = v20;
            v12 += 2;
            goto LABEL_23;
          }
          v18 *= 2;
          if ( v18 < 0 )
            break;
          v22 = *(_DWORD *)a3;
          a3 += 4;
          v18 *= 2;
          *(_DWORD *)v12 = v22;
          v12 += 4;
          if ( v18 < 0 )
            goto LABEL_23;
        }
        v21 = *(_DWORD *)a3;
        a3 += 3;
        *(_DWORD *)v12 = v21;
        v12 += 3;
      }
LABEL_23:
      v18 *= 2;
    }
    while ( v18 );
  }
  if ( (unsigned int)v12 < v11 )
  {
    v14 = RtlpMakeXpressCallback(v69, v11, v12);
    v11 = v66;
    goto LABEL_13;
  }
LABEL_135:
  v33 = v67;
  v51 = v68;
LABEL_136:
  if ( v16 >= 0 )
  {
    v18 = 2 * v16 + 1;
LABEL_138:
    if ( v18 >= 0 )
    {
      v18 *= 2;
      if ( (unsigned int)(a3 + 2) > v10 )
        return -1073741246;
      v52 = v12 + 2;
      if ( (unsigned int)(v12 + 2) > v33 )
        return -1073741246;
      v53 = *(_WORD *)a3;
      a3 += 2;
      *(_WORD *)v12 = v53;
      goto LABEL_142;
    }
    if ( (unsigned int)a3 >= v10 || (unsigned int)v12 >= v33 )
      return -1073741246;
    v54 = *a3++;
    *v12++ = v54;
    goto LABEL_132;
  }
  v18 = 2 * v16 + 1;
  while ( 1 )
  {
    if ( a3 == (unsigned __int8 *)v10 )
      goto LABEL_175;
    if ( (unsigned int)(a3 + 1) >= v10 )
      break;
    v55 = *(unsigned __int16 *)a3;
    a3 += 2;
    v56 = v55 & 7;
    v57 = (v55 >> 3) + 1;
    if ( v56 == 7 )
    {
      if ( v15 )
      {
        v59 = *v15 >> 4;
        v65 = 0;
      }
      else
      {
        if ( (unsigned int)a3 >= v10 )
          return -1073741246;
        v65 = a3;
        v58 = *a3++;
        v59 = v58 & 0xF;
      }
      if ( v59 == 15 )
      {
        if ( (unsigned int)a3 >= v10 )
          return -1073741246;
        v60 = *a3++;
        if ( v60 == 255 )
        {
          if ( (unsigned int)(a3 + 1) >= v10 )
            return -1073741246;
          v61 = *(unsigned __int16 *)a3;
          a3 += 2;
          if ( !v61 )
          {
            if ( (unsigned int)(a3 + 3) >= v10 )
              return -1073741246;
            v61 = *(_DWORD *)a3;
            a3 += 4;
          }
          if ( v61 < 22 || &v12[v61 + 3] < v12 )
            return -1073741246;
          v60 = v61 - 22;
        }
        v59 = v60 + 15;
      }
      v56 = v59 + 7;
    }
    v62 = &v12[-v57];
    v63 = v56 + 3;
    if ( (unsigned int)&v12[-v57] < v51 )
      return -1073741246;
    v52 = &v12[v63];
    if ( (unsigned int)&v12[v63] > v33 )
      return -1073741246;
    if ( v63 )
    {
      v64 = v62 - v12;
      do
      {
        --v63;
        *v12 = v12[v64];
        ++v12;
      }
      while ( v63 );
    }
    v15 = v65;
LABEL_142:
    v12 = v52;
LABEL_143:
    if ( v18 >= 0 )
    {
      v18 *= 2;
      goto LABEL_138;
    }
LABEL_132:
    v18 *= 2;
    if ( !v18 )
    {
      if ( (unsigned int)(a3 + 3) >= v10 )
        return -1073741246;
      v16 = *(_DWORD *)a3;
      a3 += 4;
      goto LABEL_136;
    }
  }
  if ( (unsigned int)v12 < v33 )
    return -1073741246;
LABEL_175:
  result = 0;
  *a5 = &v12[-v68];
  return result;
}
