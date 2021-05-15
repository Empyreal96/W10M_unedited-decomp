// PopFxStartDeviceAccounting 
 
void PopFxStartDeviceAccounting()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r2
  __int64 v4; // r0
  int v5; // r6
  int v6; // r5
  int v7; // r3
  unsigned int *v8; // r4
  int v9; // r7
  unsigned int v10; // r2
  int v11; // r3
  unsigned int v12; // r7
  int v13; // r4
  int v14; // r10
  unsigned int v15; // r2
  int v16; // r3
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  int v21; // [sp+0h] [bp-28h]
  int v22; // [sp+4h] [bp-24h]

  v0 = PopFxDeviceAccountingLevel;
  __dmb(0xBu);
  if ( v0 )
  {
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v1 + 308);
    v2 = KeAbPreAcquire(&PopFxDeviceListLock, 0, 0);
    do
      v3 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( !v3 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
    __dmb(0xBu);
    if ( v3 )
    {
      sub_50F5FC(v2, 17);
    }
    else
    {
      if ( v2 )
        *(_BYTE *)(v2 + 14) |= 1u;
      v4 = KeQueryInterruptTime();
      v21 = HIDWORD(v4);
      v22 = v4;
      v5 = PopFxDeviceList;
      if ( (int *)PopFxDeviceList != &PopFxDeviceList )
      {
        v6 = HIDWORD(v4);
        do
        {
          if ( *(_DWORD *)(v5 + 28) )
          {
            v7 = PopFxDeviceAccountingLevel;
            __dmb(0xBu);
            if ( v7 < 0 )
            {
              v8 = (unsigned int *)(v5 + 344);
              v9 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v5 + 344);
              }
              else
              {
                do
                  v10 = __ldrex(v8);
                while ( __strex(1u, v8) );
                __dmb(0xBu);
                if ( v10 )
                  KxWaitForSpinLockAndAcquire(v5 + 344);
              }
              v11 = *(unsigned __int8 *)(v5 + 348);
              *(_DWORD *)(v5 + 368) = 0;
              *(_DWORD *)(v5 + 372) = 0;
              *(_DWORD *)(v5 + 376) = 0;
              *(_DWORD *)(v5 + 380) = 0;
              if ( v11 )
              {
                *(_DWORD *)(v5 + 360) = v22;
                *(_DWORD *)(v5 + 364) = v6;
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented(v5 + 344);
              }
              else
              {
                __dmb(0xBu);
                *v8 = 0;
              }
              KfLowerIrql(v9);
            }
            v12 = 0;
            if ( *(_DWORD *)(v5 + 388) )
            {
              do
              {
                v13 = *(_DWORD *)(*(_DWORD *)(v5 + 392) + 4 * v12) + 144;
                v14 = KfRaiseIrql(2);
                if ( (dword_682604 & 0x210000) != 0 )
                {
                  KiAcquireSpinLockInstrumented(v13);
                }
                else
                {
                  do
                    v15 = __ldrex((unsigned int *)v13);
                  while ( __strex(1u, (unsigned int *)v13) );
                  __dmb(0xBu);
                  if ( v15 )
                    KxWaitForSpinLockAndAcquire(v13);
                }
                v16 = *(unsigned __int8 *)(v13 + 4);
                *(_DWORD *)(v13 + 24) = 0;
                *(_DWORD *)(v13 + 28) = 0;
                *(_DWORD *)(v13 + 32) = 0;
                *(_DWORD *)(v13 + 36) = 0;
                if ( v16 )
                {
                  *(_DWORD *)(v13 + 16) = v22;
                  *(_DWORD *)(v13 + 20) = v21;
                }
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  KiReleaseSpinLockInstrumented(v13);
                }
                else
                {
                  __dmb(0xBu);
                  *(_DWORD *)v13 = 0;
                }
                KfLowerIrql(v14);
                ++v12;
              }
              while ( v12 < *(_DWORD *)(v5 + 388) );
              v6 = v21;
            }
          }
          v5 = *(_DWORD *)v5;
        }
        while ( (int *)v5 != &PopFxDeviceList );
      }
      __dmb(0xBu);
      do
        v17 = __ldrex((unsigned int *)&PopFxDeviceListLock);
      while ( v17 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
      if ( v17 != 17 )
        ExfReleasePushLockShared(&PopFxDeviceListLock, 0);
      v18 = KeAbPostRelease(&PopFxDeviceListLock);
      v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
      *(_WORD *)(v19 + 308) = v20;
      if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
        KiCheckForKernelApcDelivery(v18);
    }
  }
}
