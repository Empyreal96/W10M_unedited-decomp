// PnpNotifyDeviceClassChange 
 
int PnpNotifyDeviceClassChange()
{
  int v0; // r0
  unsigned int v1; // r2

  KeAbPreAcquire((unsigned int)&PnpDeviceClassNotifyLock, 0, 0);
  v0 = KfRaiseIrql(1);
  do
    v1 = __ldrex((unsigned __int8 *)&PnpDeviceClassNotifyLock);
  while ( __strex(v1 & 0xFE, (unsigned __int8 *)&PnpDeviceClassNotifyLock) );
  __dmb(0xBu);
  if ( (v1 & 1) != 0 )
    JUMPOUT(0x7EE892);
  return sub_7EE888(v0);
}
