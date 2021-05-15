// PsReferenceImpersonationToken 
 
int __fastcall PsReferenceImpersonationToken(int a1, int a2, int a3, int a4)
{
  return PsReferenceImpersonationTokenEx(a1, 1, a2, a3, a4, 0);
}
