// CcIncrementWriteBehindPriority 
 
unsigned int __fastcall CcIncrementWriteBehindPriority(unsigned int result, int a2)
{
  int v2; // r3
  _DWORD *v3; // r5
  unsigned int v4; // r4
  int v5; // r2
  int *v6; // r4
  int v7; // r0
  unsigned int *v8; // r2
  unsigned int v9; // r1
  unsigned int *v10; // r2
  __int64 v11; // r0
  int **v12; // r0
  __int64 v13; // kr00_8
  int *v14; // r4
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int vars4; // [sp+1Ch] [bp+4h]

  v2 = *(_DWORD *)(result + 352);
  v3 = 0;
  v4 = result;
  if ( !v2 || (v2 & 1) != 0 )
    return result;
  KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624, a2);
  v5 = *(_DWORD *)(v4 + 352);
  if ( v5 )
  {
    *(_DWORD *)(v4 + 352) = v5 | 1;
    v11 = *(_QWORD *)v5;
    if ( *(_DWORD *)(*(_DWORD *)v5 + 4) != v5 || *(_DWORD *)HIDWORD(v11) != v5 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v11) = v11;
    *(_DWORD *)(v11 + 4) = HIDWORD(v11);
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = 0;
    v12 = (int **)dword_632694;
    *(_DWORD *)v5 = &CcFastTeardownWorkQueue;
    *(_DWORD *)(v5 + 4) = v12;
    if ( *v12 != &CcFastTeardownWorkQueue )
      __fastfail(3u);
    *v12 = (int *)v5;
    dword_632694 = v5;
    if ( !CcQueueThrottle && (int *)CcIdleWorkerThreadList != &CcIdleWorkerThreadList )
    {
      v13 = *(_QWORD *)CcIdleWorkerThreadList;
      if ( *(int **)(CcIdleWorkerThreadList + 4) != &CcIdleWorkerThreadList
        || *(_DWORD *)(v13 + 4) != CcIdleWorkerThreadList )
      {
        __fastfail(3u);
      }
      v3 = (_DWORD *)CcIdleWorkerThreadList;
      CcIdleWorkerThreadList = *(_DWORD *)CcIdleWorkerThreadList;
      *(_DWORD *)(v13 + 4) = &CcIdleWorkerThreadList;
      ++CcNumberActiveWorkerThreads;
    }
    v14 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = KiReleaseQueuedSpinLockInstrumented(v14, vars4);
      goto LABEL_36;
    }
    result = *v14;
    if ( !*v14 )
    {
      v15 = (unsigned int *)v14[1];
      __dmb(0xBu);
      result = 0;
      do
        v16 = __ldrex(v15);
      while ( (int *)v16 == v14 && __strex(0, v15) );
      if ( (int *)v16 == v14 )
      {
LABEL_36:
        if ( v3 )
        {
          *v3 = 0;
          result = ExQueueWorkItem(v3, 0);
        }
        return result;
      }
      result = KxWaitForLockChainValid(v14);
    }
    *v14 = 0;
    __dmb(0xBu);
    v17 = (unsigned int *)(result + 4);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 ^ 1, v17) );
    goto LABEL_36;
  }
  v6 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2624);
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(v6, vars4);
  v7 = *v6;
  if ( *v6 )
    goto LABEL_13;
  v8 = (unsigned int *)v6[1];
  __dmb(0xBu);
  result = 0;
  do
    v9 = __ldrex(v8);
  while ( (int *)v9 == v6 && __strex(0, v8) );
  if ( (int *)v9 != v6 )
  {
    v7 = KxWaitForLockChainValid(v6);
LABEL_13:
    *v6 = 0;
    __dmb(0xBu);
    v10 = (unsigned int *)(v7 + 4);
    do
      result = __ldrex(v10);
    while ( __strex(result ^ 1, v10) );
  }
  return result;
}
