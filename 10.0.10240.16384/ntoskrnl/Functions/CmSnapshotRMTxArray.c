// CmSnapshotRMTxArray 
 
int __fastcall CmSnapshotRMTxArray(int a1, unsigned int *a2, int *a3)
{
  unsigned int v3; // r6
  int v4; // r5
  int v5; // r9
  unsigned int v6; // r7
  unsigned int v7; // r4
  unsigned int v8; // r10
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  int *v12; // r4
  int v13; // r0
  int v14; // r0
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int *v19; // r4
  int v20; // t1
  int result; // r0
  int v23; // [sp+4h] [bp-2Ch] BYREF
  unsigned int *v24; // [sp+8h] [bp-28h]
  int *v25; // [sp+Ch] [bp-24h]

  v3 = 0;
  v4 = 0;
  v24 = a2;
  v25 = a3;
  v5 = 0;
  if ( a1 )
  {
    while ( 1 )
    {
      v23 = 0;
      v6 = 0;
      v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v7 + 308);
      v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v9 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
      v10 = v9;
      do
        v11 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
      while ( __strex(v11 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
      __dmb(0xBu);
      if ( (v11 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v9);
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      dword_632184 = v8;
      v12 = (int *)v4;
      while ( 1 )
      {
        v13 = CmListGetNextElement(a1 + 8, &v23, 0);
        if ( !v13 )
          break;
        if ( (*(_DWORD *)(v13 + 64) & 8) == 0 )
        {
          if ( v6 < v3 )
          {
            v14 = *(_DWORD *)(v13 + 32);
            *v12 = v14;
            ObfReferenceObject(v14);
          }
          ++v6;
          ++v12;
        }
      }
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
      if ( v6 <= v3 )
        break;
      if ( v4 )
      {
        if ( v3 )
        {
          v19 = (int *)v4;
          do
          {
            v20 = *v19++;
            ObfDereferenceObject(v20);
            --v3;
          }
          while ( v3 );
        }
        ExFreePoolWithTag(v4);
      }
      v3 = v6;
      v4 = ExAllocatePoolWithTag(1, 4 * v6, 909397315);
      if ( !v4 )
      {
        v5 = -1073741670;
        v3 = 0;
        goto LABEL_34;
      }
    }
    v3 = v6;
    if ( !v6 && v4 )
    {
      ExFreePoolWithTag(v4);
      v4 = 0;
    }
  }
LABEL_34:
  result = v5;
  *v24 = v3;
  *v25 = v4;
  return result;
}
