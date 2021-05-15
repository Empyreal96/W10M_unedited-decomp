// ExReleaseRundownProtection_0 
 
_DWORD *__fastcall ExReleaseRundownProtection_0(_DWORD *result)
{
  unsigned int v1; // r4
  unsigned int v2; // r2
  unsigned int v3; // r1

  __pld(result);
  v1 = *result & 0xFFFFFFFE;
  __dmb(0xBu);
  v2 = v1 - 2;
  do
    v3 = __ldrex(result);
  while ( v3 == v1 && __strex(v2, result) );
  if ( v3 != v1 )
    result = (_DWORD *)ExfReleaseRundownProtection(result, v3, v2);
  return result;
}
