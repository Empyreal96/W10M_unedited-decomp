// HvpMapEntryReleaseBlockAddress 
 
unsigned __int8 *__fastcall HvpMapEntryReleaseBlockAddress(int a1, int a2)
{
  unsigned __int8 *result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r1

  result = (unsigned __int8 *)(a2 + 12);
  __pld((void *)(a2 + 12));
  v3 = *(_DWORD *)(a2 + 12) & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v4 = __ldrex((unsigned int *)result);
  while ( v4 == v3 && __strex(v3 - 2, (unsigned int *)result) );
  if ( v4 != v3 )
    result = ExfReleaseRundownProtection(result);
  return result;
}
