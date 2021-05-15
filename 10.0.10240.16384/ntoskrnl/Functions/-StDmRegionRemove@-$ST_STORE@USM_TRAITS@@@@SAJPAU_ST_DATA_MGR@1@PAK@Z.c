// -StDmRegionRemove@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmRegionRemove(int a1, unsigned int *a2)
{
  _WORD *v4; // r0
  unsigned int v5; // r6
  int result; // r0
  int v7; // r2
  _DWORD *v8; // r5
  int v9; // r1
  _DWORD *v10; // r0
  _DWORD *v11; // r5
  int v12; // r0
  char v13; // r3

  v4 = (_WORD *)ST_STORE<SM_TRAITS>::StRegionFindRepurpose(a1, *a2);
  if ( !v4 )
    return -1073741275;
  v5 = ((int)v4 - *(_DWORD *)(a1 + 304)) >> 1;
  if ( (*v4 & 0x1FFF) == 0 )
    goto LABEL_25;
  if ( (*(_DWORD *)(a1 + 116) & 2) != 0 )
    return -1073741275;
  result = ST_STORE<SM_TRAITS>::StDmRegionEvict(a1, a1 + 252, v5);
  if ( result >= 0 )
  {
LABEL_25:
    if ( *(_BYTE *)(a1 + 72) )
      v7 = 0;
    else
      v7 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 304) + 2 * v5) >> 13;
    if ( v5 != *(_DWORD *)(a1 + 12 * v7 + 392) )
      v7 = 8;
    if ( v7 != 8 )
    {
      v8 = (_DWORD *)(a1 + 12 * v7);
      if ( v8[98] != -1 )
      {
        if ( !*(_BYTE *)(a1 + 72) )
          ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
        v9 = v8[98];
        if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v9) & 0x1FFF) == 0 )
          ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v9);
      }
      v8[99] = -1;
      v8[100] = 0;
      v8[98] = -1;
    }
    v10 = (_DWORD *)ST_STORE<SM_TRAITS>::StStagingRegionFind(a1, v5);
    v11 = v10;
    if ( v10 )
    {
      if ( *v10 != -1 )
      {
        ExFreePoolWithTag(v10[1]);
        ExFreePoolWithTag(v11[2]);
      }
      *v11 = 0;
      v11[1] = 0;
      v11[2] = 0;
      *v11 = -1;
    }
    v12 = *(_DWORD *)(a1 + 124);
    v13 = *(_BYTE *)((v5 >> 3) + v12);
    *a2 = v5;
    *(_BYTE *)((v5 >> 3) + v12) = v13 & ~(unsigned __int8)(1 << (v5 & 7));
    --*(_DWORD *)(a1 + 128);
    result = 0;
  }
  return result;
}
