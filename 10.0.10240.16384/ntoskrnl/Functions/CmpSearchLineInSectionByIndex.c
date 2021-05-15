// CmpSearchLineInSectionByIndex 
 
_DWORD *__fastcall CmpSearchLineInSectionByIndex(int a1, unsigned int a2)
{
  _DWORD *result; // r0
  unsigned int i; // r3

  if ( !a1 )
    return 0;
  result = *(_DWORD **)(a1 + 8);
  for ( i = 0; i < a2; result = (_DWORD *)*result )
  {
    if ( !result )
      break;
    ++i;
  }
  return result;
}
