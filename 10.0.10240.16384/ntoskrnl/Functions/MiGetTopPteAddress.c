// MiGetTopPteAddress 
 
unsigned int __fastcall MiGetTopPteAddress(unsigned int a1)
{
  return (((((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 10) & 0x3FFFFC) - 0x40000000;
}
