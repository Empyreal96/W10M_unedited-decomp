// PopPepIdleTimeoutRoutine 
 
int PopPepIdleTimeoutRoutine()
{
  int v0; // r0
  unsigned int v1; // r1
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int i; // r4
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  unsigned int *v11; // r6
  int v12; // r9
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  int v16; // r0
  int v17; // r10
  unsigned int v18; // r1
  unsigned int v19; // r9
  int v20; // r5
  int v22; // r0
  __int64 v23; // kr00_8
  unsigned __int64 v24; // r2
  int v25; // r0
  unsigned int v26; // r1
  unsigned int v27; // [sp+0h] [bp-28h]
  int v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]

  v0 = KeQueryInterruptTime();
  v27 = v1;
  v28 = v0;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&PopPepDeviceListLock, 0, 0);
  do
    v4 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( !v4 && __strex(0x11u, (unsigned int *)&PopPepDeviceListLock) );
  __dmb(0xBu);
  if ( v4 )
    return sub_54B534(v3, 17);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  for ( i = PopPepDeviceList; (int *)i != &PopPepDeviceList; i = *(_DWORD *)i )
  {
    if ( (*(_DWORD *)(i + 8) & 1) == 0 )
    {
      v11 = (unsigned int *)(i + 44);
      v12 = KfRaiseIrql(2);
      v29 = v12;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(i + 44);
      }
      else
      {
        v13 = (unsigned __int8 *)(i + 47);
        do
          v14 = __ldrex(v13);
        while ( __strex(v14 | 0x80, v13) );
        __dmb(0xBu);
        if ( v14 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(i + 44));
        while ( 1 )
        {
          v15 = *v11;
          if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v15 & 0x40000000) == 0 )
          {
            do
              v26 = __ldrex(v11);
            while ( v26 == v15 && __strex(v15 | 0x40000000, v11) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( *(_BYTE *)(i + 88) )
      {
        v17 = PopPepCountReadyActivities(i, 0, 3);
        v19 = v18;
        if ( *(_DWORD *)(i + 120) )
        {
          v20 = i + 128;
          do
          {
            if ( *(_DWORD *)(v20 + 144) != *(_DWORD *)(v20 + 156) - 1
              && !**(_DWORD **)(v20 + 56)
              && !**(_DWORD **)(v20 + 60) )
            {
              v23 = *(_QWORD *)(v20 + 104);
              if ( __SPAIR64__(v27, v28) > v23 )
              {
                v24 = __PAIR64__(v27, v28) - v23;
                if ( __PAIR64__(v27, v28) - v23 > *(_QWORD *)(v20 + 88) )
                {
                  *(_QWORD *)(v20 + 88) = v24;
                  v25 = PopPepComponentGetResidencyIdleState(v20, v24);
                  if ( *(_DWORD *)(v20 + 128) != v25 )
                  {
                    *(_DWORD *)(v20 + 128) = v25;
                    PopPepUpdateIdleState(i, (_DWORD *)v20, 1);
                  }
                }
              }
            }
            ++v19;
            v20 += 168;
          }
          while ( v19 < *(_DWORD *)(i + 120) );
        }
        PopPepPromoteActivities(i, 0, 3);
        v22 = PopPepCountReadyActivities(i, 0, 3);
        PopPepRequestWork(v17, v22);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(i + 44);
        }
        else
        {
          __dmb(0xBu);
          *v11 = 0;
        }
        v16 = v29;
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(i + 44);
        }
        else
        {
          __dmb(0xBu);
          *v11 = 0;
        }
        v16 = v12;
      }
      KfLowerIrql(v16);
    }
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopPepDeviceListLock);
  while ( v7 == 17 && __strex(0, (unsigned int *)&PopPepDeviceListLock) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(&PopPepDeviceListLock);
  v8 = KeAbPostRelease((unsigned int)&PopPepDeviceListLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return PopPepArmIdleTimer(1);
}
