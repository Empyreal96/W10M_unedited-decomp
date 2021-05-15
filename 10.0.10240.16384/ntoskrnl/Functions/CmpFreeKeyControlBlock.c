// CmpFreeKeyControlBlock 
 
int __fastcall CmpFreeKeyControlBlock(unsigned int a1)
{
  unsigned __int64 v2; // r2
  unsigned __int64 v4; // kr00_8
  unsigned __int64 v5; // kr08_8
  int v6; // r6
  int v7; // r8
  unsigned int v8; // r2
  int v9; // r2
  int **v10; // r0
  _DWORD *v11; // r4
  int v12; // r3
  unsigned __int8 v13; // r4
  unsigned int v14; // r1
  unsigned int i; // r1
  unsigned __int64 v16; // r2
  unsigned __int64 v17; // kr10_8
  int v18; // lr
  __int64 v19; // kr18_8

  __dmb(0xBu);
  do
    v2 = __ldrexd(&CmPerfCounters);
  while ( __strexd(v2 - 1, &CmPerfCounters) );
  __dmb(0xBu);
  if ( *(_DWORD *)(a1 + 156) )
    return sub_7DD9C4();
  if ( (*(_WORD *)(a1 + 6) & 1) == 0 )
    return ExFreePoolWithTag(a1);
  __dmb(0xBu);
  do
    v4 = __ldrexd(&qword_920970[2]);
  while ( __strexd(v4 - 1, &qword_920970[2]) );
  __dmb(0xBu);
  do
    v5 = __ldrexd(&qword_920970[1]);
  while ( __strexd(v5 + 1, &qword_920970[1]) );
  __dmb(0xBu);
  v6 = KeAbPreAcquire((unsigned int)&CmpAllocBucketLock, 0, 0);
  v7 = KfRaiseIrql(1);
  do
    v8 = __ldrex((unsigned __int8 *)&CmpAllocBucketLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&CmpAllocBucketLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpAllocBucketLock, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  dword_632404 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_63241C = v7;
  *(_DWORD *)(a1 + 20) = 0;
  v9 = a1 + 64;
  v10 = (int **)dword_6323E4;
  *(_DWORD *)(a1 + 64) = &CmpFreeKCBListHead;
  *(_DWORD *)(a1 + 68) = v10;
  if ( *v10 != &CmpFreeKCBListHead )
    __fastfail(3u);
  *v10 = (int *)v9;
  v11 = (_DWORD *)(a1 & 0xFFFFF000);
  dword_6323E4 = v9;
  v12 = *v11 + 1;
  *v11 = v12;
  if ( v12 == 25 )
  {
    for ( i = 0; i < 0x19; i = (unsigned __int16)(i + 1) )
    {
      v18 = (int)&v11[40 * i + 18];
      v19 = *(_QWORD *)v18;
      if ( *(_DWORD *)(*(_DWORD *)v18 + 4) != v18 || *(_DWORD *)HIDWORD(v19) != v18 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v19) = v19;
      *(_DWORD *)(v19 + 4) = HIDWORD(v19);
      __dmb(0xBu);
      do
        v16 = __ldrexd(&qword_920970[1]);
      while ( __strexd(v16 - 1, &qword_920970[1]) );
      __dmb(0xBu);
    }
    ExFreePoolWithTag((unsigned int)v11);
    __dmb(0xBu);
    do
      v17 = __ldrexd(qword_920970);
    while ( __strexd(v17 - 1, qword_920970) );
    __dmb(0xBu);
  }
  dword_632404 = 0;
  v13 = dword_63241C;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&CmpAllocBucketLock);
  while ( !v14 && __strex(1u, (unsigned int *)&CmpAllocBucketLock) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpAllocBucketLock, v14);
  KfLowerIrql(v13);
  return KeAbPostRelease((unsigned int)&CmpAllocBucketLock);
}
