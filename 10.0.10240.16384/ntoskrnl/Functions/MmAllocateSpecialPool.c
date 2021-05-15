// MmAllocateSpecialPool 
 
unsigned int __fastcall MmAllocateSpecialPool(int a1, int a2, int a3, int a4)
{
  int v4; // r10
  int v5; // r6
  int v6; // r8
  unsigned int v7; // r7
  unsigned int v8; // r0
  int v9; // r7
  unsigned int *v10; // r8
  unsigned int v11; // r9
  int v12; // r7
  int *v13; // r9
  unsigned int *v14; // r7
  unsigned int v15; // r0
  __int16 v16; // r1
  int *v17; // r7
  unsigned int *v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r5
  unsigned int v21; // r5
  unsigned int v22; // r0
  int v23; // r10
  int v24; // r3
  int v25; // r9
  int v26; // r0
  unsigned int v27; // r5
  __int16 v28; // r10
  int v29; // r2
  unsigned int v30; // r6
  unsigned int *v31; // r2
  unsigned int v32; // r1
  unsigned int v33; // r1
  unsigned int v34; // r0
  unsigned int v36; // [sp+8h] [bp-50h]
  unsigned int v37; // [sp+Ch] [bp-4Ch]
  int v38; // [sp+Ch] [bp-4Ch]
  unsigned int v39; // [sp+10h] [bp-48h]
  int v41; // [sp+18h] [bp-40h] BYREF
  __int16 v42; // [sp+1Ch] [bp-3Ch]
  unsigned __int16 v43; // [sp+1Eh] [bp-3Ah]
  int v44; // [sp+20h] [bp-38h]
  int v45; // [sp+24h] [bp-34h]
  int v46; // [sp+28h] [bp-30h]
  char v47[40]; // [sp+30h] [bp-28h] BYREF

  v4 = a3 & 1;
  v44 = a4;
  v45 = a2;
  v46 = v4;
  v5 = a3;
  v6 = a1;
  if ( (a3 & 1) == 0 && (a3 & 0x200) == 0 && (MiFlags & 0x30000) != 0 )
    v5 = a3 | 0x200;
  v7 = 1;
  v8 = KeGetCurrentIrql(a1);
  if ( !v4 )
    v7 = 2;
  if ( v8 > v7 )
    KeBugCheckEx(193, v8, v5, v6, 48);
  v9 = 4;
  v39 = 4;
  if ( (v5 & 0x20) != 0 )
  {
    LOWORD(v36) = (MiDetermineUserGlobalPteMask(0) | dword_681120) & 0x1ED | 0xF812;
    v10 = (unsigned int *)dword_63501C;
    MiInitializeColorBaseSession((int)&v41);
  }
  else
  {
    v10 = (unsigned int *)&unk_634D00;
    MI_INITIALIZE_COLOR_BASE(0, 0, (int)&v41);
    if ( !v4 && (v5 & 0x200) == 0 )
    {
      v9 = 6;
      v39 = 6;
    }
    v36 = (MiDetermineUserGlobalPteMask(0) | MmProtectToPteMask[v9]) & 0x1ED | 0xFFFFF012;
  }
  if ( !v10[6] )
    return 0;
  if ( !MiChargeCommit((int)MiSystemPartition, 1u, 1) )
  {
    ++dword_632D3C;
    return 0;
  }
  v11 = dword_640580;
  v12 = dword_64050C;
  v37 = dword_640580;
  if ( (!dword_64050C || v12 == MiNumberWsSwapPagefiles((int)MiSystemPartition)) && dword_634D9C > v11 >> 1 )
  {
    ++dword_632D34;
LABEL_22:
    MiReturnCommit((int)MiSystemPartition, 1);
    return 0;
  }
  if ( !v4 && dword_632D4C > (unsigned int)dword_640508 >> 3 )
  {
    ++dword_632D2C;
    goto LABEL_22;
  }
  v13 = 0;
  v14 = v10 + 1;
  if ( v4 )
  {
    if ( v10 == (unsigned int *)&unk_634D00 )
    {
      v13 = &dword_634E80;
      if ( !MiChargeWsles((int)&dword_634E80, 1, 0) )
      {
        ++dword_632D48;
        goto LABEL_22;
      }
    }
  }
  else
  {
    if ( !MiChargeResident(MiSystemPartition, 1u, 128) )
    {
      ++dword_632D38;
      goto LABEL_22;
    }
    do
      v15 = __ldrex(&dword_634A2C[64]);
    while ( __strex(v15 + 1, &dword_634A2C[64]) );
    v14 = v10 + 4;
  }
  v16 = *(_WORD *)v41 + 1;
  *(_WORD *)v41 = v16;
  if ( v37 < 0x100 || (v38 = MiGetPage((int)MiSystemPartition, (unsigned __int16)(v16 & v42) | v43, 0), v38 == -1) )
  {
    ++dword_632D28;
    goto LABEL_72;
  }
  KeAcquireInStackQueuedSpinLock(v10, (unsigned int)v47);
  v41 = 4194300;
  if ( *v14 >> 12 == (int)((((unsigned int)v14 >> 10) & 0x3FFFFC) - v14[2] - 0x40000000) >> 2 )
  {
    KeReleaseInStackQueuedSpinLock((int)v47);
    v17 = MiExpandSpecialPool(v5);
    if ( v17 )
      goto LABEL_42;
    MiReleaseFreshPage(MmPfnDatabase + 24 * v38);
    ++dword_632D30;
LABEL_72:
    MiReturnCommit((int)MiSystemPartition, 1);
    if ( v4 )
    {
      if ( v10 == (unsigned int *)&unk_634D00 )
        MiChargeWsles((int)v13, -1, 0);
    }
    else
    {
      MiReturnResidentAvailable(1);
      do
        v34 = __ldrex(&dword_634A2C[65]);
      while ( __strex(v34 + 1, &dword_634A2C[65]) );
    }
    return 0;
  }
  v17 = (int *)RemoveListHeadPte(v14);
  v18 = (unsigned int *)((v41 & ((unsigned int)v17 >> 10)) - 0x40000000);
  v19 = *v18;
  if ( (*v18 & 2) == 0 )
    KeBugCheckEx(26, 399680, (_DWORD)v18 << 10, v19, 0);
  *(_DWORD *)(MmPfnDatabase + 24 * (v19 >> 12) + 8) = ((*(_DWORD *)(MmPfnDatabase + 24 * (v19 >> 12) + 8) & 0xFFFFE000)
                                                     + 0x2000) ^ *(_DWORD *)(MmPfnDatabase + 24 * (v19 >> 12) + 8) & 0x1FFF;
  KeReleaseInStackQueuedSpinLock((int)v47);
  do
  {
LABEL_42:
    v20 = __ldrex((unsigned int *)&dword_634D9C);
    v21 = v20 + 1;
  }
  while ( __strex(v21, (unsigned int *)&dword_634D9C) );
  if ( v21 == 1 )
  {
    do
      v22 = __ldrex((unsigned int *)&dword_634C84);
    while ( __strex(v22 + 1, (unsigned int *)&dword_634C84) );
  }
  v23 = v36 & 0xFFF | (v38 << 12);
  MiInitializePfn(MmPfnDatabase + 24 * v38, v17, v39, 4);
  if ( (unsigned int)(v17 + 0x10000000) > 0x3FFFFF )
  {
    *v17 = v23;
  }
  else
  {
    v24 = *v17;
    v25 = 0;
    __dmb(0xBu);
    *v17 = v23;
    if ( (v24 & 2) == 0 )
      v25 = 1;
    if ( (unsigned int)(v17 + 267649024) <= 0xFFF )
    {
      v26 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v26, (_DWORD *)(v26 + 4 * ((unsigned __int16)v17 & 0xFFF)), v23);
    }
    if ( v25 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  if ( v21 > dword_632D24 )
    dword_632D24 = v21;
  KeQueryTickCount(&v41);
  v27 = (_DWORD)v17 << 10;
  v28 = (unsigned __int8)v41;
  memset((_BYTE *)((_DWORD)v17 << 10), (unsigned __int8)v41 | 1, 4096);
  v29 = a1;
  v41 = v5 & 0x40;
  if ( (v5 & 0x40) != 0 )
    v29 = a1 - 4;
  if ( v44 && (v44 == 1 || MmSpecialPoolCatchOverruns != 1) )
  {
    v30 = v27 + 4088;
  }
  else
  {
    v30 = (_DWORD)v17 << 10;
    v27 = (v27 - v29 + 4096) & 0xFFFFFFF8;
  }
  *(_DWORD *)v30 = 0;
  *(_DWORD *)(v30 + 4) = 0;
  *(_DWORD *)v30 = v29;
  if ( v10 != (unsigned int *)&unk_634D00 )
  {
    *(_DWORD *)v30 = v29 | 0x2000;
    v31 = v10 + 7;
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 + 1, v31) );
  }
  *(_WORD *)(v30 + 2) = *(_WORD *)(v30 + 2) ^ (*(_WORD *)(v30 + 2) ^ v28) & 0x1FE | 1;
  *(_DWORD *)(v30 + 4) = v45;
  if ( v46 )
  {
    *(_DWORD *)v30 |= 0x8000u;
    if ( !MiMakeSpecialPoolPaged(v10, v17) )
    {
      ++dword_632D40;
      MmFreeSpecialPool(v27);
      return 0;
    }
  }
  else
  {
    do
      v33 = __ldrex((unsigned int *)&dword_632D4C);
    while ( __strex(v33 + 1, (unsigned int *)&dword_632D4C) );
  }
  if ( v41 )
    *(_DWORD *)v30 |= 0x4000u;
  return v27;
}
