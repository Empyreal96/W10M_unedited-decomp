// MiRemovePhysicalMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiRemovePhysicalMemory(int a1, int a2, int a3)
{
  _DWORD *v3; // r7
  int v4; // r4
  int v7; // r8
  int v8; // r1
  int v9; // r5
  unsigned int v10; // r0
  int v11; // r1 OVERLAPPED
  int *v12; // r4
  int v13; // r1 OVERLAPPED
  unsigned int v14; // r4
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v23; // [sp+8h] [bp-58h] BYREF
  _DWORD *v24; // [sp+Ch] [bp-54h] BYREF
  int v25; // [sp+10h] [bp-50h]
  int v26; // [sp+14h] [bp-4Ch]
  int v27; // [sp+18h] [bp-48h]
  int v28[4]; // [sp+20h] [bp-40h] BYREF
  int v29[12]; // [sp+30h] [bp-30h] BYREF

  v28[2] = 0;
  v28[1] = (int)v28;
  v3 = 0;
  v4 = 0;
  v28[0] = (int)v28;
  v27 = a3;
  v23 = 0;
  v24 = 0;
  v7 = 0;
  v25 = a3 & 2;
  v26 = __mrc(15, 0, 13, 0, 3);
  v8 = v26 & 0xFFFFFFC0;
  if ( (a3 & 2) != 0 )
  {
    v9 = 0;
    MiLockDynamicMemoryExclusive((int)MiSystemPartition, v8);
LABEL_28:
    MiInitializeDynamicPfns(a1, a2, 0);
    if ( !v25 )
      KePulseEvent(dword_63F7E4, 0, 0);
    goto LABEL_7;
  }
  v29[0] = 0;
  v29[2] = a1;
  v29[3] = a2;
  MiLockDynamicMemoryExclusive((int)MiSystemPartition, v8);
  v9 = MiConfigureMemoryRemoval(&v23, (_DWORD *)MmPhysicalMemoryBlock, v29);
  if ( v9 >= 0 )
  {
    v7 = MiReferencePageRuns((int)MiSystemPartition, 1);
    if ( MiDescribePageRun((int)v28, a1, a2) )
    {
      v3 = (_DWORD *)v7;
      while ( 1 )
      {
        v12 = (int *)v28[0];
        if ( (int *)v28[0] == v28 )
          break;
        *(_QWORD *)&v13 = *(_QWORD *)v28[0];
        if ( *(int **)(v28[0] + 4) != v28 || *(_DWORD *)(v13 + 4) != v28[0] )
          __fastfail(3u);
        v28[0] = v13;
        *(_DWORD *)(v13 + 4) = v28;
        v9 = MiConfigureMemoryRemoval(&v24, v3, v12);
        ExFreePoolWithTag((unsigned int)v12);
        if ( v3 != (_DWORD *)v7 )
          ExFreePoolWithTag((unsigned int)(v3 - 2));
        v3 = v24;
        if ( v9 < 0 )
          goto LABEL_6;
      }
      MiReduceCommitLimits(MiSystemPartition, a2, a2, (int)v28);
      MiReturnCommit((int)MiSystemPartition, a2);
      do
        v14 = __ldrex((unsigned int *)0xFFFF92E8);
      while ( __strex(v14 - a2, (unsigned int *)0xFFFF92E8) );
      v15 = MiPerformMemoryChange(a1, a2, &v23, (int *)&v24, 0);
      MiComputeNodeMemory(v15, v16, v17, v18);
      v4 = v23;
      v3 = v24;
      goto LABEL_28;
    }
    v9 = -1073741670;
  }
LABEL_6:
  v4 = v23;
LABEL_7:
  MiUnlockDynamicMemoryExclusive((int)MiSystemPartition, v26 & 0xFFFFFFC0);
  if ( v4 )
    ExFreePoolWithTag(v4 - 8);
  if ( !v3 )
    goto LABEL_12;
  v10 = (unsigned int)(v3 - 2);
  while ( 1 )
  {
    ExFreePoolWithTag(v10);
LABEL_12:
    v10 = v28[0];
    if ( (int *)v28[0] == v28 )
      break;
    *(_QWORD *)&v11 = *(_QWORD *)v28[0];
    if ( *(int **)(v28[0] + 4) != v28 || *(_DWORD *)(v11 + 4) != v28[0] )
      __fastfail(3u);
    v28[0] = v11;
    *(_DWORD *)(v11 + 4) = v28;
  }
  if ( v7 )
    MiDereferencePageRuns(v7);
  if ( v9 >= 0 )
  {
    ++dword_63381C;
    KeFlushTb(3, 2);
    v19 = MiFlushCacheRange(a1, a2);
    if ( (v27 & 8) == 0 && !v25 )
      IoUpdateDumpPhysicalRanges(v19, v20, v21);
  }
  return v9;
}
