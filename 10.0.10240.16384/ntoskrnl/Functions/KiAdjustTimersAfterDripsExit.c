// KiAdjustTimersAfterDripsExit 
 
int __fastcall KiAdjustTimersAfterDripsExit(int result)
{
  char *v1; // r5
  int v2; // r4
  char v3[4]; // [sp+0h] [bp-30h] BYREF
  int v4; // [sp+4h] [bp-2Ch]
  int v5; // [sp+8h] [bp-28h]
  int v6; // [sp+Ch] [bp-24h]
  __int64 v7; // [sp+10h] [bp-20h]
  char v8; // [sp+18h] [bp-18h]

  if ( KiSerializeTimerExpiration
    && KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime > (__int64)((unsigned int)KiTimerRebaseThresholdOnDripsExit
                                                                           * (unsigned __int64)(unsigned int)dword_989680) )
  {
    MEMORY[0xFFFF93B0] += KiClockTimerOneShotEndTime - KiClockTimerOneShotStartTime;
    if ( MEMORY[0xFFFF93B4] < 0 )
      __fastfail(5u);
    v3[0] = 1;
    v7 = KiClockTimerOneShotStartTime - KiClockTimerOneShotEndTime;
    v4 = 0;
    v5 = 0;
    v6 = 0;
    v8 = 1;
    if ( KiSerializeTimerExpiration )
      v1 = (char *)KiProcessorBlock + 4096;
    else
      v1 = (char *)(result + 4096);
    v2 = KfRaiseIrql(2);
    KiAdjustTimerDueTimes(((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, (int)v1, (int)v3);
    result = KfLowerIrql(v2);
  }
  return result;
}
