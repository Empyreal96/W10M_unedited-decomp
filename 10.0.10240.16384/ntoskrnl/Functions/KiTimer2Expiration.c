// KiTimer2Expiration 
 
int __fastcall KiTimer2Expiration(int result, unsigned __int64 a2, _DWORD *a3)
{
  int v5; // r8
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // r2
  int i; // r4
  _QWORD *v9; // r9
  int j; // r2
  _DWORD *v11; // r5
  int *v12; // r0
  int *k; // r4
  unsigned __int8 *v14; // r5
  unsigned int v15; // r2
  __int64 v16; // r0
  unsigned __int64 v17; // r2
  int v18; // r0
  unsigned int v19; // r2
  unsigned int v20; // r2
  unsigned int *v21; // r0
  char v22; // r2
  int v23; // r1
  char v24[4]; // [sp+8h] [bp-30h] BYREF
  int v25; // [sp+Ch] [bp-2Ch]
  int var28[11]; // [sp+10h] [bp-28h] BYREF

  v5 = result;
  do
    v6 = __ldrexd((unsigned __int64 *)&KiNextTimer2DueTime);
  while ( !v6 && __strexd(0i64, (unsigned __int64 *)&KiNextTimer2DueTime) );
  if ( a2 < v6 )
    return result;
  var28[1] = (int)var28;
  var28[0] = (int)var28;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52F214();
  do
    v7 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
  while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
  __dmb(0xBu);
  if ( v7 )
    KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
  for ( i = 0; i < 4; ++i )
  {
    v9 = &KiTimer2Collections[2 * i];
    for ( j = *((_DWORD *)v9 + 1); j; var28[0] = (int)v11 )
    {
      if ( i != 3 )
        __asm { ADD             PC, R3 }
      v11 = (_DWORD *)j;
      if ( a2 < *(_QWORD *)(j + 24) )
        break;
      KiRemoveTimer2(j - 16);
      KiUpdateTimer2Flags(v11 - 4, 2, 1);
      v18 = var28[0];
      *v11 = var28[0];
      v11[1] = var28;
      if ( *(int **)(v18 + 4) != var28 )
        __fastfail(3u);
      *(_DWORD *)(v18 + 4) = v11;
      j = *((_DWORD *)v9 + 1);
    }
  }
  v12 = &PerfGlobalGroupMask;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
    v12 = &PerfGlobalGroupMask;
  }
  else
  {
    __dmb(0xBu);
    KiTimer2CollectionLock = 0;
  }
  for ( k = (int *)var28[0]; k != var28; v12 = &PerfGlobalGroupMask )
  {
    v14 = (unsigned __int8 *)(k - 4);
    k = (int *)*k;
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    __dmb(0xBu);
    if ( v15 >> 7 )
    {
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
        }
        while ( (*(_DWORD *)v14 & 0x80) != 0 );
        do
          v19 = __ldrex(v14);
        while ( __strex(v19 | 0x80, v14) );
        __dmb(0xBu);
      }
      while ( v19 >> 7 );
    }
    if ( (v14[1] & 2) == 0 )
    {
      if ( (v14[1] & 8) == 0 )
      {
        v22 = 4;
        v23 = 0;
        v21 = (unsigned int *)v14;
        goto LABEL_49;
      }
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented(&KiTimer2CollectionLock);
      }
      else
      {
        do
          v20 = __ldrex((unsigned int *)&KiTimer2CollectionLock);
        while ( __strex(1u, (unsigned int *)&KiTimer2CollectionLock) );
        __dmb(0xBu);
        if ( v20 )
          KxWaitForSpinLockAndAcquire(&KiTimer2CollectionLock);
      }
      v25 = KiInsertTimer2WithCollectionLockHeld((int)v14, 0, v24);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&KiTimer2CollectionLock);
      }
      else
      {
        __dmb(0xBu);
        KiTimer2CollectionLock = 0;
      }
      v21 = (unsigned int *)v14;
      if ( v25 )
      {
        v22 = 0;
        v23 = 1;
LABEL_49:
        KiUpdateTimer2Flags(v21, v23, v22);
        continue;
      }
    }
    KiExpireTimer2((int)v14, v5, a2, a3);
  }
  if ( *(_DWORD *)(v5 + 1540) )
    v12 = (int *)KiProcessThreadWaitList(v5, 1, 0, 2);
  v16 = KeQueryInterruptTime(v12);
  do
    v17 = __ldrexd(&KiTimer2Collections[5]);
  while ( !v17 && __strexd(0i64, &KiTimer2Collections[5]) );
  result = KiShouldSetClockIntervalForHighResolutionTimers(v16, v17);
  if ( result )
    result = KiSendClockInterruptToClockOwner();
  return result;
}
