// MmLockPreChargedPagedPool 
 
unsigned int __fastcall MmLockPreChargedPagedPool(unsigned int result, int a2)
{
  if ( (dword_681250 & 2) == 0 )
    result = MiLockCode(
               0,
               ((result >> 10) & 0x3FFFFC) - 0x40000000,
               ((result >> 10) & 0x3FFFFC) - 0x40000000 + 4 * (((result & 0xFFF) + a2 + 4095) >> 12) - 4,
               1);
  return result;
}
