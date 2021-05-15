// AnFwDisableBackgroundUpdateTimer 
 
int AnFwDisableBackgroundUpdateTimer()
{
  int result; // r0

  if ( byte_64194F )
  {
    result = KeCancelTimer((int)&dword_649DF8);
    byte_64194F = 0;
  }
  return result;
}
