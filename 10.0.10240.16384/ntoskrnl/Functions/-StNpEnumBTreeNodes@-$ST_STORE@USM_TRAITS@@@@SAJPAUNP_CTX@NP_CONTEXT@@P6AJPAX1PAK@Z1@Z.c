// -StNpEnumBTreeNodes@-$ST_STORE@USM_TRAITS@@@@SAJPAUNP_CTX@NP_CONTEXT@@P6AJPAX1PAK@Z1@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StNpEnumBTreeNodes(int *a1, int (__fastcall *a2)(unsigned __int16 *, int, int), int a3)
{
  int v3; // r0
  int *v5; // r0
  int v6; // r1
  unsigned __int16 *v8; // [sp+8h] [bp-10h] BYREF
  int v9[3]; // [sp+Ch] [bp-Ch] BYREF

  v3 = *a1;
  v8 = 0;
  if ( *(_DWORD *)(v3 + 68) )
  {
    v5 = (int *)(v3 - 540);
    v6 = *v5;
    v9[0] = 0;
    if ( v6 )
      return B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeWalkPostOrderInternal(
               (int)v5,
               v6,
               &v8,
               a2,
               a3,
               (int)v9);
  }
  else
  {
    v5 = (int *)(v3 - 488);
    v6 = *v5;
    v9[0] = 0;
    if ( v6 )
      return B_TREE<unsigned long,ST_STORE<SM_TRAITS>::_ST_REGION_ENTRY,4096,NP_CONTEXT>::BTreeWalkPostOrderInternal(
               (int)v5,
               v6,
               &v8,
               a2,
               a3,
               (int)v9);
  }
  return 0;
}
