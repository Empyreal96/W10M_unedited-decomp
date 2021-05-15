// -StStagingRegionIssueIo@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_ST_STAGING_REGION@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StStagingRegionIssueIo(int a1, int *a2)
{
  int v3; // r6
  _DWORD *v4; // r7
  int v5; // r4
  int v6; // r2
  int v8; // r0
  int v9; // r4

  v3 = *a2;
  v4 = (_DWORD *)a2[2];
  v5 = *(_DWORD *)(a1 + 304);
  v6 = v4[4];
  v4[3] = *a2 << *(_DWORD *)(a1 + 100);
  v4[4] ^= ((unsigned __int8)*(_DWORD *)(a1 + 116) ^ (unsigned __int8)v6) & 2;
  *(_WORD *)(v5 + 2 * v3) |= 0x8000u;
  v4[4] ^= ((unsigned __int8)v4[4] ^ (unsigned __int8)(*(_DWORD *)(a1 + 116) >> 2)) & 4;
  StEtaIoStart(*(_DWORD *)(a1 + 276), *(_DWORD *)(a1 + 80), 1, v4 + 1);
  v8 = SmIssueIo(*(void **)(a1 + 92), v3, 0, *(_DWORD *)(a1 + 80), a2[1], (int)v4);
  v9 = v8;
  if ( v8 >= 0 )
  {
    if ( (v4[4] & 4) != 0 )
    {
      SmWaitForSyncIo(*(_DWORD *)(a1 + 92));
      v9 = ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion(a1, v4);
    }
  }
  else
  {
    ST_STORE<SM_TRAITS>::StDeviceIoMarkFailed(v4 + 1, v8);
    ST_STORE<SM_TRAITS>::StDmDeviceIoCompletion(a1, v4);
  }
  return v9;
}
