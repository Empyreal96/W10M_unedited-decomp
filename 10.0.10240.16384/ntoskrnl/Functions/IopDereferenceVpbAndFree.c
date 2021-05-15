// IopDereferenceVpbAndFree 
 
int __fastcall IopDereferenceVpbAndFree(int a1)
{
  int v2; // r7
  int v3; // r8
  int v4; // r3
  unsigned int v5; // r0
  unsigned int *v6; // r5
  int result; // r0
  unsigned int v8; // r1
  int v9; // r3
  int *v10; // r4
  int v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int *v14; // r2
  unsigned int v15; // r4

  v2 = 0;
  v3 = KfRaiseIrql(2);
  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
  v5 = v4 + 72;
  v6 = *(unsigned int **)(v4 + 76);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52C798();
  do
    v8 = __ldrex(v6);
  while ( __strex(v5, v6) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForLockOwnerShip(v5);
  v9 = *(_DWORD *)(a1 + 20) - 1;
  *(_DWORD *)(a1 + 20) = v9;
  if ( !v9 && *(_DWORD *)(*(_DWORD *)(a1 + 12) + 36) != a1 && (*(_WORD *)(a1 + 4) & 4) == 0 )
    v2 = a1;
  v10 = (int *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 72);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v10);
  }
  else
  {
    v11 = *v10;
    if ( !*v10 )
    {
      v12 = (unsigned int *)v10[1];
      __dmb(0xBu);
      do
        v13 = __ldrex(v12);
      while ( (int *)v13 == v10 && __strex(0, v12) );
      if ( (int *)v13 == v10 )
        goto LABEL_13;
      v11 = KxWaitForLockChainValid(v10);
    }
    *v10 = 0;
    __dmb(0xBu);
    v14 = (unsigned int *)(v11 + 4);
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 ^ 1, v14) );
  }
LABEL_13:
  result = KfLowerIrql(v3);
  if ( v2 )
    result = ExFreePoolWithTag(v2, 0);
  return result;
}
