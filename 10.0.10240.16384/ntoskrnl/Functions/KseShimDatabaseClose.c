// KseShimDatabaseClose 
 
int __fastcall KseShimDatabaseClose(int a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int result; // r0
  int v6; // r0
  unsigned int v7; // r1
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r1
  int v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r1
  _WORD *v16; // r2

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&KsepShimDbLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&KsepShimDbLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&KsepShimDbLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7CC82C(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = KsepShimDbHandle;
  if ( a1 != KsepShimDbHandle )
  {
    __dmb(0xBu);
    do
    {
      v14 = __ldrex(&KsepHistoryErrorsIndex);
      v15 = v14 + 1;
    }
    while ( __strex(v15, &KsepHistoryErrorsIndex) );
    __dmb(0xBu);
    v16 = &KsepHistoryErrors[4 * (v15 & 0x3F)];
    *((_DWORD *)v16 + 1) = -1073740768;
    v16[1] = 9;
    *v16 = 379;
    if ( (KsepDebugFlag & 4) != 0 )
      RtlAssert((int)"DbHandle == KsepShimDbHandle", (int)"minkernel\\ntos\\kshim\\ksesdb.c", 379, 0);
    v6 = KsepShimDbHandle;
  }
  if ( KsepShimDbDuringBoot )
  {
    __dmb(0xBu);
    do
      v7 = __ldrex((unsigned int *)&KsepShimDbLock);
    while ( __strex(v7 - 1, (unsigned int *)&KsepShimDbLock) );
    if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&KsepShimDbLock);
    v8 = KeAbPostRelease((unsigned int)&KsepShimDbLock);
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = *(_WORD *)(v9 + 0x134) + 1;
    *(_WORD *)(v9 + 308) = v10;
    if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      v8 = KiCheckForKernelApcDelivery(v8);
    result = KseShimDatabaseBootRelease(v8);
  }
  else
  {
    if ( v6 )
    {
      if ( !KsepShimDbRefCount || (--KsepShimDbRefCount, !KsepShimDbRefCount) )
      {
        KsepShimDbUnmapFromMemory();
        KsepShimDbHandle = 0;
      }
    }
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&KsepShimDbLock);
    while ( __strex(v11 - 1, (unsigned int *)&KsepShimDbLock) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&KsepShimDbLock);
    result = KeAbPostRelease((unsigned int)&KsepShimDbLock);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
