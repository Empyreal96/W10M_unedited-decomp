// ProducerConsumerBufferComplete 
 
int __fastcall ProducerConsumerBufferComplete(_DWORD *a1, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r6
  unsigned int v6; // r7
  unsigned int v7; // r9
  unsigned int v10; // r4
  int result; // r0
  unsigned int v12; // r2
  __int64 v13; // r6
  unsigned int *v14; // r4
  unsigned int v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r2
  int v19; // r3
  int v20; // r0
  int v21; // r1
  int v22; // r2
  int v23; // r3
  __int64 v24; // r2
  unsigned int v25; // r2
  int v26; // r0
  int v27; // r1
  int v28; // r2
  int v29; // r3
  __int64 v30; // r2

  v4 = a1[1];
  v6 = *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(a2 + 12);
  v10 = a3 - *a1;
  if ( !v4 )
    __brkdiv0();
  result = _rt_udiv64(v4, __PAIR64__(v7, v6));
  if ( v12 > v10 )
    v10 += v4;
  LODWORD(v13) = (__PAIR64__(v7, v6) + v10 - v12) >> 32;
  HIDWORD(v13) = v6 + v10 - v12;
  v14 = a1 + 4;
  __dmb(0xBu);
  do
    v15 = __ldrex(v14);
  while ( !v15 && __strex(1u, v14) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !v15 )
      break;
    do
    {
      v16 = KePollFreezeExecution();
      result = PopHiberCheckForDebugBreak(v16, v17, v18, v19);
    }
    while ( *v14 );
    __dmb(0xBu);
    do
      v15 = __ldrex(v14);
    while ( !v15 && __strex(1u, v14) );
  }
  while ( 1 )
  {
    LODWORD(v30) = *(_DWORD *)(a2 + 12);
    HIDWORD(v30) = *(_DWORD *)(a2 + 8);
    if ( v13 == v30 )
      break;
    __dmb(0xBu);
    *v14 = 0;
    do
    {
      v20 = KePollFreezeExecution();
      result = PopHiberCheckForDebugBreak(v20, v21, v22, v23);
      LODWORD(v24) = *(_DWORD *)(a2 + 12);
      HIDWORD(v24) = *(_DWORD *)(a2 + 8);
    }
    while ( v13 != v24 );
    __dmb(0xBu);
    do
      v25 = __ldrex(v14);
    while ( !v25 && __strex(1u, v14) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !v25 )
        break;
      do
      {
        v26 = KePollFreezeExecution();
        result = PopHiberCheckForDebugBreak(v26, v27, v28, v29);
      }
      while ( *v14 );
      __dmb(0xBu);
      do
        v25 = __ldrex(v14);
      while ( !v25 && __strex(1u, v14) );
    }
  }
  *(_QWORD *)(a2 + 8) += a4;
  __dmb(0xBu);
  *v14 = 0;
  return result;
}
