// -BTreeFindLeafSiblingEx@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAPAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@PAU1@PAUSEARCH_RESULT@1@K@Z 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeFindLeafSiblingEx(int a1, _DWORD *a2, __int64 a3)
{
  char v3; // r7
  int v6; // r4
  void **v7; // r1
  struct NP_CONTEXT::NP_CTX *v8; // r0
  unsigned int v9; // r2
  struct NP_CONTEXT::NP_CTX *v10; // r0
  int v11; // r1 OVERLAPPED
  unsigned int v12; // r2 OVERLAPPED
  void **v13; // r1
  int v14; // r2
  __int64 v16[3]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a3;
  v3 = a3;
  v6 = 0;
  if ( B_TREE<_SM_PAGE_KEY,SMKM_STORE_MGR<SM_TRAITS>::SMKM_FRONTEND_ENTRY,4096,B_TREE_DUMMY_NODE_POOL>::BTreeFindSeperatorIndexEntry(
         a2,
         a3 & 1,
         v16) )
  {
    v7 = (void **)B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(
                    v16,
                    v3,
                    0);
    v8 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    if ( (a2[5] & 1) != 0 )
      v9 = 2;
    else
      v9 = 0;
    if ( !a1 )
      v8 = 0;
    if ( **(_DWORD **)v8 == -1 )
      v6 = (int)*v7;
    else
      v6 = (int)NP_CONTEXT::NpLeafRefInternal(v8, v7, v9);
    if ( v6 )
    {
      if ( (v3 & 2) != 0 )
      {
        v10 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
        *(_QWORD *)&v11 = *(_QWORD *)(*a2 + 8 * (a2[3] - 2));
        if ( v12 <= v11 + 8 )
          v13 = (void **)(v11 + 4);
        else
          v13 = (void **)(v12 - 4);
        if ( !a1 )
          v10 = 0;
        if ( **(_DWORD **)v10 != -1 )
          NP_CONTEXT::NpLeafDerefInternal(v10, v13);
      }
      B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDescendToSibling(v16, v3, a2);
      v14 = *a2 + 8 * a2[3];
      *(_DWORD *)(v14 - 8) = v6;
      *(_DWORD *)(v14 - 4) = v6 + 8;
    }
    else
    {
      v6 = -1;
    }
  }
  return v6;
}
