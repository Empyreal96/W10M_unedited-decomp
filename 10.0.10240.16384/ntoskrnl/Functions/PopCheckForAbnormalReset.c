// PopCheckForAbnormalReset 
 
int PopCheckForAbnormalReset()
{
  int result; // r0

  result = off_617B10();
  if ( result )
    JUMPOUT(0x528E4A);
  if ( dword_61F9A4 )
    result = sub_528E44();
  return result;
}
