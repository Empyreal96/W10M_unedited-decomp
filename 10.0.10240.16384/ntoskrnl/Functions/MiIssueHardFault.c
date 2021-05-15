// MiIssueHardFault 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiIssueHardFault(int a1, int a2, unsigned int a3, int a4, int a5, int a6)
{
  int v7; // r10
  int v8; // r8
  int v10; // r0
  int v11; // r4
  int v12; // r1
  int v13; // r4
  char v15; // r4
  int v16; // r5
  int v17; // r8
  unsigned int v18; // r2
  int v19; // r1
  int v20; // r3
  int v21; // r4
  int v22; // r3
  __int64 v23; // r0
  int v24; // r8
  unsigned int v25; // r4
  int v26; // r3
  int v27; // r5
  int v28; // r4
  int v29; // lr
  int v30; // r2
  int v31; // r3
  char v32; // r3
  int v33; // r0
  unsigned int v34; // r3
  _DWORD *v35; // r1
  char v36; // r2
  _DWORD *v37; // r2
  int *v38; // r1
  int v39; // r0
  __int16 v40; // r3
  unsigned __int8 *v41; // r3
  unsigned int v42; // r1
  unsigned int v43; // r4
  int v44; // r1
  __int16 v45; // r2
  char v46; // r3
  unsigned int v47; // r4
  int v48; // r3
  int v49; // r5
  int *v50; // r0
  int v51; // r3
  int v52; // r2
  unsigned int v53; // r1
  int v54; // r0
  int v55; // r0
  unsigned int v56; // r0
  int v57; // r1
  _DWORD v58[4]; // [sp+10h] [bp-70h] BYREF
  __int64 v59; // [sp+20h] [bp-60h]
  int v60; // [sp+28h] [bp-58h]
  int v61; // [sp+2Ch] [bp-54h]
  int v62; // [sp+30h] [bp-50h]
  int v63; // [sp+34h] [bp-4Ch]
  int v64[2]; // [sp+38h] [bp-48h] BYREF
  unsigned int v65; // [sp+40h] [bp-40h] BYREF
  __int64 v66; // [sp+44h] [bp-3Ch]
  int v67; // [sp+4Ch] [bp-34h]
  _DWORD *v68; // [sp+50h] [bp-30h] BYREF
  int *v69; // [sp+54h] [bp-2Ch]
  unsigned int v70; // [sp+58h] [bp-28h]

  v66 = *(_QWORD *)&a2;
  v65 = 0;
  *(_DWORD *)(a4 + 128) = a3;
  v7 = *(_DWORD *)(a4 + 88);
  v8 = *(_DWORD *)(a4 + 120);
  if ( (a3 < dword_63389C
     || (v31 = *((unsigned __int8 *)&MiState[2423]
               + ((int)(((a3 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
         v31 == 1)
     || v31 == 11)
    && (v10 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), (v11 = *(_DWORD *)(v10 + 324)) != 0)
    && !PsIsSystemProcess(v10) )
  {
    v12 = *(_DWORD *)(v11 + 8);
  }
  else
  {
    v12 = -1;
  }
  v13 = MiReferenceInPageFile(a4, v12);
  if ( (*(_BYTE *)(a1 + 115) & 0x10) != 0 )
    return sub_543C3C();
  if ( (*(_BYTE *)(a1 + 115) & 0x20) != 0 )
  {
    v52 = *(_DWORD *)(a1 + 68);
    *(_BYTE *)(a1 + 115) &= 0xDFu;
    MiReduceWs(a1, 1, v52);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(1);
  if ( v13 && (*(_DWORD *)(a4 + 116) = v13, (*(_DWORD *)(v8 + 28) & 0x20) != 0) )
  {
    v15 = 1;
    v65 = 1;
  }
  else
  {
    v15 = 0;
  }
  v16 = a5;
  v67 = a5 & 1;
  if ( (a5 & 1) == 0 || *(_BYTE *)(a5 & 0xFFFFFFFE) != 1 )
    ++*(_BYTE *)(v7 + 974);
  if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
    --*(_WORD *)(v7 + 310);
  else
    --*(_WORD *)(v7 + 308);
  KfLowerIrql(v66);
  if ( (*(_BYTE *)(a4 + 115) & 1) != 0 )
  {
    v33 = *(_DWORD *)(a4 + 4 * (((*(_DWORD *)(a4 + 172) & 0xFFF) != 0) + (*(_DWORD *)(a4 + 172) >> 12)) + 176);
    v34 = *(unsigned __int8 *)(MmPfnDatabase + 24 * v33 + 18);
    MiZeroPhysicalPage(v33, 3, v34 >> 6, v34);
  }
  v17 = *(_DWORD *)(a4 + 172);
  v68 = 0;
  *(_DWORD *)(a4 + 104) = v17;
  if ( *(_DWORD *)(a4 + 20) )
  {
    v15 |= 2u;
  }
  else
  {
    v18 = *(unsigned __int8 *)(a4 + 113);
    v19 = (v18 >> 2) & 1;
    if ( !v19 || (*(_BYTE *)(a4 + 115) & 0x10) == 0 || (v18 & 0xFFFFFF80) != 0 )
    {
      if ( ((PerfGlobalGroupMask & 0x2000) != 0 || (dword_643B6C & 1) != 0) && (v18 & 0xFFFFFF80) == 0 && !v19 )
      {
        v20 = *(_DWORD *)(a4 + 128);
        v21 = *(_DWORD *)(a4 + 116);
        v59 = *(_QWORD *)(a4 + 56);
        v60 = v20;
        v22 = *(_DWORD *)(v21 + 12);
        v68 = v58;
        v61 = v22;
        v62 = *(_DWORD *)(v7 + 880);
        v63 = v17;
        if ( (PerfGlobalGroupMask & 0x2000) != 0 )
        {
          HIDWORD(v23) = 0x2000;
          LODWORD(v23) = v58;
          EtwGetKernelTraceTimestamp(v23);
        }
        else
        {
          v58[0] = 0;
          v58[1] = 0;
          v58[2] = 0;
          v58[3] = 0;
        }
        if ( (dword_643B6C & 1) != 0 )
        {
          KeQueryTickCount(v64);
        }
        else
        {
          v64[0] = 0;
          v64[1] = 0;
        }
        v16 = a5;
      }
      if ( (*(_BYTE *)(a1 + 115) & 0xC0) == 192 && !*(_DWORD *)(a1 + 124) )
        KiStackAttachProcess(PsInitialSystemProcess, 0, a4 + 64);
      v15 = v65 | 2;
      MiIssueHardFaultIo(a4, (v65 | 2) & 1, v16);
    }
  }
  if ( v67 )
  {
    v35 = (_DWORD *)(v16 & 0xFFFFFFFE);
    if ( *(_BYTE *)(v16 & 0xFFFFFFFE) == 1 )
    {
      v36 = *(_BYTE *)(a1 + 112);
      if ( (v36 & 7u) >= 2 )
        *(_BYTE *)(a4 + 113) ^= (*(_BYTE *)(a4 + 113) ^ (v36 - 1)) & 3;
      if ( (v15 & 2) != 0 )
      {
        v37 = v35 + 5;
        v38 = (int *)v35[6];
        *(_DWORD *)a4 = v37;
        *(_DWORD *)(a4 + 4) = v38;
        if ( (_DWORD *)*v38 != v37 )
          __fastfail(3u);
        *v38 = a4;
        v37[1] = a4;
      }
      else
      {
        v50 = (int *)v35[8];
        *(_DWORD *)a4 = v35 + 7;
        *(_DWORD *)(a4 + 4) = v50;
        if ( (_DWORD *)*v50 != v35 + 7 )
          __fastfail(3u);
        *v50 = a4;
        v35[8] = a4;
        v35[9] += *(_DWORD *)(a4 + 104);
      }
      v39 = KfRaiseIrql(1);
      if ( (*(_BYTE *)(a1 + 112) & 7) != 0 )
      {
        v40 = *(_WORD *)(v7 + 310) + 1;
        *(_WORD *)(v7 + 310) = v40;
        if ( v40 || *(_DWORD *)(v7 + 100) == v7 + 100 )
          goto LABEL_71;
      }
      else
      {
        v51 = (__int16)(*(_WORD *)(v7 + 308) + 1);
        *(_WORD *)(v7 + 308) = v51;
        if ( v51 || *(_DWORD *)(v7 + 100) == v7 + 100 || *(_WORD *)(v7 + 310) )
          goto LABEL_71;
      }
      KiCheckForKernelApcDelivery(v39);
LABEL_71:
      KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(a1);
      }
      else
      {
        v41 = (unsigned __int8 *)(a1 + 3);
        do
          v42 = __ldrex(v41);
        while ( __strex(v42 | 0x80, v41) );
        __dmb(0xBu);
        if ( v42 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)a1);
        while ( 1 )
        {
          v43 = *(_DWORD *)a1;
          if ( (*(_DWORD *)a1 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v43 & 0x40000000) == 0 )
          {
            do
              v53 = __ldrex((unsigned int *)a1);
            while ( v53 == v43 && __strex(v43 | 0x40000000, (unsigned int *)a1) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      return 0;
    }
  }
  v24 = *(_DWORD *)(a4 + 140);
  v25 = *(_DWORD *)(a4 + 132);
  v26 = *(_DWORD *)(v24 + 4);
  v69 = (int *)v25;
  if ( v26 >= 0 )
    v24 = 0;
  v27 = MiWaitForInPageComplete(a4, (int)&v65, a1, v16, (int *)&v68);
  --*(_BYTE *)(v7 + 974);
  if ( v27 )
    return v27;
  if ( !v24 )
    v24 = MmPfnDatabase + 24 * (v65 >> 12);
  if ( (*(_DWORD *)(v24 + 20) & 0x8000000) != 0 )
  {
    v28 = ((HIDWORD(v66) >> 10) & 0x3FFFFC) - 0x40000000;
    v27 = MiCompleteProtoPteFault(a1, v66, HIDWORD(v66), v65, a6, 0, a5);
    if ( v27 >= 0 )
      goto LABEL_41;
    return v27;
  }
  v70 = 0x3FFFFF;
  if ( v67 && *(_BYTE *)(a5 & 0xFFFFFFFE) == 4 )
  {
    HIDWORD(v66) = *(_DWORD *)v25;
    v65 = HIDWORD(v66) & 0xFFFFFC1F | 0x80;
    if ( v25 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)v25 = v65;
    }
    else
    {
      v44 = 0;
      LODWORD(v66) = 0;
      __dmb(0xBu);
      v45 = v65;
      v46 = BYTE4(v66);
      *(_DWORD *)v25 = v65;
      if ( (v46 & 2) == 0 && (v45 & 2) != 0 )
      {
        v44 = 1;
        LODWORD(v66) = 1;
      }
      if ( v25 >= 0xC0300000 && v25 <= 0xC0300FFF )
      {
        v54 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v54, (_DWORD *)(v54 + 4 * (v25 & 0xFFF)), v45);
        v44 = v66;
      }
      if ( v44 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  v29 = MiDetermineUserGlobalPteMask(v25) | (MmProtectToPteMask[(*(_DWORD *)v25 >> 5) & 0x1F] ^ *(_DWORD *)v25) & 0xFED ^ *(_DWORD *)v25 | 0x12;
  if ( a6 )
  {
    if ( (v29 & 0x80) != 0 )
    {
      v32 = *(_BYTE *)(v24 + 18);
      v29 &= 0xFFFFFDFF;
      HIDWORD(v66) = v29;
      if ( (v32 & 0x10) == 0 && (*(_DWORD *)(v24 + 8) & 0x10) != 0 )
      {
        MiLockPageAndSetDirty(v24, 1);
        v29 = HIDWORD(v66);
      }
    }
  }
  if ( !v67 )
  {
LABEL_48:
    v30 = 0;
LABEL_49:
    v28 = (int)v69;
    if ( MiAllocateWsle(a1, (unsigned int)v69, v24, 0, v29, v30) )
    {
LABEL_41:
      if ( dword_634484 )
      {
        if ( v68 != (_DWORD *)2 )
        {
          v56 = MiGetEffectivePagePriorityThread((_DWORD *)v7);
          if ( v56 >= *(_DWORD *)(v57 + 6680) )
            MiLogPageAccess(a1, v28 | 1);
        }
      }
      if ( !v27 )
        v27 = 276;
      return v27;
    }
    MiLockAndDecrementShareCount(v24, 0);
    return -1073741801;
  }
  if ( *(_BYTE *)(a5 & 0xFFFFFFFE) != 4 )
  {
    v30 = a5 & 0xFFFFFFFE;
    if ( *(_BYTE *)(a5 & 0xFFFFFFFE) == 5 )
      goto LABEL_49;
    goto LABEL_48;
  }
  v47 = (unsigned int)v69;
  if ( (unsigned int)(v69 + 0x10000000) > v70 )
  {
    *v69 = v29;
  }
  else
  {
    v48 = *v69;
    v49 = 0;
    __dmb(0xBu);
    *(_DWORD *)v47 = v29;
    if ( (v48 & 2) == 0 )
      v49 = 1;
    if ( v47 >= 0xC0300000 && v47 <= 0xC0300FFF )
    {
      v55 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v55, (_DWORD *)(v55 + 4 * (v47 & 0xFFF)), v29);
    }
    if ( v49 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  *(_DWORD *)v24 = 0;
  return 276;
}
