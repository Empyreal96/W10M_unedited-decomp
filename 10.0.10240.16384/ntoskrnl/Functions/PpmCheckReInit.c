// PpmCheckReInit 
 
__int64 *__fastcall PpmCheckReInit(int a1)
{
  int v1; // r4
  int v2; // r5
  int *v3; // r1
  int v4; // r0
  __int64 *result; // r0

  v1 = 0;
  v2 = 0;
  v3 = &PpmCurrentProfile[44 * dword_61EC0C];
  if ( dword_6174A8 )
  {
    if ( (int *)((char *)v3 + 58) != v3 + 15 )
    {
      v1 = 1;
      v2 = 1;
    }
    if ( PpmCheckPollForFeedback )
      v1 = 1;
    if ( !PopEnergyEstimationDisabled )
      v1 = 1;
  }
  if ( PpmParkParkingAvailable(a1, v3) )
  {
    v1 = 1;
    v2 = 1;
  }
  if ( PopInterruptSteeringEnabled() )
    v1 = 1;
  if ( v1 && !PpmCheckArmed )
    PpmPerfResetHistoryAll();
  v4 = PpmParkUpdateConcurrencyTracking(v2);
  if ( !v1 )
    return (__int64 *)sub_7F33E8(v4);
  result = PpmCheckArmPeriod();
  PpmCheckPipelines = (int)PpmCheckHomogeneousPipelines;
  if ( PpmHeteroPolicy )
  {
    if ( v2 )
      PpmCheckPipelines = (int)PpmCheckHeterogeneousPipelines;
  }
  return result;
}
