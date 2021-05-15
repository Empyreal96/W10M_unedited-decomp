// PpmEventParkNodePreference 
 
int __fastcall PpmEventParkNodePreference(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+94h] [bp+8h]

  varg_r0 = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_PLATFORM_PARKING_PREFERENCE);
    if ( result )
      result = sub_540A18();
  }
  return result;
}
