// BgpFmRoundDefault 
 
int __fastcall BgpFmRoundDefault(int a1)
{
  int result; // r0

  result = a1 >> 6;
  if ( a1 < 0 )
    result |= 0xFC000000;
  if ( (a1 & 0x20) != 0 )
    ++result;
  return result;
}
