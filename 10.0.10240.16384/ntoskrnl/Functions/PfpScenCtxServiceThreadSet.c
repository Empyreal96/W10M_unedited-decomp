// PfpScenCtxServiceThreadSet 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PfpScenCtxServiceThreadSet(unsigned int a1, int a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r8 OVERLAPPED
  __int64 v6; // r6 OVERLAPPED
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r2
  unsigned int v11; // r1
  int result; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  if ( a2 )
  {
    v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v4 = PsGetThreadId(v3);
    *(__int64 *)((char *)&v6 + 4) = *(_QWORD *)(v3 + 832);
    LODWORD(v6) = v4;
  }
  else
  {
    v6 = 0i64;
    v5 = 0;
  }
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire(a1, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v10 | 1, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v8, a1);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  *(_QWORD *)(a1 + 44) = v6;
  *(_DWORD *)(a1 + 52) = v5;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)a1);
  while ( __strex(v11 - 1, (unsigned int *)a1) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  result = KeAbPostRelease(a1);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
