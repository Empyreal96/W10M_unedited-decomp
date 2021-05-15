// MmIsNonPagedSystemAddressValid 
 
BOOL __fastcall MmIsNonPagedSystemAddressValid(unsigned int a1, int a2, int a3)
{
  int v4; // r3
  BOOL result; // r0
  int v6; // r3

  result = 0;
  if ( a1 < dword_63389C
    || (a3 = ((unsigned int)dword_63389C >> 20) & 0xFFC,
        v4 = *((unsigned __int8 *)&MiState[2423] + ((int)(((a1 >> 20) & 0xFFC) - a3) >> 2)),
        v4 != 6)
    && v4 != 14
    && v4 != 7 )
  {
    if ( MmIsSpecialPoolAddress(a1, a2, a3)
      || a1 < dword_63389C
      || (v6 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
          v6 != 1)
      && v6 != 11 )
    {
      result = 1;
    }
  }
  return result;
}
