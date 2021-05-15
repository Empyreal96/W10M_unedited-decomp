// MiAddPhysicalMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiAddPhysicalMemory(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v6; // r0
  __int64 v8; // r2
  char v9; // r0
  unsigned int v10; // r6
  unsigned int v11; // r5
  unsigned int v12; // r7
  int v13; // r2
  int v14; // r8
  int v15; // r10
  int v16; // r0
  int v17; // r4
  int i; // r9
  int v19; // r8
  __int64 v20; // r2
  __int64 v21; // r0
  int v22; // r0
  unsigned int v23; // r9
  int v24; // r9
  _DWORD *v25; // r1
  int v26; // r0
  unsigned int v27; // r0
  unsigned int v28; // r5
  unsigned int *v29; // lr
  int v30; // r2
  int v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  int v34; // r0
  unsigned int v35; // r0
  unsigned int v36; // r0
  int v37; // r4
  int v38; // r2
  unsigned int v39; // r0
  unsigned int v40; // r3
  unsigned int v41; // r4
  int v42; // r1 OVERLAPPED
  int v43; // [sp+8h] [bp-60h] BYREF
  int v44; // [sp+Ch] [bp-5Ch] BYREF
  int v45; // [sp+10h] [bp-58h]
  int v46; // [sp+14h] [bp-54h]
  int v47; // [sp+18h] [bp-50h]
  int v48; // [sp+1Ch] [bp-4Ch]
  _DWORD *v49; // [sp+20h] [bp-48h]
  int v50[4]; // [sp+28h] [bp-40h] BYREF
  int v51[12]; // [sp+38h] [bp-30h] BYREF

  v6 = *a2 & 0xFFF;
  v49 = a3;
  if ( v6 )
    return sub_54E338();
  if ( (*a3 & 0xFFF) != 0 )
    return -1073741584;
  if ( !MmDynamicPfn )
    return -1073741637;
  v8 = *(_QWORD *)a2;
  v9 = a4 | 1;
  v47 = a4 | 1;
  v10 = v8 >> 12;
  v11 = *(__int64 *)a3 >> 12;
  v12 = v11 + v10;
  if ( v10 >= v11 + v10 )
    return sub_54E338();
  if ( v12 - 1 > dword_633850 )
  {
    if ( (v9 & 2) == 0 )
    {
      v12 = dword_633850 + 1;
      v11 = dword_633850 + 1 - v10;
      goto LABEL_7;
    }
    return -1073741584;
  }
