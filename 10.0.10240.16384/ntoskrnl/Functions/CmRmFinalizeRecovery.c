// CmRmFinalizeRecovery 
 
int __fastcall CmRmFinalizeRecovery(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r2
  unsigned int v6; // r7
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  __int64 **v10; // r6
  __int64 *v11; // r5
  __int64 v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  int v18; // r2
  int v19; // r3
  int v20; // r0
  int v21; // r0
  unsigned int v22; // r2
  int v23; // r0
  int v24; // r5
  unsigned int v25; // r2
  unsigned int v26; // r1
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3
  int v31[6]; // [sp+0h] [bp-18h] BYREF

  v31[0] = a4;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v9 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v9 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v7);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = (__int64 **)(a1 + 8);
  while ( 1 )
  {
    dword_632184 = v6;
    if ( *v10 == (__int64 *)v10 )
      break;
    v11 = *v10;
    v12 = **v10;
    if ( (__int64 **)HIDWORD(v12) != v10 || *(__int64 **)(v12 + 4) != v11 )
      __fastfail(3u);
    *v10 = (__int64 *)v12;
    *(_DWORD *)(v12 + 4) = v10;
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v13 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v13 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v13);
    v14 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = (__int16)(*(_WORD *)(v16 + 0x134) + 1);
    *(_WORD *)(v16 + 308) = v17;
    if ( !(_WORD)v17 )
    {
      v17 = *(_DWORD *)(v16 + 100);
      v15 = v16 + 100;
      if ( v17 != v16 + 100 )
      {
        v17 = *(__int16 *)(v16 + 310);
        if ( !*(_WORD *)(v16 + 310) )
          KiCheckForKernelApcDelivery(v14);
      }
    }
    CmpTransMgrRollback((int)v11, v31, v15, v17);
    CmpTransMgrFreeVolatileData((int)v11, 8, v18, v19);
    v20 = *((_DWORD *)v11 + 6);
    if ( v20 )
      ObfDereferenceObject(v20);
    v21 = *((_DWORD *)v11 + 8);
    if ( v21 )
      ObfDereferenceObject(v21);
    if ( *((_DWORD *)v11 + 9) )
      ZwClose();
    ExFreePoolWithTag((unsigned int)v11);
    v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v22 + 308);
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v23 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
    v24 = v23;
    do
      v25 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
    while ( __strex(v25 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
    __dmb(0xBu);
    if ( (v25 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v23);
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v26 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v26 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v26 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v26);
  v27 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = *(_WORD *)(v28 + 0x134) + 1;
  *(_WORD *)(v28 + 308) = v29;
  if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
    KiCheckForKernelApcDelivery(v27);
  return 0;
}
