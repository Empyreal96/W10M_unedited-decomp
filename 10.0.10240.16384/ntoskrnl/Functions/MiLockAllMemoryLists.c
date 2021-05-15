// MiLockAllMemoryLists 
 
unsigned int *__fastcall MiLockAllMemoryLists(unsigned int a1)
{
  unsigned int v1; // r6
  int v2; // r4
  __int16 *v3; // r5
  int v4; // r3
  int v5; // r7
  unsigned int v6; // r9
  _DWORD *v7; // r8
  unsigned int *v8; // r10
  int v9; // r3
  int v10; // r4
  unsigned int *v11; // r7
  _DWORD *v12; // r8
  int v13; // r10
  int v14; // r5
  _DWORD *v15; // r7
  unsigned int *v16; // r4
  int v17; // r8
  int v18; // r5
  unsigned int v19; // r8
  _DWORD *v20; // r7
  unsigned int *v21; // r4

  v1 = a1;
  KeAcquireInStackQueuedSpinLock(&dword_640090, a1);
  v2 = 1;
  v3 = MiSystemPartition;
  v4 = dword_633818;
  v5 = 2;
  do
  {
    v6 = 0;
    if ( v4 )
    {
      v7 = (_DWORD *)(v1 + 12 * v2);
      v8 = (unsigned int *)(*((_DWORD *)v3 + 256) + 16);
      do
      {
        KeAcquireInStackQueuedSpinLockAtDpcLevel(v8, v7);
        v4 = dword_633818;
        ++v6;
        ++v2;
        v7 += 3;
        v8 += 5;
      }
      while ( v6 < dword_633818 );
      v1 = a1;
    }
    v3 += 2;
    --v5;
  }
  while ( v5 );
  v9 = 3 * v2;
  v10 = v2 + 8;
  v11 = (unsigned int *)&unk_63FD10;
  v12 = (_DWORD *)(v1 + 4 * v9);
  v13 = 8;
  v14 = v10 + 1;
  do
  {
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v11, v12);
    v11 += 5;
    --v13;
    v12 += 3;
  }
  while ( v13 );
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)algn_640690, (_DWORD *)(v1 + 12 * v10));
  v15 = (_DWORD *)(v1 + 12 * v14);
  v16 = (unsigned int *)&unk_63FF10;
  v17 = 16;
  v18 = v14 + 16;
  do
  {
    KeAcquireInStackQueuedSpinLockAtDpcLevel(v16, v15);
    v16 += 5;
    v15 += 3;
    --v17;
  }
  while ( v17 );
  v19 = 0;
  if ( KeNumberNodes )
  {
    v20 = (_DWORD *)(v1 + 12 * v18);
    v21 = (unsigned int *)(dword_63F718 + 100);
    do
    {
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v21, v20);
      ++v19;
      ++v18;
      v20 += 3;
      v21 += 26;
    }
    while ( v19 < (unsigned __int16)KeNumberNodes );
  }
  return KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640710, (_DWORD *)(v1 + 12 * v18));
}
