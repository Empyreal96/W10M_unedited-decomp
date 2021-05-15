// ValidateStd3Range 
 
BOOL __fastcall ValidateStd3Range(unsigned int a1)
{
  return a1 > 0x2C && a1 != 47 && (a1 < 0x3A || a1 > 0x40) && (a1 < 0x5B || a1 > 0x60) && (a1 < 0x7B || a1 > 0x7F);
}
