// SmcCacheCreatePrepare 
 
int __fastcall SmcCacheCreatePrepare(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r5
  int v5; // r1
  char v6; // r2
  unsigned int v7; // r0
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)byte_636CB0, 0, 0);
  do
    v5 = __ldrex(byte_636CB0);
  while ( __strex(v5 | 1, byte_636CB0) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(byte_636CB0, v4, (unsigned int)byte_636CB0);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = dword_636CA8;
  if ( (dword_636CA8 & 8) == 0 )
  {
    v2 = SmRegistrationCtxStart(&dword_636DFC, v5, dword_636CA8, 6268);
    if ( v2 < 0 )
    {
      v6 = dword_636CA8;
    }
    else
    {
      v6 = dword_636CA8 | 8;
      dword_636CA8 |= 8u;
    }
  }
  if ( (v6 & 4) == 0 && (v6 & 8) != 0 )
  {
    v2 = SmcCacheManagerStart(a1, dword_636DFC);
    if ( v2 >= 0 )
      dword_636CA8 |= 4u;
  }
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)byte_636CB0);
  while ( __strex(v7 - 1, (unsigned int *)byte_636CB0) );
  if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)byte_636CB0);
  v8 = KeAbPostRelease((unsigned int)byte_636CB0);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v2;
}
