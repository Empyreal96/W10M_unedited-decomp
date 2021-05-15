// MmSizeOfMdl 
 
unsigned int __fastcall MmSizeOfMdl(__int16 a1, int a2)
{
  return 4 * ((((a1 & 0xFFFu) + a2 + 4095) >> 12) + 7);
}
