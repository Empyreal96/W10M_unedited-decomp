// ExReleaseExtensionTable 
 
_DWORD *__fastcall ExReleaseExtensionTable(int a1)
{
  _DWORD *result; // r0
  unsigned int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1

  result = (_DWORD *)(a1 + 36);
  __pld(result);
  v2 = *result & 0xFFFFFFFE;
  __dmb(0xBu);
  v3 = v2 - 2;
  do
    v4 = __ldrex(result);
  while ( v4 == v2 && __strex(v3, result) );
  if ( v4 != v2 )
    result = (_DWORD *)ExfReleaseRundownProtection(result, v4, v3);
  return result;
}
