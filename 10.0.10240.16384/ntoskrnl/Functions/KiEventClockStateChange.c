// KiEventClockStateChange 
 
int KiEventClockStateChange()
{
  int result; // r0

  if ( (dword_682608 & 0x100000) != 0 )
    result = sub_552B34();
  return result;
}
