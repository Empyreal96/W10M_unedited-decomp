// PopFxInsertAcpiDevice 
 
int __fastcall PopFxInsertAcpiDevice(int a1, int a2, int a3)
{
  unsigned int v4; // r1
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r1
  int **v8; // r0
  unsigned int v9; // r1
  int result; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&PopFxDeviceListLock);
  while ( __strex(v7 | 1, (unsigned __int8 *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopFxDeviceListLock, v5, (unsigned int)&PopFxDeviceListLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = (int **)dword_61F4CC;
  *(_DWORD *)(a3 + 92) = &PopFxAcpiDeviceList;
  *(_DWORD *)(a3 + 96) = v8;
  if ( *v8 != &PopFxAcpiDeviceList )
    __fastfail(3u);
  *v8 = (int *)(a3 + 92);
  dword_61F4CC = a3 + 92;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( __strex(v9 - 1, (unsigned int *)&PopFxDeviceListLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
