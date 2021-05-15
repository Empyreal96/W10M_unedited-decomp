// KiAbEntryGetLockedHeadEntry 
 
int __fastcall KiAbEntryGetLockedHeadEntry(int a1, int a2, int *a3)
{
  int v5; // r3
  unsigned int v6; // r1
  unsigned int *v7; // lr
  int v8; // r10
  int v9; // r0
  unsigned int v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r3
  _DWORD *v13; // r6
  unsigned __int8 *v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r5
  int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r0
  unsigned int *v20; // r2
  _DWORD *v21; // r5
  unsigned int v22; // r1
  int v23; // r2
  unsigned __int8 *v24; // r2
  unsigned int v25; // r0
  int result; // r0
  unsigned int v27; // r3
  unsigned int v28; // r1
  unsigned int v29; // r3
  unsigned int v30; // r5
  int v31; // r6
  int v32; // lr
  int v33; // r1
  int v34; // r1
  unsigned int v35; // r0
  int v36; // r0
  unsigned int v37; // r1
  unsigned int v38; // r2
  char v39; // r0
  unsigned int v40; // r1
  int v41; // r2
  unsigned int v42; // r0
  char v43; // r0
  int v44; // r0
  unsigned int v45; // r3
  unsigned int v46; // r1
  unsigned __int8 *v47; // r3
  unsigned int v48; // r1
  unsigned int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r2
  unsigned int v52; // r1
  unsigned int v53; // r2
  unsigned int v54; // r2
  unsigned int v55; // r3
  int v56; // r0
  unsigned int *v57; // r1
  int *v58; // r0
  unsigned int v59; // r3
  unsigned int *v60; // r2
  unsigned int v61; // r0
  unsigned int v62; // r1
  bool v63; // cf
  unsigned int v64; // r1
  unsigned int v65; // r2
  int v66; // r0
  unsigned int *v67; // r2
  unsigned int v68; // r1
  unsigned int *v69; // r2
  unsigned int v70; // r0
  __int64 v71; // [sp-18h] [bp-60h]
  unsigned int *v72; // [sp+0h] [bp-48h]
  unsigned int *v73; // [sp+8h] [bp-40h]
  unsigned int v75; // [sp+10h] [bp-38h]
  unsigned __int64 v76; // [sp+18h] [bp-30h] BYREF
  int v77[10]; // [sp+20h] [bp-28h] BYREF
  __int64 savedregs; // [sp+48h] [bp+0h]

  v5 = *(unsigned __int8 *)(a1 + 15);
  if ( (v5 & 1) != 0 )
  {
    v44 = KeAcquireInStackQueuedSpinLockAtDpcLevel(a1 + 40, a3, a3, v5);
    if ( (*(_BYTE *)(a1 + 15) & 1) != 0 )
      result = a1;
    else
      result = sub_53086C(v44);
    return result;
  }
  v71 = *(_QWORD *)(a1 + 16);
  if ( (int)v71 >= 0 && !a2 )
    return 0;
  v6 = (((unsigned int)v71 & 0x7FFFFFFC) >> 3) & 3;
  v76 = v71 & 0xFFFFFFFF7FFFFFFCui64;
  v73 = (unsigned int *)((char *)&KiAbTreeArray + 128 * v6);
  v7 = (unsigned int *)&dword_646D88[32 * v6];
  v72 = v7;
  v75 = v71 & 0x7FFFFFFC;
  v8 = 0;
  while ( 1 )
  {
    if ( v8 )
    {
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
      }
      else
      {
        v47 = (unsigned __int8 *)v7 + 3;
        do
        {
          v48 = __ldrex(v47);
          v10 = __strex(v48 | 0x80, v47);
        }
        while ( v10 );
        __dmb(0xBu);
        if ( v48 >> 7 )
        {
          ExpWaitForSpinLockExclusiveAndAcquire(v7);
          v7 = v72;
        }
        while ( 1 )
        {
          v49 = *v7;
          if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v49 & 0x40000000) == 0 )
          {
            v10 = v49 | 0x40000000;
            do
              v62 = __ldrex(v7);
            while ( v62 == v49 && __strex(v10, v7) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    else if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockSharedAtDpcLevelInstrumented(v7);
    }
    else
    {
      v9 = *v7 & 0x7FFFFFFF;
      v10 = v9 + 1;
      do
        v11 = __ldrex(v7);
      while ( v11 == v9 && __strex(v10, v7) );
      __dmb(0xBu);
      if ( v11 != v9 )
        ExpWaitForSpinLockSharedAndAcquire(v7);
    }
    v12 = (unsigned int)v73;
    v13 = (_DWORD *)*v73;
    if ( *v73 )
    {
      v10 = 2147483644;
      do
      {
        v12 = v13[4] & 0x7FFFFFFC;
        if ( v12 > v75 )
          goto LABEL_64;
        if ( v12 < v75 )
          goto LABEL_69;
        v10 = v13[5];
        v12 = HIDWORD(v71);
        if ( v10 == HIDWORD(v71) )
          break;
        v12 = HIDWORD(v71);
        v63 = v10 >= HIDWORD(v71);
        v10 = 2147483644;
        if ( v63 )
LABEL_64:
          v13 = (_DWORD *)*v13;
        else
LABEL_69:
          v13 = (_DWORD *)v13[1];
      }
      while ( v13 );
    }
    if ( !a2 )
    {
      if ( !v13 )
      {
        if ( v8 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v72);
          }
          else
          {
            __dmb(0xBu);
            *v72 = 0;
          }
        }
        else if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v72);
        }
        else
        {
          __dmb(0xBu);
          do
            v64 = __ldrex(v72);
          while ( __strex(v64 & 0xBFFFFFFF, v72) );
          __dmb(0xBu);
          do
            v65 = __ldrex(v72);
          while ( __strex(v65 - 1, v72) );
        }
        return 0;
      }
      v21 = v13;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v13 + 10, a3, v10, v12);
      if ( v8 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v72);
        }
        else
        {
          __dmb(0xBu);
          v55 = (unsigned int)v72;
          v54 = 0;
          *v72 = 0;
        }
      }
      else if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v72);
      }
      else
      {
        __dmb(0xBu);
        do
          v52 = __ldrex(v72);
        while ( __strex(v52 & 0xBFFFFFFF, v72) );
        __dmb(0xBu);
        do
        {
          v53 = __ldrex(v72);
          v54 = v53 - 1;
          v55 = __strex(v54, v72);
        }
        while ( v55 );
      }
      if ( (_DWORD *)a1 == v13 )
        return (int)v21;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(a1 + 40, v77, v54, v55);
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseQueuedSpinLockInstrumented(v77);
        goto LABEL_131;
      }
      v56 = v77[0];
      if ( !v77[0] )
      {
        v57 = (unsigned int *)v77[1];
        __dmb(0xBu);
        do
          v58 = (int *)__ldrex(v57);
        while ( v58 == v77 && __strex(0, v57) );
        if ( v58 == v77 )
        {
LABEL_131:
          if ( KiAbCompareSnappedEntryState(a1, &v76) )
            return (int)v21;
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseQueuedSpinLockInstrumented(a3);
          }
          else
          {
            v66 = *a3;
            if ( !*a3 )
            {
              v67 = (unsigned int *)a3[1];
              __dmb(0xBu);
              do
                v68 = __ldrex(v67);
              while ( (int *)v68 == a3 && __strex(0, v67) );
              if ( (int *)v68 == a3 )
                return 0;
              v66 = KxWaitForLockChainValid(a3);
            }
            *a3 = 0;
            __dmb(0xBu);
            v69 = (unsigned int *)(v66 + 4);
            do
              v70 = __ldrex(v69);
            while ( __strex(v70 ^ 1, v69) );
          }
          return 0;
        }
        v56 = KxWaitForLockChainValid(v77);
      }
      v77[0] = 0;
      __dmb(0xBu);
      v60 = (unsigned int *)(v56 + 4);
      do
        v61 = __ldrex(v60);
      while ( __strex(v61 ^ 1, v60) );
      goto LABEL_131;
    }
    if ( v13 )
    {
      v21 = v13;
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v13 + 10, a3, v10, v12);
      if ( v8 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v72);
        }
        else
        {
          __dmb(0xBu);
          *v72 = 0;
        }
      }
      else if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v72);
      }
      else
      {
        __dmb(0xBu);
        do
          v37 = __ldrex(v72);
        while ( __strex(v37 & 0xBFFFFFFF, v72) );
        __dmb(0xBu);
        do
          v38 = __ldrex(v72);
        while ( __strex(v38 - 1, v72) );
      }
      if ( *(int *)(a1 + 16) >= 0 )
      {
        if ( (*(_BYTE *)(a1 + 13) & 1) != 0 )
        {
          v39 = KiAbWaiterComputeCpuPriorityKey(a1);
          *(_BYTE *)(a1 + 24) = v39;
          v40 = v13[8];
          v41 = 0;
          if ( !v40 )
            goto LABEL_81;
          while ( 1 )
          {
            if ( *(char *)(v40 + 24) < v39 )
            {
              v45 = *(_DWORD *)v40;
              if ( !*(_DWORD *)v40 )
              {
                v41 = 0;
LABEL_81:
                v42 = (unsigned int)(v13 + 8);
LABEL_82:
                RtlRbInsertNodeEx(v42, v40, v41, (_DWORD *)a1);
                *(_BYTE *)(a1 + 19) |= 0x80u;
                goto LABEL_31;
              }
            }
            else
            {
              v45 = *(_DWORD *)(v40 + 4);
              if ( !v45 )
              {
                v41 = 1;
                goto LABEL_81;
              }
            }
            v40 = v45;
          }
        }
        v43 = KiAbOwnerComputeCpuPriorityKey(a1);
        *(_BYTE *)(a1 + 24) = v43;
        v40 = v13[6];
        v41 = 0;
        if ( !v40 )
        {
LABEL_86:
          v42 = (unsigned int)(v13 + 6);
          goto LABEL_82;
        }
        while ( 1 )
        {
          if ( *(char *)(v40 + 24) > v43 )
          {
            v59 = *(_DWORD *)v40;
            if ( !*(_DWORD *)v40 )
            {
              v41 = 0;
              v42 = (unsigned int)(v13 + 6);
              goto LABEL_82;
            }
          }
          else
          {
            v59 = *(_DWORD *)(v40 + 4);
            if ( !v59 )
            {
              v41 = 1;
              goto LABEL_86;
            }
          }
          v40 = v59;
        }
      }
      return (int)v21;
    }
    if ( v8 )
      goto LABEL_21;
    v8 = 1;
    if ( (dword_682604 & 0x210000) == 0 )
      break;
    if ( ExpTryConvertSharedSpinLockExclusiveInstrumented(v72, HIDWORD(savedregs)) )
      goto LABEL_21;
    v7 = v72;
