// PopGetReasonListByReasonCode 
 
int *__fastcall PopGetReasonListByReasonCode(int a1)
{
  int *result; // r0

  for ( result = (int *)PowerStateDisableReasonListHead; result != &PowerStateDisableReasonListHead; result = (int *)*result )
  {
    if ( result[4] == a1 )
      return result;
  }
  return 0;
}
