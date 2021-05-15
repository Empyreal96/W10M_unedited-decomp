// BgpFmRoundUp 
 
int __fastcall BgpFmRoundUp(int a1)
{
  int result; // r0

  result = a1 >> 6;
  if ( a1 < 0 )
    return result | 0xFC000000;
  if ( (a1 & 0x3F) != 0 )
    ++result;
  return result;
}
