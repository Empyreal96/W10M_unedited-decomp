// PoFxPrepareDevice 
 
int __fastcall PoFxPrepareDevice(int result, int a2, int a3, int a4)
{
  int v4; // r3
  int v5; // r4
  unsigned int v6; // r2
  int v7; // r0
  unsigned int v8; // r2
  int *v9; // r9
  int *v10; // r6
  int (__fastcall *v11)(int, int *); // r3
  unsigned int v12; // r2
  unsigned int v13; // r1
  int v14; // r3
  int v15; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  v4 = *(_DWORD *)(result + 168);
  v17 = a2;
  v5 = result;
  v15 = 0;
  if ( (v4 & 1) != 0 )
    return result;
  if ( (v4 & 2) == 0 )
  {
    result = PopFxFindDeviceAndAllocateUniqueId();
    if ( result == -1073741738 )
      return result;
    *(_DWORD *)(v5 + 168) |= 2u;
  }
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = KeAbPreAcquire((unsigned int)&PopFxPluginLock, 0, 0);
  do
    v8 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( !v8 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
  __dmb(0xBu);
  if ( v8 )
    return sub_5200F4(v7, 17);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = 0;
  v10 = (int *)PopFxPluginList;
  if ( (int *)PopFxPluginList != &PopFxPluginList )
  {
    while ( 1 )
    {
      v11 = (int (__fastcall *)(int, int *))v10[16];
      if ( v11 )
      {
        v15 = v5 + 160;
        if ( !v11(1, &v15) )
          PopFxBugCheck(1541, 1, v10, 0);
        if ( (_BYTE)v16 )
          break;
      }
      v10 = (int *)*v10;
      if ( v10 == &PopFxPluginList )
        goto LABEL_17;
    }
    PopDiagTraceFxDevicePreparation(v5, v10, v5 + 160, 1);
    v9 = v10;
    goto LABEL_20;
  }
LABEL_17:
  if ( v17 )
  {
LABEL_20:
    *(_DWORD *)(v5 + 168) |= 1u;
    *(_DWORD *)(v5 + 72) = v9;
    *(_BYTE *)(v5 + 48) = 0;
    *(_BYTE *)(v5 + 49) = 0;
    *(_BYTE *)(v5 + 50) = 4;
    *(_DWORD *)(v5 + 52) = 0;
    *(_DWORD *)(v5 + 56) = v5 + 56;
    *(_DWORD *)(v5 + 60) = v5 + 56;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( v12 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
  if ( v12 != 17 )
    ExfReleasePushLockShared(&PopFxPluginLock);
  result = KeAbPostRelease((unsigned int)&PopFxPluginLock);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
