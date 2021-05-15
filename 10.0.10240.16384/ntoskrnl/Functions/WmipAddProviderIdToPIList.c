// WmipAddProviderIdToPIList 
 
int __fastcall WmipAddProviderIdToPIList(_DWORD *a1, int *a2, _DWORD *a3, int a4, int a5)
{
  int v5; // r9

  v5 = *a2;
  if ( *a2 == *a3 )
    return sub_7D62F4();
  *(_DWORD *)(*a1 + 4 * v5) = a5;
  *a2 = v5 + 1;
  return 0;
}
