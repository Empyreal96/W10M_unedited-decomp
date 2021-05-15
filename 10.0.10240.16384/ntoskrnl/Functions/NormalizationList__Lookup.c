// NormalizationList__Lookup 
 
void **__fastcall NormalizationList__Lookup(void *a1)
{
  void **result; // r0
  void **i; // r2

  result = 0;
  for ( i = (void **)NormalizationListHead; i != &NormalizationListHead; i = (void **)*i )
  {
    if ( i[2] == a1 )
      return i + 3;
  }
  return result;
}
