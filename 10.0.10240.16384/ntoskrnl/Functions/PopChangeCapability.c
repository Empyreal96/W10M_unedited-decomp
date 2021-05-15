// PopChangeCapability 
 
_BYTE *__fastcall PopChangeCapability(_BYTE *result, int a2)
{
  if ( (unsigned __int8)*result != a2 )
  {
    *result = a2;
    result = (_BYTE *)PopResetCurrentPolicies(result);
  }
  return result;
}
