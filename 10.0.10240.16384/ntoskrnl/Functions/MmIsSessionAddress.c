// MmIsSessionAddress 
 
BOOL __fastcall MmIsSessionAddress(unsigned int a1)
{
  int v1; // r3
  BOOL result; // r0

  result = 0;
  if ( a1 >= dword_63389C )
  {
    v1 = *((unsigned __int8 *)&MiState[2423]
         + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v1 == 11 || v1 == 1 )
      result = 1;
  }
  return result;
}
