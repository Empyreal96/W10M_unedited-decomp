// PpmEventTraceLPIState 
 
void PpmEventTraceLPIState()
{
  __int64 v0; // kr00_8
  int v1; // [sp+8h] [bp-38h] BYREF
  int v2[13]; // [sp+Ch] [bp-34h] BYREF

  if ( PpmEtwRegistered )
  {
    v0 = *(_QWORD *)&PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_LPI_RUNDOWN) )
    {
      v2[0] = PpmParkLpiCap;
      v1 = PpmParkLpiEngaged;
      v2[1] = (int)v2;
      v2[2] = 0;
      v2[3] = 4;
      v2[4] = 0;
      v2[5] = (int)&v1;
      v2[6] = 0;
      v2[7] = 4;
      v2[8] = 0;
      EtwWrite(v0, SHIDWORD(v0), (int)PPM_ETW_LPI_RUNDOWN, 0);
    }
  }
}
