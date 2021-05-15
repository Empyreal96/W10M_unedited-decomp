// PopFxAcpiPrepareDevice 
 
int __fastcall PopFxAcpiPrepareDevice(int a1, int a2, int **a3, _BYTE *a4)
{
  int v6; // r5
  int *v7; // r8
  unsigned int v8; // r2
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int *i; // r4
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v6 = PopFxFindAcpiDeviceByUniqueId(a1, 0);
  if ( v6 >= 0 )
    return -1073741823;
  v7 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = KeAbPreAcquire((unsigned int)&PopFxPluginLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( !v11 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
  __dmb(0xBu);
  if ( v11 )
    ExfAcquirePushLockSharedEx(&PopFxPluginLock, v9, (unsigned int)&PopFxPluginLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  for ( i = (int *)PopFxPluginList; i != &PopFxPluginList; i = (int *)*i )
  {
    if ( (unsigned int)i[2] >= 3 && i[18] && PopPluginAcpiNotificationStrict(i, 1, a2) && *(_BYTE *)(a2 + 8) )
    {
      v7 = i;
      break;
    }
  }
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&PopFxPluginLock);
  while ( v13 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
  if ( v13 != 17 )
    ExfReleasePushLockShared(&PopFxPluginLock);
  v14 = KeAbPostRelease((unsigned int)&PopFxPluginLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  if ( v7 )
  {
    *a3 = v7;
    *a4 = 1;
    v6 = 0;
  }
  return v6;
}
