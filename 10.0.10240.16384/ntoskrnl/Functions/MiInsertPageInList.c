// MiInsertPageInList 
 
int __fastcall MiInsertPageInList(int a1, int a2, int a3)
{
  char v3; // r7
  int *v5; // r6
  int v6; // r4
  int v7; // r9
  int v8; // r1
  int v9; // r2
  unsigned int v10; // r3
  int v11; // r1
  int v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r9
  unsigned int v15; // r9
  unsigned int v16; // r9
  unsigned int *v17; // lr
  unsigned int v18; // r1
  int v19; // r1
  int result; // r0
  int v21; // r3
  int v22; // r0
  unsigned int *v23; // r1
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r1
  unsigned int *v27; // r6
  unsigned int v28; // r1
  unsigned int v29; // r3
  int v30; // r2
  int v31; // r2
  unsigned int v32; // r1
  unsigned int v33; // r1
  int v34; // r3
  unsigned int *v35; // r2
  int *v36; // r2
  unsigned int v37; // r1
  unsigned int *v38; // r0
  unsigned __int8 *v39; // r3
  unsigned int v40; // r1
  unsigned int v41; // lr
  int v42; // r3
  char *v43; // r4
  int v44; // r0
  unsigned int *v45; // r1
  int *v46; // r0
  unsigned int *v47; // r2
  unsigned int v48; // r0
  unsigned int v49; // r1
  unsigned int v50; // r1
  int v51; // r0
  unsigned int *v52; // r1
  int *v53; // r0
  unsigned int *v54; // r2
  unsigned int v55; // r0
  int v56; // r2
  int v57; // r3
  int v58; // [sp+0h] [bp-48h]
  char v59; // [sp+4h] [bp-44h]
  int v60; // [sp+8h] [bp-40h]
  int v61; // [sp+8h] [bp-40h]
  int v62; // [sp+Ch] [bp-3Ch]
  int v63; // [sp+10h] [bp-38h] BYREF
  unsigned int *v64; // [sp+14h] [bp-34h]
  int v65; // [sp+18h] [bp-30h]
  int var28[11]; // [sp+20h] [bp-28h] BYREF

  v63 = 0;
  v64 = 0;
  v65 = 0;
  v3 = a2;
  if ( (a2 & 4) != 0 )
  {
    v5 = &dword_63FC80;
  }
  else if ( (a2 & 8) != 0 )
  {
    v5 = &dword_640680;
  }
  else
  {
    if ( (a2 & 0x10) == 0 )
      return sub_533424(a1, a2, a3, 8);
    v5 = &dword_640700;
  }
  v6 = v5[1];
  v59 = v6;
  v7 = (a1 - MmPfnDatabase) / 24;
  v60 = v7;
  __dmb(0xFu);
  v8 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  v9 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)(a1 + 12) = (v9 ^ (v8 << 20)) & 0xF00000 ^ v9;
  v58 = 0;
  v62 = 0;
  if ( v6 == 2 )
  {
    v10 = *(unsigned __int8 *)(a1 + 19);
    if ( (v10 & 0x40) != 0 )
    {
      MiRestoreTransitionPte(a1, 0);
      return MiInsertPageInList(a1, 32);
    }
    v11 = (v10 >> 3) & 1;
    if ( v11 == 1 )
      v12 = 5;
    else
      v12 = v10 & 7;
    v5 = &dword_63FD00[5 * v12];
    if ( v11 )
      goto LABEL_15;
    if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
    {
      do
        v13 = __ldrex((unsigned int *)&dword_634680);
      while ( __strex(v13 + 1, (unsigned int *)&dword_634680) );
    }
    else
    {
      do
        v33 = __ldrex(dword_640300);
      while ( __strex(v33 + 1, dword_640300) );
    }
    do
    {
      v14 = __ldrex((unsigned int *)&dword_640580);
      v15 = v14 + 1;
    }
    while ( __strex(v15, (unsigned int *)&dword_640580) );
    if ( v15 > 0x80 )
    {
LABEL_12:
      v16 = v15 - 1;
      if ( v16 == dword_6402AC || v16 == dword_6402B0 )
        MiUpdateAvailableEvents(MiSystemPartition);
      v7 = v60;
LABEL_15:
      if ( (v3 & 0x80) == 0 )
      {
        v17 = (unsigned int *)(v5 + 4);
        v63 = 0;
        v64 = (unsigned int *)(v5 + 4);
        __dmb(0xBu);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireQueuedSpinLockInstrumented(&v63, v5 + 4);
        }
        else
        {
          do
            v18 = __ldrex(v17);
          while ( __strex((unsigned int)&v63, v17) );
          __dmb(0xBu);
          if ( v18 )
            KxWaitForLockOwnerShip(&v63);
        }
      }
      goto LABEL_20;
    }
    if ( v15 == 128 )
    {
      v42 = 1;
    }
    else
    {
      if ( v15 != 2 )
        goto LABEL_12;
      v42 = 0;
    }
    v43 = (char *)&unk_640284 + 20 * v42;
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640280, var28, 5 * v42, &unk_640284);
    KeSetEvent((int)v43, 0, 0);
    ++*((_DWORD *)v43 + 4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(var28);
    }
    else
    {
      v44 = var28[0];
      if ( !var28[0] )
      {
        v45 = (unsigned int *)var28[1];
        __dmb(0xBu);
        do
          v46 = (int *)__ldrex(v45);
        while ( v46 == var28 && __strex(0, v45) );
        if ( v46 == var28 )
          goto LABEL_99;
        v44 = KxWaitForLockChainValid(var28);
      }
      var28[0] = 0;
      __dmb(0xBu);
      v47 = (unsigned int *)(v44 + 4);
      do
        v48 = __ldrex(v47);
      while ( __strex(v48 ^ 1, v47) );
    }
