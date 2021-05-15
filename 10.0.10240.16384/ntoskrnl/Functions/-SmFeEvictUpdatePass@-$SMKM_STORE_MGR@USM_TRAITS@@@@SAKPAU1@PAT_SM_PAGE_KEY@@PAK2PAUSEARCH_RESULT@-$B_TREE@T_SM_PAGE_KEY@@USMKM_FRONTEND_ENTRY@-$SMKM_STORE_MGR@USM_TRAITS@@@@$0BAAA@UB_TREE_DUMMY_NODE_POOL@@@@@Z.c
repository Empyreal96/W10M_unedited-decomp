// -SmFeEvictUpdatePass@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAKPAU1@PAT_SM_PAGE_KEY@@PAK2PAUSEARCH_RESULT@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@@Z 
 
int __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmFeEvictUpdatePass(int a1, unsigned int *a2, int *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v5; // r10
  int v6; // r9
  unsigned int v7; // r6
  int v8; // r7
  int v9; // r4
  int v10; // r8
  unsigned __int16 *v11; // r1
  int v12; // r2
  unsigned int v13; // r5
  unsigned int v14; // r2
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r3
  unsigned int v18; // r2
  _DWORD *v19; // r9
  unsigned int *v20; // r6
  unsigned int v21; // r0
  unsigned int v22; // r1
  int v23; // r3
  unsigned int v24; // r0
  unsigned int v25; // r1
  int result; // r0
  int v27; // [sp+0h] [bp-40h]
  unsigned int v28; // [sp+4h] [bp-3Ch]
  unsigned int v29; // [sp+8h] [bp-38h] BYREF
  int v30; // [sp+Ch] [bp-34h]
  unsigned int v31; // [sp+10h] [bp-30h]
  int v32; // [sp+14h] [bp-2Ch]
  int *v33; // [sp+18h] [bp-28h]
  _DWORD *v34; // [sp+1Ch] [bp-24h]

  v5 = *a2;
  v6 = *a3;
  v33 = a3;
  v34 = a4;
  v7 = v5 + v6 - 1;
  v8 = 0;
  v9 = 0;
  v31 = v7;
  v32 = v6;
  v10 = 32;
  B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeIteratorFromSearchResult(
    a1,
    &v29,
    a5);
  v11 = (unsigned __int16 *)v29;
  v12 = v30;
  v27 = v30;
  v28 = v29;
  while ( 1 )
  {
    if ( !v11 )
    {
      v13 = 0;
LABEL_4:
      v14 = v7;
      v15 = 1;
      goto LABEL_5;
    }
    v16 = v12 + 8;
    v27 = v16;
    if ( v16 >= (unsigned int)&v11[4 * *v11 + 4] )
    {
      v17 = *((_DWORD *)v11 + 1);
      if ( v17 )
      {
        v13 = v17 + 8;
        v27 = v17 + 8;
        v28 = *((_DWORD *)v11 + 1);
      }
      else
      {
        v13 = 0;
      }
    }
    else
    {
      v13 = v16;
    }
    if ( !v13 )
      goto LABEL_4;
    v14 = *(_DWORD *)v13;
    if ( v5 < *(_DWORD *)v13 || (*(_BYTE *)(v13 + 7) & 1) != 0 )
      break;
LABEL_8:
    if ( v10 != 32 && v10 != *(unsigned __int16 *)(v13 + 4) )
      goto LABEL_47;
    if ( *(_BYTE *)(v13 + 6) != 2 )
    {
      if ( v8 )
      {
        if ( v10 == 32 )
          goto LABEL_47;
LABEL_42:
        *(_BYTE *)(v13 + 6) = 2;
        goto LABEL_43;
      }
      v18 = *(unsigned __int16 *)(v13 + 4);
      if ( v18 >= 0x20 )
        goto LABEL_46;
      v29 = v18 | (32 * (SmGlobals[24 * v18 + 3] & 0x7FF));
      v19 = &SmGlobals[24 * (v29 & 0x1F)];
      v20 = v19 + 1;
      __pld(v19 + 1);
      v21 = v19[1] & 0xFFFFFFFE;
      do
        v22 = __ldrex(v20);
      while ( v22 == v21 && __strex(v21 + 2, v20) );
      __dmb(0xBu);
      if ( v22 == v21 || ExfAcquireRundownProtection(v19 + 1) )
      {
        if ( (v19[3] & 0x7FF) == v29 >> 5 )
        {
          v23 = *v19;
LABEL_40:
          if ( !v23 )
            goto LABEL_46;
          v10 = *(unsigned __int16 *)(v13 + 4);
          v7 = v31;
          v6 = v32;
          goto LABEL_42;
        }
        __pld(v20);
        v24 = *v20 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v25 = __ldrex(v20);
        while ( v25 == v24 && __strex(v24 - 2, v20) );
        if ( v25 != v24 )
          ExfReleaseRundownProtection((unsigned __int8 *)v19 + 4);
      }
      v23 = 0;
      goto LABEL_40;
    }
    if ( v10 != 32 )
      goto LABEL_47;
LABEL_43:
    ++v8;
    ++v9;
    if ( v8 == v6 )
      goto LABEL_47;
    v12 = v27;
    v11 = (unsigned __int16 *)v28;
    ++v5;
  }
  if ( v7 < v14 )
    goto LABEL_4;
  v15 = 0;
LABEL_5:
  v9 += v14 - v5;
  if ( !v8 )
  {
    if ( v15 )
      goto LABEL_46;
    v8 = v14 - v5;
    v5 = v14;
    if ( (*(_BYTE *)(v13 + 7) & 1) != 0 )
      goto LABEL_43;
    goto LABEL_8;
  }
  if ( !v15 )
    goto LABEL_47;
LABEL_46:
  ++v9;
LABEL_47:
  result = v10;
  *v33 = v8;
  *v34 = v9;
  return result;
}
