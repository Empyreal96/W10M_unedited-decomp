// CmpRunDownCmRM 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpRunDownCmRM(int result, int a2, int *a3, int a4)
{
  int *v4; // r4
  unsigned int v6; // r2
  unsigned int v7; // r7
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  int *v11; // r0
  int *v12; // r2
  int *v13; // r3
  int *v14; // r1
  __int64 v15; // kr00_8
  int **v16; // r7
  unsigned int v17; // r1
  int v18; // r0
  unsigned int v19; // r1
  __int16 v20; // r3
  int *v21; // r1
  __int64 v22; // kr08_8
  unsigned int v23; // r2
  unsigned int v24; // r7
  int v25; // r0
  int v26; // r6
  unsigned int v27; // r2
  int *v28; // r1 OVERLAPPED
  int **v29; // r2 OVERLAPPED
  int v30; // r3
  unsigned int v31; // r1
  int v32; // r0
  unsigned int v33; // r1
  __int16 v34; // r3
  int v35; // r0
  int *v36; // [sp+0h] [bp-20h] BYREF
  int **v37; // [sp+4h] [bp-1Ch]

  v36 = a3;
  v37 = (int **)a4;
  v4 = (int *)result;
  if ( result && !*(_DWORD *)(result + 32) )
  {
    v37 = &v36;
    v36 = (int *)&v36;
    v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v6 + 308);
    v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v8 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
    while ( __strex(v10 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
    __dmb(0xBu);
    if ( (v10 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v8);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    dword_632184 = v7;
    v11 = (int *)CmpLazyCommitListHead;
    while ( v11 != &CmpLazyCommitListHead )
    {
      v12 = v11 - 4;
      v13 = (int *)v11[3];
      v11 = (int *)*v11;
      if ( v13 == v4 )
      {
        v14 = v12 + 4;
        v15 = *((_QWORD *)v12 + 2);
        if ( *(int **)(v15 + 4) != v12 + 4 || *(int **)HIDWORD(v15) != v14 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v15) = v15;
        *(_DWORD *)(v15 + 4) = HIDWORD(v15);
        v16 = v37;
        *v14 = (int)&v36;
        v12[5] = (int)v16;
        if ( *v16 != (int *)&v36 )
          __fastfail(3u);
        *v16 = v14;
        v37 = (int **)(v12 + 4);
      }
    }
    dword_632184 = 0;
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&CmpTransactionListLock);
    while ( !v17 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
    if ( v17 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v17);
    v18 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(_WORD *)(v19 + 0x134) + 1;
    *(_WORD *)(v19 + 308) = v20;
    if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
      KiCheckForKernelApcDelivery(v18);
    while ( 1 )
    {
      v21 = v36;
      v22 = *(_QWORD *)v36;
      if ( (int **)v36[1] != &v36 || *(int **)(v22 + 4) != v36 )
        __fastfail(3u);
      v36 = (int *)*v36;
      *(_DWORD *)(v22 + 4) = &v36;
      if ( v21 == (int *)&v36 )
        break;
      CmpCleanupTransactionState((int)v4, v21 - 4, 4, 0);
    }
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v23 + 308);
    v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v25 = KeAbPreAcquire((unsigned int)&CmpRmListLock, 0, 0);
    v26 = v25;
    do
      v27 = __ldrex((unsigned __int8 *)&CmpRmListLock);
    while ( __strex(v27 & 0xFE, (unsigned __int8 *)&CmpRmListLock) );
    __dmb(0xBu);
    if ( (v27 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&CmpRmListLock, v25);
    if ( v26 )
      *(_BYTE *)(v26 + 14) |= 1u;
    dword_631FA4 = v24;
    v4[15] |= 8u;
    *(_QWORD *)&v28 = *(_QWORD *)v4;
    if ( *(int **)(*v4 + 4) != v4 || *v29 != v4 )
      __fastfail(3u);
    *v29 = v28;
    v28[1] = (int)v29;
    v30 = v4[12];
    if ( v30 )
    {
      *(_DWORD *)(v30 + 3256) = 0;
      v4[12] = 0;
    }
    dword_631FA4 = 0;
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)&CmpRmListLock);
    while ( !v31 && __strex(1u, (unsigned int *)&CmpRmListLock) );
    if ( v31 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpRmListLock, v31);
    v32 = KeAbPostRelease((unsigned int)&CmpRmListLock);
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = *(_WORD *)(v33 + 0x134) + 1;
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(v32);
    v35 = v4[7];
    if ( v35 )
    {
      ObDereferenceObjectDeferDelete(v35);
      v4[7] = 0;
    }
    result = v4[5];
    if ( result )
    {
      result = ObDereferenceObjectDeferDelete(result);
      v4[5] = 0;
    }
    if ( a2 == 1 )
    {
      result = (int)v4;
      CmpDelayFreeCmRm(v4);
    }
  }
  return result;
}
