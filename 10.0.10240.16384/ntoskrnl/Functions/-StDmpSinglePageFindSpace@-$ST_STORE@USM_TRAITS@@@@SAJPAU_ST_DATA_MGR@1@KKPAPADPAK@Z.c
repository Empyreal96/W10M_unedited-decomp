// -StDmpSinglePageFindSpace@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@KKPAPADPAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmpSinglePageFindSpace(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  _DWORD *v5; // r5
  int v9; // r1
  int result; // r0
  int v11; // r0
  __int64 v12; // kr00_8
  int v13; // r2

  v5 = (_DWORD *)(a1 + 12 * a2);
  if ( v5[98] == -1 || (unsigned int)(v5[99] + a3) > *(_DWORD *)(a1 + 104) )
  {
    if ( !*(_BYTE *)(a1 + 72) )
    {
      if ( v5[98] != -1 )
      {
        ST_STORE<SM_TRAITS>::StUnlockAndUnmapRegion(a1);
        v9 = v5[98];
        if ( (*(_WORD *)(*(_DWORD *)(a1 + 304) + 2 * v9) & 0x1FFF) == 0 )
          ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v9);
      }
      v5[99] = -1;
      v5[100] = 0;
      v5[98] = -1;
    }
    while ( 1 )
    {
      v11 = ST_STORE<SM_TRAITS>::StDmCurrentRegionFind(a1);
      if ( v11 == -1 )
        break;
      result = ST_STORE<SM_TRAITS>::StDmCurrentRegionSet(a1, a2, v11);
      if ( result >= 0 )
        goto LABEL_13;
      if ( result != -1073741267 )
        return result;
    }
    result = -1073741697;
  }
  else
  {
LABEL_13:
    v12 = *(_QWORD *)(v5 + 99);
    v13 = v5[98];
    result = 0;
    *a4 = HIDWORD(v12) + 16 * v12;
    *a5 = (v13 << *(_DWORD *)(a1 + 100)) | v12;
  }
  return result;
}
