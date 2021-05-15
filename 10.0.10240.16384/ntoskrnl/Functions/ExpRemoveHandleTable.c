// ExpRemoveHandleTable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpRemoveHandleTable(int a1)
{
  unsigned int v2; // r5
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  _DWORD *v6; // r4
  int v7; // r1 OVERLAPPED
  _DWORD *v8; // r2 OVERLAPPED
  unsigned int v9; // r1
  __int16 v10; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&HandleTableListLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&HandleTableListLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&HandleTableListLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7E93E8(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = (_DWORD *)(a1 + 16);
  *(_QWORD *)&v7 = *(_QWORD *)(a1 + 16);
  if ( *(_DWORD *)(v7 + 4) != a1 + 16 || (_DWORD *)*v8 != v6 )
    __fastfail(3u);
  *v8 = v7;
  *(_DWORD *)(v7 + 4) = v8;
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&HandleTableListLock);
  while ( __strex(v9 - 1, (unsigned int *)&HandleTableListLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&HandleTableListLock);
  result = KeAbPostRelease((unsigned int)&HandleTableListLock);
  v10 = *(_WORD *)(v2 + 308) + 1;
  *(_WORD *)(v2 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v2 + 100) != v2 + 100 && !*(_WORD *)(v2 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  *(_DWORD *)(a1 + 20) = a1 + 16;
  *v6 = v6;
  return result;
}
