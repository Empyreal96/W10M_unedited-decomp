// -StMapAndLockRegion@-$ST_STORE@USM_TRAITS@@@@SAPADPAU_ST_DATA_MGR@1@KKK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StMapAndLockRegion(int a1, unsigned int a2, int a3, int a4)
{
  int v8; // r9
  int v9; // r0
  int v10; // r0
  int v11; // r4
  int v12; // r3
  char v13; // r2
  int v14; // r0
  int v15; // r3
  int v16; // r0
  int v17; // r7
  int v18; // r0
  bool v19; // zf
  int v20; // r3
  int v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r2
  int v25; // r1
  int v27; // [sp+0h] [bp-28h]

  v8 = 0;
  if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * a2) & 0x1FFF) == 0 )
  {
    v9 = *(_DWORD *)(a1 + 92);
    if ( (*(_BYTE *)(v9 + 3517) & 4) != 0 )
      v10 = SMKM_STORE<SM_TRAITS>::SmStAllocateVirtualRegion(v9, a2);
    else
      v10 = SMKM_STORE<SM_TRAITS>::SmStAllocatePhysicalRegion(v9, a2);
    if ( v10 < 0 )
      return 0;
    ++*(_DWORD *)(a1 + 8 * a3 + 684);
    if ( !*(_BYTE *)(a1 + 72) )
      *(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * a2) = *(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * a2) & 0x1FFF | ((_WORD)a3 << 13);
    v8 = 1;
  }
  if ( *(_BYTE *)(a1 + 72) )
    LOBYTE(v12) = 0;
  else
    v12 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * a2) >> 13;
  v13 = (32 * v12) | 0x10;
  if ( a4 )
    v13 = (32 * v12) | 0x11;
  v14 = *(_DWORD *)(a1 + 92);
  v15 = *(unsigned __int8 *)(v14 + 3517);
  if ( (v15 & 4) != 0 )
    v16 = SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(v14, a2, 0, v15, v13);
  else
    v16 = SMKM_STORE<SM_TRAITS>::SmStMapPhysicalRegion(v14, a2, 0, v15, v13);
  v11 = v16;
  v17 = v16;
  if ( v16 )
  {
    if ( v16 == 1 || v16 == 3 )
    {
      ST_STORE<SM_TRAITS>::StDmUpdateRegionLazyCleanup(a1, a2, 1);
      v19 = v11 == 1;
      v11 = -1;
      if ( !v19 )
        v11 = 0;
      v17 = 0;
    }
    else
    {
      if ( (*(_DWORD *)(a1 + 72) & 0x40000) == 0 || !SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(*(_DWORD *)(a1 + 92), a2) )
      {
        v18 = *(_DWORD *)(a1 + 92);
        if ( (*(_BYTE *)(v18 + 3517) & 4) != 0 )
          SMKM_STORE<SM_TRAITS>::SmStMapVirtualRegion(v18, a2, 0, 2, 2u);
        else
          SMKM_STORE<SM_TRAITS>::SmStMapPhysicalRegion(v18, a2, 0, 2, 2);
        return v11;
      }
      v11 = -1;
    }
  }
  else
  {
    v11 = 0;
  }
  if ( v17 )
  {
    if ( *(_BYTE *)(a1 + 72) )
      v20 = 0;
    else
      v20 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * a2) >> 13;
    v21 = *(_DWORD *)(a1 + 92);
    v22 = (8 * v20) | 4;
    v23 = *(unsigned __int8 *)(v21 + 3517);
    if ( (v23 & 4) != 0 )
    {
      SMKM_STORE<SM_TRAITS>::SmStUnmapVirtualRegion((_DWORD *)v21, a2, v22, v23, v27, v22);
    }
    else
    {
      v24 = *(_DWORD *)(v21 + 3660);
      v25 = *(_DWORD *)(v24 + 4 * a2);
      *(_DWORD *)(v24 + 4 * a2) = v25 & 0xFFFFFFFD;
      if ( (v25 & 1) == 0 )
        SmFpFree(v21 + 3880, 4, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v25 & 0xFFFFFFF8);
    }
  }
  if ( v8 )
    ST_STORE<SM_TRAITS>::StReleaseRegion(a1, a2);
  return v11;
}
