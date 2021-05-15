// IopDecrementDeviceObjectRef 
 
int __fastcall IopDecrementDeviceObjectRef(_DWORD *a1, int a2, int a3)
{
  int v6; // r6
  unsigned int v7; // r3
  unsigned int v8; // r0
  unsigned int *v9; // r7
  unsigned int v11; // r1
  int v12; // r3
  int *v13; // r4
  int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r0

  v6 = KfRaiseIrql(2);
  v7 = (unsigned int)KeGetPcr();
  v8 = *(_DWORD *)((v7 & 0xFFFFF000) + 0x14) + 80;
  v9 = *(unsigned int **)(*(_DWORD *)((v7 & 0xFFFFF000) + 0x14) + 84);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52CA58();
  do
    v11 = __ldrex(v9);
  while ( __strex(v8, v9) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForLockOwnerShip(v8);
  v12 = a1[1] - 1;
  a1[1] = v12;
  if ( v12 )
  {
    if ( v12 < 0 )
    {
      v19 = a1[2];
      if ( v19 )
      {
        IoAddTriageDumpDataBlock(v19, 168);
        IoAddTriageDumpDataBlock(*(_DWORD *)(a1[2] + 32), *(unsigned __int16 *)(a1[2] + 28));
      }
      KeBugCheckEx(24, 0, a1);
    }
LABEL_8:
    v13 = (int *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 80);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(v13);
    }
    else
    {
      v14 = *v13;
      if ( !*v13 )
      {
        v15 = (unsigned int *)v13[1];
        __dmb(0xBu);
        do
          v16 = __ldrex(v15);
        while ( (int *)v16 == v13 && __strex(0, v15) );
        if ( (int *)v16 == v13 )
          goto LABEL_14;
        v14 = KxWaitForLockChainValid(v13);
      }
      *v13 = 0;
      __dmb(0xBu);
      v17 = (unsigned int *)(v14 + 4);
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 ^ 1, v17) );
    }
LABEL_14:
    KfLowerIrql(v6);
    return 0;
  }
  if ( !a2 && (*(_DWORD *)(a1[44] + 16) & 7) == 0 )
    goto LABEL_8;
  return IopCompleteUnloadOrDelete(a1, a3, v6);
}
