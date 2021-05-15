// ExDereferenceCallBackBlock 
 
_DWORD *__fastcall ExDereferenceCallBackBlock(_DWORD *result, unsigned int a2)
{
  unsigned int v2; // r4
  unsigned int v3; // r5

  __pld(result);
  v2 = *result;
  if ( (*result ^ a2) >= 7 )
    return (_DWORD *)sub_546D28();
  while ( 1 )
  {
    __dmb(0xBu);
    do
      v3 = __ldrex(result);
    while ( v3 == v2 && __strex(v2 + 1, result) );
    if ( v3 == v2 )
      break;
    v2 = v3;
    if ( (v3 ^ a2) >= 7 )
      return (_DWORD *)sub_546D28();
  }
  return result;
}
