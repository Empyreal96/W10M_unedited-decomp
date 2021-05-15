// PopPepInsertDevice 
 
int __fastcall PopPepInsertDevice(int a1, int *a2)
{
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r2
  int result; // r0
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  int **v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r1
  __int16 v14; // r3

  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&PopPepVetoMaskReadyLock, 0, 0);
  do
    v5 = __ldrex((unsigned int *)&PopPepVetoMaskReadyLock);
  while ( !v5 && __strex(0x11u, (unsigned int *)&PopPepVetoMaskReadyLock) );
  __dmb(0xBu);
  if ( v5 )
    return sub_55143C(v4, 17);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v7 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)&PopPepDeviceListLock);
  while ( __strex(v9 | 1, (unsigned __int8 *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopPepDeviceListLock, v7, (unsigned int)&PopPepDeviceListLock);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( PopPepLastCheckedDevice == &PopPepDeviceList )
    PopPepLastCheckedDevice = a2;
  v10 = (int **)dword_61E4DC;
  *a2 = (int)&PopPepDeviceList;
  a2[1] = (int)v10;
  if ( *v10 != &PopPepDeviceList )
    __fastfail(3u);
  *v10 = a2;
  dword_61E4DC = (int)a2;
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
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
