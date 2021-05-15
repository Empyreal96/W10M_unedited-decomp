// PpProfileCancelTransitioningDock 
 
unsigned int __fastcall PpProfileCancelTransitioningDock(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r7
  unsigned int v7; // r2
  unsigned int v8; // r4
  unsigned int v9; // r4
  unsigned __int8 v10; // r6
  unsigned int v11; // r1
  unsigned int result; // r0
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v5 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_62FB5C = v6;
  *(_DWORD *)(a1 + 372) = 1;
  __dmb(0xBu);
  do
  {
    v8 = __ldrex((unsigned int *)&PiProfileDevicesInTransition);
    v9 = v8 - 1;
  }
  while ( __strex(v9, (unsigned int *)&PiProfileDevicesInTransition) );
  __dmb(0xBu);
  dword_62FB44 = 0;
  v10 = dword_62FB5C;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
  while ( !v11 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v11);
  KfLowerIrql(v10);
  result = KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
  if ( !v9 )
  {
    if ( PnpProfileUpdateHardwareProfile((int)v13) >= 0 && LOBYTE(v13[0]) )
    {
      PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_CHANGE_COMPLETE, 2, 0, 0);
      PiProfileUpdateDeviceTree();
    }
    else
    {
      PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_CHANGE_CANCELLED, 2, 0, 0);
    }
    result = KeReleaseSemaphore((int)&PiProfileChangeSemaphore, 0, 1);
  }
  return result;
}
