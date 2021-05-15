// -BTreeDeleteNode@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAXPAU1@PAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@@Z 
 
void __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(int a1, unsigned __int8 *a2)
{
  struct NP_CONTEXT::NP_CTX *v2; // r0

  if ( a1 )
    v2 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
  else
    v2 = 0;
  NP_CONTEXT::NpNodeFree(v2, a2, a2[3]);
}
