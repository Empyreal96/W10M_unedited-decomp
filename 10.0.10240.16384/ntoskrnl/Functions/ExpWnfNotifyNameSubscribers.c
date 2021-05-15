// ExpWnfNotifyNameSubscribers 
 
unsigned int __fastcall ExpWnfNotifyNameSubscribers(int a1, int a2, int a3, int a4)
{
  unsigned int *v4; // r7
  int v5; // r10
  int v6; // r8
  int v7; // r9
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r5
  int v11; // r2
  _DWORD *v12; // r4
  int v13; // r0
  int v14; // r1
  unsigned int v15; // r2
  unsigned int result; // r0
  int v17; // r5
  BOOL v18; // r2
  int v19; // r0
  int v23; // [sp+Ch] [bp-24h]

  v4 = (unsigned int *)(a1 + 64);
  v23 = a1;
  v5 = a1;
  v6 = 0;
  v7 = 1;
  v8 = KeAbPreAcquire(a1 + 64, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v4);
  while ( !v10 && __strex(0x11u, v4) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v4, v8, (unsigned int)v4);
  v11 = 1;
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v12 = *(_DWORD **)(v5 + 68);
  if ( v12 != (_DWORD *)(v5 + 68) )
  {
    do
    {
      if ( v7 && (v12[5] & 1) != 0 )
        v7 = 0;
      v13 = ExpWnfInsertSubscriptionInPendingQueue(v12 - 10, a2, v11);
      v11 = *(v12 - 4);
      v14 = *(_DWORD *)(v11 + 724);
      __dmb(0xBu);
      if ( v13 )
      {
        if ( v11 == PsInitialSystemProcess )
        {
          v6 = 1;
        }
        else
        {
          v19 = *(_DWORD *)(v14 + 64);
          if ( v19 )
            KeSetEvent(v19, 1, 0);
        }
      }
      v12 = (_DWORD *)*v12;
    }
    while ( v12 != (_DWORD *)(v5 + 68) );
    v5 = v23;
    v4 = (unsigned int *)(v23 + 64);
  }
  __dmb(0xBu);
  do
    v15 = __ldrex(v4);
  while ( v15 == 17 && __strex(0, v4) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v4);
  result = KeAbPostRelease((unsigned int)v4);
  if ( v7 && (a2 & 1) != 0 )
  {
    v18 = !v6 && a3;
    v17 = a4;
    result = ExpWnfNotifyNameSubscribers(v5, 8, v18, a4);
  }
  else
  {
    v17 = a4;
  }
  if ( v6 )
  {
    if ( a3 )
      result = ExpWnfStartKernelDispatcher(v17);
  }
  return result;
}
