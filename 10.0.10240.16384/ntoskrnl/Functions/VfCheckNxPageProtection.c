// VfCheckNxPageProtection 
 
int VfCheckNxPageProtection()
{
  int result; // r0

  if ( ViVerifierEnabled )
    result = VfCheckPageProtection();
  return result;
}
