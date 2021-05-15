// MiSwitchToTransition 
 
int __fastcall MiSwitchToTransition(unsigned int a1, int a2, int a3)
{
  unsigned int v3; // r9
  _DWORD *v4; // r3
  int v5; // r6
  int v6; // r1
  int v7; // r0
  __int64 v8; // r3
  unsigned int v9; // r5
  unsigned int *v10; // r7
  int v11; // r6
  int v12; // r10
  int v13; // r0
  unsigned int v14; // r8
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  unsigned int i; // r4
  __int16 v21; // r3
  int v22; // r0
  int v23; // r7
  int v24; // r4
  int v25; // r10
  unsigned int v26; // r4
  unsigned int v27; // r10
  unsigned int v28; // r8
  int v29; // r7
  unsigned int v30; // r1
  int v31; // r7
  int v32; // r3
  int v33; // r4
  int v34; // r2
  char v35; // r3
  unsigned int *v36; // r2
  int v37; // r8
  unsigned __int8 *v38; // r3
  unsigned int v39; // r1
  unsigned __int8 *v40; // r1
  int v41; // r3
  unsigned int v42; // r2
  char v43; // r3
  unsigned int *v44; // r2
  unsigned int v45; // r0
  int v46; // r2
  int v47; // r0
  int v48; // r0
  int v49; // r3
  int v50; // r6
  unsigned int *v51; // r2
  unsigned int v52; // r4
  int v53; // r1
  __int16 v54; // r3
  unsigned int *v55; // r2
  unsigned int v56; // r5
  unsigned int v58; // [sp+8h] [bp-108h]
  int v59; // [sp+10h] [bp-100h]
  int v60; // [sp+14h] [bp-FCh]
  int v61; // [sp+14h] [bp-FCh]
  int *v63; // [sp+1Ch] [bp-F4h]
  int v64; // [sp+20h] [bp-F0h]
  int v65; // [sp+24h] [bp-ECh]
  char v66; // [sp+2Ch] [bp-E4h]
  char v67; // [sp+30h] [bp-E0h]
  int v69; // [sp+38h] [bp-D8h]
  int v70; // [sp+40h] [bp-D0h]
  _DWORD *v71; // [sp+44h] [bp-CCh]
  _WORD *v72; // [sp+48h] [bp-C8h] BYREF
  __int16 v73; // [sp+4Ch] [bp-C4h]
  unsigned __int16 v74; // [sp+4Eh] [bp-C2h]
  int v75; // [sp+50h] [bp-C0h]
  int v76; // [sp+58h] [bp-B8h] BYREF
  char v77; // [sp+5Ch] [bp-B4h]
  char v78; // [sp+5Dh] [bp-B3h]
  int v79; // [sp+60h] [bp-B0h]
  int v80; // [sp+64h] [bp-ACh]
  int v81; // [sp+68h] [bp-A8h]
  int v82; // [sp+6Ch] [bp-A4h]

  v3 = a1;
  v4 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  v5 = v4[29];
  v71 = v4;
  v69 = v5;
  v67 = MiGetEffectivePagePriorityThread(v4);
  v63 = (int *)(v3 + 28);
  v7 = MiGetReadyInPageBlock(v6);
  v8 = *(_QWORD *)(v3 + 16);
  v70 = v8;
  v9 = (((unsigned int)v8 >> 10) & 0x3FFFFC) - 0x40000000;
  v10 = (unsigned int *)(v5 + 492);
  v75 = v7;
  v66 = 0;
  v59 = v5 + 492;
  MI_INITIALIZE_COLOR_BASE(v5 + 492, 0, (int)&v72);
  v11 = 0;
  v60 = 0xFFFFF;
  v12 = 0;
  v13 = MiObtainFaultCharges(MiSystemPartition, HIDWORD(v8) >> 12, 2);
  v58 = v9 + 4 * v13;
  v64 = v13;
  v14 = v13;
  while ( 2 )
  {
    v65 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v10);
    }
    else
    {
      v15 = (unsigned __int8 *)v10 + 3;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 | 0x80, v15) );
      __dmb(0xBu);
      if ( v16 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v10);
      while ( 1 )
      {
        v17 = *v10;
        if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v17 & 0x40000000) == 0 )
        {
          do
            v18 = __ldrex(v10);
          while ( v18 == v17 && __strex(v17 | 0x40000000, v10) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    while ( MiIsProbeActive((unsigned int *)v9, v14, 3) )
    {
      --v14;
      v58 -= 4;
      if ( !v14 )
      {
        v24 = MmPfnDatabase;
        v25 = 1;
        goto LABEL_68;
      }
    }
    for ( i = 0; ; ++i )
    {
      if ( i >= v14 )
      {
        v26 = v58;
        goto LABEL_28;
      }
      v21 = *v72 + 1;
      *v72 = v21;
      v22 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v21 & v73) | v74, 0);
      v23 = v22;
      if ( v22 == -1 )
        break;
      v11 = MmPfnDatabase + 24 * v22;
      if ( MiPageAttributeBatchChangeNeeded(v11, a3) == 1 )
      {
        *(_DWORD *)(v11 + 8) = v12;
        v12 = v11;
      }
      MiSetPfnBlink(v11, v60, 0);
      v60 = v23;
    }
    if ( !i )
    {
      v10 = (unsigned int *)v59;
      MiUnlockWorkingSetExclusive(v59, v65);
      MiWaitForFreePage(MiSystemPartition);
      continue;
    }
    break;
  }
  v26 = v9 + 4 * i;
  v58 = v26;
