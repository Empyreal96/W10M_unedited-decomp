// PopRundownPowerSettings 
 
unsigned int PopRundownPowerSettings()
{
  int v0; // r5
  int v1; // r6
  unsigned int v2; // r2
  int *v3; // r5
  int v4; // r8
  int v5; // r2
  unsigned int v6; // r1

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
  v3 = (int *)PopPowerSettings;
  dword_61F33C = v1;
  v4 = dword_61EC0C;
  if ( (int *)PopPowerSettings != &PopPowerSettings )
  {
    do
    {
      v5 = v3[v4 + 12];
      if ( v5 )
        PopDiagTracePowerSetting(1, (int)(v3 + 4), *(_DWORD *)(v5 + 4), v5 + 12);
      v3 = (int *)*v3;
    }
    while ( v3 != &PopPowerSettings );
    LOBYTE(v1) = dword_61F33C;
  }
  dword_61F324 = 0;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v6 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v6 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v6);
  KfLowerIrql((unsigned __int8)v1);
  return KeAbPostRelease((unsigned int)&PopSettingLock);
}
