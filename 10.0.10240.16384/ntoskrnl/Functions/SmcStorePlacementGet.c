// SmcStorePlacementGet 
 
int __fastcall SmcStorePlacementGet(int a1, unsigned int a2, int a3, int a4)
{
  int v4; // r3
  unsigned int v6; // r4
  unsigned int v7; // r10
  int *v8; // r5
  unsigned int v9; // r1
  _DWORD *v10; // lr
  unsigned int i; // r8
  int v12; // t1
  unsigned int v13; // r4
  signed int v14; // r4
  int v16; // r5
  signed int v17; // r0
  unsigned int v18; // [sp+0h] [bp-28h] BYREF
  int v19; // [sp+4h] [bp-24h]
  int v20; // [sp+8h] [bp-20h]

  v18 = a2;
  v19 = a3;
  v20 = a4;
  v4 = *(_DWORD *)(a3 + 8);
  v18 = *(_DWORD *)(a1 + 8);
  v19 = v4;
  v6 = a1 + 124;
  v7 = (v18 + 31) >> 5;
  while ( v6 < a1 + 380 )
  {
    if ( v6 != a3 )
    {
      v8 = *(int **)(v6 + 8);
      if ( v8 )
      {
        if ( v8 > &v8[v7] )
          v9 = 0;
        else
          v9 = (4 * v7 + 3) >> 2;
        v10 = *(_DWORD **)(a3 + 8);
        for ( i = 0; i < v9; ++v10 )
        {
          v12 = *v8++;
          ++i;
          *v10 ^= v12;
        }
      }
    }
    v6 += 16;
  }
  v13 = RtlFindSetBits(&v18, a2, 0);
  if ( v13 != -1 )
  {
    RtlClearBits(&v18, 0, v13);
    v14 = v13 + a2;
LABEL_13:
    RtlClearBits(&v18, v14, v18 - v14);
    return 0;
  }
  v16 = 0;
  v17 = RtlFindSetBits(&v18, 1u, 0);
  if ( v17 >= 0 )
  {
    while ( 1 )
    {
      ++v16;
      v14 = v17 + 1;
      if ( v16 == a2 )
        break;
      v17 = RtlFindSetBits(&v18, 1u, v14);
      if ( v17 < v14 )
        return -1073741697;
    }
    goto LABEL_13;
  }
  return -1073741697;
}
