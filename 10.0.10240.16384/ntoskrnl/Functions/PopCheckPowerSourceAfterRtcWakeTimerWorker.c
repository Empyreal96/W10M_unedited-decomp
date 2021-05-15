// PopCheckPowerSourceAfterRtcWakeTimerWorker 
 
int PopCheckPowerSourceAfterRtcWakeTimerWorker()
{
  int v0; // r5
  int v1; // r7
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  int v5; // r2
  unsigned int v6; // r1
  char v8[48]; // [sp+0h] [bp-30h] BYREF

  if ( PopSleepStats )
  {
    PopCurrentPowerStatePrecise(v8);
    if ( !v8[0] )
    {
      v0 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
      v1 = KfRaiseIrql(1);
      do
        v2 = __ldrex((unsigned __int8 *)&PopSettingLock);
      while ( __strex(v2 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
      __dmb(0xBu);
      if ( (v2 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PopSettingLock, v0);
      if ( v0 )
        *(_BYTE *)(v0 + 14) |= 1u;
      dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61F33C = v1;
      v3 = PopFindPowerSettingConfiguration(&GUID_ALLOW_RTC_WAKE, -1);
      v4 = 0;
      if ( v3 )
      {
        v5 = *(_DWORD *)(v3 + 52);
        if ( v5 )
        {
          if ( *(_DWORD *)(v5 + 4) >= 4u )
            v4 = *(_DWORD *)(v5 + 12);
        }
      }
      dword_61F324 = 0;
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned int *)&PopSettingLock);
      while ( !v6 && __strex(1u, (unsigned int *)&PopSettingLock) );
      if ( v6 )
        ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v6);
      KfLowerIrql((unsigned __int8)v1);
      KeAbPostRelease((unsigned int)&PopSettingLock);
      if ( !v4 )
        NtInitiatePowerAction(dword_61F180, unk_61F184, 0x80000000, 1);
    }
  }
  PopOkayToQueueNextWorkItem(&PopCheckPowerSourceAfterRtcWakeTimer[22]);
  return KeSetEvent((int)&PopCheckPowerSourceAfterRtcWakeCompleted, 0, 0);
}
