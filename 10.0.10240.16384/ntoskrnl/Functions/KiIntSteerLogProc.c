// KiIntSteerLogProc 
 
int __fastcall KiIntSteerLogProc(int result)
{
  int *v1; // r4

  if ( result )
    v1 = PPM_ETW_INTERRUPT_STEERING_PROC_RUNDOWN;
  else
    v1 = PPM_ETW_INTERRUPT_STEERING_PROC_CHANGE;
  if ( KiIntSteerEtwHandle )
  {
    result = EtwEventEnabled(KiIntSteerEtwHandle, HIDWORD(KiIntSteerEtwHandle), v1);
    if ( result )
      result = sub_5410D4();
  }
  return result;
}
