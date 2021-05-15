// -BTreeDeleteEx@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  unsigned int *v6; // r6
  __int64 v7; // kr00_8
  int v8; // r3
  unsigned int v9; // r8
  int v10; // r1
  unsigned int v11; // r9
  int v12; // r0
  int v13; // r7
  unsigned int v15; // r3
  int v16; // r2
  unsigned __int16 *v17; // r3
  unsigned __int16 *v18; // r3
  int v19; // r3
  unsigned int v20; // r2
  int v21; // r1
  void **v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  int v25; // r3
  __int64 v26; // kr08_8
  _DWORD *v27; // [sp+0h] [bp-28h] BYREF
  _DWORD *v28; // [sp+4h] [bp-24h]
  int v29; // [sp+8h] [bp-20h]

  v27 = a2;
  v28 = a3;
  v29 = a4;
  v6 = (unsigned int *)(*a2 + 8 * a2[3] - 8);
  v7 = *(_QWORD *)v6;
  v8 = *(unsigned __int16 *)*v6;
  if ( *(_BYTE *)(*v6 + 3) )
  {
    v9 = 16 * v8 - HIDWORD(v7) + v7 - 8;
    v10 = HIDWORD(v7) + 16;
    v11 = 127;
  }
  else
  {
    v9 = 8 * v8 - HIDWORD(v7) + v7;
    v10 = HIDWORD(v7) + 8;
    v11 = 255;
  }
  if ( v9 )
    memmove(SHIDWORD(v7), v10, v9);
  *(_WORD *)v7 = *(_DWORD *)v7 - 1;
  if ( *(_BYTE *)(v7 + 3) )
    --*(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)a1 == (_DWORD)v7 )
  {
    if ( !*(_WORD *)v7 && !*(_BYTE *)(v7 + 3) )
    {
      memmove((int)v6, (int)(v6 + 2), 8 * (a2[4] - 1));
      --a2[3];
      if ( **(_DWORD **)(a1 + 8) == -1 || *(_BYTE *)(v7 + 2) != 2 )
      {
        *(_DWORD *)a1 = *(_DWORD *)(v7 + 4);
      }
      else
      {
        *(_DWORD *)a1 = NP_CONTEXT::NpLeafRefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v7 + 4), 1u);
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v7 + 4));
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v7 + 4));
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafRemoveInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v7 + 4));
      }
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v7);
    }
  }
  else
  {
    if ( *(unsigned __int16 *)v7 < v11 )
    {
      v12 = B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(a1, a2);
      v13 = v12;
      if ( !v12 )
        return -1073741818;
      v15 = *(unsigned __int16 *)v7;
      if ( v15 < v11 )
      {
        B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeMergeNodes(a1, a2, v12);
        v6 = (unsigned int *)(*a2 + 8 * a2[3] - 8);
        if ( (v13 & 1) != 0 )
        {
          v23 = v13 & 0xFFFFFFFE;
          *v6 = v13 & 0xFFFFFFFE;
          v24 = *(unsigned __int16 *)(v13 & 0xFFFFFFFE);
          if ( *(_BYTE *)((v13 & 0xFFFFFFFE) + 3) )
            v25 = 16 * v24 - v9 + v23 + 8;
          else
            v25 = 8 * (v24 + 1) - v9 + v23;
          v6[1] = v25;
        }
      }
      else
      {
        if ( (v12 & 1) != 0 )
        {
          v16 = v15 - v11 + 1;
          v17 = (unsigned __int16 *)v6[1];
          if ( *(_BYTE *)(v7 + 3) )
            v18 = &v17[8 * v16];
          else
            v18 = &v17[4 * v16];
          v6[1] = (unsigned int)v18;
        }
        if ( *(_BYTE *)(v7 + 3) )
        {
          v19 = *(v6 - 1);
          v20 = v19 + 8;
          if ( (v12 & 1) != 0 )
            v20 = v19 - 8;
          v21 = *(v6 - 2);
          if ( v20 <= v21 + 8 )
            v22 = (void **)(v21 + 4);
          else
            v22 = (void **)(v20 - 4);
          if ( **(_DWORD **)(a1 + 8) != -1 )
            NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v22);
        }
      }
    }
    v26 = *(_QWORD *)v6;
    if ( v6[1] == *v6 + 8
      && *(_BYTE *)(v26 + 3)
      && B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
           a2,
           0,
           &v27) )
    {
      *v28 = *(_DWORD *)HIDWORD(v26);
    }
  }
  return 0;
}
