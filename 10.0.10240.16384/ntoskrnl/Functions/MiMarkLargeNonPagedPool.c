// MiMarkLargeNonPagedPool 
 
unsigned int __fastcall MiMarkLargeNonPagedPool(unsigned int result, unsigned int a2, int a3)
{
  unsigned int *v4; // r4

  v4 = (unsigned int *)result;
  if ( result <= a2 )
  {
    do
    {
      result = *v4;
      if ( (*v4 & 2) != 0 && v4 != (unsigned int *)-1070593024 )
      {
        if ( a3 != 1 )
          return sub_96E370();
        if ( (result & 0x400) != 0
          && *((_BYTE *)&MiState[2423]
             + ((int)(((unsigned __int16)v4 & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 5 )
        {
          result = (unsigned int)RtlSetBits(&dword_634C90, result >> 22, 1u);
        }
      }
      ++v4;
    }
    while ( (unsigned int)v4 <= a2 );
  }
  return result;
}
