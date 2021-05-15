// MiWorkingSetManager 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiWorkingSetManager(int a1, int a2)
{
  __int16 *v2; // r4 OVERLAPPED
  _DWORD *v4; // r5
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r0
  int v9; // r0
  int v11; // r3
  unsigned int v12; // r2
  unsigned int v13; // r1
  __int16 *v14; // r0
  int v15; // r6
  int (*v16)(); // r3
  __int64 v17; // kr00_8
  unsigned int v18; // r7
  unsigned int v19; // lr
  __int64 v20; // r0
  int (*v21)(); // r3

  v2 = MiSystemPartition;
  v4 = (_DWORD *)dword_6404B8;
  if ( !*(_DWORD *)(dword_6404B8 + 68) )
    v4[17] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  MiDeleteStaleCacheMaps();
  v5 = MiEmptyDecayClusterTimers((int)MiSystemPartition);
  v6 = v4[6] + 1;
  v7 = v4[7];
  v4[6] = v6;
  if ( v6 == v7 )
  {
    v4[6] = 0;
    v11 = ((unsigned __int8)v4[4] + 1) & 0xF;
    v4[4] = v11;
    if ( *(_DWORD *)&MiSystemPartition[10 * (((_BYTE)v11 - 8) & 0xF) + 1024] )
      return sub_516ED0(v5);
  }
  MiDeleteNoBlockStacks(1);
  if ( !a2 )
    KePulseEvent((int)&byte_634988, 0, 0);
  v8 = MiProcessWorkingSets(MiSystemPartition);
  v9 = MiAdjustPteBins(v8);
  MiAdjustCachedStacks(v9);
  MiFreePageFileHashPfns(MiSystemPartition);
  if ( (unsigned int)dword_640580 <= 0x400 )
  {
    v12 = dword_64050C;
    __dmb(0xBu);
    if ( v12 )
    {
      if ( dword_640718 && !dword_63F944 )
      {
        if ( (unsigned int)dword_63F948 >= 0x1E )
        {
          v13 = 0;
          v14 = MiSystemPartition;
          while ( 1 )
          {
            v15 = *((_DWORD *)v14 + 900);
            if ( *(_DWORD *)(v15 + 12) )
            {
              if ( (*(_WORD *)(v15 + 96) & 0x10) == 0 )
                break;
            }
            ++v13;
            v14 += 2;
            if ( v13 >= v12 )
            {
              if ( byte_63F87E == 1 )
              {
                byte_63F87E = 0;
                dword_63F948 = 0;
                v16 = MiScanPagefileSpace;
                *((_QWORD *)v2 + 72) = *(_QWORD *)(&v2 - 1);
                dword_63F938 = 0;
                ExQueueWorkItem(&dword_63F938, 2);
              }
              break;
            }
          }
        }
        else
        {
          ++dword_63F948;
        }
      }
    }
  }
  if ( MiNumberWsSwapPagefiles(MiSystemPartition) && !dword_63F96C )
  {
    __dmb(0xFu);
    do
    {
      v17 = MEMORY[0xFFFF93B0];
      while ( 1 )
      {
        v18 = MEMORY[0xFFFF900C];
        __dmb(0xBu);
        v19 = MEMORY[0xFFFF9008];
        __dmb(0xBu);
        if ( v18 == MEMORY[0xFFFF9010] )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    while ( v17 != MEMORY[0xFFFF93B0] );
    v20 = __PAIR64__(v18, v19) - v17;
    if ( __PAIR64__(v18, v19) - v17 - qword_63F970 >= 0x861C46800i64 )
    {
      if ( byte_63434D )
      {
        LODWORD(qword_63F970) = v20 + 1359738368;
        HIDWORD(qword_63F970) = __CFADD__((_DWORD)v20, 1359738368) + HIDWORD(v20) - 8;
      }
      else
      {
        v21 = MiTrimUnusedPageFileRegionsWorker;
        *((_QWORD *)v2 + 77) = *(_QWORD *)(&v2 - 1);
        dword_63F960 = 0;
        ExQueueWorkItem(&dword_63F960, 3);
      }
    }
  }
  MiAdjustModifiedPageLoad(MiSystemPartition, v4[302] >> 3, v4[22]);
  if ( dword_640680 > (unsigned int)dword_640718 && (unsigned int)(dword_640680 - dword_640718) >= 0x320 )
    KeSetEvent(&unk_63F8C4, 0, 0);
  return MiSignalLargePageRebuild(MiSystemPartition);
}
