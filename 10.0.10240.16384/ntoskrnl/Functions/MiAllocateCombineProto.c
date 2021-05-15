// MiAllocateCombineProto 
 
int __fastcall MiAllocateCombineProto(_DWORD *a1, __int64 a2, int a3, int a4)
{
  int v5; // r8
  int v6; // r4
  unsigned int *v8; // r5
  int v9; // r6
  int v10; // r10
  int v12; // r0
  unsigned int v13; // r1
  int v14; // r0
  int v15; // r4
  unsigned int v17; // r1
  unsigned int v18; // r2
  unsigned int *v19; // lr
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  unsigned int v23; // r2
  unsigned int *v24; // r2
  unsigned int v25; // r0
  _DWORD *v26; // r2
  __int64 *v27; // r3
  __int64 v28; // kr00_8
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r0
  char var28[44]; // [sp+8h] [bp-28h] BYREF

  v5 = HIDWORD(a2);
  v6 = a2;
  if ( !a2 || !a1[45] )
    return 0;
  v8 = &a1[2 * (a2 & 0xF) + 13];
  v9 = 0;
  v10 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54F090();
  v12 = *v8 & 0x7FFFFFFF;
  do
    v13 = __ldrex(v8);
  while ( v13 == v12 && __strex(v12 + 1, v8) );
  __dmb(0xBu);
  if ( v13 != v12 )
    ExpWaitForSpinLockSharedAndAcquire(v8);
  v14 = MiLocateCombineBlock(a1, v13, v6, v5, a3);
  v15 = v14;
  if ( v14 )
  {
    v19 = (unsigned int *)(v14 + 24);
    v20 = *(_DWORD *)(v14 + 24);
    if ( v20 )
    {
      while ( 1 )
      {
        do
          v21 = __ldrex(v19);
        while ( v21 == v20 && __strex(v20 + 1, v19) );
        if ( v21 == v20 )
          break;
        v20 = v21;
        if ( !v21 )
          goto LABEL_42;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
      }
      else
      {
        __dmb(0xBu);
        do
          v22 = __ldrex(v8);
        while ( __strex(v22 & 0xBFFFFFFF, v8) );
        __dmb(0xBu);
        do
          v23 = __ldrex(v8);
        while ( __strex(v23 - 1, v8) );
      }
      KfLowerIrql(v10);
      v24 = a1 + 56;
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 + 1, v24) );
      return v15;
    }
LABEL_42:
    a4 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v8);
  }
  else
  {
    __dmb(0xBu);
    do
      v17 = __ldrex(v8);
    while ( __strex(v17 & 0xBFFFFFFF, v8) );
    __dmb(0xBu);
    do
      v18 = __ldrex(v8);
    while ( __strex(v18 - 1, v8) );
  }
  KfLowerIrql(v10);
  if ( !a4 )
    return 0;
  KeAcquireInStackQueuedSpinLock(a1 + 11, (unsigned int)var28);
  v26 = a1 + 9;
  v27 = (__int64 *)a1[9];
  if ( v27 != (__int64 *)(a1 + 9) )
  {
    v9 = a1[9];
    v28 = *v27;
    if ( *((_DWORD **)v27 + 1) != v26 || *(_DWORD *)(v28 + 4) != v9 )
      __fastfail(3u);
    *v26 = v28;
    *(_DWORD *)(v28 + 4) = v26;
  }
  KeReleaseInStackQueuedSpinLock((int)var28);
  if ( !v9 )
    return 0;
  v29 = a1 + 55;
  do
    v30 = __ldrex(v29);
  while ( __strex(v30 + 1, v29) );
  *(_DWORD *)(v9 + 24) = 1;
  v31 = a1 + 56;
  *(_DWORD *)(v9 + 28) = a3;
  do
    v32 = __ldrex(v31);
  while ( __strex(v32 + 1, v31) );
  return v9;
}
