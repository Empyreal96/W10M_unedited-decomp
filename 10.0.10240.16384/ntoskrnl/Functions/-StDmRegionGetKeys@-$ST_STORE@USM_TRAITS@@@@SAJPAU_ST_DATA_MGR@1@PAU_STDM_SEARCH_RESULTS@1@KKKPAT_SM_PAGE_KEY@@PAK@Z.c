// -StDmRegionGetKeys@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@PAU_STDM_SEARCH_RESULTS@1@KKKPAT_SM_PAGE_KEY@@PAK@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmRegionGetKeys(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, _DWORD *a7)
{
  _DWORD *v8; // r4
  _DWORD *v9; // r10
  _DWORD *v10; // r5
  int v11; // r6
  int result; // r0
  int v13; // r2
  int v14; // r3
  int v15; // r2
  int v16; // r6
  unsigned __int16 *v17; // r1
  __int64 v18; // r2
  unsigned __int16 *v19; // r0
  int v20; // r2
  int v21; // r0

  v8 = *(_DWORD **)(a2 + 4);
  v9 = &a6[*a7];
  v10 = a6;
  v11 = a3 << *(_DWORD *)(a1 + 100);
  if ( (v8[5] & 1) == 0 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
      a1 + 36,
      *(_DWORD *)(a2 + 4));
  v8[5] |= 1u;
  result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
             (unsigned __int16 **)(a1 + 36),
             v11 | (a5 - 1),
             (int)v8);
  if ( result != -1073741818 )
  {
    if ( !result )
    {
      v13 = v8[3];
      if ( v13 == -1 || !v13 )
        v14 = (int)(v8 + 1);
      else
        v14 = *v8 + 8 * v13 - 8;
      v10 = a6 + 1;
      *a6 = *(_DWORD *)(*(_DWORD *)(v14 + 4) + 4);
    }
    while ( 1 )
    {
      if ( v10 >= v9 || (v15 = v8[3]) == 0 )
      {
LABEL_20:
        *a7 = v10 - a6;
        return 0;
      }
      v16 = *v8 + 8 * v15;
      v18 = *(_QWORD *)(v16 - 8);
      v17 = (unsigned __int16 *)(HIDWORD(v18) - 8);
      HIDWORD(v18) = v18 + 8;
      *(_DWORD *)(v16 - 4) = v17;
      if ( (unsigned int)v17 < (int)v18 + 8 )
      {
        LODWORD(v18) = 2;
        *(_DWORD *)(v16 - 4) = HIDWORD(v18);
        v19 = (unsigned __int16 *)B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSiblingEx(
                                    a1 + 36,
                                    v8,
                                    v18);
        if ( !v19 )
          goto LABEL_20;
        if ( v19 == (unsigned __int16 *)-1 )
          return -1073741818;
        v17 = &v19[4 * *v19];
        *(_DWORD *)(v16 - 4) = v17;
      }
      if ( v17 == (unsigned __int16 *)-1 )
        return -1073741818;
      if ( v17 )
      {
        v20 = *(_DWORD *)v17;
        v21 = *(_DWORD *)(a1 + 96);
        if ( *(_DWORD *)v17 >> *(_DWORD *)(a1 + 100) == a3 )
        {
          *v10++ = *((_DWORD *)v17 + 1);
          if ( (v21 & v20) != 0 )
            continue;
        }
      }
      goto LABEL_20;
    }
  }
  return result;
}
