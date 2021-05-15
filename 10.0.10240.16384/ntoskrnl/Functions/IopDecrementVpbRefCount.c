// IopDecrementVpbRefCount 
 
int __fastcall IopDecrementVpbRefCount(int a1, int a2)
{
  int v3; // r6
  int v4; // r3
  unsigned int v5; // r0
  unsigned int *v6; // r5
  int result; // r0
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r5
  int v11; // r3
  int *v12; // r4
  int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r4

  if ( a2 )
  {
    v3 = KfRaiseIrql(2);
    v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
    v5 = v4 + 72;
    v6 = *(unsigned int **)(v4 + 76);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_52D09C();
    do
      v8 = __ldrex(v6);
    while ( __strex(v5, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForLockOwnerShip(v5);
    v9 = *(_DWORD *)(a1 + 20);
    __dmb(0xBu);
    *(_DWORD *)(a1 + 20) = v9 - 1;
    v10 = *(_DWORD *)(a1 + 20);
    __dmb(0xBu);
    v11 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
    v12 = (int *)(v11 + 72);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v11 + 72);
    }
    else
    {
      v13 = *v12;
      if ( !*v12 )
      {
        v14 = *(unsigned int **)(v11 + 76);
        __dmb(0xBu);
        do
          v15 = __ldrex(v14);
        while ( (int *)v15 == v12 && __strex(0, v14) );
        if ( (int *)v15 == v12 )
          goto LABEL_13;
        v13 = KxWaitForLockChainValid(v12);
      }
      *v12 = 0;
      __dmb(0xBu);
      v16 = (unsigned int *)(v13 + 4);
      do
        v17 = __ldrex(v16);
      while ( __strex(v17 ^ 1, v16) );
    }
LABEL_13:
    KfLowerIrql(v3);
    return v10;
  }
  result = *(_DWORD *)(a1 + 20) - 1;
  *(_DWORD *)(a1 + 20) = result;
  return result;
}
