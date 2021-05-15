// ExAcquireResourceSharedLite 
 
int __fastcall ExAcquireResourceSharedLite(int a1, int a2)
{
  unsigned int v5; // r3
  unsigned int *v6; // r7
  int v7; // r9
  unsigned int v8; // r1
  int v9; // r3
  unsigned int v10; // r3
  BOOL v11; // r7
  int v12; // r3
  int *v13; // r5
  int v14; // r0
  int *v15; // r2
  int *v16; // r0
  int v17; // r3
  int v18; // r3
  int v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r3
  unsigned int v22; // r3
  int v23; // r3
  int v24; // r0
  unsigned int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r2
  _DWORD v28[2]; // [sp+0h] [bp-40h] BYREF
  char v29; // [sp+8h] [bp-38h]
  int v30[12]; // [sp+10h] [bp-30h] BYREF

  if ( (dword_682604 & 0x20000) != 0 )
    return sub_50C684();
  v5 = (unsigned int)KeGetPcr();
  ++*(_DWORD *)((v5 & 0xFFFFF000) + 0x144C);
  v6 = (unsigned int *)(a1 + 52);
  v28[0] = 0;
  v28[1] = a1 + 52;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __dmb(0xBu);
  v29 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented(v28, a1 + 52);
  }
  else
  {
    do
      v8 = __ldrex(v6);
    while ( __strex((unsigned int)v28, v6) );
    __dmb(0xBu);
    if ( v8 )
      KxWaitForLockOwnerShip(v28);
  }
  do
  {
    while ( 1 )
    {
      if ( !*(_DWORD *)(a1 + 32) )
      {
        v9 = *(_DWORD *)(a1 + 28) & 3 | 4;
        *(_DWORD *)(a1 + 24) = v7;
        *(_DWORD *)(a1 + 28) = v9;
        *(_DWORD *)(a1 + 32) = 1;
        *(_WORD *)(a1 + 12) = 1;
        KeReleaseInStackQueuedSpinLock(v28);
        v10 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v10 & 0xFFFFF000) + 0x1454);
        ++*(_DWORD *)((v10 & 0xFFFFF000) + 0x1424);
        return 1;
      }
      if ( (*(_WORD *)(a1 + 14) & 0x80) == 0 )
        break;
      if ( *(_DWORD *)(a1 + 24) == v7 )
      {
        *(_DWORD *)(a1 + 28) = ((*(_DWORD *)(a1 + 28) & 0xFFFFFFFC) + 4) ^ *(_DWORD *)(a1 + 28) & 3;
        KeReleaseInStackQueuedSpinLock(v28);
        v22 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v22 & 0xFFFFF000) + 0x1450);
        ++*(_DWORD *)((v22 & 0xFFFFF000) + 0x1424);
        return 1;
      }
      v16 = (int *)ExpFindEmptyEntry(a1, v28);
      if ( v16 )
        goto LABEL_37;
    }
    v11 = *(_DWORD *)(a1 + 44) != 0;
    v12 = *(_DWORD *)(a1 + 24);
    if ( v12 == v7 )
    {
      v16 = (int *)(a1 + 24);
    }
    else
    {
      if ( v12 || *(_DWORD *)(a1 + 44) )
        v13 = 0;
      else
        v13 = (int *)(a1 + 24);
      v14 = *(_DWORD *)(a1 + 8);
      if ( v14 )
      {
        v15 = (int *)(v14 + 8 * *(_DWORD *)(v14 + 4));
        v16 = (int *)(v14 + 8);
        while ( *v16 != v7 )
        {
          if ( !v13 && !*v16 )
            v13 = v16;
          v16 += 2;
          if ( v16 == v15 )
            goto LABEL_18;
        }
        *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = ((int)v16 - *(_DWORD *)(a1 + 8)) >> 3;
      }
      else
      {
LABEL_18:
        if ( v13 )
        {
          v16 = v13;
          *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x191) = ((int)v13 - *(_DWORD *)(a1 + 8)) >> 3;
        }
        else
        {
          ExpExpandResourceOwnerTable(a1, v28);
          v16 = 0;
        }
      }
    }
  }
  while ( !v16 );
  if ( *v16 == v7 )
  {
    v16[1] = ((v16[1] & 0xFFFFFFFC) + 4) ^ v16[1] & 3;
    KeReleaseInStackQueuedSpinLock(v28);
    v21 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v21 & 0xFFFFF000) + 0x1458);
    ++*(_DWORD *)((v21 & 0xFFFFF000) + 0x1424);
    return 1;
  }
  if ( !v11 )
  {
    v17 = v16[1];
    *v16 = v7;
    v16[1] = v17 & 3 | 4;
    v18 = *(_DWORD *)(a1 + 32);
    if ( v18 )
    {
      v19 = v18 + 1;
    }
    else
    {
      v19 = 1;
      *(_WORD *)(a1 + 12) = 1;
    }
    *(_DWORD *)(a1 + 32) = v19;
    KeReleaseInStackQueuedSpinLock(v28);
    v20 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v20 & 0xFFFFF000) + 0x1454);
    ++*(_DWORD *)((v20 & 0xFFFFF000) + 0x1424);
    return 1;
  }
LABEL_37:
  if ( a2 )
  {
    v23 = v16[1];
    *v16 = v7;
    v16[1] = v23 & 3 | 4;
    ++*(_DWORD *)(a1 + 40);
    memset(v30, 0, 20);
    LOWORD(v30[1]) = 1;
    v30[2] = 0;
    v24 = *(_DWORD *)(a1 + 16);
    v30[4] = (int)&v30[3];
    BYTE2(v30[1]) = 4;
    *(_DWORD *)(a1 + 16) = v30;
    v30[3] = (int)&v30[3];
    v30[0] = v24;
    ExpUnlockResource(v24, v28);
    v25 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
    ++*(_DWORD *)(v25 + 3804);
    ExpWaitForResource(a1, &v30[1]);
    ExpBoostIoAfterAcquire(a1, v7);
    v26 = (unsigned int)KeGetPcr();
    ++*(_DWORD *)((v26 & 0xFFFFF000) + 0x1454);
    ++*(_DWORD *)((v26 & 0xFFFFF000) + 0x1424);
    return 1;
  }
  KeReleaseInStackQueuedSpinLock(v28);
  v27 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  ++*(_DWORD *)(v27 + 3808);
  return 0;
}