LABEL_110:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockSharedFromDpcLevelInstrumented(v7);
      v7 = v72;
    }
    else
    {
      __dmb(0xBu);
      do
        v50 = __ldrex(v7);
      while ( __strex(v50 & 0xBFFFFFFF, v7) );
      __dmb(0xBu);
      do
        v51 = __ldrex(v7);
      while ( __strex(v51 - 1, v7) );
    }
  }
  v7 = v72;
  v14 = (unsigned __int8 *)v72 + 3;
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 | 0x80, v14) );
  __dmb(0xBu);
  if ( v15 >> 7 )
    goto LABEL_110;
  while ( 1 )
  {
    v16 = *v72;
    if ( (*v72 & 0xBFFFFFFF) == -2147483647 )
      break;
    if ( (v16 & 0x40000000) == 0 )
    {
      do
        v46 = __ldrex(v72);
      while ( v46 == v16 && __strex(v16 | 0x40000000, v72) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
LABEL_21:
  v17 = 0;
  v18 = *v73;
  if ( !*v73 )
    goto LABEL_22;
  while ( 2 )
  {
    v27 = *(_DWORD *)(v18 + 16) & 0x7FFFFFFC;
    if ( v27 <= v75 )
    {
      if ( v27 < v75 || (v28 = *(_DWORD *)(v18 + 20), v28 == HIDWORD(v71)) || v28 < HIDWORD(v71) )
      {
        v29 = *(_DWORD *)(v18 + 4);
        if ( !v29 )
        {
          v17 = 1;
          goto LABEL_22;
        }
        goto LABEL_71;
      }
    }
    v29 = *(_DWORD *)v18;
    if ( *(_DWORD *)v18 )
    {
LABEL_71:
      v18 = v29;
      continue;
    }
    break;
  }
  v17 = 0;
LABEL_22:
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = 0;
  v19 = a1;
  if ( v18 )
  {
    *(_DWORD *)(v18 + 4 * v17) = a1;
    *(_DWORD *)(a1 + 8) = v18 | 1;
    if ( !v17 && v18 == v73[1] )
      v73[1] = a1;
    if ( (*(_BYTE *)(v18 + 8) & 1) != 0 )
    {
      while ( 1 )
      {
        v30 = *(_DWORD *)(v18 + 8) & 0xFFFFFFFC;
        v31 = *(_DWORD *)v30 != v18;
        v32 = *(_DWORD *)(v30 + 4 * (*(_DWORD *)v30 == v18));
        if ( !v32 || (*(_BYTE *)(v32 + 8) & 1) == 0 )
          break;
        v19 = *(_DWORD *)(v18 + 8) & 0xFFFFFFFC;
        *(_BYTE *)(v18 + 8) &= 0xFEu;
        *(_BYTE *)(v32 + 8) &= 0xFEu;
        v18 = *(_DWORD *)(v30 + 8) & 0xFFFFFFFC;
        if ( v18 )
        {
          *(_BYTE *)(v30 + 8) |= 1u;
          v17 = v30 != *(_DWORD *)v18;
          if ( (*(_BYTE *)(v18 + 8) & 1) != 0 )
            continue;
        }
        goto LABEL_24;
      }
      if ( v17 != v31 )
      {
        if ( (*(_DWORD *)(v19 + 8) & 0xFFFFFFFC) != v18 )
          __fastfail(0x1Du);
        if ( *(_DWORD *)(v18 + 4 * (*(_DWORD *)v30 == v18)) != v19 )
          __fastfail(0x1Du);
        if ( *(_DWORD *)(v30 + 4 * v31) != v18 )
          __fastfail(0x1Du);
        *(_DWORD *)(v30 + 4 * v31) = v19;
        *(_DWORD *)(v19 + 8) = *(_DWORD *)(v19 + 8) & 3 | v30;
        v33 = *(_DWORD *)(v19 + 4 * v31);
        if ( v33 )
        {
          if ( (*(_DWORD *)(v33 + 8) & 0xFFFFFFFC) != v19 )
            __fastfail(0x1Du);
          *(_DWORD *)(v33 + 8) = *(_DWORD *)(v33 + 8) & 3 | v18;
        }
        *(_DWORD *)(v18 + 4 * (v31 ^ 1)) = v33;
        *(_DWORD *)(v19 + 4 * v31) = v18;
        *(_DWORD *)(v18 + 8) = *(_DWORD *)(v18 + 8) & 3 | v19;
        v18 = v19;
      }
      v34 = v31 ^ 1;
      if ( (*(_DWORD *)(v18 + 8) & 0xFFFFFFFC) != v30 )
        __fastfail(0x1Du);
      if ( *(_DWORD *)(v30 + 4 * v31) != v18 )
        __fastfail(0x1Du);
      v35 = *(_DWORD *)(v30 + 8) & 0xFFFFFFFC;
      if ( v35 )
      {
        if ( *(_DWORD *)(v35 + 4) == v30 )
        {
          *(_DWORD *)(v35 + 4) = v18;
        }
        else
        {
          if ( *(_DWORD *)v35 != v30 )
            __fastfail(0x1Du);
          *(_DWORD *)v35 = v18;
        }
      }
      else
      {
        if ( *v73 != v30 )
          __fastfail(0x1Du);
        *v73 = v18;
      }
      *(_DWORD *)(v18 + 8) = *(_DWORD *)(v18 + 8) & 3 | v35;
      v36 = *(_DWORD *)(v18 + 4 * v34);
      if ( v36 )
      {
        if ( (*(_DWORD *)(v36 + 8) & 0xFFFFFFFC) != v18 )
          __fastfail(0x1Du);
        *(_DWORD *)(v36 + 8) = *(_DWORD *)(v36 + 8) & 3 | v30;
      }
      *(_DWORD *)(v30 + 4 * v31) = v36;
      *(_DWORD *)(v18 + 4 * v34) = v30;
      *(_DWORD *)(v30 + 8) = *(_DWORD *)(v30 + 8) & 3 | v18;
      *(_BYTE *)(v30 + 8) |= 1u;
      *(_BYTE *)(v18 + 8) &= 0xFEu;
    }
  }
  else
  {
    *v73 = a1;
    v73[1] = a1;
    *(_DWORD *)(a1 + 8) = 0;
  }
LABEL_24:
  v20 = (unsigned int *)(a1 + 40);
  v21 = (_DWORD *)a1;
  *a3 = 0;
  a3[1] = a1 + 40;
  __dmb(0xBu);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireQueuedSpinLockInstrumented(a3, v20);
  }
  else
  {
    do
      v22 = __ldrex(v20);
    while ( __strex((unsigned int)a3, v20) );
    __dmb(0xBu);
    if ( v22 )
      KxWaitForLockOwnerShip(a3);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v72);
  }
  else
  {
    __dmb(0xBu);
    *v72 = 0;
  }
  *(_BYTE *)(a1 + 19) |= 0x80u;
  *(_BYTE *)(a1 + 15) |= 1u;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 36) = 0;
  *(_WORD *)(a1 + 46) = 0;
LABEL_31:
  v23 = a1 - 8 * *(unsigned __int8 *)(a1 + 12);
  if ( (*(_BYTE *)(a1 + 13) & 1) == 0 )
  {
    __dmb(0xBu);
    v24 = (unsigned __int8 *)(v23 + 811);
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 + 1, v24) );
    __dmb(0xBu);
    return (int)v21;
  }
  result = (int)v21;
  ++*(_BYTE *)(v23 + 485);
  return result;
}
