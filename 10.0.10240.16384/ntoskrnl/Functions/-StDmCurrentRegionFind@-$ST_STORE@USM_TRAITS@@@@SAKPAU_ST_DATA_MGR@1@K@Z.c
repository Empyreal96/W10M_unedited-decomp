// -StDmCurrentRegionFind@-$ST_STORE@USM_TRAITS@@@@SAKPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmCurrentRegionFind(int a1)
{
  int v1; // r7
  int v3; // r5
  int v4; // r0
  int v5; // r1
  unsigned int v6; // r2
  unsigned int v7; // r6
  char v8; // r3
  int v9; // r0
  int v10; // r0
  int v11; // r0

  v1 = 0;
  v3 = -1;
  if ( *(_BYTE *)(a1 + 72) == 1 )
  {
    if ( (*(_BYTE *)(a1 + 756) & 3) != 3 )
    {
      v4 = ST_STORE<SM_TRAITS>::StDmCheckForCompaction(a1, 0);
      if ( v4 )
      {
        v5 = (*(_DWORD *)(a1 + 116) & 2) != 0;
        if ( v4 == 1 )
        {
          if ( *(_BYTE *)(a1 + 72) )
            v6 = 400;
          else
            v6 = 30;
          v7 = -2;
          v8 = *(_BYTE *)(a1 + 756) & 0xFC | 1;
        }
        else
        {
          v6 = 0;
          v7 = 0;
          v8 = *(_BYTE *)(a1 + 756) & 0xFC | 2;
        }
        v9 = *(_DWORD *)(a1 + 760);
        *(_BYTE *)(a1 + 756) = v8;
        ST_STORE<SM_TRAITS>::StLazyWorkMgrQueueWork(v9, v5, v6, v7);
      }
    }
    v10 = ST_STORE<SM_TRAITS>::StStagingRegionReuse(a1);
    if ( v10 )
      return *(_DWORD *)v10;
    if ( *(_DWORD *)(a1 + 392) != -1 )
      v1 = *(_DWORD *)(a1 + 392);
    v11 = ST_STORE<SM_TRAITS>::StRegionFindRepurpose(a1, v1);
  }
  else
  {
    v11 = ST_STORE<SM_TRAITS>::StRegionFindCompact(a1);
  }
  if ( v11 )
    v3 = (v11 - *(_DWORD *)(a1 + 304)) >> 1;
  return v3;
}
