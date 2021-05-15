// CcOkToAddWriteBehindThread 
 
int CcOkToAddWriteBehindThread()
{
  unsigned int v0; // r6
  unsigned int v1; // r2
  unsigned int v2; // r4
  int v3; // r1
  unsigned int v4; // r0
  int v5; // r5
  int result; // r0
  _DWORD *v7; // r1
  int v8; // r3
  int v9; // r3

  v0 = 0;
  v1 = 0;
  v2 = CcActiveExtraWriteBehindThreads;
  v3 = CcThroughputStats;
  v4 = *(_DWORD *)(CcThroughputStats + 8 * CcActiveExtraWriteBehindThreads);
  v5 = CcPagesYetToWrite;
  if ( v4 >= CcPagesYetToWrite )
    v1 = v4 - CcPagesYetToWrite;
  result = 1;
  *(_DWORD *)(CcThroughputStats + 8 * CcActiveExtraWriteBehindThreads) = CcPagesYetToWrite;
  if ( v2 )
    v0 = *(_DWORD *)(v3 + 8 * v2 - 4);
  v7 = (_DWORD *)(v3 + 8 * v2);
  v7[1] = v1;
  if ( !v1 )
    return 1;
  v8 = CcThroughputTrend;
  if ( v1 < v0 )
  {
    if ( CcThroughputTrend > 0 )
      v8 = 0;
    v9 = v8 - 1;
  }
  else
  {
    if ( CcThroughputTrend < 0 )
      v8 = 0;
    v9 = v8 + 1;
  }
  CcThroughputTrend = v9;
  if ( v9 == 3 )
  {
    CcThroughputTrend = 0;
    result = 2;
    if ( v2 < CcMaxExtraWriteBehindThreads )
    {
      v7[2] = v5;
      v7[3] = 0;
    }
  }
  else if ( v9 == -3 )
  {
    result = 3;
    CcThroughputTrend = 0;
    if ( v2 )
    {
      *(v7 - 2) = v5;
      *(v7 - 1) = 0;
    }
  }
  return result;
}
