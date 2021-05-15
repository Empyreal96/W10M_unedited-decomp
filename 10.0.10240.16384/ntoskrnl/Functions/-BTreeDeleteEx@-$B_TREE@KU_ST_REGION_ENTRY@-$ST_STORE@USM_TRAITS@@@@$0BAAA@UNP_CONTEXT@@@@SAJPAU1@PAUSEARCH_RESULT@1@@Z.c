// -BTreeDeleteEx@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAJPAU1@PAUSEARCH_RESULT@1@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(int a1, _DWORD *a2, int a3, _DWORD *a4)
{
  int v4; // r2
  unsigned int *v7; // r6
  __int64 v8; // kr00_8
  int v9; // r3
  char *v10; // r8
  int v11; // r0
  int v12; // r7
  unsigned int v14; // r3
  int v15; // r3
  unsigned int v16; // r2
  int v17; // r1
  void **v18; // r1
  __int64 v19; // kr08_8
  int v20; // [sp+0h] [bp-20h] BYREF
  _DWORD *v21; // [sp+4h] [bp-1Ch]

  v20 = a3;
  v21 = a4;
  v4 = a2[3];
  v7 = (unsigned int *)(*a2 + 8 * v4 - 8);
  v8 = *(_QWORD *)v7;
  v9 = 8 * *(unsigned __int16 *)*v7 - *(_DWORD *)(*a2 + 8 * v4 - 4);
  v10 = (char *)(v9 + *v7);
  if ( v10 )
    memmove(SHIDWORD(v8), HIDWORD(v8) + 8, v9 + *v7);
  *(_WORD *)v8 = *(_DWORD *)v8 - 1;
  if ( *(_BYTE *)(v8 + 3) )
    --*(_DWORD *)(a1 + 4);
  if ( *(_DWORD *)a1 == (_DWORD)v8 )
  {
    if ( !*(_WORD *)v8 && !*(_BYTE *)(v8 + 3) )
    {
      memmove((int)v7, (int)(v7 + 2), 8 * (a2[4] - 1));
      --a2[3];
      if ( **(_DWORD **)(a1 + 8) == -1 || *(_BYTE *)(v8 + 2) != 2 )
      {
        *(_DWORD *)a1 = *(_DWORD *)(v8 + 4);
      }
      else
      {
        *(_DWORD *)a1 = NP_CONTEXT::NpLeafRefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v8 + 4), 1u);
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v8 + 4));
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v8 + 4));
        if ( **(_DWORD **)(a1 + 8) != -1 )
          NP_CONTEXT::NpLeafRemoveInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), (void **)(v8 + 4));
      }
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, v8);
    }
  }
  else
  {
    if ( *(unsigned __int16 *)v8 < 0xFFu )
    {
      v11 = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeRedistribute(a1, a2);
      v12 = v11;
      if ( !v11 )
        return -1073741818;
      v14 = *(unsigned __int16 *)v8;
      if ( v14 < 0xFF )
      {
        B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeMergeNodes(a1, a2, v11);
        v7 = (unsigned int *)(*a2 + 8 * a2[3] - 8);
        if ( (v12 & 1) != 0 )
        {
          *v7 = v12 & 0xFFFFFFFE;
          v7[1] = 8 * (*(unsigned __int16 *)(v12 & 0xFFFFFFFE) + 1) - (_DWORD)v10 + (v12 & 0xFFFFFFFE);
        }
      }
      else
      {
        if ( (v11 & 1) != 0 )
          v7[1] += 8 * (v14 - 254);
        if ( *(_BYTE *)(v8 + 3) )
        {
          v15 = *(v7 - 1);
          v16 = v15 + 8;
          if ( (v11 & 1) != 0 )
            v16 = v15 - 8;
          v17 = *(v7 - 2);
          if ( v16 <= v17 + 8 )
            v18 = (void **)(v17 + 4);
          else
            v18 = (void **)(v16 - 4);
          if ( **(_DWORD **)(a1 + 8) != -1 )
            NP_CONTEXT::NpLeafDerefInternal((struct NP_CONTEXT::NP_CTX *)(a1 + 8), v18);
        }
      }
    }
    v19 = *(_QWORD *)v7;
    if ( v7[1] == *v7 + 8
      && *(_BYTE *)(v19 + 3)
      && B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
           a2,
           0,
           &v20) )
    {
      *v21 = *(_DWORD *)HIDWORD(v19);
    }
  }
  return 0;
}
