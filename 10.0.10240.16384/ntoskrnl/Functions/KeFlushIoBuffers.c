// KeFlushIoBuffers 
 
int *__fastcall KeFlushIoBuffers(int a1, int a2, int a3)
{
  int v3; // r4
  int *result; // r0
  int v7; // lr
  unsigned int v8; // r7
  int v9; // r10
  int *v10; // r9
  int v11; // r1
  unsigned int v12; // r4
  BOOL v13; // r10
  int v14; // r7
  unsigned int v15; // r4
  unsigned int i; // r3
  unsigned int k; // r3
  int *v18; // r2
  int v19; // r2
  int v20; // r5
  void **v21; // r1
  int v22; // t1
  int v23; // r5
  unsigned int v24; // r2
  unsigned int v25; // r2
  unsigned int j; // r3
  unsigned int v27; // r2
  int v29; // [sp+Ch] [bp-4Ch]
  int v30; // [sp+14h] [bp-44h]
  int v31; // [sp+1Ch] [bp-3Ch]

  v3 = a1;
  v29 = a2;
  result = (int *)KeGetCurrentIrql(a1);
  v7 = (unsigned __int8)KiExternalCachePresent;
  v31 = 0;
  v30 = (unsigned __int8)KiExternalCachePresent;
  v8 = (unsigned int)result;
  if ( (dword_682610 & 0x4000000) != 0 )
    return (int *)sub_51C530();
  v9 = 1;
  if ( !a3 && !a2 )
    return result;
  if ( (*(_WORD *)(v3 + 6) & 5) != 0 )
  {
    v10 = *(int **)(v3 + 12);
  }
  else
  {
    result = (int *)MmMapLockedPagesSpecifyCache(v3, 0, 1, 0, 0, 1073741856);
    v7 = v30;
    v10 = result;
  }
  if ( v10 )
    v9 = 0;
  v11 = v29;
  v12 = *(_DWORD *)(v3 + 20);
  if ( v29 )
  {
    if ( v12 <= KiCacheFlushReadPromoteThreshold )
      goto LABEL_10;
    v18 = &KiCacheFlushReadPromoteCount;
  }
  else
  {
    if ( v12 <= KiCacheFlushWritePromoteThreshold )
      goto LABEL_10;
    v18 = &KiCacheFlushWritePromoteCount;
  }
  v9 = 1;
  ++*v18;
LABEL_10:
  if ( KiCacheFlushForcePromote )
  {
    v9 = 1;
LABEL_39:
    if ( v8 == 15 )
    {
      if ( !v10 )
        KeBugCheckEx(85, 784, 2989);
      v9 = 0;
    }
    goto LABEL_12;
  }
  if ( v9 )
    goto LABEL_39;
LABEL_12:
  if ( !v9 )
  {
    if ( a3 != 1 )
      return result;
    v13 = KiExternalCachePresent && v12 >= KiExternalCacheQuiesceThreshold && v8 <= 2;
    result = &KiExternalCacheFlushOutstanding;
    if ( v13 )
    {
      if ( v8 >= 2 )
      {
        v14 = 0;
      }
      else
      {
        v14 = KfRaiseIrql(2);
        v31 = 1;
      }
      v19 = (unsigned __int16)KeNumberNodes;
      v20 = 0;
      if ( KeNumberNodes )
      {
        v21 = &KeNodeBlock;
        do
        {
          v22 = (int)*v21++;
          v20 |= *(_DWORD *)(v22 + 128);
          --v19;
        }
        while ( v19 );
      }
      v23 = dword_681D78[0] & ~v20 & ~(1 << *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594));
      do
        v24 = __ldrex((unsigned int *)&KiExternalCacheFlushOutstanding);
      while ( __strex(v24 + 1, (unsigned int *)&KiExternalCacheFlushOutstanding) );
      while ( v23 )
      {
        v25 = __clz(__rbit(v23));
        v23 &= ~(1 << v25);
        KiInsertQueueDpc(&KiExternalCacheQuiesceDpc[32 * v25]);
      }
      v11 = v29;
      result = &KiExternalCacheFlushOutstanding;
      v7 = v30;
    }
    else
    {
      v14 = 0;
    }
    if ( v11 )
    {
      if ( ((KeLargestCacheLine - 1) & (unsigned int)v10) != 0 )
        KeBugCheck2(230, 31, 4, v10, a1, 0);
      if ( ((KeLargestCacheLine - 1) & v12) != 0 )
        KeBugCheck2(230, 31, 5, v12, a1, 0);
      v15 = (unsigned int)v10 + v12;
      for ( i = (unsigned int)v10 & ~(KiMinimumDcacheLine - 1); i < v15; i += KiMinimumDcacheLine )
        __mcr(15, 0, i, 7, 6, 1);
      __dsb(0xFu);
      if ( !v7 )
        goto LABEL_24;
      off_617A80(a1, 1);
      for ( j = (unsigned int)v10 & ~(KiMinimumDcacheLine - 1); j < v15; j += KiMinimumDcacheLine )
        __mcr(15, 0, j, 7, 6, 1);
      __dsb(0xFu);
    }
    else
    {
      for ( k = (unsigned int)v10 & ~(KiMinimumDcacheLine - 1); k < (unsigned int)v10 + v12; k += KiMinimumDcacheLine )
        __mcr(15, 0, k, 7, 10, 1);
      __dsb(0xFu);
      if ( !v7 )
        goto LABEL_24;
      off_617A80(a1, 0);
    }
    result = &KiExternalCacheFlushOutstanding;
LABEL_24:
    if ( v13 )
    {
      do
        v27 = __ldrex((unsigned int *)&KiExternalCacheFlushOutstanding);
      while ( __strex(v27 - 1, (unsigned int *)&KiExternalCacheFlushOutstanding) );
      if ( v31 )
        result = (int *)KfLowerIrql(v14);
    }
    return result;
  }
  if ( a3 == 1 )
  {
    if ( v29 )
      result = (int *)KeInvalidateAllCaches(result, v29, 0);
    else
      result = (int *)KiCleanAllCaches(result, 0, 0);
  }
  return result;
}
