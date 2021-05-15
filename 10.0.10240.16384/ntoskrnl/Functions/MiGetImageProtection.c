// MiGetImageProtection 
 
int __fastcall MiGetImageProtection(int a1)
{
  int v2; // r2

  v2 = (a1 & 0x20000000) != 0;
  if ( (a1 & 0x40000000) != 0 )
    v2 |= 2u;
  if ( a1 < 0 && ((BYTE2(MiFlags) & 3) != 3 || (a1 & 0x20000000) == 0) )
    v2 |= 4u;
  if ( (a1 & 0x10000000) != 0 )
    v2 |= 8u;
  return *((char *)MiImageProtectionArray + v2);
}
