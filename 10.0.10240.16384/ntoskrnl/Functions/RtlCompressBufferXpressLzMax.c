// RtlCompressBufferXpressLzMax 
 
int __fastcall RtlCompressBufferXpressLzMax(unsigned __int8 *a1, unsigned int a2, int a3, unsigned int a4, _DWORD *a5, _BYTE *a6, int a7, int a8, unsigned int a9)
{
  int v9; // r7
  unsigned __int8 *v11; // r5
  int v12; // r6
  _BYTE *v15; // r8
  unsigned int v16; // lr
  int v17; // r0
  _BYTE *v18; // r5
  int v19; // r6
  unsigned __int8 *v20; // r4
  unsigned __int8 *v21; // r7
  __int16 v22; // r2
  unsigned __int8 *v23; // r10
  unsigned int v24; // r0
  int v25; // r2
  _BYTE *v26; // r1
  int v27; // r2
  _BYTE *v28; // r2
  unsigned __int8 *v29; // r8
  __int16 v30; // r7
  unsigned __int8 *v31; // r1
  int v32; // lr
  int v33; // r3
  int v34; // r3
  int v35; // r3
  unsigned int v36; // r0
  unsigned __int8 *v37; // r4
  unsigned __int8 *v38; // r0
  unsigned __int8 *v39; // r3
  unsigned int v40; // r7
  unsigned int v41; // r2
  unsigned int v42; // r2
  int v43; // r3
  unsigned int v44; // r3
  int v45; // r3
  unsigned int v46; // r2
  char v47; // r3
  unsigned int v48; // r2
  unsigned int v49; // r2
  _WORD *v50; // r5
  int *v51; // r1
  int v52; // r3
  char v53; // t1
  int *v54; // [sp+0h] [bp-68h]
  unsigned int v55; // [sp+4h] [bp-64h]
  unsigned int v56; // [sp+8h] [bp-60h]
  int v57; // [sp+Ch] [bp-5Ch]
  unsigned __int8 *v58; // [sp+10h] [bp-58h]
  _BYTE *v59; // [sp+14h] [bp-54h]
  char *v60; // [sp+18h] [bp-50h]
  unsigned int v61; // [sp+1Ch] [bp-4Ch]
  int v62; // [sp+20h] [bp-48h]
  unsigned int v63; // [sp+24h] [bp-44h]
  __int16 v64; // [sp+28h] [bp-40h]
  unsigned __int8 *v65; // [sp+2Ch] [bp-3Ch]
  unsigned int v66; // [sp+30h] [bp-38h]
  unsigned int v67; // [sp+34h] [bp-34h]
  int v69[10]; // [sp+40h] [bp-28h] BYREF

  v9 = a3;
  v11 = &a1[a2];
  v12 = a3 + a4;
  v57 = 0;
  v58 = &a1[a2];
  v63 = a3 + a4;
  if ( a4 < 0x40 || a2 < 8 )
    return -1073741789;
  if ( (unsigned int)a1 <= 0x2001 )
    return -1073741637;
  v15 = a6;
  memset(a6, 0, 0x20000);
  v66 = v12 - 41;
  v60 = 0;
  v16 = (unsigned int)(v11 - 5);
  v67 = (unsigned int)(v11 - 5);
  if ( !a7 || (v17 = a9, v62 = a9, a9 > a2) )
  {
    v17 = a2;
    v62 = a2;
  }
  v69[0] = a7;
  v54 = (int *)v9;
  v18 = (_BYTE *)(v9 + 5);
  v69[1] = a8;
  v69[2] = v17;
  v19 = 2;
  v20 = a1 + 1;
  *(_BYTE *)(v9 + 4) = *a1;
  v61 = 3;
  v21 = a1;
  v56 = 0;
  v22 = 0;
  v65 = a1;
LABEL_9:
  v23 = v21 + 0x2000;
  if ( (unsigned int)(v21 + 0x2000) > v16 )
    v23 = (unsigned __int8 *)v16;
  v24 = (unsigned int)&v20[v17];
  v55 = v24;
  if ( (unsigned int)v23 < v24 )
  {
    v24 = (unsigned int)v23;
    v55 = (unsigned int)v23;
  }
  v25 = v22 & 0x3FFF;
  v64 = v25;
  if ( v21 < v23 )
  {
    v26 = &v15[4 * v25];
    v64 = v25 + (_WORD)v23 - (_WORD)v21;
    do
    {
      v27 = *((unsigned __int16 *)&XpressHashFunction[256] + v21[2]) ^ *((unsigned __int16 *)&XpressHashFunction[128]
                                                                       + v21[1]) ^ *((unsigned __int16 *)XpressHashFunction
                                                                                   + *v21);
      *((_DWORD *)v26 + 0x8000) = *(_DWORD *)&v15[4 * v27];
      *(_DWORD *)&v15[4 * v27] = v21++;
      v26 += 4;
    }
    while ( v21 < v23 );
    v24 = v55;
    v65 = v21;
  }
  v28 = v15 + 0x20000;
  v59 = v15 + 0x20000;
  while ( 2 )
  {
    v29 = v20 - 0x2000;
    v30 = 0x2000 - (_WORD)a1;
    while ( 1 )
    {
      if ( (unsigned int)v20 >= v24 )
      {
        if ( v20 >= v23 )
        {
          v16 = v67;
          v22 = v64;
          v21 = v65;
          v17 = v62;
          v15 = a6;
          if ( (unsigned int)v20 >= v67 )
          {
            v51 = v54;
            goto LABEL_95;
          }
          goto LABEL_9;
        }
        v24 = RtlpMakeXpressCallback(v69, v23, v20);
        v28 = v59;
        v55 = v24;
      }
      v31 = *(unsigned __int8 **)&v28[4 * ((v30 + (_WORD)v29) & 0x3FFF)];
      v32 = *(_DWORD *)v20;
      if ( v31 >= v29 )
      {
        v33 = *(_DWORD *)v31 ^ v32;
        if ( !v33 )
          goto LABEL_69;
        v24 = v55;
        if ( (v33 & 0xFFFFFF) == 0 )
          goto LABEL_33;
        v31 = *(unsigned __int8 **)&v28[4 * (((_WORD)v31 - (_WORD)a1) & 0x3FFF)];
        if ( v31 >= v29 )
        {
          v34 = *(_DWORD *)v31 ^ v32;
          if ( !v34 )
            goto LABEL_69;
          v30 = 0x2000 - (_WORD)a1;
          if ( (v34 & 0xFFFFFF) == 0 )
          {
LABEL_33:
            v36 = 0;
            v57 = v20 - v31;
            v29 = v20 - 0x2000;
            goto LABEL_67;
          }
          v31 = *(unsigned __int8 **)&v28[4 * (((_WORD)v31 - (_WORD)a1) & 0x3FFF)];
          if ( v31 >= v29 )
            break;
        }
      }
LABEL_31:
      *v18++ = v32;
      ++v20;
      ++v29;
      if ( v19 <= 0 )
      {
        v51 = (int *)v18;
        *v54 = 2 * v19;
        v18 += 4;
        v19 = 1;
        v54 = v51;
        if ( (unsigned int)v18 >= v66 )
          goto LABEL_95;
        goto LABEL_90;
      }
      v19 *= 2;
    }
    v35 = *(_DWORD *)v31 ^ v32;
    if ( v35 )
    {
      v24 = v55;
      if ( (v35 & 0xFFFFFF) == 0 )
        goto LABEL_33;
      goto LABEL_31;
    }
LABEL_69:
    v40 = (unsigned int)v20;
    v37 = v20 + 4;
    v38 = v37 + 32;
    for ( v31 += 4; ; v31 += 32 )
    {
      if ( v38 >= v58 )
      {
        while ( v37 < v58 && *v37 == *v31 )
        {
          ++v37;
          ++v31;
        }
        goto LABEL_61;
      }
      if ( *(_DWORD *)v37 != *(_DWORD *)v31 )
        break;
      if ( *((_DWORD *)v37 + 1) != *((_DWORD *)v31 + 1) )
      {
        v37 += 4;
        v31 += 4;
        break;
      }
      if ( *((_DWORD *)v37 + 2) != *((_DWORD *)v31 + 2) )
      {
        v37 += 8;
        v31 += 8;
        break;
      }
      if ( *((_DWORD *)v37 + 3) != *((_DWORD *)v31 + 3) )
      {
        v37 += 12;
        v31 += 12;
        break;
      }
      if ( *((_DWORD *)v37 + 4) != *((_DWORD *)v31 + 4) )
      {
        v37 += 16;
        v31 += 16;
        break;
      }
      if ( *((_DWORD *)v37 + 5) != *((_DWORD *)v31 + 5) )
      {
        v37 += 20;
        v31 += 20;
        break;
      }
      if ( *((_DWORD *)v37 + 6) != *((_DWORD *)v31 + 6) )
      {
        v37 += 24;
        v31 += 24;
        break;
      }
      if ( *((_DWORD *)v37 + 7) != *((_DWORD *)v31 + 7) )
      {
        v37 += 28;
        v31 += 28;
        break;
      }
      v37 += 32;
      v38 += 32;
    }
    if ( *v37 == *v31 )
    {
      if ( v37[1] == v31[1] )
      {
        if ( v37[2] == v31[2] )
        {
          v37 += 3;
          v31 += 3;
        }
        else
        {
          v37 += 2;
          v31 += 2;
        }
      }
      else
      {
        ++v37;
        ++v31;
      }
    }
LABEL_61:
    v39 = &v37[-v40];
    if ( (unsigned int)&v37[-v40] <= v61 )
    {
      v36 = (unsigned int)&v39[v56];
      goto LABEL_65;
    }
    v57 = v37 - v31;
    v61 = (unsigned int)&v37[-v40];
    if ( (unsigned int)v31 > v40 )
    {
      v20 = (unsigned __int8 *)v40;
    }
    else
    {
      v36 = v56;
LABEL_65:
      v28 = v59;
      LOWORD(v31) = (_WORD)v31 - (_WORD)v39;
      v20 = (unsigned __int8 *)v40;
      while ( 1 )
      {
        v56 = ++v36;
        if ( v36 >= 0x18 )
          break;
LABEL_67:
        v31 = *(unsigned __int8 **)&v28[4 * (((_WORD)v31 - (_WORD)a1) & 0x3FFF)];
        if ( v31 < v29 )
          break;
        if ( v32 == *(_DWORD *)v31 )
          goto LABEL_69;
      }
    }
    v41 = v61;
    v56 = 0;
    v61 = 3;
    v20 += v41;
    v42 = v41 - 3;
    v43 = 8 * (v57 - 1);
    if ( v42 < 7 )
    {
      v44 = v43 + v42;
      *(_WORD *)v18 = v44;
      v18 += 2;
      v57 = v44;
      goto LABEL_85;
    }
    v45 = v43 | 7;
    *(_WORD *)v18 = v45;
    v18 += 2;
    v46 = v42 - 7;
    v57 = v45;
    if ( !v60 )
    {
      v60 = v18;
      if ( v46 < 0xF )
      {
        *v18++ = v46;
        goto LABEL_85;
      }
      *v18++ = 15;
LABEL_80:
      v48 = v46 - 15;
      if ( v48 >= 0xFF )
      {
        v49 = v48 + 22;
        *v18 = -1;
        v50 = v18 + 1;
        if ( v49 >= 0x10000 )
        {
          *v50 = 0;
          v18 = v50 + 3;
          *((_DWORD *)v18 - 1) = v49;
        }
        else
        {
          *v50 = v49;
          v18 = v50 + 1;
        }
      }
      else
      {
        *v18++ = v48;
      }
      goto LABEL_85;
    }
    v47 = *v60;
    if ( v46 >= 0xF )
    {
      *v60 = v47 | 0xF0;
      v60 = 0;
      goto LABEL_80;
    }
    *v60 = v47 | (16 * v46);
    v60 = 0;
LABEL_85:
    if ( v19 <= 0 )
    {
      v52 = 2 * v19 + 1;
      v51 = (int *)v18;
      v19 = 1;
      *v54 = v52;
      v54 = (int *)v18;
      v18 += 4;
    }
    else
    {
      v51 = v54;
      v19 = 2 * v19 + 1;
    }
    if ( (unsigned int)v18 < v66 )
    {
      v24 = v55;
LABEL_90:
      v28 = v59;
      continue;
    }
    break;
  }
LABEL_95:
  while ( v20 < v58 )
  {
    if ( (unsigned int)v18 >= v63 )
      return -1073741789;
    v53 = *v20++;
    *v18++ = v53;
    if ( v19 <= 0 )
    {
      *v51 = 2 * v19;
      v51 = (int *)v18;
      v19 = 1;
      v18 += 4;
    }
    else
    {
      v19 *= 2;
    }
  }
  if ( (unsigned int)v18 >= v63 )
    return -1073741789;
  while ( v19 > 0 )
    v19 = 2 * v19 + 1;
  *v51 = 2 * v19 + 1;
  *a5 = &v18[-a3];
  if ( (unsigned int)&v18[-a3] < 8 )
    *a5 = 8;
  return 0;
}
