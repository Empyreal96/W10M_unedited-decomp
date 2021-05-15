// VerifierKeDelayExecutionThread 
 
int __fastcall VerifierKeDelayExecutionThread(char a1, int a2, int a3)
{
  int v3; // r6
  int result; // r0

  v3 = a1;
  if ( ViKeInjectStatusAlerted(a2) )
    result = 257;
  else
    result = pXdvKeDelayExecutionThread(v3, a2, a3);
  return result;
}
