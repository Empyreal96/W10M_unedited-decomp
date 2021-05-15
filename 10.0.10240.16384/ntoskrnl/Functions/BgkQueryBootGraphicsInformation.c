// BgkQueryBootGraphicsInformation 
 
int __fastcall BgkQueryBootGraphicsInformation(int a1, int a2)
{
  int result; // r0

  if ( byte_637609 )
    result = BgQueryBootGraphicsInformation(a1, a2);
  else
    result = -1073741823;
  return result;
}
