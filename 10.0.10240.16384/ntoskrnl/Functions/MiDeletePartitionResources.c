// MiDeletePartitionResources 
 
int __fastcall MiDeletePartitionResources(_DWORD *a1)
{
  _DWORD *v2; // r4
  int v3; // r7
  int v4; // r6
  __int16 *v5; // r6
  int *v6; // r8
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r0
  int v10; // r4
  unsigned int *v11; // r2
  unsigned int v12; // r0
  int v13; // r4
  unsigned int v14; // r0
  int v15; // r2
  int v16; // r4
  int *v17; // r2
  int v18; // r4
  unsigned int v19; // r0
  int v20; // r1
  int v21; // r3
  _DWORD *v22; // r0
  _DWORD *v23; // r4
  int v24; // r9
  unsigned int *v25; // r4
  int v26; // r10
  _DWORD *v27; // r2
  unsigned __int8 *v28; // r3
  unsigned int v29; // r1
  unsigned int v30; // r0
  unsigned int v31; // r1
  int v32; // r0
  int v33; // r0
  int result; // r0
  int vars4; // [sp+2Ch] [bp+4h]

  KeSetEvent((int)(a1 + 30), 1, 0);
  v2 = a1;
  v3 = 5;
  do
  {
    v4 = v2[34];
    if ( v4 )
    {
      ZwWaitForSingleObject();
      ObCloseHandle(v4);
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  MiFreePageFileHashPfns((int)a1);
  v5 = (__int16 *)a1[3];
  if ( !v5 )
    v5 = MiSystemPartition;
  MiFreePartitionPhysicalPages(a1);
  a1[1029] -= MiDeletePagingFiles(a1);
  if ( v5 == MiSystemPartition )
  {
    v6 = a1 + 960;
    v7 = a1[960];
    __dmb(0xBu);
    MiReturnResidentAvailable(v7);
    v8 = a1[960];
    __dmb(0xBu);
    do
      v9 = __ldrex(&dword_634A2C[28]);
    while ( __strex(v9 + v8, &dword_634A2C[28]) );
  }
  else
  {
    v10 = a1[960];
    v6 = a1 + 960;
    __dmb(0xBu);
    v11 = (unsigned int *)(v5 + 1920);
    do
      v12 = __ldrex(v11);
    while ( __strex(v12 + v10, v11) );
  }
  if ( v5 == MiSystemPartition )
  {
    v13 = *v6;
    __dmb(0xBu);
    do
      v14 = __ldrex(&dword_634A2C[30]);
    while ( __strex(v14 + v13, &dword_634A2C[30]) );
  }
  __dmb(0xBu);
  v15 = a1[961];
  __dmb(0xBu);
  v16 = a1[1029] - v15;
  if ( v5 == MiSystemPartition )
  {
    MiReturnCommit((int)v5, v16);
    v17 = &dword_634D94;
    v18 = -v16;
    do
    {
      v19 = __ldrex((unsigned int *)&dword_634D94);
      v20 = v19 + v18;
      v21 = __strex(v19 + v18, (unsigned int *)&dword_634D94);
    }
    while ( v21 );
  }
  else
  {
    MiIncreaseCommitLimits(v5, v16, v16, 0, 0);
  }
  if ( v5 == MiSystemPartition )
  {
    v22 = (_DWORD *)a1[7];
    if ( v22 )
    {
      do
      {
        v23 = (_DWORD *)*v22;
        ExFreePoolWithTag(v22);
        v22 = v23;
      }
      while ( v23 );
    }
  }
  else
  {
    v24 = __mrc(15, 0, 13, 0, 3);
    MiLockDynamicMemoryExclusive((int)v5, v24 & 0xFFFFFFC0);
    v25 = (unsigned int *)(v5 + 84);
    v26 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)v5 + 42);
    }
    else
    {
      v28 = (unsigned __int8 *)v5 + 171;
      do
        v29 = __ldrex(v28);
      while ( __strex(v29 | 0x80, v28) );
      __dmb(0xBu);
      if ( v29 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)v5 + 42);
      while ( 1 )
      {
        v30 = *v25;
        if ( (*v25 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v30 & 0x40000000) == 0 )
        {
          do
            v31 = __ldrex(v25);
          while ( v31 == v30 && __strex(v30 | 0x40000000, v25) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v27 = (_DWORD *)a1[7];
    if ( v27 )
    {
      while ( *v27 )
        v27 = (_DWORD *)*v27;
      *v27 = *((_DWORD *)v5 + 7);
      *((_DWORD *)v5 + 7) = a1[7];
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)v5 + 42, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v25 = 0;
    }
    KfLowerIrql(v26);
    MiSortPartitionMdls(v5);
    MiUnlockDynamicMemoryExclusive((int)v5, v24 & 0xFFFFFFC0);
  }
  MiDeletePartitionFromList((int)a1, v20, (int)v17, v21);
  v32 = a1[878];
  if ( v32 )
  {
    ExFreePoolWithTag(v32);
    a1[878] = 0;
  }
  v33 = a1[29];
  if ( v33 )
    MiDereferencePageRuns(v33);
  result = a1[8];
  if ( result )
    result = MiDereferencePageRuns(result);
  return result;
}
