// MiComputePageHash 
 
unsigned int __fastcall MiComputePageHash(int a1, int a2)
{
  int v2; // r4
  unsigned int result; // r0
  unsigned int v4; // r3
  unsigned int v5; // r1
  unsigned int v6; // r7
  unsigned int v7; // lr
  __int64 v8; // r8
  unsigned int v9; // r10
  unsigned int v10; // r5
  unsigned int v11; // r6
  __int64 v12; // t1
  unsigned int v13; // kr20_4
  unsigned __int64 v14; // kr28_8
  unsigned int v15; // r2
  unsigned int v16; // [sp+0h] [bp-30h]
  int v17; // [sp+Ch] [bp-24h]

  v2 = a2;
  if ( !a2 )
    return sub_549374();
  v17 = a2 + 4064;
  v4 = *(_DWORD *)(a1 + 8);
  if ( (v4 & 0x10) != 0 )
    v5 = v4 >> 13;
  else
    v5 = 0;
  v7 = *(_DWORD *)(v2 + 12);
  v6 = *(_DWORD *)(v2 + 8);
  v8 = *(_QWORD *)(v2 + 16);
  v9 = *(_DWORD *)(v2 + 24);
  v11 = (*(_QWORD *)v2 + (unsigned __int64)v5) >> 32;
  v10 = *(_DWORD *)v2 + v5;
  v16 = *(_DWORD *)(v2 + 28);
  do
  {
    v12 = *(_QWORD *)(v2 + 32);
    v2 += 32;
    v13 = v10 + v12;
    v11 = (__PAIR64__(v11, v10) + v12) >> 32;
    v10 += v12;
    v14 = __PAIR64__(v7, v6) + *(_QWORD *)(v2 + 8);
    v7 = HIDWORD(v14);
    v6 = v14;
    v8 += *(_QWORD *)(v2 + 16);
    v15 = (__PAIR64__(v16, v9) + *(_QWORD *)(v2 + 24)) >> 32;
    v9 += *(_DWORD *)(v2 + 24);
    v16 = v15;
  }
  while ( v2 != v17 );
  result = ((__PAIR64__(v15, v9) + v8 + v14 + __PAIR64__(v11, v13)) >> 32) + v9 + v8 + v14 + v13;
  if ( result < 3 )
    result = 3;
  return result;
}
