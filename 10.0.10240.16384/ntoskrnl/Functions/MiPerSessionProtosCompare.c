// MiPerSessionProtosCompare 
 
int __fastcall MiPerSessionProtosCompare(unsigned int a1, int a2)
{
  unsigned int v2; // r3
  bool v3; // cf
  int result; // r0

  v2 = *(_DWORD *)(a2 + 12);
  v3 = a1 >= v2;
  if ( a1 > v2 )
    return 1;
  result = -1;
  if ( v3 )
    result = 0;
  return result;
}
