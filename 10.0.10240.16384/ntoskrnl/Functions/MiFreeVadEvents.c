// MiFreeVadEvents 
 
_DWORD *__fastcall MiFreeVadEvents(int a1)
{
  _DWORD *result; // r0
  _DWORD *v2; // r4

  result = *(_DWORD **)(a1 + 36);
  if ( result )
  {
    do
    {
      v2 = (_DWORD *)*result;
      ExFreePoolWithTag(result);
      result = v2;
    }
    while ( v2 );
  }
  return result;
}
