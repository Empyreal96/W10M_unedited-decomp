// -BTreeSplitChild@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@@Z 
 
_BYTE *__fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSplitChild(int a1, _DWORD *a2)
{
  unsigned __int8 *v3; // r7
  unsigned __int16 **v4; // r8
  unsigned __int16 *v5; // r4
  _BYTE *v6; // r0
  _BYTE *v7; // r5
  int v8; // r9
  unsigned __int16 *v9; // r1
  int v10; // r3
  int *v11; // r8
  int v12; // r10
  _DWORD **v13; // r3
  int v14; // r2
  _DWORD **v15; // r3
  _BYTE *v16; // r0
  _DWORD *v17; // r8
  struct NP_CONTEXT::NP_CTX *v18; // r0
  int v19; // r2
  int v20; // r2
  int v21; // r3
  _BYTE *v24; // [sp+4h] [bp-34h]
  unsigned __int8 **v25; // [sp+8h] [bp-30h]
  int v26; // [sp+10h] [bp-28h] BYREF
  _BYTE *v27; // [sp+14h] [bp-24h]

  v24 = 0;
  v3 = 0;
  v4 = (unsigned __int16 **)(*a2 + 8 * a2[3] - 8);
  v5 = *v4;
  v25 = (unsigned __int8 **)v4;
  v6 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(
         a1,
         *((_BYTE *)*v4 + 3),
         *((_BYTE *)*v4 + 2));
  v7 = v6;
  if ( !v6 )
    return v24;
  v26 = 0;
  v27 = v6;
  v8 = (unsigned __int16)*(_DWORD *)v5 >> 1;
  if ( *((_BYTE *)v5 + 3) )
  {
    v9 = &v5[8 * v8 + 4];
    if ( (*(_DWORD *)v5 & 1) != 0 && &v5[8 * v8 + 12] < v4[1] )
      v9 = &v5[8 * v8++ + 12];
    v10 = *(_DWORD *)v9;
    v11 = 0;
  }
  else
  {
    v11 = (int *)&v5[4 * v8 + 4];
    v10 = *v11;
    v9 = 0;
  }
  v26 = v10;
  v12 = *v5 - v8;
  if ( *((_BYTE *)v5 + 3) )
  {
    v13 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v13 = 0;
    if ( **v13 == -1 )
      v14 = *((_DWORD *)v5 + 1);
    else
      v14 = 3358;
    v15 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v15 = 0;
    if ( **v15 == -1 )
      *((_DWORD *)v6 + 1) = v14;
    memmove((int)(v6 + 8), (int)v9, 16 * v12);
  }
  else
  {
    --v12;
    memmove((int)(v6 + 8), (int)(v11 + 2), 8 * v12);
    *((_DWORD *)v7 + 1) = v11[1];
  }
  *(_WORD *)v7 = v12;
  if ( *(unsigned __int16 **)a1 == v5 )
  {
    v16 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(
            a1,
            0,
            *((_BYTE *)v5 + 2) + 1);
    v3 = v16;
    if ( v16 )
    {
      *((_DWORD *)v16 + 1) = v5;
      *((_DWORD *)v16 + 2) = v26;
      *((_DWORD *)v16 + 3) = v27;
      *(_WORD *)v16 = 1;
      *(_DWORD *)a1 = v16;
      if ( *((_BYTE *)v5 + 3) && **(_DWORD **)(a1 + 8) != -1 )
      {
        *((_DWORD *)v16 + 1) |= 1u;
        NP_CONTEXT::NpGetResidentLeaf((struct NP_CONTEXT::NP_CTX *)v16, (union _NP_LEAF_PTR *)(v16 + 4));
      }
      v17 = a2;
      v18 = (struct NP_CONTEXT::NP_CTX *)memmove((int)(v25 + 2), (int)v25, 8 * (a2[4] - 1));
      *v25 = v3;
      v25[1] = v3 + 8;
      v19 = a2[3] + 1;
      a2[3] = v19;
      v3 = 0;
      goto LABEL_27;
    }
  }
  else
  {
    v17 = a2;
    --a2[3];
    v18 = (struct NP_CONTEXT::NP_CTX *)B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(
                                         a1,
                                         (int)a2,
                                         &v26);
    v19 = a2[3] + 1;
    a2[3] = v19;
    if ( (int)v18 >= 0 )
    {
LABEL_27:
      if ( *((_BYTE *)v5 + 3) )
      {
        v20 = *(_DWORD *)(*v17 + 8 * v19 - 12);
        if ( **(_DWORD **)(a1 + 8) != -1 )
        {
          *(_DWORD *)(v20 + 4) |= 1u;
          NP_CONTEXT::NpGetResidentLeaf(v18, (union _NP_LEAF_PTR *)(v20 + 4));
        }
      }
      v21 = *((unsigned __int8 *)v5 + 3);
      *v5 = v8;
      if ( v21 && **(_DWORD **)(a1 + 8) == -1 )
        *((_DWORD *)v5 + 1) = v7;
      v24 = v7;
      v7 = 0;
      goto LABEL_34;
    }
  }
LABEL_34:
  if ( v7 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v7);
  if ( v3 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v3);
  return v24;
}
