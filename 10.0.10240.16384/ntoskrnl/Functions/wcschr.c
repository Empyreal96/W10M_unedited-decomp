// wcschr 
 
_WORD *__fastcall wcschr(_WORD *result, int a2)
{
  while ( *result && (unsigned __int16)*result != a2 )
    ++result;
  if ( (unsigned __int16)*result != a2 )
    result = 0;
  return result;
}
