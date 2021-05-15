// AuthzBasepAllocateClaimCollectionNoLists 
 
_BYTE *__fastcall AuthzBasepAllocateClaimCollectionNoLists(int a1, int a2)
{
  _BYTE *v2; // r0
  _BYTE *v3; // r4

  v2 = (_BYTE *)AuthzBasepMemAlloc(304, a2, 1950442835);
  v3 = v2;
  if ( !v2 )
    return 0;
  memset(v2, 0, 304);
  return v3;
}
