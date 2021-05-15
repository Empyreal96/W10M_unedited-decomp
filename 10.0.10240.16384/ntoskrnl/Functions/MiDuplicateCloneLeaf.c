// MiDuplicateCloneLeaf 
 
int __fastcall MiDuplicateCloneLeaf(unsigned int *a1, int *a2, int a3, int a4, unsigned __int8 a5)
{
  int v5; // lr
  unsigned int v7; // r6
  int v8; // r1
  int v9; // r9
  int v10; // r10
  unsigned int *v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r0
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r5
  unsigned int v17; // r1
  int v19; // r4
  char v20; // r3
  unsigned __int8 *v21; // r0
  unsigned int v22; // r2
  int v23; // r3
  unsigned int v24; // r2
  unsigned int *v25; // r2
  unsigned int v26; // r0
  int v27; // r10
  int v28; // r6
  unsigned int *v29; // r2
  unsigned int v30; // r0
  int v31; // r9
  int v32; // r3
  int v33; // r0
  int v34; // r2
  int v35; // r6
  unsigned __int8 *v36; // r1
  unsigned int v37; // r2
  int v38; // r3
  int v39; // r2
  unsigned int *v40; // r2
  unsigned int v41; // r0
  int v42; // [sp+0h] [bp-30h]
  unsigned int v44; // [sp+4h] [bp-2Ch]
  char v46; // [sp+Ch] [bp-24h]
  unsigned int v47; // [sp+10h] [bp-20h]

  v5 = a3;
  v7 = *a1;
  if ( (*a1 & 2) != 0 )
  {
    v8 = v7 >> 12;
    v9 = MmPfnDatabase + 24 * (v7 >> 12);
    v42 = (*(_DWORD *)(v9 + 8) >> 5) & 0x1F;
    v10 = 1;
LABEL_20:
    v19 = MmPfnDatabase + 24 * a3;
    if ( v10 == 1 )
    {
      v20 = 1;
    }
    else
    {
      v21 = (unsigned __int8 *)(v19 + 15);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x80, v21) );
      __dmb(0xBu);
      if ( v22 >> 7 )
      {
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v23 = *(_DWORD *)(v19 + 12);
            __dmb(0xBu);
          }
          while ( (v23 & 0x80000000) != 0 );
          do
            v24 = __ldrex(v21);
          while ( __strex(v24 | 0x80, v21) );
          __dmb(0xBu);
        }
        while ( v24 >> 7 );
        v20 = 4;
      }
      else
      {
        v20 = 4;
      }
    }
    MiCopyPage(v5, v8, 0, v20);
    if ( !v10 )
    {
      __dmb(0xBu);
      v25 = (unsigned int *)(v19 + 12);
      do
        v26 = __ldrex(v25);
      while ( __strex(v26 & 0x7FFFFFFF, v25) );
    }
    if ( (*(_BYTE *)(v9 + 19) & 8) != 0 )
      v46 = 5;
    else
      v46 = *(_BYTE *)(v9 + 19) & 7;
    v47 = *(unsigned __int8 *)(v9 + 18);
    if ( v10 == 1 )
    {
      v27 = a3;
      v28 = v7 & 0x1C | (32 * (v42 & 0x1F | (a3 << 7) | 0x40));
    }
    else
    {
      __dmb(0xBu);
      v29 = (unsigned int *)(v9 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      KfLowerIrql(a5);
      v27 = a3;
      v28 = v7 & 0xFFF | (a3 << 12);
    }
    if ( (unsigned int)(a2 + 0x10000000) > 0x3FFFFF )
    {
      *a2 = v28;
    }
    else
    {
      v31 = 0;
      v32 = *a2;
      __dmb(0xBu);
      *a2 = v28;
      if ( (v32 & 2) == 0 && (v28 & 2) != 0 )
        v31 = 1;
      if ( (unsigned int)(a2 + 267649024) <= 0xFFF )
      {
        v33 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v33, (_DWORD *)(v33 + 4 * ((unsigned __int16)a2 & 0xFFF)), v28);
      }
      if ( v31 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    if ( (*(_DWORD *)((((unsigned int)a2 >> 20) & 0xFFC) - 1070596096) & 0x402) == 1026 )
      v34 = (((unsigned int)a2 >> 12) & 0x3FF) + (*(_DWORD *)((((unsigned int)a2 >> 20) & 0xFFC) - 1070596096) >> 12);
    else
      v34 = *(_DWORD *)((((unsigned int)a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
    MiInitializePfnForOtherProcess(v27, (int)a1, v34, 16);
    *(_DWORD *)(v19 + 8) ^= ((unsigned __int16)*(_DWORD *)(v19 + 8) ^ (unsigned __int16)(32 * v42)) & 0x3E0;
    v35 = KfRaiseIrql(2);
    v36 = (unsigned __int8 *)(v19 + 15);
    do
      v37 = __ldrex(v36);
    while ( __strex(v37 | 0x80, v36) );
    while ( 1 )
    {
      __dmb(0xBu);
      if ( !(v37 >> 7) )
        break;
      do
      {
        __dmb(0xAu);
        __yield();
        v38 = *(_DWORD *)(v19 + 12);
        __dmb(0xBu);
      }
      while ( (v38 & 0x80000000) != 0 );
      do
        v37 = __ldrex(v36);
      while ( __strex(v37 | 0x80, v36) );
    }
    if ( *(unsigned __int8 *)(v19 + 18) >> 6 != v47 >> 6 )
      MiChangePageAttribute(v19, v47 >> 6, 3);
    *(_BYTE *)(v19 + 19) ^= (*(_BYTE *)(v19 + 19) ^ v46) & 7;
    *(_BYTE *)(v19 + 18) = *(_BYTE *)(v19 + 18) & 0xF8 | 6;
    v39 = *(_DWORD *)(v19 + 12);
    *(_DWORD *)(v19 + 12) = v39 & 0xC0000000 | ((v39 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
    if ( (v39 & 0x3FFFFFFF) == 1 )
      MiPfnShareCountIsZero(v19, 0);
    __dmb(0xBu);
    v40 = (unsigned int *)(v19 + 12);
    do
      v41 = __ldrex(v40);
    while ( __strex(v41 & 0x7FFFFFFF, v40) );
    KfLowerIrql(v35);
    return 1;
  }
  v8 = v7 >> 12;
  v9 = MmPfnDatabase + 24 * (v7 >> 12);
  if ( (*(_BYTE *)(v9 + 18) & 0x20) == 0 )
  {
    v42 = (v7 >> 5) & 0x1F;
    v10 = 0;
    goto LABEL_20;
  }
  v11 = (unsigned int *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 492);
  __dmb(0xBu);
  v12 = (unsigned int *)(v9 + 12);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 & 0x7FFFFFFF, v12) );
  MiUnlockWorkingSetExclusive((int)v11, a4);
  v44 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  ++*(_BYTE *)(v44 + 974);
  --*(_BYTE *)(v44 + 974);
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11);
  }
  else
  {
    v14 = (unsigned __int8 *)v11 + 3;
    do
      v15 = __ldrex(v14);
    while ( __strex(v15 | 0x80, v14) );
    __dmb(0xBu);
    if ( v15 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v11);
    while ( 1 )
    {
      v16 = *v11;
      if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v16 & 0x40000000) == 0 )
      {
        do
          v17 = __ldrex(v11);
        while ( v17 == v16 && __strex(v16 | 0x40000000, v11) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  return 0;
}
