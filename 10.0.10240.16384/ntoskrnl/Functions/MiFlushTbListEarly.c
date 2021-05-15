// MiFlushTbListEarly 
 
int __fastcall MiFlushTbListEarly(int a1, char a2)
{
  if ( *(_DWORD *)(a1 + 12) < *(_DWORD *)(a1 + 8)
    && !*(_BYTE *)(a1 + 5)
    && *(_DWORD *)(a1 + 16) <= (unsigned int)dword_63382C )
  {
    return 0;
  }
  if ( (a2 & 2) != 0 )
    return 1;
  if ( (unsigned int)dword_63382C < 0x400 )
  {
    if ( (a2 & 1) == 0 )
      return 0;
    *(_BYTE *)(a1 + 5) = 1;
    MiFlushTbList(a1);
    return 1;
  }
  return sub_51719C();
}
