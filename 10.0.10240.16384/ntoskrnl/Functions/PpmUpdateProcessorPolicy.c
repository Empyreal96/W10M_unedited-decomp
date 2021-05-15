// PpmUpdateProcessorPolicy 
 
unsigned __int16 *__fastcall PpmUpdateProcessorPolicy(unsigned __int16 *result, int a2, int a3, int a4)
{
  unsigned __int16 v4; // r2
  unsigned int v5; // r2
  int v6; // r0
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  v4 = *result;
  LOWORD(v7) = PpmAllowedActions & *result;
  if ( ((unsigned __int16)PpmAllowedActions & v4) != 0 )
  {
    v5 = 10000 * PpmCurrentProfile[44 * dword_61EC0C + 13];
    if ( v5 <= KeMaximumIncrement )
    {
      result = (unsigned __int16 *)sub_7F33CC();
    }
    else
    {
      v6 = _rt_udiv64(10000i64, v5 - (unsigned __int64)(unsigned int)KeMaximumIncrement);
      PpmPerfTimeWindow = v6;
      if ( !PpmPerfControlStartPolicyUpdate
        || (result = (unsigned __int16 *)PpmPerfControlStartPolicyUpdate(v6), (int)result >= 0) )
      {
        result = (unsigned __int16 *)PopExecuteOnTargetProcessors(
                                       (int)&PpmPerfStatesRegistered,
                                       (int)PpmUpdateProcessorPolicyCallback,
                                       (int)&v7,
                                       0);
        if ( PpmPerfControlCompletePolicyUpdate )
          result = (unsigned __int16 *)PpmPerfControlCompletePolicyUpdate(result);
      }
    }
  }
  return result;
}
