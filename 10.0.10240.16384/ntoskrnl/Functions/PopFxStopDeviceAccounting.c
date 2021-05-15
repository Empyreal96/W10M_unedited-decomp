// PopFxStopDeviceAccounting 
 
void PopFxStopDeviceAccounting()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r2
  __int64 v4; // r0
  int i; // r6
  int v6; // r3
  unsigned int *v7; // r4
  int v8; // r8
  unsigned int v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r7
  char v12; // r3
  unsigned __int64 v13; // kr08_8
  int v14; // r1
  unsigned int v15; // r8
  int v16; // r5
  unsigned int *v17; // r4
  unsigned int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r7
  char v21; // r3
  unsigned __int64 v22; // kr18_8
  unsigned int v23; // r2
  int v24; // r0
  unsigned int v25; // r1
  int v26; // r3
  unsigned __int64 v27; // kr20_8
  unsigned __int64 v28; // kr28_8
  unsigned int v29; // [sp+0h] [bp-30h]
  int v30; // [sp+4h] [bp-2Ch]
  int v31; // [sp+4h] [bp-2Ch]
  unsigned int v32; // [sp+8h] [bp-28h]
  int v33; // [sp+10h] [bp-20h]

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
      sub_50F564(v2, 17);
    }
    else
    {
      if ( v2 )
        *(_BYTE *)(v2 + 14) |= 1u;
      v4 = KeQueryInterruptTime();
      v32 = HIDWORD(v4);
      v29 = v4;
      for ( i = PopFxDeviceList; (int *)i != &PopFxDeviceList; i = *(_DWORD *)i )
      {
        v30 = *(_DWORD *)(i + 28);
        if ( v30 )
        {
          v6 = PopFxDeviceAccountingLevel;
          __dmb(0xBu);
          if ( v6 < 0 )
          {
            v7 = (unsigned int *)(i + 344);
            v8 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(i + 344);
            }
            else
            {
              do
                v9 = __ldrex(v7);
              while ( __strex(1u, v7) );
              __dmb(0xBu);
              if ( v9 )
                KxWaitForSpinLockAndAcquire(i + 344);
            }
            v11 = *(_DWORD *)(i + 380);
            v10 = *(_DWORD *)(i + 376);
            v12 = PopFxDeviceAccountingLevel;
            __dmb(0xBu);
            if ( (v12 & 1) != 0 )
            {
              v13 = *(_QWORD *)(i + 360);
              if ( *(_BYTE *)(i + 348) && __PAIR64__(v32, v29) > v13 )
              {
                v27 = __PAIR64__(v11, v10) - v13 + __PAIR64__(v32, v29);
                v11 = HIDWORD(v27);
                v10 = v27;
              }
              *(_DWORD *)(i + 368) = v10;
              *(_DWORD *)(i + 372) = v11;
            }
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(i + 344);
            }
            else
            {
              __dmb(0xBu);
              *v7 = 0;
            }
            KfLowerIrql(v8);
            PopDiagTraceFxDeviceAccounting(v30, v14, *(_DWORD *)(i + 368), *(_DWORD *)(i + 372));
          }
          v15 = 0;
          if ( *(_DWORD *)(i + 388) )
          {
            v16 = v30;
            do
            {
              v33 = *(_DWORD *)(*(_DWORD *)(i + 392) + 4 * v15);
              v17 = (unsigned int *)(v33 + 144);
              v31 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented(v17);
              }
              else
              {
                do
                  v18 = __ldrex(v17);
                while ( __strex(1u, v17) );
                __dmb(0xBu);
                if ( v18 )
                  KxWaitForSpinLockAndAcquire(v17);
              }
              v20 = *(_DWORD *)(v33 + 180);
              v19 = *(_DWORD *)(v33 + 176);
              v21 = PopFxDeviceAccountingLevel;
              __dmb(0xBu);
              if ( (v21 & 1) != 0 )
              {
                v22 = *(_QWORD *)(v33 + 160);
                if ( *(_BYTE *)(v33 + 148) && __PAIR64__(v32, v29) > v22 )
                {
                  v28 = __PAIR64__(v20, v19) - v22 + __PAIR64__(v32, v29);
                  v20 = HIDWORD(v28);
                  v19 = v28;
                }
                *(_DWORD *)(v33 + 168) = v19;
                *(_DWORD *)(v33 + 172) = v20;
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented(v17);
              }
              else
              {
                __dmb(0xBu);
                *v17 = 0;
              }
              KfLowerIrql(v31);
              PopDiagTraceFxComponentAccounting(
                v16,
                *(_DWORD *)(v33 + 16),
                *(_DWORD *)(v33 + 168),
                *(_DWORD *)(v33 + 172));
              ++v15;
            }
            while ( v15 < *(_DWORD *)(i + 388) );
          }
        }
      }
      __dmb(0xBu);
      do
        v23 = __ldrex((unsigned int *)&PopFxDeviceListLock);
      while ( v23 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
      if ( v23 != 17 )
        ExfReleasePushLockShared(&PopFxDeviceListLock, 0);
      v24 = KeAbPostRelease(&PopFxDeviceListLock);
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = (__int16)(*(_WORD *)(v25 + 0x134) + 1);
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery(v24);
    }
  }
}
