// PfPrefetchRequestVerifyPath 
 
int __fastcall PfPrefetchRequestVerifyPath(int a1, int a2, _DWORD *a3)
{
  unsigned int v4; // r2

  v4 = a3[1];
  if ( v4 >= 0x7FFF )
    return 10000;
  if ( !v4 )
    return 10500;
  if ( !*a3 )
    return 10750;
  if ( !PfRequestRangeCheck(a2 + 48, *a3, 2 * (v4 + 1), 2) )
    return 11000;
  if ( *(_WORD *)(*a3 + 2 * a3[1] + a1) )
    return 12000;
  return 0;
}
