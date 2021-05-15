// MmQuerySpecialPoolBlockType 
 
int __fastcall MmQuerySpecialPoolBlockType(unsigned int a1)
{
  if ( a1 >= dword_63389C
    && *((_BYTE *)&MiState[2423] + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) == 13 )
  {
    return 0;
  }
  if ( MI_VA_IN_SESSION_SPECIAL_POOL(a1) )
    return 33;
  return 1;
}
