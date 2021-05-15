// PopPepRemoveDevice 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopPepRemoveDevice(int *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int *v9; // r1 OVERLAPPED
  int **v10; // r2 OVERLAPPED
  unsigned int v11; // r1
  unsigned int v12; // r2
  int result; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopPepVetoMaskReadyLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned int *)&PopPepVetoMaskReadyLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&PopPepVetoMaskReadyLock) );
  __dmb(0xBu);
  if ( v5 )
    ExfAcquirePushLockSharedEx(&PopPepVetoMaskReadyLock, v3, (unsigned int)&PopPepVetoMaskReadyLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&PopPepDeviceListLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopPepDeviceListLock, v6, (unsigned int)&PopPepDeviceListLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( PopPepLastCheckedDevice == a1 )
    PopPepLastCheckedDevice = (int *)*a1;
  *(_QWORD *)&v9 = *(_QWORD *)a1;
  if ( *(int **)(*a1 + 4) != a1 || *v10 != a1 )
    __fastfail(3u);
  *v10 = v9;
  v9[1] = (int)v10;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( __strex(v11 - 1, (unsigned int *)&PopPepDeviceListLock) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopPepDeviceListLock);
  KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PopPepVetoMaskReadyLock);
  while ( v12 == 17 && __strex(0, (unsigned int *)&PopPepVetoMaskReadyLock) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(&PopPepVetoMaskReadyLock);
  result = KeAbPostRelease((unsigned int)&PopPepVetoMaskReadyLock);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
