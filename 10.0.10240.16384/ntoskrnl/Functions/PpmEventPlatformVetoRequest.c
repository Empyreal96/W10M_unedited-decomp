// PpmEventPlatformVetoRequest 
 
int __fastcall PpmEventPlatformVetoRequest(int result, int a2, int a3, int a4)
{
  int *v4; // r4
  __int64 v5; // kr00_8
  int varg_r0; // [sp+40h] [bp+8h]

  varg_r0 = result;
  if ( a3 )
    v4 = PPM_ETW_PLATFORM_IDLE_VETO_INCREMENT;
  else
    v4 = PPM_ETW_PLATFORM_IDLE_VETO_DECREMENT;
  if ( PpmEtwRegistered )
  {
    v5 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)v4);
    if ( result )
      result = EtwWrite(v5, SHIDWORD(v5), (int)v4, 0);
  }
  return result;
}
