// KiIntSteerLogMask 
 
int __fastcall KiIntSteerLogMask(int result)
{
  int *v1; // r5

  if ( result )
    v1 = KMPnPRundownEvt_SleepStudy_ConnectionResource;
  else
    v1 = PPM_ETW_INTERRUPT_STEERING_MASK_CHANGE;
  if ( KiIntSteerEtwHandle )
  {
    result = EtwEventEnabled(KiIntSteerEtwHandle, HIDWORD(KiIntSteerEtwHandle), v1);
    if ( result )
      result = sub_541058();
  }
  return result;
}
