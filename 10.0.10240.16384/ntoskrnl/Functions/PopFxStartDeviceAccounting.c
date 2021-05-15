// PopFxStartDeviceAccounting 
 
void PopFxStartDeviceAccounting()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r0
  int v5; // r1
  int v6; // r6
  int v7; // r5
  int v8; // r3
  unsigned int *v9; // r4
  int v10; // r7
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r7
  int v14; // r4
  int v15; // r10
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  unsigned int v20; // r1
  int v21; // r3
  int v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  v0 = PopFxDeviceAccountingLevel;
  __dmb(0xBu);
  if ( v0 )
  {
    v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v1 + 308);
    v2 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
    do
      v3 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( !v3 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
    __dmb(0xBu);
    if ( v3 )
    {
      sub_50F5FC();
    }
    else
    {
      if ( v2 )
        *(_BYTE *)(v2 + 14) |= 1u;
      v4 = KeQueryInterruptTime();
      v22 = v5;
      v23 = v4;
      v6 = PopFxDeviceList;
      if ( (int *)PopFxDeviceList != &PopFxDeviceList )
      {
        v7 = v5;
        do
        {
          if ( *(_DWORD *)(v6 + 28) )
          {
            v8 = PopFxDeviceAccountingLevel;
            __dmb(0xBu);
            if ( v8 < 0 )
            {
              v9 = (unsigned int *)(v6 + 344);
              v10 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v6 + 344);
              }
              else
              {
                do
                  v11 = __ldrex(v9);
                while ( __strex(1u, v9) );
                __dmb(0xBu);
                if ( v11 )
                  KxWaitForSpinLockAndAcquire((unsigned int *)(v6 + 344));
              }
              v12 = *(unsigned __int8 *)(v6 + 348);
              *(_DWORD *)(v6 + 368) = 0;
              *(_DWORD *)(v6 + 372) = 0;
              *(_DWORD *)(v6 + 376) = 0;
              *(_DWORD *)(v6 + 380) = 0;
              if ( v12 )
              {
                *(_DWORD *)(v6 + 360) = v23;
                *(_DWORD *)(v6 + 364) = v7;
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented((_DWORD *)(v6 + 344), vars4);
              }
              else
              {
                __dmb(0xBu);
                *v9 = 0;
              }
              KfLowerIrql(v10);
            }
            v13 = 0;
            if ( *(_DWORD *)(v6 + 388) )
            {
              do
              {
                v14 = *(_DWORD *)(*(_DWORD *)(v6 + 392) + 4 * v13) + 144;
                v15 = KfRaiseIrql(2);
                if ( (dword_682604 & 0x210000) != 0 )
                {
                  KiAcquireSpinLockInstrumented(v14);
                }
                else
                {
                  do
                    v16 = __ldrex((unsigned int *)v14);
                  while ( __strex(1u, (unsigned int *)v14) );
                  __dmb(0xBu);
                  if ( v16 )
                    KxWaitForSpinLockAndAcquire((unsigned int *)v14);
                }
                v17 = *(unsigned __int8 *)(v14 + 4);
                *(_DWORD *)(v14 + 24) = 0;
                *(_DWORD *)(v14 + 28) = 0;
                *(_DWORD *)(v14 + 32) = 0;
                *(_DWORD *)(v14 + 36) = 0;
                if ( v17 )
                {
                  *(_DWORD *)(v14 + 16) = v23;
                  *(_DWORD *)(v14 + 20) = v22;
                }
                if ( (dword_682604 & 0x10000) != 0 )
                {
                  KiReleaseSpinLockInstrumented((_DWORD *)v14, vars4);
                }
                else
                {
                  __dmb(0xBu);
                  *(_DWORD *)v14 = 0;
                }
                KfLowerIrql(v15);
                ++v13;
              }
              while ( v13 < *(_DWORD *)(v6 + 388) );
              v7 = v22;
            }
          }
          v6 = *(_DWORD *)v6;
        }
        while ( (int *)v6 != &PopFxDeviceList );
      }
      __dmb(0xBu);
      do
        v18 = __ldrex((unsigned int *)&PopFxDeviceListLock);
      while ( v18 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
      if ( v18 != 17 )
        ExfReleasePushLockShared(&PopFxDeviceListLock);
      v19 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
      v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v21 = (__int16)(*(_WORD *)(v20 + 0x134) + 1);
      *(_WORD *)(v20 + 308) = v21;
      if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
        KiCheckForKernelApcDelivery(v19);
    }
  }
}
