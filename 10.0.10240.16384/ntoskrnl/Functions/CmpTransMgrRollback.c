// CmpTransMgrRollback 
 
int __fastcall CmpTransMgrRollback(int a1, _DWORD *a2, int a3, int a4)
{
  unsigned int v6; // r2
  unsigned int v7; // r8
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r2
  _DWORD *v11; // r0
  int v12; // r2
  int v13; // r3
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v19[8]; // [sp+0h] [bp-20h] BYREF

  v19[1] = a4;
  v19[0] = 0;
  *a2 = 0;
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
  *(_DWORD *)(a1 + 64) |= 2u;
  while ( 1 )
  {
    v11 = (_DWORD *)CmListGetNextElement(a1 + 8, v19, 0);
    if ( !v11 )
      break;
    v12 = v11[8];
    if ( (v12 & 1) == 0 )
    {
      ++*a2;
      v13 = v11[9];
      if ( v13 )
      {
        if ( v13 == 12 && !v11[13] )
          v11[13] = *(_DWORD *)(v11[6] + 24);
      }
      else if ( !v11[12] )
      {
        v11[12] = *(_DWORD *)(v11[6] + 24);
      }
      v11[8] = v12 | 1;
    }
  }
  dword_632184 = 0;
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&CmpTransactionListLock);
  while ( !v14 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
  if ( v14 )
    ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v14);
  v15 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  return 0;
}
