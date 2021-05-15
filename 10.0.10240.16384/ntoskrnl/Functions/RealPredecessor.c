// RealPredecessor 
 
_DWORD *__fastcall RealPredecessor(_DWORD *a1)
{
  _DWORD *v1; // r2
  _DWORD *i; // r1
  _DWORD *result; // r0

  v1 = a1;
  if ( a1[1] )
    JUMPOUT(0x554F04);
  for ( i = (_DWORD *)*a1; (_DWORD *)i[1] == v1; i = (_DWORD *)*i )
    v1 = i;
  result = (_DWORD *)*v1;
  if ( *(_DWORD **)(*v1 + 8) != v1 || (_DWORD *)*result == result )
    result = 0;
  return result;
}
