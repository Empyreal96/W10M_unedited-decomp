// _CmValidateDeviceContainerName 
 
int __fastcall CmValidateDeviceContainerName(int a1, unsigned __int16 *a2)
{
  int result; // r0

  if ( !PnpIsValidGuidString(a2) || PnpIsNullGuidString(a2) )
    result = -1073741773;
  else
    result = 0;
  return result;
}
