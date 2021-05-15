// PpProfileQueryHardwareProfileChange 
 
int __fastcall PpProfileQueryHardwareProfileChange(int a1, int a2, _DWORD *a3, unsigned __int16 *a4)
{
  int v6; // r7
  int v7; // r8
  unsigned int v8; // r5
  int *v9; // r2
  int v10; // r4
  __int64 v11; // kr00_8
  unsigned int v12; // r1
  int result; // r0
  bool v14; // r2

  v6 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = (int *)PiProfileDeviceListHead;
  dword_62FB5C = v7;
  v10 = 0;
  while ( v9 != &PiProfileDeviceListHead )
  {
    v11 = *(_QWORD *)(v9 - 1);
    v9 = (int *)*v9;
    if ( (_DWORD)v11 == 2 )
      v10 = 1;
  }
  dword_62FB44 = 0;
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
  while ( !v12 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
  if ( v12 )
    ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v12);
  KfLowerIrql((unsigned __int8)v7);
  KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
  if ( a1 )
    return 0;
  if ( v10 )
  {
    v14 = 0;
    result = 0;
  }
  else
  {
    result = PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_QUERY_CHANGE, a2, a3, a4);
    v14 = result >= 0;
  }
  PiProfileChangeCancelRequired = v14;
  return result;
}
