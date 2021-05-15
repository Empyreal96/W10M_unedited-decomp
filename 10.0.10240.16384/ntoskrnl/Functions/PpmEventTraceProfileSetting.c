// PpmEventTraceProfileSetting 
 
int __fastcall PpmEventTraceProfileSetting(int result, int a2, int a3, int a4, int a5, int a6, int a7, char a8)
{
  const __int16 *v8; // r2
  int varg_r0; // [sp+9Ch] [bp+8h]

  varg_r0 = result;
  if ( PpmEtwRegistered )
  {
    if ( a8 )
      v8 = (const __int16 *)PPM_ETW_PROCESSOR_PROFILE_SETTING_RUNDOWN;
    else
      v8 = L"i";
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)v8);
    if ( result )
      result = sub_817C28();
  }
  return result;
}
