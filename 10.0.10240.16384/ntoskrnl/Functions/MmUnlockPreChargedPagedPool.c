// MmUnlockPreChargedPagedPool 
 
unsigned int __fastcall MmUnlockPreChargedPagedPool(unsigned int result, int a2)
{
  if ( (dword_681250 & 2) == 0 )
    result = MiUnlockCodePage(
               ((result >> 10) & 0x3FFFFC) - 0x40000000,
               ((result >> 10) & 0x3FFFFC) - 0x40000000 + 4 * (((result & 0xFFF) + a2 + 4095) >> 12) - 4);
  return result;
}
