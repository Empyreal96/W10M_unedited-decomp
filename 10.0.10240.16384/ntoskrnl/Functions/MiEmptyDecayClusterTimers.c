// MiEmptyDecayClusterTimers 
 
int __fastcall MiEmptyDecayClusterTimers(int a1)
{
  int v1; // r9
  __int64 v2; // kr00_8
  unsigned int v3; // r5
  unsigned int v4; // r8
  __int64 v5; // r0
  int v6; // r3
  int v7; // r3
  int v8; // r10
  unsigned int *v9; // r8
  int v10; // r0
  int v11; // r7
  unsigned int v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r4
  int v16; // r3
  int v17; // r4
  unsigned __int8 *v18; // r3
  unsigned int v19; // r1
  char v20; // r5
  int v21; // r0
  unsigned int *v22; // r2
  int *v23; // r1
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v26; // r0
  unsigned int *v27; // r1
  int *v28; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r0
  int v33; // r0
  unsigned int *v34; // r1
  int *v35; // r0
  unsigned int *v36; // r2
  unsigned int v37; // r0
  int v38; // r0
  unsigned int *v39; // r1
  int *v40; // r0
  unsigned int *v41; // r2
  unsigned int v42; // r0
  int v45; // [sp+4h] [bp-2Ch]
  int v46; // [sp+8h] [bp-28h] BYREF
  unsigned int *v47; // [sp+Ch] [bp-24h]
  int vars4; // [sp+34h] [bp+4h]

  v1 = a1;
  do
  {
    v2 = MEMORY[0xFFFF93B0];
    v3 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v4 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v3 != MEMORY[0xFFFF9010] )
    {
      LODWORD(v5) = sub_5169A8();
      return v5;
    }
  }
  while ( v2 != MEMORY[0xFFFF93B0] );
  v5 = __PAIR64__(v3, v4) - v2;
  if ( __PAIR64__(v3, v4) - v2 - *(_QWORD *)(v1 + 2792) < (unsigned int)dword_989680 )
    return v5;
  v6 = *(_DWORD *)(v1 + 2788);
  *(_QWORD *)(v1 + 2792) = v5;
  v7 = ((_BYTE)v6 + 1) & 3;
  v8 = v1 + 4 * v7;
  v45 = v7;
  if ( (*(_DWORD *)(v8 + 2772) & 0xFFFE0000) == -131072 )
    goto LABEL_7;
  v9 = (unsigned int *)(v1 + 1652);
  while ( 1 )
  {
    v10 = KfRaiseIrql(2);
    v46 = 0;
    v47 = (unsigned int *)(v1 + 1652);
    v11 = v10;
    __dmb(0xBu);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireQueuedSpinLockInstrumented(&v46, v9);
    }
    else
    {
      do
        v12 = __ldrex(v9);
      while ( __strex((unsigned int)&v46, v9) );
      __dmb(0xBu);
      if ( v12 )
        KxWaitForLockOwnerShip(&v46);
    }
    v13 = *(_DWORD *)(v8 + 2772) >> 17;
    if ( v13 == 0x7FFF )
      break;
    v14 = v13 + dword_634690;
    v15 = MmPfnDatabase + 24 * v14;
    v16 = *(_DWORD *)(v15 + 8) >> 12;
    if ( v16 == v14 )
    {
      MiUnlinkPageFromList(MmPfnDatabase + 24 * v14, 1);
      *(_BYTE *)(v15 + 19) &= 0xF7u;
      MiRemoveDecayClusterTimer(v15);
      if ( (dword_682604 & 0x10000) != 0 )
        goto LABEL_45;
      v33 = v46;
      if ( v46 )
        goto LABEL_52;
      v34 = v47;
      __dmb(0xBu);
      do
        v35 = (int *)__ldrex(v34);
      while ( v35 == &v46 && __strex(0, v34) );
      if ( v35 != &v46 )
      {
        v33 = KxWaitForLockChainValid(&v46);
LABEL_52:
        v46 = 0;
        __dmb(0xBu);
        v36 = (unsigned int *)(v33 + 4);
        do
          v37 = __ldrex(v36);
        while ( __strex(v37 ^ 1, v36) );
        goto LABEL_27;
      }
    }
    else
    {
      v17 = MmPfnDatabase + 24 * v16;
      v18 = (unsigned __int8 *)(v17 + 15);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 | 0x80, v18) );
      __dmb(0xBu);
      if ( !(v19 >> 7) )
      {
        v20 = *(_BYTE *)(v17 + 19);
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseQueuedSpinLockInstrumented(&v46, vars4);
        }
        else
        {
          v21 = v46;
          if ( !v46 )
          {
            v22 = v47;
            __dmb(0xBu);
            do
              v23 = (int *)__ldrex(v22);
            while ( v23 == &v46 && __strex(0, v22) );
            if ( v23 == &v46 )
              goto LABEL_25;
            v21 = KxWaitForLockChainValid(&v46);
          }
          v46 = 0;
          __dmb(0xBu);
          v29 = (unsigned int *)(v21 + 4);
          do
            v30 = __ldrex(v29);
          while ( __strex(v30 ^ 1, v29) );
        }
LABEL_25:
        MiRelinkStandbyPage(v17, v20 & 7, 1022);
        __dmb(0xBu);
        v24 = (unsigned int *)(v17 + 12);
        do
          v25 = __ldrex(v24);
        while ( __strex(v25 & 0x7FFFFFFF, v24) );
        goto LABEL_27;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
LABEL_45:
        KiReleaseQueuedSpinLockInstrumented(&v46, vars4);
        goto LABEL_27;
      }
      v38 = v46;
      if ( v46 )
        goto LABEL_63;
      v39 = v47;
      __dmb(0xBu);
      do
        v40 = (int *)__ldrex(v39);
      while ( v40 == &v46 && __strex(0, v39) );
      if ( v40 != &v46 )
      {
        v38 = KxWaitForLockChainValid(&v46);
LABEL_63:
        v46 = 0;
        __dmb(0xBu);
        v41 = (unsigned int *)(v38 + 4);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 ^ 1, v41) );
        goto LABEL_27;
      }
    }
LABEL_27:
    KfLowerIrql(v11);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseQueuedSpinLockInstrumented(&v46, vars4);
    goto LABEL_34;
  }
  v26 = v46;
  if ( v46 )
  {
LABEL_40:
    v46 = 0;
    __dmb(0xBu);
    v31 = (unsigned int *)(v26 + 4);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 ^ 1, v31) );
    goto LABEL_34;
  }
  v27 = v47;
  __dmb(0xBu);
  do
    v28 = (int *)__ldrex(v27);
  while ( v28 == &v46 && __strex(0, v27) );
  if ( v28 != &v46 )
  {
    v26 = KxWaitForLockChainValid(&v46);
    goto LABEL_40;
  }
LABEL_34:
  LODWORD(v5) = KfLowerIrql(v11);
  v1 = a1;
LABEL_7:
  *(_DWORD *)(v1 + 2788) = v45;
  return v5;
}
