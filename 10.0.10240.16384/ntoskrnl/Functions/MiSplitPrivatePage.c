// MiSplitPrivatePage 
 
int __fastcall MiSplitPrivatePage(unsigned int a1, _DWORD *a2)
{
  unsigned int v2; // r5
  int v3; // r4
  int v4; // r9
  unsigned int v5; // r5
  int v6; // r7
  unsigned int *v7; // r6
  int v8; // r8
  unsigned __int8 *v9; // r3
  unsigned int v10; // r1
  unsigned int v11; // r0
  unsigned int v12; // r1
  int v13; // r4
  int v14; // r4
  int v15; // r2
  unsigned __int8 *v16; // r3
  unsigned int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r9
  int v23; // r3
  int v24; // r0
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v29; // [sp+8h] [bp-48h]
  int v30; // [sp+Ch] [bp-44h]
  int v31; // [sp+10h] [bp-40h]
  int v33; // [sp+18h] [bp-38h]
  int v35; // [sp+20h] [bp-30h]
  int v36; // [sp+28h] [bp-28h]
  unsigned int *v37[8]; // [sp+30h] [bp-20h] BYREF

  v2 = a1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *(_DWORD *)(v3 + 0x74);
  v29 = v3;
  v30 = v4;
  v35 = MiVadPureReserve((int)a2);
  v5 = ((v2 >> 10) & 0x3FFFFC) - 0x40000000;
  v33 = 0;
  v31 = 0;
  v36 = 0;
  v6 = MiChargeFullProcessCommitment(v4, 1);
  v7 = (unsigned int *)(v4 + 492);
  v8 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)(v4 + 492));
  }
  else
  {
    v9 = (unsigned __int8 *)(v4 + 495);
    do
      v10 = __ldrex(v9);
    while ( __strex(v10 | 0x80, v9) );
    __dmb(0xBu);
    if ( v10 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)(v4 + 492));
    while ( 1 )
    {
      v11 = *v7;
      if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v11 & 0x40000000) == 0 )
      {
        do
          v12 = __ldrex(v7);
        while ( v12 == v11 && __strex(v11 | 0x40000000, v7) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  while ( 1 )
  {
    if ( v35 )
    {
      if ( v5 != MiGetNextPageTable(v5, v5, 0, v8, 1, v37) )
      {
        MiUnlockWorkingSetExclusive((int)v7, v8);
        if ( v6 < 0 )
          return v6;
        v36 = 1;
        LOCK_PAGE_TABLE_COMMITMENT(v3, v4);
        v13 = MiCommitPageTablesForVad(a2, a1, a1);
        if ( v13 < 0 )
        {
          UNLOCK_PAGE_TABLE_COMMITMENT(v29, v4);
          MiReturnFullProcessCommitment(v4, 1);
          return v13;
        }
        v14 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v7);
        }
        else
        {
          v16 = (unsigned __int8 *)v7 + 3;
          do
            v17 = __ldrex(v16);
          while ( __strex(v17 | 0x80, v16) );
          __dmb(0xBu);
          if ( v17 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v7);
          v15 = 0x80000000;
          while ( 1 )
          {
            v18 = *v7;
            if ( (*v7 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v18 & 0x40000000) == 0 )
            {
              do
                v19 = __ldrex(v7);
              while ( v19 == v18 && __strex(v18 | 0x40000000, v7) );
              __dmb(0xBu);
              v15 = 0x80000000;
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v8 = v14;
        MiMakeSystemAddressValid(v5, 0, v15, v14, 1);
      }
    }
    else
    {
      MiMakeSystemAddressValid(v5, 0, 1, v8, 1);
    }
    v20 = MiGetProtoPteAddress(a2, a1 >> 12, 1, v37);
    v21 = *(_DWORD *)v5;
    v22 = v20;
    if ( !*(_DWORD *)v5 )
    {
      if ( v6 < 0 )
        goto LABEL_64;
      MI_INCREMENT_USED_PTES_BY_HANDLE_CLUSTER((_WORD *)(2 * ((a1 >> 22) - 534769440)), 1u);
      if ( v35 )
      {
        if ( !v22 || (v23 = *(_DWORD *)(((v22 >> 10) & 0x3FFFFC) - 0x40000000), (v23 & 2) == 0) && (v23 & 0x3E0) == 0 )
        {
          v31 = 1;
LABEL_57:
          v33 = 1;
          goto LABEL_58;
        }
      }
      v21 = -7136;
      if ( v5 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v5 = -7136;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v5 = -7136;
        if ( v5 + 1070596096 <= 0xFFF )
        {
          v24 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v24, (_DWORD *)(v24 + 4 * (v5 & 0xFFF)), -7136);
        }
      }
    }
    if ( (v21 & 2) != 0 )
      break;
    if ( (v21 & 0x400) == 0 )
      goto LABEL_68;
    v26 = v21 & 0xFFFFE000;
    if ( (v21 & 0xFFFFE000) != -8192 )
    {
      v26 = (v21 & 0x1FC | (v21 >> 2) & 0x3FFFFE00) - 0x40000000;
      if ( v26 != v22 )
        goto LABEL_68;
    }
    v4 = v30;
    if ( MiMakeProtoLeafValid((_DWORD *)v5, 24, v8, v26) != (_DWORD *)v5 )
    {
      if ( v21 == *(_DWORD *)v5 )
      {
        if ( v6 < 0 )
        {
LABEL_64:
          MiUnlockWorkingSetExclusive((int)v7, v8);
          return v6;
        }
        v31 = 1;
        goto LABEL_57;
      }
LABEL_49:
      v4 = v30;
    }
    v3 = v29;
  }
  v25 = MmPfnDatabase + 24 * (v21 >> 12);
  if ( (*(_DWORD *)(v25 + 20) & 0x8000000) == 0 || (*(_DWORD *)(v25 + 4) | 0x80000000) != v22 )
    goto LABEL_68;
  if ( v6 < 0 )
    goto LABEL_64;
  if ( !MiCopyOnWriteEx(a1, v5, -1, v8, 0) )
    goto LABEL_49;
  v31 = 1;
LABEL_58:
  a2[8] = a2[8] & 0x80000000 | (a2[8] + 1) & 0x7FFFFFFF;
  if ( v33 == 1 )
  {
    if ( v5 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v5 = 32;
    }
    else
    {
      __dmb(0xBu);
      *(_DWORD *)v5 = 32;
      if ( v5 + 1070596096 <= 0xFFF )
      {
        v27 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v27, (_DWORD *)(v27 + 4 * (v5 & 0xFFF)), 32);
      }
    }
  }
LABEL_68:
  MiUnlockWorkingSetExclusive((int)v7, v8);
  if ( v36 == 1 )
    UNLOCK_PAGE_TABLE_COMMITMENT(v29, v30);
  if ( !v31 && v6 >= 0 )
    MiReturnFullProcessCommitment(v30, 1);
  return 0;
}
