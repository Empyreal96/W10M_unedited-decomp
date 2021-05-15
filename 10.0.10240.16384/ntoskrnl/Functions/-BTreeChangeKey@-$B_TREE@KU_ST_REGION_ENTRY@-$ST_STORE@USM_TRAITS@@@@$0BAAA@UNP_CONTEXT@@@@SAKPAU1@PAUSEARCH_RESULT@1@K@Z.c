// -BTreeChangeKey@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAKPAU1@PAUSEARCH_RESULT@1@K@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeChangeKey(int a1, int a2, unsigned int *a3, int a4)
{
  __int64 v5; // kr00_8
  unsigned int *v7; // r8
  bool v8; // cf
  int v9; // r4
  unsigned int *v10; // r9
  _DWORD **v11; // r3
  _DWORD **v12; // r3
  int v13; // r3
  unsigned int v14; // r3
  int v15; // r1
  void **v16; // r1
  struct NP_CONTEXT::NP_CTX *v17; // r0
  unsigned __int16 *v18; // r0
  int v19; // r7
  unsigned int *v20; // r2
  struct NP_CONTEXT::NP_CTX *v21; // r0
  void **v23; // [sp+0h] [bp-28h] BYREF
  unsigned int *v24; // [sp+4h] [bp-24h]
  int v25; // [sp+8h] [bp-20h]

  v23 = (void **)a2;
  v24 = a3;
  v25 = a4;
  v5 = *(_QWORD *)(*(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 12) - 8);
  v7 = (unsigned int *)*(_DWORD *)HIDWORD(v5);
  if ( *(_DWORD *)HIDWORD(v5) >= (unsigned int)a3 )
  {
    if ( HIDWORD(v5) > (unsigned int)(v5 + 8) )
    {
      v8 = *(_DWORD *)(HIDWORD(v5) - 8) >= (unsigned int)a3;
LABEL_4:
      if ( !v8 )
        goto LABEL_46;
      return 0;
    }
  }
  else if ( HIDWORD(v5) < (unsigned int)v5 + 8 * *(unsigned __int16 *)v5 )
  {
    v8 = (unsigned int)a3 >= *(_DWORD *)(HIDWORD(v5) + 8);
    goto LABEL_4;
  }
  if ( !B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
          a2,
          v7 < a3,
          &v23) )
    goto LABEL_46;
  v10 = v24;
  if ( v7 >= a3 )
  {
    if ( v7 != a3 )
      goto LABEL_12;
    *v24 = (unsigned int)a3;
LABEL_46:
    *(_DWORD *)HIDWORD(v5) = a3;
    return 1;
  }
  if ( (unsigned int)a3 < *v24 )
    goto LABEL_46;
LABEL_12:
  v9 = -1;
  if ( v7 > a3 )
    goto LABEL_28;
  if ( a1 )
    v11 = (_DWORD **)(a1 + 8);
  else
    v11 = 0;
  if ( **v11 == -1 )
  {
    v12 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v12 = 0;
    if ( **v12 == -1 )
      v13 = *(_DWORD *)(v5 + 4);
    else
      v13 = 3358;
    v14 = *(_DWORD *)(v13 + 8);
    if ( (unsigned int)a3 < v14 )
    {
      *v24 = v14;
      goto LABEL_46;
    }
    return 0;
  }
  if ( v7 >= a3 )
LABEL_28:
    v15 = 0;
  else
    v15 = 1;
  v16 = (void **)B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(
                   &v23,
                   v15,
                   0);
  v23 = v16;
  v17 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
  if ( !a1 )
    v17 = 0;
  if ( **(_DWORD **)v17 == -1 )
  {
    v18 = (unsigned __int16 *)*v16;
  }
  else
  {
    v18 = (unsigned __int16 *)NP_CONTEXT::NpLeafRefInternal(v17, v16, 0);
    v16 = v23;
  }
  if ( v18 )
  {
    v19 = 0;
    v20 = (unsigned int *)(v18 + 4);
    if ( a3 >= v7 )
    {
      if ( (unsigned int)a3 >= *v20 )
        goto LABEL_41;
      *v10 = *v20;
    }
    else
    {
      if ( *(_DWORD *)&v18[4 * *v18] >= (unsigned int)a3 )
        goto LABEL_41;
      *v10 = (unsigned int)a3;
    }
    v19 = 1;
LABEL_41:
    v21 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    if ( !a1 )
      v21 = 0;
    if ( **(_DWORD **)v21 != -1 )
      NP_CONTEXT::NpLeafDerefInternal(v21, v16);
    if ( v19 )
      goto LABEL_46;
    return 0;
  }
  return v9;
}
