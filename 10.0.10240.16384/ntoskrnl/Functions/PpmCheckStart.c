// PpmCheckStart 
 
int __fastcall PpmCheckStart(int a1)
{
  __int64 v2; // r0
  unsigned __int64 v3; // r0
  unsigned __int64 v4; // kr00_8
  int v5; // r2
  int (__fastcall *v6)(_DWORD); // r3
  int v7; // r0
  __int64 v9; // [sp+4h] [bp-58h] BYREF
  int v10; // [sp+Ch] [bp-50h]

  PpmCheckCurrentPipelineId = a1;
  v2 = RtlGetInterruptTimePrecise(&v9);
  v10 = a1;
  *(_QWORD *)&PpmCheckTime = v2;
  v9 = PpmCheckLastExecutionTime;
  if ( PpmEtwRegistered
    && (LODWORD(v2) = EtwEventEnabled(PpmEtwHandle, dword_61DEC4, PPM_ETW_PERF_CHECK_START), (_DWORD)v2) )
  {
    LODWORD(v3) = sub_541140();
  }
  else
  {
    PpmCheckPipeline = *(_DWORD *)(PpmCheckPipelines + 4 * a1);
    if ( !PpmCheckPipeline )
      PpmCheckPipeline = *(_DWORD *)PpmCheckPipelines;
    PpmCheckPipelineIndex = 0;
    v4 = PpmPerfLatencyBoostExpiration;
    v3 = KeQueryInterruptTime(v2);
    PpmCheckLatencyBoostActive = v4 >= v3;
    v5 = PpmCheckPipelineIndex;
    v6 = *(int (__fastcall **)(_DWORD))(PpmCheckPipeline + 4 * PpmCheckPipelineIndex);
    if ( v6 )
    {
      while ( 1 )
      {
        PpmCheckPipelineIndex = v5 + 1;
        LODWORD(v3) = v6(v3);
        if ( !(_DWORD)v3 )
          break;
        v5 = PpmCheckPipelineIndex;
        v6 = *(int (__fastcall **)(_DWORD))(PpmCheckPipeline + 4 * PpmCheckPipelineIndex);
        if ( !v6 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      v7 = PpmReleaseLock(&PpmPerfPolicyLock);
      LODWORD(v3) = PpmEventTracePerfCheckStop(v7);
    }
  }
  return v3;
}
