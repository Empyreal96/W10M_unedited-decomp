// RtlFindClearRuns 
 
int __fastcall RtlFindClearRuns(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r8
  unsigned int v5; // r7
  unsigned __int8 *v6; // r5
  unsigned int v7; // r6
  int v8; // r9
  unsigned int v9; // r1
  unsigned int v10; // r2
  int v11; // r4
  int v12; // t1
  int v13; // r0
  int v14; // r2
  unsigned int v15; // r6
  int v16; // r0
  int v17; // lr
  unsigned int v19; // r2
  int v20; // r6
  int v21; // r8
  int *i; // lr
  int v23; // t1
  int v24; // r3
  unsigned int v25; // r8
  int v26; // r9
  int v27; // r10
  unsigned __int8 v28; // r3
  int v29; // r3
  int v30; // r0
  int *j; // r2
  int v32; // t1
  int v33; // r2
  int v34; // r1
  int *k; // r2
  int v36; // t1
  int v37; // r3
  unsigned int v38; // [sp+0h] [bp-38h]
  unsigned int v42; // [sp+10h] [bp-28h]
  int v43; // [sp+14h] [bp-24h]
  int v44; // [sp+18h] [bp-20h]

  v44 = *a1 & 7;
  v4 = 0;
  v5 = (v44 != 0) + (*a1 >> 3);
  v6 = (unsigned __int8 *)a1[1];
  v38 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  if ( !v5 )
    return v4;
  v10 = v5 - 1;
  v11 = 0;
  do
  {
    v12 = *v6++;
    v13 = v12;
    if ( v9 == v10 && v44 )
      v13 |= *((unsigned __int8 *)dword_409D94 + v44);
    if ( !v13 )
    {
      v7 += 8;
      goto LABEL_8;
    }
    v14 = *((unsigned __int8 *)RtlpBitsClearLow + v13);
    v15 = v7 + v14;
    if ( v15 )
    {
      if ( v4 < a3 )
      {
        v38 = ++v4;
LABEL_20:
        v21 = v4 - 2;
        if ( a4 )
        {
          for ( i = (int *)(a2 + 8 * v21); v21 >= 0 && i[1] < v15; i[5] = i[3] )
          {
            v23 = *i;
            i -= 2;
            --v21;
            i[4] = v23;
          }
        }
        v24 = a2 + 8 * v21;
        *(_DWORD *)(v24 + 8) = v8;
        *(_DWORD *)(v24 + 12) = v15;
        v4 = v38;
        if ( !a4 )
          return sub_542698();
        goto LABEL_6;
      }
      if ( *(_DWORD *)(a2 + 8 * v4 - 4) < v15 )
        goto LABEL_20;
    }
LABEL_6:
    v7 = *((unsigned __int8 *)RtlpBitsClearHigh + v13);
    v8 = v11 - v7 + 8;
    v42 = v7;
    v43 = v8;
    v16 = v13 | *((unsigned __int8 *)&dword_409D94[2] - v7) | *((unsigned __int8 *)dword_409D88 + v14);
    v17 = v16;
    if ( v16 != 255 )
    {
      v19 = a3;
      v20 = a2 + 8 * v4;
      do
      {
        if ( v4 >= v19 )
        {
          if ( *(_DWORD *)(v20 - 4) >= (unsigned int)*((unsigned __int8 *)RtlpBitsClearAnywhere + v16) )
          {
            v7 = v42;
            v8 = v43;
            goto LABEL_7;
          }
          v19 = a3;
        }
        v25 = *((unsigned __int8 *)RtlpBitsClearAnywhere + v16);
        v26 = *((unsigned __int8 *)dword_409D88 + v25);
        v27 = 0;
        v28 = *((_BYTE *)dword_409D88 + v25);
        if ( (v26 & v17) != 0 )
        {
          do
          {
            v28 *= 2;
            v26 = v28;
            ++v27;
          }
          while ( (v28 & (unsigned __int8)v17) != 0 );
        }
        v29 = v38;
        if ( v38 < v19 )
        {
          v29 = ++v38;
          v20 += 8;
        }
        v30 = v29 - 2;
        if ( a4 )
        {
          for ( j = (int *)(v20 - 16); v30 >= 0 && j[1] < v25; j[5] = j[3] )
          {
            v32 = *j;
            j -= 2;
            --v30;
            j[4] = v32;
          }
        }
        v33 = a2 + 8 * v30;
        *(_DWORD *)(v33 + 8) = v11 + v27;
        *(_DWORD *)(v33 + 12) = v25;
        v4 = v38;
        v19 = a3;
        if ( !a4 )
          JUMPOUT(0x5426A2);
        v16 = v26 | v17;
        v17 = v16;
      }
      while ( v16 != 255 );
      v7 = v42;
      v8 = v43;
    }
LABEL_7:
    v10 = v5 - 1;
LABEL_8:
    ++v9;
    v11 += 8;
  }
  while ( v9 < v5 );
  if ( !v7 )
    return v4;
  if ( v4 < a3 )
  {
    ++v4;
    goto LABEL_44;
  }
  if ( *(_DWORD *)(a2 + 8 * v4 - 4) < v7 )
  {
LABEL_44:
    v34 = v4 - 2;
    if ( a4 )
    {
      for ( k = (int *)(a2 + 8 * v34); v34 >= 0 && k[1] < v7; k[5] = k[3] )
      {
        v36 = *k;
        k -= 2;
        --v34;
        k[4] = v36;
      }
    }
    v37 = a2 + 8 * v34;
    *(_DWORD *)(v37 + 8) = v8;
    *(_DWORD *)(v37 + 12) = v7;
  }
  return v4;
}
