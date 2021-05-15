// PopFxSetDeviceAccountingCsPlatformState 
 
int __fastcall PopFxSetDeviceAccountingCsPlatformState(int result)
{
  int v1; // r8

  __dmb(0xBu);
  do
    v1 = __ldrex((unsigned int *)&PopFxDeviceAccountingLevel);
  while ( !v1 && __strex(0, (unsigned int *)&PopFxDeviceAccountingLevel) );
  __dmb(0xBu);
  if ( !v1 || v1 < 0 )
    result = sub_550C00(result, 0, &PopFxDeviceAccountingLevel);
  return result;
}
