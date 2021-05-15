// MiCopyToUserVa 
 
int __fastcall MiCopyToUserVa(unsigned int a1, int a2, int a3, unsigned int a4)
{
  int v4; // r8
  unsigned int *v5; // r4
  int v6; // r9
  int v7; // r2
  int v8; // r0
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r5
  unsigned int *v12; // r5
  unsigned int v13; // r3
  unsigned int *v14; // r4
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r5
  int v20; // r10
  int v21; // r4
  int v22; // r0
  unsigned int *v23; // r4
  int v24; // r5
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r0
  unsigned int v28; // r1
  int v29; // r0
  unsigned int v30; // r4
  int v31; // r10
  unsigned int v32; // lr
  int v33; // r5
  int v34; // r3
  int v35; // r0
  unsigned int v36; // r1
  int v38; // [sp+8h] [bp-48h]
  unsigned int *v39; // [sp+Ch] [bp-44h]
  unsigned int v40; // [sp+10h] [bp-40h]
  unsigned int v41; // [sp+20h] [bp-30h]
  int v42; // [sp+24h] [bp-2Ch]
  int v43; // [sp+30h] [bp-20h]

  v41 = a4;
  v42 = a3;
  v40 = a1;
  v4 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v39 = (unsigned int *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  v38 = 0;
  v5 = (unsigned int *)(v4 + 492);
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 492));
  }
  else
  {
    v8 = 0;
    v9 = (unsigned __int8 *)(v4 + 495);
    do
    {
      v10 = __ldrex(v9);
      v7 = __strex(v10 | 0x80, v9);
    }
    while ( v7 );
    __dmb(0xBu);
    if ( v10 >> 7 )
      v8 = ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 492));
    while ( 1 )
    {
      v11 = *v5;
      if ( (*v5 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        v7 = v11 | 0x40000000;
        do
          v36 = __ldrex(v5);
        while ( v36 == v11 && __strex(v7, v5) );
        __dmb(0xBu);
      }
      ++v8;
      __dmb(0xAu);
      __yield();
    }
  }
  v12 = v39;
  while ( 1 )
  {
    while ( 1 )
    {
      MiMakeSystemAddressValid((unsigned int)v12, 0, v7, v6, 1);
      v13 = *v12;
      if ( (*v12 & 2) != 0 )
        break;
      MiUnlockWorkingSetExclusive(v4 + 492, v6);
      v14 = (unsigned int *)(v4 + 492);
      v6 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v14);
      }
      else
      {
        v15 = (unsigned __int8 *)(v4 + 495);
        do
        {
          v16 = __ldrex(v15);
          v7 = __strex(v16 | 0x80, v15);
        }
        while ( v7 );
        __dmb(0xBu);
        if ( v16 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v14);
        while ( 1 )
        {
          v17 = *v14;
          if ( (*v14 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v17 & 0x40000000) == 0 )
          {
            v7 = v17 | 0x40000000;
            do
              v18 = __ldrex(v14);
            while ( v18 == v17 && __strex(v7, v14) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    v19 = v13 >> 12;
    v20 = MmPfnDatabase + 24 * (v13 >> 12);
    v43 = v20;
    if ( (*(_DWORD *)(v20 + 20) & 0x8000000) == 0 )
      break;
    v21 = 0;
    if ( (*(_DWORD *)(v20 + 4) & 0x80000000) == 0 )
      goto LABEL_46;
    if ( !*(_DWORD *)(v4 + 272) )
      goto LABEL_46;
    v22 = MiLocateCloneAddress(v4);
    v21 = v22;
    if ( !v22 )
      goto LABEL_46;
    if ( MEMORY[0xC0402140] <= *(_QWORD *)(v22 + 40) )
    {
      v21 = 0;
      goto LABEL_46;
    }
    if ( v38 )
    {
LABEL_46:
      v12 = v39;
      if ( MiCopyOnWriteEx(v40, (unsigned int)v39, -1, v6, 0) == 1 )
      {
        v19 = *v39 >> 12;
        v43 = MmPfnDatabase + 24 * v19;
        if ( v21 )
          v38 = 0;
        break;
      }
    }
    else
    {
      v23 = (unsigned int *)(v4 + 492);
      MiUnlockWorkingSetExclusive(v4 + 492, v6);
      v24 = MiChargeFullProcessCommitment(v4, 1);
      if ( v24 < 0 )
        goto LABEL_69;
      v38 = 1;
      v6 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 492));
      }
      else
      {
        v25 = (unsigned __int8 *)(v4 + 495);
        do
        {
          v26 = __ldrex(v25);
          v7 = __strex(v26 | 0x80, v25);
        }
        while ( v7 );
        __dmb(0xBu);
        if ( v26 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 492));
        while ( 1 )
        {
          v27 = *v23;
          if ( (*v23 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v27 & 0x40000000) == 0 )
          {
            v7 = v27 | 0x40000000;
            do
              v28 = __ldrex(v23);
            while ( v28 == v27 && __strex(v7, v23) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v12 = v39;
    }
  }
  v29 = MiReservePtes(&dword_634D58, 1u);
  v30 = v29;
  if ( v29 )
  {
    v31 = v29 << 10;
    v32 = (dword_681120 & 0x1ED | (v19 << 12) | MiDetermineUserGlobalPteMask(v29)) & 0xFFFFF1FF | 0x13;
    if ( v30 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v30 = v32;
    }
    else
    {
      v33 = 0;
      v34 = *(_DWORD *)v30;
      __dmb(0xBu);
      *(_DWORD *)v30 = v32;
      if ( (v34 & 2) == 0 )
        v33 = 1;
      if ( v30 + 1070596096 <= 0xFFF )
      {
        v35 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v35, (_DWORD *)(v35 + 4 * (v30 & 0xFFF)), v32);
      }
      if ( v33 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  else
  {
    v31 = MiMapPageInHyperSpaceWorker(v19, 0, 0x80000000);
  }
  memmove((v40 & 0xFFF) + v31, v42, v41);
  if ( v30 )
    MiReleasePtes(&dword_634D58, v30, 1u);
  else
    MiUnmapPageInHyperSpaceWorker(v31, 17, 0x80000000);
  MiLockPageAndSetDirty(v43, 1);
  MiUnlockWorkingSetExclusive(v4 + 492, v6);
  v24 = 0;
LABEL_69:
  if ( v38 )
    MiReturnFullProcessCommitment(v4, 1);
  return v24;
}
