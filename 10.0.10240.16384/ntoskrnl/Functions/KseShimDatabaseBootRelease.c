// KseShimDatabaseBootRelease 
 
int KseShimDatabaseBootRelease()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r1
  unsigned int v3; // r2
  int result; // r0
  unsigned int v5; // r1
  unsigned int v6; // r1
  __int16 v7; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&KsepShimDbLock, 0, 0);
  do
    v3 = __ldrex((unsigned __int8 *)&KsepShimDbLock);
  while ( __strex(v3 | 1, (unsigned __int8 *)&KsepShimDbLock) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    return sub_815D50(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  if ( KsepShimDbDuringBoot )
  {
    if ( !KsepShimDbRefCount || (--KsepShimDbRefCount, !KsepShimDbRefCount) )
    {
      if ( KsepShimDbHandle )
      {
        SdbReleaseDatabase(KsepShimDbHandle, v2);
        KsepShimDbHandle = 0;
        KsepPoolFreePaged(KsepShimDbAddress);
        KsepShimDbAddress = 0;
      }
      KsepShimDbDuringBoot = 0;
    }
  }
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&KsepShimDbLock);
  while ( __strex(v5 - 1, (unsigned int *)&KsepShimDbLock) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&KsepShimDbLock);
  result = KeAbPostRelease((unsigned int)&KsepShimDbLock);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = *(_WORD *)(v6 + 0x134) + 1;
  *(_WORD *)(v6 + 308) = v7;
  if ( !v7 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
