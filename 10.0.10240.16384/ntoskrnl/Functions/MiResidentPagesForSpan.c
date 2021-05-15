// MiResidentPagesForSpan 
 
unsigned int __fastcall MiResidentPagesForSpan(unsigned int a1, unsigned int a2)
{
  int v2; // r0
  int v3; // r3

  v2 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
  v3 = (int)(((a2 >> 10) & 0x3FFFFC) - 0x40000000 - v2) >> 2;
  return ((unsigned int)(4 * (v3 + 1)) >> 12) + ((((4 * ((_WORD)v3 + 1)) & 0xFFF) + (v2 & 0xFFFu) + 4095) >> 12);
}
