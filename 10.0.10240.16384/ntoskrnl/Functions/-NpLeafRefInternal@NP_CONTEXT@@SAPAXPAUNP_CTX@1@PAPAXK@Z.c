// -NpLeafRefInternal@NP_CONTEXT@@SAPAXPAUNP_CTX@1@PAPAXK@Z 
 
struct B_TREE_NODE_HDR *__fastcall NP_CONTEXT::NpLeafRefInternal(struct NP_CONTEXT::NP_CTX *a1, void **a2, unsigned int a3)
{
  char v4; // r7
  struct B_TREE_NODE_HDR *v6; // r4
  void **v7; // r1

  v4 = a3;
  if ( ((unsigned int)*a2 & 1) == 0 )
  {
    if ( (a3 & 1) != 0 )
      return 0;
    NP_CONTEXT::NpiLeafPageIn(*(struct NP_CONTEXT **)a1, a1, (union _NP_LEAF_PTR *)a2);
    if ( ((unsigned int)*a2 & 1) == 0 )
      return 0;
  }
  v6 = NP_CONTEXT::NpGetResidentLeaf(a1, (union _NP_LEAF_PTR *)a2);
  if ( (v4 & 2) == 0 && **(_DWORD **)a1 != -1 )
    NP_CONTEXT::NpLeafRemoveInternal(a1, v7);
  return v6;
}
