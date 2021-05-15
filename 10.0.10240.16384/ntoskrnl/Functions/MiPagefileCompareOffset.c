// MiPagefileCompareOffset 
 
int __fastcall MiPagefileCompareOffset(unsigned int a1, unsigned int a2)
{
  unsigned int v2; // r3
  unsigned int v3; // r2
  int result; // r0

  v2 = *(_DWORD *)(a1 - 4);
  v3 = *(_DWORD *)(a2 - 4);
  if ( v2 > v3 || v2 >= v3 && a1 > a2 )
    result = 1;
  else
    result = -1;
  return result;
}
