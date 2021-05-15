// SepGetProcessTrustLabelAce 
 
int __fastcall SepGetProcessTrustLabelAce(int a1)
{
  int v2; // r3
  int v3; // r3
  unsigned int v4; // r5
  int v5; // r0

  if ( (*(_WORD *)(a1 + 2) & 0x10) == 0 )
    return 0;
  if ( (*(_WORD *)(a1 + 2) & 0x8000) != 0 )
  {
    v2 = *(_DWORD *)(a1 + 12);
    if ( !v2 )
      return 0;
    v3 = v2 + a1;
  }
  else
  {
    v3 = *(_DWORD *)(a1 + 12);
  }
  if ( !v3 )
    return 0;
  v4 = 0;
  v5 = v3 + 8;
  if ( !*(_WORD *)(v3 + 4) )
    return 0;
  while ( *(_BYTE *)v5 != 20 )
  {
    ++v4;
    v5 += *(unsigned __int16 *)(v5 + 2);
    if ( v4 >= *(unsigned __int16 *)(v3 + 4) )
      return 0;
  }
  return sub_51D884();
}
