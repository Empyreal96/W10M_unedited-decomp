// AlpcpLocateView 
 
_DWORD *__fastcall AlpcpLocateView(int a1, int a2)
{
  _DWORD *v2; // r0
  _DWORD *i; // r2
  _DWORD *v4; // t1

  v4 = *(_DWORD **)(a1 + 32);
  v2 = (_DWORD *)(a1 + 32);
  for ( i = v4; i != v2; i = (_DWORD *)*i )
  {
    if ( i[3] == a2 )
      return i;
  }
  return 0;
}
