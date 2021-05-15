// RtlFindLongestRunClearCapped 
 
unsigned int __fastcall RtlFindLongestRunClearCapped(_DWORD *a1, unsigned int a2, int *a3)
{
  int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // lr
  unsigned __int8 *v8; // r10
  int v9; // r3
  unsigned int v10; // r0
  unsigned int v11; // r1
  int v12; // r7
  unsigned __int8 *v13; // r10
  int v14; // t1
  int v15; // r9
  int v16; // r8
  int v17; // r5
  int v18; // r9
  unsigned int v19; // r3
  int i; // r3
  unsigned int v21; // r7
  int v22; // r2
  int v23; // r3
  int v24; // r9
  int v25; // t1
  int v26; // r3
  unsigned int v28; // [sp+0h] [bp-38h]
  int v29; // [sp+4h] [bp-34h]
  unsigned int v30; // [sp+8h] [bp-30h]
  unsigned int v31; // [sp+Ch] [bp-2Ch]
  unsigned int v32; // [sp+10h] [bp-28h]

  v29 = *a1 & 7;
  v30 = (v29 != 0) + (*a1 >> 3);
  v5 = *a3;
  if ( (unsigned int)*a3 >= *a1 )
    v5 = 0;
  v6 = v5 & 0xFFFFFFF8;
  v7 = v6 >> 3;
  v8 = (unsigned __int8 *)(a1[1] + (v6 >> 3));
  v32 = 0;
  v9 = ((*a1 & 7) != 0) + (*a1 >> 3);
  v10 = 0;
  v11 = 0;
  v14 = *v8;
  v13 = v8 + 1;
  v12 = v14;
  v15 = v29;
  v28 = v6;
  v16 = 0;
  v17 = v6;
  if ( v6 >> 3 == v30 - 1 && v29 )
  {
    v12 |= *((unsigned __int8 *)dword_409D94 + v29);
    v9 = v30;
  }
  v31 = 0;
  if ( v9 )
  {
    do
    {
      if ( v12 )
      {
        v18 = *((unsigned __int8 *)RtlpBitsClearLow + v12);
        v19 = v18 + v11;
        if ( v18 + v11 )
        {
          if ( v19 >= a2 )
          {
LABEL_41:
            *a3 = v17;
            return a2;
          }
          if ( v19 > v10 )
          {
            v10 = v18 + v11;
            v16 = v17;
          }
        }
        if ( v17 == v6 )
          v32 = v18 + v11;
        v11 = *((unsigned __int8 *)RtlpBitsClearHigh + v12);
        v17 = 8 * v7 - v11 + 8;
        for ( i = *((unsigned __int8 *)dword_409D88 + v18) | *((unsigned __int8 *)&dword_409D94[2] - v11) | v12;
              ;
              i = v23 | v24 )
        {
          v24 = i;
          if ( i == 255 || (v21 = *((unsigned __int8 *)RtlpBitsClearAnywhere + i), v10 >= v21) )
          {
            v6 = v28;
            v15 = v29;
            goto LABEL_23;
          }
          v22 = 0;
          v23 = *((unsigned __int8 *)dword_409D88 + v21);
          while ( (v23 & v24) != 0 )
          {
            v23 = (unsigned __int8)(2 * v23);
            ++v22;
          }
          if ( v21 >= a2 )
            break;
          v10 = v21;
          v16 = v22 + 8 * v7;
        }
        v26 = v22 + 8 * v7;
        goto LABEL_48;
      }
      v11 += 8;
      if ( v11 >= a2 )
        goto LABEL_41;
LABEL_23:
      if ( ++v7 >= v30 )
      {
        if ( v11 )
        {
          if ( v17 == v6 )
            v32 = v11;
          if ( v11 > v10 )
          {
            v10 = v11;
            v16 = v17;
          }
          v11 = 0;
        }
        v7 = 0;
        v13 = (unsigned __int8 *)a1[1];
      }
      v25 = *v13++;
      v12 = v25;
      if ( v7 == v30 - 1 && v15 )
        v12 |= *((unsigned __int8 *)dword_409D94 + v15);
      ++v31;
      v6 = v28;
    }
    while ( v31 < v30 );
    if ( v11 )
    {
      if ( v17 + v11 == v28 )
        v11 += v32;
      if ( v11 > v10 )
      {
        v10 = v11;
        v16 = v17;
      }
    }
    else if ( !v10 )
    {
      goto LABEL_47;
    }
    if ( v10 > a2 )
      v10 = a2;
    a2 = v10;
    *a3 = v16;
  }
  else
  {
LABEL_47:
    v26 = 0;
    a2 = 0;
LABEL_48:
    *a3 = v26;
  }
  return a2;
}
