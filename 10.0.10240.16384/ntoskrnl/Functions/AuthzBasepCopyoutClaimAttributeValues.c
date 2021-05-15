// AuthzBasepCopyoutClaimAttributeValues 
 
int __fastcall AuthzBasepCopyoutClaimAttributeValues(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  unsigned int v6; // r6
  int v7; // r4
  int v9; // r3
  int v10; // r2
  unsigned int v11; // r1
  _DWORD *v12; // r9
  _DWORD *v13; // r3
  _DWORD *v14; // r7
  _WORD *v15; // r5
  unsigned int v16; // r2
  _WORD *v17; // r10
  int v18; // r2
  unsigned int v19; // r1
  _DWORD *v20; // r9
  int *v21; // r3
  int *v22; // r7
  unsigned int v23; // r1
  _WORD *v24; // r10
  int v25; // r2
  unsigned int v26; // r1
  _DWORD *v27; // r9
  int *v28; // r3
  int *v29; // r7
  unsigned int v30; // r1
  _WORD *v31; // r10
  int v32; // r7
  unsigned int v33; // r2
  unsigned int v34; // r5
  _DWORD *v35; // r0
  _DWORD *v36; // r2
  _DWORD *v37; // t1
  _DWORD *v38; // r1
  _DWORD *v40; // [sp+0h] [bp-20h]
  int *v41; // [sp+0h] [bp-20h]
  int *v42; // [sp+0h] [bp-20h]

  v6 = a3 + a4;
  v7 = 0;
  if ( a3 + a4 < a3 )
    return -2147483643;
  *a5 = 0;
  v9 = *(unsigned __int16 *)(a1 + 24);
  if ( !*(_WORD *)(a1 + 24) )
    return -1073741811;
  if ( *(unsigned __int16 *)(a1 + 24) > 2u )
  {
    switch ( v9 )
    {
      case 3:
        v25 = *(_DWORD *)(a1 + 36);
        v26 = a3 + 3;
        if ( ((a3 + 3) & 0xFFFFFFFC) + 4 * v25 <= v6 )
        {
          v27 = (_DWORD *)(v26 & 0xFFFFFFFC);
          v28 = (int *)(a1 + 44);
          *(_DWORD *)(a2 + 16) = v26 & 0xFFFFFFFC;
          v29 = *(int **)(a1 + 44);
          v15 = (_WORD *)((v26 & 0xFFFFFFFC) + 4 * v25);
          v42 = (int *)(a1 + 44);
          while ( v29 != v28 )
          {
            v30 = *((unsigned __int16 *)v29 + 12) + 2;
            v31 = (_WORD *)((char *)v15 + v30);
            if ( (unsigned int)v15 + v30 > v6 )
              return -2147483643;
            *v27++ = v15;
            RtlStringCbCopyNW(v15, v30, v29[7], v30 - 2);
            v29 = (int *)*v29;
            v28 = v42;
            v15 = v31;
          }
          goto LABEL_33;
        }
        return -2147483643;
      case 4:
        v18 = *(_DWORD *)(a1 + 36);
        v19 = a3 + 7;
        if ( ((a3 + 7) & 0xFFFFFFF8) + 16 * v18 <= v6 )
        {
          v20 = (_DWORD *)(v19 & 0xFFFFFFF8);
          v21 = (int *)(a1 + 44);
          *(_DWORD *)(a2 + 16) = v19 & 0xFFFFFFF8;
          v22 = *(int **)(a1 + 44);
          v15 = (_WORD *)((v19 & 0xFFFFFFF8) + 16 * v18);
          v41 = (int *)(a1 + 44);
          while ( v22 != v21 )
          {
            v23 = *((unsigned __int16 *)v22 + 16) + 2;
            v24 = (_WORD *)((char *)v15 + v23);
            if ( (unsigned int)v15 + v23 > v6 )
              return -2147483643;
            *v20 = v22[6];
            v20[1] = v22[7];
            v20[2] = v15;
            RtlStringCbCopyNW(v15, v23, v22[9], v23 - 2);
            v22 = (int *)*v22;
            v21 = v41;
            v15 = v24;
            v20 += 4;
          }
          goto LABEL_33;
        }
        return -2147483643;
      case 5:
        goto LABEL_10;
    }
    if ( v9 != 6 )
    {
      if ( v9 == 16 )
      {
LABEL_10:
        v10 = *(_DWORD *)(a1 + 36);
        v11 = a3 + 3;
        if ( ((a3 + 3) & 0xFFFFFFFC) + 8 * v10 <= v6 )
        {
          v12 = (_DWORD *)(v11 & 0xFFFFFFFC);
          v13 = (_DWORD *)(a1 + 44);
          *(_DWORD *)(a2 + 16) = v11 & 0xFFFFFFFC;
          v14 = *(_DWORD **)(a1 + 44);
          v15 = (_WORD *)((v11 & 0xFFFFFFFC) + 8 * v10);
          v40 = (_DWORD *)(a1 + 44);
          while ( v14 != v13 )
          {
            v16 = v14[7];
            v17 = (_WORD *)((char *)v15 + v16);
            if ( (unsigned int)v15 + v16 > v6 )
              return -2147483643;
            *v12 = v15;
            v12[1] = v16;
            memmove((int)v15, v14[6], v16);
            v14 = (_DWORD *)*v14;
            v13 = v40;
            v15 = v17;
            v12 += 2;
          }
          goto LABEL_33;
        }
        return -2147483643;
      }
      return -1073741811;
    }
  }
  v32 = *(_DWORD *)(a1 + 36);
  v33 = a3 + 7;
  if ( ((a3 + 7) & 0xFFFFFFF8) + 8 * v32 <= v6 )
  {
    v34 = v33 & 0xFFFFFFF8;
    *(_DWORD *)(a2 + 16) = v33 & 0xFFFFFFF8;
    v37 = *(_DWORD **)(a1 + 44);
    v35 = (_DWORD *)(a1 + 44);
    v36 = v37;
    if ( v37 != v35 )
    {
      v38 = (_DWORD *)v34;
      do
      {
        *v38 = v36[6];
        v38[1] = v36[7];
        v36 = (_DWORD *)*v36;
        v38 += 2;
      }
      while ( v36 != v35 );
    }
    v15 = (_WORD *)(v34 + 8 * v32);
LABEL_33:
    *a5 = (char *)v15 - a3;
    return v7;
  }
  return -2147483643;
}
