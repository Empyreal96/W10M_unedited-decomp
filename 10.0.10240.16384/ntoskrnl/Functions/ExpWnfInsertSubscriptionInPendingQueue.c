// ExpWnfInsertSubscriptionInPendingQueue 
 
int __fastcall ExpWnfInsertSubscriptionInPendingQueue(_DWORD *a1, int a2)
{
  int v3; // r3
  int v5; // r9
  unsigned __int8 *v6; // r5
  int v7; // r6
  int v8; // r0
  int v9; // r7
  unsigned int v10; // r2
  int v11; // r7
  unsigned int v12; // r1
  int v14; // r3
  _DWORD *v15; // r0
  _DWORD *v16; // r2
  int v17; // r3
  unsigned int *v18; // r2
  unsigned int v19; // r1
  unsigned int v20; // r1

  v3 = a1[6];
  if ( !v3 )
    return 0;
  v5 = *(_DWORD *)(v3 + 724);
  __dmb(0xBu);
  v6 = (unsigned __int8 *)(v5 + 52);
  v7 = 0;
  v8 = KeAbPreAcquire(v5 + 52, 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v6);
  while ( __strex(v10 | 1, v6) );
  __dmb(0xBu);
  if ( (v10 & 1) != 0 )
    v8 = ExfAcquirePushLockExclusiveEx((_DWORD *)(v5 + 52), v8, v5 + 52);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  v11 = a1[15] & a2;
  if ( v11 )
  {
    v14 = a1[18];
    if ( v14 )
    {
      if ( v14 != 3 )
      {
LABEL_19:
        if ( (a1[20] & 1) == 0 && (a1[19] & 1) == 0 && (v11 & 1) != 0 )
        {
          v17 = a1[7];
          __dmb(0xBu);
          v18 = (unsigned int *)(v17 + 92);
          do
            v19 = __ldrex(v18);
          while ( __strex(v19 + 1, v18) );
          __dmb(0xBu);
        }
        a1[19] = a1[15] & (a1[19] | v11);
        __dmb(0xBu);
        do
          v20 = __ldrex((unsigned int *)v6);
        while ( __strex(v20 - 1, (unsigned int *)v6) );
        if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)(v5 + 52));
        KeAbPostRelease(v5 + 52);
        return v7;
      }
    }
    else
    {
      v15 = *(_DWORD **)(v5 + 60);
      v16 = a1 + 16;
      a1[16] = v5 + 56;
      a1[17] = v15;
      if ( *v15 != v5 + 56 )
        __fastfail(3u);
      *v15 = v16;
      *(_DWORD *)(v5 + 60) = v16;
    }
    v7 = 1;
    a1[18] = 1;
    goto LABEL_19;
  }
  __dmb(0xBu);
  do
    v12 = __ldrex((unsigned int *)v6);
  while ( __strex(v12 - 1, (unsigned int *)v6) );
  if ( (v12 & 2) == 0 )
  {
    KeAbPostRelease(v5 + 52);
    return 0;
  }
  return sub_7C4338(v8);
}
