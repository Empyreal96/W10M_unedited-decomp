// PopDispatchPowerSettingCallbacks 
 
int PopDispatchPowerSettingCallbacks()
{
  int v0; // r0
  unsigned int v1; // r2

  KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v0 = KfRaiseIrql(1);
  do
    v1 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v1 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    JUMPOUT(0x7F2AA8);
  return sub_7F2AA0(v0);
}
