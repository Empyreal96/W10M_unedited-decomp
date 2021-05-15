// PopFxCaptureDeviceAccounting 
 
// local variable allocation has failed, the output may be wrong!
void PopFxCaptureDeviceAccounting()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2
  int v5; // r1
  int i; // r6
  int v7; // r3
  unsigned int *v8; // r4
  int v9; // r10
  unsigned int v10; // r2
  int v11; // r7 OVERLAPPED
  int v12; // r8 OVERLAPPED
  char v13; // r3
  unsigned int v14; // r1
  unsigned __int64 v15; // kr10_8
  unsigned int v16; // r2
  __int64 v17; // r0
  unsigned int j; // r10
  unsigned int *v19; // r4
  unsigned int v20; // r2
  unsigned int v21; // r7 OVERLAPPED
  unsigned int v22; // r8 OVERLAPPED
  char v23; // r3
  unsigned int v24; // r1
  unsigned __int64 v25; // kr20_8
  unsigned int v26; // r2
  unsigned int v27; // r2
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  unsigned __int64 v31; // [sp+0h] [bp-38h]
  int v32; // [sp+Ch] [bp-2Ch]
  int v33; // [sp+10h] [bp-28h]
  int v34; // [sp+14h] [bp-24h]
  int vars4; // [sp+3Ch] [bp+4h]

  v0 = PopFxDeviceAccountingLevel;
  __dmb(0xBu);
  if ( v0 )
  {
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v1 + 308);
    v2 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
    v3 = v2;
    do
      v4 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( !v4 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
    __dmb(0xBu);
    if ( v4 )
      ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v2, (unsigned int)&PopFxDeviceListLock);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    LODWORD(v31) = KeQueryInterruptTime();
    HIDWORD(v31) = v5;
    for ( i = PopFxDeviceList; (int *)i != &PopFxDeviceList; i = *(_DWORD *)i )
    {
      v32 = *(_DWORD *)(i + 28);
      if ( v32 )
      {
        v7 = PopFxDeviceAccountingLevel;
        __dmb(0xBu);
        if ( v7 < 0 )
        {
          v8 = (unsigned int *)(i + 344);
          v9 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented(i + 344);
          }
          else
          {
            do
              v10 = __ldrex(v8);
            while ( __strex(1u, v8) );
            __dmb(0xBu);
            if ( v10 )
              KxWaitForSpinLockAndAcquire((unsigned int *)(i + 344));
          }
          *(_QWORD *)&v11 = *(_QWORD *)(i + 368);
          v13 = PopFxDeviceAccountingLevel;
          __dmb(0xBu);
          if ( (v13 & 1) != 0 || !PopFxDeviceAccountingPaused )
          {
            v14 = *(_DWORD *)(i + 364);
            v15 = __PAIR64__(v12, v11) + *(_QWORD *)(i + 376);
            v12 = HIDWORD(v15);
            v11 = v15;
            v16 = *(_DWORD *)(i + 360);
            if ( *(_BYTE *)(i + 348) )
            {
              if ( v31 > __PAIR64__(v14, v16) )
              {
                v12 = (v15 - __PAIR64__(v14, v16) + v31) >> 32;
                v11 = v15 - v16 + v31;
              }
            }
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented((_DWORD *)(i + 344), vars4);
          }
          else
          {
            __dmb(0xBu);
            *v8 = 0;
          }
          v17 = KfLowerIrql(v9);
          PopDiagTraceFxDeviceAccounting(v32, SHIDWORD(v17), v11, v12);
        }
        for ( j = 0; j < *(_DWORD *)(i + 388); ++j )
        {
          v34 = *(_DWORD *)(*(_DWORD *)(i + 392) + 4 * j);
          v19 = (unsigned int *)(v34 + 144);
          v33 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented((int)v19);
          }
          else
          {
            do
              v20 = __ldrex(v19);
            while ( __strex(1u, v19) );
            __dmb(0xBu);
            if ( v20 )
              KxWaitForSpinLockAndAcquire(v19);
          }
          *(_QWORD *)&v21 = *(_QWORD *)(v34 + 168);
          v23 = PopFxDeviceAccountingLevel;
          __dmb(0xBu);
          if ( (v23 & 1) != 0 || !PopFxDeviceAccountingPaused )
          {
            v24 = *(_DWORD *)(v34 + 164);
            v25 = __PAIR64__(v22, v21) + *(_QWORD *)(v34 + 176);
            v22 = HIDWORD(v25);
            v21 = v25;
            v26 = *(_DWORD *)(v34 + 160);
            if ( *(_BYTE *)(v34 + 148) )
            {
              if ( v31 > __PAIR64__(v24, v26) )
              {
                v22 = (v25 - __PAIR64__(v24, v26) + v31) >> 32;
                v21 = v25 - v26 + v31;
              }
            }
          }
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v19, vars4);
          }
          else
          {
            __dmb(0xBu);
            *v19 = 0;
          }
          KfLowerIrql(v33);
          PopDiagTraceFxComponentAccounting(v32, *(_DWORD *)(v34 + 16), v21, v22);
        }
      }
    }
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( v27 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
    if ( v27 != 17 )
      ExfReleasePushLockShared(&PopFxDeviceListLock);
    v28 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
    v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v30 = *(_WORD *)(v29 + 0x134) + 1;
    *(_WORD *)(v29 + 308) = v30;
    if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
      KiCheckForKernelApcDelivery(v28);
  }
}
