// SepReferenceLogonSession 
 
int __fastcall SepReferenceLogonSession(int a1, int a2)
{
  int v4; // r6
  int result; // r0

  v4 = PsGetCurrentServerSilo();
  result = SepReferenceLogonSessionSilo(a1, v4, a2);
  if ( v4 )
    result = sub_7DBFFC(result);
  return result;
}
