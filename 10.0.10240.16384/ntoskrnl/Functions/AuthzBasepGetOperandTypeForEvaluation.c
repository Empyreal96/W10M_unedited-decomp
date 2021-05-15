// AuthzBasepGetOperandTypeForEvaluation 
 
int __fastcall AuthzBasepGetOperandTypeForEvaluation(unsigned __int16 *a1)
{
  int result; // r0

  if ( *((_DWORD *)a1 + 3) == 1 )
    result = a1[14];
  else
    result = *a1;
  return result;
}
