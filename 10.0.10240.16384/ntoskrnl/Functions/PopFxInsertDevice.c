// PopFxInsertDevice 
 
int __fastcall PopFxInsertDevice(int a1, int a2, int *a3)
{
  unsigned int v4; // r1
  int v5; // r0
  unsigned int v6; // r1
  int result; // r0
  int **v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r1
  __int16 v11; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  do
    v6 = __ldrex((unsigned __int8 *)&PopFxDeviceListLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    return sub_551384(v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v8 = (int **)dword_61F4D4;
  *a3 = (int)&PopFxDeviceList;
  a3[1] = (int)v8;
  if ( *v8 != &PopFxDeviceList )
    __fastfail(3u);
  *v8 = a3;
  dword_61F4D4 = (int)a3;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( __strex(v9 - 1, (unsigned int *)&PopFxDeviceListLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
