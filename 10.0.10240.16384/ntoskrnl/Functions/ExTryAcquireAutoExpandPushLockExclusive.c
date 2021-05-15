// ExTryAcquireAutoExpandPushLockExclusive 
 
int __fastcall ExTryAcquireAutoExpandPushLockExclusive(unsigned int a1, int a2)
{
  int v2; // r5
  unsigned int v4; // r2
  int v5; // r3
  int v6; // r6
  unsigned int v7; // r1
  int v8; // r2

  v2 = 0;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheckEx(338, a2, a1, 0, 0);
  if ( (a2 & 2) == 0 )
    v2 = KeAbPreAcquire(a1, 0, 1);
  do
    v4 = __ldrex((unsigned __int8 *)a1);
  while ( __strex(v4 | 1, (unsigned __int8 *)a1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
  {
    v8 = *(_DWORD *)(a1 + 8);
    v6 = 0;
    if ( (v8 & 0xF0000u) < 0xF0000 )
      *(_DWORD *)(a1 + 8) = v8 + 0x10000;
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 4);
    v6 = 1;
    if ( (v5 & 1) != 0 )
    {
      v6 = ExpTryAcquireFannedOutPushLockExclusive(v5 & 0xFFFFFFF8);
      if ( !v6 )
      {
        __dmb(0xBu);
        do
          v7 = __ldrex((unsigned int *)a1);
        while ( __strex(v7 - 1, (unsigned int *)a1) );
        if ( (v7 & 2) != 0 && (v7 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)a1);
      }
    }
  }
  if ( v2 )
  {
    if ( v6 )
      *(_BYTE *)(v2 + 14) |= 1u;
    else
      KeAbPostReleaseEx(a1, v2);
  }
  return v6;
}
