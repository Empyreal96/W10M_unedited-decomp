// MiInitializeSystemWorkingSetList 
 
int __fastcall MiInitializeSystemWorkingSetList(int a1, unsigned int a2)
{
  int v2; // r7
  unsigned int v4; // r4
  unsigned int v5; // r0
  _DWORD *v6; // r6
  unsigned int v7; // r2
  unsigned int v8; // r4
  int v9; // r2
  int v10; // r3
  int v11; // r8
  unsigned int v12; // r10
  int v13; // r0
  unsigned int v15; // r3
  int v16; // r2
  unsigned int v17; // r4
  unsigned int v18; // r3
  int v19; // r3
  unsigned int v20; // r2
  int v21; // r1
  int v22; // r2
  int v23; // r3
  int v24; // r3
  int v25; // r8
  int v26; // r0
  unsigned int v27; // [sp+0h] [bp-30h]
  unsigned int v28; // [sp+4h] [bp-2Ch]
  _WORD *v29; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 v30; // [sp+Ch] [bp-24h]
  unsigned __int16 v31; // [sp+Eh] [bp-22h]

  v2 = a2;
  if ( a2 > 0xFFFFF )
    v2 = 0xFFFFF;
  v4 = (16 * v2 + 4196287) & 0xFFC00000;
  v5 = MiObtainSystemVa((v4 + 4 * v2 + 0x3FFFFF) >> 22, 3);
  v6 = (_DWORD *)v5;
  if ( !v5 )
    return 0;
  v7 = v5 + v4;
  v8 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
  v27 = (v5 + 271) & 0xFFFFFFF0;
  v28 = v7;
  if ( !MiMakeZeroedPageTables(v8, v8, 64) )
    return 0;
  MI_INITIALIZE_COLOR_BASE(0, 0, (int)&v29);
  v9 = (unsigned __int16)(*v29 + 1);
  v10 = v30;
  *v29 = v9;
  v11 = MiGetPage((int)MiSystemPartition, v9 & v10 | v31, 2);
  if ( v11 == -1 )
    return 0;
  v12 = (dword_681120 & 0x1ED | (v11 << 12) | MiDetermineUserGlobalPteMask(v8)) & 0xFFFFF1FF | 0x12;
  v13 = MmPfnDatabase + 24 * v11;
  if ( !*(_DWORD *)(v13 + 8) )
    return sub_96A924();
  MiInitializePfn(v13, (int *)v8, 4u, 4);
  if ( v8 < 0xC0000000 || v8 > 0xC03FFFFF )
  {
    *(_DWORD *)v8 = v12;
  }
  else
  {
    v24 = *(_DWORD *)v8;
    v25 = 0;
    __dmb(0xBu);
    *(_DWORD *)v8 = v12;
    if ( (v24 & 2) == 0 )
      v25 = 1;
    if ( v8 + 1070596096 <= 0xFFF )
    {
      v26 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
      MiArmWriteConvertedHardwarePde(v26, (_DWORD *)(v26 + 4 * (v8 & 0xFFF)), v12);
    }
    if ( v25 == 1 )
    {
      __dsb(0xFu);
      __isb(0xFu);
    }
  }
  KeZeroPages((_DWORD *)(v8 << 10), 0x1000u);
  MiChargeResident(MiSystemPartition, 1u, -1);
  *(_DWORD *)(a1 + 92) = v6;
  v6[9] = 4;
  v6[1] = 1;
  v6[13] = v28;
  v6[12] = (v28 - 4096) | 1;
  v6[3] = 1;
  v6[63] = v27;
  v6[14] = v28 + 4 * v2;
  v6[11] = dword_63389C;
  v15 = (unsigned int)dword_640508 < 0x4000 ? 32 : 256;
  *(_DWORD *)(a1 + 48) = v15;
  if ( !MiChargeResident(MiSystemPartition, v15, 0) )
    return 0;
  v16 = *(_DWORD *)(a1 + 48);
  do
    v17 = __ldrex(&dword_634A2C[43]);
  while ( __strex(v17 + v16, &dword_634A2C[43]) );
  v18 = *(_BYTE *)(a1 + 112) & 7;
  if ( v18 >= 2 )
    MiState[v18 + 1557] += 2;
  v19 = ((v27 >> 12) & 0x3FF) + 2;
  *(_DWORD *)(a1 + 72) = v19;
  *(_DWORD *)(a1 + 76) = v19;
  v20 = ((4096 - (v6[63] & 0xFFFu)) >> 2) - 1;
  v6[2] = v20;
  *(_DWORD *)(a1 + 68) = v2;
  v6[4] = v20;
  *(_DWORD *)(a1 + 52) = 0;
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_DWORD *)(a1 + 64) = 0;
  __dmb(0xBu);
  *(_DWORD *)a1 = 0;
  MiPopulateWorkingSetFreeList(a1, 1u, v20);
  MiAllowWorkingSetExpansion(a1, v21, v22, v23);
  return 1;
}
