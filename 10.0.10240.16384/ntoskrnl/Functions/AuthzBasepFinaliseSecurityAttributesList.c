// AuthzBasepFinaliseSecurityAttributesList 
 
int __fastcall AuthzBasepFinaliseSecurityAttributesList(int result, int a2)
{
  int v3; // r5
  _DWORD *v4; // r4
  int v5; // r1

  v3 = result;
  v4 = (_DWORD *)(result + 16);
  while ( (_DWORD *)*v4 != v4 )
  {
    v5 = *(_DWORD *)(v3 + 16) - 8;
    if ( a2 )
      result = AuthzBasepCommitSecurityAttributeChanges(v3, v5);
    else
      result = AuthzBasepRollbackSecurityAttributeChanges(v3, v5);
    if ( result )
      return sub_517EA0();
  }
  return result;
}
