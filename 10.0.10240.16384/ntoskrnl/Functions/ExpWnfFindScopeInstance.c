// ExpWnfFindScopeInstance 
 
_DWORD *__fastcall ExpWnfFindScopeInstance(_DWORD **a1, unsigned int a2, int a3)
{
  _DWORD *i; // r5
  _DWORD *v7; // r4

  for ( i = *a1; i != a1; i = (_DWORD *)*i )
  {
    v7 = i - 5;
    if ( a3 == *(i - 2) && !memcmp(a2, *(i - 1), a3) )
      return v7;
  }
  return 0;
}
