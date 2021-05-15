// MiDeleteSegmentPages 
 
int __fastcall MiDeleteSegmentPages(int *a1)
{
  int v1; // r3
  int v2; // r10
  int v3; // r6
  int v4; // r0
  int v5; // r9
  _DWORD *v6; // r4
  unsigned int v7; // r5
  unsigned int v8; // r10
  unsigned int v9; // r4
  int v10; // r7
  unsigned int v11; // r1
  int v12; // r0
  unsigned int *v13; // r4
  int v14; // r6
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  int v17; // r9
  unsigned int v18; // r0
  int v19; // r5
  unsigned __int8 *v21; // r1
  unsigned int v22; // r3
  int v23; // r6
  int v24; // r5
  unsigned int v25; // r4
  int v26; // r0
  unsigned __int8 *v27; // r1
  int v28; // r3
  unsigned int v29; // r2
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // r2
  int v33; // r4
  int v34; // r0
  unsigned int *v35; // r2
  unsigned int v36; // r0
  unsigned int v37; // lr
  unsigned int v38; // r1
  unsigned int *v39; // r5
  unsigned int v40; // r2
  unsigned int v41; // r0
  unsigned int v42; // r0
  unsigned int v43; // r3
  int v44; // r2
  unsigned int v45; // r4
  int v46; // r0
  unsigned int v47; // r1
  unsigned __int8 *v48; // r3
  unsigned int v49; // r1
  unsigned int v50; // r0
  unsigned int v51; // r1
  unsigned int v52; // r4
  char v53[4]; // [sp+0h] [bp-50h] BYREF
  int v54; // [sp+4h] [bp-4Ch]
  int v55; // [sp+8h] [bp-48h]
  unsigned int v56; // [sp+Ch] [bp-44h]
  _DWORD *v57; // [sp+10h] [bp-40h]
  int v58; // [sp+14h] [bp-3Ch]
  int v59; // [sp+18h] [bp-38h]
  int *v60; // [sp+1Ch] [bp-34h]
  int v61; // [sp+20h] [bp-30h]
  unsigned int v62; // [sp+24h] [bp-2Ch]
  int v63; // [sp+28h] [bp-28h]
  int v64; // [sp+2Ch] [bp-24h]

  v1 = *a1;
  v2 = (int)a1;
  v60 = a1;
  v64 = v1;
  v3 = a1[7];
  v4 = 0;
  v59 = *(_DWORD *)(v1 + 8);
  v58 = 0;
  v5 = 17;
  v6 = (_DWORD *)(v2 + 80);
  v61 = 0x40000000;
  v54 = 0;
  v55 = 0;
  v53[0] = 17;
  v56 = -1;
  v57 = (_DWORD *)(v2 + 80);
  v63 = v3;
  if ( v2 == -80 )
  {
LABEL_23:
    v13 = (unsigned int *)(v2 + 36);
    v14 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2 + 36);
      v17 = v61;
    }
    else
    {
      v15 = (unsigned __int8 *)(v2 + 39);
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v2 + 36));
      v17 = 0x40000000;
      while ( 1 )
      {
        v18 = *v13;
        if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v18 & 0x40000000) == 0 )
        {
          do
            v47 = __ldrex(v13);
          while ( v47 == v18 && __strex(v18 | 0x40000000, v13) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    while ( *(_DWORD *)(v2 + 16) )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 36);
      }
      else
      {
        __dmb(0xBu);
        *v13 = 0;
      }
      KfLowerIrql(v14);
      __dmb(0xAu);
      __yield();
      v14 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2 + 36);
      }
      else
      {
        v48 = (unsigned __int8 *)(v2 + 39);
        do
          v49 = __ldrex(v48);
        while ( __strex(v49 | 0x80, v48) );
        __dmb(0xBu);
        if ( v49 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v2 + 36));
        while ( 1 )
        {
          v50 = *v13;
          if ( (*v13 & ~v17) == 0x80000000 )
            break;
          if ( (v50 & v17) == 0 )
          {
            do
              v51 = __ldrex(v13);
            while ( v51 == v50 && __strex(v50 | v17, v13) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 36);
    }
    else
    {
      __dmb(0xBu);
      *v13 = 0;
    }
    KfLowerIrql(v14);
    v19 = *(_DWORD *)(v64 + 12);
    if ( !v19 )
      return v58;
    v23 = v19 - v55;
    MiReturnCommit(MiSystemPartition, v19 - v55);
    if ( (v59 & 0x1000) != 0 )
    {
      MiReturnResidentAvailable(v23);
      do
        v52 = __ldrex(&dword_634A2C[40]);
      while ( __strex(v52 + v23, &dword_634A2C[40]) );
    }
    v24 = -v19;
    do
      v25 = __ldrex((unsigned int *)&dword_634DAC);
    while ( __strex(v25 + v24, (unsigned int *)&dword_634DAC) );
    return v58;
  }
  v62 = 0x3FFFFF;
  while ( 1 )
  {
    v7 = v6[1];
    if ( v7 )
      break;
LABEL_21:
    v6 = (_DWORD *)v6[2];
    v57 = v6;
    if ( !v6 )
    {
      v2 = (int)v60;
      goto LABEL_23;
    }
  }
  v8 = v7 + 4 * v6[7];
  if ( v7 >= v8 )
  {
LABEL_14:
    if ( v5 != 17 )
    {
      MiUnlockProtoPoolPage(v4, v5);
      v5 = 17;
      v53[0] = 17;
      if ( (v59 & 0x1000) != 0 )
      {
        v37 = v56 & 0xFFFFFC00;
        if ( ((*(char *)(((v56 & 0xFFFFFC00) >> 13) + dword_634C94) >> (((v56 & 0xFFFFFC00) >> 10) & 7)) & 1) != 0 )
        {
          v38 = ((v56 & 0xFFFFFC00) >> 10) & 0x1F;
          v39 = (unsigned int *)(dword_634C94 + 4 * ((v56 & 0xFFFFFC00) >> 15));
          LOBYTE(v40) = 1;
          if ( v38 + 1 > 0x20 )
          {
            if ( !v38 )
              goto LABEL_93;
            __dmb(0xBu);
            do
              v42 = __ldrex(v39);
            while ( __strex(v42 & ~(((1 << (32 - v38)) - 1) << v38), v39) );
            __dmb(0xBu);
            v40 = v38 - 31;
            ++v39;
            if ( v38 - 31 >= 0x20 )
            {
              v43 = v40 >> 5;
              do
              {
                v40 -= 32;
                --v43;
                *v39++ = 0;
              }
              while ( v43 );
            }
            if ( v40 )
            {
LABEL_93:
              __dmb(0xBu);
              v44 = ~((1 << v40) - 1);
              do
                v45 = __ldrex(v39);
              while ( __strex(v45 & v44, v39) );
              __dmb(0xBu);
            }
            v6 = v57;
          }
          else
          {
            __dmb(0xBu);
            do
              v41 = __ldrex(v39);
            while ( __strex(v41 & ~(1 << v38), v39) );
            __dmb(0xBu);
          }
        }
        v46 = MiFreeLargePageMemory(v37);
        v55 = v55 - v46 + 1024;
        v56 = -1;
      }
    }
    if ( (v3 & 0x80) != 0 && (v3 & 0x20) == 0 )
    {
      v12 = v6[1];
      --v6[15];
      if ( v12 )
        ExFreePoolWithTag(v12, 0);
    }
    v4 = v54;
    goto LABEL_21;
  }
  while ( 1 )
  {
    if ( v5 != 17 && (v7 & 0xFFF) != 0 )
      goto LABEL_7;
    if ( v5 != 17 )
    {
      v26 = MiUnlockProtoPoolPage(v4, v5);
      if ( (v59 & 0x1000) != 0 )
        return sub_537CA4(v26);
    }
    while ( 1 )
    {
      v54 = MiLockProtoPoolPage(v7, v53);
      if ( v54 )
        break;
      MmAccessFault(1, v7, 0, 0);
    }
    v5 = (unsigned __int8)v53[0];
LABEL_7:
    while ( 1 )
    {
      v9 = *(_DWORD *)v7;
      if ( (*(_DWORD *)v7 & 2) == 0 && ((v9 & 0x400) != 0 || (v9 & 0x800) == 0) )
        break;
      if ( MI_IS_PFN(v9 >> 12) )
      {
        v10 = MmPfnDatabase + 24 * (v9 >> 12);
        v21 = (unsigned __int8 *)(v10 + 15);
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 | 0x80, v21) );
        __dmb(0xBu);
        if ( v22 >> 7 )
        {
          v27 = (unsigned __int8 *)(v10 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v28 = *(_DWORD *)(v10 + 12);
              __dmb(0xBu);
            }
            while ( (v28 & 0x80000000) != 0 );
            do
              v29 = __ldrex(v27);
            while ( __strex(v29 | 0x80, v27) );
            __dmb(0xBu);
          }
          while ( v29 >> 7 );
        }
        if ( *(_DWORD *)v7 == v9 )
          goto LABEL_10;
        __dmb(0xBu);
        v30 = (unsigned int *)(v10 + 12);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 & 0x7FFFFFFF, v30) );
      }
    }
    v10 = 0;
