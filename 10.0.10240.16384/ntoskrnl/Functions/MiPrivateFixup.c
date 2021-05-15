// MiPrivateFixup 
 
int __fastcall MiPrivateFixup(int a1, int a2, int a3, unsigned int a4, int a5, int a6, unsigned __int8 a7)
{
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r2
  unsigned int v11; // r6
  int v12; // r4
  int v13; // r5
  int v14; // r9
  int v15; // r4
  int v16; // r0
  int v17; // r3
  int v18; // r3
  unsigned __int64 *v19; // r3
  unsigned __int64 v20; // kr00_8
  int v21; // r3
  int v22; // r4
  int v23; // r0
  int v24; // r2
  int v25; // r4
  unsigned int v26; // lr
  int v27; // r3
  int v28; // r4
  int v29; // r7
  int v30; // r0
  __int16 v31; // r3
  unsigned __int8 *v32; // r3
  unsigned int v33; // r1
  unsigned int v34; // r0
  int v35; // r4
  int v36; // r8
  unsigned __int8 *v37; // r1
  unsigned int v38; // r2
  char v39; // r2
  int v40; // r3
  char v41; // r3
  unsigned int *v42; // r2
  unsigned int v43; // r4
  unsigned int *v45; // r2
  unsigned int v46; // r4
  unsigned int *v47; // r2
  unsigned int v48; // r0
  int v49; // r0
  unsigned __int8 *v50; // r3
  unsigned int v51; // r1
  unsigned int v52; // r0
  unsigned int v53; // r1
  int v54; // r6
  unsigned __int8 *v55; // r1
  unsigned int v56; // r2
  int v57; // r2
  int v58; // r3
  int v59; // r0
  unsigned int v60; // r1
  int v61; // r3
  int v62; // [sp+8h] [bp-50h] BYREF
  int *v63; // [sp+Ch] [bp-4Ch]
  int v64; // [sp+10h] [bp-48h]
  int v65; // [sp+14h] [bp-44h]
  int v66; // [sp+18h] [bp-40h]
  int v67; // [sp+1Ch] [bp-3Ch] BYREF
  int v68; // [sp+20h] [bp-38h]
  int v69; // [sp+24h] [bp-34h]
  int v70; // [sp+28h] [bp-30h]
  int v71; // [sp+2Ch] [bp-2Ch] BYREF
  int v72; // [sp+30h] [bp-28h]
  int v73; // [sp+34h] [bp-24h]

  v64 = a4;
  v69 = a3;
  v73 = a2;
  v66 = a1;
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(_DWORD *)(v8 + 116);
  v65 = v8;
  LOBYTE(v8) = *(_BYTE *)(a6 + 112);
  v71 = v9;
  if ( (v8 & 7) != 0 || !*(_DWORD *)(v9 + 264) )
  {
    v10 = (*(_DWORD *)(a3 + 8) >> 5) & 0x1F;
    v72 = v10;
    if ( a4 >= dword_63389C && (MiFlags & 0x30000) != 0 && (MiFlags & 0x100000) != 0 && (v10 & 2) != 0 )
    {
      v11 = 0;
    }
    else
    {
      v11 = MiReservePtes(&dword_634D58);
      if ( !v11 )
        return -1073741670;
    }
    v63 = (int *)(((a4 >> 10) & 0x3FFFFC) - 0x40000000);
    v67 = *v63;
    v68 = (v69 - MmPfnDatabase) / 24;
    MiObtainFaultCharges(MiSystemPartition, 1, 2);
    v70 = 0x80000000;
    if ( v11 )
    {
      v12 = MiGetPage(MiSystemPartition, (*(_DWORD *)(v69 + 20) >> 28 << byte_6337F5) | dword_633814 & v68, 0);
      v62 = v12;
      if ( v12 != -1 )
      {
LABEL_7:
        v13 = MmPfnDatabase + 24 * v12;
        v14 = MiGetInPageSupportBlock(2);
        if ( v14 )
        {
          v15 = v65;
          v67 = 0;
          v67 = MiGetEffectivePagePriorityThread(v65) & 7 | 0x48;
          v16 = v64;
          *(_BYTE *)(v14 + 113) |= 0x10u;
          *(_DWORD *)(v14 + 48) = 0;
          *(_DWORD *)(v14 + 52) = 0;
          v17 = v67;
          *(_DWORD *)(v14 + 140) = v13;
          MiInitializeReadInProgressPfn(v16, &v62, 1, v63, v14 + 16, v17);
          if ( (*(_BYTE *)(a6 + 112) & 7) == 0 )
          {
            v45 = (unsigned int *)(v71 + 276);
            do
              v46 = __ldrex(v45);
            while ( __strex(v46 + 1, v45) );
            v15 = v65;
          }
          v71 = *v63;
          v18 = v66;
          *(_DWORD *)(v14 + 120) = v66;
          v19 = (unsigned __int64 *)(v18 + 64);
          do
            v20 = __ldrexd(v19);
          while ( __strexd(v20 + 1, v19) );
          MiUnlockWorkingSetExclusive(a6, 1);
          --*(_WORD *)(v15 + 310);
          KfLowerIrql(a7);
          if ( (v72 & 2) != 0 )
            v21 = 17;
          else
            v21 = 9;
          MiCopyPage(v62, v68, 0, v21);
          if ( v11 )
          {
            v22 = MiMakeProtectionPfnCompatible(4, v13);
            v23 = MiDetermineUserGlobalPteMask(v11);
            v24 = MmProtectToPteMask[v22];
            v25 = v62;
            v26 = (v24 & 0x1ED | (v62 << 12) | v23) & 0xFFFFF1FF | 0x12;
            if ( v11 + 0x40000000 > 0x3FFFFF )
            {
              *(_DWORD *)v11 = v26;
            }
            else
            {
              v27 = *(_DWORD *)v11;
              v28 = 0;
              __dmb(0xBu);
              if ( (v27 & 2) == 0 )
                v28 = 1;
              *(_DWORD *)v11 = v26;
              if ( v11 >= 0xC0300000 && v11 <= 0xC0300FFF )
              {
                v59 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v59, v59 + 4 * (v11 & 0xFFF), v26);
              }
              if ( v28 == 1 )
              {
                __dsb(0xFu);
                __isb(0xFu);
              }
              v25 = v62;
            }
            if ( (*(_DWORD *)(v69 + 4) & 0x80000000) != 0 )
            {
              MiGetSessionIdForVa(v64);
              MiRelocateImagePfn(v66, v11 << 10, v73, v25, a5);
            }
            MiReleasePtes(&dword_634D58, v11, 1);
            v15 = v65;
          }
          MiDereferenceControlAreaProbe(v66);
          v29 = 0;
          v30 = KfRaiseIrql(1);
          v31 = *(_WORD *)(v15 + 310) + 1;
          *(_WORD *)(v15 + 310) = v31;
          if ( !v31 && *(_DWORD *)(v15 + 100) != v15 + 100 )
            KiCheckForKernelApcDelivery(v30);
          KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a6);
          }
          else
          {
            v32 = (unsigned __int8 *)(a6 + 3);
            do
              v33 = __ldrex(v32);
            while ( __strex(v33 | 0x80, v32) );
            __dmb(0xBu);
            if ( v33 >> 7 )
              ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a6);
            while ( 1 )
            {
              v34 = *(_DWORD *)a6;
              if ( (*(_DWORD *)a6 & 0xBFFFFFFF) == 0x80000000 )
                break;
              if ( (v34 & 0x40000000) == 0 )
              {
                do
                  v60 = __ldrex((unsigned int *)a6);
                while ( v60 == v34 && __strex(v34 | 0x40000000, (unsigned int *)a6) );
                __dmb(0xBu);
              }
              __dmb(0xAu);
              __yield();
            }
          }
          v35 = MiIsFaultPteIntact(v64, v63, &v71);
          v36 = KfRaiseIrql(2);
          v37 = (unsigned __int8 *)(v13 + 15);
          do
            v38 = __ldrex(v37);
          while ( __strex(v38 | 0x80, v37) );
          while ( 1 )
          {
            __dmb(0xBu);
            if ( !(v38 >> 7) )
              break;
            do
            {
              __dmb(0xAu);
              __yield();
              v61 = *(_DWORD *)(v13 + 12);
              __dmb(0xBu);
            }
            while ( (v61 & 0x80000000) != 0 );
            do
              v38 = __ldrex(v37);
            while ( __strex(v38 | 0x80, v37) );
          }
          v39 = *(_BYTE *)(v13 + 18) & 0xDF;
          v40 = *(_DWORD *)(v13 + 12);
          *(_BYTE *)(v13 + 18) = v39;
          if ( (v40 & 0x40000000) == 0 )
          {
            *(_BYTE *)(v13 + 18) = v39 | 0x10;
            *(_DWORD *)v13 = 0;
          }
          if ( v35 == 1 )
          {
            MiAddLockedPageCharge(v13, 3);
            v41 = *(_BYTE *)(v13 + 18);
            *(_DWORD *)(v13 + 12) = *(_DWORD *)(v13 + 12) & 0xC0000000 | (*(_DWORD *)(v13 + 12) + 1) & 0x3FFFFFFF;
            *(_BYTE *)(v13 + 18) = v41 & 0xF8 | 6;
            if ( !v11 )
              *(_BYTE *)(v13 + 19) |= 8u;
          }
          else
          {
            v29 = -1073740748;
          }
          MiRemoveLockedPageChargeAndDecRef(v13);
          __dmb(0xBu);
          v42 = (unsigned int *)(v13 + 12);
          do
            v43 = __ldrex(v42);
          while ( __strex(v43 & 0x7FFFFFFF, v42) );
          KfLowerIrql(v36);
          *(_BYTE *)(v14 + 113) &= 0xEFu;
          if ( *(int *)(v14 + 100) > 1 )
            KeSetEvent(v14 + 32, 0, 0);
          MiFreeInPageSupportBlock(v14);
          return v29;
        }
        MiReturnFaultCharges(MiSystemPartition, 1, 2);
        if ( v11 )
          MiReleasePtes(&dword_634D58, v11, 1);
        v54 = KfRaiseIrql(2);
        v55 = (unsigned __int8 *)(v13 + 15);
        do
          v56 = __ldrex(v55);
        while ( __strex(v56 | 0x80, v55) );
        while ( 1 )
        {
          __dmb(0xBu);
          if ( !(v56 >> 7) )
            break;
          v57 = v70;
          do
          {
            __dmb(0xAu);
            __yield();
            v58 = *(_DWORD *)(v13 + 12);
            __dmb(0xBu);
          }
          while ( (v58 & v57) != 0 );
          do
            v56 = __ldrex(v55);
          while ( __strex(v56 | 0x80, v55) );
        }
        MiInsertPageInFreeOrZeroedList();
        __dmb(0xBu);
        v47 = (unsigned int *)(v13 + 12);
        do
          v48 = __ldrex(v47);
        while ( __strex(v48 & 0x7FFFFFFF, v47) );
        KfLowerIrql(v54);
        return -1073741670;
      }
      v29 = -1073741670;
    }
    else
    {
      v49 = MiUnlockWorkingSetExclusive(a6, a7);
      v12 = MiAllocateDriverPage(v49);
      v62 = v12;
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a6);
      }
      else
      {
        v50 = (unsigned __int8 *)(a6 + 3);
        do
          v51 = __ldrex(v50);
        while ( __strex(v51 | 0x80, v50) );
        __dmb(0xBu);
        if ( v51 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a6);
        while ( 1 )
        {
          v52 = *(_DWORD *)a6;
          if ( (*(_DWORD *)a6 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v52 & 0x40000000) == 0 )
          {
            do
              v53 = __ldrex((unsigned int *)a6);
            while ( v53 == v52 && __strex(v52 | 0x40000000, (unsigned int *)a6) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( MiIsFaultPteIntact(v64, v63, &v67) )
        goto LABEL_7;
      v29 = -1073740748;
    }
    if ( v12 != -1 )
      MiReleaseFreshPage(MmPfnDatabase + 24 * v12);
    MiReturnFaultCharges(MiSystemPartition, 1, 2);
    if ( v11 )
      MiReleasePtes(&dword_634D58, v11, 1);
    return v29;
  }
  return sub_525180();
}
