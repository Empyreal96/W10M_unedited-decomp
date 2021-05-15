// AuthzBasepQuerySystemSecurityAttributeAndValues 
 
int __fastcall AuthzBasepQuerySystemSecurityAttributeAndValues(int a1)
{
  int v2; // r0
  int v3; // r2
  int v4; // r3

  if ( *(_DWORD *)(a1 + 28) )
    return sub_7C50F8();
  v2 = AuthzBasepFindSystemSecurityAttribute(a1 + 4);
  if ( !v2 )
    return -1073741275;
  v3 = *(_DWORD *)(v2 + 44);
  *(_DWORD *)(a1 + 20) = *(_DWORD *)(v2 + 36);
  *(_WORD *)(a1 + 12) = *(_WORD *)(v2 + 24);
  v4 = *(_DWORD *)(v2 + 28);
  *(_DWORD *)(a1 + 28) = v2;
  *(_DWORD *)(a1 + 16) = v4;
  *(_DWORD *)(a1 + 24) = v3 + 24;
  *(_DWORD *)(a1 + 32) = v3;
  return 0;
}
