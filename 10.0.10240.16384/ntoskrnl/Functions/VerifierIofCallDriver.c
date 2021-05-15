// VerifierIofCallDriver 
 
int __fastcall VerifierIofCallDriver(int a1, int a2)
{
  int result; // r0
  int vars4; // [sp+Ch] [bp+4h]

  if ( pXdvIofCallDriver )
    result = pXdvIofCallDriver(a1, a2, vars4, IofCallDriverSpecifyReturn);
  else
    result = IofCallDriverSpecifyReturn(a1, a2);
  return result;
}
