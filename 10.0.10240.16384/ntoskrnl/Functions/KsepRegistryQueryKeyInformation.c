// KsepRegistryQueryKeyInformation 
 
int __fastcall KsepRegistryQueryKeyInformation(int a1, _DWORD *a2, _DWORD *a3)
{
  int v5; // r0
  int v6; // r5
  int v7; // r4

  *a2 = 0;
  *a3 = 0;
  v5 = ZwQueryKey();
  v6 = v5;
  if ( v5 == -2147483643 || v5 == -1073741789 )
  {
    v7 = KsepPoolAllocatePaged(0);
    if ( v7 )
    {
      v6 = ZwQueryKey();
      if ( v6 >= 0 )
      {
        *a2 = *(_DWORD *)(v7 + 36) + 2;
        *a3 = *(_DWORD *)(v7 + 40);
      }
      KsepPoolFreePaged(v7);
    }
    else
    {
      v6 = -1073741801;
    }
  }
  return v6;
}
