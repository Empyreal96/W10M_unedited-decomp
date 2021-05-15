// PopFxStopDeviceAccounting 
 
void PopFxStopDeviceAccounting()
{
  int v0; // r3
  unsigned int v1; // r2
  int v2; // r0
  unsigned int v3; // r2
  int v4; // r0
  unsigned int v5; // r1
  int i; // r6
  int v7; // r3
  unsigned int *v8; // r4
  int v9; // r8
  unsigned int v10; // r2
  unsigned int v11; // r0
  unsigned int v12; // r7
  char v13; // r3
  unsigned __int64 v14; // kr08_8
  __int64 v15; // r0
  unsigned int v16; // r8
  int v17; // r5
  unsigned int *v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r0
  unsigned int v21; // r7
  char v22; // r3
  unsigned __int64 v23; // kr18_8
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  int v27; // r3
  unsigned __int64 v28; // kr20_8
  unsigned __int64 v29; // kr28_8
  int v30; // [sp+0h] [bp-30h]
  int v31; // [sp+4h] [bp-2Ch]
  int v32; // [sp+4h] [bp-2Ch]
  unsigned int v33; // [sp+8h] [bp-28h]
  int v34; // [sp+10h] [bp-20h]
  int vars4; // [sp+34h] [bp+4h]

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
      sub_50F564();
    }
    else
    {
      if ( v2 )
        *(_BYTE *)(v2 + 14) |= 1u;
      v4 = KeQueryInterruptTime();
      v33 = v5;
      v30 = v4;
      for ( i = PopFxDeviceList; (int *)i != &PopFxDeviceList; i = *(_DWORD *)i )
      {
        v31 = *(_DWORD *)(i + 28);
        if ( v31 )
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
            v12 = *(_DWORD *)(i + 380);
            v11 = *(_DWORD *)(i + 376);
            v13 = PopFxDeviceAccountingLevel;
            __dmb(0xBu);
            if ( (v13 & 1) != 0 )
            {
              v14 = *(_QWORD *)(i + 360);
              if ( *(_BYTE *)(i + 348) && __PAIR64__(v33, v30) > v14 )
              {
                v28 = __PAIR64__(v12, v11) - v14 + __PAIR64__(v33, v30);
                v12 = HIDWORD(v28);
                v11 = v28;
              }
              *(_DWORD *)(i + 368) = v11;
              *(_DWORD *)(i + 372) = v12;
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
            v15 = KfLowerIrql(v9);
            PopDiagTraceFxDeviceAccounting(v31, SHIDWORD(v15), *(_DWORD *)(i + 368), *(_DWORD *)(i + 372));
          }
          v16 = 0;
          if ( *(_DWORD *)(i + 388) )
          {
            v17 = v31;
            do
            {
              v34 = *(_DWORD *)(*(_DWORD *)(i + 392) + 4 * v16);
              v18 = (unsigned int *)(v34 + 144);
              v32 = KfRaiseIrql(2);
              if ( (dword_682604 & 0x210000) != 0 )
              {
                KiAcquireSpinLockInstrumented((int)v18);
              }
              else
              {
                do
                  v19 = __ldrex(v18);
                while ( __strex(1u, v18) );
                __dmb(0xBu);
                if ( v19 )
                  KxWaitForSpinLockAndAcquire(v18);
              }
              v21 = *(_DWORD *)(v34 + 180);
              v20 = *(_DWORD *)(v34 + 176);
              v22 = PopFxDeviceAccountingLevel;
              __dmb(0xBu);
              if ( (v22 & 1) != 0 )
              {
                v23 = *(_QWORD *)(v34 + 160);
                if ( *(_BYTE *)(v34 + 148) && __PAIR64__(v33, v30) > v23 )
                {
                  v29 = __PAIR64__(v21, v20) - v23 + __PAIR64__(v33, v30);
                  v21 = HIDWORD(v29);
                  v20 = v29;
                }
                *(_DWORD *)(v34 + 168) = v20;
                *(_DWORD *)(v34 + 172) = v21;
              }
              if ( (dword_682604 & 0x10000) != 0 )
              {
                KiReleaseSpinLockInstrumented(v18, vars4);
              }
              else
              {
                __dmb(0xBu);
                *v18 = 0;
              }
              KfLowerIrql(v32);
              PopDiagTraceFxComponentAccounting(
                v17,
                *(_DWORD *)(v34 + 16),
                *(_DWORD *)(v34 + 168),
                *(_DWORD *)(v34 + 172));
              ++v16;
            }
            while ( v16 < *(_DWORD *)(i + 388) );
          }
        }
      }
      __dmb(0xBu);
      do
        v24 = __ldrex((unsigned int *)&PopFxDeviceListLock);
      while ( v24 == 17 && __strex(0, (unsigned int *)&PopFxDeviceListLock) );
      if ( v24 != 17 )
        ExfReleasePushLockShared(&PopFxDeviceListLock);
      v25 = KeAbPostRelease((unsigned int)&PopFxDeviceListLock);
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = (__int16)(*(_WORD *)(v26 + 0x134) + 1);
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
    }
  }
}
