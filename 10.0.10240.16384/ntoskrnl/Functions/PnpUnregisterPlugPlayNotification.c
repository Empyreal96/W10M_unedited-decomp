// PnpUnregisterPlugPlayNotification 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PnpUnregisterPlugPlayNotification(int a1, int a2)
{
  unsigned int v2; // r4
  int v3; // r8
  int v5; // r9
  int v6; // r5
  int v7; // r0
  unsigned __int8 v8; // r6
  unsigned int v9; // r2
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r3
  int v17; // r5
  int v18; // r6
  unsigned int v19; // r2
  int v20; // r5
  unsigned int v21; // r1
  int v22; // r5
  int v23; // r8
  unsigned int v24; // r2
  void **v25; // r5
  void **v26; // r8
  int v27; // r9
  int v28; // r1
  unsigned int v29; // r2
  int v30; // r1 OVERLAPPED
  void ***v31; // r2 OVERLAPPED
  int v32; // r9
  unsigned int v33; // r1
  unsigned int v34; // r1
  int v35; // r5
  int v36; // r6
  unsigned int v37; // r2
  int v38; // r0
  unsigned int v39; // r1
  int v40; // r3
  int v41; // [sp+0h] [bp-28h]
  int v42; // [sp+4h] [bp-24h]

  v2 = *(_DWORD *)(a1 + 36);
  v3 = a2;
  v5 = 0;
  v41 = 0;
  v6 = KeAbPreAcquire((unsigned int)&PnpNotificationInProgressLock, 0, 0);
  v7 = KfRaiseIrql(1);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)&PnpNotificationInProgressLock);
  while ( __strex(v9 & 0xFE, (unsigned __int8 *)&PnpNotificationInProgressLock) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    return sub_552200();
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_62FB04 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_62FB1C = v7;
  if ( PnpNotificationInProgress )
  {
    v22 = KeAbPreAcquire((unsigned int)&PnpDeferredRegistrationLock, 0, 0);
    v23 = KfRaiseIrql(1);
    do
      v24 = __ldrex((unsigned __int8 *)&PnpDeferredRegistrationLock);
    while ( __strex(v24 & 0xFE, (unsigned __int8 *)&PnpDeferredRegistrationLock) );
    __dmb(0xBu);
    if ( (v24 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&PnpDeferredRegistrationLock, v22);
    if ( v22 )
      *(_BYTE *)(v22 + 14) |= 1u;
    dword_630D64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_630D7C = v23;
    v25 = (void **)PnpDeferredRegistrationList;
    if ( PnpDeferredRegistrationList != &PnpDeferredRegistrationList )
    {
      do
      {
        v26 = v25;
        if ( v25[2] == (void *)a1 )
        {
          v41 = 1;
          if ( v2 )
          {
            v27 = KeAbPreAcquire(v2, 0, 0);
            v28 = KfRaiseIrql(1);
            v42 = v28;
            do
              v29 = __ldrex((unsigned __int8 *)v2);
            while ( __strex(v29 & 0xFE, (unsigned __int8 *)v2) );
            __dmb(0xBu);
            if ( (v29 & 1) == 0 )
            {
              ExpAcquireFastMutexContended(v2, v27);
              v28 = v42;
            }
            if ( v27 )
              *(_BYTE *)(v27 + 14) |= 1u;
            *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            *(_DWORD *)(v2 + 28) = v28;
          }
          *(_QWORD *)&v30 = *(_QWORD *)v25;
          v25 = (void **)*v25;
          if ( *((void ***)*v26 + 1) != v26 || *v31 != v26 )
            __fastfail(3u);
          *v31 = (void **)v30;
          *(_DWORD *)(v30 + 4) = v31;
          PnpDereferenceNotify(v26[2]);
          if ( v2 )
          {
            v32 = *(_DWORD *)(v2 + 28);
            *(_DWORD *)(v2 + 4) = 0;
            __dmb(0xBu);
            do
              v33 = __ldrex((unsigned int *)v2);
            while ( !v33 && __strex(1u, (unsigned int *)v2) );
            if ( v33 )
              ExpReleaseFastMutexContended((unsigned int *)v2, v33);
            KfLowerIrql((unsigned __int8)v32);
            KeAbPostRelease(v2);
          }
          ExFreePoolWithTag(v26, 930115152);
        }
        else
        {
          v25 = (void **)*v25;
        }
      }
      while ( v25 != &PnpDeferredRegistrationList );
      v5 = v41;
      LOBYTE(v23) = dword_630D7C;
    }
    dword_630D64 = 0;
    __dmb(0xBu);
    do
      v34 = __ldrex((unsigned int *)&PnpDeferredRegistrationLock);
    while ( !v34 && __strex(1u, (unsigned int *)&PnpDeferredRegistrationLock) );
    if ( v34 )
      ExpReleaseFastMutexContended((unsigned int *)&PnpDeferredRegistrationLock, v34);
    KfLowerIrql((unsigned __int8)v23);
    KeAbPostRelease((unsigned int)&PnpDeferredRegistrationLock);
    v3 = a2;
    v8 = dword_62FB1C;
  }
  dword_62FB04 = 0;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)&PnpNotificationInProgressLock);
  while ( !v11 && __strex(1u, (unsigned int *)&PnpNotificationInProgressLock) );
  if ( v11 )
    ExpReleaseFastMutexContended((unsigned int *)&PnpNotificationInProgressLock, v11);
  KfLowerIrql(v8);
  KeAbPostRelease((unsigned int)&PnpNotificationInProgressLock);
  if ( v3 )
  {
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(__int16 *)(v12 + 0x134) - 1;
    *(_WORD *)(v12 + 308) = v13;
    ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 40), 1, v12, v13);
  }
  else if ( v2 )
  {
    v35 = KeAbPreAcquire(v2, 0, 0);
    v36 = KfRaiseIrql(1);
    do
      v37 = __ldrex((unsigned __int8 *)v2);
    while ( __strex(v37 & 0xFE, (unsigned __int8 *)v2) );
    __dmb(0xBu);
    if ( (v37 & 1) == 0 )
      ExpAcquireFastMutexContended(v2, v35);
    if ( v35 )
      *(_BYTE *)(v35 + 14) |= 1u;
    *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v2 + 28) = v36;
  }
  if ( !*(_BYTE *)(a1 + 34) || v5 )
  {
    *(_BYTE *)(a1 + 34) = 1;
    if ( v3 )
    {
      v14 = ExpReleaseResourceForThreadLite(*(_DWORD *)(a1 + 40), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v16 = (__int16)(*(_WORD *)(v15 + 0x134) + 1);
      *(_WORD *)(v15 + 308) = v16;
      if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
        KiCheckForKernelApcDelivery(v14);
      if ( v2 )
      {
        v17 = KeAbPreAcquire(v2, 0, 0);
        v18 = KfRaiseIrql(1);
        do
          v19 = __ldrex((unsigned __int8 *)v2);
        while ( __strex(v19 & 0xFE, (unsigned __int8 *)v2) );
        __dmb(0xBu);
        if ( (v19 & 1) == 0 )
          ExpAcquireFastMutexContended(v2, v17);
        if ( v17 )
          *(_BYTE *)(v17 + 14) |= 1u;
        *(_DWORD *)(v2 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        *(_DWORD *)(v2 + 28) = v18;
      }
    }
    PnpDereferenceNotify(a1);
    if ( !v2 )
      return 0;
    v20 = *(_DWORD *)(v2 + 28);
    *(_DWORD *)(v2 + 4) = 0;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v2);
    while ( !v21 && __strex(1u, (unsigned int *)v2) );
    goto LABEL_30;
  }
  if ( v3 )
  {
    v38 = ExpReleaseResourceForThreadLite(*(_DWORD *)(a1 + 40), __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v39 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v40 = (__int16)(*(_WORD *)(v39 + 0x134) + 1);
    *(_WORD *)(v39 + 308) = v40;
    if ( !v40 && *(_DWORD *)(v39 + 100) != v39 + 100 && !*(_WORD *)(v39 + 310) )
      KiCheckForKernelApcDelivery(v38);
    return 0;
  }
  if ( v2 )
  {
    v20 = *(_DWORD *)(v2 + 28);
    *(_DWORD *)(v2 + 4) = 0;
    __dmb(0xBu);
    do
      v21 = __ldrex((unsigned int *)v2);
    while ( !v21 && __strex(1u, (unsigned int *)v2) );
LABEL_30:
    if ( v21 )
      ExpReleaseFastMutexContended((unsigned int *)v2, v21);
    KfLowerIrql((unsigned __int8)v20);
    KeAbPostRelease(v2);
  }
  return 0;
}
