// ExpSvmDereferenceDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpSvmDereferenceDevice(int a1)
{
  int v2; // r7
  int v3; // r0
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r3
  int v7; // r0
  unsigned int v8; // r1
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  unsigned int v11; // r1
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&ExpSvmDeviceListLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&ExpSvmDeviceListLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&ExpSvmDeviceListLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&ExpSvmDeviceListLock, v3, (unsigned int)&ExpSvmDeviceListLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = *(_DWORD *)(a1 + 12) - 1;
  *(_DWORD *)(a1 + 12) = v6;
  if ( !v6 )
  {
    v7 = *(_DWORD *)(a1 + 20);
    v13[0] = 7;
    (*(void (__fastcall **)(int, int *))(a1 + 40))(v7, v13);
    v2 = ((int (__cdecl *)())HalIommuDispatch[7])();
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)&ExTbFlushActive);
    while ( __strex(v8 - 1, (unsigned int *)&ExTbFlushActive) );
    __dmb(0xBu);
    *(_QWORD *)&v9 = *(_QWORD *)a1;
    if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v10 != a1 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    (*(void (__fastcall **)(_DWORD))(a1 + 28))(*(_DWORD *)(a1 + 20));
    ExFreePoolWithTag(a1);
  }
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&ExpSvmDeviceListLock);
  while ( __strex(v11 - 1, (unsigned int *)&ExpSvmDeviceListLock) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpSvmDeviceListLock);
  KeAbPostRelease((unsigned int)&ExpSvmDeviceListLock);
  return v2;
}
