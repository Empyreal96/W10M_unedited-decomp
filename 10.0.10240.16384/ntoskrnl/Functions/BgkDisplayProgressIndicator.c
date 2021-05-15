// BgkDisplayProgressIndicator 
 
int BgkDisplayProgressIndicator()
{
  int result; // r0

  if ( !byte_637609 || !byte_63761D )
    return -1073741823;
  result = BgDisplayProgressIndicator(1u);
  if ( result >= 0 )
    result = sub_975E7C();
  return result;
}
