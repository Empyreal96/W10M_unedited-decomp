// CmpRundownUnitOfWork 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpRundownUnitOfWork(_DWORD *a1)
{
  int v2; // r0
  int result; // r0
  unsigned int v4; // r2
  unsigned int v5; // r7
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int v9; // r1 OVERLAPPED
  _DWORD *v10; // r2 OVERLAPPED
  unsigned int v11; // r1
  unsigned int v12; // r1
  __int16 v13; // r3
  _DWORD *v14; // r2
  _DWORD *v15; // r3
  int v16; // r0
  _DWORD *v17; // r1

  v2 = a1[2];
  if ( v2 )
  {
    a1[2] = 0;
    CmpReleaseIXLock(v2, a1);
  }
  result = a1[3];
  if ( result )
  {
    a1[3] = 0;
    result = CmpReleaseIXLock(result, a1);
  }
  if ( (_DWORD *)*a1 != a1 )
  {
    v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v4 + 308);
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v6 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
    while ( __strex(v8 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v6);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    dword_632184 = v5;
    *(_QWORD *)&v9 = *(_QWORD *)a1;
    if ( *(_DWORD **)(*a1 + 4) != a1 || (_DWORD *)*v10 != a1 )
      __fastfail(3u);
    *v10 = v9;
    *(_DWORD *)(v9 + 4) = v10;
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v11 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v11 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v11);
    result = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v13 = *(_WORD *)(v12 + 0x134) + 1;
    *(_WORD *)(v12 + 308) = v13;
    if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
      result = KiCheckForKernelApcDelivery(result);
    a1[7] = 0;
  }
  v14 = a1 + 4;
  v15 = (_DWORD *)a1[4];
  if ( v15 != a1 + 4 )
  {
    v16 = a1[4];
    v17 = (_DWORD *)a1[5];
    if ( (_DWORD *)v15[1] != v14 || (_DWORD *)*v17 != v14 )
      __fastfail(3u);
    *v17 = v16;
    *(_DWORD *)(v16 + 4) = v17;
    result = CmpDereferenceKeyControlBlockWithLock(a1[6], 0);
    a1[6] = 0;
  }
  return result;
}
