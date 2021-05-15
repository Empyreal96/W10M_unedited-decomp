// KsepGetModuleInfoByAddress 
 
int __fastcall KsepGetModuleInfoByAddress(unsigned int a1, _DWORD *a2, unsigned int *a3, _DWORD *a4)
{
  _DWORD *v4; // r1
  unsigned int v5; // r7

  if ( !a1 || !a3 || !a2 )
    return -1073741811;
  if ( !*a2 )
    return -1073741275;
  v4 = a2 + 1;
  v5 = v4[2];
  if ( a1 < v5 || a1 >= v4[3] + v5 )
    return sub_7CF340();
  *a3 = v5;
  if ( a4 )
    *a4 = v4[3];
  return 0;
}