LABEL_10:
    v11 = *(_DWORD *)v7;
    if ( (*(_DWORD *)v7 & 2) != 0 )
    {
      v56 = v11 >> 12;
      v32 = *(_DWORD *)(v10 + 8);
      if ( v7 + 0x40000000 > v62 )
      {
        *(_DWORD *)v7 = v32;
      }
      else
      {
        v33 = 0;
        __dmb(0xBu);
        *(_DWORD *)v7 = v32;
        if ( (v11 & 2) == 0 && (v32 & 2) != 0 )
          v33 = 1;
        if ( v7 + 1070596096 <= 0xFFF )
        {
          v34 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v34, v34 + 4 * (v7 & 0xFFF), v32);
        }
        if ( v33 == 1 )
        {
          __dsb(0xFu);
          __isb(0xFu);
        }
      }
      *(_DWORD *)(v10 + 12) |= v61;
      __dmb(0xBu);
      v35 = (unsigned int *)(v10 + 12);
      do
        v36 = __ldrex(v35);
      while ( __strex(v36 & 0x7FFFFFFF, v35) );
    }
    else if ( (v11 & 0x400) == 0 )
    {
      if ( (v11 & 0x800) != 0 )
      {
        if ( (*(_DWORD *)(v10 + 8) & 0x400) != 0
          && (v60[7] & 0x20) == 0
          && ((*(_BYTE *)(v10 + 18) & 0x10) != 0 || (*(_BYTE *)(v10 + 18) & 8) != 0) )
        {
          ++v58;
        }
        if ( MiDeleteLockedTransitionPte(v7, v10, 17, 1) == 3 )
          ++v55;
      }
      else
      {
        MiReleasePageFileSpace(MiSystemPartition, v11, 1);
      }
    }
    v7 += 4;
    v4 = v54;
    if ( v7 >= v8 )
    {
      v6 = v57;
      LOBYTE(v3) = v63;
      goto LABEL_14;
    }
  }
}
