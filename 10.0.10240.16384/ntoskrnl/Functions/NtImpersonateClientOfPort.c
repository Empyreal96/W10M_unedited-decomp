// NtImpersonateClientOfPort 
 
int __fastcall NtImpersonateClientOfPort(int a1, int a2)
{
  int result; // r0

  result = NtAlpcImpersonateClientOfPort(a1, a2, 0);
  if ( result == -1073740030 )
    result = -1073741281;
  return result;
}
