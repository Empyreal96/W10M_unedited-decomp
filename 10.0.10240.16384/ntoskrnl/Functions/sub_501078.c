// sub_501078 
 
int __fastcall sub_501078(int a1, int a2, int a3)
{
  __int64 v3; // r4
  unsigned int v4; // r3
  int v6; // lr
  __int64 v7; // kr08_8
  int v8; // r1
  char v9; // r0
  int v10; // r7
  int v11; // r2
  int *v12; // r1
  int v13; // t1
  int v14; // lr
  unsigned int v15; // r4
  unsigned int v16; // r3
  __int64 v17; // kr28_8
  int v18; // r2
  int v19; // r2
  int v20; // r1
  int *v21; // r0
  int v22; // t1
  unsigned int v23; // r1
  int *v24; // r0
  int v25; // t1
  _DWORD *v26; // r4
  unsigned int v27; // r0
  int result; // r0

  v3 = (__int64)a2 << 17;
  v4 = (v3 | ((unsigned int)(a2 >> 31) >> 15)) ^ a2;
  v6 = HIDWORD(v3) ^ (a2 >> 31);
  v7 = 1284865837i64 * v4;
  LODWORD(v3) = 1481765933 * v4;
  HIDWORD(v3) = (1284865837 * (unsigned __int64)(unsigned int)v6) >> 32;
  v8 = ((v3 + __PAIR64__((1481765933 * (unsigned __int64)v4) >> 32, 1284865837 * v6)) >> 32) + 1481765933 * v6;
  if ( 1481765933 * v4 + 1284865837 * v6 + HIDWORD(v7) < HIDWORD(v7) )
    ++v8;
  v9 = v7 ^ v8;
  v10 = v7 ^ v8;
  v11 = 4;
  v12 = (int *)(a2 + 16);
  do
  {
    v13 = *--v12;
    *v12 = v13 ^ v10;
    v10 = __ROR4__(v10, -(char)v11--);
  }
  while ( v11 );
  v14 = *(_DWORD *)a2;
  if ( (v9 & 0xFu) < 7 )
  {
    v15 = ((unsigned __int64)v14 >> 15) ^ (v14 >> 31);
    v16 = ((v14 << 17) | ((unsigned int)(v14 >> 31) >> 15)) ^ v14;
    v17 = 1284865837i64 * v16;
    v18 = 1481765933 * v15 + ((1481765933i64 * v16 + 1284865837 * (unsigned __int64)v15) >> 32);
    if ( (0x5851F42D4C957F2Di64 * __PAIR64__(v15, v16)) >> 32 < HIDWORD(v17) )
      ++v18;
    v19 = (v17 ^ v18) + v10;
    v20 = 7;
    v21 = (int *)(v14 + 28);
    do
    {
      v22 = *--v21;
      *v21 = v22 ^ v19;
      v19 = __ROR4__(v19, -(char)v20--);
    }
    while ( v20 );
    v23 = (unsigned int)(*(__int16 *)(v14 + 4) - 28) >> 2;
    if ( v23 )
    {
      v24 = (int *)(v14 + 28 + 4 * v23);
      do
      {
        v25 = *--v24;
        *v24 = v25 ^ v19;
        v19 = __ROR4__(v19, -(char)v23--);
      }
      while ( v23 );
    }
  }
  v26 = *(_DWORD **)a2;
  v27 = MmMapLockedPagesWithReservedMapping(*(_DWORD *)(a2 + 4), *(_DWORD *)(a2 + 8), *(_DWORD *)a2, 1);
  result = MmSetPageProtection(
             v27,
             (v26[5] + (((unsigned __int16)v26[6] + (unsigned __int16)v26[4]) & 0xFFFu) + 4095) >> 12 << 12,
             0x40u);
  *(_DWORD *)(a1 + 16) = a3;
  *(_DWORD *)(a1 + 20) = 0;
  return result;
}
