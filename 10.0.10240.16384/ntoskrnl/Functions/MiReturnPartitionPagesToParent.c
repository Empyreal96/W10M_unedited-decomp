// MiReturnPartitionPagesToParent 
 
unsigned int __fastcall MiReturnPartitionPagesToParent(_DWORD *a1)
{
  __int16 *v2; // r6
  int v3; // r9
  unsigned int *v4; // r10
  int v5; // r7
  _DWORD *i; // r3
  int *v7; // r8
  int v8; // r3
  int *v9; // r3
  int v10; // r9
  int v11; // r7
  int v12; // lr
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  int v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r2
  int v24; // r4
  int v25; // r3
  int v26; // r2
  unsigned int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r2
  int v30; // r2
  unsigned int *v31; // r2
  unsigned int v32; // r0
  unsigned int *v33; // r2
  unsigned int v34; // r0
  unsigned int *v35; // r2
  unsigned int v36; // r0
  int v37; // r4
  unsigned int *v38; // r2
  unsigned int v39; // r0
  int v40; // r2
  int v41; // r1
  unsigned int v42; // r0
  int v43; // r3
  unsigned int *v44; // r2
  unsigned int v45; // r0
  unsigned int result; // r0
  int v47; // [sp+0h] [bp-40h]
  unsigned int v48; // [sp+4h] [bp-3Ch]
  int v49; // [sp+Ch] [bp-34h]
  int v50; // [sp+10h] [bp-30h]
  int v51; // [sp+14h] [bp-2Ch]
  _DWORD *v52; // [sp+18h] [bp-28h]
  int v53; // [sp+1Ch] [bp-24h]
  int v54; // [sp+20h] [bp-20h]
  int vars4; // [sp+44h] [bp+4h]

  v2 = (__int16 *)a1[3];
  v53 = *(unsigned __int16 *)a1;
  if ( !v2 )
    v2 = MiSystemPartition;
  v54 = (unsigned __int16)*v2;
  v3 = __mrc(15, 0, 13, 0, 3);
  v50 = v3;
  v51 = 0;
  v4 = a1 + 42;
LABEL_4:
  v5 = 0;
  v47 = 0;
  MiDrainZeroLookasides((int)a1, 0, 0, 0);
  MiLockDynamicMemoryExclusive((int)a1, v3 & 0xFFFFFFC0);
  v49 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4);
  }
  else
  {
    v19 = (unsigned __int8 *)v4 + 3;
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x80, v19) );
    __dmb(0xBu);
    if ( v20 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4);
    while ( 1 )
    {
      v21 = *v4;
      if ( (*v4 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v21 & 0x40000000) == 0 )
      {
        do
          v22 = __ldrex(v4);
        while ( v22 == v21 && __strex(v21 | 0x40000000, v4) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  for ( i = (_DWORD *)a1[7]; ; i = (_DWORD *)*v52 )
  {
    v52 = i;
    if ( !i )
      break;
    v7 = i + 7;
    v8 = i[5] >> 12;
    v48 = (unsigned int)&v7[v8];
    if ( v7 != (int *)v48 )
    {
      v9 = &v7[v8];
      while ( 1 )
      {
        v10 = *v7;
        if ( (*v7 & 0xC0000000) == 0 )
          break;
LABEL_115:
        if ( ++v7 == v9 )
          goto LABEL_116;
      }
      if ( (++v51 & 0xF) == 0 && ExSpinLockIsContended(v4) || KeShouldYieldProcessor() )
      {
        ++a1[9];
        if ( (dword_682604 & 0x10000) != 0 )
          goto LABEL_120;
        goto LABEL_121;
      }
      v11 = MmPfnDatabase + 24 * v10;
      v12 = KfRaiseIrql(2);
      v13 = (unsigned __int8 *)(v11 + 15);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 | 0x80, v13) );
      __dmb(0xBu);
      if ( v14 >> 7 )
      {
        v14 = v11 + 15;
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v15 = *(_DWORD *)(v11 + 12);
            __dmb(0xBu);
          }
          while ( (v15 & 0x80000000) != 0 );
          do
            v16 = __ldrex((unsigned __int8 *)v14);
          while ( __strex(v16 | 0x80, (unsigned __int8 *)v14) );
          __dmb(0xBu);
        }
        while ( v16 >> 7 );
      }
      if ( v53 )
      {
LABEL_22:
        __dmb(0xBu);
        v17 = (unsigned int *)(v11 + 12);
        do
          v18 = __ldrex(v17);
        while ( __strex(v18 & 0x7FFFFFFF, v17) );
        goto LABEL_24;
      }
      v23 = *(unsigned __int8 *)(v11 + 18);
      v24 = v23 & 7;
      if ( v24 == 5 )
      {
        ++a1[10];
        if ( (*(_BYTE *)(v11 + 19) & 0x40) != 0 && (*(_DWORD *)(v11 + 4) | 0x80000000) == -4 )
        {
          v25 = a1[11] + 1;
          a1[11] = v25;
          MiUnlinkPageFromBadList(v11, v14, v23, v25);
          if ( v2 != MiSystemPartition )
            ++*((_DWORD *)v2 + 898);
          --a1[898];
          MiInsertPageInList(v11, 32, v26);
          *v7 |= 0x40000000u;
          ++v47;
        }
        goto LABEL_22;
      }
      if ( (v23 & 7u) <= 1 )
      {
        if ( (*(_DWORD *)(v11 + 20) & 0xFFFFF) == 1048574 )
        {
          __dmb(0xBu);
          v27 = (unsigned int *)(v11 + 12);
          do
            v28 = __ldrex(v27);
          while ( __strex(v28 & 0x7FFFFFFF, v27) );
          KfLowerIrql(v12);
          v29 = 0;
          if ( (v10 & 0x3FF) == 0 && (unsigned int)(v7 + 1024) <= v48 )
          {
            do
            {
              if ( *v7 != v10 )
                break;
              ++v29;
              ++v10;
              ++v7;
            }
            while ( v29 < 0x400 );
            v4 = a1 + 42;
          }
          v7 -= v29;
          if ( v29 != 1024 )
          {
            MiDemoteLargeFreePage(v10 - v29);
            goto LABEL_54;
          }
          if ( v2 != MiSystemPartition )
            *((_DWORD *)v2 + 898) += 1024;
          if ( MiMoveLargeFreePage(v10 - 1024, a1) == 1 )
          {
            v30 = 1024;
            ++a1[12];
            do
            {
              *v7++ |= 0x40000000u;
              --v30;
            }
            while ( v30 );
            v47 += 1024;
            a1[898] -= 1024;
          }
          else
          {
            ++a1[13];
            if ( v2 != MiSystemPartition )
              *((_DWORD *)v2 + 898) -= 1024;
          }
          --v7;
LABEL_25:
          v5 = v47;
LABEL_114:
          v9 = (int *)v48;
          goto LABEL_115;
        }
        ++a1[14];
        MiUnlinkFreeOrZeroedPage(v10, 0);
        if ( v2 != MiSystemPartition )
          ++*((_DWORD *)v2 + 898);
        --a1[898];
        MiInsertPageInFreeOrZeroedList(v10, 2);
        __dmb(0xBu);
        v31 = (unsigned int *)(v11 + 12);
        do
          v32 = __ldrex(v31);
        while ( __strex(v32 & 0x7FFFFFFF, v31) );
LABEL_113:
        KfLowerIrql(v12);
        v5 = ++v47;
        *v7 |= 0x40000000u;
        goto LABEL_114;
      }
      if ( v24 == 7 )
      {
        ++a1[15];
LABEL_71:
        __dmb(0xBu);
        v33 = (unsigned int *)(v11 + 12);
        do
          v34 = __ldrex(v33);
        while ( __strex(v34 & 0x7FFFFFFF, v33) );
LABEL_24:
        KfLowerIrql(v12);
        goto LABEL_25;
      }
      if ( v24 == 2 )
      {
        if ( *(_WORD *)(v11 + 16) )
        {
          ++a1[16];
          goto LABEL_71;
        }
        if ( v2 != MiSystemPartition )
          ++*((_DWORD *)v2 + 898);
        if ( !MiRelinkStandbyPage(v11, 0xFFFFFF, v54) )
        {
          ++a1[17];
          if ( v2 != MiSystemPartition )
            --*((_DWORD *)v2 + 898);
          __dmb(0xBu);
          v35 = (unsigned int *)(v11 + 12);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 & 0x7FFFFFFF, v35) );
          KfLowerIrql(v12);
LABEL_54:
          --v7;
          goto LABEL_25;
        }
        --a1[898];
        if ( (*(_DWORD *)(v11 + 8) & 0x400) != 0 )
          ++a1[19];
        else
          ++a1[18];
      }
      else if ( (v23 & 7u) > 4 )
      {
        if ( (*(_DWORD *)(v11 + 8) & 0x400) != 0 )
        {
          ++a1[27];
        }
        else
        {
          v42 = MiCaptureDirtyBitToPfn(v11);
          if ( v42 )
          {
            v43 = a1[25] + 1;
            a1[25] = v43;
            MiReleasePageFileInfo((int)a1, v42, 1, v43);
          }
          else
          {
            ++a1[26];
          }
        }
        if ( v2 != MiSystemPartition )
          ++*((_DWORD *)v2 + 898);
        --a1[898];
      }
      else
      {
        if ( *(_WORD *)(v11 + 16) )
        {
          v37 = (unsigned __int8)(v23 & 8) >> 3;
          __dmb(0xBu);
          v38 = (unsigned int *)(v11 + 12);
          do
            v39 = __ldrex(v38);
          while ( __strex(v39 & 0x7FFFFFFF, v38) );
          KfLowerIrql(v12);
          if ( v37 )
          {
            ++a1[28];
            if ( (dword_682604 & 0x10000) != 0 )
            {
LABEL_120:
              ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4, vars4);
              goto LABEL_122;
            }
LABEL_121:
            __dmb(0xBu);
            *v4 = 0;
LABEL_122:
            KfLowerIrql(v49);
            v3 = v50;
            MiUnlockDynamicMemoryExclusive((int)a1, v50 & 0xFFFFFFC0);
            goto LABEL_4;
          }
          ++a1[20];
          goto LABEL_25;
        }
        MiUnlinkPageFromList(v11, 0);
        if ( v24 == 3 )
        {
          ++a1[21];
          v41 = 8;
        }
        else
        {
          ++a1[22];
          v41 = 16;
        }
        if ( (*(_DWORD *)(v11 + 8) & 0x400) != 0 )
          ++a1[24];
        else
          ++a1[23];
        if ( v2 != MiSystemPartition )
          ++*((_DWORD *)v2 + 898);
        --a1[898];
        MiInsertPageInList(v11, v41, v40);
      }
      __dmb(0xBu);
      v44 = (unsigned int *)(v11 + 12);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 & 0x7FFFFFFF, v44) );
      goto LABEL_113;
    }
LABEL_116:
    ;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v4, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v49);
  MiUnlockDynamicMemoryExclusive((int)a1, v50 & 0xFFFFFFC0);
  do
    result = __ldrex((unsigned int *)algn_634344);
  while ( __strex(result - v5, (unsigned int *)algn_634344) );
  return result;
}
