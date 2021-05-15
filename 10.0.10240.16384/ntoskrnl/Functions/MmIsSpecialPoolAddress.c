// MmIsSpecialPoolAddress 
 
int __fastcall MmIsSpecialPoolAddress(unsigned int a1, int a2, int a3)
{
  int v5; // r3

  if ( a1 >= 0xC0000000 )
    return sub_549CC8();
  if ( MiIsAddressValid(((a1 >> 10) & 0x3FFFFC) - 0x40000000, 0, a3, (a1 >> 10) & 0x3FFFFC) )
  {
    if ( a1 >= dword_63389C )
    {
      v5 = *((unsigned __int8 *)&MiState[2423]
           + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
      if ( v5 == 7 || v5 == 13 )
        return 1;
    }
    if ( MI_VA_IN_SESSION_SPECIAL_POOL(a1) )
      return 1;
  }
  return 0;
}
