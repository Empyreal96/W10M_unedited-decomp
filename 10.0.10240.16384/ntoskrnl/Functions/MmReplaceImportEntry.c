// MmReplaceImportEntry 
 
int __fastcall MmReplaceImportEntry(unsigned int a1, int a2)
{
  int *v4; // r0
  int v5; // r5
  unsigned int v6; // r0
  int result; // r0
  _DWORD *v8; // r7
  int v9; // r3
  unsigned int *v10; // r5
  int v11; // r9
  unsigned int v12; // r1
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r1
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r0
  unsigned int v20; // r1
  int v21; // r7
  int v22; // r8
  int v23; // r0
  int v24; // r4
  unsigned __int8 *v25; // r1
  unsigned int v26; // r2
  int v27; // r3
  unsigned int v28; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r4
  _DWORD *v31; // [sp+8h] [bp-28h] BYREF
  int v32; // [sp+Ch] [bp-24h]

  v32 = a2;
  if ( PsLoadedModuleList )
  {
    v4 = MiLookupDataTableEntry(a1, 0);
    v5 = (int)v4;
    if ( !v4 )
      KeBugCheckEx(26, 4116, 0, a1, a2);
    v6 = RtlImageDirectoryEntryToData(v4[6], 1, 12, (int)&v31);
    if ( !v6 || !v31 || a1 < v6 || a1 >= (unsigned int)v31 + v6 )
      KeBugCheckEx(26, 4116, v5, a1, a2);
  }
  result = (a1 >> 20) & 0xFFC;
  if ( (*(_DWORD *)(result - 1070596096) & 0x400) != 0 )
  {
    *(_DWORD *)a1 = a2;
  }
  else
  {
    v8 = (_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
    v31 = v8;
    if ( a1 >= dword_63389C
      && ((v9 = *((unsigned __int8 *)&MiState[2423] + ((int)(result - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
           v9 == 1)
       || v9 == 11) )
    {
      v10 = (unsigned int *)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 3248);
    }
    else
    {
      v10 = dword_634F00;
    }
    v11 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
LABEL_17:
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v10);
      goto LABEL_18;
    }
    v13 = (unsigned __int8 *)v10 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v10);
    while ( 1 )
    {
      v15 = *v10;
      if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v16 = __ldrex(v10);
        while ( v16 == v15 && __strex(v15 | 0x40000000, v10) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    while ( 1 )
    {
LABEL_18:
      while ( 1 )
      {
        v12 = *v8;
        if ( (*v8 & 2) != 0 )
          break;
        MiUnlockWorkingSetExclusive((int)v10, v11);
        v11 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
          goto LABEL_17;
        v17 = (unsigned __int8 *)v10 + 3;
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 | 0x80, v17) );
        __dmb(0xBu);
        if ( v18 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v10);
        while ( 1 )
        {
          v19 = *v10;
          if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v19 & 0x40000000) == 0 )
          {
            do
              v20 = __ldrex(v10);
            while ( v20 == v19 && __strex(v19 | 0x40000000, v10) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v21 = MmPfnDatabase + 24 * (v12 >> 12);
      if ( (*(_DWORD *)(v21 + 20) & 0x8000000) == 0 )
        break;
      v8 = v31;
      MiCopyOnWriteEx(a1, (unsigned int)v31, -1, v11, 0);
    }
    v22 = v32;
    if ( (v12 & 0x200) != 0 )
    {
      v23 = MiMapPageInHyperSpaceWorker(v12 >> 12, 0, 0x80000000);
      v24 = a1 & 0xFFF;
      *(_DWORD *)(v24 + v23) = v22;
      MiUnmapPageInHyperSpaceWorker(v23 + v24, 17, 0x80000000);
      v25 = (unsigned __int8 *)(v21 + 15);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 | 0x80, v25) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v26 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v27 = *(_DWORD *)(v21 + 12);
          __dmb(0xBu);
        }
        while ( (v27 & 0x80000000) != 0 );
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 | 0x80, v25) );
      }
      v28 = MiCaptureDirtyBitToPfn(v21);
      __dmb(0xBu);
      v29 = (unsigned int *)(v21 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      if ( v28 )
        MiReleasePageFileInfo((int)MiSystemPartition, v28, 1, 0);
    }
    else
    {
      *(_DWORD *)a1 = v32;
    }
    result = MiUnlockWorkingSetExclusive((int)v10, v11);
  }
  return result;
}
