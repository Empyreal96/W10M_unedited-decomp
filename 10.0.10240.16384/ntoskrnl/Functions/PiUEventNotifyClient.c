// PiUEventNotifyClient 
 
int __fastcall PiUEventNotifyClient(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v5; // r7
  int v7; // r6
  int v8; // r8
  int v9; // r4
  int v10; // r0
  unsigned int v11; // r2
  unsigned int *v13; // r4
  unsigned int v14; // r7
  unsigned int v15; // r1
  int v16; // r7
  unsigned int v17; // r6
  int v18; // r4
  int v19; // r8
  unsigned int v20; // r2
  unsigned int *v21; // r4
  unsigned int v22; // r7
  unsigned int v23; // r1
  int v24; // r4
  int v25; // r0
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v28; // kr00_4
  unsigned int v29; // r1
  int v30; // r3
  unsigned int *v31; // r4
  unsigned int v32; // r5
  unsigned int v33; // r1
  unsigned __int64 v34; // [sp+0h] [bp-28h] BYREF
  int v35; // [sp+8h] [bp-20h]

  v34 = __PAIR64__(a3, a2);
  v35 = a4;
  v5 = *(_DWORD *)(a2 + 8);
  v7 = 0;
  v8 = 0;
  v9 = KeAbPreAcquire(v5, 0, 0);
  v10 = KfRaiseIrql(1);
  do
    v11 = __ldrex((unsigned __int8 *)v5);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)v5) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
    return sub_7E8D40(v10);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_DWORD *)(v5 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)(v5 + 28) = v10;
  if ( !*(_BYTE *)(a2 + 84) )
    goto LABEL_34;
  if ( *(_DWORD *)(a2 + 72) )
  {
    v24 = *(_DWORD *)(a2 + 64);
    KeQuerySystemTime(&v34);
    v25 = _rt_sdiv64(10000i64, v34 - *(_QWORD *)(v24 + 8));
    v26 = *(_DWORD *)(a2 + 72);
    v28 = v25;
    v27 = v25 * v26;
    v30 = (__PAIR64__(v29, v28) * v26) >> 32;
    if ( v30 >= 0 && (v30 > 0 || v27 > 0x927C0) )
    {
      ++*(_DWORD *)(a2 + 80);
LABEL_34:
      v8 = 1;
      goto LABEL_9;
    }
  }
LABEL_9:
  v13 = *(unsigned int **)(a2 + 8);
  v14 = v13[7];
  v13[1] = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex(v13);
  while ( !v15 && __strex(1u, v13) );
  if ( v15 )
    ExpReleaseFastMutexContended(v13, v15);
  KfLowerIrql((unsigned __int8)v14);
  KeAbPostRelease((unsigned int)v13);
  if ( !v8 )
  {
    v16 = ExAllocatePoolWithTag(1, 24, 1500540496);
    if ( v16 )
    {
      PiUEventReferenceEventEntry(a1);
      *(_DWORD *)(v16 + 16) = a1;
      v17 = *(_DWORD *)(a2 + 8);
      v18 = KeAbPreAcquire(v17, 0, 0);
      v19 = KfRaiseIrql(1);
      do
        v20 = __ldrex((unsigned __int8 *)v17);
      while ( __strex(v20 & 0xFE, (unsigned __int8 *)v17) );
      __dmb(0xBu);
      if ( (v20 & 1) == 0 )
        ExpAcquireFastMutexContended(v17, v18);
      if ( v18 )
        *(_BYTE *)(v18 + 14) |= 1u;
      *(_DWORD *)(v17 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      *(_DWORD *)(v17 + 28) = v19;
      v7 = PiUEventQueuePendingEvent(a2, v16);
      if ( v7 >= 0
        || (PiUEventDequeuePendingEventWorker(a2, *(_DWORD **)(a2 + 64)),
            ++*(_DWORD *)(a2 + 80),
            v7 = PiUEventQueuePendingEvent(a2, v16),
            v7 >= 0) )
      {
        KeQuerySystemTime((_DWORD *)(v16 + 8));
        v21 = *(unsigned int **)(a2 + 8);
        v22 = v21[7];
        v21[1] = 0;
        __dmb(0xBu);
        do
          v23 = __ldrex(v21);
        while ( !v23 && __strex(1u, v21) );
        if ( v23 )
          ExpReleaseFastMutexContended(v21, v23);
        KfLowerIrql((unsigned __int8)v22);
        KeAbPostRelease((unsigned int)v21);
        PiUEventNotifyClientPendingEvent(a2);
      }
      else
      {
        v31 = *(unsigned int **)(a2 + 8);
        ++*(_DWORD *)(a2 + 80);
        v32 = v31[7];
        v31[1] = 0;
        __dmb(0xBu);
        do
          v33 = __ldrex(v31);
        while ( !v33 && __strex(1u, v31) );
        if ( v33 )
          ExpReleaseFastMutexContended(v31, v33);
        KfLowerIrql((unsigned __int8)v32);
        KeAbPostRelease((unsigned int)v31);
      }
    }
    else
    {
      v7 = -1073741670;
    }
  }
  return v7;
}
