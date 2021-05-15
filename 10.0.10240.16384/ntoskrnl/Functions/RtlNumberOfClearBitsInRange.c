// RtlNumberOfClearBitsInRange 
 
int __fastcall RtlNumberOfClearBitsInRange(int a1, int a2, int a3)
{
  int v4; // r3
  int result; // r0

  v4 = RtlNumberOfSetBitsInRange();
  result = -1;
  if ( v4 != -1 )
    result = a3 - v4;
  return result;
}
