// MiRemoveMappedPtes 
 
int __fastcall MiRemoveMappedPtes(int a1, unsigned int *a2)
{
  unsigned int *v2; // r4
  int v3; // r6
  _DWORD *v4; // r10
  int v5; // r8
  __int64 v6; // r0
  int v7; // r7
  int v8; // r2
  unsigned int v9; // r7
  unsigned int v10; // r5
  int v11; // r3
  int result; // r0
  unsigned __int8 *v13; // r3
  unsigned int v14; // r1
  unsigned int v15; // r0
  unsigned int v16; // r3
  unsigned int v17; // r4
  unsigned int *v18; // r4
  unsigned int v19; // r9
  int v20; // r8
  unsigned int v21; // r1
  int v22; // lr
  int v23; // r9
  unsigned int v24; // r10
  unsigned __int8 *v25; // r3
  unsigned int v26; // r1
  int v27; // r4
  int v28; // r2
  int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r0
  unsigned __int8 *v32; // r2
  unsigned int v33; // r1
  int v34; // r2
  unsigned int *v35; // r2
  unsigned int v36; // r4
  unsigned int *v37; // r4
  int v38; // r5
  unsigned __int8 *v39; // r3
  unsigned int v40; // r1
  unsigned int v41; // r0
  int v42; // r3
  unsigned int v43; // r2
  int v44; // r8
  int v45; // r0
  unsigned int v46; // r4
  int v47; // r1
  unsigned int v48; // r4
  int v49; // r4
  unsigned int *v50; // lr
  unsigned __int8 *v51; // r3
  unsigned int v52; // r1
  unsigned int v53; // r0
  int v54; // lr
  unsigned int v55; // r2
  unsigned int v56; // r0
  unsigned int *v57; // r2
  unsigned int v58; // r0
  unsigned int v59; // r1
  unsigned int v60; // r0
  int v61; // r0
  unsigned __int8 *v62; // r1
  int v63; // r3
  unsigned int v64; // r2
  unsigned __int8 *v65; // r1
  int v66; // r3
  unsigned int v67; // r2
  int v68; // r0
  unsigned int v69; // r1
  int v70; // r0
  int v71; // r0
  unsigned int v72; // r1
  unsigned int v74; // [sp+10h] [bp-E0h]
  char v75[4]; // [sp+14h] [bp-DCh] BYREF
  int v76; // [sp+18h] [bp-D8h]
  int v77; // [sp+1Ch] [bp-D4h]
  int v78; // [sp+20h] [bp-D0h]
  int v79; // [sp+24h] [bp-CCh]
  int v80; // [sp+28h] [bp-C8h]
  int v81; // [sp+2Ch] [bp-C4h]
  _DWORD *v82; // [sp+30h] [bp-C0h]
  int v83; // [sp+38h] [bp-B8h] BYREF
  char v84; // [sp+3Ch] [bp-B4h]
  char v85; // [sp+3Dh] [bp-B3h]
  int v86; // [sp+40h] [bp-B0h]
  int v87; // [sp+44h] [bp-ACh]
  int v88; // [sp+48h] [bp-A8h]
  int v89; // [sp+4Ch] [bp-A4h]

  v2 = a2;
  v3 = *(_DWORD *)(a1 + 24) >> 12;
  v4 = (_DWORD *)(*(_DWORD *)(a1 + 32) & 0xFFFFFFF8);
  v77 = 0;
  v5 = 0;
  v74 = 0;
  v81 = a1;
  v82 = v4;
  v6 = MiTbFlushType(a2);
  v84 = 0;
  v86 = 33;
  v7 = *(_DWORD *)(HIDWORD(v6) + 48);
  v83 = v6;
  v87 = 0;
  v88 = 0;
  v85 = 0;
  v89 = 0;
  v8 = v4[8];
  v9 = v7 & 0xFFFFF000;
  v80 = 4194300;
  v10 = ((v9 >> 10) & 0x3FFFFC) - 0x40000000;
  if ( !v8 || (v4[7] & 0x420) != 0 )
  {
    v5 = -1;
    v74 = -1;
  }
  if ( dword_634484 )
    v11 = v2[23];
  else
    v11 = 0;
  v78 = v11;
  v79 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_53A670();
  v13 = (unsigned __int8 *)v2 + 3;
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 | 0x80, v13) );
  __dmb(0xBu);
  if ( v14 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v2);
  while ( 1 )
  {
    v15 = *v2;
    if ( (*v2 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v15 & 0x40000000) == 0 )
    {
      do
        v59 = __ldrex(v2);
      while ( v59 == v15 && __strex(v15 | 0x40000000, v2) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  if ( v3 )
  {
    v16 = -1073741824;
    v76 = -1073741824;
    while ( 1 )
    {
      v17 = *(_DWORD *)v10;
      if ( (*(_DWORD *)v10 & 2) != 0 )
      {
        v19 = *(_DWORD *)(MmPfnDatabase + 24 * (v17 >> 12));
        v20 = MmPfnDatabase + 24 * (v17 >> 12);
        if ( v78 )
        {
          v60 = MiLocateWsle(v9, (int)a2, *(_DWORD *)(MmPfnDatabase + 24 * (v17 >> 12)));
          v19 = v60;
          if ( (*(_DWORD *)v10 & 0x10) != 0
            && (*(_DWORD *)(*(_DWORD *)(v78 + 36) * v60 + *(_DWORD *)(v78 + 252)) & 0xE00) != 3584 )
          {
            MiLogPageAccess(a2, v10);
          }
        }
        MiTerminateWsle(v9, a2, v19);
        if ( v74 != -1 && (*(_DWORD *)(v20 + 20) & 0x8000000) != 0 )
        {
          v54 = *(_DWORD *)(v20 + 8);
          if ( (v54 & 0x400) != 0 )
          {
            if ( !v74
              || (v21 = *(_DWORD *)(v74 + 4), v55 = *(_DWORD *)(v20 + 4) | 0x80000000, v55 < v21)
              || v55 >= v21 + 4 * *(_DWORD *)(v74 + 28) )
            {
              if ( v74 != (*(_DWORD *)(v20 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v20 + 8) & 0x3FC))) )
              {
                if ( v74 )
                  MiRemoveViewsFromSectionWithPfn(v74, v21, *(_DWORD *)(v74 + 28), 0);
                v74 = v54 & 0xFFFFF800 | (2 * (v54 & 0x3FC));
              }
            }
          }
        }
        MiInsertTbFlushEntry(&v83, v9, 1);
        v22 = v76;
        v23 = MmPfnDatabase + 24 * (*(_DWORD *)((v80 & (v10 >> 10)) + v76) >> 12);
        if ( v10 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v10 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v10 = 0;
          if ( v10 >= 0xC0300000 && v10 <= 0xC0300FFF )
          {
            v61 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v61, v61 + 4 * (v10 & 0xFFF), 0);
            v22 = v76;
          }
        }
        v24 = 0;
        v25 = (unsigned __int8 *)(v20 + 15);
        do
          v26 = __ldrex(v25);
        while ( __strex(v26 | 0x80, v25) );
        __dmb(0xBu);
        if ( v26 >> 7 )
        {
          v62 = (unsigned __int8 *)(v20 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v63 = *(_DWORD *)(v20 + 12);
              __dmb(0xBu);
            }
            while ( (v63 & 0x80000000) != 0 );
            do
              v64 = __ldrex(v62);
            while ( __strex(v64 | 0x80, v62) );
            __dmb(0xBu);
          }
          while ( v64 >> 7 );
        }
        if ( (v17 & 0x200) == 0 )
        {
          v56 = MiCaptureDirtyBitToPfn(v20);
          v22 = v76;
          v24 = v56;
        }
        if ( (*(_DWORD *)(v20 + 20) & 0x8000000) != 0 )
        {
          v27 = 1;
        }
        else
        {
          v27 = 0;
          *(_DWORD *)(v20 + 12) |= 0x40000000u;
        }
        if ( (*(_BYTE *)(v20 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v20 - MmPfnDatabase) / 24);
        v28 = *(_DWORD *)(v20 + 12);
        *(_DWORD *)(v20 + 12) = v28 & 0xC0000000 | ((v28 & ~v22) - 1) & 0x3FFFFFFF;
        if ( (v28 & ~v22) == 1 )
        {
          v29 = MiPfnShareCountIsZero(v20, 0);
          v22 = v76;
          if ( v29 == 3 && !v27 )
            ++v77;
        }
        __dmb(0xBu);
        v30 = (unsigned int *)(v20 + 12);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 & 0x7FFFFFFF, v30) );
        v32 = (unsigned __int8 *)(v23 + 15);
        do
          v33 = __ldrex(v32);
        while ( __strex(v33 | 0x80, v32) );
        __dmb(0xBu);
        if ( v33 >> 7 )
        {
          v65 = (unsigned __int8 *)(v23 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v66 = *(_DWORD *)(v23 + 12);
              __dmb(0xBu);
            }
            while ( (v66 & 0x80000000) != 0 );
            do
              v67 = __ldrex(v65);
            while ( __strex(v67 | 0x80, v65) );
            __dmb(0xBu);
          }
          while ( v67 >> 7 );
        }
        if ( (*(_BYTE *)(v23 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v23 - MmPfnDatabase) / 24);
        v34 = *(_DWORD *)(v23 + 12);
        *(_DWORD *)(v23 + 12) = v34 & 0xC0000000 | ((v34 & ~v22) - 1) & 0x3FFFFFFF;
        if ( (v34 & ~v22) == 1 )
          MiPfnShareCountIsZero(v23, 0);
        __dmb(0xBu);
        v35 = (unsigned int *)(v23 + 12);
        do
        {
          v36 = __ldrex(v35);
          v16 = __strex(v36 & 0x7FFFFFFF, v35);
        }
        while ( v16 );
        if ( v24 )
          MiReleasePageFileInfo((int)MiSystemPartition, v24, 1, 0);
        goto LABEL_19;
      }
      if ( (v17 & 0x400) != 0 )
      {
        if ( v10 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v10 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v10 = 0;
          if ( v10 >= 0xC0300000 && v10 <= 0xC0300FFF )
          {
            v68 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v68, v68 + 4 * (v10 & 0xFFF), 0);
          }
        }
        v16 = v17 & 0x1FC | (v17 >> 2) & 0x3FFFFE00;
        v18 = (unsigned int *)(v16 - 0x40000000);
        if ( v5 != -1 )
        {
          if ( !v5
            || (v43 = *(_DWORD *)(v5 + 4), (unsigned int)v18 < v43)
            || (v16 = v43 + 4 * *(_DWORD *)(v5 + 28), (unsigned int)v18 >= v16) )
          {
            MiUnlockWorkingSetExclusive(a2, v79);
            while ( 1 )
            {
              v44 = MiLockProtoPoolPage(v18, v75);
              if ( v44 )
                break;
              MmAccessFault(1, (unsigned int)v18, 0, 0);
            }
            v45 = MiLockLeafPage(v18, 0);
            if ( v45 )
            {
              v46 = *(_DWORD *)(v45 + 8);
              __dmb(0xBu);
              v57 = (unsigned int *)(v45 + 12);
              do
                v58 = __ldrex(v57);
              while ( __strex(v58 & 0x7FFFFFFF, v57) );
            }
            else
            {
              v46 = *v18;
            }
            MiUnlockProtoPoolPage(v44, (unsigned __int8)v75[0]);
            if ( (v46 & 0x400) != 0 )
            {
              v48 = v46 & 0xFFFFF800 | (2 * (v46 & 0x3FC));
              if ( v74 != v48 )
              {
                if ( v74 )
                  MiRemoveViewsFromSectionWithPfn(v74, v47, *(_DWORD *)(v74 + 28), 0);
                v74 = v48;
              }
            }
            v49 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a2);
            }
            else
            {
              v50 = a2;
              v51 = (unsigned __int8 *)a2 + 3;
              do
                v52 = __ldrex(v51);
              while ( __strex(v52 | 0x80, v51) );
              __dmb(0xBu);
              if ( v52 >> 7 )
              {
                ExpWaitForSpinLockExclusiveAndAcquire(a2);
                v50 = a2;
              }
              while ( 1 )
              {
                v53 = *v50;
                v16 = *v50 & 0xBFFFFFFF;
                if ( v16 == 0x80000000 )
                  break;
                if ( (v53 & 0x40000000) == 0 )
                {
                  do
                    v69 = __ldrex(v50);
                  while ( v69 == v53 && __strex(v53 | 0x40000000, v50) );
                  __dmb(0xBu);
                }
                __dmb(0xAu);
                __yield();
              }
            }
            v79 = v49;
          }
        }
        goto LABEL_19;
      }
      if ( (v17 & 0x800) == 0 )
        break;
      v70 = MiDeleteTransitionPte((_DWORD *)v10, 1, -1070596096);
      if ( v70 != 1 )
      {
        if ( v70 == 3 )
          ++v77;
        if ( v10 + 0x40000000 <= 0x3FFFFF )
        {
          __dmb(0xBu);
          *(_DWORD *)v10 = 0;
          v16 = v10 + 1070596096;
          if ( v10 + 1070596096 <= 0xFFF )
            goto LABEL_137;
          goto LABEL_19;
        }
LABEL_141:
        v16 = 0;
        *(_DWORD *)v10 = 0;
        goto LABEL_19;
      }
