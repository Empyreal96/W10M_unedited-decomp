// -BTreeSplitChild@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@@Z 
 
_BYTE *__fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSplitChild(int a1, _DWORD *a2)
{
  unsigned __int8 *v3; // r7
  unsigned __int16 **v4; // r8
  unsigned __int16 *v5; // r4
  _BYTE *v6; // r0
  _BYTE *v7; // r5
  int v8; // r9
  int v9; // r3
  int *v10; // r1
  int v11; // r3
  int *v12; // r8
  int v13; // r10
  _DWORD **v14; // r3
  int v15; // r2
  _DWORD **v16; // r3
  _BYTE *v17; // r0
  _DWORD *v18; // r8
  struct NP_CONTEXT::NP_CTX *v19; // r0
  int v20; // r2
  int v21; // r2
  int v22; // r3
  _BYTE *v25; // [sp+4h] [bp-34h]
  unsigned __int8 **v26; // [sp+8h] [bp-30h]
  int v27; // [sp+10h] [bp-28h] BYREF
  _BYTE *v28; // [sp+14h] [bp-24h]

  v25 = 0;
  v3 = 0;
  v4 = (unsigned __int16 **)(*a2 + 8 * a2[3] - 8);
  v5 = *v4;
  v26 = (unsigned __int8 **)v4;
  v6 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(
         a1,
         *((_BYTE *)*v4 + 3),
         *((_BYTE *)*v4 + 2));
  v7 = v6;
  if ( !v6 )
    return v25;
  v27 = 0;
  v28 = v6;
  v8 = (unsigned __int16)*(_DWORD *)v5 >> 1;
  v9 = v8 + 1;
  if ( *((_BYTE *)v5 + 3) )
  {
    v10 = (int *)&v5[4 * v9];
    if ( (*(_DWORD *)v5 & 1) != 0 && v10 + 2 < (int *)v4[1] )
    {
      v10 += 2;
      ++v8;
    }
    v11 = *v10;
    v12 = 0;
  }
  else
  {
    v12 = (int *)&v5[4 * v9];
    v11 = *v12;
    v10 = 0;
  }
  v27 = v11;
  v13 = *v5 - v8;
  if ( *((_BYTE *)v5 + 3) )
  {
    v14 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v14 = 0;
    if ( **v14 == -1 )
      v15 = *((_DWORD *)v5 + 1);
    else
      v15 = 3358;
    v16 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v16 = 0;
    if ( **v16 == -1 )
      *((_DWORD *)v6 + 1) = v15;
    memmove((int)(v6 + 8), (int)v10, 8 * v13);
  }
  else
  {
    --v13;
    memmove((int)(v6 + 8), (int)(v12 + 2), 8 * v13);
    *((_DWORD *)v7 + 1) = v12[1];
  }
  *(_WORD *)v7 = v13;
  if ( *(unsigned __int16 **)a1 == v5 )
  {
    v17 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(
            a1,
            0,
            *((_BYTE *)v5 + 2) + 1);
    v3 = v17;
    if ( v17 )
    {
      *((_DWORD *)v17 + 1) = v5;
      *((_DWORD *)v17 + 2) = v27;
      *((_DWORD *)v17 + 3) = v28;
      *(_WORD *)v17 = 1;
      *(_DWORD *)a1 = v17;
      if ( *((_BYTE *)v5 + 3) && **(_DWORD **)(a1 + 8) != -1 )
      {
        *((_DWORD *)v17 + 1) |= 1u;
        NP_CONTEXT::NpGetResidentLeaf((struct NP_CONTEXT::NP_CTX *)v17, (union _NP_LEAF_PTR *)(v17 + 4));
      }
      v18 = a2;
      v19 = (struct NP_CONTEXT::NP_CTX *)memmove((int)(v26 + 2), (int)v26, 8 * (a2[4] - 1));
      *v26 = v3;
      v26[1] = v3 + 8;
      v20 = a2[3] + 1;
      a2[3] = v20;
      v3 = 0;
      goto LABEL_27;
    }
  }
  else
  {
    v18 = a2;
    --a2[3];
    v19 = (struct NP_CONTEXT::NP_CTX *)B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(
                                         a1,
                                         (int **)a2,
                                         &v27);
    v20 = a2[3] + 1;
    a2[3] = v20;
    if ( (int)v19 >= 0 )
    {
LABEL_27:
      if ( *((_BYTE *)v5 + 3) )
      {
        v21 = *(_DWORD *)(*v18 + 8 * v20 - 12);
        if ( **(_DWORD **)(a1 + 8) != -1 )
        {
          *(_DWORD *)(v21 + 4) |= 1u;
          NP_CONTEXT::NpGetResidentLeaf(v19, (union _NP_LEAF_PTR *)(v21 + 4));
        }
      }
      v22 = *((unsigned __int8 *)v5 + 3);
      *v5 = v8;
      if ( v22 && **(_DWORD **)(a1 + 8) == -1 )
        *((_DWORD *)v5 + 1) = v7;
      v25 = v7;
      v7 = 0;
      goto LABEL_34;
    }
  }
LABEL_34:
  if ( v7 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v7);
  if ( v3 )
    B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v3);
  return v25;
}
