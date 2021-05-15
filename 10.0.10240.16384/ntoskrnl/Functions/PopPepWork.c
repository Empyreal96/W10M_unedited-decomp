// PopPepWork 
 
int PopPepWork()
{
  unsigned int v0; // r3
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  int *v4; // r9
  int v6; // r0
  unsigned int v7; // r1
  int *v8; // r5
  unsigned int *v9; // r7
  unsigned int v10; // r2
  int v11; // r6
  unsigned int v12; // r1
  unsigned int v13; // r2
  _DWORD *v14; // r4
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // r0
  int v23; // r0
  unsigned __int8 *v24; // r3
  unsigned int v25; // r1
  unsigned int v26; // r0
  unsigned int v27; // r1
  unsigned int v28; // [sp+8h] [bp-30h]
  int v29; // [sp+18h] [bp-20h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&PopPepDeviceListLock, v1, &PopPepDeviceListLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = PopPepLastCheckedDevice;
  if ( PopPepLastCheckedDevice == &PopPepDeviceList )
    return sub_53FA94();
  v6 = KfRaiseIrql(2);
  v7 = 0;
  v29 = v6;
  v28 = 0;
  while ( 2 )
  {
    v8 = v4;
    do
    {
      v9 = (unsigned int *)(v8 + 11);
      if ( v7 )
      {
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8 + 11);
        }
        else
        {
          v24 = (unsigned __int8 *)v8 + 47;
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 | 0x80, v24) );
          __dmb(0xBu);
          if ( v25 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v8 + 11);
          while ( 1 )
          {
            v26 = *v9;
            if ( (*v9 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v26 & 0x40000000) == 0 )
            {
              do
                v27 = __ldrex(v9);
              while ( v27 == v26 && __strex(v26 | 0x40000000, v9) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        goto LABEL_17;
      }
      if ( (dword_682604 & 0x210000) != 0 )
      {
        if ( !ExpTryAcquireSpinLockExclusiveAtDpcLevelInstrumented(v8 + 11) )
        {
LABEL_25:
          v7 = v28;
          goto LABEL_26;
        }
LABEL_17:
        v11 = v8[18];
        if ( v11 )
        {
          v22 = PopPepGetReadyActivityType(v8 + 12, 0, 0);
          if ( v22 != 6 )
          {
            v16 = PopPepStartActivity(v8, 0, v8 + 12, v22);
            if ( (dword_682604 & 0x10000) != 0 )
              goto LABEL_46;
            goto LABEL_32;
          }
        }
        v12 = v8[30];
        v13 = 0;
        if ( v12 )
        {
          v14 = v8 + 32;
          while ( !v14[18] )
          {
            ++v13;
            v14 += 42;
            if ( v13 >= v12 )
              goto LABEL_22;
          }
          v15 = PopPepGetReadyActivityType(v14 + 12, 1, 3);
          v16 = PopPepStartActivity(v8, v14, v14 + 12, v15);
          if ( (dword_682604 & 0x10000) == 0 )
            goto LABEL_32;
LABEL_46:
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v8 + 11);
          goto LABEL_33;
        }
LABEL_22:
        if ( v11 )
        {
          v23 = PopPepGetReadyActivityType(v8 + 12, 4, 5);
          v16 = PopPepStartActivity(v8, 0, v8 + 12, v23);
          if ( (dword_682604 & 0x10000) != 0 )
            goto LABEL_46;
LABEL_32:
          __dmb(0xBu);
          v8[11] = 0;
          goto LABEL_33;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v8 + 11);
        }
        else
        {
          __dmb(0xBu);
          *v9 = 0;
        }
        goto LABEL_25;
      }
      do
        v10 = __ldrex(v9);
      while ( !v10 && __strex(0x80000000, v9) );
      __dmb(0xBu);
      if ( !v10 )
        goto LABEL_17;
LABEL_26:
      v8 = (int *)*v8;
      if ( v8 == &PopPepDeviceList )
        v8 = (int *)*v8;
    }
    while ( v8 != v4 );
    v28 = ++v7;
    if ( v7 < 2 )
      continue;
    break;
  }
  v16 = 0;
LABEL_33:
  KfLowerIrql(v29);
  if ( v8 != v4 )
  {
    do
      v17 = __ldrex((unsigned int *)&PopPepLastCheckedDevice);
    while ( __strex((unsigned int)v8, (unsigned int *)&PopPepLastCheckedDevice) );
  }
  __dmb(0xBu);
  do
    v18 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( v18 == 17 && __strex(0, (unsigned int *)&PopPepDeviceListLock) );
  if ( v18 != 17 )
    ExfReleasePushLockShared(&PopPepDeviceListLock, 0);
  v19 = KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
  v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
  *(_WORD *)(v20 + 308) = v21;
  if ( v21 )
    return v16;
  if ( *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
    KiCheckForKernelApcDelivery(v19);
  return v16;
}
