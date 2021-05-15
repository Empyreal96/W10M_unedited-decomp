// PopFxRegisterDeviceWithPep 
 
int __fastcall PopFxRegisterDeviceWithPep(int *a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v6; // r9
  int *v7; // r10
  int v8; // r6
  unsigned int v10; // r2
  int v11; // r0
  unsigned int v12; // r2
  int *i; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19; // [sp+Ch] [bp-24h]

  v4 = a4;
  v19 = a2;
  v6 = a2;
  v7 = a1;
  if ( a1 )
  {
    v8 = PopPluginRegisterDevice(a1, a2, a3, a4);
  }
  else
  {
    v8 = 0;
    v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v10 + 308);
    v11 = KeAbPreAcquire((unsigned int)&PopFxPluginLock, 0, 0);
    do
      v12 = __ldrex((unsigned int *)&PopFxPluginLock);
    while ( !v12 && __strex(0x11u, (unsigned int *)&PopFxPluginLock) );
    __dmb(0xBu);
    if ( v12 )
      return sub_551410(v11, 17);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    for ( i = (int *)PopFxPluginList; i != &PopFxPluginList; i = (int *)*i )
    {
      v7 = i;
      v8 = PopPluginRegisterDevice(i, v19, a3, a4);
      if ( v8 )
        break;
    }
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)&PopFxPluginLock);
    while ( v14 == 17 && __strex(0, (unsigned int *)&PopFxPluginLock) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(&PopFxPluginLock);
    v15 = KeAbPostRelease((unsigned int)&PopFxPluginLock);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    v4 = a4;
    v6 = v19;
  }
  if ( v8 )
  {
    *(_DWORD *)(a3 + 36) = v7;
    *(_DWORD *)(a3 + 40) = 0;
    v8 = 2;
  }
  return PopPepRegisterDevice(v6, a3, v4, v8, a3 + 32);
}
