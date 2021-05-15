// IopCheckVpbMounted 
 
int __fastcall IopCheckVpbMounted(int a1, int a2, _WORD *a3, int *a4)
{
  int v7; // r8
  unsigned int v8; // r4
  unsigned int v9; // r0
  unsigned int *v10; // r5
  unsigned int v12; // r1
  int v13; // r5
  int v14; // r3
  int *v15; // r4
  int v16; // r0
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r4
  BOOL v21; // r2
  BOOL v22; // r1
  int v23; // r0
  int *v24; // r5
  int v25; // r0
  int v26; // r0
  int v27; // [sp+8h] [bp-28h] BYREF
  int *v28; // [sp+Ch] [bp-24h]

  v28 = a4;
  v7 = KfRaiseIrql(2);
  v8 = (unsigned int)KeGetPcr();
  v9 = *(_DWORD *)((v8 & 0xFFFFF000) + 0x14) + 72;
  v10 = *(unsigned int **)(*(_DWORD *)((v8 & 0xFFFFF000) + 0x14) + 76);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52C7E0();
  do
    v12 = __ldrex(v10);
  while ( __strex(v9, v10) );
  __dmb(0xBu);
  if ( v12 )
    KxWaitForLockOwnerShip(v9);
  if ( (*(_WORD *)(*(_DWORD *)(a2 + 36) + 4) & 1) == 0 )
  {
    while ( 1 )
    {
      KeReleaseQueuedSpinLock(9, v7);
      v21 = (*(_DWORD *)(a1 + 40) & 0x10) != 0;
      v27 = 0;
      v22 = !*a3 && !*(_DWORD *)(a1 + 20);
      v23 = IopMountVolume(a2, v22, 0, v21, &v27);
      v24 = v28;
      *v28 = v23;
      if ( v23 < 0 || v23 == 192 || v23 == 257 )
        break;
      v13 = v27;
      if ( v27 )
        return v13;
      v7 = KeAcquireQueuedSpinLock(9);
      if ( (*(_WORD *)(*(_DWORD *)(a2 + 36) + 4) & 1) != 0 )
        goto LABEL_7;
    }
    IopDecrementDeviceObjectRef(a2, 0, 0);
    if ( *v24 >= 0 )
      *v24 = -1073741806;
    return 0;
  }
LABEL_7:
  v13 = *(_DWORD *)(a2 + 36);
  if ( (*(_WORD *)(v13 + 4) & 2) != 0 )
  {
    v13 = 0;
    *v28 = -1073741790;
  }
  else
  {
    v14 = *(_DWORD *)(v13 + 20) + 1;
    *(_DWORD *)(v13 + 20) = v14;
    if ( v14 <= 0 )
    {
      v25 = *(_DWORD *)(v13 + 8);
      if ( v25 )
      {
        IoAddTriageDumpDataBlock(v25, 184);
        v26 = *(_DWORD *)(*(_DWORD *)(v13 + 8) + 8);
        if ( v26 )
        {
          IoAddTriageDumpDataBlock(v26, 168);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v13 + 8) + 8) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v13 + 8) + 8) + 28));
        }
      }
      KeBugCheckEx(24, 0, v13);
    }
  }
  v15 = (int *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x14) + 72);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(v15);
  }
  else
  {
    v16 = *v15;
    if ( !*v15 )
    {
      v17 = (unsigned int *)v15[1];
      __dmb(0xBu);
      do
        v18 = __ldrex(v17);
      while ( (int *)v18 == v15 && __strex(0, v17) );
      if ( (int *)v18 == v15 )
        goto LABEL_15;
      v16 = KxWaitForLockChainValid(v15);
    }
    *v15 = 0;
    __dmb(0xBu);
    v19 = (unsigned int *)(v16 + 4);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 ^ 1, v19) );
  }
LABEL_15:
  KfLowerIrql(v7);
  if ( !v13 )
    IopDecrementDeviceObjectRef(a2, 0, 0);
  return v13;
}
