// ExAcquireResourceExclusiveLite 
 
int __fastcall ExAcquireResourceExclusiveLite(int a1, int a2, int a3, int a4)
{
  unsigned int v7; // r3
  unsigned int *v8; // r7
  int v9; // r10
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  int v13; // r1
  __int64 v14; // r1
  int v15; // r5
  unsigned int v16; // r3
  unsigned int v17; // r3
  unsigned int v18; // r0
  unsigned int v19; // r3
  unsigned int v20; // r2
  int v21; // [sp+0h] [bp-28h] BYREF
  int v22; // [sp+4h] [bp-24h]
  int v23; // [sp+8h] [bp-20h]

  v21 = a2;
  v22 = a3;
  v23 = a4;
  if ( (dword_682604 & 0x20000) != 0 )
    return sub_50C614();
  v7 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v7 & 0xFFFFF000) + 0x1438);
  v8 = (unsigned int *)(a1 + 52);
  v21 = 0;
  v22 = a1 + 52;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __dmb(0xBu);
  v10 = KfRaiseIrql(2);
  LOBYTE(v23) = v10;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    v10 = KiAcquireQueuedSpinLockInstrumented(&v21, a1 + 52);
  }
  else
  {
    do
      v11 = __ldrex(v8);
    while ( __strex((unsigned int)&v21, v8) );
    __dmb(0xBu);
    if ( v11 )
      v10 = KxWaitForLockOwnerShip(&v21);
  }
  if ( *(_DWORD *)(a1 + 32) )
  {
    while ( 1 )
    {
      if ( (*(_WORD *)(a1 + 14) & 0x80) != 0 && *(_DWORD *)(a1 + 24) == v9 )
      {
        v15 = 1;
        *(_DWORD *)(a1 + 28) = ((*(_DWORD *)(a1 + 28) & 0xFFFFFFFC) + 4) ^ *(_DWORD *)(a1 + 28) & 3;
        v17 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v17 & 0xFFFFF000) + 0x1440);
        ++*(_DWORD *)((v17 & 0xFFFFF000) + 0x1424);
        goto LABEL_9;
      }
      if ( !a2 )
        break;
      if ( *(_DWORD *)(a1 + 20) )
      {
        ++*(_DWORD *)(a1 + 44);
        ExpUnlockResource(v10, &v21);
        v18 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        ++*(_DWORD *)(v18 + 3780);
        ExpWaitForResource(a1, *(_DWORD *)(a1 + 20));
        *(_DWORD *)(a1 + 24) = v9;
        ExpBoostIoAfterAcquire(a1, v9);
        v19 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x143C);
        ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x1424);
        return 1;
      }
      v10 = ExpAllocateExclusiveWaiterEvent(a1, &v21);
      if ( !*(_DWORD *)(a1 + 32) )
        goto LABEL_8;
    }
    v15 = 0;
    v20 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    ++*(_DWORD *)(v20 + 3784);
  }
  else
  {
LABEL_8:
    v12 = *(_WORD *)(a1 + 14);
    v13 = *(_DWORD *)(a1 + 28);
    *(_DWORD *)(a1 + 24) = v9;
    *(_WORD *)(a1 + 14) = v12 | 0x80;
    LODWORD(v14) = v13 & 3 | 4;
    HIDWORD(v14) = 1;
    *(_QWORD *)(a1 + 28) = v14;
    *(_WORD *)(a1 + 12) = 1;
    v15 = 1;
    v16 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v16 & 0xFFFFF000) + 0x143C);
    ++*(_DWORD *)((v16 & 0xFFFFF000) + 0x1424);
  }
LABEL_9:
  KeReleaseInStackQueuedSpinLock(&v21);
  return v15;
}
