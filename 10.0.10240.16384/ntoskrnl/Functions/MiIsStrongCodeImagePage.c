// MiIsStrongCodeImagePage 
 
int __fastcall MiIsStrongCodeImagePage(int a1, unsigned int *a2)
{
  int v2; // r2
  unsigned int v4; // r2

  if ( a2 )
    *a2 = 0;
  v2 = *(_DWORD *)(a1 + 20);
  if ( (v2 & 0x7000000) != 50331648 )
    return 0;
  if ( (v2 & 0x8000000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 8) & 0x400) != 0 )
    {
      v4 = *(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC));
      if ( (*(_DWORD *)(*(_DWORD *)v4 + 52) & 0xC000000) == 0 )
        return 0;
      if ( a2 )
        *a2 = v4;
    }
  }
  else if ( (MiFlags & 0x30000) == 0 )
  {
    return 0;
  }
  return 1;
}
