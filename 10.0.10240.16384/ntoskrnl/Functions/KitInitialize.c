// KitInitialize 
 
int KitInitialize()
{
  int result; // r0

  KitpInitAitSampleRate();
  result = EtwRegister((int)MS_Windows_AIT_Provider, 0, 0);
  if ( result < 0 )
    result = sub_96F5A4();
  return result;
}
