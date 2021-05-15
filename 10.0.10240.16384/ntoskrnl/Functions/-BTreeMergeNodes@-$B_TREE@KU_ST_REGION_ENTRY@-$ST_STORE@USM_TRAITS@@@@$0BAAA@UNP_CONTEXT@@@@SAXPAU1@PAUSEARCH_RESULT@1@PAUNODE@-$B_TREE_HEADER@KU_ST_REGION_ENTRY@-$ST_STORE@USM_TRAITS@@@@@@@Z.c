// -BTreeMergeNodes@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAXPAU1@PAUSEARCH_RESULT@1@PAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@@Z 
 
int __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeMergeNodes(int a1, _DWORD *a2, unsigned int a3)
{
  int v5; // r0
  unsigned __int16 *v6; // r7
  unsigned __int16 *v7; // r4
  int v8; // r6
  int v9; // r9
  _DWORD **v10; // r3
  int v11; // r2
  _DWORD **v12; // r3
  unsigned __int16 *v13; // r2
  struct NP_CONTEXT::NP_CTX *v14; // r0
  struct NP_CONTEXT::NP_CTX *v15; // r0
  _DWORD *v16; // r3
  int v17; // r2
  int result; // r0

  v5 = *a2 + 8 * a2[3];
  if ( (a3 & 1) != 0 )
  {
    a3 &= 0xFFFFFFFE;
    v6 = *(unsigned __int16 **)(v5 - 8);
    v7 = (unsigned __int16 *)a3;
  }
  else
  {
    v7 = *(unsigned __int16 **)(v5 - 8);
    v6 = (unsigned __int16 *)a3;
  }
  v8 = *(_DWORD *)(v5 - 12);
  v9 = *v7;
  if ( v7 == (unsigned __int16 *)a3 )
  {
    v8 -= 8;
    *(_DWORD *)(v5 - 12) = v8;
  }
  if ( *((_BYTE *)v7 + 3) )
  {
    v10 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v10 = 0;
    if ( **v10 == -1 )
      v11 = *((_DWORD *)v6 + 1);
    else
      v11 = 3358;
    v12 = (_DWORD **)(a1 + 8);
    if ( !a1 )
      v12 = 0;
    if ( **v12 == -1 )
      *((_DWORD *)v7 + 1) = v11;
  }
  else
  {
    v13 = &v7[4 * v9++];
    *((_DWORD *)v13 + 2) = *(_DWORD *)v8;
    *((_DWORD *)v13 + 3) = *((_DWORD *)v6 + 1);
  }
  memmove((int)&v7[4 * v9 + 4], (int)(v6 + 4), 8 * *v6);
  *v7 = *(_DWORD *)v6 + v9;
  if ( *((_BYTE *)v7 + 3) )
  {
    v14 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    if ( !a1 )
      v14 = 0;
    if ( **(_DWORD **)v14 != -1 )
      NP_CONTEXT::NpLeafDerefInternal(v14, (void **)(v8 + 4));
    v15 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
    if ( !a1 )
      v15 = 0;
    if ( **(_DWORD **)v15 != -1 )
      NP_CONTEXT::NpLeafRemoveInternal(v15, (void **)(v8 + 4));
  }
  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(
    a1,
    (unsigned __int8 *)v6);
  v16 = (_DWORD *)(a2[3] - 1);
  a2[3] = v16;
  result = B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteEx(a1, a2, v17, v16);
  ++a2[3];
  return result;
}
