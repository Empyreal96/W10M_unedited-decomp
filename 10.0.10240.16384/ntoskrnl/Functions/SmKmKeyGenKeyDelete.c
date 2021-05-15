// SmKmKeyGenKeyDelete 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall SmKmKeyGenKeyDelete(unsigned __int8 *a1, int a2)
{
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r1 OVERLAPPED
  _DWORD *v9; // r2 OVERLAPPED
  unsigned int v10; // r1
  int result; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire((unsigned int)a1, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(a1);
  while ( __strex(v7 | 1, a1) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a1, v5, (unsigned int)a1);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  *(_QWORD *)&v8 = *(_QWORD *)a2;
  if ( *(_DWORD *)(*(_DWORD *)a2 + 4) != a2 || *v9 != a2 )
    __fastfail(3u);
  *v9 = v8;
  *(_DWORD *)(v8 + 4) = v9;
  ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(a2);
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)a1);
  while ( __strex(v10 - 1, (unsigned int *)a1) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)a1);
  result = KeAbPostRelease((unsigned int)a1);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
