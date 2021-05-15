// MiPagefileCompare 
 
int __fastcall MiPagefileCompare(unsigned int a1, int a2)
{
  unsigned int v2; // r3
  int result; // r0

  v2 = *(_DWORD *)(a2 - 100);
  if ( a1 < v2 )
    result = -1;
  else
    result = a1 > v2;
  return result;
}
