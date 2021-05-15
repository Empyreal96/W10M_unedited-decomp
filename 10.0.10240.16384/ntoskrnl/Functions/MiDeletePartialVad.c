// MiDeletePartialVad 
 
int __fastcall MiDeletePartialVad(_DWORD *a1, unsigned int a2, unsigned int a3, int a4)
{
  _DWORD *v6; // r10
  _DWORD *v7; // r8
  unsigned int v8; // r3
  int v9; // r9
  int v10; // r3
  unsigned int v11; // r7
  int *v12; // r3
  int v13; // r2
  int v14; // r3
  int v15; // r4
  int v16; // r0
  int v17; // r5
  int v18; // r5
  int v19; // r0
  bool v20; // zf
  unsigned int *v21; // r7
  int v22; // r4
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r1
  unsigned int v26; // r0
  unsigned __int8 *v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r1
  unsigned int v30; // r0
  int v31; // r5
  int v32; // r5
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r1
  unsigned int v36; // r0
  unsigned __int8 *v37; // r3
  unsigned int v38; // r1
  unsigned int v39; // r0
  unsigned int v40; // r1
  int v41; // r5
  _DWORD *v42; // r5
  int v43; // r3
  int v44; // r5
  int v45; // r2
  int v46; // r1
  int v47; // r5
  int v48; // r3
  int v49; // r1
  int v50; // r5
  int v51; // r5
  unsigned int v52; // r4
  unsigned __int8 *v53; // r3
  unsigned int v54; // r1
  unsigned int v55; // r1
  unsigned int v56; // r0
  int v57; // r2
  int *v58; // r0
  _DWORD *v59; // r2
  int v60; // r3
  int v61; // r7
  unsigned int v62; // r1
  _DWORD *v63; // r2
  _DWORD *i; // r3
  int v65; // r3
  int v66; // r5
  int v67; // r4
  int v68; // r6
  unsigned int *v69; // r8
  unsigned int *v70; // r4
  int v71; // r5
  unsigned __int8 *v72; // r3
  unsigned int v73; // r1
  unsigned int v74; // r0
  unsigned int v75; // r1
  int v77; // [sp+Ch] [bp-74h]
  _DWORD *v78; // [sp+10h] [bp-70h]
  int v80; // [sp+18h] [bp-68h]
  unsigned int *v81; // [sp+1Ch] [bp-64h]
  unsigned int *v83; // [sp+24h] [bp-5Ch] BYREF
  unsigned int *v84; // [sp+28h] [bp-58h] BYREF
  int v85; // [sp+2Ch] [bp-54h]
  unsigned int *v86; // [sp+30h] [bp-50h]
  int v87; // [sp+34h] [bp-4Ch]
  int v88; // [sp+38h] [bp-48h]
  unsigned int v89; // [sp+3Ch] [bp-44h]
  int v90; // [sp+40h] [bp-40h] BYREF
  int v91; // [sp+44h] [bp-3Ch]
  int v92; // [sp+48h] [bp-38h]
  int v93; // [sp+4Ch] [bp-34h]
  int v94; // [sp+50h] [bp-30h] BYREF
  int v95; // [sp+54h] [bp-2Ch]
  int v96; // [sp+58h] [bp-28h]
  int v97; // [sp+5Ch] [bp-24h]

  v89 = (a3 - a2 + 1) >> 12;
  v81 = 0;
  v83 = 0;
  v84 = 0;
  v86 = 0;
  v93 = a4;
  v94 = 0;
  v95 = 0;
  v96 = 0;
  v97 = 0;
  v77 = 0;
  v78 = 0;
  v6 = 0;
  v7 = 0;
  v91 = 0;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_DWORD *)(v8 + 116);
  v92 = v8;
  v10 = a1[7];
  if ( (v10 & 0x8000) != 0 )
  {
    v11 = 40;
    v85 = 40;
    v87 = 0;
    if ( (v10 & 7) == 6 )
      v91 = 8;
  }
  else
  {
    v12 = (int *)a1[11];
    v11 = 76;
    v85 = 76;
    v13 = *v12;
    v14 = *(_DWORD *)(*v12 + 32);
    v87 = v13;
    if ( v14 )
    {
      if ( (a1[17] & 0x80000000) != 0 )
        return -1073741791;
      if ( (*(_DWORD *)(v13 + 28) & 0x420) == 0 )
        v77 = 1;
    }
  }
  if ( a4 == 3 )
  {
    v16 = ExAllocatePoolWithTag(512, v11, 1180983638);
    v7 = (_DWORD *)v16;
    if ( !v16 )
      return -1073741670;
    memmove(v16, (int)a1, v11);
    v7[5] = 0;
    v7[2] = -2;
    v7[8] &= 0x80000000;
    v7[6] = 0;
    v17 = a1[3];
    if ( (v7[7] & 7) == 6 )
    {
      v7[9] = 0;
      if ( !MiCreateRotateView(v7) )
      {
        v15 = -1073741670;
LABEL_22:
        ExFreePoolWithTag(v7, 0);
        return v15;
      }
    }
    MiLockNestedVad(v7);
    MiAdvanceVadView(v7, ((a3 + 1) >> 12) - v17);
    MiUnlockNestedVad(v7);
    v18 = v87;
    if ( v11 != 40 )
    {
      v7[10] &= 0xFDFFFFFF;
      v7[17] = 0;
      v15 = MiInsertSharedCommitNode(v18, v9, 0);
      if ( v15 < 0 )
        goto LABEL_22;
    }
    v15 = MiInsertVadCharges(v7, v9);
    if ( v15 < 0 )
    {
      if ( v18 )
        MiRemoveSharedCommitNode(v18, v9, 0);
      if ( (v7[7] & 7) == 6 )
        MiFreeRotateView(v7);
      goto LABEL_22;
    }
    if ( v11 != 40 )
    {
      v19 = v7[18];
      if ( v19 )
        ObfReferenceObjectWithTag(v19);
      MiUpControlAreaRefs(v7);
    }
  }
  v90 = 4194300;
  LOCK_PAGE_TABLE_COMMITMENT(v92, v9);
  v88 = a1[8] & 0x7FFFFFFF;
  if ( !v88 )
  {
    v80 = 0;
    v20 = v11 == 40;
    v21 = (unsigned int *)(v9 + 492);
    if ( v20 )
    {
      v22 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) == 0 )
      {
        v23 = (unsigned __int8 *)(v9 + 495);
        do
          v24 = __ldrex(v23);
        while ( __strex(v24 | 0x80, v23) );
        __dmb(0xBu);
        if ( v24 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v21);
        while ( 1 )
        {
          v26 = *v21;
          if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v26 & 0x40000000) == 0 )
          {
            do
              v25 = __ldrex(v21);
            while ( v25 == v26 && __strex(v26 | 0x40000000, v21) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        goto LABEL_56;
      }
    }
    else
    {
      v22 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) == 0 )
      {
        v27 = (unsigned __int8 *)(v9 + 495);
        do
          v28 = __ldrex(v27);
        while ( __strex(v28 | 0x80, v27) );
        __dmb(0xBu);
        if ( v28 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v21);
        while ( 1 )
        {
          v30 = *v21;
          if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v30 & 0x40000000) == 0 )
          {
            do
              v29 = __ldrex(v21);
            while ( v29 == v30 && __strex(v30 | 0x40000000, v21) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        goto LABEL_56;
      }
    }
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v21);
LABEL_56:
    v31 = 0;
    goto LABEL_84;
  }
  if ( v11 == 40 )
  {
    v21 = (unsigned int *)(v9 + 492);
    v32 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v21);
    }
    else
    {
      v33 = (unsigned __int8 *)(v9 + 495);
      do
        v34 = __ldrex(v33);
      while ( __strex(v34 | 0x80, v33) );
      __dmb(0xBu);
      if ( v34 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v21);
      while ( 1 )
      {
        v36 = *v21;
        if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v36 & 0x40000000) == 0 )
        {
          do
            v35 = __ldrex(v21);
          while ( v35 == v36 && __strex(v36 | 0x40000000, v21) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v22 = v32;
    v31 = MiComputePageCommitment(a2, a3, (int)a1, v32, 0);
    v80 = v31;
  }
  else
  {
    v31 = ((int)(((a3 >> 10) & 0x3FFFFC) - ((a2 >> 10) & 0x3FFFFC)) >> 2)
        - MiCountSharedPages(a1, ((a2 >> 10) & 0x3FFFFC) - 0x40000000, ((a3 >> 10) & 0x3FFFFC) - 0x40000000)
        + 1;
    v80 = v31;
    v21 = (unsigned int *)(v9 + 492);
    v22 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v21);
    }
    else
    {
      v37 = (unsigned __int8 *)(v9 + 495);
      do
        v38 = __ldrex(v37);
      while ( __strex(v38 | 0x80, v37) );
      __dmb(0xBu);
      if ( v38 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v21);
      while ( 1 )
      {
        v39 = *v21;
        if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v39 & 0x40000000) == 0 )
        {
          do
            v40 = __ldrex(v21);
          while ( v40 == v39 && __strex(v39 | 0x40000000, v21) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
  }
LABEL_84:
  if ( v93 == 1 )
  {
    v41 = v85;
    if ( v85 != 40 && v77 == 1 )
    {
      MiGetProtoPteAddress(a1, a1[3], 1, &v84);
      v81 = v84;
    }
    a1[8] = a1[8] & 0x80000000 | (v88 - v80) & 0x7FFFFFFF;
    MiAdvanceVadView(a1, ((a3 + 1) >> 12) - a1[3]);
    if ( v41 != 40 && v77 == 1 )
    {
      MiGetProtoPteAddress(a1, a1[3], 1, &v83);
      v86 = v83;
    }
    v6 = a1;
    v42 = 0;
  }
  else
  {
    if ( v93 == 2 )
    {
      v43 = v88 - v31;
      v44 = v85;
      a1[8] = a1[8] & 0x80000000 | v43 & 0x7FFFFFFF;
      v45 = v77;
      if ( v44 != 40 && v77 == 1 )
      {
        MiGetProtoPteAddress(a1, a1[4], 1, &v83);
        v45 = 1;
        v86 = (unsigned int *)v83[2];
      }
      v46 = (a2 - 1) >> 12;
      a1[4] = v46;
      if ( v44 != 40 && v45 == 1 )
      {
        MiGetProtoPteAddress(a1, v46, 1, &v84);
        v81 = (unsigned int *)v84[2];
        MiAdvanceVadView(a1, 0);
      }
    }
    else
    {
      v47 = v85;
      v48 = v77;
      if ( v85 != 40 && v77 == 1 )
      {
        MiGetProtoPteAddress(a1, a1[4], 1, &v83);
        v86 = (unsigned int *)v83[2];
        v48 = 1;
      }
      v49 = (a2 - 1) >> 12;
      a1[4] = v49;
      if ( v47 != 40 && v48 == 1 )
      {
        MiGetProtoPteAddress(a1, v49, 1, &v84);
        v81 = (unsigned int *)v84[2];
        MiAdvanceVadView(a1, 0);
      }
      v89 += v7[4] - v7[3] + 1;
      MiInsertVad((int)v7, (_DWORD *)v9);
      if ( v47 == 40 )
      {
        v50 = MiComputePageCommitment(a1[3] << 12, a2 - 1, (int)a1, v22, 0);
      }
      else
      {
        MiUnlockWorkingSetExclusive((int)v21, v22);
        v51 = (a1[3] & 0xFFFFF) - 0x10000000;
        v52 = (v90 & ((a2 - 1) >> 10)) - 0x40000000;
        v50 = ((int)(v52 - 4 * v51) >> 2) - MiCountSharedPages(a1, 4 * v51, v52) + 1;
        v22 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v21);
        }
        else
        {
          v53 = (unsigned __int8 *)v21 + 3;
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 | 0x80, v53) );
          __dmb(0xBu);
          if ( v54 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v21);
          while ( 1 )
          {
            v56 = *v21;
            if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v56 & 0x40000000) == 0 )
            {
              do
                v55 = __ldrex(v21);
              while ( v55 == v56 && __strex(v56 | 0x40000000, v21) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
      }
      v57 = v88;
      a1[8] = a1[8] & 0x80000000 | v50 & 0x7FFFFFFF;
      v6 = v7;
      v7[8] = v7[8] & 0x80000000 | (v57 - v80 - v50) & 0x7FFFFFFF;
    }
    v42 = a1;
    v78 = a1;
  }
  MiDeleteVirtualAddresses(a2, a3, v91, v22, (int)&v94);
  if ( v81 && *(_DWORD *)(v9 + 500) )
  {
    MiEmptyPageAccessLog();
    *(_DWORD *)(v9 + 500) = 0;
  }
  MiCaptureDeleteHierarchy(a2, a3, v22, &v90);
  MiUnlockWorkingSetExclusive((int)v21, v22);
  if ( v7 && (v7[7] & 0x8000) == 0 )
  {
    v58 = (int *)v7[11];
    v7[16] = v9 | 1;
    MiManageSubsectionView(v58, (int)(v7 + 14), 3);
  }
  UNLOCK_PAGE_TABLE_COMMITMENT(v92, v9);
  if ( !v42 )
  {
    v59 = a1;
    v78 = (_DWORD *)*a1;
    if ( *a1 )
    {
      v60 = *(_DWORD *)(*a1 + 4);
      if ( v60 )
      {
        do
        {
          v61 = v60;
          v60 = *(_DWORD *)(v60 + 4);
        }
        while ( v60 );
        goto LABEL_138;
      }
    }
    else
    {
      v62 = a1[2] & 0xFFFFFFFC;
      v78 = (_DWORD *)v62;
      if ( v62 )
      {
        do
        {
          if ( *(_DWORD **)(v62 + 4) == v59 )
            break;
          v59 = (_DWORD *)v62;
          v62 = *(_DWORD *)(v62 + 8) & 0xFFFFFFFC;
        }
        while ( v62 );
        v78 = (_DWORD *)v62;
      }
    }
  }
  v61 = (int)v78;
