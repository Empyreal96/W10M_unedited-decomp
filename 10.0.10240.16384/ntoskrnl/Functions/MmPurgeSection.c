// MmPurgeSection 
 
int __fastcall MmPurgeSection(int *a1, __int64 *a2, int a3, char a4)
{
  unsigned int *v4; // r5
  _DWORD *v7; // r0
  int v8; // r4
  _DWORD *v9; // r8
  unsigned int *v11; // lr
  int v12; // r5
  unsigned int v13; // r4
  int v14; // r6
  int v15; // r7
  int v16; // r1
  int v17; // r2
  unsigned __int8 *v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // lr
  unsigned int v21; // r0
  unsigned int v22; // r7
  int v23; // r6
  int v24; // r2
  int v25; // r0
  int v26; // r5
  int v27; // r3
  int v28; // r0
  unsigned __int8 *v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r0
  int v32; // r3
  int v33; // r2
  unsigned int v34; // r1
  unsigned int *v35; // r2
  unsigned int v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r0
  unsigned int v39; // r1
  int v40; // r0
  char v41[4]; // [sp+8h] [bp-60h] BYREF
  int i; // [sp+Ch] [bp-5Ch]
  int v43; // [sp+10h] [bp-58h]
  int v44; // [sp+14h] [bp-54h]
  int v45; // [sp+18h] [bp-50h]
  int v46; // [sp+1Ch] [bp-4Ch]
  unsigned __int8 *v47; // [sp+20h] [bp-48h]
  int v48; // [sp+24h] [bp-44h]
  __int64 v49; // [sp+28h] [bp-40h] BYREF
  char v50[4]; // [sp+30h] [bp-38h] BYREF
  unsigned int v51; // [sp+34h] [bp-34h]
  int v52; // [sp+38h] [bp-30h]
  int v53; // [sp+3Ch] [bp-2Ch]
  int v54; // [sp+40h] [bp-28h]

  v4 = (unsigned int *)a2;
  if ( a2 )
  {
    v4 = (unsigned int *)&v49;
    v49 = *a2;
  }
  v48 = a4 & 2;
  v46 = 0;
  v7 = (_DWORD *)MiCanFileBeTruncatedInternal(a1, v4, 1, v48 != 0, v41);
  v8 = (unsigned __int8)v41[0];
  v9 = v7;
  if ( v41[0] == 17 )
    return 0;
  if ( !v7 )
    return 1;
  if ( (a4 & 1) == 0 && v7[12] || !v7[8] )
    return sub_5380C4();
  v7[7] |= 0x8000u;
  if ( !MiComputeDataFlushRange(v7, v8, v4, a3, 1, v50) )
    return 1;
  v11 = v9 + 9;
  v47 = (unsigned __int8 *)v9 + 39;
  v12 = 17;
  v13 = v51;
  v14 = v53;
  v15 = v54;
  v16 = 1;
  LODWORD(v49) = (char *)v9 + 39;
  v43 = 1;
LABEL_11:
  v17 = v52;
  v44 = v14;
  if ( v12 == 17 )
  {
    v12 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 9);
    }
    else
    {
      v18 = v47;
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 | 0x80, v18) );
      __dmb(0xBu);
      if ( v19 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v9 + 9);
      v20 = v9 + 9;
      while ( 1 )
      {
        v21 = *v20;
        if ( (*v20 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v21 & 0x40000000) == 0 )
        {
          do
            v34 = __ldrex(v20);
          while ( v34 == v21 && __strex(v21 | 0x40000000, v20) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v16 = v43;
    v17 = v52;
    v11 = v9 + 9;
  }
  if ( v15 == v14 )
    v22 = v17 + 4;
  else
    v22 = *(_DWORD *)(v14 + 4) + 4 * *(_DWORD *)(v14 + 28);
  if ( *(_DWORD *)(v14 + 4) )
  {
    ++*(_DWORD *)(v14 + 60);
    if ( (*(_WORD *)(v14 + 18) & 8) != 0 )
    {
      MiRemoveUnusedSubsection(v14);
      v11 = v9 + 9;
    }
    *(_WORD *)(v14 + 16) |= 1u;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v11);
    }
    else
    {
      __dmb(0xBu);
      *v11 = 0;
    }
    KfLowerIrql(v12);
    v23 = 17;
    v24 = 0;
    v45 = 0;
    v41[0] = 17;
    for ( i = 0; ; v24 = i )
    {
      if ( v13 >= v22 )
      {
LABEL_49:
        if ( v23 != 17 )
          MiUnlockProtoPoolPage(v24, v23);
        v14 = v44;
        if ( v45 == 1 )
          MiDeleteFileExtents(*(_DWORD *)(v44 + 12), 0, *(_DWORD *)(v44 + 28), 1);
        v12 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 9);
          v11 = v9 + 9;
        }
        else
        {
          v29 = (unsigned __int8 *)v49;
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 | 0x80, v29) );
          __dmb(0xBu);
          if ( v30 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v9 + 9);
          v11 = v9 + 9;
          while ( 1 )
          {
            v31 = *v11;
            if ( (*v11 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v31 & 0x40000000) == 0 )
            {
              do
                v39 = __ldrex(v11);
              while ( v39 == v31 && __strex(v31 | 0x40000000, v11) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v32 = *(_DWORD *)(v14 + 60) - 1;
        *(_DWORD *)(v14 + 60) = v32;
        if ( !v32 && (*(_WORD *)(v14 + 18) & 1) == 0 )
        {
          v40 = MiInsertUnusedSubsection(v14, 1);
          v11 = v9 + 9;
          v46 += v40;
        }
        v16 = v43;
        v15 = v54;
LABEL_62:
        if ( v14 == v15 || !v16 )
          goto LABEL_63;
        v14 = *(_DWORD *)(v14 + 8);
        v13 = *(_DWORD *)(v14 + 4);
        goto LABEL_11;
      }
      if ( v23 != 17 && (v13 & 0xFFF) != 0 )
        goto LABEL_31;
      if ( v23 != 17 )
        MiUnlockProtoPoolPage(v24, v23);
      v28 = MiCheckProtoPtePageState(v13, v41);
      v23 = (unsigned __int8)v41[0];
      i = v28;
      if ( v28 )
      {
LABEL_31:
        v25 = MiLockLeafPage(v13, 0);
        v26 = v25;
        if ( !v25 )
        {
          if ( (v9[7] & 0x40000000) != 0 && MiPurgeFileExtentPage(v44, v13) == 1 )
            v45 = 1;
LABEL_40:
          v13 += 4;
          continue;
        }
        if ( (*(_DWORD *)v13 & 2) != 0 )
        {
          __dmb(0xBu);
          v37 = (unsigned int *)(v25 + 12);
          do
            v38 = __ldrex(v37);
          while ( __strex(v38 & 0x7FFFFFFF, v37) );
          goto LABEL_90;
        }
        v27 = *(_DWORD *)(v25 + 8);
        if ( (v27 & 0x400) == 0 || (v27 & 2) != 0 || (*(_DWORD *)(v25 + 4) | 0x80000000) != v13 )
          KeBugCheckEx(222, 2, v13);
        if ( (*(_BYTE *)(v25 + 18) & 0x10) != 0 && v48 )
        {
          __dmb(0xBu);
          v35 = (unsigned int *)(v25 + 12);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 & 0x7FFFFFFF, v35) );
LABEL_90:
          v43 = 0;
LABEL_48:
          v24 = i;
          goto LABEL_49;
        }
        if ( (*(_BYTE *)(v25 + 18) & 8) == 0 )
        {
          if ( (v9[7] & 0x40000000) != 0 && MiPurgeFileExtentPage(v44, v13) == 1 )
            v45 = 1;
          MiDeleteLockedTransitionPte(v13, v26, 17, 1);
          if ( !v9[4] )
            goto LABEL_48;
          goto LABEL_40;
        }
        MiWaitForPageWriteCompletion(v25, v9, i, v23);
        v23 = 17;
        v41[0] = 17;
      }
      else
      {
        v13 = (v13 & 0xFFFFF000) + 4096;
      }
    }
  }
  v15 = v54;
  if ( v14 != v54 && v16 )
    goto LABEL_62;
LABEL_63:
  MiDecrementSubsections(v53);
  MiDecrementSubsections(v15);
  v33 = v9[5] - 1;
  v9[7] &= 0xFFFFFFFB;
  v9[5] = v33;
  MiCheckControlArea(v9, v12);
  return v43;
}
