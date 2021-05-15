// MiCopyOnWriteEx 
 
int __fastcall MiCopyOnWriteEx(unsigned int a1, unsigned int a2, int a3, unsigned int a4, char a5)
{
  unsigned int v5; // lr
  _DWORD *v8; // r9
  int v9; // r5
  int v11; // r1
  int *v12; // r2
  unsigned int *v13; // r10
  int v14; // r0
  int v15; // r2
  int v16; // lr
  unsigned int v17; // r4
  unsigned int v18; // r6
  unsigned int v19; // r0
  int v20; // r3
  unsigned int v21; // r1
  int v22; // r2
  unsigned int v23; // r2
  int v24; // r3
  __int16 v25; // r3
  int v26; // r4
  __int16 v27; // r2
  unsigned int v28; // r1
  bool v29; // zf
  int v30; // r2
  int v31; // r0
  char v32; // r6
  unsigned int v33; // r9
  unsigned __int8 *v34; // r1
  unsigned int v35; // r2
  int v36; // r3
  unsigned int v37; // r1
  int v38; // r3
  char v39; // r0
  int v40; // r6
  unsigned int *v41; // r2
  unsigned int v42; // r0
  unsigned int *v43; // r1
  unsigned int v44; // r0
  int v45; // r6
  int v46; // r2
  int v47; // r1
  int v48; // r2
  __int16 v49; // r10
  int v50; // r6
  unsigned int v51; // r2
  unsigned int v52; // r3
  int v53; // r4
  int v54; // r4
  unsigned int *v55; // r2
  unsigned int v56; // r0
  unsigned __int8 *v57; // r1
  unsigned int v58; // r2
  int v59; // r2
  unsigned int *v60; // r2
  unsigned int v61; // r0
  int v62; // r5
  int v63; // r0
  int v65; // r0
  int v66; // r3
  unsigned int v67; // r2
  unsigned int v68; // r2
  int v69; // r1
  unsigned int v70; // r3
  int v71; // r6
  int v72; // r3
  unsigned int v73; // r2
  unsigned __int8 *v74; // r3
  unsigned int v75; // r1
  unsigned int v76; // r0
  unsigned int v77; // r1
  unsigned int v78; // r3
  int v79; // r3
  unsigned int v80; // r2
  int v81; // r0
  int v82; // r0
  int v83; // r0
  int v84; // [sp+8h] [bp-120h]
  int v85; // [sp+Ch] [bp-11Ch]
  int v86; // [sp+10h] [bp-118h]
  int v87; // [sp+14h] [bp-114h]
  unsigned int v88; // [sp+18h] [bp-110h]
  _DWORD *v89; // [sp+1Ch] [bp-10Ch] BYREF
  int v90; // [sp+20h] [bp-108h]
  int v91; // [sp+28h] [bp-100h] BYREF
  __int16 v92; // [sp+2Ch] [bp-FCh]
  unsigned __int16 v93; // [sp+2Eh] [bp-FAh]
  unsigned int v94; // [sp+30h] [bp-F8h]
  int v95; // [sp+34h] [bp-F4h]
  unsigned int v96; // [sp+38h] [bp-F0h]
  unsigned int *v97; // [sp+3Ch] [bp-ECh]
  int v98; // [sp+40h] [bp-E8h]
  unsigned int v99; // [sp+44h] [bp-E4h]
  int v100[6]; // [sp+48h] [bp-E0h] BYREF
  int v101[4]; // [sp+60h] [bp-C8h] BYREF
  int v102; // [sp+70h] [bp-B8h] BYREF
  char v103; // [sp+74h] [bp-B4h]
  char v104; // [sp+75h] [bp-B3h]
  int v105; // [sp+78h] [bp-B0h]
  int v106; // [sp+7Ch] [bp-ACh]
  int v107; // [sp+80h] [bp-A8h]
  int v108; // [sp+84h] [bp-A4h]

  v5 = *(_DWORD *)a2;
  v94 = a4;
  v84 = 0;
  v96 = v5 >> 12;
  v91 = a3;
  v8 = 0;
  v9 = MmPfnDatabase + 24 * (v5 >> 12);
  v88 = v5;
  v89 = 0;
  v95 = 0;
  if ( (v5 & 0x100) == 0 )
    v84 = 1;
  v98 = *(_DWORD *)(v9 + 4);
  v11 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v90 = v11;
  if ( a1 >= dword_63389C )
  {
    v66 = *((unsigned __int8 *)&MiState[2423]
          + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v66 == 12 )
      goto LABEL_89;
    if ( v66 == 11 || v66 == 1 )
    {
      v69 = *(_DWORD *)(v11 + 324);
      if ( *(int *)(v9 + 4) >= 0 )
        return sub_539B68();
      v13 = (unsigned int *)(v69 + 3248);
      v16 = *(_DWORD *)(v69 + 3340);
      v15 = 2;
      v87 = 2;
      v85 = v16;
      goto LABEL_13;
    }
  }
  v12 = &MmPfnDatabase;
  if ( PsNtosImageBase && (a1 >= PsNtosImageBase && a1 < PsNtosImageEnd || a1 >= PsHalImageBase && a1 < PsHalImageEnd) )
  {
LABEL_89:
    v15 = 0;
    v87 = 0;
    v13 = (unsigned int *)&dword_634F00;
    v16 = dword_634F5C;
    v85 = dword_634F5C;
    if ( *(int *)(v9 + 4) >= 0 )
      v84 |= 2u;
    goto LABEL_13;
  }
  if ( a1 >= dword_63389C )
  {
    v12 = (int *)*((unsigned __int8 *)&MiState[2423]
                 + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v12 == (int *)9 )
      KeBugCheckEx(26, 13056, a1);
    if ( v12 == (int *)6 || v12 == (int *)14 )
    {
      v13 = (unsigned int *)&dword_634E80;
      v15 = 0;
      v87 = 0;
      v85 = dword_634EDC;
      v84 |= 2u;
      if ( *(int *)(v9 + 4) < 0 )
        KeBugCheckEx(26, 13056, a1);
      goto LABEL_12;
    }
    if ( v12 == (int *)5 )
      KeBugCheckEx(26, 13056, a1);
    v11 = v90;
  }
  if ( !*(_DWORD *)(v11 + 264) )
  {
    v87 = 1;
    v13 = (unsigned int *)(v11 + 492);
    v85 = -1069539328;
    if ( *(int *)(v9 + 4) >= 0 )
      v84 |= 2u;
    v14 = MiComputeFaultNode(v13, a1, 0, 0, &v89);
    v8 = v89;
    v95 = v14;
    v15 = 1;
LABEL_12:
    v16 = v85;
LABEL_13:
    v17 = 0;
    v18 = *(_DWORD *)v9;
    v89 = (_DWORD *)(a5 & 1);
    if ( (a5 & 1) != 0 || v18 && (v15 == 1 || (*(_BYTE *)(v9 + 19) & 8) == 0) )
    {
      v19 = MiLocateWsle(a1, (int)v13, v18);
      v16 = v85;
      v18 = v19;
      if ( v19 < *(_DWORD *)(v85 + 4) && v87 != 2 )
      {
        v17 = 1;
        if ( (*(_DWORD *)(v9 + 8) & 0x400) != 0 )
          v17 = 2;
      }
      v20 = *(_DWORD *)(v85 + 252);
      v21 = *(_DWORD *)(v20 + *(_DWORD *)(v85 + 36) * v19);
      v97 = (unsigned int *)(v20 + *(_DWORD *)(v85 + 36) * v19);
      v22 = (v21 >> 4) & 0x1F;
      v99 = v21;
      if ( !v22 )
      {
        v23 = *(_DWORD *)(v9 + 8);
        if ( (v23 & 0x400) != 0 )
          v22 = (*(unsigned __int16 *)((*(_DWORD *)(v9 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v9 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
        else
          v22 = (v23 >> 5) & 0x1F;
      }
    }
    else
    {
      v67 = *(_DWORD *)(v9 + 8);
      if ( (v67 & 0x400) != 0 )
        v22 = (*(unsigned __int16 *)((*(_DWORD *)(v9 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v9 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
      else
        v22 = (v67 >> 5) & 0x1F;
      v97 = 0;
      v99 = v96;
    }
    v86 = MmMakeProtectNotWriteCopy[v22];
    v24 = v91;
    if ( v91 != -1 )
    {
LABEL_23:
      if ( v17 )
      {
        if ( v17 >= 2 )
          MiReturnCommit(MiSystemPartition, 1);
        MiUnlockPageTableCharges(MmPfnDatabase + 24 * (*(_DWORD *)(v9 + 20) & 0xFFFFF), 2, 0);
        v16 = v85;
        v24 = v91;
      }
      v26 = MmPfnDatabase + 24 * v24;
      v27 = v86;
      *(_DWORD *)(v26 + 8) = 0;
      if ( v86 != 24 )
      {
LABEL_25:
        *(_DWORD *)(v26 + 8) ^= ((unsigned __int16)*(_DWORD *)(v26 + 8) ^ (unsigned __int16)(32 * v27)) & 0x3E0;
        if ( v89 || v18 && (v87 == 1 || (*(_BYTE *)(v9 + 19) & 8) == 0) )
        {
          ++v13[16];
          if ( a1 < 0xC0000000 || a1 > 0xC03FFFFF )
            ++v13[14];
          v28 = v99 & 0xFFFFFE0F;
          v29 = (v99 & 8) == 0;
          *(_DWORD *)(*(_DWORD *)(v16 + 36) * v18 + *(_DWORD *)(v16 + 252)) = v99 & 0xFFFFFE0F;
          if ( v29 )
          {
            if ( (v28 & 4) != 0 )
            {
              MiUpdateWsleHash(a1, v18, (int)v13, 1);
              v16 = v85;
              v28 = *v97;
            }
            *(_DWORD *)(*(_DWORD *)(v16 + 36) * v18 + *(_DWORD *)(v16 + 252)) = v28 | 8;
          }
        }
        *(_WORD *)(v26 + 16) = 1;
        v30 = ((a2 >> 10) & 0x3FFFFC) - 0x40000000;
        *(_DWORD *)v26 = v18;
        if ( (*(_DWORD *)v30 & 2) == 0 )
          KeBugCheckEx(26, 399680, v30 << 10);
        *(_DWORD *)(v26 + 20) = *(_DWORD *)(v26 + 20) & 0xFFF00000 | (*(_DWORD *)v30 >> 12);
        v31 = MiGetEffectivePagePriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
        *(_BYTE *)(v26 + 18) |= 0x10u;
        v32 = v31;
        v33 = v84;
        v94 = v31;
        if ( (dword_682604 & 0x8000001) != 0 )
        {
          v33 = v84 | 4;
          LOBYTE(v84) = v84 | 4;
        }
        v34 = (unsigned __int8 *)(v26 + 15);
        do
          v35 = __ldrex(v34);
        while ( __strex(v35 | 0x80, v34) );
        __dmb(0xBu);
        if ( v35 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v79 = *(_DWORD *)(v26 + 12);
              __dmb(0xBu);
            }
            while ( (v79 & 0x80000000) != 0 );
            do
              v80 = __ldrex(v34);
            while ( __strex(v80 | 0x80, v34) );
            __dmb(0xBu);
          }
          while ( v80 >> 7 );
        }
        if ( v87 || (*(_BYTE *)(v9 + 19) & 8) == 0 || v89 )
          LOBYTE(v36) = *(_BYTE *)(v26 + 19) & 0xF7;
        else
          v36 = *(_BYTE *)(v26 + 19) | 8;
        *(_BYTE *)(v26 + 19) = v36;
        v37 = *(unsigned __int8 *)(v9 + 18);
        if ( *(unsigned __int8 *)(v26 + 18) >> 6 != v37 >> 6 )
          MiChangePageAttribute(v26, v37 >> 6, 1);
        MiSetPfnTbFlushStamp(v26, 0, 1);
        v38 = *(_DWORD *)(v26 + 12);
        *(_DWORD *)(v26 + 4) = a2;
        *(_DWORD *)(v26 + 12) = v38 & 0xC0000000 | 1;
        v39 = (*(_BYTE *)(v26 + 19) ^ v32) & 7 ^ *(_BYTE *)(v26 + 19);
        v40 = (v33 >> 2) & 1;
        *(_BYTE *)(v26 + 18) = *(_BYTE *)(v26 + 18) & 0xF8 | 6;
        *(_BYTE *)(v26 + 19) = v39;
        if ( v40 )
        {
          memset(v100, 0, sizeof(v100));
          MiIdentifyPfn(v26, v100);
        }
        __dmb(0xBu);
        v41 = (unsigned int *)(v26 + 12);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 & 0x7FFFFFFF, v41) );
        if ( v40 )
        {
          v100[4] |= 8u;
          v101[0] = (int)v100;
          v101[1] = 0;
          v101[2] = 24;
          v101[3] = 0;
          EtwTraceKernelEvent(v101, 1, 671088641, 642, 289413890);
        }
        v43 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 2956);
        do
          v44 = __ldrex(v43);
        while ( __strex(v44 + 1, v43) );
        LOWORD(v45) = v88;
        v46 = -1070596096;
        v47 = -1070592001;
        if ( (v88 & 0x10) == 0 )
        {
          v45 = v88 | 0x10;
          v70 = a2 + 0x40000000;
          v88 |= 0x10u;
          if ( a2 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)a2 = v45;
          }
          else
          {
            v70 = *(_DWORD *)a2;
            v71 = 0;
            __dmb(0xBu);
            *(_DWORD *)a2 = v88;
            if ( (v70 & 2) == 0 && (v88 & 2) != 0 )
              v71 = 1;
            if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
            {
              v81 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v81, v81 + 4 * (a2 & 0xFFF), v88);
            }
            if ( v71 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
            LOWORD(v45) = v88;
          }
          KeFlushSingleCurrentTb(a1, v47, v46, v70);
        }
        v48 = 1;
        if ( (v86 & 2) != 0 )
        {
          if ( (BYTE2(MiFlags) & 3) == 1 && a1 >= dword_63389C )
            v48 = 17;
        }
        else
        {
          v48 = 9;
        }
        MiCopyPage(v91, v96, 0, v48);
        if ( dword_634484 && v94 >= dword_634498 )
          MiLogPageAccess(v13, a2);
        if ( (v84 & 1) != 0 )
        {
          v49 = v88;
        }
        else
        {
          v49 = v45 & 0xFCFF | 0x90;
          if ( (BYTE2(MiFlags) & 3u) > 1 && (((unsigned __int8)v45 | 0x90) & 1) == 0 )
            MiMarkPfnVerified(v26, 1);
        }
        v50 = v49 & 0xFFF | (v91 << 12);
        v103 = 0;
        v105 = 33;
        v106 = 0;
        v104 = 0;
        v107 = 0;
        v108 = 0;
        v102 = v87;
        MiInsertTbFlushEntry(&v102, a1 & 0xFFFFF000, 1);
        if ( (v50 & 0x200) != 0 )
        {
          __dmb(0xBu);
          do
            v68 = __ldrex((unsigned int *)a2);
          while ( __strex(v50, (unsigned int *)a2) );
          __dmb(0xBu);
          MiFlushTbList(&v102);
        }
        else
        {
          v51 = v50 & 0xFFFFFFFC | 0x400;
          if ( a2 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)a2 = v51;
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)a2 = v51;
            if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
            {
              v82 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v82, v82 + 4 * (a2 & 0xFFF), v51);
            }
          }
          MiFlushTbList(&v102);
          if ( a2 + 0x40000000 > 0x3FFFFF )
          {
            *(_DWORD *)a2 = v50;
          }
          else
          {
            v52 = *(_DWORD *)a2;
            v53 = 0;
            __dmb(0xBu);
            *(_DWORD *)a2 = v50;
            if ( (v52 & 2) == 0 && (v50 & 2) != 0 )
              v53 = 1;
            if ( a2 >= 0xC0300000 && a2 <= 0xC0300FFF )
            {
              v83 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v83, v83 + 4 * (a2 & 0xFFF), v50);
            }
            if ( v53 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
        v54 = v90;
        if ( v87 == 1 )
        {
          v55 = (unsigned int *)(v90 + 276);
          do
            v56 = __ldrex(v55);
          while ( __strex(v56 + 1, v55) );
        }
        v57 = (unsigned __int8 *)(v9 + 15);
        do
          v58 = __ldrex(v57);
        while ( __strex(v58 | 0x80, v57) );
        __dmb(0xBu);
        if ( v58 >> 7 )
        {
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v72 = *(_DWORD *)(v9 + 12);
              __dmb(0xBu);
            }
            while ( (v72 & 0x80000000) != 0 );
            do
              v73 = __ldrex(v57);
            while ( __strex(v73 | 0x80, v57) );
            __dmb(0xBu);
          }
          while ( v73 >> 7 );
        }
        if ( !v87 && !v89 && (*(_BYTE *)(v9 + 19) & 8) != 0 )
          *(_BYTE *)(v9 + 19) &= 0xF7u;
        v59 = *(_DWORD *)(v9 + 12);
        if ( (*(_BYTE *)(v9 + 18) & 7) != 6 )
          KeBugCheckEx(78, 153, (v9 - MmPfnDatabase) / 24);
        *(_DWORD *)(v9 + 12) = v59 & 0xC0000000 | ((v59 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
        if ( (v59 & 0x3FFFFFFF) == 1 )
          MiPfnShareCountIsZero(v9, 0);
        __dmb(0xBu);
        v60 = (unsigned int *)(v9 + 12);
        do
          v61 = __ldrex(v60);
        while ( __strex(v61 & 0x7FFFFFFF, v60) );
        if ( (v84 & 2) != 0 )
        {
          v65 = MiDecrementCombinedPte(v98 | 0x80000000);
        }
        else
        {
          if ( v85 != -1069539328 )
            return 1;
          v62 = v98;
          v63 = MiLocateCloneAddress(v54, v98 | 0x80000000);
          if ( !v63 )
            return 1;
          v65 = MiDecrementCloneBlockReference(v63, v62 | 0x80000000, v54);
        }
        if ( v65 == 3 )
          MiChargeCommit((int)MiSystemPartition, 1u, 4);
        return 1;
      }
      LOWORD(v86) = 1;
      if ( v8 || (v16 = v85, (v8 = MiLocateAddress(a1)) != 0) )
      {
        v78 = (unsigned __int8)v8[7] >> 3;
        if ( v78 >> 3 == 3 && (v78 & 7) != 0 )
        {
          LOBYTE(v86) = 25;
          v27 = 25;
          goto LABEL_25;
        }
        if ( v78 >> 3 == 1 )
          LOWORD(v86) = 9;
      }
      v27 = v86;
      goto LABEL_25;
    }
    MI_INITIALIZE_COLOR_BASE(v13, v95, &v91);
    v25 = *(_WORD *)v91 + 1;
    *(_WORD *)v91 = v25;
    v24 = MiGetPage((int)MiSystemPartition, v93 | (unsigned __int16)(v25 & v92), 0);
    v91 = v24;
    if ( v24 != -1 )
    {
      v16 = v85;
      goto LABEL_23;
    }
    if ( v94 < 2 )
    {
      MiUnlockWorkingSetExclusive(v13, v94);
      MiWaitForFreePage(MiSystemPartition);
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v13);
      }
      else
      {
        v74 = (unsigned __int8 *)v13 + 3;
        do
          v75 = __ldrex(v74);
        while ( __strex(v75 | 0x80, v74) );
        __dmb(0xBu);
        if ( v75 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v13);
        while ( 1 )
        {
          v76 = *v13;
          if ( (*v13 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v76 & 0x40000000) == 0 )
          {
            do
              v77 = __ldrex(v13);
            while ( v77 == v76 && __strex(v76 | 0x40000000, v13) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
    }
    return 0;
  }
  MiWaitForForkToComplete(v90, a4, v12);
  return 0;
}
