// PopFxPauseDeviceAccounting 
 
int PopFxPauseDeviceAccounting()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  unsigned int v6; // r10
  int v7; // r5
  int v8; // r6
  int v9; // r3
  unsigned int *v10; // r4
  int v11; // r9
  unsigned int v12; // r2
  unsigned int v13; // r0
  unsigned int v14; // r7
  unsigned __int64 v15; // kr08_8
  unsigned __int64 v16; // kr10_8
  unsigned int i; // r7
  int v18; // r4
  int v19; // r9
  unsigned int v20; // r2
  unsigned int v21; // r0
  unsigned int v22; // lr
  unsigned __int64 v23; // kr20_8
  unsigned __int64 v24; // kr28_8
  unsigned int v25; // r2
  int result; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int vars4; // [sp+2Ch] [bp+4h]

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v1, (unsigned int)&PopFxDeviceListLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = KeQueryInterruptTime();
  v6 = v5;
  v7 = PopFxDeviceList;
  if ( (int *)PopFxDeviceList != &PopFxDeviceList )
  {
    v8 = v4;
    do
    {
      if ( *(_DWORD *)(v7 + 28) )
      {
        v9 = PopFxDeviceAccountingLevel;
        __dmb(0xBu);
        if ( v9 < 0 )
        {
          v10 = (unsigned int *)(v7 + 344);
          v11 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v7 + 344);
          }
          else
          {
            do
              v12 = __ldrex(v10);
            while ( __strex(1u, v10) );
            __dmb(0xBu);
            if ( v12 )
              KxWaitForSpinLockAndAcquire((unsigned int *)(v7 + 344));
          }
          v14 = *(_DWORD *)(v7 + 380);
          v13 = *(_DWORD *)(v7 + 376);
          v15 = *(_QWORD *)(v7 + 360);
          if ( *(_BYTE *)(v7 + 348) && __PAIR64__(v6, v8) > v15 )
          {
            v16 = __PAIR64__(v14, v13) - v15 + __PAIR64__(v6, v8);
            v14 = HIDWORD(v16);
            v13 = v16;
          }
          *(_QWORD *)(v7 + 368) += __PAIR64__(v14, v13);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented((_DWORD *)(v7 + 344), vars4);
          }
          else
          {
            __dmb(0xBu);
            *v10 = 0;
          }
          KfLowerIrql(v11);
        }
        for ( i = 0; i < *(_DWORD *)(v7 + 388); ++i )
        {
          v18 = *(_DWORD *)(*(_DWORD *)(v7 + 392) + 4 * i) + 144;
          v19 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(v18);
          }
          else
          {
            do
              v20 = __ldrex((unsigned int *)v18);
            while ( __strex(1u, (unsigned int *)v18) );
            __dmb(0xBu);
            if ( v20 )
              KxWaitForSpinLockAndAcquire((unsigned int *)v18);
          }
          v22 = *(_DWORD *)(v18 + 36);
          v21 = *(_DWORD *)(v18 + 32);
          v23 = *(_QWORD *)(v18 + 16);
          if ( *(_BYTE *)(v18 + 4) && __PAIR64__(v6, v8) > v23 )
          {
            v24 = __PAIR64__(v22, v21) - v23 + __PAIR64__(v6, v8);
            v22 = HIDWORD(v24);
            v21 = v24;
          }
          *(_QWORD *)(v18 + 24) += __PAIR64__(v22, v21);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented((_DWORD *)v18, vars4);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v18 = 0;
          }
          KfLowerIrql(v19);
        }
      }
      v7 = *(_DWORD *)v7;
    }
    while ( (int *)v7 != &PopFxDeviceList );
  }
  PopFxDeviceAccountingPaused = 1;
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v25 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v25 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