LABEL_7:
  if ( v10 >= v12 )
    return sub_54E338();
  v13 = __mrc(15, 0, 13, 0, 3);
  v45 = 0;
  v14 = 0;
  v43 = 0;
  v50[2] = 0;
  v50[1] = (int)v50;
  v15 = 0;
  v50[0] = (int)v50;
  v48 = v13;
  v44 = 0;
  v16 = MiLockDynamicMemoryExclusive(MiSystemPartition, v13 & 0xFFFFFFC0);
  v17 = MiInitializeNumaRanges(v16);
  if ( v17 >= 0 )
  {
    v46 = v47 & 2;
    if ( (v47 & 2) == 0 )
    {
      if ( dword_640508 + v11 > dword_633810 )
      {
        v11 = dword_633810 - dword_640508;
        v12 = dword_633810 - dword_640508 + v10;
      }
      v45 = MiReferencePageRuns((int)MiSystemPartition, 1);
      if ( v10 >= v12 )
      {
        v17 = -1073741585;
        goto LABEL_39;
      }
      if ( !MiDescribePageRun(v50, v10, v11) )
        goto LABEL_55;
      v51[2] = v10;
      v51[3] = v11;
      v51[0] = 0;
      v17 = MiConfigureMemoryInsertion(&v43, MmPhysicalMemoryBlock, v51);
      if ( v17 < 0 )
      {
LABEL_54:
        v14 = v43;
        goto LABEL_39;
      }
      for ( i = v45; ; i = v44 )
      {
        v19 = v50[0];
        if ( (int *)v50[0] == v50 )
          break;
        v20 = *(_QWORD *)v50[0];
        if ( *(int **)(v50[0] + 4) != v50 || *(_DWORD *)(v20 + 4) != v50[0] )
          __fastfail(3u);
        v50[0] = *(_DWORD *)v50[0];
        *(_DWORD *)(v20 + 4) = v50;
        v17 = MiConfigureMemoryInsertion(&v44, i, v19);
        ExFreePoolWithTag(v19, 0);
        if ( i != v45 )
          ExFreePoolWithTag(i - 8, 0);
        v15 = v44;
        if ( v17 < 0 )
          goto LABEL_54;
      }
      v14 = v43;
    }
    HIDWORD(v21) = MmPfnDatabase + 24 * v12 - 1;
    LODWORD(v21) = MmPfnDatabase + 24 * v10;
    v22 = MiPageTablesNeeded(v21, 0);
    v23 = v22;
    if ( !v22 )
      goto LABEL_25;
    if ( MiChargeResident(MiSystemPartition, v22, 0) )
    {
      do
        v35 = __ldrex(&dword_634A2C[56]);
      while ( __strex(v35 + v23, &dword_634A2C[56]) );
      if ( !MiChargeCommit((int)MiSystemPartition, v23, 0) )
      {
        v17 = -1073741670;
        goto LABEL_62;
      }
LABEL_25:
      if ( v46 || MiIncreaseCommitLimits(MiSystemPartition, v11, v11, 0) )
      {
        v24 = v47;
        MiMapNewPfns(v10, v12, v47);
        v25 = v49;
        *v49 = v11 << 12;
        v25[1] = v11 >> 20;
        if ( v46 )
        {
LABEL_38:
          v17 = 0;
LABEL_39:
          MiUnlockDynamicMemoryExclusive(MiSystemPartition, v48 & 0xFFFFFFC0);
          if ( v14 )
            ExFreePoolWithTag(v14 - 8, 0);
          if ( v15 )
            ExFreePoolWithTag(v15 - 8, 0);
          while ( 1 )
          {
            v33 = v50[0];
            if ( (int *)v50[0] == v50 )
              break;
            *(_QWORD *)&v42 = *(_QWORD *)v50[0];
            if ( *(int **)(v50[0] + 4) != v50 || *(_DWORD *)(v42 + 4) != v50[0] )
              __fastfail(3u);
            v50[0] = v42;
            *(_DWORD *)(v42 + 4) = v50;
            ExFreePoolWithTag(v33, 0);
          }
          if ( !v46 )
          {
            v34 = MiDereferencePageRuns(v45);
            if ( v17 >= 0 )
              IoUpdateDumpPhysicalRanges(v34);
          }
          return v17;
        }
        v26 = MiPerformMemoryChange(v10, v11, &v43, &v44, v24);
        MiComputeNodeMemory(v26);
        do
          v27 = __ldrex((unsigned int *)0xFFFF92E8);
        while ( __strex(v27 + v11, (unsigned int *)0xFFFF92E8) );
        v28 = (v11 + 1023) >> 10;
        v29 = (unsigned int *)(dword_634C94 + 4 * (v10 >> 15));
        v30 = (v10 >> 10) & 0x1F;
        if ( v30 + v28 > 0x20 )
        {
          if ( v30 )
          {
            v37 = 32 - v30;
            __dmb(0xBu);
            v38 = ~(((1 << (32 - v30)) - 1) << v30);
            do
              v39 = __ldrex(v29);
            while ( __strex(v39 & v38, v29) );
            __dmb(0xBu);
            v28 -= v37;
            ++v29;
          }
          if ( v28 >= 0x20 )
          {
            v40 = v28 >> 5;
            do
            {
              v28 -= 32;
              --v40;
              *v29++ = 0;
            }
            while ( v40 );
          }
          if ( !v28 )
            goto LABEL_35;
          __dmb(0xBu);
          do
            v41 = __ldrex(v29);
          while ( __strex(v41 & ~((1 << v28) - 1), v29) );
        }
        else
        {
          if ( v28 == 32 )
          {
            *v29 = 0;
            goto LABEL_35;
          }
          __dmb(0xBu);
          v31 = ~(((1 << v28) - 1) << v30);
          do
            v32 = __ldrex(v29);
          while ( __strex(v32 & v31, v29) );
        }
        __dmb(0xBu);
LABEL_35:
        if ( (v24 & 4) == 0 )
          MiEnableNewPfns(v10, v12);
        KePulseEvent(dword_63F7E4, 0, 0);
        v14 = v43;
        v15 = v44;
        goto LABEL_38;
      }
      v17 = -1073741523;
      MiReturnCommit((int)MiSystemPartition, v23);
LABEL_62:
      if ( v23 )
      {
        MiReturnResidentAvailable(v23);
        do
          v36 = __ldrex(&dword_634A2C[60]);
        while ( __strex(v36 + v23, &dword_634A2C[60]) );
      }
      goto LABEL_39;
    }
LABEL_55:
    v17 = -1073741670;
    goto LABEL_39;
  }
  MiUnlockDynamicMemoryExclusive(MiSystemPartition, v48 & 0xFFFFFFC0);
  return v17;
}
