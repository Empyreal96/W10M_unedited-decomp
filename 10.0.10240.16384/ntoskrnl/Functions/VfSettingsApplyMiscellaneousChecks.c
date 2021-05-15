// VfSettingsApplyMiscellaneousChecks 
 
int *__fastcall VfSettingsApplyMiscellaneousChecks(__int16 a1)
{
  int *result; // r0

  if ( (a1 & 0x800) != 0 )
    result = (int *)ExSetPoolFlags(1030);
  else
    result = ExClearPoolFlags();
  return result;
}