LABEL_20:
      if ( !v3 )
      {
        v4 = v82;
        v2 = a2;
        goto LABEL_52;
      }
      v5 = v74;
    }
    if ( !v17 )
      goto LABEL_19;
    MiReleasePageFileSpace((int)MiSystemPartition, *(_DWORD *)v10, 1, v16);
    if ( v10 + 0x40000000 <= 0x3FFFFF )
    {
      __dmb(0xBu);
      *(_DWORD *)v10 = 0;
      v16 = v10 + 1070596096;
      if ( v10 + 1070596096 <= 0xFFF )
      {
LABEL_137:
        v71 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v71, v71 + 4 * (v10 & 0xFFF), 0);
      }
LABEL_19:
      v10 += 4;
      --v3;
      v9 += 4096;
      goto LABEL_20;
    }
    goto LABEL_141;
  }
LABEL_52:
  MiUnlockWorkingSetExclusive(v2, v79);
  MiFlushTbList(&v83);
  v37 = v4 + 9;
  v38 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v4 + 9);
  }
  else
  {
    v39 = (unsigned __int8 *)v4 + 39;
    do
      v40 = __ldrex(v39);
    while ( __strex(v40 | 0x80, v39) );
    __dmb(0xBu);
    if ( v40 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(v4 + 9);
    while ( 1 )
    {
      v41 = *v37;
      if ( (*v37 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (v41 & 0x40000000) == 0 )
      {
        do
          v72 = __ldrex(v37);
        while ( v72 == v41 && __strex(v41 | 0x40000000, v37) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  if ( v74 != -1 && v74 )
    MiRemoveViewsFromSection(v74, v74, *(_DWORD *)(v74 + 28), 0);
  --v4[6];
  --v4[5];
  result = MiCheckControlArea(v4, v38);
  v42 = *(_DWORD *)(v81 + 28);
  if ( v42 != v77 )
    result = MiReturnCommit(MiSystemPartition, v42 - v77);
  return result;
}
