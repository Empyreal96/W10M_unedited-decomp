// PspRemoveQuotaBlock 
 
int __fastcall PspRemoveQuotaBlock(int a1)
{
  int v2; // r8
  int v3; // r0
  unsigned int v4; // r5
  unsigned __int8 *v5; // r6
  int v6; // r0
  int v7; // r7
  unsigned int v8; // r2
  __int64 v9; // r0
  unsigned int v10; // r1
  int result; // r0
  __int16 v12; // r3

  if ( *(_DWORD *)(a1 + 1032) == 1 )
  {
    v2 = 1;
    v3 = 0;
  }
  else
  {
    v2 = 0;
    v3 = a1 + 1152;
  }
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (unsigned __int8 *)(PspQuotaBlockTable + 12 * PspHashKeyValue(v3, 0));
  --*(_WORD *)(v4 + 308);
  v6 = KeAbPreAcquire((unsigned int)v5, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( __strex(v8 | 1, v5) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v5, v6, (unsigned int)v5);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( v2 )
  {
    if ( a1 == PspDefaultQuotaBlock )
      PspDefaultQuotaBlock = 0;
  }
  else if ( *(_DWORD *)(a1 + 1032) )
  {
    v9 = *(_QWORD *)(a1 + 1032);
    if ( *(_DWORD *)(v9 + 4) != a1 + 1032 || *(_DWORD *)HIDWORD(v9) != a1 + 1032 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v9) = v9;
    *(_DWORD *)(v9 + 4) = HIDWORD(v9);
  }
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v5);
  while ( __strex(v10 - 1, (unsigned int *)v5) );
  if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v5);
  result = KeAbPostRelease((unsigned int)v5);
  v12 = *(_WORD *)(v4 + 308) + 1;
  *(_WORD *)(v4 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v4 + 100) != v4 + 100 && !*(_WORD *)(v4 + 310) )
    result = KiCheckForKernelApcDelivery(result);
  return result;
}
