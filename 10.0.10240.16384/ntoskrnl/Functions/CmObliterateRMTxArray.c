// CmObliterateRMTxArray 
 
__int64 __fastcall CmObliterateRMTxArray(int a1)
{
  unsigned int v2; // r2
  unsigned int v3; // r6
  int v4; // r0
  int v5; // r5
  unsigned int v6; // r2
  int *v7; // r0
  int *v8; // r2
  int v9; // r3
  int *v10; // r1
  __int64 v11; // kr00_8
  int **v12; // r6
  unsigned int v13; // r1
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  __int64 result; // r0
  __int64 v18; // kr08_8
  int *v19; // [sp+0h] [bp-18h] BYREF
  int **v20; // [sp+4h] [bp-14h]

  v20 = &v19;
  v19 = (int *)&v19;
  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
  __dmb(0xBu);
  if ( (v6 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v4);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  dword_632184 = v3;
  v7 = (int *)CmpLazyCommitListHead;
  while ( v7 != &CmpLazyCommitListHead )
  {
    v8 = v7 - 4;
    v9 = v7[3];
    v7 = (int *)*v7;
    if ( v9 == a1 )
    {
      v10 = v8 + 4;
      v11 = *((_QWORD *)v8 + 2);
      if ( *(int **)(v11 + 4) != v8 + 4 || *(int **)HIDWORD(v11) != v10 )
        __fastfail(3u);
      *(_DWORD *)HIDWORD(v11) = v11;
      *(_DWORD *)(v11 + 4) = HIDWORD(v11);
      v12 = v20;
      *v10 = (int)&v19;
      v8[5] = (int)v12;
      if ( *v12 != (int *)&v19 )
        __fastfail(3u);
      *v12 = v10;
      v20 = (int **)(v8 + 4);
    }
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v13 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v13 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v13);
  v14 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  while ( 1 )
  {
    HIDWORD(result) = v19;
    v18 = *(_QWORD *)v19;
    LODWORD(result) = *v19;
    if ( (int **)v19[1] != &v19 || *(int **)(v18 + 4) != v19 )
      __fastfail(3u);
    v19 = (int *)*v19;
    *(_DWORD *)(v18 + 4) = &v19;
    if ( (int **)HIDWORD(result) == &v19 )
      break;
    CmpCleanupTransactionState(a1, HIDWORD(result) - 16, 8, 0);
  }
  return result;
}
