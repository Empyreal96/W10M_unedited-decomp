// MiChangePageAttributeBatch 
 
int __fastcall MiChangePageAttributeBatch(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int result; // r0
  unsigned int v7; // r7
  int v8; // r10
  int v9; // r4
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  int v12; // r1
  int v13; // r2
  int v14; // r8
  int v15; // r4
  unsigned int v16; // r3
  unsigned int v17; // r6
  int v18; // r3
  __int64 v19; // r0
  int v20; // r2
  int v21; // r5
  unsigned int i; // r3
  unsigned int *v23; // r2
  int v24; // r2
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  int v28; // [sp+0h] [bp-C8h]
  int v29; // [sp+4h] [bp-C4h]
  int v30; // [sp+10h] [bp-B8h] BYREF
  char v31; // [sp+14h] [bp-B4h]
  char v32; // [sp+15h] [bp-B3h]
  int v33; // [sp+18h] [bp-B0h]
  int v34; // [sp+1Ch] [bp-ACh]
  int v35; // [sp+20h] [bp-A8h]
  int v36; // [sp+24h] [bp-A4h]
  int varg_r0; // [sp+D0h] [bp+8h]
  int varg_r1; // [sp+D4h] [bp+Ch]
  int varg_r2; // [sp+D8h] [bp+10h]
  int varg_r3; // [sp+DCh] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v4 = a1;
  result = 17;
  v28 = v4;
  v29 = 17;
  while ( v4 )
  {
    v7 = 0;
    v8 = 1;
    v9 = v4;
    do
    {
      if ( v7 >= 0x1000 )
        break;
      if ( v7 )
      {
        v10 = (unsigned __int8 *)(v9 + 15);
        do
          v11 = __ldrex(v10);
        while ( __strex(v11 | 0x80, v10) );
        __dmb(0xBu);
        if ( v11 >> 7 )
          break;
      }
      else
      {
        v29 = KfRaiseIrql(2);
        v25 = (unsigned __int8 *)(v9 + 15);
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 | 0x80, v25) );
        __dmb(0xBu);
        if ( v26 >> 7 )
          return sub_53AC08();
      }
      if ( (*(_BYTE *)(v9 + 18) & 0xC0) != 192 )
        v8 = 0;
      result = MiAbortCombineScan(v9);
      v9 = *(_DWORD *)(v9 + 8);
      ++v7;
    }
    while ( v9 );
    v4 = v28;
    if ( !v8 )
    {
      ++dword_63381C;
      result = KeFlushTb(3, 2);
      if ( v7 >= dword_633828 && a2 != 1 )
        result = KeInvalidateAllCaches(result, v12, v13, ++dword_633820);
    }
    v14 = 0;
    v15 = v28;
    if ( !v28 )
      break;
    do
    {
      v16 = *(unsigned __int8 *)(v15 + 18);
      *(_BYTE *)(v15 + 18) = v16 & 0x3F | ((_BYTE)a2 << 6);
      if ( v7 < dword_633828 && a2 != 1 && v16 >> 6 == 1 && !v8 )
      {
        ++dword_633824;
        v34 = 0;
        v35 = 0;
        v30 = 0;
        v31 = 0;
        v32 = 0;
        v33 = 33;
        v36 = 0;
        v17 = (v15 - MmPfnDatabase) / 24;
        if ( a2 == 2 )
          v18 = 2;
        else
          v18 = 0;
        v19 = MiMapPageInHyperSpaceWorker(v17, 0, v18 | 0xC0000000);
        v21 = v19;
        if ( (KeFeatureBits & 0x100) != 0 )
        {
          KeInvalidateAllCaches(v19, SHIDWORD(v19), v20, KeFeatureBits);
        }
        else
        {
          for ( i = v19 & ~(KiMinimumDcacheLine - 1); i < (int)v19 + 4096; i += KiMinimumDcacheLine )
            __mcr(15, 0, i, 7, 14, 1);
          __dsb(0xFu);
          if ( (KiCacheType & 0xC000) == 49152 )
            KiVoidIcacheRangePoUWithCatch(v19, 4096);
          else
            __mcr(15, 0, 0, 7, 1, 0);
          __mcr(15, 0, 0, 7, 5, 6);
          __dsb(0xFu);
          __isb(0xFu);
          __mcr(15, 0, 0, 7, 5, 6);
          __dsb(0xFu);
          __isb(0xFu);
          off_617AB8(v17 << 12, v17 >> 20);
        }
        MiUnmapPageInHyperSpaceWorker(v21, 17, 0x80000000);
        if ( a2 == 3 )
        {
          MiInsertTbFlushEntry(&v30, v21, 1);
          MiFlushTbList(&v30);
        }
        v4 = v28;
      }
      ++v14;
      *(_DWORD *)(v15 + 12) &= 0xFF0FFFFF;
      __dmb(0xBu);
      v23 = (unsigned int *)(v15 + 12);
      if ( v14 == v7 )
      {
        do
          v27 = __ldrex(v23);
        while ( __strex(v27 & 0x7FFFFFFF, v23) );
        result = KfLowerIrql(v29);
        v4 = *(_DWORD *)(v15 + 8);
        v24 = 0;
        v28 = v4;
      }
      else
      {
        do
          result = __ldrex(v23);
        while ( __strex(result & 0x7FFFFFFF, v23) );
        v24 = *(_DWORD *)(v15 + 8);
      }
      if ( varg_r2 != -1 )
        *(_DWORD *)(v15 + 8) = varg_r2;
      v15 = v24;
    }
    while ( v24 );
  }
  return result;
}
