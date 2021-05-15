// MiInsertProtectedStandbyPage 
 
int __fastcall MiInsertProtectedStandbyPage(int a1, int a2)
{
  int v4; // lr
  int result; // r0
  _DWORD *v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r5
  unsigned int v9; // r5
  unsigned int v10; // r5
  int v11; // r1
  int v12; // r4
  char v13; // r2
  int v14; // r1
  int v15; // r2
  int v16; // r0
  unsigned int *v17; // r1
  unsigned int v18; // r1
  unsigned int *v19; // r2
  int v20; // r0
  unsigned int *v21; // r1
  int *v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // r3
  char *v26; // r4
  int v27; // r0
  unsigned int *v28; // r1
  int *v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // [sp+4h] [bp-3Ch]
  int v33; // [sp+8h] [bp-38h] BYREF
  char *v34; // [sp+Ch] [bp-34h]
  int var28[11]; // [sp+18h] [bp-28h] BYREF

  v4 = (a2 - MmPfnDatabase) / 24;
  if ( !a1 || (*(_BYTE *)(a2 + 19) & 0x10) != 0 || (*(_BYTE *)(a2 + 19) & 0x40) != 0 || (*(_BYTE *)(a2 + 19) & 7u) >= 5 )
    return MiPfnReferenceCountIsZero(a2, v4);
  v32 = (a1 - MmPfnDatabase) / 24;
  v33 = 0;
  v34 = algn_63FD74;
  __dmb(0xBu);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53B360();
  do
    v6 = (_DWORD *)__ldrex((unsigned int *)algn_63FD74);
  while ( __strex((unsigned int)&v33, (unsigned int *)algn_63FD74) );
  __dmb(0xBu);
  if ( v6 )
    KxWaitForLockOwnerShip((int)&v33, v6);
  if ( (*(_BYTE *)(a1 + 19) & 8) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v33);
    }
    else
    {
      v20 = v33;
      if ( !v33 )
      {
        v21 = (unsigned int *)v34;
        __dmb(0xBu);
        do
          v22 = (int *)__ldrex(v21);
        while ( v22 == &v33 && __strex(0, v21) );
        if ( v22 == &v33 )
          return MiPfnReferenceCountIsZero(a2, v4);
        v20 = KxWaitForLockChainValid(&v33);
      }
      v33 = 0;
      __dmb(0xBu);
      v23 = (unsigned int *)(v20 + 4);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 ^ 1, v23) );
    }
    return MiPfnReferenceCountIsZero(a2, v4);
  }
  *(_BYTE *)(a2 + 19) |= 8u;
  if ( (*(_DWORD *)(a2 + 20) & 0x8000000) != 0 )
  {
    do
      v7 = __ldrex((unsigned int *)&dword_634680);
    while ( __strex(v7 + 1, (unsigned int *)&dword_634680) );
  }
  else
  {
    do
      v18 = __ldrex(dword_640300);
    while ( __strex(v18 + 1, dword_640300) );
  }
  do
  {
    v8 = __ldrex((unsigned int *)&dword_640580);
    v9 = v8 + 1;
  }
  while ( __strex(v9, (unsigned int *)&dword_640580) );
  if ( v9 <= 0x80 )
  {
    if ( v9 == 128 )
    {
      v25 = 1;
    }
    else
    {
      if ( v9 != 2 )
        goto LABEL_15;
      v25 = 0;
    }
    v26 = (char *)&unk_640284 + 20 * v25;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640280, var28, 5 * v25, &unk_640284);
    KeSetEvent((int)v26, 0, 0);
    ++*((_DWORD *)v26 + 4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(var28);
      goto LABEL_15;
    }
    v27 = var28[0];
    if ( !var28[0] )
    {
      v28 = (unsigned int *)var28[1];
      __dmb(0xBu);
      do
        v29 = (int *)__ldrex(v28);
      while ( v29 == var28 && __strex(0, v28) );
      if ( v29 == var28 )
        goto LABEL_15;
      v27 = KxWaitForLockChainValid(var28);
    }
    var28[0] = 0;
    __dmb(0xBu);
    v30 = (unsigned int *)(v27 + 4);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 ^ 1, v30) );
  }
LABEL_15:
  v10 = v9 - 1;
  if ( v10 == dword_6402AC || v10 == dword_6402B0 )
    MiUpdateAvailableEvents(MiSystemPartition);
  __dmb(0xFu);
  v11 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v12 = (*(_DWORD *)(a2 + 12) ^ (v11 << 20)) & 0xF00000 ^ *(_DWORD *)(a2 + 12);
  v13 = *(_BYTE *)(a2 + 18);
  *(_DWORD *)(a2 + 12) = v12;
  *(_BYTE *)(a2 + 18) = v13 & 0xF8 | 2;
  v14 = *(_DWORD *)(a1 + 20) & 0xFFFFF;
  v15 = *(_DWORD *)(a1 + 8) >> 12;
  *(_DWORD *)(a2 + 12) = v12 & 0xFFF00000 | v14;
  *(_DWORD *)a2 = v32;
  if ( v15 == v32 )
    *(_DWORD *)(a1 + 8) = *(_DWORD *)(a1 + 8) & 0xFFF | (v4 << 12);
  else
    *(_DWORD *)(MmPfnDatabase + 24 * v14) = v4;
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 20) & 0xFFF00000 | v4 & 0xFFFFF;
  ++dword_63FD64;
  if ( (dword_682604 & 0x10000) != 0 )
    return KiReleaseQueuedSpinLockInstrumented(&v33);
  v16 = v33;
  if ( v33 )
    goto LABEL_30;
  v17 = (unsigned int *)v34;
  __dmb(0xBu);
  do
    result = __ldrex(v17);
  while ( (int *)result == &v33 && __strex(0, v17) );
  if ( (int *)result != &v33 )
  {
    v16 = KxWaitForLockChainValid(&v33);
LABEL_30:
    v33 = 0;
    __dmb(0xBu);
    v19 = (unsigned int *)(v16 + 4);
    do
      result = __ldrex(v19);
    while ( __strex(result ^ 1, v19) );
  }
  return result;
}
