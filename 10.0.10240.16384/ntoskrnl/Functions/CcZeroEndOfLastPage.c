// CcZeroEndOfLastPage 
 
int __fastcall CcZeroEndOfLastPage(int result)
{
  int v1; // r4
  int v2; // r6
  int v3; // r2
  unsigned int v4; // r7
  int v5; // r5
  int v6; // r8
  unsigned int v7; // r2
  unsigned int *v8; // r5
  unsigned int v9; // r7
  unsigned int v10; // r1
  int v11[10]; // [sp+8h] [bp-28h] BYREF

  v1 = result;
  v2 = 0;
  if ( !*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) )
  {
    v2 = 1;
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 1;
    result = FsRtlAcquireFileExclusive(result);
  }
  v3 = *(_DWORD *)(v1 + 12);
  if ( (*(_BYTE *)(v3 + 4) & 0x40) != 0 )
  {
    v4 = *(_DWORD *)(v3 + 40);
    v5 = KeAbPreAcquire(v4, 0, 0);
    v6 = KfRaiseIrql(1);
    do
      v7 = __ldrex((unsigned __int8 *)v4);
    while ( __strex(v7 & 0xFE, (unsigned __int8 *)v4) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      ExpAcquireFastMutexContended(v4, v5);
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= 1u;
    *(_DWORD *)(v4 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v4 + 28) = v6;
    *(_BYTE *)(*(_DWORD *)(v1 + 12) + 4) |= 0x20u;
    v8 = *(unsigned int **)(*(_DWORD *)(v1 + 12) + 40);
    v9 = v8[7];
    v8[1] = 0;
    __dmb(0xBu);
    do
      v10 = __ldrex(v8);
    while ( !v10 && __strex(1u, v8) );
    if ( v10 )
      return sub_546B1C();
    KfLowerIrql((unsigned __int8)v9);
    result = KeAbPostRelease((unsigned int)v8);
  }
  else
  {
    *(_BYTE *)(v3 + 4) |= 0x20u;
  }
  if ( (*(_BYTE *)(*(_DWORD *)(v1 + 12) + 6) & 4) != 0 )
  {
    result = CcFlushCachePriv(*(_DWORD *)(v1 + 20), 0, 0, 0, 0, (int)v11);
    if ( !v11[0] )
      result = CcPurgeCacheSection(*(_DWORD *)(v1 + 20), 0, 0, 0);
  }
  if ( v2 )
  {
    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
    result = FsRtlReleaseFile(v1);
  }
  return result;
}
