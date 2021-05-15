// -StDmGetStatsBitmap@-$ST_STORE@USM_TRAITS@@@@SAJPAU_ST_DATA_MGR@1@KPAEPA_K@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDmGetStatsBitmap(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v5; // r4
  int v7; // r3
  int v8; // r0
  int v9; // r4
  unsigned int v10; // r8
  unsigned __int16 *v11; // r9
  int v12; // r3
  unsigned int v13; // r3
  _DWORD **v14; // r3
  unsigned int **v15; // r3
  int v16; // r0
  int v17; // r6
  int v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r2
  int v22; // r3
  unsigned int v23; // r3
  int v24; // r4
  unsigned int v25; // r0
  unsigned int v26; // r1
  int v27; // r2
  char v28; // r3
  __int64 v30; // [sp+0h] [bp-38h]
  unsigned __int16 *v33; // [sp+10h] [bp-28h] BYREF
  int v34; // [sp+14h] [bp-24h]

  v5 = *(_DWORD *)(a1 + 128);
  v7 = 0;
  v8 = 0;
  v30 = 0i64;
  v33 = 0;
  v34 = 0;
  if ( v5 )
  {
    if ( (*(_DWORD *)(a1 + 32) & 1) == 0 )
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(a1, a1 + 12);
    *(_DWORD *)(a1 + 32) |= 1u;
    if ( (*(_DWORD *)(a1 + 68) & 1) == 0 )
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
        a1 + 36,
        a1 + 48);
    *(_DWORD *)(a1 + 68) |= 1u;
    v9 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
           (unsigned __int16 **)(a1 + 36),
           0,
           a1 + 48);
    if ( v9 != -1073741818 )
    {
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorFromSearchResult(
        a1 + 36,
        &v33,
        a1 + 48);
      v11 = v33;
      v10 = v34;
      while ( 1 )
      {
        if ( !v11 )
        {
LABEL_42:
          v8 = HIDWORD(v30);
          v7 = v30;
          goto LABEL_43;
        }
        v12 = *v11;
        v10 += 8;
        v34 = v10;
        v13 = (unsigned int)&v11[4 * v12 + 4];
        if ( v10 >= v13 )
        {
          v14 = (_DWORD **)(a1 + 44);
          if ( a1 == -36 )
            v14 = 0;
          if ( **v14 == -1 )
          {
            v15 = (unsigned int **)(a1 + 44);
            if ( a1 == -36 )
              v15 = 0;
            v13 = **v15;
            if ( v13 == -1 )
              v16 = *((_DWORD *)v11 + 1);
            else
              v16 = 3358;
          }
          else
          {
            v16 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSibling(
                    a1 + 36,
                    v11);
            if ( v16 == -1 )
            {
              v17 = -1;
              goto LABEL_24;
            }
          }
          if ( !v16 )
          {
            v17 = 0;
            goto LABEL_24;
          }
          v10 = v16 + 8;
          v33 = (unsigned __int16 *)v16;
          v34 = v16 + 8;
          v11 = (unsigned __int16 *)v16;
        }
        v17 = v10;
LABEL_24:
        if ( !v17 )
          goto LABEL_42;
        if ( v17 == -1 )
        {
          v9 = -1073741818;
          break;
        }
        v9 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
               (unsigned __int16 **)a1,
               *(_DWORD *)(v17 + 4),
               a1 + 12,
               v13);
        if ( v9 == -1073741818 )
          break;
        v18 = *(_DWORD *)(a1 + 24);
        if ( v18 == -1 || !v18 )
          v19 = a1 + 16;
        else
          v19 = *(_DWORD *)(a1 + 12) + 8 * v18 - 8;
        v20 = *(_DWORD *)(v19 + 4);
        v21 = *(_DWORD *)(v20 + 8) & 0xFFF;
        if ( v21 )
          v22 = *(_DWORD *)(v20 + 8) & 0xFFF;
        else
          v22 = 4096;
        v30 += (unsigned int)v22;
        if ( !v21 )
          v21 = 4096;
        v23 = *(_DWORD *)(a1 + 112) + v21 + 15;
        v24 = v23 >> 4;
        if ( !a2 )
          __brkdiv0();
        v25 = *(_DWORD *)v17 / a2;
        if ( v23 >> 4 )
        {
          do
          {
            v26 = v25 >> 3;
            v27 = 1 << (v25 & 7);
            v28 = *(_BYTE *)((v25 >> 3) + a3);
            v24 -= a2;
            ++v25;
            *(_BYTE *)(v26 + a3) = v28 | v27;
          }
          while ( v24 > 0 );
        }
      }
    }
  }
  else
  {
LABEL_43:
    *a4 = v7;
    a4[1] = v8;
    v9 = 0;
  }
  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeIteratorCleanup(&v33, a1 + 36);
  return v9;
}
