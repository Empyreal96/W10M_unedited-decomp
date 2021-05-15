// BiFreeIdentifierList 
 
_DWORD *__fastcall BiFreeIdentifierList(_DWORD *result)
{
  if ( (_DWORD *)*result != result )
    result = (_DWORD *)sub_812E5C();
  return result;
}