LABEL_99:
    LOBYTE(v6) = v59;
    goto LABEL_12;
  }
  if ( v6 == 3 )
  {
    if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
      v24 = (unsigned int *)&dword_634680;
    else
      v24 = dword_640300;
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 + 1, v24) );
    goto LABEL_40;
  }
  if ( v6 != 4 )
  {
    MiClearPfnImageVerified(a1, 12, v9, 0);
    KeAcquireInStackQueuedSpinLockAtDpcLevel(&dword_640090, &v63, v56, v57);
    *(_DWORD *)(a1 + 4) = -4;
    goto LABEL_20;
  }
  v58 = *(_DWORD *)(*(_DWORD *)(a1 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(a1 + 8) & 0x3FC)));
  if ( (*(_DWORD *)(a1 + 20) & 0x8000000) != 0 )
  {
    v36 = &dword_634680;
    do
      v37 = __ldrex((unsigned int *)&dword_634680);
    while ( __strex(v37 + 1, (unsigned int *)&dword_634680) );
  }
  else
  {
    v36 = (int *)dword_640300;
    do
      v49 = __ldrex(dword_640300);
    while ( __strex(v49 + 1, dword_640300) );
  }
  KeAcquireInStackQueuedSpinLockAtDpcLevel(v5 + 4, &v63, v36, 0);
  v38 = (unsigned int *)(v58 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v38);
    v38 = (unsigned int *)(v58 + 36);
  }
  else
  {
    v39 = (unsigned __int8 *)(v58 + 39);
    do
      v40 = __ldrex(v39);
    while ( __strex(v40 | 0x80, v39) );
    __dmb(0xBu);
    if ( v40 >> 7 )
    {
      ExpWaitForSpinLockExclusiveAndAcquire(v38);
      v38 = (unsigned int *)(v58 + 36);
    }
    while ( 1 )
    {
      v41 = *v38;
      if ( (*v38 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v41 & 0x40000000) == 0 )
      {
        do
          v50 = __ldrex(v38);
        while ( v50 == v41 && __strex(v41 | 0x40000000, v38) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( (*(_DWORD *)(v58 + 28) & 8) == 0 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v38);
    }
    else
    {
      __dmb(0xBu);
      *v38 = 0;
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v63);
    }
    else
    {
      v51 = v63;
      if ( !v63 )
      {
        v52 = v64;
        __dmb(0xBu);
        do
          v53 = (int *)__ldrex(v52);
        while ( v53 == &v63 && __strex(0, v52) );
        if ( v53 == &v63 )
          goto LABEL_124;
        v51 = KxWaitForLockChainValid(&v63);
      }
      v63 = 0;
      __dmb(0xBu);
      v54 = (unsigned int *)(v51 + 4);
      do
        v55 = __ldrex(v54);
      while ( __strex(v55 ^ 1, v54) );
    }
LABEL_124:
    v58 = 0;
    LOBYTE(v6) = 3;
    do
LABEL_40:
      v26 = __ldrex((unsigned int *)&dword_640680);
    while ( __strex(v26 + 1, (unsigned int *)&dword_640680) );
    if ( (*(_DWORD *)(a1 + 8) & 0x400) != 0 )
    {
      v34 = *(_DWORD *)(dword_6404B8 + 16);
      v5 = (int *)((char *)&unk_63FF00 + 20 * v34);
      KeAcquireInStackQueuedSpinLockAtDpcLevel(v5 + 4, &v63, &unk_63FF00, v34);
      *(_DWORD *)(a1 + 20) = *(_DWORD *)(a1 + 20) & 0xFFFFFFF | ((((char *)v5 - (char *)MiSystemPartition - 2048) / 20) << 28);
    }
    else
    {
      if ( (v3 & 0x80) == 0 )
      {
        v27 = (unsigned int *)(v5 + 4);
        v63 = 0;
        v64 = v27;
        __dmb(0xBu);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          KiAcquireQueuedSpinLockInstrumented(&v63, v27);
        }
        else
        {
          do
            v28 = __ldrex(v27);
          while ( __strex((unsigned int)&v63, v27) );
          __dmb(0xBu);
          if ( v28 )
            KxWaitForLockOwnerShip(&v63);
        }
      }
      v29 = *(_DWORD *)(a1 + 8);
      v30 = (v29 >> 2) & 1;
      if ( (v29 & 8) != 0 || v30 == dword_63F99C )
        v5 = (int *)((char *)&unk_63FE80 + 20 * v30);
      else
        v5 = &dword_63FE00;
      if ( !*v5 )
        v62 = 1;
      ++dword_640718;
    }
    v31 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    ++*(_DWORD *)(v31 + 628);
    v32 = dword_640580;
    v61 = dword_640580;
    if ( (unsigned int)dword_640580 < 0x400 )
    {
      if ( (unsigned int)dword_640580 < 0x100 && (unsigned int)dword_640718 >= 0x10 )
      {
        MiWakeModifiedPageWriter(MiSystemPartition, -1);
        v32 = v61;
      }
      if ( (unsigned int)(dword_640680 - dword_640718) >= 0x320
        || v32 < 0x100 && (unsigned int)(dword_640680 - dword_640718) >= 0x10 )
      {
        KeSetEvent((int)&unk_63F8C4, 0, 0);
      }
    }
  }