LABEL_138:
  if ( !v6 )
  {
    v6 = (_DWORD *)a1[1];
    v63 = a1;
    if ( v6 )
    {
      for ( i = (_DWORD *)*v6; i; i = (_DWORD *)*i )
        v6 = i;
    }
    else
    {
      v65 = a1[2];
      while ( 1 )
      {
        v6 = (_DWORD *)(v65 & 0xFFFFFFFC);
        if ( (v65 & 0xFFFFFFFC) == 0 || (_DWORD *)*v6 == v63 )
          break;
        v65 = v6[2];
        v63 = v6;
      }
    }
  }
  v66 = v95;
  v67 = v80 - v96;
  if ( v80 != v96 )
    MiReturnFullProcessCharges(v9, v80 - v96, v80, v96);
  if ( v67 != v66 )
    MiReturnCommit((int)MiSystemPartition, v67 - v66);
  if ( v85 != 40 )
    PsReturnProcessPagedPoolQuota(v9, 4 * v89);
  MiFinishVadDeletion(a1, v61, (int)v6, a2, a3, (int)&v90);
  v68 = (int)v81;
  if ( v81 )
  {
    v69 = v86;
    if ( v81 != v86 )
    {
      v70 = (unsigned int *)(v87 + 36);
      v71 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v70);
      }
      else
      {
        v72 = (unsigned __int8 *)v70 + 3;
        do
          v73 = __ldrex(v72);
        while ( __strex(v73 | 0x80, v72) );
        __dmb(0xBu);
        if ( v73 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v70);
        while ( 1 )
        {
          v74 = *v70;
          if ( (*v70 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v74 & 0x40000000) == 0 )
          {
            do
              v75 = __ldrex(v70);
            while ( v75 == v74 && __strex(v74 | 0x40000000, v70) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
        v68 = (int)v81;
      }
      do
      {
        MiDecrementSubsections(v68, v68);
        v68 = *(_DWORD *)(v68 + 8);
      }
      while ( (unsigned int *)v68 != v69 );
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v70);
      }
      else
      {
        __dmb(0xBu);
        *v70 = 0;
      }
      KfLowerIrql(v71);
    }
  }
  return 0;
}
