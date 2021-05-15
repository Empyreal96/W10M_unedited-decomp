// MiDbgUnTranslatePhysicalAddress 
 
int __fastcall MiDbgUnTranslatePhysicalAddress(int a1)
{
  unsigned int *v2; // r0
  int v3; // r2
  int result; // r0
  unsigned int v5; // r3
  int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r0
  int *v9; // r5
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int *v13; // r2
  unsigned int v14; // r0
  int v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int *v18; // r2
  unsigned int v19; // r0

  if ( (*(_DWORD *)a1 & 0x20) != 0 )
  {
    v2 = (unsigned int *)dword_634584;
    __dmb(0xBu);
    do
      v3 = __ldrex(v2);
    while ( __strex(0, v2) );
    __dmb(0xBu);
    if ( (*(_DWORD *)a1 & 0x12) != 0 )
      return sub_555970();
    KeFlushSingleCurrentTb((_DWORD)v2 << 10, 0, v3, *(_DWORD *)a1);
  }
  v5 = *(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 4) != 0 )
    goto LABEL_12;
  if ( (v5 & 1) != 0 )
  {
    __dmb(0xBu);
    v6 = *(_DWORD *)(a1 + 8);
    goto LABEL_10;
  }
  if ( (v5 & 2) != 0 )
  {
    v6 = *(_DWORD *)(a1 + 8);
    __dmb(0xBu);
LABEL_10:
    v7 = (unsigned int *)(v6 + 12);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 & 0x7FFFFFFF, v7) );
    goto LABEL_12;
  }
  if ( (v5 & 8) == 0 )
  {
    if ( (v5 & 0x10) == 0 )
      goto LABEL_12;
    v9 = (int *)(a1 + 12);
    if ( (dword_682604 & 0x10000) == 0 )
    {
      v15 = *v9;
      if ( !*v9 )
      {
        v16 = *(unsigned int **)(a1 + 16);
        __dmb(0xBu);
        do
          v17 = __ldrex(v16);
        while ( (int *)v17 == v9 && __strex(0, v16) );
        if ( (int *)v17 == v9 )
          goto LABEL_12;
        v15 = KxWaitForLockChainValid((int *)(a1 + 12));
      }
      *v9 = 0;
      __dmb(0xBu);
      v18 = (unsigned int *)(v15 + 4);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 ^ 1, v18) );
      goto LABEL_12;
    }
LABEL_38:
    KiReleaseQueuedSpinLockInstrumented(v9);
    goto LABEL_12;
  }
  v9 = (int *)(a1 + 12);
  if ( (dword_682604 & 0x10000) != 0 )
    goto LABEL_38;
  v10 = *v9;
  if ( !*v9 )
  {
    v11 = *(unsigned int **)(a1 + 16);
    __dmb(0xBu);
    do
      v12 = __ldrex(v11);
    while ( (int *)v12 == v9 && __strex(0, v11) );
    if ( (int *)v12 == v9 )
      goto LABEL_12;
    v10 = KxWaitForLockChainValid((int *)(a1 + 12));
  }
  *v9 = 0;
  __dmb(0xBu);
  v13 = (unsigned int *)(v10 + 4);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 ^ 1, v13) );
LABEL_12:
  result = *(unsigned __int8 *)(a1 + 4);
  if ( result != 17 )
    result = KfLowerIrql(result);
  return result;
}
