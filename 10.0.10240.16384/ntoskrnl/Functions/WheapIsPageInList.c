// WheapIsPageInList 
 
int __fastcall WheapIsPageInList(_DWORD *a1, unsigned int a2, int a3)
{
  int result; // r0
  unsigned int v5; // r5

  result = 0;
  v5 = 0;
  if ( a2 )
  {
    while ( *a1 != a3 || a1[1] )
    {
      ++v5;
      a1 += 2;
      if ( v5 >= a2 )
        return result;
    }
    result = 1;
  }
  return result;
}
