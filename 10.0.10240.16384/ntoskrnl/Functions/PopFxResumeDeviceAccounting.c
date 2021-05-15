// PopFxResumeDeviceAccounting 
 
int PopFxResumeDeviceAccounting()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r1
  int v6; // r10
  int v7; // r5
  int v8; // r6
  int v9; // r3
  unsigned int *v10; // r4
  int v11; // r7
  unsigned int v12; // r2
  int v13; // r3
  unsigned int v14; // r7
  int v15; // r4
  int v16; // r10
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  int result; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // [sp+0h] [bp-28h]
  int v24; // [sp+8h] [bp-20h]
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
  v24 = v5;
  v7 = PopFxDeviceList;
  v23 = v4;
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
          v13 = *(unsigned __int8 *)(v7 + 348);
          *(_DWORD *)(v7 + 376) = 0;
          *(_DWORD *)(v7 + 380) = 0;
          if ( v13 )
          {
            *(_DWORD *)(v7 + 360) = v8;
            *(_DWORD *)(v7 + 364) = v6;
          }
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
        v14 = 0;
        if ( *(_DWORD *)(v7 + 388) )
        {
          do
          {
            v15 = *(_DWORD *)(*(_DWORD *)(v7 + 392) + 4 * v14) + 144;
            v16 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(v15);
            }
            else
            {
              do
                v17 = __ldrex((unsigned int *)v15);
              while ( __strex(1u, (unsigned int *)v15) );
              __dmb(0xBu);
              if ( v17 )
                KxWaitForSpinLockAndAcquire((unsigned int *)v15);
            }
            v18 = *(unsigned __int8 *)(v15 + 4);
            *(_DWORD *)(v15 + 32) = 0;
            *(_DWORD *)(v15 + 36) = 0;
            if ( v18 )
            {
              *(_DWORD *)(v15 + 16) = v23;
              *(_DWORD *)(v15 + 20) = v24;
            }
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented((_DWORD *)v15, vars4);
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v15 = 0;
            }
            KfLowerIrql(v16);
            ++v14;
          }
          while ( v14 < *(_DWORD *)(v7 + 388) );
          v6 = v24;
          v8 = v23;
        }
      }
      v7 = *(_DWORD *)v7;
    }
    while ( (int *)v7 != &PopFxDeviceList );
  }
  PopFxDeviceAccountingPaused = 0;
  __dmb(0xBu);
  do
    v19 = __ldrex((unsigned int *)&PopFxDeviceListLock);
  while ( v19 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(&PopFxDeviceListLock);
  result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
