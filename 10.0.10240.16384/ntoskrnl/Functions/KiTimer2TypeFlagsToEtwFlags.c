// KiTimer2TypeFlagsToEtwFlags 
 
int __fastcall KiTimer2TypeFlagsToEtwFlags(char a1)
{
  int result; // r0

  result = 0;
  if ( (a1 & 2) != 0 )
    result = 4;
  if ( (a1 & 4) != 0 )
    result |= 8u;
  if ( (a1 & 8) != 0 )
    result |= 0x10u;
  if ( (a1 & 0x10) != 0 )
    result |= 0x20u;
  return result;
}
