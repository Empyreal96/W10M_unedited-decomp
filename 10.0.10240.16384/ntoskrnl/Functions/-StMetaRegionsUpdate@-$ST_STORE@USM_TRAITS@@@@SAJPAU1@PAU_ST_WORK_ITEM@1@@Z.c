// -StMetaRegionsUpdate@-$ST_STORE@USM_TRAITS@@@@SAJPAU1@PAU_ST_WORK_ITEM@1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StMetaRegionsUpdate(int a1, int a2, int a3, int a4)
{
  int v4; // r7
  int v7; // r10
  int v8; // r8
  unsigned int v9; // r6
  int v10; // r9
  int v11; // r5
  struct NP_CONTEXT::NP_CTX *v12; // r0
  struct NP_CONTEXT::NP_CTX *v13; // r0
  unsigned int v15; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]

  v17 = a4;
  v4 = a1 + 824;
  v7 = 0;
  v16 = a2;
  v8 = 0;
  ST_STORE<SM_TRAITS>::StDmGetSpaceStats(a1 + 824, &v15, 0);
  v9 = *(_DWORD *)(a1 + 952) - v15;
  if ( (*(_DWORD *)(a2 + 12) & 1) != 0 )
  {
    if ( v9 < 2 )
    {
      v9 = 2;
      v15 = 0;
      v10 = a1 + 56;
      v8 = v4;
      goto LABEL_9;
    }
    goto LABEL_5;
  }
  if ( v9 < 8 )
  {
LABEL_5:
    v11 = 1075380276;
    goto LABEL_12;
  }
  v10 = v4;
  v8 = a1 + 56;
  if ( *(_DWORD *)(v4 + 128) == v9 )
    --v9;
  v15 = 0;
  if ( v9 )
  {
LABEL_9:
    while ( 1 )
    {
      v11 = ST_STORE<SM_TRAITS>::StDmRegionRemove(v10, &v15);
      if ( v11 < 0 )
        break;
      ++v7;
      *(_BYTE *)((v15 >> 3) + *(_DWORD *)(v8 + 124)) |= 1 << (v15 & 7);
      ++*(_DWORD *)(v8 + 128);
      if ( !--v9 )
        goto LABEL_11;
    }
  }
  else
  {
LABEL_11:
    v11 = 0;
  }
LABEL_12:
  ST_STORE<SM_TRAITS>::StStoreWorkItemCleanup(a1, v16);
  if ( v8 == v4 && v7 && v11 != -1073741818 )
  {
    v12 = (struct NP_CONTEXT::NP_CTX *)(a1 + 64);
    if ( a1 == -56 )
      v12 = 0;
    NP_CONTEXT::NpNodesPageOut(v12);
    v13 = (struct NP_CONTEXT::NP_CTX *)(a1 + 100);
    if ( a1 == -92 )
      v13 = 0;
    NP_CONTEXT::NpNodesPageOut(v13);
  }
  return v11;
}
