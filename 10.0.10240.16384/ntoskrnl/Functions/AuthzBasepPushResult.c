// AuthzBasepPushResult 
 
int __fastcall AuthzBasepPushResult(int a1, int *a2, int a3)
{
  int v3; // r3
  int result; // r0

  v3 = *a2;
  result = 0;
  if ( (unsigned int)*a2 >= 0x100 )
    return -1073740791;
  *(_DWORD *)(a1 + 4 * v3) = a3;
  *a2 = v3 + 1;
  return result;
}
