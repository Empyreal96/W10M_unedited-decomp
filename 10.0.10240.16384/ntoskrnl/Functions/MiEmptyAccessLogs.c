// MiEmptyAccessLogs 
 
int MiEmptyAccessLogs()
{
  int result; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int i; // r6
  unsigned int *v5; // r4
  int v6; // r8
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int j; // r6
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r3
  unsigned int *v15; // r4
  int v16; // r3
  int v17; // r8
  unsigned int v18; // r0
  unsigned int *v19; // r4
  int v20; // r6
  int v21; // r4
  unsigned __int8 *v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r1
  unsigned __int8 *v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r1
  _BYTE v30[16]; // [sp-4h] [bp-48h] BYREF
  char v31[56]; // [sp+Ch] [bp-38h] BYREF

  __mrc(15, 0, 13, 0, 3);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634500, (unsigned int)v30);
  if ( dword_634484 )
  {
    dword_634494 = 0;
    result = KeReleaseInStackQueuedSpinLock((int)v30);
  }
  else
  {
    do
    {
      dword_634494 = 2;
      KeReleaseInStackQueuedSpinLock((int)v30);
      for ( i = PsGetNextProcess(0); i; i = PsGetNextProcess(i) )
      {
        v5 = (unsigned int *)(i + 492);
        if ( *(_DWORD *)(i + 500) )
        {
          KiStackAttachProcess(i, 0, (int)v31);
          if ( *(_DWORD *)(i + 500) )
          {
            v6 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(i + 492));
            }
            else
            {
              v22 = (unsigned __int8 *)(i + 495);
              do
                v23 = __ldrex(v22);
              while ( __strex(v23 | 0x80, v22) );
              __dmb(0xBu);
              if ( v23 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(i + 492));
              while ( 1 )
              {
                v24 = *v5;
                if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (v24 & 0x40000000) == 0 )
                {
                  do
                    v25 = __ldrex(v5);
                  while ( v25 == v24 && __strex(v24 | 0x40000000, v5) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
            }
            v7 = *(_DWORD *)(i + 500);
            if ( v7 )
            {
              MiEmptyPageAccessLog(v7);
              *(_DWORD *)(i + 500) = 0;
            }
            MiUnlockWorkingSetExclusive(i + 492, v6);
          }
          KiUnstackDetachProcess((unsigned int)v31, 0);
        }
      }
      for ( j = MiGetNextSession(0, v1, v2, v3); j; j = MiGetNextSession(j, v11, v12, v13) )
      {
        if ( MmAttachSession(j, (int)v31, v8, v9) >= 0 )
        {
          v14 = __mrc(15, 0, 13, 0, 3);
          v15 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((v14 & 0xFFFFFFC0) + 0x74) + 324) + 3248);
          v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)((v14 & 0xFFFFFFC0) + 0x74) + 324) + 3256);
          if ( v16 )
          {
            v17 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v15);
            }
            else
            {
              v26 = (unsigned __int8 *)v15 + 3;
              do
                v27 = __ldrex(v26);
              while ( __strex(v27 | 0x80, v26) );
              __dmb(0xBu);
              if ( v27 >> 7 )
                ExpWaitForSpinLockExclusiveAndAcquire(v15);
              while ( 1 )
              {
                v28 = *v15;
                if ( (*v15 & 0xBFFFFFFF) == 0x80000000 )
                  break;
                if ( (v28 & 0x40000000) == 0 )
                {
                  do
                    v29 = __ldrex(v15);
                  while ( v29 == v28 && __strex(v28 | 0x40000000, v15) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
            }
            v18 = v15[2];
            if ( v18 )
            {
              MiEmptyPageAccessLog(v18);
              v15[2] = 0;
            }
            MiUnlockWorkingSetExclusive((int)v15, v17);
          }
          MmDetachSession(j, (int)v31, v12, v16);
        }
      }
      v19 = dword_634E00;
      v20 = 3;
      do
      {
        MiDrainSystemAccessLog((int)v19);
        v19 += 32;
        --v20;
      }
      while ( v20 );
      v21 = 0;
      MiCheckAndProcessCcAccessLog(0, 0, 1);
      KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634500, (unsigned int)v30);
    }
    while ( dword_634494 != 2 );
    if ( !dword_634484 )
    {
      v21 = dword_6346A0;
      dword_6346A0 = 0;
    }
    dword_634494 = 0;
    result = KeReleaseInStackQueuedSpinLock((int)v30);
    if ( v21 )
      result = ExFreePoolWithTag(v21);
  }
  return result;
}
