// ExpWnfAcquireSubscriptionNameInstance 
 
int __fastcall ExpWnfAcquireSubscriptionNameInstance(int a1, int a2)
{
  int v2; // r3
  unsigned int *v4; // r5
  int v5; // r7
  int v6; // r0
  unsigned int v7; // r2
  int v9; // r3
  unsigned int *v10; // r0
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r2

  v2 = *(_DWORD *)(a1 + 724);
  __dmb(0xBu);
  v4 = (unsigned int *)(v2 + 40);
  v5 = 0;
  v6 = KeAbPreAcquire(v2 + 40, 0, 0);
  do
    v7 = __ldrex(v4);
  while ( !v7 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v7 )
    return sub_7F3468(v6, 17);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v9 = *(_DWORD *)(a2 + 28);
  if ( v9 )
  {
    v10 = (unsigned int *)(v9 + 4);
    __pld((void *)(v9 + 4));
    v11 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
    do
      v12 = __ldrex(v10);
    while ( v12 == v11 && __strex(v11 + 2, v10) );
    __dmb(0xBu);
    if ( v12 == v11 || ExfAcquireRundownProtection(v10) )
      v5 = *(_DWORD *)(a2 + 28);
  }
  __dmb(0xBu);
  do
    v13 = __ldrex(v4);
  while ( v13 == 17 && __strex(0, v4) );
  if ( v13 != 17 )
    ExfReleasePushLockShared(v4);
  KeAbPostRelease((unsigned int)v4);
  return v5;
}
