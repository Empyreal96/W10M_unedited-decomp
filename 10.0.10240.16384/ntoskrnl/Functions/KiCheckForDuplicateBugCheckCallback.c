// KiCheckForDuplicateBugCheckCallback 
 
int __fastcall KiCheckForDuplicateBugCheckCallback(_DWORD *a1, _DWORD *a2)
{
  _DWORD *i; // r3
  _DWORD *j; // r3

  for ( i = (_DWORD *)*a1; i != a1; i = (_DWORD *)*i )
  {
    if ( i == a2 )
      return 1;
  }
  for ( j = (_DWORD *)a1[1]; j != a1; j = (_DWORD *)j[1] )
  {
    if ( j == a2 )
      return 1;
  }
  return 0;
}
