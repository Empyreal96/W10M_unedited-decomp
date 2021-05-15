// PopFxDeviceAccountingWatchdog 
 
int __fastcall PopFxDeviceAccountingWatchdog(int result, unsigned int a2, int *a3, _DWORD *a4)
{
  int v4; // r4
  unsigned int v5; // r5
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r5
  int v9; // r1
  int v10; // r5
  int v11; // r3
  unsigned int *v12; // r4
  int v13; // r6
  unsigned int v14; // r2
  char v15; // r3
  int v16; // r6
  int v17; // r4
  int v18; // r8
  unsigned int v19; // r2
  char v20; // r3
  int v21; // r0
  unsigned int v22; // r2
  unsigned int v23; // r1
  __int16 v24; // r3
  __int64 v25; // [sp+0h] [bp-38h]
  int v27; // [sp+Ch] [bp-2Ch]
  int vars4; // [sp+3Ch] [bp+4h]

  v27 = result;
  v4 = PopFxDeviceAccountingLevel;
  __dmb(0xBu);
  if ( v4 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v5 + 308);
    v6 = KeAbPreAcquire((unsigned int)&PopFxDeviceListLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( !v8 && __strex(0x11u, (unsigned int *)&PopFxDeviceListLock) );
    __dmb(0xBu);
    if ( v8 )
      ExfAcquirePushLockSharedEx(&PopFxDeviceListLock, v6, (unsigned int)&PopFxDeviceListLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    LODWORD(v25) = KeQueryInterruptTime();
    HIDWORD(v25) = v9;
    v10 = PopFxDeviceList;
    if ( (int *)PopFxDeviceList != &PopFxDeviceList )
    {
      while ( 1 )
      {
        if ( *(_DWORD *)(v10 + 28) )
        {
          v11 = PopFxDeviceAccountingLevel;
          __dmb(0xBu);
          if ( v11 < 0 )
          {
            v12 = (unsigned int *)(v10 + 344);
            v13 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(v10 + 344);
            }
            else
            {
              do
                v14 = __ldrex(v12);
              while ( __strex(1u, v12) );
              __dmb(0xBu);
              if ( v14 )
                KxWaitForSpinLockAndAcquire((unsigned int *)(v10 + 344));
            }
            v15 = PopFxDeviceAccountingLevel;
            __dmb(0xBu);
            if ( ((v15 & 1) != 0 || !PopFxDeviceAccountingPaused)
              && *(_BYTE *)(v10 + 348)
              && v25 - *(_QWORD *)(v10 + 360) >= __PAIR64__(a2, v27) )
            {
              *a3 = v10;
              *a4 = -1;
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented((_DWORD *)(v10 + 344), vars4);
              }
              else
              {
                __dmb(0xBu);
                *v12 = 0;
              }
              v21 = v13;
              goto LABEL_49;
            }
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented((_DWORD *)(v10 + 344), vars4);
            }
            else
            {
              __dmb(0xBu);
              *v12 = 0;
            }
            KfLowerIrql(v13);
          }
          v16 = 0;
          if ( *(_DWORD *)(v10 + 388) )
            break;
        }
LABEL_39:
        v10 = *(_DWORD *)v10;
        if ( (int *)v10 == &PopFxDeviceList )
          goto LABEL_50;
      }
      while ( 1 )
      {
        v17 = *(_DWORD *)(*(_DWORD *)(v10 + 392) + 4 * v16) + 144;
        v18 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireSpinLockInstrumented(v17);
        }
        else
        {
          do
            v19 = __ldrex((unsigned int *)v17);
          while ( __strex(1u, (unsigned int *)v17) );
          __dmb(0xBu);
          if ( v19 )
            KxWaitForSpinLockAndAcquire((unsigned int *)v17);
        }
        v20 = PopFxDeviceAccountingLevel;
        __dmb(0xBu);
        if ( ((v20 & 1) != 0 || !PopFxDeviceAccountingPaused)
          && *(_BYTE *)(v17 + 4)
          && v25 - *(_QWORD *)(v17 + 16) >= __PAIR64__(a2, v27) )
        {
          break;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented((_DWORD *)v17, vars4);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v17 = 0;
        }
        KfLowerIrql(v18);
        if ( (unsigned int)++v16 >= *(_DWORD *)(v10 + 388) )
          goto LABEL_39;
      }
      *a3 = v10;
      *a4 = v16;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented((_DWORD *)v17, vars4);
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v17 = 0;
      }
      v21 = v18;
LABEL_49:
      KfLowerIrql(v21);
    }
LABEL_50:
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&PopFxDeviceListLock);
    while ( v22 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
    if ( v22 != 17 )
      ExfReleasePushLockShared(&PopFxDeviceListLock);
    result = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
