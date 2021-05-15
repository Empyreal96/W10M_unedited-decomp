// PfSnNameRemoveAll 
 
_DWORD *__fastcall PfSnNameRemoveAll(int a1)
{
  int i; // r0
  _DWORD *result; // r0
  _DWORD *v4; // r4

  for ( i = 0; ; i = (int)v4 )
  {
    result = (_DWORD *)PfSnActiveTraceGetNext(i);
    v4 = result;
    if ( !result )
      break;
    if ( PfSnNameRemove(result, *(_DWORD *)(a1 + 8)) )
      return (_DWORD *)sub_803098();
  }
  return result;
}
