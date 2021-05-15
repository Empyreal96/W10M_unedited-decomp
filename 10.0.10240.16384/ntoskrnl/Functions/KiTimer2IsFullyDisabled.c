// KiTimer2IsFullyDisabled 
 
BOOL __fastcall KiTimer2IsFullyDisabled(__int16 a1)
{
  return (a1 & 0x3F00) == 0x2000;
}
