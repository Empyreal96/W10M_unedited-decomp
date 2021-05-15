// MmDeterminePoolType 
 
int __fastcall MmDeterminePoolType(unsigned int a1)
{
  int v1; // r3

  if ( a1 < dword_63389C )
    return 0;
  v1 = *((unsigned __int8 *)&MiState[2423]
       + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
  switch ( v1 )
  {
    case 6:
    case 14:
      return 1;
    case 1:
      return 33;
    case 7:
      return 1;
  }
  if ( v1 != 11 )
    return 0;
  return 33;
}
