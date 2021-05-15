// PpmEventLPICoreParking 
 
int __fastcall PpmEventLPICoreParking(int result, int a2)
{
  __int64 v2; // kr00_8
  int vars8; // [sp+40h] [bp+8h]

  vars8 = result;
  if ( PpmEtwRegistered )
  {
    v2 = *(_QWORD *)&PpmEtwHandle;
    result = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_LPI_CORE_PARK);
    if ( result )
      result = EtwWrite(v2, SHIDWORD(v2), (int)PPM_ETW_LPI_CORE_PARK, 0);
  }
  return result;
}
