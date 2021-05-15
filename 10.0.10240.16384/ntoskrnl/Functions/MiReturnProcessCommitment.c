// MiReturnProcessCommitment 
 
unsigned int __fastcall MiReturnProcessCommitment(int a1, int a2)
{
  unsigned int *v2; // r2
  unsigned int result; // r0

  v2 = (unsigned int *)(a1 + 484);
  do
    result = __ldrex(v2);
  while ( __strex(result - a2, v2) );
  return result;
}
