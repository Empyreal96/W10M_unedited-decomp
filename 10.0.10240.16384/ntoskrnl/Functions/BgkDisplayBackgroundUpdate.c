// BgkDisplayBackgroundUpdate 
 
int BgkDisplayBackgroundUpdate()
{
  int result; // r0

  if ( !byte_637609 || !byte_63761D )
    return -1073741823;
  result = BgDisplayBackgroundUpdate(1u);
  if ( result >= 0 )
    byte_63761C = 1;
  return result;
}
