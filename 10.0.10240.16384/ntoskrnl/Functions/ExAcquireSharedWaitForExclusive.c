// ExAcquireSharedWaitForExclusive 
 
int __fastcall ExAcquireSharedWaitForExclusive(int a1, int a2)
{
  unsigned int v5; // r3
  unsigned int v6; // r6
  int v7; // r3
  unsigned int v8; // r3
  unsigned int *v9; // r0
  unsigned int v10; // r3
  int v11; // r3
  unsigned int v12; // r2
  unsigned int *v13; // r0
  unsigned int v14; // r3
  _BYTE *v15; // r0
  unsigned int v16; // r2
  unsigned int v17; // r3
  unsigned int v18; // r3
  _BYTE *v19; // r0
  unsigned int v20; // r2
  unsigned int *v21; // r0
  int v22; // r3
  char v23[16]; // [sp+8h] [bp-38h] BYREF
  int v24[10]; // [sp+18h] [bp-28h] BYREF

  if ( (dword_682604 & 0x20000) != 0 )
    return sub_521980();
  v5 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v5 & 0xFFFFF000) + 0x147C);
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  KeAcquireInStackQueuedSpinLock(a1 + 52, v23);
  do
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)(a1 + 32) )
      {
        v7 = *(_DWORD *)(a1 + 28);
        *(_DWORD *)(a1 + 24) = v6;
        *(_DWORD *)(a1 + 28) = v7 & 3 | 4;
        goto LABEL_6;
      }
      if ( (*(_WORD *)(a1 + 14) & 0x80) != 0 )
        break;
      if ( *(_DWORD *)(a1 + 44) )
      {
        if ( !a2 )
          goto LABEL_17;
        ++*(_DWORD *)(a1 + 40);
        v19 = memset(v24, 0, 20);
        LOWORD(v24[1]) = 1;
        BYTE2(v24[1]) = 4;
        v24[2] = 0;
        v24[4] = (int)&v24[3];
        v24[3] = (int)&v24[3];
        v24[0] = *(_DWORD *)(a1 + 16);
        *(_DWORD *)(a1 + 16) = v24;
        ExpUnlockResource(v19, v23);
        v20 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
        ++*(_DWORD *)(v20 + 3852);
        ExpWaitForResource(a1, &v24[1]);
        ExpBoostIoAfterAcquire(a1, v6);
        ExpLockResource(a1, v23);
        do
          v21 = (unsigned int *)ExpFindCurrentThread(a1, v6, v23, 1, 1);
        while ( !v21 );
        v22 = v21[1] & 3 | 4;
        *v21 = v6;
        v21[1] = v22;
        ExpUnlockResource(v21, v23);
LABEL_8:
        v8 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v8 & 0xFFFFF000) + 0x1484);
        ++*(_DWORD *)((v8 & 0xFFFFF000) + 0x1424);
        return 1;
      }
      v9 = (unsigned int *)ExpFindCurrentThread(a1, v6, v23, 1, 0);
      if ( v9 )
      {
        if ( *v9 != v6 )
        {
          v10 = v9[1];
          *v9 = v6;
          v9[1] = v10 & 3 | 4;
          v11 = *(_DWORD *)(a1 + 32);
          if ( v11 )
          {
            *(_DWORD *)(a1 + 32) = v11 + 1;
            goto LABEL_7;
          }
LABEL_6:
          *(_WORD *)(a1 + 12) = 1;
          *(_DWORD *)(a1 + 32) = 1;
LABEL_7:
          KeReleaseInStackQueuedSpinLock(v23);
          goto LABEL_8;
        }
        v9[1] = ((v9[1] & 0xFFFFFFFC) + 4) ^ v9[1] & 3;
        KeReleaseInStackQueuedSpinLock(v23);
        v18 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v18 & 0xFFFFF000) + 0x1488);
        ++*(_DWORD *)((v18 & 0xFFFFF000) + 0x1424);
        return 1;
      }
    }
    if ( *(_DWORD *)(a1 + 24) == v6 )
    {
      *(_DWORD *)(a1 + 28) = *(_DWORD *)(a1 + 28) & 3 ^ ((*(_DWORD *)(a1 + 28) & 0xFFFFFFFC) + 4);
      KeReleaseInStackQueuedSpinLock(v23);
      v17 = (unsigned int)KeGetPcr();
      ++*(_DWORD *)((v17 & 0xFFFFF000) + 0x1480);
      ++*(_DWORD *)((v17 & 0xFFFFF000) + 0x1424);
      return 1;
    }
    v13 = (unsigned int *)ExpFindEmptyEntry(a1, v23);
  }
  while ( !v13 );
  if ( a2 )
  {
    v14 = v13[1];
    *v13 = v6;
    v13[1] = v14 & 3 | 4;
    ++*(_DWORD *)(a1 + 40);
    v15 = memset(v24, 0, 20);
    LOWORD(v24[1]) = 1;
    BYTE2(v24[1]) = 4;
    v24[2] = 0;
    v24[4] = (int)&v24[3];
    v24[3] = (int)&v24[3];
    v24[0] = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 16) = v24;
    ExpUnlockResource(v15, v23);
    v16 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    ++*(_DWORD *)(v16 + 3852);
    ExpWaitForResource(a1, &v24[1]);
    ExpBoostIoAfterAcquire(a1, v6);
    goto LABEL_8;
  }
LABEL_17:
  KeReleaseInStackQueuedSpinLock(v23);
  v12 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  ++*(_DWORD *)(v12 + 3856);
  return 0;
}
