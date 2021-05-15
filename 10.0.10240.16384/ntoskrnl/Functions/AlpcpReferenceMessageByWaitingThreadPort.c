// AlpcpReferenceMessageByWaitingThreadPort 
 
int __fastcall AlpcpReferenceMessageByWaitingThreadPort(int a1, _DWORD *a2)
{
  unsigned int *v2; // r7
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  int v8; // r3
  unsigned __int8 *v9; // r4
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r5
  unsigned int v14; // r1
  unsigned int v15; // r1
  unsigned __int8 *v16; // r6
  int v17; // r0
  int v18; // r4
  unsigned int v19; // r2
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r5
  unsigned int v23; // r2
  unsigned int v24; // r2

  v2 = a2 + 52;
  v5 = KeAbPreAcquire((unsigned int)(a2 + 52), 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v2);
  while ( !v7 && __strex(0x11u, v2) );
  __dmb(0xBu);
  if ( v7 )
    ExfAcquirePushLockSharedEx(v2, v5, (unsigned int)v2);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = a2[61];
  if ( (v8 & 1) == 0 || (v8 & 0x40) != 0 )
  {
    v13 = 0;
    goto LABEL_51;
  }
  v9 = (unsigned __int8 *)(a2 + 23);
  v10 = KeAbPreAcquire((unsigned int)(a2 + 23), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( __strex(v12 | 1, v9) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(a2 + 23, v10, (unsigned int)(a2 + 23));
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = AlpcpReferenceMessageByWaitingThreadPortQueue(a1, a2 + 24);
  if ( v13 )
  {
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned int *)v9);
    while ( __strex(v14 - 1, (unsigned int *)v9) );
LABEL_19:
    if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v9);
    KeAbPostRelease((unsigned int)v9);
    goto LABEL_51;
  }
  v13 = AlpcpReferenceMessageByWaitingThreadPortQueue(a1, a2 + 26);
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)v9);
  while ( __strex(v15 - 1, (unsigned int *)v9) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock(a2 + 23);
  KeAbPostRelease((unsigned int)(a2 + 23));
  if ( !v13 )
  {
    v16 = (unsigned __int8 *)(a2 + 28);
    v17 = KeAbPreAcquire((unsigned int)(a2 + 28), 0, 0);
    v18 = v17;
    do
      v19 = __ldrex(v16);
    while ( __strex(v19 | 1, v16) );
    __dmb(0xBu);
    if ( (v19 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(a2 + 28, v17, (unsigned int)(a2 + 28));
    if ( v18 )
      *(_BYTE *)(v18 + 14) |= 1u;
    v13 = AlpcpReferenceMessageByWaitingThreadPortQueue(a1, a2 + 29);
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)v16);
    while ( __strex(v20 - 1, (unsigned int *)v16) );
    if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
      ExfTryToWakePushLock(a2 + 28);
    KeAbPostRelease((unsigned int)(a2 + 28));
    if ( !v13 )
    {
      v9 = (unsigned __int8 *)(a2 + 31);
      v21 = KeAbPreAcquire((unsigned int)(a2 + 31), 0, 0);
      v22 = v21;
      do
        v23 = __ldrex(v9);
      while ( __strex(v23 | 1, v9) );
      __dmb(0xBu);
      if ( (v23 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(a2 + 31, v21, (unsigned int)(a2 + 31));
      if ( v22 )
        *(_BYTE *)(v22 + 14) |= 1u;
      v13 = AlpcpReferenceMessageByWaitingThreadPortQueue(a1, a2 + 32);
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)v9);
      while ( __strex(v14 - 1, (unsigned int *)v9) );
      goto LABEL_19;
    }
  }
LABEL_51:
  __dmb(0xBu);
  do
    v24 = __ldrex(v2);
  while ( v24 == 17 && __strex(0, v2) );
  if ( v24 != 17 )
    ExfReleasePushLockShared(v2);
  KeAbPostRelease((unsigned int)v2);
  return v13;
}
