// ExpWnfNotifySubscription 
 
int __fastcall ExpWnfNotifySubscription(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int *v4; // r6
  int v7; // r8
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r5
  unsigned int v11; // r2
  int result; // r0
  int v13; // r3

  v4 = (unsigned int *)(a1 + 64);
  v7 = 0;
  v8 = KeAbPreAcquire(a1 + 64, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v4);
  while ( !v10 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v4, v8, (unsigned int)v4);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  if ( a2[7] && ExpWnfInsertSubscriptionInPendingQueue(a2, a3) )
    v7 = a2[6];
  __dmb(0xBu);
  do
    v11 = __ldrex(v4);
  while ( v11 == 17 && __strex(0, v4) );
  if ( v11 != 17 )
    ExfReleasePushLockShared(v4);
  result = KeAbPostRelease((unsigned int)v4);
  if ( v7 )
  {
    if ( PsInitialSystemProcess == v7 )
    {
      result = ExpWnfStartKernelDispatcher(a4);
    }
    else
    {
      v13 = *(_DWORD *)(v7 + 724);
      __dmb(0xBu);
      result = *(_DWORD *)(v13 + 64);
      if ( result )
        result = KeSetEvent(result, 1, 0);
    }
  }
  return result;
}
