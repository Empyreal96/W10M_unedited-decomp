// PopIrpWorker 
 
int __fastcall PopIrpWorker(_DWORD *a1)
{
  int *v3; // r7
  char v4; // r3
  int v5; // r5
  int v6; // r6
  unsigned int v7; // r2
  unsigned __int8 v8; // r5
  unsigned int v9; // r1
  int v10; // r6
  __int64 v11; // r2
  int v12; // r5
  int v13; // r7
  unsigned int v14; // r2
  int v15; // r2
  unsigned int v16; // r1
  int v17; // r9
  int v18; // r3
  int v19; // r8
  int v20; // r0
  int v21; // r3
  int v22; // r6
  int v23; // r2
  int v24; // r5
  unsigned int *v25; // r7
  unsigned int v26; // r1
  int v27; // r2
  BOOL v28; // r3
  int v29; // r5
  int v30; // r6
  int v31; // r5
  int v32; // r6
  unsigned int v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r1
  int v36; // r5
  int v37; // r7
  unsigned int v38; // r2
  int v39; // r6
  BOOL v40; // r5
  int v41; // r0
  int v42; // r1
  unsigned int v43; // r1
  int v44; // [sp+8h] [bp-58h]
  int *v45; // [sp+Ch] [bp-54h]
  int v46[2]; // [sp+10h] [bp-50h] BYREF
  char v47[16]; // [sp+18h] [bp-48h] BYREF
  _DWORD v48[14]; // [sp+28h] [bp-38h] BYREF

  v44 = 0;
  memset(v48, 0, 24);
  v48[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( a1 )
  {
    if ( *a1 )
      return sub_54B01C();
    ExFreeToNPagedLookasideList(&PopDynamicIrpWorkerLookaside, a1);
    v3 = v46;
    v46[0] = -100000000;
    v46[1] = -1;
    v4 = 0;
  }
  else
  {
    v3 = 0;
    v4 = 1;
  }
  LOBYTE(v48[5]) = v4;
  v45 = v3;
  v5 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
  while ( __strex(v7 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopIrpWorkerMutex, v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_61DFC4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --PopIrpWorkerPendingCount;
  dword_61DFDC = v6;
  ++PopIrpWorkerCount;
  v48[0] = &PopIrpThreadList;
  v48[1] = dword_61DFA4;
  if ( *(_UNKNOWN **)dword_61DFA4 != &PopIrpThreadList )
    __fastfail(3u);
  *(_DWORD *)dword_61DFA4 = v48;
  dword_61DFA4 = (int)v48;
  dword_61DFC4 = 0;
  v8 = dword_61DFDC;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
  while ( !v9 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
  if ( v9 )
    ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v9);
  KfLowerIrql(v8);
  KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
  while ( 1 )
  {
    if ( KeWaitForSingleObject((unsigned int)&PopIrpWorkerSemaphore, 0, 0, 0, v3) != 258 )
    {
      KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)v47);
      PopIrpLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10 = PopIrpWorkerList;
      v11 = *(_QWORD *)PopIrpWorkerList;
      if ( *(int **)(PopIrpWorkerList + 4) != &PopIrpWorkerList || *(_DWORD *)(v11 + 4) != PopIrpWorkerList )
        __fastfail(3u);
      PopIrpWorkerList = *(_DWORD *)PopIrpWorkerList;
      *(_DWORD *)(v11 + 4) = &PopIrpWorkerList;
      PopIrpLockThread = 0;
      KeReleaseInStackQueuedSpinLock((int)v47);
      v12 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
      v13 = KfRaiseIrql(1);
      do
        v14 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
      while ( __strex(v14 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
      __dmb(0xBu);
      if ( (v14 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PopIrpWorkerMutex, v12);
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      dword_61DFC4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61DFDC = v13;
      v15 = ++PopIrpWorkerInFlightCount;
      if ( PopCreateIrpWorkerAllowed
        && v15 == PopIrpWorkerCount
        && (unsigned int)PopIrpWorkerCount < 0xF
        && !PopIrpWorkerPendingCount
        && !PopIrpWorkerRequested )
      {
        PopIrpWorkerRequested = 1;
        KeSetEvent((int)&PopIrpWorkerControlEvent, 0, 0);
        LOBYTE(v13) = dword_61DFDC;
      }
      dword_61DFC4 = 0;
      __dmb(0xBu);
      do
        v16 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
      while ( !v16 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
      if ( v16 )
        ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v16);
      KfLowerIrql((unsigned __int8)v13);
      KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
      v17 = v10 - 88;
      v18 = *(_DWORD *)(v10 + 8);
      v19 = *(_DWORD *)(v18 + 24);
      PoDeviceAcquireIrp(v10 - 88, *(unsigned __int8 *)(v18 + 1), v19);
      v20 = *(_DWORD *)(v10 - 88 + 40 * *(char *)(v10 - 54) + 108);
      if ( *(_BYTE *)(v20 + 112) == 2 && *(_DWORD *)(v20 + 116) == 1 && *(_DWORD *)(v20 + 16) == v19 )
      {
        v21 = *(_DWORD *)(v20 + 12);
        v22 = *(_DWORD *)(v20 + 128);
        v23 = v21 ? *(_DWORD *)(*(_DWORD *)(v21 + 176) + 20) : 0;
        v24 = *(_DWORD *)(v23 + 80);
        *(_DWORD *)(v23 + 80) = *(_DWORD *)(v20 + 120);
        if ( v22 )
        {
          __dmb(0xBu);
          v25 = (unsigned int *)(v22 + 16);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26, v25) );
          __dmb(0xBu);
          v27 = *(_DWORD *)(v20 + 120);
          *(_BYTE *)(v20 + 132) = (v26 & 1) != 0;
          v28 = v27 != v24 && ((v26 & 1) == 0 || v27 == 1);
          *(_BYTE *)(v20 + 133) = v28;
          if ( v28 )
          {
            if ( v27 == 1 )
            {
              __dmb(0xBu);
              do
                v35 = __ldrex(v25);
              while ( __strex(v35 | 2, v25) );
              __dmb(0xBu);
            }
            PopPepDeviceDState(*(_DWORD *)(v22 + 32), *(_DWORD *)(v20 + 120), 0, *(unsigned __int8 *)(v20 + 132));
          }
        }
      }
      v48[3] = v17;
      v48[4] = v19;
      v29 = 0;
      if ( (*(_DWORD *)(v19 + 28) & 0x2000) == 0 && v17 == PopInrushIrp )
      {
        v30 = KfRaiseIrql(2);
        v44 = v30;
        v29 = 1;
      }
      else
      {
        v30 = v44;
      }
      (*(void (__fastcall **)(int, int))(*(_DWORD *)(v19 + 8) + 144))(v19, v17);
      if ( v29 )
        KfLowerIrql(v30);
      v48[3] = 0;
      v48[4] = 0;
      ObfDereferenceObjectWithTag(v19);
      v31 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
      v32 = KfRaiseIrql(1);
      do
        v33 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
      while ( __strex(v33 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
      __dmb(0xBu);
      if ( (v33 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&PopIrpWorkerMutex, v31);
      if ( v31 )
        *(_BYTE *)(v31 + 14) |= 1u;
      __mrc(15, 0, 13, 0, 3);
      dword_61DFDC = v32;
      --PopIrpWorkerInFlightCount;
      dword_61DFC4 = 0;
      __dmb(0xBu);
      do
        v34 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
      while ( !v34 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
      if ( v34 )
        ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v34);
      KfLowerIrql((unsigned __int8)v32);
      KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
      goto LABEL_66;
    }
    v36 = KeAbPreAcquire((unsigned int)&PopIrpWorkerMutex, 0, 0);
    v37 = KfRaiseIrql(1);
    do
      v38 = __ldrex((unsigned __int8 *)&PopIrpWorkerMutex);
    while ( __strex(v38 & 0xFE, (unsigned __int8 *)&PopIrpWorkerMutex) );
    __dmb(0xBu);
    if ( (v38 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PopIrpWorkerMutex, v36);
    if ( v36 )
      *(_BYTE *)(v36 + 14) |= 1u;
    dword_61DFC4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v39 = PopIrpWorkerCount;
    dword_61DFDC = v37;
    v40 = !PopCreateIrpWorkerAllowed || PopIrpWorkerInFlightCount == PopIrpWorkerCount - 1 && !PopIrpWorkerPendingCount;
    if ( !v40 )
    {
      v41 = v48[0];
      v42 = v48[1];
      if ( *(_DWORD **)(v48[0] + 4) != v48 || *(_DWORD **)v48[1] != v48 )
        __fastfail(3u);
      *(_DWORD *)v48[1] = v48[0];
      *(_DWORD *)(v41 + 4) = v42;
      PopIrpWorkerCount = v39 - 1;
      LOBYTE(v37) = dword_61DFDC;
    }
    dword_61DFC4 = 0;
    __dmb(0xBu);
    do
      v43 = __ldrex((unsigned int *)&PopIrpWorkerMutex);
    while ( !v43 && __strex(1u, (unsigned int *)&PopIrpWorkerMutex) );
    if ( v43 )
      ExpReleaseFastMutexContended((unsigned int *)&PopIrpWorkerMutex, v43);
    KfLowerIrql((unsigned __int8)v37);
    KeAbPostRelease((unsigned int)&PopIrpWorkerMutex);
    if ( !v40 )
      return PsTerminateSystemThread(0);
LABEL_66:
    v3 = v45;
  }
}
