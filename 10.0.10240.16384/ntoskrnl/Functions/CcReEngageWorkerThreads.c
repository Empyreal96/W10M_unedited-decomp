// CcReEngageWorkerThreads 
 
_DWORD *__fastcall CcReEngageWorkerThreads(_DWORD *result, unsigned int a2)
{
  _DWORD *v2; // r5
  unsigned int v3; // r8
  __int64 v4; // r2
  unsigned int i; // r5
  __int64 v6; // r2

  v2 = result;
  v3 = 0;
  if ( result )
  {
    do
    {
      result = (_DWORD *)CcIdleWorkerThreadList;
      if ( (int *)CcIdleWorkerThreadList == &CcIdleWorkerThreadList )
        break;
      v4 = *(_QWORD *)CcIdleWorkerThreadList;
      if ( *(int **)(CcIdleWorkerThreadList + 4) != &CcIdleWorkerThreadList
        || *(_DWORD *)(v4 + 4) != CcIdleWorkerThreadList )
      {
        __fastfail(3u);
      }
      HIDWORD(v4) = CcNumberActiveWorkerThreads;
      CcIdleWorkerThreadList = *(_DWORD *)CcIdleWorkerThreadList;
      *(_DWORD *)(v4 + 4) = &CcIdleWorkerThreadList;
      CcNumberActiveWorkerThreads = HIDWORD(v4) + 1;
      *result = 0;
      result = (_DWORD *)ExQueueWorkItem(result, 0);
      ++v3;
    }
    while ( v3 < (unsigned int)v2 );
  }
  for ( i = 0; i < a2; ++i )
  {
    result = (_DWORD *)CcIdleExtraWriteBehindThreadList;
    if ( (int *)CcIdleExtraWriteBehindThreadList == &CcIdleExtraWriteBehindThreadList )
      break;
    v6 = *(_QWORD *)CcIdleExtraWriteBehindThreadList;
    if ( *(int **)(CcIdleExtraWriteBehindThreadList + 4) != &CcIdleExtraWriteBehindThreadList
      || *(_DWORD *)(v6 + 4) != CcIdleExtraWriteBehindThreadList )
    {
      __fastfail(3u);
    }
    HIDWORD(v6) = CcActiveExtraWriteBehindThreads;
    CcIdleExtraWriteBehindThreadList = *(_DWORD *)CcIdleExtraWriteBehindThreadList;
    *(_DWORD *)(v6 + 4) = &CcIdleExtraWriteBehindThreadList;
    CcActiveExtraWriteBehindThreads = HIDWORD(v6) + 1;
    *result = 0;
    result = (_DWORD *)ExQueueWorkItem(result, 0);
  }
  return result;
}
