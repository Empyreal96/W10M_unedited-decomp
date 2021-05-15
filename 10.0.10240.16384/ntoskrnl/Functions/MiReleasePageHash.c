// MiReleasePageHash 
 
int __fastcall MiReleasePageHash(unsigned int a1, unsigned int a2)
{
  return MiReleasePtes(
           &dword_634D58,
           ((a1 >> 10) & 0x3FFFFC) - 0x40000000,
           (((4 * (_WORD)a2) & 0xFFF) != 0) + (unsigned int)((4i64 * a2) >> 12));
}
