// ArbInitializeArbiterInstance 
 
int __fastcall ArbInitializeArbiterInstance(int a1, int a2, int a3, int a4)
{
  int v7; // r0
  int v9; // r0
  int v10; // r0
  int v11; // r0
  _DWORD *v12; // r3
  _DWORD *v13; // r3
  int v14; // r0
  int v15; // r3

  *(_DWORD *)a1 = 1935831617;
  *(_DWORD *)(a1 + 156) = 0;
  v7 = ExAllocatePoolWithTag(512, 16, 1298297409);
  *(_DWORD *)(a1 + 4) = v7;
  if ( !v7 )
    return sub_80D384();
  KeInitializeEvent(v7, 1, 1);
  v9 = ExAllocatePoolWithTag(1, 4096, 1096970817);
  *(_DWORD *)(a1 + 56) = v9;
  if ( !v9 )
    return sub_80D384();
  *(_DWORD *)(a1 + 52) = 4096;
  v10 = ExAllocatePoolWithTag(1, 20, 1382183489);
  *(_DWORD *)(a1 + 20) = v10;
  if ( !v10 )
    return sub_80D384();
  v11 = ExAllocatePoolWithTag(1, 20, 1382183489);
  *(_DWORD *)(a1 + 24) = v11;
  if ( !v11 )
    return sub_80D384();
  v12 = *(_DWORD **)(a1 + 20);
  *v12 = v12;
  v12[1] = v12;
  v12[2] = 0;
  v12[3] = 0;
  v12[4] = 0;
  v13 = *(_DWORD **)(a1 + 24);
  *v13 = v13;
  v13[1] = v13;
  v13[2] = 0;
  v13[3] = 0;
  v13[4] = 0;
  *(_BYTE *)(a1 + 144) = 0;
  v14 = ExAllocatePoolWithTag(512, 16, 1298297409);
  *(_DWORD *)(a1 + 148) = v14;
  if ( !v14 )
    return sub_80D384();
  KeInitializeEvent(v14, 0, 1);
  *(_DWORD *)(a1 + 8) = a4;
  *(_DWORD *)(a1 + 12) = L"Root";
  v15 = *(_DWORD *)(a1 + 76);
  *(_DWORD *)(a1 + 16) = a3;
  if ( !v15 )
    *(_DWORD *)(a1 + 76) = ArbTestAllocation;
  if ( !*(_DWORD *)(a1 + 80) )
    *(_DWORD *)(a1 + 80) = ArbRetestAllocation;
  if ( !*(_DWORD *)(a1 + 84) )
    *(_DWORD *)(a1 + 84) = ArbCommitAllocation;
  if ( !*(_DWORD *)(a1 + 88) )
    *(_DWORD *)(a1 + 88) = ArbRollbackAllocation;
  if ( !*(_DWORD *)(a1 + 104) )
    *(_DWORD *)(a1 + 104) = xHalAllocatePmcCounterSet;
  if ( !*(_DWORD *)(a1 + 112) )
    *(_DWORD *)(a1 + 112) = HvlRegisterWheaErrorNotification;
  if ( !*(_DWORD *)(a1 + 116) )
    *(_DWORD *)(a1 + 116) = ArbAllocateEntry;
  if ( !*(_DWORD *)(a1 + 120) )
    *(_DWORD *)(a1 + 120) = ArbGetNextAllocationRange;
  if ( !*(_DWORD *)(a1 + 124) )
    *(_DWORD *)(a1 + 124) = ArbFindSuitableRange;
  if ( !*(_DWORD *)(a1 + 128) )
    *(_DWORD *)(a1 + 128) = ArbAddAllocation;
  if ( !*(_DWORD *)(a1 + 132) )
    *(_DWORD *)(a1 + 132) = ArbBacktrackAllocation;
  if ( !*(_DWORD *)(a1 + 136) )
    *(_DWORD *)(a1 + 136) = ArbOverrideConflict;
  if ( !*(_DWORD *)(a1 + 92) )
    *(_DWORD *)(a1 + 92) = ArbBootAllocation;
  if ( !*(_DWORD *)(a1 + 100) )
    *(_DWORD *)(a1 + 100) = ArbQueryConflict;
  if ( !*(_DWORD *)(a1 + 96) )
    *(_DWORD *)(a1 + 96) = HvlRegisterWheaErrorNotification;
  if ( !*(_DWORD *)(a1 + 108) )
    *(_DWORD *)(a1 + 108) = ArbStartArbiter;
  if ( !*(_DWORD *)(a1 + 140) )
    *(_DWORD *)(a1 + 140) = ArbInitializeRangeList;
  if ( ArbBuildAssignmentOrdering(a1) < 0 )
    JUMPOUT(0x80D386);
  return 0;
}
