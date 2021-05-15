// CmpAllocateKeyControlBlock 
 
int CmpAllocateKeyControlBlock()
{
  unsigned __int64 v0; // r2
  int v1; // r4
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r4
  __int64 v5; // r2
  unsigned __int8 v6; // r5
  unsigned int v7; // r1
  unsigned __int64 v8; // kr00_8
  unsigned __int64 v9; // kr08_8
  int result; // r0
  _DWORD *v11; // r0
  _DWORD *v12; // r9
  unsigned __int64 v13; // kr10_8
  unsigned int i; // r4
  _DWORD *v15; // r0
  int **v16; // lr
  unsigned __int64 v17; // r2
  unsigned __int8 v18; // r4
  unsigned int v19; // r1

  __dmb(0xBu);
  do
    v0 = __ldrexd(&CmPerfCounters);
  while ( __strexd(v0 + 1, &CmPerfCounters) );
  __dmb(0xBu);
  if ( CmpAllocInited )
  {
    v1 = KeAbPreAcquire((unsigned int)&CmpAllocBucketLock, 0, 0);
    v2 = KfRaiseIrql(1);
    do
      v3 = __ldrex((unsigned __int8 *)&CmpAllocBucketLock);
    while ( __strex(v3 & 0xFE, (unsigned __int8 *)&CmpAllocBucketLock) );
    __dmb(0xBu);
    if ( (v3 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpAllocBucketLock, v1);
    if ( v1 )
      *(_BYTE *)(v1 + 14) |= 1u;
    dword_632404 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_63241C = v2;
    while ( 1 )
    {
      v4 = CmpFreeKCBListHead;
      if ( (int *)CmpFreeKCBListHead != &CmpFreeKCBListHead )
      {
        v5 = *(_QWORD *)CmpFreeKCBListHead;
        if ( *(int **)(CmpFreeKCBListHead + 4) != &CmpFreeKCBListHead || *(_DWORD *)(v5 + 4) != CmpFreeKCBListHead )
          __fastfail(3u);
        CmpFreeKCBListHead = *(_DWORD *)CmpFreeKCBListHead;
        *(_DWORD *)(v5 + 4) = &CmpFreeKCBListHead;
        --*(_DWORD *)((v4 - 64) & 0xFFFFF000);
        dword_632404 = 0;
        v6 = dword_63241C;
        __dmb(0xBu);
        do
          v7 = __ldrex((unsigned int *)&CmpAllocBucketLock);
        while ( !v7 && __strex(1u, (unsigned int *)&CmpAllocBucketLock) );
        if ( v7 )
          ExpReleaseFastMutexContended((unsigned int *)&CmpAllocBucketLock, v7);
        KfLowerIrql(v6);
        KeAbPostRelease((unsigned int)&CmpAllocBucketLock);
        __dmb(0xBu);
        do
          v8 = __ldrexd(&qword_920970[2]);
        while ( __strexd(v8 + 1, &qword_920970[2]) );
        __dmb(0xBu);
        do
          v9 = __ldrexd(&qword_920970[1]);
        while ( __strexd(v9 - 1, &qword_920970[1]) );
        __dmb(0xBu);
        return v4 - 64;
      }
      v11 = (_DWORD *)ExAllocatePoolWithTag(1, 4096, 1816218947);
      v12 = v11;
      if ( !v11 )
        break;
      __dmb(0xBu);
      do
        v13 = __ldrexd(qword_920970);
      while ( __strexd(v13 + 1, qword_920970) );
      __dmb(0xBu);
      *v11 = 25;
      for ( i = 0; i < 0x19; i = (unsigned __int16)(i + 1) )
      {
        v15 = &v12[40 * i];
        v15[3] |= 0x10000u;
        v16 = (int **)dword_6323E4;
        v15[18] = &CmpFreeKCBListHead;
        v15[19] = v16;
        if ( *v16 != &CmpFreeKCBListHead )
          sub_805284();
        *v16 = v15 + 18;
        dword_6323E4 = (int)(v15 + 18);
        __dmb(0xBu);
        do
          v17 = __ldrexd(&qword_920970[1]);
        while ( __strexd(v17 + 1, &qword_920970[1]) );
        __dmb(0xBu);
      }
    }
    dword_632404 = 0;
    v18 = dword_63241C;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)&CmpAllocBucketLock);
    while ( !v19 && __strex(1u, (unsigned int *)&CmpAllocBucketLock) );
    if ( v19 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpAllocBucketLock, v19);
    KfLowerIrql(v18);
    KeAbPostRelease((unsigned int)&CmpAllocBucketLock);
  }
  result = ExAllocatePoolWithTag(1, 160, 1651199299);
  if ( result )
    *(_DWORD *)(result + 4) &= 0xFFFEFFFF;
  return result;
}
