// KsepCacheHwIdFree 
 
int __fastcall KsepCacheHwIdFree(int result)
{
  int v1; // r4

  v1 = result;
  if ( result )
  {
    KsepStringFree(result + 20);
    result = KsepPoolFreePaged(v1);
  }
  return result;
}
