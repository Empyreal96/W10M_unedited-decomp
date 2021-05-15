// AuthzBasepObjectInTypeList 
 
int __fastcall AuthzBasepObjectInTypeList(_DWORD *a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v4; // r6
  _DWORD *i; // r5

  v4 = 0;
  if ( !a3 )
    return 0;
  for ( i = (_DWORD *)(a2 + 4); *a1 != *i || a1[1] != i[1] || a1[2] != i[2] || a1[3] != i[3]; i += 11 )
  {
    if ( ++v4 >= a3 )
      return 0;
  }
  *a4 = v4;
  return 1;
}
