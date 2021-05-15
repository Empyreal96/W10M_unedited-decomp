// IopIncrementDeviceObjectRefCount 
 
int __fastcall IopIncrementDeviceObjectRefCount(int a1, int a2)
{
  int v3; // r7
  int v4; // r3
  unsigned int v5; // r0
  unsigned int *v6; // r4
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r5
  int v11; // r3
  int *v12; // r4
  int v13; // r0
  unsigned int *v14; // r2
  unsigned int v15; // r1
  unsigned int *v16; // r2
  unsigned int v17; // r0
  int v18; // r0

  if ( !a2 )
  {
    v10 = *(_DWORD *)(a1 + 4) + 1;
    *(_DWORD *)(a1 + 4) = v10;
    goto LABEL_14;
  }
  v3 = KfRaiseIrql(2);
  v4 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
  v5 = v4 + 80;
  v6 = *(unsigned int **)(v4 + 84);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52D060();
  do
    v8 = __ldrex(v6);
  while ( __strex(v5, v6) );
  __dmb(0xBu);
  if ( v8 )
    KxWaitForLockOwnerShip(v5);
  v9 = *(_DWORD *)(a1 + 4);
  __dmb(0xBu);
  *(_DWORD *)(a1 + 4) = v9 + 1;
  v10 = *(_DWORD *)(a1 + 4);
  __dmb(0xBu);
  v11 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
  v12 = (int *)(v11 + 80);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v11 + 80);
  }
  else
  {
    v13 = *v12;
    if ( !*v12 )
    {
      v14 = *(unsigned int **)(v11 + 84);
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
LABEL_14:
  if ( v10 <= 0 )
  {
    v18 = *(_DWORD *)(a1 + 8);
    if ( v18 )
    {
      IoAddTriageDumpDataBlock(v18, 168);
      IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
    }
    KeBugCheckEx(24, 0, a1);
  }
  return v10;
}
