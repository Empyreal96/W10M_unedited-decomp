// -BTreeFindLeafSiblingEx@-$B_TREE@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@T_SM_PAGE_KEY@@U_ST_PAGE_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@K@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSiblingEx(int a1, _DWORD *a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r1
  void **v8; // r1
  struct NP_CONTEXT::NP_CTX *v9; // r0
  unsigned int v10; // r2
  struct NP_CONTEXT::NP_CTX *v11; // r0
  int v12; // r1 OVERLAPPED
  unsigned int v13; // r2 OVERLAPPED
  void **v14; // r1
  int v15; // r2
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = (int)a2;
  v17[1] = a3;
  v17[2] = a4;
  v6 = 0;
  if ( B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
         a2,
         1,
         v17) )
  {
    v8 = (void **)B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(
                    v17,
                    v7,
                    0);
    v9 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    if ( (a2[5] & 1) != 0 )
      v10 = 2;
    else
      v10 = 0;
    if ( !a1 )
      v9 = 0;
    if ( **(_DWORD **)v9 == -1 )
      v6 = (int)*v8;
    else
      v6 = (int)NP_CONTEXT::NpLeafRefInternal(v9, v8, v10);
    if ( v6 )
    {
      v11 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
      *(_QWORD *)&v12 = *(_QWORD *)(*a2 + 8 * (a2[3] - 2));
      if ( v13 <= v12 + 8 )
        v14 = (void **)(v12 + 4);
      else
        v14 = (void **)(v13 - 4);
      if ( !a1 )
        v11 = 0;
      if ( **(_DWORD **)v11 != -1 )
        NP_CONTEXT::NpLeafDerefInternal(v11, v14);
      B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(v17, (int)v14, a2);
      v15 = *a2 + 8 * a2[3];
      *(_DWORD *)(v15 - 8) = v6;
      *(_DWORD *)(v15 - 4) = v6 + 8;
    }
    else
    {
      v6 = -1;
    }
  }
  return v6;
}
