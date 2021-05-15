// MiLocateVadEvent 
 
_DWORD *__fastcall MiLocateVadEvent(int a1, int a2)
{
  _DWORD *result; // r0

  for ( result = *(_DWORD **)(a1 + 36); result && result[1] != a2; result = (_DWORD *)*result )
    ;
  return result;
}
