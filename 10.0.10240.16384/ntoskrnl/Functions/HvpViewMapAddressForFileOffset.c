// HvpViewMapAddressForFileOffset 
 
unsigned int __fastcall HvpViewMapAddressForFileOffset(int a1, unsigned int a2)
{
  return (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 12) + 4 * (HIBYTE(a2) & 0x7F)) + 24 * ((a2 >> 18) & 0x3F)) & 0xFFFFFFFE)
       + (a2 & 0x3FFFF);
}
