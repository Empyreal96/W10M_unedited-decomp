// IopCheckDeviceAndDriver 
 
int __fastcall IopCheckDeviceAndDriver(int a1, _DWORD *a2)
{
  int v4; // r7
  int v5; // r3
  unsigned int v6; // r0
  unsigned int *v7; // r5
  unsigned int v9; // r1
  int v10; // r3
  int v11; // r3
  int v12; // r5
  int *v13; // r4
  int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  unsigned int *v17; // r2
  unsigned int v18; // r4
  int v19; // r0

  v4 = KfRaiseIrql(2);
  v5 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14);
  v6 = v5 + 80;
  v7 = *(unsigned int **)(v5 + 84);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52C948();
  do
    v9 = __ldrex(v7);
  while ( __strex(v6, v7) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForLockOwnerShip(v6);
  if ( (*(_DWORD *)(a2[44] + 16) & 0x1F) != 0 || (v10 = a2[7], (v10 & 0x80) != 0) )
  {
    v12 = -1073741810;
  }
  else if ( (v10 & 8) == 0 || !a2[1] || *(_DWORD *)(a1 + 20) || (*(_DWORD *)(a1 + 56) & 0x400) != 0 )
  {
    v11 = a2[1] + 1;
    a2[1] = v11;
    if ( v11 <= 0 )
    {
      v19 = a2[2];
      if ( v19 )
      {
        IoAddTriageDumpDataBlock(v19, 168);
        IoAddTriageDumpDataBlock(*(_DWORD *)(a2[2] + 32), *(unsigned __int16 *)(a2[2] + 28));
      }
      KeBugCheckEx(24, 0, a2);
    }
    v12 = 0;
  }
  else
  {
    v12 = -1073741790;
  }
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
        goto LABEL_17;
      v14 = KxWaitForLockChainValid(v13);
    }
    *v13 = 0;
    __dmb(0xBu);
    v17 = (unsigned int *)(v14 + 4);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 ^ 1, v17) );
  }
LABEL_17:
  KfLowerIrql(v4);
  return v12;
}
