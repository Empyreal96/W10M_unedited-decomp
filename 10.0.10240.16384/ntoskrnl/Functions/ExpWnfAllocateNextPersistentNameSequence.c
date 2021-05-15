// ExpWnfAllocateNextPersistentNameSequence 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall ExpWnfAllocateNextPersistentNameSequence(unsigned __int64 *a1)
{
  unsigned __int64 v1; // r2
  int v3; // r9
  int v4; // r6
  int v5; // r0
  int v6; // r4
  unsigned int v7; // r2
  unsigned __int64 v8; // r2
  int v9; // r0
  unsigned __int64 v10; // kr10_8
  unsigned __int64 v11; // kr18_8
  unsigned __int64 v12; // kr20_8
  unsigned __int64 v13; // kr28_8
  unsigned __int64 v14; // r2
  int v15; // r0
  int v16; // r4
  unsigned int v17; // r2
  unsigned __int64 v18; // r2
  unsigned int v19; // r2
  int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r3
  unsigned __int64 v23; // kr38_8
  unsigned __int64 v24; // kr48_8
  unsigned int v25; // r1
  unsigned __int64 v27; // [sp+8h] [bp-48h]
  unsigned __int64 v28; // [sp+8h] [bp-48h]
  int v29[5]; // [sp+10h] [bp-40h] BYREF
  unsigned __int64 v30; // [sp+24h] [bp-2Ch]

  v29[0] = 0;
  v1 = __PAIR64__(ExpWnfPermanentNameSequenceNumberPool, dword_927794);
  v3 = 0;
  v4 = 0;
  __dmb(0xBu);
  if ( v1 )
    goto LABEL_19;
  v4 = ExpWnfGetNameStoreRegistryRoot(1, v29);
  if ( v4 < 0 )
    return v4;
  v5 = KeAbPreAcquire((unsigned int)&ExpWnfPermanentNameSequenceNumberLock, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex((unsigned __int8 *)&ExpWnfPermanentNameSequenceNumberLock);
  while ( __strex(v7 | 1, (unsigned __int8 *)&ExpWnfPermanentNameSequenceNumberLock) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(
      &ExpWnfPermanentNameSequenceNumberLock,
      v5,
      (unsigned int)&ExpWnfPermanentNameSequenceNumberLock);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  v8 = __PAIR64__(ExpWnfPermanentNameSequenceNumberPool, dword_927794);
  v3 = 1;
  __dmb(0xBu);
  if ( v8 )
    goto LABEL_19;
  v9 = ZwQueryValueKey();
  v4 = v9;
  if ( v9 >= 0 )
  {
    if ( v29[4] != 8 )
    {
      v4 = -1073741823;
      goto LABEL_43;
    }
    v27 = v30;
    __dmb(0xBu);
    do
      v10 = __ldrexd(&ExpWnfPermanentNameSequenceNumber);
    while ( __strexd(v27, &ExpWnfPermanentNameSequenceNumber) );
    __dmb(0xBu);
    do
      v11 = __ldrexd(&ExpWnfPermanentNameSequenceNumberPool);
    while ( __strexd(v27, &ExpWnfPermanentNameSequenceNumberPool) );
    __dmb(0xBu);
    do
    {
LABEL_19:
      __dmb(0xBu);
      do
      {
        v12 = __ldrexd(&ExpWnfPermanentNameSequenceNumber);
        v13 = v12 + 1;
      }
      while ( __strexd(v12 + 1, &ExpWnfPermanentNameSequenceNumber) );
      __dmb(0xBu);
    }
    while ( v12 == -1i64 );
    v14 = ExpWnfPermanentNameSequenceNumberPool;
    __dmb(0xBu);
    if ( v13 > v14 )
    {
      if ( !v29[0] )
      {
        v4 = ExpWnfGetNameStoreRegistryRoot(1, v29);
        if ( v4 < 0 )
          goto LABEL_42;
      }
      if ( !v3 )
      {
        v15 = KeAbPreAcquire((unsigned int)&ExpWnfPermanentNameSequenceNumberLock, 0, 0);
        v16 = v15;
        do
          v17 = __ldrex((unsigned __int8 *)&ExpWnfPermanentNameSequenceNumberLock);
        while ( __strex(v17 | 1, (unsigned __int8 *)&ExpWnfPermanentNameSequenceNumberLock) );
        __dmb(0xBu);
        if ( (v17 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(
            &ExpWnfPermanentNameSequenceNumberLock,
            v15,
            (unsigned int)&ExpWnfPermanentNameSequenceNumberLock);
        if ( v16 )
          *(_BYTE *)(v16 + 14) |= 1u;
        v3 = 1;
      }
      v18 = ExpWnfPermanentNameSequenceNumberPool;
      __dmb(0xBu);
      if ( v13 <= v18 )
        goto LABEL_41;
      v19 = dword_927794;
      v20 = ExpWnfPermanentNameSequenceNumberPool;
      __dmb(0xBu);
      v23 = __PAIR64__(v19, v20) + 100;
      v21 = (__PAIR64__(v19, v20) + 100) >> 32;
      v22 = v23;
      v28 = __PAIR64__(v21, v23);
      if ( __PAIR64__(v21, v23) < v13 )
      {
        do
        {
          v21 = (__PAIR64__(v21, v22) + 100) >> 32;
          v22 += 100;
        }
        while ( __PAIR64__(v21, v22) < v13 );
        v28 = __PAIR64__(v21, v22);
      }
      v4 = ZwSetValueKey();
      if ( v4 < 0 )
      {
LABEL_42:
        if ( !v3 )
          return v4;
        goto LABEL_43;
      }
      __dmb(0xBu);
      do
        v24 = __ldrexd(&ExpWnfPermanentNameSequenceNumberPool);
      while ( __strexd(v28, &ExpWnfPermanentNameSequenceNumberPool) );
      __dmb(0xBu);
    }
LABEL_41:
    *a1 = v13;
    goto LABEL_42;
  }
  if ( v9 == -1073741772 )
    goto LABEL_19;
LABEL_43:
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)&ExpWnfPermanentNameSequenceNumberLock);
  while ( __strex(v25 - 1, (unsigned int *)&ExpWnfPermanentNameSequenceNumberLock) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExpWnfPermanentNameSequenceNumberLock);
  KeAbPostRelease((unsigned int)&ExpWnfPermanentNameSequenceNumberLock);
  return v4;
}
