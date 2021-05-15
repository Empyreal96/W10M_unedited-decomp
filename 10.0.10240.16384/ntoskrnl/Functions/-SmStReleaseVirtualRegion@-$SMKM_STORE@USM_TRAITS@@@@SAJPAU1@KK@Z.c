// -SmStReleaseVirtualRegion@-$SMKM_STORE@USM_TRAITS@@@@SAJPAU1@KK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStReleaseVirtualRegion(int a1, int a2, char a3)
{
  int v3; // r6
  int v4; // r10
  int v7; // r7
  int result; // r0
  int v10; // r4
  char v11; // r3
  _DWORD v12[14]; // [sp+0h] [bp-38h] BYREF

  v3 = *(_DWORD *)(a1 + 3660);
  v4 = *(_DWORD *)(a1 + 3652);
  v7 = *(_DWORD *)(v3 + 4 * a2) & 0x7FFF0000;
  if ( (a3 & 2) != 0 && !v7 )
    return 1075380276;
  if ( (*(_WORD *)(v3 + 4 * a2) & 0x4000) != 0 )
    *(_WORD *)(v3 + 4 * a2) &= 0xBFFFu;
  else
    SMKM_STORE<SM_TRAITS>::SmStCheckLockInProgressRegionComplete(a1, v3 + 4 * a2);
  if ( SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(a1, a2) )
    return -1073741650;
  MmStoreDecommitVirtualMemory(v7, v4);
  if ( (*(_WORD *)(v3 + 4 * a2) & 0x8000) != 0 )
    return -1073741650;
  v10 = *(_DWORD *)(v3 + 4 * a2);
  *(_DWORD *)(v3 + 4 * a2) = 0;
  memset(v12, 0, 24);
  if ( (a3 & 1) != 0 )
    v11 = 3;
  else
    v11 = 0;
  v12[0] = v7;
  v12[1] = v4;
  result = SMKM_STORE<SM_TRAITS>::SmStHelperSendCommand(a1, 3, (int)v12, v11);
  if ( result != -1073741650 )
    return 0;
  *(_DWORD *)(v3 + 4 * a2) = v10;
  return result;
}
