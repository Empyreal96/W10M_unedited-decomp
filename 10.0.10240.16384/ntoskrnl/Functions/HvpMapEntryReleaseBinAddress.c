// HvpMapEntryReleaseBinAddress 
 
unsigned int *__fastcall HvpMapEntryReleaseBinAddress(int a1, int a2)
{
  unsigned int *result; // r0
  unsigned int v3; // r4
  unsigned int v4; // r2
  unsigned int v5; // r1

  result = (unsigned int *)(a2 + 12);
  __pld((void *)(a2 + 12));
  v3 = *(_DWORD *)(a2 + 12) & 0xFFFFFFFE;
  __dmb(0xBu);
  v4 = v3 - 2;
  do
    v5 = __ldrex(result);
  while ( v5 == v3 && __strex(v4, result) );
  if ( v5 != v3 )
    result = (unsigned int *)ExfReleaseRundownProtection(result, v5, v4);
  return result;
}
