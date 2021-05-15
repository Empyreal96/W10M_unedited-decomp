// PopFxLowPowerEpochCallback 
 
int __fastcall PopFxLowPowerEpochCallback(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r2
  int *i; // r4
  void (__fastcall *v12)(int, _DWORD *); // r2
  char v13; // r2
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  _DWORD v18[6]; // [sp+0h] [bp-18h] BYREF

  v18[0] = a3;
  v18[1] = a4;
  v6 = -1073741811;
  if ( !memcmp((unsigned int)&GUID_LOW_POWER_EPOCH, a1, 16) && a3 == 4 && a2 )
  {
    PopFxLowPowerEpoch = *a2;
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v7 + 308);
    v8 = KeAbPreAcquire(&PopFxPluginLock, 0, 0);
    do
      v9 = __ldrex((unsigned int *)&PopFxPluginLock);
    while ( !v9 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
    __dmb(0xBu);
    if ( v9 )
      return sub_5290E8(v8, 17);
    if ( v8 )
      *(_BYTE *)(v8 + 14) |= 1u;
    for ( i = (int *)PopFxPluginList; i != &PopFxPluginList; i = (int *)*i )
    {
      v12 = (void (__fastcall *)(int, _DWORD *))i[16];
      if ( v12 )
      {
        LOBYTE(v18[0]) = PopFxLowPowerEpoch;
        v12(24, v18);
      }
    }
    v13 = PopFxLowPowerEpoch;
    __dmb(0xBu);
    LOBYTE(PopPepLowPowerEpoch) = v13;
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&PopFxPluginLock);
    while ( v14 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(&PopFxPluginLock, 0);
    v15 = KeAbPostRelease(&PopFxPluginLock);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    v6 = 0;
  }
  return v6;
}
