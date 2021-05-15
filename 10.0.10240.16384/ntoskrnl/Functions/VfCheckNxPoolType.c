// VfCheckNxPoolType 
 
int VfCheckNxPoolType()
{
  int result; // r0

  if ( ViVerifierEnabled )
    result = VfCheckPoolType();
  return result;
}
