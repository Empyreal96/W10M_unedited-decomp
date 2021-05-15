// CcReferenceSharedCacheMapByVacb 
 
int __fastcall CcReferenceSharedCacheMapByVacb(int a1, int a2)
{
  int v3; // r5
  int v4; // r2
  int *v5; // r4
  int v6; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned int *v9; // r2
  unsigned int v10; // r0
  int *v11; // r4
  int v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r1
  unsigned int *v15; // r2
  unsigned int v16; // r4
  int vars4; // [sp+14h] [bp+4h]

  v3 = 0;
  KeAcquireQueuedSpinLockAtDpcLevel(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2600, a2);
  v4 = *(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(v4 + 68) & 0xFFFFFFF8) + 20) + 4) == v4 )
  {
    ++*(_DWORD *)(v4 + 4);
    v5 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2600);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v5, vars4);
    }
    else
    {
      v6 = *v5;
      if ( !*v5 )
      {
        v7 = (unsigned int *)v5[1];
        __dmb(0xBu);
        do
          v8 = __ldrex(v7);
        while ( (int *)v8 == v5 && __strex(0, v7) );
        if ( (int *)v8 == v5 )
          return 1;
        v6 = KxWaitForLockChainValid(v5);
      }
      *v5 = 0;
      __dmb(0xBu);
      v9 = (unsigned int *)(v6 + 4);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 ^ 1, v9) );
    }
    return 1;
  }
  v11 = (int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2600);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v11, vars4);
    return v3;
  }
  v12 = *v11;
  if ( *v11 )
    goto LABEL_21;
  v13 = (unsigned int *)v11[1];
  __dmb(0xBu);
  do
    v14 = __ldrex(v13);
  while ( (int *)v14 == v11 && __strex(0, v13) );
  if ( (int *)v14 != v11 )
  {
    v12 = KxWaitForLockChainValid(v11);
LABEL_21:
    *v11 = 0;
    __dmb(0xBu);
    v15 = (unsigned int *)(v12 + 4);
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 ^ 1, v15) );
  }
  return v3;
}
