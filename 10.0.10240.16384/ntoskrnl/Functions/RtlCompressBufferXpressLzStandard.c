// RtlCompressBufferXpressLzStandard 
 
int __fastcall RtlCompressBufferXpressLzStandard(_BYTE *a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, _DWORD *a6, int a7, int a8, unsigned int a9)
{
  int v9; // r9
  unsigned int v10; // r4
  unsigned __int8 *v11; // r2
  char *v12; // lr
  unsigned int v13; // r10
  int v14; // r4
  _DWORD *v15; // r4
  unsigned __int8 *v16; // r5
  int v17; // r8
  _BYTE *v18; // r7
  _DWORD *v19; // r3
  _DWORD *v20; // r2
  _DWORD *v21; // r1
  int v22; // r0
  unsigned __int8 *v23; // r6
  int v24; // r1
  int v25; // r2
  int v26; // r4
  int v27; // r0
  unsigned __int8 *v28; // r1
  unsigned __int8 v29; // r3
  char v30; // t2
  int v31; // r2
  char v32; // t2
  int v33; // r0
  unsigned __int8 *v34; // r1
  int v35; // r2
  unsigned __int8 v36; // r4
  char v37; // t2
  unsigned __int8 v38; // r1
  char v39; // t2
  int v40; // r0
  unsigned __int8 *v41; // r1
  int v42; // r2
  unsigned int v43; // r2
  __int16 v44; // r3
  unsigned int v45; // r2
  char v46; // r3
  unsigned int v47; // r2
  unsigned int v48; // r2
  _WORD *v49; // r7
  int v50; // r3
  char v51; // t1
  int v53; // r3
  _DWORD *v54; // [sp+0h] [bp-50h]
  unsigned int v55; // [sp+4h] [bp-4Ch]
  char *v56; // [sp+8h] [bp-48h]
  unsigned int v57; // [sp+Ch] [bp-44h]
  unsigned __int8 *v58; // [sp+10h] [bp-40h]
  unsigned int v59; // [sp+14h] [bp-3Ch]
  int v60; // [sp+18h] [bp-38h]
  int v61; // [sp+18h] [bp-38h]
  int v62; // [sp+1Ch] [bp-34h]
  int v63; // [sp+1Ch] [bp-34h]
  unsigned __int8 *v64; // [sp+20h] [bp-30h]
  int v66[10]; // [sp+28h] [bp-28h] BYREF

  v9 = a3;
  v10 = a3 + a4;
  v11 = &a1[a2];
  v58 = &a1[a2];
  v59 = v10;
  if ( a4 < 0x40 || a2 < 8 )
    return -1073741789;
  v12 = 0;
  v56 = 0;
  v57 = v10 - 41;
  v13 = (unsigned int)(v11 - 38);
  if ( !a7 || (v14 = a9, a9 > a2) )
    v14 = a2;
  v55 = (unsigned int)&a1[v14];
  if ( v13 < (unsigned int)&a1[v14] )
    v55 = (unsigned int)(v11 - 38);
  v66[0] = a7;
  v66[1] = a8;
  v66[2] = v14;
  v15 = (_DWORD *)v9;
  v16 = a1 + 1;
  *(_BYTE *)(v9 + 4) = *a1;
  v17 = 2;
  v54 = (_DWORD *)v9;
  v18 = (_BYTE *)(v9 + 5);
  if ( a2 >= 0x40 )
  {
    v19 = a6;
    do
      *v19++ = a1;
    while ( v19 != a6 + 2806 );
    v20 = a6 + 2806;
    do
      *v20++ = a1;
    while ( v20 != a6 + 7652 );
    v15 = (_DWORD *)v9;
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = &a6[*v16];
        v22 = v16[2] + 4 * v16[1];
        v23 = (unsigned __int8 *)v21[2 * v22];
        v21[2 * v22] = v16;
        v24 = *v16;
        if ( *v23 == v24 && v23[1] == v16[1] && v23[2] == v16[2] && v16 - v23 < 0x2000 )
          break;
        ++v16;
        *v18++ = v24;
        if ( v17 <= 0 )
        {
          *v15 = 2 * v17;
          v15 = v18;
          v18 += 4;
          v17 = 1;
          v54 = v15;
          if ( (unsigned int)v16 >= v55 )
          {
            if ( (unsigned int)v16 >= v13 )
              goto LABEL_93;
            v12 = v56;
            v55 = RtlpMakeXpressCallback(v66, v13, v16);
          }
          if ( (unsigned int)v18 >= v57 )
          {
LABEL_93:
            v11 = v58;
            v9 = a3;
            goto LABEL_94;
          }
        }
        else
        {
          v17 *= 2;
        }
      }
      v25 = v16[3];
      v26 = v23[3];
      v64 = v16;
      if ( v25 != v26 )
      {
        v27 = *v16 + 2 * v22;
        v28 = (unsigned __int8 *)a6[v25 + 2806 + v27];
        a6[v26 + 2806 + v27] = v23;
        if ( v16 - v28 >= 0x2000 || *(_DWORD *)v16 != *(_DWORD *)v28 )
          goto LABEL_24;
        v23 = v28;
        a6[v16[3] + 2806 + v27] = v16;
      }
      v60 = v16[4];
      v62 = v23[4];
      if ( v60 != v62 )
      {
        v29 = v16[2] + v16[1] + 97;
        v30 = __ROR4__((unsigned __int16)(v29 | (v29 << 8)), 1);
        v31 = (unsigned __int8)__ROR4__(
                                 (unsigned __int16)((unsigned __int8)(*v16 ^ v30) | ((unsigned __int8)(*v16 ^ v30) << 8)),
                                 5);
        v32 = __ROR4__(
                (unsigned __int16)((unsigned __int8)(v16[3] + *v16) | ((unsigned __int8)(v16[3] + *v16) << 8)),
                5);
        v33 = (unsigned __int8)__ROR4__(
                                 (unsigned __int16)((unsigned __int8)(v16[1] ^ v32) | ((unsigned __int8)(v16[1] ^ v32) << 8)),
                                 1)
            + 4 * v31;
        v34 = (unsigned __int8 *)a6[2 * v33 + 2806 + v60];
        a6[2 * v33 + 2806 + v62] = v23;
        if ( v16 - v34 >= 0x2000 || *(_DWORD *)v16 != *(_DWORD *)v34 || (v35 = v16[4], v35 != v34[4]) || v16 == v34 )
        {
          v16 += 4;
          LOWORD(v23) = (_WORD)v23 + 4;
          goto LABEL_67;
        }
        a6[2 * v33 + 2806 + v35] = v16;
        v23 = v34;
      }
      v61 = v23[5];
      v63 = v16[5];
      if ( v63 != v61 )
      {
        v36 = v16[4];
        v37 = __ROR4__((unsigned __int16)(*v16 | (*v16 << 8)), 1);
        v38 = __ROR4__(
                (unsigned __int16)((unsigned __int8)((v37 + 69) ^ v36) | ((unsigned __int8)((v37 + 69) ^ v36) << 8)),
                5);
        v39 = __ROR4__((unsigned __int16)(v16[3] | (v16[3] << 8)), 5);
        v40 = (v16[2] ^ (unsigned __int8)__ROR4__((unsigned __int16)(*v16 | (*v16 << 8)), -v36))
            + 4
            * ((unsigned __int8)__ROR4__(
                                  (unsigned __int16)((unsigned __int8)(v16[1] ^ v39) | ((unsigned __int8)(v16[1] ^ v39) << 8)),
                                  1)
             + v38);
        v41 = (unsigned __int8 *)a6[2 * v40 + 2806 + v63];
        a6[2 * v40 + 2806 + v61] = v23;
        if ( v16 - v41 >= 0x2000
          || *(_DWORD *)v16 != *(_DWORD *)v41
          || v16[4] != v41[4]
          || (v42 = v16[5], v42 != v41[5])
          || v16 == v41 )
        {
          v16 += 5;
          LOWORD(v23) = (_WORD)v23 + 5;
          goto LABEL_67;
        }
        a6[2 * v40 + 2806 + v42] = v16;
        v23 = v41;
      }
      v16 += 6;
      for ( v23 += 6; ; v23 += 32 )
      {
        if ( (unsigned int)v16 >= v13 )
        {
          while ( v16 < v58 && *v16 == *v23 )
          {
            ++v16;
            ++v23;
          }
          goto LABEL_67;
        }
        if ( *(_DWORD *)v16 != *(_DWORD *)v23 )
          goto LABEL_59;
        if ( *((_DWORD *)v16 + 1) != *((_DWORD *)v23 + 1) )
          break;
        if ( *((_DWORD *)v16 + 2) != *((_DWORD *)v23 + 2) )
        {
          v16 += 8;
          v23 += 8;
          goto LABEL_59;
        }
        if ( *((_DWORD *)v16 + 3) != *((_DWORD *)v23 + 3) )
        {
          v16 += 12;
          v23 += 12;
          goto LABEL_59;
        }
        if ( *((_DWORD *)v16 + 4) != *((_DWORD *)v23 + 4) )
        {
          v16 += 16;
          v23 += 16;
          goto LABEL_59;
        }
        if ( *((_DWORD *)v16 + 5) != *((_DWORD *)v23 + 5) )
        {
          v16 += 20;
          v23 += 20;
          goto LABEL_59;
        }
        if ( *((_DWORD *)v16 + 6) != *((_DWORD *)v23 + 6) )
        {
          v16 += 24;
          v23 += 24;
          goto LABEL_59;
        }
        if ( *((_DWORD *)v16 + 7) != *((_DWORD *)v23 + 7) )
        {
          v16 += 28;
          v23 += 28;
          goto LABEL_59;
        }
        v16 += 32;
      }
      v16 += 4;
      v23 += 4;
LABEL_59:
      if ( *v16 == *v23 )
      {
        if ( v16[1] != v23[1] )
        {
          ++v16;
          LOWORD(v23) = (_WORD)v23 + 1;
          goto LABEL_67;
        }
        if ( v16[2] != v23[2] )
        {
          v16 += 2;
          LOWORD(v23) = (_WORD)v23 + 2;
          goto LABEL_67;
        }
LABEL_24:
        v16 += 3;
        LOWORD(v23) = (_WORD)v23 + 3;
      }
LABEL_67:
      v43 = v16 - v64 - 3;
      v44 = 8 * ((_WORD)v16 - (_WORD)v23 - 1);
      if ( v43 >= 7 )
      {
        v45 = v16 - v64 - 10;
        *(_WORD *)v18 = v44 | 7;
        v18 += 2;
        if ( v12 )
        {
          v46 = *v12;
          if ( v45 >= 0xF )
          {
            *v12 = v46 | 0xF0;
            v56 = 0;
LABEL_76:
            v47 = v16 - v64 - 25;
            if ( v47 >= 0xFF )
            {
              v48 = v16 - v64 - 3;
              *v18 = -1;
              v49 = v18 + 1;
              if ( v48 >= 0x10000 )
              {
                *v49 = 0;
                v18 = v49 + 3;
                *((_DWORD *)v18 - 1) = v48;
              }
              else
              {
                *v49 = v48;
                v18 = v49 + 1;
              }
            }
            else
            {
              *v18++ = v47;
            }
            goto LABEL_81;
          }
          *v12 = v46 | (16 * v45);
          v56 = 0;
        }
        else
        {
          v56 = v18;
          if ( v45 >= 0xF )
          {
            *v18++ = 15;
            goto LABEL_76;
          }
          *v18++ = v45;
        }
      }
      else
      {
        *(_WORD *)v18 = v44 + v43;
        v18 += 2;
      }
LABEL_81:
      v50 = 2 * v17;
      if ( v17 <= 0 )
      {
        v15 = v18;
        *v54 = v50 + 1;
        v17 = 1;
        v54 = v18;
        v18 += 4;
      }
      else
      {
        v15 = v54;
        v17 = v50 + 1;
      }
      if ( (unsigned int)v16 >= v55 )
      {
        if ( (unsigned int)v16 >= v13 )
          goto LABEL_93;
        v55 = RtlpMakeXpressCallback(v66, v13, v16);
      }
      if ( (unsigned int)v18 >= v57 )
        goto LABEL_93;
      v12 = v56;
    }
  }
LABEL_94:
  while ( v16 < v11 )
  {
    if ( (unsigned int)v18 >= v59 )
      return -1073741789;
    v51 = *v16++;
    *v18++ = v51;
    if ( v17 <= 0 )
    {
      *v15 = 2 * v17;
      v15 = v18;
      v18 += 4;
      v17 = 1;
    }
    else
    {
      v17 *= 2;
    }
  }
  if ( (unsigned int)v18 >= v59 )
    return -1073741789;
  while ( 1 )
  {
    v53 = 2 * v17;
    if ( v17 <= 0 )
      break;
    v17 = v53 + 1;
  }
  *v15 = v53 + 1;
  *a5 = &v18[-v9];
  if ( (unsigned int)&v18[-v9] < 8 )
    *a5 = 8;
  return 0;
}
