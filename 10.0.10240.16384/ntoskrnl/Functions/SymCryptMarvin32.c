// SymCryptMarvin32 
 
int __fastcall SymCryptMarvin32(int a1, __int64 *a2, unsigned int a3, _DWORD *a4)
{
  int *v4; // r0
  unsigned int v5; // r6
  int v7; // r1
  int v8; // r4
  _DWORD *v9; // lr
  unsigned int v10; // r7
  __int64 v11; // t1
  int v12; // r4
  int v13; // r0
  int v14; // r3
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int result; // r0
  int v19; // r2
  int v20; // r1
  int v21; // r0
  int v22; // r2
  int v23; // r1
  int v24; // r1

  v4 = &HvSymcryptSeed;
  v5 = a3;
  v8 = dword_641F84;
  v7 = HvSymcryptSeed;
  v9 = a4;
  if ( a3 > 7 )
  {
    v10 = ((a3 - 8) >> 3) + 1;
    do
    {
      v11 = *a2++;
      v5 -= 8;
      v12 = v8 ^ (v11 + v7);
      v13 = __ROR4__(v11 + v7, 12) + v12;
      v14 = __ROR4__(v12, 23) ^ v13;
      v15 = __ROR4__(v13, 5) + HIDWORD(v11) + v14;
      v16 = __ROR4__(v14, 13) ^ v15;
      v17 = __ROR4__(v15, 12);
      v4 = (int *)(__ROR4__(v16, 23) ^ (v17 + v16));
      v7 = (int)v4 + __ROR4__(v17 + v16, 5);
      --v10;
      v8 = __ROR4__(v4, 13);
    }
    while ( v10 );
    v9 = a4;
  }
  if ( v5 )
    return sub_51D420(v4, v7);
  v19 = v8 ^ (v7 + 128);
  v20 = __ROR4__(v7 + 128, 12) + v19;
  v21 = __ROR4__(v19, 23) ^ v20;
  v22 = __ROR4__(v20, 5) + v21;
  v23 = __ROR4__(v21, 13) ^ v22;
  result = __ROR4__(v22, 12) + v23;
  v24 = __ROR4__(v23, 23) ^ result;
  *v9 = __ROR4__(result, 5) + v24;
  v9[1] = __ROR4__(v24, 13);
  return result;
}
