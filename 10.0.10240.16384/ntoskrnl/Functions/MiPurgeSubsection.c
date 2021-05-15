// MiPurgeSubsection 
 
int __fastcall MiPurgeSubsection(unsigned int a1)
{
  unsigned int v2; // r4
  unsigned int *v3; // r10
  int v4; // r6
  int v5; // r5
  unsigned int *v6; // r6
  unsigned __int8 *v7; // r3
  unsigned int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r1
  int v11; // r0
  unsigned int v12; // r3
  int v13; // r10
  int v14; // lr
  unsigned int v15; // r3
  int v16; // r9
  int v17; // r0
  unsigned int *v18; // r2
  unsigned int v19; // r0
  unsigned __int8 *v20; // r3
  unsigned int v21; // r1
  unsigned __int8 *v22; // r1
  int v23; // r3
  unsigned int v24; // r2
  int v25; // r2
  unsigned int *v26; // r2
  unsigned int v27; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int *v31; // r4
  int v32; // r5
  unsigned __int8 *v33; // r3
  unsigned int v34; // r1
  unsigned int v35; // r0
  unsigned int v36; // r1
  char v37[4]; // [sp+8h] [bp-38h] BYREF
  unsigned int *v38; // [sp+Ch] [bp-34h]
  unsigned int v39; // [sp+10h] [bp-30h]
  int v40; // [sp+14h] [bp-2Ch]
  unsigned int v41; // [sp+18h] [bp-28h]
  int v42; // [sp+1Ch] [bp-24h]
  int vars4; // [sp+44h] [bp+4h]

  v2 = *(_DWORD *)(a1 + 4);
  v3 = *(unsigned int **)a1;
  v4 = 17;
  v5 = 0;
  v41 = v2 + 4 * *(_DWORD *)(a1 + 28);
  v38 = v3;
  v37[0] = 17;
  if ( v2 >= v41 )
  {
LABEL_59:
    if ( v4 != 17 )
      MiUnlockProtoPoolPage(v5, v4);
    return 1;
  }
  v42 = -1073741824;
  while ( 1 )
  {
    v39 = v2 & 0xFFF;
    if ( (v2 & 0xFFF) != 0 && v4 != 17 )
      break;
    if ( v4 != 17 )
      MiUnlockProtoPoolPage(v5, v4);
    v5 = MiCheckProtoPtePageState(v2, v37);
    if ( v5 )
    {
      v6 = v3 + 9;
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v3 + 9);
      }
      else
      {
        v7 = (unsigned __int8 *)v3 + 39;
        do
          v8 = __ldrex(v7);
        while ( __strex(v8 | 0x80, v7) );
        __dmb(0xBu);
        if ( v8 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v3 + 9);
        while ( 1 )
        {
          v9 = *v6;
          if ( (*v6 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v9 & 0x40000000) == 0 )
          {
            do
              v10 = __ldrex(v6);
            while ( v10 == v9 && __strex(v9 | 0x40000000, v6) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( *(_DWORD *)(a1 + 60) != 1 || (*(_WORD *)(a1 + 16) & 1) != 0 )
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 9, vars4);
        }
        else
        {
          __dmb(0xBu);
          v3[9] = 0;
        }
        MiUnlockProtoPoolPage(v5, (unsigned __int8)v37[0]);
        return 0;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 9, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v6 = 0;
      }
      v4 = (unsigned __int8)v37[0];
      break;
    }
    v4 = (unsigned __int8)v37[0];
    v2 = (v2 & 0xFFFFF000) + 4096;
LABEL_58:
    if ( v2 >= v41 )
      goto LABEL_59;
  }
  v11 = MiLockLeafPage((unsigned int *)v2, 0);
  v12 = *(_DWORD *)v2;
  if ( !v11 )
  {
    if ( (v12 & 0xC00) == 0 && v12 )
      KeBugCheck2(222, 4, a1, v2, v12, 0);
LABEL_57:
    v2 += 4;
    goto LABEL_58;
  }
  if ( (v12 & 2) != 0 )
    KeBugCheck2(222, 3, a1, v2, v12, 0);
  v40 = v12 >> 12;
  v13 = MmPfnDatabase + 24 * (v12 >> 12);
  if ( (*(_BYTE *)(v13 + 18) & 0x10) == 0 && !*(_WORD *)(v13 + 16) )
  {
    MiDereferenceControlAreaPfn(v38, a1, 2);
    v14 = *(_DWORD *)(v13 + 8);
    if ( v2 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v2 = v14;
    }
    else
    {
      v15 = *(_DWORD *)v2;
      v16 = 0;
      __dmb(0xBu);
      *(_DWORD *)v2 = v14;
      if ( (v15 & 2) == 0 && (v14 & 2) != 0 )
        v16 = 1;
      if ( v2 + 1070596096 <= 0xFFF )
      {
        v17 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v17, (_DWORD *)(v17 + 4 * v39), v14);
      }
      if ( v16 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
    MiUnlinkPageFromList(v13, 0);
    MiInsertPageInFreeOrZeroedList(v40, 2);
    __dmb(0xBu);
    v18 = (unsigned int *)(v13 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    v20 = (unsigned __int8 *)(v5 + 15);
    do
      v21 = __ldrex(v20);
    while ( __strex(v21 | 0x80, v20) );
    __dmb(0xBu);
    if ( v21 >> 7 )
    {
      v22 = (unsigned __int8 *)(v5 + 15);
      do
      {
        do
        {
          __dmb(0xAu);
          __yield();
          v23 = *(_DWORD *)(v5 + 12);
          __dmb(0xBu);
        }
        while ( (v23 & 0x80000000) != 0 );
        do
          v24 = __ldrex(v22);
        while ( __strex(v24 | 0x80, v22) );
        __dmb(0xBu);
      }
      while ( v24 >> 7 );
    }
    if ( (*(_BYTE *)(v5 + 18) & 7) != 6 )
      KeBugCheck2(78, 153, (v5 - MmPfnDatabase) / 24, *(_BYTE *)(v5 + 18) & 7, *(_DWORD *)(v5 + 12) & ~v42, 0);
    v25 = *(_DWORD *)(v5 + 12);
    *(_DWORD *)(v5 + 12) = v25 & 0xC0000000 | ((v25 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
    if ( (v25 & 0x3FFFFFFF) == 1 )
      MiPfnShareCountIsZero(v5, 0);
    __dmb(0xBu);
    v26 = (unsigned int *)(v5 + 12);
    do
      v27 = __ldrex(v26);
    while ( __strex(v27 & 0x7FFFFFFF, v26) );
    v3 = v38;
    goto LABEL_57;
  }
  __dmb(0xBu);
  v29 = (unsigned int *)(v13 + 12);
  do
    v30 = __ldrex(v29);
  while ( __strex(v30 & 0x7FFFFFFF, v29) );
  MiUnlockProtoPoolPage(v5, v4);
  v31 = v38 + 9;
  v32 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v31);
  }
  else
  {
    v33 = (unsigned __int8 *)v31 + 3;
    do
      v34 = __ldrex(v33);
    while ( __strex(v34 | 0x80, v33) );
    __dmb(0xBu);
    if ( v34 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v31);
    while ( 1 )
    {
      v35 = *v31;
      if ( (*v31 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v35 & 0x40000000) == 0 )
      {
        do
          v36 = __ldrex(v31);
        while ( v36 == v35 && __strex(v35 | 0x40000000, v31) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *(_WORD *)(a1 + 16) |= 1u;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v31, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v31 = 0;
  }
  KfLowerIrql(v32);
  return 0;
}
