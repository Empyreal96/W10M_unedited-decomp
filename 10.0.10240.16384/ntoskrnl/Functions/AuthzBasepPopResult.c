// AuthzBasepPopResult 
 
int __fastcall AuthzBasepPopResult(int a1, int *a2, _DWORD *a3)
{
  int result; // r0
  int v5; // r3

  result = 0;
  if ( !*a2 )
    return -1073741406;
  v5 = *a2 - 1;
  *a2 = v5;
  *a3 = *(_DWORD *)(a1 + 4 * v5);
  return result;
}
