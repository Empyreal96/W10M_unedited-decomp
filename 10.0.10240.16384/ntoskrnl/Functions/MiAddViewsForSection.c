// MiAddViewsForSection 
 
int __fastcall MiAddViewsForSection(int a1, unsigned __int64 a2, char a3)
{
  int v4; // r5
  _DWORD *v5; // r6
  int v6; // r7
  unsigned int *v7; // r4
  int v8; // lr
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1
  unsigned int v12; // r0
  int v13; // r0
  unsigned int v14; // r3
  int v15; // r0
  int v16; // lr
  unsigned __int8 *v17; // r3
  unsigned int v18; // r1
  unsigned int v19; // r0
  int *v20; // r3
  unsigned int v21; // r1
  unsigned __int8 *v22; // r3
  unsigned int v23; // r1
  unsigned int v24; // r0
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r1
  unsigned __int8 *v29; // r3
  unsigned int v30; // r1
  unsigned int v31; // r0
  unsigned int v32; // r1
  unsigned int v33; // r1
  int v34; // r2
  unsigned __int8 *v35; // r3
  unsigned int v36; // r1
  unsigned int v37; // r0
  unsigned int v38; // r1
  unsigned int v39; // r1
  unsigned __int8 *v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r1
  int v44; // r3
  int v45; // r3
  unsigned __int8 *v46; // r3
  unsigned int v47; // r1
  unsigned int v48; // r0
  unsigned int v49; // r1
  int v50; // r5
  unsigned __int8 *v51; // r3
  unsigned int v52; // r1
  unsigned int v53; // r0
  unsigned int v54; // r1
  int v55; // [sp+0h] [bp-48h]
  char v56; // [sp+4h] [bp-44h]
  int v57; // [sp+8h] [bp-40h]
  BOOL v58; // [sp+Ch] [bp-3Ch]
  int v59; // [sp+10h] [bp-38h]
  int v60; // [sp+10h] [bp-38h]
  int v61; // [sp+14h] [bp-34h]
  int v62; // [sp+14h] [bp-34h]
  int v63; // [sp+14h] [bp-34h]
  int v64; // [sp+14h] [bp-34h]
  int v65; // [sp+18h] [bp-30h]
  int v67; // [sp+24h] [bp-24h]

  v4 = a1;
  v5 = *(_DWORD **)a1;
  v65 = 0;
  v57 = 0;
  v6 = a1;
  v58 = *(_DWORD *)(*(_DWORD *)a1 + 32) != 0;
  v7 = (unsigned int *)(*(_DWORD *)a1 + 36);
  v8 = KfRaiseIrql(2);
  v55 = v8;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_545A64();
  v10 = (unsigned __int8 *)v5 + 39;
  do
    v11 = __ldrex(v10);
  while ( __strex(v11 | 0x80, v10) );
  __dmb(0xBu);
  if ( v11 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
  while ( 1 )
  {
    v12 = *v7;
    if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v12 & 0x40000000) == 0 )
    {
      do
        v21 = __ldrex(v7);
      while ( v21 == v12 && __strex(v12 | 0x40000000, v7) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( (a3 & 1) != 0 )
  {
    ++v5[5];
    ++v5[12];
  }
  while ( 1 )
  {
    if ( *(_DWORD *)(v6 + 4) )
    {
      while ( v58 )
      {
        v59 = 0;
        v56 = 1;
        do
        {
          v13 = MiReferenceSubsection(v6);
          if ( v13 )
          {
            if ( v13 == 1 && (v56 & 8) != 0 )
              v65 += v59;
            goto LABEL_17;
          }
          v59 = *(_DWORD *)(v6 + 28);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
          }
          else
          {
            __dmb(0xBu);
            *v7 = 0;
          }
          KfLowerIrql(v55);
          if ( (v56 & 8) != 0 )
          {
            v57 = -1073741523;
            goto LABEL_146;
          }
          v56 |= 8u;
          v57 = 0;
          v62 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
          }
          else
          {
            v25 = (unsigned __int8 *)v5 + 39;
            do
              v26 = __ldrex(v25);
            while ( __strex(v26 | 0x80, v25) );
            __dmb(0xBu);
            if ( v26 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
            while ( 1 )
            {
              v27 = *v7;
              if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v27 & 0x40000000) == 0 )
              {
                do
                  v28 = __ldrex(v7);
                while ( v28 == v27 && __strex(v27 | 0x40000000, v7) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          v55 = v62;
        }
        while ( *(_DWORD *)(v6 + 4) && v59 == *(_DWORD *)(v6 + 28) );
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
        KfLowerIrql(v62);
        v63 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
        }
        else
        {
          v29 = (unsigned __int8 *)v5 + 39;
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 | 0x80, v29) );
          __dmb(0xBu);
          if ( v30 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
          while ( 1 )
          {
            v31 = *v7;
            if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v31 & 0x40000000) == 0 )
            {
              do
                v32 = __ldrex(v7);
              while ( v32 == v31 && __strex(v31 | 0x40000000, v7) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v8 = v63;
        v55 = v63;
        if ( !*(_DWORD *)(v6 + 4) )
          goto LABEL_22;
      }
      goto LABEL_17;
    }
LABEL_22:
    v61 = *(_DWORD *)(v6 + 36) + *(_DWORD *)(v6 + 28);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
      v8 = v55;
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v8);
    v15 = ExAllocatePoolWithTag(-2147483647, 4 * v61, 1951624525);
    v60 = v15;
    if ( !v15 )
    {
      v44 = -1073741670;
      v57 = -1073741670;
      goto LABEL_145;
    }
    MiInitializePrototypePtes(v15, v61, v6);
    v16 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      v17 = (unsigned __int8 *)v5 + 39;
      do
        v18 = __ldrex(v17);
      while ( __strex(v18 | 0x80, v17) );
      __dmb(0xBu);
      if ( v18 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
      while ( 1 )
      {
        v19 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v19 & 0x40000000) == 0 )
        {
          do
            v33 = __ldrex(v7);
          while ( v33 == v19 && __strex(v19 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v55 = v16;
    if ( (v5[7] & 0x40000000) != 0 )
    {
      v57 = MiInitializeFileExtents(v6, v16);
      if ( v57 < 0 )
        break;
    }
    if ( v58 )
    {
      ++*(_DWORD *)(v6 + 60);
      *(_WORD *)(v6 + 16) |= 1u;
    }
    if ( *(_DWORD *)(v6 + 4) )
    {
      if ( v58 && (*(_WORD *)(v6 + 18) & 8) != 0 )
        MiRemoveUnusedSubsection(v6);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
      }
      else
      {
        __dmb(0xBu);
        *v7 = 0;
      }
      KfLowerIrql(v16);
      ExFreePoolWithTag(v60, 0);
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
LABEL_137:
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
        goto LABEL_17;
      }
      v40 = (unsigned __int8 *)v5 + 39;
      do
        v41 = __ldrex(v40);
      while ( __strex(v41 | 0x80, v40) );
      __dmb(0xBu);
      if ( v41 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
      while ( 1 )
      {
        v42 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v42 & 0x40000000) == 0 )
        {
          do
            v43 = __ldrex(v7);
          while ( v43 == v42 && __strex(v42 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    else
    {
      *(_DWORD *)(v6 + 4) = v60;
      if ( v58 )
      {
        v20 = *(int **)(v6 + 12);
        if ( v20 )
        {
          v34 = *v20;
          *v20 = 0;
          v64 = v34;
          if ( v34 )
          {
            if ( (dword_682604 & 0x10000) != 0 )
            {
              ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
            }
            else
            {
              __dmb(0xBu);
              *v7 = 0;
            }
            KfLowerIrql(v16);
            MiReleaseFileExtentWaiters(v64);
            KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
              goto LABEL_137;
            v35 = (unsigned __int8 *)v5 + 39;
            do
              v36 = __ldrex(v35);
            while ( __strex(v36 | 0x80, v35) );
            __dmb(0xBu);
            if ( v36 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
            while ( 1 )
            {
              v37 = *v7;
              if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v37 & 0x40000000) == 0 )
              {
                do
                  v38 = __ldrex(v7);
                while ( v38 == v37 && __strex(v37 | 0x40000000, v7) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
        }
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
        }
        else
        {
          __dmb(0xBu);
          *v7 = 0;
        }
        KfLowerIrql(v16);
        MiUpdatePageFileSectionList(v6, 1);
        KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
          goto LABEL_137;
        v22 = (unsigned __int8 *)v5 + 39;
        do
          v23 = __ldrex(v22);
        while ( __strex(v23 | 0x80, v22) );
        __dmb(0xBu);
        if ( v23 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
        while ( 1 )
        {
          v24 = *v7;
          if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v24 & 0x40000000) == 0 )
          {
            do
              v39 = __ldrex(v7);
            while ( v39 == v24 && __strex(v24 | 0x40000000, v7) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
LABEL_17:
    if ( a2 )
    {
      v14 = *(_DWORD *)(v6 + 28);
      if ( a2 <= v14 )
        goto LABEL_19;
      a2 -= v14;
    }
    v6 = *(_DWORD *)(v6 + 8);
    if ( !v6 )
    {
LABEL_19:
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
      }
      else
      {
        __dmb(0xBu);
        *v7 = 0;
      }
      KfLowerIrql(v55);
      return v57;
    }
    v8 = v55;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  KfLowerIrql(v16);
  ExFreePoolWithTag(v60, 0);
  v44 = v57;
LABEL_145:
  if ( v58 )
  {
LABEL_146:
    v67 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      v46 = (unsigned __int8 *)v5 + 39;
      do
        v47 = __ldrex(v46);
      while ( __strex(v47 | 0x80, v46) );
      __dmb(0xBu);
      if ( v47 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
      while ( 1 )
      {
        v48 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v48 & 0x40000000) == 0 )
        {
          do
            v49 = __ldrex(v7);
          while ( v49 == v48 && __strex(v48 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    for ( ; v4 != v6; v4 = *(_DWORD *)(v4 + 8) )
    {
      v45 = *(_DWORD *)(v4 + 60) - 1;
      *(_DWORD *)(v4 + 60) = v45;
      if ( !v45 )
        MiInsertUnusedSubsection(v4, 0);
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      __dmb(0xBu);
      *v7 = 0;
    }
    KfLowerIrql(v67);
    v44 = v57;
  }
  if ( (a3 & 1) != 0 )
  {
    v50 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v5 + 9);
    }
    else
    {
      v51 = (unsigned __int8 *)v5 + 39;
      do
        v52 = __ldrex(v51);
      while ( __strex(v52 | 0x80, v51) );
      __dmb(0xBu);
      if ( v52 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v5 + 9);
      while ( 1 )
      {
        v53 = *v7;
        if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v53 & 0x40000000) == 0 )
        {
          do
            v54 = __ldrex(v7);
          while ( v54 == v53 && __strex(v53 | 0x40000000, v7) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    --v5[5];
    --v5[12];
    MiCheckControlArea(v5, v50);
    v44 = v57;
  }
  return v44;
}
