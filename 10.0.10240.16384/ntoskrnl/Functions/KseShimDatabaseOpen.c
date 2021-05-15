// KseShimDatabaseOpen 
 
int __fastcall KseShimDatabaseOpen(_DWORD *a1)
{
  unsigned int v2; // r2
  int v3; // r0
  unsigned int v4; // r2
  int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int v9; // r1
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned int v13; // r1

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&KsepShimDbLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&KsepShimDbLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&KsepShimDbLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7CD010(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  if ( !KsepShimDbDuringBoot )
  {
    if ( KsepShimDbHandle )
    {
      *a1 = KsepShimDbHandle;
      ++KsepShimDbRefCount;
      v6 = 0;
      __dmb(0xBu);
      v7 = (unsigned int *)&unk_621718;
    }
    else
    {
      v6 = KsepShimDbMapToMemory();
      if ( v6 < 0 )
      {
        v6 = -1073741823;
        *a1 = 0;
        __dmb(0xBu);
        do
          v13 = __ldrex(&dword_62171C);
        while ( __strex(v13 + 1, &dword_62171C) );
        goto LABEL_11;
      }
      *a1 = KsepShimDbHandle;
      ++KsepShimDbRefCount;
      __dmb(0xBu);
      v7 = (unsigned int *)&unk_621714;
    }
    do
LABEL_10:
      v8 = __ldrex(v7);
    while ( __strex(v8 + 1, v7) );
LABEL_11:
    __dmb(0xBu);
    goto LABEL_12;
  }
  if ( KsepShimDbHandle )
  {
    *a1 = KsepShimDbHandle;
    ++KsepShimDbRefCount;
    v6 = 0;
    __dmb(0xBu);
    v7 = (unsigned int *)&unk_621710;
    goto LABEL_10;
  }
  v6 = -1073741823;
  *a1 = 0;
LABEL_12:
  __dmb(0xBu);
  do
    v9 = __ldrex((unsigned int *)&KsepShimDbLock);
  while ( __strex(v9 - 1, (unsigned int *)&KsepShimDbLock) );
  if ( (v9 & 2) != 0 && (v9 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&KsepShimDbLock);
  v10 = KeAbPostRelease((unsigned int)&KsepShimDbLock);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v6;
}