LABEL_28:
  if ( v12 )
    MiChangePageAttributeBatch(v12, a3, 128, v19);
  if ( v9 >= v26 )
  {
LABEL_66:
    v25 = 0;
    v24 = MmPfnDatabase;
  }
  else
  {
    v27 = v9 + 1070596096;
    while ( 1 )
    {
      v28 = *(_DWORD *)v9;
      if ( (*(_DWORD *)v9 & 2) == 0 )
        KeBugCheck2(26, 266752, v9, v28, v3, 0);
      v24 = MmPfnDatabase;
      v29 = MmPfnDatabase + 24 * (v28 >> 12);
      if ( MI_IS_PFN(v28 >> 12) )
      {
        if ( (*(_DWORD *)(v29 + 4) | 0x80000000) == v9 )
          KeBugCheck2(26, 266752, v9, v28, v3, 0);
        v30 = 1;
        if ( (*(_DWORD *)(v29 + 20) & 0xFFFFF) == 1048573 )
          v30 = 2;
        if ( *(unsigned __int16 *)(v29 + 16) > v30 )
          break;
      }
      v31 = v11;
      v32 = *(_DWORD *)(v11 + 12) & 0xFFFFF;
      if ( v32 == 0xFFFFF )
        v11 = 0;
      else
        v11 = v24 + 24 * v32;
      v61 = (v31 - v24) / 24;
      if ( (v28 & 0x80) != 0 )
        v33 = 4;
      else
        v33 = 1;
      if ( a3 == 2 )
      {
        v33 |= 0x18u;
      }
      else if ( !a3 )
      {
        v33 |= 8u;
      }
      v34 = v75;
      *(_DWORD *)v31 = v75 + 16;
      *(_DWORD *)(v31 + 8) = 32 * v33;
      *(_BYTE *)(v31 + 18) |= 0x20u;
      if ( (v66 & 1) == 0 )
      {
        *(_DWORD *)(v34 + 88) = v71;
        v35 = *(_BYTE *)(v34 + 113);
        *(_DWORD *)(v34 + 140) = v31;
        *(_DWORD *)(v34 + 48) = 0;
        *(_DWORD *)(v34 + 52) = 0;
        *(_BYTE *)(v34 + 113) = v35 | 0x10;
        v66 |= 1u;
      }
      v36 = (unsigned int *)(((v9 >> 10) & 0x3FFFFC) - 0x40000000);
      if ( (*v36 & 2) == 0 )
        KeBugCheck2(26, 399680, (_DWORD)v36 << 10, *v36, 0, 0);
      *(_DWORD *)(v31 + 20) = *(_DWORD *)(v31 + 20) & 0xFFF00000 | (*v36 >> 12);
      v37 = KfRaiseIrql(2);
      v38 = (unsigned __int8 *)(v31 + 15);
      do
        v39 = __ldrex(v38);
      while ( __strex(v39 | 0x80, v38) );
      __dmb(0xBu);
      if ( v39 >> 7 )
      {
        v40 = (unsigned __int8 *)(v31 + 15);
        do
        {
          do
          {
            __dmb(0xAu);
            __yield();
            v41 = *(_DWORD *)(v31 + 12);
            __dmb(0xBu);
          }
          while ( (v41 & 0x80000000) != 0 );
          do
            v42 = __ldrex(v40);
          while ( __strex(v42 | 0x80, v40) );
          __dmb(0xBu);
        }
        while ( v42 >> 7 );
      }
      *(_DWORD *)(v31 + 12) &= 0xC0000000;
      MiAddLockedPageCharge(v31, 1);
      v43 = *(_BYTE *)(v31 + 18);
      *(_DWORD *)(v31 + 4) = v9;
      *(_BYTE *)(v31 + 18) = v43 & 0xF8 | 2;
      *(_BYTE *)(v31 + 19) ^= (*(_BYTE *)(v31 + 19) ^ v67) & 7;
      __dmb(0xBu);
      v44 = (unsigned int *)(v31 + 12);
      do
        v45 = __ldrex(v44);
      while ( __strex(v45 & 0x7FFFFFFF, v44) );
      KfLowerIrql(v37);
      MiReturnFaultCharges(MiSystemPartition, 1, 0);
      --v64;
      v46 = 32 * (v33 & 0x1F | (v61 << 7) | 0x40);
      if ( v27 + 3145728 > 0x3FFFFF )
      {
        *(_DWORD *)v9 = v46;
      }
      else
      {
        __dmb(0xBu);
        *(_DWORD *)v9 = v46;
        if ( v27 <= 0xFFF )
        {
          v47 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
          MiArmWriteConvertedHardwarePde(v47, (_DWORD *)(v47 + 4 * (v9 & 0xFFF)), v46);
        }
      }
      v9 += 4;
      v27 += 4;
      *v63++ = v61;
      if ( v9 >= v58 )
        goto LABEL_66;
    }
    v25 = 1;
  }
  v10 = (unsigned int *)v59;
