// -BTreeInsertEx@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAUSEARCH_RESULT@1@PAK@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(int a1, int **a2, _DWORD *a3)
{
  unsigned int v6; // r0
  __int64 v7; // kr00_8
  int v8; // r0
  int *v9; // r6
  char *v10; // r5
  int v11; // r4
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1
  unsigned int v15; // r3
  char *v16; // r0
  void **v17; // r1
  int v18; // r0
  int v20; // r3
  int v21; // r1
  void **v22; // r1
  unsigned __int16 *v23; // r4
  int v24; // r3
  int v25; // r0

  if ( *(_DWORD *)a1 )
    v6 = *(unsigned __int8 *)(*(_DWORD *)a1 + 2);
  else
    v6 = 0;
  v7 = *(_QWORD *)(a2 + 3);
  if ( HIDWORD(v7) <= v6 && !SmArrayGrow() )
    return -1073741670;
  if ( (_DWORD)v7 )
  {
    v9 = &(*a2)[2 * v7 - 2];
  }
  else
  {
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(a1, 1, 1);
    *(_DWORD *)a1 = v8;
    if ( !v8 )
      return -1073741670;
    v9 = *a2;
    *v9 = v8;
    v9[1] = *(_DWORD *)a1 + 8;
    a2[3] = (int *)((char *)a2[3] + 1);
  }
  v10 = (char *)*v9;
  if ( *(unsigned __int16 *)*v9 >= 0x1FFu )
  {
    v11 = (v9[1] - (int)v10 - 8) >> 3;
    if ( v10 == *(char **)a1 )
    {
      v14 = 0;
      v12 = 0;
      v13 = 0;
    }
    else
    {
      v12 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(a1, a2);
      v13 = *(v9 - 1);
      if ( (v12 & 1) != 0 )
        v14 = v13 - 8;
      else
        v14 = v13 + 8;
    }
    v15 = *(unsigned __int16 *)v10;
    if ( v15 < 0x1FF )
    {
      if ( (v12 & 1) == 0 )
      {
        if ( v11 <= (int)v15 )
          goto LABEL_25;
        v11 -= v15;
        if ( !v10[3] )
          --v11;
        v10 = (char *)v12;
        goto LABEL_30;
      }
      v11 = v15 + v11 - 511;
      v16 = (char *)(v12 & 0xFFFFFFFE);
      if ( v10[3] )
      {
        if ( v11 > 0 )
          goto LABEL_24;
        v11 += (unsigned __int16)*(_DWORD *)v16;
      }
      else
      {
        if ( v11 >= 0 )
          goto LABEL_24;
        v11 += (unsigned __int16)*(_DWORD *)v16 + 1;
      }
      v10 = v16;
LABEL_24:
      if ( v10 != v16 )
      {
LABEL_25:
        v13 = v14;
        goto LABEL_45;
      }
LABEL_30:
      *(v9 - 1) = v14;
LABEL_45:
      *v9 = (int)v10;
      if ( v10[3] )
      {
        v9[1] = (int)&v10[8 * v11 + 8];
        v21 = *(v9 - 2);
        if ( v13 <= v21 + 8 )
          v22 = (void **)(v21 + 4);
        else
          v22 = (void **)(v13 - 4);
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v22);
      }
      else
      {
        v9[1] = (int)&v10[8 * v11 + 8];
      }
      goto LABEL_52;
    }
    if ( v12 && v10[3] )
    {
      v13 = *(v9 - 2);
      v17 = (void **)(v14 <= v13 + 8 ? v13 + 4 : v14 - 4);
      if ( **(_DWORD **)(a1 + 8) != -1 )
        NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v17);
    }
    v18 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeSplitChild(a1, a2, v13);
    if ( v18 )
    {
      v9 = &(*a2)[2 * (_DWORD)a2[3] - 2];
      v20 = *(unsigned __int16 *)v10;
      v13 = (*a2)[2 * (_DWORD)a2[3] - 3];
      if ( v11 <= v20 )
      {
        v13 += 8;
      }
      else
      {
        v11 -= v20;
        if ( !v10[3] )
          --v11;
        (*a2)[2 * (_DWORD)a2[3] - 3] = v13 + 8;
        v10 = (char *)v18;
      }
      goto LABEL_45;
    }
    return -1073741670;
  }
LABEL_52:
  v23 = (unsigned __int16 *)v9[1];
  v24 = *(unsigned __int16 *)v10;
  v25 = (int)(v23 + 4);
  if ( v10[3] )
  {
    memmove(v25, (int)v23, (unsigned int)&v10[8 * (v24 + 1) - (_DWORD)v23]);
    *(_DWORD *)v23 = *a3;
    *((_DWORD *)v23 + 1) = a3[1];
    ++*(_DWORD *)(a1 + 4);
  }
  else
  {
    memmove(v25, (int)v23, (unsigned int)&v10[8 * (v24 + 1) - (_DWORD)v23]);
    *(_DWORD *)v23 = *a3;
    *((_DWORD *)v23 + 1) = a3[1];
  }
  ++*(_WORD *)v10;
  return 0;
}
