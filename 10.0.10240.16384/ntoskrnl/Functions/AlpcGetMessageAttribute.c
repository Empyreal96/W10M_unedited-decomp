// AlpcGetMessageAttribute 
 
char *__fastcall AlpcGetMessageAttribute(_DWORD *a1, int a2)
{
  char *result; // r0

  if ( (*a1 & a2) == 0 || ((a2 - 1) & a2) != 0 )
    result = 0;
  else
    result = (char *)a1 + AlpcGetHeaderSize(*a1 & ~(2 * a2 - 1));
  return result;
}
