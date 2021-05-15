// PfPowerActionNotify 
 
int __fastcall PfPowerActionNotify(int result, char a2, int a3)
{
  int v4; // r0
  int v5; // r5
  int v6; // r2
  int v7; // r1
  int v8; // r2
  int v9; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+Ch] [bp-1Ch]
  unsigned int v11; // [sp+10h] [bp-18h] BYREF
  unsigned int v12; // [sp+14h] [bp-14h]

  v10 = 0;
  v9 = 2 * result;
  if ( (a2 & 1) != 0 )
    v9 = (2 * result) | 1;
  if ( result )
  {
    if ( result == 1 )
    {
      if ( (unsigned int)(a3 - 2) > 3 )
        return result;
      MmPerformMemoryListCommand(1, a2, a3, a3 - 2);
      v5 = PfTSetTraceWorkerPriority(0x10u);
      PfGenerateTrace(&dword_643940, 1);
      if ( v5 <= 31 )
        PfTSetTraceWorkerPriority(v5);
      if ( a3 == 5 )
      {
        v6 = dword_6370D8;
        v7 = 2;
        if ( dword_6372AC == 5 )
        {
          v6 = dword_6370DC;
          v7 = 5;
        }
      }
      else
      {
        v6 = dword_6370D4;
        v7 = 1;
      }
      v10 = PfpScenCtxPrefetchWait(&unk_637290, v7, v6);
      PfpServiceMainThreadUnboost(0);
      goto LABEL_21;
    }
    if ( result != 2 )
    {
      if ( result == 7 && (unsigned int)(a3 - 2) <= 2 )
        ((void (__fastcall *)(int, int, int, int, _DWORD))PfpLogScenarioEvent)(1, 2, 1, dword_6372B0, 0);
LABEL_12:
      KeQueryTickCount((int *)&v11);
      v10 = ((__int64)(v11 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((MEMORY[0xFFFF9004] * v12) << 8);
LABEL_21:
      KeQueryTickCount((int *)&v11);
      return PfLogEvent(
               28,
               ((__int64)(((v11 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                        + ((v12 * (unsigned __int64)MEMORY[0xFFFF9004]) << 8)) >> 10)
             + dword_63728C,
               (int)&v9,
               8u);
    }
    PfpPowerActionStartScenarioTracing(&unk_637290);
    if ( dword_6372AC == 5 )
      PfSnBeginBootPhase(4u);
    PfpScenCtxScenarioSet(&unk_637290, 1, 0, 0);
    PfpScenCtxScenarioSet(&unk_637290, 2, 0, 0);
    v4 = PfpScenCtxScenarioSet(&unk_637290, 5, 0, 0);
    result = PfpStartLoggingHardFaultEvents(v4);
    if ( result >= 0 )
      goto LABEL_12;
  }
  else
  {
    if ( (unsigned int)(a3 - 2) > 2 )
    {
      if ( a3 != 5 )
        return result;
      if ( (a2 & 4) != 0 )
        v8 = 5;
      else
        v8 = 2;
    }
    else
    {
      v8 = 1;
    }
    result = PfpScenCtxScenarioSet(&unk_637290, 0, v8, 0);
  }
  return result;
}
