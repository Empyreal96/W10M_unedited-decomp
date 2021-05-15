// MiLockCode 
 
int __fastcall MiLockCode(int a1, unsigned int a2, unsigned int a3, char a4)
{
  int v4; // lr
  char v5; // r9
  unsigned int v6; // r8
  int v7; // r5
  int v8; // r3
  unsigned int *v10; // r4
  unsigned int v11; // r6
  int v12; // r10
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r4
  int v17; // r5
  unsigned int v18; // r9
  unsigned __int8 *v19; // r3
  unsigned int v20; // r1
  unsigned int v21; // r3
  int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r4
  int v25; // r4
  unsigned int v26; // r2
  unsigned int v27; // r0
  int v28; // r7
  unsigned int *v29; // r2
  unsigned int v30; // r0
  unsigned int v31; // r4
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  int v34; // r0
  int v35; // r4
  unsigned __int8 *v36; // r3
  unsigned int v37; // r1
  unsigned int v38; // r0
  unsigned int v39; // r1
  unsigned int v40; // r1
  unsigned int v41; // r1
  unsigned __int8 *v42; // r1
  int v43; // r3
  unsigned int v44; // r2
  unsigned __int8 *v45; // r1
  int v46; // r3
  unsigned int v47; // r2
  unsigned int *v48; // [sp+Ch] [bp-E4h]
  int v49; // [sp+10h] [bp-E0h]
  int v51; // [sp+18h] [bp-D8h]
  int v52; // [sp+1Ch] [bp-D4h]
  unsigned int v53; // [sp+20h] [bp-D0h]
  int v54; // [sp+24h] [bp-CCh]
  unsigned __int8 *v57; // [sp+30h] [bp-C0h]
  int v58; // [sp+38h] [bp-B8h] BYREF
  char v59; // [sp+3Ch] [bp-B4h]
  char v60; // [sp+3Dh] [bp-B3h]
  int v61; // [sp+40h] [bp-B0h]
  int v62; // [sp+44h] [bp-ACh]
  int v63; // [sp+48h] [bp-A8h]
  int v64; // [sp+4Ch] [bp-A4h]

  v4 = (a2 << 10 >> 20) & 0xFFC;
  v5 = a4;
  v53 = a3;
  v6 = a2;
  if ( (*(_DWORD *)(v4 - 1070596096) & 0x402) == 1026 )
    return 0;
  v54 = 0;
  v7 = 1;
  v51 = 1;
  if ( a2 << 10 >= dword_63389C )
  {
    v8 = *((unsigned __int8 *)&MiState[2423] + ((int)(v4 - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v8 == 11 || v8 == 1 )
    {
      v52 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324);
      v10 = (unsigned int *)(v52 + 3248);
      v54 = 2;
      goto LABEL_10;
    }
    if ( v8 == 6 || v8 == 14 || v8 == 7 )
      return sub_538B38();
  }
  v10 = (unsigned int *)&dword_634F00;
  v52 = 0;
LABEL_10:
  v11 = a3;
  v48 = v10;
  MiPrefetchDriverPages(a2, a3);
  v62 = 0;
  v59 = 0;
  v58 = v54;
  v63 = 0;
  v61 = 33;
  v12 = -1;
  v60 = 0;
  v64 = 0;
  v49 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v10);
  }
  else
  {
    v13 = (unsigned __int8 *)v10 + 3;
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
    __dmb(0xBu);
    if ( v14 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v10);
    while ( 1 )
    {
      v15 = *v10;
      if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v15 & 0x40000000) == 0 )
      {
        do
          v39 = __ldrex(v10);
        while ( v39 == v15 && __strex(v15 | 0x40000000, v10) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v57 = (unsigned __int8 *)v10 + 3;
  do
  {
    v16 = *(_DWORD *)v6;
    if ( (*(_DWORD *)v6 & 2) != 0 )
    {
      v17 = MmPfnDatabase + 24 * (v16 >> 12);
      if ( (*(_DWORD *)(v17 + 4) & 0x80000000) == 0 )
      {
        MiFlushTbList(&v58);
        MiCopyOnWriteEx(v6 << 10, v6, -1, v49, 0);
        goto LABEL_48;
      }
      if ( (*(_DWORD *)(v17 + 20) & 0x8000000) != 0 && !v52 && (v5 & 1) != 0 )
      {
        MiFlushTbList(&v58);
        MiMakeDriverPagesPrivate(a1, v6, v11, v49, 0);
        goto LABEL_48;
      }
      if ( (v16 & 0x80) == 0 && (v16 & 0x100) != 0 )
      {
        MiFlushTbList(&v58);
        MiMakeDriverPagesPrivate(a1, v6, v11, v49, 1);
        goto LABEL_48;
      }
      v18 = 0;
      if ( v12 == -1 )
      {
        if ( (a4 & 2) != 0 )
        {
          if ( (*(_BYTE *)(v17 + 19) & 8) != 0 || !*(_DWORD *)v17 )
            goto LABEL_26;
        }
        else if ( *(_WORD *)(v17 + 16) != 1 )
        {
          goto LABEL_26;
        }
        if ( ((v16 >> 12) & 0x3FF) < (dword_632F30 & 0x3FFu) )
        {
          MiFlushTbList(&v58);
          v34 = MiUnlockWorkingSetExclusive(v48, v49);
          v12 = MiAllocateDriverPage(v34);
          v35 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v48);
          }
          else
          {
            v36 = (unsigned __int8 *)v48 + 3;
            do
              v37 = __ldrex(v36);
            while ( __strex(v37 | 0x80, v36) );
            __dmb(0xBu);
            if ( v37 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire(v48);
            while ( 1 )
            {
              v38 = *v48;
              if ( (*v48 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v38 & 0x40000000) == 0 )
              {
                do
                  v41 = __ldrex(v48);
                while ( v41 == v38 && __strex(v38 | 0x40000000, v48) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          v49 = v35;
          goto LABEL_47;
        }
      }
LABEL_26:
      v19 = (unsigned __int8 *)(v17 + 15);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 0x80, v19) );
      __dmb(0xBu);
      if ( v20 >> 7 )
      {
        v42 = (unsigned __int8 *)(v17 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v43 = *(_DWORD *)(v17 + 12);
            __dmb(0xBu);
          }
          while ( (v43 & 0x80000000) != 0 );
          do
            v44 = __ldrex(v42);
          while ( __strex(v44 | 0x80, v42) );
          __dmb(0xBu);
        }
        while ( v44 >> 7 );
      }
      if ( v12 == -1
        || (a4 & 2) == 0
        || (*(_BYTE *)(v17 + 19) & 8) != 0
        || !*(_DWORD *)v17
        || ((v16 >> 12) & 0x3FF) >= (v12 & 0x3FFu) )
      {
        goto LABEL_30;
      }
      v28 = MmPfnDatabase;
      __dmb(0xBu);
      v29 = (unsigned int *)(v17 + 12);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 & 0x7FFFFFFF, v29) );
      if ( (*(_DWORD *)(v17 + 20) & 0x8000000) != 0 && (*(_DWORD *)(v17 + 8) & 0x400) != 0 )
      {
        v31 = MiLockProtoPoolPage(*(_DWORD *)(v17 + 4) | 0x80000000, 0);
        if ( !v31 )
        {
LABEL_72:
          if ( v31 > 1 )
            MiUnlockProtoPoolPage(v31, 17);
          v32 = (unsigned __int8 *)(v17 + 15);
          do
            v33 = __ldrex(v32);
          while ( __strex(v33 | 0x80, v32) );
          __dmb(0xBu);
          if ( v33 >> 7 )
          {
            v45 = (unsigned __int8 *)(v17 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v46 = *(_DWORD *)(v17 + 12);
                __dmb(0xBu);
              }
              while ( (v46 & 0x80000000) != 0 );
              do
                v47 = __ldrex(v45);
              while ( __strex(v47 | 0x80, v45) );
              __dmb(0xBu);
            }
            while ( v47 >> 7 );
          }
          v11 = v53;
LABEL_30:
          if ( (a4 & 2) != 0 )
          {
            if ( (*(_BYTE *)(v17 + 19) & 8) == 0 && *(_DWORD *)v17 )
              MiRemoveImagePageFromSystemWorkingSet(v48, v6, v17);
          }
          else if ( v54 == 2 )
          {
            if ( !MiAddLockedPageCharge(v17, 0) )
              v51 = 0;
          }
          else
          {
            if ( MiAreChargesNeededToLockPage(v17) )
              *(_BYTE *)(v17 + 19) |= 0x20u;
            ++*(_WORD *)(v17 + 16);
          }
          if ( (*(_DWORD *)(v17 + 8) & 0x400) == 0 )
            v18 = MiCaptureDirtyBitToPfn(v17);
          v21 = *(_DWORD *)v6;
          v22 = 0;
          if ( (*(_DWORD *)v6 & 0x80) != 0 && (v21 & 0x200) != 0 )
            v22 = 2;
          if ( (v21 & 0x10) == 0 )
            v22 |= 1u;
          if ( v22 )
          {
            MI_WRITE_VALID_PTE_VOLATILE((unsigned int *)v6, v22);
            MiInsertTbFlushEntry(&v58, v6 << 10, 1);
          }
          __dmb(0xBu);
          v23 = (unsigned int *)(v17 + 12);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 & 0x7FFFFFFF, v23) );
          if ( v18 )
            MiReleasePageFileInfo(MiSystemPartition, v18, 1);
          v6 += 4;
LABEL_47:
          v5 = a4;
LABEL_48:
          v7 = v51;
          continue;
        }
      }
      else
      {
        v31 = 1;
      }
      if ( MiTradeActivePage(v17, v28 + 24 * v12, v6 << 10, 2) == 1 )
      {
        *(_DWORD *)(v17 + 8) = 128;
        MiReleaseFreshPage(v17);
        v17 = v28 + 24 * v12;
        v12 = -1;
      }
      goto LABEL_72;
    }
    MiFlushTbList(&v58);
    MiUnlockWorkingSetExclusive(v48, v49);
    if ( MmAccessFault(0, v6 << 10, 0, 0) < 0 )
      KeBugCheckEx(26, 12288, v6 << 10);
    v25 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v48);
    }
    else
    {
      do
        v26 = __ldrex(v57);
      while ( __strex(v26 | 0x80, v57) );
      __dmb(0xBu);
      if ( v26 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v48);
      while ( 1 )
      {
        v27 = *v48;
        if ( (*v48 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v27 & 0x40000000) == 0 )
        {
          do
            v40 = __ldrex(v48);
          while ( v40 == v27 && __strex(v27 | 0x40000000, v48) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v5 = a4;
    }
    v49 = v25;
  }
  while ( v6 <= v11 && v7 == 1 );
  if ( v49 != 17 )
  {
    MiFlushTbList(&v58);
    MiUnlockWorkingSetExclusive(v48, v49);
  }
  if ( v12 != -1 )
    MiReleaseFreshPage(MmPfnDatabase + 24 * v12);
  if ( v7 )
    return 0;
  MiUnlockCodePage(a2, v6 - 8);
  return -1073741670;
}
