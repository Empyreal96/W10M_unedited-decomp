// -BTreeInsertEx@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAUSEARCH_RESULT@1@PAT_SM_PAGE_KEY@@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeInsertEx(int a1, int a2, _DWORD *a3)
{
  unsigned int v6; // r0
  __int64 v7; // kr00_8
  int v8; // r0
  int *v9; // r6
  unsigned __int16 *v10; // r5
  unsigned int v11; // r9
  int v12; // r3
  int v13; // r4
  int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // r3
  unsigned __int16 *v18; // r0
  void **v19; // r1
  int v20; // r0
  int v22; // r3
  int v23; // r1
  void **v24; // r1
  _DWORD *v25; // r4
  int v26; // r3
  int v27; // r1
  int v28; // r2
  int v29; // r3

  if ( *(_DWORD *)a1 )
    v6 = *(unsigned __int8 *)(*(_DWORD *)a1 + 2);
  else
    v6 = 0;
  v7 = *(_QWORD *)(a2 + 12);
  if ( HIDWORD(v7) <= v6 && !SmArrayGrow() )
    return -1073741670;
  if ( (_DWORD)v7 )
  {
    v9 = (int *)(*(_DWORD *)a2 + 8 * v7 - 8);
  }
  else
  {
    v8 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeNewNode(a1, 1, 1);
    *(_DWORD *)a1 = v8;
    if ( !v8 )
      return -1073741670;
    v9 = *(int **)a2;
    *v9 = v8;
    v9[1] = *(_DWORD *)a1 + 8;
    ++*(_DWORD *)(a2 + 12);
  }
  v10 = (unsigned __int16 *)*v9;
  if ( *(_BYTE *)(*v9 + 3) )
    v11 = 255;
  else
    v11 = 511;
  if ( *v10 >= v11 )
  {
    v12 = v9[1];
    if ( *(_BYTE *)(*v9 + 3) )
      v13 = (v12 - (int)v10 - 8) >> 4;
    else
      v13 = (v12 - (int)v10 - 8) >> 3;
    if ( v10 == *(unsigned __int16 **)a1 )
    {
      v16 = 0;
      v14 = 0;
      v15 = 0;
    }
    else
    {
      v14 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(a1, a2);
      v15 = *(v9 - 1);
      if ( (v14 & 1) != 0 )
        v16 = v15 - 8;
      else
        v16 = v15 + 8;
    }
    v17 = *v10;
    if ( v17 < v11 )
    {
      if ( (v14 & 1) == 0 )
      {
        if ( v13 <= v17 )
          goto LABEL_31;
        v13 -= v17;
        if ( !*((_BYTE *)v10 + 3) )
          --v13;
        v10 = (unsigned __int16 *)v14;
        goto LABEL_36;
      }
      v13 += v17 - v11;
      v18 = (unsigned __int16 *)(v14 & 0xFFFFFFFE);
      if ( *((_BYTE *)v10 + 3) )
      {
        if ( v13 > 0 )
          goto LABEL_30;
        v13 += (unsigned __int16)*(_DWORD *)v18;
      }
      else
      {
        if ( v13 >= 0 )
          goto LABEL_30;
        v13 += (unsigned __int16)*(_DWORD *)v18 + 1;
      }
      v10 = v18;
LABEL_30:
      if ( v10 != v18 )
      {
LABEL_31:
        v15 = v16;
        goto LABEL_51;
      }
LABEL_36:
      *(v9 - 1) = v16;
LABEL_51:
      *v9 = (int)v10;
      if ( *((_BYTE *)v10 + 3) )
      {
        v9[1] = (int)&v10[8 * v13 + 4];
        v23 = *(v9 - 2);
        if ( v15 <= v23 + 8 )
          v24 = (void **)(v23 + 4);
        else
          v24 = (void **)(v15 - 4);
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v24);
      }
      else
      {
        v9[1] = (int)&v10[4 * v13 + 4];
      }
      goto LABEL_58;
    }
    if ( v14 && *((_BYTE *)v10 + 3) )
    {
      v15 = *(v9 - 2);
      v19 = (void **)(v16 <= v15 + 8 ? v15 + 4 : v16 - 4);
      if ( **(_DWORD **)(a1 + 8) != -1 )
        NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v19);
    }
    v20 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSplitChild(a1, a2, v15);
    if ( v20 )
    {
      v9 = (int *)(*(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 12) - 8);
      v22 = *v10;
      v15 = *(_DWORD *)(*(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 12) - 12);
      if ( v13 <= v22 )
      {
        v15 += 8;
      }
      else
      {
        v13 -= v22;
        if ( !*((_BYTE *)v10 + 3) )
          --v13;
        *(_DWORD *)(*(_DWORD *)a2 + 8 * *(_DWORD *)(a2 + 12) - 12) = v15 + 8;
        v10 = (unsigned __int16 *)v20;
      }
      goto LABEL_51;
    }
    return -1073741670;
  }
LABEL_58:
  v25 = (_DWORD *)v9[1];
  v26 = *v10;
  if ( *((_BYTE *)v10 + 3) )
  {
    memmove((int)(v25 + 4), (int)v25, (unsigned int)v10 + 16 * v26 - (_DWORD)v25 + 8);
    v27 = a3[1];
    v28 = a3[2];
    v29 = a3[3];
    *v25 = *a3;
    v25[1] = v27;
    v25[2] = v28;
    v25[3] = v29;
    ++*(_DWORD *)(a1 + 4);
  }
  else
  {
    memmove((int)(v25 + 2), (int)v25, (unsigned int)v10 + 8 * (v26 + 1) - (_DWORD)v25);
    *v25 = *a3;
    v25[1] = a3[1];
  }
  ++*v10;
  return 0;
}
