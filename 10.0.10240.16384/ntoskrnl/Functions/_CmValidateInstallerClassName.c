// _CmValidateInstallerClassName 
 
int __fastcall CmValidateInstallerClassName(int a1, unsigned __int16 *a2)
{
  int result; // r0

  if ( PnpIsValidGuidString(a2) )
    result = 0;
  else
    result = -1073741773;
  return result;
}
