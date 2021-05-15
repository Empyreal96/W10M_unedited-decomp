// MiAllocatePfnRepurposeLogDispatch 
 
// local variable allocation has failed, the output may be wrong!
unsigned __int8 *MiAllocatePfnRepurposeLogDispatch()
{
  int v0; // r7 OVERLAPPED
  int v1; // r8 OVERLAPPED
  _DWORD *v2; // r0
  int v3; // r6
  int v4; // r5
  unsigned __int8 *result; // r0
  unsigned int *v6; // r1
  unsigned int *v7; // r2
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r4
  unsigned int v15; // r0
  int v16; // r7
  unsigned int v17; // r4
  int v18[2]; // [sp+0h] [bp-38h] BYREF
  int v19[2]; // [sp+8h] [bp-30h] BYREF
  int var28[12]; // [sp+10h] [bp-28h] BYREF

  KeQueryTickCount(v18);
  v0 = v18[0];
  v1 = v18[1];
  v2 = (_DWORD *)ExAllocatePoolWithTag(512, 4096);
  v3 = (int)v2;
  if ( v2 )
  {
    v2[1] = 2;
    v2[8] = v2 + 14;
    v2[9] = v2 + 1023;
    v2[4] = v0;
    v2[5] = v1;
    *v2 = 0;
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634500, var28);
  v4 = dword_6346A0;
  if ( !dword_634484 )
  {
LABEL_9:
    dword_6346A0 = 0;
    goto LABEL_10;
  }
  if ( v3 )
  {
    dword_6346A0 = v3;
    v3 = 0;
    goto LABEL_10;
  }
  if ( dword_6346A0 )
  {
    if ( (*(_DWORD *)(dword_6346A0 + 32) & 0xFFF) != 0 )
    {
      v4 = 0;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
LABEL_10:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = (unsigned __int8 *)KiReleaseQueuedSpinLockInstrumented(var28, var28[11]);
    goto LABEL_20;
  }
  result = (unsigned __int8 *)var28[0];
  if ( var28[0] )
    goto LABEL_18;
  v6 = (unsigned int *)var28[1];
  __dmb(0xBu);
  do
    result = (unsigned __int8 *)__ldrex(v6);
  while ( result == (unsigned __int8 *)var28 && __strex(0, v6) );
  if ( result != (unsigned __int8 *)var28 )
  {
    result = (unsigned __int8 *)KxWaitForLockChainValid(var28);
LABEL_18:
    var28[0] = 0;
    __dmb(0xBu);
    v7 = (unsigned int *)(result + 4);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 ^ 1, v7) );
  }
LABEL_20:
  if ( v3 )
    result = (unsigned __int8 *)ExFreePoolWithTag(v3);
  if ( v4 )
  {
    v9 = *(_DWORD *)(v4 + 32);
    if ( v9 == v4 + 56 )
      goto LABEL_47;
    if ( (v9 & 0xFFF) != 0 )
    {
      if ( __PAIR64__(v1, v0) < *(_QWORD *)(v4 + 16) )
      {
        KeQueryTickCount(v19);
        v0 = v19[0];
        v1 = v19[1];
      }
      v10 = *(_DWORD *)(v4 + 32);
      *(_QWORD *)(v4 + 24) = *(_QWORD *)&v0;
      *(_DWORD *)(v4 + 36) = v10 - 4;
    }
    *(_DWORD *)(v4 + 32) = v4 + 56;
    __pld(&dword_643B48);
    v11 = dword_643B48 & 0xFFFFFFFE;
    v12 = (dword_643B48 & 0xFFFFFFFE) + 2;
    do
      v13 = __ldrex((unsigned int *)&dword_643B48);
    while ( v13 == v11 && __strex(v12, (unsigned int *)&dword_643B48) );
    __dmb(0xBu);
    if ( v13 != v11 && !ExfAcquireRundownProtection(&dword_643B48) )
      goto LABEL_47;
    v14 = (unsigned __int16)word_643B64;
    if ( (unsigned __int16)word_643B64 < (unsigned int)dword_643B5C )
    {
      RtlpInterlockedPushEntrySList((unsigned __int64 *)&unk_643B60, (_DWORD *)v4);
      if ( !dword_643B50 && v14 >= 8 )
        KeSetEvent((int)algn_643B4C, 0, 0);
      v16 = 1;
    }
    else
    {
      __dmb(0xBu);
      do
        v15 = __ldrex(&dword_643B08);
      while ( __strex(v15 + 100, &dword_643B08) );
      __dmb(0xBu);
      v16 = 0;
    }
    __pld(&dword_643B48);
    v17 = dword_643B48 & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      result = (unsigned __int8 *)__ldrex((unsigned int *)&dword_643B48);
    while ( result == (unsigned __int8 *)v17 && __strex(v17 - 2, (unsigned int *)&dword_643B48) );
    if ( result != (unsigned __int8 *)v17 )
      result = ExfReleaseRundownProtection((unsigned __int8 *)&dword_643B48);
    if ( !v16 )
LABEL_47:
      result = (unsigned __int8 *)ExFreePoolWithTag(v4);
  }
  return result;
}
