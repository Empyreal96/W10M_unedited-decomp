// MiSetImageProtection 
 
int __fastcall MiSetImageProtection(int a1, unsigned int a2, int a3)
{
  return MiSetSystemCodeProtection(
           a1,
           ((a2 >> 10) & 0x3FFFFC) - 0x40000000,
           (((a3 + a2 - 1) >> 10) & 0x3FFFFC) - 0x40000000);
}
