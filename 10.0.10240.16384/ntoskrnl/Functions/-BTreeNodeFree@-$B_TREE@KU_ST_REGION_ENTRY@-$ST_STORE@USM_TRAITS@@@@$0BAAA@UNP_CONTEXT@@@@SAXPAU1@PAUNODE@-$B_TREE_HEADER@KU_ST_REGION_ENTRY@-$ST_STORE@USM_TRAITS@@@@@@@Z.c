// -BTreeNodeFree@-$B_TREE@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@$0BAAA@UNP_CONTEXT@@@@SAXPAU1@PAUNODE@-$B_TREE_HEADER@KU_ST_REGION_ENTRY@-$ST_STORE@USM_TRAITS@@@@@@@Z 
 
void __fastcall B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFree(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v4; // r7
  unsigned __int8 *v5; // r6
  unsigned int v6; // r8
  void **v7; // r1
  _DWORD **v8; // r3
  struct NP_CONTEXT::NP_CTX *v9; // r0
  void *v10; // r0

  if ( !a2[3] )
  {
    v4 = a2 + 8;
    v5 = a2 + 8;
    v6 = (unsigned int)&a2[8 * *(unsigned __int16 *)a2 + 8];
    if ( (unsigned int)(a2 + 8) <= v6 )
    {
      do
      {
        if ( v5 <= v4 )
          v7 = (void **)(a2 + 4);
        else
          v7 = (void **)(v5 - 4);
        v8 = (_DWORD **)(a1 + 8);
        if ( !a1 )
          v8 = 0;
        if ( **v8 == -1 || a2[2] != 2 )
          goto LABEL_14;
        v9 = (struct NP_CONTEXT::NP_CTX *)(a1 + 8);
        if ( !a1 )
          v9 = 0;
        if ( **(_DWORD **)v9 == -1 )
LABEL_14:
          v10 = *v7;
        else
          v10 = NP_CONTEXT::NpLeafRemoveInternal(v9, v7);
        if ( v10 )
          B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeNodeFree(a1);
        v5 += 8;
      }
      while ( (unsigned int)v5 <= v6 );
    }
  }
  B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeDeleteNode(a1, a2);
}
