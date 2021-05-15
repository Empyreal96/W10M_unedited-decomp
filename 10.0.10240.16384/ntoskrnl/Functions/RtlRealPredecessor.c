// RtlRealPredecessor 
 
_DWORD *__fastcall RtlRealPredecessor(_DWORD *a1)
{
  _DWORD *v1; // r2
  _DWORD *result; // r0
  _DWORD *i; // r3
  _DWORD *j; // r1

  v1 = a1;
  result = (_DWORD *)a1[1];
  if ( result )
  {
    for ( i = (_DWORD *)result[2]; i; i = (_DWORD *)i[2] )
      result = i;
  }
  else
  {
    for ( j = (_DWORD *)*v1; (_DWORD *)j[1] == v1; j = (_DWORD *)*j )
      v1 = j;
    result = (_DWORD *)*v1;
    if ( *(_DWORD **)(*v1 + 8) != v1 )
      result = 0;
  }
  return result;
}
