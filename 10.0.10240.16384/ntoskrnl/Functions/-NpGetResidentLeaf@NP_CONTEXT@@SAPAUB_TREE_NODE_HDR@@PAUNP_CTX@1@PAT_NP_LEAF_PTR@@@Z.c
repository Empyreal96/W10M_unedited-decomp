// -NpGetResidentLeaf@NP_CONTEXT@@SAPAUB_TREE_NODE_HDR@@PAUNP_CTX@1@PAT_NP_LEAF_PTR@@@Z 
 
struct B_TREE_NODE_HDR *__fastcall NP_CONTEXT::NpGetResidentLeaf(struct NP_CONTEXT::NP_CTX *a1, union _NP_LEAF_PTR *a2)
{
  int v2; // r0

  v2 = *(_DWORD *)a2;
  if ( (*(_DWORD *)a2 & 2) != 0 )
    *(_DWORD *)a2 = (((v2 & 0xFFFFFFFC) + 4) ^ v2) & 0xFFC ^ v2;
  else
    *(_DWORD *)a2 = v2 & 0xFFFFF001 | 6;
  return (struct B_TREE_NODE_HDR *)(*(_DWORD *)a2 & 0xFFFFF000);
}
