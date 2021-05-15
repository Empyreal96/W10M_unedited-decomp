// VfCheckNxPagePriority 
 
int VfCheckNxPagePriority()
{
  int result; // r0

  if ( ViVerifierEnabled )
    result = VfCheckPagePriority();
  return result;
}
