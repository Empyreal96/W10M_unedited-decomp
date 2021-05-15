// -BTreeInsertEx@-$B_TREE@T_SM_PAGE_KEY@@USMKM_FRONTEND_ENTRY@-$SMKM_STORE_MGR@USM_TRAITS@@@@$0BAAA@UB_TREE_DUMMY_NODE_POOL@@@@SAJPAU1@PAUSEARCH_RESULT@1@PAT_SM_PAGE_KEY@@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeInsertEx(unsigned int *a1, unsigned int **a2, _DWORD *a3)
{
  unsigned int v6; // r0
  __int64 v7; // kr00_8
  unsigned int *v8; // r6
  char *v9; // r5
  int v10; // r4
  int v11; // r0
  int v12; // r3
  unsigned __int16 *v13; // r1
  unsigned int v14; // r3
  char *v15; // r2
  int v17; // r3
  unsigned __int16 *v18; // r4
  int v19; // r3
  int v20; // r0

  if ( *a1 )
    v6 = *(unsigned __int8 *)(*a1 + 2);
  else
    v6 = 0;
  v7 = *(_QWORD *)(a2 + 3);
  if ( HIDWORD(v7) <= v6 )
  {
    v6 = SmArrayGrow();
    if ( !v6 )
      return -1073741670;
  }
  if ( (_DWORD)v7 )
  {
    v8 = &(*a2)[2 * v7 - 2];
  }
  else
  {
    v6 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeNewNode();
    *a1 = v6;
    if ( !v6 )
      return -1073741670;
    v8 = *a2;
    *v8 = v6;
    v8[1] = *a1 + 8;
    a2[3] = (unsigned int *)((char *)a2[3] + 1);
  }
  v9 = (char *)*v8;
  if ( *(unsigned __int16 *)*v8 >= 0x1FFu )
  {
    v10 = (int)(v8[1] - (_DWORD)v9 - 8) >> 3;
    if ( v9 == (char *)*a1 )
    {
      v13 = 0;
      v11 = 0;
    }
    else
    {
      v11 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeRedistribute(v6);
      v12 = *(v8 - 1);
      if ( (v11 & 1) != 0 )
        v13 = (unsigned __int16 *)(v12 - 8);
      else
        v13 = (unsigned __int16 *)(v12 + 8);
    }
    v14 = *(unsigned __int16 *)v9;
    if ( v14 < 0x1FF )
    {
      if ( (v11 & 1) != 0 )
      {
        v10 = v14 + v10 - 511;
        v15 = (char *)(v11 & 0xFFFFFFFE);
        if ( v9[3] )
        {
          if ( v10 > 0 )
            goto LABEL_24;
          v10 += (unsigned __int16)*(_DWORD *)v15;
        }
        else
        {
          if ( v10 >= 0 )
            goto LABEL_24;
          v10 += (unsigned __int16)*(_DWORD *)v15 + 1;
        }
        v9 = (char *)(v11 & 0xFFFFFFFE);
LABEL_24:
        if ( v9 == v15 )
          *(v8 - 1) = (unsigned int)v13;
        goto LABEL_37;
      }
      if ( v10 > (int)v14 )
      {
        v10 -= v14;
        if ( !v9[3] )
          --v10;
        *(v8 - 1) = (unsigned int)v13;
LABEL_36:
        v9 = (char *)v11;
        goto LABEL_37;
      }
      goto LABEL_37;
    }
    v11 = B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeSplitChild(
            a1,
            a2);
    if ( v11 )
    {
      v8 = &(*a2)[2 * (_DWORD)a2[3] - 2];
      v17 = *(unsigned __int16 *)v9;
      if ( v10 > v17 )
      {
        v10 -= v17;
        if ( !v9[3] )
          --v10;
        (*a2)[2 * (_DWORD)a2[3] - 3] += 8;
        goto LABEL_36;
      }
LABEL_37:
      *v8 = (unsigned int)v9;
      v8[1] = (unsigned int)&v9[8 * v10 + 8];
      goto LABEL_38;
    }
    return -1073741670;
  }
LABEL_38:
  v18 = (unsigned __int16 *)v8[1];
  v19 = *(unsigned __int16 *)v9;
  v20 = (int)(v18 + 4);
  if ( v9[3] )
  {
    memmove(v20, (int)v18, (unsigned int)&v9[8 * (v19 + 1) - (_DWORD)v18]);
    *(_DWORD *)v18 = *a3;
    *((_DWORD *)v18 + 1) = a3[1];
    ++a1[1];
  }
  else
  {
    memmove(v20, (int)v18, (unsigned int)&v9[8 * (v19 + 1) - (_DWORD)v18]);
    *(_DWORD *)v18 = *a3;
    *((_DWORD *)v18 + 1) = a3[1];
  }
  ++*(_WORD *)v9;
  return 0;
}
