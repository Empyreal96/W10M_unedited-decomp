// PpmEventPerfState 
 
int __fastcall PpmEventPerfState(int result, int a2, int a3, int a4)
{
  int varg_r0; // [sp+8Ch] [bp+8h]

  varg_r0 = result;
  if ( PpmEtwRegistered )
  {
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, result);
    if ( result )
      result = sub_540590();
  }
  return result;
}
