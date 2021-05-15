// -SmStFindVirtualLockedRegion@-$SMKM_STORE@USM_TRAITS@@@@SAPAU_SM_VIRTUAL_LOCKED_REGION@@PAU1@KPAX@Z 
 
unsigned int __fastcall SMKM_STORE<SM_TRAITS>::SmStFindVirtualLockedRegion(int a1, int a2, int a3)
{
  unsigned int result; // r0
  unsigned int v5; // r4
  bool v6; // zf

  result = *(_DWORD *)(a1 + 3664);
  v5 = result + 40;
  if ( a2 != -1 )
    result += 4 * a2;
  while ( result < v5 )
  {
    if ( *(_DWORD *)result )
      v6 = *(_DWORD *)(*(_DWORD *)result + 16) == a3;
    else
      v6 = a3 == 0;
    if ( v6 )
      return result;
    if ( result >= *(_DWORD *)(a1 + 3664) + 32 || a2 == -1 )
      result += 4;
    else
      result = *(_DWORD *)(a1 + 3664) + 32;
  }
  return 0;
}
