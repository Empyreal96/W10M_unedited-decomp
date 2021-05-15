// MiDeleteFinalPageTables 
 
int __fastcall MiDeleteFinalPageTables(int a1)
{
  int v2; // r0
  int v3; // r7
  int v4; // r6
  int v5; // r0
  int v6; // r4
  int v7; // r8
  unsigned int *v8; // r4
  int v9; // r10
  unsigned __int8 *v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r0
  int v14; // r5
  int i; // r4
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  char v18; // r3
  int v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r5
  unsigned __int8 *v23; // r1
  unsigned int v24; // r2
  int v25; // r0
  unsigned int *v26; // r2
  unsigned int v27; // r4
  unsigned int v28; // r1
  unsigned __int8 *v29; // r1
  int v30; // r3
  unsigned int v31; // r2
  int v32; // r3
  char v33[4]; // [sp+8h] [bp-58h] BYREF
  int v34; // [sp+Ch] [bp-54h]
  int v35; // [sp+10h] [bp-50h]
  _DWORD v36[4]; // [sp+18h] [bp-48h] BYREF
  char v37[56]; // [sp+28h] [bp-38h] BYREF

  v36[0] = 0;
  v36[1] = 0;
  v36[2] = 0;
  v36[3] = 0;
  v2 = *(_DWORD *)(a1 + 24) >> 12;
  v3 = MmPfnDatabase + 24 * v2;
  v4 = 0;
  v5 = MiMapPageInHyperSpaceWorker(v2, v33, 0x80000000);
  v6 = *(_DWORD *)(v5 + 2044);
  MiUnmapPageInHyperSpaceWorker(v5, (unsigned __int8)v33[0], 0x80000000);
  if ( v6 )
  {
    v7 = __mrc(15, 0, 13, 0, 3);
    KiStackAttachProcess(a1, 0, v37);
    LOCK_ADDRESS_SPACE(v7 & 0xFFFFFFC0, a1);
    v8 = (unsigned int *)(a1 + 492);
    v9 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_514E8C();
    v11 = (unsigned __int8 *)(a1 + 495);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 | 0x80, v11) );
    __dmb(0xBu);
    if ( v12 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(a1 + 492);
    while ( 1 )
    {
      v13 = *v8;
      if ( (*v8 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v13 & 0x40000000) == 0 )
      {
        do
          v28 = __ldrex(v8);
        while ( v28 == v13 && __strex(v13 | 0x40000000, v8) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    MiDeleteVirtualAddresses(2147352576, 2147352576, 0, v9, v36);
    MiDeleteAllHashMappings(a1 + 492);
    MiUnlockWorkingSetExclusive(a1 + 492, v9);
    UNLOCK_ADDRESS_SPACE(v7 & 0xFFFFFFC0, a1);
    KiUnstackDetachProcess(v37, 0);
  }
  if ( (*(_DWORD *)(v3 + 12) & 0x3FFFFFFF) != 3 )
    KeBugCheckEx(26, 13395, a1);
  MiUnlinkProcessFromSession(a1);
  v14 = *(_DWORD *)(a1 + 248);
  for ( i = MmPfnDatabase + 24 * v14; ; MiLockAndDecrementShareCount(i, 0) )
  {
    v34 = v14;
    v14 = *(_DWORD *)(i + 20) & 0xFFFFF;
    v35 = KfRaiseIrql(2);
    v16 = (unsigned __int8 *)(i + 15);
    do
      v17 = __ldrex(v16);
    while ( __strex(v17 | 0x80, v16) );
    __dmb(0xBu);
    if ( v17 >> 7 )
    {
      v29 = (unsigned __int8 *)(i + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v30 = *(_DWORD *)(i + 12);
          __dmb(0xBu);
        }
        while ( (v30 & 0x80000000) != 0 );
        do
          v31 = __ldrex(v29);
        while ( __strex(v31 | 0x80, v29) );
        __dmb(0xBu);
      }
      while ( v31 >> 7 );
    }
    MiClearContainingMapping(i);
    v18 = *(_BYTE *)(i + 18);
    *(_DWORD *)(i + 12) |= 0x40000000u;
    if ( (v18 & 7) != 6 )
      KeBugCheckEx(78, 153, (i - MmPfnDatabase) / 24);
    if ( MiUpdateShareCount(i, -1) )
      v19 = 2;
    else
      v19 = MiPfnShareCountIsZero(i, 0);
    if ( v19 == 3 )
      ++v4;
    __dmb(0xBu);
    v20 = (unsigned int *)(i + 12);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 & 0x7FFFFFFF, v20) );
    KfLowerIrql(v35);
    if ( v34 == v14 )
      break;
    i = MmPfnDatabase + 24 * v14;
  }
  v22 = KfRaiseIrql(2);
  v23 = (unsigned __int8 *)(i + 15);
  do
    v24 = __ldrex(v23);
  while ( __strex(v24 | 0x80, v23) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v24 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v32 = *(_DWORD *)(i + 12);
      __dmb(0xBu);
    }
    while ( (v32 & 0x80000000) != 0 );
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 | 0x80, v23) );
  }
  if ( (*(_BYTE *)(i + 18) & 7) != 6 )
    KeBugCheckEx(78, 153, (i - MmPfnDatabase) / 24);
  if ( MiUpdateShareCount(i, -1) )
    v25 = 2;
  else
    v25 = MiPfnShareCountIsZero(i, 0);
  if ( v25 == 3 )
    ++v4;
  __dmb(0xBu);
  v26 = (unsigned int *)(i + 12);
  do
    v27 = __ldrex(v26);
  while ( __strex(v27 & 0x7FFFFFFF, v26) );
  KfLowerIrql(v22);
  return v4;
}
