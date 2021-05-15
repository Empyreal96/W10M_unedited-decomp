// PfpPrefetchSharedStart 
 
int __fastcall PfpPrefetchSharedStart(_DWORD *a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r4
  unsigned int v4; // r1
  unsigned int v5; // r0
  int result; // r0
  unsigned int v7; // r2
  int v8; // r7
  unsigned int v9; // r1
  int v10; // r1
  unsigned int v11; // r0
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  a1[10] |= 8u;
  a1[2] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  a1[10] ^= ((unsigned __int8)a1[10] ^ (unsigned __int8)(2 * PsSetCurrentThreadPrefetching(1))) & 2;
  __pld(dword_63734C);
  v3 = dword_63734C[0] & 0xFFFFFFFE;
  v4 = (dword_63734C[0] & 0xFFFFFFFE) + 2;
  do
    v5 = __ldrex(dword_63734C);
  while ( v5 == v3 && __strex(v4, dword_63734C) );
  __dmb(0xBu);
  if ( v5 != v3 )
    return sub_80936C(v5, v4, dword_63734C);
  a1[10] |= 1u;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = KeAbPreAcquire((unsigned int)&dword_637354, 0, 0);
  do
    v9 = __ldrex((unsigned __int8 *)&dword_637354);
  while ( __strex(v9 | 1, (unsigned __int8 *)&dword_637354) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_637354, v8, (unsigned int)&dword_637354);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  if ( (dword_637360 & 1) == 0 )
  {
    v10 = dword_637358;
    *a1 = dword_637358;
    a1[1] = &dword_637358;
    if ( *(int **)(v10 + 4) != &dword_637358 )
      __fastfail(3u);
    *(_DWORD *)(v10 + 4) = a1;
    dword_637358 = (int)a1;
  }
  __dmb(0xBu);
  do
    v11 = __ldrex(&dword_637354);
  while ( __strex(v11 - 1, &dword_637354) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock(&dword_637354);
  v12 = KeAbPostRelease((unsigned int)&dword_637354);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = (__int16)(*(_WORD *)(v13 + 0x134) + 1);
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  if ( *a1 )
    result = 0;
  else
    result = -1073741127;
  return result;
}
