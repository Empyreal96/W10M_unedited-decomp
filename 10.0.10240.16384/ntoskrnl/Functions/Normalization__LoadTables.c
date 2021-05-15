// Normalization__LoadTables 
 
int __fastcall Normalization__LoadTables(__int16 a1, unsigned __int16 *a2, unsigned int a3, int a4)
{
  unsigned int v8; // r1
  unsigned int v9; // r7
  unsigned int v10; // lr
  int v11; // r3
  unsigned __int16 *v12; // r3

  memset((_BYTE *)a4, 0, 68);
  v8 = a3 >> 1;
  if ( a3 >> 1 < a2[26] )
    return -1073741672;
  v9 = a2[27];
  if ( v8 < v9 )
    return -1073741672;
  v10 = a2[28];
  if ( v8 < v10 || v8 < a2[29] || v8 < a2[30] || v8 < a2[31] || v8 < a2[32] || v8 < a2[33] || v10 - v9 != 4352 )
    return -1073741672;
  *(_DWORD *)(a4 + 4) = a2;
  *(_DWORD *)(a4 + 8) = a3;
  *(_DWORD *)a4 = a2[20];
  *(_DWORD *)(a4 + 12) = a2[21];
  *(_DWORD *)(a4 + 16) = a2[22];
  *(_DWORD *)(a4 + 20) = &a2[a2[27]];
  *(_DWORD *)(a4 + 24) = &a2[a2[28]];
  *(_DWORD *)(a4 + 32) = a2[23];
  *(_DWORD *)(a4 + 36) = &a2[a2[29]];
  *(_DWORD *)(a4 + 40) = &a2[a2[30]];
  *(_DWORD *)(a4 + 44) = &a2[a2[31]];
  v11 = a2[24];
  *(_DWORD *)(a4 + 48) = v11;
  if ( v11 )
  {
    *(_BYTE *)(a4 + 60) = 0;
    *(_DWORD *)(a4 + 52) = &a2[a2[32]];
    v12 = &a2[a2[33]];
  }
  else
  {
    *(_BYTE *)(a4 + 60) = 1;
    v12 = 0;
    *(_DWORD *)(a4 + 52) = 0;
  }
  *(_DWORD *)(a4 + 56) = v12;
  *(_DWORD *)(a4 + 28) = &a2[a2[26]];
  Normalization__LoadClassMapExceptions(a4);
  *(_BYTE *)(a4 + 61) = (a1 & 0x100) == 0;
  return 0;
}
