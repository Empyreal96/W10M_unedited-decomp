// PpProfileCancelHardwareProfileTransition 
 
int PpProfileCancelHardwareProfileTransition()
{
  int v0; // r5
  int v1; // r6
  unsigned int v2; // r2
  int *v3; // r1
  unsigned int v4; // r2
  unsigned int v5; // r1

  v0 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
  v1 = KfRaiseIrql(1);
  do
    v2 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
  while ( __strex(v2 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v0);
  if ( v0 )
    *(_BYTE *)(v0 + 14) |= 1u;
  dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = (int *)PiProfileDeviceListHead;
  dword_62FB5C = v1;
  if ( (int *)PiProfileDeviceListHead != &PiProfileDeviceListHead )
  {
    do
    {
      if ( *(v3 - 1) != 1 )
      {
        __dmb(0xBu);
        do
          v4 = __ldrex((unsigned int *)&PiProfileDevicesInTransition);
        while ( __strex(v4 - 1, (unsigned int *)&PiProfileDevicesInTransition) );
        __dmb(0xBu);
        *(v3 - 1) = 1;
      }
      v3 = (int *)*v3;
    }
    while ( v3 != &PiProfileDeviceListHead );
    LOBYTE(v1) = dword_62FB5C;
  }
  dword_62FB44 = 0;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
  while ( !v5 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
  if ( v5 )
    ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v5);
  KfLowerIrql((unsigned __int8)v1);
  KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
  if ( PiProfileChangeCancelRequired )
    PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_CHANGE_CANCELLED, 2, 0, 0);
  return KeReleaseSemaphore((int)&PiProfileChangeSemaphore, 0, 1);
}
