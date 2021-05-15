// MiDeleteCachedSubsection 
 
int __fastcall MiDeleteCachedSubsection(int a1)
{
  _DWORD *v2; // r5
  int v3; // r6
  _DWORD *v4; // r8
  _DWORD *v5; // r10
  unsigned int v6; // r1
  int v7; // lr
  int v8; // r1
  unsigned int v9; // r0
  int v10; // r7
  _DWORD *v11; // r1
  __int64 v12; // kr00_8
  int v13; // r3
  __int64 v14; // r0
  int v15; // r4
  unsigned int *v16; // r4
  int v17; // r0
  int v18; // r7
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r7
  unsigned __int64 *v24; // r3
  unsigned __int64 v25; // kr08_8
  unsigned __int8 *v26; // r3
  unsigned int v27; // r1
  unsigned int v28; // r0
  unsigned int v29; // r1
  int v30; // r10
  int v31; // r3
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned int v34; // r0
  unsigned int v35; // r1
  int v36; // r1
  unsigned __int8 *v37; // r3
  unsigned int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r1
  unsigned int v41; // r2
  _DWORD *v42; // r5
  int v43; // r9
  int v44; // r3
  int v45; // r1
  _DWORD *v46; // r6
  unsigned int v48; // [sp+10h] [bp-40h]
  int v49; // [sp+14h] [bp-3Ch]
  int v50; // [sp+14h] [bp-3Ch]
  BOOL v51; // [sp+14h] [bp-3Ch]
  int v52; // [sp+14h] [bp-3Ch]
  int v53; // [sp+18h] [bp-38h]
  int v54; // [sp+1Ch] [bp-34h]
  int v55; // [sp+20h] [bp-30h]
  int v56[10]; // [sp+28h] [bp-28h] BYREF
  int vars4; // [sp+54h] [bp+4h]

  v2 = 0;
  v3 = 0;
  v49 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v6 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v6 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    if ( v6 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v7 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v8 = dword_632D80 | 0x40000000;
        do
          v9 = __ldrex((unsigned int *)&dword_632D80);
        while ( v9 == v7 && __strex(v8, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v4 = *(_DWORD **)(a1 + 880);
  v5 = (_DWORD *)(a1 + 880);
  while ( v4 != v5 )
  {
    v3 = (int)(v4 - 13);
    v2 = (_DWORD *)*(v4 - 13);
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v2 + 9) )
      break;
    v4 = (_DWORD *)*v4;
  }
  if ( v4 == v5 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
    }
    else
    {
      __dmb(0xBu);
      dword_632D80 = 0;
    }
    v10 = -1073741275;
LABEL_38:
    KfLowerIrql(v49);
    return v10;
  }
  v11 = (_DWORD *)(v3 + 52);
  v12 = *(_QWORD *)(v3 + 52);
  if ( *(_DWORD *)(v12 + 4) != v3 + 52 || *(_DWORD **)HIDWORD(v12) != v11 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v12) = v12;
  *(_DWORD *)(v12 + 4) = HIDWORD(v12);
  *(_WORD *)(v3 + 18) &= 0xFFF7u;
  *v11 = v11;
  *(_DWORD *)(v3 + 56) = v3 + 52;
  MI_UNUSED_SUBSECTIONS_COUNT_REMOVE(v3);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  v13 = v2[7];
  HIDWORD(v14) = 1;
  if ( (v13 & 1) != 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
    }
    else
    {
      __dmb(0xBu);
      v2[9] = 0;
    }
    v10 = -1073741709;
    goto LABEL_38;
  }
  if ( (v13 & 8) != 0 )
  {
    if ( (*(_WORD *)(v3 + 18) & 4) != 0 )
    {
      MiInsertUnusedSubsection(v3, 1);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
      }
      else
      {
        __dmb(0xBu);
        v2[9] = 0;
      }
      v10 = -1073741792;
      goto LABEL_38;
    }
    v15 = 1;
  }
  else
  {
    v15 = 0;
  }
  LODWORD(v14) = v2;
  *(_WORD *)(v3 + 16) &= 0xFFFEu;
  *(_DWORD *)(v3 + 60) = 1;
  MiRemoveUnusedSegment(v14);
  v2[7] |= 0x100u;
  v53 = *(_DWORD *)(v3 + 4);
  if ( v15 == 1 )
  {
    v16 = v2 + 9;
    ++v2[10];
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
    KfLowerIrql(v49);
    v17 = MiIsSubsectionClean(v3);
    if ( v17 )
    {
      if ( v17 == 1 )
      {
        v18 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2 + 9);
        }
        else
        {
          v19 = (unsigned __int8 *)v2 + 39;
          do
            v20 = __ldrex(v19);
          while ( __strex(v20 | 0x80, v19) );
          __dmb(0xBu);
          if ( v20 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v2 + 9);
          while ( 1 )
          {
            v21 = *v16;
            if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v21 & 0x40000000) == 0 )
            {
              do
                v22 = __ldrex(v16);
              while ( v22 == v21 && __strex(v21 | 0x40000000, v16) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        *(_WORD *)(v3 + 18) |= 4u;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v16 = 0;
        }
        KfLowerIrql(v18);
      }
      v10 = -1073741792;
    }
    else
    {
      v10 = 0;
    }
  }
  else
  {
    v23 = MiPreventControlAreaDelete(v2);
    v48 = v23;
    v16 = v2 + 9;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
    KfLowerIrql(v49);
    v55 = *(_DWORD *)(v3 + 4);
    v54 = v55 + 4 * *(_DWORD *)(v3 + 28);
    v10 = FsRtlAcquireFileForCcFlushEx(v23);
    v50 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v2 + 9);
    }
    else
    {
      v26 = (unsigned __int8 *)v2 + 39;
      do
        v27 = __ldrex(v26);
      while ( __strex(v27 | 0x80, v26) );
      __dmb(0xBu);
      if ( v27 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v2 + 9);
      while ( 1 )
      {
        v28 = *v16;
        if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v28 & 0x40000000) == 0 )
        {
          do
            v29 = __ldrex(v16);
          while ( v29 == v28 && __strex(v28 | 0x40000000, v16) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v24 = (unsigned __int64 *)(v2 + 16);
    do
      v25 = __ldrexd(v24);
    while ( __strexd(v25 - 1, v24) );
    if ( v10 < 0 || (v2[7] & 1) != 0 )
    {
      if ( v25 != 1 )
        ++v2[10];
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      KfLowerIrql(v50);
      if ( v10 >= 0 )
      {
        FsRtlReleaseFileForCcFlush(v48);
        v10 = -1073741431;
      }
      if ( v25 == 1 )
      {
        MiDeleteControlArea(v2);
        ObfDereferenceObjectWithTag(v48);
        return v10;
      }
    }
    else
    {
      ++v2[10];
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v2 + 9, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v16 = 0;
      }
      KfLowerIrql(v50);
      *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 1;
      v10 = MiFlushSectionInternal(v55, v54 - 4, (_DWORD *)v3, v3, 0, 2u, v56);
      *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 0;
      FsRtlReleaseFileForCcFlush(v48);
    }
    MI_DEREFERENCE_CONTROL_AREA_FILE((int)v2, v48);
  }
  v30 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v16);
  }
  else
  {
    v32 = (unsigned __int8 *)v16 + 3;
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 | 0x80, v32) );
    __dmb(0xBu);
    if ( v33 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v16);
    while ( 1 )
    {
      v34 = *v16;
      if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v34 & 0x40000000) == 0 )
      {
        do
          v35 = __ldrex(v16);
        while ( v35 == v34 && __strex(v34 | 0x40000000, v16) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v31 = v2[7];
  if ( (v31 & 1) != 0 )
  {
    v2[7] = v31 & 0xFFFFFEFF;
LABEL_134:
    --*(_DWORD *)(v3 + 60);
    v42 = (_DWORD *)MiDecrementModifiedWriteCount((int)v2, 1);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v16, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
    KfLowerIrql(v30);
    if ( v42 )
      MiReleaseControlAreaWaiters(v42);
    return -1073741823;
  }
  if ( v10 < 0 )
    goto LABEL_132;
  if ( *(_DWORD *)(v3 + 60) != 1 || (*(_WORD *)(v3 + 16) & 1) != 0 )
  {
    v10 = -1073741823;
LABEL_132:
    v36 = 1;
    goto LABEL_133;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v16, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v16 = 0;
  }
  KfLowerIrql(v30);
  v51 = MiPurgeSubsection(v3) == 0;
  v30 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v16);
  }
  else
  {
    v37 = (unsigned __int8 *)v16 + 3;
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 | 0x80, v37) );
    __dmb(0xBu);
    if ( v38 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v16);
    while ( 1 )
    {
      v39 = *v16;
      if ( (*v16 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v39 & 0x40000000) == 0 )
      {
        do
          v40 = __ldrex(v16);
        while ( v40 == v39 && __strex(v39 | 0x40000000, v16) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v36 = v51;
LABEL_133:
  v41 = v2[7] & 0xFFFFFEFF;
  v2[7] = v41;
  if ( (v41 & 1) != 0 )
    goto LABEL_134;
  v52 = 0;
  if ( v36 == 1 || *(_DWORD *)(v3 + 60) != 1 || *(_DWORD *)(v3 + 64) || (*(_WORD *)(v3 + 16) & 1) != 0 )
  {
    v10 = -1073741823;
    v44 = *(_DWORD *)(v3 + 60) - 1;
    *(_DWORD *)(v3 + 60) = v44;
    if ( !v44 )
      MiInsertUnusedSubsection(v3, 1);
    v53 = 0;
    v43 = 0;
  }
  else
  {
    if ( (v41 & 0x40000000) != 0 )
    {
      v43 = MiMarkFileExtentsDeleted(v3);
      v52 = *(_DWORD *)(v3 + 28);
    }
    else
    {
      v43 = 0;
    }
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 60) = 0;
  }
  v46 = (_DWORD *)MiDecrementModifiedWriteCount((int)v2, 1);
  if ( v2[3] | v2[5] )
    goto LABEL_154;
  if ( v2[4] )
  {
    MiInsertUnusedSegment(v2, v45);
LABEL_154:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v16, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v16 = 0;
    }
    KfLowerIrql(v30);
    goto LABEL_159;
  }
  MiDestroySection(v2, v30);
LABEL_159:
  if ( v46 )
    MiReleaseControlAreaWaiters(v46);
  if ( v43 )
    MiDeleteFileExtents(v43, 0, v52, 2);
  if ( v53 )
    ExFreePoolWithTag(v53);
  return v10;
}
