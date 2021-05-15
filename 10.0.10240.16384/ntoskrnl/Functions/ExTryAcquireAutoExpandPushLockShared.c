// ExTryAcquireAutoExpandPushLockShared 
 
int __fastcall ExTryAcquireAutoExpandPushLockShared(unsigned int a1, int a2)
{
  int v2; // r5
  int v3; // r4
  int v5; // r7
  int v6; // r3
  unsigned int v7; // r2

  v2 = 0;
  v3 = 0;
  if ( (a2 & 0xFFFFFFFC) != 0 )
    KeBugCheck2(338, a2, a1, 0, 0, 0);
  v5 = a2 & 2;
  if ( (a2 & 2) == 0 )
    v2 = KeAbPreAcquire(a1, 0, 1);
  v6 = *(_DWORD *)(a1 + 4);
  if ( (v6 & 1) != 0 )
  {
    v3 = ExpTryAcquireFannedOutPushLockShared(v6 & 0xFFFFFFF8);
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)a1);
    while ( !v7 && __strex(0x11u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( !v7 || ExfTryAcquirePushLockShared((unsigned int *)a1) )
      v3 = a1 | 1;
  }
  if ( !v5 && v3 )
    v3 |= 2u;
  if ( v2 )
  {
    if ( v3 )
      *(_BYTE *)(v2 + 14) |= 1u;
    else
      KeAbPostReleaseEx(a1, v2);
  }
  return v3;
}
