// PopInitilizeAcDcSettings 
 
int PopInitilizeAcDcSettings()
{
  int v0; // r7
  int v1; // r5
  int v2; // r6
  unsigned int v3; // r2
  int result; // r0
  _DWORD *v5; // r0
  unsigned int v6; // r1
  int v7[6]; // [sp+8h] [bp-18h] BYREF

  v7[0] = 0;
  PopSetPowerSettingValue(&GUID_ACDC_POWER_SOURCE, -1, 0, 4, v7);
  v7[0] = 1;
  PopSetPowerSettingValue(&GUID_ACDC_POWER_SOURCE, -1, 1, 4, v7);
  v0 = 0;
  v1 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v2 = KfRaiseIrql(1);
  do
    v3 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v3 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v3 & 1) == 0 )
    return sub_529114();
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61F33C = v2;
  v5 = (_DWORD *)PopFindPowerSettingConfiguration(&GUID_ACDC_POWER_SOURCE, -1);
  if ( v5[10] || v5[11] )
  {
    v0 = 1;
    v5[9] |= 1u;
    LOBYTE(v2) = dword_61F33C;
  }
  dword_61F324 = 0;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v6 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v6 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v6);
  KfLowerIrql((unsigned __int8)v2);
  result = KeAbPostRelease((unsigned int)&PopSettingLock);
  if ( (unsigned int)PopOsInitPhase >= 3 )
  {
    if ( v0 )
      PopSetNotificationWork(128);
    result = PopSetNotificationWork(32);
  }
  return result;
}