LABEL_20:
  if ( (*(_BYTE *)(a1 + 19) & 8) != 0 )
    MiInsertDecayClusterTimer(a1);
  else
    ++*v5;
  v19 = v5[3];
  result = 0xFFFFF;
  if ( v19 == 0xFFFFF )
    v5[2] = v7;
  else
    *(_DWORD *)(MmPfnDatabase + 24 * v19) = v7;
  *(_BYTE *)(a1 + 18) ^= (*(_BYTE *)(a1 + 18) ^ v6) & 7;
  v5[3] = v7;
  v21 = *(_DWORD *)(a1 + 12);
  *(_DWORD *)a1 = 0xFFFFF;
  *(_DWORD *)(a1 + 12) = v21 & 0xFFF00000 | v19 & 0xFFFFF;
  if ( v58 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v58 + 36);
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)(v58 + 36) = 0;
    }
  }
  if ( (v3 & 0x80) != 0 )
    goto LABEL_32;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    result = KiReleaseQueuedSpinLockInstrumented(&v63);
  }
  else
  {
    v22 = v63;
    if ( !v63 )
    {
      v23 = v64;
      __dmb(0xBu);
      do
        result = __ldrex(v23);
      while ( (int *)result == &v63 && __strex(0, v23) );
      if ( (int *)result == &v63 )
        goto LABEL_32;
      v22 = KxWaitForLockChainValid(&v63);
    }
    v63 = 0;
    __dmb(0xBu);
    v35 = (unsigned int *)(v22 + 4);
    do
      result = __ldrex(v35);
    while ( __strex(result ^ 1, v35) );
  }
LABEL_32:
  if ( v62 )
    result = KeSetEvent((int)&unk_63F908, 0, 0);
  return result;
}
