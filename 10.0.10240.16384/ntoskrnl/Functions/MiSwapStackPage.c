// MiSwapStackPage 
 
int __fastcall MiSwapStackPage(int a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v6; // r4
  int v8; // r1
  int v9; // r0
  int v10; // r9
  int v11; // r4
  int v12; // r10
  unsigned int v13; // r1
  int v14; // r4
  unsigned __int8 *v15; // r1
  unsigned int v16; // r2
  int v17; // r9
  unsigned int v18; // r4
  unsigned int *v19; // r0
  unsigned int v20; // r1
  int v21; // r0
  int v22; // r0
  unsigned __int8 *v23; // r1
  unsigned int v24; // r2
  unsigned int *v25; // r4
  unsigned int v26; // r1
  int *v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r0
  int v30; // r3
  int v31; // r9
  unsigned int v32; // r1
  int v33; // r5
  int v34; // r4
  unsigned int v35; // r0
  int v36; // r3
  unsigned int *v37; // r2
  unsigned int v38; // r0
  int v39; // r0
  unsigned int *v40; // r2
  unsigned int v41; // r0
  int v42; // r0
  unsigned int *v43; // r2
  unsigned int v44; // r0
  int v45; // r0
  unsigned int v46; // r0
  int v47; // r0
  int v48; // r5
  unsigned __int8 *v49; // r1
  unsigned int v50; // r2
  int v51; // r3
  int v52; // r3
  unsigned int *v53; // r2
  unsigned int v54; // r0
  int v55; // r10
  unsigned int v56; // r3
  unsigned int v57; // r2
  unsigned int *v58; // r2
  unsigned int v59; // r0
  int v60; // [sp+8h] [bp-60h]
  int v61; // [sp+Ch] [bp-5Ch]
  int v62; // [sp+10h] [bp-58h]
  int v63; // [sp+14h] [bp-54h] BYREF
  unsigned int v64; // [sp+18h] [bp-50h]
  unsigned int v65; // [sp+1Ch] [bp-4Ch]
  int v66; // [sp+20h] [bp-48h]
  int v67; // [sp+24h] [bp-44h]
  int *v68; // [sp+28h] [bp-40h]
  int v69[4]; // [sp+30h] [bp-38h] BYREF
  int v70; // [sp+40h] [bp-28h]
  int v71; // [sp+44h] [bp-24h]
  int v72; // [sp+48h] [bp-20h]

  v68 = (int *)a4;
  v63 = a2;
  v64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( !byte_634C8C )
    return 0;
  v66 = (a1 - MmPfnDatabase) / 24;
  if ( a3 != -1 )
    return sub_513E68();
  v6 = (a1 - MmPfnDatabase) / 24;
  v8 = (MiPageToNode() << byte_6337F5) | dword_633814 & v6;
  v9 = MiGetPage(MiSystemPartition, v8, 0);
  v62 = v9;
  if ( v9 == -1 )
    return 0;
  v10 = MmPfnDatabase;
  v11 = 3 * v9;
  v60 = MmPfnDatabase;
  v61 = 3 * v9;
  MiFinalizePageAttribute(MmPfnDatabase + 24 * v9, 1, 0);
  v72 = 0;
  v12 = KfRaiseIrql(2);
  v67 = 0x80000000;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634F00);
  }
  else
  {
    do
      v13 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
    while ( __strex(v13 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
    __dmb(0xBu);
    if ( v13 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire(&dword_634F00);
    while ( 1 )
    {
      v14 = dword_634F00;
      if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_634F00 & 0x40000000) == 0 )
      {
        do
          v35 = __ldrex((unsigned int *)&dword_634F00);
        while ( v35 == v14 && __strex(v14 | 0x40000000, (unsigned int *)&dword_634F00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    v11 = v61;
  }
  v15 = (unsigned __int8 *)(a1 + 15);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 | 0x80, v15) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v16 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v36 = *(_DWORD *)(a1 + 12);
      __dmb(0xBu);
    }
    while ( (v36 & 0x80000000) != 0 );
    do
      v16 = __ldrex(v15);
    while ( __strex(v16 | 0x80, v15) );
  }
  v71 = *(_DWORD *)(a1 + 4) << 10;
  if ( !MiCanStealKernelStack(a1, 1) )
  {
    __dmb(0xBu);
    v37 = (unsigned int *)(a1 + 12);
    do
      v38 = __ldrex(v37);
    while ( __strex(v38 & 0x7FFFFFFF, v37) );
    MiUnlockWorkingSetExclusive(&dword_634F00, v12);
    v39 = v10 + 8 * v11;
    goto LABEL_109;
  }
  if ( (MiFlags & 0x800) != 0 || MiSwapStackPageNoDpc(v63, a1, v10 + 8 * v11) != 1 )
  {
    v17 = *(_DWORD *)a1;
    if ( *(_DWORD *)a1 == -5 || (v17 & 1) == 0 )
    {
      __dmb(0xBu);
      v58 = (unsigned int *)(a1 + 12);
      do
        v59 = __ldrex(v58);
      while ( __strex(v59 & 0x7FFFFFFF, v58) );
      MiUnlockWorkingSetExclusive(&dword_634F00, v12);
      v39 = v60 + 8 * v11;
    }
    else
    {
      v18 = MiGetPteFromCopyList(v63, v62, -1);
      if ( v17 != -3 && v17 != (v64 | 1) )
      {
        v65 = v17 & 0xFFFFFFFE;
        if ( KeTryToFreezeThreadStack(v17 & 0xFFFFFFFE, &v63) == 1 )
        {
          MiCopyKstack(v60 + 8 * v61, a1, v18);
          MiSwitchKstackPages(v60 + 8 * v61, a1);
          *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
          *(_BYTE *)(a1 + 18) &= 0xC7u;
          *(_BYTE *)(a1 + 19) &= 0xDFu;
          *(_DWORD *)(a1 + 12) &= 0xC0000000;
          __dmb(0xBu);
          v28 = (unsigned int *)(a1 + 12);
          do
            v29 = __ldrex(v28);
          while ( __strex(v29 & 0x7FFFFFFF, v28) );
          KeFlushSingleTb(v71, 1);
          v30 = v63;
          if ( v63 )
          {
            __dmb(0xBu);
            *(_DWORD *)(v30 + 24) = 0;
          }
          __dmb(0xBu);
          *(_DWORD *)(v65 + 44) = 0;
          MiUnlockWorkingSetExclusive(&dword_634F00, v12);
          if ( v18 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)v18 = 0;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)v18 = 0;
            if ( v18 >= 0xC0300000 && v18 <= 0xC0300FFF )
            {
              v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v42, v42 + 4 * (v18 & 0xFFF), 0);
            }
          }
          *a5 = 1;
          goto LABEL_34;
        }
LABEL_21:
        __dmb(0xBu);
        v19 = (unsigned int *)(a1 + 12);
        do
          v20 = __ldrex(v19);
        while ( __strex(v20 & 0x7FFFFFFF, v19) );
        MiUnlockWorkingSetExclusive(&dword_634F00, v12);
        v69[2] = v18;
        v69[3] = v64 | 1;
        v69[0] = v66;
        v69[1] = v62;
        v70 = 0;
        if ( v17 == -3 || v17 == (v64 | 1) )
        {
          v21 = KeExpandKernelStackAndCalloutInternal(MiJumpStack, v69, 12288, 5, 0);
          if ( v21 < 0 )
          {
            v70 = v21;
            goto LABEL_27;
          }
        }
        else
        {
          KeGenericCallDpc(MiDoStackCopy, v69);
        }
        v21 = v70;
LABEL_27:
        if ( v21 >= 0 )
        {
          *a5 = 0;
          v22 = KfRaiseIrql(2);
          v23 = (unsigned __int8 *)(a1 + 15);
          do
            v24 = __ldrex(v23);
          while ( __strex(v24 | 0x80, v23) );
          __dmb(0xBu);
          v25 = (unsigned int *)(a1 + 12);
          if ( v24 >> 7 )
          {
            v55 = v67;
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v56 = *v25;
                __dmb(0xBu);
              }
              while ( (v56 & v55) != 0 );
              do
                v57 = __ldrex(v23);
              while ( __strex(v57 | 0x80, v23) );
              __dmb(0xBu);
            }
            while ( v57 >> 7 );
          }
          *(_DWORD *)(a1 + 12) &= 0xC0000000;
          __dmb(0xBu);
          do
            v26 = __ldrex(v25);
          while ( __strex(v26 & 0x7FFFFFFF, v25) );
          KfLowerIrql(v22);
          goto LABEL_34;
        }
        v31 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_634F00);
        }
        else
        {
          do
            v32 = __ldrex((unsigned __int8 *)&dword_634F00 + 3);
          while ( __strex(v32 | 0x80, (unsigned __int8 *)&dword_634F00 + 3) );
          __dmb(0xBu);
          if ( v32 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(&dword_634F00);
          while ( 1 )
          {
            v33 = dword_634F00;
            if ( (dword_634F00 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (dword_634F00 & 0x40000000) == 0 )
            {
              do
                v46 = __ldrex((unsigned int *)&dword_634F00);
              while ( v46 == v33 && __strex(v33 | 0x40000000, (unsigned int *)&dword_634F00) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        if ( v18 + 0x40000000 > 0x3FFFFF )
        {
          *(_DWORD *)v18 = 0;
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)v18 = 0;
          if ( v18 >= 0xC0300000 && v18 <= 0xC0300FFF )
          {
            v47 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
            MiArmWriteConvertedHardwarePde(v47, v47 + 4 * (v18 & 0xFFF), 0);
          }
        }
        MiUnlockWorkingSetExclusive(&dword_634F00, v31);
        MiReleaseFreshPage(v60 + 8 * v61);
        v34 = v72;
        if ( v72 )
        {
          v48 = KfRaiseIrql(2);
          v49 = (unsigned __int8 *)(v34 + 15);
          do
            v50 = __ldrex(v49);
          while ( __strex(v50 | 0x80, v49) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v50 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v51 = *(_DWORD *)(v34 + 12);
              __dmb(0xBu);
            }
            while ( (v51 & 0x80000000) != 0 );
            do
              v50 = __ldrex(v49);
            while ( __strex(v50 | 0x80, v49) );
          }
          MiRemoveLockedPageChargeAndDecRef(v72);
          v52 = v72;
          __dmb(0xBu);
          v53 = (unsigned int *)(v52 + 12);
          do
            v54 = __ldrex(v53);
          while ( __strex(v54 & 0x7FFFFFFF, v53) );
          KfLowerIrql(v48);
        }
        return 0;
      }
      if ( MiAddLockedPageCharge(a1, 0) )
      {
        v72 = a1;
        goto LABEL_21;
      }
      __dmb(0xBu);
      v43 = (unsigned int *)(a1 + 12);
      do
        v44 = __ldrex(v43);
      while ( __strex(v44 & 0x7FFFFFFF, v43) );
      if ( v18 + 0x40000000 > 0x3FFFFF )
      {
        *(_DWORD *)v18 = 0;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v18 = 0;
        if ( v18 + 1070596096 <= 0xFFF )
        {
          v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v45, v45 + 4 * (v18 & 0xFFF), 0);
        }
      }
      MiUnlockWorkingSetExclusive(&dword_634F00, v12);
      v39 = v60 + 8 * v61;
    }
LABEL_109:
    MiReleaseFreshPage(v39);
    return 0;
  }
  *(_DWORD *)(a1 + 20) &= 0xF7FFFFFF;
  *(_BYTE *)(a1 + 18) &= 0xC7u;
  *(_BYTE *)(a1 + 19) &= 0xDFu;
  *(_DWORD *)(a1 + 12) &= 0xC0000000;
  __dmb(0xBu);
  v40 = (unsigned int *)(a1 + 12);
  do
    v41 = __ldrex(v40);
  while ( __strex(v41 & 0x7FFFFFFF, v40) );
  MiUnlockWorkingSetExclusive(&dword_634F00, v12);
  *a5 = 1;
LABEL_34:
  v27 = v68;
  *(_WORD *)(a1 + 16) = 0;
  if ( v27 )
    *v27 = v62;
  return 1;
}
