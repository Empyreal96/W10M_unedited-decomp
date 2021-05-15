// KsepValidateShimProviderAndData 
 
int __fastcall KsepValidateShimProviderAndData(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r2
  int v6; // r0
  _DWORD *v7; // r1
  int v8; // r5
  unsigned int v9; // r3
  unsigned int v11; // [sp+0h] [bp-18h]
  int v12; // [sp+4h] [bp-14h]

  v11 = a3;
  v12 = a4;
  if ( !a1 )
    return 0;
  if ( !a3 )
    return 0;
  if ( KsepGetModuleInfoByAddress() < 0 )
    return 0;
  v5 = *(_DWORD **)(a3 + 24);
  if ( !v5 )
    return 0;
  v6 = 0;
  do
  {
    if ( *v5 == 4 )
      break;
    v7 = (_DWORD *)v5[2];
    if ( !v7 )
      return 0;
    v8 = 0;
    do
    {
      if ( *v7 == 2 )
        break;
      v9 = v7[2];
      if ( !v9 )
        return 0;
      if ( v9 < v11 )
        return sub_7CF334(v6);
      v8 += 16;
      v7 = (_DWORD *)(v5[2] + v8);
    }
    while ( v7 );
    v6 += 12;
    v5 = (_DWORD *)(v6 + *(_DWORD *)(a3 + 24));
  }
  while ( v5 );
  return 1;
}
