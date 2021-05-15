// ExpUpdateProductSuiteTypeInRegistry 
 
_BYTE *ExpUpdateProductSuiteTypeInRegistry()
{
  _BYTE *result; // r0
  char v1[757]; // [sp+15h] [bp-317h] BYREF

  result = memset(v1, 0, sizeof(v1));
  if ( !ExpSetupModeDetected )
  {
    if ( ExpProductInfoMappedType )
      result = (_BYTE *)sub_96DE4C(result);
  }
  return result;
}
