// PpmEventTraceProfileEnable 
 
int __fastcall PpmEventTraceProfileEnable(int result, int a2)
{
  int *v2; // r4
  int _2C; // [sp+2Ch] [bp+8h]

  _2C = result;
  if ( a2 )
    v2 = PPM_ETW_PROCESSOR_PROFILE_ENABLED;
  else
    v2 = PPM_ETW_PROCESSOR_PROFILE_DISABLED;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)v2);
    if ( result )
      result = sub_818698();
  }
  return result;
}
