// -StDmCleanup@-$ST_STORE@USM_TRAITS@@@@SAXPAU_ST_DATA_MGR@1@K@Z 
 
unsigned int __fastcall ST_STORE<SM_TRAITS>::StDmCleanup(int a1, int a2)
{
  int v2; // r6
  unsigned int result; // r0
  _DWORD **v5; // r5
  _DWORD *v6; // r2
  _DWORD **v7; // r5
  _DWORD *v8; // r2
  int v9; // r5
  int v10; // r1
  int v11; // r3
  int v12; // r8
  _DWORD *v13; // r5
  int v14; // r7
  int v15; // r0
  int v16; // r0
  int v17; // r0
  _DWORD *v18; // r0
  bool v19; // zf
  _DWORD *v20; // r0
  unsigned int v21; // lr
  unsigned int v22; // r7
  int v23; // r6
  _DWORD *v24; // r8
  int i; // r3
  unsigned int v26; // r3
  int v27; // r0
  unsigned int j; // r5

  v2 = a2;
  B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
  if ( *(_DWORD *)(a1 + 24) != -1 && *(_DWORD *)(a1 + 12) )
    return sub_511420();
  if ( *(_DWORD *)a1 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFree(a1);
  result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
             a1 + 36,
             a1 + 48);
  if ( *(_DWORD *)(a1 + 60) != -1 )
  {
    result = *(_DWORD *)(a1 + 48);
    if ( result )
    {
      if ( !v2 )
        result = ExFreePoolWithTag(result, 0);
    }
  }
  if ( *(_DWORD *)(a1 + 36) )
    result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFree(a1 + 36);
  if ( v2 )
  {
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 4) = 0;
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 36) = 0;
    *(_DWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 44) = 0;
    *(_DWORD *)(a1 + 8) = a1 + 488;
    *(_DWORD *)(a1 + 44) = a1 + 576;
  }
  else
  {
    v5 = (_DWORD **)(a1 + 532);
    while ( 1 )
    {
      v6 = *(_DWORD **)(a1 + 536);
      if ( v6 == v5 )
        break;
      v18 = *v5;
      v19 = *v5 == v6;
      *v5 = (_DWORD *)**v5;
      if ( v19 )
      {
        *v5 = 0;
        *(_DWORD *)(a1 + 536) = a1 + 532;
      }
      else
      {
        --*v6;
      }
      result = ExFreePoolWithTag(v18, 0);
    }
    v7 = (_DWORD **)(a1 + 620);
    while ( 1 )
    {
      v8 = *(_DWORD **)(a1 + 624);
      if ( v8 == v7 )
        break;
      v20 = *v7;
      v19 = *v7 == v8;
      *v7 = (_DWORD *)**v7;
      if ( v19 )
      {
        *v7 = 0;
        *(_DWORD *)(a1 + 624) = a1 + 620;
      }
      else
      {
        --*v8;
      }
      result = ExFreePoolWithTag(v20, 0);
    }
  }
  if ( *(_DWORD *)(a1 + 304) )
  {
    result = ST_STORE<SM_TRAITS>::StDmInvalidateCurrentRegions(a1);
    v9 = -1;
    while ( 1 )
    {
      if ( *(_BYTE *)(a1 + 72) )
      {
        v21 = *(_DWORD *)(a1 + 120);
        v22 = v9 + 1 < v21 ? v9 + 1 : 0;
        v23 = *(_DWORD *)(a1 + 124);
        result = v21 - 1;
        while ( 1 )
        {
          if ( result - v22 == -1 )
            goto LABEL_61;
          v24 = (_DWORD *)(v23 + 4 * (v22 >> 5));
          for ( i = ~*v24 | ((1 << (v22 & 0x1F)) - 1); i == -1; i = ~*v24 )
          {
            if ( (unsigned int)++v24 > v23 + 4 * (result >> 5) )
              goto LABEL_61;
          }
          v26 = __clz(__rbit(~i)) + 32 * (((int)v24 - v23) >> 2);
          if ( v26 > result )
          {
LABEL_61:
            v26 = -1;
          }
          else if ( v26 != -1 )
          {
            break;
          }
          if ( !v22 )
            break;
          v27 = v9 + 2;
          if ( v9 + 2 > v21 )
            v27 = *(_DWORD *)(a1 + 120);
          result = v27 - 1;
          v22 = 0;
        }
        if ( (int)v26 <= v9 )
          v26 = *(_DWORD *)(a1 + 84);
        v9 = v26;
      }
      else
      {
        ++v9;
      }
      if ( v9 == *(_DWORD *)(a1 + 84) )
        break;
      v10 = *(_DWORD *)(a1 + 304);
      if ( (*(_WORD *)(v10 + 2 * v9) & 0x1FFF) != 0 )
      {
        v11 = *(_WORD *)(v10 + 2 * v9) & 0x1FFF;
        if ( *(_BYTE *)(a1 + 72) )
          result = 0;
        else
          result = *(unsigned __int16 *)(v10 + 2 * v9) >> 13;
        *(_WORD *)(v10 + 2 * v9) -= v11;
        *(_DWORD *)(a1 + 8 * result + 688) -= v11;
        if ( (*(_WORD *)(v10 + 2 * v9) & 0x1FFF) == 0 && v9 != *(_DWORD *)(a1 + 12 * result + 392) )
          result = ST_STORE<SM_TRAITS>::StReleaseRegion(a1, v9);
      }
    }
    v2 = a2;
    if ( (*(_DWORD *)(a1 + 72) & 0x40000) != 0 && !a2 )
    {
      result = RtlNumberOfClearBits(a1 + 120);
      if ( result )
        result = ST_STORE<SM_TRAITS>::StDmLazyRegionsWorker(a1, 1);
    }
    v12 = *(_DWORD *)(a1 + 304);
    v13 = (_DWORD *)(a1 + 320);
    v14 = 6;
    while ( a2 )
    {
      if ( *v13 == -1 )
        goto LABEL_30;
      if ( (*(_WORD *)(v12 + 2 * *v13) & 0xC000) == 0 )
        break;
LABEL_32:
      v13 += 3;
      if ( !--v14 )
        goto LABEL_33;
    }
    if ( *v13 != -1 )
    {
      ExFreePoolWithTag(v13[1], 0);
      result = ExFreePoolWithTag(v13[2], 0);
    }
LABEL_30:
    if ( a2 )
    {
      *v13 = 0;
      v13[1] = 0;
      v13[2] = 0;
      *v13 = -1;
    }
    goto LABEL_32;
  }
LABEL_33:
  if ( !v2 )
  {
    v15 = *(_DWORD *)(a1 + 124);
    if ( v15 )
      ExFreePoolWithTag(v15, 0);
    v16 = *(_DWORD *)(a1 + 668);
    if ( v16 )
      ExFreePoolWithTag(v16, 0);
    v17 = *(_DWORD *)(a1 + 672);
    if ( v17 )
      ExFreePoolWithTag(v17, 0);
    result = *(_DWORD *)(a1 + 676);
    if ( result )
      result = ExFreePoolWithTag(result, 0);
    if ( *(_DWORD *)(a1 + 164) )
    {
      for ( j = 0; j < *(_DWORD *)(a1 + 188); ++j )
      {
        result = *(_DWORD *)(*(_DWORD *)(a1 + 164) + 4 * j);
        if ( result )
          result = (*(int (**)(void))(a1 + 180))();
      }
      if ( (*(_DWORD *)(a1 + 208) & 2) == 0 )
        result = (*(int (__fastcall **)(_DWORD))(a1 + 180))(*(_DWORD *)(a1 + 164));
    }
  }
  return result;
}
