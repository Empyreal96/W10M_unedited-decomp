// PpmInfoConfigComparer 
 
int __fastcall PpmInfoConfigComparer(int a1, int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  int result; // r0

  v2 = *(unsigned __int8 *)(a2 + 24);
  v3 = *(unsigned __int8 *)(a1 + 24);
  if ( v3 >= v2 )
    result = v3 > v2;
  else
    result = -1;
  return result;
}
