// -StCompactionPerformEmergency@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCompactionPerformEmergency(int a1)
{
  _WORD *v1; // r5
  int v2; // r10
  int v3; // r6
  _WORD *v4; // r9
  unsigned int v6; // r2
  unsigned int v7; // r8
  int v8; // r7
  unsigned int v9; // r3
  int v10; // r0
  unsigned int v11; // r0

  v1 = *(_WORD **)(a1 + 304);
  v2 = *(_DWORD *)(a1 + 80);
  v3 = 0;
  v4 = &v1[*(_DWORD *)(a1 + 128)];
  v6 = v2 - 4096;
  if ( v1 >= v4 )
    return 0;
  do
  {
    v7 = (unsigned __int16)*v1;
    if ( (*v1 & 0x1FFF) != 0 && (*v1 & 0x1FFFu) <= v6 >> 4 )
    {
      v8 = ((int)v1 - *(_DWORD *)(a1 + 304)) >> 1;
      if ( SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(*(_DWORD *)(a1 + 92), v8) )
      {
LABEL_5:
        v3 = 1;
LABEL_15:
        v6 = v2 - 4096;
        goto LABEL_16;
      }
      v9 = v7 >> 13;
      if ( *(_BYTE *)(a1 + 72) )
        v9 = 0;
      if ( v8 == *(_DWORD *)(a1 + 12 * v9 + 392) )
        goto LABEL_15;
      if ( ST_STORE<SM_TRAITS>::StCompactRegions(a1, 0, v8, 0, v8, 0) < 0 )
      {
        if ( ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 2) != 2 )
          break;
        v10 = ST_STORE<SM_TRAITS>::StMapAndLockRegion(a1, v8, 0, 1);
        if ( !v10 || v10 == -1 )
          goto LABEL_5;
        ST_STORE<SM_TRAITS>::StCompactRegions(a1, v10, v8, v10, v8, 0);
        ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
      }
      v11 = (16 * (*v1 & 0x1FFF) + 4095) & 0xFFFFF000;
      MmStoreDecommitVirtualMemory(
        v11 + (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 92) + 3660) + 4 * v8) & 0x7FFF0000),
        v2 - v11);
      goto LABEL_15;
    }
LABEL_16:
    ++v1;
  }
  while ( v1 < v4 );
  if ( v3 )
    return -1073741267;
  return 0;
}
