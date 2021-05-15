// MiSessionInitializeWorkingSetList 
 
int __fastcall MiSessionInitializeWorkingSetList(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  unsigned int v5; // r8
  int v6; // r7
  int v7; // r10
  unsigned int v8; // r0
  int *v9; // r5
  int v11; // r4
  unsigned int v12; // r6
  unsigned int *v13; // r2
  unsigned int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r0
  int v17; // r2
  int v18; // r3
  unsigned int v19; // r2
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r3
  int v24; // r4
  _DWORD v25[10]; // [sp+0h] [bp-28h] BYREF

  v25[0] = a2;
  v25[1] = a3;
  v25[2] = a4;
  v4 = __mrc(15, 0, 13, 0, 3);
  v5 = dword_633790;
  v6 = *(_DWORD *)(*(_DWORD *)((v4 & 0xFFFFFFC0) + 0x74) + 324);
  *(_DWORD *)(v6 + 3376) = (dword_633790 + 271) & 0xFFFFFFF0;
  *(_DWORD *)(v6 + 3340) = v5;
  if ( !MiChargeCommit((int)MiSystemPartition, 1u, 0) )
LABEL_22:
    JUMPOUT(0x80F7C0);
  v7 = *(_DWORD *)(v6 + 3296);
  if ( !MiChargeResident(MiSystemPartition, 1u, 20) )
  {
    MiReturnCommit((int)MiSystemPartition, 1);
    goto LABEL_22;
  }
  do
    v8 = __ldrex(&dword_634A2C[44]);
  while ( __strex(v8 + 1, &dword_634A2C[44]) );
  v9 = (int *)(((v5 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( !MiMakeZeroedPageTables((unsigned int)v9, (int)v9, 65) )
    return sub_80F79C();
  MI_INITIALIZE_COLOR_BASE(v6 + 3248, 0, (int)v25);
  *(_DWORD *)(v6 + 4) |= 0x10u;
  v11 = MiGetSystemPage((int)v25);
  v12 = (MiDetermineUserGlobalPteMask(0) | (((v11 - MmPfnDatabase) / 24) << 12)) & 0xFFFFF9FF | dword_681120 & 0x1ED | 0x812;
  MiInitializePfn(v11, v9, 4u, 4);
  if ( (unsigned int)v9 < 0xC0000000 || (unsigned int)v9 > 0xC03FFFFF )
  {
    *v9 = v12;
  }
  else
  {
    v23 = *v9;
    v24 = 0;
    __dmb(0xBu);
    *v9 = v12;
    if ( (v23 & 2) == 0 && (v12 & 2) != 0 )
      v24 = 1;
    if ( ((v5 >> 10) & 0x3FFFFC) - 3145728 <= 0xFFF )
      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v12, (__int16)v9);
    if ( v24 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  v13 = (unsigned int *)(v6 + 28);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 + 1, v13) );
  v15 = (unsigned int *)(v6 + 32);
  do
    v16 = __ldrex(v15);
  while ( __strex(v16 + 1, v15) );
  *(_BYTE *)(v6 + 3360) = *(_BYTE *)(v6 + 3360) & 0x78 | 0x81;
  *(_DWORD *)(v6 + 3316) = v7 + 4;
  *(_DWORD *)(v5 + 8) = 0;
  v17 = *(_DWORD *)(v6 + 3376);
  *(_DWORD *)(v5 + 36) = 4;
  *(_DWORD *)(v5 + 252) = v17;
  *(_DWORD *)(v5 + 52) = dword_633794;
  *(_DWORD *)(v5 + 56) = dword_633798;
  *(_DWORD *)(v5 + 44) = dword_63389C;
  v18 = dword_633794;
  *(_DWORD *)(v5 + 4) = 1;
  *(_DWORD *)(v5 + 12) = 1;
  *(_DWORD *)(v5 + 48) = (v18 - 4096) | 1;
  v19 = ((4096 - (v17 & 0xFFFu)) >> 2) - 1;
  *(_DWORD *)(v5 + 16) = v19;
  *(_DWORD *)(v6 + 3300) = 0;
  *(_DWORD *)(v6 + 3304) = 0;
  *(_DWORD *)(v6 + 3308) = 0;
  *(_DWORD *)(v6 + 3312) = 0;
  MiPopulateWorkingSetFreeList(v6 + 3248, 1u, v19);
  MiAllowWorkingSetExpansion(v6 + 3248, v20, v21, v22);
  return 0;
}
