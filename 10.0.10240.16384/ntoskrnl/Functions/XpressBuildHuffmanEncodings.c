// XpressBuildHuffmanEncodings 
 
unsigned int __fastcall XpressBuildHuffmanEncodings(int a1)
{
  int v1; // r5
  unsigned __int8 *v2; // r7
  unsigned __int8 *v3; // r6
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r0
  unsigned int result; // r0
  unsigned int v8; // r2
  int v9; // r3
  _WORD *v10; // r1
  int v11; // r0
  unsigned __int8 *v12; // r1
  int v13; // t1
  int v14; // r8
  int v15; // lr
  int v16; // r4
  unsigned int v17; // r0
  int v18; // r2
  int v19; // r1
  int v20; // r3
  unsigned __int8 *v21; // r1
  unsigned __int8 *v22; // r0
  unsigned __int8 *v23; // r4
  int v24; // r3
  int v25; // r2
  int v26; // r3
  int v27; // t1
  int v28; // t1
  int v29; // r0
  int v30; // r4
  int i; // r2
  int v32; // r3
  unsigned int *v33; // r2
  unsigned int v34; // r3
  unsigned int v35; // r2
  int v36; // r4
  char v37; // r8
  int v38; // lr
  _BYTE *v39; // r7
  int v40; // r6
  int v41; // r1
  unsigned int v42; // r9
  int v43; // r6
  int v44; // r1
  unsigned int v45; // [sp+0h] [bp-28h]
  unsigned int v46; // [sp+4h] [bp-24h]

  v1 = a1;
  memset((_BYTE *)(a1 + 14348), 0, 514);
  memset((_BYTE *)(v1 + 14862), 0, 514);
  v2 = (unsigned __int8 *)(v1 + 2048);
  v3 = (unsigned __int8 *)(v1 + 2048);
  memset((_BYTE *)(v1 + 16400), 0, 512);
  v4 = 0;
  v5 = v1;
  do
  {
    v6 = *(_DWORD *)(v5 + 16912);
    if ( v6 )
    {
      *(_DWORD *)v3 = v6;
      ++*(_WORD *)(v1 + 2 * (unsigned __int8)v6 + 14350);
      ++*(_WORD *)(v1 + 2 * (v6 >> 8) + 14864);
      *((_DWORD *)v3 + 1) = 0;
      *((_DWORD *)v3 + 2) = v4;
      v3 += 12;
    }
    ++v4;
    v5 += 4;
  }
  while ( v4 < 0x200 );
  memset((_BYTE *)(v1 + 18960), 0, 256);
  if ( (unsigned int)v3 > v1 + 2060 )
  {
    v10 = (_WORD *)(v1 + 2);
    v11 = 255;
    do
    {
      v10[7174] += v10[7173];
      v10[7431] += v10[7430];
      ++v10;
      --v11;
    }
    while ( v11 );
    v12 = (unsigned __int8 *)(v1 + 2048);
    if ( v2 < v3 )
    {
      do
      {
        *(_WORD *)(v1 + 2 * *(unsigned __int16 *)(v1 + 2 * *v12 + 14348) + 15376) = *((_DWORD *)v12 + 2);
        v13 = *v12;
        v12 += 12;
        ++*(_WORD *)(v1 + 2 * v13 + 14348);
      }
      while ( v12 < v3 );
    }
    v14 = (int)&v3[-v1 - 2048] / 12;
    if ( v14 )
    {
      v15 = v1;
      do
      {
        v16 = *(unsigned __int16 *)(v15 + 15376);
        v15 += 2;
        v17 = *(_DWORD *)(v1 + 4 * v16 + 16912);
        v18 = v1 + 2 * (v17 >> 8);
        v19 = *(unsigned __int16 *)(v18 + 14862);
        *(_WORD *)(v18 + 14862) = v19 + 1;
        v20 = v1 + 12 * v19;
        *(_DWORD *)(v20 + 2056) = v16;
        *(_DWORD *)(v20 + 2048) = v17;
        --v14;
      }
      while ( v14 );
      v2 = (unsigned __int8 *)(v1 + 2048);
    }
    while ( 1 )
    {
      *((_DWORD *)v3 + 1) = v2;
      *((_DWORD *)v3 + 2) = v1 + 2060;
      v21 = v3;
      v22 = (unsigned __int8 *)(v1 + 2072);
      *(_DWORD *)v3 = *(_DWORD *)(v1 + 2048) + *(_DWORD *)(v1 + 2060);
      v23 = v3;
      while ( v22 != v3 || v23 != v21 )
      {
        v21 += 12;
        if ( v22 == v3 || v23 < v21 && *(_DWORD *)v23 < *(_DWORD *)v22 )
        {
          *((_DWORD *)v21 + 1) = v23;
          v24 = *(_DWORD *)v23;
          v23 += 12;
        }
        else
        {
          *((_DWORD *)v21 + 1) = v22;
          v24 = *(_DWORD *)v22;
          v22 += 12;
        }
        *(_DWORD *)v21 = v24;
        if ( v22 == v3 || v23 < v21 && *(_DWORD *)v23 < *(_DWORD *)v22 )
        {
          v26 = *(_DWORD *)v21;
          *((_DWORD *)v21 + 2) = v23;
          v28 = *(_DWORD *)v23;
          v23 += 12;
          v25 = v28;
        }
        else
        {
          v25 = *(_DWORD *)v21;
          *((_DWORD *)v21 + 2) = v22;
          v27 = *(_DWORD *)v22;
          v22 += 12;
          v26 = v27;
        }
        *(_DWORD *)v21 = v26 + v25;
      }
      v29 = 0;
      v30 = 0;
      for ( i = v1; ; v29 = *(_DWORD *)(i + 14352) )
      {
        while ( *((_DWORD *)v21 + 1) )
        {
          *(_DWORD *)(i + 14352) = ++v29;
          ++v30;
          *(_DWORD *)(i + 14348) = *((_DWORD *)v21 + 1);
          v21 = (unsigned __int8 *)*((_DWORD *)v21 + 2);
          i += 8;
        }
        v32 = *((_DWORD *)v21 + 2);
        *((_DWORD *)v21 + 1) = v29;
        *(_BYTE *)(v32 + v1 + 16400) = v29;
        if ( !v30 )
          break;
        --v30;
        i -= 8;
        v21 = *(unsigned __int8 **)(i + 14348);
      }
      if ( *(_DWORD *)(v1 + 2052) <= 0xFu )
        break;
      v33 = (unsigned int *)v2;
      if ( v2 < v3 )
      {
        do
        {
          v34 = *v33;
          v33[1] = 0;
          *v33 = (v34 + 1) >> 1;
          v33 += 3;
        }
        while ( v33 < (unsigned int *)v3 );
      }
    }
    v35 = *((_DWORD *)v3 - 2);
    result = 0;
    v36 = 0;
    v45 = 0;
    v46 = *(_DWORD *)(v1 + 2052);
    if ( v35 <= v46 )
    {
      v37 = 16 * v35;
      do
      {
        v38 = 0;
        v39 = (_BYTE *)(v1 + 18960);
        v40 = v1;
        v41 = v1;
        v42 = 0;
        do
        {
          if ( *(unsigned __int8 *)(v40 + 16400) == v35 )
          {
            v38 += *(_DWORD *)(v41 + 16912);
            *v39 |= v35;
            *(_WORD *)(v41 + 2) = v36++;
            *(_WORD *)v41 = v35;
          }
          v43 = v40 + 1;
          v44 = v41 + 4;
          if ( *(unsigned __int8 *)(v43 + 16400) == v35 )
          {
            v38 += *(_DWORD *)(v44 + 16912);
            *v39 |= v37;
            *(_WORD *)(v44 + 2) = v36++;
            *(_WORD *)v44 = v35;
          }
          v42 += 2;
          ++v39;
          v40 = v43 + 1;
          v41 = v44 + 4;
        }
        while ( v42 < 0x200 );
        v1 = a1;
        v36 *= 2;
        result = v45 + v38 * v35++;
        v37 += 16;
        v45 = result;
      }
      while ( v35 <= v46 );
    }
  }
  else if ( v3 == v2 )
  {
    result = 0;
  }
  else
  {
    v8 = *(_DWORD *)(v1 + 2056);
    v9 = v1 + (v8 >> 1);
    if ( (v8 & 1) != 0 )
      *(_BYTE *)(v9 + 18960) = 16;
    else
      *(_BYTE *)(v9 + 18960) = 1;
    *(_DWORD *)(v1 + 4 * v8) = 1;
    result = *(_DWORD *)v2;
  }
  return result;
}
