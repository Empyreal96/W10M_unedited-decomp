// MiDetermineUserGlobalPteMask 
 
int __fastcall MiDetermineUserGlobalPteMask(unsigned int a1)
{
  int v1; // r1
  int v2; // r3

  v1 = 2048;
  if ( a1 <= (((unsigned int)MmHighestUserAddress >> 10) & 0x3FFFFC) - 0x40000000 && a1 >= 0xC0000000 )
    return 2080;
  if ( a1 < 0xC0300000 || a1 > dword_633898 )
  {
    if ( a1 + 0x40000000 > 0x3FFFFF
      || a1 << 10 < dword_63389C
      || (v2 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((a1 >> 10) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
          v2 != 11)
      && v2 != 1 )
    {
      v1 = 0;
    }
  }
  return v1;
}
