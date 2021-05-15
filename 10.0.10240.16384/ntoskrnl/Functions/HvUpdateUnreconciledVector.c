// HvUpdateUnreconciledVector 
 
int __fastcall HvUpdateUnreconciledVector(unsigned int *a1, int a2)
{
  unsigned int *v3; // r1
  int result; // r0

  if ( a2 )
    v3 = a1 + 469;
  else
    v3 = a1 + 9;
  RtlMergeBitMaps(a1 + 13, v3);
  result = RtlNumberOfSetBits(a1 + 13);
  a1[15] = result;
  return result;
}
