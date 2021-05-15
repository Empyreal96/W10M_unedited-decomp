// CmpTransMgrCommit 
 
int __fastcall CmpTransMgrCommit(int a1, int a2, _DWORD *a3)
{
  char v4; // r3
  int v5; // r5
  int v8; // r0
  int v9; // r4
  int i; // r0
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  unsigned int v14; // r7
  int v15; // r0
  int v16; // r6
  unsigned int v17; // r2
  unsigned int v18; // r1
  int v19; // r0
  unsigned int v20; // r1
  __int16 v21; // r3
  int v23; // [sp+0h] [bp-30h] BYREF
  int v24[10]; // [sp+8h] [bp-28h] BYREF

  v23 = 0;
  *a3 = 0;
  v4 = dword_64B084;
  v5 = 0;
  if ( dword_64B084 )
  {
    ++dword_64B084;
    if ( (v4 & 3) != 0 )
      return -1073741670;
  }
  if ( *(_DWORD *)(a2 + 8) == a2 + 8 )
    return 0;
  KeQuerySystemTime(v24);
  while ( 1 )
  {
    v8 = CmListGetNextElement(a2 + 8, &v23, 0);
    v9 = v8;
    if ( !v8 )
      break;
    if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v8 + 24) + 20) + 3256) == a1 && (*(_DWORD *)(v8 + 32) & 1) == 0 )
    {
      ++*a3;
      if ( v5 >= 0 )
      {
        v5 = CmpTransMgrCommitUoW(v8);
        if ( v5 >= 0 )
          *(_DWORD *)(v9 + 32) |= 1u;
      }
    }
  }
  if ( v5 >= 0 )
  {
    CmpLockRegistry();
    for ( i = 0; ; i = v12 )
    {
      v11 = CmpGetNextActiveHive(i);
      v12 = v11;
      if ( !v11 )
        break;
      if ( *(_DWORD *)(v11 + 3256) == a1 && (*(_DWORD *)(v11 + 92) & 2) == 0 && CmpIsHiveBoundToTrans(v11, a2) == 1 )
      {
        CmpUnlockRegistry();
        if ( CmpTransMgrSyncHive(v12) < 0 )
          v5 = -1073741670;
        CmpLockRegistry();
      }
    }
    CmpUnlockRegistry();
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v13 + 308);
    v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v15 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
    v16 = v15;
    do
      v17 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
    while ( __strex(v17 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
    __dmb(0xBu);
    if ( (v17 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v15);
    if ( v16 )
      *(_BYTE *)(v16 + 14) |= 1u;
    dword_632184 = v14;
    *(_DWORD *)(a2 + 64) |= 4u;
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v18 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v18 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v18 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v18);
    v19 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v20 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v21 = *(_WORD *)(v20 + 0x134) + 1;
    *(_WORD *)(v20 + 308) = v21;
    if ( !v21 && *(_DWORD *)(v20 + 100) != v20 + 100 && !*(_WORD *)(v20 + 310) )
      KiCheckForKernelApcDelivery(v19);
  }
  return v5;
}
