// SepSecureBootCheckForUpdates 
 
int SepSecureBootCheckForUpdates()
{
  int result; // r0

  if ( ZwOpenKey() < 0 || ZwQueryValueKey() < 0 )
    result = 0;
  else
    result = sub_96DA08();
  return result;
}
