// ViIsDriverSuspectForVerifier 
 
int ViIsDriverSuspectForVerifier()
{
  int result; // r0

  result = 0;
  if ( (int *)VfSuspectDriversList != &VfSuspectDriversList )
    result = sub_8E538C(0);
  return result;
}
