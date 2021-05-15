// RtlpMuiRegGetLangInfoIndex 
 
int __fastcall RtlpMuiRegGetLangInfoIndex(int a1, unsigned __int16 *a2)
{
  int v3; // r3
  unsigned int v4; // lr
  unsigned int v5; // r4
  unsigned int v6; // r7
  int v7; // r2
  int v8; // r10
  unsigned __int16 *v9; // r0
  unsigned int v10; // r8
  BOOL v11; // r3
  unsigned int v12; // r6

  if ( !a1 || !a2 )
    return -1;
  if ( !a2[2] )
    return sub_819E38();
  v3 = ((int)a2 - *(_DWORD *)(a1 + 12)) / 28;
  if ( v3 >> 31 != -1 && v3 < (unsigned int)*(unsigned __int16 *)(a1 + 6) )
    return (__int16)v3;
  v4 = *(unsigned __int16 *)(a1 + 6);
  v5 = 0;
  v6 = 0;
  if ( !*(_WORD *)(a1 + 6) )
    return -1;
  v7 = *a2;
  v8 = *(_DWORD *)(a1 + 12);
  while ( 1 )
  {
    v9 = (unsigned __int16 *)(v8 + 28 * v5);
    if ( *v9 == v7 )
      break;
LABEL_10:
    v6 = (__PAIR64__(v6, v5++) + 1) >> 32;
    if ( __SPAIR64__(v6, v5) >= v4 )
      return -1;
  }
  if ( v9[2] != a2[2] )
    goto LABEL_13;
  if ( v9[3] != a2[3] )
    goto LABEL_13;
  if ( v9[5] != a2[5] )
    goto LABEL_13;
  v10 = a2[4];
  if ( ((v9[4] ^ v10) & 0xFFFFC000) != 0 )
    goto LABEL_13;
  v11 = 1;
  v12 = 0;
  do
  {
    if ( v12 >= 4 )
      break;
    v11 = (((v9[4] ^ v10) >> (v12 * 2)) & 3) == 0 && v9[v12 + 6] == a2[v12 + 6];
    ++v12;
  }
  while ( v11 );
  if ( !v11 )
  {
LABEL_13:
    v7 = *a2;
    goto LABEL_10;
  }
  return (__int16)v5;
}
