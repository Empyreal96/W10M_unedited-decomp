// KseQueryDeviceDataList 
 
int __fastcall KseQueryDeviceDataList(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r4
  int v9; // r4
  unsigned __int8 *v10; // r9
  unsigned int v11; // r2
  int v12; // r0
  int v13; // r5
  unsigned int v14; // r2
  _DWORD *v15; // r0
  _DWORD *v16; // r5
  unsigned int *v17; // r6
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  _DWORD *v23; // [sp+0h] [bp-48h] BYREF
  int v24; // [sp+4h] [bp-44h]
  char v25[20]; // [sp+8h] [bp-40h] BYREF
  char v26[44]; // [sp+1Ch] [bp-2Ch] BYREF

  v5 = a2;
  v23 = 0;
  v24 = a2;
  v6 = dword_6416D4;
  __dmb(0xBu);
  if ( v6 != 2 || (KseEngine & 2) != 0 )
    return -1073741275;
  if ( !a1 || !a4 )
    return -1073741811;
  v9 = KsepDbQueryRegistryDeviceDataList();
  if ( v9 == -1073741275 )
  {
    if ( KsepShimDbChanged() )
    {
      KseResetDeviceCache();
LABEL_27:
      v9 = KsepDbCacheReadDevice(a1, &v23);
      if ( v9 >= 0 )
      {
        v9 = KsepDbCacheQueryDeviceDataList(v23, v5, a3, a4);
        if ( KsepDbCacheInsertDevice(a1, v23) < 0 )
          KsepCacheDeviceFree((int)v23);
      }
      return v9;
    }
    RtlInitUnicodeString((unsigned int)v26, a1);
    v10 = (unsigned __int8 *)dword_6416F8;
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v11 + 308);
    v12 = KeAbPreAcquire((unsigned int)v10, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v10);
    while ( __strex(v14 | 1, v10) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v10, v12, (unsigned int)v10);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v15 = KsepCacheLookup(dword_6416F8, (int)v25);
    v16 = v15;
    v23 = v15;
    if ( v15 )
      v9 = KsepDbCacheQueryDeviceDataList(v15, v24, a3, a4);
    v17 = (unsigned int *)dword_6416F8;
    __dmb(0xBu);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 - 1, v17) );
    if ( (v18 & 2) != 0 && (v18 & 4) == 0 )
      ExfTryToWakePushLock(v17);
    v19 = KeAbPostRelease((unsigned int)v17);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
    if ( !v16 )
    {
      v5 = v24;
      goto LABEL_27;
    }
  }
  return v9;
}
