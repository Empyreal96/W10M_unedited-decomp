// MiZeroBootMappings 
 
int MiZeroBootMappings()
{
  int result; // r0

  result = MxZeroBootMappings(
             -1070596096,
             ((((((unsigned int)dword_63389C >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000,
             1);
  __dsb(0xFu);
  __mcr(15, 0, 0, 8, 7, 0);
  __dsb(0xFu);
  __isb(0xFu);
  return result;
}