LABEL_68:
  if ( v11 )
  {
    while ( 1 )
    {
      v48 = v11;
      v49 = *(_DWORD *)(v11 + 12) & 0xFFFFF;
      v11 = v49 == 0xFFFFF ? 0 : v24 + 24 * v49;
      *(_DWORD *)(v48 + 8) = 128;
      MiReleaseFreshPage(v48);
      if ( !v11 )
        break;
      v24 = MmPfnDatabase;
    }
    v3 = a1;
    v10 = (unsigned int *)v59;
  }
  MiUnlockWorkingSetExclusive((int)v10, v65);
  if ( v64 )
    MiReturnFaultCharges(MiSystemPartition, v64, 0);
  v50 = (int)((int)v63 - v3 - 28) >> 2;
  *(_DWORD *)(v3 + 20) = v50 << 12;
  if ( v50 )
  {
    v51 = (unsigned int *)(v69 + 276);
    do
      v52 = __ldrex(v51);
    while ( __strex(v52 + v50, v51) );
    v80 = 0;
    v76 = 1;
    v77 = 0;
    v78 = 0;
    v81 = 0;
    v79 = 33;
    v82 = 0;
    MiInsertTbFlushEntry((int)&v76, v70 & 0xFFFFF000, v50, 0);
    MiFlushTbList((unsigned int)&v76, v53);
    v54 = *(_WORD *)(v3 + 6);
    *(_DWORD *)(v3 + 8) = v69;
    v55 = (unsigned int *)(v69 + 280);
    *(_WORD *)(v3 + 6) = v54 | 2;
    do
      v56 = __ldrex(v55);
    while ( __strex(v56 + v50, v55) );
    if ( (MmTrackLockedPages & 1) != 0 )
      MiAddMdlTracker(v3, v50, 4);
  }
  return v25;
}
