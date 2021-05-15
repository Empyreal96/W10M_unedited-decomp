// _IsFixedSizeType 
 
BOOL __fastcall IsFixedSizeType(__int16 a1)
{
  unsigned int v1; // r0

  v1 = a1 & 0xFFF;
  return v1 < 0x12 || v1 > 0x14 && v1 != 25;
}
