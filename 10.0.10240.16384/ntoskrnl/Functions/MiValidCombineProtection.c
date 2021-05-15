// MiValidCombineProtection 
 
BOOL __fastcall MiValidCombineProtection(unsigned int a1)
{
  return a1 != 24 && a1 != 31 && (a1 & 0xFFFFFFF8) != 16 && a1 < 0x1E;
}
