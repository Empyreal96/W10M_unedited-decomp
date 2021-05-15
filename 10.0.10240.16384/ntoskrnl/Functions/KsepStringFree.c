// KsepStringFree 
 
int __fastcall KsepStringFree(_DWORD *a1)
{
  int result; // r0

  if ( !a1 )
    return sub_7CD27C();
  result = a1[1];
  if ( result )
  {
    result = KsepPoolFreePaged(result);
    *a1 = 0;
    a1[1] = 0;
  }
  return result;
}
