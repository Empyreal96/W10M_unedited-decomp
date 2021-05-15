// CmpCleanupTransactionState 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall CmpCleanupTransactionState(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int v8; // r4
  unsigned int v9; // r8
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  int v13; // r1 OVERLAPPED
  _DWORD *v14; // r2 OVERLAPPED
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r0
  int v20; // r0
  int v21; // r2
  int v22; // r3
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3

  CmpLockRegistryExclusive();
  CmpTransMgrFreeVolatileData(a2, a3);
  CmpUnlockRegistry();
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v12 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v12 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v10);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  dword_632184 = v9;
  *(_QWORD *)&v13 = *(_QWORD *)a2;
  if ( *(_DWORD **)(*a2 + 4) != a2 || (_DWORD *)*v14 != a2 )
    __fastfail(3u);
  *v14 = v13;
  *(_DWORD *)(v13 + 4) = v14;
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v15 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v15 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v15);
  v16 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  v19 = a2[6];
  a2[16] |= 0x10u;
  if ( v19 )
    ObfDereferenceObject(v19);
  v20 = a2[8];
  if ( v20 )
    ObDereferenceObjectDeferDelete(v20);
  ExFreePoolWithTag((unsigned int)a2);
  if ( a4 )
  {
    CmpLockRegistry();
    v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v22 = *(__int16 *)(v21 + 0x134) - 1;
    *(_WORD *)(v21 + 308) = v22;
    ExAcquireResourceExclusiveLite(*(_DWORD *)(a1 + 80), 1, v21, v22);
    CmpLogCheckpoint(a1);
    v23 = ExReleaseResourceLite(*(_DWORD *)(a1 + 80));
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = *(_WORD *)(v24 + 0x134) + 1;
    *(_WORD *)(v24 + 308) = v25;
    if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
      KiCheckForKernelApcDelivery(v23);
    CmpUnlockRegistry();
  }
}
