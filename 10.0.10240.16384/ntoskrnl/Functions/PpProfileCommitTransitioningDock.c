// PpProfileCommitTransitioningDock 
 
unsigned int __fastcall PpProfileCommitTransitioningDock(unsigned int result, int a2, int a3, int a4)
{
  _DWORD *v5; // r4
  unsigned int v6; // r0
  int v7; // r5
  int v8; // r8
  unsigned int v9; // r2
  _DWORD *v10; // r2
  __int64 v11; // r0
  unsigned __int8 v12; // r5
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int v15; // r1
  int v16; // [sp+0h] [bp-20h] BYREF
  int v17[7]; // [sp+4h] [bp-1Ch] BYREF

  v16 = a3;
  v17[0] = a4;
  v5 = (_DWORD *)result;
  if ( a2 == 3 )
  {
    v6 = *(_DWORD *)(result + 384);
    if ( v6 )
    {
      ExFreePoolWithTag(v6);
      v5[96] = 0;
    }
    v7 = KeAbPreAcquire((unsigned int)&PiProfileDeviceListLock, 0, 0);
    v8 = KfRaiseIrql(1);
    do
      v9 = __ldrex((unsigned __int8 *)&PiProfileDeviceListLock);
    while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PiProfileDeviceListLock) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PiProfileDeviceListLock, v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    dword_62FB44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = v5 + 94;
    dword_62FB5C = v8;
    v11 = *((_QWORD *)v5 + 47);
    if ( *(_DWORD **)(v11 + 4) != v5 + 94 || *(_DWORD **)HIDWORD(v11) != v10 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v11) = v11;
    *(_DWORD *)(v11 + 4) = HIDWORD(v11);
    *v10 = v10;
    v5[95] = v5 + 94;
    --PiProfileDeviceCount;
    dword_62FB44 = 0;
    v12 = dword_62FB5C;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&PiProfileDeviceListLock);
    while ( !v13 && __strex(1u, (unsigned int *)&PiProfileDeviceListLock) );
    if ( v13 )
      ExpReleaseFastMutexContended((unsigned int *)&PiProfileDeviceListLock, v13);
    KfLowerIrql(v12);
    result = KeAbPostRelease((unsigned int)&PiProfileDeviceListLock);
  }
  else if ( !*(_DWORD *)(result + 384) )
  {
    result = PnpIrpQueryID(*(_DWORD *)(result + 16), 4, v17);
    v5[96] = v17[0];
  }
  v5[93] = 1;
  __dmb(0xBu);
  do
  {
    v14 = __ldrex((unsigned int *)&PiProfileDevicesInTransition);
    v15 = v14 - 1;
  }
  while ( __strex(v15, (unsigned int *)&PiProfileDevicesInTransition) );
  __dmb(0xBu);
  if ( !v15 )
  {
    LOBYTE(v16) = 0;
    if ( (a2 != 2 || v5[96]) && PnpProfileUpdateHardwareProfile((int)&v16) >= 0 && (_BYTE)v16 )
    {
      PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_CHANGE_COMPLETE, 2, 0, 0);
      PiProfileUpdateDeviceTree();
    }
    else if ( PiProfileChangeCancelRequired )
    {
      PnpRequestHwProfileChangeNotification(&GUID_HWPROFILE_CHANGE_CANCELLED, 2, 0, 0);
    }
    result = KeReleaseSemaphore((int)&PiProfileChangeSemaphore, 0, 1);
  }
  return result;
}
