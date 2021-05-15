// PopTranslateDependencyArray 
 
int __fastcall PopTranslateDependencyArray(int result, int a2, int a3, unsigned int a4, unsigned int a5, int a6)
{
  unsigned int i; // r1

  if ( a5 > a4 )
    PopFxBugCheck(a3, result, a2, 0);
  for ( i = 0; i < a5; a6 += 8 )
  {
    if ( !*(_DWORD *)a6 )
      PopFxBugCheck(a3, result, a2, 0);
    ++i;
    *(_DWORD *)a6 = *(_DWORD *)(*(_DWORD *)a6 + 88);
  }
  return result;
}
