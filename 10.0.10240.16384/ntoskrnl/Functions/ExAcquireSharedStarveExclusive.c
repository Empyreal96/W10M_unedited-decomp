// ExAcquireSharedStarveExclusive 
 
int __fastcall ExAcquireSharedStarveExclusive(int a1, int a2)
{
  unsigned int v5; // r3
  unsigned int *v6; // r7
  int v7; // r9
  _DWORD *v8; // r1
  int v9; // r3
  int v10; // r0
  unsigned int *v11; // r1
  int *v12; // r0
  unsigned int v13; // r3
  int *v14; // r0
  unsigned int v15; // r3
  int v16; // r3
  int v17; // r3
  int v18; // r3
  unsigned int v19; // r3
  _DWORD *v20; // r0
  int v21; // r3
  int v22; // r0
  unsigned int v23; // r0
  unsigned int v24; // r3
  unsigned int v25; // r2
  unsigned int v26; // r3
  unsigned int *v27; // r2
  unsigned int v28; // r0
  int v29; // [sp+8h] [bp-40h] BYREF
  unsigned int *v30; // [sp+Ch] [bp-3Ch]
  unsigned __int8 v31; // [sp+10h] [bp-38h]
  int var30[13]; // [sp+18h] [bp-30h] BYREF

  if ( (dword_682604 & 0x20000) != 0 )
    return sub_54A518();
  v5 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v5 & 0xFFFFF000) + 0x1464);
  v6 = (unsigned int *)(a1 + 52);
  v29 = 0;
  v30 = (unsigned int *)(a1 + 52);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __dmb(0xBu);
  v31 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented(&v29, a1 + 52);
  }
  else
  {
    do
      v8 = (_DWORD *)__ldrex(v6);
    while ( __strex((unsigned int)&v29, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForLockOwnerShip((int)&v29, v8);
  }
  do
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)(a1 + 32) )
      {
        v9 = *(_DWORD *)(a1 + 28);
        *(_DWORD *)(a1 + 24) = v7;
        *(_DWORD *)(a1 + 28) = v9 & 3 | 4;
        *(_DWORD *)(a1 + 32) = 1;
        *(_WORD *)(a1 + 12) = 1;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(&v29);
        }
        else
        {
          v10 = v29;
          if ( !v29 )
          {
            v11 = v30;
            __dmb(0xBu);
            do
              v12 = (int *)__ldrex(v11);
            while ( v12 == &v29 && __strex(0, v11) );
            if ( v12 == &v29 )
              goto LABEL_14;
            v10 = KxWaitForLockChainValid(&v29);
          }
          v29 = 0;
          __dmb(0xBu);
          v27 = (unsigned int *)(v10 + 4);
          do
            v28 = __ldrex(v27);
          while ( __strex(v28 ^ 1, v27) );
        }
LABEL_14:
        KfLowerIrql(v31);
        v13 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v13 & 0xFFFFF000) + 0x146C);
        ++*(_DWORD *)((v13 & 0xFFFFF000) + 0x1424);
        return 1;
      }
      if ( (*(_WORD *)(a1 + 14) & 0x80) != 0 )
        break;
      v14 = (int *)ExpFindCurrentThread(a1, v7, &v29, 1, 0);
      if ( v14 )
      {
        if ( *v14 == v7 )
        {
          v14[1] = ((v14[1] & 0xFFFFFFFC) + 4) ^ v14[1] & 3;
          KeReleaseInStackQueuedSpinLock((int)&v29);
          v15 = (unsigned int)KeGetPcr();
          ++*(_DWORD *)((v15 & 0xFFFFF000) + 0x1470);
          ++*(_DWORD *)((v15 & 0xFFFFF000) + 0x1424);
        }
        else
        {
          v16 = v14[1];
          *v14 = v7;
          v14[1] = v16 & 3 | 4;
          v17 = *(_DWORD *)(a1 + 32);
          if ( v17 )
          {
            v18 = v17 + 1;
          }
          else
          {
            v18 = 1;
            *(_WORD *)(a1 + 12) = 1;
          }
          *(_DWORD *)(a1 + 32) = v18;
          KeReleaseInStackQueuedSpinLock((int)&v29);
          v19 = (unsigned int)KeGetPcr();
          ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x146C);
          ++*(_DWORD *)((v19 & 0xFFFFF000) + 0x1424);
        }
        return 1;
      }
    }
    if ( *(_DWORD *)(a1 + 24) == v7 )
    {
      *(_DWORD *)(a1 + 28) = *(_DWORD *)(a1 + 28) & 3 ^ ((*(_DWORD *)(a1 + 28) & 0xFFFFFFFC) + 4);
      KeReleaseInStackQueuedSpinLock((int)&v29);
      v26 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v26 & 0xFFFFF000) + 0x1468);
      ++*(_DWORD *)((v26 & 0xFFFFF000) + 0x1424);
      return 1;
    }
    v20 = ExpFindEmptyEntry(a1, (int)&v29);
  }
  while ( !v20 );
  if ( a2 )
  {
    v21 = v20[1];
    *v20 = v7;
    v20[1] = v21 & 3 | 4;
    ++*(_DWORD *)(a1 + 40);
    memset(var30, 0, 20);
    LOWORD(var30[1]) = 1;
    var30[2] = 0;
    v22 = *(_DWORD *)(a1 + 16);
    var30[4] = (int)&var30[3];
    BYTE2(var30[1]) = 4;
    *(_DWORD *)(a1 + 16) = var30;
    var30[3] = (int)&var30[3];
    var30[0] = v22;
    ExpUnlockResource(v22, &v29);
    v23 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    ++*(_DWORD *)(v23 + 3828);
    ExpWaitForResource(a1, &var30[1]);
    ExpBoostIoAfterAcquire(a1, v7);
    v24 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v24 & 0xFFFFF000) + 0x146C);
    ++*(_DWORD *)((v24 & 0xFFFFF000) + 0x1424);
    return 1;
  }
  KeReleaseInStackQueuedSpinLock((int)&v29);
  v25 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  ++*(_DWORD *)(v25 + 3832);
  return 0;
}
