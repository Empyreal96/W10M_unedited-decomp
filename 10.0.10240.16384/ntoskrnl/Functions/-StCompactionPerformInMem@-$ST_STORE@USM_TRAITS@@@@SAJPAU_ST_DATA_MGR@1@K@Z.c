// -StCompactionPerformInMem@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StCompactionPerformInMem(_DWORD *a1, int a2)
{
  int v3; // r9
  BOOL v4; // r10
  unsigned int v5; // r0
  int v6; // r0
  int v7; // r2
  unsigned int v8; // r8
  int v9; // r7
  int v10; // r4
  int v11; // r0
  int v12; // r6
  int v13; // r9
  char *i; // r3
  int v15; // r8
  int v16; // r0
  int v17; // r10
  BOOL v19; // [sp+8h] [bp-C8h]
  unsigned int v20; // [sp+Ch] [bp-C4h]
  char *v21; // [sp+10h] [bp-C0h]
  _WORD *v22; // [sp+14h] [bp-BCh]
  int v24; // [sp+20h] [bp-B0h] BYREF
  char v25; // [sp+24h] [bp-ACh] BYREF
  char v26[160]; // [sp+30h] [bp-A0h] BYREF

  v3 = a2;
  v4 = (a1[18] & 0x40000) != 0;
  v19 = v4;
  v5 = ST_STORE<SM_TRAITS>::StCompactionFindEmptiest((int)a1, (unsigned int)v26, 32, a1[26] - a1[27] + 1);
  v6 = ST_STORE<SM_TRAITS>::StCompactionPickPriority(a1, v26, v5, &v24);
  v7 = a1[76];
  v8 = v6;
  v20 = v6;
  v9 = (v24 - v7) >> 1;
  if ( (a1[18] & 0x40000) != 0 && SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(a1[23], (v24 - v7) >> 1) )
    return -1073740024;
  v11 = ST_STORE<SM_TRAITS>::StMapAndLockRegion(a1, v9, 0, v4);
  v12 = v11;
  if ( !v11 )
    return -1073741739;
  if ( v11 == -1 )
    return -1073740024;
  v10 = ST_STORE<SM_TRAITS>::StCompactRegions((int)a1, v11, v9, v11, v9, v3);
  if ( v10 >= 0 )
  {
    v13 = 1;
    if ( v8 <= 1 )
    {
LABEL_22:
      v10 = 0;
    }
    else
    {
      for ( i = &v25; ; i = v21 )
      {
        v21 = i + 4;
        v22 = *(_WORD **)i;
        v15 = *(_DWORD *)i - a1[76];
        if ( (a1[18] & 0x40000) != 0 && SMKM_STORE<SM_TRAITS>::SmStIsRegionBusy(a1[23], v15 >> 1) )
        {
LABEL_20:
          v10 = -1073740024;
          goto LABEL_23;
        }
        v16 = ST_STORE<SM_TRAITS>::StMapAndLockRegion(a1, v15 >> 1, 0, v4);
        v17 = v16;
        if ( !v16 )
          break;
        if ( v16 == -1 )
          goto LABEL_20;
        v10 = ST_STORE<SM_TRAITS>::StCompactRegions((int)a1, v16, v15 >> 1, v12, v9, a2);
        if ( (*v22 & 0x1FFF) != 0 )
        {
          ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
          v12 = v17;
          v9 = v15 >> 1;
        }
        else
        {
          ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
          ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v15 >> 1);
        }
        if ( v10 < 0 )
          goto LABEL_23;
        if ( ++v13 >= v20 )
          goto LABEL_22;
        v4 = v19;
      }
      v10 = -1073741739;
    }
  }
LABEL_23:
  if ( v12 )
    ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
  return v10;
}
