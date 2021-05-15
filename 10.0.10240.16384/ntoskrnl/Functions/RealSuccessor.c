// RealSuccessor 
 
_DWORD *__fastcall RealSuccessor(_DWORD *a1)
{
  _DWORD *v1; // r2
  _DWORD *result; // r0
  _DWORD *j; // r1
  _DWORD *i; // r3

  v1 = a1;
  result = (_DWORD *)a1[2];
  if ( result )
  {
    for ( i = (_DWORD *)result[1]; i; i = (_DWORD *)i[1] )
      result = i;
  }
  else
  {
    for ( j = (_DWORD *)*v1; (_DWORD *)j[2] == v1; j = (_DWORD *)*j )
      v1 = j;
    result = (_DWORD *)*v1;
    if ( *(_DWORD **)(*v1 + 4) != v1 )
      result = 0;
  }
  return result;
}
