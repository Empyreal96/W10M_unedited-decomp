// ExpInsertLowLevelTableIntoFreeList 
 
// local variable allocation has failed, the output may be wrong!
unsigned int *__fastcall ExpInsertLowLevelTableIntoFreeList(unsigned int *result, int a2, unsigned int a3, int a4)
{
  _QWORD *v7; // r2
  int v8; // r1
  int v9; // r3 OVERLAPPED
  _QWORD *v10; // r4
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1

  if ( a4 )
  {
    v7 = (_QWORD *)(a2 + 8);
    v8 = 510;
    v9 = 0;
    do
    {
      v10 = v7 + 1;
      *v7++ = *(_QWORD *)&v9;
      --v8;
    }
    while ( v8 );
    *(_DWORD *)(a2 + 4088) = 0;
    *(_DWORD *)(a2 + 4092) = 0;
  }
  __dmb(0xBu);
  do
    v11 = __ldrex(result);
  while ( __strex(v11 + 2048, result) );
  __dmb(0xBu);
  if ( a4 )
  {
    v12 = KeAbPreAcquire(a3, 0, 0);
    do
      v13 = __ldrex((unsigned __int8 *)a3);
    while ( __strex(v13 | 1, (unsigned __int8 *)a3) );
    __dmb(0xBu);
    if ( (v13 & 1) != 0 )
    {
      result = (unsigned int *)sub_7DE02C(v12);
    }
    else
    {
      if ( v12 )
        *(_BYTE *)(v12 + 14) |= 1u;
      if ( *(_DWORD *)(a3 + 4) )
        *(_DWORD *)(*(_DWORD *)(a3 + 8) + 4) = a2 + 8;
      else
        *(_DWORD *)(a3 + 4) = a2 + 8;
      *(_DWORD *)(a3 + 8) = a2 + 4088;
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)a3);
      while ( __strex(v14 - 1, (unsigned int *)a3) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)a3);
      result = (unsigned int *)KeAbPostRelease(a3);
    }
  }
  return result;
}
