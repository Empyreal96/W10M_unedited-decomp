// PsDereferenceImpersonationToken 
 
int __fastcall PsDereferenceImpersonationToken(int a1)
{
  if ( a1 )
    a1 = ObfDereferenceObject(a1);
  return a1;
}
