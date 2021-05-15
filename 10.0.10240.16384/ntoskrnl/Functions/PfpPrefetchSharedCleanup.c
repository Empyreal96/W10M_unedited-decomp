// PfpPrefetchSharedCleanup 
 
// local variable allocation has failed, the output may be wrong!
_DWORD *__fastcall PfpPrefetchSharedCleanup(_DWORD *result)
{
  _DWORD *v1; // r5
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r1
  int v5; // r1 OVERLAPPED
  _DWORD *v6; // r2 OVERLAPPED
  unsigned int v7; // r0
  unsigned int v8; // r1
  int v9; // r3
  unsigned int v10; // r4
  unsigned int v11; // r1
  __int16 v12; // r3

  v1 = result;
  if ( *result )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v2 + 308);
    v3 = KeAbPreAcquire((unsigned int)&dword_637354, 0, 0);
    do
      v4 = __ldrex((unsigned __int8 *)&dword_637354);
    while ( __strex(v4 | 1, (unsigned __int8 *)&dword_637354) );
    __dmb(0xBu);
    if ( (v4 & 1) != 0 )
      return (_DWORD *)sub_7E8F8C(v3);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    *(_QWORD *)&v5 = *(_QWORD *)v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 || (_DWORD *)*v6 != v1 )
      __fastfail(3u);
    *v6 = v5;
    *(_DWORD *)(v5 + 4) = v6;
    __dmb(0xBu);
    do
      v7 = __ldrex(&dword_637354);
    while ( __strex(v7 - 1, &dword_637354) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock(&dword_637354);
    result = (_DWORD *)KeAbPostRelease((unsigned int)&dword_637354);
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v9 = (__int16)(*(_WORD *)(v8 + 0x134) + 1);
    *(_WORD *)(v8 + 308) = v9;
    if ( !v9 && *(_DWORD *)(v8 + 100) != v8 + 100 && !*(_WORD *)(v8 + 310) )
      result = (_DWORD *)KiCheckForKernelApcDelivery((int)result);
  }
  if ( (v1[10] & 1) != 0 )
  {
    __pld(dword_63734C);
    v10 = dword_63734C[0] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      result = (_DWORD *)__ldrex(dword_63734C);
    while ( result == (_DWORD *)v10 && __strex(v10 - 2, dword_63734C) );
    if ( result != (_DWORD *)v10 )
      result = ExfReleaseRundownProtection((unsigned __int8 *)dword_63734C);
    v1[10] &= 0xFFFFFFFE;
  }
  if ( v1[2] )
    result = (_DWORD *)PsSetCurrentThreadPrefetching((v1[10] >> 1) & 1);
  if ( (v1[10] & 8) != 0 )
  {
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      result = (_DWORD *)KiCheckForKernelApcDelivery((int)result);
  }
  return result;
}
