// PpmEventStaticPolicyRundown 
 
void PpmEventStaticPolicyRundown()
{
  __int64 v0; // kr00_8
  int v1[38]; // [sp+8h] [bp-98h] BYREF

  if ( PpmEtwRegistered )
  {
    v0 = *(_QWORD *)&PpmEtwHandle;
    if ( EtwEventEnabled(PpmEtwHandle, dword_61DEC4, (int)PPM_ETW_STATIC_POLICY_RUNDOWN) )
    {
      v1[0] = 0;
      v1[2] = (int)&PpmPerfBoostAtGuaranteed;
      v1[3] = 0;
      v1[4] = 4;
      v1[5] = 0;
      v1[6] = (int)&PpmPerfIdealAggressiveIncreaseThreshold;
      v1[7] = 0;
      v1[8] = 4;
      v1[9] = 0;
      v1[10] = (int)&PpmPerfSingleStepSize;
      v1[11] = 0;
      v1[12] = 4;
      v1[13] = 0;
      v1[14] = (int)&PpmPerfCalculateActualUtilization;
      v1[15] = 0;
      v1[16] = 4;
      v1[17] = 0;
      v1[18] = (int)&PpmPerfArtificialDomainEnabled;
      v1[19] = 0;
      v1[20] = 4;
      v1[21] = 0;
      v1[22] = (int)v1;
      v1[23] = 0;
      v1[24] = 4;
      v1[25] = 0;
      v1[26] = (int)&PpmParkUseCoreGranularity;
      v1[27] = 0;
      v1[28] = 4;
      v1[29] = 0;
      v1[30] = (int)&PpmParkMultiparkGranularity;
      v1[31] = 0;
      v1[32] = 4;
      v1[33] = 0;
      EtwWrite(v0, SHIDWORD(v0), (int)PPM_ETW_STATIC_POLICY_RUNDOWN, 0);
    }
  }
}
