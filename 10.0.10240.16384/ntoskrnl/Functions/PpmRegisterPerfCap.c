// PpmRegisterPerfCap 
 
int __fastcall PpmRegisterPerfCap(int a1)
{
  unsigned int v2; // r6
  __int64 v3; // r8
  int v4; // r7
  int v5; // r10
  int v6; // r5
  int v7; // r3
  __int64 v8; // r0
  __int64 v9; // r0
  int v10; // r0
  int v11; // r4

  if ( *(_BYTE *)(a1 + 7) )
    return -1073741811;
  if ( *(_WORD *)(a1 + 4) || (v2 = *(unsigned __int8 *)(a1 + 6), v2 >= KeNumberProcessors_0) )
    v2 = -1;
  if ( v2 == -1 )
    return -1073741811;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v3 = *(_QWORD *)(a1 + 8);
  if ( v2 >= KeNumberProcessors_0 )
    v4 = 0;
  else
    v4 = (int)*(&KiProcessorBlock + v2);
  v5 = *(_DWORD *)(v4 + 3200);
  v6 = *(_DWORD *)(v4 + 3204);
  if ( v5 && v6 )
  {
    *(_DWORD *)(v6 + 24) = *(_DWORD *)(a1 + 16);
    v7 = *(_DWORD *)(v6 + 16);
    if ( v7 != (_DWORD)v3 )
    {
      if ( v7 == 100 )
      {
        LODWORD(v8) = KeQueryInterruptTime();
        *(_QWORD *)(v6 + 32) = v8;
      }
      else if ( (_DWORD)v3 == 100 )
      {
        LODWORD(v9) = KeQueryInterruptTime();
        v10 = _rt_udiv64(10000i64, v9 - *(_QWORD *)(v6 + 32));
        PopDiagTraceProcessorThrottleDurationPerfTrack(v10, v2);
        *(_DWORD *)(v6 + 32) = 0;
        *(_DWORD *)(v6 + 36) = 0;
      }
      *(_DWORD *)(v6 + 16) = v3;
      PpmEventBiosCapChange(v4, v3);
      PopDiagTraceProcessorThrottlePerfTrack(100 - v3, v2);
    }
    if ( *(_DWORD *)(v6 + 20) != HIDWORD(v3) )
    {
      *(_DWORD *)(v6 + 20) = HIDWORD(v3);
      PpmEventThermalCapChange(v4, HIDWORD(v3));
    }
    dword_61749C |= 1 << *(_DWORD *)(*(_DWORD *)(v5 + 8) + 20);
    PpmCheckApplyPerfConstraints(0);
    v11 = 0;
  }
  else
  {
    v11 = -1073741811;
    PpmReleaseLock(&PpmPerfPolicyLock);
  }
  return v11;
}
