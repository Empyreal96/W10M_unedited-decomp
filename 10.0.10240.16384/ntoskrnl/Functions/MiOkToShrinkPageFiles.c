// MiOkToShrinkPageFiles 
 
BOOL __fastcall MiOkToShrinkPageFiles(unsigned int a1, unsigned int a2)
{
  return a1 + 0x8000 < 8 * (a2 / 0xA) && a1 + 0x8000 > a1;
}
