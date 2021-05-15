// KsepEngineGetShimsFromRegistry 
 
int __fastcall KsepEngineGetShimsFromRegistry(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  if ( (*(_DWORD *)(a1 + 8) & 1) == 0 )
    return sub_7CD094();
  KsepPoolFreePaged(0);
  *a3 = 0;
  *a4 = 0;
  return -1073741275;
}
