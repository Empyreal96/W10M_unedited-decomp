// PopSqmCreateDwordStreamEntry 
 
_DWORD *__fastcall PopSqmCreateDwordStreamEntry(_DWORD *result, int a2)
{
  *result = 1;
  result[1] = a2;
  return result;
}
