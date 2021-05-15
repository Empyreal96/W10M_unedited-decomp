// AuthzBasepRollbackSecurityAttributeChanges 
 
int __fastcall AuthzBasepRollbackSecurityAttributeChanges(_DWORD *a1, int a2)
{
  int v3; // r6
  int v4; // r1
  int v5; // r3
  int v6; // r5

  v3 = 0;
  AuthzBasepRemoveSecurityAttributeFromLists(a1, (__int64 *)a2, 0, 1);
  v5 = *(_DWORD *)(a2 + 32);
  if ( (v5 & 4) != 0 )
  {
    if ( (v5 & 1) == 0 )
    {
      AuthzBasepFreeSecurityAttributeValues(v4, 0);
      return 1;
    }
    *(_DWORD *)(a2 + 32) = v5 & 0xFFFFFFFB;
    AuthzBasepFreeSecurityAttributeValues(v4, 1);
  }
  while ( *(_DWORD *)(a2 + 56) != a2 + 56 )
  {
    v6 = *(_DWORD *)(a2 + 56);
    AuthzBasepRemoveSecurityAttributeValueFromLists((_DWORD *)a2, (__int64 *)(v6 - 8), 0);
    if ( (*(_DWORD *)(v6 + 8) & 4) != 0 )
    {
      --*(_DWORD *)(a2 + 40);
      *(_DWORD *)(v6 + 8) &= 0xFFFFFFFB;
    }
    if ( (*(_DWORD *)(v6 + 8) & 1) == 0 )
      ExFreePoolWithTag(v6 - 8);
  }
  if ( (*(_DWORD *)(a2 + 32) & 1) == 0 )
    return 1;
  return v3;
}
