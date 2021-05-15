// MiPagefileSectionCompare 
 
int __fastcall MiPagefileSectionCompare(unsigned int a1, int a2)
{
  unsigned int v2; // r2
  int result; // r0

  v2 = *(_DWORD *)(a2 - 36);
  if ( a1 < v2 )
    result = -1;
  else
    result = a1 >= v2 + 4 * *(_DWORD *)(a2 - 12);
  return result;
}
