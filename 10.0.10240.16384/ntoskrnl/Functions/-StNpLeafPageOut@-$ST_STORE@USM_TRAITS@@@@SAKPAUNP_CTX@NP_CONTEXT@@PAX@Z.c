// -StNpLeafPageOut@-$ST_STORE@USM_TRAITS@@@@SAKPAUNP_CTX@NP_CONTEXT@@PAX@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StNpLeafPageOut(int a1, int a2)
{
  _DWORD *v2; // r4
  int v4; // r5
  int v5; // r6
  int v6; // r3
  int result; // r0
  int v8; // [sp+0h] [bp-28h] BYREF
  _DWORD v9[2]; // [sp+8h] [bp-20h] BYREF
  int v10; // [sp+10h] [bp-18h]

  v2 = *(_DWORD **)a1;
  v4 = *(_DWORD *)(*(_DWORD *)a1 + 84);
  if ( (*(_DWORD *)(v4 + 32) & 1) == 0 )
    B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchResultDeref(
      *(_DWORD *)(*(_DWORD *)a1 + 84),
      v4 + 12);
  *(_DWORD *)(v4 + 32) |= 1u;
  do
  {
    v5 = v2[18];
    if ( v5 == v2[20] )
      v6 = v2[19];
    else
      v6 = v5 + 1;
    v2[18] = v6;
  }
  while ( B_TREE<_SM_PAGE_KEY,ST_STORE<SM_TRAITS>::_ST_PAGE_ENTRY,4096,NP_CONTEXT>::BTreeSearchKey(
            (unsigned __int16 **)v4,
            4 * v5,
            v4 + 12,
            v6) != -1073741275 );
  v9[0] = 0;
  v9[1] = a2;
  v10 = 0;
  v8 = *(_DWORD *)(v4 + 108);
  v10 = 4 * v5;
  if ( ST_STORE<SM_TRAITS>::StDmpSinglePageAdd(v4, v9, &v8) >= 0 )
    result = 4 * v5;
  else
    result = 0;
  return result;
}
