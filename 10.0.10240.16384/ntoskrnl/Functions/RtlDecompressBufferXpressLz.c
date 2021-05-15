// RtlDecompressBufferXpressLz 
 
int __fastcall RtlDecompressBufferXpressLz(_BYTE *a1, int a2, unsigned __int8 *a3, unsigned int a4, int a5, _DWORD *a6)
{
  int result; // r0
  unsigned int v7; // r7
  unsigned int v8; // r10
  unsigned int v9; // lr
  unsigned int v10; // r8
  _BYTE *v11; // r1
  unsigned __int8 *v12; // r9
  int v13; // r3
  int v14; // t1
  int i; // r4
  char v16; // t1
  unsigned int v17; // t1
  int v18; // r0
  unsigned int v19; // r6
  char v20; // r3
  int v21; // r0
  __int16 v22; // t1
  int v23; // t1
  int v24; // t1
  unsigned int v25; // r3
  int v26; // r0
  int v27; // r0
  _BYTE *v28; // r5
  int v29; // r0
  char *v30; // r5
  _BYTE *v31; // r6
  int v32; // r5
  unsigned int v33; // lr
  unsigned int v34; // t1
  int v35; // r0
  char v36; // r3
  int v37; // r0
  unsigned int v38; // r3
  int v39; // r0
  int v40; // t1
  int v41; // r0
  int v42; // r0
  _BYTE *v43; // r5
  int v44; // r6
  __int16 v45; // r3
  char v46; // t1
  int v47; // t1
  unsigned int v48; // [sp+0h] [bp-20h]

  v48 = (unsigned int)a1;
  if ( a4 >= 5 )
  {
    v7 = (unsigned int)&a3[a4];
    v8 = (unsigned int)&a1[a2];
    v9 = (unsigned int)&a3[a4 - 86];
    v10 = (unsigned int)&a1[a2 - 352];
    v11 = a1;
    v12 = 0;
    while ( 1 )
    {
      __pld(a3 + 48);
      __pld(a3 + 64);
      v14 = *(_DWORD *)a3;
      a3 += 4;
      v13 = v14;
      if ( (unsigned int)a3 >= v9 || (unsigned int)v11 >= v10 )
      {
        v33 = v48;
        while ( v13 < 0 )
        {
          i = 2 * v13 + 1;
          do
          {
            if ( a3 == (unsigned __int8 *)v7 )
              goto LABEL_98;
            if ( (unsigned int)(a3 + 1) >= v7 )
            {
              if ( (unsigned int)v11 < v8 )
                return -1073741246;
LABEL_98:
              result = 0;
              *a6 = &v11[-v48];
              return result;
            }
            v34 = *(unsigned __int16 *)a3;
            a3 += 2;
            v35 = v34 & 7;
            v19 = (v34 >> 3) + 1;
            if ( v35 == 7 )
            {
              if ( v12 )
              {
                v38 = *v12;
                v12 = 0;
                v37 = v38 >> 4;
              }
              else
              {
                if ( (unsigned int)a3 >= v7 )
                  return -1073741246;
                v12 = a3;
                v36 = *a3++;
                v37 = v36 & 0xF;
              }
              if ( v37 == 15 )
              {
LABEL_68:
                if ( (unsigned int)a3 >= v7 )
                  return -1073741246;
                v40 = *a3++;
                v39 = v40;
                if ( v40 == 255 )
                {
                  if ( (unsigned int)(a3 + 1) >= v7 )
                    return -1073741246;
                  v41 = *(unsigned __int16 *)a3;
                  a3 += 2;
                  if ( !v41 )
                  {
                    if ( (unsigned int)(a3 + 3) >= v7 )
                      return -1073741246;
                    v41 = *(_DWORD *)a3;
                    a3 += 4;
                  }
                  if ( v41 < 22 || &v11[v41 + 3] < v11 )
                    return -1073741246;
                  v39 = v41 - 22;
                }
                v37 = v39 + 15;
              }
              v35 = v37 + 7;
            }
            v42 = v35 + 3;
            if ( (unsigned int)&v11[-v19] < v33 )
              return -1073741246;
            v43 = &v11[v42];
            if ( (unsigned int)&v11[v42] > v8 )
              return -1073741246;
            if ( v42 )
            {
              v44 = -v19;
              do
              {
                --v42;
                *v11 = v11[v44];
                ++v11;
              }
              while ( v42 );
            }
LABEL_84:
            v11 = v43;
LABEL_85:
            if ( i >= 0 )
            {
              i *= 2;
              goto LABEL_87;
            }
LABEL_94:
            i *= 2;
          }
          while ( i );
          if ( (unsigned int)(a3 + 3) >= v7 )
            return -1073741246;
          v47 = *(_DWORD *)a3;
          a3 += 4;
          v13 = v47;
        }
        i = 2 * v13 + 1;
LABEL_87:
        if ( i < 0 )
        {
          if ( (unsigned int)a3 < v7 && (unsigned int)v11 < v8 )
          {
            v46 = *a3++;
            *v11++ = v46;
            goto LABEL_94;
          }
        }
        else
        {
          i *= 2;
          if ( (unsigned int)(a3 + 2) <= v7 )
          {
            v43 = v11 + 2;
            if ( (unsigned int)(v11 + 2) <= v8 )
            {
              v45 = *(_WORD *)a3;
              a3 += 2;
              *(_WORD *)v11 = v45;
              goto LABEL_84;
            }
          }
        }
        return -1073741246;
      }
      if ( v13 < 0 )
        break;
      for ( i = 2 * v13 + 1; ; i *= 2 )
      {
        if ( i < 0 )
        {
          v16 = *a3++;
          *v11++ = v16;
          goto LABEL_11;
        }
        i *= 2;
        if ( i < 0 )
        {
          v22 = *(_WORD *)a3;
          a3 += 2;
          *(_WORD *)v11 = v22;
          v11 += 2;
          goto LABEL_11;
        }
        i *= 2;
        if ( i < 0 )
          break;
        v24 = *(_DWORD *)a3;
        a3 += 4;
        i *= 2;
        *(_DWORD *)v11 = v24;
        v11 += 4;
LABEL_47:
        if ( i < 0 )
          goto LABEL_11;
      }
      v23 = *(_DWORD *)a3;
      a3 += 3;
      *(_DWORD *)v11 = v23;
      v11 += 3;
LABEL_11:
      i *= 2;
      if ( i )
        goto LABEL_12;
    }
    i = 2 * v13 + 1;
LABEL_12:
    v17 = *(unsigned __int16 *)a3;
    a3 += 2;
    v18 = v17 & 7;
    v19 = (v17 >> 3) + 1;
    if ( v18 == 7 )
    {
      if ( v12 )
      {
        v25 = *v12;
        v12 = 0;
        v21 = v25 >> 4;
      }
      else
      {
        v12 = a3;
        v20 = *a3++;
        v21 = v20 & 0xF;
      }
      if ( v21 == 15 )
      {
        if ( (unsigned int)(a3 + 7) >= v9 )
        {
          v33 = v48;
          goto LABEL_68;
        }
        v26 = *a3++;
        if ( v26 == 255 )
        {
          v27 = *(unsigned __int16 *)a3;
          a3 += 2;
          if ( !v27 )
          {
            v27 = *(_DWORD *)a3;
            a3 += 4;
          }
          if ( v27 < 22 || &v11[v27 + 3] < v11 )
            return -1073741246;
          v26 = v27 - 22;
        }
        v21 = v26 + 15;
      }
      v18 = v21 + 7;
    }
    v28 = &v11[-v19];
    v29 = v18 + 3;
    if ( (unsigned int)&v11[-v19] >= v48 )
    {
      if ( v19 < 4 )
      {
        *v11 = *v28;
        if ( v19 == 1 )
        {
          v29 -= 3;
          v11[1] = *v28;
          v11[2] = *v28;
          v11 += 3;
        }
        else
        {
          v11[1] = v28[1];
          if ( v19 == 2 )
          {
            v29 -= 2;
            v11 += 2;
          }
          else
          {
            v11[2] = v28[2];
            v11 += 3;
            v29 -= 3;
          }
        }
        if ( !v29 )
          goto LABEL_47;
      }
      *(_DWORD *)v11 = *(_DWORD *)v28;
      *((_DWORD *)v11 + 1) = *((_DWORD *)v28 + 1);
      if ( v29 < 9 )
      {
LABEL_46:
        v11 += v29;
        goto LABEL_47;
      }
      v11 += 8;
      v30 = v28 + 8;
      v29 -= 8;
      while ( (unsigned int)v11 < v10 )
      {
        if ( v29 > 32 )
          __pld(v30 + 32);
        *(_DWORD *)v11 = *(_DWORD *)v30;
        *((_DWORD *)v11 + 1) = *((_DWORD *)v30 + 1);
        *((_DWORD *)v11 + 2) = *((_DWORD *)v30 + 2);
        *((_DWORD *)v11 + 3) = *((_DWORD *)v30 + 3);
        if ( v29 < 17 )
          goto LABEL_46;
        v11 += 16;
        v30 += 16;
        v29 -= 16;
      }
      v31 = &v11[v29];
      if ( (unsigned int)&v11[v29] <= v8 )
      {
        if ( v29 )
        {
          v32 = v30 - v11;
          do
          {
            --v29;
            *v11 = v11[v32];
            ++v11;
          }
          while ( v29 );
        }
        v11 = v31;
        v33 = v48;
        goto LABEL_85;
      }
    }
  }
  return -1073741246;
}
