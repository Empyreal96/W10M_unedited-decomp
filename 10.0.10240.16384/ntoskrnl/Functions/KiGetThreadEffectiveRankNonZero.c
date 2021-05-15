// KiGetThreadEffectiveRankNonZero 
 
int __fastcall KiGetThreadEffectiveRankNonZero(int a1, int a2, int a3)
{
  int v3; // r2
  int result; // r0

  if ( *(char *)(a1 + 123) >= 16
    || (*(_DWORD *)(a1 + 80) & 0x100) != 0
    || a3 && (*(_DWORD *)(a1 + 308) || *(_BYTE *)(a1 + 134) == 1) )
  {
    return 0;
  }
  v3 = a2;
  do
  {
    if ( (*(_BYTE *)(v3 + 92) & 2) != 0 )
      return -1;
    v3 = *(_DWORD *)(v3 + 236);
  }
  while ( v3 );
  do
  {
    result = *(_DWORD *)(a2 + 96);
    if ( result )
      break;
    a2 = *(_DWORD *)(a2 + 236);
  }
  while ( a2 );
  return result;
}
